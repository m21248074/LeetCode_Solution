class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> need,window;
        for(char c:s1) need[c]++;

        int left=0,right=0,valid=0;

        int start=0,len=s2.size()+50;
        while(right<s2.size())
        {
            char c=s2[right];
            right++;
            if(need.count(c))
            {
                window[c]++;
                if(need[c]==window[c])
                    valid++;
            }
            if(right-left>=s1.size())
            {
                if(valid==need.size())
                    return true;
                char d=s2[left];
                left++;
                if(need.count(d))
                {
                    if(need[d]==window[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        return false;
    }
};