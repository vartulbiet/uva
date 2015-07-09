#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cstdlib>
#include<map>
#include<cstdio>
#define INF 1<<30
#include<queue>
#include<algorithm>
using namespace std;
int arr[101][101];
int n;
void init()
{
	for(int i =0;i<101;i++)
	{
		for(int j =0;j<101;j++)
		{
		arr[i][j] =0;
		}
	}
}
int minDistance(int dist[], bool sptSet[])
{
   // Initialize min value
   int min = INF, min_index;
 
   for (int v = 0; v < n; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
 
   return min_index;
}
void dijkstra()
{
     int dist[n];
 
     bool sptSet[n]; 
 
     for (int i = 0; i < n; i++)
        dist[i] = INF, sptSet[i] = false;

     dist[0] = 0;

     for (int count = 0; count < n-1; count++)
     {
       int u = minDistance(dist, sptSet);
    
       sptSet[u] = true;
       for (int v = 0; v < n; v++)
         if (!sptSet[v] && arr[u][v] && dist[u] != INF && dist[u]+arr[u][v] < dist[v])
            dist[v] = dist[u] + arr[u][v];
     }
 int nas =0;
  for (int i = 0; i < n; i++)
  {
  nas= max(nas,dist[i]);
  //cout<<dist[i]<<"--";
  }
  cout<<nas<<endl;
     // print the constructed distance array
   
}
int main()
{
	while(scanf("%d",&n)==1)
	{
		string in;
		for(int i =1;i<n;i++)
		{
			for(int j =0;j<i;j++)
			{
			 cin >> in;
				   if(in == "x")
                    arr[i][j] = INF;
                else
                    arr[i][j] = atoi(in.c_str());
				arr[j][i]=arr[i][j];
			}
		}
		

		dijkstra();
	}
	return 0;
}