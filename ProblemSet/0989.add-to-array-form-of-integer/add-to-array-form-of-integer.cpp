class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n=num.size();
        int i=n-1;
        while(k)
        {
            int t=k%10;
            k/=10;
            if(i==-1)
            {
                num.insert(num.begin(),0);
                n++;
                i++;
            }
            num[i]+=t;
            i--;
        }
        for(i=n-1;i>=0;i--)
        {
            if(num[i]>=10)
            {
                num[i]%=10;
                if(i)
                    num[i-1]++;
                else
                {
                    num.insert(num.begin(),1);
                    i++;
                }
            }
        }
        return num;
    }
};