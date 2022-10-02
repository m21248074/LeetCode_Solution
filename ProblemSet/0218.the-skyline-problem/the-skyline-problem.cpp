class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> heights;
        for(auto building:buildings)
        {
            heights.push_back(make_pair(building[0],-building[2]));
            heights.push_back(make_pair(building[1],building[2]));
        }
        sort(heights.begin(),heights.end());
        vector<vector<int>> result;
        multiset<int> ms;
        ms.insert(0);
        int pre=0;
        for(auto height:heights)
        {
            if(height.second<0)
                ms.insert(-height.second);
            else
                ms.erase(ms.find(height.second));
            int cur=*ms.rbegin();
            if(pre!=cur)
            {
                result.push_back(vector<int>({height.first,cur}));
                pre=cur;
            }
        }
        return result;
    }
};