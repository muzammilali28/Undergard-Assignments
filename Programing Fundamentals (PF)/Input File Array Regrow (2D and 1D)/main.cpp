#include<iostream>
#include<fstream>
using namespace std;

int **regrow2D(int**,int,int);
int *regrow1D(int*,int,int);

int main()
{
	ifstream fin("file.txt");
	
	int colsize=0;
	int row=0;
	int num=0;
	int length=0;
	
	int **arr=NULL;
	int *size=NULL;
	
	while(fin>>colsize)
	{
		fin>>num;
		
		arr=regrow2D(arr,row,num);
		size=regrow1D(size,row,colsize);
		row++;
		
		length=1;
		
		for(int i=1; i<colsize; i++)
		{
			fin>>num;
			
			arr[row-1]=regrow1D(arr[row-1],length,num);
			length++;
		}
	}
	
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<size[i]; j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}
int **regrow2D(int **ptr,int length,int value)
{
	if(length==0)
	{
		ptr=new int*[1];
		ptr[0]=new int[1];
		ptr[0][0]=value;
		return ptr;
	}
	else
	{
		int **temp=NULL;
		
		temp=ptr;
		
		ptr=new int*[length+1];
		
		for(int i=0; i<length; i++)
		{
			ptr[i]=temp[i];
		}
		
		ptr[length]=new int[1];
		ptr[length][0]=value;
		
		delete[]temp;
		
		return ptr;
	}
}
int *regrow1D(int *ptr,int length,int value)
{
	if(length==0)
	{
		ptr=new int[1];
		ptr[0]=value;
		return ptr;
	}
	else
	{
		int *temp=NULL;
		
		temp=ptr;
		
		ptr=new int[length+1];
		
		for(int i=0; i<length; i++)
		{
			ptr[i]=temp[i];
		}
		
		ptr[length]=value;
		
		delete[]temp;
		
		return ptr;
	}
}
