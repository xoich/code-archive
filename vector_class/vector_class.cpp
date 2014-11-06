#include <iostream>
#include <cmath>

struct Vector{
	Vector() : x(0), y(0) { };
	Vector(int a, int b) : x(a), y(b) { }
	friend Vector operator+(const Vector, const Vector);
	friend std::istream& operator>>(std::istream&, Vector&);
	friend std::ostream& operator<<(std::ostream&, const Vector&);
	double length() const { return sqrt(pow(x,2) + pow(y,2)); }
	
private:
	int x;
	int y;
};

Vector operator+(const Vector a,const Vector b) {
	return Vector(a.x + b.x, a.y + b.y);
}

std::ostream& operator<<(std::ostream& out, const Vector& vec) {
	out << "(" << vec.x << "," << vec.y << ")"; 
	return out;
}

bool operator==(const Vector& a, const Vector& b) {
	return a.length() == b.length();
}

std::istream& operator>>(std::istream& i, Vector& vec) {
	i >> vec.x >> vec.y;
	if (!i)
		vec = Vector();
	return i;
}


main() {
	Vector a(1,2);
	Vector b(-1,2);
	Vector c = (a + b);
	std::cin >> b;
	std::cout << b;
	
}
	
