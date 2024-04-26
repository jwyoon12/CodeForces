// CodeForces.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

const double PI = 3.141592;

struct pos {
	double x;
	double y;
};

double distance(pos pillarIndex1, pos pillarIndex2) {
	return sqrt(pow(pillarIndex2.x - pillarIndex1.x, 2) + pow(pillarIndex2.y - pillarIndex1.y, 2));
}

double angle(double a, double b, double c) {
	double cosTheta = (c * c + b * b - a * a) / (2 * c * b);
	return acos(cosTheta);
}

double findSmallestPolygonArea(vector<pos>& points) {
	pos p1 = points[0], p2 = points[1], p3 = points[2];
	double a = distance(p1, p2);
	double b = distance(p2, p3);
	double c = distance(p3, p1);

	double A = angle(a, b, c);
	double B = angle(b, c, a);
	double C = angle(c, a, b);

	double minArea = std::numeric_limits<double>::infinity();

	for (int n = 3; n <= 100; n++)
	{

		double angleN = 2 * PI / n;
		double R = a / (2.0 * sin(A));
		double areaPolygon = 0.5 * n * R * R * sin(A);
		minArea = min(minArea, areaPolygon);
	}
	return minArea;
}

int main() {
	int n = 3;
	vector<pos> inputVec(n);
	
	double x,y;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		inputVec[i].x = x;
		inputVec[i].y = y;
	}
	double result = findSmallestPolygonArea(inputVec);
	cout << fixed << setprecision(6) << result << endl;

	return 0;
}
