class Solution {
public:
    string pushDominoes(string dominoes) {
        string result;
        dominoes="L"+dominoes+"R";
        for(int i=0,j=1;j<dominoes.length();j++)
        {
            if(dominoes.at(j)=='.') continue;
            int mid=j-i-1;
            if(i)
                result+=dominoes.at(i);
            if(dominoes.at(i)==dominoes.at(j)) // all L or R
                result+=string(mid,dominoes.at(i));
            else if(dominoes.at(i)=='L'&&dominoes.at(j)=='R')
                result+=string(mid,'.');
            else // i == R && j == L
                result+=string(mid/2,'R')+string(mid%2,'.')+string(mid/2,'L');
            i=j;
        }
        return result;
    }
};