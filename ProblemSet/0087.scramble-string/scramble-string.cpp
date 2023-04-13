class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1==s2) return true;
        if(s1.length()!=s2.length()) return false;
        unordered_map<string,bool> um;
        function<bool(string,string)> helper=[&](string a,string b)->bool{
            if(a==b) return true;
            if(a.length()<=1) return false;
            int n=a.length();
            bool check=false;
            string key=a+" "+b;
            if(um.count(key))
                return um[key];
            for(int i=1;i<n;i++)
            {
                bool swap=helper(a.substr(0,i),b.substr(n-i))&&helper(a.substr(i),b.substr(0,n-i));
                bool unswap=helper(a.substr(0,i),b.substr(0,i))&&helper(a.substr(i),b.substr(i));
                if(swap||unswap)
                {
                    check=true;
                    break;
                }
            }
            um[key]=check;
            return check;
        };
        return helper(s1,s2);
    }
};