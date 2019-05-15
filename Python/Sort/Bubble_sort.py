#!/usr/bin/python3
# @file: Bubble_sort.py
# @brief: 排序算法之冒泡排序
# @date:  2019/5/15
# @author: luhao

'''
冒泡排序：
从头到尾，不断将相邻两数比较，将较大的往后移，这样每次第i次循环结束，第i大的数就保证移到了最后末尾；
每相邻两个数都要比较，共比较n^2次，所以时间复杂度是O(n^2);
若相邻元素大小一样，并不会交换位置，所以是稳定排序
'''

def bubble_sort(a):
    n = len(a)
    for i in range(n-1):
        for j in range(n-i-1):
            # 内循环把前n-i个数中的最大值移到第n-i位
            if (a[j] > a[j+1]):
                a[j], a[j+1] = a[j+1], a[j]

a = [3,2,5,1,7,5]
bubble_sort(a)
print (a)

