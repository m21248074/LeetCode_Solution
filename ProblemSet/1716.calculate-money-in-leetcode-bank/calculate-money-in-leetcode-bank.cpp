class Solution {
public:
    int totalMoney(int n) {
        int result=0;
        int mon=1;
        int day=0;
        while(n!=0)
        {
            result+=mon+day;
            day++;
            n--;
            if(day==7)
            {
                mon++;
                day=0;
            }
        }
        return result;
    }
};