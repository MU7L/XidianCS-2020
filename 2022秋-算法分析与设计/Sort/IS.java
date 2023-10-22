package Sort;

import java.util.Arrays;

public class IS {
    //    升序排列
    public static void sort(int[] a) {
        for (int i = 1; i < a.length; i++) {
            for (int j = i; j > 0 && a[j - 1] > a[j]; j--) {
                exch(a, j, j - 1);
            }
        }
    }

    private static void exch(int[] a, int i, int j) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }

    public static void main(String[] args) {
        int[] a = {1, 1, 4, 5, 1, 4};
        IS.sort(a);
        System.out.println(Arrays.toString(a));
    }
}
