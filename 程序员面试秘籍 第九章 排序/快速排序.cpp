#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
void quickSort(int *arr,int l,int r)
{
	//�˴���д����ʵ�ֿ�������
	int i,j,x,temp;
	if(l<r)
	{
		i=l;
		j=r;
		x=arr[(l+r)/2]; 
		//���м�Ԫ��Ϊ�� 
		while(1)
		{
			while(i<=r&&arr[i]<x)
				i++;
			while(j>=0&&arr[j]>x)
				j--;
			if(i>=j) //���������� 
				break;
			else
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp; 
				//���� 
			}
		}
		quickSort(arr,l,i-1); //����벿�ֽ��п��� 
		quickSort(arr,j+1,r); //���Ұ벿�ֽ��п��� 
	}
}
void print_num(int a[],int n)
{
	for(int i =0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void main()
{
	int a[]={7,3,5,8,9,1,2,4,6};
	print_num(a,9);
	quickSort(a,0,8);
	print_num(a,9);
	system("pause");
}
}