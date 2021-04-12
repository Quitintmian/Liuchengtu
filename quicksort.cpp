#include<iostream>
using namespace std;

void display(int a[],int n)
{
    cout<<" a[i]:";
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int Partition(int a[],int s,int t){
    int i=s,j=t;
    int temp=a[s];
    while (i!=j)
    {
        while (j>i&&a[j]>=temp) j--;
        while (i<j&&a[i]<=temp) i++;
        swap(a[i],a[j]);
    }
    swap(a[i],a[s]); //这里只能写a[s],不能写temp
    return i;
}

void QuickSort(int a[],int s,int t){
    if (s < t)
    {
        int i = Partition(a,s,t);
        cout<<"s:"<<s<<" t:"<<t;
        display(a,10);
        QuickSort(a,s,i-1);
        QuickSort(a,i+1,t);
    }
}

int main()
{
    int a[10]={4,9,1,0,14,3,2,20,11,6};
    QuickSort(a,0,9);
    system("pause");
}
