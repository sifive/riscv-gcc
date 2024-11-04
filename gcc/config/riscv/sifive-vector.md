(define_insn "@pred_matrix_mul_plus<su><mode>_qoq"
  [(set (match_operand:V_SF 0 "register_operand"                    "=&vr")
	(if_then_else:V_SF
	  (unspec:<VM>
	    [(match_operand:<VM> 1 "vector_mask_operand"             "vmWc1")
	     (match_operand 5 "vector_length_operand"                "   rK")
	     (match_operand 6 "const_int_operand"                    "    i")
	     (match_operand 7 "const_int_operand"                    "    i")
	     (match_operand 8 "const_int_operand"                    "    i")
	     (reg:SI VL_REGNUM)
	     (reg:SI VTYPE_REGNUM)] UNSPEC_VPREDICATE)
	  (plus:V_SF
	    (mult:V_SF
	      (any_extend:V_SF
	        (match_operand:RVVM1QI 3 "register_operand" "   vr"))
	      (any_extend:V_SF
	        (match_operand:<V_SF_QMACC> 4 "register_operand" "   vr")))
	    (match_operand:V_SF 2 "register_operand"               "    0"))
	  (match_dup 2)))]
  "TARGET_VECTOR && TARGET_XSFVQMACCQOQ"
  "sf.vqmacc<u>.4x8x4\t%0,%3,%4"
  [(set_attr "type" "vsfmuladd")
   (set_attr "mode" "<MODE>")])

(define_insn "@pred_matrix_mul_plussu<mode>_qoq"
  [(set (match_operand:V_SF 0 "register_operand"                    "=&vr")
	(if_then_else:V_SF
	  (unspec:<VM>
	    [(match_operand:<VM> 1 "vector_mask_operand"             "vmWc1")
	     (match_operand 5 "vector_length_operand"                "   rK")
	     (match_operand 6 "const_int_operand"                    "    i")
	     (match_operand 7 "const_int_operand"                    "    i")
	     (match_operand 8 "const_int_operand"                    "    i")
	     (reg:SI VL_REGNUM)
	     (reg:SI VTYPE_REGNUM)] UNSPEC_VPREDICATE)
	  (plus:V_SF
	    (mult:V_SF
	      (sign_extend:V_SF
	        (match_operand:RVVM1QI 3 "register_operand" "   vr"))
	      (zero_extend:V_SF
	        (match_operand:<V_SF_QMACC> 4 "register_operand" "   vr")))
	    (match_operand:V_SF 2 "register_operand"               "    0"))
	  (match_dup 2)))]
  "TARGET_VECTOR && TARGET_XSFVQMACCQOQ"
  "sf.vqmaccsu.4x8x4\t%0,%3,%4"
  [(set_attr "type" "vsfmuladd")
   (set_attr "mode" "<MODE>")])

(define_insn "@pred_matrix_mul_plusus<mode>_qoq"
  [(set (match_operand:V_SF 0 "register_operand"                    "=&vr")
	(if_then_else:V_SF
	  (unspec:<VM>
	    [(match_operand:<VM> 1 "vector_mask_operand"             "vmWc1")
	     (match_operand 5 "vector_length_operand"                "   rK")
	     (match_operand 6 "const_int_operand"                    "    i")
	     (match_operand 7 "const_int_operand"                    "    i")
	     (match_operand 8 "const_int_operand"                    "    i")
	     (reg:SI VL_REGNUM)
	     (reg:SI VTYPE_REGNUM)] UNSPEC_VPREDICATE)
	  (plus:V_SF
	    (mult:V_SF
	      (zero_extend:V_SF
	        (match_operand:RVVM1QI 3 "register_operand" "   vr"))
	      (sign_extend:V_SF
	        (match_operand:<V_SF_QMACC> 4 "register_operand" "   vr")))
	    (match_operand:V_SF 2 "register_operand"               "    0"))
	  (match_dup 2)))]
  "TARGET_VECTOR && TARGET_XSFVQMACCQOQ"
  "sf.vqmaccus.4x8x4\t%0,%3,%4"
  [(set_attr "type" "vsfmuladd")
   (set_attr "mode" "<MODE>")])

