#include <stdio.h>
#include <stdlib.h>
/**4.1 Write out the code for the earlier sum function.
   4.2 Write a recursive function to count the number of items in a list.
   4.3 Find the maximum number in a list.
   4.4 binary search {1,2,3,5,6,9,17,20,77} //17
**/
int sum(int arr[],int len);
int count(int arr[], int len);
int Find_max(int arr[], int len, int max);
int binary_search(int arr[],int first ,int last,int Snumber);
int main()
{
    int ret=0;
    int arr[]={1,2,4,5,6,9,17,20,77};
    int len=sizeof(arr)/sizeof(arr[0]);

    ret= sum(arr,len);
    printf("sum=%i \n",ret);

    ret= count(arr,len);
    printf("count=%i \n",ret);

    ret= Find_max(arr,len,arr[len]);
    printf("max=%i \n",ret);

    ret= binary_search(arr,0,len,100);

    if((ret+1)) printf("index of number =%i\n",ret+1);

    return 0;
}

int sum(int arr[],int len)
{
    if(len==0)
    {
        return 0;
    }
    else
    {
        return arr[len - 1] + sum(arr, len - 1);
    }
}
int count(int arr[], int len)
{
    if (len == 0)
    {
        return 0;
    }
    else
    {
        return 1 + count(arr, len - 1);
    }
}
int Find_max(int arr[], int len, int max)
{
    if (len == 0)
    {
        return max;
    }
    if (arr[len - 1] > max)
    {
        max = arr[len - 1];
    }
    return Find_max(arr, len - 1, max);
}
int binary_search(int arr[],int first ,int last,int Snumber)
{
    if (first > last) {
        return -1; // Element is not found
    }

    int midpoint= (first+last)/2 ;

    if(Snumber==arr[midpoint])
    {
        return midpoint;
    }
    else if(Snumber>arr[midpoint])
    {
        return binary_search(arr,midpoint+1 ,last,Snumber);
    }
    else if(Snumber>arr[midpoint])
    {
        return binary_search(arr,first,midpoint-1,Snumber);
    }

}
