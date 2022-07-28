class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<char,bool> m;
        int result=0;
        for(int i=0;i<jewels.length();i++)
            m[jewels.at(i)]=true;
        for(int i=0;i<stones.length();i++)
        {
            if(m[stones.at(i)])
                result++;
        }
        return result;
    }
};