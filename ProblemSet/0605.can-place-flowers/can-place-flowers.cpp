class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len=flowerbed.size();
        for(int i=0;i<len&&n;i++)
        {
            bool front=false;
            bool back=false;
            if(!i||!flowerbed[i-1])
                front=true;
            if(i==len-1||!flowerbed[i+1])
                back=true;
            if(front&&back&&!flowerbed[i])
            {
                flowerbed[i]=1;
                n--;
            }
        }
        return n==0;
    }
};