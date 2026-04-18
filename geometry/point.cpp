struct Point {
    double x, y;
    Point(double x = 0, double y = 0): x(x), y(y) {}
    Point operator +(Point p) {
        return Point(x + p.x, y + p.y);
    }
    Point operator -(Point p) {
        return Point(x - p.x, y - p.y);
    }
    double abs() {
        return sqrt(x * x + y * y);
    }
    double dot(Point p) {
        return x * p.x + y * p.y;
    }
    double cross(Point p) {
        return x * p.y - y * p.x;
    }
};
