class Solution {
public:
    static void dfs(vector<vector<int>>& input, int i, int j, int num,
                    vector<vector<bool>>& vis) {
        if (i < 0 || i >= num || j < 0 || j >= num || input[i][j] == 1 ||
            vis[i][j])
            return;
        vis[i][j] = true;
        dfs(input, i + 1, j, num, vis);
        dfs(input, i - 1, j, num, vis);
        dfs(input, i, j + 1, num, vis);
        dfs(input, i, j - 1, num, vis);
    }
    static void fill(vector<string>& grid, vector<vector<int>>& input) {
        int n = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '/') {
                    input[3 * i + 2][3 * j] = 1;
                    input[3 * i + 1][3 * j + 1] = 1;
                    input[3 * i][3 * j + 2] = 1;
                }
                if (grid[i][j] == '\\') {
                    input[3 * i][3 * j] = 1;
                    input[3 * i + 1][3 * j + 1] = 1;
                    input[3 * i + 2][3 * j + 2] = 1;
                }
            }
        }
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid[0].size();
        vector<vector<int>> input(3 * n, vector<int>(3 * n, 0));
        vector<vector<bool>> vis(3 * n, vector<bool>(3 * n, false));
        fill(grid, input);
        int ans = 0;
        for (int i = 0; i < 3 * n; i++) {
            for (int j = 0; j < 3 * n; j++) {
                cout << input[i][j];
                if (vis[i][j] || input[i][j] == 1)
                    continue;
                dfs(input, i, j, 3 * n, vis);
                ans++;
            }
            cout << endl;
        }
        return ans;
    }
};