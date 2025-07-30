#include<bits/stdc++.h>
using namespace std;

class HashTable{
	public:
	static const int LIMIT = 10;
	list<int> table[LIMIT];

	int hashFunction(int key){
		return key % LIMIT;
	}

	void insert(int key){
		int index = hashFunction(key);
		table[index].push_back(key);
	}

	void remove(int key){
		int index = hashFunction(key);
		table[index].remove(key);
	}

	bool search(int key){
		int index = hashFunction(key);
		for(int val : table[index]){
			if(val == key){
				return true;
			}
		}
		return false;
	}

	void display() {
		for(int i=0;i<LIMIT; i++){
			cout<<i<<" : ";
			for(int val : table[i]){
				cout<<val <<" ";
			}
			cout<<endl;
		}
	}
};

int main() {
	HashTable HashTable;
	HashTable.insert(10);
	HashTable.insert(12);
	HashTable.insert(19);
	HashTable.insert(11);
	HashTable.insert(26);
	HashTable.insert(17);
	HashTable.insert(23);
	HashTable.insert(31);
	HashTable.display();
}