class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> result;
        unordered_map<string,vector<string>> um;
        for(auto path:paths)
        {
            string parentDir=path.substr(0,path.find(' '))+"/";
            path=path.substr(path.find(' ')+1);
            size_t pos=0;
            string token;
            while((pos=path.find(' '))!=path.npos)
            {
                token=path.substr(0,pos);
                string filename=parentDir+token.substr(0,token.find('('));
                string content=token.substr(token.find('(')+1,token.find(')')-token.find('(')-1);
                um[content].push_back(filename);
                path.erase(0,pos+1);
            }
            string filename=parentDir+path.substr(0,path.find('('));
            string content=path.substr(path.find('(')+1,path.find(')')-path.find('(')-1);
            um[content].push_back(filename);
        }
        for(auto i:um)
        {
            if(i.second.size()>1)
                result.push_back(i.second);
        }
        return result;
    }
};