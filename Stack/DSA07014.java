import java.util.Scanner;
import java.util.Stack;
import java.lang.String;
public class DSA07014 {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        while (t-- > 0) {
            String s; 
            s = sc.nextLine();
            Stack<Integer> st = new Stack<>();
            for (int i = s.length() - 1; i >= 0; i--) {
                if (s.charAt(i) >= '0' && s.charAt(i) <= '9') st.push(s.charAt(i) - '0');
                else {
                    int so1 = st.pop();
                    int so2 = st.pop();
                    switch (s.charAt(i)) {
                        case '+': st.push(so1 + so2); break;
                        case '-': st.push(so1 - so2); break;
                        case '*': st.push(so1 * so2); break;
                        case '/': st.push(so1 / so2); break;
                    }
                }
            }
            System.out.println(st.peek());
        }
        sc.close();
    }
}

