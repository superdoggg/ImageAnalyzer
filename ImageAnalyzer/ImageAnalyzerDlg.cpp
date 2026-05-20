#include "pch.h"
#include "ImageAnalyzer.h"
#include "ImageAnalyzerDlg.h"
#include "resource.h"

#include <algorithm>
#include <vector>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CImageAnalyzerDlg::CImageAnalyzerDlg(CWnd* pParent)
    : CDialogEx(IDD_IMAGEANALYZER_DIALOG, pParent)
{
}

void CImageAnalyzerDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CImageAnalyzerDlg, CDialogEx)
    ON_WM_DRAWITEM()
    ON_BN_CLICKED(IDC_BUTTON_LOAD_SAMPLE, &CImageAnalyzerDlg::OnBnClickedLoadSample)
    ON_BN_CLICKED(IDC_BUTTON_LOAD_TARGET, &CImageAnalyzerDlg::OnBnClickedLoadTarget)
    ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CImageAnalyzerDlg::OnBnClickedClear)
END_MESSAGE_MAP()

BOOL CImageAnalyzerDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    UpdateStatus();

    return TRUE;
}

void CImageAnalyzerDlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
    CDC dc;
    dc.Attach(lpDrawItemStruct->hDC);

    const CRect rect = lpDrawItemStruct->rcItem;
    if (nIDCtl == IDC_PICTURE_SAMPLE)
    {
        DrawImageBox(dc, rect, m_imgSample, _T("Sample 이미지 없음"));
    }
    else if (nIDCtl == IDC_PICTURE_TARGET)
    {
        DrawImageBox(dc, rect, m_imgTarget, _T("Target 이미지 없음"));
    }
    else
    {
        CDialogEx::OnDrawItem(nIDCtl, lpDrawItemStruct);
    }

    dc.Detach();
}

void CImageAnalyzerDlg::OnBnClickedLoadSample()
{
    CFileDialog dialog(
        TRUE,
        nullptr,
        nullptr,
        OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST,
        _T("이미지 파일 (*.png;*.jpg;*.jpeg;*.bmp)|*.png;*.jpg;*.jpeg;*.bmp|모든 파일 (*.*)|*.*||"),
        this);

    if (dialog.DoModal() == IDOK && LoadImageFile(dialog.GetPathName(), m_imgSample, m_strSamplePath))
    {
        RefreshImageBox(IDC_PICTURE_SAMPLE);
        UpdateStatus();
    }
}

void CImageAnalyzerDlg::OnBnClickedLoadTarget()
{
    CFileDialog dialog(
        TRUE,
        nullptr,
        nullptr,
        OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST,
        _T("이미지 파일 (*.png;*.jpg;*.jpeg;*.bmp)|*.png;*.jpg;*.jpeg;*.bmp|모든 파일 (*.*)|*.*||"),
        this);

    if (dialog.DoModal() == IDOK && LoadImageFile(dialog.GetPathName(), m_imgTarget, m_strTargetPath))
    {
        RefreshImageBox(IDC_PICTURE_TARGET);
        UpdateStatus();
    }
}

void CImageAnalyzerDlg::OnBnClickedClear()
{
    if (!m_imgSample.IsNull())
    {
        m_imgSample.Destroy();
    }

    if (!m_imgTarget.IsNull())
    {
        m_imgTarget.Destroy();
    }

    m_strSamplePath.Empty();
    m_strTargetPath.Empty();

    RefreshImageBox(IDC_PICTURE_SAMPLE);
    RefreshImageBox(IDC_PICTURE_TARGET);
    UpdateStatus();
}

bool CImageAnalyzerDlg::LoadImageFile(const CString& path, CImage& image, CString& storedPath)
{
    CImage loadedImage;
    const HRESULT result = loadedImage.Load(path);
    if (FAILED(result))
    {
        CString message;
        message.Format(_T("이미지를 불러오지 못했습니다.\n%s"), path.GetString());
        AfxMessageBox(message, MB_ICONERROR);
        return false;
    }

    if (!image.IsNull())
    {
        image.Destroy();
    }

    image.Attach(loadedImage.Detach());
    storedPath = path;
    return true;
}

