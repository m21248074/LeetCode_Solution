class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n=obstacles.size();
        vector<int> result;
        vector<int> order;
        for(int i=0;i<n;i++)
        {
            if(!order.size()||order.back()<=obstacles[i])
            {
                order.push_back(obstacles[i]);
                result.push_back(order.size());
            }
            else
            {
                int index=upper_bound(order.begin(),order.end(),obstacles[i])-order.begin();
                order[index]=obstacles[i];
                result.push_back(index+1);
            }
        }
        return result;
    }
};