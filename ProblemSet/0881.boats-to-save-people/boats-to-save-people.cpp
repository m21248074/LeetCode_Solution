class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int result=0;
        int n=people.size();
        int left=0,right=n-1;
        sort(people.begin(),people.end());
        while(left<=right)
        {
            if(people[left]+people[right]<=limit)
                left++;
            right--;
            result++;
        }
        return result;
    }
};