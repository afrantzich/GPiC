#pragma once
#include "AIState.h"

class AIEnemyLevel1 : public AIState
{
public:
	AIEnemyLevel1(class AIComponent* owner);

	void Update(float deltaTime) override;
	void OnEnter() override;
	void OnExit() override;

	const char* GetName() const override { return "Level 1"; }
};