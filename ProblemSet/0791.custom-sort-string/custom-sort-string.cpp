class Solution {
public:
    string customSortString(string order, string s) {
        int n=order.size();
        unordered_map<char,int> um;
        for(int i=0;i<n;i++)
            um[order[i]]=i;
        sort(s.begin(),s.end(),[&](char a,char b)->bool{
            return um[a]<um[b];
        });
        return s;
    }
};