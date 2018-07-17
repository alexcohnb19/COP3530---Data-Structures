#include <iostream>
#include <fstream>
#include <time.h>
#include <chrono>
#include <ctime>
#include <ratio>
#include "mergeSort.cpp"
#include "selectionSort.cpp"
using namespace std;
int main(){
	int size;
	string fileName;
	
	cout<<"Please enter the name of the file"<<endl;
	cin>>fileName;
	
	cout<<"Please enter the size of the file"<<endl;
	cin>>size;
	
	int unsorted[size];
	
	ifstream inFile;
	inFile.open(fileName);
	int i = 0;
	if(!inFile){
		cout<<"Cant Read File";
	}else{
		while(inFile>>unsorted[i]){
			i++;
		}
	}
	
	//Calculate Time
	//Sort 1000 Times
	
	auto time = chrono::high_resolution_clock::now();
	cout<<chrono::(nanoseconds)time;

	return 0;
}