/*
Reference:
KMP & getNext: https://www.bilibili.com/video/av76933202?p=4
StringStruct: https://www.cnblogs.com/hughdong/p/6885514.html
*/

#define MAXLEN 255
#include<string>
#include<iostream>
using namespace std;

typedef struct {
	char ch[MAXLEN];
	int length;
}SeqString;

typedef struct {
	char* ch;
	int length;
}HeapString;

int StrAssign(HeapString& str, char* chars) {
	int len = strlen(chars);
	if (!len) {
		str.ch = nullptr;
		str.length = 0;
		return -1;
	}
	else {
		str.ch = (char*)malloc((len+1) * sizeof(char));
		if (!str.ch) {
			exit(OVERFLOW);
		}
		for (int i = 1; i <= len; i++)
			str.ch[i] = chars[i];
		str.length = len;
		return 0;
	}
}

// BF
int BruteForceMatch(HeapString str, HeapString pattern, int pos){
	int i = pos, j = 1, k = i;
	while (i <= str.length && j <= pattern.length) {
		if (str.ch[i] == pattern.ch[j]) {
			i++; j++;
		}
		else {
			j = 1;
			i = ++k;
		}
	}
	if (j > pattern.length)
		return k;
	else
		return 0;
}

void getNext(HeapString pattern, int next[]) {
	int i = 1, j = 0;
	next[1] = 0;
	while (i < pattern.length) {
		if (j == 0 || pattern.ch[i] == pattern.ch[j]) {
			i++; j++;
			next[i] = j;
		}
		else
			j = next[j];
	}
}

int KMPMatch(HeapString str, HeapString pattern, int next[], int pos) {
	int i = pos, j = 1;
	while (i <= str.length && j <= pattern.length) {
		if (j == 0 || str.ch[i] == pattern.ch[j]) {
			i++; j++;
		}
		else
			j = next[j];
	}
	if (j > pattern.length)
		return i - pattern.length;
	else
		return 0;
}

int main() {
	HeapString str;
	char* str_chars = (char*)"abcabcacabbabcacbcc";
	StrAssign(str, str_chars);
	HeapString pattern;
	char* pattern_chars = (char*)"abcac";
	StrAssign(pattern, pattern_chars);

	cout << "BF_1: " << BruteForceMatch(str, pattern, 2) << endl;
	cout << "BF_2: " << BruteForceMatch(str, pattern, 9) << endl;
	cout << "BF_3: " << BruteForceMatch(str, pattern, 16) << endl;

	int next[5];
	getNext(pattern, next);
	for (int i = 0; i < 5; i++) {
		cout << next[i] << " ";
	}
	cout << endl;

	cout << "KMP_1: " << KMPMatch(str, pattern, next, 2) << endl;
	cout << "KMP_2: " << KMPMatch(str, pattern, next, 9) << endl;
	cout << "KMP_3: " << KMPMatch(str, pattern, next, 16) << endl;

	return 0;

}