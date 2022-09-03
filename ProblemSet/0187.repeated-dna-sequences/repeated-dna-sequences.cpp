class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.length();

        unordered_set<string> us;
        unordered_set<string> result;

        int left=0,right=0;
        string window="";
        while(right<n)
        {
            window.push_back(s.at(right));
            right++;
            if(right-left==10)
            {
                if(us.count(window))
                    result.insert(window);
                else
                    us.insert(window);
                window.erase(0,1);
                left++;
            }
        }
        vector<string> temp;
        for(auto i:result)
            temp.push_back(i);
        return temp;
    }
};