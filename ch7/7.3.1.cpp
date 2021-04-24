#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
using std::string;
using std::vector;

class Screen
{
    friend class Window_mgr;

public:
    Screen &display(ostream &os)
    {
        do_display(os);
        return *this;
    }
    const Screen &display(ostream &os) const
    {
        os << content;
        return *this;
    }
    Screen &move(int, int);
    Screen &set(int, int, char);
    Screen &set(char);
    Screen() = default;
    Screen(int x, int y) : x(x), y(y){};
    Screen(int x, int y, char c) : x(x), y(y), content(x * y, c){};

private:
    int x{0};
    int y{0};
    int cursor{0};
    string content;
    void do_display(ostream &os) { os << content; };
};
class Window_mgr
{
    void clear(int);

private:
    vector<Screen> screens{(80, 24, ' ')};
};
void Window_mgr::clear(int i)
{
    Screen &s = screens[i];
    s.content = string(s.x * s.y, ' ');
}
Screen &Screen::move(int r, int c)
{
    cursor = x * r + c;
    return *this;
}
Screen &Screen::set(int r, int c, char ch)
{
    content[r * x + c] = ch;
    return *this;
}
Screen &Screen::set(char ch)
{
    content[cursor] = ch;
    return *this;
}
int main()
{
    Screen MyScren(5, 5, 'X');
    MyScren.move(4, 0).set('#').display(cout);
    return 0;
}