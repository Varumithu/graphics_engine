#pragma once
#include "Mesh.h"
#include <vector>
#include "GraphicsEngine/Vector3.h"

#include <string>


class MeshObjFile : public Mesh
{
public:
	MeshObjFile(const char * filepath);

	virtual void Init();
	virtual void Deinit();

private:
	std::string m_filepath;
};
