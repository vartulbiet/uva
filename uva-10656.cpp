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
	int n =0;
	cin>>n;
	while(n>0)
	{
		vector<int>vec(n);
		for(int i =0;i<n;i++)
		{
			int x ;
			cin>>x;
			vec[i] = x;
		}
		vector<int>ans;
		int j = 0;
		while(j<vec.size())
		{
			if(vec[j] ==0)
			{
				vec.erase(vec.begin()+j);
				j =0;
			}
			else
			j++;
		}
		if(vec.size()==0)
		cout<<"0";
		else
		{
		for(int i =0;i<vec.size();i++)
		{
			cout<<vec[i];
			if(i != vec.size()-1)
			cout<<" ";
		}
		}
		cout<<endl;
		cin>>n;
	}
	return  0;
}