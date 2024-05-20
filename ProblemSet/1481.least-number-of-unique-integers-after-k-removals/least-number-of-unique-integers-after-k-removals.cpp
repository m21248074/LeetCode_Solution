class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> um;
        for(int num:arr)
            um[num]++;
        int n=um.size();
        vector<int> count;
        for(auto i:um)
            count.push_back(i.second);
        sort(count.begin(),count.end());
        for(int c:count)
        {
            if(k>=c)
            {
                k-=c;
                n--;
            }
            else // k<c
                break;
        }
        return n;
    }
};