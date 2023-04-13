class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int index=0;
        for(int num:pushed)
        {
            s.push(num);
            while(!s.empty()&&popped[index]==s.top())
            {
                s.pop();
                index++;
            }
        }
        return s.empty();
    }
};