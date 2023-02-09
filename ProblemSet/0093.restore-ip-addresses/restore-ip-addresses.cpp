class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        function<bool(string)> isValid=[&](string s){
            if(s.empty()||s.size()>3||(s.size()>1&&s[0]=='0'))
                return false;
            int result=stoi(s);
            return result<=255&&result>=0;
        };
        function<void(string,string,int)> helper=[&](string s,string r,int k){
            if(k==0) 
            {
                if(s.empty()) result.push_back(r);
            }
            else
            {
                for(int i=1;i<=3;i++)
                {
                    string subS=s.substr(0,i);
                    if(s.size()>=i&&isValid(subS))
                    {
                        if(k==1)
                            helper(s.substr(i),r+subS,k-1);
                        else
                            helper(s.substr(i),r+subS+".",k-1);
                    }
                }
            }
        };
        helper(s,"",4);
        return result;
    }
};