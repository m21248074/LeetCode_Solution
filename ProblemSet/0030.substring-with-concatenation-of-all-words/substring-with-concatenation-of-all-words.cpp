class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        const int single_len=words[0].length();
        const int len=words.size()*single_len;
        unordered_map<string,int> um;
        for(string word:words)
            um[word]++;
        int left=0,right=0; // (left,right]
        while(right<s.length())
        {
            char c=s.at(right);
            right++;
            if(right-left==len)
            {
                bool isOK=true;
                string temp=s.substr(left,right-left);
                unordered_map<string,int> copy(um);
                for(int i=0;i<len;i+=single_len)
                {
                    string t=temp.substr(i,single_len);
                    if(!copy[t])
                    {
                        isOK=false;
                        break;
                    }
                    copy[t]--;
                }
                if(isOK)
                    result.push_back(left);
                left++;
            }
        }
        return result;
    }
};