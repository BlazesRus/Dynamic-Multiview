// MultiViewDoc.cpp : implementation of the MultiViewDoc class
//

#include "StdMultiView.h"
#include "MultiViewApp.h"

#include "MultiViewDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// MultiViewDoc

IMPLEMENT_DYNCREATE(MultiViewDoc, CDocument)

BEGIN_MESSAGE_MAP(MultiViewDoc, CDocument)
	//{{AFX_MSG_MAP(MultiViewDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// MultiViewDoc construction/destruction

MultiViewDoc::MultiViewDoc()
{
	// TODO: add one-time construction code here
	m_str="Hello from document";
}

MultiViewDoc::~MultiViewDoc()
{
}

BOOL MultiViewDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// MultiViewDoc serialization

void MultiViewDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// MultiViewDoc diagnostics

#ifdef _DEBUG
void MultiViewDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void MultiViewDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// MultiViewDoc commands
