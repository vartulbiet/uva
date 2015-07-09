import java.math.BigInteger;
public class BigInt 
{
  public static void main(String[] args) 
  {
  int place = Integer.parseInt(args[0]);
	while(place>0)
	{
		double x =5;
	  double bigInteger1 = Math.pow(x,.5); 
	  double bigIntResult2 =
		bigInteger1.multiply(bigInteger1); 
	  System.out.println("Result is  ==> " + bigIntResult2);
	  place--;
	}
  }
}