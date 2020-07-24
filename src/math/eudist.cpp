double eudist(P a, P b) {
	double res = abs(a.first - b.first) * abs(a.first - b.first) + abs(a.second - b.second) * abs(a.second - b.second);
	return sqrt(res);
}
double eudist(double x1, double y1, double x2, double y2) {
	double res = abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2);
	return sqrt(res);
}