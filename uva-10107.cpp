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
	vector<long long>vec;
	int fish =0;
	while(scanf("%d",&n)!=EOF)
	{
		vec.push_back(n);
		fish++;
		sort(vec.begin(),vec.end());
		if(fish%2==0)
		cout<<(vec[(fish-1)/2]+vec[(fish)/2])/2<<endl;
		else
		cout<<vec[fish/2]<<endl;	
	}
	return 0;
}