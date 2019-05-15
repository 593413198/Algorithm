#!/usr/bin/python3
# @file: Select_sort.py
# @brief: 排序算法之选择排序
# @date:  2019/5/15
# @author: luhao

'''
选择排序：
每次循环找出第i小的元素，放到下标为i的位置上，这样n-1次循环结束，所有数都排好序；
仍然是比较n^2次，时间复杂度是O(n^2)；
如3 2 3 1，第一次循环结束开头3和末尾1交换位置，这就破坏了两个3的相对位置，所以选择排序是不稳定的。根本原因在于涉及相隔较远的元素交换位置
'''

def select_sort(a):
    n = len(a)
    for i in range(n-1):
        MIN = a[i]
        MIN_i = i
        for  j in range(i,n):
            # 内循环把第i小的元素放在下标为i的位置上
            if a[j] < MIN:
                MIN, MIN_i = a[j], j
        a[MIN_i],a[i] = a[i], a[MIN_i]


a = [1,5,3,2,8,5]
select_sort(a)
print (a)
