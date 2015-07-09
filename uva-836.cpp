#include<iostream>
#include<vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <string>
#include <queue>
#include <sstream>
#include <iostream>
#include<string.h>
#include <iomanip>
#include <cstdio>
#include<math.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define ull unsigned long long 
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
using namespace std;
int arr[27][27];
int india;

void do_sum()
{
	for(int i =1;i<india;i++)
	arr[i][0]=arr[i][0]+arr[i-1][0];
	for(int i =1;i<india;i++)
	arr[0][i]=arr[0][i]+arr[0][i-1];
	for(int i =1;i<india;i++)
	{
		for(int j =1;j<india;j++)
		arr[i][j] = arr[i][j]+arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
	}
	/*for(int i =1;i<india;i++)
	{
		for(int j =1;j<india;j++)
		cout<<arr[i][j]<<" ";
		cout<<endl;
	}*/
}
int calculate()
{
	int max_sum =0;
	for(int i =0;i<india;i++)
	{
		for(int j =0;j<india;j++)
		{
			for(int k =i;k<india;k++)
			{
				for(int l =j;l<india;l++)
				{
					int temp = arr[k][l];
					if(i-1>=0)
					temp -=arr[i-1][l];
					if( j-1>=0)
					temp-=arr[k][j-1];
					if(i-1>=0 && j-1>=0)
					temp+=arr[i-1][j-1];
					max_sum = max(max_sum,temp);
				}
			}
		}
	}
	return max_sum;
}
int main()
{
	int n =0;
	scanf ("%d", &n);
    getchar ();
	char input [25 + 2] [25 + 2];
	gets(input[0]);
	while(n>0)
	{
		india = 0;
        while ( gets (input [india]) && strlen (input [india]) ) 
		india++;
		 for ( int i = 0; i < india; i++ )
            for ( int j = 0; j < india; j++ )
                arr[i][j] = input[i][j] == '1' ? 1 : -10000;
		
		do_sum();
		int ans = calculate();
		cout<<ans<<endl;
		if(n!=1)
		cout<<endl;
		n--;
	}
	return 0;
}