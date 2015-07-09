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

int main(){
    int F,C,f,c,cont;
    vector<string> grid;
    string s;
    int visited[10][10];
    bool loop;
    
    while(1){
        cin>>F>>C>>c;
        if(F==0 && C==0 && c==0) break;
        
        f=0;
        c--;
        
        grid.clear();
        
        for(int i=0;i<F;i++){
            cin>>s;
            grid.push_back(s);
        }
        
        memset(visited,-1,sizeof(visited));
        cont=0;
        loop=false;
        
        visited[f][c]=0;
        
        while(1){
            cont++;
            
            if(grid[f][c]=='N') f--;
            else if(grid[f][c]=='S') f++;
            else if(grid[f][c]=='W') c--;
            else c++;
            
            if(f<0 || f>=F || c<0 || c>=C) break;
            
            if(visited[f][c]!=-1){
                loop=true;
                break;
            }else visited[f][c]=cont;
        }
        
        if(!loop) cout<<cont<<" step(s) to exit"<<endl;
        else cout<<visited[f][c]<<" step(s) before a loop of "<<cont-visited[f][c]<<" step(s)"<<endl;
    }
    return 0;
}