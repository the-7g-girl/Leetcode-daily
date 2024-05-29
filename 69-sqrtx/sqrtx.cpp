class Solution {
public:
    int mySqrt(int x) {
        long long int lo=1,hi=x,mid;
        long long int val;
        if(x==1) return 1;
        while(hi-lo>1){
            mid=(hi+lo)/2;
            val=mid*mid;
            if(val>x) hi=mid-1;
            else lo=mid;
        }
        val=hi*hi;
        if(val<=x) return hi;
        return lo;
    }
};