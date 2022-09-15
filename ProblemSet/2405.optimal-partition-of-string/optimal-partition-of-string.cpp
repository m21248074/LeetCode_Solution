class Solution {
public:
    int partitionString(string s) {
        int result=0;
        unordered_set<char> us;
        for(int i=0;i<s.length();i++)
        {
            if(!us.count(s.at(i)))
                us.insert(s.at(i));
            else
            {
                result++;
                us.clear();
                us.insert(s.at(i));
            }
        }
        return result+1;
    }
};