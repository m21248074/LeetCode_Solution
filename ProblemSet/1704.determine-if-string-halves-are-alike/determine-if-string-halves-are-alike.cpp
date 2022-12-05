class Solution {
public:
    int countVowels(string s)
    {
        int count=0;
        for(char c:s)
        {
            switch(c)
            {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                    count++;
            }
        }
        return count;
    }
    bool halvesAreAlike(string s) {
        int n=s.length();
        string a=s.substr(0,n/2);
        string b=s.substr(n/2);
        return countVowels(a)==countVowels(b);
    }
};