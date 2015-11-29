
# MAKE file for WATCOM.MAK     Version 2.1

# Revised:  1994-01-05

# Copyright ¸ 1987-1994  Prominare Inc.

# MAKE file created by Prominare Builder  Version 2.1

# Macro definitions

LNK_SW=DEBUG ALL
C_SW=-c -ms -3s -bd -s -od -d2 -zp4 -w3 


ListBox.Dll: EventMgr.Obj heapmgr.Obj listbox.Obj\
             listmgr.Obj TraffMgr.Obj
  WLink $(LNK_SW) @WATCOM.Lnk

EventMgr.Obj: EventMgr.C
 Wcl386 $(C_SW)-fo=$*.Obj EventMgr.C

heapmgr.Obj: heapmgr.c
 Wcl386 $(C_SW)-fo=$*.Obj heapmgr.c

listbox.Obj: listbox.c
 Wcl386 $(C_SW)-fo=$*.Obj listbox.c

listmgr.Obj: listmgr.c
 Wcl386 $(C_SW)-fo=$*.Obj listmgr.c

TraffMgr.Obj: TraffMgr.C
 Wcl386 $(C_SW)-fo=$*.Obj TraffMgr.C

