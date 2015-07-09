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

typedef struct A{
    int h,mus,spo;
    A(int _h,int _mus,int _spo){
        h = _h, mus = _mus, spo = _spo;
    }
    bool ok(A a){
        if(abs(h-a.h)>40)    return false;
        if(mus!=a.mus)    return false;
        if(spo==a.spo)    return false;
        return true;
    }
}AA;
vector <AA> peo[2];
vector <int> v[505];
map <string,int> music,sport;
int vis[505],my[505];

bool bipartite(int x){
    for(int i=0;i<v[x].size();i++){
        int y = v[x][i];
        if(vis[y]==0){
            vis[y] = 1;
            if(my[y]==-1 || bipartite(my[y])){
                my[y] = x;
                return true;
            }
        }
    }
    return false;
}

int main()
{

   
    int T;
    cin >> T;
    for(int N;T--;){
        peo[0].clear();
        peo[1].clear();
        music.clear();
        sport.clear();
        cin >> N;
        int mu = 0, sp = 0;
        for(int i=0,hei;i<N;i++){
            string s1,s2,s3;
            cin >> hei >> s1 >> s2 >> s3;
            if(music.find(s2)==music.end())
                music[s2] = mu++;
            if(sport.find(s3)==sport.end())
                sport[s3] = sp++;
            if(s1=="M") peo[0].push_back(A(hei,music[s2],sport[s3]));
            else    peo[1].push_back(A(hei,music[s2],sport[s3]));
        }
        for(int i=0;i<=N;i++)
            v[i].clear();
        for(int i=0;i<peo[0].size();i++){
            for(int j=0;j<peo[1].size();j++)
			{
                if(peo[0][i].ok(peo[1][j])){
                    v[i].push_back(j);cout<<"1"<<" ";}
					else
					cout<<"0"<<" ";}
					cout<<endl;}
					
        memset(my,-1,sizeof(my));
        int ans = 0;
        for(int i=0;i<peo[0].size();i++){
            memset(vis,0,sizeof(vis));
            if(bipartite(i))
                ans++;
        }
		cout<<ans<<endl;
        printf("%d\n",N-ans);
    }
   
    return 0;
} 