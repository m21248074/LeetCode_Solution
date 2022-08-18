class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> um;
        for(int num:arr)
            um[num]++;
        vector<int> counts;
        for(auto i=um.begin();i!=um.end();i++)
            counts.push_back(i->second);
        sort(counts.begin(),counts.end());
        int target=arr.size()/2;
        int cur_n=arr.size();
        int cnt=0;
        while(target<cur_n)
        {
            cur_n-=counts.back();
            counts.pop_back();
            cnt++;
        }
        return cnt;
    }
};