class Solution {
public:
    string clearDigits(string s) {
        stack <char> st;
        for (char c : s) {
            if (c < '0' || c > '9')
                st.push(c);
            else {
                if (!st.empty())
                    st.pop();
            }
        }
        string ans;
        while (!st.empty()) {
            char c = st.top();
            st.pop();
            ans = c + ans;
        }
        return ans;
    }
};