class Solution {
public:
    bool match(string a, string b) {
        if (a.size() != b.size())
            return false;
        int cnt = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i])
                cnt++;
        }
        if (cnt == 1)
            return true;
        return false;
    }
    int make(int n, vector<vector<int>>& grid, vector<string>& word, string end) {
        int k = -1;
        for (int i = 0; i < n; i++) {
            if (word[i] == end)
                k = i;
            for (int j = i + 1; j < n; j++) {
                if (match(word[i], word[j])) {
                    grid[i].push_back(j);
                    grid[j].push_back(i);
                }
            }
        }
        return k;
    }
    int ladderLength(string begin, string end, vector<string>& words) {
        words.push_back(begin);
        int n = words.size();
        vector<vector<int>> grid(n);
        int k = make(n, grid, words, end);
        if(k==-1) return 0;
        queue<int> q;
        vector<int> level(n, -1);
        q.push(n - 1);
        level[n - 1] = 0;
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            cout<<words[t]<<endl;
            for (int child : grid[t]) {
                
                if (level[child] != -1)
                    continue;
                cout<<words[child]<<endl;    
                level[child] = level[t]+1;
                q.push(child);
            }
        }
        return level[k]+1;
    }
};