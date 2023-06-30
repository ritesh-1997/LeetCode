from sys import stdin,setrecursionlimit
setrecursionlimit(10**7)
import heapq
# Same as huffman encoding
def connectRopes( arr, n) :

	# Your code goes here
	heapq.heapify(arr)
	res = 0
	while len(arr)>1:
		first = heapq.heappop(arr)
		second = heapq.heappop(arr)
		res +=(first+second)
		heapq.heappush(arr,first+second)
	 
	return res