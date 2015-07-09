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
vector< vector<vector<int> > >myvec;
void func(int steps)
{
	bool t =true;int x ,y;vector< vector<vector<int> > >myvec2;
	while(myvec.size()!=0 && t)
	{
		vector< vector<int> > arr= myvec.front();
		myvec.erase(myvec.begin());
			for(int i =0;i<n;i++)
			 {
				 for(int j =0;j<n;j++)
				{
                vector<vector<int> > brr;
                  for(int k =0;k<n;k++)
                      {
						  vector<int>x(n);
                          for(int m =0;m<n;m++)
                          {
                              if(abs(m-j)+abs(k-i)<=d)
							  {
								  if(arr[k][m] ==1)
                                  x[m] = 0;
								  else 
									x[m] =1;
							  }
                                else 
                                    x[m] = arr[k][m];
                          }
						  brr.push_back(x);
                      }
				  if(check(brr))
					{ans =steps+1; t =false;x =i;y =j;break;}
                    if(mymap.find(brr)==mymap.end())
                    {
                        mymap[brr] = true;
                        myvec2.push_back(brr);
                    }
            }
				 if(t==false)
					 break;
		}
			if(myvec.size()==0)
			{ myvec =myvec2;
			myvec2.erase(myvec2.begin(),myvec2.end());
		steps++;
			}
    }
	if(t== true)
		cout<<"Impossible"<<endl;
	else
	{
		cout<<"Possible"<<endl;
		cout<<ans<<endl;
		cout<<x<<" "<<y<<endl;
	}
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    cin>>n>>d;
    vector<vector<int> >arr;
    for(int i =0;i<n;i++)
    {
		vector<int>x(n);
        for(int j =0;j<n;j++)
		{
            cin>>x[j];
		}
		arr.push_back(x);
    }
    mymap[arr] =true;
	myvec.push_back(arr);
    func(0);
    return 0;
}
