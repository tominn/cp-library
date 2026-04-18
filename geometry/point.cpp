struct Point {
    double x, y;
    Point(double x = 0, double y = 0): x(x), y(y) {}
    Point operator +(const Point& p) const {
        return Point(x + p.x, y + p.y);
    }
    Point operator -(const Point& p) const {
        return Point(x - p.x, y - p.y);
    }
    double abs() const {
        return sqrt(x * x + y * y);
    }
    double dot(const Point& p) const {
        return x * p.x + y * p.y;
    }
    double cross(const Point& p) const {
        return x * p.y - y * p.x;
    }
    static bool arg_cmp(const Point& a, const Point& b) {
        auto half = [](const Point& p) {
            return p.y > 0 || (p.y == 0 && p.x > 0);
        };
        if (half(a) != half(b)) return half(a) > half(b);
        return a.cross(b) > 0;
    }
};
