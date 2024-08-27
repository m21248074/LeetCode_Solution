class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        return countBeautifulSubsets(nums, k, 0, 0);
    }

private:
    int countBeautifulSubsets(vector<int>& nums, int difference,int index,int mask) {
        if (index == nums.size())
            return mask > 0 ? 1 : 0;
        bool isBeautiful = true;
        for (int j = 0; j < index && isBeautiful; ++j) 
            isBeautiful = ((1 << j) & mask) == 0 ||abs(nums[j] - nums[index]) != difference;
        int skip = countBeautifulSubsets(nums, difference, index + 1, mask);
        int take;
        if (isBeautiful) 
            take = countBeautifulSubsets(nums, difference, index + 1, mask + (1 << index));
        else
            take = 0;
        return skip + take;
    }
};