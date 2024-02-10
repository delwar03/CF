#include <bits/stdc++.h>
using namespace std;


char grid[25][25];
int n, m, vis[25][25], ans, cnt;

void dfs(int i, int j)
{
    cnt++;
    vis[i][j] = 1;
    if(!vis[i][(j+1)%n]) dfs(i, (j+1)%n);
    if(!vis[i][(j-1+n)%n]) dfs(i, (j-1+n)%n);
    if(i+1 < m && !vis[i+1][j]) dfs(i+1, j);
    if(i-1 >= 0 && !vis[i-1][j]) dfs(i-1, j);
}

int main()
{
    while(cin>>m>>n){
        memset(vis, 0, sizeof vis);
        getchar();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                scanf("%c", &grid[i][j]);
            }
            getchar();
        }

        int x, y;
        scanf("%d%d", &x, &y);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++)
                if(grid[i][j] != grid[x][y])
                    vis[i][j] = 1;
        }
        dfs(x, y);

        ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j]){
                    cnt = 0;
                    dfs(i, j);
                    ans = max(ans, cnt);
                }
            }
        }
        printf("%d\n", ans);
    }
}