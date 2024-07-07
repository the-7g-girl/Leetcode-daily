class Solution {
public:
    int numWaterBottles(int bot, int ex) {
        int ans=0,drink=bot,empty=0;
        while(bot>=ex){
            ans+=drink;
            empty=bot%ex;
            drink=bot/ex;
            bot=drink+empty;
        }
        ans+=drink;
        return ans;
    }
};