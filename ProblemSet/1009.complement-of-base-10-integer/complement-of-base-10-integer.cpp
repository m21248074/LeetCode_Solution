class Solution {
public:
    int bitwiseComplement(int num) {
        if(!num) return 1;
        unsigned int highestBit = 1 << (int)(log2(num));
        unsigned int mask = (highestBit * 2) - 1;
        return num ^ mask;
    }
};