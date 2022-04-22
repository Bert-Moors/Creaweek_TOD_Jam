#pragma once
#include "OAMEntry.h"

class Fish
{
public:
	Fish(float dirChangeChance, OAMEntry* oam);
	
	void Update(float elapsedSed);
	void SetBounds(const Rectf& bounds);
	Point2f GetPos() const;

private:
	Rectf m_Bounds;
	OAMEntry* m_Oam;
	//Rectf m_Shape;
	const float m_DirChangeChance;
	float m_AccTime;
	const float m_MaxTime;
	float m_Accel;
	float m_Velocity;
	const float m_Drag;
	const float m_MaxAcceleration;

	void AddTime(float elapsedSec);
	void AddDrag(float elapsedSec);
	void Clamp();
};

