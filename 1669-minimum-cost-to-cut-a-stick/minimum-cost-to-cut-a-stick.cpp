struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

class Solution {
public:
    int find(int i, int j, vector<int>& cuts,
             unordered_map<pair<int, int>, int, hash_pair>& dp) {
        if (dp[{i, j}] != INT_MAX - 1)
            return dp[{i, j}];
        if(j-i==1) return 0;
        int cnt=0;
        for (int cut : cuts) {
            if (i < cut && cut < j) {
                cnt++;
                dp[{i, j}] = min( dp[{i, j}], find(i, cut, cuts, dp) + find(cut, j, cuts, dp) );
            }
        }

        dp[{i, j}] += j - i;
        if(cnt==0) dp[{i,j}]=0;
        return dp[{i, j}];
    }
    int minCost(int n, vector<int>& cuts) {
        unordered_map<pair<int, int>, int, hash_pair> dp;
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        for (int i = 0; i < cuts.size()-1; i++) {
            for (int j = i + 1; j < cuts.size(); j++) {
                dp[{cuts[i], cuts[j]}] = ((j - i == 1) ? 0 : INT_MAX - 1);
            }
        }

        return find(0, n, cuts, dp);
    }
};