class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        stack<int> s;
        for(int i=0;i<asteroids.size();i++)
        {
            int asteroid=asteroids[i];
            if(s.empty())
            {
                s.push(asteroid);
                continue;
            }
            // else
            int top=s.top();
            if((top>0&&asteroid>0)||(top<0&&asteroid<0))
                s.push(asteroid);
            else if(top<0&&asteroid>0)
                s.push(asteroid);
            else if(abs(top)==abs(asteroid))
                s.pop();
            else if(abs(top)<abs(asteroid))
            {
                s.pop();
                i--;
            }
        }
        while(!s.empty())
        {
            result.push_back(s.top());
            s.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};