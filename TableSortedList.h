#if !defined (TABLESORTEDLIST_H)
#define TABLESORTEDLIST_H

#include "SortedListDoublyLinked.h"

template < class T >
class TableSortedList
{

   private:
      SortedListDoublyLinked<T>* sldl;

   public:
      TableSortedList(int (*comp_item) (T* item_1, T* item_2), int (*comp_key) (String* key, T* item));
      ~TableSortedList();

      bool tableIsEmpty();
      int tableSize();
      T* tableRetrieve(String* sk);
      void tableInsert(T* item);  //does not allow duplicate search keys into the table (need to use getKey() to check for duplicates)
      bool tableRemove(String* search_key);  //returns true if delete is successful (need to call tableRetrieve to see if the item is there)

      ListDoublyLinkedIterator<T>* iterator();

};


template < class T >
TableSortedList<T>::TableSortedList(int (*comp_item) (T* item_1, T* item_2), int (*comp_key) (String* key, T* item)) {

	

}

template < class T >
TableSortedList<T>::~TableSortedList() {
	sldl -> removeAll();
}

template < class T >
bool TableSortedList<T>:: tableIsEmpty() {
	return sldl -> size() == 0;
}

template < class T >
int TableSortedList<T>::tableSize() {
	return sldl -> size();
}

template < class T >
T* TableSortedList<T>::tableRetrieve(String* sk) {
	return sldl -> get(sk);
}

template < class T >
void TableSortedList<T>::tableInsert(T* item) {
	return sldl -> add(item);
}

template < class T >
bool TableSortedList<T>::tableRemove(String* search_key) {
	return sldl -> remove(search_key);
}

#endif
