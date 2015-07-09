#include<cstdio> 
#include<cmath> 
#include<algorithm> 
using namespace std; 
 
struct node 
{ 
    int x, y; 
    bool operator < (const node a) const
    { 
       return x < a.x; 
    } 
} island[1000]; 
 
int main(void) 
{ 
    int n, i, count, cid = 0; 
    double tx, lf, rf, llf, rrf, d; 
   while (scanf("%d%lf", &n, &d), n) 
   { 
      for (i = 0; i < n; i++) 
          scanf("%d%d", &island[i].x, &island[i].y); 
     sort(island, island + n); 
      count = 0; 
      for (i = 0; i < n; i++) 
      { 
           if (island[i].y > d || island[i].y < 0) 
           { 
              count = -1; 
             break; 
          } 
           if (i == 0) 
          { 
              count = 1; 
              tx = sqrt(d * d - island[i].y * island[i].y); 
             lf = island[i].x - tx; 
              rf = island[i].x + tx; 
        } 
           else
          { 
            tx = sqrt(d * d - island[i].y * island[i].y); 
              llf = island[i].x - tx; 
            rrf = island[i].x + tx; 
              if(rf<llf || rrf<lf)
				{
					count++;
					lf =llf;
					rf =rrf;
				}
				else if(llf<lf && rrf>lf && rrf<rf)
				{
					rf =rrf;
				}
				else if(rrf>rf && llf>lf && llf<rf)
				{
					lf =llf;
				}
				else if(llf>lf && rrf<rf)
				{
					lf =llf;
					rf =rrf;
				}
              }  
       } 
       printf("Case %d: %d\n", ++cid, count); 
   } 
}