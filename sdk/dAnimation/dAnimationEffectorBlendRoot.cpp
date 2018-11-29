/* Copyright (c) <2003-2016> <Newton Game Dynamics>
* 
* This software is provided 'as-is', without any express or implied
* warranty. In no event will the authors be held liable for any damages
* arising from the use of this software.
* 
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely
*/

#include "dAnimationStdAfx.h"
#include "dAnimationEffectorBlendRoot.h"

dAnimationEffectorBlendRoot::dAnimationEffectorBlendRoot(dAnimationCharacterRig* const character, dAnimationEffectorBlendNode* const childNode)
	:dAnimationEffectorBlendNode(character)
	,m_pose(character)
	,m_childNode (childNode)
{
}

dAnimationEffectorBlendRoot::~dAnimationEffectorBlendRoot()
{
	if (m_childNode) {
		delete m_childNode;
	}
}

void dAnimationEffectorBlendRoot::Update(dFloat timestep)
{
	dAssert(0);
}

void dAnimationEffectorBlendRoot::Evaluate(dAnimationPose& output, dFloat timestep)
{
	dAssert(0);
}