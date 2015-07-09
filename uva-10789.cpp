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
bool arr[2005];
void prime_number()
{
	arr[0] = false;
	arr[1] = false;
	arr[2] = true;
	arr[3] = true;
	for(int i =4;i<2005;i++)
	{
		if(i%2 == 0)
		arr[i] = false;
		else
		{
			int j =2;
			int y =sqrt(i)+1;
			for(j =2;j<y;j++)
			{
				if(i%j==0)
				{
				arr[i] = false;
				break;
				}
			}
			if(j==y)
				arr[i] = true;
		}
	}
}
int main()
{
	int n = 0;
	prime_number();
	cin>>n;
	string s;
	getline(cin,s);
	int tt =1;
	while(n>0)
	{
		getline(cin,s);
		map<char,int>mymap;
		for(int i =0;i<s.size();i++)
		mymap[s[i]]++;
		string ans;
		for(std::map<char,int>::iterator it = mymap.begin();it!=mymap.end();it++)
		if(arr[it->second]==true)
		ans.PB(it->first);
		if(ans.size()==0)
		ans+="empty";
		cout<<"Case "<<tt++<<": "<<ans<<endl;;
		n--;
	}
	return 0;
}