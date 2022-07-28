class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l=0,r=letters.size();
        while(l<r)
        {
            int m=(l+r)/2;
            if(letters.at(m)==target)
                l=m+1;
            else if(letters.at(m)>target)
                r=m;
            else // letters.at(m)<target
                l=m+1;
        }
        return (l==letters.size())?letters.at(0):letters.at(l);
    }
};