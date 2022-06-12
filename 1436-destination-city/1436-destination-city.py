class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        
        myset = set()
        
        out = None
        
        for path in paths:
            if path[0] not in myset:
                myset.add(path[0]);
        
        for path in paths:
            if path[1] not in myset:
                out = path[1]
        
        return out
        