#!/usr/bin/python3
# @file: Insert_sort.py
# @brief: 排序算法之插入排序
# @date:  2019/5/15
# @author: luhao

'''
插入排序：
第一个数默认已排好序，从第二个数开始往前面的数插，不断比较小知道找到适合它的位置，最后一个数插完则所有元素已排好序；
仍然比较O(n^2)次，时间复杂度是O(N^2)；
插入排序是稳定排序，例如1,2,3,3,前三个数是有序的，最后的3自然不会再往前插入
'''

def insert_sort(a):
    n = len(a)
    for i in range(1,n):
        for j in range(i,0,-1):
            # 将第i个数和前i-1个已排好序的比较，找到适合它的位置并插入
            if a[j]<a[j-1]:
                a[j],a[j-1] = a[j-1], a[j]

a = [1,3,6,4,2,5]
insert_sort(a)
print (a)
