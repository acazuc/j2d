#include <gfx/window.h>
#include <gfx/device.h>

#include <j2d/line.h>

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	gfx_error_callback = printf;

	gfx_window_properties_t properties;
	gfx_window_properties_init(&properties);
	properties.device_backend = GFX_DEVICE_GL4;
	properties.window_backend = GFX_WINDOW_X11;
	gfx_window_t *window = gfx_create_window("demo", 640, 480, &properties);
	if (!window)
	{
		fprintf(stderr, "can't create window\n");
		return EXIT_FAILURE;
	}

	if (!gfx_create_device(window))
	{
		fprintf(stderr, "can't create device\n");
		return EXIT_FAILURE;
	}

	gfx_device_t *device = window->device;

	j2d_line_t line;
	if (!j2d_line_ctr(&line, device))
	{
		fprintf(stderr, "can't create line\n");
		return EXIT_FAILURE;
	}

	vec4f_t color1;
	vec4f_t color2;
	VEC4_SET(color1, 1, 0, 0, 1);
	VEC4_SET(color2, 0, 0, 1, 1);
	j2d_line_set_colors(&line, color1, color2);

	gfx_window_show(window);

	while (1)
	{
		vec4f_t clear_color;
		VEC4_SET(clear_color, 0, 1, 0, 1);
		gfx_clear_color(device, NULL, GFX_RENDERTARGET_ATTACHMENT_COLOR0, clear_color);
		j2d_line_draw(&line);
		gfx_window_swap_buffers(window);
	}

	return EXIT_SUCCESS;
}
