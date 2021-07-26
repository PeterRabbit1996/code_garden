class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
    	index_1 = 0
    	index_2 = 0
    	left = 0
    	right = 0
    	for i in range((len(nums1) + len(nums2)) // 2 + 1):
    		if index_1 < len(nums1) and index_2 < len(nums2):
    			if nums1[index_1] < nums2[index_2]: 
    				left = right
    				right = nums1[index_1]
    				index_1 += 1
    			else:
    				left = right
    				right = nums2[index_2]
    				index_2 += 1
    		elif index_1 < len(nums1):
    			left = right
    			right = nums1[index_1]
    			index_1 += 1
    		else:
    			left = right
    			right = nums2[index_2]
    			index_2 += 1

    	if (len(nums1) + len(nums2)) % 2 == 0:
    		return (left + right) / 2
    	else:
    		return right

if __name__ == '__main__':
	s = Solution()
	print(s.findMedianSortedArrays([1, 1], [1, 2]))