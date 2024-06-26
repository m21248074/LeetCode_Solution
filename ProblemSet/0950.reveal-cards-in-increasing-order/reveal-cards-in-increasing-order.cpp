class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        vector<int> result(n);
        queue<int> q;
        sort(deck.begin(),deck.end());
        for(int i=0;i<n;i++) q.push(i);
        for(int i=0;i<n;i++)
        {
            int t=q.front();
            q.pop();
            result[t]=deck[i];
            t=q.front();
            q.pop();
            q.push(t);
        }
        return result;
    }
};