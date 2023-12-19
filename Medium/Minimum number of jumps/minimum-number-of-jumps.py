#User function Template for python3
class Solution:
    def minJumps(self, arr, n):
        #code here
       if n == 1:
           return 0
       l, r = 0, 0
       count = 0
       while True:
           farthest = 0
           for i in range(l, r + 1):
               farthest = max(farthest, i + arr[i])
           l = r + 1
           r = farthest
           if l>r:
               return -1
           count += 1
           if r >= n - 1:
               return count
#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		n = int(input())
		Arr = [int(x) for x in input().split()]
		ob = Solution()
		ans = ob.minJumps(Arr,n)
		print(ans)
# } Driver Code Ends