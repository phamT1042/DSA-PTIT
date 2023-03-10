import java.util.Scanner;
import java.util.Stack;
import java.lang.String;
public class DSA07008 {
    static int uuTien (char x) {//Mức độ ưu tiên của các toán tử, toán hạng
        if (x == '+' || x == '-') return 1;
        if (x == '*' || x == '/') return 2;
        if (x == '^') return 3;
        return 0; //Mức độ ưu tiên 0 đối với toán hạng và mở ngoặc
    }
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        while (t-- > 0) {
            String s; 
            s = sc.nextLine();
            Stack<Character> st = new Stack<>();
            for (int i = 0; i < s.length(); i++) {
                char now = s.charAt(i);
                if (now == '(') st.push(now); //Nếu là ( cho vào stack
                else if (now == ')') {
                    while (!st.empty()) { //Nếu là ), pop tất cả toán tử trong stack đến khi gặp (, pop cả ( 
                        if (st.peek() == '(') {
                            st.pop();
                            break;
                        }
                        else System.out.print(st.pop());
                    }
                }
                else {
                    int kiTu = uuTien(now); //Nếu là các toán hạng và toán tử
                    if (kiTu == 0) System.out.print(now); //Nếu là toán hạng thì in ra
                    else { //Nếu là toán tử
                        //Chừng nào ở đỉnh stack là toán tử và toán tử đó có độ ưu tiên >= toán tử hiện tại
                        //thì pop toán tử đó ra
                        while (!st.empty()) {
                            if (uuTien(st.peek()) >= kiTu) System.out.print(st.pop());
                            else break;
                        }
                        //push toán tử hiện tại vào
                        st.push(now);
                    }
                }
            }
            //push nốt các toán tử còn lại trong stack
            while (!st.empty()) System.out.print(st.pop());
            System.out.print('\n');
        }
        sc.close();
    }
}