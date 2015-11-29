
# MAKE file for Borland.MAK     Version 2.1

# Revised:  1994-01-05

# Copyright ¸ 1987-1994  Prominare Inc.

# MAKE file created by Prominare Builder  Version 2.1

# Macro definitions

LNK_SW=-v 
C_SW=-sd -N- -Od -v -w -c 

ListBox.Dll: EventMgr.Obj HeapMgr.Obj ListBox.Obj\
             ListMgr.Obj TraffMgr.Obj
 Tlink $(LNK_SW) @Borland.Lnk;

EventMgr.Obj: EventMgr.C
 BCC $(C_SW)-o$*.Obj EventMgr.C

HeapMgr.Obj: HeapMgr.C
 BCC $(C_SW)-o$*.Obj HeapMgr.C

ListBox.Obj: ListBox.C
 BCC $(C_SW)-o$*.Obj ListBox.C

ListMgr.Obj: ListMgr.C
 BCC $(C_SW)-o$*.Obj ListMgr.C

TraffMgr.Obj: TraffMgr.C
 BCC $(C_SW)-o$*.Obj TraffMgr.C

