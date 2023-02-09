class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int result=1;
        int n=points.size();
        sort(points.begin(),points.end());
        int end=points[0][1];
        for(int i=1;i<n;i++)
        {
            if(points[i][0]<=end)
                end=min(end,points[i][1]);
            else // points[i][0]>end
            {
                result++;
                end=points[i][1];
            }
        }
        return result;
    }
};