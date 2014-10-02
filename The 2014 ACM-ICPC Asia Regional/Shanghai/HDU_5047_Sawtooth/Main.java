import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int t = Integer.parseInt(in.readLine());
		
		BigInteger eight = BigInteger.valueOf(8);
		BigInteger seven = BigInteger.valueOf(7);
		
		for (int k = 1; k <= t; k++) {
			BigInteger n = new BigInteger(in.readLine());
			BigInteger ans = eight.multiply(n).subtract(seven).multiply(n).add(BigInteger.ONE);
			out.write("Case #" + String.valueOf(k) + ": " + ans.toString());
			out.newLine();
			out.flush();
		}
		
		out.close();
		in.close();
	}
}