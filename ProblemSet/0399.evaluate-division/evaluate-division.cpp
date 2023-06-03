class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> result;
        unordered_map<string,unordered_map<string,double>> um;
        int n=equations.size();
        for(int i=0;i<n;i++)
        {
            um[equations[i][0]][equations[i][1]]=values[i];
            um[equations[i][1]][equations[i][0]]=1.0/values[i];
        }
        for(auto query:queries)
        {
            unordered_set<string> visited;
            function<double(string,string)> helper=[&](string up,string down)->double{
                if(um[up].count(down)) return um[up][down];
                for(auto i:um[up])
                {
                    if(visited.count(i.first)) continue;
                    visited.insert(i.first);
                    double r=helper(i.first,down);
                    if(r>0.0) return r*i.second;
                }
                return -1;
            };
            double r=helper(query[0],query[1]);
            result.push_back(r>0.0?r:-1);
        }
        return result;
    }
};