class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int a=0,b=0;
        vector<int> ans;
        while(a<nums1.size() && b<nums2.size()){
            if(nums1[a]>nums2[b]) b++;
            else if(nums1[a]<nums2[b]) a++;
            else {ans.push_back(nums1[a]); a++; b++; }
        }
        return ans;
    }
};