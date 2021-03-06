#pragma once

#include "CoreMinimal.h"

#include "LuaObjectBase.h"

class BLUELUA_API FLuaUDelegate : public FLuaObjectBase
{
public:
	FLuaUDelegate(UObject* InOwner, void* InSource, UFunction* InFunction, bool InbIsMulticast);
	~FLuaUDelegate();

	static int Push(lua_State* L, UObject* Owner, void* InSource, UFunction* InFunction, bool InbIsMulticast, void* InBuffer = nullptr);
	static bool Fetch(lua_State* L, int32 Index, UFunction* InFunction, FScriptDelegate* InScriptDelegate);
	static int CreateDelegate(lua_State* L);
	static int DeleteDelegate(lua_State* L);
	static int CreateLatentAction(lua_State* L);

protected:
	static int Index(lua_State* L);
	static int ToString(lua_State* L);
	static int Add(lua_State* L);
	static int Remove(lua_State* L);

	static const char* UDELEGATE_METATABLE;

protected:
	UObject* Owner;
	void* Source;
	UFunction* Function;
	bool bIsMulticast;
};
