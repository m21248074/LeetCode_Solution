class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        for(int i=1;i<=9;i++)
        {
            int next=i,num=i;
            while(num<=high&&next<10)
            {
                if(num>=low)
                    result.push_back(num);
                next++;
                num=num*10+next;
            }
        }
        sort(result.begin(),result.end());
        return result;
    }
};