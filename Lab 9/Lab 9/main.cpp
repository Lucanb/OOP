#include <iostream>
#include <stdio.h>
#include <functional>
#include "Iterrator.h"
#include "Node.h"
#include "Node.cpp"
#include "List.h"
#include "List.cpp"
#include "Map.h"
#include "Map.cpp"

using namespace std;



int main()
{
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[20] = "Previous one is deleted";
    m[30] = "Poo";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    m.Delete(20);

    cout << "\n" << m.Get(10, "Java") << "\n";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }


    m.Clear();
    cout << "Map Cleared\n";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    m.Clear();
    return 0;
}
