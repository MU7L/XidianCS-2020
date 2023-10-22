package Sort;

import edu.princeton.cs.algs4.StdRandom;

import java.util.Arrays;

public class QD3P {
    public static void sort(int[] a) {
        StdRandom.shuffle(a); // 消除对输入的依赖
        sort(a, 0, a.length - 1);
    }

    private static void sort(int[] a, int lo, int hi) {
        if (hi <= lo) {
            return;
        }
        int lt = lo, i = lo + 1, gt = hi; //a[lo..lt] < a[lt..i] < a[gt..hi] a[i..gt]是未排序的段
        int v = a[lo];
        while (i <= gt) {                 // 当i==gt时 数组只剩下三段 排序完成 主要移动i
            int cmp = a[i] - v;
            if (cmp < 0) {                // a[i]<v时 将a[i]移到a[lo..lt]
                exch(a, lt++, i++);
            } else if (cmp > 0) {         // a[i]>v时 将a[i]移到a[gt..hi]
                exch(a, i, gt--);
            } else {                      // a[i]=v时 a[i]位置不变
                i++;
            }
        } // a[lo..lt-1] < v = a[lt..gt] < a[gt+1..hi]
        sort(a, lo, lt - 1);
        sort(a, gt + 1, hi);
    }

    private static void exch(int[] a, int i, int j) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }

    public static void main(String[] args) {
        int[] a = {1, 1, 4, 5, 1, 4};
        QD3P.sort(a);
        System.out.println(Arrays.toString(a));
    }
}