bool CImageAnalyzerDlg::FindFileNearby(const CString& fileName, CString& foundPath) const
{
    std::vector<CString> startDirectories;

    TCHAR currentDirectory[MAX_PATH] = {};
    if (GetCurrentDirectory(MAX_PATH, currentDirectory) > 0)
    {
        startDirectories.emplace_back(currentDirectory);
    }

    TCHAR modulePath[MAX_PATH] = {};
    if (GetModuleFileName(nullptr, modulePath, MAX_PATH) > 0)
    {
        startDirectories.emplace_back(GetDirectoryName(modulePath));
    }

    for (const CString& startDirectory : startDirectories)
    {
        CString directory = startDirectory;
        for (int depth = 0; depth < 8 && !directory.IsEmpty(); ++depth)
        {
            CString candidate;
            candidate.Format(_T("%s\\%s"), directory.GetString(), fileName.GetString());
            if (FileExists(candidate))
            {
                foundPath = candidate;
                return true;
            }

            const CString parent = GetParentDirectory(directory);
            if (parent.CompareNoCase(directory) == 0)
            {
                break;
            }
            directory = parent;
        }
    }

    return false;
}

bool CImageAnalyzerDlg::FileExists(const CString& path) const
{
    const DWORD attributes = GetFileAttributes(path);
    return attributes != INVALID_FILE_ATTRIBUTES && (attributes & FILE_ATTRIBUTE_DIRECTORY) == 0;
}

CString CImageAnalyzerDlg::GetDirectoryName(const CString& path) const
{
    const int separator = path.ReverseFind(_T('\\'));
    if (separator <= 0)
    {
        return CString();
    }

    return path.Left(separator);
}

CString CImageAnalyzerDlg::GetParentDirectory(const CString& path) const
{
    CString trimmedPath = path;
    trimmedPath.TrimRight(_T("\\/"));

    const int separator = trimmedPath.ReverseFind(_T('\\'));
    if (separator <= 0)
    {
        return trimmedPath;
    }

    return trimmedPath.Left(separator);
}

void CImageAnalyzerDlg::DrawImageBox(CDC& dc, const CRect& rect, const CImage& image, const CString& placeholder) const
{
    dc.FillSolidRect(rect, RGB(250, 250, 250));
    dc.Draw3dRect(rect, RGB(170, 170, 170), RGB(170, 170, 170));

    CRect contentRect = rect;
    contentRect.DeflateRect(8, 8);

    if (image.IsNull())
    {
        dc.SetBkMode(TRANSPARENT);
        dc.SetTextColor(RGB(110, 110, 110));
        dc.DrawText(placeholder, contentRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_NOPREFIX);
        return;
    }

    const int imageWidth = image.GetWidth();
    const int imageHeight = image.GetHeight();
    if (imageWidth <= 0 || imageHeight <= 0)
    {
        return;
    }

    const double scaleX = static_cast<double>(contentRect.Width()) / imageWidth;
    const double scaleY = static_cast<double>(contentRect.Height()) / imageHeight;
    const double scale = std::min(scaleX, scaleY);

    const int drawWidth = static_cast<int>(imageWidth * scale);
    const int drawHeight = static_cast<int>(imageHeight * scale);
    const int drawX = contentRect.left + (contentRect.Width() - drawWidth) / 2;
    const int drawY = contentRect.top + (contentRect.Height() - drawHeight) / 2;

    image.Draw(dc.GetSafeHdc(), drawX, drawY, drawWidth, drawHeight);
}

void CImageAnalyzerDlg::RefreshImageBox(UINT controlId)
{
    CWnd* imageBox = GetDlgItem(controlId);
    if (imageBox != nullptr)
    {
        imageBox->Invalidate();
        imageBox->UpdateWindow();
    }
}

void CImageAnalyzerDlg::UpdateStatus()
{
    CString status;

    if (m_strSamplePath.IsEmpty() && m_strTargetPath.IsEmpty())
    {
        status = _T("sample.png와 target.png를 자동으로 찾지 못했습니다. 버튼으로 이미지를 선택하세요.");
    }
    else
    {
        status.Format(
            _T("Sample: %s\r\nTarget: %s"),
            m_strSamplePath.IsEmpty() ? _T("선택되지 않음") : m_strSamplePath.GetString(),
            m_strTargetPath.IsEmpty() ? _T("선택되지 않음") : m_strTargetPath.GetString());
    }

    SetDlgItemText(IDC_STATIC_STATUS, status);
}
