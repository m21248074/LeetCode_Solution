class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int result=0;
        int n=nums.size();
        int curFlipped=0;
        vector<int> isFlipped(n);
        for (int i=0;i<n;i++)
        {
        	if (i>=k)
                curFlipped ^= isFlipped[i-k];
        	if (curFlipped % 2 == nums[i]) {
        		if (i + k> n) return -1;
        		isFlipped[i]=1;
        		curFlipped^=1;
        		result++;
        	}
        }
        return result;
    }
};