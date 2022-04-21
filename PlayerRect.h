#pragma once
class PlayerRect
{
public:
	PlayerRect(const Rectf& rect);

	void Update(float elapsedSec);
	void Draw() const;

	void SetBounds(const Rectf& rect);
	bool CollidesWithFish(const Point2f& point);

private:
	Rectf m_Shape, m_Bounds;
	const float m_GravityAccel;
	float m_Velocity, m_Accel;
	const float m_Restitution;
	const float m_JumpForce, m_MaxSpeed;

	void Clamp();
	void CheckUserInput(float elapsedSec);
};

