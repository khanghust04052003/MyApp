#include "pch.h"
#include "CColorButton.h"

CColorButton::CColorButton()
{
}

CColorButton::~CColorButton()
{
}

BEGIN_MESSAGE_MAP(CColorButton, CButton)
END_MESSAGE_MAP()

void CColorButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
    // Lấy device context để vẽ
    CDC dc;
    dc.Attach(lpDrawItemStruct->hDC);

    // Lấy vùng của button
    CRect rect = lpDrawItemStruct->rcItem;

    // Xác định trạng thái của button (bị nhấn hay không)
    BOOL bPressed = (lpDrawItemStruct->itemState & ODS_SELECTED) != 0;
    BOOL bFocused = (lpDrawItemStruct->itemState & ODS_FOCUS) != 0;

    // Đặt màu nền (màu đỏ)
    COLORREF bgColor = RGB(0, 200, 0); // Màu đỏ
    if (bPressed)
    {
        bgColor = RGB(200, 0, 0); // Màu đỏ đậm hơn khi nhấn
    }

    // Vẽ nền button
    dc.FillSolidRect(rect, bgColor);

    // Vẽ viền
    dc.Draw3dRect(rect, RGB(0, 0, 0), RGB(0, 0, 0)); // Viền đen
    if (bPressed)
    {
        rect.OffsetRect(1, 1); // Dịch chuyển khi nhấn
    }

    // Lấy text của button
    CString buttonText;
    GetWindowText(buttonText);

    // Đặt màu chữ (màu trắng)
    dc.SetTextColor(RGB(255, 255, 0)); // Màu trắng
    dc.SetBkMode(TRANSPARENT); // Nền trong suốt cho chữ

    // Căn giữa chữ
    dc.DrawText(buttonText, rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

    // Vẽ đường viền focus (nếu button được focus)
    if (bFocused)
    {
        CRect focusRect = rect;
        focusRect.DeflateRect(3, 3);
        dc.DrawFocusRect(focusRect);
    }

    // Giải phóng device context
    dc.Detach();
}
