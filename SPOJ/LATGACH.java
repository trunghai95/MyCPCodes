import java.util.*;
import java.math.BigInteger;

class LATGACH {

	public static void main(String args[]) {
		int test, n;
		BigInteger[] res = new BigInteger[101];
		
		res[0] = res[1] = BigInteger.ONE;
		for (int i = 2; i <= 100; ++i) {
			res[i] = res[i-1].add(res[i-2]);
		}

		Scanner in = new Scanner(System.in);
		
		test = in.nextInt();

		while (test --> 0) {
			n = in.nextInt();
			System.out.println(res[n]);
		}
		in.close();
	}
}