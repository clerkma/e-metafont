#define EXTERN
#define STAT
#define INI
#define INIMF

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

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
typedef union {
  int32_t cint;
  struct {
    union {
      uint16_t lh;
      struct {
        uint8_t b0, b1;
      };
    };
    uint16_t rh;
  } hh;
  struct {
    uint8_t b0, b1, b2, b3;
  } qqqq;
} memory_word;
typedef FILE* /* of  memory_word */ word_file;
typedef uint8_t command_code;
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
EXTERN integer mem_top;
EXTERN integer mem_max;
EXTERN integer buf_size;
EXTERN integer error_line;
EXTERN integer half_error_line;
EXTERN integer max_print_line;
EXTERN integer screenwidth;
EXTERN integer screendepth;
EXTERN integer gf_buf_size;
EXTERN cinttype parsefirstlinep;
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
EXTERN int8_t error_count;

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

EXTERN integer bisect_stack[bistack_size + 1];
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
EXTERN integer base_default_length;

EXTERN char * MF_base_default;

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
/* 11 */
/*
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
#define bistack_size (1500)
#define header_size (100)
#define lig_table_size (15000)
#define max_kerns (2500)
#define max_font_dimen (60)
#define infmainmemory (3000)
#define supmainmemory (8000000L)
#define infbuf_size (500)
#define supbuf_size (30000000L)
*/
const uint32_t mem_max = 30000; /*{greatest index in \MF's internal |mem| array;
  must be strictly less than |max_halfword|;
  must be equal to |mem_top| in \.{INIMF}, otherwise |>=mem_top|}*/
const uint32_t max_internal = 100; //{maximum number of internal quantities}
const uint32_t buf_size = 500; /*{maximum number of characters simultaneously present in
  current lines of open files; must not exceed |max_halfword|}*/
const uint32_t error_line = 72; //{width of context lines on terminal error messages}
const uint32_t half_error_line = 42; /*{width of first lines of contexts in terminal
  error messages; should be between 30 and |error_line-15|}*/
const uint32_t max_print_line = 79; //{width of longest text lines output; should be at least 60}
const uint32_t screen_width = 768; //{number of pixels in each row of screen display}
const uint32_t screen_depth = 1024; //{number of pixels in each column of screen display}
const uint32_t stack_size = 30; //{maximum number of simultaneous input sources}
const uint32_t max_strings = 2000; //{maximum number of strings; must not exceed |max_halfword|}
const uint32_t string_vacancies = 8000; /*{the minimum number of characters that should be
  available for the user's identifier names and strings,
  after \MF's own error messages are stored}*/
const uint32_t pool_size = 32000; /*{maximum number of characters in strings, including all
  error messages and help texts, and the names of all identifiers;
  must exceed |string_vacancies| by the total
  length of \MF's own strings, which is currently about 22000}*/
const uint32_t move_size = 5000; //{space for storing moves in a single octant}
const uint32_t max_wiggle = 300; //{number of autorounded points per cycle}
const uint32_t gf_buf_size = 800; //{size of the output buffer, must be a multiple of 8}
const uint32_t file_name_size = 40; //{file names shouldn't be longer than this}
const uint8_t* pool_name = "MFbases:MF.POOL                         ";
  //{string of length |file_name_size|; tells where the string pool appears}
const uint32_t path_size = 300; //{maximum number of knots between breakpoints of a path}
const uint32_t bistack_size = 785; /*{size of stack for bisection algorithms;
  should probably be left at this value}*/
const uint32_t header_size = 100; //{maximum number of \.{TFM} header words, times~4}
const uint32_t lig_table_size = 5000; /*{maximum number of ligature/kern steps, must be
  at least 255 and at most 32510}*/
const uint32_t max_kerns = 500; //{maximum number of distinct kern amounts}
const uint32_t max_font_dimen = 50; //{maximum number of \&{fontdimen} parameters}
/* 12 */
#define mem_min 0 /*{smallest index in the |mem| array, must not be less
  than |min_halfword|}*/
#define mem_top 30000 /*{largest index in the |mem| array dumped by \.{INIMF};
  must be substantially larger than |mem_min|
  and not greater than |mem_max|}*/
#define hash_size 2100 /*{maximum number of symbolic tokens,
  must be less than |max_halfword-3*param_size|}*/
#define hash_prime 1777 //{a prime number equal to about 85\pct! of |hash_size|}
#define max_in_open 6 /*{maximum number of input files and error insertions that
  can be going on simultaneously}*/
#define param_size 150 //{maximum number of simultaneous macro parameters}
/* 16 */
#define incr(a) a=a+1 //{increase a variable by unity}
#define decr(a) a=a-1 //{decrease a variable by unity}
#define negate(a) a=-a //{change the sign of a variable}
#define double(a) a=a+a //{multiply a variable by two}
#define do_nothing //{empty statement}
/* 19 */
#define text_char char //{the data type of characters in text files}
#define first_text_char 0 //{ordinal number of the smallest element of |text_char|}
#define last_text_char 255 //{ordinal number of the largest element of |text_char|}
/* 37 */
#define si(a) a //{convert from |ASCII_code| to |packed_ASCII_code|}
#define so(a) a //{convert from |packed_ASCII_code| to |ASCII_code|}
/* 39 */
#define length(a) (str_start[a+1]-str_start[a]) /*{the number of characters
  in string number \#}*/
