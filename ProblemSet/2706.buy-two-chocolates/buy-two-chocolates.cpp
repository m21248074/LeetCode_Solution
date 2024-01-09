class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        int chocoPrices=prices[0]+prices[1];
        return (chocoPrices>money)?money:money-chocoPrices;
    }
};