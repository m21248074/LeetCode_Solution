class Solution {
private:
    unordered_map<int,vector<int>> um;
public:
    Solution(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
            um[nums[i]].push_back(i);
    }
    int pick(int target) {
        int x=um[target].size();
        x=rand()%x;
        return um[target][x];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */