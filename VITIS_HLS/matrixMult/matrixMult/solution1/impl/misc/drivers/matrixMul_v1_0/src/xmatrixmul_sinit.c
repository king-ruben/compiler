// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.2 (64-bit)
// Tool Version Limit: 2019.12
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xmatrixmul.h"

extern XMatrixmul_Config XMatrixmul_ConfigTable[];

XMatrixmul_Config *XMatrixmul_LookupConfig(u16 DeviceId) {
	XMatrixmul_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XMATRIXMUL_NUM_INSTANCES; Index++) {
		if (XMatrixmul_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XMatrixmul_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XMatrixmul_Initialize(XMatrixmul *InstancePtr, u16 DeviceId) {
	XMatrixmul_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XMatrixmul_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XMatrixmul_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

