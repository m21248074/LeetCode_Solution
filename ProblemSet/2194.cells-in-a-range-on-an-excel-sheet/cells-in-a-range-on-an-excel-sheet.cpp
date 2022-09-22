class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> result;
        for(int i=s.at(0);i<=s.at(3);i++)
        {
            for(int j=s.at(1);j<=s.at(4);j++)
            {
                string t;
                t.push_back(i);
                t.push_back(j);
                result.push_back(t);
            }
        }
        return result;
    }
};