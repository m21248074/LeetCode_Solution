class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> um;
        int max=-1;
        int max_cnt=0;
        for(int num:nums)
        {
            if(num%2) continue;
            um[num]++;
            if(um[num]>max_cnt)
            {
                max=num;
                max_cnt=um[num];
            }
            else if(um[num]==max_cnt&&max>num)
                max=num;
        }
        return max;
    }
};