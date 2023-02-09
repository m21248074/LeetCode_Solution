class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> result;
        unordered_set<string> us;
        for(string word:words) us.insert(word);
        for(string word:words)
        {
            us.erase(word);

            int len=word.length();
            vector<bool> v(len+1,false);
            v[0]=true;
            for(int i=0;i<len+1;i++)
            {
                for(int j=0;j<i;j++)
                {
                    if(v[j]&&us.count(word.substr(j,i-j)))
                    {
                        v[i]=true;
                        break;
                    }
                }
            }
            if(v.back())
                result.push_back(word);

            us.insert(word);
        }
        
        return result;
    }
};