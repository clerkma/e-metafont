#define EXTERN
#define STAT
#define INI
#define INIMF

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define max_internal (300) 
#define stack_size (300) 
#define max_strings (7500) 
#define string_vacancies (74000L) 
#define pool_size (100000L) 
#define move_size (20000) 
#define max_wiggle (1000) 
#define pool_name (TEXMFpool_name) 
#define enginename (TEXMFENGINENAME) 
#define path_size (1000) 
#define bi_stack_size (1500) 
#define header_size (100)
#define lig_table_size (15000)
#define max_kerns (2500)
#define max_font_dimen (60)
#define infmainmemory (3000)
#define supmainmemory (8000000L)
#define infbufsize (500)
#define supbufsize (30000000L)

typedef int32_t  integer;
typedef uint32_t boolean;
typedef char* constcstring;

typedef uint8_t ASCII_code;
typedef uint8_t eight_bits;
typedef FILE* /* of  ASCII_code */ alpha_file;
typedef FILE* /* of  eight_bits */ byte_file;
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
typedef FILE* /* of  memory_word */ word_file;
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

EXTERN integer bad;

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

EXTERN ASCII_code xord[256];
EXTERN ASCII_code xchr[256];

EXTERN ASCII_code * name_of_file;
EXTERN integer name_length;

EXTERN ASCII_code * buffer;
EXTERN integer first;
EXTERN integer last;
EXTERN integer max_buf_stack;

EXTERN packed_ASCII_code str_pool[pool_size + 1];
EXTERN pool_pointer str_start[max_strings + 1];
EXTERN pool_pointer pool_ptr;
EXTERN str_number str_ptr;
EXTERN pool_pointer init_pool_ptr;
EXTERN str_number init_str_ptr;
EXTERN pool_pointer max_pool_ptr;
EXTERN str_number max_str_ptr;

EXTERN uint8_t str_ref[max_strings + 1];

#ifdef INIMF
EXTERN alpha_file pool_file;
#endif /* INIMF */

EXTERN alpha_file log_file;
EXTERN uint8_t selector;
EXTERN uint8_t dig[23];
EXTERN integer tally;
EXTERN integer term_offset;
EXTERN integer file_offset;
EXTERN ASCII_code trick_buf[256];
EXTERN integer trick_count;
EXTERN integer first_count;

EXTERN uint8_t interaction;
EXTERN uint8_t interactionoption;

EXTERN boolean deletions_allowed;
EXTERN uint8_t history;
EXTERN schar error_count;

EXTERN str_number help_line[6];
EXTERN uint8_t help_ptr;
EXTERN boolean use_err_help;
EXTERN str_number err_help;

EXTERN integer interrupt;
EXTERN boolean OK_to_interrupt;

EXTERN boolean arith_error;

EXTERN integer two_to_the[31];
EXTERN integer spec_log[29];

EXTERN angle spec_atan[27];

EXTERN fraction n_sin, n_cos;

EXTERN fraction randoms[55];
EXTERN uint8_t j_random;

EXTERN memory_word * mem;
EXTERN halfword lo_mem_max;
EXTERN halfword hi_mem_min;

EXTERN integer var_used, dyn_used;

EXTERN halfword avail;
EXTERN halfword mem_end;

EXTERN halfword rover;

#ifdef TEXMF_DEBUG
EXTERN boolean freearr[2];
EXTERN boolean was_free[2];
EXTERN halfword was_mem_end, was_lo_max, was_hi_min;
EXTERN boolean panicking;
#endif /* TEXMF_DEBUG */

EXTERN scaled internal[max_internal + 1];
EXTERN str_number int_name[max_internal + 1];
EXTERN integer int_ptr;

EXTERN uint8_t old_setting;

EXTERN uint8_t char_class[256];

EXTERN halfword hash_used;
EXTERN integer st_count;

EXTERN two_halves hash[9770];
EXTERN two_halves eqtb[9770];

