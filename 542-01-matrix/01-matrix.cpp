class Solution {
public:
    bool isValid(int i, int j, int m, int n) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> level(m, vector<int>(n, INT_MAX));
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                    level[i][j] = 0;
                    vis[i][j] = true;
                }
            }
        }
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            for (auto move : moves) {
                int chi = curr.first + move.first;
                int chj = curr.second + move.second;
                cout << chi << " " << chj << endl;
                if (!isValid(chi, chj, m, n))
                    continue;
                if (vis[chi][chj])
                    continue;
                if (grid[chi][chj] == 1) {
                    level[chi][chj] = min(level[curr.first][curr.second] + 1,
                                          level[chi][chj]);
                    vis[chi][chj] = true;
                    q.push({chi, chj});
                }
            }
        }
        return level;
    }
};