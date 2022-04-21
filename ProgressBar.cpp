#include "pch.h"
#include "utils.h"
#include "ProgressBar.h"

ProgressBar::ProgressBar(float max, float start)
	:m_MaxValue{max}
	,m_CurrentValue{start}
	,m_Shape{50,50,50,start}
	,m_PointDelta{0.2f}
{

}

void ProgressBar::Update(float elapsedSec)
{
	m_Shape.height = m_CurrentValue;
}

void ProgressBar::Draw() const
{
	utils::FillRect(m_Shape);
	utils::DrawRect(m_Shape.left, m_Shape.bottom, m_Shape.width, m_MaxValue);
}

void ProgressBar::UpdateRect(bool isInside)
{
	if (isInside && m_CurrentValue < m_MaxValue)
	{
		m_CurrentValue += m_PointDelta * 2;
	}
	if (!isInside && m_CurrentValue > 0)
	{
		m_CurrentValue -= m_PointDelta;
	}
}