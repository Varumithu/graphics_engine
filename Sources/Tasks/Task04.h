﻿#pragma once
#include "GraphicsEngine/Application.h"
#include "GraphicsEngine/GraphicsEngine.h"
#include "GraphicsEngine/Light.h"
#include "GraphicsEngine/Materials/MaterialDiffuse.h"
#include "GraphicsEngine/Meshes/MeshSphere.h"
#include "GraphicsEngine/Object.h"
#include "GraphicsEngine/Scene.h"
#include "GraphicsEngine/Transform.h"

#include "GraphicsEngine/Camera.h"

#include "Tasks/Task.h"
#include "Tasks/ObjectRotator.h"

/**
* @brief Shows how to write lightning materials.
* Key code is situated in the classes MaterialDiffuse, Light.
*/
class Task04: public Task
{
public:
	virtual ~Task04() { }

	virtual void Init()
	{
		Scene & scene = Application::Instance().GetScene();
		
		// Camera
		{
			Object * pCameraObj = new Object();
            pCameraObj->m_pTransform = new Transform( Vector3(0.0, 0.0,-7.0), Vector3(0.0, 0.0, 0.0));
			Camera * pCamera = new Camera();
			pCameraObj->AddComponent( pCamera );

			scene.SetCamera( pCamera );
		}

		// Object - Sphere
		{
			Object * pObject1 = new Object();

			pObject1->m_pTransform	= new Transform(0,0,0, 0,0,0, 3,3,3);
			pObject1->m_pMesh		= new MeshSphere(20);
            pObject1->m_pMaterial	= new MaterialDiffuse();
            pObject1->m_pMaterial->reflectiveness = 500.0;

            pObject1->AddComponent( new ObjectRotator(0,10,0) );

			scene.AddObject( pObject1 );
		}

        // Ligth source #1 - Directional
//        {
//            Light * pLight = new Light(LIGHT_DIRECTIONAL);
//            pLight->SetColor(1,1,0);
//            pLight->SetIntensity(1);

//            Object * pLightObject = new Object();
//            pLightObject->m_pTransform	= new Transform(1,0,0, 90,0,0, 1,1,1);
//            pLightObject->AddComponent(pLight);

//            scene.AddLight(pLight);
//        }

      //   Ligth source #2 - Point
        {
            Light * pLight = new Light(LIGHT_POINT);
            pLight->SetColor(1,1,1);
            pLight->SetIntensity(1);

            pLight->SetAttenuationCoefficient(0.001f);

            Object * pLightObject = new Object();
            pLightObject->m_pTransform	= new Transform(60,0,-20, 0,0,0, 1,1,1);
            pLightObject->AddComponent(pLight);

            scene.AddLight(pLight);
        }

        // Ligth source #3 - Spot
        {
            Light * pLight = new Light(LIGHT_SPOT);
            pLight->SetColor(1,1,0);
            pLight->SetIntensity(1);

            pLight->SetAttenuationCoefficient(0.01f);
            pLight->SetOuterAngle(0.6f);
            pLight->SetInnerAngle(0.075f);
            Object * pLightObject = new Object();
            pLightObject->m_pTransform	= new Transform( 0.0, 0.0,-7.0, 0.0, 0.0, 0.0, 1,1,1);
            pLightObject->AddComponent(pLight);
            pLightObject->AddComponent( new ObjectRotator(0,10,0) );
            scene.AddLight(pLight);
        }

        // FPS counter
//		{
//			Object * pObject = new Object();
//			pObject->m_pTransform	= new Transform();
//			pObject->AddComponent( new FpsCounter() );

//			scene.AddObject( pObject );
//		}
	}

	virtual void Update()
	{
		
	}
};
