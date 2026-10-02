class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n=bits.size();
        int i=0;
        for(i=0;i<n;i++)
        {
            int bit=bits[i];
            if(bit==1)
                i+=1;
            if(i==n-1 && bit==0)
                return true;
        }
        return false;
    }
};