#include "hud.h"

#include <whitgl/logging.h>

void space_hud_draw(space_entity src, space_hud_markers m, space_camera camera)
{

	space_sprite hud_sprite = {
		{{-0.25,-2},{0.25,-2},{-0.5,-1.75},{0.5,-1.75}},
		{{0,1},{0,2},{1,3}},
		4,
		3,
	};
	whitgl_int i;
	for(i=0; i<m.num; i++)
	{
		whitgl_fvec diff = whitgl_fvec_sub(m.marker[i].pos, src.pos);
		whitgl_float ang = whitgl_fvec_to_angle(diff)+whitgl_pi/2;
		whitgl_fvec dir = whitgl_fvec_normalize(diff);
		space_sprite_draw(hud_sprite, src.pos, ang, camera);
		space_entity mini = m.marker[i];
		mini.pos = whitgl_fvec_add(src.pos, whitgl_fvec_scale_val(dir, 1.5));
		whitgl_int j;
		for(j=0; j<mini.sprite.num_points; j++)
			mini.sprite.points[j] = whitgl_fvec_scale_val(mini.sprite.points[j], 0.1);
		space_entity_draw(mini, camera);

	}
}