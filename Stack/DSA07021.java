import java.util.Scanner;
import java.util.Stack;
import java.lang.String;
public class DSA07021 {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        while (t-- > 0) {
            String s; 
            s = sc.nextLine();
            int lengthMax = 0;
            Stack<Integer> st = new Stack<>();
            st.push(-1);
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == '(') st.push(i);
                else {
                    st.pop();
                    if (st.empty()) st.push(i);
                    else lengthMax = Math.max(lengthMax, i - st.peek());
                }
            }
            System.out.println(lengthMax);
        }
        sc.close();
    }
}