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
#include <queue>
#include <sstream>
#include <iostream>
#include<string.h>
#include<string.h>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define pi 3.141592653589793
using namespace std;
int main()
{
	int t =0;
	scanf("%d\n",&t);
	char vec[100048];
	int r =1;
	while(t>0)
	{
		int arr[100] ={0};
		gets(vec);
		int p = 0;

		for(int i = 0;i<strlen(vec);i++)
		{
			cout<<vec[i];
			if(vec[i] == '>')
			p++;
			else if(vec[i]  == '<')
			p--;
			else if(vec[i] == '+')
			arr[p]++;
			else if(vec[i]  == '-')
			arr[p]--;
			if(p==100)
			p =0;
			if(p<0)
			p=99;
		}
		cout<<"Case "<<r++<<":";
		for(int i =0;i<100;i++)
		printf(" %02X",arr[i]);
		t--;
	}
	return 0;
}