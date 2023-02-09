class UnionFind
{
    private:
        unordered_map<char,char> parent;
    public:
        UnionFind(string init)
        {
            for(char c:init)
                parent[c]=c;
        }
        char find(char x)
        {
            if(!parent.count(x))
                return x;
            else if(x!=parent[x])
                parent[x]=find(parent[x]);
            return parent[x];
        }
        void unionSets(char a,char b)
        {
            char rootA=find(a);
            char rootB=find(b);
            if(rootA==rootB)
                return;
            else if(rootA<rootB)
                parent[rootB]=rootA;
            else // rootB<rootA
                parent[rootA]=rootB;
        }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.length();
        UnionFind uf(s1+s2);
        for(int i=0;i<n;i++)
            uf.unionSets(s1[i],s2[i]);
        for(char &c:baseStr)
            c=uf.find(c);
        return baseStr;
    }
};