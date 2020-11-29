#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>

#include <iostream>

int main(int argc, char* argv[])
{
    auto win = new Fl_Double_Window(600, 400, "AOC 2019 Day 1");
    auto box = new Fl_Box(20, 40, 560, 320, "Hello AOC in FLTK");
    box->box(FL_UP_BOX);
    box->labelfont(FL_BOLD | FL_ITALIC);
    box->labelsize(48);
    box->labeltype(FL_SHADOW_LABEL);
    win->end();
    win->show(argc, argv);
    return Fl::run();
}