class Solution {
public:
    struct Hash{
        size_t operator()(const pair<int,int> a) const
        {
            return hash<int>()(a.first)^hash<int>()(a.second);
        }
    };
    bool isPathCrossing(string path) {
        unordered_set<pair<int,int>,Hash> walked;
        walked.clear();
        walked.insert(make_pair<int,int>(0,0));
        int x=0;
        int y=0;
        for(char c:path)
        {
            switch(c)
            {
                case 'N':
                    y++;
                    break;
                case 'S':
                    y--;
                    break;
                case 'E':
                    x++;
                    break;
                default:
                    x--;
            }
            if(walked.count({x,y}))
                return true;
            walked.emplace(x,y);
        }
        return false;
    }
};