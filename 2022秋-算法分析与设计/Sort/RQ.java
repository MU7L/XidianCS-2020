package Sort;

import edu.princeton.cs.algs4.StdRandom;

import java.util.Arrays;

public class RQ {
    public static void sort(int[] a) {
        StdRandom.shuffle(a); // 消除对输入的依赖
        sort(a, 0, a.length - 1);
    }

    private static void sort(int[] a, int lo, int hi) {
        if (hi <= lo) {
            return;
        }
        int j = partition(a, lo, hi);
        sort(a, lo, j - 1); // 将左半部分a[lo .. j-1]排序
        sort(a, j + 1, hi); // 将右半部分a[j+1 .. hi]排序
    }

    // 将数组切分为a[lo..i-1], a[i], a[i+1..hi]
    private static int partition(int[] a, int lo, int hi) {
        int i = lo, j = hi + 1;     // 左右扫描指针
        int v = a[lo];              // 切分元素 默认为a[lo]
        while (true) {              // 扫描左右，检查扫描是否结束并交换元素
            while (a[++i] < v) {    // 在第一步先自增恰好跨过v
                if (i == hi) {      // i已经扫描到hi时 说明v为最大元素
                    break;          // 此时 i=hi j=hi+1
                }
            }                       // 此时a[i]为从左往右第一个比v大的元素
            while (v < a[--j]) {    // 在第一步自减减去了初始化时多的1
//                if (j == lo) {      // j=lo时 说明v为最小元素
//                    break;          // 此时 i=lo j=lo
//                }
            }
            if (i >= j) {           // 两指针相遇或交叉时结束循环
                break;
            }
            exch(a, i, j);
        }
        exch(a, lo, j);             // 将v=a[j]放入正确的位置 a[lo]<->a[j]
        return j;                   // a[lo..j-1] <= a[j] <= a[j+1..hi]
    }

    private static void exch(int[] a, int i, int j) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }

    public static void main(String[] args) {
        int[] a = {1, 1, 4, 5, 1, 4};
        RQ.sort(a);
        System.out.println(Arrays.toString(a));
    }
}
