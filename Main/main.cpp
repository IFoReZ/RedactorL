#include <iostream>
#include <string>
#include "String.h"
#include "Window.h"

int main()
{
  system("chcp 65001 > nul");
  system("cls");

  int cordX, cordY, fieldLen;

  std::cout << "Enter coordinate of X (-1 < X < 51): ";
  std::cin >> cordX;

  while (cordX > 50 and cordX < 0)
  {
    system("cls");
    std::cout << "Wrong coordinate of X! Try again.\n";
    std::cout << "Enter coordinate of X (-1 < X < 51): ";
    std::cin >> cordX;

  }

  std::cout << "Enter coordinate of Y (-1 < Y < 26): ";
  std::cin >> cordY;

  while (cordY > 25 and cordY < 0)
  {
    system("cls");
    std::cout << "Wrong coordinate of Y! Try again.\n";
    std::cout << "Enter coordinate of Y (-1 < Y < 26): ";
    std::cin >> cordY;

  }

  std::cout << "Enter lenght of input field (0 < lenght < 51): ";
  std::cin >> fieldLen;

  while (fieldLen > 50 and fieldLen < 1)
  {
    system("cls");
    std::cout << "Wrong lenght of input field! Try again.\n";
    std::cout << "Enter lenght of input field (0 < lenght < 51): ";
    std::cin >> fieldLen;

  }

  system("cls");

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  std::string result = InputStr(cordX, cordY, fieldLen);

  SetCursPos(0, cordY + 2);

  std::cout << "Your string is: " << result << std::endl;

  return 0;
}