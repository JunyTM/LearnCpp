#include <bits/stdc++.h>

using namespace std;

void sort(int *a, int num)
{
    for (int i = 1; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (a[i] < a[j])
            {
                a[i] += a[j];
                a[j] = a[i] - a[j];
                a[i] -= a[j];
            }
        }
    }
}

int minSum(int *a, int num)
{
    int sum = a[0] + a[1] + a[2];
    for (int i = 3; i < num; i++)
    {
        if (a[i] < 0)
            sum += a[i];
    }
    return sum;
}

int main()
{
    sort(a, num);
    cout << minSum(a, num);
}