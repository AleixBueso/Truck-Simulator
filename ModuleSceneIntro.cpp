#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "ModulePlayer.h"
#include "Primitive.h"
#include "PhysBody3D.h"
#include "PhysVehicle3D.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	DrawMap();

	ball1.SetPos(1, 3, -3);
	ball1.radius = 0.62;
	ball1.color = Green;

	ball2.SetPos(-1, 3, -3);
	ball2.radius = 0.62;
	ball2.color = Green;

	ball3.SetPos(1, 3, -4);
	ball3.radius = 0.62;
	ball3.color = Green;

	ball4.SetPos(-1, 3, -4);
	ball4.radius = 0.62;
	ball4.color = Green;

	ball5.SetPos(1, 3, -5);
	ball5.radius = 0.62;
	ball5.color = Green;

	ball6.SetPos(-1, 3, -5);
	ball6.radius = 0.62;
	ball6.color = Green;

	ball7.SetPos(1, 4, -3.5);
	ball7.radius = 0.62;
	ball7.color = Green;

	ball8.SetPos(-1, 4, -3.5);
	ball8.radius = 0.62;
	ball8.color = Green;

	ball9.SetPos(1, 4, -4.5);
	ball9.radius = 0.62;
	ball9.color = Green;

	ball10.SetPos(-1, 4, -4.5);
	ball10.radius = 0.62;
	ball10.color = Green;

	ball1_body = App->physics->AddBody(ball1, 1);
	ball2_body = App->physics->AddBody(ball2, 1);
	ball3_body = App->physics->AddBody(ball3, 1);
	ball4_body = App->physics->AddBody(ball4, 1);
	ball5_body = App->physics->AddBody(ball5, 1);
	ball6_body = App->physics->AddBody(ball6, 1);
	ball7_body = App->physics->AddBody(ball7, 1);
	ball8_body = App->physics->AddBody(ball8, 1);
	ball9_body = App->physics->AddBody(ball9, 1);
	ball10_body = App->physics->AddBody(ball10, 1);

	balls.PushBack(ball1_body);
	balls.PushBack(ball2_body);
	balls.PushBack(ball3_body);
	balls.PushBack(ball4_body);
	balls.PushBack(ball5_body);
	balls.PushBack(ball6_body);
	balls.PushBack(ball7_body);
	balls.PushBack(ball8_body);
	balls.PushBack(ball9_body);
	balls.PushBack(ball10_body);

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");
	delete floor;

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{

	floor->Render();

	Road1.Render();
	Road2.Render();
	Road3.Render();
	Road4.Render();
	Road5.Render();
	Road6.Render();
	Road7.Render();
	Road8.Render();
	Road9.Render();
	Road10.Render();
	Road11.Render();
	Road12.Render();
	Road13.Render();
	Road14.Render();
	Road15.Render();
	Road16.Render();
	Road17.Render();
	Road18.Render();
	Road19.Render();
	Road20.Render();
	Road21.Render();
	Road22.Render();
	Road23.Render();

	Camp1.Render();
	Camp2.Render();
	Camp3.Render();
	Camp4.Render();
	Camp5.Render();
	Camp6.Render();
	Camp7.Render();
	Camp8.Render();
	Camp9.Render();
	Camp10.Render();

	House_walls.Render();
	House_door.Render();
	House_window1.Render();
	House_window2.Render();
	House_roof.Render();

	trunk.Render();
	leaves.Render();
	trunk2.Render();
	leaves2.Render();
	trunk3.Render();
	leaves3.Render();
	trunk4.Render();
	leaves4.Render();

	//collider.Render();
	finish.Render();
	
	DrawBalls();

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::SetBalls()
{
	ball1_body->SetPos(1, 3, -3);
	ball1_body->StopMotion();
	ball2_body->SetPos(-1, 3, -3);
	ball2_body->StopMotion();
	ball3_body->SetPos(1, 3, -4);
	ball3_body->StopMotion();
	ball4_body->SetPos(-1, 3, -4);
	ball4_body->StopMotion();
	ball5_body->SetPos(1, 3, -5);
	ball5_body->StopMotion();
	ball6_body->SetPos(-1, 3, -5);
	ball6_body->StopMotion();
	ball7_body->SetPos(1, 4, -3.5);
	ball7_body->StopMotion();
	ball8_body->SetPos(-1, 4, -3.5);
	ball8_body->StopMotion();
	ball9_body->SetPos(1, 4, -4.5);
	ball9_body->StopMotion();
	ball10_body->SetPos(-1, 4, -4.5);
	ball10_body->StopMotion();

	for (uint i = 0; i < balls.Count(); i++)
	{
		balls[i]->delivered = false;
	}

}
void ModuleSceneIntro::DrawBalls()
{
	// The 10 balls
	ball1_body->GetTransform(&ball1.transform);
	ball1.Render();
	ball2_body->GetTransform(&ball2.transform);
	ball2.Render();
	ball3_body->GetTransform(&ball3.transform);
	ball3.Render();
	ball4_body->GetTransform(&ball4.transform);
	ball4.Render();
	ball5_body->GetTransform(&ball5.transform);
	ball5.Render();
	ball6_body->GetTransform(&ball6.transform);
	ball6.Render();
	ball7_body->GetTransform(&ball7.transform);
	ball7.Render();
	ball8_body->GetTransform(&ball8.transform);
	ball8.Render();
	ball9_body->GetTransform(&ball9.transform);
	ball9.Render();
	ball10_body->GetTransform(&ball10.transform);
	ball10.Render();
}

void ModuleSceneIntro::DrawMap()
{
	floor = new Cube();
	floor->Scale(3000, 0.01f, 3000);
	floor->color = Green;

	Road1.color = Gray;
	Road1.size.x = 20;
	Road1.size.y = 1;
	Road1.size.z = 100;
	Road1.SetPos(0, 0.1f, 40);
	App->physics->AddBody(Road1, 0);

	wall1.color;
	wall1.size.x = 1;
	wall1.size.y = 10;
	wall1.size.z = 100;
	wall1.SetPos(10, 5, 40);
	App->physics->AddBody(wall1, 0);

	wall2.color;
	wall2.size.x = 1;
	wall2.size.y = 10;
	wall2.size.z = 100;
	wall2.SetPos(-10, 5, 40);
	App->physics->AddBody(wall2, 0);

	wall3.color;
	wall3.size.x = 20;
	wall3.size.y = 10;
	wall3.size.z = 1;
	wall3.SetPos(0, 5, -10);
	App->physics->AddBody(wall3, 0);

	Road2.color = Gray;
	Road2.size.x = 20;
	Road2.size.y = 1;
	Road2.size.z = 40;
	Road2.SetPos(0, 0.1f, 110);
	App->physics->AddBody(Road2, 0);

	wall4.color;
	wall4.size.x = 1;
	wall4.size.y = 10;
	wall4.size.z = 40;
	wall4.SetPos(10, 5, 110);
	App->physics->AddBody(wall4, 0);

	wall5.color;
	wall5.size.x = 1;
	wall5.size.y = 10;
	wall5.size.z = 40;
	wall5.SetPos(-10, 5, 110);
	App->physics->AddBody(wall5, 0);

	Road3.color = Gray;
	Road3.size.x = 20;
	Road3.size.y = 1;
	Road3.size.z = 40;
	Road3.SetPos(0, 0.1f, 149);
	App->physics->AddBody(Road3, 0);

	wall6.color;
	wall6.size.x = 1;
	wall6.size.y = 10;
	wall6.size.z = 40;
	wall6.SetPos(-10, 5, 149);
	App->physics->AddBody(wall6, 0);

	wall7.color = Gray;
	wall7.size.x = 1;
	wall7.size.y = 10;
	wall7.size.z = 38;
	wall7.SetPos(10, 5, 149);
	App->physics->AddBody(wall7, 0);

	Road4.color = Gray;
	Road4.size.x = 20;
	Road4.size.y = 1;
	Road4.size.z = 40;
	Road4.SetRotation(-20, vec3(0.f, 1.f, 0.f));
	Road4.SetPos(-6, 0.1f, 184);
	App->physics->AddBody(Road4, 0);

	wall8.color = Gray;
	wall8.size.x = 1;
	wall8.size.y = 10;
	wall8.size.z = 34;
	wall8.SetRotation(-20, vec3(0.f, 1.f, 0.f));
	wall8.SetPos(-17, 5, 184);
	App->physics->AddBody(wall8, 0);

	wall9.color = Gray;
	wall9.size.x = 1;
	wall9.size.y = 10;
	wall9.size.z = 40;
	wall9.SetRotation(-20, vec3(0.f, 1.f, 0.f));
	wall9.SetPos(4, 5, 186);
	App->physics->AddBody(wall9, 0);

	Road5.color = Gray;
	Road5.size.x = 20;
	Road5.size.y = 1;
	Road5.size.z = 40;
	Road5.SetRotation(-30, vec3(0.f, 1.f, 0.f));
	Road5.SetPos(-22, 0.1f, 217);
	App->physics->AddBody(Road5, 0);

	wall10.color;
	wall10.size.x = 1;
	wall10.size.y = 10;
	wall10.size.z = 34;
	wall10.SetRotation(-30, vec3(0.f, 1.f, 0.f));
	wall10.SetPos(-32, 5, 213);
	App->physics->AddBody(wall10, 0);

	wall11.color = Gray;
	wall11.size.x = 1;
	wall11.size.y = 10;
	wall11.size.z = 40;
	wall11.SetRotation(-30, vec3(0.f, 1.f, 0.f));
	wall11.SetPos(-13, 5, 222);
	App->physics->AddBody(wall11, 0);

	Road6.color = Gray;
	Road6.size.x = 20;
	Road6.size.y = 1;
	Road6.size.z = 40;
	Road6.SetRotation(-50, vec3(0.f, 1.f, 0.f));
	Road6.SetPos(-45, 0.1f, 245);
	App->physics->AddBody(Road6, 0);

	wall12.color = Gray;
	wall12.size.x = 1;
	wall12.size.y = 10;
	wall12.size.z = 46;
	wall12.SetRotation(-50, vec3(0.f, 1.f, 0.f));
	wall12.SetPos(-38, 5, 251);
	App->physics->AddBody(wall12, 0);

	wall13.color = Gray;
	wall13.size.x = 1;
	wall13.size.y = 10;
	wall13.size.z = 35;
	wall13.SetRotation(-50, vec3(0.f, 1.f, 0.f));
	wall13.SetPos(-54, 5, 239);
	App->physics->AddBody(wall13, 0);

	Road7.color = Gray;
	Road7.size.x = 20;
	Road7.size.y = 1;
	Road7.size.z = 40;
	Road7.SetRotation(-70, vec3(0.f, 1.f, 0.f));
	Road7.SetPos(-75, 0.1f, 263);
	App->physics->AddBody(Road7, 0);

	wall14.color = Gray;
	wall14.size.x = 1;
	wall14.size.y = 10;
	wall14.size.z = 42;
	wall14.SetRotation(-70, vec3(0.f, 1.f, 0.f));
	wall14.SetPos(-70, 5, 272);
	App->physics->AddBody(wall14, 0);

	wall15.color = Gray;
	wall15.size.x = 1;
	wall15.size.y = 10;
	wall15.size.z = 30;
	wall15.SetRotation(-66, vec3(0.f, 1.f, 0.f));
	wall15.SetPos(-77, 5, 253);
	App->physics->AddBody(wall15, 0);

	Road8.color = Gray;
	Road8.size.x = 40;
	Road8.size.y = 1;
	Road8.size.z = 20;
	Road8.SetPos(-110, 0.1f, 269);
	App->physics->AddBody(Road8, 0);

	wall16.color = Gray;
	wall16.size.x = 120;
	wall16.size.y = 10;
	wall16.size.z = 1;
	wall16.SetPos(-150, 5, 259);
	App->physics->AddBody(wall16, 0);

	wall17.color = Gray;
	wall17.size.x = 120;
	wall17.size.y = 10;
	wall17.size.z = 1;
	wall17.SetPos(-150, 5, 279);
	App->physics->AddBody(wall17, 0);

	Road9.color = Gray;
	Road9.size.x = 10;
	Road9.size.y = 1;
	Road9.size.z = 20;
	Road9.SetRotation(-6, vec3(0.f, 0.f, 1.f));
	Road9.SetPos(-135, 0.7f, 269);
	App->physics->AddBody(Road9, 0);

	Road10.color = Gray;
	Road10.size.x = 10;
	Road10.size.y = 1;
	Road10.size.z = 20;
	Road10.SetRotation(6, vec3(0.f, 0.f, 1.f));
	Road10.SetPos(-145, 0.7f, 269);
	App->physics->AddBody(Road10, 0);

	Road11.color = Gray;
	Road11.size.x = 10;
	Road11.size.y = 1;
	Road11.size.z = 20;
	Road11.SetRotation(-6, vec3(0.f, 0.f, 1.f));
	Road11.SetPos(-155, 0.7f, 269);
	App->physics->AddBody(Road11, 0);

	Road12.color = Gray;
	Road12.size.x = 10;
	Road12.size.y = 1;
	Road12.size.z = 20;
	Road12.SetRotation(6, vec3(0.f, 0.f, 1.f));
	Road12.SetPos(-165, 0.7f, 269);
	App->physics->AddBody(Road12, 0);

	Road13.color = Gray;
	Road13.size.x = 10;
	Road13.size.y = 1;
	Road13.size.z = 20;
	Road13.SetRotation(-6, vec3(0.f, 0.f, 1.f));
	Road13.SetPos(-175, 0.7f, 269);
	App->physics->AddBody(Road13, 0);

	Road14.color = Gray;
	Road14.size.x = 10;
	Road14.size.y = 1;
	Road14.size.z = 20;
	Road14.SetRotation(6, vec3(0.f, 0.f, 1.f));
	Road14.SetPos(-185, 0.7f, 269);
	App->physics->AddBody(Road14, 0);

	Road15.color = Gray;
	Road15.size.x = 10;
	Road15.size.y = 1;
	Road15.size.z = 20;
	Road15.SetRotation(-6, vec3(0.f, 0.f, 1.f));
	Road15.SetPos(-195, 0.7f, 269);
	App->physics->AddBody(Road15, 0);

	Road16.color = Gray;
	Road16.size.x = 10;
	Road16.size.y = 1;
	Road16.size.z = 20;
	Road16.SetRotation(6, vec3(0.f, 0.f, 1.f));
	Road16.SetPos(-205, 0.7f, 269);
	App->physics->AddBody(Road16, 0);

	Road17.color = Gray;
	Road17.size.x = 10;
	Road17.size.y = 1;
	Road17.size.z = 20;
	Road17.SetRotation(-6, vec3(0.f, 0.f, 1.f));
	Road17.SetPos(-215, 0.7f, 269);
	App->physics->AddBody(Road17, 0);

	Road18.color = Gray;
	Road18.size.x = 10;
	Road18.size.y = 1;
	Road18.size.z = 20;
	Road18.SetRotation(6, vec3(0.f, 0.f, 1.f));
	Road18.SetPos(-225, 0.7f, 269);
	App->physics->AddBody(Road18, 0);

	Road19.color = Gray;
	Road19.size.x = 10;
	Road19.size.y = 1;
	Road19.size.z = 20;
	Road19.SetRotation(-6, vec3(0.f, 0.f, 1.f));
	Road19.SetPos(-235, 0.7f, 269);
	App->physics->AddBody(Road19, 0);

	Road20.color = Gray;
	Road20.size.x = 10;
	Road20.size.y = 1;
	Road20.size.z = 20;
	Road20.SetRotation(6, vec3(0.f, 0.f, 1.f));
	Road20.SetPos(-245, 0.7f, 269);
	App->physics->AddBody(Road20, 0);

	wall18.color = Gray;
	wall18.size.x = 120;
	wall18.size.y = 10;
	wall18.size.z = 1;
	wall18.SetPos(-270, 5, 259);
	App->physics->AddBody(wall18, 0);

	wall19.color = Gray;
	wall19.size.x = 120;
	wall19.size.y = 10;
	wall19.size.z = 1;
	wall19.SetPos(-270, 5, 279);
	App->physics->AddBody(wall19, 0);

	Road21.color = Gray;
	Road21.size.x = 100;
	Road21.size.y = 1;
	Road21.size.z = 20;
	Road21.SetPos(-300, 0.1f, 269);
	App->physics->AddBody(Road21, 0);

	Road22.color = Gray;
	Road22.size.x = 50;
	Road22.size.y = 1;
	Road22.size.z = 20;
	Road22.SetRotation(-14, vec3(0.f, 0.f, 1.f));
	Road22.SetPos(-374, 6, 269);
	App->physics->AddBody(Road22, 0);

	Road23.color = Gray;
	Road23.size.x = 160;
	Road23.size.y = 1;
	Road23.size.z = 100;
	Road23.SetPos(-374 - 75 - 30, 12, 269);
	App->physics->AddBody(Road23, 0);

	wall20.color = Gray;
	wall20.size.x = 120;
	wall20.size.y = 25;
	wall20.size.z = 1;
	wall20.SetPos(-374 + 40, 5, 279);
	App->physics->AddBody(wall20, 0);

	wall21.color = Gray;
	wall21.size.x = 120;
	wall21.size.y = 25;
	wall21.size.z = 1;
	wall21.SetPos(-374 + 40, 5, 259);
	App->physics->AddBody(wall21, 0);

	Camp1.color = Gray;
	Camp1.radius = 2;
	Camp1.SetPos(-274, -0.5f, 273);
	App->physics->AddBody(Camp1, 0);

	Camp2.color = Gray;
	Camp2.radius = 2;
	Camp2.SetPos(-290, -0.5f, 270);
	App->physics->AddBody(Camp2, 0);

	Camp3.color = Gray;
	Camp3.radius = 2;
	Camp3.SetPos(-298, -0.5f, 262);
	App->physics->AddBody(Camp3, 0);

	Camp4.color = Gray;
	Camp4.radius = 2;
	Camp4.SetPos(-310, -0.5f, 265);
	App->physics->AddBody(Camp4, 0);

	Camp5.color = Gray;
	Camp5.radius = 2;
	Camp5.SetPos(-320, -0.5f, 267);
	App->physics->AddBody(Camp5, 0);

	Camp6.color = Gray;
	Camp6.radius = 2;
	Camp6.SetPos(-305, -0.5f, 261);
	App->physics->AddBody(Camp6, 0);

	Camp7.color = Gray;
	Camp7.radius = 2;
	Camp7.SetPos(-282, -0.5f, 273);
	App->physics->AddBody(Camp7, 0);

	Camp8.color = Gray;
	Camp8.radius = 2;
	Camp8.SetPos(-294, -0.5f, 269);
	App->physics->AddBody(Camp8, 0);

	Camp9.color = Gray;
	Camp9.radius = 2;
	Camp9.SetPos(-287, -0.5f, 265);
	App->physics->AddBody(Camp9, 0);

	Camp10.color = Gray;
	Camp10.radius = 2;
	Camp10.SetPos(-325, -0.5f, 273);
	App->physics->AddBody(Camp10, 0);

	House_walls.color = White;
	House_walls.size.x = 20;
	House_walls.size.y = 15;
	House_walls.size.z = 20;
	House_walls.SetPos(-398 - 50, 7.5f + 12, 305);
	App->physics->AddBody(House_walls, 0);

	House_door.color = Black;
	House_door.size.x = 4;
	House_door.size.y = 6;
	House_door.size.z = 2;
	House_door.SetPos(-398 - 50, 3 + 12, 295);
	App->physics->AddBody(House_door, 0);

	House_window1.color = Turquese;
	House_window1.size.x = 4;
	House_window1.size.y = 4;
	House_window1.size.z = 2;
	House_window1.SetPos(-398 - 56, 10 + 12, 295);
	App->physics->AddBody(House_window1, 0);

	House_window2.color = Turquese;
	House_window2.size.x = 4;
	House_window2.size.y = 4;
	House_window2.size.z = 2;
	House_window2.SetPos(-398 - 50 + 7, 10 + 12, 295);
	App->physics->AddBody(House_window2, 0);

	House_roof.color = Red;
	House_roof.size.x = 13;
	House_roof.size.y = 13;
	House_roof.size.z = 19;
	House_roof.SetRotation(45, vec3(0.f, 0.f, 1.f));
	House_roof.SetPos(-398 - 50, 14 + 12, 306);
	App->physics->AddBody(House_roof, 0);

	trunk.color = Brown;
	trunk.radius = 0.5;
	trunk.height = 4;
	trunk.SetPos(12, 2, 20);
	trunk.SetRotation(90, vec3(0, 0, 1));

	trunk2.color = Brown;
	trunk2.radius = 0.5;
	trunk2.height = 4;
	trunk2.SetPos(-12, 2, 20);
	trunk2.SetRotation(90, vec3(0, 0, 1));

	trunk3.color = Brown;
	trunk3.radius = 0.5;
	trunk3.height = 4;
	trunk3.SetPos(12, 2, 40);
	trunk3.SetRotation(90, vec3(0, 0, 1));

	trunk4.color = Brown;
	trunk4.radius = 0.5;
	trunk4.height = 4;
	trunk4.SetPos(-12, 2, 40);
	trunk4.SetRotation(90, vec3(0, 0, 1));

	leaves.color = Green;
	leaves.size.Set(2, 3, 2);
	leaves.SetPos(12, 4, 20);

	leaves2.color = Green;
	leaves2.size.Set(2, 3, 2);
	leaves2.SetPos(-12, 4, 20);

	leaves3.color = Green;
	leaves3.size.Set(2, 3, 2);
	leaves3.SetPos(12, 4, 40);

	leaves4.color = Green;
	leaves4.size.Set(2, 3, 2);
	leaves4.SetPos(-12, 4, 40);

	collider.color = Blue;
	collider.radius = 15;
	collider.height = 16;
	collider.SetRotation(90, vec3(0, 0, 1));
	collider.SetPos(-398 -50, 12 + 8, 269.f);

	finish.color = Blue;
	finish.radius = 10;
	finish.height = 1;
	finish.SetRotation(90, vec3(0, 0, 1));
	finish.SetPos(-398 - 50, 13, 269.f);

	sensor = App->physics->AddBody(collider, 0.0f);
	sensor->SetAsSensor(true);
	sensor->collision_listeners.add(this);
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	if (App->player->lost == false)
	{
		for (uint i = 0; i < balls.Count(); i++)
		{
			if (body1 == sensor && body2 == balls[i])
			{
				if (body2->delivered == false)
				{
					App->player->win = true;
					App->player->ball_score++;
					body2->delivered = true;
				}
			}
		}
	}
}

