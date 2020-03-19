#include <bits/stdc++.h>
using namespace std;

//DATA STRUCTURE
list<string> database;
vector<string> clipboard;
list<string> database2;
int redoflag=0;

//API
//SHALLOW COPY
void shalow()
{
	database2.clear();
	auto it = database.begin();
	while(it!=database.end())
	{
		database2.push_back(*it);
		it++;
	}
}
//INSERT
void insert(int n, string s)
{
	shalow();
	auto it = database.begin();
	advance(it,n);
	database.insert(it,s);
}
//DISPLAY
void display()
{
	auto it = database.begin();
	while(it!=database.end())
	{
		cout<<*it<<endl;
		it++;
	}
}
//DISPLAY N M
void display(int n,int m)
{
	auto it = database.begin();
	advance(it,n) ;
	while(it!=database.end() && n<=m)
	{
		cout<<*it<<endl;
		it++;
		n++;
	}
}
//DELETE
void delete_(int n)
{
	shalow();
	auto it = database.begin();
	advance(it,n);
	database.erase(it);
}
//DELETE N M
void delete_(int n,int m)
{
	shalow();
	auto it = database.begin();
	auto it2 = database.begin();
	advance(it,n);
	advance(it2,m);
	database.erase(it,it2);
}
//COPY
void copy(int n,int m)
{
	auto it = database.begin();
	advance(it,n);
	while(it!=database.end()&&n<=m)
	{
		clipboard.push_back(*it);
		it++;
		n++;
	}
}
//PASTE
void paste(int n)
{
	shalow();
	auto it = database.begin();
	advance(it,n);
	for(int i=0;i<clipboard.size();i++)
	{
		database.insert(it,clipboard[i]);
		it++;
	}
}
//UNDO
void undo()
{
	list<string> database3(database.begin(),database.end());
	database.clear();
	auto it = database2.begin();
	while(it!=database2.end())
	{
		database.push_back(*it);
		it++;
	}
	database2.clear();
	it = database3.begin();
	while(it!=database3.end())
	{
		database2.push_back(*it);
		it++;
	}
	redoflag=1;
}
//REDO
void redo()
{
	if(redoflag==1)
	{
	list<string> database3(database.begin(),database.end());
	database.clear();
	auto it = database2.begin();
	while(it!=database2.end())
	{
		database.push_back(*it);
		it++;
	}
	database2.clear();
	it = database3.begin();
	while(it!=database3.end())
	{
		database2.push_back(*it);
		it++;
	}
	}
	redoflag=0;
}

//MAIN
int main() {
	string command;
	while(cin>>command)
	{
		cout<<"_____________________________"<<endl;
		if(command=="insert")
		{
			int n;
			cin>>n;
			std::string s;
			std::getline(std::cin >> std::ws, s);
			insert(n,s);
		}
		if(command=="display")
		{
			display();
		}
		if(command=="displaynm")
		{
			int n,m;
			cin>>n>>m;
			display(n,m);
		}
		if(command=="deletenm")
		{
			int n,m;
			cin>>n>>m;
			delete_(n,m);
		}
		if(command=="delete")
		{
			int n;
			cin>>n;
			delete_(n);
		}
		if(command=="copy")
		{
			int n,m;
			cin>>n>>m;
			copy(n,m);
		}
		if(command=="paste")
		{
			int n;
			cin>>n;
			paste(n);
		}
		if(command=="redo")
		{
			redo();
		}
		if(command=="undo")
		{
			undo();
		}
		
	}
	return 0;
}
