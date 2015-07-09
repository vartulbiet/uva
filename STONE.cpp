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
#define ull long long 
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<30
using namespace std;
int main()
{
	ull n =0;
	ull m =0;
	cin>>m>>n;
	vector<int>orig;
	vector<ull>first;
	vector<ull>second;
	ull mint = INF;ull maxt = -INF;
	for(ull i =0;i<m;i++)
	{
		ull g =0;
		cin>>g;
		mint = min(mint,g);
		maxt = max(maxt,g);
		orig.PB(g);
	}
	ull newmaxt =0;
	if(mint != 0)
	{
		for(ull i =0;i<m;i++)
		{
			first.PB(maxt - orig[i]);
			newmaxt = max(first[i],newmaxt);
		}
	}
	for(ull i =0;i<m;i++)
	{
		second.PB(newmaxt - first[i]);
	}
		if(n ==0)
		{
			for(ull i =0;i<m;i++){
			cout<<orig[i];
			cout<<" ";}
			cout<<endl;
		}
		else if(n%2!=0)
		{
			for(ull i =0;i<m;i++){
			cout<<first[i];
			cout<<" ";}
			cout<<endl;
		}
		else
		{
			for(ull i =0;i<m;i++){
			cout<<second[i];
			if(i !=m-1)
			cout<<" ";}
			cout<<endl;
		}
	return 0;
}