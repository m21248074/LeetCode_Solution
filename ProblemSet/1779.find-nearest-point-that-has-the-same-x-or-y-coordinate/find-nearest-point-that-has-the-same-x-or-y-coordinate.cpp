class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int index=-1;
        int d=INT_MAX;
        for(int i=0;i<points.size();i++)
        {
            vector<int> point=points[i];
            if(point[0]==x||point[1]==y)
            {
                if(abs(point[0]-x)+abs(point[1]-y)<d)
                {
                    index=i;
                    d=abs(point[0]-x)+abs(point[1]-y);
                }
            }
        }
        return index;
    }
};