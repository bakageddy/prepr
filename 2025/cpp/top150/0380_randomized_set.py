from random import choice


class RandomizedSet:
    def __init__(self):
        self.bucket: list[int] = list()
        self.map: dict[int,int] = dict()
        
    def insert(self, val: int) -> bool:
        if (self.map.get(val, -1) == -1):
            self.bucket.append(val)
            self.map[val] = len(self.bucket) - 1
            return True
        return False

    def remove(self, val: int) -> bool:
        if (self.map.get(val, -1) == -1):
            return False
        else:
            _ = self.map.pop(val)
            self.bucket.remove(val)
            return True
        
    def getRandom(self) -> int:
        return choice(self.bucket)
        

