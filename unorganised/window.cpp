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
    typedef string::size_type pos;
    pos size() const;
    Screen &display(ostream &os)
    {
        do_display(os);
        return *this;
    }
    const Screen &display(ostream &os) const
    {
        do_display(os);
        return *this;
    }
    Screen &set(char);
    Screen &set(pos, pos, char);
    Screen() = default;
    Screen(pos ht, pos wt, char c) : height(ht), width(wt), contents(ht * wt, c) {}
    char get() const { return contents[cursor]; }
    inline char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);
    
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
    void do_display(ostream &os) const { os << contents; }
};
class Window_mgr
{
public:
    using ScreenIndex = vector<Screen>::size_type;
    void clear(ScreenIndex);

private:
    vector<Screen> screens{Screen(24, 80, ' ')};
};
void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = screens[i];
    s.contents = string(s.height * s.width, ' ');
}
inline Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}
inline Screen &Screen::set(pos r, pos col, char ch)
{
    contents[r * width + col] = ch;
    return *this;
}
inline Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}
char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}
Screen::pos Screen::size() const
{
    return height * width;
}
int main()
{
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << "\n";
    myScreen.display(cout);
    cout << "\n";
    cout << myScreen.size() << endl;
    return 0;
}