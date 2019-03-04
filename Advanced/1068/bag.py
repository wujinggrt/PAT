#!/usr/bin/env python3

value = [1, 6, 18, 22, 28]
weight = [1, 2, 5, 6, 7]
# 背包大小
capacity = 11
num_item = len(value)

def bag_solution_naive():
    # bag_table大小比value和weight分别多一行一列，为了方便计算第一个的时候，value为0
    bag_table = [[0 for j in range(capacity + 1)] for i in range(num_item + 1)]

    for i in range(1, num_item + 1):
            for w in range(1, capacity + 1):
                if weight[i - 1] > w:
                    # 不拿, 避免访问下标的index invalid
                    bag_table[i][w] = bag_table[i - 1][w] 
                else:
                    # m[i - 1][w], w表示当前列
                    bag_table[i][w] = max(bag_table[i - 1][w], value[i - 1] + bag_table[i - 1][w - weight[i - 1]])

    for row in bag_table:
        print(row)

def bag_basic():
    F = [[0 for j in range(capacity + 1)] for i in range(num_item + 1)]

    for i in range(1, num_item):
        for v in range()