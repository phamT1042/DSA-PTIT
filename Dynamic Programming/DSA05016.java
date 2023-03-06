import java.util.Scanner;
import java.lang.Math;
public class DSA05016 {
	static int[] dp = new int[10001];
	static void xayDung() {
		int i = 1, j = 1, k = 1;
		dp[1] = 1;
		for (int m = 2; m <= 10000; m++) {
			dp[m] = Math.min(dp[i] * 2, Math.min(dp[j] * 3, dp[k] * 5));
			if (dp[m] == dp[i] * 2) i++;
			if (dp[m] == dp[j] * 3) j++;
			if (dp[m] == dp[k] * 5) k++;
		}
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		xayDung();
		while (t-- > 0) {
			int n = sc.nextInt();
			System.out.println(dp[n]);
		}
		sc.close();
	}
}