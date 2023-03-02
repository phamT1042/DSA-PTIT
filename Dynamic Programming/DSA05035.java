import java.util.Scanner;
public class DSA05035 {
    public static void main(String[] args) {
        long MOD = 1000000007;
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            long[][] dp = new long[n + 1][10]; //dp[i][j]: số số có số chữ số là i có chữ số cuối là j
            long res = 0;
            for (int i = 0; i < 10; i++) {
                dp[1][i] = 1; res += dp[1][i];
            }
            for (int i = 2; i <= n; i++) {
                dp[i][1] = 1; res += dp[i][1];
            } 
            for (int i = 2; i <= n; i++) {
                for (int j = 9; j >= 2; j--) {
                    dp[i][j] = dp[i - 1][j];
                    for (int k = j - 1; k >= 1; k--) {
                        dp[i][j] += dp[i - 1][k];
                        dp[i][j] %= MOD;
                    }
                    res += dp[i][j];
                    res %= MOD; 
                }
            }
            System.out.println(res);
        }
        sc.close();
    }
}