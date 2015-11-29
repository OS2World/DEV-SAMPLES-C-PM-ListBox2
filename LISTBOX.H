
/* Program name: Listbox.C    Title: A List Box	Replacement		*/
/*									*/
/* OS/2	Developer Magazine, Issue:  Jan	'94, page 66                    */
/* Author:  Mark Benge	   IBM Corp.					*/
/*	    Matt Smith	   Prominare Inc.				*/
/* Description:	 Replacement for OS/2 List Box,	first of a series.	*/
/*									*/
/* Program Requirements:  OS/2 2.x					*/
/*			  IBM C	Set/2					*/
/*			  WATCOM C 386/9.0				*/
/*			  Borland C++ for OS/2				*/
/*			  Zortech C++ for OS/2				*/
/*			  OS/2 Toolkit					*/

/* Copyright ¸ International Business Machines Corp. 1991-1994		*/
/* Copyright ¸ 1989-1994  Prominare Inc.  All Rights Reserved.		*/

/* listbox.h	   Created:    1993-10-08  Revised:    1993-12-18	*/

/* List	Box Control Constant Definition	Header				*/

/* Functions are defined with strong typing to insure correct usage	*/
/* within the final program and	correct	linkage				*/


/* --- Memory Types ---------------------------------------------------	*/

typedef	ULONG HHEAPMEM;
#define	HALLOC_DEFAULT	0xffffffffUL

/* --- Internal	Structures --------------------------------------------	*/

#define	USER_RESERVED	   8	   /* Control Reserved Memory Size	*/

#define	QUCWP_WNDP (QWL_USER + 4)  /* Pointer to Internal Control Data	*/

typedef	struct _LISTITEM
   {
   PSZ	     pszText;		   /* Text Pointer			*/
   ULONG     cText;		   /* Text Length			*/
   ULONG     ulHandle;		   /* User Defined Handle		*/
   ULONG     fl;		   /* Flags (Upper 16 bits old Flags)	*/
   LONG	     cyItem;		   /* Item Height			*/
   LONG	     cxItem;		   /* Item Width			*/
   ULONG     iIndex;		   /* Index Position			*/
   } LISTITEM ;

typedef	LISTITEM *PLISTITEM;

#define	LI_CLEAR	   0x00000000UL
#define	LI_SELECTED	   0x00000001UL
#define	LI_FOCUS	   0x00000002UL
#define	LI_INSERTED	   0x00001000UL
#define	LI_SELECTEDPREV	   0x00000010UL
#define	LI_SELECTEDOLD	   0x00010000UL
#define	LI_FOCUSOLD	   0x00020000UL
#define	LI_INSERTEDOLD	   0x10000000UL
#define	LI_SELECTEDPREVOLD 0x00100000UL

typedef	struct _LISTCOL
   {
   HHEAPMEM  hHeap;		   /* Heap Handle			*/
   PLISTITEM ali;		   /* List Item	Array Pointer		*/
   } LISTCOL ;

typedef	LISTCOL	*PLISTCOL;

