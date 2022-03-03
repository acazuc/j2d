#ifndef J2D_LINE_H
#define J2D_LINE_H

#include <jks/vec4.h>

#include "drawable.h"

typedef struct j2d_line_s
{
	j2d_drawable_t drawable;
	j2d_vertex_t points[2];
} j2d_line_t;

bool j2d_line_ctr(j2d_line_t *line, gfx_device_t *device);
void j2d_line_dtr(j2d_line_t *line);

static inline void j2d_line_draw(j2d_line_t *line)
{
	j2d_draw(&line->drawable);
}

static inline void j2d_line_set_color1(j2d_line_t *line, vec4f_t color)
{
	VEC4_CPY(line->points[0].color, color);
	line->drawable.dirty_buffers |= J2D_BUFFER_VERTEXES;
}

static inline void j2d_line_set_color2(j2d_line_t *line, vec4f_t color)
{
	VEC4_CPY(line->points[1].color, color);
	line->drawable.dirty_buffers |= J2D_BUFFER_VERTEXES;
}

static inline void j2d_line_set_colors(j2d_line_t *line, vec4f_t color1, vec4f_t color2)
{
	VEC4_CPY(line->points[0].color, color1);
	VEC4_CPY(line->points[1].color, color2);
	line->drawable.dirty_buffers |= J2D_BUFFER_VERTEXES;
}

static inline void j2d_line_set_color(j2d_line_t *line, vec4f_t color)
{
	VEC4_CPY(line->points[0].color, color);
	VEC4_CPY(line->points[1].color, color);
	line->drawable.dirty_buffers |= J2D_BUFFER_VERTEXES;
}

static inline void j2d_line_set_point1(j2d_line_t *line, vec2f_t point)
{
	VEC2_CPY(line->points[0].position, point);
	line->drawable.dirty_buffers |= J2D_BUFFER_VERTEXES;
}

static inline void j2d_line_set_point2(j2d_line_t *line, vec2f_t point)
{
	VEC2_CPY(line->points[1].position, point);
	line->drawable.dirty_buffers |= J2D_BUFFER_VERTEXES;
}

static inline void j2d_line_set_points(j2d_line_t *line, vec2f_t point1, vec2f_t point2)
{
	VEC2_CPY(line->points[0].position, point1);
	VEC2_CPY(line->points[1].position, point2);
	line->drawable.dirty_buffers |= J2D_BUFFER_VERTEXES;
}

#endif
