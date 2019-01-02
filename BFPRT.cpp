/*
 * @Author: fzy
 * @Date: 2019-01-02 18:36:56
 * @LastEditors: Zhenying
 * @LastEditTime: 2019-01-02 19:12:24
 * @Description: BFPRT
 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int K) {
        int size = nums.size();
        int nk = size - K + 1;
        int res = getMinKthByBFPRT(nums, nk);
        return res;
    }

    int getMinKthByBFPRT(vector<int>& nums, int K) {
        vector<int> copyArr = copyArray(nums);
        return select(copyArr, 0, copyArr.size() - 1, K - 1);
    }

    vector<int> copyArray(vector<int>& nums) {
        vector<int> copyArr;
        for (int i = 0; i < nums.size(); ++i) {
            copyArr.push_back(nums[i]);
        }
        return copyArr;
    }

    int select(vector<int>& arr, int begin, int end, int i) {
        if (begin == end) {
            return arr[begin];
        }
        int pivot = medianOfMedians(arr, begin, end);
        vector<int> pivotRange = partition(arr, begin, end, pivot);
        if (i >= pivotRange[0] && i <= pivotRange[1]) {
            return arr[i];
        } else if (i < pivotRange[0]) {
            return select(arr, begin, pivotRange[0] - 1, i);
        } else {
            return select(arr, pivotRange[1] + 1, end, i);
        }
    }

    int medianOfMedians(vector<int>& arr, int begin, int end) {
        int num = end - begin + 1;
        int offset = num % 5 == 0 ? 0 : 1;
        vector<int> mArr(num / 5 + offset);
        for (int i = 0; i < mArr.size(); ++i) {
            int beginI = begin + i * 5;
            int endI = beginI + 4;
            mArr[i] = getMedian(arr, beginI, min(end, endI));
        }
        return select(mArr, 0, mArr.size() - 1, mArr.size() / 2);
    }

    vector<int> partition(vector<int>& arr, int begin, int end, int pivotValue) {
        int small = begin - 1;
        int cur = begin;
        int big = end + 1;
        while (cur != big) {
            if (arr[cur] < pivotValue) {
                swap(arr, ++small, cur++);
            } else if (arr[cur] > pivotValue) {
                swap(arr, cur, --big);
            } else {
                cur++;
            }
        }
        vector<int> range(2);
        range[0] = small + 1;
        range[1] = big - 1;
        return range;
    }

    int getMedian(vector<int>& arr, int begin, int end) {
        insertionSort(arr, begin, end);
        int sum = end + begin;
        int mid = (sum / 2) + (sum % 2);
        return arr[mid];
    }

    void insertionSort(vector<int>& arr, int begin, int end) {
        for (int i = begin + 1; i != end + 1; i++) {
			for (int j = i; j != begin; j--) {
				if (arr[j - 1] > arr[j]) {
					swap(arr, j - 1, j);
				} else {
					break;
				}
			}
		}
    }

    void swap(vector<int>& arr, int index1, int index2) {
		int tmp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = tmp;
	}

};

int main() {
    Solution s;
    int k = 2;
    vector<int> input;
    input.push_back(3);
    input.push_back(2);
    input.push_back(1);
    input.push_back(5);
    input.push_back(6);
    input.push_back(4);
    cout << s.findKthLargest(input, k) << endl;
    return 0;
}
