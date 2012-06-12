//
//  main.cpp
//  SortBox
//
//  Created by Gun Li on 6/6/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>


/**************************快速排序*****************************/
void quickSort(int array[], int left, int right)
{
    if (left < right) {
        int i = left, j = right, x = array[left];
        //以下调整array，使x左边的数都比它小，右边的数都比它大
        while (i < j) {
            while (i < j && array[j] >= x) {//从右向左，右边都是比x大的
                j --;
            }
            if (i < j) {
                array[i++] = array[j];
            }
            
            while (i < j && array[i] < x) {
                i ++;
            }
            if (i < j) {
                array[j--] = array[i];
            }
        }
        array[i] = x;
        quickSort(array, left, i-1);
        quickSort(array, i+1, right);
    }
}

/**************************归并排序*****************************/
void mergeSort(int src[], int leftStart, int rightEnd, int temp[])
{//每次递归都只利用temp中下标leftStart～rightEnd这一段空间
    if (leftStart < rightEnd) {
        int start = leftStart, end = rightEnd;
        int leftEnd = (leftStart + rightEnd) / 2;
        int rightStart = leftEnd + 1;
        int tempStart = leftStart;
        mergeSort(src, leftStart, leftEnd, temp);
        mergeSort(src, rightStart, rightEnd, temp);
        while (leftStart <= leftEnd && rightStart <= rightEnd) { //逐个比较并排序src[leftStart~leftEnd] 和 src[rightStart~rightEnd],(这两段数组都是已经排序好的)
            if (src[leftStart] <= src[rightStart]) {
                temp[tempStart++] = src[leftStart++];
            } else {
                temp[tempStart++] = src[rightStart++];
            }
        }
        
        while (leftStart <= leftEnd) { //把左边数组中没比较完的全部依此放进temp
            temp[tempStart++] = src[leftStart++];
        }
        
        while (rightStart <= rightEnd) {  //把右边数组中没比较完的全部依此放进temp
            temp[tempStart++] = src[rightStart++];
        }
        
        //copy temp to src,把temp中排序好的放进下标对应的src中
        for (int i = start; i <= end; i ++) { //注意是 i <= end
            src[i] = temp[i];
        }
    }
}


/**************************选择排序*****************************/
void selectSort(int arr[], int size/*arr.size()*/)
{
    for (int i = 0; i < size; i++) {
        int min = arr[i];
        int minIndex = i;
        for (int j = i; j < size; j++) {
            if (arr[j] < min) {  //决定升降序
                minIndex = j;
                min = arr[j];
            }
        }
        //交换最小数
        int temp = arr[i];
        arr[i] = min;
        arr[minIndex] = temp;
    }
}

/**************************冒泡排序*****************************/
void bubbleSort(int arr[], int size)
{
    for (int i = size; i > 0; i --) {  //冒到顶部的数据不再计入排序的范围内
        for (int j = 0; j < i; j ++) {
            if (arr[j+1] < arr[j]) {  //决定升降序
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

/**************************插入排序*****************************/
void insertSort(int arr[], int size)
{
    for (int pos = 0; pos < size; pos++) {
        int insert = arr[pos];
        int comp = pos-1;
        while (comp >= 0 && arr[comp] > insert) {  //决定升降序
            arr[comp+1] = arr[comp];
            comp --;
        }
        arr[comp+1] = insert; //安置insert到正确的位置
    }
}

/**************************希尔排序*****************************/
void shell_order(int *a,int length)
{
    int increment,i,j,tem;
    for(increment = length/2; increment > 0; increment /=2)
    {
        for(i = increment; i < length; i++)
        {
            tem = a[i];
            for(j = i; j >= increment; j -= increment)
            {
                if(tem<a[j-increment])
                    a[j] = a[j-increment];
                else break;
            }
            a[j] = tem;
        }
    }
}

int main(int argc, const char * argv[])
{
    // insert code here...
    std::cout << "Hello, World!\n";
    int array[10] = {6, 7, 3, 8, 9, 1, 2, 5, 3, 4};
    
//    quickSort(array, 0, 9);       //快排
    
//    int temp[10] = {0};           //归并排序
//    mergeSort(array, 0, 9, temp); //归并排序
    
//    selectSort(array, 10);        //选择排序
    
//    bubbleSort(array, 10);        //冒泡排序
    
//    insertSort(array, 10);        //插入排序
    
    for (int i = 0; i < 10; i ++) {
        printf("%d",array[i]);
    }
    return 0;
}
