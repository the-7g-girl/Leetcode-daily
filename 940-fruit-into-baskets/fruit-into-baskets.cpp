class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int l=0, r=0;
        int cnt=0, ans=0;
        unordered_map<int,int> s;
        while( r<nums.size()){
            while(s.size()<=2 && r<nums.size()){
                s[nums[r]]++;
                r++;
            }
            if(s.size()>2){
                s[nums[l]]--;
                if (s[nums[l]] == 0) {
                    s.erase(nums[l]);
                }
                l++;
            }
            ans=max(ans, r-l);

        }
        return ans;
    }
};