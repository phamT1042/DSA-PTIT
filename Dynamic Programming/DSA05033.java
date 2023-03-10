import java.util.Scanner;
import java.lang.Math;
import java.lang.String;
public class DSA05033 {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        while (t-- > 0) {
            String s = sc.nextLine();
            int n = s.length();
            int[][] dp = new int[n][n];
            for (int i = n - 2; i >= 0; i--) {
                dp[i][i] = 0;
                for (int j = i + 1; j < n; j++) {
                    if (s.charAt(i) == s.charAt(j)) dp[i][j] = dp[i + 1][j - 1];
                    else dp[i][j] = Math.min(dp[i][j - 1], dp[i + 1][j]) + 1;
                }
            }
            System.out.println(dp[0][n - 1]);
        }
        sc.close();
    }
}