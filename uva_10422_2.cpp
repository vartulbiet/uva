#include <iostream>
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
#define ull long long int  
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<30
#define M 1000000009
using namespace std;

vector<vector<int> > final_arr ={
	0,0,0,0,0,
	1,0,0,0,0,
	1,1,-1,0,0,
	1,1,1,1,0,
	1,1,1,1,1
};
vector<vector<int> >curr_arr;
int main()
{
	int n =0;
	cin>>n;
	while(n--)
	{
		for(int i =0; i< 5 ; i++)
		{
			string s;
			cin>>s;vector<int>arr;
			for(int i =0 ;i <5; i++)
			{
				if(s[i] == '1')
					arr.PB(1);
				else if(s[i] == '0')
					arr.PB(0);
				else
					arr.PB(-1);
			}
			curr_arr.PB(arr);
		}
	}
	return 0;
}