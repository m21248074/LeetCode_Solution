class DSU {
private:
    vector<int> parents;
    vector<int> size;
public:
    DSU(int n)
    {
        parents=vector<int>(n+1);
        size=vector<int>(n+1);
        for(int i=0;i<=n;i++)
        {
            parents[i]=i;
            size[i]=1;
        }
    }
    int find(int x)
    {
        if(parents[x]!=x)
            parents[x]=find(parents[x]);
        return parents[x];
    }
    void Union(int x,int y)
    {
        int parentX=find(x);
        int parentY=find(y);
        if(parentX==parentY)
            return;
        if(size[parentX]>size[parentY])
        {
            // swap parentX and parentY
            int temp=parentX;
            parentX=parentY;
            parentY=temp;
        }
        parents[parentX]=parentY;
        size[parentY]+=size[parentX];
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return true;
        int MAX=nums[0];
        set<int> s;
        for(int num:nums)
        {
            s.insert(num);
            MAX=max(MAX,num);
        }
        if(s.count(1))
            return false;
        vector<int> sieve(MAX+1);
        for(int i=2;i<=MAX;i++)
        {
            if(sieve[i]==0)
            {
                for(int j=i;j<=MAX;j+=i)
                    sieve[j]=i;
            }
        }
        DSU dsu(2*MAX+1);
        for(int num:nums)
        {
            int val=num;
            while(val>1)
            {
                int prime=sieve[val];
                int root=prime+MAX;
                if(dsu.find(root)!=dsu.find(num))
                    dsu.Union(root,num);
                while(val%prime==0)
                    val/=prime;
            }
        }
        int cnt=0;
        for(int i=2;i<=MAX;i++)
        {
            if(s.count(i)&&dsu.find(i)==i)
                cnt++;
        }
        return cnt==1;
    }
};