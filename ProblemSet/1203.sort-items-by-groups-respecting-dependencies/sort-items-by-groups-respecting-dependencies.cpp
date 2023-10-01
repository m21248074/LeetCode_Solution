class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for (int i = 0; i < n; ++i) {
            if (group[i] == -1) group[i] = m++;
        }
        vector<unordered_set<int>> graphGroup(m), graphItem(n);
        vector<int> inGroup(m), inItem(n), res;
        for (int i = 0; i < n; ++i) {
            int to_group = group[i];
            for (int j : beforeItems[i]) {
                int from_group = group[j];
                if (from_group != to_group && !graphGroup[from_group].count(to_group)) {
                    graphGroup[from_group].insert(to_group);
                    ++inGroup[to_group];
                }
                if (!graphItem[j].count(i)) {
                    graphItem[j].insert(i);
                    ++inItem[i];
                }
            }
        }
        vector<int> group_sorted = helper(graphGroup, inGroup), item_sorted = helper(graphItem, inItem);
        if (group_sorted.empty() || item_sorted.empty()) return {};
        vector<vector<int>> group2item(m);
        for (int item : item_sorted) {
            group2item[group[item]].push_back(item);
        }
        for (int group_id : group_sorted) {
            for (int item : group2item[group_id]) {
                res.push_back(item);
            }
        }
        return res;
    }
    vector<int> helper(vector<unordered_set<int>>& g, vector<int>& inDegree) {
        vector<int> res;
        queue<int> q;
        for (int i = 0; i < inDegree.size(); ++i) {
            if (inDegree[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int t = q.front(); q.pop();
            res.push_back(t);
            for (int next : g[t]) {
                if (--inDegree[next] == 0) {
                    q.push(next);
                } 
            }
        }
        for (int i = 0; i < inDegree.size(); ++i) {
            if (inDegree[i] > 0) return {};
        }
        return res;
    }
};
