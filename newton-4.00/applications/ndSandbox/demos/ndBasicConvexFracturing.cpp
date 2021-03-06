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

#include "ndSandboxStdafx.h"
#include "ndSkyBox.h"
#include "ndTargaToOpenGl.h"
#include "ndDemoMesh.h"
#include "ndDemoCamera.h"
#include "ndPhysicsUtils.h"
#include "ndPhysicsWorld.h"
#include "ndMakeStaticMap.h"
#include "ndDemoEntityManager.h"
#include "ndSimpleConvexFracture.h"

void ndBasicConvexFracturing(ndDemoEntityManager* const scene)
{
	// build a floor
	BuildFloorBox(scene);

	ndPhysicsWorld* const world = scene->GetWorld();
	ndSimpleConvexFracture* const fractureManager = new ndSimpleConvexFracture(scene);
	world->AddModel(fractureManager);
	world->RegisterModelUpdate(fractureManager);

	dInt32 woodX = 3;
	dInt32 woodZ = 3;
	dMatrix matrix(dGetIdentityMatrix());
	matrix.m_posit.m_x += 10.0f;
	matrix.m_posit.m_y += 2.0f;

//woodX = 1;
//woodZ = 1;

	ndShapeInstance shape0(new ndShapeCylinder(0.5f, 0.5f, 3.0f));
	fractureManager->AddFracturedWoodPrimitive(scene, shape0, 10.0f, 1000.0f, matrix.m_posit, woodX, woodZ, 1.0f, 0, 0);

	matrix.m_posit.m_x += 10.0f;
	matrix.m_posit.m_z += 4.0f;
	ndShapeInstance shape1(new ndShapeCapsule(0.5f, 0.5f, 3.0f));
	fractureManager->AddFracturedWoodPrimitive(scene, shape1, 10.0f, 1000.0f, matrix.m_posit, woodX, woodZ, 1.0f, 0, 0);

	dQuaternion rot;
	//dVector origin(-80.0f, 5.0f, 0.0f, 0.0f);
	//dVector origin(-60.0f, 5.0f, 0.0f, 0.0f);
	dVector origin(-10.0f, 5.0f, 0.0f, 0.0f);
	scene->SetCameraMatrix(rot, origin);
}
