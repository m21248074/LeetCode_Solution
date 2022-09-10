class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_map<char,int> um;
        for(int i=0;i<s.length();i++)
        {
            char c=s.at(i);
            if(!um.count(c))
                um[c]=i;
            else
                um[c]=abs(um[c]-i);
        }
        //cout << um['a'] << endl;
        bool result=true;
        for(int i=0;i<distance.size();i++)
        {
            //cout << char(i+'a') << " " << um[char(i+'a')] << endl;
            if(!um.count(i+'a')) continue;
            if(um[i+'a']!=distance[i]+1)
            {
                result=false;
                break;
            }
        }
        return result;
    }
};