#include "pch.h"
#include "FishingLevel.h"

FishingLevel::FishingLevel(OAMEntry* OamEntries) 
	: m_Fish{ 50, &OamEntries[0] }
	, m_Container{ 0, 0, 200, 200 }
	, m_Player{ &OamEntries[1], &OamEntries[2] }
	, m_Bar{ 300, 33 }
	, m_State{GameState::loading}
{
	m_Fish.SetBounds(m_Container);
	m_Player.SetBounds(m_Container);
}

void FishingLevel::Update(float elapsedSec) {

	switch (m_State) {
		case GameState::loading:
			m_State = GameState::playing;
			break;
		case GameState::finishing:
			break;
		case GameState::playing:
			m_Fish.Update(elapsedSec);
			m_Player.Update(elapsedSec);
			m_Bar.UpdateRect(m_Player.CollidesWithFish(m_Fish.GetPos()));
			m_Bar.Update(elapsedSec);

			if (m_Bar.HasWon()) {
				m_State = GameState::finishing;
			}
			if (m_Bar.HasLost()) {
				m_State = GameState::done;
			}
			break;
	}
}

bool FishingLevel::HasReachedEnd() {
	return m_State == GameState::done;
}