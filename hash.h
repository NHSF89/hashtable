#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

#ifndef HASH_H
#define HASH_H

class hash
{
	private:
		static const int table = 20;
	
		struct item
		{
			int number;
			string name;
			item* nextItem;
		};
		
		item* hashTable[table];
		
	public:
        hash();
		int Hash(string key);
		void AddItem(int number, string name);
		int NumItemsInIndex(int index);
		void printTable();
		void printIndex(int index);
		void findNumber(string name);
		void removeItem(string name);

};

#endif
