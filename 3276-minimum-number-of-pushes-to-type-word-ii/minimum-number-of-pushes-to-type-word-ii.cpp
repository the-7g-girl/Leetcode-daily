class Solution {
public:
    static bool cmp(pair<char, int>& a, pair<char, int>& b) 
    { 
        return a.second>b.second; 
    } 
    int minimumPushes(string word) {
        vector<pair<char, int>> A(26); 
        for(int i=0;i<26;i++){
            A[i]={'a'+i,0};
        }
        for(char ch:word){
            A[ch-'a'].second++;
        }
        sort(A.begin(),A.end(),cmp);
        int c,ans=0,p=1;
        for(int i=0;i<A.size();i++){
            if(A[i].second!=0)
            {    
                if(p%8!=0) c=(p/8)+1;
                if(p%8==0) c=p/8;
                ans+=c*A[i].second;
                p++;
            }
        }
        return ans;
    }
};