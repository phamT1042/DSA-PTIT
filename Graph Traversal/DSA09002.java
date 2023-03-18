import java.util.Scanner;
import java.lang.String;
import java.util.Vector;
import java.util.ArrayList;
import java.util.Collections;
public class DSA09002 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<Vector<Integer>> a = new ArrayList<>(n + 1);
        for (int i = 0; i <= n; i++) {
            a.add(new Vector<Integer>());
        }
        for (int i = 1; i <= n; i++) {
            String s = sc.nextLine();
            String[] tach = s.split(" ");
            for (String x : tach) {
                a.get(i).add(Integer.parseInt(x));
            }
        }
        for (int i = 1; i <= n; i++) {
            Collections.sort(a.get(i));
            for (int x : a.get(i)) {
                if (x > i) System.out.println(i + " " + x);
            }
        }
        sc.close();
    }
}
