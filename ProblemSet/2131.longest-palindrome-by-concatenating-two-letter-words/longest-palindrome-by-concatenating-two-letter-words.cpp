class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> um;
        for(auto word:words) um[word]++;

        bool isSame=false;
        int cnt=0;
        for(auto word:words)
        {
            if(um[word]<=0) continue;
            um[word]--;
            string temp=word;
            reverse(temp.begin(),temp.end());
            if(um[temp]>0)
            {
                cnt+=2;
                um[temp]--;
            }
            else if(word==temp)
                isSame=true;
        }
        if(isSame) cnt++;
        return cnt*2;
    }
};