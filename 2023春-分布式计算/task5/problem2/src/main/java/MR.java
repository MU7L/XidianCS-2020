import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class MR {

    public static class MyMapper extends org.apache.hadoop.mapreduce.Mapper<LongWritable, Text, Text, Text> {
        @Override
        protected void map(LongWritable key, Text value, Mapper<LongWritable, Text, Text, Text>.Context context)
                throws IOException, InterruptedException {
            String line = value.toString();
            String[] splitLine = line.split(",");
            String child = splitLine[0];
            String parent = splitLine[1];
            context.write(new Text(child), new Text(parent + "-1"));
            context.write(new Text(parent), new Text(child + "-0"));
            // <one: parent-1> <one: child-0>
        }
    }

    public static class MyReducer extends org.apache.hadoop.mapreduce.Reducer<Text, Text, Text, Text> {
        @Override
        protected void reduce(Text key, Iterable<Text> values, Reducer<Text, Text, Text, Text>.Context context) throws IOException, InterruptedException {
            // <one: parent-1, child-0, parent-1, child-0>
            List<String> grandparents = new ArrayList<>();
            List<String> grandchildren = new ArrayList<>();
            for (Text v : values) {
                String[] tmp = v.toString().split("-");
                if (tmp[1].equals("0")) {
                    grandchildren.add(tmp[0]);
                } else if (tmp[1].equals("1")) {
                    grandparents.add(tmp[0]);
                }
            }
            for (String grandchild : grandchildren) {
                for (String grandparent : grandparents) {
                    context.write(new Text(grandchild), new Text(grandparent));
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        Configuration conf = new Configuration();
        Job job = Job.getInstance(conf, MR.class.getSimpleName());
        //打成jar执行
        job.setJarByClass(MR.class);

        //数据在哪里
        FileInputFormat.setInputPaths(job, args[0]);

        //使用哪个mapper处理输入的数据
        job.setMapperClass(MyMapper.class);

        //map输出的数据类型是什么
        job.setMapOutputKeyClass(Text.class);
        job.setMapOutputValueClass(Text.class);

        //使用哪个reducer处理输入的数据
        job.setReducerClass(MyReducer.class);

        //reduce输出的数据类型是什么
        job.setOutputKeyClass(Text.class);
        job.setOutputValueClass(Text.class);

        //数据输出到哪里
        FileOutputFormat.setOutputPath(job, new Path(args[1]));

        //交给yarn去执行，直到执行结束才退出本程序
        job.waitForCompletion(true);
    }
}
