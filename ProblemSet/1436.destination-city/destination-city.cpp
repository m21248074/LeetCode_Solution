class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,string> um;
        for(auto path:paths)
            um[path[0]]=path[1];
        string city=paths[0][1];
        while(true)
        {
            if(!um.count(city))
                return city;
            city=um[city];
        }
        return "";
    }
};