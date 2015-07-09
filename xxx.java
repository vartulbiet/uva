import java.util.Scanner;
import java.math.BigInteger;
public class Main{

	public static void main(String[] args)
	{
			Scanner scanner = new Scanner(System.in);
			BigInteger[] fact = new BigInteger[2001];
			fact[0] = fact[1] = BigInteger.ONE;
			for (int i = 2; i < 2001; i++)
            fact[i] = (new BigInteger("" + i)).multiply(fact[i - 1]);
			int n = scanner.nextInt();
			while(n!=0)
			{
			 StringBuilder builder = new StringBuilder();
			BigInteger res = ((fact[2 * n].divide((fact[n]*fact[n]))).divide(new BigInteger("" + (n + 1))));
            builder.append(res.toString());
            builder.append('\n');
			System.out.print(builder.toString());
			n =scanner.nextInt();
			}
	}
}