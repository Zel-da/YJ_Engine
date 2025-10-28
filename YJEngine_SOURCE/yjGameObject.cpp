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
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255)); // �Ķ� �귯�ø� �����մϴ�.
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush); // DC�� �Ķ� �귯�ø� �����մϴ�, ��� �귯�� ��ȯ

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0)); // ���� ���� �����մϴ�. GDI������Ʈ �����
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen); // DC�� ���� ���� �����մϴ�.

		SelectObject(hdc, oldPen);

		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		SelectObject(hdc, oldBrush);
		DeleteObject(brush); // �Ķ� �귯�ø� �����մϴ�.
		DeleteObject(redPen); // ���� ���� �����մϴ�. 
	}
}
