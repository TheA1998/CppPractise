#include"typedef.h"

int SeqSearch(SeqList list, int key) {
	list.elem[0] = key;
	int i;
	for (i = list.tablelen; list.elem[i] != key; --i);
	return i;
}