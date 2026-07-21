#include "PlayerRegistrationState.h"

#include "InputSystem.h"
#include "UISystem.h"
#include "Players.h"

bool PlayerRegistrationState::needInput()
{
	return true;
}

void PlayerRegistrationState::handleInput(std::istream& in)
{
	switch (currentStep)
	{
	case EInputStep::InputName:
		InputSystem::InputString(name, "용사의 이름을 입력해주세요: ", "* 잘못된 입력입니다. 다시 입력하세요.");
		break;
	case EInputStep::InputHPAndMP:
		// HP, MP 입력
		while (true)
		{
			std::cout << "HP와 MP를 입력해주세요: ";
			if (InputSystem::InputInt(stat[0], 51) && InputSystem::InputInt(stat[1], 51))
			{
				break;
			}
			std::cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요." << "\n";
		}
		break;
	case EInputStep::InputPowerAndDefence:
		// 공격력, 방어력 입력
		while (true)
		{
			std::cout << "공격력과 방어력을 입력해주세요: ";
			if (InputSystem::InputInt(stat[2], 51) && InputSystem::InputInt(stat[3], 51))
			{
				break;
			}
			std::cout << "공격력이나 방어력의 값이 너무 작습니다. 다시 입력해주세요." << "\n";
		}
		break;
	case EInputStep::Complete:
		context->player = new NoJob(name, stat[0], stat[1], stat[2], stat[3]);
		std::cout << "\n\n";
		UISystem::PrintPlayerStat(context->player);

		// TODO 게임 종료 상태 만들어서 연결
		context->changeState(nullptr);
		break;
	default:
		break;
	}
}

void PlayerRegistrationState::onEnter()
{
}

void PlayerRegistrationState::onExit()
{
}
