#pragma once

class CImageAnalyzerDlg : public CDialogEx
{
public:
    CImageAnalyzerDlg(CWnd* pParent = nullptr);

#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_IMAGEANALYZER_DIALOG };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);
    virtual BOOL OnInitDialog();

    DECLARE_MESSAGE_MAP()

private:
    CImage m_sampleImage;
    CImage m_targetImage;
    CString m_samplePath;
    CString m_targetPath;

    void LoadDefaultImages();
    bool LoadImageFile(const CString& path, CImage& image, CString& storedPath);
    bool FindFileNearby(const CString& fileName, CString& foundPath) const;
    bool FileExists(const CString& path) const;
    CString GetDirectoryName(const CString& path) const;
    CString GetParentDirectory(const CString& path) const;
    void DrawImageBox(CDC& dc, const CRect& rect, const CImage& image, const CString& placeholder) const;
    void RefreshImageBox(UINT controlId);
    void UpdateStatus();

public:
    afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
    afx_msg void OnBnClickedLoadSample();
    afx_msg void OnBnClickedLoadTarget();
    afx_msg void OnBnClickedClear();
};
