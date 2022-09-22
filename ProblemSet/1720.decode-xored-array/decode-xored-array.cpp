class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> result;
        result.push_back(first);
        for(int e:encoded)
        {
            result.push_back(first^e);
            first^=e;
        }
        return result;
    }
};