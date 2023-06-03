class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int,int> um;
        for(int num:nums)
            um[num]++;
        priority_queue<pair<int,int>> pq;
        for(auto i:um)
            pq.emplace(i.second,i.first);
        for(int i=0;i<k;i++)
        {
            auto t=pq.top();
            pq.pop();
            result.push_back(t.second);
        }
        return result;
    }
};