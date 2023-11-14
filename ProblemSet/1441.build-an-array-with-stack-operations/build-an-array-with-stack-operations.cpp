class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;
        int cur=0;
        for(int i=1;i<=n;i++)
        {
            if(target[cur]==i)
            {
                result.push_back("Push");
                cur++;
                if(cur>=target.size())
                    break;
            }
            else
            {
                result.push_back("Push");
                result.push_back("Pop");
            }
        }
        return result;
    }
};