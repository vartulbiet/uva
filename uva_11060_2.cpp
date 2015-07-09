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
#define graphAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<10
using namespace std;
 int arr[105][105]; bool visited[105];
 int degree[105];
 vector<string>brr;
 void init()
 {
	for(int i =0;i<105;i++)
	{
		for(int j=0;j<105;j++)
		arr[i][j] =0;
		visited[i] = false;
		degree[i] =0;
	}
 }

 int n;


 void topo_sort()
 {
 bool done =false;
	while(!done)
        {
            done = true;
            for(int i  = 0;i<n;i++)
            if(!visited[i]&&degree[i]==0)
            {
                done=false;
                visited[i]=true;
                cout<<" "<<brr[i];
                for(int j =0;j<n;j++)
                    if(arr[j][i]==1)
                        degree[j]--;
                i = -1;
            }
        }
 }
 

int main()
{
	int tc =1;
		while(scanf("%d",&n)!=EOF)
		{
			init();
			map<string,int>mymap;
			string s;getline(cin,s);
			for(int i =0;i<n;i++)
			{
				getline(cin,s);
			//	cout<<s<<"-";
				mymap[s] =i;
				brr.PB(s);
			}
			int m =0;
			cin>>m;
			for(int i =0;i<m;i++)
			{
				string x,y;
				cin>>x>>y;
				//cout<<x<<y;
				arr[mymap[y]][mymap[x]] =1;
				degree[mymap[y]]++;
			}
			cout<<"Case #"<<tc++<<": Dilbert should drink beverages in this order:";
			topo_sort();
			cout<<"."<<endl;
			cout<<endl;
			brr.erase(brr.begin(),brr.end());
		}
		return 0;
}