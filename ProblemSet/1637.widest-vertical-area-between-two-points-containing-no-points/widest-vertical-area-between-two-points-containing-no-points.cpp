class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int result=0;
        int n=points.size();
        sort(points.begin(),points.end());
        for(int i=0;i<n-1;i++)
        {
            if(points[i+1][0]-points[i][0]>result)
                result=points[i+1][0]-points[i][0];
        }
        return result;
    }
};