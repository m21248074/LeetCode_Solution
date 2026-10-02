class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> result;
        set<int> s(friends.begin(),friends.end());
        for(int o:order)
        {
            if(s.count(o))
                result.push_back(o);
        }
        return result;
    }
};