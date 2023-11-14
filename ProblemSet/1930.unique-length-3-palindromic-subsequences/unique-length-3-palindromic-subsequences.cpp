class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char,int> um;
        unordered_map<char,pair<int,int>> indexes;
        int len=s.length();
        for(int i=0;i<len;i++)
        {
            char c=s[i];
            if(!um[c])
                indexes[c].first=i;
            um[c]++;
        }
        um.clear();
        for(int i=len-1;i>=0;i--)
        {
            char c=s[i];
            if(!um[c])
                indexes[c].second=i;
            um[c]++;
        }
        int result=0;
        unordered_set<char> us;
        for(char i='a';i<='z';i++)
        {
            if(um[i]<=1)
                continue;
            int f=indexes[i].first;
            int e=indexes[i].second;
            if(e-f>1)
            {
                us.clear();
                for(int j=f+1;j<e;j++)
                    us.insert(s[j]);
                result+=us.size();
            }
        }
        return result;
    }
};