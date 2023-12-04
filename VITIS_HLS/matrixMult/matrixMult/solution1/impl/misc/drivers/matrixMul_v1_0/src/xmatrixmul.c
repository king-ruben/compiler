// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.2 (64-bit)
// Tool Version Limit: 2019.12
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xmatrixmul.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XMatrixmul_CfgInitialize(XMatrixmul *InstancePtr, XMatrixmul_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XMatrixmul_Start(XMatrixmul *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMatrixmul_ReadReg(InstancePtr->Control_BaseAddress, XMATRIXMUL_CONTROL_ADDR_AP_CTRL) & 0x80;
    XMatrixmul_WriteReg(InstancePtr->Control_BaseAddress, XMATRIXMUL_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XMatrixmul_IsDone(XMatrixmul *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMatrixmul_ReadReg(InstancePtr->Control_BaseAddress, XMATRIXMUL_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XMatrixmul_IsIdle(XMatrixmul *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMatrixmul_ReadReg(InstancePtr->Control_BaseAddress, XMATRIXMUL_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XMatrixmul_IsReady(XMatrixmul *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMatrixmul_ReadReg(InstancePtr->Control_BaseAddress, XMATRIXMUL_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XMatrixmul_Continue(XMatrixmul *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMatrixmul_ReadReg(InstancePtr->Control_BaseAddress, XMATRIXMUL_CONTROL_ADDR_AP_CTRL) & 0x80;
    XMatrixmul_WriteReg(InstancePtr->Control_BaseAddress, XMATRIXMUL_CONTROL_ADDR_AP_CTRL, Data | 0x10);
}

void XMatrixmul_EnableAutoRestart(XMatrixmul *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMatrixmul_WriteReg(InstancePtr->Control_BaseAddress, XMATRIXMUL_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XMatrixmul_DisableAutoRestart(XMatrixmul *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMatrixmul_WriteReg(InstancePtr->Control_BaseAddress, XMATRIXMUL_CONTROL_ADDR_AP_CTRL, 0);
}

void XMatrixmul_InterruptGlobalEnable(XMatrixmul *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMatrixmul_WriteReg(InstancePtr->Control_BaseAddress, XMATRIXMUL_CONTROL_ADDR_GIE, 1);
}

void XMatrixmul_InterruptGlobalDisable(XMatrixmul *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMatrixmul_WriteReg(InstancePtr->Control_BaseAddress, XMATRIXMUL_CONTROL_ADDR_GIE, 0);
}

void XMatrixmul_InterruptEnable(XMatrixmul *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMatrixmul_ReadReg(InstancePtr->Control_BaseAddress, XMATRIXMUL_CONTROL_ADDR_IER);
    XMatrixmul_WriteReg(InstancePtr->Control_BaseAddress, XMATRIXMUL_CONTROL_ADDR_IER, Register | Mask);
}

void XMatrixmul_InterruptDisable(XMatrixmul *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMatrixmul_ReadReg(InstancePtr->Control_BaseAddress, XMATRIXMUL_CONTROL_ADDR_IER);
    XMatrixmul_WriteReg(InstancePtr->Control_BaseAddress, XMATRIXMUL_CONTROL_ADDR_IER, Register & (~Mask));
}

void XMatrixmul_InterruptClear(XMatrixmul *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMatrixmul_WriteReg(InstancePtr->Control_BaseAddress, XMATRIXMUL_CONTROL_ADDR_ISR, Mask);
}

u32 XMatrixmul_InterruptGetEnabled(XMatrixmul *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMatrixmul_ReadReg(InstancePtr->Control_BaseAddress, XMATRIXMUL_CONTROL_ADDR_IER);
}

u32 XMatrixmul_InterruptGetStatus(XMatrixmul *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMatrixmul_ReadReg(InstancePtr->Control_BaseAddress, XMATRIXMUL_CONTROL_ADDR_ISR);
}

