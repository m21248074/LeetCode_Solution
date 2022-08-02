struct Item
{
    int index,count;
};

struct cmp{
    bool operator()(Item a,Item b)
    {
        int a_score=a.count*1000+a.index;
        int b_score=b.count*1000+b.index;
        return a_score > b_score;
    }
};

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> result;
        priority_queue<Item,vector<Item>,cmp> q;
        for(int i=0;i<mat.size();i++)
        {
            Item t;
            t.index=i;
            int count=0;
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j]==1)
                    count++;
            }
            t.count=count;
            q.push(t);
        }
        for(int i=0;i<k;i++)
        {
            Item t=q.top();
            q.pop();
            result.push_back(t.index);
        }
        return result;
    }
};