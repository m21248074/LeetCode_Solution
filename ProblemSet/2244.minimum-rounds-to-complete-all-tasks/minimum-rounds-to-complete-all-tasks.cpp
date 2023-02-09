class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int result=0;
        map<int,int> m;
        for(int task:tasks)
            m[task]++;
        for(auto i:m)
        {
            if(i.second==1)
                return -1;
            else if(!(i.second%3))
                result+=i.second/3;
            else if(i.second==2)
                result++;
            else
            {
                int cnt=i.second;
                while(cnt-3!=1&&cnt-3>=0)
                {
                    cnt-=3;
                    result++;
                }
                result+=cnt/2;
            }
        }
        return result;
    }
};