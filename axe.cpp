// axe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "raylib.h"

int main()
{
	// Dimensiuni fereastra
	int width = 1200;
	int height = 800;

	InitWindow(width, height, "Axe Game");

	// Circle coordinates
	int circle_x = 600;
	int circle_y = 400;
	int circle_radius = 25;

	// Circle edges
	int l_circle_x = circle_x - circle_radius;
	int r_circle_x = circle_x + circle_radius;
	int u_circle_y = circle_y - circle_radius;
	int b_circle_y = circle_y + circle_radius;
	 
	// Axe coordinates
	int axe_x = 400;
	int axe_y = 400;
	int axe_length = 50;

	// Axe edges
	int l_axe_x = axe_x;
	int r_axe_x = axe_x + axe_length;
	int u_axe_y = axe_y;
	int b_axe_y = axe_y + axe_length;


	int direction = 5;

	SetTargetFPS(120);

	bool collision_with_axe =
		(b_axe_y >= u_circle_y) && 
		(u_axe_y <= b_circle_y) &&
		(r_axe_x >= l_circle_x) &&
		(l_axe_x <= r_circle_x);

	while (WindowShouldClose() == false) {

		BeginDrawing();
		ClearBackground(WHITE);

		if (collision_with_axe) {
			DrawText("Game Over BOBER!", 300, 200, 50, GREEN);
		}
		else {
			// Game logic start
			
			// Update edges
			l_circle_x = circle_x - circle_radius;
			r_circle_x = circle_x + circle_radius;
			u_circle_y = circle_y - circle_radius;
			b_circle_y = circle_y + circle_radius;
			l_axe_x = axe_x;
			r_axe_x = axe_x + axe_length;
			u_axe_y = axe_y;
			b_axe_y = axe_y + axe_length;
			//update collision with axe
			collision_with_axe =
				(b_axe_y >= u_circle_y) &&
				(u_axe_y <= b_circle_y) &&
				(r_axe_x >= l_circle_x) &&
				(l_axe_x <= r_circle_x);


			DrawCircle(circle_x, circle_y, circle_radius, BLUE);
			DrawRectangle(axe_x, axe_y, axe_length, axe_length, RED);

			//Move axe

			axe_y += direction;
			if (axe_y > height || axe_y < 0) {
				direction = -direction;
			}

			// Circle movement
			if (IsKeyDown(KEY_D) && circle_x < width) {
				circle_x = circle_x + 5;
			}

			if (IsKeyDown(KEY_A) && circle_x > 0) {
				circle_x = circle_x - 5;
			}

			if (IsKeyDown(KEY_W)) {
				circle_y = circle_y - 5;
			}

			if (IsKeyDown(KEY_S)) {
				circle_y = circle_y + 5;
			}
		}

		
		

		//Game logic stop
		EndDrawing();
	}



}




