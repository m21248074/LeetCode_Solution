class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> scores;
        for(string op:ops)
        {
            if(op=="C")
                scores.pop_back();
            else if(op=="D")
                scores.push_back(scores.back()*2);
            else if(op=="+")
            {
                int lastSecond=scores.at(scores.size()-2);
                scores.push_back(scores.back()+lastSecond);
            }
            else
                scores.push_back(stoi(op));
        }
        int result=0;
        for(int score:scores)
            result+=score;
        return result;
    }
};