/* 40 */
#define cur_length (pool_ptr - str_start[str_ptr])
/* 54 */
#define no_print 0 //{|selector| setting that makes data disappear}
#define term_only 1 //{printing is destined for the terminal only}
#define log_only 2 //{printing is destined for the transcript file only}
#define term_and_log 3 //{normal |selector| setting}
#define pseudo 4 //{special |selector| setting for |show_context|}
#define new_string 5 //{printing is deflected to the string pool}
#define max_selector 5 //{highest selector setting}
/* 68 */
#define batch_mode 0 //{omits all stops and omits terminal output}
#define nonstop_mode 1 //{omits all stops}
#define scroll_mode 2 //{omits error stops}
#define error_stop_mode 3 //{stops at every opportunity to interact}
/* 71 */
#define spotless 0 //{|history| value when nothing has been amiss yet}
#define warning_issued 1 //{|history| value when |begin_diagnostic| has been called}
#define error_message_issued 2 //{|history| value when |error| has been called}
#define fatal_error_stop 3 //{|history| value when termination was premature}
/* 74 */
static inline void mf_help (unsigned int n, ...)
{
  int i;
  va_list help_arg;

  if (n > 6)
    n = 6;

  help_ptr = n;
  va_start(help_arg, n);

  for (i = n - 1; i > -1; --i)
    help_line[i] = va_arg(help_arg, char *);

  va_end(help_arg);
}
#define help0()     mf_help(0)
#define help1(...)  mf_help(1, __VA_ARGS__)
#define help2(...)  mf_help(2, __VA_ARGS__)
#define help3(...)  mf_help(3, __VA_ARGS__)
#define help4(...)  mf_help(4, __VA_ARGS__)
#define help5(...)  mf_help(5, __VA_ARGS__)
#define help6(...)  mf_help(6, __VA_ARGS__)
/* 95 */
#define el_gordo 017777777777 //{$2^{31}-1$, the largest value that \MF\ likes}
/* 96 */
#define half(a) (a)/2
/* 99 */
#define check_arith() \
  do { if (arith_error) clear_arith(); } while (0)
/* 101 */
#define quarter_unit 040000 //{$2^{14}$, represents 0.250000}
#define half_unit 0100000 //{$2^{15}$, represents 0.50000}
#define three_quarter_unit 0140000 //{$3\cdot2^{14}$, represents 0.75000}
#define unity 0200000 //{$2^{16}$, represents 1.00000}
#define two 0400000 //{$2^{17}$, represents 2.00000}
#define three 0600000 //{$2^{17}+2^{16}$, represents 3.00000}
/* 105 */
#define fraction_half 01000000000 //{$2^{27}$, represents 0.50000000}
#define fraction_one 02000000000 //{$2^{28}$, represents 1.00000000}
#define fraction_two 04000000000 //{$2^{29}$, represents 2.00000000}
#define fraction_three 06000000000 //{$3\cdot2^{28}$, represents 3.00000000}
#define fraction_four 010000000000 //{$2^{30}$, represents 4.00000000}
/* 106 */
#define forty_five_deg 0264000000 //{$45\cdot2^{20}$, represents $45^\circ$}
#define ninety_deg 0550000000 //{$90\cdot2^{20}$, represents $90^\circ$}
#define one_eighty_deg 01320000000 //{$180\cdot2^{20}$, represents $180^\circ$}
#define three_sixty_deg 02640000000 //{$360\cdot2^{20}$, represents $360^\circ$}
/* 139 */
#define negate_x 1
#define negate_y 2
#define switch_x_and_y 4
#define first_octant 1
#define second_octant (first_octant+switch_x_and_y)
#define third_octant (first_octant+switch_x_and_y+negate_x)
#define fourth_octant (first_octant+negate_x)
#define fifth_octant (first_octant+negate_x+negate_y)
#define sixth_octant (first_octant+switch_x_and_y+negate_x+negate_y)
#define seventh_octant (first_octant+switch_x_and_y+negate_y)
#define eighth_octant (first_octant+negate_y)
/* 161 */
#define link(a) mem[a].hh.rh //{the |link| field of a memory word}
#define info(a) mem[a].hh.lh //{the |info| field of a memory word}
/* 166 */
#define empty_flag max_halfword //{the |link| of an empty variable-size node}
#define is_empty(a) (link(a)==empty_flag) //{tests for empty node}
#define node_size info //{the size field in empty variable-size nodes}
#define llink(a) info(a+1) //{left link in doubly-linked list of empty nodes}
#define rlink(a) link(a+1) //{right link in doubly-linked list of empty nodes}
/* 175 */
#define null_coords mem_min //{specification for pen offsets of $(0,0)$}
#define null_pen (null_coords+3) //{we will define |coord_node_size=3|}
#define dep_head (null_pen+10) //{and |pen_node_size=10|}
#define zero_val (dep_head+2) //{two words for a permanently zero value}
#define temp_val (zero_val+2) //{two words for a temporary value node}
#define end_attr (temp_val) //{we use |end_attr+2| only}
#define inf_val (end_attr+2) //{and |inf_val+1| only}
#define bad_vardef (inf_val+2) //{two words for \&{vardef} error recovery}
#define lo_mem_stat_max (bad_vardef+1)  /*{largest statically
  allocated word in the variable-size |mem|}*/
#define sentinel mem_top //{end of sorted lists}
#define temp_head (mem_top-1) //{head of a temporary list of some kind}
#define hold_head (mem_top-2) //{head of a temporary list of another kind}
#define hi_mem_stat_min (mem_top-2) /*{smallest statically allocated word in
  the one-word |mem|}*/
