class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result;
		map<int,int> m;
		for (int num:arr1) m[num]++;
		for (int num:arr2)
        {
			for(int i=0;i<m[num];++i)
				result.push_back(num);
			m.erase(num);
		}
		for (auto a:m)
        {
			for (int i=0;i<a.second;i++)
				result.push_back(a.first);
		}
		return result;
    }
};