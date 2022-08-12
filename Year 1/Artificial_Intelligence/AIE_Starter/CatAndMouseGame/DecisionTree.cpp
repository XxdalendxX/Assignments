#include "DecisionTree.h"
#include "Mouse.h"

namespace AIForGames
{
	ABDecision::ABDecision(Decision* a, Decision* b, std::function<bool(Mouse&)> condition) : trueOutcome(a), falseOutcome(b), condition(condition)
	{

	}
	
	void ABDecision::MakeDecision(Mouse& mouse, float deltaTime)
	{
		if (condition(mouse))
		{
			trueOutcome->MakeDecision(mouse, deltaTime);
		}
		else
		{
			falseOutcome->MakeDecision(mouse, deltaTime);
		}
	}

	ActionDecision::ActionDecision(std::function<void(Mouse&, float)> action) : action(action)
	{

	}

	void ActionDecision::MakeDecision(Mouse& mouse, float deltaTime)
	{
		action(mouse, deltaTime);
	}
}