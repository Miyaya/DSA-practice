class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        q=[]
        people.sort(key=lambda x:(-x[0], x[1])) # height desc, and ppl infront asc
        for p in people:
            q.insert(p[1], p)
                
        return q
                    
