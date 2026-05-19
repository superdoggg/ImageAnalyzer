#pragma once

#ifndef __AFXWIN_H__
#error "include 'pch.h' before including this file for PCH"
#endif

class CImageAnalyzerApp : public CWinApp
{
public:
    CImageAnalyzerApp();

public:
    virtual BOOL InitInstance();

    DECLARE_MESSAGE_MAP()
};

extern CImageAnalyzerApp theApp;