typedef	struct _LISTBOXWIN
   {
	     /***********************************************************/
	     /*	Window Management					*/
	     /***********************************************************/
   HHEAPMEM  hHeap;		   /* Heap Handle			*/
   HAB	     hAB;		   /* Anchor Block Handle		*/
   HWND	     hWnd;		   /* Control Window Handle		*/
   HWND	     hwndOwner;		   /* Owner Window Handle		*/
   HWND	     hwndParent;	   /* Parent Window Handle		*/
   HPOINTER  hptr;		   /* Selection	Mouse Pointer		*/
	     /***********************************************************/
	     /*	Styles/ID						*/
	     /***********************************************************/
   ULONG     flStyle;		   /* Style Flags			*/
   ULONG     id;		   /* Window ID				*/
	     /***********************************************************/
	     /*	Flags							*/
	     /***********************************************************/
   BOOL	     fFocus;		   /* Focus Flag			*/
   BOOL	     fDblClk;		   /* Mouse Double Click Flag		*/
   BOOL	     fCapture;		   /* Mouse Capture Flag		*/
   BOOL	     fTimer;		   /* Mouse Capture Flag		*/
   BOOL	     fVisible;		   /* List Box Visible Flag		*/
   BOOL	     fDelaySort;	   /* Delay Sort Flag			*/
   BOOL	     fFocusShown;	   /* FocusShown Flag			*/
	     /***********************************************************/
	     /*	Window Display						*/
	     /***********************************************************/
   LONG	     cx;		   /* List Box Width			*/
   LONG	     cy;		   /* List Box Height			*/
   LONG	     cxWindow;		   /* List Box Width  (Actual)		*/
   LONG	     cyWindow;		   /* List Box Height (Actual)		*/
   LONG	     lClrBackground;	   /* Background Colour			*/
   LONG	     lClrBorder;	   /* Border Colour			*/
   LONG	     lClrHilite;	   /* Hilite Colour			*/
   LONG	     lClrHiliteBackground; /* Hilite Background	Colour		*/
   LONG	     lClrList;		   /* List Colour			*/
   LONG	     lClrText;		   /* Text Colour			*/
   RECTL     rcl;		   /* Window Rectangle			*/
   RECTL     rclCorner;		   /* Scroll Corner Rectangle		*/
   RECTL     rclAdjusted;	   /* Adjusted Top Rectangle		*/
   POINTL    aptlOutside[5];	   /* Border Points Array		*/
   POINTL    aptlInside[5];	   /* Border Points Array		*/
   LONG	     cptl;		   /* Border Points Array Count		*/
	     /***********************************************************/
	     /*	Scroll Bars						*/
	     /***********************************************************/
   SWP	     aswp[4];		   /* Scroll Bar Position Array		*/
   HWND	     hwndScrollBottom;	   /* Bottom Scroll Bar	Window Handle	*/
   HWND	     hwndScrollLeft;	   /* Left Scroll Bar Window Handle	*/
   HWND	     hwndScrollRight;	   /* Right Scroll Bar Window Handle	*/
   HWND	     hwndScrollTop;	   /* Top Scroll Bar Window Handle	*/
   LONG	     cxScroll;		   /* Vertical Scroll Bar Width		*/
   LONG	     cyScroll;		   /* Horizontal Scroll	Bar Height	*/
	     /***********************************************************/
	     /*	Scroll Bar Indices					*/
	     /***********************************************************/
   LONG	     cHorzScroll;	   /* Horizontal Scroll	Count		*/
   LONG	     cVertScroll;	   /* Vertical Scroll Count		*/
   LONG	     iHorzScroll;	   /* Horizontal Scroll	Position	*/
   LONG	     iVertScroll;	   /* Vertical Scroll Position		*/
	     /***********************************************************/
	     /*	Indices							*/
	     /***********************************************************/
   LONG	     iAnchor;		   /* Anchor Item Index			*/
   LONG	     iAnchorLast;	   /* Last Anchor Item Index		*/
   LONG	     iFocus;		   /* Focus Item Index			*/
   LONG	     iFocusLast;	   /* Last Focus Item Index		*/
   LONG	     iSelected;		   /* Selected Item Index		*/
   LONG	     iSelectedLast;	   /* Last Selected Item Index		*/
	     /***********************************************************/
	     /*	List Box Limits						*/
	     /***********************************************************/
   LONG	     cCharsPage;	   /* Characters per Page		*/
   LONG	     cLinesPage;	   /* Lines per	Page			*/
   LONG	     cxItem;		   /* Longest Horizontal Item		*/
   LONG	     cyItem;		   /* Item Height			*/
   LONG	     xChar;		   /* Character	Width			*/
   LONG	     yAscender;		   /* Character	Ascender Height		*/
	     /***********************************************************/
	     /*	List Box List						*/
	     /***********************************************************/
   PLISTCOL  plc;		   /* List Column Array			*/
   LONG	     cColumns;		   /* Columns Count			*/
   LONG	     cItems;		   /* Items Count			*/
   BOOL	     fDirty;		   /* Dirty Update Flag			*/
   } LISTBOXWIN	;

typedef	LISTBOXWIN *PLISTBOXWIN;

#define	SWP_VERT       0
#define	SWP_HORZ       1

#define	IDT_SCROLL  512UL

typedef	struct _LISTBOXCDATA
   {
   ULONG    cb;			   /* Structure	Size			*/
   ULONG    ulVersion;		   /* Structure	Version	NUmber		*/
   ULONG    cItems;		   /* Items Count			*/
   BYTE	    abList[1];		   /* Array List Start			*/
   } LISTBOXCDATA ;

typedef	LISTBOXCDATA *PLISTBOXCDATA;

#define	LBV_100	   0x00010000UL	   /* Control Data Version Number	*/

typedef	struct _LISTBOXITEM	   /* lbi */
   {
   PSZ	    pszText;		   /* Item Text	Pointer			*/
   ULONG    ulHandle;		   /* Item Handle			*/
   } LISTBOXITEM ;

typedef	LISTBOXITEM *PLISTBOXITEM;

/************************************************************************/
/************************************************************************/
/*									*/
/*     Inline Macros							*/
/*									*/
/************************************************************************/
/************************************************************************/

#define	SaveSelectState(iCol, iSelected)  { if ( plbw->flStyle & LS_OWNERDRAW )\
   if (	(plbw->plc[iCol].ali[iSelected].fl & LI_SELECTED) && fItemVisible(plbw,	iSelected) )\
       plbw->plc[iCol].ali[iSelected].fl |= LI_SELECTEDPREV;\
   else\
       plbw->plc[iCol].ali[iSelected].fl &= ~LI_SELECTEDPREV; }

/************************************************************************/
/************************************************************************/
/*									*/
/*     Extended	Messages						*/
/*									*/
/************************************************************************/
/************************************************************************/

