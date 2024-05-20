class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> um1;
        unordered_map<char,int> um2;
        for(char c:s)
            um1[c]++;
        for(char c:t)
            um2[c]++;
        int result=0;
        for(auto i:um1)
        {
            if(i.second>um2[i.first])
                result+=i.second-um2[i.first];
        }
        return result;
    }
};