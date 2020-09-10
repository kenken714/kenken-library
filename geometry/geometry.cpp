//ok -> verified
using Real = double;
using Pt = complex<Real>;
const Real EPS = 1e-8;

int sgn(Real a){//ok
    return (a < -EPS) ? -1 : (a > EPS) ? 1 : 0;
}
inline Pt operator*= (const Pt &a, const Real &b){
    return Pt(real(a) * b, imag(a) * b);
}

inline Pt operator* (const Pt &a, const Real &b){
    return a *= b;
}

namespace std {
    bool operator<(const Pt &a, const Pt &b){
        return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag();
    }
}

istream &operator>> (istream &is, Pt &p){//ok
    Real a, b;
    is >> a >> b;
    p = Pt(a, b);
    return is;
}

Real dot(const Pt &a, const Pt &b) {//ok
    return real(a) * real(b) + imag(a) * imag(b);
}

Real cross(const Pt &a, const Pt &b){//ok
    return real(a) * imag(b) - real(b) * imag(a);
}

Real arg(const Pt &a){
    return atan2(imag(a), real(a));
}

int ccw(const Pt &a, const Pt &b, const Pt &c){//ok
    if (cross(b - a, c - a) > EPS) return 1; //CCW
    if (cross(b - a, c - a) < -EPS) return -1; //CW
    if (dot(a - b, c - b) < -EPS) return 2; //a-b-c
    if (dot(b - a, c - a) < -EPS) return -2; //c-a-b
    return 0; //a-c-b(on seg)
}

struct Line{//ok
    Pt a, b;
    Line(Pt a, Pt b) : a(a), b(b){};
};

struct Segment : Line{
    Segment(Pt a, Pt b) : Line(a, b){};
};

struct Circle{//ok
    Pt a;
    Real r;
    Circle(Pt a, Real r) : a(a), r(r){};
};

using Polygon = vector<Pt>;

Pt projection(const Line &a, const Pt &p){//ok
    Real t = dot(p - a.a, a.a - a.b) / norm(a.a - a.b);
    return a.a + (a.a - a.b) * t;
}

Pt projection(const Segment &a, const Pt &p){//ok
    Real t = dot(p - a.a, a.a - a.b) / norm(a.a - a.b);
    return a.a + (a.a - a.b) * t;
}

Pt reflection(const Line &a, const Pt &b){//ok
    return b + (projection(a, b) - b) * 2.0;
}

Pt reflection(const Segment &a, const Pt &b){//ok
    return b + (projection(a, b) - b) * 2.0;
}

//平行
bool parallel(const Line &a, const Line &b){
    return !sgn(cross(a.b - a.a, b.b - b.a));
}

//直角
bool orthogonal(const Line &a, const Line &b){
    return !sgn(dot(a.a - a.b, b.a - b.b));
}

bool intersect(const Line &a, const Pt &b){
    return abs(ccw(a.a, a.b, b)) != 1;
}

bool intersect(const Line &a, const Line &b){
    return !parallel(a, b);
}

bool intersect(const Line &a, const Segment &b){
    return cross(a.b - a.a, b.a - a.a) * cross(a.b - a.a, b.b - a.a) < EPS;
}

bool intersect(const Segment &a, const Pt &b){//ok
    return ccw(a.a, a.b, b) == 0;
}

bool intersect(const Segment &a, const Segment &b){//ok
    return (sgn(ccw(a.a, a.b, b.a) * ccw(a.a, a.b, b.b)) <= 0 and
    sgn(ccw(b.a, b.b, a.a) * ccw(b.a, b.b, a.b)) <= 0);
}

Real distance(const Line &a, const Pt &b);

bool intersect(const Circle &a, const Pt &b){
    return sgn(abs(a.a - b) - a.r) == 0;
}

bool intersect(const Circle &a, const Line &b){
    return sgn(distance(b, a.a) - a.r) == -1;
}

int intersect(const Circle &a, const Segment &b){
    if (norm(projection(b, a.a) - a.a) - a.r * a.r > EPS) return 0;
    auto d1 = abs(a.a - b.a), d2 = abs(a.a - b.b);
    if (d1 < a.r + EPS and d2 < a.r + EPS) return 0;
    if (d1 < a.r - EPS and d2 > a.r + EPS or d1 > a.r + EPS and d2 < a.r - EPS) return 1;
    const Pt j = projection(b, a.a);
    if (dot(b.a - j, b.b - j) < 0) return 2;
    return 0;
}

int intersect(Circle a, Circle b){ //共通接線の数 ok
    if (a.r < b.r) swap(a, b);
    Real d = abs(a.a - b.a);
    if (sgn(a.r + b.r - d) == -1) return 4;
    if (sgn(a.r + b.r - d) == 0) return 3;
    if (sgn(a.r - b.r - d) == -1) return 2;
    if (sgn(a.r - b.r - d) == 0) return 1;
    return 0;
}

Real distance(const Pt &a, const Pt &b){
    return abs(a - b);
}

Real distance(const Line &a, const Pt &b){
    return abs(b - projection(a, b));
}

Real distance(const Line &a, const Line &b){
    return intersect(a, b) ? 0 : distance(a, b.a);
}

Real distance(const Line &a, const Segment &b){
    return intersect(a, b) ? 0 : min(distance(a, b.a), distance(a, b.b));
}

Real distance(const Segment &a, const Pt &b){//ok
    Pt p = projection(a, b);
    if (intersect(a, p)) return abs(p - b);
    return min(abs(a.a - b), abs(a.b - b));
}

Real distance(const Segment &a, const Segment &b){//ok
    if (intersect(a, b)) return 0;
    return min({distance(a, b.a), distance(a, b.b),
                distance(b, a.a), distance(b, a.b)});
}

Pt crosspoint(const Line &a, const Line &b){//ok
    return a.a + (a.b - a.a) * cross(b.a - a.a, b.b - b.a) / cross(a.b - a.a, b.b - b.a);
}

Pt crosspoint(const Segment &a, const Segment &b){//ok
    return crosspoint(Line(a), Line(b));
}

pair<Pt, Pt> crosspoint(const Circle &a, const Line &b){//ok
    Pt pt = projection(b, a.a);
    Pt e = (b.b - b.a) / abs(b.b - b.a);
    if (!sgn(distance(b, a.a) - a.r)) return {pt, pt};
    double base = sqrt(a.r * a.r - norm(pt - a.a));
    return {pt - e * base, pt + e * base};
}

pair<Pt, Pt> crosspoint(const Circle &a, const Segment &b){
    Line c = Line(b);
    if (intersect(a, b) == 2) return crosspoint(a, c);
    auto res = crosspoint(a, c);
    if (dot(b.a - res.first, b.b - res.first) < 0) res.second = res.first;
    return res;
}

bool is_convex(const Polygon &p){//ok
    ll sz = p.size();
    REP(i, sz){
        if (ccw(p[(i - 1 + sz) % sz], p[i], p[(i + 1) % sz]) == -1) return false;
    }
    return true;
}

Polygon convex_hull(Polygon &p){//ok
    int n = p.size(), k = 0;
    sort(ALL(p));
    vector<Pt> ch(2 * n);
    for (int i = 0; i < n; ch[k++] = p[i++])
        while (k >= 2 and ccw(ch[k - 2], ch[k - 1], p[i]) <= 0) k--;
    for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = p[i--])
        while (k >= t and ccw(ch[k - 2], ch[k - 1], p[i]) <= 0) k--;
    ch.resize(k - 1);
    return ch;
}