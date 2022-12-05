class Solution {
public:
    string frequencySort(string s) {
        string result;
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> um;
        for(char c:s)
            um[c]++;
        for(auto i:um)
            pq.push({i.second,i.first});
        while(!pq.empty())
        {
            auto i=pq.top();
            pq.pop();
            result.append(i.first,i.second);
        }
        return result;
    }
};