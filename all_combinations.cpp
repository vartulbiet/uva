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
#define pi 3.141592653589793
using namespace std;
void all_combinations(string x,string y)
{
	if(x.size()==2)
	{
	cout<<x<<endl;
	return;
	}
	if(x.size()>3)
	return;
	else
	{
		for(int i =0;i<y.size();i++)
		{
			x.push_back(y[i]);
			all_combinations(x,y);
			x.erase(x.begin()+x.size()-1);
		}
	}
}
int main()
{
	string s;
	s= "EHT";string x;
	all_combinations(x,s);
}