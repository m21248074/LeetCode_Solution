class Solution {
public:
    string freqAlphabets(string s) {
        reverse(s.begin(),s.end());
        string result;
        for(int i=0;i<s.length();i++)
        {
            if(s.at(i)!='#')
                result.push_back(s.at(i)-'1'+'a');
            else // s.at(i)=='#'
            {
                string temp=s.substr(i+1,2);
                reverse(temp.begin(),temp.end());
                result.push_back('a'+stoi(temp)-1);
                i+=2;
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};