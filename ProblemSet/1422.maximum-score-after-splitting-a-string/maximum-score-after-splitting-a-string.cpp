class Solution {
public:
    int maxScore(string s) {
        int left=0;
        int right=accumulate(s.begin(),s.end(),0)-(s.size()*'0');
        int result=0;
        s.pop_back();
        for(char c:s)
        {
            if(c=='0')
                left++;
            else
                right--;
            result=max(result,left+right);
        }
        return result;
    }
};