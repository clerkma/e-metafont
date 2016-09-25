#undef TRIP
#undef TRAP

#define EXTERN
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

typedef uint8_t ASCII_code;
typedef uint8_t eight_bits;
typedef text /* of  ASCII_code */ alpha_file;
typedef text /* of  eight_bits */ byte_file;
typedef integer pool_pointer;
typedef integer str_number;
typedef uint8_t packed_ASCII_code;
typedef integer scaled;
typedef uint8_t small_number;
typedef integer fraction;
typedef integer angle;
typedef uint8_t quarterword;
typedef integer halfword;
typedef uint8_t twochoices;
typedef uint8_t threechoices;
#include "texmfmem.h"
typedef text /* of  memoryword */ word_file;
typedef uint8_t commandcode;
typedef short screen_row;
typedef short screen_col;
typedef screen_col * trans_spec;
typedef uint8_t pixel_color;
typedef uint8_t window_number;
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
EXTERN uint8_t str_ref[max_strings + 1];

#ifdef INIMF
EXTERN alpha_file poolfile;
#endif /* INIMF */

/* 54. On-line and off-line printing. */
EXTERN alpha_file log_file;
EXTERN uint8_t selector;
EXTERN uint8_t dig[23];
EXTERN integer tally;
EXTERN integer term_offset;
EXTERN integer file_offset;
EXTERN ASCII_code trick_buf[256];
EXTERN integer trick_count;
EXTERN integer first_count;

/* 68. */
EXTERN uint8_t interaction;
EXTERN uint8_t interactionoption;

/* 71. */
EXTERN boolean deletions_allowed;
EXTERN uint8_t history;
EXTERN schar error_count;

/* 74. */
EXTERN str_number help_line[6];
EXTERN uint8_t help_ptr;
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
EXTERN uint8_t j_random;

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
EXTERN uint8_t old_setting;

/* 198. */
EXTERN uint8_t char_class[256];

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
EXTERN uint8_t octant;

/* 389. */
EXTERN scaled cur_x, cur_y;

/* 395. */
EXTERN str_number octant_dir[9];

/* 403. */
EXTERN halfword cur_spec;
EXTERN integer turning_number;
EXTERN halfword cur_pen;
EXTERN uint8_t cur_path_type;
EXTERN scaled max_allowed;

/* 427. */
EXTERN scaled before[max_wiggle + 1], after[max_wiggle + 1];
EXTERN halfword node_to_round[max_wiggle + 1];
EXTERN integer cur_rounding_ptr;
EXTERN integer max_rounding_ptr;

/* 430. */
EXTERN scaled cur_gran;

/* 448. */
EXTERN uint8_t octant_number[9];
EXTERN uint8_t octant_code[9];

/* 455. */
EXTERN boolean rev_turns;

/* 461. */
EXTERN uint8_t y_corr[9], xy_corr[9], z_corr[9];
EXTERN schar x_corr[9];

/* 464. */
EXTERN integer m0, n0, m1, n1;
EXTERN uint8_t d0, d1;

/* 507. */
EXTERN integer env_move[move_size + 1];

/* 552. */
EXTERN uint8_t tol_step;

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
EXTERN uint8_t in_open;
EXTERN uint8_t open_parens;
EXTERN alpha_file input_file[16];
EXTERN integer line;
EXTERN integer line_stack[16];
EXTERN str_number * sourcefilenamestack;
EXTERN str_number * fullsourcefilenamestack;

/* 633. */
EXTERN halfword param_stack[151];
EXTERN uint8_t param_ptr;
EXTERN integer max_param_stack;

/* 634. */
EXTERN integer file_ptr;

/* 659. */
EXTERN uint8_t scanner_status;
EXTERN integer warning_info;

/* 680. */
EXTERN boolean force_eof;

/* 699. */
EXTERN short bg_loc, eg_loc;

/* 738. Conditional processing. */
EXTERN halfword cond_ptr;
EXTERN uint8_t if_limit;
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
EXTERN uint8_t var_flag;

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
EXTERN uint8_t char_tag[256];
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

