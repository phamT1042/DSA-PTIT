import java.util.Locale;
import java.util.Scanner;
import java.lang.Math;
public class DSA05036 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in).useLocale(Locale.US);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int res = 1;
            int[] l = new int[n];
            float[] a = new float[n];
            float[] b = new float[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextFloat();
                b[i] = sc.nextFloat();
                l[i] = 1;
            }
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (a[i] > a[j] && b[i] < b[j]) {
                        l[i] = Math.max(l[i], l[j] + 1);
                    }
                }
                res = Math.max(res, l[i]);
            }
            System.out.println(res);
        }
        sc.close();
    }
}