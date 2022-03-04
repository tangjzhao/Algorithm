#include<cstdio>

double a, b, c, d;
int count = 0;
double f(double x) {
	double ans = a * x * x * x + b * x * x + c * x + d;
	return ans;
}
void BinarySearch(double start, double end) {
	double mid = 0, tmp;
	while (start < end - 0.001) {
		mid = start + (end - start) / 2;
		tmp = f(mid);
		if (tmp == 0) {
			printf("%.2f ", mid);
			count++;
			return;
		}
		else if (tmp * f(start) < 0)
			end = mid;
		else start = mid;
	}
	printf("%.2f ", start);
}
int main()
{
	double l, r, i;
	scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
	for (i = -100; i <= 100; i++) {
		l = i;
		r = l + 1;
		if (f(l) == 0) {
			printf("%.2f ", l);
			count++;
		}
		else if (f(l) * f(r) < 0)
			BinarySearch(l, r);
		if (count == 3)
			return 0;
	}
	return 0;
}