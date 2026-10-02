class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int result = nums[left];

        if (nums[left] > nums[right]) {
             while (left <= right) {
                int mid = (left+right)/2;
                result = min(result, nums[mid]);

                if (nums[mid] > nums[right])
                    left = mid + 1;
                else 
                    right = mid - 1;
            }
        }

        return result;
    }
};