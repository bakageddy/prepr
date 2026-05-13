from typing import *

def grid_traveller(row: int, col: int, dp: dict[tuple[int, int], int] = {}) -> int:
    if (row, col) in dp:
        return dp[(row, col)]
    if (row == 0 or col == 0):
        return 0
    if (row == 1 and col == 1):
        return 1
    dp[(row, col)] = grid_traveller(row - 1, col, dp)
    dp[(row, col)] += grid_traveller(row, col - 1, dp)
    return dp[(row, col)]


print(grid_traveller(1, 1))
print(grid_traveller(3, 3))
