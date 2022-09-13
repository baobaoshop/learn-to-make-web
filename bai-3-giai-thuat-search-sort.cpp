#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void nhapMang(int a[], int &n);
void xuatMang(int a[], int n);
int LinearSearch (int a[], int n, int x);
int BinarySearch(int a[], int n, int x);
void sapXepTangInterchangeSort(int a[], int n);
void sapXepTangSelectionSort(int a[], int n);
void sapXepTangQuickSort(int a[], int left, int right);
void hoanvi(int &a, int &b);

int main()
{
    int a[100], n;
    nhapMang(a,n);
    xuatMang(a,n);
    int x;
    printf("Nhap x: ");
    scanf("%d", &x);
    printf("Vi tri x: %d", LinearSearch(a,n,x));
    // sapXepTangInterchangeSort(a,n);
    // sapXepTangSelectionSort(a,n);
    sapXepTangQuickSort(a,0,n-1);
    xuatMang(a,n);
    printf("Vi tri x: %d", BinarySearch(a,n,x));
}

void nhapMang(int a[], int &n)
{
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        a[i] = rand()%100;
    }
    printf("Xong");
}

void xuatMang(int a[], int n)
{
    printf("\n***** XUAT MANG *****\n");
    for (int i = 0; i < n; i++)
    {
        printf("%5d", a[i]);
    }
    printf("\n");
}

int LinearSearch (int a[], int n, int x)
{
    for(int i = 0; i < n; i++) {
        if(a[i] == x)
        return i;
    }
    return -1;
}

int BinarySearch(int a[], int n, int x)
{
    int left = 0, right = n - 1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(a[mid] == x)
        return mid;
        else if(a[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

void sapXepTangInterchangeSort(int a[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(a[i]>a[j]) hoanvi(a[i], a[j]);
        }
        
    }
    
}

void sapXepTangSelectionSort(int a[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int imin=i;
        for (int j = i+1; j < n; j++)
        {
            if(a[imin]>a[j]) imin=j;
        }
        hoanvi(a[imin], a[i]);
    }
    
}

void sapXepTangQuickSort(int a[], int left, int right)
{
    if(left >= right) return;
    int i = left, j = right, mid = (left+right)/2;
    float x = a[mid];
    do
    {
        while (a[i]<x)
        {
            i++;
        }
        while (a[j]>x)
        {
            j--;
        }
        if(i<=j)
        {
            hoanvi(a[i], a[j]);
            i++;
            j--;
        }
    } while (i<j);
    sapXepTangQuickSort(a,left,j);
    sapXepTangQuickSort(a,i,right);
}

void hoanvi(int &a, int &b)
{
    int c=a;
    a=b;
    b=c;
}