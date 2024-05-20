class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> um;
        for(int num:nums)
            um[num]++;
        int maxCnt=0;
        for(auto i:um)
            maxCnt=max(maxCnt,i.second);
        int result=0;
        for(auto i:um)
        {
            if(i.second==maxCnt)
                result+=i.second;
        }
        return result;
    }
};