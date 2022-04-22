#include "pch.h"
#include <iostream>
#include "utils.h"
#include "Fish.h"

Fish::Fish(float dirChangeChance, OAMEntry* oam)
	:m_AccTime{0}
	,m_MaxTime{1}
	,m_DirChangeChance{dirChangeChance}
	,m_Accel{0}
	,m_Drag{10}
	,m_Velocity{0}
	,m_Bounds{}
	,m_Oam{oam}
	,m_MaxAcceleration{300.0f}
{

}

void Fish::Update(float elapsedSec)
{
	AddTime(elapsedSec);
	AddDrag(elapsedSec);

	m_Velocity += m_Accel * elapsedSec;
	m_Oam->AddPosition(0, int(m_Velocity * elapsedSec));
	Clamp();
}

void Fish::SetBounds(const Rectf& rect)
{
	m_Bounds = rect;
}

Point2f Fish::GetPos() const
{
	return m_Oam->GetPosition();
}

void Fish::AddTime(float elapsedSec) {
	m_AccTime += elapsedSec;
	if (m_AccTime >= m_MaxTime)
	{
		m_AccTime -= m_MaxTime;

		m_Accel = (rand() % int(m_MaxAcceleration + 1)) - m_MaxAcceleration/2;
		m_Velocity = 0;
	}
}

void Fish::AddDrag(float elapsedSec) {
	if (m_Accel < 0)
	{
		m_Accel += m_Drag * elapsedSec;
	}
	if (m_Accel > 0)
	{
		m_Accel -= m_Drag * elapsedSec;
	}
}

void Fish::Clamp() {
	float posY{ m_Oam->GetPosition().y};
	if (posY + 4 > m_Bounds.height + m_Bounds.bottom)
	{
		m_Oam->SetPosition(0, int(m_Bounds.height + m_Bounds.bottom - 4));
	}
	if (posY - 4 < m_Bounds.bottom)
	{
		m_Oam->SetPosition(0, int(m_Bounds.bottom + 4));
	}
}