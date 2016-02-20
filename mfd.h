#undef TRIP
#undef TRAP
#define STAT
#define INI
#define INIMF
#define MF
#ifdef TEXMF_DEBUG
#endif /* TEXMF_DEBUG */
#define MFCOERCE
#include "texmfmp.h"
/* 1 9998 9999 */ 

/* 11. */
#define max_internal (300) 
#define stack_size (300) 
#define max_strings (7500) 
#define string_vacancies (74000L) 
#define pool_size (100000L) 
#define move_size (20000) 
#define max_wiggle (1000) 
#define pool_name (TEXMFpool_name) 
#define enginename (TEXMFENGINENAME) 
#define pathsize (1000) 
#define bistack_size (1500) 
#define header_size (100)
#define lig_table_size (15000)
#define max_kerns (2500)
#define max_font_dimen (60)
#define infmainmemory (3000)
#define supmainmemory (8000000L)
#define infbufsize (500)
#define supbufsize (30000000L)

typedef unsigned char ASCII_code;
typedef unsigned char eight_bits;
typedef text /* of  ASCII_code */ alpha_file;
typedef text /* of  eight_bits */ byte_file;
typedef integer pool_pointer;
typedef integer str_number;
typedef unsigned char packed_ASCII_code;
typedef integer scaled;
typedef unsigned char small_number;
typedef integer fraction;
typedef integer angle;
typedef unsigned char quarterword;
typedef integer halfword;
typedef unsigned char twochoices;
typedef unsigned char threechoices;
#include "texmfmem.h"
typedef text /* of  memoryword */ word_file;
typedef unsigned char commandcode;
typedef short screen_row;
typedef short screen_col;
typedef screen_col * trans_spec;
typedef unsigned char pixel_color;
typedef unsigned char window_number;
typedef struct {
  quarterword index_field;
  halfword start_field, loc_field, limit_field, name_field;
} in_state_record;
typedef integer gf_index;

/* G L O B A L   V A R I A B L E S */

/* 13. */
EXTERN integer bad;

/* { */
#ifdef INIMF
EXTERN boolean iniversion;
EXTERN boolean dumpoption;
EXTERN boolean dumpline;
#endif /* INIMF */
EXTERN constcstring dumpname;
EXTERN integer bounddefault;
EXTERN constcstring boundname;
EXTERN integer mainmemory;
EXTERN integer memtop;
EXTERN integer memmax;
EXTERN integer bufsize;
EXTERN integer errorline;
EXTERN integer halferrorline;
EXTERN integer maxprintline;
EXTERN integer screenwidth;
EXTERN integer screendepth;
EXTERN integer gf_bufsize;
EXTERN cinttype parsefirstlinep;
EXTERN cinttype filelineerrorstylep;
EXTERN cinttype eightbitp;
EXTERN cinttype haltonerrorp;
EXTERN boolean quotedfilename;
/* } */

/* 20. */
EXTERN ASCII_code xord[256];
EXTERN ASCII_code xchr[256];

/* 25. */
EXTERN ASCII_code * name_of_file;
EXTERN integer name_length;

/* 29. */
EXTERN ASCII_code * buffer;
EXTERN integer first;
EXTERN integer last;
EXTERN integer max_buf_stack;

/* 38. */
EXTERN packed_ASCII_code str_pool[pool_size + 1];
EXTERN pool_pointer str_start[max_strings + 1];
EXTERN pool_pointer pool_ptr;
EXTERN str_number str_ptr;
EXTERN pool_pointer init_pool_ptr;
EXTERN str_number init_str_ptr;
EXTERN pool_pointer max_pool_ptr;
EXTERN str_number max_str_ptr;

/* 42. */
EXTERN unsigned char str_ref[max_strings + 1];

#ifdef INIMF
EXTERN alpha_file poolfile;
#endif /* INIMF */

/* 54. On-line and off-line printing. */
EXTERN alpha_file log_file;
EXTERN unsigned char selector;
EXTERN unsigned char dig[23];
EXTERN integer tally;
EXTERN integer term_offset;
EXTERN integer file_offset;
EXTERN ASCII_code trick_buf[256];
EXTERN integer trick_count;
EXTERN integer first_count;

/* 68. */
EXTERN unsigned char interaction;
EXTERN unsigned char interactionoption;

/* 71. */
EXTERN boolean deletions_allowed;
EXTERN unsigned char history;
EXTERN schar error_count;

/* 74. */
EXTERN str_number help_line[6];
EXTERN unsigned char help_ptr;
EXTERN boolean use_err_help;
EXTERN str_number err_help;

/* 91. */
EXTERN integer interrupt;
EXTERN boolean OK_to_interrupt;

/* 97. */
EXTERN boolean arith_error;

/* 129. */
EXTERN integer two_to_the[31];
EXTERN integer spec_log[29];

/* 137. */
EXTERN angle spec_atan[27];

