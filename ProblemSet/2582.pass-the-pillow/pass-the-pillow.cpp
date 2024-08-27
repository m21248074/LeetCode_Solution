class Solution {
public:
    int passThePillow(int n, int time) {
        int dir=1;
        int result=1;
        for(int i=0;i<time;i++)
        {
            result+=dir;
            if(result==n)
                dir*=-1;
            else if(result==1)
                dir*=-1;
        }
        return result;
    }
};