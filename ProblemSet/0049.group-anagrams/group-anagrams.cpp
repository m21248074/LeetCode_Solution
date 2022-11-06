class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string,int> um;
        for(string str:strs)
        {
            string t=str;
            sort(str.begin(),str.end());
            if(!um.count(str))
            {
                um[str]=result.size();
                result.push_back({});
            }
            result[um[str]].push_back(t);
        }
        return result;
    }
};