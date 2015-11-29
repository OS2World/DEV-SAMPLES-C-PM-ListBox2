#pragma	title("List Box Replacement  --  Version 1.0 -- (EventMgr.C)")
#pragma	subtitle("   Event Manager - Interface Definitions")

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


/************************************************************************/
/************************************************************************/
/*		       DISCLAIMER OF WARRANTIES.			*/
/************************************************************************/
/************************************************************************/
/*     The following [enclosed]	code is	source code created by the	*/
/*     authors.	 This source code is  provided to you solely		*/
/*     for the purpose of assisting you	in the development of your	*/
/*     applications.  The code is provided "AS IS", without		*/
/*     warranty	of any kind.  The authors shall	not be liable		*/
/*     for any damages arising out of your use of the source code,	*/
/*     even if they have been advised of the possibility of such	*/
/*     damages.	 It is provided	purely for instructional and		*/
/*     illustrative purposes.						*/
/************************************************************************/
/************************************************************************/

#pragma	info(noext)
#pragma	strings(readonly)

#if defined(__ZTC__)

#define	_Seg16

#endif

#define	INCL_WIN		   /* Include OS/2 PM Windows Interface	*/

#include <os2.h>

#include "listbox.h"

/* This	module contains	the routines that handle the event management	*/
/* for the list	box.  All notifications	to the owner window are	handled	*/
/* through these routines.						*/
/*									*/
/* Equivalent command line invocation of each module using the		*/
/* IBM C Set++ Compiler	Version	2.0 is:					*/
/*									*/
/*     Icc -G3e- -O+ -Rn -C -W3	-FoEventMgr EventMgr.C			*/

/* Filename:   EventMgr.C						*/

/*  Version:   1.0							*/
/*  Created:   1993-10-14						*/
/*  Revised:   1993-10-21						*/

/* Routines:   MRESULT mrNotifyOwner(PLISTBOXWIN plbw,			*/
/*				     ULONG ulNotification);		*/

/* --------------------------------------------------------------------	*/

#pragma	subtitle("   Event Manager - Owner Notification Procedure")
#pragma	page( )

/* --- mrNotifyOwner ----------------------------------- [ Public } ---	*/
/*									*/
/*     This function is	used to	send the notification message to the	*/
/*     window owning the list box control.  The	notification message	*/
/*     is one of the defined messages for the control.			*/
/*									*/
/* Standard List Box notification messages				*/
/*									*/
/*     LN_SELECT		  1					*/
/*     LN_SETFOCUS		  2					*/
/*     LN_KILLFOCUS		  3					*/
/*     LN_SCROLL		  4					*/
/*     LN_ENTER			  5					*/
/*									*/
/*     Upon Entry:							*/
/*									*/
/*     PLISTBOXWIN plbw;	   = List Box Internal Data Pointer	*/
/*     ULONG	   ulNotification; = Notification Value			*/
/*									*/
/*     Upon Exit:							*/
/*									*/
/*     mrNotifyOwner = Notification Result				*/
/*									*/
/* --------------------------------------------------------------------	*/

MRESULT	mrNotifyOwner(PLISTBOXWIN plbw,	ULONG ulNotification)

{

return(WinSendMsg(plbw->hwndOwner, WM_CONTROL,
		  MPFROM2SHORT(plbw->id, (USHORT)ulNotification),
		  MPFROMHWND((plbw->hWnd))));
}
