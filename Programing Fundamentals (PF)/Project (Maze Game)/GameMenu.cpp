#include<iostream>
#include<fstream>
using namespace std;

int **dynamic2D(int);
void fillArr(int**,int,int,ifstream&);
void outputArr(int**,int,int);
bool checkMove(int,int,int,int);
bool isSafe(int**,int,int,int&,int&,int**,int,int);
void solveMaze(int**,int,int,int&,int&,int&,int**);

int main()
{
	char name[50]={'\0'};
	int choice=0;
	int select=0;
	
	cout<<"Wlcome to Rat in a Maze Game!"<<endl<<endl;
	cout<<"1. Start New Game"<<endl;
	cout<<"2. Game Info"<<endl;
	cout<<"3. High Scores"<<endl<<endl;
	
	cout<<"Select Option : ";
	cin>>select;
	
	cin.ignore();
	
	system("CLS");
	
	if(select==1)
	{
		cout<<"Enter Name : ";
		cin.getline(name,49);
		system("CLS");
		
		cout<<"Choose your Maze Difficulty"<<endl<<endl;
		cout<<"1. Easy"<<endl;
		cout<<"2. Medium"<<endl;
		cout<<"3. Hard"<<endl<<endl;
		
		cout<<"Enter choice : ";
		cin>>choice;
		system("CLS");
		
		if(choice==1)
		{
			ifstream fin("easy.txt");
			
			int row=0;
			int col=0;
			int x=0;
			int y=0;
			int score=0;
			
			fin>>row;
			fin>>col;
			
			int **maze=dynamic2D(row);
			
			fillArr(maze,row,col,fin);
			
			fin.close();
			
			int **sol=dynamic2D(row);
			
			for(int i=0; i<row; i++)
			{
				sol[i] = new int[col];
				
				for(int j=0; j<col; j++)
				{
					sol[i][j]=8;
				}
			}
			
			solveMaze(maze,row,col,x,y,score,sol);
			
			if(score<0)
			{
				score=0;
			}
			
			outputArr(sol,row,col);
			cout<<endl<<"Name : "<<name<<endl;
			cout<<"Score : "<<score;
			
			ofstream fout;
			fout.open("scores.txt",ios::app);
			
			fout<<name<<" "<<score<<endl;
			
			fout.close();
		}
		else if(choice==2)
		{
			ifstream fin("medium.txt");
			
			int row=0;
			int col=0;
			int x=0;
			int y=0;
			int score=0;
			
			fin>>row;
			fin>>col;
			
			int **maze=dynamic2D(row);
			
			fillArr(maze,row,col,fin);
			
			fin.close();
			
			int **sol=dynamic2D(row);
			
			for(int i=0; i<row; i++)
			{
				sol[i] = new int[col];
				
				for(int j=0; j<col; j++)
				{
					sol[i][j]=8;
				}
			}
			
			solveMaze(maze,row,col,x,y,score,sol);
			
			if(score<0)
			{
				score=0;
			}
			
			outputArr(sol,row,col);
			cout<<endl<<"Name : "<<name<<endl;
			cout<<"Score : "<<score;
			
			ofstream fout;
			fout.open("scores.txt",ios::app);
			
			fout<<name<<" "<<score<<endl;
			
			fout.close();
		}
		else if(choice==3)
		{
			ifstream fin("hard.txt");
			
			int row=0;
			int col=0;
			int x=0;
			int y=0;
			int score=0;
			
			fin>>row;
			fin>>col;
			
			int **maze=dynamic2D(row);
			
			fillArr(maze,row,col,fin);
			
			fin.close();
			
			int **sol=dynamic2D(row);
			
			for(int i=0; i<row; i++)
			{
				sol[i] = new int[col];
				
				for(int j=0; j<col; j++)
				{
					sol[i][j]=8;
				}
			}
			
			solveMaze(maze,row,col,x,y,score,sol);
			
			if(score<0)
			{
				score=0;
			}
			
			outputArr(sol,row,col);
			cout<<endl<<"Name : "<<name<<endl;
			cout<<"Score : "<<score;
		
			ofstream fout;
			fout.open("scores.txt",ios::app);
			
			fout<<name<<" "<<score<<endl;
			
			fout.close();
		}
	}
	else if(select==2)
	{
		cout<<"Movement Control!"<<endl;
		cout<<"(W) Up"<<endl;
		cout<<"(A) Left"<<endl;
		cout<<"(S) Down"<<endl;
		cout<<"(D) Right"<<endl<<endl;
		
		cout<<"Path Tracking Info!"<<endl;
		cout<<"Path = * (Path Unexplored)"<<endl;
		cout<<"Path = 0 (Path Blocked)"<<endl;
		cout<<"Path = 1 (Valid Path)"<<endl;
		cout<<"Path = -2 (Monster)"<<endl<<endl;
		
		cout<<"Scores Info!"<<endl;
		cout<<"You Will have (3 Rat Lives) to reach the Destination --> (Bottom Right)"<<endl;
		cout<<"You will Start from --> (Top Left) of the Maze and have to reach your Destination"<<endl<<endl;
		cout<<"Hit = 0 (Score -1)"<<endl;
		cout<<"Hit = -2 (Score -5) and RatLife(-1)"<<endl;
		cout<<"Hit = 1 (Score +5)"<<endl;
	}
	else if(select==3)
	{
		char arr[100]={'\0'};
		ifstream fin("scores.txt");
		
		cout<<"Name | Score"<<endl<<endl;
		
		while(fin.getline(arr,99))
		{
			cout<<arr<<endl<<endl;
		}
		
		fin.close();
	}
	
	return 0;
}

