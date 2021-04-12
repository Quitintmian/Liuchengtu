#include<iostream>
#include<malloc.h>
using namespace std;

void display(int a[],int n)
{
    cout<<" t[i]:";
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void Merge(int a[],int low,int mid,int high){
    int *tmpa;
    int i=low;
    int j=mid+1,k=0;
    tmpa=(int *)malloc(sizeof(int)*(high-low+1));//´æ·ÅÓÐÐòÐòÁÐ
    cout<<"i:"<<i<<" j:"<<j<<" k:"<<k<<" a[i]:"<<a[i]<<" a[j]:"<<a[j];
    display(tmpa,10);
    while (i<=mid&&j<=high)
    {
        if(a[i]<=a[j]){
            tmpa[k]=a[i];
            i++;
            k++;
            cout<<"i:"<<i<<" j:"<<j<<" k:"<<k<<" a[i]:"<<a[i]<<" a[j]:"<<a[j];
            display(tmpa,10);
        }else
        {
            tmpa[k]=a[j];
            j++;
            k++;
            cout<<"i:"<<i<<" j:"<<j<<" k:"<<k<<" a[i]:"<<a[i]<<" a[j]:"<<a[j];
            display(tmpa,10);
        }
    }
    cout<<"--------------------------------"<<endl;
    while (j<=high)
    {
        tmpa[k]=a[j];
        j++;
        k++;
        cout<<"i:"<<i<<" j:"<<j<<" k:"<<k<<" a[i]:"<<a[i]<<" a[j]:"<<a[j];
        display(tmpa,10);
    }
    while (i<=mid)
    {
        tmpa[k]=a[i];
        i++;
        k++;
        cout<<"i:"<<i<<" j:"<<j<<" k:"<<k<<" a[i]:"<<a[i]<<" a[j]:"<<a[j];
        display(tmpa,10);
    }
    for (k=0,i=low;i<=high;k++,i++)
    {
        a[i]=tmpa[k];
    }
    free(tmpa);
}

int main()
{
    int a[10]={1,3,7,8,9,0,2,5,6,10};
    Merge(a,0,4,9);
    system("pause");
}