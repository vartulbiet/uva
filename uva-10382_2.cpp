#include <stdio.h>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
#include <memory.h>
#include <math.h>
#define pi acos(-1.0)
struct sprinkler{
    double cover_left;
    double cover_right;
 
    friend bool operator < (const sprinkler&a,const sprinkler&b)
    {
        return a.cover_left < b.cover_left;
    }
}glass[10010];
int main()
{
    //freopen("input.txt","r",stdin);
    int n;
    double l,w;
    while(cin>>n>>l>>w)
    {
        memset(glass,0,sizeof(glass));
        int j=0;
        double k=w/2.0,start,radius;
        for(int i=0;i<n;i++)
        {
            cin>>start>>radius;
            if(radius>=k)
            {
                double dis=radius*radius-k*k;
                dis=sqrt(dis);
                glass[j].cover_left=start-dis;
                glass[j++].cover_right=start+dis;
            }
        }
        sort(glass,glass+j);
 
       // for(int i=0;i<j;i++)
       //     cout<<glass[i].cover_left<<' '<<glass[i].cover_right<<endl;cout<<endl;
 
        int i,sv;
        double p=-1;
        for(i=0;i<n;i++)
        {
            if(glass[i].cover_left<=0)
            {
                if(p<glass[i].cover_right)
                {
                    p=glass[i].cover_right;
                    sv=i;
                }
                continue;
            }
            else break;
        }
        int y=i;
        if(p<0.0)   cout<<-1<<endl;
        else{
            int take=1,pre,cur=sv;
            for(i=y;i<n;i++)
            {
                if(p>=glass[i].cover_left && p<glass[i].cover_right)
                {
                    if(take>1)
                        if(glass[i].cover_left-glass[pre].cover_right<=0)
                        {
                            take--;
                            cur=pre;
                        }
                    pre=cur;
                    p=glass[i].cover_right;
                    take++;
                    cur=i;
                  //  cout<<p<<endl;
                    if(p>=l)    break;
                }
            }
            if(p>=l)    cout<<take<<endl;
            else cout<<-1<<endl;
        }
    }
}