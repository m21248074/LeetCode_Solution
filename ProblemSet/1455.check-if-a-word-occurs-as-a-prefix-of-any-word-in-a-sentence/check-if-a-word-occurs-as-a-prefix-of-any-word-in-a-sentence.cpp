class Solution {
public:
    const vector<string> split(string &str,const char &delimiter) {
        vector<string> result;
        stringstream ss(str);
        string tok;

        while (getline(ss, tok, delimiter)) {
            result.push_back(tok);
        }
        return result;
    }
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> words=split(sentence,' ');
        for(int i=0;i<words.size();i++)
        {
            string word=words[i];
            auto res = mismatch(searchWord.begin(), searchWord.end(), word.begin());
            if (res.first == searchWord.end())
                return i+1;
        }
        return -1;
    }
};