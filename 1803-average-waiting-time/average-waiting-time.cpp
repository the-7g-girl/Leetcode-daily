class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long int tot=0,time=0,num=0;
        for(int i=0;i<customers.size();i++){
            if(time<customers[i][0]) {
                num++;
                time=customers[ i][0]+customers[i][1];
                tot+=customers[i][1];
            }
            else {
                num++;
                time=time+customers[i][1];
                tot+=time-customers[i][0];
            }
        }
        double ans=tot*1.00/num;
        return ans;
    }
};