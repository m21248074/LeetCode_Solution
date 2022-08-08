struct cmp
{
    bool operator()(pair<string,int> a,pair<string,int> b)
    {
        if(a.second!=b.second)
            return a.second>b.second;
        else // a.second==b.second
            return a.first<b.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> result(k);
        unordered_map<string,int> um;
        priority_queue<pair<string,int>,vector<pair<string,int>>,cmp> pq;
        for(string word:words)
            um[word]++;
        for(auto i=um.begin();i!=um.end();i++)
        {
            pq.push({i->first,i->second});
            if(pq.size()>k)
                pq.pop();
        }
        for(int i=k-1;i>=0;i--)
        {
            pair<string,int> tmp=pq.top();
            pq.pop();
            result[i]=tmp.first;
        }
        return result;
    }
};