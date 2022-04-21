#pragma once
class ProgressBar
{
public:
	ProgressBar(float max, float start);

	void Update(float elapsedSec);
	void Draw() const;

	void UpdateRect(bool isInside);

private:
	float m_MaxValue;
	float m_CurrentValue;
	const float m_PointDelta;

	Rectf m_Shape;
};

