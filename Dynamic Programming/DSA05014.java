import java.math.BigInteger;
import java.util.Scanner;
public class DSA05014 {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            BigInteger[] C = new BigInteger[n + 1];
            C[0] = BigInteger.ONE;
            for (int i = 1; i <= n; i++) {
                C[i] = BigInteger.ZERO;
                for (int j = 0; j < i; j++) {
                    C[i] = C[i].add(C[j].multiply(C[i - j - 1]));
                }
            }
            System.out.println(C[n]);
        }
        sc.close(); 
    }
}
