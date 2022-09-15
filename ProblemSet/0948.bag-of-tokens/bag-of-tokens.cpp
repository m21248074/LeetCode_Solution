class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int left=0,right=tokens.size()-1;
        int score=0;
        sort(tokens.begin(),tokens.end());
        while(left<=right)
        {
            if(tokens[left]<=power)
            {
                power-=tokens[left];
                left++;
                score+=1;
            }
            else if(score>=1&&left<right)
            {
                power+=tokens[right];
                right--;
                score-=1;
            }
            else
                break;
        }
        return score;
    }
};