/* 186 */
#define if_test 1 //{conditional text (\&{if})}
#define fi_or_else 2 //{delimiters for conditionals (\&{elseif}, \&{else}, \&{fi})}
#define input 3 //{input a source file (\&{input}, \&{endinput})}
#define iteration 4 //{iterate (\&{for}, \&{forsuffixes}, \&{forever}, \&{endfor})}
#define repeat_loop 5 //{special command substituted for \&{endfor}}
#define exit_test 6 //{premature exit from a loop (\&{exitif})}
#define relax 7 //{do nothing (\.{\char`\\})}
#define scan_tokens 8 //{put a string into the input buffer}
#define expand_after 9 //{look ahead one token}
#define defined_macro 10 //{a macro defined by the user}
#define min_command (defined_macro+1)
#define display_command 11 //{online graphic output (\&{display})}
#define save_command 12 //{save a list of tokens (\&{save})}
#define interim_command 13 //{save an internal quantity (\&{interim})}
#define let_command 14 //{redefine a symbolic token (\&{let})}
#define new_internal 15 //{define a new internal quantity (\&{newinternal})}
#define macro_def 16 //{define a macro (\&{def}, \&{vardef}, etc.)}
#define ship_out_command 17 //{output a character (\&{shipout})}
#define add_to_command 18 //{add to edges (\&{addto})}
#define cull_command 19 //{cull and normalize edges (\&{cull})}
#define tfm_command 20 //{command for font metric info (\&{ligtable}, etc.)}
#define protection_command 21 //{set protection flag (\&{outer}, \&{inner})}
#define show_command 22 //{diagnostic output (\&{show}, \&{showvariable}, etc.)}
#define mode_command 23 //{set interaction level (\&{batchmode}, etc.)}
#define random_seed 24 //{initialize random number generator (\&{randomseed})}
#define message_command 25 //{communicate to user (\&{message}, \&{errmessage})}
#define every_job_command 26 //{designate a starting token (\&{everyjob})}
#define delimiters 27 //{define a pair of delimiters (\&{delimiters})}
#define open_window 28 //{define a window on the screen (\&{openwindow})}
#define special_command 29 //{output special info (\&{special}, \&{numspecial})}
#define type_name 30 //{declare a type (\&{numeric}, \&{pair}, etc.)}
#define max_statement_command type_name
#define min_primary_command type_name
#define left_delimiter 31 //{the left delimiter of a matching pair}
#define begin_group 32 //{beginning of a group (\&{begingroup})}
#define nullary 33 //{an operator without arguments (e.g., \&{normaldeviate})}
#define unary 34 //{an operator with one argument (e.g., \&{sqrt})}
#define str_op 35 //{convert a suffix to a string (\&{str})}
#define cycle 36 //{close a cyclic path (\&{cycle})}
#define primary_binary 37 //{binary operation taking `\&{of}' (e.g., \&{point})}
#define capsule_token 38 //{a value that has been put into a token list}
#define string_token 39 //{a string constant (e.g., |"hello"|)}
#define internal_quantity 40 //{internal numeric parameter (e.g., \&{pausing})}
#define min_suffix_token internal_quantity
#define tag_token 41 //{a symbolic token without a primitive meaning}
#define numeric_token 42 //{a numeric constant (e.g., \.{3.14159})}
#define max_suffix_token numeric_token
#define plus_or_minus 43 //{either `\.+' or `\.-'}
#define max_primary_command plus_or_minus //{should also be |numeric_token+1|}
#define min_tertiary_command plus_or_minus
#define tertiary_secondary_macro 44 //{a macro defined by \&{secondarydef}}
#define tertiary_binary 45 //{an operator at the tertiary level (e.g., `\.{++}')}
#define max_tertiary_command tertiary_binary
#define left_brace 46 //{the operator `\.{\char`\{}'}
#define min_expression_command left_brace
#define path_join 47 //{the operator `\.{..}'}
#define ampersand 48 //{the operator `\.\&'}
#define expression_tertiary_macro 49 //{a macro defined by \&{tertiarydef}}
#define expression_binary 50 //{an operator at the expression level (e.g., `\.<')}
#define equals 51 //{the operator `\. '}
#define max_expression_command equals
#define and_command 52 //{the operator `\&{and}'}
#define min_secondary_command and_command
#define secondary_primary_macro 53 //{a macro defined by \&{primarydef}}
#define slash 54 //{the operator `\./'}
#define secondary_binary 55 //{an operator at the binary level (e.g., \&{shifted})}
#define max_secondary_command secondary_binary
#define param_type 56 //{type of parameter (\&{primary}, \&{expr}, \&{suffix}, etc.)}
#define controls 57 //{specify control points explicitly (\&{controls})}
#define tension 58 //{specify tension between knots (\&{tension})}
#define at_least 59 //{bounded tension value (\&{atleast})}
#define curl_command 60 //{specify curl at an end knot (\&{curl})}
#define macro_special 61 //{special macro operators (\&{quote}, \.{\#\AT!}, etc.)}
#define right_delimiter 62 //{the right delimiter of a matching pair}
#define left_bracket 63 //{the operator `\.['}
#define right_bracket 64 //{the operator `\.]'}
#define right_brace 65 //{the operator `\.{\char`\}}'}
#define with_option 66 //{option for filling (\&{withpen}, \&{withweight})}
#define cull_op 67 //{the operator `\&{keeping}' or `\&{dropping}'}
#define thing_to_add 68 //{variant of \&{addto} (\&{contour}, \&{doublepath}, \&{also})}
#define of_token 69 //{the operator `\&{of}'}
#define from_token 70 //{the operator `\&{from}'}
#define to_token 71 //{the operator `\&{to}'}
#define at_token 72 //{the operator `\&{at}'}
#define in_window 73 //{the operator `\&{inwindow}'}
#define step_token 74 //{the operator `\&{step}'}
#define until_token 75 //{the operator `\&{until}'}
#define lig_kern_token 76 //{the operators `\&{kern}' and `\.{ :}' and `\.{ :\char'174}', etc.}
#define assignment 77 //{the operator `\.{: }'}
#define skip_to 78 //{the operation `\&{skipto}'}
#define bchar_label 79 //{the operator `\.{\char'174\char'174:}'}
#define double_colon 80 //{the operator `\.{::}'}
#define colon 81 //{the operator `\.:'}
#define comma 82 //{the operator `\.,', must be |colon+1|}
#define end_of_statement  (cur_cmd>comma)
#define semicolon 83 //{the operator `\.;', must be |comma+1|}
#define end_group 84 //{end a group (\&{endgroup}), must be |semicolon+1|}
#define stop 85 //{end a job (\&{end}, \&{dump}), must be |end_group+1|}
#define max_command_code stop
#define outer_tag (max_command_code+1) //{protection code added to command code}
/* 187 */
#define undefined 0 //{no type has been declared}
#define unknown_tag 1 //{this constant is added to certain type codes below}
#define vacuous 1 //{no expression was present}
#define boolean_type 2 //{\&{boolean} with a known value}
#define unknown_boolean (boolean_type+unknown_tag)
#define string_type 4 //{\&{string} with a known value}
#define unknown_string (string_type+unknown_tag)
#define pen_type 6 //{\&{pen} with a known value}
#define unknown_pen (pen_type+unknown_tag)
#define future_pen 8 //{subexpression that will become a \&{pen} at a higher level}
#define path_type 9 //{\&{path} with a known value}
#define unknown_path (path_type+unknown_tag)
#define picture_type 11 //{\&{picture} with a known value}
#define unknown_picture (picture_type+unknown_tag)
#define transform_type 13 //{\&{transform} variable or capsule}
#define pair_type 14 //{\&{pair} variable or capsule}
#define numeric_type 15 //{variable that has been declared \&{numeric} but not used}
#define known 16 //{\&{numeric} with a known value}
#define dependent 17 //{a linear combination with |fraction| coefficients}
#define proto_dependent 18 //{a linear combination with |scaled| coefficients}
#define independent 19 //{\&{numeric} with unknown value}
#define token_list 20 //{variable name or suffix argument or text argument}
#define structured 21 //{variable with subscripts and attributes}
#define unsuffixed_macro 22 //{variable defined with \&{vardef} but no \.{\AT!\#}}
#define suffixed_macro 23 //{variable defined with \&{vardef} and \.{\AT!\#}}
/* 188 */
#define root 0 //{|name_type| at the top level of a variable}
#define saved_root 1 //{same, when the variable has been saved}
#define structured_root 2 //{|name_type| where a |structured| branch occurs}
#define subscr 3 //{|name_type| in a subscript node}
#define attr 4 //{|name_type| in an attribute node}
#define x_part_sector 5 //{|name_type| in the \&{xpart} of a node}
#define y_part_sector 6 //{|name_type| in the \&{ypart} of a node}
#define xx_part_sector 7 //{|name_type| in the \&{xxpart} of a node}
#define xy_part_sector 8 //{|name_type| in the \&{xypart} of a node}
#define yx_part_sector 9 //{|name_type| in the \&{yxpart} of a node}
#define yy_part_sector 10 //{|name_type| in the \&{yypart} of a node}
#define capsule 11 //{|name_type| in stashed-away subexpressions}
#define token 12 //{|name_type| in a numeric token or string token}
/* 189 */
#define true_code 30 //{operation code for \.{true}}
#define false_code 31 //{operation code for \.{false}}
#define null_picture_code 32 //{operation code for \.{nullpicture}}
#define null_pen_code 33 //{operation code for \.{nullpen}}
#define job_name_op 34 //{operation code for \.{jobname}}
#define read_string_op 35 //{operation code for \.{readstring}}
#define pen_circle 36 //{operation code for \.{pencircle}}
#define normal_deviate 37 //{operation code for \.{normaldeviate}}
#define odd_op 38 //{operation code for \.{odd}}
#define known_op 39 //{operation code for \.{known}}
#define unknown_op 40 //{operation code for \.{unknown}}
#define not_op 41 //{operation code for \.{not}}
#define decimal 42 //{operation code for \.{decimal}}
#define reverse 43 //{operation code for \.{reverse}}
#define make_path_op 44 //{operation code for \.{makepath}}
#define make_pen_op 45 //{operation code for \.{makepen}}
#define total_weight_op 46 //{operation code for \.{totalweight}}
#define oct_op 47 //{operation code for \.{oct}}
#define hex_op 48 //{operation code for \.{hex}}
#define ASCII_op 49 //{operation code for \.{ASCII}}
#define char_op 50 //{operation code for \.{char}}
#define length_op 51 //{operation code for \.{length}}
#define turning_op 52 //{operation code for \.{turningnumber}}
#define x_part 53 //{operation code for \.{xpart}}
#define y_part 54 //{operation code for \.{ypart}}
#define xx_part 55 //{operation code for \.{xxpart}}
#define xy_part 56 //{operation code for \.{xypart}}
#define yx_part 57 //{operation code for \.{yxpart}}
#define yy_part 58 //{operation code for \.{yypart}}
#define sqrt_op 59 //{operation code for \.{sqrt}}
#define m_exp_op 60 //{operation code for \.{mexp}}
#define m_log_op 61 //{operation code for \.{mlog}}
#define sin_d_op 62 //{operation code for \.{sind}}
#define cos_d_op 63 //{operation code for \.{cosd}}
#define floor_op 64 //{operation code for \.{floor}}
#define uniform_deviate 65 //{operation code for \.{uniformdeviate}}
#define char_exists_op 66 //{operation code for \.{charexists}}
#define angle_op 67 //{operation code for \.{angle}}
#define cycle_op 68 //{operation code for \.{cycle}}
#define plus 69 //{operation code for \.+}
#define minus 70 //{operation code for \.-}
#define times 71 //{operation code for \.*}
#define over 72 //{operation code for \./}
#define pythag_add 73 //{operation code for \.{++}}
#define pythag_sub 74 //{operation code for \.{+-+}}
#define or_op 75 //{operation code for \.{or}}
#define and_op 76 //{operation code for \.{and}}
#define less_than 77 //{operation code for \.<}
#define less_or_equal 78 //{operation code for \.{< }}
#define greater_than 79 //{operation code for \.>}
#define greater_or_equal 80 //{operation code for \.{> }}
#define equal_to 81 //{operation code for \. }
#define unequal_to 82 //{operation code for \.{<>}}
#define concatenate 83 //{operation code for \.\&}
#define rotated_by 84 //{operation code for \.{rotated}}
#define slanted_by 85 //{operation code for \.{slanted}}
#define scaled_by 86 //{operation code for \.{scaled}}
#define shifted_by 87 //{operation code for \.{shifted}}
#define transformed_by 88 //{operation code for \.{transformed}}
#define x_scaled 89 //{operation code for \.{xscaled}}
#define y_scaled 90 //{operation code for \.{yscaled}}
#define z_scaled 91 //{operation code for \.{zscaled}}
#define intersect 92 //{operation code for \.{intersectiontimes}}
#define double_dot 93 //{operation code for improper \.{..}}
#define substring_of 94 //{operation code for \.{substring}}
#define min_of substring_of
#define subpath_of 95 //{operation code for \.{subpath}}
#define direction_time_of 96 //{operation code for \.{directiontime}}
#define point_of 97 //{operation code for \.{point}}
#define precontrol_of 98 //{operation code for \.{precontrol}}
#define postcontrol_of 99 //{operation code for \.{postcontrol}}
#define pen_offset_of 100 //{operation code for \.{penoffset}}
/* 190 */
#define tracing_titles 1 //{show titles online when they appear}
#define tracing_equations 2 //{show each variable when it becomes known}
#define tracing_capsules 3 //{show capsules too}
#define tracing_choices 4 //{show the control points chosen for paths}
#define tracing_specs 5 //{show subdivision of paths into octants before digitizing}
#define tracing_pens 6 //{show details of pens that are made}
#define tracing_commands 7 //{show commands and operations before they are performed}
#define tracing_restores 8 //{show when a variable or internal is restored}
#define tracing_macros 9 //{show macros before they are expanded}
#define tracing_edges 10 //{show digitized edges as they are computed}
#define tracing_output 11 //{show digitized edges as they are output}
#define tracing_stats 12 //{show memory usage at end of job}
#define tracing_online 13 //{show long diagnostics on terminal and in the log file}
#define year 14 //{the current year (e.g., 1984)}
#define month 15 //{the current month (e.g., 3 $\equiv$ March)}
#define day 16 //{the current day of the month}
#define time 17 //{the number of minutes past midnight when this job started}
#define char_code 18 //{the number of the next character to be output}
#define char_ext 19 //{the extension code of the next character to be output}
#define char_wd 20 //{the width of the next character to be output}
#define char_ht 21 //{the height of the next character to be output}
#define char_dp 22 //{the depth of the next character to be output}
#define char_ic 23 //{the italic correction of the next character to be output}
#define char_dx 24 //{the device's $x$ movement for the next character, in pixels}
#define char_dy 25 //{the device's $y$ movement for the next character, in pixels}
#define design_size 26 //{the unit of measure used for |char_wd..char_ic|, in points}
#define hppp 27 //{the number of horizontal pixels per point}
#define vppp 28 //{the number of vertical pixels per point}
#define x_offset 29 //{horizontal displacement of shipped-out characters}
#define y_offset 30 //{vertical displacement of shipped-out characters}
#define pausing 31 //{positive to display lines on the terminal before they are read}
#define showstopping 32 //{positive to stop after each \&{show} command}
#define fontmaking 33 //{positive if font metric output is to be produced}
#define proofing 34 //{positive for proof mode, negative to suppress output}
#define smoothing 35 //{positive if moves are to be ``smoothed''}
#define autorounding 36 //{controls path modification to ``good'' points}
#define granularity 37 //{autorounding uses this pixel size}
#define fillin 38 //{extra darkness of diagonal lines}
#define turning_check 39 //{controls reorientation of clockwise paths}
#define warning_check 40 //{controls error message when variable value is large}
#define boundary_char 41 //{the right boundary character for ligatures}
#define max_given_internal 41
/* 198 */
#define digit_class 0 //{the class number of \.{0123456789}}
#define period_class 1 //{the class number of `\..'}
#define space_class 2 //{the class number of spaces and nonstandard characters}
#define percent_class 3 //{the class number of `\.\%'}
#define string_class 4 //{the class number of `\."'}
#define right_paren_class 8 //{the class number of `\.)'}
#define isolated_classes  5,6,7,8 //{characters that make length-one tokens only}
#define letter_class 9 //{letters and the underline character}
#define left_bracket_class 17 //{`\.['}
#define right_bracket_class 18 //{`\.]'}
#define invalid_class 20 //{bad character in the input}
#define max_class 20 //{the largest class number}
/* 200 */
#define next(a) hash[a].lh //{link for coalesced lists}
#define text(a) hash[a].rh //{string number for symbolic token name}
#define eq_type(a) eqtb[a].lh //{the current ``meaning'' of a symbolic token}
#define equiv(a) eqtb[a].rh //{parametric part of a token's meaning}
#define hash_base=257 //{hashing actually starts here}
#define hash_is_full (hash_used==hash_base) //{are all positions occupied?}
/* 201 */
#define hash_top (hash_base+hash_size) //{the first location of the frozen area}
#define frozen_inaccessible hash_top //{|hash| location to protect the frozen area}
#define frozen_repeat_loop (hash_top+1) //{|hash| location of a loop-repeat token}
#define frozen_right_delimiter (hash_top+2) //{|hash| location of a permanent `\.)'}
#define frozen_left_bracket (hash_top+3) //{|hash| location of a permanent `\.['}
#define frozen_slash (hash_top+4) //{|hash| location of a permanent `\./'}
#define frozen_colon (hash_top+5) //{|hash| location of a permanent `\.:'}
#define frozen_semicolon (hash_top+6) //{|hash| location of a permanent `\.;'}
#define frozen_end_for (hash_top+7) //{|hash| location of a permanent \&{endfor}}
#define frozen_end_def (hash_top+8) //{|hash| location of a permanent \&{enddef}}
#define frozen_fi (hash_top+9) //{|hash| location of a permanent \&{fi}}
#define frozen_end_group (hash_top+10)
//  {|hash| location of a permanent `\.{endgroup}'}
#define frozen_bad_vardef (hash_top+11) //{|hash| location of `\.{a bad variable}'}
#define frozen_undefined (hash_top+12) //{|hash| location that never gets defined}
#define hash_end (hash_top+12) //{the actual size of the |hash| and |eqtb| arrays}
/* 214 */
#define type(a) mem[a].hh.b0 //{identifies what kind of value this is}
#define name_type(a) mem[a].hh.b1 //{a clue to the name of this value}
#define token_node_size 2 //{the number of words in a large token node}
#define value_loc(a) (a+1) //{the word that contains the |value| field}
#define value(a) mem[value_loc(a)].cint //{the value stored in a large token node}
#define expr_base (hash_end+1) //{code for the zeroth \&{expr} parameter}
#define suffix_base (expr_base+param_size) //{code for the zeroth \&{suffix} parameter}
#define text_base (suffix_base+param_size) //{code for the zeroth \&{text} parameter}
/* 226 */
#define ref_count info //{reference count preceding a macro definition or pen header}
#define add_mac_ref(a) incr(ref_count(a)) //{make a new reference to a macro list}
#define general_macro 0 //{preface to a macro defined with a parameter list}
#define primary_macro 1 //{preface to a macro with a \&{primary} parameter}
#define secondary_macro 2 //{preface to a macro with a \&{secondary} parameter}
#define tertiary_macro 3 //{preface to a macro with a \&{tertiary} parameter}
#define expr_macro 4 //{preface to a macro with an undelimited \&{expr} parameter}
#define of_macro 5 /*{preface to a macro with
  undelimited `\&{expr} |x| \&{of}~|y|' parameters}*/
#define suffix_macro 6 //{preface to a macro with an undelimited \&{suffix} parameter}
#define text_macro 7 //{preface to a macro with an undelimited \&{text} parameter}
/* 228 */
#define subscr_head_loc(a) (a+1) //{where |value|, |subscr_head|, and |attr_head| are}
#define attr_head(a) info(subscr_head_loc(a)) //{pointer to attribute info}
#define subscr_head(a) link(subscr_head_loc(a)) //{pointer to subscript info}
#define value_node_size 2 //{the number of words in a value node}
/* 229 */
#define attr_loc_loc(a) (a+2) //{where the |attr_loc| and |parent| fields are}
#define attr_loc(a) info(attr_loc_loc(a)) //{hash address of this attribute}
#define parent(a) link(attr_loc_loc(a)) //{pointer to |structured| variable}
#define subscript_loc(a) a+2 //{where the |subscript| field lives}
#define subscript(a) mem[subscript_loc(a)].sc //{subscript of this variable}
#define attr_node_size 3 //{the number of words in an attribute node}
#define subscr_node_size 3 //{the number of words in a subscript node}
#define collective_subscript 0 //{code for the attribute `\.{[]}'}
/* 230 */
#define x_part_loc(a) a //{where the \&{xpart} is found in a pair or transform node}
#define y_part_loc(a) (a+2) //{where the \&{ypart} is found in a pair or transform node}
#define xx_part_loc(a) (a+4) //{where the \&{xxpart} is found in a transform node}
#define xy_part_loc(a) (a+6) //{where the \&{xypart} is found in a transform node}
#define yx_part_loc(a) (a+8) //{where the \&{yxpart} is found in a transform node}
#define yy_part_loc(a) (a+10) //{where the \&{yypart} is found in a transform node}
#define pair_node_size 4 //{the number of words in a pair node}
#define transform_node_size 12 //{the number of words in a transform node}
/* 255 */
#define left_type(a) mem[a].hh.b0 //{characterizes the path entering this knot}
#define right_type(a) mem[a].hh.b1 //{characterizes the path leaving this knot}
#define endpoint 0 //{|left_type| at path beginning and |right_type| at path end}
#define x_coord(a) mem[a+1].sc //{the |x| coordinate of this knot}
#define y_coord(a) mem[a+2].sc //{the |y| coordinate of this knot}
#define left_x(a) mem[a+3].sc //{the |x| coordinate of previous control point}
#define left_y(a) mem[a+4].sc //{the |y| coordinate of previous control point}
#define right_x(a) mem[a+5].sc //{the |x| coordinate of next control point}
#define right_y(a) mem[a+6].sc //{the |y| coordinate of next control point}
#define knot_node_size 7 //{number of words in a knot node}
/* 256 */
#define left_curl left_x //{curl information when entering this knot}
#define left_given left_x //{given direction when entering this knot}
#define left_tension left_y //{tension information when entering this knot}
#define right_curl right_x //{curl information when leaving this knot}
#define right_given right_x //{given direction when leaving this knot}
#define right_tension right_y //{tension information when leaving this knot}
#define explicit 1 //{|left_type| or |right_type| when control points are known}
#define given 2 //{|left_type| or |right_type| when a direction is given}
#define curl 3 //{|left_type| or |right_type| when a curl is desired}
#define open 4 //{|left_type| or |right_type| when \MF\ should choose the direction}
/* 309 */
#define stack_x1 bisect_stack[bisect_ptr] //{stacked value of $X_1$}
#define stack_x2 bisect_stack[bisect_ptr+1] //{stacked value of $X_2$}
#define stack_x3 bisect_stack[bisect_ptr+2] //{stacked value of $X_3$}
#define stack_r bisect_stack[bisect_ptr+3] //{stacked value of $R$}
#define stack_m bisect_stack[bisect_ptr+4] //{stacked value of $m$}
#define stack_y1 bisect_stack[bisect_ptr+5] //{stacked value of $Y_1$}
#define stack_y2 bisect_stack[bisect_ptr+6] //{stacked value of $Y_2$}
#define stack_y3 bisect_stack[bisect_ptr+7] //{stacked value of $Y_3$}
#define stack_s bisect_stack[bisect_ptr+8] //{stacked value of $S$}
#define stack_n bisect_stack[bisect_ptr+9] //{stacked value of $n$}
#define stack_l bisect_stack[bisect_ptr+10] //{stacked value of $l$}
#define move_increment 11 //{number of items pushed by |make_moves|}
/* 324 */
#define zero_w 4
#define _void (null+1)
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
#define empty_edges(a) link(a)==a
/* 553 */
#define stack_1(a) bisect_stack[a] //{$U_1$, $V_1$, $X_1$, or $Y_1$}
#define stack_2(a) bisect_stack[a+1] //{$U_2$, $V_2$, $X_2$, or $Y_2$}
#define stack_3(a) bisect_stack[a+2] //{$U_3$, $V_3$, $X_3$, or $Y_3$}
#define stack_min(a) bisect_stack[a+3]
//  {$U\submin$, $V\submin$, $X\submin$, or $Y\submin$}
#define stack_max(a) bisect_stack[a+4]
//  {$U\submax$, $V\submax$, $X\submax$, or $Y\submax$}
#define int_packets 20 //{number of words to represent $U_k$, $V_k$, $X_k$, and $Y_k$}
#define u_packet(a) (a-5)
#define v_packet(a) (a-10)
#define x_packet(a) (a-15)
#define y_packet(a) (a-20)
#define l_packets (bisect_ptr-int_packets)
#define r_packets bisect_ptr
#define ul_packet u_packet(l_packets) //{base of $U'_k$ variables}
#define vl_packet v_packet(l_packets) //{base of $V'_k$ variables}
#define xl_packet x_packet(l_packets) //{base of $X'_k$ variables}
#define yl_packet y_packet(l_packets) //{base of $Y'_k$ variables}
#define ur_packet u_packet(r_packets) //{base of $U''_k$ variables}
#define vr_packet v_packet(r_packets) //{base of $V''_k$ variables}
#define xr_packet x_packet(r_packets) //{base of $X''_k$ variables}
#define yr_packet y_packet(r_packets) //{base of $Y''_k$ variables}
#define u1l stack_1(ul_packet) //{$U'_1$}
#define u2l stack_2(ul_packet) //{$U'_2$}
#define u3l stack_3(ul_packet) //{$U'_3$}
#define v1l stack_1(vl_packet) //{$V'_1$}
#define v2l stack_2(vl_packet) //{$V'_2$}
#define v3l stack_3(vl_packet) //{$V'_3$}
#define x1l stack_1(xl_packet) //{$X'_1$}
#define x2l stack_2(xl_packet) //{$X'_2$}
#define x3l stack_3(xl_packet) //{$X'_3$}
#define y1l stack_1(yl_packet) //{$Y'_1$}
#define y2l stack_2(yl_packet) //{$Y'_2$}
#define y3l stack_3(yl_packet) //{$Y'_3$}
#define u1r stack_1(ur_packet) //{$U''_1$}
#define u2r stack_2(ur_packet) //{$U''_2$}
#define u3r stack_3(ur_packet) //{$U''_3$}
#define v1r stack_1(vr_packet) //{$V''_1$}
#define v2r stack_2(vr_packet) //{$V''_2$}
#define v3r stack_3(vr_packet) //{$V''_3$}
#define x1r stack_1(xr_packet) //{$X''_1$}
#define x2r stack_2(xr_packet) //{$X''_2$}
#define x3r stack_3(xr_packet) //{$X''_3$}
#define y1r stack_1(yr_packet) //{$Y''_1$}
#define y2r stack_2(yr_packet) //{$Y''_2$}
#define y3r stack_3(yr_packet) //{$Y''_3$}
#define stack_dx bisect_stack[bisect_ptr] //{stacked value of |delx|}
#define stack_dy bisect_stack[bisect_ptr+1] //{stacked value of |dely|}
#define stack_tol bisect_stack[bisect_ptr+2] //{stacked value of |tol|}
#define stack_uv bisect_stack[bisect_ptr+3] //{stacked value of |uv|}
#define stack_xy bisect_stack[bisect_ptr+4] //{stacked value of |xy|}
#define int_increment (int_packets+int_packets+5) //{number of stack words per level}
/* 592 */
#define coef_bound 04525252525 //{|fraction| approximation to 7/3}
#define independent_needing_fix 0
/* 594 */
#define fraction_threshold 2685 //{a |fraction| coefficient less than this is zeroed}
#define half_fraction_threshold 1342 //{half of |fraction_threshold|}
#define scaled_threshold 8 //{a |scaled| coefficient less than this is zeroed}
#define half_scaled_threshold 4 //{half of |scaled_threshold|}
/* 632 */
#define token_type index //{type of current token list}
#define token_state (index>max_in_open) //{are we scanning a token list?}
#define file_state (index<=max_in_open) //{are we scanning a file line?}
#define param_start limit //{base of macro parameters in |param_stack|}
#define forever_text (max_in_open+1) //{|token_type| code for loop texts}
#define loop_text (max_in_open+2) //{|token_type| code for loop texts}
#define parameter (max_in_open+3) //{|token_type| code for parameter texts}
#define backed_up (max_in_open+4) //{|token_type| code for texts to be reread}
#define inserted (max_in_open+5) //{|token_type| code for inserted texts}
#define macro (max_in_open+6) //{|token_type| code for macro replacement texts}
/* 659 */
#define normal 0 //{|scanner_status| at ``quiet times''}
#define skipping 1 //{|scanner_status| when false conditional text is being skipped}
#define flushing 2 //{|scanner_status| when junk after a statement is being ignored}
#define absorbing 3 //{|scanner_status| when a \&{text} parameter is being scanned}
#define var_defining 4 //{|scanner_status| when a \&{vardef} is being scanned}
#define op_defining 5 //{|scanner_status| when a macro \&{def} is being scanned}
#define loop_defining 6 //{|scanner_status| when a \&{for} loop is being scanned}
/* 667 */
#define _switch 25 //{a label in |get_next|}
#define start_numeric_token 85 //{another}
#define start_decimal_token 86 //{and another}
#define fin_numeric_token 87
//  {and still another, although |goto| is considered harmful}
/* 683 */
#define start_def 1 //{command modifier for \&{def}}
#define var_def 2 //{command modifier for \&{vardef}}
#define end_def 0 //{command modifier for \&{enddef}}
#define start_forever 1 //{command modifier for \&{forever}}
#define end_for 0 //{command modifier for \&{endfor}}
/* 688 */
#define quote 0 //{|macro_special| modifier for \&{quote}}
#define macro_prefix 1 //{|macro_special| modifier for \.{\#\AT!}}
#define macro_at 2 //{|macro_special| modifier for \.{\AT!}}
#define macro_suffix 3 //{|macro_special| modifier for \.{\AT!\#}}
/* 738 */
#define if_node_size 2 //{number of words in stack entry for conditionals}
#define if_line_field(a) mem[a+1].cint
#define if_code 1 //{code for \&{if} being evaluated}
#define fi_code 2 //{code for \&{fi}}
#define else_code 3 //{code for \&{else}}
#define else_if_code 4 //{code for \&{elseif}}
/* 752 */
#define loop_list_loc(a) a+1 //{where the |loop_list| field resides}
#define loop_type(a) info(loop_list_loc(a)) //{the type of \&{for} loop}
#define loop_list(a) link(loop_list_loc(a)) //{the remaining list elements}
#define loop_node_size 2 //{the number of words in a loop control node}
#define progression_node_size 4 //{the number of words in a progression node}
#define step_size(a) mem[a+2].sc //{the step size in an arithmetic progression}
#define final_value(a) mem[a+3].sc //{the final value in an arithmetic progression}
/* 1037 */
#define show_token_code 0 //{show the meaning of a single token}
#define show_stats_code 1 //{show current memory and string usage}
#define show_code 2 //{show a list of expressions}
#define show_var_code 3 //{show a variable and its descendents}
#define show_dependencies_code 4 //{show dependent variables in terms of independents}
/* 1091 */
#define no_tag 0 //{vanilla character}
#define lig_tag 1 //{character has a ligature/kerning program}
#define list_tag 2 //{character has a successor in a charlist}
#define ext_tag 3 //{character is extensible}
/* 1093 */
#define stop_flag (128+min_quarterword)
//  {value indicating `\.{STOP}' in a lig/kern program}
#define kern_flag (128+min_quarterword) //{op code for a kern step}
#define skip_byte(a) lig_kern[a].b0
#define next_char(a) lig_kern[a].b1
#define op_byte(a) lig_kern[a].b2
#define rem_byte(a) lig_kern[a].b3
/* 1094 */
#define ext_top(a) exten[a].b0 //{|top| piece in a recipe}
#define ext_mid(a) exten[a].b1 //{|mid| piece in a recipe}
#define ext_bot(a) exten[a].b2 //{|bot| piece in a recipe}
#define ext_rep(a) exten[a].b3 //{|rep| piece in a recipe}
/* 1095 */
#define slant_code 1
#define space_code 2
#define space_stretch_code 3
#define space_shrink_code 4
#define x_height_code 5
#define quad_code 6
#define extra_space_code 7
/* 1101 */
#define char_list_code 0
#define lig_table_code 1
#define extensible_code 2
#define header_byte_code 3
#define font_dimen_code 4
/* 1145 */
#define paint_0 0 //{beginning of the \\{paint} commands}
#define paint1 64 /*{move right a given number of columns, then
  black${}\swap{}$white}*/
