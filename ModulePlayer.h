#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"

struct PhysVehicle3D;

#define MAX_ACCELERATION 1000.0f
#define TURN_DEGREES 10.0f * DEGTORAD
#define BRAKE_POWER 100.0f

class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();
	void ResetTruck(float x_truck, float y_truck, float z_truck, float orient_angle_truck);
	void ResetTrailer(float x_trailer, float y_trailer, float z_trailer, float orient_angle_trailer);
	void GameState();

public:

	PhysVehicle3D* front_truck;
	PhysVehicle3D* trailer;
	PhysBody3D* vehicle_sphere;
	btTypedConstraint* constraint;
	uint ball_score = 0;
	float Time = 0.0f;
	float turn;
	float acceleration;
	float brake;
	float start_timer = 0.f;
	float game_time = 0.f;
	bool detach = false;
	bool win = false;
	bool lost = false;
	bool following_camera;
};