(define_insn "@pred_matrix_mul_plus<su><mode>_dod"
  [(set (match_operand:V_SF 0 "register_operand"                    "=&vr")
	(if_then_else:V_SF
	  (unspec:<VM>
	    [(match_operand:<VM> 1 "vector_mask_operand"             "vmWc1")
	     (match_operand 5 "vector_length_operand"                "   rK")
	     (match_operand 6 "const_int_operand"                    "    i")
	     (match_operand 7 "const_int_operand"                    "    i")
	     (match_operand 8 "const_int_operand"                    "    i")
	     (reg:SI VL_REGNUM)
	     (reg:SI VTYPE_REGNUM)] UNSPEC_VPREDICATE)
	  (plus:V_SF
	    (mult:V_SF
	      (any_extend:V_SF
	        (match_operand:RVVM1QI 3 "register_operand" "   vr"))
	      (any_extend:V_SF
	        (match_operand:<V_SF_QMACC> 4 "register_operand" "   vr")))
	    (match_operand:V_SF 2 "register_operand"               "    0"))
	  (match_dup 2)))]
  "TARGET_VECTOR && TARGET_XSFVQMACCDOD"
  "sf.vqmacc<u>.4x8x4\t%0,%3,%4"
  [(set_attr "type" "vsfmuladd")
   (set_attr "mode" "<MODE>")])

(define_insn "@pred_matrix_mul_plussu<mode>_dod"
  [(set (match_operand:V_SF 0 "register_operand"                    "=&vr")
	(if_then_else:V_SF
	  (unspec:<VM>
	    [(match_operand:<VM> 1 "vector_mask_operand"             "vmWc1")
	     (match_operand 5 "vector_length_operand"                "   rK")
	     (match_operand 6 "const_int_operand"                    "    i")
	     (match_operand 7 "const_int_operand"                    "    i")
	     (match_operand 8 "const_int_operand"                    "    i")
	     (reg:SI VL_REGNUM)
	     (reg:SI VTYPE_REGNUM)] UNSPEC_VPREDICATE)
	  (plus:V_SF
	    (mult:V_SF
	      (sign_extend:V_SF
	        (match_operand:<V_SF_QMACC> 3 "register_operand" "   vr"))
	      (zero_extend:V_SF
	        (match_operand:<V_SF_QMACC> 4 "register_operand" "   vr")))
	    (match_operand:V_SF 2 "register_operand"               "    0"))
	  (match_dup 2)))]
  "TARGET_VECTOR && TARGET_XSFVQMACCDOD"
  "sf.vqmaccsu.4x8x4\t%0,%3,%4"
  [(set_attr "type" "vsfmuladd")
   (set_attr "mode" "<MODE>")])

(define_insn "@pred_matrix_mul_plusus<mode>_dod"
  [(set (match_operand:V_SF 0 "register_operand"                    "=&vr")
	(if_then_else:V_SF
	  (unspec:<VM>
	    [(match_operand:<VM> 1 "vector_mask_operand"             "vmWc1")
	     (match_operand 5 "vector_length_operand"                "   rK")
	     (match_operand 6 "const_int_operand"                    "    i")
	     (match_operand 7 "const_int_operand"                    "    i")
	     (match_operand 8 "const_int_operand"                    "    i")
	     (reg:SI VL_REGNUM)
	     (reg:SI VTYPE_REGNUM)] UNSPEC_VPREDICATE)
	  (plus:V_SF
	    (mult:V_SF
	      (zero_extend:V_SF
	        (match_operand:<V_SF_QMACC> 3 "register_operand" "   vr"))
	      (sign_extend:V_SF
	        (match_operand:<V_SF_QMACC> 4 "register_operand" "   vr")))
	    (match_operand:V_SF 2 "register_operand"               "    0"))
	  (match_dup 2)))]
  "TARGET_VECTOR && TARGET_XSFVQMACCDOD"
  "sf.vqmaccus.4x8x4\t%0,%3,%4"
  [(set_attr "type" "vsfmuladd")
   (set_attr "mode" "<MODE>")])

