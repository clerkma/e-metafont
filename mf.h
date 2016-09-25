#define EXTERN
#define STAT
#define INI
#define INIMF

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
EXTERN alpha_file poolfile;
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

EXTERN memoryword * mem;
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

EXTERN twohalves hash[9770];
EXTERN twohalves eqtb[9770];

EXTERN halfword g_pointer;

EXTERN small_number 
#define big_node_size (zzzaa -13)
  zzzaa[2];

EXTERN halfword save_ptr;

EXTERN halfword path_tail;

EXTERN scaled delta_x[pathsize + 1], delta_y[pathsize + 1], delta[pathsize + 1];
EXTERN angle psi[pathsize + 1];

EXTERN angle theta[pathsize + 1];
EXTERN fraction uu[pathsize + 1];
EXTERN angle vv[pathsize + 1];
EXTERN fraction ww[pathsize + 1];

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

void deletemacref(halfword p);
void printcmdmod(integer c, integer m);
void showmacro(halfword p, integer q, integer l);
void initbignode(halfword p);
halfword idtransform(void);
void newroot(halfword x);
void printvariablename(halfword p);
boolean interesting(halfword p);
halfword newstructure(halfword p);
halfword findvariable(halfword t);
void printpath(halfword h, str_number s, boolean nuline);
void printweight(halfword q, integer xoff);
void printedges(str_number s, boolean nuline, integer xoff, integer yoff);
void unskew(scaled x, scaled y, small_number octant);
void printpen(halfword p, str_number s, boolean nuline);
void printdependency(halfword p, small_number t);
void printdp(small_number t, halfword p, small_number verbosity);
halfword stashcurexp(void);
void unstashcurexp(halfword p);
void printexp(halfword p, small_number verbosity);
void disperr(halfword p, str_number s);
halfword pplusfq(halfword p, integer f, halfword q, small_number t, small_number tt);
halfword poverv(halfword p, scaled v, small_number t0, small_number t1);
void valtoobig(scaled x);
void makeknown(halfword p, halfword q);
void fixdependencies(void);
void tossknotlist(halfword p);
void tossedges(halfword h);
void tosspen(halfword p);
void ringdelete(halfword p);
void recyclevalue(halfword p);
void flushcurexp(scaled v);
void flusherror(scaled v);
void putgeterror(void);
void putgetflusherror(scaled v);
void flushbelowvariable(halfword p);
void flushvariable(halfword p, halfword t, boolean discardsuffixes);
small_number undtype(halfword p);
void clearsymbol(halfword p, boolean saving);
void savevariable(halfword q);
void saveinternal(halfword q);
void unsave(void);
halfword copyknot(halfword p);
halfword copypath(halfword p);
halfword htapypoc(halfword p);
fraction curlratio(scaled gamma, scaled atension, scaled btension);
void setcontrols(halfword p, halfword q, integer k);
void solvechoices(halfword p, halfword q, halfword n);
void makechoices(halfword knots);
void makemoves(scaled xx0, scaled xx1, scaled xx2, scaled xx3, scaled yy0, scaled yy1, scaled yy2, scaled yy3, small_number xicorr, small_number etacorr);
void smoothmoves(integer b, integer t);
void initedges(halfword h);
void fixoffset(void);
void edgeprep(integer ml, integer mr, integer nl, integer nr);
halfword copyedges(halfword h);
void yreflectedges(void);
void xreflectedges(void);
void yscaleedges(integer s);
void xscaleedges(integer s);
void negateedges(halfword h);
void sortedges(halfword h);
void culledges(integer wlo, integer whi, integer wout, integer win);
void xyswapedges(void);
void mergeedges(halfword h);
integer totalweight(halfword h);
void beginedgetracing(void);
void traceacorner(void);
void endedgetracing(void);
void tracenewedge(halfword r, integer n);
void lineedges(scaled x0, scaled y0, scaled x1, scaled y1);
void movetoedges(integer m0, integer n0, integer m1, integer n1);
void skew(scaled x, scaled y, small_number octant);
void abnegate(scaled x, scaled y, small_number octantbefore, small_number octantafter);
fraction crossingpoint(integer a, integer b, integer c);
void printspec(str_number s);
void printstrange(str_number s);
void removecubic(halfword p);
void splitcubic(halfword p, fraction t, scaled xq, scaled yq);
void quadrantsubdivide(void);
void octantsubdivide(void);
void makesafe(void);
void beforeandafter(scaled b, scaled a, halfword p);
scaled goodval(scaled b, scaled o);
scaled compromise(scaled u, scaled v);
void xyround(void);
void diaground(void);
void newboundary(halfword p, small_number octant);
halfword makespec(halfword h, scaled safetymargin, integer tracing);
void endround(scaled x, scaled y);
void fillspec(halfword h);
void dupoffset(halfword w);
halfword makepen(halfword h);
halfword trivialknot(scaled x, scaled y);
halfword makepath(halfword penhead);
void findoffset(scaled x, scaled y, halfword p);
void splitforoffset(halfword p, fraction t);
void finoffsetprep(halfword p, halfword k, halfword w, integer x0, integer x1, integer x2, integer y0, integer y1, integer y2, boolean rising, integer n);
void offsetprep(halfword c, halfword h);
void skewlineedges(halfword p, halfword w, halfword ww);
void dualmoves(halfword h, halfword p, halfword q);
void fillenvelope(halfword spechead);
halfword makeellipse(scaled majoraxis, scaled minoraxis, angle theta);
scaled finddirectiontime(scaled x, scaled y, halfword h);
void cubicintersection(halfword p, halfword pp);
void pathintersection(halfword h, halfword hh);
void openawindow(windownumber k, scaled r0, scaled c0, scaled r1, scaled c1, scaled x, scaled y);
void dispedges(windownumber k);
fraction maxcoef(halfword p);
halfword pplusq(halfword p, halfword q, small_number t);
halfword ptimesv(halfword p, integer v, small_number t0, small_number t1, boolean visscaled);
halfword pwithxbecomingq(halfword p, halfword x, halfword q, small_number t);
void newdep(halfword q, halfword p);
halfword constdependency(scaled v);
halfword singledependency(halfword p);
halfword copydeplist(halfword p);
void lineareq(halfword p, small_number t);
halfword newringentry(halfword p);
void nonlineareq(integer v, halfword p, boolean flushp);
void ringmerge(halfword p, halfword q);
void showcmdmod(integer c, integer m);
void showcontext(void);
void begintokenlist(halfword p, quarterword t);
void endtokenlist(void);
void encapsulate(halfword p);
void install(halfword r, halfword q);
void makeexpcopy(halfword p);
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
halfword scantoks(commandcode terminator, halfword substlist, halfword tailend, small_number suffixcount);
void getsymbol(void);
void getclearsymbol(void);
void checkequals(void);
void makeopdef(void);
void checkdelimiter(halfword ldelim, halfword rdelim);
halfword scandeclaredvariable(void);
void scandef(void);
void printmacroname(halfword a, halfword n);
void printarg(halfword q, integer n, halfword b);
void scantextarg(halfword ldelim, halfword rdelim);
void macrocall(halfword defref, halfword arglist, halfword macroname);
void expand(void);
void getxnext(void);
void stackargument(halfword p);
void passtext(void);
void changeiflimit(small_number l, halfword p);
void checkcolon(void);
void conditional(void);
void badfor(str_number s);
void beginiteration(void);
void resumeiteration(void);
void stopiteration(void);
void beginname(void);
boolean morename(ASCIIcode c);
void endname(void);
void packfilename(str_number n, str_number a, str_number e);
void packbufferedname(small_number n, integer a, integer b);
str_number makenamestring(void);
str_number amakenamestring(alphafile f);
str_number bmakenamestring(bytefile f);
str_number wmakenamestring(wordfile f);
void scanfilename(void);
void packjobname(str_number s);
void promptfilename(str_number s, str_number e);
void openlogfile(void);
void startinput(void);
void badexp(str_number s);
void stashin(halfword p);
void backexpr(void);
void badsubscript(void);
void obliterated(halfword q);
void binarymac(halfword p, halfword c, halfword n);
void materializepen(void);
void knownpair(void);
halfword newknot(void);
small_number scandirection(void);
void donullary(quarterword c);
boolean nicepair(integer p, quarterword t);
void printknownorunknowntype(small_number t, integer v);
void badunary(quarterword c);
void negatedeplist(halfword p);
void pairtopath(void);
void takepart(quarterword c);
void strtonum(quarterword c);
scaled pathlength(void);
void testknown(quarterword c);
void dounary(quarterword c);
void badbinary(halfword p, quarterword c);
halfword tarnished(halfword p);
void depfinish(halfword v, halfword q, small_number t);
void addorsubtract(halfword p, halfword q, quarterword c);
void depmult(halfword p, integer v, boolean visscaled);
void hardtimes(halfword p);
void depdiv(halfword p, scaled v);
void setuptrans(quarterword c);
void setupknowntrans(quarterword c);
void trans(halfword p, halfword q);
void pathtrans(halfword p, quarterword c);
void edgestrans(halfword p, quarterword c);
void bilin1(halfword p, scaled t, halfword q, scaled u, scaled delta);
void addmultdep(halfword p, scaled v, halfword r);
void bilin2(halfword p, halfword t, scaled v, halfword u, halfword q);
void bilin3(halfword p, scaled t, scaled v, scaled u, scaled delta);
void bigtrans(halfword p, quarterword c);
void cat(halfword p);
void chopstring(halfword p);
void choppath(halfword p);
void pairvalue(scaled x, scaled y);
void setupoffset(halfword p);
void setupdirectiontime(halfword p);
void findpoint(scaled v, quarterword c);
void dobinary(halfword p, quarterword c);
void fracmult(scaled n, scaled d);
void gfswap(void);
void gffour(integer x);
void gftwo(integer x);
void gfthree(integer x);
void gfpaint(integer d);
void gfstring(str_number s, str_number t);
void gfboc(integer minm, integer maxm, integer minn, integer maxn);
void initgf(void);
void shipout(eightbits c);
void tryeq(halfword l, halfword r);
void makeeq(halfword lhs);
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
void dispvar(halfword p);
void doshowvar(void);
void doshowdependencies(void);
void doshowwhatever(void);
boolean scanwith(void);
void findedgesvar(halfword t);
void doaddto(void);
scaled tfmcheck(small_number m);
void doshipout(void);
void dodisplay(void);
boolean getpair(commandcode c);
void doopenwindow(void);
void docull(void);
void domessage(void);
eightbits getcode(void);
void settag(halfword c, small_number t, halfword r);
void dotfmcommand(void);
void dospecial(void);
void storebasefile(void);
void dostatement(void);
void maincontrol(void);
halfword sortin(scaled v);
integer mincover(scaled d);
scaled thresholdfn(integer m);
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
