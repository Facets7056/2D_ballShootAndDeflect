#pragma once
#include <GameDev2D.h>

namespace GameDev2D
{
	//Class definition
	class Game
	{
	public:
		Game();  //Constructor
		~Game(); //Destructor

		//Write game logic in the Update method
		void Update(double delta);

		//Render game objects in the Draw method
		void Draw();

		//Input methods
		void HandleLeftMouseClick(float mouseX, float mouseY);
		void HandleRightMouseClick(float mouseX, float mouseY);
		void HandleMouseMove(float mouseX, float mouseY, float previousX, float previousY);
		void HandleKeyPress(Keyboard::Key key);
		void HandleKeyReleased(Keyboard::Key key);
		
	private:
		//Member variables GO HERE 
		Polygon* m_circle;
		Polygon* m_cursor;
		Vector2 m_cursorPos;
		double m_timer;
		//tracks the position of my circle object 
		Vector2 m_playerCurrentPosition;
		Vector2 m_newPlayerPosition;
		Vector2 m_playerStartPos;
		//position of left-click
		float m_newPositionX;
		float m_newPositionY;
		//variables used to compute positions in motion animation
		Vector2 m_playerMovementNormal;
		double m_normalMagnitudeSqrd;
		double m_normalMagnitude;
		
	
		
	};
}