;; CLIP
(define_insn "@pred_fnr_clip<v_su><mode>"
  [(set (match_operand:<V_SF_FNRCLIPXFQF> 0 "register_operand"           "=vd,vd, vr, vr,vd, vr,  &vr,  &vr, vd, vr,  &vr,  &vr")
	(if_then_else:<V_SF_FNRCLIPXFQF>
	  (unspec:<VM>
	    [(match_operand:<VM> 1 "vector_mask_operand"               " vm,vm,Wc1,Wc1,vm,Wc1,vmWc1,vmWc1, vm,Wc1,vmWc1,vmWc1")
	     (match_operand 5 "vector_length_operand"                  " rK,rK, rK, rK,rK, rK,   rK,   rK, rK, rK,   rK,   rK")
	     (match_operand 6 "const_int_operand"                      "  i, i,  i,  i, i,  i,    i,    i,  i,  i,    i,    i")
	     (match_operand 7 "const_int_operand"                      "  i, i,  i,  i, i,  i,    i,    i,  i,  i,    i,    i")
	     (match_operand 8 "const_int_operand"                      "  i, i,  i,  i, i,  i,    i,    i,  i,  i,    i,    i")
	     (match_operand 9 "const_int_operand"                      "  i, i,  i,  i, i,  i,    i,    i,  i,  i,    i,    i")
	     (reg:SI VL_REGNUM)
	     (reg:SI VTYPE_REGNUM)
	     (reg:SI VXRM_REGNUM)] UNSPEC_VPREDICATE)
	  (unspec:<V_SF_FNRCLIPXFQF>
	    [(match_operand:VWEXTI 3 "register_operand"                " vr,vr, vr, vr, 0,  0,   vr,   vr,  0,  0,   vr,   vr")
	     (match_operand:<V_SF_FNRCLIPXFQF> 4 "vector_shift_operand"  "  0, 0,  0,  0,vr, vr,   vr,   vr, vk, vk,   vk,   vk")] VNCLIP)
	  (match_operand:<V_SF_FNRCLIPXFQF> 2 "vector_merge_operand"     "  0,vu,  0, vu,vu, vu,   vu,    0, vu, vu,   vu,    0")))]
  "TARGET_VECTOR && TARGET_XSFVFNRCLIPXFQF"
  "sf.vfnrclip.x.f.qf%o4\t%0,%3,%v4%p1"
  [(set_attr "type" "vsfclip")
   (set_attr "mode" "<V_SF_FNRCLIPXFQF>")
   (set_attr "spec_restriction" "thv,thv,thv,thv,thv,thv,none,none,thv,thv,none,none")])

(define_insn "@pred_fnr_clip<v_su><mode>_scalar"
  [(set (match_operand:<V_DOUBLE_TRUNC> 0 "register_operand"           "=vd, vd, vr, vr,  &vr,  &vr")
	(if_then_else:<V_DOUBLE_TRUNC>
	  (unspec:<VM>
	    [(match_operand:<VM> 1 "vector_mask_operand"               " vm, vm,Wc1,Wc1,vmWc1,vmWc1")
	     (match_operand 5 "vector_length_operand"                  " rK, rK, rK, rK,   rK,   rK")
	     (match_operand 6 "const_int_operand"                      "  i,  i,  i,  i,    i,    i")
	     (match_operand 7 "const_int_operand"                      "  i,  i,  i,  i,    i,    i")
	     (match_operand 8 "const_int_operand"                      "  i,  i,  i,  i,    i,    i")
	     (match_operand 9 "const_int_operand"                      "  i,  i,  i,  i,    i,    i")
	     (reg:SI VL_REGNUM)
	     (reg:SI VTYPE_REGNUM)
	     (reg:SI VXRM_REGNUM)] UNSPEC_VPREDICATE)
	  (unspec:<V_DOUBLE_TRUNC>
	    [(match_operand:VWEXTI 3 "register_operand"                "  0,  0,  0,  0,   vr,   vr")
	     (match_operand 4 "pmode_reg_or_uimm5_operand"             " rK, rK, rK, rK,   rK,   rK")] VNCLIP)
	  (match_operand:<V_DOUBLE_TRUNC> 2 "vector_merge_operand"     " vu,  0, vu,  0,   vu,    0")))]
  "TARGET_VECTOR && TARGET_XSFVFNRCLIPXFQF"
  "sf.vfnrclip.xu.f.qf%o4\t%0,%3,%4%p1"
  [(set_attr "type" "vsfclip")
   (set_attr "mode" "<V_DOUBLE_TRUNC>")
   (set_attr "spec_restriction" "thv,thv,thv,thv,none,none")])
