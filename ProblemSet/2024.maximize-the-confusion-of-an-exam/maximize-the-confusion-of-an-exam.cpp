class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        function<int(char)> helper=[&](char c)->int{
            int len=answerKey.size();
            int result=0;
            int cnt=0;
            for(int i=0,j=0;i<len;i++)
            {
                cnt+=answerKey[i]==c?1:0;
                while(cnt>k)
                {
                    cnt-=answerKey[j]==c?1:0;
                    j++;
                }
                result=max(result,i-j+1);
            }
            return result;
        };
        return max(helper('T'),helper('F'));
    }
};