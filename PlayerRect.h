#pragma once
#include "OAMEntry.h"
class PlayerRect
{
public:
	PlayerRect(OAMEntry* top, OAMEntry* bottom);

	void Update(float elapsedSec);

	void SetBounds(const Rectf& rect);
	bool CollidesWithFish(const Point2f& point);

private:
	Rectf m_Bounds;
	OAMEntry* m_Top;
	OAMEntry* m_Bottom;
	const float m_GravityAccel;
	float m_Velocity, m_Accel;
	const float m_Restitution;
	const float m_JumpForce, m_MaxSpeed;

	void Clamp();
	void CheckUserInput(float elapsedSec);
};

