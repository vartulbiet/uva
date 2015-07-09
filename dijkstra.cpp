#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<map>
using namespace std;
int arr[100][100];
int ans;
int r,c;
int dist[100][100];
int m,n;
map<pair<int,int>,bool>mymap;

int find_set(int*arr,int m)
{
	if(arr[m] == m)
	return m;
	else
	return arr[m] = find_set(arr,arr[m]);
}
void merge_set(int*arr,int m,int n)
{
	arr[find_set(arr,m)] = find_set(arr,n);
}

void kruskals()
{
        	vector<pair<int,pair<int,int> > >vec;
	for(int i =0;i<m;i++)
	{
		for(int j =0;j<m;j++)
		{
		if(dist[i][j]>0)
		{
			pair<int,pair<int,int> >p;
                    pair<int,int>x;
                    x.first= i;
                    x.second =j;
                    p.first =dist[i][j];
                    p.second =x;
                    vec.push_back(p);
					}
		}
	}
       int arr[m];
	for(int i =0;i<m;i++)
	arr[i] = i;
	ans =0;
	sort(vec.begin(),vec.end());
	while(vec.size()!=0)
	{
		pair<int,pair<int,int> >p = vec.front();
		vec.erase(vec.begin());
		if(find_set(arr,p.second.first)!=find_set(arr,p.second.second))
		{
			ans +=p.first;
			merge_set(arr,p.second.first,p.second.second);
			//cout<<p.second.first<<"--"<<p.second.second<<endl;
		}
	}
}
void min_dist()
{
      std::map<pair<int,int>,bool>::iterator it;
        std::map<pair<int,int>,bool>::iterator bt;
     ans = 0;m =0;n=0;
      for(it = mymap.begin();it!=mymap.end();it++ )
      {
          int sum =0;m;n =0;
          for(bt = mymap.begin();bt!=mymap.end();bt++)
          {
               dist[m][n++] = max(abs(bt->first.first-it->first.first),abs(bt->first.second-it->first.second));
			   
          }
		  m++;
      }
	  m  =n =mymap.size();
}

void func()
{
        for(int i =0;i<r;i++)
        {
            for(int j =0;j<c;j++)
            {
                pair<int,int>p =make_pair(i,j);
                if(arr[i][j] == 1)
                {
                  mymap[p] = true;
				//  cout<<i<<" "<<j<<endl;
                }
            }
        }
    
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin>>r>>c;

    for(int i =0;i<r;i++)
    {
         for(int j =0;j<c;j++)
         {
             cin>>arr[i][j];
         }
    }
    
   func();
    min_dist();
	kruskals();
    cout<<ans<<endl;
    return 0;
}
