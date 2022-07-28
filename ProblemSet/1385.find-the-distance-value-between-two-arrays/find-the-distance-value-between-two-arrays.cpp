class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int output=0;
        sort(arr2.begin(),arr2.end());
        for(int i=0;i<arr1.size();i++)
        {
            bool result=true;
            int left=0,right=arr2.size()-1;
            while(left<=right)
            {
                int mid=(left+right)/2;
                if(abs(arr1[i]-arr2[mid])<=d)
                {
                    result=false;
                    break;
                }
                if(arr1[i]<arr2[mid])
                    right=mid-1;
                else // arr1[i]>arr2[mid]
                    left=mid+1;
            }
            if(result) output++;
        }
        return output;
    }
};