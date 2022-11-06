class Solution {
public:
    int countTime(string time) {
        int result=1;
        if(time[4]=='?')result*=10;
        if(time[3]=='?')result*=6;
        if(time[0]=='?'&&time[1]=='?')result*=24;
        else
        {
            if(time[1]=='?') // time[0]!='?'
            {
                if(time[0]=='2')
                    result*=4;
                else
                    result*=10;
            }
            if(time[0]=='?') // time[1]!='?'
            {
                if(time[1]<'4')
                    result*=3;
                else
                    result*=2;
            }
        }
        return result;
    }
};