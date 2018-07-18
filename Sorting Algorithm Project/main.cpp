#include <iostream>
#include <fstream>
#include <chrono>
#include "mergeSort.cpp"
#include "selectionSort.cpp"
#include "quickSort.cpp"
using namespace std;
int main(){
	auto totalTime = 0;
	int size;
	string fileName;
	
	cout<<"Please enter the name of the file"<<endl;
	cin>>fileName;
	
	cout<<"Please enter the size of the file"<<endl;
	cin>>size;
	
	int unsorted[size];
	int temp[size];
	
	ifstream inFile;
	inFile.open(fileName);
	int i = 0;
	if(!inFile){
		cout<<"Cant Read File";
	}else{
		while(inFile>>unsorted[i]){
			i++;
		}
		inFile.close();
	}

	//Calculate Time
	//Sort 1000 Times

	quickSort(unsorted,0,size-1);
	ofstream myfile ("output.txt");
	if (myfile.is_open())
	{
		for(int i = 0; i < size; i++){
			myfile<<unsorted[i]<<"\n";
		}
		myfile.close();
	}
	else cout << "Unable to open file";
	return 0;
}