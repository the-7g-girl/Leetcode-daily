class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n+1, false);
        for(int i:nums){
            v[i]=true;
        }
        for(int i=0; i<=n;i++){
            if(!v[i]) return i;
        }
        return 0;
    }
};