#pragma once
class Fish
{
public:
	Fish(const Point2f& pos, float dirChangeChance);
	
	void Update(float elapsedSed);
	void Draw() const;
	void SetBounds(const Rectf& bounds);
	Point2f GetPos() const;

private:
	Rectf m_Bounds;
	Rectf m_Shape;
	const float m_DirChangeChance;
	float m_AccTime;
	const float m_MaxTime;
	float m_Accel;
	float m_Velocity;
	const float m_Drag;
};

