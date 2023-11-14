class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char> vowels({'a','e','i','o','u','A','E','I','O','U'});
        vector<char> v;
        for(char c:s)
        {
            if(vowels.count(c))
                v.push_back(c);
        }
        sort(v.begin(),v.end());
        int i=0;
        string result;
        for(char c:s)
        {
            if(vowels.count(c))
            {
                result+=v[i];
                i++;
            }
            else
                result+=c;
        }
        return result;
    }
};