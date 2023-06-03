class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        int result=0;
        vector<int> root(n);
        for(int i=0;i<n;i++)
            root[i]=i;
        function<bool(string,string)> isSimilar=[&](string a,string b)->bool{
            int len=a.length();
            for(int i=0,cnt=0;i<len;i++)
            {
                if(a[i]==b[i]) continue;
                if(++cnt>2) return false;
            }
            return true;
        };
        function<int(int)> getRoot=[&](int i)->int{
            return root[i]==i?i:getRoot(root[i]);
        };
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(!isSimilar(strs[i],strs[j])) continue;
                root[getRoot(j)]=i;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(root[i]==i)
                result++;
        }
        return result;
    }
};