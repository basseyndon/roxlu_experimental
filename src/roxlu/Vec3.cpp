#include "Vec2.h"
#include "Vec3.h"
#include "Vec4.h"

namespace roxlu {

Vec3::Vec3(const float xx, const float yy, const float zz)
	:x(xx)
	,y(yy)
	,z(zz)
{
}

Vec3::Vec3(const Vec2& v) 
	:x(v.x)
	,y(v.y)
	,z(0.0f)
{
}

Vec3::Vec3(const Vec3& v) 
	:x(v.x)
	,y(v.y)
	,z(v.z)
{
}

Vec3::Vec3(const Vec4& v4) 
	:x(v4.x * v4.w)
	,y(v4.y * v4.w)
	,z(v4.z * v4.w)
{
}

Vec3::Vec3(const float s) 
	:x(s)
	,y(s)
	,z(s)
{
}

Vec3& Vec3::operator=(const Vec4& v4) {
	x = v4.x;
	y = v4.y;
	z = v4.z;
	return *this;
}

}; // roxlu


