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
long long int fact[30];
void create_fact()
{
	fact[0] =1;
	for(int i =1;i<30;i++)
	{
		fact[i] =fact[i-1]*i;
	}
}
string s;
string ans;
void recurse(int k,int sz,int div,int curr)
{
	if(ans.size()==s.size())
	return;
	else
	{
	int start =sz/div;
	int pos =0;
	while(start<=sz)
	{
		if(k>start)
		pos++;
		else
		break;
		start= 2*start;
	}
	//if(pos>=ans.size())
	ans.PB(s[curr]);
	//else
	//ans.insert(s.begin()+pos+1,s[curr]);
	recurse(k-(pos)*sz/div,sz/div,div+1,curr+1);
	}
	
}
int main()
{
	int n =0;
	create_fact();
	cin>>n;
	while(n>0)
	{
		cin>>s;
		int k;
		int sz =s.size();
		int perm= fact[s.size()];
		cin>>k;
		ans.PB(s[0]);
		recurse(k,perm,2,1);
		cout<<ans<<endl;
	}
	return 0;
}