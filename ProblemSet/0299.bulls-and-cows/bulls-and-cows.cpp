class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> m;
        int a=0,b=0;
        for(int i=0;i<secret.length();i++)
        {
            if(secret.at(i)==guess.at(i))
                a++;
            else
                m[secret.at(i)]++;
        }
        for(int i=0;i<guess.length();i++)
        {
            if(secret.at(i)!=guess.at(i))
            {
                if(m[guess.at(i)])
                {
                    b++;
                    m[guess.at(i)]--;
                }
            }
        }
        return to_string(a)+'A'+to_string(b)+'B';
    }
};