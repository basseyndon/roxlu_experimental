#include <buttons/Panel.h>
#include <Buttons/Buttons.h>
#include <algorithm>

namespace buttons {

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
struct ButtonsFindByName {	
	ButtonsFindByName(const string n):n(n){}
	bool operator()(Buttons* b) {
		return b->getName() == n;
	}
	string n;
};


// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++	

Panel::Panel(const string& defaultGuiName, int w, int h) 
	:w(w)
	,h(h)
	,active_gui(NULL)
	,content_h(0)
	,content_x(0)
	,content_y(0)
	,step_dx(0)
{
	addButtons(defaultGuiName);
}

Panel::~Panel() {
	for(vector<Buttons*>::iterator it = guis.begin(); it != guis.end(); ++it) {
		delete *it;
	}
}


void Panel::update() {
	for(vector<Buttons*>::iterator it = guis.begin(); it != guis.end(); ++it) {
		(*it)->update();
	}
}

void Panel::draw() {
	for(vector<Buttons*>::iterator it = guis.begin(); it != guis.end(); ++it) {
		(*it)->draw();
	}
}

void Panel::onMouseMoved(int mx, int my) {
	for(vector<Buttons*>::iterator it = guis.begin(); it != guis.end(); ++it) {
		(*it)->onMouseMoved(mx, my);
	}
}

void Panel::onMouseDown(int mx, int my) {
	for(vector<Buttons*>::iterator it = guis.begin(); it != guis.end(); ++it) {
		(*it)->onMouseDown(mx, my);
	}

}

void Panel::onMouseUp(int mx, int my) {
	for(vector<Buttons*>::iterator it = guis.begin(); it != guis.end(); ++it) {
		(*it)->onMouseUp(mx, my);
	}
}

// -----------------------------------------------------------------------------
Buttons& Panel::addButtons(const string& title) {
	Buttons* bt = new Buttons(title, w);
	guis.push_back(bt);
	active_gui = bt;
	active_gui->addListener(this);
	if(guis.size() > 1) {
		bt->setLock(true);
	}
	return *bt;
}


Sliderf& Panel::addFloat(const string& label, float& value) {
	assert(active_gui != NULL);
	return active_gui->addFloat(label, value);
}

ColorPicker& Panel::addColor(const string& label, float* value) {
	assert(active_gui != NULL);
	return active_gui->addColor(label, value);
}

// get a Buttons
Buttons& Panel::getButtons(const string& name) {
	vector<Buttons*>::iterator it = std::find_if(guis.begin(), guis.end(), ButtonsFindByName(name));
	assert(it != guis.end());
	return **it;
}
// set the current active gui
void Panel::select(const string& name) {
	assert(active_gui != NULL);
	active_gui = &getButtons(name);
}

void Panel::setColor(const float hue, float a) {
	assert(active_gui != NULL);
	active_gui->setColor(hue, a);
}

// Resize / positioning / open-close
// -----------------------------------------------------------------------------
int Panel::getContentHeight() {
	int new_h = 0;
	for(vector<Buttons*>::iterator it = guis.begin(); it != guis.end(); ++it) {
		new_h += (*it)->getPanelHeight();
	}
	return new_h;
}

void Panel::position() {
	int yy = content_y;
	int xx = content_x;
	(*guis.begin())->getPosition(xx, yy);
	for(vector<Buttons*>::iterator it = guis.begin(); it != guis.end(); ++it) {
		Buttons& b = **it;
		b.setPosition(xx, yy);
		yy += b.getPanelHeight();
	}
}

void Panel::step() {
	step_dx = ++step_dx % guis.size();
	for(int i = 0; i < guis.size(); ++i) {
		if(i == step_dx) {
			guis[i]->open();
		}
		else {
			guis[i]->close();
		}
	}
}

void Panel::save() {
	for(vector<Buttons*>::iterator it = guis.begin(); it != guis.end(); ++it) {
		Buttons& b = **it;
		string filename = "gui_" +b.getName() +".bin";
		b.save(File::toDataPath(filename));
	}
}

void Panel::load() {
	for(vector<Buttons*>::iterator it = guis.begin(); it != guis.end(); ++it) {
		Buttons& b = **it;
		string filename = "gui_" +b.getName() +".bin";
		b.load(File::toDataPath(filename));
	}
}

// Event handling
// -----------------------------------------------------------------------------
void Panel::onRedraw(Buttons& bt) {
	// position change?
	int xx = 0;
	int yy = 0;
	(*guis.begin())->getPosition(xx, yy);
		
	if(xx != content_x || yy != content_y) {
		content_x = xx;
		content_y = yy;
		position();
		return;
	}
	
	// size changed?
	int new_h = getContentHeight();;
	if(new_h != content_h) {
		content_h = new_h;
		position();
	}
}


} // buttons