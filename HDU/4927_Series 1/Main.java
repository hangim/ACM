// Accepted
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		BigInteger A[] = new BigInteger[3000];
		
		int t;
		t = in.nextInt();
		for (; t > 0; t--) {
			int n;
			n = in.nextInt();
			for (int i = 0; i < n; i++) {
				A[i] = in.nextBigInteger();
			}
			
			BigInteger ans = A[n-1];
			BigInteger k = BigInteger.valueOf(1);
			int flag = -1;
			for (int i = 1; i < n; i++) {
				k = k.multiply(BigInteger.valueOf(n-i)).divide(BigInteger.valueOf(i));
				BigInteger tmp = k.multiply(A[n-1-i]);
				if (flag == -1) {
					ans = ans.subtract(tmp);
				} else {
					ans = ans.add(tmp);
				}
				flag *= -1;
			}
			System.out.println(ans);
		}
		in.close();
	}
}

