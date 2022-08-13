class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        vector<int> ps(arr.size()+1,0);
        ps[0]=0;
        for(int i=0;i<arr.size();i++)
            ps[i+1]=ps[i]+arr[i];
        int result=0;
        for(int i=0;i<ps.size();i++)
        {
            for(int j=i+1;j<ps.size();j++)
            {
                int len=j-i;
                if(len%2)
                    result+=ps[j]-ps[i];
            }
        }
        return result;
    }
};