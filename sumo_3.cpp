#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <numeric>
#include <bitset>
#define REP(i, a, b) for ( int i = int(a); i <= int(b); i++ )
#define PB push_back
#define MP make_pair
#define for_each(it, X) for (__typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)
#define DFS_WHITE -1
#define DFS_BLACK 1
#define MAXN 1000
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define INF 1<<30
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
int main()
{
	int num_integers =0;
	cout<<"Enter number of integers"<<endl;
	cin>>num_integers;
	cout<<"Enter integers"<<endl;
	vector<int>arr;
	for(int i =0;i<num_integers;i++)
	{
		int x =0;
		cin>>x;
		arr.PB(x);
	}
	int sum =0;
	cout<<"Enter the value of K"<<endl;
	cin>>sum;
	sort(arr.begin(),arr.end());
	int  i =0;int j = arr.size()-1;
	bool bt =true;
	while(i<j && bt)
	{
		if(arr[i]+arr[j] == sum)
		{
			cout<<arr[i]<<" "<<arr[j]<<endl;
			bt = false;
		}
		else if(arr[i]+arr[j] > sum)
		j--;
		else
		i++;
	}
	if(bt)
	cout<<"No such element exists"<<endl;
	return 0;
}