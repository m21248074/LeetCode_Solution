class Solution {
public:
    bool isOperator(string token)
    {
        return token=="+"||token=="-"||token=="*"||token=="/";
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string token:tokens)
        {
            if(isOperator(token))
            {
                long b=s.top();
                s.pop();
                long a=s.top();
                s.pop();
                long result;
                switch(token[0])
                {
                    case '+':
                        result=a+b;
                        break;
                    case '-':
                        result=a-b;
                        break;
                    case '*':
                        result=a*b;
                        break;
                    case '/':
                        result=a/b;
                        break;
                }
                s.push(result);
            }
            else
                s.push(stoi(token));
        }
        return s.top();
    }
};