/* 144. */
EXTERN fraction n_sin, n_cos;

/* 148. */
EXTERN fraction randoms[55];
EXTERN unsigned char j_random;

/* 159. */
EXTERN memoryword * mem;
EXTERN halfword lo_mem_max;
EXTERN halfword hi_mem_min;

/* 160. */
EXTERN integer var_used, dyn_used;

/* 161. */
EXTERN halfword avail;
EXTERN halfword mem_end;

/* 166. */
EXTERN halfword rover;

/* 178. */
#ifdef TEXMF_DEBUG
EXTERN boolean freearr[2];
EXTERN boolean was_free[2];
EXTERN halfword was_mem_end, was_lo_max, was_hi_min;
EXTERN boolean panicking;
#endif /* TEXMF_DEBUG */

/* 190. */
EXTERN scaled internal[max_internal + 1];
EXTERN str_number int_name[max_internal + 1];
EXTERN integer int_ptr;

/* 196. */
EXTERN unsigned char old_setting;

/* 198. */
EXTERN unsigned char char_class[256];

/* 200. The hash table. */
EXTERN halfword hash_used;
EXTERN integer st_count;

/* 201. */
EXTERN twohalves hash[9770];
EXTERN twohalves eqtb[9770];

/* 225. */
EXTERN halfword g_pointer;

/* 230. */
EXTERN small_number 
#define big_node_size (zzzaa -13)
  zzzaa[2];

/* 250. Saving and restoring equivalents. */
EXTERN halfword save_ptr;

/* 267. */
EXTERN halfword path_tail;

/* 279. */
EXTERN scaled delta_x[pathsize + 1], delta_y[pathsize + 1], delta[pathsize + 1];
EXTERN angle psi[pathsize + 1];

/* 283. */
EXTERN angle theta[pathsize + 1];
EXTERN fraction uu[pathsize + 1];
EXTERN angle vv[pathsize + 1];
EXTERN fraction ww[pathsize + 1];

/* 298. */
EXTERN fraction st, ct, sf, cf;

/* 308. */
EXTERN integer move[move_size + 1];
EXTERN integer move_ptr;

/* 309. */
EXTERN integer bisect_stack[bistack_size + 1];
EXTERN integer bisect_ptr;

/* 327. */
EXTERN halfword cur_edges;
EXTERN integer cur_wt;

/* 371. */
EXTERN integer trace_x;
EXTERN integer trace_y;
EXTERN integer trace_yy;

/* 379. */
EXTERN unsigned char octant;

/* 389. */
EXTERN scaled cur_x, cur_y;

/* 395. */
EXTERN str_number octant_dir[9];

/* 403. */
EXTERN halfword cur_spec;
EXTERN integer turning_number;
EXTERN halfword cur_pen;
EXTERN unsigned char cur_path_type;
EXTERN scaled max_allowed;

/* 427. */
EXTERN scaled before[max_wiggle + 1], after[max_wiggle + 1];
EXTERN halfword node_to_round[max_wiggle + 1];
EXTERN integer cur_rounding_ptr;
EXTERN integer max_rounding_ptr;

/* 430. */
EXTERN scaled cur_gran;

/* 448. */
EXTERN unsigned char octant_number[9];
EXTERN unsigned char octant_code[9];

/* 455. */
EXTERN boolean rev_turns;

/* 461. */
EXTERN unsigned char y_corr[9], xy_corr[9], z_corr[9];
EXTERN schar x_corr[9];

/* 464. */
EXTERN integer m0, n0, m1, n1;
EXTERN unsigned char d0, d1;

/* 507. */
EXTERN integer env_move[move_size + 1];

/* 552. */
EXTERN unsigned char tol_step;

/* 555. */
EXTERN integer cur_t, cur_tt;
EXTERN integer time_to_go;
EXTERN integer max_t;

/* 557. */
EXTERN integer delx, dely;
EXTERN integer tol;
EXTERN integer uv, xy;
EXTERN integer three_l;
EXTERN integer appr_t, appr_tt;

/* 569. */
EXTERN boolean screen_started;
EXTERN boolean screen_OK;

/* 572. */
EXTERN boolean window_open[16];
EXTERN screen_col left_col[16];
EXTERN screen_col right_col[16];
EXTERN screen_row top_row[16];
EXTERN screen_row bot_row[16];
EXTERN integer m_window[16];
EXTERN integer n_window[16];
EXTERN integer window_time[16];

/* 579. */
EXTERN trans_spec row_transition;

/* 585. Dynamic linear equations. */
EXTERN integer serial_no;

/* 592. */
EXTERN boolean fix_needed;
EXTERN boolean watch_coefs;
EXTERN halfword dep_final;

/* 624. Introduction to the syntactic routines. */
EXTERN eight_bits cur_cmd;
EXTERN integer cur_mod;
EXTERN halfword cur_sym;

