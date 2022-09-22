class Trie {
private:
    int cnt;
    Trie* children[26]={};
public:
    Trie() {
        cnt=0;
    }
    void insert(string word) {
        Trie* t=this;
        for(int i=0;i<word.length();i++)
        {
            char c=word[i];
            if(t->children[c-'a']==nullptr) t->children[c-'a']=new Trie();
            t->children[c-'a']->cnt++;
            t=t->children[c-'a'];
        }
    }
    int getPrefixScores(string word)
    {
        int sum=0;
        Trie* t=this;
        for(int i=0;i<word.length();i++)
        {
            char c=word[i];
            sum+=t->children[c-'a']->cnt;
            t=t->children[c-'a'];
        }
        return sum;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n=words.size();
        vector<int> result;
        Trie t;
        for(string word:words)
            t.insert(word);
        for(string word:words)
            result.push_back(t.getPrefixScores(word));
        return result;
    }
};