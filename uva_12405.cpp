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
	int n =0;
	cin>>n;
	int tc =1;
	while(n--)
	{
		int m =0;
		cin>>m;
		vector<char>vec(m);
		for(int i =0;i<m;i++)
		cin>>vec[i];
		int count =0;
		for(int i =0;i<vec.size();)
		{
			if(vec[i]!='#')
			{
				count++;
				i =i+3;
			}
			else
			i++;
		}
		cout<<"Case "<<tc++<<": "<<count<<endl;
	}
	return 0;
}