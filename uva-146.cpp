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
string x;

int main()
{
	cin>>x;
	while(x!="#")
	{
		string y = x;
		std::next_permutation(y.begin(),y.begin()+y.size());
		sort(x.begin(),x.end());
		if(y==x)
		cout<<"No Successor"<<endl;
		else
		cout<<y<<endl;
		cin>>x;
	}
	return 0;
}