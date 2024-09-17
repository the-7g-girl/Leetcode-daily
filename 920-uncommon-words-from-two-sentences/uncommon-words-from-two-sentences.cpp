class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map <string,int> mp;
        int i=0;
        string word="";
        while(i<s1.size()){
            word="";
            while(s1[i]!=' ' && i<s1.size()){
                word=word+s1[i];
                i++;
            }
            if(s1[i]==' '){
                mp[word]++;
                i++;
            }
        }
        if(i==s1.size()) mp[word]++;

        i=0;
        while(i<s2.size()){
            word="";
            while(s2[i]!=' ' && i<s2.size()){
                word=word+s2[i];
                i++;
            }
            if(s2[i]==' '){
                mp[word]++;
                i++;
            }
        }
        if(i==s2.size()) mp[word]++;
        
        vector<string> ans;
        for(auto it: mp){
            if(it.second==1) ans.push_back(it.first);
        }
        return ans;
    }
};