class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int result=0;
        set<int> s;
        for(int num:nums)
            s.insert(num);
        for(int i:s)
        {
            if(s.count(i-diff)&&s.count(i+diff))
                result++;
        }
        return result;
    }
};