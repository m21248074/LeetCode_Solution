class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string result="";
        string temp="";
        vector<vector<string>> v(26);
        istringstream is(sentence);
        sort(dictionary.begin(),dictionary.end(),[](string &a, string &b){
            return a.size()<b.size();
        });
        for(string word:dictionary)
            v[word[0]-'a'].push_back(word);
        while(is>>temp)
        {
            for(string word:v[temp[0]-'a'])
            {
                if (temp.substr(0,word.size())==word)
                {
                    temp=word;
                    break;
                }
            }
            result+=temp+" ";
        }
        result.pop_back();
        return result;
    }
};