EXTERN halfword g_pointer;

EXTERN small_number 
#define big_node_size (zzzaa -13)
  zzzaa[2];

EXTERN halfword save_ptr;

EXTERN halfword path_tail;

EXTERN scaled delta_x[path_size + 1], delta_y[path_size + 1], delta[path_size + 1];
EXTERN angle psi[path_size + 1];

EXTERN angle theta[path_size + 1];
EXTERN fraction uu[path_size + 1];
EXTERN angle vv[path_size + 1];
EXTERN fraction ww[path_size + 1];

EXTERN fraction st, ct, sf, cf;

EXTERN integer move[move_size + 1];
EXTERN integer move_ptr;

EXTERN integer bisect_stack[bi_stack_size + 1];
EXTERN integer bisect_ptr;

EXTERN halfword cur_edges;
EXTERN integer cur_wt;

EXTERN integer trace_x;
EXTERN integer trace_y;
EXTERN integer trace_yy;

EXTERN uint8_t octant;

EXTERN scaled cur_x, cur_y;

EXTERN str_number octant_dir[9];

EXTERN halfword cur_spec;
EXTERN integer turning_number;
EXTERN halfword cur_pen;
EXTERN uint8_t cur_path_type;
EXTERN scaled max_allowed;

EXTERN scaled before[max_wiggle + 1], after[max_wiggle + 1];
EXTERN halfword node_to_round[max_wiggle + 1];
EXTERN integer cur_rounding_ptr;
EXTERN integer max_rounding_ptr;

EXTERN scaled cur_gran;

EXTERN uint8_t octant_number[9];
EXTERN uint8_t octant_code[9];

EXTERN boolean rev_turns;

EXTERN uint8_t y_corr[9], xy_corr[9], z_corr[9];
EXTERN schar x_corr[9];

EXTERN integer m0, n0, m1, n1;
EXTERN uint8_t d0, d1;

EXTERN integer env_move[move_size + 1];

EXTERN uint8_t tol_step;

EXTERN integer cur_t, cur_tt;
EXTERN integer time_to_go;
EXTERN integer max_t;

EXTERN integer delx, dely;
EXTERN integer tol;
EXTERN integer uv, xy;
EXTERN integer three_l;
EXTERN integer appr_t, appr_tt;

EXTERN boolean screen_started;
EXTERN boolean screen_OK;

EXTERN boolean window_open[16];
EXTERN screen_col left_col[16];
EXTERN screen_col right_col[16];
EXTERN screen_row top_row[16];
EXTERN screen_row bot_row[16];
EXTERN integer m_window[16];
EXTERN integer n_window[16];
EXTERN integer window_time[16];

EXTERN trans_spec row_transition;

EXTERN integer serial_no;

EXTERN boolean fix_needed;
EXTERN boolean watch_coefs;
EXTERN halfword dep_final;

EXTERN eight_bits cur_cmd;
EXTERN integer cur_mod;
EXTERN halfword cur_sym;

EXTERN in_state_record input_stack[stack_size + 1];
EXTERN integer input_ptr;
EXTERN integer max_in_stack;
EXTERN in_state_record cur_input;

EXTERN uint8_t in_open;
EXTERN uint8_t open_parens;
EXTERN alpha_file input_file[16];
EXTERN integer line;
EXTERN integer line_stack[16];
EXTERN str_number * sourcefilenamestack;
EXTERN str_number * fullsourcefilenamestack;

EXTERN halfword param_stack[151];
EXTERN uint8_t param_ptr;
EXTERN integer max_param_stack;

EXTERN integer file_ptr;

EXTERN uint8_t scanner_status;
EXTERN integer warning_info;

EXTERN boolean force_eof;

EXTERN short bg_loc, eg_loc;

EXTERN halfword cond_ptr;
EXTERN uint8_t if_limit;
EXTERN small_number cur_if;
EXTERN integer if_line;

EXTERN halfword loop_ptr;

