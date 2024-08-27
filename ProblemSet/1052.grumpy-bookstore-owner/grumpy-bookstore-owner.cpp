class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int result=0;
        int sum=0;
        vector<int> ones(n+1);
        for(int i=1;i<=n;i++)
        {
            ones[i]+=ones[i-1];
            if(grumpy[i-1]==1)
                ones[i]+=customers[i-1];
            else
                sum+=customers[i-1];
        }        
        for(int i=0;i+minutes<=n;i++)
            result=max(result,sum+ones[i+minutes]-ones[i]);
        return result;
    }
};