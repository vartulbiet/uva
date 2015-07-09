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
	while(n!=0)
	{
		int arr[1423] ={0};
		for(int i =0;i<n;i++)
		{
			int x =0;
			cin>>x;
			arr[x] = 1;
		}
		bool poss = true;
		int charge =200;
		for(int i =1;i<1423;i++)
		{
			if(arr[i] == 1)
			charge =200;
			if(charge== 0)
			{
			poss= false;
			break;
			}
			charge--;
			
		}
		for(int i =1422;i>=0 ;i--)
		{
			if(arr[i] == 1)
			charge =200;
			if(charge== 0)
			{
			poss= false;
			break;
			}
			charge--;
		}
		if(poss == true)
		cout<<"POSSIBLE"<<endl;
		else
		cout<<"IMPOSSIBLE"<<endl;
		cin>>n;
	}
	return  0;
}