class Solution {
public:
    static bool ismagic(vector<vector<int>> grid) {
        vector<int> rsum(3, 0), csum(3, 0);
        vector<bool> dis(10, false);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                dis[grid[i][j]] = true;
                rsum[i] += grid[i][j];
                csum[j] += grid[i][j];
            }
        }
        bool distinct = true;
        for (int i = 1; i < 10; i++) {
            distinct = distinct && dis[i];
        }

        int diag1 = grid[0][0] + grid[1][1] + grid[2][2],
            diag2 = grid[2][0] + grid[1][1] + grid[0][2];
        return (rsum[0] == rsum[1]) && (rsum[1] == rsum[2]) &&
               (rsum[0] == csum[0]) && (csum[0] == csum[1]) &&
               (csum[1] == csum[2]) && (diag1 == diag2) && (diag2 == rsum[0]) &&
               distinct;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (m < 3 || n < 3)
            return 0;
        vector<int> rsum(m, 0), csum(n, 0);
        int ans = 0;
        vector<vector<int>> subgrid(3, vector<int>(3));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i + 2 < m && j + 2 < n) {
                    for (int a = i; a < i + 3; a++) {
                        for (int b = j; b < j + 3; b++) {
                            subgrid[a - i][b - j] = grid[a][b];
                            // cout<<subgrid[a-i][b-j];
                        }
                    }
                    if (ismagic(subgrid))
                        ans++;
                }
            }
        }
        return ans;
    }
};