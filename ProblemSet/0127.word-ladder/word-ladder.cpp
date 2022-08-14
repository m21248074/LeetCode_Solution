class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());
        if(!s.count(endWord)) return 0;
        queue<string> q;
        q.push(beginWord);
        int step=0;
        int len=beginWord.length();
        while(!q.empty())
        {
            step++;
            for(int i=q.size();i>0;i--)
            {
                string str=q.front();
                q.pop();
                for(int j=0;j<len;j++)
                {
                    char c=str.at(j);
                    for(int k='a';k<='z';k++)
                    {
                        str[j]=k;
                        if(str==endWord) return step+1;
                        if(!s.count(str)) continue;
                        s.erase(str);
                        q.push(str);
                    }
                    str[j]=c;
                }
            }
        }
        return 0;
    }
};