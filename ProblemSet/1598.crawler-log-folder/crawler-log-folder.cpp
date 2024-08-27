class Solution {
public:
    int minOperations(vector<string>& logs) {
        int result=0;
        for(string log:logs)
        {
            if(log=="../")
                result=max(0,result-1);
            else if(log!="./")
                result++;
        }
        return result;
    }
};