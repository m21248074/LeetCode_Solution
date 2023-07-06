class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int> prefix(n+1,0);
        for(int i=1;i<n+1;i++)
            prefix[i]=prefix[i-1]+gain[i-1];
        return *max_element(prefix.begin(),prefix.end());
    }
};