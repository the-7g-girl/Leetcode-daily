class Solution {
public:
    int time(string s){
        //if(s=="00:00") return 24*60;
        int t=((s[0]-'0')*10+(s[1]-'0'))*60+((s[3]-'0')*10+(s[4]-'0'));
        return t;
    }
    int findMinDifference(vector<string>& arr) {
        vector<int> mins;
        for(string s:arr){
            cout<<time(s)<<endl;
            mins.push_back(time(s));
        }
        sort(mins.begin(),mins.end());
        int a=INT_MAX;
        int n=mins.size();
        for(int i=0;i<n-1;i++){
            a=min(a, mins[i+1]-mins[i]) ;
        }
        a=min(a , mins[0]-mins[n-1]+24*60 );

        return a;
    }
};