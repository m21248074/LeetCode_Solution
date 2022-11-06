class Solution {
public:
    bool helper(string a,string b)
    {
        int count=0;
        for(int i=0;i<8;i++)
        {
            if(a[i]!=b[i])
                count++;
        }
        return count==1?true:false;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        queue<pair<string,int>> q;
        q.push({start,0});
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            auto iter=bank.begin();
            while(iter!=bank.end())
            {
                if(helper(node.first,*iter))
                {
                    if(*iter==end)
                        return node.second+1;
                    else
                        q.push({*iter,node.second+1});
                    iter=bank.erase(iter);
                }
                else
                    iter++;
            }
        }
        return -1;
    }
};