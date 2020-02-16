// MultiView.cpp : implementation of the MultiView class
//

#include "stdafx.h"
#include "MultiViewApp.h"

#include "MultiViewDoc.h"
#include "MultiView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// MultiView

IMPLEMENT_DYNCREATE(MultiView, CView)

BEGIN_MESSAGE_MAP(MultiView, CView)
	//{{AFX_MSG_MAP(MultiView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// MultiView construction/destruction

MultiView::MultiView()
{
	// TODO: add construction code here

}

MultiView::~MultiView()
{
}


/////////////////////////////////////////////////////////////////////////////
// MultiView drawing

void MultiView::OnDraw(CDC* pDC)
{
	MultiViewDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(400,300,"First view"); 
	pDC->TextOut(400,320,pDoc->m_str);  
}

/////////////////////////////////////////////////////////////////////////////
// MultiView diagnostics

#ifdef _DEBUG
void MultiView::AssertValid() const
{
	CView::AssertValid();
}

void MultiView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

MultiViewDoc* MultiView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(MultiViewDoc)));
	return (MultiViewDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// MultiView message handlers
