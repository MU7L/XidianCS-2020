package PercolationProblem;

import edu.princeton.cs.algs4.QuickFindUF;

import java.util.Random;

public class Percolation {
    private int n; // 系统规模
    private int[][] sites; // 系统对象
    private int openStats; // open统计
    private QuickFindUF uf; // QuickFindUF对象
    //    private WeightedQuickUnionUF uf; // WeightQuickUnionUF对象
    private int top; // UF顶点
    private int bottom; // UF底端

    //    创建N*N矩阵，初始化为block(0)
    public Percolation(int N) {
        if (N <= 1) {
            throw new IllegalArgumentException("[Percolation] IllegalArgumentException: " + N);
        }
        n = N;
        sites = new int[N][N];
        openStats = 0;
//        site[i][j] 对应 uf[i*N+j] 上顶点uf[n*n] 下端点uf[n*n+1]
        uf = new QuickFindUF(N * N + 2);
//        uf = new WeightedQuickUnionUF(N * N + 2);
        top = N * N;
        bottom = N * N + 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                sites[i][j] = 0; // 0=block 1=open
            }
        }
        for (int j = 0; j < N; j++) {
            uf.union(top, id(0, j)); // 连接顶点uf[n*n] 与 第一行
            uf.union(bottom, id(N - 1, j)); // 连接底端点uf[n*n+1] 与 最后一行
        }
    }

//    注意：题中节点(i, j)对应的是sites[i-1][j-1]

    //    检验
    private void validate(int... ps) {
        for (int p : ps) {
            if (p < 0 || p >= n) {
                throw new IllegalArgumentException("[validate] IllegalArgumentException: " + p);
            }
        }
    }

    //    将二维数组site下标转为UF下标
    private int id(int i, int j) {
        return i * n + j;
    }

    //    open 操作 site变为1，并与四周site联通
    public void open(int i, int j) {
        validate(i, j);
        sites[i][j] = 1;
        int id = id(i, j);
//        联通上
        if (i > 0 && isOpen(i - 1, j)) {
            uf.union(id, id(i - 1, j));
        }
//        联通下
        if (i < n - 1 && isOpen(i + 1, j)) {
            uf.union(id, id(i + 1, j));
        }
//        联通左
        if (j > 0 && isOpen(i, j - 1)) {
            uf.union(id, id(i, j - 1));
        }
//        联通右
        if (j < n - 1 && isOpen(i, j + 1)) {
            uf.union(id, id(i, j + 1));
        }
        openStats++;
    }

    //    检查是否open
    public boolean isOpen(int i, int j) {
        validate(i, j);
        return sites[i][j] == 1;
    }

    //    site[i][j] 能否联通到顶端
    public boolean isFull(int i, int j) {
        validate(i, j);
        return uf.connected(top, id(i, j));
    }

    //    系统是否渗漏
    public boolean percolates() {
        return uf.connected(top, bottom);
    }

    //    渗透率
    public double rate() {
        return openStats * 1.0 / (n * n);
    }

    //    打印sites
    public void showSites() {
        System.out.println("sites: ========");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(String.valueOf(sites[i][j]) + ' ');
            }
            System.out.println();
        }
        System.out.println(String.format("open sites: %d/%d", openStats, n * n));
    }

    //    打印UF
    public void showUF() {
        System.out.println("UF: ========");
        for (int i = 0; i < n * n; i++) {
            System.out.print(String.format("id[%d]=%d ", i, uf.find(i)));
        }
        System.out.println("\n");
    }

    public static void main(String[] args) {
        int N = 8;
        Random r = new Random();
        int openI, openJ;
        Percolation p = new Percolation(N);
        while (!p.percolates()) {
            openI = r.nextInt(N);
            openJ = r.nextInt(N);
            if (!p.isOpen(openI, openJ)) {
                p.open(openI, openJ);
            }
            p.showSites();
            p.showUF();
        }
    }
}

