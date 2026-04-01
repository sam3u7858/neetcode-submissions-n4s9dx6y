
class ListNode:
    def __init__(self, key: int = -1, val: int = -1, next=None):
        self.key = key
        self.val = val
        self.next = None

class MyHashMap:

    def __init__(self):
        self.size = 1009
        self.map = [ListNode() for _ in range(self.size)]
    
    def hash(self, key: int) -> int:
        return key % self.size

    def put(self, key: int, value: int) -> None:
        cur = self.map[self.hash(key)];
        while cur.next:
            if cur.next.key == key:
                cur.next.val = value
                return
            cur = cur.next
        # If not found in the bucket
        cur.next = ListNode(key, value)
        

    def get(self, key: int) -> int:
        cur = self.map[self.hash(key)];
        while cur.next:
            if cur.next.key == key:
                return cur.next.val
            cur = cur.next
        # If not found in the bucket
        return -1
        

    def remove(self, key: int) -> None:
        cur = self.map[self.hash(key)];
        while cur.next:
            if cur.next.key == key:
                cur.next = cur.next.next
                return
            cur = cur.next
       
        


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)