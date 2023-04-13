class Solution {
public:
    string removeStars(string s) {
        string result;
        for(char c:s)
        {
            if(c!='*')
                result.push_back(c);
            else
                result.pop_back();
        }
        return result;
    }
};