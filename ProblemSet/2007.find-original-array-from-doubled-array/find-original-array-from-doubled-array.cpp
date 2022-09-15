class Solution {
public:
    static bool cmp(int a,int b)
    {
        return abs(a)<abs(b);
    }
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(),changed.end(),cmp);
        unordered_map<int,int> um;
        for(int num:changed)
            um[num]++;
        vector<int> result;
        for(int num:changed)
        {
            if(um[num]>um[num*2]) return {};
            if(um[num]<=0) continue;
            um[num*2]--;
            um[num]--;
            result.push_back(num);
        }
        return (result.size()!=changed.size()/2)?vector<int>():result;
    }
};