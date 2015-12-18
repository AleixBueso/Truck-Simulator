#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "Primitive.h"
#include "PhysVehicle3D.h"
#include "PhysBody3D.h"

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled), front_truck(NULL)
{
	turn = acceleration = brake = 0.0f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	VehicleInfo front_car;
	VehicleInfo trailer_car;
	VehicleInfo cabin;
	VehicleInfo wall1;
	VehicleInfo wall2;
	VehicleInfo wall3;
	VehicleInfo wall4;

	// Car properties ----------------------------------------
	front_car.chassis_size.Set(3, 1.5, 4);
	front_car.chassis_offset.Set(0, 1.5, 0);
	front_car.mass = 500.0f;
	front_car.suspensionStiffness = 15.88f;
	front_car.suspensionCompression = 0.83f;
	front_car.suspensionDamping = 0.88f;
	front_car.maxSuspensionTravelCm = 1000.0f;
	front_car.frictionSlip = 50.5;
	front_car.maxSuspensionForce = 6000.0f;

	// Wheel properties ---------------------------------------
	float connection_height = 1.5f;
	float wheel_radius = 0.6f;
	float wheel_width = 0.5f;
	float suspensionRestLength = 1.2f;

	// Don't change anything below this line ------------------

	float half_width = front_car.chassis_size.x*0.5f;
	float half_length = front_car.chassis_size.z*0.5f;
	
	vec3 direction(0,-1,0);
	vec3 axis(-1,0,0);
	
	front_car.num_wheels = 4;
	front_car.wheels = new Wheel[4];

	// FRONT-LEFT ------------------------
	front_car.wheels[0].connection.Set(half_width - 0.3f * wheel_width, connection_height, wheel_radius + 0.8);
	front_car.wheels[0].direction = direction;
	front_car.wheels[0].axis = axis;
	front_car.wheels[0].suspensionRestLength = suspensionRestLength;
	front_car.wheels[0].radius = wheel_radius;
	front_car.wheels[0].width = wheel_width;
	front_car.wheels[0].front = true;
	front_car.wheels[0].drive = true;
	front_car.wheels[0].brake = false;
	front_car.wheels[0].steering = true;

	// FRONT-RIGHT ------------------------
	front_car.wheels[1].connection.Set(-half_width + 0.3f * wheel_width, connection_height, wheel_radius + 0.8);
	front_car.wheels[1].direction = direction;
	front_car.wheels[1].axis = axis;
	front_car.wheels[1].suspensionRestLength = suspensionRestLength;
	front_car.wheels[1].radius = wheel_radius;
	front_car.wheels[1].width = wheel_width;
	front_car.wheels[1].front = true;
	front_car.wheels[1].drive = true;
	front_car.wheels[1].brake = false;
	front_car.wheels[1].steering = true;

	front_car.wheels[2].connection.Set(half_width - 0.3f * wheel_width, connection_height, wheel_radius - 1.6);
	front_car.wheels[2].direction = direction;
	front_car.wheels[2].axis = axis;
	front_car.wheels[2].suspensionRestLength = suspensionRestLength;
	front_car.wheels[2].radius = wheel_radius;
	front_car.wheels[2].width = wheel_width;
	front_car.wheels[2].front = false;
	front_car.wheels[2].drive = false;
	front_car.wheels[2].brake = true;
	front_car.wheels[2].steering = false;

	front_car.wheels[3].connection.Set(- half_width + 0.3f * wheel_width, connection_height, wheel_radius - 1.6);
	front_car.wheels[3].direction = direction;
	front_car.wheels[3].axis = axis;
	front_car.wheels[3].suspensionRestLength = suspensionRestLength;
	front_car.wheels[3].radius = wheel_radius;
	front_car.wheels[3].width = wheel_width;
	front_car.wheels[3].front = false;
	front_car.wheels[3].drive = false;
	front_car.wheels[3].brake = true;
	front_car.wheels[3].steering = false;

	cabin.chassis_size.Set(3, 2, 2.5);
	cabin.chassis_offset.Set(0, 3.2, -0.75);
	cabin.mass = 100.0f;

	front_truck = App->physics->AddVehicle(front_car, cabin);

	// trailer properties ----------------------------------------
	trailer_car.chassis_size.Set(3, 1, 6);
	trailer_car.chassis_offset.Set(0, 1, 0);
	trailer_car.mass = 500.0f;
	trailer_car.suspensionStiffness = 15.88f;
	trailer_car.suspensionCompression = 0.83f;
	trailer_car.suspensionDamping = 0.88f;
	trailer_car.maxSuspensionTravelCm = 1000.0f;
	trailer_car.frictionSlip = 50.5;
	trailer_car.maxSuspensionForce = 6000.0f;

	//-----------------------------------------------------
	wall1.chassis_size.Set(0.5, 3, 6);
	wall1.chassis_offset.Set(1.3, 3, 0);
	wall1.mass = 100.0f;

	wall2.chassis_size.Set(0.5, 3, 6);
	wall2.chassis_offset.Set(-1.3, 3, 0);
	wall2.mass = 100.0f;

	wall3.chassis_size.Set(3, 3, 0.5);
	wall3.chassis_offset.Set(0, 3, -2.75);
	wall3.mass = 50.0f;

	wall4.chassis_size.Set(3, 3, 0.5);
	wall4.chassis_offset.Set(0, 3, 2.75);
	wall4.mass = 50.0f;

	// Don't change anything below this line ------------------

	half_width = trailer_car.chassis_size.x*0.5f;
	half_length = trailer_car.chassis_size.z*0.5f;

	trailer_car.num_wheels = 6;
	trailer_car.wheels = new Wheel[6];

	// FRONT-LEFT ------------------------
	trailer_car.wheels[0].connection.Set(half_width - 0.3f * wheel_width, connection_height, wheel_radius + 1.5);
	trailer_car.wheels[0].direction = direction;
	trailer_car.wheels[0].axis = axis;
	trailer_car.wheels[0].suspensionRestLength = suspensionRestLength;
	trailer_car.wheels[0].radius = wheel_radius;
	trailer_car.wheels[0].width = wheel_width;
	trailer_car.wheels[0].front = false;
	trailer_car.wheels[0].drive = false;
	trailer_car.wheels[0].brake = false;
	trailer_car.wheels[0].steering = false;

	// FRONT-RIGHT ------------------------
	trailer_car.wheels[1].connection.Set(-half_width + 0.3f * wheel_width, connection_height, wheel_radius + 1.5);
	trailer_car.wheels[1].direction = direction;
	trailer_car.wheels[1].axis = axis;
	trailer_car.wheels[1].suspensionRestLength = suspensionRestLength;
	trailer_car.wheels[1].radius = wheel_radius;
	trailer_car.wheels[1].width = wheel_width;
	trailer_car.wheels[1].front = false;
	trailer_car.wheels[1].drive = false;
	trailer_car.wheels[1].brake = false;
	trailer_car.wheels[1].steering = false;

	trailer_car.wheels[2].connection.Set(half_width - 0.3f * wheel_width, connection_height, wheel_radius - 2);
	trailer_car.wheels[2].direction = direction;
	trailer_car.wheels[2].axis = axis;
	trailer_car.wheels[2].suspensionRestLength = suspensionRestLength;
	trailer_car.wheels[2].radius = wheel_radius;
	trailer_car.wheels[2].width = wheel_width;
	trailer_car.wheels[2].front = false;
	trailer_car.wheels[2].drive = false;
	trailer_car.wheels[2].brake = false;
	trailer_car.wheels[2].steering = false;

	trailer_car.wheels[3].connection.Set(-half_width + 0.3f * wheel_width, connection_height, wheel_radius - 2);
	trailer_car.wheels[3].direction = direction;
	trailer_car.wheels[3].axis = axis;
	trailer_car.wheels[3].suspensionRestLength = suspensionRestLength;
	trailer_car.wheels[3].radius = wheel_radius;
	trailer_car.wheels[3].width = wheel_width;
	trailer_car.wheels[3].front = false;
	trailer_car.wheels[3].drive = false;
	trailer_car.wheels[3].brake = false;
	trailer_car.wheels[3].steering = false;

	trailer_car.wheels[4].connection.Set(half_width - 0.3f * wheel_width, connection_height, wheel_radius - 3);
	trailer_car.wheels[4].direction = direction;
	trailer_car.wheels[4].axis = axis;
	trailer_car.wheels[4].suspensionRestLength = suspensionRestLength;
	trailer_car.wheels[4].radius = wheel_radius;
	trailer_car.wheels[4].width = wheel_width;
	trailer_car.wheels[4].front = false;
	trailer_car.wheels[4].drive = false;
	trailer_car.wheels[4].brake = false;
	trailer_car.wheels[4].steering = false;

	trailer_car.wheels[5].connection.Set(-half_width + 0.3f * wheel_width, connection_height, wheel_radius - 3);
	trailer_car.wheels[5].direction = direction;
	trailer_car.wheels[5].axis = axis;
	trailer_car.wheels[5].suspensionRestLength = suspensionRestLength;
	trailer_car.wheels[5].radius = wheel_radius;
	trailer_car.wheels[5].width = wheel_width;
	trailer_car.wheels[5].front = false;
	trailer_car.wheels[5].drive = false;
	trailer_car.wheels[5].brake = false;
	trailer_car.wheels[5].steering = false;

	trailer = App->physics->AddVehicle(trailer_car, wall1, wall2, wall3, wall4);
	ResetTruck(0.f, 1.f, 2.f, 0.f);
	ResetTrailer(0.f, 0.f, -5.f, 0.f);
	
	constraint = &App->physics->AddConstraintHinge(*front_truck, *trailer, vec3(0, 1, -1), vec3(0, 1, 5), vec3(0,1,0), vec3(0,1,0), false);
	App->camera->Reference = App->camera->Reference + vec3(0, 3, -5);
	App->camera->Look(front_truck->GetPos(), App->camera->Reference, true);

	//App->audio->PlayMusic("Music/Kansas_-_Carry_On_Wayward_Son.wav");

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	return true;
}

