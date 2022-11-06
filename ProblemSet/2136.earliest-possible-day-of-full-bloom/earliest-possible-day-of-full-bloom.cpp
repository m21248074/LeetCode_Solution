class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n=plantTime.size();
        int result=0;
        int cur=0;
        vector<int> idx(n);
        iota(idx.begin(),idx.end(),0);
        sort(idx.begin(),idx.end(),[&growTime](int a,int b){return growTime[a]>growTime[b];});
        for(int i:idx)
        {
            cur+=plantTime[i];
            result=max(result,cur+growTime[i]);
        }
        return result;
    }
};