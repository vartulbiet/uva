    #include<iostream>  
    #include<cstring>  
      
    using namespace std;  
      
    char grid[6][6],vis[6][6];  
    int maxnum,n,num;  
      
    bool judge(int posx,int posy)  
    {  
        int i,j;  
        for(i=posx;i<n;i++)  
        {  
            if(vis[i][posy]==1&&grid[i][posy]=='.') return false;  
            else if(grid[i][posy]=='X') break;  
        }  
        for(i=posx;i>=0;i--)  
        {  
            if(vis[i][posy]==1&&grid[i][posy]=='.') return false;  
            else if(grid[i][posy]=='X') break;  
        }  
        for(i=posy;i<n;i++)  
        {  
            if(vis[posx][i]==1&&grid[posx][i]=='.') return false;  
            else if(grid[posx][i]=='X') break;  
        }  
        for(i=posy;i>=0;i--)  
        {  
            if(vis[posx][i]==1&&grid[posx][i]=='.') return false;  
            else if(grid[posx][i]=='X') break;  
        }  
        return true;  
    }  
      
    void search(int posx,int posy)  
    {  
        int i,j;  
        num++;  
        for(i=0;i<n;i++)  
        {  
            for(j=0;j<n;j++)  
            {  
                if(judge(i,j)&&grid[i][j]=='.'&&vis[i][j]==0)  
                {  
                    vis[i][j]=1;  
                    search(i,j);  
                    num--;  
                    vis[i][j]=0;  
                }  
            }  
        }  
        if(num>maxnum) maxnum=num;  
    }  
      
    int main()  
    {  
        while(cin>>n&&n)  
        {  
            int i,j,k;  
            memset(grid,0,sizeof(grid));  
            memset(vis,0,sizeof(vis));  
            for(i=0;i<n;i++)  
                for(j=0;j<n;j++)  
                    cin>>grid[i][j];  
            maxnum=0;  
            for(i=0;i<n;i++)  
            {  
                for(j=0;j<n;j++)  
                {  
                    if(grid[i][j]!='X')  
                    {  
                        memset(vis, 0, sizeof(vis));  
                        vis[i][j]=1;  
                        num=0;  
                        search(i,j);  
                        vis[i][j]=0;  
                    }  
                }  
            }  
            cout<<maxnum<<endl;  
        }  
        return 0;  
    }  