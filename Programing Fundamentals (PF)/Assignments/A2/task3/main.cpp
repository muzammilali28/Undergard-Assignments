#include<iostream>
#include<fstream>
using namespace std;

int length(char[]);
void compare(char[],char[],int[],int&,ofstream&);

int main()
{
	char text1[50]={'\0'};
	char text2[50]={'\0'};
	int position[50]={'\0'};
	int index=0;
	
	ifstream fin;
	fin.open("input.txt");
	
	ofstream fout;
	fout.open("output.txt");
	
	if(!(fin.is_open()))
	{
		cout<<"File not Found";
	}
	else
	{
		fin>>text1;
		fin>>text2;
	
		compare(text1,text2,position,index,fout);
	
		fout<<" ";
		
		for(int i=0; i<index; i++)
		{
			fout<<position[i]<<" ";
		}
	
	}
	
	fin.close();
	fout.close();
	
	return 0;
}
int length(char array[])
{
	int size=0;
	
	for(int i=0; array[i]!='\0'; i++)
	{
		size++;
	}
	
	return size;
}
void compare(char array1[],char array2[],int position[],int &index,ofstream &fout)
{
	if(length(array1)==length(array2))
	{
		for(int i=0; array1[i]!='\0'; i++)
		{
			if(array1[i]==array2[i])
			{
				fout<<array1[i];
				
				position[index]=i+1;
				index++;
			}
		}
	}
}
