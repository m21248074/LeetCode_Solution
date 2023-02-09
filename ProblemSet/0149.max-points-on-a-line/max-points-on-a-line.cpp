class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int result=1;
        int n=points.size();
        for(int i=0;i<n;i++)
        {
            map<double,int> m;
            for(int j=i+1;j<n;j++)
            {
                double x=(double)(points[j][1]-points[i][1])/(double)(points[j][0]-points[i][0]);
                if(points[j][1]-points[i][1]<0&&(points[j][0]-points[i][0])==0)
                    m[abs(x)]++;
                else
                    m[x]++;
            }
            for(auto iter:m)
                result=max(result,iter.second+1);
        }
        return result;
    }
};