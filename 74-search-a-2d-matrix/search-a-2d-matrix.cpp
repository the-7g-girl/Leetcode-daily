class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int t) {
        int m = arr.size(), n = arr[0].size();

        if (m == 1 && n == 1)
            return (arr[0][0] == t) ? true : false;

        int lo = 0, hi = m - 1, mid;

        if (m > 1) {
            while (hi - lo > 1) {
                mid = (lo + hi) / 2;
                if (arr[mid][0] == t) {
                    return true;
                } else if (arr[mid][0] > t) {
                    hi = mid - 1;
                } else {
                    lo = mid;
                }
            }
            if(arr[lo][0] == t || arr[hi][0] == t) return true;
        }

        int r = (arr[hi][0] < t) ? hi : lo;

        if (n > 1) {
            lo = 0, hi = n - 1;

            while (hi - lo > 1) {
                mid = (lo + hi) / 2;
                if (arr[r][mid] == t) {
                    return true;
                } else if (arr[r][mid] > t) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            if(arr[r][lo] == t || arr[r][hi] == t) return true;
        }
        return false;
    }
};