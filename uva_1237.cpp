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
struct node
{
	string s;
	int start;
	int end;
};
int main()
{
	int n =0;
	cin>>n;
	while(n!=0)
	{
		int k =0;
		cin>>k;
		vector<node>vec;
		for(int i =0;i<k;i++)
		{
			struct node t;
			cin>>t.s>>t.start>>t.end;
			vec.PB(t);
		}
		int y =0;
		cin>>y;
		for(int i =0;i<y;i++)
		{
			int u =0;
			cin>>u;
			int kk =0;string ans;
			for(int i =0;i<vec.size();i++)
			{
				if(u>=vec[i].start && u<=vec[i].end)
				{
					ans = vec[i].s;
					kk++;
				}
			}
			if(kk>1 || kk==0)
			cout<<"UNDETERMINED"<<endl;
			else
			cout<<ans<<endl;
		}
		if(n!=1)
		cout<<endl;
		n--;
	}
	return 0;
}