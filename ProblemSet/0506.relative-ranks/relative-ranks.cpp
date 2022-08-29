class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<int> ranks(n,1);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(score[i]<score[j])
                    ranks[i]++;
                else //score[i]>score[j]
                    ranks[j]++;
            }
        }
        vector<string> result;
        vector<string> rankStr({"Gold","Silver","Bronze"});
        for(int rank:ranks)
        {
            if(rank<=3)
                result.push_back(rankStr[rank-1]+" Medal");
            else
                result.push_back(to_string(rank));
        }
        return result;
    }
};