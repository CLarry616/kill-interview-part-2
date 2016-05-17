#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

oid HeapAdjust(int *a,int i,int size)  //������ 
{
    int lchild=2*i+1;       //i�����ӽڵ���� 
    int rchild=2*i+2;     //i���Һ��ӽڵ���� 
    int max=i;            //��ʱ���� 
    if(i<=size/2)          //���i��Ҷ�ڵ�Ͳ��ý��е��� 
    {
        if(lchild<=size&&a[lchild]>a[max])
        {
            max=lchild;
        }    
        if(rchild<=size&&a[rchild]>a[max])
        {
            max=rchild;
        }
        if(max!=i)
        {
            swap(a[i],a[max]);
            HeapAdjust(a,max,size);    //�������֮����maxΪ���ڵ���������Ƕ� 
        }
    }        
}

void BuildHeap(int *a,int size)    //������ 
{
    int i;
    for(i=size/2;i>=1;i--)    //��Ҷ�ڵ�������ֵΪsize/2 
    {
        HeapAdjust(a,i,size);    
    }    
} 

void HeapSort(int *a,int size)    //������ 
{
    int i;
    BuildHeap(a,size);
    for(i=size;i>=1;i--)
    {
        //cout<<a[1]<<" ";
        swap(a[1],a[i]);           //�����Ѷ������һ��Ԫ�أ���ÿ�ν�ʣ��Ԫ���е�����߷ŵ������ 
          //BuildHeap(a,i-1);        //������Ԫ�����½���Ϊ�󶥶� 
          HeapAdjust(a,1,i-1);      //���µ����Ѷ��ڵ��Ϊ�󶥶�
    }
}

void main()
{
	int a[]={7,3,5,8,9,1,2,4,6};
	print_num(a,9);
	HeapSort(a,8);
	print_num(a,9);
	system("pause");
}