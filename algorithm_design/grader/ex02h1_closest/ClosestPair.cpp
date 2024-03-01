#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

struct Point {int x, y;};
bool compareX(const Point& a, const Point& b) {return a.x < b.x;}
bool compareY(const Point& a, const Point& b) {return a.y < b.y;}

// Change the return type to long long for squared distances
long long calculateDistanceSquared(const Point& a, const Point& b) {
    return 1LL * (a.x - b.x) * (a.x - b.x) + 1LL * (a.y - b.y) * (a.y - b.y);
}

// Change the return type to long long for squared distances
long long bruteForce(const vector<Point>& points, int left, int right) {
    long long minDistanceSquared = LLONG_MAX;

    for (int i = left; i < right; ++i) {
        for (int j = i + 1; j < right; ++j) {
            minDistanceSquared = min(minDistanceSquared, calculateDistanceSquared(points[i], points[j]));
        }
    }

    return minDistanceSquared;
}

// Change the return type to long long for squared distances
long long closestPairUtil(const vector<Point>& pointsX, const vector<Point>& pointsY, int left, int right) {
    if (right - left <= 3) {
        return bruteForce(pointsX, left, right);
    }

    int mid = (left + right) / 2;
    long long leftMin = closestPairUtil(pointsX, pointsY, left, mid);
    long long rightMin = closestPairUtil(pointsX, pointsY, mid, right);
    long long minDistanceSquared = min(leftMin, rightMin);

    vector<Point> strip;
    for (int i = left; i < right; ++i) {
        if (abs(pointsY[i].x - pointsX[mid].x) < minDistanceSquared) {
            strip.push_back(pointsY[i]);
        }
    }

    sort(strip.begin(), strip.end(), compareY);

    for (size_t i = 0; i < strip.size(); ++i) {
        for (size_t j = i + 1; j < strip.size() && 1LL * (strip[j].y - strip[i].y) * (strip[j].y - strip[i].y) < minDistanceSquared; ++j) {
            minDistanceSquared = min(minDistanceSquared, calculateDistanceSquared(strip[i], strip[j]));
        }
    }

    return minDistanceSquared;
}

// Change the return type to long long for squared distances
long long closestPair(const vector<Point>& points) {
    vector<Point> pointsX = points;
    vector<Point> pointsY = points;

    sort(pointsX.begin(), pointsX.end(), compareX);
    sort(pointsY.begin(), pointsY.end(), compareY);

    return closestPairUtil(pointsX, pointsY, 0, points.size());
}

int main() {
    int N;
    cin >> N;

    vector<Point> points(N);

    for (int i = 0; i < N; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    // Use long long for squared distances and result
    long long result = closestPair(points);

    cout << result << endl;

    return 0;
}
