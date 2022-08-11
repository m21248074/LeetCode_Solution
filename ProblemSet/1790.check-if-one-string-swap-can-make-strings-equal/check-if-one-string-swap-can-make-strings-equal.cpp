class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        unordered_map<char,int> um;
        int count=0;
        for(int i=0;i<s1.length();i++)
        {
            um[s1.at(i)]++;
            um[s2.at(i)]--;
            if(s1.at(i)!=s2.at(i))
                count++;
        }
        for(auto i:um)
        {
            if(i.second!=0)
                return false;
        }
        return count>2?false:true;
    }
};