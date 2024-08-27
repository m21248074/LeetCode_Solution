class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> m;
        for (int i : hand) m[i]++;
        while (!m.empty())
        {
            int start=m.begin()->first;
            for (int i=0; i<groupSize;i++) {
                if (!m.count(start+i)) 
                    return false;
                if (--m[start+i]==0) 
                    m.erase(start + i);
            }
        }
        return true;
    }
};