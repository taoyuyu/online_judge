#include <iostream>
using namespace std;

void swap(int array[], int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

//堆排序
void heap_adujust(int array[], int i, int end) {
    int child;
    while (2*i+1 <= end) {
        child = i*2+1;
        if (i*2+2 <= end && array[i*2+1] < array[i*2+2]) {
            child ++;
        }
        if (array[i] < array[child]) {
            swap(array,i,child);
            i = child;
        } else {
            break;
        }
    }
    return;
}

void heap_sort(int array[], int size) {
    int start = size/2 -1;
    while(start >= 0) {
        heap_adujust(array, start, size-1);
        start --;
    }

    int end = size - 1;
    while (end > 0) {
        swap(array, 0, end);
        heap_adujust(array, 0, end-1);
        end --;
    }
}

//希尔排序
void shell_sort(int array[], int length) {
    for (int gap = length/2; gap > 0; gap /=2) {
        for (int i = gap; i < length; ++i) {
            for (int j = i-gap; j >=0; j -= gap) {
                if (array[j] > array[j+gap]) {
                    swap(array, j, j+gap);
                }
            }
        }
    }
}

//归并排序
void merge_sort(int array[], int arrTemp[], int start, int mid, int end) {
    if (start >= end) return;

    int i = start, j = mid+1, k = start;
    while(i <= mid && j <= end) {
        if (array[i] < array[j]) {
            arrTemp[k++] = array[i++];
        } else {
            arrTemp[k++] = array[j++];
        }
    }
    while(i<=mid) arrTemp[k++] = array[i++];
    while(j<=end) arrTemp[k++] = array[j++];
    
    for (int index=start; index<=end; ++index) {
        array[index] = arrTemp[index];
    }
    return;
}
void merge(int array[], int arrTemp[], int start, int end) {
    if (start >= end) return;
    int mid = (start + end) / 2;
    merge(array, arrTemp, start, mid);
    merge(array, arrTemp, mid+1, end);
    merge_sort(array, arrTemp, start, mid, end);
    return;
}

//快速排序
void quick_sort(int array[], int start, int end) {
    if (start >= end) return;
    int temp = array[start];
    int i = start, j = end;
    while(i < j) {
        while(i<j && array[j]>temp) j--;
        array[i] = array[j];
        while(i<j && array[i]<temp) i++;
        array[j] = array[i];
    }
    array[i] = temp;
    quick_sort(array, start, i-1);
    quick_sort(array, i+1, end);
    return;
}

//插入排序
void insert_sort(int array[], int end) {
    for (int i=0; i<=end; ++i) {
        for (int j=i; j<end; --j) {
            if (array[j] > array[j+1]) {
                swap(array, j, j+1);
            } else {
                break;
            }
        }
    }
    return;
}

//选择排序
void select_sort(int array[], int end) {
    int start = 0;
    int min, tag;
    while (start < end) {
        min = array[start];
        tag = start;
        for (int i=start+1; i<=end; ++i) {
            if (array[i] < min) {
                tag = i;
                min = array[tag];
            }
        }
        swap(array, start, tag);
        start ++;
    }
}

//冒泡排序
void bubble_sort(int array[], int length) {
    for (int i=0; i<length; ++i) {
        for (int j=0; j< length-1-i; ++j) {
            if (array[j] > array[j+1]) {
                swap(array, j, j+1);
            }
        }
    }
    return;
}

int main() {
    int array[10] = {5,1,3,9,0,2,8,6,7,4};
    //heap_sort(array, 10);
    //shell_sort(array,10);
    //int arrTemp[10];
    //merge(array, arrTemp, 0, 9);
    //quick_sort(array,0,9);
    //insert_sort(array,9);
    //select_sort(array,9);
    bubble_sort(array,10);
    for (int i = 0; i < 10; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}
