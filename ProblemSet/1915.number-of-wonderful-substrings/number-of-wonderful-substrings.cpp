class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n=word.size();
        int xor_sum=0;
        long long result=0;
        vector<int> cnt(1024);
        cnt[0]=1;
        for(char c:word)
        {
            xor_sum^=(1<<(c-'a'));
            result+=cnt[xor_sum];
            for(int j=0;j<=9;j++)
                result+=cnt[xor_sum^(1<<j)];
            cnt[xor_sum]++;
        }
        return result;
    }
};