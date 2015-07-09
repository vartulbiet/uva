#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
using namespace std;
  vector<string>arr;
int n,m;
struct node
    {
    int a,b,c;
};
int bfs(int sx,int sy,int rx,int ry)
{
    bool visited[n][m];
    for(int i =0;i<n;i++)
        {
        for(int j =0;j<m;j++)
            visited[i][j] = false;
    }
    queue<struct node*>q;
    int count =0;
    visited[sx][sy] = true;
    struct node*p = (struct node*)malloc(sizeof(struct node));
    p->a =sx;
    p->b =sy;
    p->c = 0;
    q.push(p);
    while(!q.empty())
    {
       struct node*t = (struct node*)malloc(sizeof(struct node));
        t = q.front();
        q.pop();
        int pp,qq;
        pp= t->a;qq= t->b;//cout<<t->a<<" "<<t->b<<" "<<t->c<<endl;
        if(pp==rx && qq ==ry)
           {
		  // cout<<"--";
            count = t->c;
            break;
        }
        else
        {
            	int h =0;
            if(pp>0 &&arr[pp-1][qq]!='X' && !visited[pp-1][qq])
                h++;
            if(qq>0 &&arr[pp][qq-1]!='X' && !visited[pp][qq-1])
                h++;
            if(pp+1<n &&arr[pp+1][qq]!='X' && !visited[pp+1][qq])
                h++;
            if(qq+1<m &&arr[pp][qq+1]!='X' && !visited[pp][qq+1])
                h++;
            if(h>1)
             {
               // cout<<h<<endl;
                
                if(pp>0 &&arr[pp-1][qq]!='X' && !visited[pp-1][qq])
                { struct node*rrr = (struct node*)malloc(sizeof(struct node));rrr->a= pp-1;rrr->b =qq;rrr->c =t->c+1;q.push(rrr);visited[pp-1][qq] = true;}
            if(qq>0 &&arr[pp][qq-1]!='X' && !visited[pp][qq-1])
               {struct node*rrr = (struct node*)malloc(sizeof(struct node));rrr->a= pp;rrr->b =qq-1;rrr->c =t->c+1;q.push(rrr);visited[pp][qq-1] = true;}
            if(pp+1<n &&arr[pp+1][qq]!='X' && !visited[pp+1][qq])
               {struct node*rrr = (struct node*)malloc(sizeof(struct node));rrr->a= pp+1;rrr->b =qq;rrr->c =t->c+1;q.push(rrr);visited[pp+1][qq] = true;}
            if(qq+1<m &&arr[pp][qq+1]!='X' && !visited[pp][qq+1])
                {struct node*rrr = (struct node*)malloc(sizeof(struct node));rrr->a= pp;rrr->b =qq+1;rrr->c =t->c+1;q.push(rrr);visited[pp][qq+1] = true;}
            }
            else
             {
			 //cout<<"h ==1"<<endl;
                 struct node*rrr = (struct node*)malloc(sizeof(struct node));
                if(pp>0 &&arr[pp-1][qq]!='X' && !visited[pp-1][qq])
                {rrr->a= pp-1;rrr->b =qq;rrr->c =t->c;q.push(rrr);visited[pp-1][qq] = true;}
            if(qq>0 &&arr[pp][qq-1]!='X' && !visited[pp][qq-1])
               {rrr->a= pp;rrr->b =qq-1;rrr->c =t->c;q.push(rrr);visited[pp][qq-1] = true;}
            if(pp+1<n &&arr[pp+1][qq]!='X' && !visited[pp+1][qq])
               {rrr->a= pp+1;rrr->b =qq;rrr->c =t->c;q.push(rrr);visited[pp+1][qq] = true;}
            if(qq+1<m &&arr[pp][qq+1]!='X' && !visited[pp][qq+1])
                {rrr->a= pp;rrr->b =qq+1;rrr->c =t->c;q.push(rrr);visited[pp][qq+1] = true;}
            }
    }
    }
    return count;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t =0;
    cin>>t;
    while(t>0)
    {
        cin>>n>>m;
         //cout<<n<<m<<endl;
        string s;
        getline(cin,s);
        for(int i =0;i<n;i++)
       		{	
 getline(cin,s);
    
        arr.push_back(s);
            }
       int k =0;
        cin>>k;
        int sx,sy,rx,ry;
        for(int i =0;i<n;i++)
        {
        	for(int j =0;j<m;j++)
             {
                if(arr[i][j] =='M')
                 {
                    sx =i;
                    sy =j;
                }
                if(arr[i][j] =='*')
                 {
                    rx =i;
                    ry =j;
                }
            }
        }
		//cout<<rx<<ry<<sx<<sy<<endl;
       int c = bfs(sx,sy,rx,ry);
      //  cout<<c<<endl;
           if(c == k)
           cout<<"Impressed"<<endl;
           else
           cout<<"Oops!"<<endl;
     	t--;   
		arr.erase(arr.begin(),arr.end());
    }
    return 0;
}
