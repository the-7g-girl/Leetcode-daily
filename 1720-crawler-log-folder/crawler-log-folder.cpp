class Solution {
public:
    int minOperations(vector<string>& logs) {
        int k=0;
        for(string s: logs){
            if(s=="../") {
                if(k!=0) k--;
            }
            else if(s!="./"){
                k++;
            }
        }
        return k;
    }
};