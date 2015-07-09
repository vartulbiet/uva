 #include <iostream>
    #include <cmath>
    #include <conio.h>
 
using namespace std;
 
void findPrimes(int arraySize);
 
int main()
{
  endl(cout);
     endl(cout);
     cout << "Welcome to the Sieve of Atkins\n" << endl;
 
     int arraySize;
     int numberPrimes = 2;
 
     cout << "Input a positive integer to find all the prime numbers up to and "
          << "\nincluding that number: ";
 
     cin >> arraySize;
     endl (cout);
 
/**************************************************************************************
                  CALCULATIONS IN BELOW METHOD TAKEN FROM:
                http://en.wikipedia.org/wiki/Sieve_of_Atkin
                  AND TURNED INTO A C++ PROGRAM
**************************************************************************************/
    int sqrtArraySize;
    bool isPrime [arraySize] ;
 
    for (int i = 0; i <= arraySize; i++)
    {
        isPrime[i] = false;
    }
 
    sqrtArraySize = sqrt(arraySize);
/**************************************************************************************
                     put in candidate primes:
                     integers which have an odd number of
                     representations by certain quadratic forms
**************************************************************************************/
for (int x = 1; x <= sqrtArraySize; x++)
{
        for (int y = 1; y <= sqrtArraySize; y++)
        {
            int n = 4 * x * x + y * y;
 
                    if (n <= arraySize && (n % 12 == 1 || n % 12 == 5))
                    {
                        isPrime[n] = !isPrime[n];
                    }
 
                    n = 3 * x * x + y * y;
 
                    if (n <= arraySize && (n % 12 == 7))
                    {
                        isPrime[n] = !isPrime[n];
                    }
 
                    if (x > y)
                    {
                        n = 3 * x * x - y * y;
 
                            if (n <=arraySize && n % 12 == 11)
                            {
                                isPrime[n] = !isPrime[n];
                            }
                    }
        }//end 2nd FOR LOOP
}//end 1st FOR LOOP
 
/***************************     Eliminate composites by sieving    ******************/
for (int n = 5; n <= sqrtArraySize; n++)
{
        if (isPrime[n])
        {
            int omit = n * n;
 
                    for (int k = omit; k <=arraySize; k +=omit)
                    {
                        isPrime[k] = false;
                    }
        }
}
 
        if (arraySize > 2)
        {
                    cout << 2 << "\t" << 3 << "\t";//adds 2 and 3 to the output
        }
/*********************************   Output Prime Numbers    *************************/
   for (int x = 2; x <= arraySize; x++)
   {
        if (isPrime[x])
        {
            cout << x << "\t" << flush;
            numberPrimes++;
        }
   }
 
   cout << "\n\nNumber of Primes: " << numberPrimes << endl;
 
   return 0;
}