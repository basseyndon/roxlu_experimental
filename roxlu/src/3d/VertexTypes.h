#ifndef ROXLU_VERTEXTYPESH
#define ROXLU_VERTEXTYPESH

#include <vector>
#include "Vec4.h"
#include "Vec3.h"
#include "Vec2.h"
#include "../Graphics/Color.h"

using std::vector;

namespace roxlu {

// Here we define a couple of different vertex types; 
// P = position
// N = normal
// T = texcoord 
// T = tangent  (see member name)
// B = binormal
// C = color
enum VertexAttrib {
	 VERT_NONE 		= ( 0 )
	,VERT_POS 		= ( 1 << 0 )
	,VERT_TEX 		= ( 1 << 1 )
	,VERT_NORM		= ( 1 << 2 )
	,VERT_COL		= ( 1 << 3 )
	,VERT_BINORM 	= ( 1 << 4 )
	,VERT_TAN		= ( 1 << 5 )
	
	// clienstate types
	,ARRAY_VERT		= (1 << 6)
	,ARRAY_NORM		= (1 << 7)
	,ARRAY_COL		= (1 << 8)
	,ARRAY_TEX		= (1 << 9)
	,ARRAY_INDEX	= (1 << 10)
};

struct Vertex {
};

struct VertexP : public Vertex {
	Vec3 pos;
	
	void setPos(const float& x, const float& y, const float& z) {
		pos.set(x,y,z);
	}
};


struct VertexPT : public Vertex  {
	Vec3 pos;
	Vec2 tex;
	
	VertexPT& setPos(const float& x, const float& y, const float& z) {
		pos.set(x,y,z);
		return *this;
	}
	
	VertexPT& setTex(const float& u, const float& v) {
		tex.set(u,v);
		return *this;
	}
	
	const float* getPtr() {
		return pos.getPtr();
	}
};

struct VertexPN : public Vertex  {
	Vec3 pos;
	Vec3 norm;
	
	VertexPN& setPos(const float& x, const float& y, const float& z) {
		pos.set(x,y,z);
		return *this;
	}
	
	VertexPN& setNorm(const float& x, const float& y, const float& z) {
		norm.set(x,y,z);
		return *this;
	}
};

struct VertexPNC : public Vertex  {
	Vec3 pos;
	Vec3 norm;
	Color4 col;
	
	VertexPNC& setNorm(const float& x, const float& y, const float& z) {
		norm.set(x,y,z);
		return *this;
	}
	
	VertexPNC& setPos(const float& x, const float& y, const float& z) {
		pos.set(x,y,z);
		return *this;
	}
	
	VertexPNC& setCol(const float& r, const float& g, const float& b, const float& a) {
		col.set(r,g,b,a);
		return *this;
	}
};

struct VertexPTN : public Vertex  {
	Vec3 pos;
	Vec3 norm;
	Vec2 tex;
	
	
	VertexPTN& setPos(const float& x, const float& y, const float& z) {
		pos.set(x,y,z);
		return *this;
	}
	
	VertexPTN& setNorm(const float& x, const float& y, const float& z) {
		norm.set(x,y,z);
		return *this;
	}
	
	VertexPTN& setTex(const float& u, const float& v) {
		tex.set(u,v);
		return *this;
	}
};

struct VertexPTNC : public Vertex  {
	Vec3 pos;
	Vec3 norm;
	Color4 col;
	Vec2 tex;
	
	VertexPTNC& setPos(const float& x, const float& y, const float& z) {
		pos.set(x,y,z);
		return *this;
	}
	VertexPTNC& setNorm(const float& x, const float& y, const float& z) {
		norm.set(x,y,z);
		return *this;
	}
	VertexPTNC& setCol(const float& r, const float& g, const float& b, const float& a) {
		col.set(r,g,b,a);
		return *this;
	}
	VertexPTNC& setTex(const float& u, const float& v) {
		tex.set(u,v);
		return *this;
	}
};

struct VertexPTNT : public Vertex  { // with tangent.
	Vec3 pos;
	Vec3 norm;
	Vec4 tan;
	Vec2 tex;
};

struct VertexPTNTB : public Vertex  { // can be used for normal mapping
	Vec3 pos;
	Vec3 norm;
	Vec4 tan;
	Vec3 binorm;
	Vec2 tex;
};


class VerticesP {
public:
	int add(const float& x, const float& y, const float& z) {
		VertexP p;
		p.setPos(x, y, z);
		verts.push_back(p);
		return verts.size()-1;
	}
	
	int createRect(const float& x, const float& y, const float& z, const float& w, const float& h) {
		// first triangle.
		add(x  , y  , z);
		add(x+w, y  , z);
		add(x+w, y+h, z);
		
		// second triangle.
		add(x  , y  , z);
		add(x+w, y+h, z);
		add(x  , y+h, z); 
		return 6; // number of vertices created
	}
	
	void clear() {
		verts.clear();						
	}
		
	size_t numBytes() {
		return sizeof(VertexP) * size();  	
	}
	
	size_t size() {
		return verts.size();				
	}
	
	float* getPtr() {
		return &verts[0].pos.x;
	}
	
	vector<VertexP>::iterator begin() 	{	
		return verts.begin();	
	}
	
	vector<VertexP>::iterator end() 	{	
		return verts.end();		
	}
	
	vector<VertexP> verts;
};

class VerticesPT {
public:
	int add(const float& x, const float& y, const float& z, const float& u, const float& v) {
		VertexPT p;
		p.setPos(x, y, z);
		p.setTex(u,v);
		verts.push_back(p);
		return verts.size()-1;
	}
	
	/**
	 * Adds the vertices for a rectangle and returns the number of vertices
	 * created. We create two triangles
	 * 
	 * hw = half width
	 * hh = half height
	 *
	 * - We start with the positions at the bottom left
	 * - Texture coordinates start at bottom left
	 * - Z depth is 0
	 * See: http://d1xzuxjlafny7l.cloudfront.net/wp-content/uploads/2012/02/TextureVertex.png 
	 */
	const int addRectangle(const float hw, const float hh) {
		add(-hw, -hh, 0, 0,0);
		add(hw, -hw, 0, 1,0);
		add(hw, hw, 0, 1, 1);
		
		add(hw, hw, 0, 1, 1);
		add(-hw, hw, 0, 0, 1);
		add(-hw, -hh, 0, 0,0);
		return 6;
	}
	
	void clear() {
		verts.clear();					
	}
	
	size_t numBytes() {		
		return sizeof(VertexPT) * size();  	
	}
	
	size_t size() {	
		return verts.size();
	}
	
	float* getPtr() {
		return &verts[0].pos.x;
	}
	
	vector<VertexPT>::iterator begin() {	
		return verts.begin();	
	}
	
	vector<VertexPT>::iterator end() {
		return verts.end();		
	}
	
	VertexPT& operator[](const unsigned int dx) {
		return verts[dx];
	}
	
	vector<VertexPT> verts;
};



} // roxlu

#endif