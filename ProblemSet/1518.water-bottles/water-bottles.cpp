class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int result=numBottles;
        while(numBottles>=numExchange)
        {
            int numNew=numBottles/numExchange;
            int numRemain=numBottles%numExchange;
            numBottles=numNew+numRemain;
            result+=numNew;
        }
        return result;
    }
};