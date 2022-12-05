class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<double> s;
        while(nums.size())
        {
            double smallest=nums.front();
            double biggest=nums.back();
            s.insert((smallest+biggest)/2);
            nums.erase(nums.begin());
            nums.pop_back();
        }
        return s.size();
    }
};