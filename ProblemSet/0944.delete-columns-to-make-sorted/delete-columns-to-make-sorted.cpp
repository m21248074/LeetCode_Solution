class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int result=0;
        int n=strs.size();
        int len=strs[0].length();
        for(int i=0;i<len;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(strs[j-1][i]>strs[j][i])
                {
                    result++;
                    break;
                }
            }
        }
        return result;
    }
};