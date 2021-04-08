#include<iostream>
using namespace std;

int Parent(int i){return i/2;}

int Left(int i){return 2*i+1;}

int Right(int i){return 2*i+2;}

void SwapFunc(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void MaxHeapify(int a[],int n,int i)
{
    int l=Left(i);
    int r=Right(i);
    int largest;

    if(l<=n && a[l]>a[i]){largest=l;}
    else largest=i;

    if(r<=n && a[r]>a[largest]){largest=r;}

    if(largest!=i)
    {
        SwapFunc(&a[i],&a[largest]);
        MaxHeapify(a,n,largest);
    }
}
void BuildMaxHeap(int a[],int n)
{
    for(int i=(n/2-1);i>=0;i--)
    {
        MaxHeapify(a,n,i);
    }
}

void HeapSort(int a[],int n)
{
    int HeapSize=n;
    for(int i=n-1;i>=1;i--)
    {
        SwapFunc(&a[0],&a[i]);
        HeapSize = HeapSize-1;
        MaxHeapify(a,HeapSize,0);
    }
}
int main()
{
    int n;
    cout<<"Enter array size:";
    cin>>n;

    int a[n];
    cout<<"Enter Array:";
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the a["<<i<<"]th element:";
        cin>>a[i];
    }

    BuildMaxHeap(a,n);
    HeapSort(a,n);

    for(int i=0;i<n;i++)
    {
        cout<<"\n"<<"a["<<i<<"]th element:"<<a[i];
    }
}

