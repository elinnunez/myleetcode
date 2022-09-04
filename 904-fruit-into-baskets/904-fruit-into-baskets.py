class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        hashmap = {}
        
        winStart = 0
        
        maxFruit = 0
        
        for winEnd in range(len(fruits)):
            if fruits[winEnd] not in hashmap:
                hashmap[fruits[winEnd]] = 0
                
            hashmap[fruits[winEnd]]+= 1
            
            while len(hashmap) > 2:
                hashmap[fruits[winStart]]-= 1
                if hashmap[fruits[winStart]] == 0:
                    del hashmap[fruits[winStart]]
                winStart+= 1
            
            maxFruit = max(maxFruit, winEnd - winStart + 1)
        
        return maxFruit

# Time Complexity: O(n)
# Space Complexity: O(1) since hashmap will always at most be size k+1 no matter how large the input is