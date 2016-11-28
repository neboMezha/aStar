//#include "testing.h"
#include "myHeap.h"
#include <iostream>
#include <fstream>

struct searchData{ 
	bool visited;
	float gn;
	int hn;
};


void printMap(char dat[]) { ///////////////////////////////////////////////////////////PRINTING THE MAP

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 25; i++) {
		std::cout << dat[i] << " ";
		if (i == 4 || i == 9 || i == 14 || i == 19)
			std::cout << std::endl;
	}
	std::cout << std::endl;
}

void aStar() {
	myHeap<int, int> mh;

	char goal;
	int hn;
	int goalIndex;
	char data[25];
	/////////////////////////////////////////////////////////////READING IN THE MAP
	std::fstream file("map.txt", std::ios_base::in);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			file >> data[i * 5 + j]; //fills the array with numbers
		}
	}
	file.close();

	for (int i = 0; i < 25; i++) { //sets goal
		if (data[i] == '0' && i != 12)
		{
			goal = data[i];
			goalIndex = i;
		}
	}

	///////////////////////////////////////////////////////////STEP 2 AND ON

	int gx = goalIndex % 5;
	int gy = goalIndex / 5;
	int cx, cy;

	searchData srch[25];
	//int index = -1; //back-trace???
	//int* nodeData; DO I NEED THIS???
	for (int i = 0; i < 25; i++) {
		srch[i].visited = false;
		srch[i].gn = INFINITY;

		cx = i % 5;
		cy = i / 5;
		srch[i].hn = labs(cx-gx) + labs(cy-gy);
	}

	srch[12].visited = true;
	srch[12].gn = 0;  //distance  from n to start 

	////////////////////////////////////////////////////////////////////N IS THE INDEX OF THE ARRAY
	mh.push(srch[12].gn, 12); 

	//////////////////////////////////////////////////////////STEP 3?????

	int arb =12; //index holder

	std::cout<<"Goal Index is " << goalIndex << " goal is " <<goal;


	while (arb != goalIndex) {  

		arb = mh.pop();

		while (srch[arb].visited == true && arb!=12) {
			arb = mh.pop();
		}
		srch[arb].visited = true;


		cx = arb % 5;
		cy = arb / 5;

		//////////////////////////////////////////finding the H(n)

		//////////////////////////////////////////////

		//cout << srch[arb].fn << " " << srch[arb - 1].fn << endl;

		data[arb] = 'X';

		//cout << data[2]<<endl;

		if (!srch[arb - 1].visited && arb>0) {
			srch[arb - 1].gn = int(data[arb - 1]) - 48;//update G(n)


			mh.push(srch[arb - 1].gn + srch[arb-1].hn, arb - 1); //pushes in the left value
		}
		if (!srch[arb + 1].visited && arb<24) {
			srch[arb + 1].gn = int(data[arb + 1]) - 48;
			mh.push(srch[arb + 1].gn + srch[arb + 1].hn, arb + 1); //pushes in the right value
		}
		if (!srch[arb - 5].visited && arb>4) {
			srch[arb - 5].gn = int(data[arb - 5]) - 48;
			mh.push(srch[arb - 5].gn + srch[arb - 5].hn, arb - 5); //pushes in top value
		}
		if (!srch[arb + 5].visited && arb<20) {
			srch[arb + 5].gn = int(data[arb + 5]) - 48;
			mh.push(srch[arb + 5].gn + srch[arb + 5].hn, arb + 5); //pushes in lower value
		}

		printMap(data);
		if (arb == 2)break;

		char input;
		std::cout << "Went to " << arb%5<< "," << arb/5<< " Current Index is "<< arb << std::endl;
		//std::cout << "Neightbours are " << srch[arb - 1].visited << " " << srch[arb + 1].visited << " " << srch[arb - 5].visited << " " << srch[arb + 5].visited << std::endl;
		std::cout << "Continue?" << std::endl;
		std::cin >> input;
		//char input; /////////////////////////////////////////used to progress step by step
		//cin >> input;

		//cout << data[arb + 1] - 48 << " " << srch[arb + 1].gn;
	}


	///////////////////////////////////////////PRINTING OUT TO CHECK THINGS
	/*int size = mh.getSize();
	for (int a = 0; a < size; a++) {
		cout << mh.pop()<< " ";
	}*/


	//std::cout << "things are done" << std::endl;  //////////////////////////////////////////////BREAK POINT
	return;
}


int main() {

	aStar();
/*
	myHeap<float, char> mh;

	mh.push(2.f, 'b');
	mh.push(1.f, 'a');
	mh.push(3.f, 'c');
	mh.push(5.f, 'e');
	mh.push(1.f, 'a');
	mh.push(4.f, 'd');
	mh.push(3.f, 'c');

	int size = mh.getSize();
	for (int a = 0; a < size; a++) {
		cout << mh.pop();
	}
*/
	char input;
	std::cout << "GOAL WAS FOUND" << std::endl;
	std::cin >> input;
	return 0;
}

