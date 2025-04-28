#pragma once
#include <iostream>

class String
{
protected:
  char* str;
  int len;
public:
  String();
  String(const String& p);
  String(String&& p);
  String(char* str_, int len_);
  String(const char* str_);
  ~String();

  const char* GetStr() const;
  int GetLen() const;

  void SetStr(const char* str_);
  void SetLen(int len_);

  int FindSb(const String& substring) const;

  String Substring(size_t start, size_t count = -1) const;

  String operator+ (const String& other) const;
  String operator* (int count) const;
  String& operator= (const String& p);
  bool operator== (const String& p) const;
  char& operator[] (size_t i);
  const char& operator[] (size_t i) const;


  friend std::ostream& operator<<(std::ostream& o, const String& str);
  friend std::istream& operator>>(std::istream& i, String& str);
};
