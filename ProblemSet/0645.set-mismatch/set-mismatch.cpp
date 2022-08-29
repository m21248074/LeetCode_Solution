class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int d=0;
        int m=0;
        unordered_map<int,int> um;
        for(int num:nums) um[num]++;
        for(int i=1;i<=nums.size();i++)
        {
            if(um[i]==2)
                d=i;
            else if(!um[i])
                m=i;
            if(d&&m)
                break;
        }
        return vector<int>({d,m});
    }
};