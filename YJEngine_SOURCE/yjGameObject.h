#pragma once
#include "CommonInclude.h"

namespace yj
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPosition(float x, float y)
		{
			mX = x;
			mY = y;
		}

		float GetPositionX() const { return mX; }
		float GetPositionY() const { return mY; }

	private:
		float mX = 0.0f;
		float mY = 0.0f;
	};
}


