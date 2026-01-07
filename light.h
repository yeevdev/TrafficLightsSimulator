#ifndef __LIGHT_H__
#define __LIGHT_H__

typedef enum _LightState {
	RED,
	YELLOW,
	GREEN,
	LEFT
} LightState;

typedef struct _Light {
	LightState state;
} Light;

typedef struct _Intersection {
	Light north;
	Light south;
	Light east;
	Light west;
} Intersection;

#endif // !__LIGHT_H__