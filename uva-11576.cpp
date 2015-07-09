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
	cin>>n;
	while(n>0)
	{
		int a,b;
		cin>>a>>b;
		string s;
		getline(cin,s);
		getline(cin,s);
		int ans = a;
		string last =s;
		for(int i =1;i<b;i++)
		{
			getline(cin,s);
			string fst = s;
			string temp = last;
			int r =0;
			for(int j =0;j<a;j++)
			{
				int y =0;int inc =j;bool bt = true;
				for(int k =0;k<a,inc<a;k++ )
				{
					if(temp[inc++] ==fst[k])
					y++;
					else{
					bt =false;
					break;}
				}
				if(!bt)
				y =0;
				r = max(r,y);
			}
		//	cout<<r<<endl;
			int add = a-r;
			ans+=add;
			last = fst;
		}
		cout<<ans<<endl;
		n--;
	}
	return 0;
}