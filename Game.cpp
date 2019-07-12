#include "Game.h"
#include "Constants.h"



namespace GameDev2D
{
	Game::Game()
	{
		m_timer = 0.0;
		m_cursorPos = Vector2::Zero;
		m_playerCurrentPosition = Vector2(15, 15);
		m_playerStartPos = Vector2(15, 15);
		m_newPlayerPosition = Vector2(15, 15);
		m_playerMovementNormal = Vector2::Zero;
		m_normalMagnitudeSqrd = 0.0;
		m_normalMagnitude = 0.0;
		m_newPositionX = 0.0f;
		m_newPositionY = 0.0f;

		m_circle = new Polygon();
		m_circle->MakeCircle(15.0f, true);
		m_circle->SetColor(Color::YellowColor());
		m_circle->SetAnchor(Vector2(0.5f, 0.5f));
		m_circle->SetPosition(m_playerStartPos);

		m_cursor = new Polygon();
		m_cursor->MakeCircle(6.0f, true);
		m_cursor->SetColor(Color::FireEngineRedColor());
		m_cursor->SetAnchor(Vector2(0.0f, 0.0f));

	}

	Game::~Game()
	{
		if (m_circle != nullptr)
		{
			delete m_circle;
			m_circle = nullptr;
		}
		if (m_cursor != nullptr)
		{
			delete m_cursor;
			m_cursor = nullptr;
		}
	
	}

	void Game::Update(double delta)
	{
		
		//m_mxLineEq = m_playerMovementSlope * delta * c_playerSpeed;

		if (m_playerCurrentPosition.x != m_newPlayerPosition.x || m_playerCurrentPosition.y != m_newPlayerPosition.y) {
			
			if (m_playerCurrentPosition.x != m_newPlayerPosition.x) {
				m_playerCurrentPosition.x += m_playerMovementNormal.x * (float)delta*c_playerSpeed;
			}
			if (m_playerCurrentPosition.y != m_newPlayerPosition.y) {
				m_playerCurrentPosition.y += m_playerMovementNormal.y *(float)delta*c_playerSpeed;
			}
		}
	
		//reset position when ball goes out of bounds
		if (m_playerCurrentPosition.x > 1280 || m_playerCurrentPosition.y > 720 || m_playerCurrentPosition.x < 0 || m_playerCurrentPosition.y < 0) // R key for reset to 0,0
		{
			m_playerCurrentPosition = Vector2(15, 15);
			m_newPlayerPosition = Vector2(15, 15);
			m_normalMagnitudeSqrd = 0.0;
		}
		//update position
		m_circle->SetPosition(Vector2((float)m_playerCurrentPosition.x, (float)m_playerCurrentPosition.y));
		m_cursor->SetPosition(m_cursorPos);
	}

	void Game::Draw()
	{
		m_circle->Draw();
		m_cursor->Draw();
		
	}

	void Game::HandleLeftMouseClick(float aMouseX, float aMouseY)
	{
		
		m_newPositionX = aMouseX;
		m_newPositionY = aMouseY;
		m_newPlayerPosition = Vector2(aMouseX, aMouseY);
		m_playerMovementNormal = Vector2::Zero;
		
		m_normalMagnitudeSqrd = ((m_newPlayerPosition.x - m_playerCurrentPosition.x) * (m_newPlayerPosition.x - m_playerCurrentPosition.x)) + ((m_newPlayerPosition.y - m_playerCurrentPosition.y) * (m_newPlayerPosition.y - m_playerCurrentPosition.y));
		m_normalMagnitude = sqrt(m_normalMagnitudeSqrd);
		m_playerMovementNormal = Vector2((m_newPlayerPosition.x - m_playerCurrentPosition.x)/ (float)m_normalMagnitude, (m_newPlayerPosition.y - m_playerCurrentPosition.y)/ (float)m_normalMagnitude);
		
	}

	void Game::HandleRightMouseClick(float aMouseX, float aMouseY)
	{
		
	}

	void Game::HandleMouseMove(float aMouseX, float aMouseY, float aPreviousX, float aPreviousY)
	{
		m_cursorPos = Vector2(aMouseX, aMouseY);
	}

	void Game::HandleKeyPress(Keyboard::Key aKey)
	{

	}

	void Game::HandleKeyReleased(Keyboard::Key key)
	{

	}
	
}