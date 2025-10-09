//(5)-Aim: Implement Mergesort and observe the execution time for various input sizes (Average, Worst and Best cases).

#include <stdio.h>
#include <stdlib.h>
void merge(int arr[],int l,int m,int h)
{
int i,j,k;
int n1 = m - l + 1;
int n2 = h - m;
int L[20],R[20];
for (i = 0; i < n1; i++)
L[i] = arr[l + i];
for (j = 0; j < n2; j++)
R[j] = arr[m + 1 + j];
i = 0;
j = 0;
k = l;
while (i < n1 && j < n2)
{
if (L[i] <= R[j]) 
{
arr[k] = L[i];
i++;
}
else 
{
arr[k] = R[j];
j++;
}
k++;
}
while (i < n1) 
{
arr[k] = L[i];
i++;
k++;
}
while (j < n2) 
{
arr[k] = R[j];
j++;
k++;
}
}
void mergeSort(int arr[], int l, int h)
{
if (l < h) 
{
int m = l + (h - l) / 2;
mergeSort(arr, l, m);
mergeSort(arr, m + 1, h);
merge(arr, l, m, h);
}
}
void printArray(int A[], int size)
{
int i;
for (i = 0; i < size; i++)
printf("%d ", A[i]);
printf("\n");
}
int main()
{
int arr[20],n,i;
clrscr();
printf("Enter the size of the array: \n");
scanf("%d",&n);
printf("Enter Elements to sort: \n");
for (i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
mergeSort(arr, 0, n-1);
printf("\n Merge Sorted array is: \n");
printArray(arr, n);
return 0;
}
