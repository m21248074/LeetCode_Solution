class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=scores.size();
        vector<int> dp(n,0);
        vector<pair<int,int>> data;
        for(int i=0;i<n;i++)
            data.push_back(pair<int,int>(ages[i],scores[i]));
        sort(data.begin(),data.end(),[](pair<int,int> a,pair<int,int> b){
            if(a.first!=b.first)
                return a.first<b.first;
            return a.second<b.second;
        });
        for(int i=0;i<n;i++)
        {
            dp[i]=data[i].second;
            for(int j=0;j<i;j++)
            {
                if(data[i].second>=data[j].second)
                    dp[i]=max(dp[i],dp[j]+data[i].second);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};