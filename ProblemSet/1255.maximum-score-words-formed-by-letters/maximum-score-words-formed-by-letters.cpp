class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> cnt(26);
        for (char c : letters) ++cnt[c - 'a'];
        return dfs(words, cnt, score, 0);
    }
    int dfs(vector<string>& words, vector<int>& cnt, vector<int>& score, int idx) {
        int res = 0;
        for (int i = idx; i < words.size(); ++i) {
            int sum = 0;
            bool isValid = true;
            for (char c : words[i]) {
                if (--cnt[c - 'a'] < 0) {
                    isValid = false;
                }
                sum += score[c - 'a'];
            }
            if (isValid) {
                sum += dfs(words, cnt, score, i + 1);
                res = max(res, sum);
            }
            for (char c : words[i]) {
                ++cnt[c - 'a'];
            }
        }
        return res;
    }
};