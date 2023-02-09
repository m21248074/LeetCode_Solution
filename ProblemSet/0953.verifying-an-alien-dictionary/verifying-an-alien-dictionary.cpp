class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> um;
        for(int i=0;i<order.length();i++)
            um[order[i]]=i;
        return is_sorted(words.begin(),words.end(),[&](string a,string b){
            int i=0;
            while(true)
            {
                int a_=-1;
                int b_=-1;
                if(a.length()>=i)
                    a_=um[a[i]];
                if(b.length()>=i)
                    b_=um[b[i]];
                if(a_==-1&&b_==-1)
                    break;
                if(a_!=b_)
                    return a_<b_;
                i++;
            }
            return false;
        });
    }
};