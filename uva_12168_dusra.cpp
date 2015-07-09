#include<iostream>  
#include<string>  
#include<algorithm>  
#include<cstdlib>  
#include<cstdio>  
#include<set>  
#include<map>  
#include<vector>  
#include<cstring>  
#include<stack>  
#include<cmath>  
#include<queue>  
using namespace std;  
#define CL(x,v); memset(x,v,sizeof(x));  
#define INF 0x3f3f3f3f  
#define LL long long  
#define REP(i,r,n) for(int i=r;i<=n;i++)  
#define RREP(i,n,r) for(int i=n;i>=r;i--)  
  
const int MAXN=505;  
int lencat,lendog;  
struct node{  
    int x,y;  
}cat[MAXN],dog[MAXN];  
int Left[MAXN];//Left[i]???????i???????  
int w[MAXN][MAXN];  
bool S[MAXN],T[MAXN];  
int N;  
bool match(int i)  
{  
    S[i]=true;  
    for(int j=1;j<=lendog;j++)if(w[i][j]&&!T[j])  
    {  
        T[j]=true;  
        if(Left[j]==0||match(Left[j]))  
        {  
            Left[j]=i;  
            return true;  
        }  
    }  
    return false;  
}  
int hungry(){  
    CL(Left,0);  
    int sum=0;  
    for(int i=1;i<=lencat;i++)  
    {  
        CL(S,0);  
        CL(T,0);  
        if(match(i))sum++;  
    }  
    return sum;  
}  
  
int main()  
{  
    int cas;  
    scanf("%d",&cas);  
    while(cas--)  
    {  
        int c,d,v;  
        scanf("%d%d%d",&c,&d,&v);  
            lencat=0;lendog=0;  
        REP(i,1,v)  
        {  
            int a,b;  
            char s1,s2;  
            cin>>s1>>a>>s2>>b;  
            if(s1=='C')  
            {  
                lencat++;  
                cat[lencat].x=a;cat[lencat].y=b;  
            }  
            else{  
                dog[++lendog].x=a;dog[lendog].y=b;  
            }  
        } 
cout<<lendog<<lencat<<endl;		
        CL(w,0);  
        REP(i,1,lencat)  
            REP(j,1,lendog)  
            {  
                if(cat[i].x==dog[j].y||cat[i].y==dog[j].x)  
                {  
                    w[i][j]=1;  
                }  
            }  
        int sum=hungry();  
		cout<<sum<<endl;
        printf("%d\n",v-sum);  
    }  
    return 0;  
} 