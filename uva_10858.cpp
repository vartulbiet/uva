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
#define ull long long int  
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<30
#define M 1000000009
using namespace std;
vector<vector<int> >vec;
vector<int>arr;
void factorize(int x,int c)
{
	for(int i = c ; i*i <= x ; i++)
	{
		if(x%i == 0)
		{
			arr.PB(i);
			factorize(x/i, i );
			arr.pop_back();
		}
	}
	arr.PB(x);
	vec.PB(arr);
	arr.pop_back();
}
int main()
{
	int x =0;
	while(cin>>x)
	{
		if(x == 0)
			break;
		factorize(x,2);
		cout<<vec.size()-1<<endl;
		for(int i =0 ; i< vec.size()-1 ;i ++)
		{
			vector<int>arr = vec[i];
			for(int i =0 ; i < arr.size(); i++){
					if(i>0){
						cout<<" ";
					}
					cout<<arr[i];
				}
			cout<<endl;
		}
	}
	return 0;
}