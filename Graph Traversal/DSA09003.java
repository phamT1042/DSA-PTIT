import java.util.Scanner;
import java.util.Vector;
import java.util.ArrayList;
public class DSA09003 {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int v = sc.nextInt();
            int e = sc.nextInt();
            ArrayList<Vector<Integer>> a = new ArrayList<>(v + 1);
            for (int i = 0; i <= v; i++) {
                a.add(new Vector<Integer>());
            }
            while (e-- > 0) {
                int x = sc.nextInt();
                int y = sc.nextInt();
                a.get(x).add(y);
            }
            for (int i = 1; i <= v; i++) {
                System.out.print(i + ": ");
                for (int j = 0; j < a.get(i).size(); j++) {
                    System.out.print(a.get(i).get(j) + " ");
                }
                System.out.println("");
            }
        }
        sc.close();
    }
}