import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;
public class DSA08001 {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            Deque<Integer> q = new ArrayDeque<>();
            while (n-- > 0) {
                int i = sc.nextInt();
                switch(i) {
                    case 1: 
                        System.out.println(q.size()); 
                        break;
                    case 2: 
                        if (q.isEmpty()) System.out.println("YES");
                        else System.out.println("NO");
                        break;
                    case 3:
                        int x = sc.nextInt();
                        q.addLast(x); 
                        break;
                    case 4:
                        if (!q.isEmpty()) q.pollFirst(); 
                        break;
                    case 5:
                        if (!q.isEmpty()) System.out.println(q.getFirst()); 
                        else System.out.println("-1");
                        break;
                    case 6:
                        if (!q.isEmpty()) System.out.println(q.getLast()); 
                        else System.out.println("-1");
                        break;
                }
            }
        }
        sc.close();
    }
}