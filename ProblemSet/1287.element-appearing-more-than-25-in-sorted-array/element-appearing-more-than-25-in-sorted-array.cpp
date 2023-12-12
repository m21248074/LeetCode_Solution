class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> um;
        for(int i:arr)
        {
            um[i]++;
            if(um[i]>n/4)
                return i;
        }
        return 0;
    }
};