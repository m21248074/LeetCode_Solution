class WordDictionary {
private:
    bool have;
    vector<WordDictionary*> children;
public:
    WordDictionary() {
        have=false;
        children=vector<WordDictionary*>(26,nullptr);
    }
    
    void addWord(string word) {
        int i=int(word[0]-'a');
        word.erase(word.begin());
        if(children[i]==nullptr)
            children[i]=new WordDictionary();
        if(word.length())
            children[i]->addWord(word);
        else
            children[i]->have=true;
    }
    
    bool search(string word) {
        if(!word.length()) return true;
        char c=word[0];
        if(c!='.')
        {
            int i=int(c-'a');
            if(children[i]==nullptr) return false;
            word.erase(word.begin());
            if(!word.length())
                return children[i]->have;
            return children[i]->search(word);
        }
        // c=='.'
        word.erase(word.begin());
        bool result=false;
        for(int i=0;i<26&&!result;i++)
        {
            if(children[i]==nullptr) continue;
            if(!word.length())
                result|=children[i]->have;
            else
                result|=children[i]->search(word);
        }
        return result;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */