class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> s;
        for(int i=0;i<arr.size();i++)
        {
            if(s.count(arr[i]*2))
                return true;
            else if(!(arr[i]%2)&&s.count(arr[i]/2))
                return true;
            s.insert(arr[i]);
        }
        return false;
    }
};