#include "pch.h"
#include "utils.h"
#include <iostream>
#include "PlayerRect.h"

PlayerRect::PlayerRect(OAMEntry* top, OAMEntry* bottom)
	:m_Bounds{}
	,m_GravityAccel{-30000}
	,m_Velocity{0}
	,m_Top{top}
	,m_Bottom{bottom}
	,m_Accel{0}
	,m_Restitution{0.65f}
	,m_JumpForce{1000}
	,m_MaxSpeed{300}
{

}

void PlayerRect::Update( float elapsedSec)
{
	m_Accel = m_GravityAccel * elapsedSec;
	m_Velocity += m_Accel * elapsedSec;
	m_Top->AddPosition(0, int(m_Velocity * elapsedSec));
	m_Bottom->AddPosition(0, int(m_Velocity * elapsedSec));

	Clamp();
	CheckUserInput(elapsedSec);

}

void PlayerRect::SetBounds(const Rectf& rect)
{
	m_Bounds = rect;
}

bool PlayerRect::CollidesWithFish(const Point2f& pos)
{
	return utils::IsPointInRect(pos, Rectf{ m_Bottom->GetPosition().x, m_Bottom->GetPosition().y, 8,16 });
}

void PlayerRect::Clamp() {

	float posY{ m_Bottom->GetPosition().y};

	if (posY + 16 > m_Bounds.height + m_Bounds.bottom)
	{
		m_Bottom->SetPosition(0, int(m_Bounds.height + m_Bounds.bottom - 16));
		m_Top->SetPosition(0, int(m_Bounds.height + m_Bounds.bottom - 8));
		m_Velocity = 0;
	}
	if (posY < m_Bounds.bottom)
	{
		m_Bottom->SetPosition(0, int(m_Bounds.bottom));
		m_Top->SetPosition(0, int(m_Bounds.bottom + 8));
		m_Velocity *= -m_Restitution;
	}
}

void PlayerRect::CheckUserInput(float elapsedSec) {

	const Uint8* pStates = SDL_GetKeyboardState(nullptr);
	if (pStates[SDL_SCANCODE_J] && m_Velocity <= m_MaxSpeed)
	{
		m_Velocity += m_JumpForce * elapsedSec;
	}
}