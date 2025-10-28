#include "yjGameObject.h"
#include "yjInput.h"
#include "yjTime.h"

namespace yj
{
	GameObject::GameObject()
	{
	}
	GameObject::~GameObject()
	{
	}


	void GameObject::Update()
	{
		const int speed = 100.0f;

		if (Input::GetKey(eKeyCode::Left))
		{
			mX -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::Right))
		{
			mX += speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::Up))
		{
			mY -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::Down))
		{
			mY += speed * Time::DeltaTime();
		}
	}

	void GameObject::LateUpdate()
	{

	}

	void GameObject::Render(HDC hdc)
	{
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255)); // 파랑 브러시를 생성합니다.
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush); // DC에 파랑 브러시를 선택합니다, 흰색 브러시 반환

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0)); // 빨강 펜을 생성합니다. GDI오브젝트 만들기
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen); // DC에 빨강 펜을 선택합니다.

		SelectObject(hdc, oldPen);

		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		SelectObject(hdc, oldBrush);
		DeleteObject(brush); // 파랑 브러시를 삭제합니다.
		DeleteObject(redPen); // 빨강 펜을 삭제합니다. 
	}
}
