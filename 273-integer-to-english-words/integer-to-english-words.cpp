class Solution {
public:
    string hundredword(int num, vector<string> ones, vector<string> tens) {
        if (num == 0)
            return "Zero";
            if (num == 10)
            return "Ten";
        if (num == 11)
            return "Eleven";
        if (num == 12)
            return "Twelve";
        if (num == 13)
            return "Thirteen";
        if (num == 14)
            return "Fourteen";
        if (num == 15)
            return "Fifteen";
        if (num == 16)
            return "Sixteen";
        if (num == 17)
            return "Seventeen";
        if (num == 18)
            return "Eighteen";
        if (num == 19)
            return "Nineteen";
        
        int fir = num % 10;
        num = num / 10;
        int sec = num % 10;
        int thi = num / 10;

        string ans = "";
        if (thi != 0) {
            ans = ones[thi] + " Hundred";
        }
        if (sec != 0) {
            if (ans != "")
                ans = ans + " ";
            if(sec==1){
                int k=10+fir;
                ans=ans+hundredword(k,ones,tens);
                return ans;
            }
            ans = ans + tens[sec];
        }
        if (fir != 0) {
            if (ans != "")
                ans = ans + " ";
            ans = ans + ones[fir];
        }
        return ans;
    }
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";

        vector<string> ones = {"Zero", "One", "Two",   "Three", "Four",
                               "Five", "Six", "Seven", "Eight", "Nine"};
        vector<string> tens = {"Zero",  "Ten",   "Twenty",  "Thirty", "Forty",
                               "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        int fir = num % 1000;
        num = num / 1000;
        int sec = num % 1000;
        num = num / 1000;
        int thi = num % 1000;
        num = num / 1000;
        string ans = "";
        if (num != 0) {
            ans += ones[num] + " Billion";
        }
        if (thi != 0) {
            if (ans != "")
                ans = ans + " ";
            ans = ans + hundredword(thi, ones, tens) + " Million";
        }
        if (sec != 0) {
            if (ans != "")
                ans = ans + " ";
            ans = ans + hundredword(sec, ones, tens) + " Thousand";
        }
        if (fir != 0) {
            if (ans != "")
                ans = ans + " ";
            ans = ans + hundredword(fir, ones, tens);
        }
        return ans;
    }
};