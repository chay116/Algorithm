#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
class Rectangle
{
	public:
		int _x; int _y;	int _w;	int _h;

		Rectangle(void) : _x(0), _y(0), _w(0), _h(0) {};
		Rectangle(float x, float y, float w, float h) : _x(x), _y(y), _w(w), _h(h) {};
		void	set(float x, float y, float w, float h)
		{
			_x = x; _y = y;	_w = w;	_h = h;
		};
		bool	contains(target_x, target_y)
		{
			return (target_x >= this->_x && target_x < this->_x + this->_w &&
					target_y >= this->_y && target_y < this->_y + this->_h);
		}
};

class QuadTree
{
	public:
		QuadTree(int capacity, Rectangle boundary)
		: _capacity(capacity), _next(0), _divided(false), _boundary(boundary)
		{
			_points = new Circle[capacity];
		};
		QuadTree(int capacity, float x, float y, float w, float h)
		: _capacity(capacity), _next(0), _divided(false)
		{
			_boundary.set(x, y, w, h);
			_points = new Circle[capacity];
		};
		~QuadTree() {};

		void insert(int target_x, int target_y)
		{
			if (!this->_boundary.contains(target_x, target_y))
				return;
			if (this->_next < this->_capacity)
			{
				_points[_next] = target;
				_next++;
			}
			else
			{
				if (!this->_divided)
				{
					this->subdivide();
					this->_divided = true;
				}
				for (int i=0; i < 4; i++)
					(*_child[i]).insert(target_x, target_y);
			}
		};

		void subdivide(void)
		{
			_child[0] = new QuadTree(_capacity, _boundary._x, _boundary._y, _boundary._w/2, _boundary._h/2);
			_child[1] = new QuadTree(_capacity, _boundary._x + _boundary._w/2, _boundary._y, _boundary._w/2, _boundary._h/2);
			_child[2] = new QuadTree(_capacity, _boundary._x, _boundary._y + _boundary._h/2, _boundary._w/2, _boundary._h/2);
			_child[3] = new QuadTree(_capacity, _boundary._x + _boundary._w/2, _boundary._y + _boundary._h/2, _boundary._w/2, _boundary._h/2);
		}

		void print(void)
		{
			std::cout	<< "boundary x : " << _boundary._x
						<< " y : " << _boundary._y
						<< " w : " << _boundary._w
						<< " h : " << _boundary._h << "\n";
			for (int i=0; i < _next; i++)
			{
				std::cout	<< "bullets x : " << _points[i]._x
							<< " y : " << _points[i]._y
							<< " r : " << _points[i]._r << "\n";
			}
			std::cout << std::endl;
			if (this->_divided)
			{
				for (int i=0; i < 4; i++)
					(*(_child[i])).print();
			}
		}

	private:
		bool		_divided;
		Rectangle	_boundary;
		int			_capacity;
		int			_next;
		int			*x_points;
		int			*y_points;
		QuadTree	*_child[4]; // southwest, southeast, northwest, northeast
};


int main() {
	fastio;
	int N, x, y, tmp; cin >> N;
	QuadTree board(0, 0, 10000, 10000);

	for (int i=0; i < N; i++)
	{
		cin >> x >> y;
		Map.insert(bullets[i]);
	}
	Map.print();
}
