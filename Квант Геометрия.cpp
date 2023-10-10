Квант Геометрия


x1(n), y1(n)

c++
struct point
{
	int x = 0;
	int y = 0;
	//int x,y;
}

python 
class point:
	x = 0, y = 0

point A;
A = point()




прямая
line create_line(point p1, point p2)
{
    a = p2.y - p1.y;
    b = p1.x - p2.x;
    c = -a * p2.x - b * p2.y;
}

struct line
{
    double a, b, c;

    line(point p1, point p2)
	{
	    a = p2.y - p1.y;
	    b = p1.x - p2.x;
	    c = -a * p2.x - b * p2.y;
	}

    void norm()
    {
        double d = sqrt(a*a + b*b);
        a /= d; b /= d; c /= d;
    }

    ld dist(point p)
    {
        norm();
        return abs(a*p.x+b*p.y+c);
    }

    point projection(point p)
    {
        ld d = dist(p);
        return point(p.x + a * d, p.y + b * d);
    }
};




line A = create_line(point(3,5), point(6,4))
A = line(point(3,5), point(6,4))

A.a
A.b
A.c
в структуре - метод
A.norm()
вне структуры
B = norm(A)





векторное произведение
int dotproduct(point a, point b)
{
    return a.x * b.x + a.y * b.y;
}

скалярное произведение
int crossproduct(point a, point b)
{
    return a.x * b.y - b.x * a.y;
}

ld areatriangle(point a, point b, point c) 
{
    //return abs(crossproduct((a - c), (b - c)) / 2.0);
    return (a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y)u7 / 2.0;
}

sqrt((p - a) * (p - b) * (p - c) * p)
p - полупериметр


bool intersect_1(int a, int b, int c, int d)
{
	if (a > b) swap(a, b) py a, b = b, a
	if (c > d) swap(c, d) py c, d = d, a
	return max(a, c) <= min(b, d)
}

bool intersect(point a, point b, point c, point d)
{
	return intersect_1(a.x, b.x, c.x, d.x) and 
		   intersect_1(a.y, b.y, c.y, d.y) and
		   areatriangle(a, b, c) * areatriangle(a, b, d) <= 0 and
		   areatriangle(c, d, a) * areatriangle(c, d, b) <= 0 
} 


const double EPS = 1e-9

double det(double a, double b, double c, double d)
	return a * d - b * c

bool intersect(line m, line n, point res)
	double zn = det(m.a, m.b, n.a, n.b)
	if abs(zn) < EPS
		return false

	res.x = - det(m.c, m.b, n.c, n.b) / zn
	res.y = - det(m.a, m.c, n.a, n.c) / zn
	return true
	передать res

bool parallel (line n, line m)
	return abs(det(m.a, m.b, n.a, n.b)) < EPS

bool equiv (line n, line m)
	return abs(det(m.a, m.b, n.a, n.b)) < EPS and
		   abs(det(m.a, m.c, n.a, n.c)) < EPS and
		   abs(det(m.b, m.c, n.b, n.c)) < EPS



точка пересечения отрезков
bool betw(double l, double r, double x)
	return min(l, r) <= x + EPS and
		   x <= max(l, r) + EPS

bool intersect_1(double a, double b, double c, double d)
{
	if (a > b) swap(a, b) py a, b = b, a
	if (c > d) swap(c, d) py c, d = d, a
	return max(a, c) <= min(b, d)
}

bool less(point a, point b)
	return a.x < b.x or (a.x == b.x and a.y < b.y) 
	слева направо, снизу вверх

	return atan2(a.y, a.x) < atan2(b.y, b.x) по полярному углу

примеры
a.sort(key = less)
sort(a.begin(), a.end(), less)

bool intersect2(point a, point b, point c, point d)
	if (not intersect_1(a.x, b.x, c.x, d.x)) and 
		not intersect_1(a.y, b.y, c.y, d.y))
		return false

	line m (a, b)
	line n (c, d)

	double zn = det(m.a, m.b, n.a, n.c)
	if (abs(zn) < EPS)
		if (abs(m.dist(c)) > EPS or abs(n.dist(a)) > EPS)
			return false

		if (less(b, a)) swap(a, b) py a, b = b, a
		if (less(d, c)) swap(c, d) py c, d = d, a
		left  = max(a, c)
		right = min(b, d)
		вернуть left, right
		return true
	else
		left.x = right.x = - det(m.c, m.b, n.c, n.b) / zn
		left.y = right.y = - det(m.a, m.c, n.a, n.c) / zn		
		вернуть left, right
		return betw(a.x, b.x, left.x) and
			   betw(a.y, b.y, left.y) and
			   betw(c.x, d.x, left.x) and
			   betw(c.y, d.y, left.y)




площадь многоугольника
1. координаты были заданы в порядке обхода
a.sort(key=less)

point pt(n)
point O
O.x = O.y = 0
S = 0
for i = 1..n - 1
	S += areatriangle(O, pt[i], pt[i + 1])

S += areatriangle(O, pt[n], pt[1])