class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        for(int i=1;i<=n;i++)
        {
            string temp="";
            if(!(i%3))
                temp+="Fizz";
            if(!(i%5))
                temp+="Buzz";
            else if(temp=="")
                temp=to_string(i);
            result.push_back(temp);
        }
        return result;
    }
};