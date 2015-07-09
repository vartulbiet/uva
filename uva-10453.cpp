    #include <iostream>  
    #include <cstdlib>  
    #include <cstring>  
    #include <cstdio>  
    #include <cstring>  
    #include <string>  
    #include <queue>  
    using namespace std;  
      
    const int MAXN = 1010;  
    const int INF = 0x3f3f3f3f;  
      
    int d[MAXN][MAXN];  
    int path[MAXN][MAXN];  
    bool vis[MAXN][MAXN];  
      
    char str[MAXN];  
      
    void init()  
    {  
        memset(path, -1, sizeof(path));  
        memset(vis, 0, sizeof(vis));  
    }  
      
    int dp(int i, int j)  
    {  
        int &ans = d[i][j];  
        if(i >= j) return 0;  
        if(vis[i][j]) return ans;  
        vis[i][j] = 1;  
        if(str[i] == str[j]) { ans = dp(i+1, j-1); path[i][j] = 0;}  
        else if(dp(i+1, j) < dp(i, j-1)) {ans = dp(i+1, j)+1; path[i][j] = 1;} // <=? <?????   
        else  { ans = dp(i,j-1)+1; path[i][j] = 2;}   
        return ans;  
    }  
      
    void print_ans(int i, int j)  
    {  
        if(i > j) return ;  
        if(i == j) printf("%c", str[i]);  
        if(path[i][j] == 0)  
        {  
            printf("%c", str[i]);  
            print_ans(i+1, j-1);  
            printf("%c", str[i]);  
        }  
        else if(path[i][j] == 1)  
        {  
            printf("%c", str[i]);  
            print_ans(i+1, j);  
            printf("%c", str[i]);  
        }  
        else if(path[i][j] == 2)  
        {  
            printf("%c", str[j]);  
            print_ans(i, j-1);  
            printf("%c", str[j]);  
        }  
    }  
      
    void solve()  
    {  
        init();  
        int n = strlen(str);  
        int ans = dp(0, n-1);  
        printf("%d ", ans);  
        print_ans(0, n-1);  
        printf("\n");  
    }  
      
    int main()  
    {  
        while(~scanf("%s", str))  
        {  
            solve();  
        }  
        return 0;  
    }  