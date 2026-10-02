class Solution {
public:
    int reverseDegree(string s) {
        int result=0;
        for(int i=0;i<s.length();i++)
        {
            char c=s[i];
            int idx=26-(c-'a');
            result+=idx*(i+1);
        }
        return result;
    }
};