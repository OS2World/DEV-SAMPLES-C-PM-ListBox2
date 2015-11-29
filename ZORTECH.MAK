
# MAKE file for Zortech.MAK     Version 2.1

# Revised:  1994-01-06

# Copyright ¸ 1987-1994  Prominare Inc.

# MAKE file created by Prominare Builder  Version 2.1

# Macro definitions

LNK_SW=/CO /DOSSEG
C_SW=-c -mF -3 -o+none -C -co -g 


ListBox.Dll: EventMgr.Obj heapmgr.Obj listbox.Obj\
             listmgr.Obj TraffMgr.Obj
 Blink $(LNK_SW) @Zortech.Lnk;

EventMgr.Obj: EventMgr.C
 ZTC $(C_SW)-o$*.Obj EventMgr.C

heapmgr.Obj: heapmgr.c
 ZTC $(C_SW)-o$*.Obj heapmgr.c

listbox.Obj: listbox.c
 ZTC $(C_SW)-o$*.Obj listbox.c

listmgr.Obj: listmgr.c
 ZTC $(C_SW)-o$*.Obj listmgr.c

TraffMgr.Obj: TraffMgr.C
 ZTC $(C_SW)-o$*.Obj TraffMgr.C

