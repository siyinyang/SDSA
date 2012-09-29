#include "StdAfx.h"
#include "IString.h"


IString::IString(void)
{
}

IString::IString(IString& s)
{
	this->str = new char[strlen(s.str)];
	strcpy(str, s.str);
}

IString::~IString(void)
{
}

ostream& operator<<(ostream& output, IString& str){
	output<<str.str;
	return output;
}

bool IString::operator==(const IString s2){
	return !strcmp(this->str, s2.str);
}

bool IString::operator==(const char* s2){
	return !strcmp(this->str, s2);
}


void IString::operator=(IString& newStr){
	swap(newStr.str, str);
}

IString IString::operator+(const char* s2){
	IString istr(*this);
	istr.append(s2);
	//char* newStr = new char[strlen(str)];
	//strcpy(newStr, str);
	//strcat(newStr, s2);
	
	return istr;
}

IString IString::operator+(IString& s2){
	IString istr(*this);
	istr.append(s2.str);
	//char* newStr = new char[strlen(str)];
	//strcpy(newStr, str);
	//strcat(newStr, s2);
	
	return istr;
}

IString operator+(const char* s1, IString& s2){
	IString istr((char*)s1);
	istr.append(s2.str);
	//char* newStr = new char[strlen(str)];
	//strcpy(newStr, str);
	//strcat(newStr, s2);
	
	return istr;
}

bool IString::hasSubstring(const char *str, const char *find){
	if (str[0] == '\0' && find[0] == '\0')
        return true;
    
    for(int i = 0; str[i] != '\0'; i++) {
        bool foundNonMatch = false;
		for(int j = 0; find[j] != '\0'; j++) {
            if (str[i + j] != find[j]) {
                foundNonMatch = true;
                break;
			}       
		}   
        if (!foundNonMatch)
            return true;
	}
	
	return false;
}

void IString::reverse(char* str){
	int len = strlen(str);
	for(int i = 0; i < len / 2; i++)
		swap(str[i], str[len-1-i]);
}

void IString::reverse(char* str, int start, int end){
	int len = end - start + 1;
	for(int i = 0; i < len / 2; i++)
		swap(str[start + i], str[end-i]);
}

void IString::swapAt_1(char* str, int i){
	
	for(int j = 0; j < i; j++){
		
	}
}

void IString::swapAt_2(char* str, int i, int start, int end){
	if (end <= start)
		return;

	int len = end - start + 1;
	int k = len - i;
	
	if(i > k){
		//  a[1, i] b[1, k]
		//reverse b[1, k] and a[i-k+1 ,i]
		for(int j = start+i; j <= end; j++)
			swap(str[j], str[j-k]);

		swapAt_2(str, i-k, start, i-1);
	}
	else{
		//  a[1, i] b[1, k]
		//reverse b[1, k] and a[i-k+1 ,i]
		for(int j = start; j < start+i; j++)
			swap(str[j], str[j+i]);

		swapAt_2(str, i, start + i, end);
	}
}

void IString::swapAt_3(char* str, int i){
	reverse(str, 0, i-1);
	reverse(str, i, strlen(str)-1);
	reverse(str);
}

int IString::kmpSearch(char* S,  char* W){
    /*input:
        an array of characters, S (the text to be searched)
        an array of characters, W (the word sought)
    output:
        an integer (the zero-based position in S at which W is found)*/

 
	int m = 0 ;//(the beginning of the current match in S)
    int i = 0 ;//(the position of the current character in W)
	int lenS = strlen(S);
    int* T = new int[lenS]; //(the table, computed elsewhere)

	int pos = 2; // (the current position we are computing in T)
    int cnd = 0; // (the zero-based index in W of the next character of the current candidate substring)

    //(the first few values are fixed but different from what the algorithm might suggest)
    T[0] = -1; T[1] = 0;

    while (pos < strlen(W)){
        //(first case: the substring continues)
        if (W[pos - 1] == W[cnd]){
			cnd = cnd + 1; T[pos] = cnd; pos = pos + 1;
		}
        //(second case: it doesn't,  but we can fall back)
        else if (cnd > 0)
			cnd = T[cnd];
		//(third case: we have run out of candidates.  Note cnd = 0)
		else{
			T[pos] = 0;
			pos = pos + 1;
		}
	}
	
    while (m+i < lenS){
        if (W[i] == S[m + i]){
            if (i == strlen(W)-1)
                return m;
            i++;
		}
		else{
            m = m + i - T[i];
            if (T[i] > -1)
                i = T[i];
            else
                i = 0;
		}
	} 
    //(if we reach here, we have searched all of S unsuccessfully)
    return strlen(S); 
}

void IString::reverse(){
	IString::reverse(this->str);
}

bool IString::readInt(int& i, int& v){
	int len = strlen(str);
	int start = i;
	//int end = start;
	bool flag = false;
	for(int j = i; j < len; j++){
		if(str[j] >= '0' && str[j] <='9' ){
			if(!flag){
				flag = true;
				start = j;
				i = start;
			}
			else{
				i++;
			}
		}
		else if(flag){
			break;
		}
	}

	if(!flag)
		return false;

	v = 0;
	for(int k = i, j = 0; k >= start; k--, j++){
		int digit = str[k] - '0';
		v+= digit *pow(10.0, j);
	}

	return true;
}

int IString::length(){
	return strlen(str);
}

char IString::charAt(int i){
	if(i>=0 && i < strlen(str)){
		return str[i];
	}
	else 
		return '\0';
}

void IString::append(const char* appStr){
	if(str && appStr){
		int len1 = strlen(str);
		int len2 = strlen(appStr);

		char* temp = new char[len1 + 1]; 
		strcpy(temp, str);
	
		for(int i = len1, j = 0; i < len1 + len2; i++, j++)
			temp[i] = appStr[j];

		temp[len1+len2] = '\0';
		swap(str, temp);
	}
}

void IString::deleteLast(int n){
	int len = strlen(str);
	if(n <= len)
		str[len-n] = '\0';
}

char* IString::charStr(){
	return str;
}