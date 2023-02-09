class Solution {
public:
    string convert(string s, int numRows) {
        int max_increase=(numRows==1)?1:2*numRows-2;
        string result;
        int inc1,inc2;
        bool swap;
        for(int i=0;i<numRows;i++)
        {
            int j=i;
            swap=true;
            inc1=(i==numRows-1)?max_increase:max_increase-i*2;
            inc2=(i==0)?max_increase:i*2;
            while(j<s.length())
            {
                result.push_back(s[j]);
                if(i==0||i==numRows-1)
                    j+=max_increase;
                else
                {
                    j+=(swap)?inc1:inc2;
                    swap=!swap;
                }
            }
        }
        return result;
    }
};