#ifndef ROXLU_BOXH
#define ROXLU_BOXH
namespace roxlu {

class Vertexdata;

class Box {
public:
	static void create(float width, float height, float depth, VertexData& vertexData);
};

};
#endif