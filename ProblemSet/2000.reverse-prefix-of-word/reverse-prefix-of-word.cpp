class Solution {
public:
    string reversePrefix(string word, char ch) {
        int idx=word.find(ch);
        if(idx==-1) return word;
        int idx2=(idx-1)/2;
        for(int i=0;i<=idx2;i++)
            swap(word[i],word[idx-i]);
        return word;
    }
};