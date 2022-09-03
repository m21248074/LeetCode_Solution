class Solution {
public:
    int strStr(string haystack, string needle) {
        int left=0,right=0;
        string window="";
        while(right<haystack.size())
        {
            window.push_back(haystack.at(right));
            right++;
            if(right-left==needle.size())
            {
                if(window==needle)
                    return left;
                window.erase(0,1);
                left++;
            }
        }
        return -1;
    }
};