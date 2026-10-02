class Solution {
public:
    long long sumAndMultiply(int n) {
        long long result=0;
        int total=0;
        int i=1;
        while(n!=0)
        {
            int bit=n%10;
            n/=10;
            if(bit)
            {
                total+=bit;
                result+=bit*i;
                i*=10;
            }
        }
        return result*total;
    }
};