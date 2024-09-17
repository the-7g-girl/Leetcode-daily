class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> vis(n,false);

        queue<int> q;
        q.push(0);
        vis[0]=true;
        while(!q.empty()){
            int t=q.front();
            q.pop();
            if(rooms[t].size()==0){
                vis[t]=true;
                continue;
            }
            else for(int ch: rooms[t]){
                if(!vis[ch]){
                    q.push(ch);
                    vis[ch]=true;
                } 
            }
        }
        bool flag=true;
        for(bool k : vis){
            flag=flag && k;
        }
        return flag;
    }
};