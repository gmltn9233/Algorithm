#include <iostream>
#include <algorithm>
using namespace std;

int h, w;
int a[501];
int left_max[501], right_max[501];

int main()
{
    cin >> h >> w;
    for (int i = 0; i < w; i++)
        cin >> a[i];

    left_max[0] = a[0];
    for (int i = 1; i < w; i++)
        left_max[i] = max(left_max[i - 1], a[i]);

    right_max[w - 1] = a[w - 1];
    for (int i = w - 2; i >= 0; i--)
        right_max[i] = max(right_max[i + 1], a[i]);

    int answer = 0;
    for (int i = 1; i < w - 1; i++)
    {
        int water = min(left_max[i], right_max[i]) - a[i];
        if (water > 0)
            answer += water;
    }

    cout << answer;
    return 0;
}