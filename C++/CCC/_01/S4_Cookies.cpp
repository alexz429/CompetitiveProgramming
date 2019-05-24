#include <iostream>
#include <bits/stdc++.h>

class point
{
public:
    int x;
    int y;
    point(int a, int b)
    {
        x = a;
        y = b;
    }
};
double circle(point x, point y, point z)
{
    double a = sqrt(pow(abs(x.x - y.x), 2) + pow(abs(x.y - y.y), 2));
    double b = sqrt(pow(abs(x.x - z.x), 2) + pow(abs(x.y - z.y), 2));
    double c = sqrt(pow(abs(z.x - y.x), 2) + pow(abs(z.y - y.y), 2));
    // printf("%f %f %f\n", a, c, b);
    double radius;
    if ((a * a + b * b - c * c < 0) || (b * b + c * c - a * a < 0) || (c * c + a * a - b * b < 0))
    {
        radius = std::max(std::max(a, b), c);
    }
    else
    {
        radius = (2*a * b * c) / (sqrt((a + b + c) * (b + c - a) * (c + a - b) * (a + b - c)));
    }

    return radius;
}

int main()
{
    int max;
    scanf("%d", &max);
    std::vector<point> things;
    for (int count = 0; count < max; count++)
    {
        // printf("go %d", max);
        int x, y;
        scanf("%d %d", &x, &y);

        things.push_back(point(x, y));
    }
    double best = 0;
    // printf("run");
    for (int count = 0; count < max; count++)
    {
        for (int count2 = 1; count2 < max; count2++)
        {
            for (int count3 = 2; count3 < max; count3++)
            {
                if (count == count2 || count2 == count3 || count3 == count)
                    continue;
                best = std::max(circle(things[count], things[count2], things[count3]), best);
            }
        }
    }
    printf("%.2f", best);
}