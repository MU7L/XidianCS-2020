package PercolationProblem;

import edu.princeton.cs.algs4.StdStats;
import edu.princeton.cs.algs4.Stopwatch;

import java.util.Random;

public class PercolationStats {
    private int n; // 实验规模
    private int t; // 实验次数
    private Percolation p; // 实验对象
    private double[] data; // 实验数据
    private double mu; // 样本均值
    private double sigma; // 样本方差
    private double confidenceLow; // 置信区间下限
    private double confidenceHigh; // 置信区间上限
    private double time; // 运行时间

    //    T次独立实验，N方格点
    public PercolationStats(int N, int T) {
        validate(N, T);
        n = N;
        t = T;
        data = new double[T];
        mu = 0.0;
        sigma = 0.0;
        confidenceLow = 0.0;
        confidenceHigh = 0.0;
//        统计
        Random r = new Random();
        int openI = 0;
        int openJ = 0;
        Stopwatch s = new Stopwatch(); // 计时开始
        for (int i = 0; i < t; i++) {
            p = new Percolation(n);
            while (!p.percolates()) {
                openI = r.nextInt(n);
                openJ = r.nextInt(n);
                if (!p.isOpen(openI, openJ)) {
                    p.open(openI, openJ);
                }
            }

            data[i] = p.rate();
        }
        time = s.elapsedTime(); // 计时结束
        mu = mean();
        sigma = stddev();
        confidenceLow = confidenceLo();
        confidenceHigh = confidenceHi();
    }

    public static void main(String[] args) {
        System.out.println("==== start ====");
        PercolationStats st1 = new PercolationStats(200, 100);
        System.out.println(st1);
        PercolationStats st2 = new PercolationStats(200, 100);
        System.out.println(st2);
        PercolationStats st3 = new PercolationStats(2, 100000);
        System.out.println(st3);
        System.out.println("===== end =====");
    }

    //    检查
    private void validate(int... ps) {
        for (int p : ps) {
            if (p <= 0) {
                throw new IllegalArgumentException("IllegalArgumentException: " + p);
            }
        }
    }

    //    均值
    public double mean() {
        return StdStats.mean(data);
    }

    //    标准差
    public double stddev() {
        return StdStats.stddev(data);
    }

    //    置信区间下限
    public double confidenceLo() {
        return mu - 1.96 * sigma / Math.sqrt(t);
    }

    //    置信区间上限
    public double confidenceHi() {
        return mu + 1.96 * sigma / Math.sqrt(t);
    }

    //    结果显示
    public String toString() {
        return String.format("PercolationStats(%d, %d):\n" +
                "                         mean() = %f\n" +
                "                       stddev() = %f\n" +
                "                confidenceLow() = %f\n" +
                "               confidenceHigh() = %f\n" +
                "                           time = %f", n, t, mu, sigma, confidenceLow, confidenceHigh, time);
    }
}
