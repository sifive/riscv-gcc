(define_insn "@pred_quad_mul_plus<su><mode>_qoq"
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

(define_insn "@pred_quad_mul_plussu<mode>_qoq"
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

(define_insn "@pred_quad_mul_plusus<mode>_qoq"
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

(define_insn "@pred_quad_mul_plus<su><mode>_dod"
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

(define_insn "@pred_quad_mul_plussu<mode>_dod"
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

(define_insn "@pred_quad_mul_plusus<mode>_dod"
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
