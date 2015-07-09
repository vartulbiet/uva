#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <queue>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define INF 1<<30
using namespace std;
int main()
{
	int n =0;
	cin>>n;
	while(n!=0)
	{
		queue<int>order;
		vector<deque<int> >vec(n);
		map<int,int>mymap;
		for(int i =0;i<n;i++)
		{
			int j =0;
			cin>>j;
			for(int k =0;k<j;k++)
			{
				int t =0;
				cin>>t;
				mymap[t] = i;
			}
		}
		string p;
		int q;
		cin>>p;
		int k =1;
		while(p!="END")
		{
			
			if(p=="ENQUEUE")
			{
				cin>>q;
				order.push(mymap[q]);
				k++;
				vec[mymap[q]].push_back(q);
			}
			else if(p=="DEQUEUE")
			{
				k--;
				int t =order.front();
				order.pop();
				cout<<vec[t].front()<<endl;
				vec[t].pop_front();
			}
			cin>>p;
		}

		cin>>n;
	}
	return 0;
}