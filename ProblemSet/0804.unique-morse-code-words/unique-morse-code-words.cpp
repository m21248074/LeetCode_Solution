class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse({".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."});
        unordered_set<string> us;
        for(string word:words)
        {
            string temp;
            for(char c:word)
                temp+=morse[c-'a'];
            us.insert(temp);
        }
        return us.size();
    }
};