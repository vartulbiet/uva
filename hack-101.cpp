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
  while(n--)
  {
    int x = 0;
    cin>>x;
    string s;
      	getline(cin,s);
    vector<string>vec(2);vector<string>temp(2);
    for(int i =0;i<2;i++)
    {
      getline(cin,s);
      vec[i] = s;
      temp[i] = s;
    }
    vector<string>arr;string y;
    for(int i = 0;i<x;i++)
	y.PB('F');
    arr.PB(y);
    arr.PB(y);

    for(int i =0;i<2;i++)
    {
    	for(int j =0;j<x;j++)
        {
          if(vec[i][j] == '0' && arr[i][j] =='F')
          {
          	if(j+1<x && vec[i][j+1] == '0'&& arr[i][j+1] =='F')
            {arr[i][j] = 'T'; arr[i][j+1] = 'T';}
            else if(i+1<2 && vec[i+1][j] == '0' && arr[i+1][j] =='F')
            {arr[i][j] = 'T'; arr[i+1][j] = 'T';}
           else   if(i-1>=0 && vec[i-1][j] == '0' && arr[i-1][j] =='F')
            {arr[i][j] = 'T'; arr[i-1][j] = 'T';}
           else  if(j-1>=0 && vec[i][j-1] == '0' && arr[i][j-1] =='F')
            {arr[i][j] = 'T'; arr[i][j-1] = 'T';}
          }
        }
    }
    bool bt = true;
     for(int i =0;i<2;i++)
    {
    	for(int j =0;j<x;j++)
        {
			cout<<arr[i][j]<<" ";
          if(!((arr[i][j] == 'T' && vec[i][j] =='0') ||(arr[i][j] == 'F' && vec[i][j] =='1')))
            bt = false;
        }
		cout<<endl;
     }
    if(bt)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }
  return 0;
}