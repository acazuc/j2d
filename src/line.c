#include "line.h"

bool j2d_line_ctr(j2d_line_t *line, gfx_device_t *device)
{
	if (!j2d_drawable_ctr(&line->drawable, device, GFX_PRIMITIVE_LINES))
		return false;
	line->drawable.dirty_buffers |= J2D_BUFFER_INDICES;
	return true;
}

void j2d_line_dtr(j2d_line_t *line)
{
	j2d_drawable_dtr(&line->drawable);
}
