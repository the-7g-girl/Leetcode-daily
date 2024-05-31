class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size()-1;
        long long int lo=0,hi=n,mid;
        if(n==0) return letters[0];
        if(target>=letters[n]) return letters[0];
        while(hi>lo){
            mid=(hi+lo)/2;
            if(letters[mid]<target) lo=mid+1;
            else hi=mid;
        }
        while(letters[lo]==target) {lo++;}
        return letters[lo];
    }
};