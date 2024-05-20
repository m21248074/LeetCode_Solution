class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int ones=0;
        int zeros=0;
        for(int i:students)
        {
            if(i)
                ones++;
            else
                zeros++;
        }
        for(int i:sandwiches)
        {
            if(i)
            {
                if(!ones)
                    return zeros;
                ones--;
            }
            else
            {
                if(!zeros)
                    return ones;
                zeros--;
            }
        }
        return ones+zeros;
    }
};