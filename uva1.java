import java.math.BigInteger;
import java.util.Scanner;
 
public class uva1{
 
    public static void main(String[] args) {
        BigInteger[] fact = new BigInteger[2001];
        fact[0] = fact[1] = BigInteger.ONE;
        for (int i = 2; i < 2001; i++)
            fact[i] = (new BigInteger("" + i)).multiply(fact[i - 1]);
        Scanner scan = new Scanner(System.in);
        StringBuilder builder = new StringBuilder();
        while (scan.hasNext()) {
            int n = scan.nextInt();
            BigInteger res = ((fact[2 * n].divide((fact[n]))).divide(new BigInteger("" + (n + 1))));
            builder.append(res.toString());
            builder.append('\n');
            // (fact[2 * n] / (fact[n] * fact[n])) / (n + 1);
        }
        System.out.print(builder.toString());
    }
}