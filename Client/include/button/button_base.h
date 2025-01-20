#pragma once

#include <SDL2/SDL.h>

class ButtonBase {
public:
	ButtonBase();
	virtual ~ButtonBase();

	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;

	virtual void OnClick() = 0;

	virtual void SetPosition(float x, float y) = 0;
	virtual void SetSize(float width, float height) = 0;

	virtual void SetVisible(bool visible) = 0;
	virtual bool IsVisible() = 0;

	virtual void SetEnable(bool enable) = 0;
	virtual bool IsEnable() = 0;

private:
};