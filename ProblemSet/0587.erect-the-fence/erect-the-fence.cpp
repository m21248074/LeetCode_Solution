class Solution {
private:
    static bool compare(vector<int> a,vector<int> b)
    {
        return (a[0]<b[0])||(a[0]==b[0]&&a[1]<b[1]);
    }
    double cross(vector<int> o,vector<int> a,vector<int> b)
    {
        return (a[0]-o[0])*(b[1]-o[1])-(a[1]-o[1])*(b[0]-o[0]);
    }
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        vector<vector<int>> result;
        int n=trees.size();
        sort(trees.begin(),trees.end(),compare);
        int m=0;
        for(int i=0;i<n;i++)
        {
            while(m>=2&&cross(result[m-2],result[m-1],trees[i])<0)
            {
                result.pop_back();
                m--;
            }
            result.push_back(trees[i]);
            m++;
        }
        for(int i=n-2,t=m+1;i>=0;i--)
        {
            while(m>=t&&cross(result[m-2],result[m-1],trees[i])<0)
            {
                result.pop_back();
                m--;
            }
            result.push_back(trees[i]);
            m++;
        }
        sort(result.begin(),result.end());
        result.erase(unique(result.begin(),result.end()),result.end());
        return result;
    }
};