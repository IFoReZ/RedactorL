#include <iostream>
#include "String.h"

String::String()
{
  len = 1;
  str = new char[1] {'\0'};
}

String::String(const String& p) : len(p.len), str(new char[p.len + 1])
{
  std::copy(p.str, p.str + len + 1, str);
}

String::String(String&& p) : len(p.len), str(p.str)
{
  p.str = nullptr;
  p.len = 0;
}

String::String(char* str_, int len_) : len(len_)
{
  if (len_ <= 0)
    throw std::invalid_argument("Error! Length < 1");

  str = new char[len + 1];
  std::copy(str_, str_ + len, str);
  str[len] = '\0';
}

String::String(const char* str_)
{
  if (!str_)
    throw std::invalid_argument("Error! Null pointer");

  len = strlen(str_);
  str = new char[len + 1];
  std::copy(str_, str_ + len + 1, str);
}

String::~String()
{
  if (str != nullptr)
    delete[] str;
  str = nullptr;
}

const char* String::GetStr() const
{
  return str;
}

int String::GetLen() const
{
  return len;
}

void String::SetStr(const char* str_)
{
  int len_ = strlen(str_);
  char* new_str = new char[len_ + 1];
  strcpy(new_str, str_);
  delete[] str;
  str = new_str;
  len = len_;
}

void String::SetLen(int len_)
{
  if (len_ < 0)
    len_ = 0;

  if (len_ == len)
    return;

  char* new_str = new char[len_ + 1];
  int copy_len = (len_ > len) ? len : len_;

  if (str != nullptr)
  {
    strncpy(new_str, str, copy_len);
    new_str[copy_len] = '\0';
  }
  else
  {
    new_str[0] = '\0';
  }

  delete[] str;
  str = new_str;
  len = len_;
}

int String::FindSb(const String& substring) const
{
  const char* main_str = GetStr();
  const char* sub_str = substring.GetStr();
  int main_len = GetLen();
  int sub_len = substring.GetLen();

  if (sub_len == 0)
    return 0;

  if (main_len < sub_len)
    return -1;

  for (int i = 0; i <= main_len - sub_len; ++i)
  {
    bool found = true;
    for (int j = 0; j < sub_len; ++j)
    {
      if (main_str[i + j] != sub_str[j])
      {
        found = false;
        break;
      }
    }
    if (found)
      return i;
  }
  return -1;
}


String String::Substring(size_t start, size_t count) const
{
  if (start >= len)
    throw std::out_of_range("Error! Start index >= lenght");

  size_t actual_count = std::min(count, len - start);

  String res;

  res.len = actual_count;
  res.str = new char[actual_count + 1];

  std::copy(str + start, str + start + actual_count, res.str);
  res.str[actual_count] = '\0';

  return res;
}

String String::operator+ (const String& p) const
{
  String res;

  res.len = this->len + p.len;
  res.str = new char[res.len + 1];

  if (this->str)
    std::copy(this->str, this->str + this->len, res.str);

  if (p.str)
    std::copy(p.str, p.str + p.len + 1, res.str + this->len);

  return res;
}


String String::operator* (int n) const
{
  if (n <= 0)
  {
    return String();
  }

  String res;

  res.len = len * n;
  res.str = new char[res.len + 1];

  for (int i = 0; i < n; ++i)
  {
    std::copy(str, str + len, res.str + i * len);
  }

  res.str[res.len] = '\0';

  return res;
}


String& String::operator=(const String& p)
{
  if (this != &p)
  {
    delete[] str;
    len = p.len;
    str = new char[len + 1];
    std::copy(p.str, p.str + len + 1, str);
  }

  return *this;
}

bool String::operator==(const String& p) const
{
  if (len != p.len)
    return false;

  return std::equal(str, str + len, p.str);
}

char& String::operator[](size_t i)
{
  if (i >= len)
    throw std::out_of_range("Error! Index out of range");

  return str[i];
}

const char& String::operator[](size_t i) const
{
  if (i >= len)
    throw std::out_of_range("Error! Index out of range");

  return str[i];
}

std::ostream& operator<<(std::ostream& o, const String& str)
{
  o << str.GetStr();
  return o;
}

std::istream& operator>>(std::istream& i, String& str)
{
  char buff[1024];
  if (i >> buff)
  {
    str.SetStr(buff);
  }
  return i;
}