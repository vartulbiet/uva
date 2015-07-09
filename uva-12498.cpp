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
int main()
{
	int n =0;
	cin>>n;int dd =1;
	while(n>0)
	{
		int a,b;
		cin>>a>>b;
		int arr[a][b];
		string s;
		//getline(cin,s);
		for(int i =0;i<a;i++)
		{
			getline(cin,s);
			cin>>s;
			//cout<<s<<endl;
			for(int j =0;j<b;j++)
			{
				if(s[j] =='0')
				arr[i][j] =0;
				else
				arr[i][j] =1;
			}
		}
	//	cout<<a<<b;
		int ans =1<<30;
		for(int i =0;i<a;i++)
		{
			for(int j =0;j<b;j++)
			{
				int f = arr[i][j];int sum =0;
				if(f==0)
				{
					for(int m =0;m<a;m++)
					{
						int temp =1<<30;
						for(int x =0;x<b;x++)
						{
							if(arr[m][j] == 0)
							temp =0;
							if(arr[m][x] == 0 && m!=i && j!=x)
							{
								temp = min(temp,abs(x-j));
							}
						}
						sum+=temp;
					}
					ans = min(ans,sum);
				}
			}
		}
		if(ans==1<<30)
		ans =-1;
		cout<<"Case "<<dd++<<": ";
		cout<<ans<<endl;
		n--;
	}
	return 0;
}