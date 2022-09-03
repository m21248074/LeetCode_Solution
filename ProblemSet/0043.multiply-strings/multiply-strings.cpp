class Solution {
public:
    string multiply(string num1, string num2) {
        string result;
        int m=num1.length(),n=num2.length();
        vector<int> temp(m+n,0);
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                int mul=(num1[i]-'0')*(num2[j]-'0');
                int sum=temp[i+j+1]+mul;
                temp[i+j]+=sum/10;
                temp[i+j+1]=sum%10;
            }
        }
        for(int t:temp)
            if(!result.empty()||t!=0) result.push_back(t+'0');
        return result.empty()?"0":result;
    }
};