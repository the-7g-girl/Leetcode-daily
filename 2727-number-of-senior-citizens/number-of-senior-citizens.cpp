class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0;
        for(auto k: details){
            int age=(k[11]-'0')*10+(k[12]-'0');
            if(age>60) ans++;
        }
        return ans;
    }
};