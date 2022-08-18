class Solution {
public:
    static int get1Bits(int num)
    {
        int result=0;
        while(num!=0)
        {
            if(num%2)
                result++;
            num/=2;
        }
        return result;
    }
    static bool compare(int a,int b)
    {
        if(get1Bits(a)!=get1Bits(b))
            return get1Bits(a)<get1Bits(b);
        else
            return a<b;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare);
        return arr;
    }
};