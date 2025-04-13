#pragma once
#include <afxwin.h>

class CColorButton : public CButton
{
public:
    CColorButton();
    virtual ~CColorButton();

protected:
    DECLARE_MESSAGE_MAP()

public:
    virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct); // Hàm để vẽ button
};
