package Sort;

import java.util.Arrays;

public class TDM {
    private static int[] aux; // 归并所需的辅助数组

    public static void sort(int[] a) {
        aux = new int[a.length]; // 一次性分配空间
        sort(a, 0, a.length - 1);
    }

    private static void sort(int[] a, int lo, int hi) {
        if (hi <= lo) {
            return;
        }
        int mid = lo + (hi - lo) / 2;
        sort(a, lo, mid);         // 将左半边排序
        sort(a, mid + 1, hi); // 将右半边排序
        merge(a, lo, mid, hi);   // 归并结果
    }
    // 将a[lo..mid]和a[mid+1..hi]归并
    public static void merge(int[] a, int lo, int mid, int hi) {
        int i = lo, j = mid + 1;
        if (hi + 1 - lo >= 0) {
            System.arraycopy(a, lo, aux, lo, hi + 1 - lo); // 将a[lo..hi]复制到aux[lo..hi]
        }
        for (int k = lo; k <= hi; k++) { // 归并回到a[lo..hi] k指向a i,j指向aux
            if (i > mid) { // aux[lo..mid]已处理完
                a[k] = aux[j++];
            } else if (j > hi) { // aux[mid+1..hi]已处理完
                a[k] = aux[i++];
            } else if (aux[j] < aux[i]) { // a[k]处放入min(aux[i], aux[j])
                a[k] = aux[j++];
            } else {
                a[k] = aux[i++];
            }
        }
    }

    public static void main(String[] args) {
        int[] a = {1, 1, 4, 5, 1, 4};
        TDM.sort(a);
        System.out.println(Arrays.toString(a));
    }
}
