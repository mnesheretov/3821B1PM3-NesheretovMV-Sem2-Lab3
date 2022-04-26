#pragma once
#include <iostream>

using namespace std;

class String
{
protected:

  char* string;
  int length;

public:

  String();
  String(int length, char c);
  String(const String& p);
  String(const char* s);
  ~String();

  char* GetString();
  int GetLength();

  void SetString(char* s1);
  void SetConstString(const char* s1);
  void SetLength(int l);

  String operator + (String& value);
  String operator = (const String& value);
  bool operator == (String& value);
  bool operator < (const String& value);
  bool operator > (const String& value);
  char operator [] (int i);
  friend ostream& operator << (ostream& ostr, const String& value);
  friend istream& operator >> (istream& istr, String& value);

  int FindWord(const char* str);
  int FindSymbol(char c);
  void SplitWord(char c);
  
};