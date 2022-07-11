#pragma once

class PlayerInput : public Behaviour
{
protected:
	bool invertHorizontal = false;
	bool invertVerticla = false;
	bool raw = false;

	KeyCode sprintButton = KeyCode::Shift;
	KeyCode dashButton = KeyCode::Mouse1;

public:
	void Update() override;
	void SwapWeapons();
	void SetAxes();
	void SetSprint();
};