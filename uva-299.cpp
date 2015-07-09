#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#define INF 1<<30
using namespace std;
int main()
{
	int t =0;
	cin>>t;
	while(t>0)
	{
		int n =0;
		cin>>n;
		vector<int>arr(n);
		for(int i =0 ;i<n;i++)
		cin>>arr[i];
		int ans =0;
		for(int i =0;i<n;i++)
		{
			for(int j =i+1;j<n;j++)
			{
				if(arr[i]>arr[j])
				{
					int temp =arr[i];
					arr[i] =arr[j];
					arr[j] = temp;
					ans++;
				}
			}
		}
		cout<<"Optimal train swapping takes "<<ans<<" swaps."<<endl;
		//cout<<ans<<endl;
		t--;
	}
	return 0;
}