class Solution {
public:
    string makeFancyString(string s) {
        char ch = '.';
        string ans;
        int curr = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ch) {
                curr++;
            } else {
                if (curr == 1)
                    ans.push_back(ch);
                else if (curr >= 2)
                    ans.push_back(ch), ans.push_back(ch);
                ch = s[i], curr = 1;
            }
        }
        if (curr == 1)
            ans.push_back(ch);
        else if (curr >= 2)
            ans.push_back(ch), ans.push_back(ch);
        return ans;
    }
};