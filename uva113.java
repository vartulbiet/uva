import java.math.BigInteger;
import java.util.Scanner;
 
public class uva113{
 
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        StringBuilder builder = new StringBuilder();
        while (scan.hasNext()) {
            BigInteger n = scan.nextBigInteger();
			BigInteger m = scan.nextBigInteger();
			double	nn = Math.log(n.doubleValue());
			double	mm = Math.log(m.doubleValue());
			double res = mm/nn;
    
    
			System.out.print(res);
            // (fact[2 * n] / (fact[n] * fact[n])) / (n + 1);
        }
    }
}