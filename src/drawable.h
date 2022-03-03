#ifndef J2D_DRAWABLE_H
#define J2D_DRAWABLE_H

#include <gfx/objects.h>

#include <jks/vec4.h>
#include <jks/vec2.h>

#include <stdbool.h>

#define J2D_BUFFER_VERTEXES 0x1
#define J2D_BUFFER_INDICES  0x2

typedef struct j2d_vertex_s
{
	vec4f_t color;
	vec2f_t position;
	vec2d_t uv;
} j2d_vertex_t;

typedef struct j2d_drawable_s j2d_drawable_t;

struct j2d_drawable_s
{
	gfx_device_t *device;
	gfx_buffer_t vertexes;
	gfx_buffer_t indices;
	enum gfx_primitive_type primitive;
	uint32_t indices_count;
	uint32_t dirty_buffers;
};

bool j2d_drawable_ctr(j2d_drawable_t *drawble, gfx_device_t *device, enum gfx_primitive_type primitive);
void j2d_drawable_dtr(j2d_drawable_t *drawable);

void j2d_draw(j2d_drawable_t *drawable);

#endif
