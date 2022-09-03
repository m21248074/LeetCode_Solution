class MyQueue
{
    private:
        list<int> data;
    public:
        void push(int n)
        {
            while(!data.empty()&&data.back()<n)
                data.pop_back();
            data.push_back(n);
        }
        int max()
        {
            return *data.begin();
        }
        void pop(int n)
        {
            if(n==*data.begin())
                data.pop_front();
        }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        MyQueue mq;
        for(int i=0;i<nums.size();i++)
        {
            mq.push(nums[i]);
            if(i>=k-1)
            {
                result.push_back(mq.max());
                mq.pop(nums[i-k+1]);
            }
        }
        return result;
    }
};