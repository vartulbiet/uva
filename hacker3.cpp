#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
map<vector< vector<int> >,bool>mymap;
int n,d;
int ans =0;
bool check(vector<vector<int> >arr)
{
    for(int i =0;i<n;i++)
    {
            for(int j =0;j<n;j++)
            {
                if(arr[i][j]==1)
                    return false;
            }
    }
    return true;
}
void func(vector< vector<int> >arr,int steps)
{
    if(check(arr))
        ans =steps;
    else
    {
    for(int i =0;i<n;i++)
    {
            for(int j =0;j<n;j++)
            {
                vector<vector<int> > brr;
                  for(int k =0;k<n;k++)
                      {
                          for(int m =0;m<n;m++)
                          {
                              if(abs(m-j)+abs(k-i)<=d)
                                  brr[k][m] = 0;
                                else 
                                    brr[k][m] = arr[k][m];
                          }
                      }
                    if(mymap.find(brr)!=mymap.end())
                    {
                        mymap[brr] = true;
                        func(brr,steps+1);
                    }
            }
    }
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    cin>>n>>d;
    vector<vector<int> >arr(n*n);
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
            cin>>arr[i][j];
    }
    mymap[arr] =true;
    func(arr,0);
    return 0;
}

