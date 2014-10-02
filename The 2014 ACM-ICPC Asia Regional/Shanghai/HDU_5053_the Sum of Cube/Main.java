import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int t;
		t = in.nextInt();
		for (int k = 1; k <= t; k++) {
			BigInteger ans = BigInteger.ZERO;
			int a, b;
			a = in.nextInt();
			b = in.nextInt();
			for (int i = a; i <= b; i++) {
				ans = ans.add(BigInteger.valueOf(i).pow(3));
			}
			
			System.out.print("Case #" + String.valueOf(k) + ": ");
			System.out.println(ans);
		}
		
		in.close();
	}
}
