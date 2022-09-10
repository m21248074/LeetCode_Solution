class Solution {
public:
    int lengthOfLastWord(string s) {
        s.erase(s.find_last_not_of(" ")+1);
        int count=0;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s.at(i)==' ')
                break;
            count++;
        }
        return count;
    }
};