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
	int m,n;
	scanf("%d%d",&m,&n);
	while(m!=0)
	{
		vector<pair<int,int> >vec;
		for(int i =0;i<n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			vec.PB(make_pair(x-y,x+y));
		}
		sort(vec.begin(),vec.end());
		int pos =0;
		int aux, i=0,ans =n;
		while(pos < m){
            aux = pos;
            
            while(i < n && vec[i].first <= pos)
                aux = max(aux,vec[i++].second);
            
            if(aux == pos) break;
            
            pos = aux;
            --ans;
        }
		printf("%d\n",pos < m? -1 : ans);
		scanf("%d%d",&m,&n);
	}
	return 0;
}