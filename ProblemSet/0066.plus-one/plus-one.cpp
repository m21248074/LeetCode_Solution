class Solution {
public:
    vector<int> helper(vector<int>& digits,int tail)
    {
        if(tail==-1)
        {
            digits.insert(digits.begin(),1);
            return digits;
        }
        if(digits[tail]==9)
        {
            digits[tail]=0;
            return helper(digits,tail-1);
        }
        digits[tail]+=1;
        return digits;
    }
    vector<int> plusOne(vector<int>& digits) {
        return helper(digits,digits.size()-1);
    }
};