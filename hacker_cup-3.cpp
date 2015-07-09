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
#define ull unsigned long long 
#define pi 3.141592653589793
using namespace std;
int a,b;
int vec[500][500];
char arr[500][500];
void init()
{
	for(int i =0;i<a;i++)
	{
		for(int j =0;j<b;j++)
		{
			vec[i][j] =0;
			arr[i][j] = ' ';
		}
	}
}
int get_length_row(int i,int j)
{
	int h =0;
	for(int k =j-1;k>=0;k--)
	{
		if(arr[i][k]=='.')
		h++;
		else
		break;
	}
	return h;
}
int get_length_col(int i,int j)
{
	int h =0;
	for(int k =i-1;k>=0;k--)
	{
		if(arr[k][j]=='.')
		h++;
		else
		break;
	}
	return h;
}
int get_ans(int r,int c,int val)
{
	int ans =0;
	for(int i =0;i<r;i++)
	{
		for(int j =0;j<c;j++)
		{
			if(vec[i][j] == val)
			{
				ans =max(ans,(val+(max(get_length_row(i,j),get_length_col(i,j)))*2));
			}
		}
	}
	return ans;
}

int get_maximum(int row,int colu)
{
	int val =0;
	for(int i =0;i<row;i++)
	{
		for(int j =0;j<colu;j++)
		val =max(val,vec[i][j]);
	}
	return val;
}
int get_column()
{
	for(int i =0;i<b;i++)
	{
		bool tt =true;
		for(int j =0;j<a;j++)
		{
			if(arr[j][i]='.')
			{
			tt=false;
			break;
			}
		}
		if(tt == true)
		return i;
	}
}
int get_row()
{
	for(int i =0;i<a;i++)
	{
		bool tt =true;
		for(int j =0;j<b;j++)
		{
			if(arr[i][j]='.')
			{
			tt=false;
			break;
			}
		}
		if(tt == true)
		return i;
	}
}
void set_vec()
{
	vec[0][0] =1;
	for(int i =1;i<a;i++)
	{
		if(arr[i][0]=='.')
			vec[i][0] =vec[i-1][0]+1;
		else
		vec[i][0] = 0;
	}
	for(int i =1;i<b;i++)
	{
	if(arr[0][i]=='.')
	vec[0][i] = vec[0][i-1]+1;
	else
	vec[0][i] = 0;
	}
	for(int i =1;i<a;i++)
	{
		for(int j =1;j<b;j++)
		if(arr[i][j]=='.')
		vec[i][j] = max(vec[i][j],vec[i][j-1]+1);
		else
		vec[i][j] = 0;
	}
	for(int i =1;i<b;i++)
	{
		for(int j =1;j<a;j++)
		if(arr[i][j]=='.')
		vec[j][i] = max(vec[j][i],vec[j-1][i]+1);
		else
		vec[i][j] = 0;
	}
}

int main()
{
	int n =0;
	cin>>n;
	while(n>0)
	{
		cin>>a>>b;
		for(int i =0;i<a;i++)
		{
			for(int j =0;j<b;j++)
			{
				char f;
				cin>>f;
				arr[i][j] =f;
			}
		}
		set_vec();
		for(int i =0;i<a;i++)
		{
			for(int j =0;j<b;j++)
			{
			cout<<vec[i][j];
			}
			cout<<endl;
		}
		
		int row = get_row();
		int col = get_column();
		if(row==0)
		row =a;
		if(col ==0)
		col =b;
		int get_max = get_maximum(row,col);
		cout<<row<<col<<get_max<<endl;
		if(row>1 && col>1)
		{
		int ans = get_ans(row,col,get_max);
		cout<<ans;
		}
		else
		cout<<get_max;
		/*if(a>1 && b>1)
		cout<<(a-1)+b+(max(a,b)-1)*2;
		else
		cout<<(a-1)+b;*/
		cout<<endl;
		n--;
	}
	return 0;
}