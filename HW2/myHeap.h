#pragma once

template<typename T, typename K>
class myHeap
{

public:
	myHeap(){
		size = 0; 
	}
	~myHeap() { }

	int getSize() {
		return size;
	}
	void push(T newKey, K val) {
		keys[size] = newKey;
		vals[size] = val;
		HeapifyUp(size);
		size++;

	}
	K pop() {
		//K popped = vals[size - 1];
		//size--;
		K temp = vals[0];

		vals[0] = vals[size - 1];
		vals[size - 1] = 0; //maybe???
		keys[0] = keys[size - 1];
		keys[size - 1] = 0; //maybe???
		size--;
		HeapifyDn(0);
		return temp;
		//return popped;
	}


private:
	int size;
	static const int MAX_SIZE = 100;

	T keys[MAX_SIZE] = {}; //weights
	K vals[MAX_SIZE] = {}; //names

	void HeapifyUp(int i) {
		if (i <= 0)return;
		int p = getParent(i);
		if (keys[i] < keys[p])
			swap(i, p);
		HeapifyUp(p);
		
	}
	void HeapifyDn(int i) {
		int c;
		if (getLeft(i) > size - 1) return;

		if (getRight(i) > size - 1) {
			c = getLeft(i);
		}
		else {
			c = (keys[getLeft(i)]< keys[getRight(i)]) ? (getLeft(i)) : (getRight(i));
		}
		if (keys[i] > keys[c])
			swap(i, c);
		HeapifyDn(c);

	}
	void swap(int i, int j) {
		T temp = keys[i];
		keys[i] = keys[j];
		keys[j] = temp;

		K temp2 = vals[i];
		vals[i] = vals[j];
		vals[j] = temp2;
	}
	static int getParent(int i) {
		return (i - 1) / 2;
	}
	static int getLeft(int i) {
		return 2 * i + 1;
	}
	static int getRight(int i) {
		return 2 * i + 2;
	}

};
