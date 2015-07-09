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
int main()
{
	int n =0;
	cin>>n;
	while(n>0)
	{
		int m =0;
		cin>>m;
		string h;
		bool bt =true;
		getline(cin,h);
		vector<pair<int,string> >vec;
			for(int i =0;i<m;i++)
			{
				getline(cin,h);
				vec.PB(make_pair(h.size(),h));
			}
			sort(vec.begin(),vec.end());
			for(int i =0;i<vec.size();i++)
			{
				for(int j =i+1;j<vec.size();j++)
				{
					int k =0;
					for(k =0;k<vec[i].second.size();k++)
					{
						if(vec[i].second[k]!=vec[j].second[k])
						break;
					}
					if(k==vec[i].second.size()){
					bt =false;
					break;
					}
				}
				if(!bt)
				break;
			}
			if(!bt)
			cout<<"NO";
			else
			cout<<"YES";
			cout<<endl;
			n--;
	}
	return 0;
}