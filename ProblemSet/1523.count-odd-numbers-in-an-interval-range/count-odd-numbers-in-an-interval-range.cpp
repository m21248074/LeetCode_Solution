class Solution {
public:
    int countOdds(int low, int high) {
        int temp=high-low;
        if(!(temp%2))
            return (low%2)?temp/2+1:temp/2;
        return temp/2+1;
    }
};