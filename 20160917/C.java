import java.util.*;
import java.math.*;

class C {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		BigInteger x, xp, xq, tmp, tt;
		int p, q;
		tmp = BigInteger.TEN.pow(100);
		tt = new BigInteger("400");

		while (in.hasNextBigInteger()) {
			x = in.nextBigInteger();
			p = in.nextInt();
			q = in.nextInt();
			if (x.equals(BigInteger.ONE) || p >= 340 || q >= 340) {
				System.out.println("NaN");
				continue;
			}

			xp = x.pow(p);
			xq = x.pow(q);

			if (xp.compareTo(tmp) >= 0 || xq.compareTo(tmp) >= 0) {
				System.out.println("NaN");
			} else {
				xp = xp.subtract(BigInteger.ONE);
				xq = xq.subtract(BigInteger.ONE);
				if (xp.mod(xq).compareTo(BigInteger.ZERO) != 0) {
					System.out.println("NaN");
				} else {
					System.out.println(xp.divide(xq));
				}
			}
		}

		in.close();
	}
}