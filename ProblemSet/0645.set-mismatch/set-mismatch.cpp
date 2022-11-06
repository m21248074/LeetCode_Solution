class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        map<int,int> m;
        for(int num:nums)
            m[num]++;
        vector<int> result(2);
        for(int i=1;i<=n;i++)
        {
            if(!m.count(i))
                result[1]=i;
            else if(m[i]==2)
                result[0]=i;
        }
        return result;
    }
};