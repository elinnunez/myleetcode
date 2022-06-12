class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        
        hmap = {}
        
        out = None
        
        for first,second in paths:
            print(f"index 0: {first}, index 1: {second}")
            if first not in hmap:
                hmap[first] = first;
        
        for first,second in paths:
            if second not in hmap:
                out = second
        
        return out
        