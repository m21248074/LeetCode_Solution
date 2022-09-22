class Solution {
public:
    int numberOfSteps(int num) {
        int result=0;
        while(num)
        {
            result++;
            if(num%2) num--;
            else num>>=1;
        }
        return result;
    }
};