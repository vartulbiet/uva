#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<map>
using namespace std;
int arr[50][50];
int ans;
int r,c;
int dist[50][50];
int m,n;
map<pair<int,int>,bool>mymap;
void primsAlgo(){
    int selected[m],i,j,ne; //ne for no. of edges
	int min,x,y;

    for(i=0;i<m;i++)
       selected[i]=false;

    selected[0]=true;
    ne=0;

    while(ne < m-1){
       min=1<<30;

       for(i=0;i<m;i++)
       {
          if(selected[i]==true){
         for(j=0;j<m;j++){
            if(selected[j]==false){
               if(min > dist[i][j])
               {
               min=dist[i][j];
               x=i;
               y=j;
               }
            }
         }
          }
       }
       selected[y]=true;
       ans+=min;
       ne=ne+1;
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
	primsAlgo();
    cout<<ans<<endl;
    return 0;
}
