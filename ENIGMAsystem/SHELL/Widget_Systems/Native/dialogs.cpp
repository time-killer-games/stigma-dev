/*

 MIT License

 Copyright © 2021-2024 Samuel Venable

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.

*/

#include "Widget_Systems/Native/dialogs.h"
#include "Widget_Systems/widgets_mandatory.h"
#include "Platforms/General/PFwindow.h"
#include "Platforms/General/PFmain.h"

#include <libdlgmod/libdlgmod.h>

using std::string;

namespace enigma {

  bool widget_system_initialize() {
    return true;
  }

}

namespace enigma_user {

void show_info(string info, int bgcolor, int left, int top, int width, int height, bool embedGameWindow, bool showBorder, bool allowResize, bool stayOnTop, bool pauseGame, string caption) { }

void show_info() { }

void show_debug_message(string errortext, MESSAGE_TYPE type) {
  dialog_module::widget_set_owner((char *)enigma_user::pointer_to_ull_string((void *)enigma_user::window_handle()).c_str());
  #ifndef DEBUG_MODE
  errortext += "\n";
  fputs(errortext.c_str(), stderr);
  fflush(stderr);
  #endif
  if (type == MESSAGE_TYPE::M_FATAL_ERROR || 
    type == MESSAGE_TYPE::M_FATAL_USER_ERROR) {
    std::string caption = dialog_module::widget_get_caption();
    dialog_module::widget_set_caption((char *)"Fatal Error");
    dialog_module::show_error((char *)errortext.c_str(), true);
    dialog_module::widget_set_caption((char *)caption.c_str());
    abort();
  } else if (type == MESSAGE_TYPE::M_ERROR || 
    type == MESSAGE_TYPE::M_USER_ERROR) {
    std::string caption = dialog_module::widget_get_caption();
    dialog_module::widget_set_caption((char *)"Error");
    dialog_module::show_error((char *)errortext.c_str(), false);
    dialog_module::widget_set_caption((char *)caption.c_str());
  }
}

int show_message(const string &message) {
  dialog_module::widget_set_owner((char *)enigma_user::pointer_to_ull_string((void *)enigma_user::window_handle()).c_str());
  return dialog_module::show_message((char *)message.c_str());
}

int show_message_cancelable(std::string str) {
  dialog_module::widget_set_owner((char *)enigma_user::pointer_to_ull_string((void *)enigma_user::window_handle()).c_str());
  return dialog_module::show_message_cancelable((char *)str.c_str());
}

bool show_question(std::string str) {
  dialog_module::widget_set_owner((char *)enigma_user::pointer_to_ull_string((void *)enigma_user::window_handle()).c_str());
  return (bool)dialog_module::show_question((char *)str.c_str());
}

int show_question_cancelable(std::string str) {
  dialog_module::widget_set_owner((char *)enigma_user::pointer_to_ull_string((void *)enigma_user::window_handle()).c_str());
  return dialog_module::show_question_cancelable((char *)str.c_str());
}

int show_attempt(std::string str) {
  dialog_module::widget_set_owner((char *)enigma_user::pointer_to_ull_string((void *)enigma_user::window_handle()).c_str());
  return dialog_module::show_attempt((char *)str.c_str());
}

std::string get_string(std::string str, std::string def) {
  dialog_module::widget_set_owner((char *)enigma_user::pointer_to_ull_string((void *)enigma_user::window_handle()).c_str());
  return dialog_module::get_string((char *)str.c_str(), (char *)def.c_str());
}

std::string get_password(std::string str, std::string def) {
  dialog_module::widget_set_owner((char *)enigma_user::pointer_to_ull_string((void *)enigma_user::window_handle()).c_str());
  return dialog_module::get_password((char *)str.c_str(), (char *)def.c_str());
}

double get_number(std::string str, double def) {
  dialog_module::widget_set_owner((char *)enigma_user::pointer_to_ull_string((void *)enigma_user::window_handle()).c_str());
  return dialog_module::get_integer((char *)str.c_str(), def);
}

double get_integer(std::string str, double def) {
  dialog_module::widget_set_owner((char *)enigma_user::pointer_to_ull_string((void *)enigma_user::window_handle()).c_str());
  return dialog_module::get_integer((char *)str.c_str(), def);
}

double get_passcode(std::string str, double def) {
  dialog_module::widget_set_owner((char *)enigma_user::pointer_to_ull_string((void *)enigma_user::window_handle()).c_str());
  return dialog_module::get_passcode((char *)str.c_str(), def);
}

std::string get_open_filename(std::string filter, std::string fname) {
  dialog_module::widget_set_owner((char *)enigma_user::pointer_to_ull_string((void *)enigma_user::window_handle()).c_str());
  return dialog_module::get_open_filename((char *)filter.c_str(), (char *)fname.c_str());
}

std::string get_open_filename_ext(std::string filter, std::string fname, std::string dir, std::string title) {
  dialog_module::widget_set_owner((char *)enigma_user::pointer_to_ull_string((void *)enigma_user::window_handle()).c_str());
  return dialog_module::get_open_filename_ext((char *)filter.c_str(), (char *)fname.c_str(), (char *)dir.c_str(), (char *)title.c_str());
}

std::string get_open_filenames(std::string filter, std::string fname) {
  dialog_module::widget_set_owner((char *)enigma_user::pointer_to_ull_string((void *)enigma_user::window_handle()).c_str());
  return dialog_module::get_open_filenames((char *)filter.c_str(), (char *)fname.c_str());
}

std::string get_open_filenames_ext(std::string filter, std::string fname, std::string dir, std::string title) {
  dialog_module::widget_set_owner((char *)enigma_user::pointer_to_ull_string((void *)enigma_user::window_handle()).c_str());
  return dialog_module::get_open_filenames_ext((char *)filter.c_str(), (char *)fname.c_str(), (char *)dir.c_str(), (char *)title.c_str());
}

std::string get_save_filename(std::string filter, std::string fname) {
  dialog_module::widget_set_owner((char *)enigma_user::pointer_to_ull_string((void *)enigma_user::window_handle()).c_str());
  return dialog_module::get_save_filename((char *)filter.c_str(), (char *)fname.c_str());
}

std::string get_save_filename_ext(std::string filter, std::string fname, std::string dir, std::string title) {
  dialog_module::widget_set_owner((char *)enigma_user::pointer_to_ull_string((void *)enigma_user::window_handle()).c_str());
  return dialog_module::get_save_filename_ext((char *)filter.c_str(), (char *)fname.c_str(), (char *)dir.c_str(), (char *)title.c_str());
}

std::string get_directory(std::string dname) {
  dialog_module::widget_set_owner((char *)enigma_user::pointer_to_ull_string((void *)enigma_user::window_handle()).c_str());
  return dialog_module::get_directory((char *)dname.c_str());
}

std::string get_directory_alt(std::string capt, std::string root) {
  dialog_module::widget_set_owner((char *)enigma_user::pointer_to_ull_string((void *)enigma_user::window_handle()).c_str());
  return dialog_module::get_directory_alt((char *)capt.c_str(), (char *)root.c_str());
}

int get_color(int defcol) {
  dialog_module::widget_set_owner((char *)enigma_user::pointer_to_ull_string((void *)enigma_user::window_handle()).c_str());
  return dialog_module::get_color(defcol);
}

int get_color_ext(int defcol, std::string title) {
  dialog_module::widget_set_owner((char *)enigma_user::pointer_to_ull_string((void *)enigma_user::window_handle()).c_str());
  return dialog_module::get_color_ext(defcol, (char *)title.c_str());
}

std::string widget_get_caption() {
  return dialog_module::widget_get_caption();
}

void widget_set_caption(std::string str) {
  dialog_module::widget_set_caption((char *)str.c_str());
}

std::string widget_get_owner() {
  return dialog_module::widget_get_owner();
}

void widget_set_owner(std::string hwnd) {
  dialog_module::widget_set_owner((char *)hwnd.c_str());
}

std::string widget_get_icon() {
  return dialog_module::widget_get_icon();
}

void widget_set_icon(std::string icon) {
  dialog_module::widget_set_icon((char *)icon.c_str());
}

std::string widget_get_system() {
  return dialog_module::widget_get_system();
}

void widget_set_system(std::string sys) {
  dialog_module::widget_set_system((char *)sys.c_str());
}

void widget_set_button_name(int type, std::string name) {
  dialog_module::widget_set_button_name(type, (char *)name.c_str());
}

std::string widget_get_button_name(int type) {
  return dialog_module::widget_get_button_name(type);
}

bool widget_get_canceled() {
  return dialog_module::widget_get_canceled();
}

} // namespace enigma_user