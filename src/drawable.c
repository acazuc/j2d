#include "drawable.h"

#include <gfx/device.h>

bool j2d_drawable_ctr(j2d_drawable_t *drawable, gfx_device_t *device, enum gfx_primitive_type primitive)
{
	drawable->device = device;
	drawable->primitive = primitive;
	drawable->vertexes = GFX_BUFFER_INIT();
	drawable->indices = GFX_BUFFER_INIT();
	return true;
}

void j2d_drawable_dtr(j2d_drawable_t *drawable)
{
	gfx_delete_buffer(drawable->device, &drawable->vertexes);
	gfx_delete_buffer(drawable->device, &drawable->indices);
}

static void update_vertexes(j2d_drawable_t *drawable)
{
}

static void update_indices(j2d_drawable_t *drawable)
{
}

void j2d_draw(j2d_drawable_t *drawable)
{
	if (!drawable->indices_count)
		return;
	if (drawable->dirty_buffers & J2D_BUFFER_VERTEXES)
	{
		update_vertexes(drawable);
		drawable->dirty_buffers &= ~J2D_BUFFER_VERTEXES;
	}
	if (drawable->dirty_buffers & J2D_BUFFER_INDICES)
	{
		update_indices(drawable);
		drawable->dirty_buffers &= ~J2D_BUFFER_INDICES;
	}
	gfx_draw_indexed(drawable->device, drawable->primitive, drawable->indices_count, 0);
}
