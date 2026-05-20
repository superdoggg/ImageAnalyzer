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
    // sample 이미지 데이터를 보관합니다.
    CImage m_imgSample;

    // target 이미지 데이터를 보관합니다.
    CImage m_imgTarget;

    // sample 이미지 파일 경로를 보관합니다.
    CString m_strSamplePath;

    // target 이미지 파일 경로를 보관합니다.
    CString m_strTargetPath;

    // 지정한 경로의 이미지 파일을 CImage 객체로 불러옵니다.
    bool LoadImageFile(const CString& path, CImage& image, CString& storedPath);

    // 실행 파일 또는 현재 폴더 주변에서 지정한 파일명을 찾습니다.
    bool FindFileNearby(const CString& fileName, CString& foundPath) const;

    // 파일 경로가 실제 파일인지 확인합니다.
    bool FileExists(const CString& path) const;

    // 전체 파일 경로에서 폴더 경로만 분리합니다.
    CString GetDirectoryName(const CString& path) const;

    // 현재 폴더 경로의 상위 폴더 경로를 구합니다.
    CString GetParentDirectory(const CString& path) const;

    // 대화상자 이미지 영역에 이미지를 비율 유지 상태로 그립니다.
    void DrawImageBox(CDC& dc, const CRect& rect, const CImage& image, const CString& placeholder) const;

    // 지정한 이미지 표시 영역을 다시 그리도록 요청합니다.
    void RefreshImageBox(UINT controlId);

    // 현재 불러온 이미지 경로를 상태 문구에 표시합니다.
    void UpdateStatus();

public:
    // owner-draw 이미지 표시 컨트롤을 직접 그립니다.
    afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);

    // sample 이미지 선택 버튼 클릭을 처리합니다.
    afx_msg void OnBnClickedLoadSample();

    // target 이미지 선택 버튼 클릭을 처리합니다.
    afx_msg void OnBnClickedLoadTarget();

    // 불러온 sample/target 이미지를 초기화합니다.
    afx_msg void OnBnClickedClear();
};
