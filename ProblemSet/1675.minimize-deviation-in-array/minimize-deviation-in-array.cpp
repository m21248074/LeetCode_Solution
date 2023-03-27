class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> s;
        for(int num:nums)
        {
            if(num%2)
                s.insert(num*2);
            else
                s.insert(num);
        }
        int result=INT_MAX;
        while(true)
        {
            int top=*s.rbegin();
            result=min(result,top-*s.begin());
            if(!(top%2))
            {
                s.erase(top);
                s.insert(top/2);
            }
            else
                break;
        }
        return result;
    }
};