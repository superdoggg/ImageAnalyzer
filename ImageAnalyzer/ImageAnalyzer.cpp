#include "pch.h"
#include "framework.h"
#include "ImageAnalyzer.h"
#include "ImageAnalyzerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(CImageAnalyzerApp, CWinApp)
END_MESSAGE_MAP()

CImageAnalyzerApp::CImageAnalyzerApp()
{
}

CImageAnalyzerApp theApp;

BOOL CImageAnalyzerApp::InitInstance()
{
    CWinApp::InitInstance();

    AfxEnableControlContainer();

    CImageAnalyzerDlg dlg;
    m_pMainWnd = &dlg;
    dlg.DoModal();

    return FALSE;
}
