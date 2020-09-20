/* Copyright (c) <2003-2019> <Newton Game Dynamics>
* 
* This software is provided 'as-is', without any express or implied
* warranty. In no event will the authors be held liable for any damages
* arising from the use of this software.
* 
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely
*/
#ifndef __PHYSICS_WORLD_H__
#define __PHYSICS_WORLD_H__

#include "ndSandboxStdafx.h"
class ndDemoEntityManager;

class ndPhysicsWorld: public ndWorld
{
	public:
	ndPhysicsWorld(ndDemoEntityManager* const manager);
	~ndPhysicsWorld();

	void ResetTimer();
	void AdvanceTime();

	private:
	ndDemoEntityManager* m_manager;

	dUnsigned64 m_microsecunds;
};

#endif