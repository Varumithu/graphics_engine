#include "MaterialUnlitSimpleChoosable.h"
#include "GraphicsEngine/Transform.h"
#include "GraphicsEngine/MathUtils.h"
#include "GraphicsEngine/SceneUtils.h"
#include "GraphicsEngine/Time.h"
#include <cmath>

MaterialUnlitSimpleChoosable::MaterialUnlitSimpleChoosable(std::string vs_shader, std::string ps_shader)
{
    m_vsFileName = vs_shader;
    m_psFileName = ps_shader;
}

// TODO: Реализовать переключение Graphics API при нажатии на кнопки (1 - DirectX 11, 2 - OpenGL 2.0, 9 - DirectX 9)
// и отладить на этом механизм использования функций Init() и Deinit()
void MaterialUnlitSimpleChoosable::Init()
{
    Material::Init();

    // TODO: Нужно при компиляции скопировать папку с шейдерами
    // Google it: "visual studio during build copy files into application folder"
}

void MaterialUnlitSimpleChoosable::Deinit()
{
    Material::Deinit();
}

void MaterialUnlitSimpleChoosable::SetMaterial(const Object * pObject)
{
    // Заполняем матрицы World, View, Proj
    const Matrix4x4 & matWorld	= SceneUtils::GetMatrixWorld(pObject);
    const Matrix4x4 & matView	= SceneUtils::GetMatrixView();
    const Matrix4x4 & matProj	= SceneUtils::GetMatrixProj();

    const Matrix4x4 matWorldViewProjT = MathUtils::GetMatrixWorldViewProjT(matWorld, matView, matProj);
    double time = Time::GetTime();
    SetMaterialBegin();
    {
        SetVertexShaderBegin();
        SetVertexShaderMatrix4x4("matrixWorldViewProjT", matWorldViewProjT);
        SetVertexShaderVector4("constColor", Vector4(1, 1, 1, 1));
        SetVertexShaderVector4("time", Vector4(time, 1, 1, 1));
        SetVertexShaderEnd();

        SetPixelShaderBegin();
        SetPixelShaderEnd();
    }
    SetMaterialEnd();
}
