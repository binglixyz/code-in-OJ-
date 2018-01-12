#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
/*
最精彩的一步就是对两个有序数组搜索逆序对时，左小右大，
取出右边最小元素，搜索其在左数组中的位置，
一旦找到，记录左数组中比它大的第一个数的位置，取出右边第二小的元素，从记录的位置开始往右搜索，
重复上述步骤直到右边数组的最后一个数。
*/
class Solution {
public:
	int InversePairs(vector<int> data) {
		long long size = data.size();
		if (size <= 1) {
			return 0;
		}
		int result = mergeSort(data.begin(), data.end());
		return result;
	}
	int mergeSort(vector<int>::iterator startIter, vector<int>::iterator endIter) {
		long long size = endIter - startIter;
		if (startIter + 1 == endIter) {
			return 0;
		}
		vector<int>::iterator middleIter = startIter + size / 2;

		long long numPairs = mergeSort(startIter, middleIter) + mergeSort(middleIter, endIter);
		/* Noted: 
		search start by the element that bigger than the former element
		avoid searching from the head of the vector. 
		*/
		auto leftIter = startIter; 
		for (auto rightIter = middleIter; rightIter != endIter; rightIter++) {
			while(leftIter != middleIter) {
				if ((*rightIter) < (*leftIter)) {
					numPairs += middleIter - leftIter;
					break;
				}
				leftIter += 1;
			}
		}
		vector<int> mirrorVector(startIter, endIter);
		merge(mirrorVector.begin(), mirrorVector.begin()+size/2, mirrorVector.begin() + size / 2,mirrorVector.end(), startIter);
		return numPairs % 1000000007;
	}
};
