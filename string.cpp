#include "string.h"
#include <string.h>
#include <iostream>

String::String()
{
  length = 0;
  string = new char[1];
  string[0] = '\0';
}

String::String(int l, char c)
{
  length = l;
  string = new char[length + 1];

  for (int i = 0; i < l; i++)
    string[i] = c;

  string[length] = '\0';
}

String::String(const String& p)
{
  length = p.length;
  string = new char[length + 1];

  for (int i = 0; i < length; i++)
    string[i] = p.string[i];
  string[length] = '\0';
}

String::String(const char* s)
{
  if (s == nullptr)
  {
    length = 0;
    string = new char[1];
    string[0] = '\0';
  }
  else
  {
    length = strlen(s);
    string = new char[length + 1];

    for (int i = 0; i < length; i++)
      string[i] = s[i];
    string[length] = '\0';
  }
}

String::~String()
{
  delete[] string;
}

int String::GetLength()
{
  return length;
}

char* String::GetString()
{
  char* a = new char[length];
  for (int i = 0; i <= length; i++)
    a[i] = string[i];
  return a;
}

void String::SetLength(int l)
{
  length = l;
}

void String::SetString(char* s1)
{
  if (s1 == nullptr) throw "Error!!!";

  if (string != nullptr) delete[] string;
  string = new char[strlen(s1) + 1];
  string[strlen(s1)] = '\0';

  for (int q = 0; q < strlen(s1); q++)
  {
    string[q] = s1[q];
  }

  length = (int)strlen(s1);
}

void String::SetConstString(const char* s1)
{
  if (s1 == nullptr) throw "Error!!!";

  if (string != nullptr) delete[] string;
  string = new char[strlen(s1) + 1];
  string[strlen(s1)] = '\0';

  for (int q = 0; q < strlen(s1); q++)
  {
    string[q] = s1[q];
  }

  length = (int)strlen(s1);
}

String String::operator+(String& value)
{
  int tlen = length + value.length;
  String total(tlen, 0);

  for (int i = 0; i < length; i++)
    total.string[i] = string[i];

  for (int i = length; i < tlen; i++)
    total.string[i] = value.string[i - length];

  string[tlen] = '\0';
  return total;
}

String String::operator=(const String& value)
{
  if (string != nullptr)
  {
    delete[] string;
    string = nullptr;
  }

  length = value.length;
  string = new char[length + 1];

  for (int i = 0; i < length; i++)
    string[i] = value.string[i];

  string[length] = '\0';

  return *this;
}

bool String::operator == (String& value)
{
  if (length == value.length)
  {
    for (int i = 0; i < length; i++)
      if (string[i] == value.string[i])
      {
      }
      else
        return false;

    return true;
  }
  return false;
}

bool String::operator<(const String& value)
{
  if (length < value.length)
  {
    return true;
  }
  else
    if (length > value.length)
    {
      return false;
    }
    else
    {
      for (int i = 0; i < length; i++)
      {
        if (string[i] < value.string[i])
        {
          return true;
        }
        else
          if (string[i] > value.string[i])
            return false;
      }
    }
  return false;
}

bool String::operator>(const String& value)
{
  if (length > value.length)
  {
    return true;
  }
  else
    if (length < value.length)
    {
      return false;
    }
    else
    {
      for (int i = 0; i < length; i++)
      {
        if (string[i] > value.string[i])
        {
          return true;
        }
        else
          if (string[i] < value.string[i])
            return false;
      }
    }
  return false;
}

char String::operator[](int i)
{
  if ((i >= 0) && (i <= length))
  {
    return string[i];
  }
  else
  {
    throw ("Error");
  }
}

int String::FindWord(const char* str)
{
  int lp = strlen(str);
  bool f;

  for (int i = 0; i <= length - lp; i++)
  {
    f = true;

    if (string[i] == str[0])
    {
      for (int j = 1; j < lp; j++)
      {
        if (string[i + j] == str[j])
        {
          f = true;
        }
        else
        {
          f = false;
          break;
        }
      }

      if (f == true)
      {
        return i + 1;
      }
    }
  }

  return -1;
}

int String::FindSymbol(char c)
{
  if (string == nullptr)
    return -1;
  for (int i = 0; i < length; i++)
    if (string[i] == c)
      return i;

  return -1;
}

void String::SplitWord(char c)
{
  for (int i = 0; i < strlen(string); i++)
  {
    if (string[i] != c)
    {
      cout << string[i];
    }

    else
      cout << '\n';
  }
}


ostream& operator<<(ostream& ostr, const String& value)
{
  value.string[value.length] = '\0';
  ostr << value.string;
  return ostr;
}

istream& operator>>(istream& istr, String& value)
{
  value.string = nullptr;

  char* tot = new char[1024];
  istr >> tot;

  String a(strlen(tot), ' ');

  for (int i = 0; i < strlen(tot); i++)
    a.string[i] = tot[i];

  value = a;

  return istr;
}