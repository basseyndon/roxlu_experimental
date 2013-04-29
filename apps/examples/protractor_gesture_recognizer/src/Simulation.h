#include <glfw_wrapper/SimulationBase.h>
#include <roxlu/Roxlu.h>
#include <glr/GL.h>
#include <protractor/Protractor.h>

#define STATE_NONE 0
#define STATE_NEW_KEY 1
#define STATE_NEW_INPUT 2
#define STATE_MATCH 3
#define STATE_MATCH_REALTIME 4  /* match continously if the input contains a gesture */

using namespace gl;
using namespace protractor;

class Simulation : public SimulationBase {
 public:
  Simulation();
  ~Simulation();
  void setup();
  void update();
  void draw();

  void drawNone();
  void drawNewKey();
  void drawNewInput();
  void drawMatch();
  void drawRealtime();
 
  void onMouseDown(int x, int y, int buton);
  void onMouseUp(int x, int y, int button);
  void onMouseDrag(int x, int y, int dx, int dy, int button);
  void onMouseMove(int x, int y);
  void onChar(int ch); 
  void onKeyDown(int key);
  void onKeyUp(int key);
  void onWindowClose();
 public:
  FPS fps;

  Gesture* gesture;
  Gesture* input_gesture;
  Gesture* matched;
  Gesture realtime;

  Protractor protractor;
  int state;
};
