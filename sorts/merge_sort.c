#include "merge_sort.h"

void merge(int arr[], int arr2[], int size, int i, int left, int right, int leftm, int rightm) {
	for( ; left < leftm || right < rightm; i++) {
		if(left < leftm && right < rightm) {
			if(arr[left] < arr[right]) {
				arr2[i] = arr[left];
				left++;
			}else{
				arr2[i] = arr[right];
				right++;
			}
		}else if(left == leftm) {
			arr2[i] = arr[right];
			right++;
		}else if(right == rightm) {
			arr2[i] = arr[left];	
			left++;
		}
	}

	for(i = 0; i < size; i++) {
		arr[i] = arr2[i];
	}
}

void merge_sort(int arr[], int size) {
	int arr2[size];
	
	for(int i = 0; i < size; i++) {
		arr2[i] = arr[i];
	}

	for(int i = 2; i <= size; i *= 2) {
		for(int left = 0, right = i / 2; left <= size - i; left += i, right = left + i / 2) {
			merge(arr, arr2, size, left, left, right, left + i / 2, left + i);
		}

		if((size % i) != 0 && ((size / i) % 2) == 1) {
			merge(arr, arr2, size, (size / i) * i - i, (size / i) * i - i, (size / i) * i, (size / i) * i, size);
		}
	}
}
