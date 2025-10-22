//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include <mujoco/experimental/usd/mjcPhysics/keyframe.h>
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<MjcPhysicsKeyframe,
        TfType::Bases< UsdTyped > >();
    
    // Register the usd prim typename as an alias under UsdSchemaBase. This
    // enables one to call
    // TfType::Find<UsdSchemaBase>().FindDerivedByName("MjcKeyframe")
    // to find TfType<MjcPhysicsKeyframe>, which is how IsA queries are
    // answered.
    TfType::AddAlias<UsdSchemaBase, MjcPhysicsKeyframe>("MjcKeyframe");
}

/* virtual */
MjcPhysicsKeyframe::~MjcPhysicsKeyframe()
{
}

/* static */
MjcPhysicsKeyframe
MjcPhysicsKeyframe::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return MjcPhysicsKeyframe();
    }
    return MjcPhysicsKeyframe(stage->GetPrimAtPath(path));
}

/* static */
MjcPhysicsKeyframe
MjcPhysicsKeyframe::Define(
    const UsdStagePtr &stage, const SdfPath &path)
{
    static TfToken usdPrimTypeName("MjcKeyframe");
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return MjcPhysicsKeyframe();
    }
    return MjcPhysicsKeyframe(
        stage->DefinePrim(path, usdPrimTypeName));
}

/* virtual */
UsdSchemaKind MjcPhysicsKeyframe::_GetSchemaKind() const
{
    return MjcPhysicsKeyframe::schemaKind;
}

/* static */
const TfType &
MjcPhysicsKeyframe::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<MjcPhysicsKeyframe>();
    return tfType;
}

/* static */
bool 
MjcPhysicsKeyframe::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
MjcPhysicsKeyframe::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
MjcPhysicsKeyframe::GetMjcQposAttr() const
{
    return GetPrim().GetAttribute(MjcPhysicsTokens->mjcQpos);
}

UsdAttribute
MjcPhysicsKeyframe::CreateMjcQposAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(MjcPhysicsTokens->mjcQpos,
                       SdfValueTypeNames->DoubleArray,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
MjcPhysicsKeyframe::GetMjcQvelAttr() const
{
    return GetPrim().GetAttribute(MjcPhysicsTokens->mjcQvel);
}

UsdAttribute
MjcPhysicsKeyframe::CreateMjcQvelAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(MjcPhysicsTokens->mjcQvel,
                       SdfValueTypeNames->DoubleArray,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
MjcPhysicsKeyframe::GetMjcActAttr() const
{
    return GetPrim().GetAttribute(MjcPhysicsTokens->mjcAct);
}

UsdAttribute
MjcPhysicsKeyframe::CreateMjcActAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(MjcPhysicsTokens->mjcAct,
                       SdfValueTypeNames->DoubleArray,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
MjcPhysicsKeyframe::GetMjcCtrlAttr() const
{
    return GetPrim().GetAttribute(MjcPhysicsTokens->mjcCtrl);
}

UsdAttribute
MjcPhysicsKeyframe::CreateMjcCtrlAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(MjcPhysicsTokens->mjcCtrl,
                       SdfValueTypeNames->DoubleArray,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
MjcPhysicsKeyframe::GetMjcMposAttr() const
{
    return GetPrim().GetAttribute(MjcPhysicsTokens->mjcMpos);
}

UsdAttribute
MjcPhysicsKeyframe::CreateMjcMposAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(MjcPhysicsTokens->mjcMpos,
                       SdfValueTypeNames->DoubleArray,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
MjcPhysicsKeyframe::GetMjcMquatAttr() const
{
    return GetPrim().GetAttribute(MjcPhysicsTokens->mjcMquat);
}

UsdAttribute
MjcPhysicsKeyframe::CreateMjcMquatAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(MjcPhysicsTokens->mjcMquat,
                       SdfValueTypeNames->DoubleArray,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

namespace {
static inline TfTokenVector
_ConcatenateAttributeNames(const TfTokenVector& left,const TfTokenVector& right)
{
    TfTokenVector result;
    result.reserve(left.size() + right.size());
    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), right.begin(), right.end());
    return result;
}
}

/*static*/
const TfTokenVector&
MjcPhysicsKeyframe::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        MjcPhysicsTokens->mjcQpos,
        MjcPhysicsTokens->mjcQvel,
        MjcPhysicsTokens->mjcAct,
        MjcPhysicsTokens->mjcCtrl,
        MjcPhysicsTokens->mjcMpos,
        MjcPhysicsTokens->mjcMquat,
    };
    static TfTokenVector allNames =
        _ConcatenateAttributeNames(
            UsdTyped::GetSchemaAttributeNames(true),
            localNames);

    if (includeInherited)
        return allNames;
    else
        return localNames;
}

PXR_NAMESPACE_CLOSE_SCOPE

// ===================================================================== //
// Feel free to add custom code below this line. It will be preserved by
// the code generator.
//
// Just remember to wrap code in the appropriate delimiters:
// 'PXR_NAMESPACE_OPEN_SCOPE', 'PXR_NAMESPACE_CLOSE_SCOPE'.
// ===================================================================== //
// --(BEGIN CUSTOM CODE)--
