class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        int n = arr.size();
        if (n == 1)
            return 0;
        int l = INT_MAX, r = INT_MIN, lidx = -1, ridx = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i][0] < l) {
                l = arr[i][0];
                lidx = i;
            }
            if (arr[i][arr[i].size() - 1] > r) {
                r = arr[i][arr[i].size() - 1];
                ridx = i;
            }
        }

        if (lidx != ridx) {
            return (r - l);
        } else {
            int sl = INT_MAX, sr = INT_MIN;
            for (int i = 0; i < n; i++) {
                if (arr[i][0] < sl && i != lidx) {
                    sl = arr[i][0];
                }
                if (arr[i][arr[i].size() - 1] > sr && i != ridx) {
                    sr = arr[i][arr[i].size() - 1];
                }
            }
            return max(r - sl, sr - l);
        }
        return 0;
    }
};