class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n=words.size();
        vector<unordered_map <char,int> > wee(n); 
        for(int j=0;j<n;j++){
            for(int i=0;i<26;i++){
                wee[j]['a'+i]=0;
            }
        }
        for(int j=0;j<n;j++){
            for(int i=0;i<words[j].size();i++){
                wee[j][words[j][i]]+=1;
            }
        }
        vector<string> ans;
        for(int i=0;i<26;i++){
            int cnt=10000; 
            for(int j=0;j<n;j++){
                cnt=min(cnt,wee[j]['a'+i]);
            }
            string str(1,'a'+i);
            if(cnt>0 && cnt!=0 ) for(int t=0;t<cnt;t++) ans.push_back(str);
        }
        return ans;
    }
};