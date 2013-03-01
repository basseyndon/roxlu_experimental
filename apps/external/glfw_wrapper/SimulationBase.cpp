#include <glfw_wrapper/SimulationBase.h>

SimulationBase::SimulationBase()
  :is_mouse_down(false)
  ,mouse_x(0)
  ,mouse_y(0)
  ,prev_mouse_x(0)
  ,prev_mouse_y(0)
  ,pressed_mouse_button(0)
  ,window(NULL)
  ,window_w(0)
  ,window_h(0)
{
}

SimulationBase::~SimulationBase() {
}

void SimulationBase::setup() {
}

void SimulationBase::update() {
}

void SimulationBase::draw() {
}

void SimulationBase::onMouseDown(int x, int y, int button) {
}

void SimulationBase::onMouseUp(int x, int y, int button) {
}

void SimulationBase::onMouseDrag(int x, int y, int dx, int dy, int button) {
}

void SimulationBase::onMouseMove(int x, int y) {
}

void SimulationBase::onChar(int ch) {
}

void SimulationBase::onKeyDown(int key) {
}

void SimulationBase::onKeyUp(int key) {
}

void SimulationBase::setWindowTitle(const char* title) {
  glfwSetWindowTitle(window, title);
}

void SimulationBase::onWindowResize(int w, int h) {
  glViewport(0,0,w,h);
}

void SimulationBase::onWindowClose() {
}

void SimulationBase::showCursor() {
  glfwSetInputMode(window, GLFW_CURSOR_MODE, GLFW_CURSOR_NORMAL);
}

void SimulationBase::hideCursor() {
  glfwSetInputMode(window, GLFW_CURSOR_MODE, GLFW_CURSOR_CAPTURED);
}

void SimulationBase::toggleCursor() {
  int curr_cursor_mode = glfwGetInputMode(window, GLFW_CURSOR_MODE);
  if(curr_cursor_mode == GLFW_CURSOR_NORMAL) {
    hideCursor();
  }
  else {
    showCursor();
  }
}
