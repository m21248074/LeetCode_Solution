class Solution {
public:
    int findComplement(int num) {
        unsigned int highestBit = 1 << (int)(log2(num));
        unsigned int mask = (highestBit * 2) - 1;
        return num ^ mask;
    }
};