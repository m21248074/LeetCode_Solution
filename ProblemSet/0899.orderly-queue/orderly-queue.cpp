class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k>1)
        {
            sort(s.begin(),s.end());
            return s;
        }
        string result=s;
        for(int i=0;i<s.length();i++)
            result=min(result,s.substr(i)+s.substr(0,i));
        return result;
    }
};