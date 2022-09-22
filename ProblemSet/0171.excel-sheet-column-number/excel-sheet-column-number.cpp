class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n=columnTitle.length();
        int result=0;
        for(int i=0;i<n;i++)
        {
            int index=n-i-1;
            result+=(columnTitle[i]-'A'+1)*pow(26,index);
        }
        return result;
    }
};