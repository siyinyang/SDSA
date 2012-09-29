#pragma once
class IString
{
private:
	char* str;
public:
	IString(void);
	IString(char* s):str(s){}
	IString(IString& str);
	~IString(void);
	static bool hasSubstring(const char *str, const char *find);
	static int IString::kmpSearch(char* S,  char* W);
	static void reverse(char* str);

	static void reverse(char* str, int start, int end);
	static void swapAt_1(char* str, int i);
	static void swapAt_2(char* str, int i, int start, int end);
	static void swapAt_3(char* str, int i);
	
	void append(const char* appStr);
	void reverse();
	void deleteLast(int n);

	char charAt(int i);
	int length();

	bool readInt(int& start, int& v);

	bool operator==(const char* s2);
	bool operator==(IString s2);
	void operator=(IString& istr);
	IString operator+(const char*);
	IString operator+(IString& s2);
	friend IString operator+(const char* s1, IString& s2);
	
	char* charStr();
	
	friend ostream& operator<<(ostream& output, IString& str);
};

