class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int result=INT_MAX;
        int v=INT_MIN;
        int pre=0;
        for(auto log:logs)
        {
            if(log[1]-pre>v)
            {
                v=log[1]-pre;
                result=log[0];
            }
            else if(log[1]-pre==v&&result>log[0])
                result=log[0];
            pre=log[1];
        }
        return result;
    }
};