class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.length();
        int count=0;
        int lastIndex=0;
        for(int i=0;i<n;i++)
        {
            if(isupper(word[i]))
            {
                count++;
                lastIndex=i;
            }
        }
        if(count==n) return true;
        else if(!count) return true;
        else if(count==1&&!lastIndex) return true;
        else return false;
    }
};