void initialize(void);
void print_ln(void);
void print_char(ASCIIcode s);
void print(integer s);
void slow_print(integer s);
void print_nl(str_number s);
void print_the_digs(eightbits k);
void print_int(integer n);
void print_scaled(scaled s);
void print_two(scaled x, scaled y);
void print_type(small_number t);
void begin_diagnostic(void);
void end_diagnostic(boolean blankline);
void print_diagnostic(str_number s, str_number t, boolean nuline);
void print_file_name(integer n, integer a, integer e);
void flush_string(str_number s);
void jumpout(void);
void error(void);
void fatal_error(str_number s);
void overflow(str_number s, integer n);
void confusion(str_number s);
boolean init_terminal(void);
str_number make_string(void);
boolean str_eq_buf(str_number s, integer k);
integer str_vs_str(str_number s, str_number t);
boolean get_strings_started(void);
void print_dd(integer n);
void term_input(void);
void normalize_selector(void);
void pause_for_instructions(void);
void missing_err(str_number s);
void clear_arith(void);
integer slow_add(integer x, integer y);
scaled round_decimals(small_number k);
fraction make_fraction(integer p, integer q);
integer take_fraction(integer q, fraction f);
integer take_scaled(integer q, scaled f);
scaled make_scaled(integer p, integer q);
fraction velocity(fraction st, fraction ct, fraction sf, fraction cf, scaled t);
integer ab_vs_cd(integer a, integer b, integer c, integer d);
scaled square_rt(scaled x);
integer pyth_add(integer a, integer b);
integer pyth_sub(integer a, integer b);
scaled m_log(scaled x);
scaled m_exp(scaled x);
angle n_arg(integer x, integer y);
void n_sin_cos(angle z);
void new_randoms(void);
void init)randoms(scaled seed);
scaled unif_rand(scaled x);
scaled norm_rand(void);
void print_word(memoryword w);
void show_token_list(integer p, integer q, integer l, integer nulltally);
void runaway(void);
halfword get_avail(void);
halfword get_node(integer s);
void free_node(halfword p, halfword s);
void sort_avail(void);
void flush_list(halfword p);
void flush_node_list(halfword p);
void check_mem(boolean printlocs);
void search_mem(halfword p);
void print_op(quarterword c);
void fix_date_and_time(void);
halfword id_lookup(integer j, integer l);
void primitive(str_number s, halfword c, halfword o);
halfword new_num_tok(scaled v);
void flush_token_list(halfword p);

