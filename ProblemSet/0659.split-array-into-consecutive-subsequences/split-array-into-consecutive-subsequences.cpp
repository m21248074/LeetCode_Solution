class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> cnts,need;
        for(int num:nums)
            cnts[num]++;
        for(int num:nums)
        {
            if(!cnts[num]) continue;
            // cnts[num]!=0
            if(need[num]>0)
            {
                need[num]--;
                need[num+1]++;
            }
            else if(cnts[num+1]>0&&cnts[num+2]>0)
            {
                cnts[num+1]--;
                cnts[num+2]--;
                need[num+3]++;
            }
            else
                return false;
            cnts[num]--;
        }
        return true;
    }
};