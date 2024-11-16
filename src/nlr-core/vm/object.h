// Licensed to the NiTiS-Dev under one or more agreements.
// The NiTiS-Dev licenses this file to you under the MIT license.

#ifndef _NLR_OBJECT_H
#define _NLR_OBJECT_H

#include "../support.h"

NLR_BEGIN_NAMESPACE

typedef struct Type *TypeHandle;

typedef struct Object *ObjectHandle;

struct ObjectHeader {
	TypeHandle object_type;
};

/// @brief Dereference object.
/// @tparam Type Strict type.
/// @param object Object to dereference.
/// @return Value stored in object.
template<typename Type>
NLR_API constexpr Type dereference_object(ObjectHandle object) noexcept {
	Type retusa;
	memmove(&retusa, object, sizeof(Type));
	return retusa;
}

/// @brief Returns TypeHandle of object.
/// @param object Object to get type of.
/// @return TypeHandle of object.
NLR_API constexpr TypeHandle get_object_type(ObjectHandle object) noexcept {
	ObjectHeader *header = move_ptr<ObjectHeader>(object, -sizeof(ObjectHeader));
	return header->object_type;
}

NLR_END_NAMESPACE
#endif