int **dynamic2D(int row)
{
	int **temp=NULL;
	temp=new int*[row];
	return temp;
}
void fillArr(int **maze,int row,int col,ifstream &fin)
{
	for (int i=0; i<col; i++)
	{
		maze[i]=new int[col];
		
		for(int j=0; j<col; j++)
		{
			fin>>maze[i][j];
		}
	}
}
void outputArr(int**arr,int row,int col)
{
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			if(arr[i][j]==8)
			{
				cout<<"*"<<"\t";
			}
			else
			{
				cout<<arr[i][j]<<"\t";
			}
		}
		cout<<endl;
	}
}
bool checkMove(int x,int y,int row,int col)
{
	if((x>=0 && x<row) && (y>=0 && y<col))
	{
		return true;
	}
	return false;
}
bool isSafe(int**maze,int x,int y,int &score,int &ratLife,int **sol,int row,int col)
{
	if(maze[x][y]==0)
	{
		sol[x][y]=0;
		score--;
		outputArr(sol,row,col);
		cout<<endl<<"Path Blocked , stored back to last position!"<<endl;
		cout<<endl<<endl;
		cout<<"SCore : "<<score<<endl<<endl;
		return false;
	}
	else if(maze[x][y]==-2)
	{
		sol[x][y]=-2;
		ratLife--;
		score=score-5;
		outputArr(sol,row,col);
		cout<<endl<<"Monster in Path , stored back to last position!"<<endl;
		cout<<endl<<"ratLife : "<<ratLife<<endl<<endl;
		cout<<"Score : "<<score<<endl<<endl;
		return false;
	}
	else if(sol[x][y]==1)
	{
		score=score;
		cout<<"Score : "<<score<<endl<<endl;
		return true;
	}
	else if(maze[x][y]==1)
	{
		score=score+5;
		return true;
	}
}
void solveMaze(int**maze,int row,int col,int &x,int &y,int &score,int**sol)
{	
	char move='\0';
	int ratLife=3;
	
	if(x==0 && y==0)
	{
		sol[x][y]=1;
	}
	
	cout<<"Starting Position --> (Top Left)"<<endl<<endl;
	outputArr(sol,row,col);
	cout<<endl<<endl;
	cout<<"Movement Control!"<<endl;
	cout<<"(W) Up"<<endl;
	cout<<"(A) Left"<<endl;
	cout<<"(S) Down"<<endl;
	cout<<"(D) Right"<<endl<<endl;
	
	cout<<"Path Tracking Info!"<<endl;
	cout<<"Path = * (Path Unexplored)"<<endl;
	cout<<"Path = 0 (Path Blocked)"<<endl;
	cout<<"Path = 1 (Valid Path)"<<endl;
	cout<<"Path = -2 (Monster)"<<endl<<endl;
	
	while(1)
	{
		if(ratLife==0)
		{
			system("CLS");
			cout<<"GAME OVER"<<endl;
			cout<<"You ran out of Lives!"<<endl<<endl;
			break;
		}
		else if(x==row-1 && y==col-1)
		{
			sol[x][y]=1;
			system("CLS");
			cout<<"Congratulation! You solved the Maze!"<<endl<<endl;
			break;
		}
		
		cout<<"Enter Move : ";
		cin>>move;
		cout<<endl<<endl;
		
		if(move=='d' || move=='D')
		{
			if(checkMove(x,y+1,row,col)==true)
			{
				if(isSafe(maze,x,y+1,score,ratLife,sol,row,col)==true)
				{
					y=y+1;
					sol[x][y]=1;
					outputArr(sol,row,col);
					cout<<endl<<endl;
					cout<<"Score : "<<score<<endl<<endl;
				}
			}
			else
			{
				cout<<"Can't go out of Maze!"<<endl<<endl;
			}
		}
		else if(move=='s' || move=='S')
		{
			if(checkMove(x+1,y,row,col)==true)
			{
				if(isSafe(maze,x+1,y,score,ratLife,sol,row,col)==true)
				{
					x=x+1;
					sol[x][y]=1;
					outputArr(sol,row,col);
					cout<<endl<<endl;
					cout<<"Score : "<<score<<endl<<endl;
				}
			}
			else
			{
				cout<<"Can't go out of Maze!"<<endl<<endl;
			}
		}
		else if(move=='a' || move=='A')
		{
			if(checkMove(x,y-1,row,col)==true)
			{
				if(isSafe(maze,x,y-1,score,ratLife,sol,row,col)==true)
				{
					y=y-1;
					sol[x][y]=1;
					outputArr(sol,row,col);
					cout<<endl<<endl;
					cout<<"Score : "<<score<<endl<<endl;
				}
			}
			else
			{
				cout<<"Can't go out of Maze!"<<endl<<endl;
			}
		}
		else if(move=='w' || move=='W')
		{
			if(checkMove(x-1,y,row,col)==true)
			{
				if(isSafe(maze,x-1,y,score,ratLife,sol,row,col)==true)
				{
					x=x-1;
					sol[x][y]=1;
					outputArr(sol,row,col);
					cout<<endl<<endl;
					cout<<"Score : "<<score<<endl<<endl;
				}
			}
			else
			{
				cout<<"Can't go out of Maze!"<<endl<<endl;
			}
		}
	}
}
