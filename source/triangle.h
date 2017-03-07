#if !defined(TRIANGLE_H_)
#define TRIANGLE_H_

enum TriangleType {
    TRIANGLE_EQUALATERAL, 
    TRIANGLE_ISOSCELES, 
    TRIANGLE_SCALENE, 
    TRIANGLE_RIGHTTRIANGLE, 
    TRIANGLE_INVALID
};

TriangleType CheckTriangleType(int a, int b, int c);

#endif
