class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> basket;
        int left = 0, maxCnt = 0;
        
        for(int right=0;right<fruits.size();right++) {
            // Add current fruit into basket
            basket[fruits[right]]++;

            // If more than 2 fruit types
            while(basket.size()>2) {
                basket[fruits[left]]--;

                if(basket[fruits[left]] == 0){
                    basket.erase(fruits[left]);
                }
                left++;
            }
            //Update Answer
            maxCnt = max(maxCnt, right-left+1);
        }
        return maxCnt;
    }
};