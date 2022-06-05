#ifndef _BIT_UTILS_H
#define _BIT_UTILS_H

#define SET_BIT(Reg,Bit)        Reg|=(1<<Bit)
#define CLR_BIT(Reg,Bit)        Reg&=~(1<<Bit)
#define GET_BIT(Reg,Bit)        ((Reg>>Bit)&1)
#define TGL_BIT(Reg,Bit)        Reg^=(1<<Bit)
#define RSHFT_REG(Reg,n)        Reg>>=n
#define LSHFT_REG(Reg,n)        Reg<<=n
#define CRSHFT_REG(Reg,n)       
#define CLSHFT_REG(Reg,n)       
#define ASSIGN_REG(Reg,Val)     Reg=Val
#define SET_REG(Reg)            Reg=0xFFFFFFFFFFFFFFFF
#define CLR_REG(Reg)            Reg=0x0
#define TGL_REG(Reg)            Reg^=0xFFFFFFFFFFFFFFFF
#define SET_H_NIB(Reg)          Reg=~(0xFFFF)
#define SET_L_NIB(Reg)          Reg=0xFFFF
#define CLR_H_NIB(Reg)          Reg&=0xFFFF
#define CLR_L_NIB(Reg)          Reg&=~(0xFFFF)
#define GET_H_NIB(Reg)          ((Reg>>16)&0xFFFF)
#define GET_L_NIB(Reg)          (Reg&0xFFFF)
#define ASSIGN_H_NIB(Reg,Val)   CLR_H_NIB(Reg);Reg|=(Val<<16)
#define ASSIGN_L_NIB(Reg,Val)   CLR_L_NIB(Reg);Reg|=(Val&0xFFFF)
#define TGL_H_NIB(Reg)          Reg^=~(0xFFFF)
#define TGL_L_NIB(Reg)          Reg^=0xFFFF
#define SWAP_NIB(Reg)           CRSHFT_REG(Reg,16)

#define FLOAR(val)              ((f32)(u32)val)
#define CEIL(val)               ((f32)(u32)val + ((f32)(u32)val != val))

#endif
