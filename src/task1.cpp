
#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#define ARRAYSIZE 7
using namespace std;

void fillArray(string* array)
{
    array[0] = "Ivanov";
    array[1] = "Petrov";
    array[2] = "Chubais";
    array[3] = "Erohin";
    array[4] = "Pivarich";
    array[5] = "Chevapchich";
    array[6] = "Shoha";
}

typedef bool (func)(int a, int b);

void bubbleSort(string* array, int array_size, bool cmp(string a, string b))
{
    for (int i = 0; i < array_size; i++) {
        bool flag = true;
        for (int j = 0; j < array_size - (i + 1); j++) {
            if (cmp(array[j], array[j + 1])) {
                flag = false;
                swap(array[j], array[j + 1]);
            }
        }
        if (flag) {
            break;
        }
    }

    for (int i = 0; i < array_size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int main() {    

    string* array = new string[ARRAYSIZE];
    fillArray(array);

    cout << "a < b" << endl;
    bubbleSort(array, ARRAYSIZE, [](string a, string b) { return a < b; });
    cout << "a > b" << endl;
    bubbleSort(array, ARRAYSIZE, [](string a, string b) { return a > b; });
    cout << "a != b" << endl;
    bubbleSort(array, ARRAYSIZE, [](string a, string b) { return a != b; });
    cout << "a[0] > b[0]" << endl;
    bubbleSort(array, ARRAYSIZE, [](string a, string b) { return a[0] > b[0];});
    cout << "a.size() < b.size()" << endl;
    bubbleSort(array, ARRAYSIZE, [](string a, string b) {  return a.size() > b.size();});
   
    return 0;
}
