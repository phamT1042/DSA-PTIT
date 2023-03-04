import java.util.Scanner;
import java.util.Stack;
import java.lang.String;
public class DSA07013 {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        while (t-- > 0) {
            String s; 
            s = sc.nextLine();
            Stack<Integer> st = new Stack<>();
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) >= '0' && s.charAt(i) <= '9') st.push(s.charAt(i) - '0');
                else {
                    int so1 = st.pop();
                    int so2 = st.pop();
                    switch (s.charAt(i)) {
                        case '+': st.push(so2 + so1); break;
                        case '-': st.push(so2 - so1); break;
                        case '*': st.push(so2 * so1); break;
                        case '/': st.push(so2 / so1); break;
                    }
                }
            }
            System.out.println(st.peek());
        }
        sc.close();
    }
}