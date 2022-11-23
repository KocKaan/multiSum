#include <iostream>
#include <vector>
using namespace std;

int sum(const vector<int> &arr)
{

    int counter = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        counter += arr[i];
    }

    return counter;
}

int main()
{
    cout << "Hello World" << endl;

    vector<int> vect = {1, 10, 13, 43, 43, 543, 63};

    int result = sum(vect);

    cout << result << endl;
}
