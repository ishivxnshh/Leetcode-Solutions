#include <bits/stdc++.h>
using namespace std;

class FoodRatings
{
public:
    unordered_map<string, set<pair<int, string>>> cuisineRatings; // cuisine -> {{-rating, food},...}
    unordered_map<string, int> foodRating; // food -> rating
    unordered_map<string, string> foodToCuisine; // food -> cuisine

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings)
    {
        for (int i = 0; i < foods.size(); i++)
        {
            cuisineRatings[cuisines[i]].insert({-ratings[i], foods[i]});
            foodRating[foods[i]] = ratings[i];
            foodToCuisine[foods[i]] = cuisines[i];
        }
    }
    
    void changeRating(string food, int newRating)
    {
        string cuisine = foodToCuisine[food];
        int oldRating = foodRating[food];

        cuisineRatings[cuisine].erase({-oldRating, food});
        cuisineRatings[cuisine].insert({-newRating, food});

        foodRating[food] = newRating;
    }
    
    string highestRated(string cuisine)
    {
        return (*cuisineRatings[cuisine].begin()).second;
    }
};

int main()
{
    vector<string> foods = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
    vector<string> cuisines = {"korean", "japanese", "japanese", "greek", "japanese", "korean"};
    vector<int> ratings = {9, 12, 8, 15, 14, 7};

    FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);

    cout << obj->highestRated("korean") << endl;   // Expected: kimchi
    cout << obj->highestRated("japanese") << endl; // Expected: ramen

    obj->changeRating("sushi", 16);

    cout << obj->highestRated("japanese") << endl; // Expected: sushi

    obj->changeRating("ramen", 16);

    cout << obj->highestRated("japanese") << endl; // Expected: ramen (lexicographically smaller)

    return 0;
}