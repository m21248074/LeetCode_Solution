class Solution {
public:
    string makeGood(string s) {
        string result;
        for(char c:s)
        {
            if(!result.empty()&&abs(c-result.back())==abs('a'-'A'))
            {
                result.pop_back();
                continue;
            }
            result.push_back(c);
        }
        return result;
    }
};