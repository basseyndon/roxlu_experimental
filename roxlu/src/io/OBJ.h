#ifndef ROXLU_OBJH
#define ROXLU_OBJH

#include <sstream>
#include <map>
#include <string>
#include <fstream>

#include "VertexData.h"
using namespace std;

namespace roxlu {



class OBJ {
public:
	
	struct Object {
		VertexData vd;
		string name;
	};	
	
	bool import(const string& filepath);
	bool extractFace(string info, int& vertexIndex, int& normalIndex, int& texcoordIndex);
	std::map<string, Object> objects;
	VertexData operator[](const string& name);
};

inline VertexData OBJ::operator[](const string& name) {
	map<string,Object>::iterator it = objects.find(name);
	if(it == objects.end()) {
		VertexData vd;
		return vd;	
	}
	return it->second.vd;
}

};

#endif