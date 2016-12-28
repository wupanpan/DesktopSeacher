// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//  are changed infrequently
//

#pragma once

#define  _CRT_SECURE_NO_WARNINGS
#define	 DLL_SOUI
#include <souistd.h>
#include <core/SHostDialog.h>
#include <control/SMessageBox.h>
#include <control/souictrls.h>
#include <res.mgr/sobjdefattr.h>
#include <com-cfg.h>
#include "resource.h"
#include "CommonHeader.h"
#define R_IN_CPP	//定义这个开关来
#include "res\resource.h"
using namespace SOUI;
#include "MemoryMgr.h"
#include "ExtArray.h"
#include "MemoryPool.h"
#include "IndexNodeBlock.h"
#include "DirBasicInfoMap.h"
#include "Index.h"
#include "Record.h"
#include "NameSort.h"
extern CMemoryMgr* g_pMemoryMgr;
extern CExtArray g_ExtMgr;//扩展名管理
extern CMemoryPool g_MemFile, g_MemDir;//文件和目录的数据都保存在此处
extern CDirBasicInfoMap g_DirMap;
extern BYTE g_NoCaseTable[ALPHABETA_SIZE]; //已经初始化
extern CIndex g_vDirIndex, g_vFileIndex;