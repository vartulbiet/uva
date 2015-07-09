#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#define INF 1<<30
using namespace std;
int main()
{
	int t =0;
	cin>>t;int tt =1;
	while(t>0)
	{
		int a,b,c;
		cin>>a>>b>>c;
		cout<<"Case "<<tt++<<": ";
		if(!(a+b>c && b+c>a && a+c>b && a-c<b && b-c<a && a-b<c))
		cout<<"Invalid";
		else if(a==b==c)
		cout<<"Equilateral";
		else if(a==b || b==c || a==c)
		cout<<"Isosceles";
		else
		cout<<"Scalene";
		cout<<endl;
		t--;
	}
	return 0;
}