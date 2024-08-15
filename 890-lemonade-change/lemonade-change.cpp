class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n20 = 0, n10 = 0, n5 = 0;
        for (int i : bills) {
            if (i == 5)
                n5++;
            if (i == 10) {
                if (n5 > 0) {
                    n5--;
                    n10++;
                } else {
                    return false;
                }
            }
            if (i == 20) {
                if (n10 > 0 && n5 > 0) {
                    n20++;
                    n10--;
                    n5--;
                } else if (n5 >= 3) {
                    n5 = n5 - 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};