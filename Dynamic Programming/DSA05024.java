import java.util.Scanner;
public class DSA05024 {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        long MOD = 1000000007;
        while (t-- > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt(); 
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = sc.nextInt();
            long[] dp = new long[k + 1]; //Số cách lấy tổng các phần tử của a[] để được tổng i
            dp[0] = 1;
            for (int i = 1; i <= k; i++) {
                dp[i] = 0;
                for (int j = 0; j < n; j++) {
                    if (i >= a[j]) {
                        dp[i] += dp[i - a[j]];
                        dp[i] %= MOD;
                    }
                }
            }
            System.out.println(dp[k]);
        }
        sc.close();
    }
}

