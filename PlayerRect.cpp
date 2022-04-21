#include "pch.h"
#include "utils.h"
#include <iostream>
#include "PlayerRect.h"

PlayerRect::PlayerRect(const Rectf& rect)
	:m_Bounds{}
	,m_GravityAccel{-100000}
	,m_Velocity{0}
	,m_Shape{rect}
	,m_Accel{0}
{

}

void PlayerRect::Update( float elapsedSec)
{
	m_Accel = m_GravityAccel * elapsedSec;
	m_Velocity += m_Accel * elapsedSec;
	m_Shape.bottom += m_Velocity * elapsedSec;

	if (m_Shape.bottom + m_Shape.height > m_Bounds.height + m_Bounds.bottom)
	{
		m_Shape.bottom = m_Bounds.height + m_Bounds.bottom - m_Shape.height;
		m_Velocity = 0;
	}
	if (m_Shape.bottom < m_Bounds.bottom)
	{
		m_Shape.bottom = m_Bounds.bottom;
		m_Velocity *= -0.65f;
	}

	const Uint8* pStates = SDL_GetKeyboardState(nullptr);
	if (pStates[SDL_SCANCODE_J] && m_Velocity <= 300)
	{
		m_Velocity += 10;
	}
}


void PlayerRect::Draw() const
{
	utils::SetColor(Color4f{ 0.7f, 0.1f, 0.2f, 1 });
	utils::FillRect(m_Shape);
}

void PlayerRect::SetBounds(const Rectf& rect)
{
	m_Bounds = rect;
}

bool PlayerRect::CollidesWithFish(const Point2f& pos)
{
	return utils::IsPointInRect(pos, m_Shape);
}