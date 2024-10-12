class Solution {
public:
    int minGroups(vector<vector<int>>& arr) {
        int end=0;
        for(auto v: arr){
            end=max(end,v[1]);
        }
        vector<int> pre(end+2,0);
        for(auto v: arr){
            pre[v[0]]++;
            pre[v[1]+1]--;
        }
        vector<int>  presum(end+2,0);
        for(int i=1; i<end; i++){
            presum[i]=pre[i]+presum[i-1];
        }
        int m=0;
        for(int k: presum){
            m=max(m,k);
        }
        if(m==0) return 1;
        return m;
    }
};