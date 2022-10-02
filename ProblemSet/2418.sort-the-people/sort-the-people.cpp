class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n=names.size();
        vector<pair<string,int>> zipped;
        for(int i=0;i<n;i++)
            zipped.push_back(make_pair(names[i],heights[i]));
        sort(begin(zipped),end(zipped),[&](auto &a,auto &b){
            return a.second>b.second;
        });
        for(int i=0;i<n;i++)
            names[i]=zipped[i].first;
        return names;
    }
};