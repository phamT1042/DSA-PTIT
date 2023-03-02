import java.util.Scanner;
public class DSA05030 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while (t-- > 0) {
        	int n = sc.nextInt();
			int m = sc.nextInt(); 
		    long dp[][] = new long[n + 1][m + 1];
			for (int i = 0; i <= n; i++)
            	for (int j = 0; j <= m; j++) 
                	dp[i][j] = 1;
			for (int i = 1; i <= n; i++) 
				for (int j = 1; j <= m; j++)
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			System.out.println(dp[n][m]);
		}
		sc.close();
	}
}