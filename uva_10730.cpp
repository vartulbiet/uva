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
#define graphAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<20
using namespace std;
int main()
{
	int n =0;
	cin>>n;
	while(n!=0)
	{
		//cout<<n<<endl;
		string s;
		cin>>s;
		//cout<<s<<endl;
		vector<int>arr(n);
		for(int i =0;i<n;i++)
		{
			int x =0;
			cin>>x;
		//	cout<<x;
			arr[i] =x;
		}bool bt =true;
		for(int i =0;i<n;i++)
		{
			for(int j =i+1;j<n;j++)
			{
				int y = arr[i] - arr[j];
				for(int k =j+1;k<n;k++)
				{
					int z= arr[j] -arr[k];
					if(y==z)
					{
					bt= false;
					break;
					}
				}
				if(!bt)
				break;
			}
			if(!bt)
				break;
		}
		if(bt)
		cout<<"yes"<<endl;
		else
		cout<<"no"<<endl;
		cin>>n;
	}
	return 0;
}