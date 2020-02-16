// DynView.cpp : implementation file
//

#include "stdafx.h"
#include "DynViewsApp.h"
#include "DynView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DynView

IMPLEMENT_DYNCREATE(DynView, CView)

DynView::DynView()
{
}

DynView::~DynView()
{
	if(! m_points.IsEmpty()) {
		POSITION pos = m_points.GetHeadPosition();
		while(pos != NULL)
			delete ((ViewPosition*) m_points.GetNext(pos));
	};
}


BEGIN_MESSAGE_MAP(DynView, CView)
	//{{AFX_MSG_MAP(DynView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DynView drawing

void DynView::OnDraw(CDC* pDC)
{

	CRect rect;
	GetClientRect(&rect);
	
	pDC->DrawEdge(rect, EDGE_ETCHED, BF_RECT);

	// pDC->SelectStockObject(BLACK_PEN);

	BOOL first = TRUE;
	POSITION pos = m_points.GetHeadPosition();
	while(pos != NULL) {
		ViewPosition* p = (ViewPosition*) m_points.GetNext(pos);
		if(first) { pDC->MoveTo(p->m_location); first = FALSE; }
		pDC->LineTo(p->m_location);
	};
}

/////////////////////////////////////////////////////////////////////////////
// DynView diagnostics

#ifdef _DEBUG
void DynView::AssertValid() const
{
	CView::AssertValid();
}

void DynView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// DynView message handlers

void DynView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	m_points.AddTail(new ViewPosition(point));
	
	CView::OnLButtonDown(nFlags, point);

	Invalidate();
}

void DynView::OnMouseMove(UINT nFlags, CPoint point) 
{
	if(nFlags && MK_LBUTTON) {
		m_points.AddTail(new ViewPosition(point));
		Invalidate();
	}

	CView::OnMouseMove(nFlags, point);
}

