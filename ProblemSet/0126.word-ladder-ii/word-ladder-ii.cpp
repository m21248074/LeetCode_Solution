class Solution {
public:
    void dfs(string beginWord,string str,vector<vector<string>>& result,unordered_map<string,int>& um,vector<string> &path)
    {
        int len=beginWord.length();
        path.push_back(str);
        if(str==beginWord) // end
        {
            vector<string> copy(path);
            reverse(copy.begin(),copy.end());
            result.push_back(copy);
            path.pop_back();
            return;
        }
        int cnt=um[str];
        for(int i=0;i<len;i++)
        {
            char c=str.at(i);
            for(int j='a';j<='z';j++)
            {
                str[i]=j;
                if(um.count(str)&&um[str]==cnt-1)
                    dfs(beginWord,str,result,um,path);
            }
            str[i]=c;
        }
        path.pop_back();
        return;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> result;
        vector<string> path;

        unordered_set<string> us(wordList.begin(),wordList.end());
        queue<string> q;
        q.push(beginWord);
        int len=beginWord.length();

        unordered_map<string,int> um;
        um[beginWord]=0;

        while(!q.empty())
        {
            int size=q.size();
            for(int i=size;i>0;i--)
            {
                string str=q.front();
                q.pop();
                int cnt=um[str]+1;
                for(int j=0;j<len;j++)
                {
                    string temp=str;
                    for(int k='a';k<='z';k++)
                    {
                        temp[j]=k;
                        if(!um.count(temp)&&us.count(temp))
                        {
                            um[temp]=cnt;
                            q.push(temp);
                        }
                    }
                }
            }
        }
        if(um.count(endWord))
            dfs(beginWord,endWord,result,um,path);
        return result;
    }
};