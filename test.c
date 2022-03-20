#include <stdio.h>
#include <limits.h>
/* 冒泡排序 */
void bubbleSort(int *arr, int length){
    int i ,j;
    for(i = length - 1 ; i >=0 ; i--){
        for(j = 0;j < i ; j++){
            if(arr[j+1] < arr[j]){
                int tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    //打印一下结果
    for(i = 0 ; i < length ; i ++){
        printf("Array's %d element is %d \n", i, arr[i]);
    }
}
/* 插入排序 */
void insertSort(int* arr, int length){
    int i,j;
    for(i= 1 ; i< length; i++){
        for(j = i;j >= 1 ; j--){
            if(arr[j]>= arr[j-1]){
                break;
            }else{
                sweep_element(arr,j, j-1);
            }
        }
    }
    for (i = 0; i < length; i++)
    {
        printf("Array's %d element is %d \n", i, arr[i]);
    }
}
/* 选择排序 : 每一次遍历选择一个最大的*/
void selectSort(int* arr, int length){  
    int i,j;
    int min;
    int min_flag;
    for(i = 0 ; i < length ; i++){
        min_flag = i;
        min=arr[i];
        for(j = i ; j < length ; j++){
            if(arr[j] < min){
                min = arr[j];
                min_flag = j;
            }
        }
        sweep_element(arr, i, min_flag);
    }
    for (i = 0; i < length; i++)
    {
        printf("Array's %d element is %d \n", i, arr[i]);
    }
}
/* 快速排序 */
void quickSort(int* arr, int length){

}

void sweep_element(int *arr, int i, int j) {
    if(i == j) {
        return ;
    }
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

int main(){
    int test[] = {11,2,54,34,454,78,0};
    int length  = sizeof(test) / sizeof(test[0]);
    selectSort(test, length);
    return 0;
    
}