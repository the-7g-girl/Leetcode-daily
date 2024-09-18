class Solution {
public:
    static bool comp(int a, int b) {
        string sa = to_string(a);
        string sb = to_string(b);
        if (sa + sb > sb + sa)
            return true;
        else
            return false;
    }
    string largestNumber(vector<int>& nums) {
        if (nums.size() == 1)
            return to_string(nums[0]);
        sort(nums.begin(), nums.end(), comp);
        string ans = "";
        for (int k : nums) {
            if (k == 0 && ans == "")
                continue;
            ans = ans + to_string(k);
        }
        if(ans=="") return "0";
        return ans;
    }
};