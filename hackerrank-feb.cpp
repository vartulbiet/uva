#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define PB push_back
using namespace std;
struct node
{
	int a,b,c;
    int d;
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t =0;
    cin>>t;
    while(t>0)
    {
        int m,n;
        cin>>m>>n;
        vector<struct node*>vec;
        for(int  i =0;i<n;i++)
        {
            string s;
            cin>>s;
        	if(s == "QUERY")
            {
            	int x1,y1,z1,x2,y2,z2; 
                cin>>x1>>y1>>z1>>x2>>y2>>z2;
                int ans =0;
                for(int k =0;k<vec.size();k++)
                {
                    struct node*p = (struct node*)malloc(sizeof(struct node));
                         p =vec[i];
                    cout<<p->a<<p->b<<p->c<<p->d<<endl;
                    if(p->a>=x1 && p->a<=x2 && p->b>=y1&& p->b<=y2 && p->c>=z1 && p->c<=z2)
                        ans+=(p->d);
                }
                cout<<ans<<endl;
            }
            else
            {
                int x,y,z;
   				 int w;
                cin>>x>>y>>z>>w;
               // cout<<x<<y<<z<<w;
                struct node* p = (struct node*)malloc(sizeof(struct node));
                p->a =x;
                p->b =y;
                p->c =z;
                p->d =w;
                vec.PB(p);
            }
        }
    	t--;    
    }
    return 0;
}
