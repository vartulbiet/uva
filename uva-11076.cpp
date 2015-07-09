#include <vector>
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
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
typedef unsigned long long ull;
ull fact[20]={1};
using namespace std;
int main()
{
	ull n =0;
	cin>>n;
	for(int i =1;i<20;i++)
	fact[i] = i*fact[i-1];
	while(n!=0)
	{
		vector<ull>vec;
		int arr[10] = {0};
		for(ull i =0;i<n;i++)
		{
			ull x;
			cin>>x;
			arr[x]++;
			vec.push_back(x);
		}
		if(n==1)
		cout<<vec[0]<<endl;
		else
		{
		ull sum =0;
		vector<ull>ans;

			for(ull j =0;j<n;j++)
			{
			sum +=(vec[j]*fact[n-1]);
			}
		ull value =0;ull C =1;
		for(ull i =0;i<n-1;i++)
		{
			C=C*10+1;
		}
		//cout<<value;
		for(ull i =0;i<10;i++)
		{
			if(arr[i]>1)
			sum =sum/fact[arr[i]];
		}
		cout<<sum*C<<endl;
		}
		cin>>n;
	}
	return 0;
}