// Update: draw background
update_status ModulePlayer::Update(float dt)
{
	float speed_cam = 0.9f;
	if (following_camera)
	{
		vec3 p = front_truck->GetPos();
		vec3 f = front_truck->getForwardVector();

		vec3 dist_to_car = { -20.0f, 10.0f, -20.0f };
		vec3 camera_new_position = { p.x + (f.x * dist_to_car.x), p.y + f.y + dist_to_car.y, p.z + (f.z * dist_to_car.z) };
		vec3 speed_camera = camera_new_position - App->camera->Position;

		App->camera->Look(App->camera->Position + (speed_cam * speed_camera), p);
	}

	turn = acceleration = brake = 0.0f;

	if(App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
	{
		if (front_truck->GetKmh() >= 90)
			acceleration += 0;
		else
			acceleration = MAX_ACCELERATION * 2;
	}

	if(App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
	{
		if(turn < TURN_DEGREES)
			turn +=  TURN_DEGREES;
	}

	if(App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
	{
		if(turn > -TURN_DEGREES)
			turn -= TURN_DEGREES;
	}

	if(App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
	{
		if (front_truck->GetKmh() <= 0)
		{
			if (front_truck->GetKmh() <= -20)
				acceleration = 0;
			else
				acceleration = -MAX_ACCELERATION;
		}
		else
			brake = BRAKE_POWER;
	}

	/*if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN)
	{
		detach = true;
	}*/

	if (App->input->GetKey(SDL_SCANCODE_R) == KEY_DOWN)
	{
		ResetTruck(0.f, 1.f, 2.f, 0.f);
		ResetTrailer(0.f, 0.f, -5.f, 0.f);
		App->scene_intro->SetBalls();
		start_timer = 0;
		game_time = SDL_GetTicks() / 1000;
		ball_score = 0;
	}

	if (detach == true)
		constraint->setEnabled(false);

	Time = (SDL_GetTicks() / 1000) - game_time;

	front_truck->ApplyEngineForce(acceleration);
	front_truck->Turn(turn);
	front_truck->Brake(brake);

	trailer->RenderTrailer();
	front_truck->RenderFront();

	if (App->player->Time >= 60 && win == false)
		lost = true;

	char title[80];

	if (win == true)
	{
		sprintf_s(title, "You Won!  Balls delivered: %i", ball_score);
		detach = true;
		App->player->trailer->Brake(BRAKE_POWER);
	}

	else if (lost == true)
		sprintf_s(title, "You Lost, the customer got angry!");

	else
	{
		sprintf_s(title, "%.1f Km/h  Time: %is of 60s", front_truck->GetKmh(), (int)Time);
		start_timer = Time;
	}

	GameState();

	App->window->SetTitle(title);

	return UPDATE_CONTINUE;
}

void ModulePlayer::ResetTruck(float x_truck, float y_truck, float z_truck, float orient_angle_truck)
{
	front_truck->SetPos(x_truck, y_truck, z_truck);
	front_truck->StopMotion();
	front_truck->Orient(orient_angle_truck);
}

void ModulePlayer::ResetTrailer(float x_trailer, float y_trailer, float z_trailer, float orient_angle_trailer)
{
	trailer->SetPos(x_trailer, y_trailer, z_trailer);
	trailer->StopMotion();
	trailer->Orient(orient_angle_trailer);
}

void ModulePlayer::GameState()
{
	if (win == true)
	{
		if (start_timer + 5 == Time)
		{
			win = false;
			ResetTruck(0.f, 1.f, 2.f, 0.f);
			ResetTrailer(0.f, 0.f, -5.f, 0.f);
			ball_score = 0;
			App->scene_intro->SetBalls();
			if (detach == true)
			{
				constraint->setEnabled(true);
				detach = false;
			}
			start_timer = 0;
			game_time = SDL_GetTicks() / 1000;
		}
	}

	else if (lost == true)
	{
		if (start_timer + 5 == Time)
		{
			lost = false;
			ResetTruck(0.f, 1.f, 2.f, 0.f);
			ResetTrailer(0.f, 0.f, -5.f, 0.f);
			App->scene_intro->SetBalls();
			start_timer = 0;
			ball_score = 0;
			game_time = SDL_GetTicks() / 1000;
		}
	}
}



