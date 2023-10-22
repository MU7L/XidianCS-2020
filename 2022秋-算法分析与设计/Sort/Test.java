package Sort;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

public class Test {
    public static void main(String[] args) throws IOException {
        // 实验规模
        int times = 10;    // 每种排序测试次数
        int size = 100000; // 测试样例数组大小

        // 数据存储
        double[] timeIS = new double[times];
        double[] timeTDM = new double[times];
        double[] timeBUM = new double[times];
        double[] timeRQ = new double[times];
        double[] timeQD3P = new double[times];
        long[] spaceIS = new long[times];
        long[] spaceTDM = new long[times];
        long[] spaceBUM = new long[times];
        long[] spaceRQ = new long[times];
        long[] spaceQD3P = new long[times];

        // 测试样例
        int[] src = new int[size];
        Random r = new Random();
        for (int i = 0; i < size; ++i) {
            src[i] = r.nextInt() % 40000;
        }

        // 实验
        Monitor m = new Monitor();
        int[] unsorted = new int[100000];
        for (int i = 0; i < times; i++) {
            // IS
            System.arraycopy(src, 0, unsorted, 0, src.length);
            m.start();
            IS.sort(unsorted);
            m.end();
            timeIS[i] = m.getTime();
            spaceIS[i] = m.getSpace();
            m.clear();

            // TDM
            System.arraycopy(src, 0, unsorted, 0, src.length);
            m.start();
            TDM.sort(unsorted);
            m.end();
            timeTDM[i] = m.getTime();
            spaceTDM[i] = m.getSpace();
            m.clear();

            // BUM
            System.arraycopy(src, 0, unsorted, 0, src.length);
            m.start();
            BUM.sort(unsorted);
            m.end();
            timeBUM[i] = m.getTime();
            spaceBUM[i] = m.getSpace();
            m.clear();

            // RQ
            System.arraycopy(src, 0, unsorted, 0, src.length);
            m.start();
            RQ.sort(unsorted);
            m.end();
            timeRQ[i] = m.getTime();
            spaceRQ[i] = m.getSpace();
            m.clear();

            // QD3P
            System.arraycopy(src, 0, unsorted, 0, src.length);
            m.start();
            QD3P.sort(unsorted);
            m.end();
            timeQD3P[i] = m.getTime();
            spaceQD3P[i] = m.getSpace();
            m.clear();

            // 展示过程
            System.out.println("循环：" + i);
        }

        // 处理数据
        String res = "IS," + dataPrint(timeIS) + "\b\n"
                + "TDM," + dataPrint(timeTDM) + "\b\n"
                + "BUM," + dataPrint(timeBUM) + "\b\n"
                + "RQ," + dataPrint(timeRQ) + "\b\n"
                + "QD3P," + dataPrint(timeQD3P) + "\b\n"
                + "IS," + dataPrint(spaceIS) + "\b\n"
                + "TDM," + dataPrint(spaceTDM) + "\b\n"
                + "BUM," + dataPrint(spaceBUM) + "\b\n"
                + "RQ," + dataPrint(spaceRQ) + "\b\n"
                + "QD3P," + dataPrint(spaceQD3P) + "\b\n";
        System.out.println(res);

        // 写入结果
//        try {
//            File file = new File("result.csv");
//            if (!file.exists()) {
//                file.createNewFile();
//            }
//            FileWriter fw = new FileWriter(file.getAbsoluteFile());
//            BufferedWriter bw = new BufferedWriter(fw);
//            bw.write(res);
//            bw.close();
//            System.out.println("Done");
//        } catch (Exception e) {
//            e.printStackTrace();
//        }
    }

    public static String dataPrint(double[] data) {
        StringBuilder sb = new StringBuilder();
        for(double d : data) {
            sb.append(d).append(",");
        }
        return sb.toString();
    }

    public static String dataPrint(long[] data) {
        StringBuilder sb = new StringBuilder();
        for(double d : data) {
            sb.append(d).append(",");
        }
        return sb.toString();
    }
}
