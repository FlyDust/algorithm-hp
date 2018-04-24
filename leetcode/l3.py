class Solution:
	def lengthOfLongestSubstring(self, s):
		"""
		:type s: str
		:rtype: int
		"""
		dic = {}
		start = 0
		max_len = 0
		for i, value in enumerate(s):
			if value in dic and start <= dic[value]:
				start = dic[value] + 1
				dic[value] = i
				print(i)
				print(start)
			else:
				dic[value] = i
				max_len = max(max_len, i - start + 1)
		return max_len
		
if __name__ == '__main__':
	s = input('input a string: ')
	sol = Solution()
	print('The max sub-lenth:', sol.lengthOfLongestSubstring(s))
