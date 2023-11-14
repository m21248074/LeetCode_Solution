class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n=arr.size();
        int cur=arr[0];
        int cnt=0;
        for(int i=1;i<n;i++)
        {
            if(arr[i]>cur)
            {
                cur=arr[i];
                cnt=0;
            }
            if(++cnt==k) return cur;
        }
        return cur;
    }
};