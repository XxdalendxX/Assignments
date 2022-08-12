#pragma once
#include <functional>

namespace AIForGames
{
	class Mouse;

	class Decision
	{
	public:
		virtual void MakeDecision(Mouse& mouse, float deltaTime) = 0;
	};

	class ABDecision : public Decision
	{
	public:
		Decision* trueOutcome;
		Decision* falseOutcome;
		std::function<bool(Mouse&)> condition;

		ABDecision(Decision* a, Decision* b, std::function<bool(Mouse&)> condition);
		ABDecision() = default;


		void MakeDecision(Mouse& mouse, float deltaTime) override;
	};

	class ActionDecision : public Decision
	{
		public:
		std::function<void(Mouse&, float)> action;

		ActionDecision(std::function<void(Mouse&, float)> action);
		ActionDecision() = default;

		void MakeDecision(Mouse& mouse, float deltaTime) override;

	};
}