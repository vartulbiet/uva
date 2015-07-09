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
#define ll long long int
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<30
using namespace std;
vector<ll>twos;
vector<ll>threes;
vector<ll>total;
void generate()
{
	twos.PB(1);
	threes.PB(1);
	for(int i =1;i<32;i++)
	twos.PB(twos[twos.size()-1]*2);
	for(int i =0;i<32;i++)
	threes.PB(threes[threes.size()-1]*3);
	for(int i =0;i<twos.size();i++)
	{
		for(int j =0;j<threes.size();j++)
		{
			total.PB(twos[i]*threes[j]);
		}
	}
	sort(total.begin(),total.end());
		/*for(int j =0;j<total.size();j++)
		{
			cout<<total[j]<<" ";
		}
		cout<<endl;*/
}
int search_total(ll n,int i ,int j)
{
	//cout<<i<<" "<<j<<endl;
	if(i>j)
	return -1;
	else
	{
		int mid = i+(j-i)/2;
		if(total[mid] == n)
		{
	//	cout<<mid<<endl;
		return mid;
		}
		if(mid+1<=j && total[mid+1]>n && total[mid]<n)
		{
		return mid+1;
		}
		if(mid-1>=i && total[mid-1]<n && total[mid]>n)
		{
		return mid;
		}
		else if(total[mid]>n)
		{
			search_total(n,i,mid-1);
		}
		else if(total[mid]<n)
			search_total(n,mid+1,j);
	}
}
int main()
{
	generate();
	long long int n =0;
	scanf("%lld",&n);
	while(n!=0)
	{
		printf("%lld\n",total[search_total(n,0,total.size()-1)]);
		/*for(int i =0;i<total.size();i++)
		if(n<=total[i])
		{
		printf("%lld\n",total[i]);
		break;}*/
		scanf("%lld",&n);
	}
	return 0;
}