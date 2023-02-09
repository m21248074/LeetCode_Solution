class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<int> ms; // monotonic stack
        vector<int> result(n,0);
        for(int i=0;i<n;i++)
        {
            while(!ms.empty()&&temperatures[i]>temperatures[ms.top()])
            {
                int j=ms.top();
                ms.pop();
                result[j]=i-j;
            }
            ms.push(i);
        }
        return result;
    }
};