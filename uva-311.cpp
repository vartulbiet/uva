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

using namespace std;

int main()
{
	int a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	while(a!=0 || b!=0 || c!=0 || d!=0 || e!=0 || f!=0)
	{
		int x =a*1+b*4+c*9+d*16+e*25+f*36;
		int t =0;
		while(x>0){
		x=x-36;
		t++;
		}
		cout<<t<<endl;
		cin>>a>>b>>c>>d>>e>>f;
	}
}