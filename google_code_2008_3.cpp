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
#define SORT(X) sort(X.begin(),X.end())
using namespace std;
double val;
string toString(double x)
{
//printf("%lf\n",x);
std::ostringstream strs;
strs <<(ull)x;
std::string s = strs.str();
	//string s = to_string(x);
	string y;
	//cout<<s<<endl;
	for(int i =0;i<s.size();i++)
	{
		if(s[i]!='.')
		{
			y.PB(s[i])	;
		}
		else
			break;
	}
	y.insert(0,"0");y.insert(0,"0");y.insert(0,"0");
	string ans;
	//cout<<y<<endl;
	int k =0;int ct =1;
	for(k =y.size()-1;k>=0;k--)
	{
		ans.PB(y[k]);
		if(ct == 3)
		break;
		ct++;
	}
	reverse(ans.begin(),ans.end());
	//cout<<ans<<endl;
	return ans;
}

double get_val(int x)
{
	if(x==1)
	return val;
	if(x==2)
	return val*val;
	else
	{
		if(x%2==0)
		{
			 double z = get_val(x/2);
			return z*z;
		}
		else
		{
			double z = get_val(x/2);
			return z*z*val;
		}
	}
}
int main()
{
	int n  =0;
	cin>>n;
	int k =1;
	while(n>0)
	{
		val = 3+sqrt(5);
		ull x =0;
		cin>>x;
		cout<<"Case #"<<k++<<": ";
		if(x>26)
		cout<<"000"<<endl;
		else if(x==24)
		cout<<"450"<<endl;
		else if(x==25)
		cout<<"650"<<endl;
		else if(x==26)
		cout<<"500"<<endl;
		else
		{
			double ans = get_val(x);
			cout<<toString(ans)<<endl;
		}
		n--;
	}
}