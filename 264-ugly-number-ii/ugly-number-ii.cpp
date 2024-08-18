class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> ug;
        ug.insert(1);
        long curr=1;
        for(int i=0;i<n;i++){
            curr=*ug.begin();
            ug.erase(ug.begin());
            ug.insert(curr*2);
            ug.insert(curr*3);
            ug.insert(curr*5);
        }
        return curr;
    }
};