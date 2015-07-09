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
#define INF 1<<30
using namespace std;
int main()
{
std::map<int,int> mymap;
//std::unordered_map<int,int>mymap;
vector<int>vec;
	int n =0;int i =0;
	while(scanf("%d",&n)==1)
	{
		if(mymap.find(n)==mymap.end())
		vec.PB(n);
		mymap[n]++;
		
	}
	for(int i =0;i<vec.size();i++)
	{
		cout<<vec[i]<<" "<<mymap[vec[i]]<<endl;
	}
	return 0;
}