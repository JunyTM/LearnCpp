#include <bits/stdc++.h>

using namespace std;

void change(int *a, int n)
{
    int cache = a[0];
    for (int i = 0; i < n; i++)
    {
        a[i] = a[i + 1];
    }
    a[n - 1] = cache;
}

int m_Sum(int *a, int n)
{
    int lenght = n;
    int minSum = INT_MAX;
    while (lenght > 0)
    {
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 2; j < n; j++)
            {
                int sum = 0;
                for (int k = i; k <= j; k++)
                {
                    sum += a[k];
                }
                minSum = min(minSum, sum);
            }
        }
        change(a, n);
        lenght--;
    }
    return minSum;
}

int main()
{
    int num = 100;
    int a[num] = {-273,-261,-916,-388,143,-878,-794,-134,596,-447,
-722,-485,-33,439,-286,-84,-924,0,-903,-676,
609,-645,-870,-862,-258,888,640,-570,587,-421,
625,-134,-31,714,-161,-194,-834,-122,-919,-541,
-217,-757,-781,281,956,-779,-354,-872,-928,-561,
-36,-293,-483,130,-189,356,-262,-916,-760,-323,
-88,-146,-481,-410,260,-497,-95,-896,-833,-66,
-381,-829,-234,-202,-701,807,-768,-19,497,252,
-553,-751,-857,-640,-904,-538,-992,-777,-592,-786,
-157,-190,-607,-60,-707,-380,247,659,-14,-560};
    // cin>>num;
    // for (int i = 0; i < num; i++)
    // {
    //     cin>>a[i];
    // }
    cout << m_Sum(a, num);
}