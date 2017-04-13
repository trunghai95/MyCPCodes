import java.util.*;

public class Main {
    public static boolean check(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();
        char[] s = scan.next().toCharArray();

        for (int i = 0; i < n; ++i) {
            if (!check(s[i]) || i == 0 || s[i] != s[i-1]) {
                System.out.print(s[i]);
                if (i < n-1 && (s[i] == 'e' || s[i] == 'o')) {
                    if ((i == 0 || s[i] != s[i-1]) && s[i] == s[i+1] && (i >= n-2 || s[i+1] != s[i+2])) {
                        System.out.print(s[i]);
                    }
                }
            }
        }

        System.out.println();
    }
}
