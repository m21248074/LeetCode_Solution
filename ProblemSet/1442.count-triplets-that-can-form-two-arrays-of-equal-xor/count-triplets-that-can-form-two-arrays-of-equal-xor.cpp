class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        if (n<2)
            return 0;
        int result=0;
        for(int i=0;i<n;i++)
        {
            int temp=arr[i];
            for(int j=i+1;j<n;j++)
            {
                temp^=arr[j];
                if(!temp)
                    result+=j-i;
            }
        }
        return result;
    }
};