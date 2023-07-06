class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int result=INT_MAX;
        vector<int> childs(k,0);
        function<void(int)> helper=[&](int index){
            if(index==cookies.size())
            {
                result=min(*max_element(childs.begin(),childs.end()),result);
                return;
            }
            for(int i=0;i<k;i++)
            {
                childs[i]+=cookies[index];
                helper(index+1);
                childs[i]-=cookies[index];
                if(childs[i]==0) break;
            }
        };
        helper(0);
        return result;
    }
};