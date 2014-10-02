import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int t;
		t = in.nextInt();
		for (int k = 1; k <= t; k++) {
			
			String s1, s2;
			s1 = in.next();
			s2 = in.next();
			
			BigInteger a = BigInteger.ONE;
			BigInteger b = BigInteger.ONE;
			
			for (int i = 1; i < s1.length(); i++) {
				a = a.multiply(BigInteger.valueOf(2));
				if (s1.charAt(i) == '1')
					a = a.add(BigInteger.ONE);
			}
			
			for (int i = 1; i < s2.length(); i++) {
				b = b.multiply(BigInteger.valueOf(2));
				if (s2.charAt(i) == '1')
					b = b.add(BigInteger.ONE);
			}
			
			// System.out.println(a);
			// System.out.println(b);
			BigInteger tmp = a.gcd(b);
			String ans = "";
			while (!tmp.equals(BigInteger.ZERO)) {
				// System.out.println(tmp);
				// System.out.println(tmp.mod(BigInteger.valueOf(2)));
				
				if (tmp.mod(BigInteger.valueOf(2)).equals(BigInteger.ONE))
					ans = "1" + ans;
				else
					ans = "0" + ans;
				tmp = tmp.divide(BigInteger.valueOf(2));
			}
			
			System.out.print("Case #" + String.valueOf(k) + ": ");
			System.out.println(ans);
		}
		
		in.close();
	}
}
