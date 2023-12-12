class Solution {
public:
    string largestGoodInteger(string num) {
        string result;
        int len=num.size();
        for(int i=0;i<len-2;i++)
            if(num[i]==num[i+1]&&num[i]==num[i+2]&&(result.empty()||num[i]>result[0]))
                result=num.substr(i,3);
        return result;
    }
};