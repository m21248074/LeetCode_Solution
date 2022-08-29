class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string nStr=to_string(n);
        sort(nStr.begin(),nStr.end());
        for(int i=0;i<31;i++)
        {
            string temp=to_string(1<<i);
            sort(temp.begin(),temp.end());
            if(temp==nStr) return true;
        }
        return false;
    }
};