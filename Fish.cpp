#include "pch.h"
#include <iostream>
#include "utils.h"
#include "Fish.h"

Fish::Fish(const Point2f& pos, float dirChangeChance)
	:m_AccTime{0}
	,m_MaxTime{1}
	,m_DirChangeChance{dirChangeChance}
	,m_Accel{0}
	,m_Drag{10}
	,m_Velocity{0}
	,m_Bounds{}
	,m_Shape{pos.x, pos.y, 20,20}
	,m_MaxAcceleration{300.0f}
{

}

void Fish::Update(float elapsedSec)
{
	AddTime(elapsedSec);
	AddDrag(elapsedSec);
	
	m_Velocity += m_Accel * elapsedSec;
	m_Shape.bottom += m_Velocity * elapsedSec;

	Clamp();
}

void Fish::Draw() const
{
	utils::SetColor(Color4f{ 0.2f, 0.7f, 0.2f, 1 });
	utils::FillRect(m_Shape);
}

void Fish::SetBounds(const Rectf& rect)
{
	m_Bounds = rect;
}

Point2f Fish::GetPos() const
{
	return Point2f{m_Shape.left, m_Shape.bottom};
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
	if (m_Shape.bottom + m_Shape.height / 2 > m_Bounds.height + m_Bounds.bottom)
	{
		m_Shape.bottom = m_Bounds.height + m_Bounds.bottom - m_Shape.height / 2;
	}
	if (m_Shape.bottom - m_Shape.height / 2< m_Bounds.bottom)
	{
		m_Shape.bottom = m_Bounds.bottom + m_Shape.height / 2;
	}
}