class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int _min=arrays[0][0];
        int _max=arrays[0][arrays[0].size()-1];
        int result=INT_MIN;
        int n=arrays.size();
        for(int i=1;i<n;i++)
        {
            result=max(result,abs(arrays[i][0]-_max));
            result=max(result,abs(arrays[i][arrays[i].size()-1]-_min));
            _max=max(_max, arrays[i][arrays[i].size()-1]);
            _min=min(_min, arrays[i][0]);
        }
        return result;
    }
};