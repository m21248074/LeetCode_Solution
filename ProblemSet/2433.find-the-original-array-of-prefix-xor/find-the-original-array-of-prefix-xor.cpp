class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n=pref.size();
        if(n==1) return pref;
        vector<int> result;
        result.push_back(pref[0]);
        for(int i=1;i<n;i++)
            result.push_back(pref[i-1]^pref[i]);
        return result;
    }
};