class Solution {
public:
    int countPrimes(int n) {
        vector<int> nums(n+1, true);
        if(n==0 || n==1) return 0;
        nums[0]=false;
        nums[1]=false;
        for(int i=2;i*i<=n;i++){
            if(!nums[i]) continue;
            for(int j=2*i; j<=n; j+=i){
                nums[j]=false;
            }
        }
        int k=0;
        for(int i=0; i<n;i++){
            if(nums[i]) k++;
        }
        return k;
    }
};