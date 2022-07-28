class Solution {
public:
    int trailingZeroes(int n) {
        int result=0;
        int divider=5;
        while(divider<=n)
        {
            result+=n/divider;
            divider*=5;
        }
        return result;
    }
};