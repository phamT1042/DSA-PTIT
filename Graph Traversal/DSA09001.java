import java.util.Scanner;
import java.util.Vector;
public class DSA09001 {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int v = sc.nextInt();
            int e = sc.nextInt();
            Vector<Integer>[] a = new Vector[v + 1];
            for (int i = 0; i <= v; i++) {
                a[i] = new Vector<Integer>();
            }
            while (e-- > 0) {
                int x = sc.nextInt();
                int y = sc.nextInt();
                a[x].add(y);
                a[y].add(x);
            }
            for (int i = 1; i <= v; i++) {
                System.out.print(i + ": ");
                for (int j = 0; j < a[i].size(); j++) {
                    System.out.print(a[i].get(j) + " ");
                }
                System.out.println("");
            }
        }
        sc.close();
    }
}