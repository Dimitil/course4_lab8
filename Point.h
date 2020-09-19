#pragma once
#include <iostream>

class Point {
	int m_x;
	int m_y;

public:
	Point(int x, int y) : m_x(x), m_y(y) { }

	Point() : m_x(0), m_y(0) { }

	int getX() const { return m_x; }

	int getY() const { return m_y; }

	bool operator<(const Point& other)
	{
		return m_x * m_y < other.m_x * other.m_y;
	}

	bool operator==(const Point& other) 
	{
		return (m_x == other.m_x) && (m_y == other.m_y);
	}

	friend std::ostream& operator<<(std::ostream& out, const Point& p)
	{
		out << '{' << p.m_x << ", " << p.m_y << "}";
		return out;
	}

	friend bool operator==(const Point& a, const Point& b)
	{
		return (a.m_x == b.m_x) && (a.m_y == b.m_y);
	}
};

