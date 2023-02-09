class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int result=0;
        int total_sum=0;
        int sum=0;
        int n=gas.size();
        for(int i=0;i<n;i++)
        {
            total_sum=total_sum+gas[i]-cost[i];
            sum=sum+gas[i]-cost[i];
            if(sum<0)
            {
                result=i+1;
                sum=0;
            }
        }
        return total_sum>=0?result:-1;
    }
};