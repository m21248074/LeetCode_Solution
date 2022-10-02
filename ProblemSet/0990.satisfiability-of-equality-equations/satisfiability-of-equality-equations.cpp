class DisjointSet
{
    private:
        vector<int> parent;
    public:
        DisjointSet()
        {
            parent.resize(26);
            for(int i=0;i<parent.size();i++) parent[i]=i;
        }
        int find(char a)
        {
            int x=a-'a';
            if(parent[x]!=x)
                parent[x]=find(parent[x]+'a');
            return parent[x];
        }
        void join(char x,char y)
        {
            int parentX=find(x);
            int parentY=find(y);
            if(parentX==parentY) return;
            parent[parentX]=parentY;
        }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int n=equations.size();
        DisjointSet ds;
        for(string equation:equations)
        {
            char r=equation[1];
            if(r=='!') continue;
            char a=equation[0];
            char b=equation[3];
            ds.join(a,b);
        }
        for(string equation:equations)
        {
            char r=equation[1];
            if(r=='=') continue;
            char a=equation[0];
            char b=equation[3];
            if(ds.find(a)==ds.find(b)) return false;
        }
        return true;
    }
};