import java.util.Scanner;
import java.lang.String;
public class DSA09020 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        Integer[][] a = new Integer[n + 1][n + 1];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++) a[i][j] = 0;
        for (int i = 1; i <= n; i++) {
            String s = sc.nextLine();
            String[] tach = s.split(" ");
            for (String x : tach) {
                a[i][Integer.parseInt(x)] = 1;
                a[Integer.parseInt(x)][i] = 1;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) System.out.print(a[i][j] + " ");
            System.out.println("");
        }
        sc.close();
    }
}
