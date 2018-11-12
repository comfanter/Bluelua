#pragma once

#include "CoreMinimal.h"

#include "LuaDelegateCaller.generated.h"

class FLuaState;

UCLASS()
class BLUELUA_API ULuaDelegateCaller : public UObject
{
	GENERATED_BODY()

public:
	virtual void ProcessEvent(UFunction* Function, void* Parameters) override;
	virtual void BeginDestroy() override;

	static ULuaDelegateCaller* CreateDelegate(UObject* InDelegateOwner, TSharedPtr<FLuaState> InLuaState, UFunction* InSignatureFunction, int InLuaFunctionIndex);

	void BindLuaState(TSharedPtr<FLuaState> InLuaState);
	void BindDelegateOwner(UObject* InOwner);
	void BindLuaFunction(UFunction* InSignatureFunction, int InLuaFunctionIndex);
	void BindLuaFunctionOwner(int InLuaFunctionOwerIndex);
	void ReleaseLuaFunction();
	bool IsBound();

	UFUNCTION()
	void NeverUsed() {}

protected:
	TWeakPtr<FLuaState> LuaState;
	TWeakObjectPtr<UObject> DelegateOwner;

	UFunction* SignatureFunction = nullptr;
	int LuaFunctionIndex = -2;
	int LuaFunctionOwnerIndex = -2;
};