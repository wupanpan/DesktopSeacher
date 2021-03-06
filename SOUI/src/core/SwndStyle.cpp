//////////////////////////////////////////////////////////////////////////
//   File Name: SwndStyle.h
//////////////////////////////////////////////////////////////////////////

#include "souistd.h"
#include "core/Swndstyle.h"

namespace SOUI
{

SwndStyle::SwndStyle()
    : m_uAlign(Align_Center)
    , m_uVAlign(VAlign_Middle)
    , m_nTextAlign(0)
    , m_crBg(CR_INVALID)
    , m_crBorder(CR_INVALID)
    , m_strCursor(_T("arrow"))
    , m_byAlpha(0xFF)
    , m_dDotted(0)
    , m_bTrackMouseEvent(0)
    , m_bBkgndBlend(1)
    , m_bySepSpace(5)
{
    for(int i=0; i<4; i++)
    {
        m_ftText[i]=NULL;
        m_crText[i]=CR_INVALID;
    }
}

UINT SwndStyle::GetTextAlign()
{
    if(m_nTextAlign) return m_nTextAlign;
    UINT uRet=0;
    switch(m_uAlign)
    {
    case Align_Center: uRet |= DT_CENTER;break;
    case Align_Right: uRet|= DT_RIGHT;break;
    }
    switch(m_uVAlign)
    {
    case VAlign_Middle:uRet |= DT_VCENTER|DT_SINGLELINE;break;
    case VAlign_Bottom:uRet|= DT_BOTTOM|DT_SINGLELINE;break;
    }
	///////////////////////////////////////////////////火柴盒修改 author=wupanpan 添加字符串省略的不同形式
	if (m_dDotted == 1) uRet |= DT_END_ELLIPSIS;
	if (m_dDotted == 2) uRet |= DT_PATH_ELLIPSIS;
	if (m_dDotted == 3) uRet |= DT_WORD_ELLIPSIS;
	if (m_dDotted == 4) uRet |= DT_PATH_ELLIPSIS | DT_END_ELLIPSIS;
	////////////////////////////////////////////////////火柴盒修改end
	///////////////////////////////////////////////////火柴盒修改 author=fanliyang 去掉前缀，要不然&&==_&,修改后&&=&
	uRet |= DT_NOPREFIX;
	////////////////////////////////////////////////////火柴盒修改end
    return uRet;
}

int SwndStyle::GetStates()
{
    int fonts=1,colors=1;
    for(int i=1;i<4;i++)
    {
        if(m_ftText[i]!=NULL) fonts++;
        if(m_crText[i]!=CR_INVALID) colors++;
    }
    return max(fonts,colors);
}

COLORREF SwndStyle::GetTextColor( int iState )
{
    if(m_crText[iState]==CR_INVALID) iState=0;
    return m_crText[iState];
}

IFontPtr SwndStyle::GetTextFont( int iState )
{
    if(!m_ftText[iState]) iState=0;
    return m_ftText[iState];
}

HRESULT SwndStyle::OnAttrMargin(const SStringW strValue,BOOL bLoading)
{
    int v1=0,v2=0,v3=3,v4=0;
    int nValues = swscanf(strValue,L"%d,%d,%d,%d",&v1,&v2,&v3,&v4);
    if(nValues == 1)
    {
        m_rcMargin.left = m_rcMargin.right = m_rcMargin.top = m_rcMargin.bottom = v1;
    }else if(nValues == 2)
    {
        m_rcMargin.left = m_rcMargin.right = v1;
        m_rcMargin.top = m_rcMargin.bottom = v2;
    }else if(nValues == 4)
    {
        m_rcMargin.left = v1;
        m_rcMargin.top = v2;
        m_rcMargin.right = v3;
        m_rcMargin.bottom =v4;
    }
    return !bLoading?S_OK:S_FALSE;
}

HRESULT SwndStyle::OnAttrMarginX(const SStringW strValue,BOOL bLoading)
{
    m_rcMargin.left = m_rcMargin.right = _wtoi(strValue);
    return !bLoading?S_OK:S_FALSE;
}

HRESULT SwndStyle::OnAttrMarginY(const SStringW strValue,BOOL bLoading)
{
    m_rcMargin.top = m_rcMargin.bottom = _wtoi(strValue);
    return !bLoading?S_OK:S_FALSE;
}

}//namespace SOUI