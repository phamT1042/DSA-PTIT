import java.util.Scanner;
import java.util.Stack;
import java.lang.String;
public class DSA07041 {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        while (t-- > 0) {
            String s; s = sc.nextLine();
            int length = 0;
            Stack<Integer> st = new Stack<>();
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == '(') st.push(i);
                else {
                    if (!st.empty()) {
                        st.pop();
                        length += 2;
                    }
                }
            }
            System.out.println(length);
        }
        sc.close();
    }
}
