class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int result=0;
        int n=points.size();
        for(int i=0;i<n-1;i++)
        {
            int x_absDiff=abs(points[i][0]-points[i+1][0]);
            int y_absDiff=abs(points[i][1]-points[i+1][1]);
            result+=max(x_absDiff,y_absDiff);
        }
        return result;
    }
};