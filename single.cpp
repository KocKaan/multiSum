#include <iostream>
#include <vector>
#include <chrono>

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
    auto start = chrono::system_clock::now();

    vector<int> vect = {1, 5, 7, 10, 12, 14, 15, 18, 20, 22, 25, 27, 30, 64, 110, 220};

    int result = sum(vect);
    chrono::duration<double> dur = chrono::system_clock::now() - start;
    cout << "Time for addition " << dur.count() << " seconds" << endl;

    cout << result << endl;
}