void zdeletemacref(halfword p);
#define deletemacref(p) zdeletemacref((halfword) (p))
void zprintcmdmod(integer c, integer m);
#define printcmdmod(c, m) zprintcmdmod((integer) (c), (integer) (m))
void zshowmacro(halfword p, integer q, integer l);
#define showmacro(p, q, l) zshowmacro((halfword) (p), (integer) (q), (integer) (l))
void zinitbignode(halfword p);
#define initbignode(p) zinitbignode((halfword) (p))
halfword idtransform(void);
void znewroot(halfword x);
#define newroot(x) znewroot((halfword) (x))
void zprintvariablename(halfword p);
#define printvariablename(p) zprintvariablename((halfword) (p))
boolean zinteresting(halfword p);
#define interesting(p) zinteresting((halfword) (p))
halfword znewstructure(halfword p);
#define newstructure(p) znewstructure((halfword) (p))
halfword zfindvariable(halfword t);
#define findvariable(t) zfindvariable((halfword) (t))
void zprintpath(halfword h, str_number s, boolean nuline);
#define printpath(h, s, nuline) zprintpath((halfword) (h), (str_number) (s), (boolean) (nuline))
void zprintweight(halfword q, integer xoff);
#define printweight(q, xoff) zprintweight((halfword) (q), (integer) (xoff))
void zprintedges(str_number s, boolean nuline, integer xoff, integer yoff);
#define printedges(s, nuline, xoff, yoff) zprintedges((str_number) (s), (boolean) (nuline), (integer) (xoff), (integer) (yoff))
void zunskew(scaled x, scaled y, small_number octant);
#define unskew(x, y, octant) zunskew((scaled) (x), (scaled) (y), (small_number) (octant))
void zprintpen(halfword p, str_number s, boolean nuline);
#define printpen(p, s, nuline) zprintpen((halfword) (p), (str_number) (s), (boolean) (nuline))
void zprintdependency(halfword p, small_number t);
#define printdependency(p, t) zprintdependency((halfword) (p), (small_number) (t))
void zprintdp(small_number t, halfword p, small_number verbosity);
#define printdp(t, p, verbosity) zprintdp((small_number) (t), (halfword) (p), (small_number) (verbosity))
halfword stashcurexp(void);
void zunstashcurexp(halfword p);
#define unstashcurexp(p) zunstashcurexp((halfword) (p))
void zprintexp(halfword p, small_number verbosity);
#define printexp(p, verbosity) zprintexp((halfword) (p), (small_number) (verbosity))
void zdisperr(halfword p, str_number s);
#define disperr(p, s) zdisperr((halfword) (p), (str_number) (s))
halfword zpplusfq(halfword p, integer f, halfword q, small_number t, small_number tt);
#define pplusfq(p, f, q, t, tt) zpplusfq((halfword) (p), (integer) (f), (halfword) (q), (small_number) (t), (small_number) (tt))
halfword zpoverv(halfword p, scaled v, small_number t0, small_number t1);
#define poverv(p, v, t0, t1) zpoverv((halfword) (p), (scaled) (v), (small_number) (t0), (small_number) (t1))
void zvaltoobig(scaled x);
#define valtoobig(x) zvaltoobig((scaled) (x))
void zmakeknown(halfword p, halfword q);
#define makeknown(p, q) zmakeknown((halfword) (p), (halfword) (q))
void fixdependencies(void);
void ztossknotlist(halfword p);
#define tossknotlist(p) ztossknotlist((halfword) (p))
void ztossedges(halfword h);
#define tossedges(h) ztossedges((halfword) (h))
void ztosspen(halfword p);
#define tosspen(p) ztosspen((halfword) (p))
void zringdelete(halfword p);
#define ringdelete(p) zringdelete((halfword) (p))
void zrecyclevalue(halfword p);
#define recyclevalue(p) zrecyclevalue((halfword) (p))
void zflushcurexp(scaled v);
#define flushcurexp(v) zflushcurexp((scaled) (v))
void zflusherror(scaled v);
#define flusherror(v) zflusherror((scaled) (v))
void putgeterror(void);
void zputgetflusherror(scaled v);
#define putgetflusherror(v) zputgetflusherror((scaled) (v))
void zflushbelowvariable(halfword p);
#define flushbelowvariable(p) zflushbelowvariable((halfword) (p))
void zflushvariable(halfword p, halfword t, boolean discardsuffixes);
#define flushvariable(p, t, discardsuffixes) zflushvariable((halfword) (p), (halfword) (t), (boolean) (discardsuffixes))
small_number zundtype(halfword p);
#define undtype(p) zundtype((halfword) (p))
void zclearsymbol(halfword p, boolean saving);
#define clearsymbol(p, saving) zclearsymbol((halfword) (p), (boolean) (saving))
void zsavevariable(halfword q);
#define savevariable(q) zsavevariable((halfword) (q))
void zsaveinternal(halfword q);
#define saveinternal(q) zsaveinternal((halfword) (q))
void unsave(void);
halfword zcopyknot(halfword p);
#define copyknot(p) zcopyknot((halfword) (p))
halfword zcopypath(halfword p);
#define copypath(p) zcopypath((halfword) (p))
halfword zhtapypoc(halfword p);
#define htapypoc(p) zhtapypoc((halfword) (p))
fraction zcurlratio(scaled gamma, scaled atension, scaled btension);
#define curlratio(gamma, atension, btension) zcurlratio((scaled) (gamma), (scaled) (atension), (scaled) (btension))
void zsetcontrols(halfword p, halfword q, integer k);
#define setcontrols(p, q, k) zsetcontrols((halfword) (p), (halfword) (q), (integer) (k))
void zsolvechoices(halfword p, halfword q, halfword n);
#define solvechoices(p, q, n) zsolvechoices((halfword) (p), (halfword) (q), (halfword) (n))
void zmakechoices(halfword knots);
#define makechoices(knots) zmakechoices((halfword) (knots))
void zmakemoves(scaled xx0, scaled xx1, scaled xx2, scaled xx3, scaled yy0, scaled yy1, scaled yy2, scaled yy3, small_number xicorr, small_number etacorr);
#define makemoves(xx0, xx1, xx2, xx3, yy0, yy1, yy2, yy3, xicorr, etacorr) zmakemoves((scaled) (xx0), (scaled) (xx1), (scaled) (xx2), (scaled) (xx3), (scaled) (yy0), (scaled) (yy1), (scaled) (yy2), (scaled) (yy3), (small_number) (xicorr), (small_number) (etacorr))
void zsmoothmoves(integer b, integer t);
#define smoothmoves(b, t) zsmoothmoves((integer) (b), (integer) (t))
void zinitedges(halfword h);
#define initedges(h) zinitedges((halfword) (h))
void fixoffset(void);
void zedgeprep(integer ml, integer mr, integer nl, integer nr);
#define edgeprep(ml, mr, nl, nr) zedgeprep((integer) (ml), (integer) (mr), (integer) (nl), (integer) (nr))
halfword zcopyedges(halfword h);
#define copyedges(h) zcopyedges((halfword) (h))
void yreflectedges(void);
void xreflectedges(void);
void zyscaleedges(integer s);
#define yscaleedges(s) zyscaleedges((integer) (s))
void zxscaleedges(integer s);
#define xscaleedges(s) zxscaleedges((integer) (s))
void znegateedges(halfword h);
#define negateedges(h) znegateedges((halfword) (h))
void zsortedges(halfword h);
#define sortedges(h) zsortedges((halfword) (h))
void zculledges(integer wlo, integer whi, integer wout, integer win);
#define culledges(wlo, whi, wout, win) zculledges((integer) (wlo), (integer) (whi), (integer) (wout), (integer) (win))
void xyswapedges(void);
void zmergeedges(halfword h);
#define mergeedges(h) zmergeedges((halfword) (h))
integer ztotalweight(halfword h);
#define totalweight(h) ztotalweight((halfword) (h))
void beginedgetracing(void);
void traceacorner(void);
void endedgetracing(void);
void ztracenewedge(halfword r, integer n);
#define tracenewedge(r, n) ztracenewedge((halfword) (r), (integer) (n))
void zlineedges(scaled x0, scaled y0, scaled x1, scaled y1);
#define lineedges(x0, y0, x1, y1) zlineedges((scaled) (x0), (scaled) (y0), (scaled) (x1), (scaled) (y1))
void zmovetoedges(integer m0, integer n0, integer m1, integer n1);
#define movetoedges(m0, n0, m1, n1) zmovetoedges((integer) (m0), (integer) (n0), (integer) (m1), (integer) (n1))
void zskew(scaled x, scaled y, small_number octant);
#define skew(x, y, octant) zskew((scaled) (x), (scaled) (y), (small_number) (octant))
void zabnegate(scaled x, scaled y, small_number octantbefore, small_number octantafter);
#define abnegate(x, y, octantbefore, octantafter) zabnegate((scaled) (x), (scaled) (y), (small_number) (octantbefore), (small_number) (octantafter))
fraction zcrossingpoint(integer a, integer b, integer c);
#define crossingpoint(a, b, c) zcrossingpoint((integer) (a), (integer) (b), (integer) (c))
void zprintspec(str_number s);
#define printspec(s) zprintspec((str_number) (s))
void zprintstrange(str_number s);
#define printstrange(s) zprintstrange((str_number) (s))
void zremovecubic(halfword p);
#define removecubic(p) zremovecubic((halfword) (p))
void zsplitcubic(halfword p, fraction t, scaled xq, scaled yq);
#define splitcubic(p, t, xq, yq) zsplitcubic((halfword) (p), (fraction) (t), (scaled) (xq), (scaled) (yq))
void quadrantsubdivide(void);
void octantsubdivide(void);
void makesafe(void);
void zbeforeandafter(scaled b, scaled a, halfword p);
#define beforeandafter(b, a, p) zbeforeandafter((scaled) (b), (scaled) (a), (halfword) (p))
scaled zgoodval(scaled b, scaled o);
#define goodval(b, o) zgoodval((scaled) (b), (scaled) (o))
scaled zcompromise(scaled u, scaled v);
#define compromise(u, v) zcompromise((scaled) (u), (scaled) (v))
void xyround(void);
void diaground(void);
void znewboundary(halfword p, small_number octant);
#define newboundary(p, octant) znewboundary((halfword) (p), (small_number) (octant))
halfword zmakespec(halfword h, scaled safetymargin, integer tracing);
#define makespec(h, safetymargin, tracing) zmakespec((halfword) (h), (scaled) (safetymargin), (integer) (tracing))
void zendround(scaled x, scaled y);
#define endround(x, y) zendround((scaled) (x), (scaled) (y))
void zfillspec(halfword h);
#define fillspec(h) zfillspec((halfword) (h))
void zdupoffset(halfword w);
#define dupoffset(w) zdupoffset((halfword) (w))
halfword zmakepen(halfword h);
#define makepen(h) zmakepen((halfword) (h))
halfword ztrivialknot(scaled x, scaled y);
#define trivialknot(x, y) ztrivialknot((scaled) (x), (scaled) (y))
halfword zmakepath(halfword penhead);
#define makepath(penhead) zmakepath((halfword) (penhead))
void zfindoffset(scaled x, scaled y, halfword p);
#define findoffset(x, y, p) zfindoffset((scaled) (x), (scaled) (y), (halfword) (p))
void zsplitforoffset(halfword p, fraction t);
#define splitforoffset(p, t) zsplitforoffset((halfword) (p), (fraction) (t))
void zfinoffsetprep(halfword p, halfword k, halfword w, integer x0, integer x1, integer x2, integer y0, integer y1, integer y2, boolean rising, integer n);
#define finoffsetprep(p, k, w, x0, x1, x2, y0, y1, y2, rising, n) zfinoffsetprep((halfword) (p), (halfword) (k), (halfword) (w), (integer) (x0), (integer) (x1), (integer) (x2), (integer) (y0), (integer) (y1), (integer) (y2), (boolean) (rising), (integer) (n))
void zoffsetprep(halfword c, halfword h);
#define offsetprep(c, h) zoffsetprep((halfword) (c), (halfword) (h))
void zskewlineedges(halfword p, halfword w, halfword ww);
#define skewlineedges(p, w, ww) zskewlineedges((halfword) (p), (halfword) (w), (halfword) (ww))
void zdualmoves(halfword h, halfword p, halfword q);
#define dualmoves(h, p, q) zdualmoves((halfword) (h), (halfword) (p), (halfword) (q))
void zfillenvelope(halfword spechead);
#define fillenvelope(spechead) zfillenvelope((halfword) (spechead))
halfword zmakeellipse(scaled majoraxis, scaled minoraxis, angle theta);
#define makeellipse(majoraxis, minoraxis, theta) zmakeellipse((scaled) (majoraxis), (scaled) (minoraxis), (angle) (theta))
scaled zfinddirectiontime(scaled x, scaled y, halfword h);
#define finddirectiontime(x, y, h) zfinddirectiontime((scaled) (x), (scaled) (y), (halfword) (h))
void zcubicintersection(halfword p, halfword pp);
#define cubicintersection(p, pp) zcubicintersection((halfword) (p), (halfword) (pp))
void zpathintersection(halfword h, halfword hh);
#define pathintersection(h, hh) zpathintersection((halfword) (h), (halfword) (hh))
void zopenawindow(windownumber k, scaled r0, scaled c0, scaled r1, scaled c1, scaled x, scaled y);
#define openawindow(k, r0, c0, r1, c1, x, y) zopenawindow((windownumber) (k), (scaled) (r0), (scaled) (c0), (scaled) (r1), (scaled) (c1), (scaled) (x), (scaled) (y))
void zdispedges(windownumber k);
#define dispedges(k) zdispedges((windownumber) (k))
fraction zmaxcoef(halfword p);
#define maxcoef(p) zmaxcoef((halfword) (p))
halfword zpplusq(halfword p, halfword q, small_number t);
#define pplusq(p, q, t) zpplusq((halfword) (p), (halfword) (q), (small_number) (t))
halfword zptimesv(halfword p, integer v, small_number t0, small_number t1, boolean visscaled);
#define ptimesv(p, v, t0, t1, visscaled) zptimesv((halfword) (p), (integer) (v), (small_number) (t0), (small_number) (t1), (boolean) (visscaled))
halfword zpwithxbecomingq(halfword p, halfword x, halfword q, small_number t);
#define pwithxbecomingq(p, x, q, t) zpwithxbecomingq((halfword) (p), (halfword) (x), (halfword) (q), (small_number) (t))
void znewdep(halfword q, halfword p);
#define newdep(q, p) znewdep((halfword) (q), (halfword) (p))
halfword zconstdependency(scaled v);
#define constdependency(v) zconstdependency((scaled) (v))
halfword zsingledependency(halfword p);
#define singledependency(p) zsingledependency((halfword) (p))
halfword zcopydeplist(halfword p);
#define copydeplist(p) zcopydeplist((halfword) (p))
void zlineareq(halfword p, small_number t);
#define lineareq(p, t) zlineareq((halfword) (p), (small_number) (t))
halfword znewringentry(halfword p);
#define newringentry(p) znewringentry((halfword) (p))
void znonlineareq(integer v, halfword p, boolean flushp);
#define nonlineareq(v, p, flushp) znonlineareq((integer) (v), (halfword) (p), (boolean) (flushp))
void zringmerge(halfword p, halfword q);
#define ringmerge(p, q) zringmerge((halfword) (p), (halfword) (q))
void zshowcmdmod(integer c, integer m);
#define showcmdmod(c, m) zshowcmdmod((integer) (c), (integer) (m))
void showcontext(void);
void zbegintokenlist(halfword p, quarterword t);
#define begintokenlist(p, t) zbegintokenlist((halfword) (p), (quarterword) (t))
void endtokenlist(void);
void zencapsulate(halfword p);
#define encapsulate(p) zencapsulate((halfword) (p))
void zinstall(halfword r, halfword q);
#define install(r, q) zinstall((halfword) (r), (halfword) (q))
void zmakeexpcopy(halfword p);
#define makeexpcopy(p) zmakeexpcopy((halfword) (p))
halfword curtok(void);
void backinput(void);
void backerror(void);
void inserror(void);
void beginfilereading(void);
void endfilereading(void);
void clearforerrorprompt(void);
boolean checkoutervalidity(void);
void getnext(void);
void firmuptheline(void);
halfword zscantoks(commandcode terminator, halfword substlist, halfword tailend, small_number suffixcount);
#define scantoks(terminator, substlist, tailend, suffixcount) zscantoks((commandcode) (terminator), (halfword) (substlist), (halfword) (tailend), (small_number) (suffixcount))
void getsymbol(void);
void getclearsymbol(void);
void checkequals(void);
void makeopdef(void);
void zcheckdelimiter(halfword ldelim, halfword rdelim);
#define checkdelimiter(ldelim, rdelim) zcheckdelimiter((halfword) (ldelim), (halfword) (rdelim))
halfword scandeclaredvariable(void);
void scandef(void);
void zprintmacroname(halfword a, halfword n);
#define printmacroname(a, n) zprintmacroname((halfword) (a), (halfword) (n))
void zprintarg(halfword q, integer n, halfword b);
#define printarg(q, n, b) zprintarg((halfword) (q), (integer) (n), (halfword) (b))
void zscantextarg(halfword ldelim, halfword rdelim);
#define scantextarg(ldelim, rdelim) zscantextarg((halfword) (ldelim), (halfword) (rdelim))
void zmacrocall(halfword defref, halfword arglist, halfword macroname);
#define macrocall(defref, arglist, macroname) zmacrocall((halfword) (defref), (halfword) (arglist), (halfword) (macroname))
void expand(void);
void getxnext(void);
void zstackargument(halfword p);
#define stackargument(p) zstackargument((halfword) (p))
void passtext(void);
void zchangeiflimit(small_number l, halfword p);
#define changeiflimit(l, p) zchangeiflimit((small_number) (l), (halfword) (p))
void checkcolon(void);
void conditional(void);
void zbadfor(str_number s);
#define badfor(s) zbadfor((str_number) (s))
void beginiteration(void);
void resumeiteration(void);
void stopiteration(void);
void beginname(void);
boolean zmorename(ASCIIcode c);
#define morename(c) zmorename((ASCIIcode) (c))
void endname(void);
void zpackfilename(str_number n, str_number a, str_number e);
#define packfilename(n, a, e) zpackfilename((str_number) (n), (str_number) (a), (str_number) (e))
void zpackbufferedname(small_number n, integer a, integer b);
#define packbufferedname(n, a, b) zpackbufferedname((small_number) (n), (integer) (a), (integer) (b))
str_number makenamestring(void);
str_number zamakenamestring(alphafile f);
#define amakenamestring(f) zamakenamestring((alphafile) (f))
str_number zbmakenamestring(bytefile f);
#define bmakenamestring(f) zbmakenamestring((bytefile) (f))
str_number zwmakenamestring(wordfile f);
#define wmakenamestring(f) zwmakenamestring((wordfile) (f))
void scanfilename(void);
void zpackjobname(str_number s);
#define packjobname(s) zpackjobname((str_number) (s))
void zpromptfilename(str_number s, str_number e);
#define promptfilename(s, e) zpromptfilename((str_number) (s), (str_number) (e))
void openlogfile(void);
void startinput(void);
void zbadexp(str_number s);
#define badexp(s) zbadexp((str_number) (s))
void zstashin(halfword p);
#define stashin(p) zstashin((halfword) (p))
void backexpr(void);
void badsubscript(void);
void zobliterated(halfword q);
#define obliterated(q) zobliterated((halfword) (q))
void zbinarymac(halfword p, halfword c, halfword n);
#define binarymac(p, c, n) zbinarymac((halfword) (p), (halfword) (c), (halfword) (n))
void materializepen(void);
void knownpair(void);
halfword newknot(void);
small_number scandirection(void);
void zdonullary(quarterword c);
#define donullary(c) zdonullary((quarterword) (c))
boolean znicepair(integer p, quarterword t);
#define nicepair(p, t) znicepair((integer) (p), (quarterword) (t))
void zprintknownorunknowntype(small_number t, integer v);
#define printknownorunknowntype(t, v) zprintknownorunknowntype((small_number) (t), (integer) (v))
void zbadunary(quarterword c);
#define badunary(c) zbadunary((quarterword) (c))
void znegatedeplist(halfword p);
#define negatedeplist(p) znegatedeplist((halfword) (p))
void pairtopath(void);
void ztakepart(quarterword c);
#define takepart(c) ztakepart((quarterword) (c))
void zstrtonum(quarterword c);
#define strtonum(c) zstrtonum((quarterword) (c))
scaled pathlength(void);
void ztestknown(quarterword c);
#define testknown(c) ztestknown((quarterword) (c))
void zdounary(quarterword c);
#define dounary(c) zdounary((quarterword) (c))
void zbadbinary(halfword p, quarterword c);
#define badbinary(p, c) zbadbinary((halfword) (p), (quarterword) (c))
halfword ztarnished(halfword p);
#define tarnished(p) ztarnished((halfword) (p))
void zdepfinish(halfword v, halfword q, small_number t);
#define depfinish(v, q, t) zdepfinish((halfword) (v), (halfword) (q), (small_number) (t))
void zaddorsubtract(halfword p, halfword q, quarterword c);
#define addorsubtract(p, q, c) zaddorsubtract((halfword) (p), (halfword) (q), (quarterword) (c))
void zdepmult(halfword p, integer v, boolean visscaled);
#define depmult(p, v, visscaled) zdepmult((halfword) (p), (integer) (v), (boolean) (visscaled))
void zhardtimes(halfword p);
#define hardtimes(p) zhardtimes((halfword) (p))
void zdepdiv(halfword p, scaled v);
#define depdiv(p, v) zdepdiv((halfword) (p), (scaled) (v))
void zsetuptrans(quarterword c);
#define setuptrans(c) zsetuptrans((quarterword) (c))
void zsetupknowntrans(quarterword c);
#define setupknowntrans(c) zsetupknowntrans((quarterword) (c))
void ztrans(halfword p, halfword q);
#define trans(p, q) ztrans((halfword) (p), (halfword) (q))
void zpathtrans(halfword p, quarterword c);
#define pathtrans(p, c) zpathtrans((halfword) (p), (quarterword) (c))
void zedgestrans(halfword p, quarterword c);
#define edgestrans(p, c) zedgestrans((halfword) (p), (quarterword) (c))
void zbilin1(halfword p, scaled t, halfword q, scaled u, scaled delta);
#define bilin1(p, t, q, u, delta) zbilin1((halfword) (p), (scaled) (t), (halfword) (q), (scaled) (u), (scaled) (delta))
void zaddmultdep(halfword p, scaled v, halfword r);
#define addmultdep(p, v, r) zaddmultdep((halfword) (p), (scaled) (v), (halfword) (r))
void zbilin2(halfword p, halfword t, scaled v, halfword u, halfword q);
#define bilin2(p, t, v, u, q) zbilin2((halfword) (p), (halfword) (t), (scaled) (v), (halfword) (u), (halfword) (q))
void zbilin3(halfword p, scaled t, scaled v, scaled u, scaled delta);
#define bilin3(p, t, v, u, delta) zbilin3((halfword) (p), (scaled) (t), (scaled) (v), (scaled) (u), (scaled) (delta))
void zbigtrans(halfword p, quarterword c);
#define bigtrans(p, c) zbigtrans((halfword) (p), (quarterword) (c))
void zcat(halfword p);
#define cat(p) zcat((halfword) (p))
void zchopstring(halfword p);
#define chopstring(p) zchopstring((halfword) (p))
void zchoppath(halfword p);
#define choppath(p) zchoppath((halfword) (p))
void zpairvalue(scaled x, scaled y);
#define pairvalue(x, y) zpairvalue((scaled) (x), (scaled) (y))
void zsetupoffset(halfword p);
#define setupoffset(p) zsetupoffset((halfword) (p))
void zsetupdirectiontime(halfword p);
#define setupdirectiontime(p) zsetupdirectiontime((halfword) (p))
void zfindpoint(scaled v, quarterword c);
#define findpoint(v, c) zfindpoint((scaled) (v), (quarterword) (c))
void zdobinary(halfword p, quarterword c);
#define dobinary(p, c) zdobinary((halfword) (p), (quarterword) (c))
void zfracmult(scaled n, scaled d);
#define fracmult(n, d) zfracmult((scaled) (n), (scaled) (d))
void gfswap(void);
void zgffour(integer x);
#define gffour(x) zgffour((integer) (x))
void zgftwo(integer x);
#define gftwo(x) zgftwo((integer) (x))
void zgfthree(integer x);
#define gfthree(x) zgfthree((integer) (x))
void zgfpaint(integer d);
#define gfpaint(d) zgfpaint((integer) (d))
void zgfstring(str_number s, str_number t);
#define gfstring(s, t) zgfstring((str_number) (s), (str_number) (t))
void zgfboc(integer minm, integer maxm, integer minn, integer maxn);
#define gfboc(minm, maxm, minn, maxn) zgfboc((integer) (minm), (integer) (maxm), (integer) (minn), (integer) (maxn))
void initgf(void);
void zshipout(eightbits c);
#define shipout(c) zshipout((eightbits) (c))
void ztryeq(halfword l, halfword r);
#define tryeq(l, r) ztryeq((halfword) (l), (halfword) (r))
void zmakeeq(halfword lhs);
#define makeeq(lhs) zmakeeq((halfword) (lhs))
void doequation(void);
void doassignment(void);
void dotypedeclaration(void);
void dorandomseed(void);
void doprotection(void);
void defdelims(void);
void dointerim(void);
void dolet(void);
void donewinternal(void);
void doshow(void);
void disptoken(void);
void doshowtoken(void);
void doshowstats(void);
void zdispvar(halfword p);
#define dispvar(p) zdispvar((halfword) (p))
void doshowvar(void);
void doshowdependencies(void);
void doshowwhatever(void);
boolean scanwith(void);
void zfindedgesvar(halfword t);
#define findedgesvar(t) zfindedgesvar((halfword) (t))
void doaddto(void);
scaled ztfmcheck(small_number m);
#define tfmcheck(m) ztfmcheck((small_number) (m))
void doshipout(void);
void dodisplay(void);
boolean zgetpair(commandcode c);
#define getpair(c) zgetpair((commandcode) (c))
void doopenwindow(void);
void docull(void);
void domessage(void);
eightbits getcode(void);
void zsettag(halfword c, small_number t, halfword r);
#define settag(c, t, r) zsettag((halfword) (c), (small_number) (t), (halfword) (r))
void dotfmcommand(void);
void dospecial(void);
void storebasefile(void);
void dostatement(void);
void maincontrol(void);
halfword zsortin(scaled v);
#define sortin(v) zsortin((scaled) (v))
integer zmincover(scaled d);
#define mincover(d) zmincover((scaled) (d))
scaled zthresholdfn(integer m);
#define thresholdfn(m) zthresholdfn((integer) (m))
integer zskimp(integer m);
#define skimp(m) zskimp((integer) (m))
void tfm_warning(small_number m);
void fix_design_size(void);
integer dimen_out(scaled x);
void fix_checksum(void);
void tfm_qqqq(fourquarters x);
boolean open_base_file(void);
boolean load_base_file(void);
void scan_primary(void);
void scan_suffix(void);
void scan_secondary(void);
void scan_tertiary(void);
void scan_expression(void);
void get_boolean(void);
void print_capsule(void);
void token_recycle(void);
void close_files_and_terminate(void);
void final_cleanup(void);
void init_prim(void);
void init_tab(void);
void debug_help(void);

extern str_number getjobname(str_number);
extern void calledit(packedASCIIcode *, poolpointer, integer, integer);
extern void blankrectangle(screencol, screencol, screenrow, screenrow);
extern void paintrow(screenrow, pixelcolor, transspec, screencol);

extern str_number makefullnamestring(void);
