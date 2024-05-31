// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long int lo=1,hi=n,mid;
        if(n==1) return 1;

        while(hi>lo){
            mid=(hi+lo)/2;
            if(!isBadVersion(mid)) lo=mid+1;
            else hi=mid;
        }
        return lo;
    }
};