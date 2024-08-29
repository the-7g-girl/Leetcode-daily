class Solution {
public:
    bool valid(int i, int j, int m, int n) {
        return (i >= 0 && j >= 0 && i < m && j < n);
    }
    bool edge(int i, int j, int m, int n) {
        return (i == 0 || j == 0 || i == m - 1 || j == n - 1);
    }
    void solve(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> level(m, vector<int>(n, -1));
        vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int l = 0;
        unordered_map<int, bool> mp;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'X')
                    continue;
                if (level[i][j] != -1)
                    continue;
                if (edge(i, j, m, n))
                    continue;
                level[i][j] = l;
                bool flag = true;
                q.push({i, j});
                while (!q.empty()) {
                    auto curr = q.front();
                    q.pop();
                    for (auto move : moves) {
                        int ich = curr.first + move.first;
                        int jch = curr.second + move.second;
                        if (!valid(ich, jch, m, n))
                            continue;
                        if (level[ich][jch] != -1)
                            continue;
                        if (grid[ich][jch] == 'X')
                            continue;
                        if (edge(ich, jch, m, n))
                            flag = false;
                        level[ich][jch] = l;
                        q.push({ich, jch});
                    }
                }
                mp[l] = flag;
                l++;
            }
        }
        mp[-1] = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'X')
                    continue;
                if (mp[level[i][j]]) {
                    grid[i][j] = 'X';
                }
            }
        }
        return;
    }
};