
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
using namespace std;

int minCoins(vector< int > a , int S) {
sort(a.begin(),a.end());
    int matrix[a.size()+1][S+1];
    //memset(matrix,0,sizeof(matrix));
     for(int i =0;i<a.size()+1;i++)
        for(int j =0;j<=S;j++)
        matrix[i][j] =1<<10;
    for(int i =0;i<a.size()+1;i++)
        matrix[i][0] =0;
    
    for(int i =1;i<=a.size();i++)
    {
            for(int j =1;j<=S;j++)
            {
                    if(a[i-1] == j)
                        matrix[i][j] =1;
                    else if(a[i-1]>j)
                        matrix[i][j] = matrix[i-1][j];
                    else if(j>a[i] && matrix[i][j-a[i]]>0)
                        matrix[i][j] = min(matrix[i][j],matrix[i][j-a[i]]+1);
            }
    }
	for(int i =0;i<a.size()+1;i++)
	{
        for(int j =0;j<=S;j++)
		cout<<matrix[i][j]<<" ";
		cout<<endl;
		}
    if(matrix[a.size()][S] ==1<<30)
        return -1;
    else
    return matrix[a.size()][S];
}
int main()
{
	vector<int>arr;
	arr.PB(1);
	arr.PB(3);
	arr.PB(5);
	cout<<minCoins(arr,11);
}