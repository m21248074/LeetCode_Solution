class Solution {
public:
    int romanToInt(string s) {
        int result=0;
        unordered_map<char,int> um({{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}});
        for(int i=0;i<s.length();i++)
        {
            if(i+1<s.length()&&um[s.at(i)]<um[s.at(i+1)])
                result-=um[s.at(i)];
            else
                result+=um[s.at(i)];
        }
        return result;
    }
};