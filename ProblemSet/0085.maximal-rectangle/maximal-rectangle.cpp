class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int result=0;
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> height;
        
        function<int()> helper=[&]()->int{
            int result=0;
            stack<int> s;
            height.push_back(0);
            for(int i=0;i<height.size();i++)
            {
                if(s.empty()||height[s.top()]<=height[i])
                    s.push(i);
                else
                {
                    int temp=s.top();
                    s.pop();
                    result=max(result,height[temp]*(s.empty()?i:i-s.top()-1));
                    i--;
                }
            }
            return result;
        };

        for(int i=0;i<m;i++)
        {
            height.resize(n);
            for(int j=0;j<n;j++)
                height[j]=matrix[i][j]=='0'?0:1+height[j];
            result=max(result,helper());
        }
        return result;
    }
};