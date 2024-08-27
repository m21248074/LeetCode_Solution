class Solution {
public:
    int numSteps(string s) {
        int step = 0;
        int n=s.size();
        if (n==1)
        {
            if (s[0]=='0') 
                step++;
            return step;
        }
        
        int carry = 0;
        for (int i=n-1;i>0;i--)
        {
            if (s[i]=='0')
            {
                if (!carry)
                    step++;
                else
                {
                    step += 2;
                    carry = 1;
                }
            }
            else
            {
                if (!carry)
                    step += 2;
                else
                    step++;
                carry = 1;
            }
        }
        return step + carry;
    }
};