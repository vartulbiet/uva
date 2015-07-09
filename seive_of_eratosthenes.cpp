#include <stdio.h>
#include <string.h>
 #include<iostream>
 using namespace std;
// marks all mutiples of 'a' ( greater than 'a' but less than equal to 'n') as 1.
void markMultiples(bool arr[], int a, int n)
{
    int i = 2, num;
    while ( (num = i*a) <= n )
    {
        arr[ num-1 ] = 1; // minus 1 because index starts from 0.
        ++i;
    }
}
 
void SieveOfEratosthenes(int n,int m)
{
    
    if (n >= 2)
    {
        bool arr[n];
        memset(arr, 0, sizeof(arr));
 
        for (int i=1; i<n; ++i)
        {
            if ( arr[i] == 0 )
            {
                markMultiples(arr, i+1, n);
            }
        }
		for(int i =m-1;i<n;i++)
	if(arr[i] == 0)
	cout<<i+1<<endl;
    }
	
}
 
int main()
{
    int n,m;
	cin>>m>>n;
    printf("Following are the prime numbers below %d\n", n);
    SieveOfEratosthenes(n,m);
    return 0;
}