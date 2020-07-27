class Solution {
    int ans2=0;
    int dfs(vector<vector<int>>& grid,int i,int j,int n,int m,vector<vector<int>>&visited,int sum)
    {
        if(i<0 || i>=n || j>=m || j<0 || visited[i][j] || grid[i][j]==0)
            return 0;
        visited[i][j]=1;
        int right = dfs(grid,i,j+1,n,m,visited);
        int left = dfs(grid,i,j-1,n,m,visited);
        int down = dfs(grid,i-1,j,n,m,visited);
        int up = dfs(grid,i+1,j,n,m,visited);
        visited[i][j]=0;
        
        return max(left,max(right,max(down,up)))+grid[i][j];
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m));
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                
                if(grid[i][j]!=0){
                    ans = max(ans,dfs(grid,i,j,n,m,visited));
                 }
            }
        }
        return ans;
    }
};
