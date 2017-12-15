#pragma once
#include "precision.hpp"
#include "Point2.hpp"
#include "Vector2.hpp"
#include "Color.hpp"
#include <string>

namespace Impact {
namespace Rendering3D {

class Texture {

private:
	typedef Geometry2D::Point Point2;
	typedef Geometry2D::Vector Vector2;

protected:

	imp_uint _width, _height, _n_pixels, _n_components, _size;
    imp_float* _pixel_buffer;
	
	void readPPM(const std::string& filename);

public:
	Texture(const std::string& filename);
	~Texture();

	Color getColor(const Point2& uv_coord) const;
	Vector2 getBumpValues(const Point2& uv_coord) const;
	
    imp_uint getWidth() const;
    imp_uint getHeight() const;
    const imp_float* getRawPixelArray() const;
};

} // Rendering3D
} // Impact
