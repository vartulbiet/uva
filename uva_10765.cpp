#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

vector <int> v[10005];
int dfs_c,clk[10005],ap[10005],low[10005],pt[10005];

int tarjan(int x,int par){
    int lowx = clk[x] = ++dfs_c, child = 0, cp = 0;
    for(int i=0;i<v[x].size();i++){
        int y = v[x][i];
        if(clk[y]==0){
            child++;
            int lowy = tarjan(y,x);
            lowx = min(lowx,lowy);
            if(lowy>=clk[x]){
                ap[x] = 1;
                cp++;
            }
        }else if(y!=par && clk[y] < clk[x]){
            lowx = min(lowx,clk[y]);
        }
    }
    if(par<0 && child==1)    ap[x] = 0;
    if(par<0)    pt[x] = cp;
    else if(ap[x]==1)    pt[x] = cp+1;
    else    pt[x] = 1;
    low[x] = lowx;
    return lowx;
}
bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.second!=b.second)    return a.second > b.second;
    return a.first < b.first;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    for(int N,M;scanf(" %d %d",&N,&M)==2 && (N+M);){
        for(int i=0;i<N;i++)    
            v[i].clear();
        for(int x,y;scanf(" %d %d",&x,&y)==2 && x!=-1;)
            v[x].push_back(y), v[y].push_back(x);
        memset(clk,0,sizeof(clk));
        memset(ap,0,sizeof(ap));
        memset(pt,0,sizeof(pt));
        dfs_c = 0;
        for(int i=0;i<N;i++)
            if(clk[i]==0)
                tarjan(i,-1);
        vector <pair<int,int> > ans;
        for(int i=0;i<N;i++)
            if(ap[i]==1)
                ans.push_back(make_pair(i,pt[i]));
            else
                ans.push_back(make_pair(i,1));
        sort(ans.begin(),ans.end(),cmp);
        for(int i=0;i<M;i++)
            printf("%d %d\n",ans[i].first,ans[i].second);
        printf("\n");
    }
    
    return 0;
}