// too slow...

import java.util.*;
import java.io.*;
import java.math.*;

class _101090B {

	public static void main(String[] args) throws IOException {
		BigInteger n;
		int k, nn;
		BigInteger res, tmp;
		int lo, hi, mid;
		final BigInteger HUNDRED = new BigInteger("100");
		final BigInteger NINE = new BigInteger("9");
		final BigInteger TWO = new BigInteger("2");

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		nn = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());

		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		n = new BigInteger(nn + "");
		nn = (int) Math.sqrt(nn);

		bw.write(nn + ".");

		res = new BigInteger(nn + "");

		for (int i = 0; i < k; ++i) {
			res = res.multiply(BigInteger.TEN);
			n = n.multiply(HUNDRED);
			lo = 0;
			hi = 9;

			while (lo < hi) {
				mid = ((lo + hi) >> 1) + 1;
				tmp = res.add(new BigInteger(mid+""));
				if (tmp.multiply(tmp).compareTo(n) > 0) {
					hi = mid - 1;
				} else {
					lo = mid;
				}
			}

			bw.write(lo + "");

			res = res.add(new BigInteger(lo + ""));
		}

		bw.flush();
	}
}