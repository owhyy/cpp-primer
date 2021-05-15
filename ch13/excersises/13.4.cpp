

struct Point {

  Point();
  Point(const Point &);

private:
  int x;
  int y;
};

Point::Point(const Point &orig) : x(orig.x), y(orig.y) {}

Point global;
Point foo_bar(Point arg) // 1
{
  Point local = arg,
        *heap = new Point(global); // 2 where local = arg and heap = new...
  *heap = local;                   // ???
  Point pa[4] = {local, *heap};    // 3
  return *heap;                    // 4
}
