class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
    string gcdOfStrings(string s1, string s2) {
        int a = s1.size(), b = s2.size();
        if (a < b)
            swap(a, b);
        int d = gcd(a, b);
        string poss=s1.substr(0, d);
        bool flag=true;
        for(int i=0;i<s2.size();i=i+d){
            if(poss!=s2.substr(i,d)) flag=false;
        }
        for(int i=0;i<s1.size();i=i+d){
            if(poss!=s1.substr(i,d)) flag=false;
        }
        if(flag) return poss;
        else return "";
    }
};