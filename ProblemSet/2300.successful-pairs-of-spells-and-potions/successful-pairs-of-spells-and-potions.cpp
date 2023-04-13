class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        int m=potions.size();
        sort(potions.begin(),potions.end());
        vector<int> result;
        for(int i=0;i<n;i++)
        {
            int cnt=-1;
            int left=0,right=m-1;
            while(left<=right)
            {
                int mid=(left+right)/2;
                if((long long)spells[i]*(long long)potions[mid]>=success)
                {
                    right=mid-1;
                    cnt=mid;
                }
                else // < success
                    left=mid+1;
            }
            /*
            for(int j=0;j<m;j++)
            {
                if((long long)spells[i]*(long long)potions[j]>=success)
                    cnt++;
                else
                    break;
            }
            */
            result.push_back(cnt==-1?0:m-cnt);
        }
        return result;
    }
};