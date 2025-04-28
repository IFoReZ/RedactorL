#include <iostream>
#include "Window.h"
#include <windows.h>
#include <conio.h>

void SetCursPos(int x, int y)
{
  COORD coordinate = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}

std::string InputStr(int x, int y, int maxLen)
{
  std::string in;
  in.reserve(maxLen);

  SetCursPos(x, y);
  std::cout << '[' << std::string(maxLen, ' ') << ']';

  int cursPos = 0;
  SetCursPos(x + 1 + cursPos, y);

  while (true)
  {
    int c = _getch();

    if (c == 13)
    {
      return in;
    }
    else if (c == 8)
    {
      if (cursPos > 0)
      {
        cursPos--;

        in.pop_back();
        SetCursPos(x + 1 + cursPos, y);

        std::cout << ' ';
        SetCursPos(x + 1 + cursPos, y);
      }
    }
    else if (isprint(c) && cursPos < maxLen)
    {
      in += static_cast<char>(c);

      std::cout << static_cast<char>(c);

      cursPos++;
    }
  }
}