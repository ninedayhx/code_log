// tag: 数学题
// 题目说明：给定三角形的三条边，求在三角形中能构造的
//         最大正方形的边长
#include <bits/stdc++.h>
using namespace std;

double calSquareSide(double area, double trag_side)
{
    double h = area * 2.0 / trag_side;
    return h * trag_side / (h + trag_side);
    // 这个公式怎么来的呢
    // 认为最大正方形的边在该边上，边长设为x,然后正方形会与该边组成一个梯形
    // 再从该边延伸一个该边的高度h，做一个辅助梯形，辅助梯形与前一个梯形相似
    // 即 h/x = (h+c)/c
    // 所以边长x=h*c/(h+c)
}

int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    double s = (a + b + c) / 2.0;
    // 海伦公式求解三角形面积
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    // 分别求解每一条边的上能构造的正方形边长的最大值
    double side_a = calSquareSide(area, a);
    double side_b = calSquareSide(area, b);
    double side_c = calSquareSide(area, c);
    double max_side = max(side_a, side_b);
    max_side = max(max_side, side_c);
    cout << fixed << setprecision(6) << max_side << endl;
}