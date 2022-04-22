#pragma once
#include "Level.h"
#include "Fish.h"
#include "PlayerRect.h"
#include "ProgressBar.h"
#include "Level.h"
#include "OAMEntry.h"

enum class GameState { loading, playing, finishing, done };

class FishingLevel : public Level
{
	public:
		FishingLevel(OAMEntry* entries);

		virtual void Update(float elapsedSec) override;
		virtual bool HasReachedEnd() override;

	private:
		Fish m_Fish;
		PlayerRect m_Player;
		ProgressBar m_Bar;
		Rectf m_Container;
		GameState m_State;
};

