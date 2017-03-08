#include <math.h>
#include <algorithm>
#include "triangle.h"

TriangleType CheckTriangleType(int a, int b, int c)
{
    int arr[3] = {a, b, c};

    for (const int &val : arr)
        if (val <= 0 || val > 200)
            return TRIANGLE_INVALID;

    if (a + b <= c)
        return TRIANGLE_INVALID;
    if (b + c <= a)
        return TRIANGLE_INVALID;
    if (c + a <= b)
        return TRIANGLE_INVALID;

    if (a == b && b == c)
        return TRIANGLE_EQUALATERAL;

    std::sort(arr, arr + 3);
    
    if (pow(arr[0], 2) + pow(arr[1], 2) == pow(arr[2], 2))
        return TRIANGLE_RIGHTTRIANGLE;

    if (arr[0] != arr[1] && arr[1] == arr[2])
        return TRIANGLE_ISOSCELES;

    return TRIANGLE_SCALENE;
}
