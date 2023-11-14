class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int t=minutesToTest/minutesToDie;
        return ceil(log2(buckets)/log2(t+1));
    }
};