/* 628. */
EXTERN in_state_record input_stack[stack_size + 1];
EXTERN integer input_ptr;
EXTERN integer max_in_stack;
EXTERN in_state_record cur_input;

/* 631. */
EXTERN unsigned char in_open;
EXTERN unsigned char open_parens;
EXTERN alpha_file input_file[16];
EXTERN integer line;
EXTERN integer line_stack[16];
EXTERN str_number * sourcefilenamestack;
EXTERN str_number * fullsourcefilenamestack;

/* 633. */
EXTERN halfword param_stack[151];
EXTERN unsigned char param_ptr;
EXTERN integer max_param_stack;

/* 634. */
EXTERN integer file_ptr;

/* 659. */
EXTERN unsigned char scanner_status;
EXTERN integer warning_info;

/* 680. */
EXTERN boolean force_eof;

/* 699. */
EXTERN short bg_loc, eg_loc;

/* 738. Conditional processing. */
EXTERN halfword cond_ptr;
EXTERN unsigned char if_limit;
EXTERN small_number cur_if;
EXTERN integer if_line;

/* 752. Iterations. */
EXTERN halfword loop_ptr;

/* 767. */
EXTERN str_number cur_name;
EXTERN str_number cur_area;
EXTERN str_number cur_ext;

/* 768. */
EXTERN pool_pointer area_delimiter;
EXTERN pool_pointer ext_delimiter;
EXTERN integer basedefaultlength;

/* 775. */
EXTERN cstring MF_base_default;

/* 782. */
EXTERN str_number job_name;
EXTERN boolean log_opened;
EXTERN str_number texmflogname;

/* 785. */
EXTERN str_number gf_ext;

/* 791. */
EXTERN byte_file gf_file;
EXTERN str_number output_file_name;

/* 796. Introduction to the parsing routines. */
EXTERN small_number cur_type;
EXTERN integer cur_exp;

/* 813. */
EXTERN integer 
#define max_c (zzzab -17)
  zzzab[2];
EXTERN halfword 
#define max_ptr (zzzac -17)
  zzzac[2];
EXTERN halfword 
#define max_link (zzzad -17)
  zzzad[2];

/* 821. */
EXTERN unsigned char var_flag;

/* 954. */
EXTERN scaled txx, txy, tyx, tyy, tx, ty;

/* 1077. */
EXTERN halfword start_sym;

/* 1084. */
EXTERN boolean long_help_seen;

/* 1087. Font metric data. */
EXTERN byte_file tfm_file;
EXTERN str_number metric_file_name;

/* 1096. */
EXTERN eight_bits bc, ec;
EXTERN scaled tfm_width[256];
EXTERN scaled tfm_height[256];
EXTERN scaled tfm_depth[256];
EXTERN scaled tfm_ital_corr[256];
EXTERN boolean char_exists[256];
EXTERN unsigned char char_tag[256];
EXTERN integer char_remainder[256];
EXTERN short header_byte[header_size + 1];
EXTERN fourquarters lig_kern[lig_table_size + 1];
EXTERN short nl;
EXTERN scaled kern[max_kerns + 1];
EXTERN integer nk;
EXTERN fourquarters exten[256];
EXTERN short ne;
EXTERN scaled param[max_font_dimen + 1];
EXTERN integer np;
EXTERN short nw, nh, nd, ni;
EXTERN integer skip_table[256];
EXTERN boolean lk_started;
EXTERN integer bchar;
EXTERN integer bch_label;
EXTERN integer ll, lll;
EXTERN integer label_loc[257];
EXTERN eight_bits label_char[257];
EXTERN short label_ptr;

/* 1119. */
EXTERN scaled perturbation;
EXTERN integer excess;

/* 1125. */
EXTERN halfword dimen_head[5];

/* 1130. */
EXTERN scaled max_tfm_dimen;
EXTERN integer tfm_changed;

/* 1149. Shipping characters out. */
EXTERN integer gf_min_m, gf_max_m, gf_min_n, gf_max_n;
EXTERN integer gf_prev_ptr;
EXTERN integer total_chars;
EXTERN integer char_ptr[256];
EXTERN integer gf_dx[256], gf_dy[256];

/* 1152. */
EXTERN eight_bits * gf_buf;
EXTERN gf_index half_buf;
EXTERN gf_index gf_limit;
EXTERN gf_index gf_ptr;
EXTERN integer gf_offset;

/* 1162. */
EXTERN integer boc_c, boc_p;

/* 1183. Dumping and undumping the tables. */
EXTERN str_number base_ident;

/* 1188. */
EXTERN word_file base_file;

/* 1203. */
EXTERN integer ready_already;


EXTERN pool_pointer editnamestart;
EXTERN integer editname_length, editline;
EXTERN ASCII_code xprn[256];
EXTERN boolean stopatspace;

#include "mfcoerce.h"