EXTERN str_number cur_name;
EXTERN str_number cur_area;
EXTERN str_number cur_ext;

EXTERN pool_pointer area_delimiter;
EXTERN pool_pointer ext_delimiter;
EXTERN integer basedefaultlength;

EXTERN cstring MF_base_default;

EXTERN str_number job_name;
EXTERN boolean log_opened;
EXTERN str_number texmflogname;

EXTERN str_number gf_ext;

EXTERN byte_file gf_file;
EXTERN str_number output_file_name;

EXTERN small_number cur_type;
EXTERN integer cur_exp;

EXTERN integer 
#define max_c (zzzab -17)
  zzzab[2];
EXTERN halfword 
#define max_ptr (zzzac -17)
  zzzac[2];
EXTERN halfword 
#define max_link (zzzad -17)
  zzzad[2];

EXTERN uint8_t var_flag;

EXTERN scaled txx, txy, tyx, tyy, tx, ty;

EXTERN halfword start_sym;

EXTERN boolean long_help_seen;

EXTERN byte_file tfm_file;
EXTERN str_number metric_file_name;

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

EXTERN scaled perturbation;
EXTERN integer excess;

EXTERN halfword dimen_head[5];

EXTERN scaled max_tfm_dimen;
EXTERN integer tfm_changed;

EXTERN integer gf_min_m, gf_max_m, gf_min_n, gf_max_n;
EXTERN integer gf_prev_ptr;
EXTERN integer total_chars;
EXTERN integer char_ptr[256];
EXTERN integer gf_dx[256], gf_dy[256];

EXTERN eight_bits * gf_buf;
EXTERN gf_index half_buf;
EXTERN gf_index gf_limit;
EXTERN gf_index gf_ptr;
EXTERN integer gf_offset;

EXTERN integer boc_c, boc_p;

EXTERN str_number base_ident;

EXTERN word_file base_file;

EXTERN integer ready_already;

EXTERN pool_pointer editnamestart;
EXTERN integer editname_length, editline;
EXTERN ASCII_code xprn[256];
EXTERN boolean stopatspace;

/* M A C R O S */
/* 90 */
#define check_arith() \
  do { if (arith_error) clear_arith(); } while (0)
