class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int>& nums) {
        this->nums=nums;
    }
    vector<int> reset() {
        return nums;
    }
    vector<int> shuffle() {
        random_device rd;
        default_random_engine gen=default_random_engine(rd());
        int n=nums.size();
        vector<int> copy(nums);
        for(int i=0;i<n;i++)
        {
            uniform_int_distribution dis(i,n-1);
            swap(copy[i],copy[dis(gen)]);
        }
        return copy;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */