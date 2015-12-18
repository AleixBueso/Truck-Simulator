#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"

#define MAX_SNAKE 2

struct PhysBody3D;
struct PhysMotor3D;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);
	void DrawMap();
	void SetBalls();
	void DrawBalls();

public:

	Cylinder collider;
	PhysBody3D* sensor;
	Cylinder finish;

	Cube* floor;

	Cube Road1;
	Cube Road2;
	Cube Road3;
	Cube Road4;
	Cube Road5;
	Cube Road6;
	Cube Road7;
	Cube Road8;
	Cube Road9;
	Cube Road10;
	Cube Road11;
	Cube Road12;
	Cube Road13;
	Cube Road14;
	Cube Road15;
	Cube Road16;
	Cube Road17;
	Cube Road18;
	Cube Road19;
	Cube Road20;
	Cube Road21;
	Cube Road22;
	Cube Road23;

	Cube wall1;
	Cube wall2;
	Cube wall3;
	Cube wall4;
	Cube wall5;
	Cube wall6;
	Cube wall7;
	Cube wall8;
	Cube wall9;
	Cube wall10;
	Cube wall11;
	Cube wall12;
	Cube wall13;
	Cube wall14;
	Cube wall15;
	Cube wall16;
	Cube wall17;
	Cube wall18;
	Cube wall19;
	Cube wall20;
	Cube wall21;
	Cube wall22;
	Cube wall23;

	Sphere Camp1;
	Sphere Camp2;
	Sphere Camp3;
	Sphere Camp4;
	Sphere Camp5;
	Sphere Camp6;
	Sphere Camp7;
	Sphere Camp8;
	Sphere Camp9;
	Sphere Camp10;

	Cube House_walls;
	Cube House_door;
	Cube House_window1;
	Cube House_window2;
	Cube House_roof;

	Cylinder trunk;
	Cube leaves;
	Cylinder trunk2;
	Cube leaves2;
	Cylinder trunk3;
	Cube leaves3;
	Cylinder trunk4;
	Cube leaves4;

	PhysBody3D* ball1_body;
	Sphere ball1;
	PhysBody3D* ball2_body;
	Sphere ball2;
	PhysBody3D* ball3_body;
	Sphere ball3;
	PhysBody3D* ball4_body;
	Sphere ball4;
	PhysBody3D* ball5_body;
	Sphere ball5;
	PhysBody3D* ball6_body;
	Sphere ball6;
	PhysBody3D* ball7_body;
	Sphere ball7;
	PhysBody3D* ball8_body;
	Sphere ball8;
	PhysBody3D* ball9_body;
	Sphere ball9;
	PhysBody3D* ball10_body;
	Sphere ball10;

	p2DynArray<PhysBody3D*> balls;

	PhysBody3D* pb_chassis;
	Cube p_chassis;

	PhysBody3D* pb_wheel;
	Cylinder p_wheel;

	PhysBody3D* pb_wheel2;
	Cylinder p_wheel2;

	PhysMotor3D* left_wheel;
	PhysMotor3D* right_wheel;
};
