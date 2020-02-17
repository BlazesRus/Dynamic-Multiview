#include "StdMultiView.h"
#include "DynMultiViewApp.h"

#include "MainFrm.h"
#include "MultiViewDoc.h"
#include "MultiView.h"
#include "AboutDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DynMultiViewApp

BEGIN_MESSAGE_MAP(DynMultiViewApp, CWinApp)
	//{{AFX_MSG_MAP(DynMultiViewApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_COMMAND(ID_VIEW_PRIMARYVIEW, OnViewPrimaryView)
	ON_COMMAND(ID_VIEW_SECONDARYVIEW, OnViewSecondaryView)
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DynMultiViewApp construction

DynMultiViewApp::DynMultiViewApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only DynMultiViewApp object

DynMultiViewApp theApp;

/////////////////////////////////////////////////////////////////////////////
// DynMultiViewApp initialization

BOOL DynMultiViewApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	//LoadStdProfileSettings();  // Load standard INI file options (including MRU)
  
  // Initialize the random generator
	srand( (unsigned)time( NULL ) );

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(MultiViewDoc),
		RUNTIME_CLASS(MainFrame),       // main SDI frame window
		RUNTIME_CLASS(MultiView));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	CView* pActiveView = ((CFrameWnd*) m_pMainWnd)->GetActiveView();
	m_pPrimaryView = pActiveView;
	m_pSecondaryView = (CView*) new MultiView;

	CDocument* pDoc = ((CFrameWnd*)m_pMainWnd)->GetActiveDocument();

	CCreateContext context;
	context.m_pCurrentDoc = pDoc;

	UINT m_ID = AFX_IDW_PANE_FIRST + 1;
	CRect rect; 

	m_pSecondaryView->Create(NULL, NULL, WS_CHILD, rect, m_pMainWnd, m_ID, &context);

	// The one and only window has been initialized, so show and update it.
	m_pMainWnd->ShowWindow(SW_SHOWMAXIMIZED);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}

// App command to run the dialog
void DynMultiViewApp::OnAppAbout()
{
	AboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// DynMultiViewApp message handlers

void DynMultiViewApp::OnViewPrimaryView() 
{
 	// TODO: Add your command handler code here
    
    UINT temp = ::GetWindowWord(m_pSecondaryView->m_hWnd, GWL_ID);
    ::SetWindowWord(m_pSecondaryView->m_hWnd, GWL_ID, ::GetWindowWord(m_pPrimaryView->m_hWnd, GWL_ID));
    ::SetWindowWord(m_pPrimaryView->m_hWnd, GWL_ID, temp);
 
 	m_pSecondaryView->ShowWindow(SW_HIDE);
 	m_pPrimaryView->ShowWindow(SW_SHOW);  	
 	
 	((CFrameWnd*)m_pMainWnd)->SetActiveView(m_pPrimaryView);  
 	((CFrameWnd*)m_pMainWnd)->RecalcLayout();
    m_pPrimaryView->Invalidate();
}

void DynMultiViewApp::OnViewSecondaryView() 
{
	// TODO: Add your command handler code here
	UINT temp = ::GetWindowLong(m_pSecondaryView->m_hWnd, GWL_ID);
    ::SetWindowLong(m_pSecondaryView->m_hWnd, GWL_ID, ::GetWindowLong(m_pPrimaryView->m_hWnd, GWL_ID));
    ::SetWindowLong(m_pPrimaryView->m_hWnd, GWL_ID, temp);

	m_pPrimaryView->ShowWindow(SW_HIDE);
	m_pSecondaryView->ShowWindow(SW_SHOW);  	

	((CFrameWnd*)m_pMainWnd)->SetActiveView(m_pSecondaryView);  
	((CFrameWnd*) m_pMainWnd)->RecalcLayout();
    m_pSecondaryView->Invalidate();
	
}




