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
#include <string.h>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define ull unsigned long long 
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
using namespace std;
#define INF 1<<20
int graph[27][27];
vector<char>arr[27][27];
void init()
{
	vector<char>x;
	for(int i =0;i<27;i++)
		for(int j=0;j<27;j++)
		{
			graph[i][j] = INF;
			arr[i][j] = x;
		}
}

void floyd_warshall()
{
	for(int i =0;i<27;i++)
	{
		for(int m =0; m<27;m++)
		{
			for(int n =0;n<27;n++)
			{
				if(graph[m][n] > (graph[m][i] + graph[i][n])){
					graph[m][n] = graph[m][i] + graph[i][n];
					vector<char>AB;
					AB.reserve( arr[m][i].size() + arr[i][n].size() ); // preallocate memory
					AB.insert( AB.end(), arr[m][i].begin(), arr[m][i].end() );
					AB.insert( AB.end(), arr[i][n].begin(), arr[i][n].end() );
					arr[m][n] = AB;
				}
			}
		}
	}
}

int main()
{
	int m,n;
	cin>>m>>n;

	init();

	while(n--)
	{
		char x,y;
		cin>>x>>y;
	
		int z;
		cin>>z;
		graph[x-'A'][y-'A'] = z;
		vector<char>vec,dec;
		vec.PB(y);dec.PB(x);
		arr[x-'A'][y-'A'] = vec;
		graph[y-'A'][x-'A'] = z;
		arr[y-'A'][x-'A'] = dec;
	}
	floyd_warshall();
	int q =0;

	cin>>q;

	for(int i =0;i<q;i++)
	{
		char a,b;
		cin>>a>>b;
		
		//cout<<graph[a-'A'][b-'A']<<arr[a-'A'][b-'A'].size()<<endl;
		cout<<a;
		for(int i =0;i<arr[a-'A'][b-'A'].size();i++)
		{
			cout<<" "<<arr[a-'A'][b-'A'][i];
		}
		cout<<endl;
	}
	return 0;
}