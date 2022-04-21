#include "pch.h"
#include <iostream>
#include "Game.h"

Game::Game( const Window& window ) 
	:m_Window{ window }
	, m_Fish{Point2f{m_Window.width/2,m_Window.height / 2}, 50}
	, m_Container{ 0, 0, m_Window.width, m_Window.height }
	, m_Player{Rectf{m_Window.width/2,100,50,100}}
	, m_Bar{300, 33}
{
	Initialize( );
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	m_Fish.SetBounds(m_Container);
	m_Player.SetBounds(m_Container);
	m_State = GameState::loading;
}

void Game::Cleanup( )
{
	// Walk cycle 0-11 and 12-22
	// Fishing 23-35
	// Fish 36-37
	// Fishing pole 38
	// 
}

void Game::Update( float elapsedSec )
{

	switch (m_State) {
	case GameState::loading:
		m_State = GameState::playing;
		break;
	case GameState::finishing:
		break;
	case GameState::playing:
		m_Fish.Update(elapsedSec);
		m_Player.Update(elapsedSec);
		m_Bar.UpdateRect(m_Player.CollidesWithFish(m_Fish.GetPos()));
		m_Bar.Update(elapsedSec);

		if (m_Bar.HasWon()) {
			m_State = GameState::finishing;
		}
		if (m_Bar.HasLost()) {
			m_State = GameState::done;
		}
		break;
	}

	// Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
}

void Game::Draw( ) const
{
	ClearBackground( );

	switch (m_State) {
		case GameState::loading:
			break;
		case GameState::finishing:
			break;
		case GameState::playing:
			m_Player.Draw();
			m_Fish.Draw();
			m_Bar.Draw();
			break;
	}

}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	//std::cout << "KEYDOWN event: " << e.keysym.sym << std::endl;
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
	//std::cout << "KEYUP event: " << e.keysym.sym << std::endl;
	//switch ( e.keysym.sym )
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "`Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void Game::ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e )
{
	//std::cout << "MOUSEMOTION event: " << e.x << ", " << e.y << std::endl;
}

void Game::ProcessMouseDownEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONDOWN event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
}

void Game::ProcessMouseUpEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONUP event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
}

void Game::ClearBackground( ) const
{
	glClearColor( 0.0f, 0.0f, 0.3f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}