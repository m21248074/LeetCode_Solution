class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        int result=0;
        int range=0;
        int sum=0;

        sort(satisfaction.begin(),satisfaction.end());
        for(int i=n-1;i>=0;i--)
        {
            range+=satisfaction[i];
            sum+=range;
            result=max(result,sum);
        }
        return result;
    }
};