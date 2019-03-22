#pragma once
#include "GraphicsEngine/Component.h"
#include "GraphicsEngine/GUI.h"
#include "GraphicsEngine/Object.h"
#include "GraphicsEngine/Transform.h"
#include "GraphicsEngine/Time.h"
#include "GraphicsEngine/Vector3.h"
#include <cstdio>

class FpsCounter : public Component
{
	double	t1;
	int		f1;
	double	fps;

public:
	FpsCounter() 
	{
		t1 = Time::GetTime();
		f1 = Time::GetFrameCount();
		fps = 0;
	}

	virtual ~FpsCounter() {}

	virtual void Update() 
	{
		double t2	= Time::GetTime();
		int f2		= Time::GetFrameCount();

        double fps = f2 / t2;
        char str[300];
        std::sprintf(str, "%lf FPS", fps);
        GUI::Label(1, 2, 3, 4, str);

	}
};
