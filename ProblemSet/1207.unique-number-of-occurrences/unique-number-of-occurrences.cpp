class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> um;
        set<int> s;
        for(int i:arr)
            um[i]++;
        for(auto i:um)
            s.insert(i.second);
        return s.size()==um.size();
    }
};