#define if_test 1
#define fi_or_else 2
#define input 3
#define iteration 4
#define repeat_loop 5
#define exit_test 6
#define relex 7
#define scan_tokens 8
#define expand_after 9
#define defined_macro 10
#define min_command (defined_macro + 1)
#define display_command 12
#define save_command 13
#define let_command 14
#define new_internal 15
#define macro_def 16
#define ship_out_command 17
#define add_to_command 18
#define cull_command 19
#define tfm_command 20
#define protection_command 21
#define show_command 22
#define mode_command 23
#define random_seed 24
#define message_command 25
#define every_job_command 26
#define delimiters 27
#define open_window 28
#define special_command 29
#define type_name 30
#define max_statement_command type_name
#define min_primary_command type_name
#define let_delimiter 31
#define begin_group 32
#define nullary 33
#define unary 34
#define str_op 35
#define cycle 36
#define primary_binary 37
#define capsule_token 38
#define string_token 39
#define internal_quantity 40
#define min_suffix_token internal_quantity
#define tag_token 41
#define numeric_token 42
#define max_suffix_token numeric_token
#define plus_or_minus 43
#define max_primary_command plus_or_minus
#define min_tertiary_command plus_or_minus
#define tertiary_secondary_macro 44
#define tertiary_binary 45
/* 325 */
#define knil info
#define sorted_loc(a) (a + 1)
#define sorted(a) link(sorted_loc(a))
#define unsorted(a) info(a + 1)
#define row_node_size 2
/* 326 */
#define zero_field 4096
#define n_min(a) info(a + 1)
#define n_max(a) link(a + 1)
#define m_min(a) info(a + 2)
#define m_max(a) link(a + 2)
#define m_offset(a) info(a + 3)
#define last_window(a) link(a + 3)
#define last_window_time(a) mem[a + 4].cint
#define n_pos(a) info(a + 5)
#define n_rover(a) link(a + 5)
#define edge_header_size 6
#define valid_range(a) (abs(a - 4096) < 4096)
#define empty_edges(a) link(a)=a

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
void init_randoms(scaled seed);
scaled unif_rand(scaled x);
scaled norm_rand(void);
void print_word(memory_word w);
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
void delete_mac_ref(halfword p);
void print_cmd_mod(integer c, integer m);
void show_macro(halfword p, integer q, integer l);
void init_big_node(halfword p);
halfword id_transform(void);
void new_root(halfword x);
void print_variable_name(halfword p);
boolean interesting(halfword p);
halfword new_structure(halfword p);
halfword find_variable(halfword t);
void print_path(halfword h, str_number s, boolean nuline);
void print_weight(halfword q, integer xoff);
void print_edges(str_number s, boolean nuline, integer xoff, integer yoff);
void unskew(scaled x, scaled y, small_number octant);
void print_pen(halfword p, str_number s, boolean nuline);
void print_dependency(halfword p, small_number t);
void print_dp(small_number t, halfword p, small_number verbosity);
halfword stash_cur_exp(void);
void unstash_cur_exp(halfword p);
void print_exp(halfword p, small_number verbosity);
void disp_err(halfword p, str_number s);
halfword p_plus_fq(halfword p, integer f, halfword q, small_number t, small_number tt);
halfword poverv(halfword p, scaled v, small_number t0, small_number t1);
void val_too_big(scaled x);
void make_known(halfword p, halfword q);
void fix_dependencies(void);
void toss_knot_list(halfword p);
void toss_edges(halfword h);
void toss_pen(halfword p);
void ring_delete(halfword p);
void recycle_value(halfword p);
void flush_cur_exp(scaled v);
void flush_error(scaled v);
void put_get_error(void);
void put_get_flush_error(scaled v);
void flush_below_variable(halfword p);
void flush_variable(halfword p, halfword t, boolean discardsuffixes);
small_number und_type(halfword p);
void clear_symbol(halfword p, boolean saving);
void save_variable(halfword q);
void save_internal(halfword q);
void unsave(void);
halfword copy_knot(halfword p);
halfword copy_path(halfword p);
halfword htap_ypoc(halfword p);
fraction curl_ratio(scaled gamma, scaled atension, scaled btension);
void set_controls(halfword p, halfword q, integer k);
void solve_choices(halfword p, halfword q, halfword n);
void make_choices(halfword knots);
void make_moves(scaled xx0, scaled xx1, scaled xx2, scaled xx3, scaled yy0, scaled yy1, scaled yy2, scaled yy3, small_number xicorr, small_number etacorr);
void smooth_moves(integer b, integer t);
void init_edges(halfword h);
void fix_offset(void);
void edge_prep(integer ml, integer mr, integer nl, integer nr);
halfword copy_edges(halfword h);
void y_reflect_edges(void);
void x_reflect_edges(void);
void y_scale_edges(integer s);
void x_scale_edges(integer s);
void negate_edges(halfword h);
void sort_edges(halfword h);
void cull_edges(integer wlo, integer whi, integer wout, integer win);
void xy_swap_edges(void);
void merge_edges(halfword h);
integer total_weight(halfword h);
void begin_edge_tracing(void);
void trace_a_corner(void);
void end_edge_tracing(void);
void trace_new_edge(halfword r, integer n);
void line_edges(scaled x0, scaled y0, scaled x1, scaled y1);
void move_to_edges(integer m0, integer n0, integer m1, integer n1);
void skew(scaled x, scaled y, small_number octant);
void abnegate(scaled x, scaled y, small_number octantbefore, small_number octantafter);
fraction crossing_point(integer a, integer b, integer c);
void print_spec(str_number s);
void print_strange(str_number s);
void remove_cubic(halfword p);
void split_cubic(halfword p, fraction t, scaled xq, scaled yq);
void quadrant_sub_divide(void);
void octant_sub_divide(void);
void make_safe(void);
void before_and_after(scaled b, scaled a, halfword p);
scaled good_val(scaled b, scaled o);
scaled compromise(scaled u, scaled v);
void xy_round(void);
void diag_round(void);
void new_boundary(halfword p, small_number octant);
halfword make_spec(halfword h, scaled safetymargin, integer tracing);
void end_round(scaled x, scaled y);
void fill_spec(halfword h);
void dup_offset(halfword w);
halfword make_pen(halfword h);
halfword trivial_knot(scaled x, scaled y);
halfword make_path(halfword penhead);
void find_offset(scaled x, scaled y, halfword p);
void split_for_offset(halfword p, fraction t);
void fin_offset_prep(halfword p, halfword k, halfword w, integer x0, integer x1, integer x2, integer y0, integer y1, integer y2, boolean rising, integer n);
void offset_prep(halfword c, halfword h);
void skew_line_edges(halfword p, halfword w, halfword ww);
void dual_moves(halfword h, halfword p, halfword q);
void fill_envelope(halfword spechead);
halfword make_ellipse(scaled major_axis, scaled minor_axis, angle theta);
scaled find_direction_time(scaled x, scaled y, halfword h);
void cubic_intersection(halfword p, halfword pp);
void path_intersection(halfword h, halfword hh);
void open_a_window(windownumber k, scaled r0, scaled c0, scaled r1, scaled c1, scaled x, scaled y);
void disp_edges(windownumber k);
fraction max_coef(halfword p);
halfword p_plus_q(halfword p, halfword q, small_number t);
halfword p_times_v(halfword p, integer v, small_number t0, small_number t1, boolean v_is_scaled);
halfword p_with_x_becoming_q(halfword p, halfword x, halfword q, small_number t);
void new_dep(halfword q, halfword p);
halfword const_dependency(scaled v);
halfword single_dependency(halfword p);
halfword copy_dep_list(halfword p);
void linear_eq(halfword p, small_number t);
halfword new_ring_entry(halfword p);
void non_linear_eq(integer v, halfword p, boolean flushp);
void ring_merge(halfword p, halfword q);
void show_cmd_mod(integer c, integer m);
void show_context(void);
void begin_token_list(halfword p, quarterword t);
void end_token_list(void);
void encapsulate(halfword p);
void install(halfword r, halfword q);
void make_exp_copy(halfword p);
halfword cur_tok(void);
void back_input(void);
void back_error(void);
void ins_error(void);
void begin_file_reading(void);
void end_file_reading(void);
void clear_for_err_or_prompt(void);
boolean check_outer_validity(void);
void get_next(void);
void firmup_the_line(void);
halfword scan_toks(commandcode terminator, halfword substlist, halfword tailend, small_number suffixcount);
void get_symbol(void);
void get_clear_symbol(void);
void check_equals(void);
void make_op_def(void);
void check_delimiter(halfword ldelim, halfword rdelim);
halfword scan_declared_variable(void);
void scan_def(void);
void print_macro_name(halfword a, halfword n);
void print_arg(halfword q, integer n, halfword b);
void scan_text_arg(halfword ldelim, halfword rdelim);
void macro_call(halfword defref, halfword arg_list, halfword macro_name);
void expand(void);
void get_x_next(void);
void stack_argument(halfword p);
void pass_text(void);
void change_if_limit(small_number l, halfword p);
void check_colon(void);
void conditional(void);
void bad_for(str_number s);
void begin_iteration(void);
void resume_iteration(void);
void stop_iteration(void);
void begin_name(void);
boolean more_name(ASCIIcode c);
void end_name(void);
void pack_file_name(str_number n, str_number a, str_number e);
void pack_buffered_name(small_number n, integer a, integer b);
str_number make_name_string(void);
str_number a_make_name_string(alphafile f);
str_number b_make_name_string(bytefile f);
str_number w_make_name_string(wordfile f);
void scan_file_name(void);
void pack_job_name(str_number s);
void prompt_file_name(str_number s, str_number e);
void open_log_file(void);
void start_input(void);
void bad_exp(str_number s);
void stash_in(halfword p);
void back_expr(void);
void bad_sub_script(void);
void obliterated(halfword q);
void binary_mac(halfword p, halfword c, halfword n);
void materialize_pen(void);
void known_pair(void);
halfword new_knot(void);
small_number scan_direction(void);
void do_nullary(quarterword c);
boolean nice_pair(integer p, quarterword t);
void print_known_or_unknown_type(small_number t, integer v);
void bad_unary(quarterword c);
void negate_dep_list(halfword p);
void pair_to_path(void);
void take_part(quarterword c);
void str_to_num(quarterword c);
scaled path_length(void);
void test_known(quarterword c);
void do_unary(quarterword c);
void bad_binary(halfword p, quarterword c);
halfword tarnished(halfword p);
void dep_finish(halfword v, halfword q, small_number t);
void add_or_subtract(halfword p, halfword q, quarterword c);
void dep_mult(halfword p, integer v, boolean v_is_scaled);
void hard_times(halfword p);
void dep_div(halfword p, scaled v);
void setup_trans(quarterword c);
void setup_known_trans(quarterword c);
void trans(halfword p, halfword q);
void path_trans(halfword p, quarterword c);
void edges_trans(halfword p, quarterword c);
void bilin1(halfword p, scaled t, halfword q, scaled u, scaled delta);
void add_mult_dep(halfword p, scaled v, halfword r);
void bilin2(halfword p, halfword t, scaled v, halfword u, halfword q);
void bilin3(halfword p, scaled t, scaled v, scaled u, scaled delta);
void big_trans(halfword p, quarterword c);
void cat(halfword p);
void chop_string(halfword p);
void chop_path(halfword p);
void pair_value(scaled x, scaled y);
void setup_offset(halfword p);
void setup_direction_time(halfword p);
void find_point(scaled v, quarterword c);
void do_binary(halfword p, quarterword c);
void frac_mult(scaled n, scaled d);
void gf_swap(void);
void gf_four(integer x);
void gf_two(integer x);
void gf_three(integer x);
void gf_paint(integer d);
void gf_string(str_number s, str_number t);
void gf_boc(integer minm, integer maxm, integer minn, integer maxn);
void init_gf(void);
void shipout(eightbits c);
void try_eq(halfword l, halfword r);
void make_eq(halfword lhs);
void do_equation(void);
void do_assignment(void);
void do_type_declaration(void);
void do_random_seed(void);
void do_protection(void);
void def_delims(void);
void do_interim(void);
void do_let(void);
void do_new_internal(void);
void do_show(void);
void disp_token(void);
void do_show_token(void);
void do_show_stats(void);
void disp_var(halfword p);
void do_show_var(void);
void do_show_dependencies(void);
void do_show_whatever(void);
boolean scan_with(void);
void find_edges_var(halfword t);
void do_add_to(void);
scaled tfm_check(small_number m);
void do_shipout(void);
void do_display(void);
boolean get_pair(commandcode c);
void do_open_window(void);
void do_cull(void);
void do_message(void);
eightbits get_code(void);
void set_tag(halfword c, small_number t, halfword r);
void do_tfm_command(void);
void do_special(void);
void store_base_file(void);
void do_statement(void);
void main_control(void);
halfword sort_in(scaled v);
integer min_cover(scaled d);
scaled threshold_fn(integer m);
integer skimp(integer m);
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

str_number getjobname(str_number);
void calledit(packedASCIIcode *, poolpointer, integer, integer);
void blankrectangle(screencol, screencol, screenrow, screenrow);
void paintrow(screenrow, pixelcolor, transspec, screencol);
str_number makefullnamestring(void);
