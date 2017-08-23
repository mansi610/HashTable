#include "HashTable.h"

#include <string>
#include <iostream>
using namespace std;

int main()
{
		HashTable h(5);

		h.insert("Mary");
		h.insert("had");
		h.insert("a");
		h.insert("little");
		h.insert("lamb.");
		h.insert("It's");
		h.insert("fleece");
		h.insert("was");
		h.insert("white");
		h.insert("as");
		h.insert("snow");
		h.insert("And");
		h.insert("everywhere");
		h.insert("that");
		h.insert("Mary");
		h.insert("went,");
		h.insert("that");
		h.insert("lamb");
		h.insert("was");
		h.insert("sure");
		h.insert("to");
		h.insert("go.");

		h.print();
		system("pause");
	return 0;
}
