class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        unordered_map<int, int> basket;
        
        int leftFruitIdx = 0;
        
        int maxCount = 0;
        
        int count = 0;
        
        for(int i = 0; i < fruits.size(); i++) {
            int curFruit = fruits[i];
            basket[curFruit]++;
            count++;
            
            while(basket.size() > 2) {
                int leftFruit = fruits[leftFruitIdx];
                
                basket[leftFruit]--;
                count--;
                
                if(basket[leftFruit] == 0) {
                    basket.erase(leftFruit);
                }
                
                leftFruitIdx++;
            }
            
            maxCount = max(maxCount, count);
            
        }
        
        return maxCount;
        
    }
};