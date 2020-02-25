#include<cstdio>
#include<cstring>

void ReplaceSpaces(char* str, int maxlength) {
	if (str == nullptr || maxlength <= 0)
		return;
	
	int origlen = 0;
	int numofspaces = 0;
	int i = 0;
	while (str[i] != '\0') {
		++origlen;
		if (str[i] == ' ')
			++numofspaces;
		++i;
	}

	int newlen = origlen + 2*numofspaces;
	if (newlen > maxlength)
		return;

	int ind_orig = origlen;
	int ind_new = newlen;
	while (ind_orig >= 0 && ind_new > ind_orig) {
		if (str[ind_orig] == ' ') {
			str[ind_new--] = '0';
			str[ind_new--] = '2';
			str[ind_new--] = '%';
		}
		else {
			str[ind_new--] = str[ind_orig];
		}
		--ind_orig;
	}
}

void Test(char str[], int maxlength, char expectedstr[]) {
	ReplaceSpaces(str, maxlength);
	if (expectedstr == nullptr && str == nullptr)
		printf("passed.\n");
	else if (expectedstr == nullptr && str != nullptr)
		printf("failed.\n");
	else if (strcmp(str, expectedstr) == 0)
		printf("passed.\n");
	else
		printf("failed.\n");
}

void main() {
	const int maxlength = 50;
	char str1[maxlength] = "hello world";
	Test(str1, maxlength, (char*)"hello%20world");
	char str2[maxlength] = " hello world ";
	Test(str2, maxlength, (char*)"%20hello%20world%20");
	char str3[maxlength] = "hello   world";
	Test(str3, maxlength, (char*)"hello%20%20%20world");
	char str4[maxlength] = "";
	Test(str4, maxlength, (char*)"");
	return;
}