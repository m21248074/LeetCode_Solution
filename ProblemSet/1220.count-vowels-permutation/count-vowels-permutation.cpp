class Solution {
public:
    int countVowelPermutation(int n) {
        const long MOD=1e9+7;
        vector<long> status(5,1);
        for(int i=n;i>1;i--)
        {
            vector<long> copy(status);
            for(int j=0;j<status.size();j++)
            {
                long count=copy[j];
                status[j]-=count;
                switch(j)
                {
                    case 0: // a
                        status[1]+=count;
                        break;
                    case 1: // e
                        status[0]+=count;
                        status[2]+=count;
                        break;
                    case 2: // i
                        status[0]+=count;
                        status[1]+=count;
                        status[3]+=count;
                        status[4]+=count;
                        break;
                    case 3: // o
                        status[2]+=count;
                        status[4]+=count;
                        break;
                    case 4: // u
                        status[0]+=count;
                        break;
                }
                status[j]%=MOD;
            }
        }
        long sum=0;
        for(int i=0;i<status.size();i++)
            sum+=status[i];
        return sum%MOD;
    }
};