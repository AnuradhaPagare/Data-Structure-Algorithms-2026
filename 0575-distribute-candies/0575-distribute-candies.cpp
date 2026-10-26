class Solution {
public:
    int distributeCandies(std::vector<int>& candyType) {
        unordered_set<int> unique_candies(candyType.begin(), candyType.end());
        int max_allowed = candyType.size() / 2;
        return std::min((int)unique_candies.size(), max_allowed);
    }
};