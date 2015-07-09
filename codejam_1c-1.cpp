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
#define INF 1<<30
using namespace std;
int toInt(string s)
{
	int h =0;int ans =0;
	for(int k =s.size()-1;k>=0;k--)
	{
		ans +=((s[k]-'0')*pow(10,h++));
	}
	return ans;
}
int main()
{
	int n =0;
	cin>>n;
	while(n--)
	{
		string s;
		cin>>s;int b =0;
		for(int i =0;i<s.size();i++)
		{
			if(s[i] == '/'){
			b =i;break;}
		}
		int y = toInt(s.substr(0,b));
		int t =toInt(s.substr(b+1,s.size()-b));
		int count =0;
		while(pow((0.5),count)-(2*y/(double)t)>=0)
		{
			count++;
		}
		cout<<count<<endl;
	}
	return 0;
}