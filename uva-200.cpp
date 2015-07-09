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
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define pi 3.141592653589793
using namespace std;
int main()
{
	char temp[21];
	char arr[5000][21];
	int i =0;
	int ans[26]={0};
	while(scanf("%s",temp))
	{
		if(temp[0]=='#')
		break;
		for(int k =0;k<strlen(temp);k++)
		{
		arr[i][k] = temp[k];
		//cout<<temp[k];
		}
		for(int j =strlen(temp);j<21;j++)
		arr[i][j] ='a';
		i++;
	}
	for(int k =0;k<21;k++)
	{
		for(int j =0;j<i;j++)
		{
		if(arr[j][k]>64 && arr[j][k]<91)
		ans[(arr[j][k]-65)]++;
		if(ans[arr[j][k]-65]==1)
		cout<<arr[j][k];
		}
	}
	cout<<endl;
	return 0;
}