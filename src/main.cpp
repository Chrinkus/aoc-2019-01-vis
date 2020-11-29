#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Group.H>
#include <FL/fl_draw.H>
#include <cmath>

#include <iostream>

class Viewport : public Fl_Group {
private:
    double vp_angle = 0;
    static constexpr double FRAME_S = 1.0 / 60.0;

public:
    Viewport(int xx, int yy, int ww, int hh, const char* ll = 0)
        : Fl_Group{xx, yy, ww, hh, ll}
    {
        box(FL_UP_BOX);
        color(FL_BLACK);
        Fl::add_timeout(FRAME_S, timer_cb, static_cast<void*>(this));
    }

    void draw() override
    {
        Fl_Group::draw();

        fl_push_matrix();
        fl_translate(w() / 2, h() / 2);
        fl_rotate(vp_angle);

        fl_color(FL_GREEN);
        fl_begin_polygon();
        fl_vertex(-60, -60);
        fl_vertex(60, -60);
        fl_vertex(60, 60);
        fl_vertex(-60, 60);
        fl_end_polygon();

        fl_pop_matrix();
        increment_angle(2.0);
    }

private:
    void increment_angle(double delta)
    {
        vp_angle = std::fmod(vp_angle + delta, 360.0); 
    }

    static void timer_cb(void* userdata)
    {
        auto p = static_cast<Viewport*>(userdata);
        p->redraw();
        Fl::repeat_timeout(FRAME_S, timer_cb, userdata);
    }
};

int main(int argc, char* argv[])
{
    auto win = new Fl_Double_Window{600, 400, "AOC 2019 Day 1"};
    auto vp  = new Viewport{0, 0, win->w(), win->h()};
    win->end();
    win->show(argc, argv);
    return Fl::run();
}