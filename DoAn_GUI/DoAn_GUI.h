
// DoAn_GUI.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CDoAnGUIApp:
// See DoAn_GUI.cpp for the implementation of this class
//

class CDoAnGUIApp : public CWinApp
{
public:
	CDoAnGUIApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CDoAnGUIApp theApp;
