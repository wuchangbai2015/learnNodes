#include <stdio.h>
#define MAXSIZE 7
void ISort(int *k,int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        if(k[i]<k[i-1])
        {
            temp=k[i];
            for(j=i-1;k[j]>temp;j--)
            {
                k[j+1]=k[j];
            }
            k[j+1]=temp;
        }
    }
}
void InsertSort(int *k,int low,int high)
{
    ISort(k+low,(high-low+1));
}
void swap(int *k,int low,int high)
{
    int temp;
    temp=k[low];
    k[low]=k[high];
    k[high]=temp;
}
int Partition(int *k,int low,int high)
{
    int point;
    int mid=low+(high-low)/2;
    if(k[low]>k[high])
    {
        swap(k,low,high);
    }
    if(k[mid]>k[high])
    {
        swap(k,mid,high);
    }
    if(k[mid]>k[low])
    {
        swap(k,mid,low);
    }
    point=k[low];
    while(low<high)
    {
        while(low<high &&k[high]>=point)
        {
            high--;
        }
        //swap(k,low,high);
        k[low]=k[high];
        while(low<high &&k[low]<=point)
        {
            low++;
        }
        //swap(k,low,high);
        k[high]=k[low];
    }
    k[low]=point;
    return low;
}
void Qsort(int *k,int low,int high)
{
    int point;
    if(high-low>MAXSIZE)
    {
        if(low<high)
        {
        point=Partition(k,low,high);
        Qsort(k,low,point-1);
        Qsort(k,point+1,high);
        }
    }
    else
    {
        InsertSort(k,low,high);
    }

}
void QuickSort(int *k,int n)
{
    Qsort(k,0,n-1);
}
int main()
{
    int i,a[10]={5,2,6,0,3,9,1,7,4,8};
    QuickSort(a,10);
    printf("�����Ľ���ǣ�");
    for(i=0;i<10;i++)
    {
        printf("%d  ",a[i]);
    }
    printf("\n\n");
    return 0;
}
