class NumArray {
private:
    vector<int> preNums;
public:
    NumArray(vector<int>& nums) {
        preNums.push_back(0);
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            preNums.push_back(sum);
        }
    }
    int sumRange(int left, int right) {
        return preNums[right+1]-preNums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */