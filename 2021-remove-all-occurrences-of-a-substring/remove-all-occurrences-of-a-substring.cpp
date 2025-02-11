class Solution {
public:
    string removeOccurrences(string s, string part) {
        for (int i = 0; i < s.length(); i++) {
            if(s.substr(i, part.length()) == part) {
                s.erase(i , part.size());
                break;
            }
        }
        bool ptr = false;
        for (int i = 0; i < s.length(); i++) {
            if(s.substr(i, part.length()) == part) {
                ptr = true;
            }
        }
        if(ptr) return removeOccurrences(s, part);
        return s;
    }
};