class Solution {
public:
    static bool cmp(int a,int b)
    {
        return abs(a)<abs(b);
    }
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int,int> um;
        for(int num:arr)
            um[num]++;
        vector<int> keys;
        for(auto i:um) keys.push_back(i.first);
        sort(keys.begin(),keys.end(),cmp);
        for(int num:keys)
        {
            if(um[num]>um[num*2]) return false;
            um[num*2]-=um[num];
        }
        return true;
    }
};