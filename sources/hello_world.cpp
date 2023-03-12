#include <iostream>

int main(){

char name[50];
//ввод имени пользователя
std::cout << "input name: "; cin >> name;
//вывод строки с именем
cout << "\nHello world from " << name;

return 0;
}
