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
vector<ull> ullTOvec(ull n)
{
	vector<ull>ans;
	while(n!=0)
	{
		ans.PB(n%10);
		n =n/10;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
ull vectorToull(vector<ull>x)
{
	ull n = 0;
	reverse(x.begin(),x.end());
	for(ull i =0;i<x.size();i++)
	{
		n += x[i]*pow((double)10,i);
	}
	return n;
}
bool isPalindrome(vector<ull>a)
{
	vector<ull>b;
	b = a;
	reverse(b.begin(),b.end());
	if(a == b)
	return true;
	else;
	return false;
}
ull val;
ull recurse(ull n)
{
	if(isPalindrome(ullTOvec(n)))
	{
		val = n;
		return 0;
	}
	else
	{
		vector<ull>temp = ullTOvec(n);
		reverse(temp.begin(),temp.end());
		return 1+ recurse(n+vectorToull(temp));
	}
}
int main()
{
	ull n =0;
	cin>>n;
	while(n--)
	{
		ull num =0;val =0;
		cin>>num;
		cout<<recurse(num)<<" ";
		cout<<val<<endl;
	}
	return 0;
}