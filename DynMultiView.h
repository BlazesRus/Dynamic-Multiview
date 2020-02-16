// MultiView.h : interface of the MultiView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(Multiview_Included)
#define Multiview_Included

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DynView.h"

class MultiView : public DynView
{
protected: // create from serialization only
	MultiView();
	DECLARE_DYNCREATE(MultiView)

// Attributes
public:
	MultiViewDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(MultiView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~MultiView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(MultiView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MultiView.cpp
inline MultiViewDoc* MultiView::GetDocument()
   { return (MultiViewDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif
