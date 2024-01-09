class FoodRatings {
private:
    struct cmp{
        bool operator()(pair<int,string> a,pair<int,string> b)
        {
            if(a.first==b.first)
                return a.second>b.second;
            return a.first<b.first;
        }
    };
    unordered_map<string,pair<string,int>> um;
    unordered_map<string,priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>> um1;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0;i<n;i++)
        {
            um[foods[i]]=make_pair(cuisines[i],ratings[i]);
            um1[cuisines[i]].push(make_pair(ratings[i],foods[i]));
        }
    }
    void changeRating(string food, int newRating) {
        um[food].second=newRating;
        um1[um[food].first].push(make_pair(newRating,food));
    }
    string highestRated(string cuisine) {
        auto food=um1[cuisine].top();
        while(um[food.second].second!=food.first)
        {
            um1[cuisine].pop();
            food=um1[cuisine].top();
        }
        return food.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */