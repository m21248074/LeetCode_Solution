class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> count(n);
        int result=0;
        function<void(int,int)> dfs=[&](int index,int pickup){
            if(index==requests.size())
            {
                for(int i:count)
                {
                    if(i!=0)
                        return;
                }
                result=max(result,pickup);
                return;
            }
            count[requests[index][0]]--;
            count[requests[index][1]]++;
            dfs(index+1,pickup+1);
            count[requests[index][0]]++;
            count[requests[index][1]]--;
            dfs(index+1,pickup);
        };
        dfs(0,0);
        return result;
    }
};