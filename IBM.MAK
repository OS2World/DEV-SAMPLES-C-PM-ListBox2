
# MAKE file for IBM.MAK     Version 2.1

# Revised:  1994-01-05

# Copyright ¸ 1987-1994  Prominare Inc.

# MAKE file created by Prominare Builder  Version 2.1

# Macro definitions

LNK_SW=/DEBUG /BASE:0x12000000 /ALIGN:4 
C_SW=-G3e-s- -O- -Oi- -Op- -Os- -Rn -Ti -W3 -C 

ListBox.Dll: EventMgr.Obj HeapMgr.Obj ListBox.Obj\
             ListMgr.Obj TraffMgr.Obj
 Link386 $(LNK_SW) @IBM.Lnk;

EventMgr.Obj: EventMgr.C
 ICC $(C_SW)-Fo$*.Obj EventMgr.C

HeapMgr.Obj: HeapMgr.C
 ICC $(C_SW)-Fo$*.Obj HeapMgr.C

ListBox.Obj: ListBox.C
 ICC $(C_SW)-Fo$*.Obj ListBox.C

ListMgr.Obj: ListMgr.C
 ICC $(C_SW)-Fo$*.Obj ListMgr.C

TraffMgr.Obj: TraffMgr.C
 ICC $(C_SW)-Fo$*.Obj TraffMgr.C