#define	LMX_CALCLINECOUNT      0x0180UL
#define	LMX_CALCSIZE	       0x0181UL
#define	LMX_COPY	       0x0182UL
#define	LMX_CUT		       0x0183UL
#define	LMX_PASTE	       0x0184UL
#define	LMX_QUERYITEMCOUNT     0x0185UL
#define	LMX_QUERYITEMRECT      0x0186UL
#define	LMX_QUERYSELECTLIST    0x0187UL
#define	LMX_RESETLIST	       0x0188UL
#define	LMX_SELECTALL	       0x0189UL
#define	LMX_SELECTITEMBITMAP   0x018aUL
#define	LMX_SETARRAY	       0x018bUL
#define	LMX_SETARRAYHANDLES    0x018cUL
#define	LMX_SETITEMBITMAPS     0x018dUL
#define	LMX_SETITEMCOUNT       0x018eUL
#define	LMX_SORT	       0x018fUL
#define	LMX_SETARRAYITEMS      0x0190UL
#define	LMX_ADDARRAY	       0x0191UL

/************************************************************************/
/************************************************************************/
/*									*/
/*     Prototypes							*/
/*									*/
/************************************************************************/
/************************************************************************/

/* --- EventMgr.C Prototype Definitions	-------------------------------	*/

MRESULT	mrNotifyOwner(PLISTBOXWIN plbw,	ULONG ulNotification);

/* --- HeapMgr.C Prototype Definitions --------------------------------	*/

HHEAPMEM HeapAlloc(ULONG cbInitial, ULONG cbNewBlks);
VOID	 HeapRelease(HHEAPMEM hHeap);
ULONG	 HeapSize(HHEAPMEM hHeap);

VOID	 HeapStatus(HHEAPMEM hHeap, PULONG pcBlocks, PULONG pulSize,
		    PULONG pulUsed, PULONG pulFree, PULONG pulUnused, PULONG pulOverhead);
VOID	 HeapDisplayStatus(HHEAPMEM hHeap);

PVOID	 HeapMalloc(HHEAPMEM hHeap, ULONG cbSize);
PVOID	 HeapCalloc(HHEAPMEM hHeap, ULONG cItems, ULONG	cbSize);
PVOID	 HeapRealloc(HHEAPMEM hHeap, PVOID pv, ULONG cbSize);
VOID	 HeapFree(HHEAPMEM hHeap, PVOID	pv);

/* --- ListBox.C Prototype Definitions --------------------------------	*/

BOOL EXPENTRY fRegisterListBox(HAB hAB);
VOID UpdateScrollBars(PLISTBOXWIN plbw);
VOID DrawSelection(PLISTBOXWIN plbw, LONG iItem);
VOID DrawItemSelection(PLISTBOXWIN plbw, LONG iItem);
BOOL fItemVisible(PLISTBOXWIN plbw, LONG iItem);
LONG lItemFromPoint(PLISTBOXWIN	plbw, LONG y);
MRESULT	EXPENTRY ScrollBarWndProc(HWND hWnd, ULONG msg,	MPARAM mp1, MPARAM mp2);
MRESULT	EXPENTRY ListBoxWndProc(HWND hWnd, ULONG msg, MPARAM mp1, MPARAM mp2);

/* --- ListMgr.C Prototype Definitions --------------------------------	*/

VOID SaveExtendedState(PLISTBOXWIN plbw);
VOID RestoreExtendedState(PLISTBOXWIN plbw);
BOOL fSelectMultipleItem(PLISTBOXWIN plbw, LONG	iCol, LONG iSelected, BOOL fSelect);
BOOL fSelectItem(PLISTBOXWIN plbw, LONG	iCol, LONG iItem, BOOL fSelect);
VOID SelectExtendedItems(PLISTBOXWIN plbw, LONG	iCol, LONG iSelected);
VOID SetControlDataList(PLISTBOXWIN plbw, ULONG	cItems,	PBYTE pb);
MRESULT	EXPENTRY mrBaseListHandler(HWND	hWnd, ULONG msg, MPARAM	mp1, MPARAM mp2);
MRESULT	EXPENTRY mrExtendedListHandler(HWND hWnd, ULONG	msg, MPARAM mp1, MPARAM	mp2);

/* --- TraffMgr.C Prototype Definitions	-------------------------------	*/

LONG lGetPresParam(HWND	hWnd, ULONG ulID1, ULONG ulID2,	LONG lDefault);
BOOL fAddHorzScroll(HWND hWnd, PLISTBOXWIN plbw);
VOID MeasureItem(PLISTBOXWIN plbw, LONG	lMaxBaselineExt);
VOID SizeListBox(PLISTBOXWIN plbw);
VOID FocusChange(PLISTBOXWIN plbw, LONG	iFocus,	BOOL fSet);
VOID RemoveFocus(PLISTBOXWIN plbw);
VOID SetFocus(PLISTBOXWIN plbw,	LONG iFocus);
VOID DrawItemSelection(PLISTBOXWIN plbw, LONG iItem);
BOOL fDecodeMouse(PLISTBOXWIN plbw, MPARAM mp1);
BOOL fDecodeExtendedMouse(PLISTBOXWIN plbw, MPARAM mp1,	BOOL fBlock);
VOID LineUp(PLISTBOXWIN	plbw);
VOID LineDown(PLISTBOXWIN plbw);
VOID DragUp(PLISTBOXWIN	plbw);
VOID DragDown(PLISTBOXWIN plbw);
