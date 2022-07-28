class Solution {
public:
    int getWords(string sentence)
    {
        int occur=0;
        int p=0;
        while(true)
        {
            int p=sentence.find(" ",p);
            if(p==string::npos)
                break;
            occur++;
            p+=1;
        }
        return occur;
    }
    int mostWordsFound(vector<string>& sentences) {
        vector<int> occurs;
        for(int i=0;i<sentences.size();i++)
            occurs.push_back(getWords(sentences[i]));
        sort(occurs.begin(),occurs.end(),greater<int>());
        return occurs[0]+1;
    }
};