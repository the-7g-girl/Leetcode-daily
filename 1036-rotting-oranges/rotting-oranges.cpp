class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> level(m, vector<int>(n, -1));
        vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1,0}, {-1, 0}};
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    level[i][j] = 0;
                }
            }
        }
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            for (auto move : moves) {
                int chi = curr.first + move.first;
                int chj = curr.second + move.second;
                cout<<chi<<" "<<chj<<endl;
                if (!isValid(chi, chj, m, n))
                    continue;
                if (grid[chi][chj] != 1)
                    continue;
                // if (grid[chi][chj] == 2) {
                //     level[chi][chj] = min(level[chi][chj],
                //                           level[curr.first][curr.second] + 1);
                // }
                if (grid[chi][chj] == 1) {
                    grid[chi][chj]=2;
                    level[chi][chj] = level[curr.first][curr.second] + 1;
                    q.push({chi, chj});
                }
            }
        }
        int mx = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    return -1;
                mx = max(mx, level[i][j]);
            }
        }
        return mx;
    }
    bool isValid(int i, int j, int m, int n) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }
};