class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long> sums;
        for(int i=1; i<n; i++) {
            nums[i]+= nums[i-1]%MOD;
            nums[i] = nums[i]%MOD;
        }
        nums.insert(nums.begin(), 0);
        
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n+1; j++) {
                sums.push_back((nums[j]-nums[i])%MOD);
            }
        }

        sort(sums.begin(), sums.end());

        int ans = 0;
        int k = sums.size();
        for(int i= left-1; i<right; i++) {
            if(i<k) {
                ans += sums[i];
                ans = ans%MOD;
            }
        }

        return ans;
    }
private:
    const long MOD = pow(10, 9) + 7;    
};