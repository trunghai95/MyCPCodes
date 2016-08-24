// 10/100

import java.io.*;
import java.util.*;
import java.math.BigInteger;

class ONE4EVER {

	static BigInteger a, b, m, k;
	static final BigInteger TWO = new BigInteger("2");

	public static BigInteger solve() {
		if (a.equals(BigInteger.ONE)) {
			return b.multiply(k).mod(m);
		}

		if (m.equals(BigInteger.ONE)) {
			return BigInteger.ZERO;
		}

		BigInteger res = b.mod(m);
		BigInteger tmp = a.modPow(k, m).subtract(BigInteger.ONE).add(m).mod(m);
		res = res.multiply(tmp).mod(m);
		tmp = a.subtract(BigInteger.ONE).modPow(m.subtract(TWO), m);
		res.multiply(tmp).mod(m);

		return res;
	}

	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		int test = in.nextInt();

		while (test --> 0) {
			a = in.nextBigInteger();
			b = in.nextBigInteger();
			m = in.nextBigInteger();
			k = in.nextBigInteger();

			System.out.println(solve());
		}
		in.close();
	}
}