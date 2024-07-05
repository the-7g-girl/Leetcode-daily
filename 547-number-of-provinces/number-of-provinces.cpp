class Solution {
public:
    int findCircleNum(vector<vector<int>>& input) {
        int n=input.size();
        vector<bool> vis(n,false);
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            dfs(i,input,vis);
            ans++;
        }
        return ans;
    }

    void dfs(int i,vector<vector<int>>& input, vector<bool> &vis ){
        vis[i]=true;
        int n=input.size();
        for(int j=0;j<n;j++){
            if(input[i][j]) {
                if(vis[j]) continue;
                dfs(j,input,vis);
            }
        }
        return;
    }
};