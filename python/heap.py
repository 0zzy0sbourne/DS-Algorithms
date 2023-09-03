import sys
import os 

def heapify(i):
    pass 

def buildHeap(arr): 
    nodeAmount = len(arr)
    indexOfLastNotLeafNode = nodeAmount // 2 - 1

    """
        Perform reverse level order traversal 
        from last non-leaf node and heapify 
    """

    """
        Create a for loop that iterates the non-leaf nodes in decreasing order 
        starting from the last non-leaf nodes (which has an index of indexofLastNotLeafNode)
    """
    for i in range(indexOfLastNotLeafNode, -1, -1):
        heapify(arr, nodeAmount, i)


