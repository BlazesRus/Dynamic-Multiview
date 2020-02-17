// ***********************************************************************
// Edited/Merged by James Michael Armstrong (https://github.com/BlazesRus)
// Multi-view features/code based on https://www.codeproject.com/Articles/7686/Using-Multiview
// and https://www.codeproject.com/Articles/1483/Creation-of-Multiple-Dynamic-Views
// ***********************************************************************
#pragma once
#include DynMultiViewApp_IncludeGuard
#if !defined(DynMultiViewApp_IncludeGuard)
#define DynMultiViewApp_IncludeGuard

#ifndef __AFXWIN_H__
	#error include 'StdMultiView.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

class DynMultiViewApp : public CWinApp
{
	CView* m_pPrimaryView;
	CView* m_pSecondaryView;
public:
	DynMultiViewApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DynMultiViewApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(DynMultiViewApp)
	afx_msg void OnAppAbout();
	afx_msg void OnViewPrimaryView();
	afx_msg void OnViewSecondaryView();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
#endif