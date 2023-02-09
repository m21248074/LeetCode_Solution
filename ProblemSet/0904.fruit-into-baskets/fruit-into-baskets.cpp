class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int result=0;
        int start=0;
        int n=fruits.size();
        unordered_map<int,int> um;
        for(int i=0;i<n;i++)
        {
            um[fruits[i]]++;
            while(um.size()>2)
            {
                um[fruits[start]]--;
                if(!um[fruits[start]])
                    um.erase(fruits[start]);
                start++;
            }
            result=max(result,i-start+1);
        }
        return result;
    }
};