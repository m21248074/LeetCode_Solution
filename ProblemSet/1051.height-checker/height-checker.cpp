class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int result=0;
        int n=heights.size();
		vector<int> sorted=heights;
		sort(sorted.begin(),sorted.end());
		for (int i=0;i<n;i++)
		  	if(sorted[i]!=heights[i]) result++;
		return result;
    }
};