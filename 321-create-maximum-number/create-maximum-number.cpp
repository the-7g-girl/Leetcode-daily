class Solution {
public:
    vector<int> maxSeq(vector<int>& n1, int n) {
        int del = n1.size() - n;
        stack<int> stc;

        for (int i = 0; i < n1.size(); i++) {
            while (del > 0 and !stc.empty() and stc.top() < n1[i]) {
                stc.pop();
                del--;
            }
            stc.push(n1[i]);
        }

        vector<int> ans;
        int extra = stc.size() - n;
        while (!stc.empty() and extra--)
            stc.pop();
        while (!stc.empty()) {
            ans.push_back(stc.top());
            stc.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    bool isGreater(vector<int>& a, int i, vector<int>& b, int j) {
        while (i < a.size() && j < b.size()) {
            if (a[i] > b[j])
                return true;
            if (a[i] < b[j])
                return false;
            i++;
            j++;
        }
        return (a.size() - i) > (b.size() - j);
    }

    vector<int> merge(vector<int>& a, vector<int>& b) {
        int i = 0, j = 0;
        vector<int> merged;
        while (i < a.size() || j < b.size()) {
            if (isGreater(a, i, b, j)) {
                merged.push_back(a[i++]);
            } else {
                merged.push_back(b[j++]);
            }
        }
        return merged;
    }

    vector<int> maxNumber(vector<int>& n1, vector<int>& n2, int k) {
        int n = n1.size(), m = n2.size();
        vector<int> ans(k, -1), temp;

        for (int i = 0; i <= k; i++) {
            // sub-sequence from n1=i, from n2=k-i
            vector<int> s1 = maxSeq(n1, i);
            vector<int> s2 = maxSeq(n2, k - i);

            temp = merge(s1, s2);
            if (temp.size() < k)
                continue;

            if (isGreater(temp, 0, ans, 0))
                ans = temp;
        }

        return ans;
    }
};