#define boc 67 //{beginning of a character}
#define boc1 68 //{short form of |boc|}
#define eoc 69 //{end of a character}
#define skip0 70 //{skip no blank rows}
#define skip1 71 //{skip over blank rows}
#define new_row_0 74 //{move down one row and then right}
#define max_new_row 164 //{the largest \\{new\_row} command is |new_row_164|}
#define xxx1 239 //{for \&{special} strings}
#define xxx3 241 //{for long \&{special} strings}
#define yyy 243 //{for \&{numspecial} numbers}
#define char_loc 245 //{character locators in the postamble}
#define pre 247 //{preamble}
#define post 248 //{postamble beginning}
#define post_post 249 //{postamble ending}

/* F U N C T I O N S */
void initialize(void);
void print_ln(void);
void print_char(ASCII_code s);
void print(integer s);
void slow_print(integer s);
void print_nl(str_number s);
void print_the_digs(eight_bits k);
void print_int(integer n);
void print_scaled(scaled s);
void print_two(scaled x, scaled y);
void print_type(small_number t);
void begin_diagnostic(void);
void end_diagnostic(boolean blank_line);
void print_diagnostic(str_number s, str_number t, boolean nuline);
void print_file_name(integer n, integer a, integer e);
void flush_string(str_number s);
void jump_out(void);
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
void check_mem(boolean print_locs);
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
halfword p_over_v(halfword p, scaled v, small_number t0, small_number t1);
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
void quadrant_subdivide(void);
void octant_subdivide(void);
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
void open_a_window(window_number k, scaled r0, scaled c0, scaled r1, scaled c1, scaled x, scaled y);
void disp_edges(window_number k);
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
void clear_for_error_prompt(void);
boolean check_outer_validity(void);
void get_next(void);
void firm_up_the_line(void);
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
boolean more_name(ASCII_code c);
void end_name(void);
void pack_file_name(str_number n, str_number a, str_number e);
void pack_buffered_name(small_number n, integer a, integer b);
str_number make_name_string(void);
str_number a_make_name_string(alpha_file f);
str_number b_make_name_string(byte_file f);
str_number w_make_name_string(word_file f);
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
void set_up_trans(quarterword c);
void set_up_known_trans(quarterword c);
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
void set_up_offset(halfword p);
void set_up_direction_time(halfword p);
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
void ship_out(eight_bits c);
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
void do_ship_out(void);
void do_display(void);
boolean get_pair(command_code c);
void do_open_window(void);
void do_cull(void);
void do_message(void);
eight_bits get_code(void);
void set_tag(halfword c, small_number t, halfword r);
void do_tfm_command(void);
void do_special(void);
void store_base_file(void);
void do_statement(void);
void main_control(void);
halfword sort_in(scaled v);
integer min_cover(scaled d);
scaled threshold(integer m);
integer skimp(integer m);
void tfm_warning(small_number m);
void fix_design_size(void);
integer dimen_out(scaled x);
void fix_check_sum(void);
void tfm_qqqq(four_quarters x);
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
void blankrectangle(screencol, screencol, screenrow, screenrow);
void paintrow(screenrow, pixelcolor, transspec, screencol);
