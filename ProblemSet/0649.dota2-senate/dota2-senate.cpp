class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> qR;
        queue<int> qD;
        int n=senate.length();
        for(int i=0;i<n;i++)
        {
            if(senate[i]=='R')
                qR.push(i);
            else
                qD.push(i);
        }
        while(!qR.empty()&&!qD.empty())
        {
            int r=qR.front();
            qR.pop();
            int d=qD.front();
            qD.pop();
            if(r>d)
                qD.push(d+n);
            else
                qR.push(r+n);
        }
        return qR.size()?"Radiant":"Dire";
    }
};