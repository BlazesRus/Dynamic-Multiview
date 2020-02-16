#if !defined(AFX_DynView_H__C72843BE_35BA_4E59_B2A9_0B5A55DC572F__INCLUDED_)
#define AFX_DynView_H__C72843BE_35BA_4E59_B2A9_0B5A55DC572F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DynView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DynView view

// This view encapsulates a personalized 2D view
class DynView : public CView
{

	class ViewPosition : public CObject  
	{		
	public:
		ViewPosition(CPoint location) { m_location = location; }
		CPoint	m_location;
	};

public:
	DynView();
	virtual ~DynView();

public:
	int		m_idView;

protected:
	DECLARE_DYNCREATE(DynView)

// Attributes
protected:
	CObList		m_points;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DynView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(DynView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DynView_H__C72843BE_35BA_4E59_B2A9_0B5A55DC572F__INCLUDED_)
