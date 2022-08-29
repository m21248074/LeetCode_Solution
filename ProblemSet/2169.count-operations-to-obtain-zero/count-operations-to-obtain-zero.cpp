class Solution {
public:
    void helper(int &cnt,int &num1,int &num2)
    {
        if(num1==0||num2==0) return;
        cnt++;
        if(num1>=num2)
        {
            num1-=num2;
            helper(cnt,num1,num2);
        }
        else
        {
            num2-=num1;
            helper(cnt,num1,num2);
        }
    }
    int countOperations(int num1, int num2) {
        int cnt=0;
        helper(cnt,num1,num2);
        return cnt;
    }
};