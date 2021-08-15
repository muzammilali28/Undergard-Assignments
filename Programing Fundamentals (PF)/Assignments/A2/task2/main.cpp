#include<iostream>
#include<fstream>
using namespace std;

int size(char[]);
void find(char[],char[],int&);
int length(char[]);

int main()
{
	char search[20]={"Pakistan"};
	char text[30]={'\0'};
	int count=0;
	
	ifstream fin;
	fin.open("input.txt");
	
	ofstream fout;
	fout.open("output.txt");
	
	if(!(fin.is_open()))
	{
		cout<<"File not found";
	}
	else
	{
		int Size=size(text);
	
		for(int i=0; i<Size; i++)
		{
			fin>>text;
		
			find(text,search,count);
		}
	
		fout<<search<<" is repeated "<<count<<" times.";
	}
	
	fin.close();
	fout.close();
	
	return 0;
}
int size(char filesize[])
{
	ifstream fin;
	fin.open("input.txt");
	
	int size=0;
	
	while(fin>>filesize)
	{
		size++;
	}
	
	fin.close();
	
	return size;
}
int length(char array[])
{
	int l=0;
	
	for(int i=0; array[i]!='\0'; i++)
	{
		l++;
	}
	
	return l;
}
void find(char text[],char search[],int &count)
{
	int check=0;
	
	for(int i=0; search[i]!='\0'; i++)
	{
		if(text[i]==search[i])
		{
			check++;
		}
	}
	
	if(check==length(search))
	{
		count++;
	}
}
