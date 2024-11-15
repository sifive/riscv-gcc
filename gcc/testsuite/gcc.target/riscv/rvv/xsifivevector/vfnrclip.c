/* { dg-do compile } */
/* { dg-options "-march=rv64gc_xsfvfnrclip -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" } } */

#include "riscv_vector.h"

/*
** foo1:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8mf8_t foo1(vfloat32mf2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_i8mf8(vs2, rs1, vl);
}

/*
** foo2:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8mf4_t foo2(vfloat32m1_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_i8mf4(vs2, rs1, vl);
}

/*
** foo3:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8mf2_t foo3(vfloat32m2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_i8mf2(vs2, rs1, vl);
}

/*
** foo4:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8m1_t foo4(vfloat32m4_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_i8m1(vs2, rs1, vl);
}

/*
** foo5:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8m2_t foo5(vfloat32m8_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_i8m2(vs2, rs1, vl);
}

/*
** foo6:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8mf8_t foo6(vfloat32mf2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf(vs2, rs1, vl);
}

/*
** foo7:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8mf4_t foo7(vfloat32m1_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf(vs2, rs1, vl);
}

/*
** foo8:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8mf2_t foo8(vfloat32m2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf(vs2, rs1, vl);
}

/*
** foo9:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8m1_t foo9(vfloat32m4_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf(vs2, rs1, vl);
}

/*
** foo10:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8m2_t foo10(vfloat32m8_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf(vs2, rs1, vl);
}

/*
** foo11:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8mf8_t foo11(vfloat32mf2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf__vfnrclip_xu_f_qf_u8mf8(vs2, rs1, vl);
}

/*
** foo12:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8mf4_t foo12(vfloat32m1_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_u8mf4(vs2, rs1, vl);
}

/*
** foo13:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8mf2_t foo13(vfloat32m2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_u8mf2(vs2, rs1, vl);
}

/*
** foo14:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8m1_t foo14(vfloat32m4_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_u8m1(vs2, rs1, vl);
}

/*
** foo15:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8m2_t foo15(vfloat32m8_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_u8m2(vs2, rs1, vl);
}

/*
** foo16:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8mf8_t foo16(vfloat32mf2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf(vs2, rs1, vl);
}

/*
** foo17:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8mf4_t foo17(vfloat32m1_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf(vs2, rs1, vl);
}

/*
** foo18:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8mf2_t foo18(vfloat32m2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf(vs2, rs1, vl);
}

/*
** foo19:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8m1_t foo19(vfloat32m4_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf(vs2, rs1, vl);
}

/*
** foo20:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8m2_t foo20(vfloat32m8_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf(vs2, rs1, vl);
}


/*
** foo21:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8mf8_t foo21(vbool64_t mask, vfloat32mf2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_i8mf8_m(mask, vs2, rs1, vl);
}

/*
** foo22:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8mf4_t foo22(vbool32_t mask, vfloat32m1_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_i8mf4_m(mask, vs2, rs1, vl);
}

/*
** foo23:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8mf2_t foo23(vbool16_t mask, vfloat32m2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_i8mf2_m(mask, vs2, rs1, vl);
}

/*
** foo24:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8m1_t foo24(vbool8_t mask, vfloat32m4_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_i8m1_m(mask, vs2, rs1, vl);
}

/*
** foo25:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8m2_t foo25(vbool4_t mask, vfloat32m8_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_i8m2_m(mask, vs2, rs1, vl);
}


/*
** foo26:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8mf8_t foo26(vbool64_t mask, vfloat32mf2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_u8mf8_m(vs2, rs1, vl);
}

/*
** foo27:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8mf4_t foo27(vbool32_t mask, vfloat32m1_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_u8mf4_m(vs2, rs1, vl);
}

/*
** foo28:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8mf2_t foo28(vbool16_t mask, vfloat32m2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_u8mf2_m(vs2, rs1, vl);
}

/*
** foo29:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8m1_t foo29(vbool8_t mask, vfloat32m4_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_u8m1_m(vs2, rs1, vl);
}

/*
** foo30:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8m2_t foo30(vbool4_t mask, vfloat32m8_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_u8m2_m(vs2, rs1, vl);
}


/*
** foo31:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8mf8_t foo31(vint8mf8_t maskedoff, vfloat32mf2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_i8mf8_tu(maskedoff, vs2, rs1, vl);
}

/*
** foo32:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8mf4_t foo32(vint8mf4_t maskedoff, vfloat32m1_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_i8mf4_tu(maskedoff, vs2, rs1, vl);
}

/*
** foo33:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8mf2_t foo33(vint8mf2_t maskedoff, vfloat32m2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_i8mf2_tu(maskedoff, vs2, rs1, vl);
}

/*
** foo34:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8m1_t foo34(vint8m1_t maskedoff, vfloat32m4_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_i8m1_tu(maskedoff, vs2, rs1, vl);
}

/*
** foo35:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8m2_t foo35(vint8m2_t maskedoff, vfloat32m8_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_i8m2_tu(maskedoff, vs2, rs1, vl);
}


/*
** foo36:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8mf8_t foo36(vint8mf8_t maskedoff, vfloat32mf2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_tu(maskedoff, vs2, rs1, vl);
}

/*
** foo37:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8mf4_t foo37(vint8mf4_t maskedoff, vfloat32m1_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_tu(maskedoff, vs2, rs1, vl);
}

/*
** foo38:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8mf2_t foo38(vint8mf2_t maskedoff, vfloat32m2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_tu(maskedoff, vs2, rs1, vl);
}

/*
** foo39:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8m1_t foo39(vint8m1_t maskedoff, vfloat32m4_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_tu(maskedoff, vs2, rs1, vl);
}

/*
** foo40:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8m2_t foo40(vint8m2_t maskedoff, vfloat32m8_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_tu(maskedoff, vs2, rs1, vl);
}


/*
** foo41:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8mf8_t foo41(vuint8mf8_t maskedoff, vfloat32mf2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_u8mf8_tu(maskedoff, vs2, rs1, vl);
}

/*
** foo42:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8mf4_t foo42(vuint8mf4_t maskedoff, vfloat32m1_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_u8mf4_tu(maskedoff, vs2, rs1, vl);
}

/*
** foo43:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8mf2_t foo43(vuint8mf2_t maskedoff, vfloat32m2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_u8mf2_tu(maskedoff, vs2, rs1, vl);
}

/*
** foo44:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8m1_t foo44(vuint8m1_t maskedoff, vfloat32m4_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_u8m1_tu(maskedoff, vs2, rs1, vl);
}

/*
** foo45:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8m2_t foo45(vuint8m2_t maskedoff, vfloat32m8_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_u8m2_tu(maskedoff, vs2, rs1, vl);
}


/*
** foo46:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8mf8_t foo46(vint8mf8_t maskedoff, vfloat32mf2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_tu(maskedoff, vs2, rs1, vl);
}

/*
** foo47:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8mf4_t foo47(vint8mf4_t maskedoff, vfloat32m1_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_tu(maskedoff, vs2, rs1, vl);
}

/*
** foo48:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8mf2_t foo48(vint8mf2_t maskedoff, vfloat32m2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_tu(maskedoff, vs2, rs1, vl);
}

/*
** foo49:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8m1_t foo49(vint8m1_t maskedoff, vfloat32m4_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_tu(maskedoff, vs2, rs1, vl);
}

/*
** foo50:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8m2_t foo50(vint8m2_t maskedoff, vfloat32m8_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_tu(maskedoff, vs2, rs1, vl);
}


/*
** foo51:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8mf8_t foo51(vbool64_t mask, vint8mf8_t maskedoff, vfloat32mf2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_i8mf8_tum(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo52:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8mf4_t foo52(vbool32_t mask, vint8mf4_t maskedoff, vfloat32m1_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_i8mf4_tum(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo53:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8mf2_t foo53(vbool16_t mask, vint8mf2_t maskedoff, vfloat32m2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_i8mf2_tum(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo54:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8m1_t foo54(vbool8_t mask, vint8m1_t maskedoff, vfloat32m4_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_i8m1_tum(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo55:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8m2_t foo55(vbool4_t mask, vint8m2_t maskedoff, vfloat32m8_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_i8m2_tum(mask, maskedoff, vs2, rs1, vl);
}


/*
** foo56:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8mf8_t foo56(vbool64_t mask, vint8mf8_t maskedoff, vfloat32mf2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_tum(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo57:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8mf4_t foo57(vbool32_t mask, vint8mf4_t maskedoff, vfloat32m1_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_tum(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo58:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8mf2_t foo58(vbool16_t mask, vint8mf2_t maskedoff, vfloat32m2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_tum(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo59:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8m1_t foo59(vbool8_t mask, vint8m1_t maskedoff, vfloat32m4_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_tum(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo60:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8m2_t foo60(vbool4_t mask, vint8m2_t maskedoff, vfloat32m8_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_tum(mask, maskedoff, vs2, rs1, vl);
}


/*
** foo61:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8mf8_t foo61(vbool64_t mask, vuint8mf8_t maskedoff, vfloat32mf2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_u8mf8_tum(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo62:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8mf4_t foo62(vbool32_t mask, vuint8mf4_t maskedoff, vfloat32m1_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_u8mf4_tum(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo63:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8mf2_t foo63(vbool16_t mask, vuint8mf2_t maskedoff, vfloat32m2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_u8mf2_tum(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo64:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8m1_t foo64(vbool8_t mask, vuint8m1_t maskedoff, vfloat32m4_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_u8m1_tum(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo65:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8m2_t foo65(vbool4_t mask, vuint8m2_t maskedoff, vfloat32m8_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_u8m2_tum(mask, maskedoff, vs2, rs1, vl);
}


/*
** foo66:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8mf8_t foo66(vbool64_t mask, vint8mf8_t maskedoff, vfloat32mf2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_tum(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo67:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8mf4_t foo67(vbool32_t mask, vint8mf4_t maskedoff, vfloat32m1_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_tum(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo68:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8mf2_t foo68(vbool16_t mask, vint8mf2_t maskedoff, vfloat32m2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_tum(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo69:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8m1_t foo69(vbool8_t mask, vint8m1_t maskedoff, vfloat32m4_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_tum(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo70:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8m2_t foo70(vbool4_t mask, vint8m2_t maskedoff, vfloat32m8_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_tum(maskedoff, vs2, rs1, vl);
}


/*
** foo71:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8mf8_t foo71(vbool64_t mask, vint8mf8_t maskedoff, vfloat32mf2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_i8mf8_tumu(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo72:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8mf4_t foo72(vbool32_t mask, vint8mf4_t maskedoff, vfloat32m1_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_i8mf4_tumu(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo73:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8mf2_t foo73(vbool16_t mask, vint8mf2_t maskedoff, vfloat32m2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_i8mf2_tumu(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo74:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8m1_t foo74(vbool8_t mask, vint8m1_t maskedoff, vfloat32m4_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_i8m1_tumu(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo75:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8m2_t foo75(vbool4_t mask, vint8m2_t maskedoff, vfloat32m8_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_i8m2_tumu(mask, maskedoff, vs2, rs1, vl);
}


/*
** foo76:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8mf8_t foo76(vbool64_t mask, vint8mf8_t maskedoff, vfloat32mf2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_tumu(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo77:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8mf4_t foo77(vbool32_t mask, vint8mf4_t maskedoff, vfloat32m1_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_tumu(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo78:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8mf2_t foo78(vbool16_t mask, vint8mf2_t maskedoff, vfloat32m2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_tumu(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo79:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8m1_t foo79(vbool8_t mask, vint8m1_t maskedoff, vfloat32m4_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_tumu(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo80:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8m2_t foo80(vbool4_t mask, vint8m2_t maskedoff, vfloat32m8_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_tumu(mask, maskedoff, vs2, rs1, vl);
}


/*
** foo81:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8mf8_t foo81(vbool64_t mask, vuint8mf8_t maskedoff, vfloat32mf2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_u8mf8_tumu(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo82:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8mf4_t foo82(vbool32_t mask, vuint8mf4_t maskedoff, vfloat32m1_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_u8mf4_tumu(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo83:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8mf2_t foo83(vbool16_t mask, vuint8mf2_t maskedoff, vfloat32m2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_u8mf2_tumu(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo84:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8m1_t foo84(vbool8_t mask, vuint8m1_t maskedoff, vfloat32m4_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_u8m1_tumu(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo85:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8m2_t foo85(vbool4_t mask, vuint8m2_t maskedoff, vfloat32m8_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_u8m2_tumu(mask, maskedoff, vs2, rs1, vl);
}


/*
** foo86:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8mf8_t foo86(vbool64_t mask, vint8mf8_t maskedoff, vfloat32mf2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_tumu(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo87:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8mf4_t foo87(vbool32_t mask, vint8mf4_t maskedoff, vfloat32m1_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_tumu(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo88:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8mf2_t foo88(vbool16_t mask, vint8mf2_t maskedoff, vfloat32m2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_tumu(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo89:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8m1_t foo89(vbool8_t mask, vint8m1_t maskedoff, vfloat32m4_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_tumu(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo90:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8m2_t foo90(vbool4_t mask, vint8m2_t maskedoff, vfloat32m8_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_tumu(maskedoff, vs2, rs1, vl);
}

/*
** foo91:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8mf8_t foo91(vbool64_t mask, vint8mf8_t maskedoff, vfloat32mf2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_i8mf8_mu(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo92:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8mf4_t foo92(vbool32_t mask, vint8mf4_t maskedoff, vfloat32m1_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_i8mf4_mu(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo93:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8mf2_t foo93(vbool16_t mask, vint8mf2_t maskedoff, vfloat32m2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_i8mf2_mu(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo94:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8m1_t foo94(vbool8_t mask, vint8m1_t maskedoff, vfloat32m4_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_i8m1_mu(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo95:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8m2_t foo95(vbool4_t mask, vint8m2_t maskedoff, vfloat32m8_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_i8m2_mu(mask, maskedoff, vs2, rs1, vl);
}


/*
** foo96:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8mf8_t foo96(vbool64_t mask, vint8mf8_t maskedoff, vfloat32mf2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_mu(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo97:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8mf4_t foo97(vbool32_t mask, vint8mf4_t maskedoff, vfloat32m1_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_mu(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo98:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8mf2_t foo98(vbool16_t mask, vint8mf2_t maskedoff, vfloat32m2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_mu(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo99:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8m1_t foo99(vbool8_t mask, vint8m1_t maskedoff, vfloat32m4_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_mu(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo100:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8m2_t foo100(vbool4_t mask, vint8m2_t maskedoff, vfloat32m8_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf_mu(mask, maskedoff, vs2, rs1, vl);
}


/*
** foo101:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8mf8_t foo101(vbool64_t mask, vuint8mf8_t maskedoff, vfloat32mf2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_u8mf8_mu(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo102:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8mf4_t foo102(vbool32_t mask, vuint8mf4_t maskedoff, vfloat32m1_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_u8mf4_mu(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo103:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8mf2_t foo103(vbool16_t mask, vuint8mf2_t maskedoff, vfloat32m2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_u8mf2_mu(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo84:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8m1_t foo104(vbool8_t mask, vuint8m1_t maskedoff, vfloat32m4_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_u8m1_mu(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo105:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8m2_t foo105(vbool4_t mask, vuint8m2_t maskedoff, vfloat32m8_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_u8m2_mu(mask, maskedoff, vs2, rs1, vl);
}


/*
** foo106:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8mf8_t foo106(vbool64_t mask, vint8mf8_t maskedoff, vfloat32mf2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_mu(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo87:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8mf4_t foo107(vbool32_t mask, vint8mf4_t maskedoff, vfloat32m1_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_mu(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo108:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8mf2_t foo108(vbool16_t mask, vint8mf2_t maskedoff, vfloat32m2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_mu(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo109:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8m1_t foo109(vbool8_t mask, vint8m1_t maskedoff, vfloat32m4_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_mu(mask, maskedoff, vs2, rs1, vl);
}

/*
** foo110:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qfs+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8m2_t foo110(vbool4_t mask, vint8m2_t maskedoff, vfloat32m8_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf_mu(maskedoff, vs2, rs1, vl);
}


/*
** foo111:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8mf8_t foo111(vbool64_t mask, vfloat32mf2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf(mask, vs2, rs1, vl);
}

/*
** foo112:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8mf4_t foo112(vbool32_t mask, vfloat32m1_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf(mask, vs2, rs1, vl);
}

/*
** foo113:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8mf2_t foo113(vbool16_t mask, vfloat32m2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf(mask, vs2, rs1, vl);
}

/*
** foo114:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8m1_t foo114(vbool8_t mask, vfloat32m4_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf(mask, vs2, rs1, vl);
}

/*
** foo115:
** ...
** vsetvli\t
** sf\.vfnrclip\.x\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint8m2_t foo115(vbool4_t mask, vfloat32m8_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_x_f_qf(mask, vs2, rs1, vl);
}


/*
** foo116:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8mf8_t foo116(vbool64_t mask, vfloat32mf2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf(vs2, rs1, vl);
}

/*
** foo117:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8mf4_t foo117(vbool32_t mask, vfloat32m1_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf(vs2, rs1, vl);
}

/*
** foo118:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8mf2_t foo118(vbool16_t mask, vfloat32m2_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf(vs2, rs1, vl);
}

/*
** foo119:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8m1_t foo119(vbool8_t mask, vfloat32m4_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf(vs2, rs1, vl);
}

/*
** foo120:
** ...
** vsetvli\t
** sf\.vfnrclip\.xu\.f\.qf\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vuint8m2_t foo120(vbool4_t mask, vfloat32m8_t vs2, float rs1, size_t vl)
{    
    return __riscv_sf_vfnrclip_xu_f_qf(vs2, rs1, vl);
}
