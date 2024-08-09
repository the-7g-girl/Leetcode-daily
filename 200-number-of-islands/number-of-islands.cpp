class Solution {
public:
    static void dfs(vector<vector<char>>& grid, int i, int j, int m, int n,
             vector<vector<bool>>& vis) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0' ||
            vis[i][j])
            return;
        vis[i][j] = true;
        dfs(grid, i + 1, j, m, n, vis);
        dfs(grid, i - 1, j, m, n, vis);
        dfs(grid, i, j + 1, m, n, vis);
        dfs(grid, i, j - 1, m, n, vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] || grid[i][j]=='0') continue;
                ans++;
                dfs(grid, i, j, m, n, vis);
            }
        }
        return ans;
    }
};