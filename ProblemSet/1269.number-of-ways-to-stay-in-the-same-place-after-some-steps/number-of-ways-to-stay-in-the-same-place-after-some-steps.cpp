class Solution {
public:
  int numWays(int steps, int arrLen) {
    const int kMod = 1e9 + 7;
    arrLen = min(steps + 1, arrLen);
    vector<int> dp(arrLen);
    dp[0] = 1;
    for (int i = 0; i < steps; ++i) {
      vector<int> tmp(dp.size());      
      for (int j = 0; j < arrLen; ++j) {
        tmp[j] = dp[j];
        if (j > 0) tmp[j] = (tmp[j] + dp[j - 1]) % kMod;
        if (j < arrLen - 1) tmp[j] = (tmp[j] + dp[j + 1]) % kMod;
      }
      swap(dp, tmp);
    }
    return dp[0];
  }
};