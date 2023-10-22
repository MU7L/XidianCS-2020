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

// 计算每个学生必修课的平均成绩
public class MR1 {

    public static class MyMapper extends org.apache.hadoop.mapreduce.Mapper<LongWritable, Text, Text, Text> {
        @Override
        protected void map(LongWritable key, Text value, Mapper<LongWritable, Text, Text, Text>.Context context)
                throws IOException, InterruptedException {
            String line = value.toString();
            String[] split = line.split(",");
            // 过滤必修
            if (split[3].equals("必修")) {
                String name = split[1];
                String grade = split[4];
                context.write(new Text(name), new Text(grade));
                // <name: grade>
            }
        }
    }

    public static class MyReducer extends org.apache.hadoop.mapreduce.Reducer<Text, Text, Text, Text> {
        @Override
        protected void reduce(Text key, Iterable<Text> grades, Reducer<Text, Text, Text, Text>.Context context) throws IOException, InterruptedException {
            double sum = 0.0;
            int len = 0;
            for (Text grade : grades) {
                sum += Double.parseDouble(grade.toString());
                len++;
            }
            double avg = sum / len;
            String avgString = String.format("%.2f", avg);
            context.write(key, new Text(avgString));
        }
    }

    public static void main(String[] args) throws Exception {
        Configuration conf = new Configuration();
        Job job = Job.getInstance(conf, MR1.class.getSimpleName());
        //打成jar执行
        job.setJarByClass(MR1.class);

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
