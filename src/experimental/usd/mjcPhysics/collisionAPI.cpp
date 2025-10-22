//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include <mujoco/experimental/usd/mjcPhysics/collisionAPI.h>
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<MjcPhysicsCollisionAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
MjcPhysicsCollisionAPI::~MjcPhysicsCollisionAPI()
{
}

/* static */
MjcPhysicsCollisionAPI
MjcPhysicsCollisionAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return MjcPhysicsCollisionAPI();
    }
    return MjcPhysicsCollisionAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind MjcPhysicsCollisionAPI::_GetSchemaKind() const
{
    return MjcPhysicsCollisionAPI::schemaKind;
}

/* static */
bool
MjcPhysicsCollisionAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<MjcPhysicsCollisionAPI>(whyNot);
}

/* static */
MjcPhysicsCollisionAPI
MjcPhysicsCollisionAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<MjcPhysicsCollisionAPI>()) {
        return MjcPhysicsCollisionAPI(prim);
    }
    return MjcPhysicsCollisionAPI();
}

/* static */
const TfType &
MjcPhysicsCollisionAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<MjcPhysicsCollisionAPI>();
    return tfType;
}

/* static */
bool 
MjcPhysicsCollisionAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
MjcPhysicsCollisionAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
MjcPhysicsCollisionAPI::GetGroupAttr() const
{
    return GetPrim().GetAttribute(MjcPhysicsTokens->mjcGroup);
}

UsdAttribute
MjcPhysicsCollisionAPI::CreateGroupAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(MjcPhysicsTokens->mjcGroup,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
MjcPhysicsCollisionAPI::GetShellInertiaAttr() const
{
    return GetPrim().GetAttribute(MjcPhysicsTokens->mjcShellinertia);
}

UsdAttribute
MjcPhysicsCollisionAPI::CreateShellInertiaAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(MjcPhysicsTokens->mjcShellinertia,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
MjcPhysicsCollisionAPI::GetPriorityAttr() const
{
    return GetPrim().GetAttribute(MjcPhysicsTokens->mjcPriority);
}

UsdAttribute
MjcPhysicsCollisionAPI::CreatePriorityAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(MjcPhysicsTokens->mjcPriority,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
MjcPhysicsCollisionAPI::GetConDimAttr() const
{
    return GetPrim().GetAttribute(MjcPhysicsTokens->mjcCondim);
}

UsdAttribute
MjcPhysicsCollisionAPI::CreateConDimAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(MjcPhysicsTokens->mjcCondim,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
MjcPhysicsCollisionAPI::GetSolMixAttr() const
{
    return GetPrim().GetAttribute(MjcPhysicsTokens->mjcSolmix);
}

UsdAttribute
MjcPhysicsCollisionAPI::CreateSolMixAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(MjcPhysicsTokens->mjcSolmix,
                       SdfValueTypeNames->Double,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
MjcPhysicsCollisionAPI::GetSolRefAttr() const
{
    return GetPrim().GetAttribute(MjcPhysicsTokens->mjcSolref);
}

UsdAttribute
MjcPhysicsCollisionAPI::CreateSolRefAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(MjcPhysicsTokens->mjcSolref,
                       SdfValueTypeNames->DoubleArray,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
MjcPhysicsCollisionAPI::GetSolImpAttr() const
{
    return GetPrim().GetAttribute(MjcPhysicsTokens->mjcSolimp);
}

UsdAttribute
MjcPhysicsCollisionAPI::CreateSolImpAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(MjcPhysicsTokens->mjcSolimp,
                       SdfValueTypeNames->DoubleArray,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
MjcPhysicsCollisionAPI::GetMarginAttr() const
{
    return GetPrim().GetAttribute(MjcPhysicsTokens->mjcMargin);
}

UsdAttribute
MjcPhysicsCollisionAPI::CreateMarginAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(MjcPhysicsTokens->mjcMargin,
                       SdfValueTypeNames->Double,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
MjcPhysicsCollisionAPI::GetGapAttr() const
{
    return GetPrim().GetAttribute(MjcPhysicsTokens->mjcGap);
}

UsdAttribute
MjcPhysicsCollisionAPI::CreateGapAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(MjcPhysicsTokens->mjcGap,
                       SdfValueTypeNames->Double,
                       /* custom = */ false,
                       SdfVariabilityUniform,
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
MjcPhysicsCollisionAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        MjcPhysicsTokens->mjcGroup,
        MjcPhysicsTokens->mjcShellinertia,
        MjcPhysicsTokens->mjcPriority,
        MjcPhysicsTokens->mjcCondim,
        MjcPhysicsTokens->mjcSolmix,
        MjcPhysicsTokens->mjcSolref,
        MjcPhysicsTokens->mjcSolimp,
        MjcPhysicsTokens->mjcMargin,
        MjcPhysicsTokens->mjcGap,
    };
    static TfTokenVector allNames =
        _ConcatenateAttributeNames(
            UsdAPISchemaBase::GetSchemaAttributeNames(true),
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
