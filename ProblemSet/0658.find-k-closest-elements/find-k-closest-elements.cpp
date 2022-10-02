class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(),arr.end(),[&](auto &a,auto &b){
            if(abs(a-x)!=abs(b-x))
                return abs(a-x)<abs(b-x);
            else
                return a<b;
        });
        arr.erase(arr.begin()+k,arr.end());
        sort(arr.begin(),arr.end());
        return arr;
    }
};