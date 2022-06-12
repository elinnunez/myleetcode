class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        
        myset = set()
        
        out = None
        
        for first,second in paths:
            print(f"index 0: {first}, index 1: {second}")
            if first not in myset:
                myset.add(first);
        
        for first,second in paths:
            if second not in myset:
                out = second
        
        return out
        