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

	Rectf m_Shape;
};

