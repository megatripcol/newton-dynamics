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

#ifndef _D_MESH_H_
#define _D_MESH_H_

#include "ndSandboxStdafx.h"
class ndDemoMesh;
class ndDemoEntity;
class ShaderPrograms;
class ndDemoEntityManager;

class ndDemoSubMesh
{
	public:
	ndDemoSubMesh();
	~ndDemoSubMesh();

	void Render() const;
	void AllocIndexData(int indexCount);
	void OptimizeForRender(const ndDemoMesh* const mesh) const;

	void SetOpacity(dFloat32 opacity);

	dVector m_ambient;
	dVector m_diffuse;
	dVector m_specular;
	dString  m_textureName;
	dFloat32 m_opacity;
	dFloat32 m_shiness;
	int m_indexCount;
	unsigned m_shader;
	unsigned m_textureHandle;
	unsigned *m_indexes;
};

//class DemoMeshInterface: public dClassInfo  
class ndDemoMeshInterface: public dRefCounter
{
	public:
	ndDemoMeshInterface();
	~ndDemoMeshInterface();
	const dString& GetName () const;

	bool GetVisible () const;
	void SetVisible (bool visibilityFlag);

	virtual ndDemoMeshInterface* Clone(ndDemoEntity* const owner) { dAssert(0); return NULL; }

	virtual void RenderTransparency () const = 0;
	virtual void Render (ndDemoEntityManager* const scene) = 0;
	virtual void RenderNormals () = 0;
	//virtual NewtonMesh* CreateNewtonMesh(NewtonWorld* const world, const dMatrix& meshMatrix) = 0;
	//dAddRtti(dClassInfo,DOMMY_API);

	dString m_name;
	bool m_isVisible;
};

class ndDemoMesh: public ndDemoMeshInterface, public dList<ndDemoSubMesh>
{
	public:
	ndDemoMesh(const ndDemoMesh& mesh, const ShaderPrograms& shaderCache);
	ndDemoMesh(const char* const name, const ShaderPrograms& shaderCache);
	//ndDemoMesh(NewtonMesh* const mesh, const ShaderPrograms& shaderCache);
	//ndDemoMesh(const dScene* const scene, dScene::dTreeNode* const meshNode, const ShaderPrograms& shaderCache);
	//ndDemoMesh(const char* const name, const ShaderPrograms& shaderCache, const NewtonCollision* const collision, const char* const texture0, const char* const texture1, const char* const texture2, dFloat32 opacity = 1.0f, const dMatrix& uvMatrix = dGetIdentityMatrix());
	ndDemoMesh(const char* const name, const ShaderPrograms& shaderCache, dFloat32* const elevation, int size, dFloat32 cellSize, dFloat32 texelsDensity, int tileSize);

	virtual ndDemoMeshInterface* Clone(ndDemoEntity* const owner) 
	{ 
		dAssert(0);
		return (ndDemoMeshInterface*)AddRef();
	}

	//using dClassInfo::operator new;
	//using dClassInfo::operator delete;

	ndDemoSubMesh* AddSubMesh();
	void AllocVertexData (int vertexCount);

	virtual const dString& GetTextureName (const ndDemoSubMesh* const subMesh) const;

    virtual void RenderTransparency () const;
	virtual void Render (ndDemoEntityManager* const scene);
	virtual void RenderNormals ();

	void OptimizeForRender();
	//virtual NewtonMesh* CreateNewtonMesh(NewtonWorld* const world, const dMatrix& meshMatrix);

	protected:
	virtual ~ndDemoMesh();

	//dAddRtti (DemoMeshInterface, DOMMY_API);
	
	void  ResetOptimization();
	void  SpliteSegment(dListNode* const node, int maxIndexCount);

	public:
	int m_vertexCount;
	dFloat32* m_uv;
	dFloat32* m_vertex;
	dFloat32* m_normal;
	unsigned m_optimizedOpaqueDiplayList;
	unsigned m_optimizedTransparentDiplayList;		
};

/*
class DemoSkinMesh: public ndDemoMeshInterface
{
	public:
	struct dWeightBoneIndex
	{
		int m_boneIndex[4];
	};

	DemoSkinMesh(const DemoSkinMesh& clone, ndDemoEntity* const owner);
	DemoSkinMesh(dScene* const scene, ndDemoEntity* const owner, dScene::dTreeNode* const meshNode, const dTree<ndDemoEntity*, dScene::dTreeNode*>& boneMap, const ShaderPrograms& shaderCache);
	~DemoSkinMesh();

	void Render (ndDemoEntityManager* const scene);
	void RenderNormals ();
	void RenderTransparency () const;
	NewtonMesh* CreateNewtonMesh(NewtonWorld* const world, const dMatrix& meshMatrix);

	protected: 
	virtual ndDemoMeshInterface* Clone(ndDemoEntity* const owner);
	int CalculateMatrixPalette(dMatrix* const bindMatrix) const;
	void ConvertToGlMatrix(int count, const dMatrix* const bindMatrix, GLfloat* const glMatrices) const;
	//dGeometryNodeSkinClusterInfo* FindSkinModifier(dScene* const scene, dScene::dTreeNode* const meshNode) const;
	void OptimizeForRender(const ndDemoSubMesh& segment, const dVector* const pointWeights, const dWeightBoneIndex* const pointSkinBone) const;

	ndDemoMesh* m_mesh;
	ndDemoEntity* m_entity; 
	dMatrix* m_bindingMatrixArray;
	int m_nodeCount; 
	int m_shader;
};

class DemoBezierCurve: public ndDemoMeshInterface
{
	public:
	DemoBezierCurve(const dBezierSpline& curve);
	DemoBezierCurve(const dScene* const scene, dScene::dTreeNode* const meshNode);

	int GetRenderResolution() const;
	void SetRenderResolution(int breaks);

	virtual void RenderTransparency() const;
	virtual void Render(ndDemoEntityManager* const scene);
	virtual void RenderNormals();

	virtual NewtonMesh* CreateNewtonMesh(NewtonWorld* const world, const dMatrix& meshMatrix);

	dBezierSpline m_curve;
	int m_renderResolution;

	//dAddRtti(DemoMeshInterface, DOMMY_API);
};
*/
#endif 


