#include <iostream>
#include <fstream>
#include <chrono>
#include <string.h>
#include "mergeSort.cpp"
#include "selectionSort.cpp"
#include "quickSort.cpp"
using namespace std;

int main(){
	int size;
	char sort;
	string fileName;
	
	cout<<"Please enter the name of the file"<<endl;
	cin>>fileName;
	
	cout<<"Please enter the size of the file"<<endl;
	cin>>size;
	
	cout<<"Select the sort (Merge Sort(m), Quick Sort(q), Selection Sort(s))"<<endl;
	cin>>sort;
	
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
	
	/*for(int i = 0; i < 10; i++){
		memmove(temp,unsorted,size);
		quickSort(temp,0,size-1);
	}*/
	typedef std::chrono::high_resolution_clock Time;
	
	auto t0 = Time::now();
	for(int i = 0; i < 10; i++){
		int temp[size];
		for(int j = 0; j < size; j++){
			temp[j] = unsorted[j];
		}
		if(sort == 'm'){
			mergeSort(temp, 0 , size-1);
		}else if(sort == 'q'){
			quickSort(temp, 0 , size-1);
		}else{
			selection_sort_array(temp, size);
		}
		
	}
	auto t1 = Time::now();
	
	cout << chrono::duration_cast<nanosecond>((t0 - t1));
	
	ofstream myfile ("output.txt");
	if (myfile.is_open())
	{
		for(int i = 0; i < size; i++){
			myfile<<temp[i]<<"\n";
		}
		myfile.close();
	}
	else cout << "Unable to open file";
	return 0;
}