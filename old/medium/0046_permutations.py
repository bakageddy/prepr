from typing import List


def perms(x: List[int]) -> List[List[int]]:
    res: List[List[int]] = []
    def backtrack(acc: List[int], list: List[int]) -> None:
        if len(acc) == len(x):
            res.append(acc)
            return
        else:
            for i in range(len(list)):
                backtrack(acc + [list[i]], list[:i] + list[i + 1:])
    backtrack([], x)
    return res


if __name__ == '__main__':
    result = perms([1, 2, 3])
    print(result)
