#include<iostream>
using namespace std;

void display(int a[],int n)
{
    cout<<"\t\ta[i]:";
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void Merge(int a[],int low,int mid,int high){
    cout<<"\t\tlow:"<<low<<" mid:"<<mid<<" high:"<<high<<endl;
    int *tmpa;
    int i=low;
    int j=mid+1,k=0;
    tmpa=(int *)malloc(sizeof(int)*(high-low+1));//存放有序序列
    while (i<=mid&&j<=high)
    {
        if(a[i]<=a[j]){
            tmpa[k]=a[i];
            i++;
            k++;
        }else
        {
            tmpa[k]=a[j];
            j++;
            k++;
        }
    }
    while (j<=high)
    {
        tmpa[k]=a[j];
        j++;
        k++;
    }
    while (i<=mid)
    {
        tmpa[k]=a[i];
        i++;
        k++;
    }
    for (k=0,i=low;i<=high;k++,i++)
    {
        a[i]=tmpa[k];
    }
    free(tmpa);
}

void MergePass(int a[],int length,int n){
    int i;
    for (i = 0;i+2*length-1<n;i=i+2*length){
        cout<<"Circle begin:   length:"<<length<<" i:"<<i<<" i+length-1:"<<i+length-1<<" i+2*length-1:"<<i+2*length-1<<endl;
        Merge(a,i,i+length-1,i+2*length-1);
        display(a,10);
    }
    if (i+length-1<n){
        cout<<"Circle begin:   length:"<<length<<" i:"<<i<<" i+length-1:"<<i+length-1<<" n-1:"<<n-1<<endl;
        Merge(a,i,i+length-1,n-1);
        display(a,10);
    }
}

void MergeSort(int a[],int n){
    int length;
    int count=1;
    for (length = 1; length < n; length=2*length,count++)
    {
        cout<<"-------------------------------------------------------------"<<endl;
        cout<<"第"<<count<<"轮"<<" MS.Length:"<<length<<endl;
        MergePass(a,length,n);
    }
    
}

int main()
{
    int a[10]={8,6,1,0,14,24,7,3,14,2};
    MergeSort(a,10);
    system("pause");
}