class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1]; // Longer to end first
            return a[0] < b[0];
        });

        int covered = 0;
        int endPoint = intervals[0][1];

        for(int i = 1; i < n; i++){
            
            if(intervals[i][1] <= endPoint){
                covered++;
            } else {
                endPoint = intervals[i][1];
            }
        }

        return n - covered;
    }
};