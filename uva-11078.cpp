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
	int n=0;
	cin>>n;
	while(n>0)
	{
		int t =0;
		cin>>t;
		int value = -(1<<30);
		int ans = -(1<<30);
		int last =0;
		for(int i =0;i<t;i++)
		{
			int g;
			cin>>g;
			
			if(g>value)
			{
				ans = max(ans,value-g);
				value = g;
			}
			else
				ans = max(ans,value-g);
		}
		cout<<ans<<endl;
		n--;
	}
	return 0;
}