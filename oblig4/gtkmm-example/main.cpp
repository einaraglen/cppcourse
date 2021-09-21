#include <gtkmm.h>
#include <iostream>

using namespace std;

class Window : public Gtk::Window {
public:
  Gtk::VBox vbox;
  Gtk::Label fname_label;
  Gtk::Label lname_label;
  Gtk::Entry fname_entry;
  Gtk::Entry lname_entry;
  Gtk::Button button;
  Gtk::Label label;
  string first_name = "";
  string last_name = "";
  bool areEntriesFilled() {
    return first_name != "" && last_name != "";
  }

  Window() {
    button.set_label("Combine Names");
    //default as not enabled
    button.set_sensitive(false);
    fname_label.set_text("First Name");
    lname_label.set_text("Last Name");

    vbox.pack_start(fname_label);
    vbox.pack_start(fname_entry);
    vbox.pack_start(lname_label);
    vbox.pack_start(lname_entry);
    vbox.pack_start(button);
    vbox.pack_start(label);

    add(vbox);
    show_all();

    //set the first name variable and check if user can click button
    fname_entry.signal_changed().connect([this]() {
      first_name = fname_entry.get_text();
      button.set_sensitive(areEntriesFilled());
    });

    //set the last name variable and check if user can click button
    lname_entry.signal_changed().connect([this]() {
      last_name = lname_entry.get_text();
      button.set_sensitive(areEntriesFilled());
    });

    //merge names and set it as labels text
    button.signal_clicked().connect([this]() {
      label.set_text("Names Combined: " + first_name + " " + last_name);
    });
  }
};

int main() {
  Gtk::Main gtk_main;
  Window window;
  gtk_main.run(window);
}
