#include <iostream>
#include <vector>
using namespace std;
int firstCircularTour(vector<int> &petrol, vector<int> &distance, int N)
{
    int balance = 0;
    int defecit = 0;
    int start = 0;
    for (int i = 0; i < N; i++)
    {
        balance += petrol[i] - distance[i];
        if (balance < 0)
        {
            defecit += balance;
            start = i + 1;
            balance = 0;
        }
    }

    if (defecit + balance >= 0)
    {
        return start;
    }
    else
    {
        return -1;
    }
}

int main()
{
    vector<int> petrol = {4, 6, 7, 4};
    vector<int> distance = {6, 5, 3, 5};
    int N = petrol.size();
    int ans = firstCircularTour(petrol, distance, N);
    cout << ans << endl;
    return 0;
}