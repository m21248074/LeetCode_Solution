class Trie {
private:
    bool have;
    vector<Trie*> children;
public:
    Trie() {
        have=false;
        children=vector<Trie*>(26,nullptr);
    }
    void insert(string word) {
        int i=int(*word.begin()-'a');
        word.erase(word.begin());
        if(children[i]==nullptr)
            children[i]=new Trie();
        if(word.length())
            children[i]->insert(word);
        else
            children[i]->have=true;
    }
    bool search(string word) {
        if(!word.length()) return true;
        int i=int(*word.begin()-'a');
        if(children[i]==nullptr) return false;
        word.erase(word.begin());
        if(!word.length())
            return children[i]->have;
        return children[i]->search(word);
    }
    bool startsWith(string prefix) {
        if(!prefix.length()) return true;
        int i=int(*prefix.begin()-'a');
        if(children[i]==nullptr) return false;
        prefix.erase(prefix.begin());
        return children[i]->startsWith(prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */