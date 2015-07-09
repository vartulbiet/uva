#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;
int main()
{
		int m,n;
		cin>>m>>n;
		int k=1;
		map<int, int >mymap;
		bool g =false;
		while(m>=0&&n>=0)
		{	
			if(m==0 && n==0)
			{
					int c =0;int d =0;int e =0;
					if(g==true )
						cout<<"Case "<<k<<" is not a tree."<<endl;
					else
					{
						if(mymap.size()==0)
							cout<<"Case "<<k<<" is a tree."<<endl;
						else
						{
							std::map<int,int >::iterator i;
							for(i=mymap.begin();i!=mymap.end();i++)
							{
							if(i->second==-1)
							c++;
							if(i->second == 1 || i->second == 0)
							d++;
							}
							if( c==1 && c+d==mymap.size())
							cout<<"Case "<<k<<" is a tree."<<endl;
							else
							cout<<"Case "<<k<<" is not a tree."<<endl;
						}
					}
					mymap.clear();
					k++;
					g =false;
			}
			else
			{
			if(mymap.find(m) ==mymap.end())
			{
				mymap[m]=-1;
			}
			if(mymap.find(n) ==mymap.end())
			{
				mymap[n]=1;
			}
			else
			{
				if(mymap[n]==-1 && mymap[m]>0)
					g =true;
				else
				{
					mymap[n]++;
				}
			}
				if(m  ==n)
			{
				g =true;
			}
			}
			cin>>m>>n;
		}
		return 0;
}