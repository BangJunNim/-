#include "stdafx.h"
#include "First_Villein.h"

void First_Villein::move()
{
	_Move.Move++;

	switch (_Move.Villein) {
	case V_ONE:
		if (_Move.Move == 30) {

			_Move.Left_Right = !_Move.Left_Right;

			_Move.Move = 0;
		}
		// _Move.turn �� ���� true �� ��,
		if (_Move.Left_Right)
		{
			_rc.left += 7;
			_rc.right += 7;
		}
		// _Move.turn �� ���� false �� ���� ,,
		if (!_Move.Left_Right)
		{
			_rc.left -= 7;
			_rc.right -= 7;
		}
		break;
	}
}
