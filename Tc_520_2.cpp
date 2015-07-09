#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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

	int countCompetitors(vector <int> ratings, int K) {
		int u = ratings[0];
		int c = ceil((double)ratings.size()/(double)K);
		cout<<c<<endl;
		vector<vector<int> >hold(c);
		sort(ratings.begin(),ratings.end());
		reverse(ratings.begin(),ratings.end());
		int j =0;
		for(int i =0;i<ratings.size();i++)
		{
			cout<<ratings[i]<<" ";
			hold[j++].push_back(ratings[i]);
			cout<<j<<endl;
			j %= K;
		}
		cout<<endl;
		int t =0;
		for(int i =0;i<hold.size();i++)
		{
			for(int j =0;j<hold[i].size();j++)
			cout<<hold[i][j]<<" ";
			cout<<endl;
		}
		for(int i =0;i<hold.size();i++)
		{
			for(int j =0;j<hold[i].size();j++)
			if(hold[i][j] == u)
			t = i;
		}
		int ans =0;
		for(int i =0;i<hold[t].size();i++)
		if(hold[t][i]>u)
		ans++;
		return ans;
	}
int main()
{	
	
	int y =0;
	cin>>y;vector<int>x(y);
	for(int i =0;i<y;i++)
	cin>>x[i];
	int vv =0;
	cin>>vv;
	cout<<countCompetitors(x,vv);
	return 0;
}
