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
#define INF 1<<10
using namespace std;
int main()
{
	int n =0;
	cin>>n;
	while(n!=0)
	{
		vector<int>temp;
		int ans =0;
		for(int i =0;i<n;i++)
		{
			int x;
			cin>>x;
			for(int j =0;j<x;j++)
			{
				int y =0;
				cin>>y;
				temp.PB(y);
			}
			sort(temp.begin(),temp.end());
			int f = temp[0];
			int l = temp[temp.size()-1];
			temp.erase(temp.begin());
			temp.erase(temp.begin()+temp.size()-1);
			ans+=(l-f);
		}
		cout<<ans<<endl;
	}
	return 0;
}