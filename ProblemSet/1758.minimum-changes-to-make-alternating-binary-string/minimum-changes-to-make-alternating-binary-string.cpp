class Solution {
public:
    int minOperations(string s) {
        int n=s.length();
        int start1=0;
        int start0=0;
        int temp1=1;
        int temp0=0;
        for(char c:s)
        {
            int digit=c-'0';
            if(digit!=temp1)
                start1++;
            if(digit!=temp0)
                start0++;
            temp1^=1;
            temp0^=1;
        }
        return min(start1,start0);
    }
};