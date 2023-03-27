class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int result=0;
        for(int i=0,j=0;i<n;i=j)
        {
            while(j<n&&chars[j]==chars[i])
                j++;
            chars[result++]=chars[i];
            if(j-i==1)
                continue;
            for(char c:to_string(j-i))
                chars[result++]=c;
        }
        return result;
    }
};