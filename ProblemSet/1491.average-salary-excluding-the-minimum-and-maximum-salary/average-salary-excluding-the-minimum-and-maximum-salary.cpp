class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(),salary.end());
        double result=0;
        for(int i=1;i<salary.size()-1;i++)
            result+=salary[i];
        return result/double(salary.size()-2);
    }
};