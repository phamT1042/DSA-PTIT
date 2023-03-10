import java.util.Scanner;
import java.lang.Math;
public class DSA05022 {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int x = sc.nextInt();
            int y = sc.nextInt();
            int z = sc.nextInt();
            int[] dp = new int[n + 1];
            dp[1] = x;
            for (int i = 2; i <= n; i++) {
                if (i % 2 == 0) dp[i] = Math.min(dp[i - 1] + x, dp[i / 2] + z);
                else dp[i] = Math.min(dp[i - 1] + x, dp[i / 2 + 1] + z + y);
            }
            System.out.println(dp[n]);
        }
        sc.close();
    }
}