// ConsoleApplication6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;
void print(int arr[])
{
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int _array[6] = { 0,1,2,3,4,5 };
    int _array2[6] = { 2,6,7,8,9,0 };
    int n = 6;
    _asm {
        cld;
        mov ecx, n;//кол-во элементов
        lea esi, _array;
        lea edi, _array2;
        mov ecx, 6
            rep movs _array2, _array;
        lea eax, _array2;
        push eax;
        call print;
        pop eax;
        lea eax, _array;
        push eax;
        call print;
        pop eax;
    }
}
