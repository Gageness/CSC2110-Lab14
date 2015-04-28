#include "TableSortedList.h"
#include "ListArray.h"
using CSC2110::ListArray;
#include "ListArrayIterator.h"
using CSC2110::ListArrayIterator;
#include "CD.h"
using CSC2110::CD;
#include "Text.h"
using CSC2110::String;

#include <iostream>
using namespace std;

void deleteCDs(ListArray<CD>* list)
{
   ListArrayIterator<CD>* iter = list->iterator();

   while(iter->hasNext())
   {
      CD* cd = iter->next();
      delete cd;
   }
   delete iter;
}

int main()
{
   ListArray<CD>* cds = CD::readCDs("cds.txt");
   int num_items = cds->size();
   cout << num_items << endl;

   TableSortedList<CD>* slt = new TableSortedList<CD>(&CD::compare_items, &CD::compare_keys);

   //DO THIS
   //thoroughly test your table
   ListArrayIterator<CD>* addCDs = cds->iterator();
   while (addCDs->hasNext())
   {
	   slt->tableInsert(addCDs->next());
   }
   cout << "Size after adding CDs: " << slt->tableSize() << endl;
   
   String* sk = new String("Omnivium");
   cout << "Retrieving " << "Omnivium" << "..." << endl;
   slt->tableRetrieve(sk)->displayCD();
   
   cout << "\nSize after retrieval: " << slt->tableSize() << endl;
   
   cout << "\n\nRemoving " << "Omnivium" << "..." << endl;
   bool isDelete = slt->tableRemove(sk);
   cout << "successful? ";
   if (isDelete) cout << "Yes";
   else cout << "No";
   
   
   sk = new String("Programmed To Consume");
   cout << "\n\nRemoving " << "Programmed to Consume" << "..." << endl;
   isDelete = slt->tableRemove(sk);
   cout << "Successful? ";
   if (isDelete) cout << "Yes";
   else cout << "No";
   
   cout << "\n\nSize after removal: " << slt->tableSize() << endl;
   
   sk = new String("My Little Pony Anthology");
   cout << "\n\nRemoving item not in table, " << "My Little Pony Anthology" << "..." << endl;
   isDelete = slt->tableRemove(sk);
   cout << "Successful? ";
   if (isDelete) cout << "Yes";
   else cout << "No";
   
   cout << "\n\nSize after removal: " << slt->tableSize() << endl;
   
   cout << "\nIs the table empty? ";
   if (!slt->tableIsEmpty()) cout << "No";
   else cout << "Yes";

   deleteCDs(cds);
   delete cds;
   delete slt;
   return 0;
}
