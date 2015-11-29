
# MAKE file for Driver.MAK     Version 2.1

# Revised:  1994-01-05

# Copyright ¸ 1987-1994  Prominare Inc.

# MAKE file created by Prominare Builder  Version 2.1

# Macro definitions

LNK_SW=/DEBUG /BASE:0x10000 /ALIGN:4
C_SW=-G3 -O- -Oi- -Op- -Os- -Rn -Ti -W3 -C 


Driver.Exe: Driver.Obj
 Link386 $(LNK_SW) @Driver.Lnk;

Driver.Obj: Driver.C
 ICC $(C_SW)-Fo$*.Obj Driver.C

