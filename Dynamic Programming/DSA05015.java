import java.util.Scanner;
public class DSA05015 {
    static final int MOD = 1000000007;
    static long[][] C = new long[1001][1001];
    static long[] gt = new long[1001];
    static void xayDung() {
        for (int i = 0; i <= 1000; i++) {
            if (i == 1 || i == 0) gt[i] = 1;
            else {
                gt[i] = (gt[i - 1] * i) % MOD;
            }
            for (int j = 0; j <= i; j++) {
                if (i == j || i == 0 || j == 0) C[i][j] = 1;
                else {
                    C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
                    C[i][j] %= MOD;
                }
            }
        }
    }
    public static void main (String[] args) {
        xayDung();
        Scanner sc = new Scanner(System.in);
        int t; t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            if (k > n) System.out.println("0");
            else if (k == n) System.out.println("1");
            else {
                long res = (C[n][k] * gt[k]) % MOD;
                System.out.println(res);
            }
        }
        sc.close();
    }
}
