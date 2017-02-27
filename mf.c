#include "mf.h"

/* 4 */
void initialize (void)
{
  integer i; /* 19 */
  integer k; /* 130 */

  xchr[040] = ' ';
  xchr[041] = '!';
  xchr[042] = '"';
  xchr[043] = '#';
  xchr[044] = '$';
  xchr[045] = '%';
  xchr[046] = '&';
  xchr[047] = '\'';
  xchr[050] = '(';
  xchr[051] = ')';
  xchr[052] = '*';
  xchr[053] = '+';
  xchr[054] = ',';
  xchr[055] = '-';
  xchr[056] = '.';
  xchr[057] = '/';
  xchr[060] = '0';
  xchr[061] = '1';
  xchr[062] = '2';
  xchr[063] = '3';
  xchr[064] = '4';
  xchr[065] = '5';
  xchr[066] = '6';
  xchr[067] = '7';
  xchr[070] = '8';
  xchr[071] = '9';
  xchr[072] = ':';
  xchr[073] = ';';
  xchr[074] = '<';
  xchr[075] = '=';
  xchr[076] = '>';
  xchr[077] = '?';
  xchr[0100] = '@';
  xchr[0101] = 'A';
  xchr[0102] = 'B';
  xchr[0103] = 'C';
  xchr[0104] = 'D';
  xchr[0105] = 'E';
  xchr[0106] = 'F';
  xchr[0107] = 'G';
  xchr[0110] = 'H';
  xchr[0111] = 'I';
  xchr[0112] = 'J';
  xchr[0113] = 'K';
  xchr[0114] = 'L';
  xchr[0115] = 'M';
  xchr[0116] = 'N';
  xchr[0117] = 'O';
  xchr[0120] = 'P';
  xchr[0121] = 'Q';
  xchr[0122] = 'R';
  xchr[0123] = 'S';
  xchr[0124] = 'T';
  xchr[0125] = 'U';
  xchr[0126] = 'V';
  xchr[0127] = 'W';
  xchr[0130] = 'X';
  xchr[0131] = 'Y';
  xchr[0132] = 'Z';
  xchr[0133] = '[';
  xchr[0134] = '\\';
  xchr[0135] = ']';
  xchr[0136] = '^';
  xchr[0137] = '_';
  xchr[0140] = '`';
  xchr[0141] = 'a';
  xchr[0142] = 'b';
  xchr[0143] = 'c';
  xchr[0144] = 'd';
  xchr[0145] = 'e';
  xchr[0146] = 'f';
  xchr[0147] = 'g';
  xchr[0150] = 'h';
  xchr[0151] = 'i';
  xchr[0152] = 'j';
  xchr[0153] = 'k';
  xchr[0154] = 'l';
  xchr[0155] = 'm';
  xchr[0156] = 'n';
  xchr[0157] = 'o';
  xchr[0160] = 'p';
  xchr[0161] = 'q';
  xchr[0162] = 'r';
  xchr[0163] = 's';
  xchr[0164] = 't';
  xchr[0165] = 'u';
  xchr[0166] = 'v';
  xchr[0167] = 'w';
  xchr[0170] = 'x';
  xchr[0171] = 'y';
  xchr[0172] = 'z';
  xchr[0173] = '{';
  xchr[0174] = '|';
  xchr[0175] = '}';
  xchr[0176] = '~';
  for (i = 0; i <= 037; i++)
    xchr[i] = ' ';
  for (i = 0177; i <= 0377; i++)
    xchr[i] = ' ';
  for (i = first_text_char; i <= last_text_char; i++)
    xord[chr(i)] = 0177;
  for (i = 0200; i <= 0377; i++)
    xord[xchr[i]] = i;
  for (i = 0; i <= 0176; i++)
    xord[xchr[i]] = i;
  interaction = error_stop_mode;
  deletions_allowed = true;
  error_count = 0;
  help_ptr = 0;
  use_err_help = false;
  err_help = 0;
  interrupt = 0;
  OK_to_interrupt = true;
  arith_error = false;
  two_to_the[0] = 1;
  for (k = 1; k <= 30; k++)
    two_to_the[k] = 2 * two_to_the[k - 1];
  spec_log[1] = 93032640;
  spec_log[2] = 38612034;
  spec_log[3] = 17922280;
  spec_log[4] = 8662214;
  spec_log[5] = 4261238;
  spec_log[6] = 2113709;
  spec_log[7] = 1052693;
  spec_log[8] = 525315;
  spec_log[9] = 262400;
  spec_log[10] = 131136;
  spec_log[11] = 65552;
  spec_log[12] = 32772;
  spec_log[13] = 16385;
  for (k = 14; k <= 27; k++)
    spec_log[k] = two_to_the[27 - k];
  spec_log[28] = 1;
  spec_atan[1] = 27855475;
  spec_atan[2] = 14718068;
  spec_atan[3] = 7471121;
  spec_atan[4] = 3750058;
  spec_atan[5] = 1876857;
  spec_atan[6] = 938658;
  spec_atan[7] = 469357;
  spec_atan[8] = 234682;
  spec_atan[9] = 117342;
  spec_atan[10] = 58671;
  spec_atan[11] = 29335;
  spec_atan[12] = 14668;
  spec_atan[13] = 7334;
  spec_atan[14] = 3667;
  spec_atan[15] = 1833;
  spec_atan[16] = 917;
  spec_atan[17] = 458;
  spec_atan[18] = 229;
  spec_atan[19] = 115;
  spec_atan[20] = 57;
  spec_atan[21] = 29;
  spec_atan[22] = 14;
  spec_atan[23] = 7;
  spec_atan[24] = 4;
  spec_atan[25] = 2;
  spec_atan[26] = 1;
#ifdef DEBUG
  was_mem_end = mem_min;
  was_lo_max = mem_min;
  was_hi_min = mem_max;
  panicking = false;
#endif
  for (k = 1; k <= max_given_internal; k++)
    internal[k] = 0;
  int_ptr = max_given_internal;
  for (k = '0'; k <= '9'; k++)
    char_class[k] = digit_class;
  char_class['.'] = period_class;
  char_class[' '] = space_class;
  char_class['%'] = percent_class;
  char_class['"'] = string_class;
  char_class[','] = 5;
  char_class[';'] = 6;
  char_class['('] = 7;
  char_class[')'] = right_paren_class;
  for (k = 'A'; k <= 'Z'; k++)
    char_class[k] = letter_class;
  for (k = 'a'; k <= 'z'; k++)
    char_class[k] = letter_class;
  char_class['_'] = letter_class;
  char_class['<'] = 10;
  char_class['='] = 10;
  char_class['>'] = 10;
  char_class[':'] = 10;
  char_class['|'] = 10;
  char_class['`'] = 11;
  char_class['\''] = 11;
  char_class['+'] = 12;
  char_class['-'] = 12;
  char_class['/'] = 13;
  char_class['*'] = 13;
  char_class['\\'] = 13;
  char_class['!'] = 14;
  char_class['?'] = 14;
  char_class['#'] = 15;
  char_class['&'] = 15;
  char_class['@'] = 15;
  char_class['$'] = 15;
  char_class['^'] = 16;
  char_class['~'] = 16;
  char_class['['] = left_bracket_class;
  char_class[']'] = right_bracket_class;
  char_class['{'] = 19;
  char_class['}'] = 19;
  for (k = 0; k <= ' ' - 1; k++)
    char_class[k] = invalid_class;
  for (k = 127; k <= 255; k++)
    char_class[k] = invalid_class;
  char_class[9] = 2;
  char_class[12] = 2;
  next(1) = 0;
  text(1) = 0;
  eq_type(1) = tag_token;
  equiv(1) = null;
  for (k = 2; k <= hash_end; k++)
  {
    hash[k] = hash[1];
    eqtb[k] = eqtb[1];
  }
  big_node_size[transform_type] = transform_node_size;
  big_node_size[pair_type] = pair_node_size;
  save_ptr = null;
  octant_dir[first_octant] = "ENE";
  octant_dir[second_octant] = "NNE";
  octant_dir[third_octant] = "NNW";
  octant_dir[fourth_octant] = "WNW";
  octant_dir[fifth_octant] = "WSW";
  octant_dir[sixth_octant] = "SSW";
  octant_dir[seventh_octant] = "SSE";
  octant_dir[eighth_octant] = "ESE";
  max_rounding_ptr = 0;
  octant_code[1] = first_octant;
  octant_code[2] = second_octant;
  octant_code[3] = third_octant;
  octant_code[4] = fourth_octant;
  octant_code[5] = fifth_octant;
  octant_code[6] = sixth_octant;
  octant_code[7] = seventh_octant;
  octant_code[8] = eighth_octant;
  for (k = 1; k <= 8; k++)
    octant_number[octant_code[k]] = k;
  rev_turns = false;
  x_corr[first_octant] = 0;
  y_corr[first_octant] = 0;
  xy_corr[first_octant] = 0;
  x_corr[second_octant] = 0;
  y_corr[second_octant] = 0;
  xy_corr[second_octant] = 1;
  x_corr[third_octant] = -1;
  y_corr[third_octant] = 1;
  xy_corr[third_octant] = 0;
  x_corr[fourth_octant] = 1;
  y_corr[fourth_octant] = 0;
  xy_corr[fourth_octant] = 1;
  x_corr[fifth_octant] = 0;
  y_corr[fifth_octant] = 1;
  xy_corr[fifth_octant] = 1;
  x_corr[sixth_octant] = 0;
  y_corr[sixth_octant] = 1;
  xy_corr[sixth_octant] = 0;
  x_corr[seventh_octant] = 1;
  y_corr[seventh_octant] = 0;
  xy_corr[seventh_octant] = 1;
  x_corr[eighth_octant] = -1;
  y_corr[eighth_octant] = 1;
  xy_corr[eighth_octant] = 0;
  for (k = 1; k <= 8; k++)
    z_corr[k] = xy_corr[k] - x_corr[k];
  screen_started = false;
  screen_OK = false;
  for (k = 0; k <= 15; k++)
  {
    window_open[k] = false;
    window_time[k] = 0;
  }
  fix_needed = false;
  watch_coefs = true;
  cond_ptr = null;
  if_limit = normal;
  cur_if = 0;
  if_line = 0;
  loop_ptr = null;
  MF_base_default = "MFbases:plain.base";
  cur_exp = 0;
  var_flag = 0;
  start_sym = 0;
  long_help_seen = false;
  for (k = 0; k <= 255; k++)
  {
    tfm_width[k] = 0;
    tfm_height[k] = 0;
    tfm_depth[k] = 0;
    tfm_ital_corr[k] = 0;
    char_exists[k] = false;
    char_tag[k] = 0;
    char_remainder[k] = 0;
    skip_table[k] = undefined_label;
  }
  for (k = 1; k <= header_size; k++)
    header_byte[k] = -1;
  bc = 255;
  ec = 0;
  nl = 0;
  nk = 0;
  ne = 0;
  np = 0;
  internal[boundary_char] = -unity;
  bch_label = undefined_label;
  label_loc[0] = -1;
  label_ptr = 0;
  gf_prev_ptr = 0;
  total_chars = 0;
  half_buf = gf_buf_size / 2;
  gf_limit = gf_buf_size;
  gf_ptr = 0;
  gf_offset = 0;
  base_ident = 0;
}
/* 57 */
void print_ln (void)
{
  switch (selector)
  {
    case term_and_log:
      {
        wterm_cr();
        wlog_cr();
        term_offset = 0;
        file_offset = 0;
      }
      break;
    case log_only:
      {
        wlog_cr();
        file_offset = 0;
      }
      break;
    case term_only:
      {
        wterm_cr();
        term_offset = 0;
      }
      break;
    case no_print:
    case pseudo:
    case new_string:
      do_nothing();
      break;
  }
}
/* 58 */
void print_char (ASCII_code s)
{
  switch (selector)
  {
    case term_and_log:
      {
        wterm(xchr[s]);
        wlog(xchr[s]);
        incr(term_offset);
        incr(file_offset);
        if (term_offset == max_print_line)
        {
          wterm_cr();
          term_offset = 0;
        }
        if (file_offset == max_print_line)
        {
          wlog_cr();
          file_offset = 0;
        }
      }
      break;
    case log_only:
      {
        wlog(xchr[s]);
        incr(file_offset);
        if (file_offset == max_print_line)
          print_ln();
      }
      break;
    case term_only:
      {
        wterm(xchr[s]);
        incr(term_offset);
        if (term_offset == max_print_line)
          print_ln();
      }
      break;
    case no_print:
      do_nothing();
      break;
    case pseudo:
      if (tally < trick_count)
        trick_buf[tally % error_line] = s;
      break;
    case new_string:
      {
        if (pool_ptr < pool_size)
          append_char(s);
      }
      break;
  }
  incr(tally);
}
/* 59 */
void print (integer s)
{
  pool_pointer j;

  if ((s < 0) || (s >= str_ptr))
    s = "???";
  if ((s < 256) && (selector > pseudo))
    print_char(s);
  else
  {
    j = str_start[s];
    while (j < str_start[s + 1])
    {
      print_char(so(str_pool[j]));
      incr(j);
    }
  }
}
void r_print (const char * s)
{
  while (*s)
    print_char(*s++);
}
/* 60 */
void slow_print (integer s)
{
  pool_pointer j;

  if ((s < 0) || (s >= str_ptr))
    s = "???";
  if ((s < 256) && (selector > pseudo))
    print_char(s);
  else
  {
    j = str_start[s];
    while (j < str_start[s + 1])
    {
      print(so(str_pool[j]));
      incr(j);
    }
  }
}
/* 62 */
void print_nl (str_number s)
{
  if (((term_offset > 0) && (odd(selector))) || ((file_offset > 0) && (selector >= log_only)))
    print_ln();
  print(s);
}
void r_print_nl (const char * s)
{
  if (((term_offset > 0) && (odd(selector))) || ((file_offset > 0) && (selector >= log_only)))
    print_ln();
  r_print(s);
}
/* 63 */
void print_the_digs (eight_bits k)
{
  while (k > 0)
  {
    decr(k);
    print_char('0' + dig[k]);
  }
}
/* 64 */
void print_int (integer n)
{
  unsigned char k;
  integer m;
  
  k = 0;
  if (n < 0)
  {
    print_char('-');
    if (n > -100000000)
      negate(n);
    else
    {
      m = -1 - n;
      n = m / 10;
      m = (m % 10) + 1;
      k = 1;
      if (m < 10)
        dig[0] = m;
      else
      {
        dig[0] = 0;
        incr(n);
      }
    }
  }
  do {
    dig[k] = n % 10;
    n = n / 10;
    incr(k);
  } while (!(n == 0));
  print_the_digs(k);
}
/* 103 */
void print_scaled (scaled s)
{
  scaled delta;

  if (s < 0)
  {
    print_char('-');
    negate(s);
  }
  print_int(s / unity);
  s = 10 * (s % unity) + 5;
  if (s != 5)
  {
    delta = 10;
    print_char('.');
    do {
      if (delta > unity)
        s = s + 0100000 - (delta / 2);
      print_char('0' + (s / unity));
      s = 10 * (s % unity);
      delta = delta * 10;
    } while (!(s <= delta));
  }
}
/* 104 */
void print_two (scaled x, scaled y)
{
  print_char('(');
  print_scaled(x);
  print_char(',');
  print_scaled(y);
  print_char(')');
}
/* 187 */
void print_type (small_number t)
{
  switch (t)
  {
    case vacuous:
      r_print("vacuous");
      break;
    case boolean_type:
      r_print("boolean");
      break;
    case unknown_boolean:
      r_print("unknown boolean");
      break;
    case string_type:
      r_print("string");
      break;
    case unknown_string:
      r_print("unknown string");
      break;
    case pen_type:
      r_print("pen");
      break;
    case unknown_pen:
      r_print("unknown pen");
      break;
    case future_pen:
      r_print("future pen");
      break;
    case path_type:
      r_print("path");
      break;
    case unknown_path:
      r_print("unknown path");
      break;
    case picture_type:
      r_print("picture");
      break;
    case unknown_picture:
      r_print("unknown picture");
      break;
    case transform_type:
      r_print("transform");
      break;
    case pair_type:
      r_print("pair");
      break;
    case known:
      r_print("known numeric");
      break;
    case dependent:
      r_print("dependent");
      break;
    case proto_dependent:
      r_print("proto-dependent");
      break;
    case numeric_type:
      r_print("numeric");
      break;
    case independent:
      r_print("independent");
      break;
    case token_list:
      r_print("token list");
      break;
    case structured:
      r_print("structured");
      break;
    case unsuffixed_macro:
      r_print("unsuffixed macro");
      break;
    case suffixed_macro:
      r_print("suffixed macro");
      break;
    default:
      r_print("undefined");
      break;
  }
}
/* 195 */
void begin_diagnostic (void)
{
  old_setting = selector;
  if ((internal[tracing_online] <= 0) && (selector == term_and_log))
  {
    decr(selector);
    if (history == spotless)
      history = warning_issued;
  }
}
/* 195 */
void end_diagnostic (boolean blank_line)
{
  r_print_nl("");
  if (blank_line)
    print_ln();
  selector = old_setting;
}
/* 197 */
void print_diagnostic (str_number s, str_number t, boolean nuline)
{
  begin_diagnostic();
  if (nuline)
    print_nl(s);
  else
    print(s);
  r_print(" at line ");
  print_int(line);
  print(t);
  print_char(':');
}
/* 773 */
void print_file_name (integer n, integer a, integer e)
{
  slow_print(a);
  slow_print(n);
  slow_print(e);
}
void normalize_selector(void); void get_next(void);
void term_input(void); void show_context(void);
void begin_file_reading(void); void open_log_file(void);
void close_files_and_terminate(void);
void clear_for_error_prompt(void);
/* 43 */
void flush_string (str_number s)
{
  if (s < str_ptr - 1)
    str_ref[s] = 0;
  else
  {
    do {
      decr(str_ptr);
    } while (!(str_ref[str_ptr - 1] != 0));
  }
  pool_ptr = str_start[str_ptr];
}
/* 76 */
void jump_out (void)
{
  close_files_and_terminate();
}
/* 77 */
void error (void)
{
  ASCII_code c;
  integer s1, s2, s3;
  pool_pointer j;

  if (history < error_message_issued)
    history = error_message_issued;
  print_char('.');
  show_context();
  if (interaction == error_stop_mode)
  {
    while (true)
    {
    l_continue:
      clear_for_error_prompt();
      prompt_input("? ");
      if (last == first)
        goto l_exit;
      c = buffer[first];
      if (c >= 'a')
        c = c + 'A' - 'a';
      switch (c)
      {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
          if (deletions_allowed)
          {
            s1 = cur_cmd;
            s2 = cur_mod;
            s3 = cur_sym;
            OK_to_interrupt = false;
            if ((last > first + 1) && (buffer[first + 1] >= '0') && (buffer[first + 1] <= '9'))
              c = c * 10 + buffer[first + 1] - '0' * 11;
            else
              c = c - '0';
            while (c > 0)
            {
              get_next();
              if (cur_cmd == string_token)
                delete_str_ref(cur_mod);
              decr(c);
            }
            cur_cmd = s1;
            cur_mod = s2;
            cur_sym = s3;
            OK_to_interrupt = true;
            help2("I have just deleted some text, as you asked.",
              "You can now delete more, or insert, or whatever.");
            show_context();
            goto l_continue;
          }
          break;
#ifdef DEBUG
        case 'D':
          {
            debug_help();
            goto l_continue;
          }
          break;
#endif
        case 'E':
          if (file_ptr > 0)
          {
            r_print_nl("You want to edit file ");
            slow_print(input_stack[file_ptr].name_field);
            r_print(" at line ");
            print_int(line);
            interaction = scroll_mode;
            jump_out();
          }
          break;
        case 'H':
          {
            if (use_err_help)
            {
              j = str_start[err_help];
              while (j < str_start[err_help + 1])
              {
                if (str_pool[j] != si('%'))
                  print(so(str_pool[j]));
                else if (j + 1 == str_start[err_help + 1])
                  print_ln();
                else if (str_pool[j + 1] != si('%'))
                  print_ln();
                else
                {
                  incr(j);
                  print_char('%');
                }
                incr(j);
              }
              use_err_help = false;
            }
            else
            {
              if (help_ptr == 0)
                help2("Sorry, I don't know how to help in this situation.",
                  "Maybe you should try asking a human?");
              do {
                decr(help_ptr);
                print(help_line[help_ptr]);
                print_ln();
              } while (!(help_ptr == 0));
            }
            help4("Sorry, I already gave what help I could...",
              "Maybe you should try asking a human?",
              "An error might have occurred before I noticed any problems.",
              "``If all else fails, read the instructions.''");
            goto l_continue;
          }
          break;
        case 'I':
          {
            begin_file_reading();
            if (last > first + 1)
            {
              loc = first + 1;
              buffer[first] = ' ';
            }
            else
            {
              prompt_input("insert>");
              loc = first;
            }
            first = last + 1;
            cur_input.limit_field = last;
            goto l_exit;
          }
          break;
        case 'Q':
        case 'R':
        case 'S':
          {
            error_count = 0;
            interaction = 0 + c - 'Q';
            print(272);
            switch (c)
            {
              case 'Q':
                {
                  r_print("batchmode");
                  decr(selector);
                }
                break;
              case 'R':
                r_print("nonstopmode");
                break;
              case 'S':
                r_print("scrollmode");
                break;
            }
            r_print("...");
            print_ln();
            update_terminal();
            goto l_exit;
          }
          break;
        case 'X':
          {
            interaction = scroll_mode;
            jump_out();
          }
          break;
        default:
          do_nothing();
          break;
      }
      {
        r_print("Type <return> to proceed, S to scroll future error messages,");
        r_print_nl("R to run without stopping, Q to run quietly,");
        r_print_nl("I to insert something, ");
        if (file_ptr > 0)
          r_print("E to edit your file,");
        if (deletions_allowed)
          r_print_nl("1 or ... or 9 to ignore the next 1 to 9 tokens of input,");
        r_print_nl("H for help, X to quit.");
      }
    }
  }
  incr(error_count);
  if (error_count == 100)
  {
    r_print_nl("(That makes 100 errors; please try again.)");
    history = fatal_error_stop;
    jump_out();
  }
  if (interaction > batch_mode)
    decr(selector);
  if (use_err_help)
  {
    r_print_nl("");
    j = str_start[err_help];
    while (j < str_start[err_help + 1])
    {
      if (str_pool[j] != si('%'))
        print(so(str_pool[j]));
      else if (j + 1 == str_start[err_help + 1])
        print_ln();
      else if (str_pool[j + 1] != si('%'))
        print_ln();
      else
      {
        incr(j);
        print_char('%');
      }
      incr(j);
    }
  }
  else
  {
    while (help_ptr > 0)
    {
      decr(help_ptr);
      print_nl(help_line[help_ptr]);
    }
  }
  print_ln();
  if (interaction > batch_mode)
    incr(selector);
  print_ln();
  l_exit:;
}
/* 88 */
void fatal_error (str_number s)
{
  normalize_selector();
  print_err("Emergency stop");
  help1(s);
  succumb();
}
/* 89 */
void overflow (str_number s, integer n)
{
  normalize_selector();
  print_err("METAFONT capacity exceeded, sorry [");
  print(s);
  print_char('=');
  print_int(n);
  print_char(']');
  help2("If you really absolutely need more capacity,",
    "you can ask a wizard to enlarge me.");
  succumb();
}
/* 90 */
void confusion (str_number s)
{
  normalize_selector();
  if (history < error_message_issued)
  {
    print_err("This can't happen (");
    print(s);
    print_char(')');
    help1("I'm broken. Please show this to someone who can fix can fix");
  }
  else
  {
    print_err("I can't go on meeting you like this");
    help2("One of your faux pas seems to have wounded me deeply...",
      "in fact, I'm barely conscious. Please fix it and try again.");
  }
  succumb();
}
/* 36 */
boolean init_terminal (void)
{
  boolean Result;

  t_open_in();
  if (last > first)
  {
    loc = first;
    while ((loc < last) && (buffer[loc] == ' '))
      incr(loc);
    if (loc < last)
    {
      Result = true;
      goto l_exit;
    }
  }
  while (true)
  {
    wakeup_terminal();
    fputs("**", stdout);
    fflush(stdout);
    if (!input_ln(stdin, true))
    {
      putc('\n', stdout);
      fprintf(stdout, "%s\n", "!End of file on the terminal... why?");
      Result = false;
      goto l_exit;
    }
    loc = first;
    while ((loc < last) && (buffer[loc] == ' '))
      incr(loc);
    if (loc < last)
    {
      Result = true;
      goto l_exit;
    }
    fprintf(stdout, "%s\n", "Please type the name of your input file.");
  }
l_exit:;
  return Result;
}
/* 44 */
str_number make_string (void)
{
  if (str_ptr == max_str_ptr)
  {
    if (str_ptr == max_strings)
      overflow("number of strings", max_strings - init_str_ptr);
    incr(max_str_ptr);
  }
  str_ref[str_ptr] = 1;
  incr(str_ptr);
  str_start[str_ptr] = pool_ptr;
  return str_ptr - 1;
}
/* 45 */
boolean str_eq_buf (str_number s, integer k)
{
  pool_pointer j;
  boolean result;

  j = str_start[s];
  while (j < str_start[s + 1])
  {
    if (str_pool[j] != buffer[k])
    {
      result = false;
      goto not_found;
    }
    incr(j);
    incr(k);
  }
  result = true;
not_found:
  return result;
}
/* 46 */
integer str_vs_str (str_number s, str_number t)
{
  integer Result;
  pool_pointer j, k;
  integer ls, lt;
  integer l;

  ls = length(s);
  lt = length(t);
  if (ls <= lt)
    l = ls;
  else
    l = lt;
  j = str_start[s];
  k = str_start[t];
  while (l > 0)
  {
    if (str_pool[j] != str_pool[k])
    {
      Result = str_pool[j] - str_pool[k];
      goto l_exit;
    }
    incr(j);
    incr(k);
    decr(l);
  }
  Result = ls - lt;
l_exit:;
  return Result;
}
/* 47 */
boolean get_strings_started (void)
{
  boolean Result;
  unsigned char k, l;
  str_number g;

  pool_ptr = 0;
  str_ptr = 0;
  max_pool_ptr = 0;
  max_str_ptr = 0;
  str_start[0] = 0;
  for (k = 0; k <= 255; k++)
  {
    if (((k < ' ') || (k > '~')))
    {
      append_char('^');
      append_char('^');
      if (k < 0100)
        append_char(k + 0100);
      else if (k < 0200)
        append_char(k - 0100);
      else
      {
        append_lc_hex(k / 16);
        append_lc_hex(k % 16);
      }
    }
    else
      append_char(k);
    g = make_string();
    str_ref[g] = max_str_ref;
  }
  g = load_pool_strings((pool_size - string_vacancies));
  if (g == 0)
  {
    fprintf(stdout, "%s\n", "! You have to increase pool_size.");
    Result = false;
    goto l_exit;
  }
  Result = true;
l_exit:;
  return Result;
}
/* 65 */
void print_dd (integer n)
{
  n = abs(n) % 100;
  print_char('0' + (n / 10));
  print_char('0' + (n % 10));
}
/* 66 */
void term_input (void)
{
  integer k;

  update_terminal();
  if (!input_ln(stdin, true))
    fatal_error("End of file on the terminal!");
  term_offset = 0;
  decr(selector);
  if (last != first)
    for (k = first; k <= last - 1; k++)
      print(buffer[k]);
  print_ln();
  buffer[last] = '%';
  incr(selector);
}
/* 87 */
void normalize_selector (void)
{
  if (log_opened)
    selector = term_and_log;
  else
    selector = term_only;
  if (job_name == 0)
    open_log_file();
  if (interaction == batch_mode)
    decr(selector);
}
/* 93 */
void pause_for_instructions (void)
{
  if (OK_to_interrupt)
  {
    interaction = error_stop_mode;
    if ((selector == log_only) || (selector == no_print))
      incr(selector);
    print_err("Interruption");
    help3("You rang?",
      "Try to insert some instructions for me (e.g.,`I show x'),",
      "unless you just want to quit by typing `X'.");
    deletions_allowed = false;
    error();
    deletions_allowed = true;
    interrupt = 0;
  }
}
/* 94 */
void missing_err (str_number s)
{
  print_err("Missing `");
  print(s);
  r_print("' has been inserted");
}
/* 99 */
void clear_arith (void)
{
  print_err("Arithmetic overflow");
  help4("Uh, oh. A little while ago one of the quantities that I was",
    "computing got too large, so I'm afraid your answers will be",
    "somewhat askew. You'll probably have to adopt different",
    "tactics next time. But I shall try to carry on anyway.");
  error();
  arith_error = false;
}
/* 100 */
integer slow_add (integer x, integer y)
{
  if (x >= 0)
  {
    if (y <= el_gordo - x)
      return x + y;
    else
    {
      arith_error = true;
      return el_gordo;
    }
  }
  else if (-y <= el_gordo + x)
    return x + y;
  else
  {
    arith_error = true;
    return -el_gordo;
  }
}
/* 102 */
scaled round_decimals (small_number k)
{
  integer a;
  
  a = 0;
  while (k > 0)
  {
    decr(k);
    a = (a + dig[k] * two) / 10;
  }
  return half(a + 1);
}
/* 107 */
fraction make_fraction (integer p, integer q)
{
  integer f;
  integer n;
  boolean negative;
  integer be_careful;
  
  if (p >= 0)
    negative = false;
  else
  {
    negate(p);
    negative = true;
  }
  if (q <= 0)
  {
#ifdef DEBUG
    if (q == 0)
      confusion("/");
#endif
    negate(q);
    negative = !negative;
  }
  n = p / q;
  p = p % q;
  if (n >= 8)
  {
    arith_error = true;
    if (negative)
      return -el_gordo;
    else
      return el_gordo;
  }
  else
  {
    n = (n - 1) * fraction_one;
    f = 1;
    do {
      be_careful = p - q;
      p = be_careful + p;
      if (p >= 0)
        f = f + f + 1;
      else
      {
        _double(f);
        p = p + q;
      }
    } while (!(f >= fraction_one));
    be_careful = p - q;
    if (be_careful + p >= 0)
      incr(f);
    if (negative)
      return -(f + n);
    else
      return f + n;
  }
}
/* 109 */
integer take_fraction (integer q, fraction f)
{
  integer p;
  boolean negative;
  integer n;
  integer be_careful;
  
  if (f >= 0)
    negative = false;
  else
  {
    negate(f);
    negative = true;
  }
  if (q < 0)
  {
    negate(q);
    negative = !negative;
  }
  if (f < fraction_one)
    n = 0;
  else
  {
    n = f / fraction_one;
    f = f % fraction_one;
    if (q <= el_gordo / n)
      n = n * q;
    else
    {
      arith_error = true;
      n = el_gordo;
    }
  }
  f = f + fraction_one;
  p = fraction_half;
  if (q < fraction_four)
    do {
      if (odd(f))
        p = half(p + q);
      else
        p = half(p);
      f = half(f);
    } while (!(f == 1));
  else
    do {
      if (odd(f))
        p = p + half(q - p);
      else
        p = half(p);
      f = half(f);
    } while (!(f == 1));
  be_careful = n - el_gordo;
  if (be_careful + p > 0)
  {
    arith_error = true;
    n = el_gordo - p;
  }
  if (negative)
    return -(n + p);
  else
    return n + p;
}
/* 112 */
integer take_scaled (integer q, scaled f)
{
  integer p;
  boolean negative;
  integer n;
  integer be_careful;
  
  if (f >= 0)
    negative = false;
  else
  {
    negate(f);
    negative = true;
  }
  if (q < 0)
  {
    negate(q);
    negative = !negative;
  }
  if (f < unity)
    n = 0;
  else
  {
    n = f / unity;
    f = f % unity;
    if (q <= el_gordo / n)
      n = n * q;
    else
    {
      arith_error = true;
      n = el_gordo;
    }
  }
  f = f + unity;
  p = half_unit;
  if (q < fraction_four)
    do {
      if (odd(f))
        p = half(p + q);
      else
        p = half(p);
      f = half(f);
    } while (!(f == 1));
  else
    do {
      if (odd(f))
        p = p + half(q - p);
      else
        p = half(p);
      f = half(f);
    } while (!(f == 1));
  be_careful = n - el_gordo;
  if (be_careful + p > 0)
  {
    arith_error = true;
    n = el_gordo - p;
  }
  if (negative)
    return -(n + p);
  else
    return n + p;
}
/* 114 */
scaled make_scaled (integer p, integer q)
{
  integer f;
  integer n;
  boolean negative;
  integer be_careful;

  if (p >= 0)
    negative = false;
  else
  {
    negate(p);
    negative = true;
  }
  if (q <= 0)
  {
#ifdef DEBUG
    if (q == 0)
      confusion("/");
#endif
    negate(q);
    negative = !negative;
  }
  n = p / q;
  p = p % q;
  if (n >= 0100000)
  {
    arith_error = true;
    if (negative)
      return -el_gordo;
    else
      return el_gordo;
  }
  else
  {
    n = (n - 1) * unity;
    f = 1;
    do {
      be_careful = p - q;
      p = be_careful + p;
      if (p >= 0)
        f = f + f + 1;
      else
      {
        _double(f);
        p = p + q;
      }
    } while (!(f >= unity));
    be_careful = p - q;
    if (be_careful + p >= 0)
      incr(f);
    if (negative)
      return -(f + n);
    else
      return f + n;
  }
}
/* 116 */
fraction velocity (fraction st, fraction ct, fraction sf, fraction cf, scaled t)
{
  integer acc, num, denom;

  acc = take_fraction(st - (sf / 16), sf - (st / 16));
  acc = take_fraction(acc, ct - cf);
  num = fraction_two + take_fraction(acc, 379625062);
  denom = fraction_three + take_fraction(ct, 497706707) + take_fraction(cf, 307599661);
  if (t != unity)
    num = make_scaled(num, t);
  if (num / 4 >= denom)
    return fraction_four;
  else
    return make_fraction(num, denom);
}
/* 117 */
integer ab_vs_cd (integer a, integer b, integer c, integer d)
{
  integer Result;
  integer q, r;
  
  if (a < 0)
  {
    negate(a);
    negate(b);
  }
  if (c < 0)
  {
    negate(c);
    negate(d);
  }
  if (d <= 0)
  {
    if (b >= 0)
    {
      if (((a == 0) || (b == 0)) && ((c == 0) || (d == 0)))
        return_sign(0);
      else
        return_sign(1);
    }
    if (d == 0)
    {
      if (a == 0)
        return_sign(0);
      else
        return_sign(-1);
    }
    q = a;
    a = c;
    c = q;
    q = -b;
    b = -d;
    d = q;
  }
  else if (b <= 0)
  {
    if (b < 0)
    {
      if (a > 0)
        return_sign(-1);
    }
    if (c == 0)
      return_sign(0);
    else
      return_sign(-1);
  }
  while (true)
  {
    q = a / d;
    r = c / b;
    if (q != r)
    {
      if (q > r)
        return_sign(1);
      else
        return_sign(-1);
    }
    q = a % d;
    r = c % b;
    if (r == 0)
    {
      if (q == 0)
        return_sign(0);
      else
        return_sign(1);
    }
    if (q == 0)
      return_sign(-1);
    a = b;
    b = q;
    c = d;
    d = r;
  }
  l_exit:;
  return Result;
}
/* 121 */
scaled square_rt (scaled x)
{
  small_number k;
  integer y, q;
  
  if (x <= 0)
  {
    if (x < 0)
    {
      print_err("Square root of ");
      print_scaled(x);
      r_print(" has been replaced by 0");
      help2("Since I don't take square roots of negative numbers,",
        "I'm zeroing this one. Proceed, with fingers crossed.");
      error();
    }
    return 0;
  }
  else
  {
    k = 23;
    q = 2;
    while (x < fraction_two)
    {
      decr(k);
      x = x + x + x + x;
    }
    if (x < fraction_four)
      y = 0;
    else
    {
      x = x - fraction_four;
      y = 1;
    }
    do {
      _double(x);
      _double(y);
      if (x >= fraction_four)
      {
        x = x - fraction_four;
        incr(y);
      }
      _double(x);
      y = y + y - q;
      _double(q);
      if (x >= fraction_four)
      {
        x = x - fraction_four;
        incr(y);
      }
      if (y > q)
      {
        y = y - q;
        q = q + 2;
      }
      else if (y <= 0)
      {
        q = q - 2;
        y = y + q;
      }
      decr(k);
    } while (!(k == 0));
    return half(q);
  }
}
/* 124 */
integer pyth_add (integer a, integer b)
{
  integer Result;
  fraction r;
  boolean big;
  
  a = abs(a);
  b = abs(b);
  if (a < b)
  {
    r = b;
    b = a;
    a = r;
  }
  if (b > 0)
  {
    if (a < fraction_two)
      big = false;
    else
    {
      a = a / 4;
      b = b / 4;
      big = true;
    }
    while (true)
    {
      r = make_fraction(b, a);
      r = take_fraction(r, r);
      if (r == 0)
        goto done;
      r = make_fraction(r, fraction_four + r);
      a = a + take_fraction(a + a, r);
      b = take_fraction(b, r);
    }
  done:;
    if (big)
    {
      if (a < fraction_two)
        a = a + a + a + a;
      else
      {
        arith_error = true;
        a = el_gordo;
      }
    }
  }
  return a;
}
/* 126 */
integer pyth_sub (integer a, integer b)
{
  fraction r;
  boolean big;
  
  a = abs(a);
  b = abs(b);
  if (a <= b)
  {
    if (a < b)
    {
      print_err("Pythagorean subtraction ");
      print_scaled(a);
      r_print("+-+");
      print_scaled(b);
      r_print(" has been replaced by 0");
      help2("Since I don't take square roots of negative numbers,",
        "I'm zeroing this one. Proceed, with fingers crossed.");
      error();
    }
    a = 0;
  }
  else
  {
    if (a < fraction_four)
      big = false;
    else
    {
      a = half(a);
      b = half(b);
      big = true;
    }
    while (true)
    {
      r = make_fraction(b, a);
      r = take_fraction(r, r);
      if (r == 0)
        goto done;
      r = make_fraction(r, fraction_four - r);
      a = a - take_fraction(a + a, r);
      b = take_fraction(b, r);
    }
  done:;
    if (big)
      a = a + a;
  }
  return a;
}
/* 132 */
scaled m_log (scaled x)
{
  integer y, z;
  integer k;

  if (x <= 0)
  {
    print_err("Logarithm of ");
    print_scaled(x);
    r_print(" has been replaced by 0");
    help2("Since I don't take logs of non-positive numbers,",
      "I'm zeroing this one. Proceed, with fingers crossed.");
    error();
    return 0;
  }
  else
  {
    y = 1302456956 + 4 - 100;
    z = 27595 + 6553600;
    while (x < fraction_four)
    {
      _double(x);
      y = y - 93032639;
      z = z - 48782;
    }
    y = y + (z / unity);
    k = 2;
    while (x > fraction_four + 4)
    {
      z = ((x - 1) / two_to_the[k]) + 1;
      while (x < fraction_four + z)
      {
        z = half(z + 1);
        k = k + 1;
      }
      y = y + spec_log[k];
      x = x - z;
    }
    return y / 8;
  }
}
/* 135 */
scaled m_exp (scaled x)
{
  small_number k;
  integer y, z;
  
  if (x > 174436200)
  {
    arith_error = true;
    return el_gordo;
  }
  else if (x < -197694359)
    return 0;
  else
  {
    if (x <= 0)
    {
      z = -8 * x;
      y = 04000000;
    }
    else
    {
      if (x <= 127919879)
        z = 1023359037 - 8 * x;
      else
        z = 8 * (174436200 - x);
      y = el_gordo;
    }
    k = 1;
    while (z > 0)
    {
      while (z >= spec_log[k])
      {
        z = z - spec_log[k];
        y = y - 1 - ((y - two_to_the[k - 1]) / two_to_the[k]);
      }
      incr(k);
    }
    if (x <= 127919879)
      return (y + 8) / 16;
    else
      return y;
  }
}
/* 139 */
angle n_arg (integer x, integer y)
{
  angle Result;
  angle z;
  integer t;
  small_number k;
  unsigned char octant;
  
  if (x >= 0)
    octant = first_octant;
  else
  {
    negate(x);
    octant = first_octant + negate_x;
  }
  if (y < 0)
  {
    negate(y);
    octant = octant + negate_y;
  }
  if (x < y)
  {
    t = y;
    y = x;
    x = t;
    octant = octant + switch_x_and_y;
  }
  if (x == 0)
  {
    print_err("angle(0,0) is taken as zero");
    help2("The `angle' between two identical points is undefined.",
      "I'm zeroing this one. Proceed, with fingers crossed." );
    error();
    Result = 0;
  }
  else
  {
    while (x >= fraction_two)
    {
      x = half(x);
      y = half(y);
    }
    z = 0;
    if (y > 0)
    {
      while (x < fraction_one)
      {
        _double(x);
        _double(y);
      }
      k = 0;
      do {
        _double(y);
        incr(k);
        if (y > x)
        {
          z = z + spec_atan[k];
          t = x;
          x = x + (y / two_to_the[k + k]);
          y = y - t;
        }
      } while (!(k == 15));
      do {
        _double(y);
        incr(k);
        if (y > x)
        {
          z = z + spec_atan[k];
          y = y - x;
        }
      } while (!(k == 26));
    }
    switch (octant)
    {
      case first_octant:
        Result = z;
        break;
      case second_octant:
        Result = ninety_deg - z;
        break;
      case third_octant:
        Result = ninety_deg + z;
        break;
      case fourth_octant:
        Result = one_eighty_deg - z;
        break;
      case fifth_octant:
        Result = z - one_eighty_deg;
        break;
      case sixth_octant:
        Result = -z - ninety_deg;
        break;
      case seventh_octant:
        Result = z - ninety_deg;
        break;
      case eighth_octant:
        Result = -z;
        break;
    }
  }
  return Result;
}
/* 145 */
void n_sin_cos (angle z)
{
  small_number k;
  unsigned char q;
  fraction r;
  integer x, y, t;
  
  while (z < 0)
    z = z + three_sixty_deg;
  z = z % three_sixty_deg;
  q = z / forty_five_deg;
  z = z % forty_five_deg;
  x = fraction_one;
  y = x;
  if (!odd(q))
    z = forty_five_deg - z;
  k = 1;
  while (z > 0)
  {
    if (z >= spec_atan[k])
    {
      z = z - spec_atan[k];
      t = x;
      x = t + y / two_to_the[k];
      y = y - t / two_to_the[k];
    }
    incr(k);
  }
  if (y < 0)
    y = 0;
  switch (q)
  {
    case 0:
      do_nothing();
      break;
    case 1:
      {
        t = x;
        x = y;
        y = t;
      }
      break;
    case 2:
      {
        t = x;
        x = -y;
        y = t;
      }
      break;
    case 3:
      negate(x);
      break;
    case 4:
      {
        negate(x);
        negate(y);
      }
      break;
    case 5:
      {
        t = x;
        x = -y;
        y = -t;
      }
      break;
    case 6:
      {
        t = x;
        x = y;
        y = -t;
      }
      break;
    case 7:
      negate(y);
      break;
  }
  r = pyth_add(x, y);
  n_cos = make_fraction(x, r);
  n_sin = make_fraction(y, r);
}
/* 149 */
void new_randoms (void)
{
  unsigned char k;
  fraction x;
  
  for (k = 0; k <= 23; k++)
  {
    x = randoms[k] - randoms[k + 31];
    if (x < 0)
      x = x + fraction_one;
    randoms[k] = x;
  }
  for (k = 24; k <= 54; k++)
  {
    x = randoms[k] - randoms[k - 24];
    if (x < 0)
      x = x + fraction_one;
    randoms[k] = x;
  }
  j_random = 54;
}
/* 150 */
void init_randoms (scaled seed)
{
  fraction j, jj, k;
  unsigned char i;

  j = abs(seed);
  while (j >= fraction_one)
    j = half(j);
  k = 1;
  for (i = 0; i <= 54; i++)
  {
    jj = k;
    k = j - k;
    j = jj;
    if (k < 0)
      k = k + fraction_one;
    randoms[(i * 21) % 55] = j;
  }
  new_randoms();
  new_randoms();
  new_randoms();
}
/* 151 */
scaled unif_rand (scaled x)
{
  scaled y;
  
  next_random();
  y = take_fraction(abs(x), randoms[j_random]);
  if (y == abs(x))
    return 0;
  else if (x > 0)
    return y;
  else
    return -y;
}
/* 152 */
scaled norm_rand (void)
{
  integer x, u, l;

  do {
    do {
      next_random();
      x = take_fraction(112429, randoms[j_random] - fraction_half);
      next_random();
      u = randoms[j_random];
    } while (!(abs(x) < u));
    x = make_fraction (x, u);
    l = 139548960 - m_log(u);
  } while (!(ab_vs_cd(1024, l, x, x) >= 0));
  return x;
}
/* 157 */
#ifdef DEBUG
void print_word (memory_word w)
{
  print_int(w.cint);
  print_char(' ');
  print_scaled(w.sc);
  print_char(' ');
  print_scaled(w.sc / 010000);
  print_ln();
  print_int(w.hh.lh);
  print_char('=');
  print_int(w.hh.b0);
  print_char(':');
  print_int(w.hh.b1);
  print_char(';');
  print_int(w.hh.rh);
  print_char(' ');
  print_int(w.qqqq.b0);
  print_char(':');
  print_int(w.qqqq.b1);
  print_char(':');
  print_int(w.qqqq.b2);
  print_char(':');
  print_int(w.qqqq.b3);
}
#endif
void print_capsule(void);
/* 217 */
void show_token_list (integer p, integer q, integer l, integer null_tally)
{
  small_number cclass, c;
  integer r, v;

  cclass = percent_class;
  tally = null_tally;
  while ((p != null) && (tally < l))
  {
    if (p == q)
      set_trick_count();
    c = letter_class;
    if ((p < mem_min) || (p > mem_end))
    {
      r_print(" CLOBBERED");
      goto l_exit;
    }
    if (p < hi_mem_min)
      if (name_type(p) == token)
        if (type(p) == known)
        {
          if (cclass == digit_class)
            print_char(' ');
          v = value(p);
          if (v < 0)
          {
            if (cclass == left_bracket_class)
              print_char(' ');
            print_char('[');
            print_scaled(v);
            print_char(']');
            c = right_bracket_class;
          }
          else
          {
            print_scaled(v);
            c = digit_class;
          }
        }
        else if (type(p) != string_type)
          r_print(" BAD");
        else
        {
          print_char('"');
          slow_print(value(p));
          print_char('"');
          c = string_class;
        }
      else if ((name_type(p) != capsule) || (type(p) < vacuous) || (type(p) > independent))
        r_print(" BAD");
      else
      {
        g_pointer = p;
        print_capsule();
        c = right_paren_class;
      }

    else
    {
      r = info(p);
      if (r >= expr_base)
      {
        if (r < suffix_base)
        {
          r_print("EXPR");
          r = r - (expr_base);
        }
        else if (r < text_base)
        {
          r_print("SUFFIX");
          r = r - (suffix_base);
        }
        else
        {
          r_print("TEXT");
          r = r - (text_base);
        }
        print_int(r);
        print_char(')');
        c = right_paren_class;
      }
      else if (r < 1)
        if (r == 0)
        {
          if (cclass == left_bracket_class)
            print_char(' ');
          r_print("[]");
          c = right_bracket_class;
        }
        else
          r_print(" IMPOSSIBLE");
      else
      {
        r = text(r);
        if ((r < 0) || (r >= str_ptr))
          r_print(" NONEXISTENT");
        else
        {
          c = char_class[str_pool[str_start[r]]];
          if (c == cclass)
          {
            switch (c)
            {
              case letter_class:
                print_char('.');
                break;
              case isolated_classes:
                do_nothing();
                break;
              default:
                print_char(' ');
                break;
            }
          }
          slow_print(r);
        }
      }
    }
    cclass = c;
    p = link(p);
  }
  if (p != null)
    r_print(" ETC.");
  l_exit:;
}
/* 665 */
void runaway (void)
{
  if (scanner_status > flushing)
  {
    r_print_nl("Runaway ");
    switch (scanner_status)
    {
      case absorbing:
        r_print("text?");
        break;
      case var_defining:
      case op_defining:
        r_print("definition?");
        break;
      case loop_defining:
        r_print("loop?");
        break;
    }
    print_ln();
    show_token_list(link(hold_head), null, error_line - 10, 0);
  }
}
/* 163 */
pointer get_avail (void)
{
  pointer p;
  
  p = avail;
  if (p != null)
    avail = link(avail);
  else if (mem_end < mem_max)
  {
    incr(mem_end);
    p = mem_end;
  }
  else
  {
    decr(hi_mem_min);
    p = hi_mem_min;
    if (hi_mem_min <= lo_mem_max)
    {
      runaway();
      overflow("main memory size", mem_max + 1 - mem_min);
    }
  }
  link(p) = null;
#ifdef STAT
  incr(dyn_used);
#endif
  return p;
}
/* 167 */
pointer get_node (integer s)
{
  pointer Result;
  pointer p;
  pointer q;
  integer r;
  integer t, tt;
  
l_restart:
  p = rover;
  do {
    q = p + node_size(p);
    while (is_empty(q))
    {
      t = rlink(q);
      tt = llink(q);
      if (q == rover)
        rover = t;
      llink(t) = tt;
      rlink(tt) = t;
      q = q + node_size(q);
    }
    r = q - s;
    if (r > p + 1)
    {
      node_size(p) = r - p;
      rover = p;
      goto found;
    }
    if (r == p)
      if (rlink(p) != p)
      {
        rover = rlink(p);
        t = llink(p);
        llink(rover) = t;
        rlink(t) = rover;
        goto found;
      }
    node_size(p) = q - p;
    p = rlink(p);
  } while (!(p == rover));
  if (s == 010000000000)
  {
    Result = max_halfword;
    goto l_exit;
  }
  if (lo_mem_max + 2 < hi_mem_min)
    if (lo_mem_max + 2 <= mem_min + max_halfword)
    {
      if (hi_mem_min - lo_mem_max >= 1998)
        t = lo_mem_max + 1000;
      else
        t = lo_mem_max + 1 + (hi_mem_min - lo_mem_max) / 2;
      if (t > mem_min + max_halfword)
        t = mem_min + max_halfword;
      p = llink(rover);
      q = lo_mem_max;
      rlink(p) = q;
      llink(rover) = q;
      rlink(q) = rover;
      llink(q) = p;
      link(q) = empty_flag;
      node_size(q) = t - lo_mem_max;
      lo_mem_max = t;
      link(lo_mem_max) = null;
      info(lo_mem_max) = null;
      rover = q;
      goto l_restart;
    }
  overflow("main memory size", mem_max + 1 - mem_min);
found:
  link(r) = null;
#ifdef STAT
  var_used = var_used + s;
#endif
  Result = r;
l_exit:;
  return Result;
}
/* 172 */
void free_node (pointer p, halfword s)
{
  pointer q;

  node_size(p) = s;
  link(p) = empty_flag;
  q = llink(rover);
  llink(p) = q;
  rlink(p) = rover;
  llink(rover) = p;
  rlink(q) = p;
#ifdef STAT
  var_used = var_used - s;
#endif
}
/* 173 */
void sort_avail (void)
{
  pointer p, q, r;
  pointer old_rover;

  p = get_node(010000000000);
  p = rlink(rover);
  rlink(rover) = max_halfword;
  old_rover = rover;
  while (p != old_rover)
  {
    if (p < rover)
    {
      q = p;
      p = rlink(q);
      rlink(q) = rover;
      rover = q;
    }
    else
    {
      q = rover;
      while (rlink(q) < p)
        q = rlink(q);
      r = rlink(p);
      rlink(p) = rlink(q);
      rlink(q) = p;
      p = r;
    }
  }
  p = rover;
  while (rlink(p) != max_halfword)
  {
    llink(rlink(p)) = p;
    p = rlink(p);
  }
  rlink(p) = rover;
  llink(rover) = p;
}
/* 177 */
void flush_list (pointer p)
{
  pointer q, r;

  if (p >= hi_mem_min)
    if (p != sentinel)
    {
      r = p;
      do {
        q = r;
        r = link(r);
#ifdef STAT
        decr(dyn_used);
#endif
        if (r < hi_mem_min)
          goto done;
      } while (!(r == sentinel));
    done:
      link(q) = avail;
      avail = p;
    }
}
/* 177 */
void flush_node_list (pointer p)
{
  pointer q;

  while (p != null)
  {
    q = p;
    p = link(p);
    if (q < hi_mem_min)
      free_node(q, 2);
    else
      free_avail(q);
  }
}
/* 180 */
#ifdef DEBUG
void check_mem (boolean print_locs)
{
  pointer p, q, r;
  boolean clobbered;
  
  for (p = 0; p <= lo_mem_max; p++)
    freearr[p] = false;
  for (p = hi_mem_min; p <= mem_end; p++)
    freearr[p] = false;
  p = avail;
  q = null;
  clobbered = false;
  while (p != null)
  {
    if ((p > mem_end) || (p < hi_mem_min))
      clobbered = true;
    else if (freearr[p])
      clobbered = true;
    if (clobbered)
    {
      print_nl(("AVAIL list clobbered at ");
      print_int(q);
      goto done1;
    }
    freearr[p] = true;
    q = p;
    p = link(q);
  }
done1:;
  p = rover;
  q = null;
  clobbered = false;
  do {
    if ((p >= lo_mem_max) || (p < mem_min))
      clobbered = true;
    else if ((rlink(p) >= lo_mem_max) || (rlink(p) < mem_min))
      clobbered = true;
    else if (!(is_empty(p)) || (node_size(p) < 2) || (p + node_size(p) > lo_mem_max) || (llink(rlink(p)) != p))
      clobbered = true;
    if (clobbered)
    {
      r_print_nl("Double-AVAIL list clobbered at ");
      print_int(q);
      goto done2;
    }
    for (q = p; q <= p + node_size(p) - 1; q++)
    {
      if (freearr[q])
      {
        r_print_nl("Doubly free location at ");
        print_int(q);
        goto done2;
      }
      freearr[q] = true;
    }
    q = p;
    p = rlink(p);
  } while (!(p == rover));
done2:;
  p = mem_min;
  while (p <= lo_mem_max)
  {
    if (is_empty(p))
    {
      r_print_nl("Bad flag at ");
      print_int(p);
    }
    while ((p <= lo_mem_max) && !freearr[p])
      incr(p);
    while ((p <= lo_mem_max) && freearr[p])
      incr(p);
  }
  q = dep_head;
  p = link(q);
  while (p != dep_head)
  {
    if (prev_dep(p) != q)
    {
      r_print_nl("Bad PREVDEP at ");
      print_int(p);
    }
    p = dep_list(p);
    r = inf_val;
    do {
      if (value(info(p)) >= value(r))
      {
        r_print_nl("Out of order at ");
        print_int(p);
      }
      r = info(p);
      q = p;
      p = link(q);
    } while (!(r == null));
  }
  if (print_locs)
  {
    r_print_nl("New busy locs:");
    for (p = mem_min; p <= lo_mem_max; p++)
    {
      if (!freearr[p] && ((p > was_lo_max) || was_free[p]))
      {
        print_char(' ');
        print_int(p);
      }
    }
    for (p = hi_mem_min; p <= mem_end; p++)
    {
      if (!freearr[p]&& ((p < was_hi_min) || (p > was_mem_end) || was_free[p]))
      {
        print_char(' ');
        print_int(p);
      }
    }
  }
  for (p = 0; p <= lo_mem_max; p++)
    was_free[p] = freearr[p];
  for (p = hi_mem_min; p <= mem_end; p++)
    was_free[p] = freearr[p];
  was_mem_end = mem_end;
  was_lo_max = lo_mem_max;
  was_hi_min = hi_mem_min;
}
#endif
/* 185 */
#ifdef DEBUG
void search_mem (pointer p)
{
  integer q;

  for (q = 0; q <= lo_mem_max; q++)
  {
    if (link(q) == p)
    {
      r_print_nl("LINK(");
      print_int(q);
      print_char(')');
    }
    if (info(q) == p)
    {
      r_print_nl("INFO(");
      print_int(q);
      print_char(')');
    }
  }
  for (q = hi_mem_min; q <= mem_end; q++)
  {
    if (link(q) == p)
    {
      r_print_nl("LINK(");
      print_int(q);
      print_char(')');
    }
    if (info(q) == p)
    {
      r_print_nl("INFO(");
      print_int(q);
      print_char(')');
    }
  }
  for (q = 1; q <= hash_end; q++)
  {
    if (equiv(q) == p)
    {
      r_print_nl("EQUIV(");
      print_int(q);
      print_char(')');
    }
  }
}
#endif
/* 189 */
void print_op (quarterword c)
{
  if (c <= numeric_type)
    print_type(c);
  else
    switch (c)
    {
      case true_code:
        r_print("true");
        break;
      case false_code:
        r_print("false");
        break;
      case null_picture_code:
        r_print("nullpicture");
        break;
      case null_pen_code:
        r_print("nullpen");
        break;
      case job_name_op:
        r_print("jobname");
        break;
      case read_string_op:
        r_print("readstring");
        break;
      case pen_circle:
        r_print("pencircle");
        break;
      case normal_deviate:
        r_print("normaldeviate");
        break;
      case odd_op:
        r_print("odd");
        break;
      case known_op:
        r_print("known");
        break;
      case unknown_op:
        r_print("unknown");
        break;
      case not_op:
        r_print("not");
        break;
      case decimal:
        r_print("decimal");
        break;
      case reverse:
        r_print("reverse");
        break;
      case make_path_op:
        r_print("makepath");
        break;
      case make_pen_op:
        r_print("makepen");
        break;
      case total_weight_op:
        r_print("totalweight");
        break;
      case oct_op:
        r_print("oct");
        break;
      case hex_op:
        r_print("hex");
        break;
      case ASCII_op:
        r_print("ASCII");
        break;
      case char_op:
        r_print("char");
        break;
      case length_op:
        r_print("length");
        break;
      case turning_op:
        r_print("turningnumber");
        break;
      case x_part:
        r_print("xpart");
        break;
      case y_part:
        r_print("ypart");
        break;
      case xx_part:
        r_print("xxpart");
        break;
      case xy_part:
        r_print("xypart");
        break;
      case yx_part:
        r_print("yxpart");
        break;
      case yy_part:
        r_print("yypart");
        break;
      case sqrt_op:
        r_print("sqrt");
        break;
      case m_exp_op:
        r_print("mexp");
        break;
      case m_log_op:
        r_print("mlog");
        break;
      case sin_d_op:
        r_print("sind");
        break;
      case cos_d_op:
        r_print("cosd");
        break;
      case floor_op:
        r_print("floor");
        break;
      case uniform_deviate:
        r_print("uniformdeviate");
        break;
      case char_exists_op:
        r_print("charexists");
        break;
      case angle_op:
        r_print("angle");
        break;
      case cycle_op:
        r_print("cycle");
        break;
      case plus:
        print_char('+');
        break;
      case minus:
        print_char('-');
        break;
      case times:
        print_char('*');
        break;
      case over:
        print_char('/');
        break;
      case pythag_add:
        r_print("++");
        break;
      case pythag_sub:
        r_print("+-+");
        break;
      case or_op:
        r_print("or");
        break;
      case and_op:
        r_print("and");
        break;
      case less_than:
        print_char('<');
        break;
      case less_or_equal:
        r_print("<=");
        break;
      case greater_than:
        print_char(">");
        break;
      case greater_or_equal:
        r_print(">=");
        break;
      case equal_to:
        print_char("=");
        break;
      case unequal_to:
        r_print("<>");
        break;
      case concatenate:
        r_print("&");
        break;
      case rotated_by:
        r_print("rotated");
        break;
      case slanted_by:
        r_print("slanted");
        break;
      case scaled_by:
        r_print("scaled");
        break;
      case shifted_by:
        r_print("shifted");
        break;
      case transformed_by:
        r_print("transformed");
        break;
      case x_scaled:
        r_print("xscaled");
        break;
      case y_scaled:
        r_print("yscaled");
        break;
      case z_scaled:
        r_print("zscaled");
        break;
      case intersect:
        r_print("intersectiontimes");
        break;
      case substring_of:
        r_print("substring");
        break;
      case subpath_of:
        r_print("subpath");
        break;
      case direction_time_of:
        r_print("directiontime");
        break;
      case point_of:
        r_print("point");
        break;
      case precontrol_of:
        r_print("precontrol");
        break;
      case postcontrol_of:
        r_print("postcontrol");
        break;
      case pen_offset_of:
        r_print("penoffset");
        break;
      default:
        r_print("..");
        break;
  }
}
/* 194 */
void fix_date_and_time (void)
{
  date_and_time(internal[time], internal[day], internal[month], internal[year]);
  internal[time] = internal[time] * unity;
  internal[day] = internal[day] * unity;
  internal[month] = internal[month] * unity;
  internal[year] = internal[year] * unity;
}
/* 205 */
pointer id_lookup (integer j, integer l)
{
  integer h;
  pointer p;
  pointer k;
  
  if (l == 1)
  {
    p = buffer[j] + 1;
    text(p) = p - 1;
    goto found;
  }
  h = buffer[j];
  for (k = j + 1; k <= j + l - 1; k++)
  {
    h = h + h + buffer[k];
    while (h >= hash_prime)
      h = h - hash_prime;
  }
  p = h + hash_base;
  while (true)
  {
    if (text(p) > 0)
      if (length(text(p)) == l)
      {
        if (str_eq_buf(text(p), j))
          goto found;
      }
    if (next(p) == 0)
    {
      if (text(p) > 0)
      {
        do {
          if (hash_is_full)
            overflow("hash size", hash_size);
          decr(hash_used);
        } while (!(text(hash_used) == 0));
        next(p) = hash_used;
        p = hash_used;
      }
      str_room(l);
      for (k = j; k <= j + l - 1; k++)
        append_char(buffer[k]);
      text(p) = make_string();
      str_ref[text(p)] = max_str_ref;
#ifdef STAT
      incr(st_count);
#endif
      goto found;
    }
    p = next(p);
  }
found:
  return p;
}
/* 210 */
void primitive (str_number s, halfword c, halfword o)
{
  pool_pointer k;
  small_number j;
  small_number l;

  k = str_start[s];
  l = str_start[s + 1] - k;
  for (j = 0; j < l - 1; j++)
    buffer[j] = so(str_pool[k + j]);
  cur_sym = id_lookup(0, l);
  if (s >= 256)
  {
    flush_string(str_ptr - 1);
    text(cur_sym) = s;
  }
  eq_type(cur_sym) = c;
  equiv(cur_sym) = o;
}
/* 215 */
pointer new_num_tok (scaled v)
{
  pointer p;

  p = get_node(token_node_size);
  value(p) = v;
  type(p) = known;
  name_type(p) = token;
  return p;
}
/* 216 */
void token_recycle(void);
void flush_token_list (pointer p)
{
  pointer q;

  while (p != null)
  {
    q = p;
    p = link(p);
    if (q >= hi_mem_min)
      free_avail(q);
    else
    {
      switch (type(q))
      {
        case vacuous:
        case boolean_type:
        case known:
          do_nothing();
          break;
        case string_type:
          delete_str_ref(value(q));
          break;
        case unknown_types:
        case pen_type:
        case path_type:
        case future_pen:
        case picture_type:
        case pair_type:
        case transform_type:
        case dependent:
        case proto_dependent:
        case independent:
          {
            g_pointer = q;
            token_recycle();
          }
          break;
        default:
          confusion("token");
          break;
      }
      free_node(q, token_node_size);
    }
  }
}
/* 226 */
void delete_mac_ref (pointer p)
{
  if (ref_count(p) == null)
    flush_token_list(p);
  else
    decr(ref_count(p));
}
/* 625 */
void print_cmd_mod (integer c, integer m)
{
  switch (c)
  {
    case add_to_command:
      r_print("addto");
      break;
    case assignment:
      r_print(":=");
      break;
    case at_least:
      r_print("atleast");
      break;
    case at_token:
      r_print("at");
      break;
    case bchar_label:
      r_print("||:");
      break;
    case begin_group:
      r_print("begingroup");
      break;
    case colon:
      r_print(":");
      break;
    case comma:
      r_print(",");
      break;
    case controls:
      r_print("controls");
      break;
    case cull_command:
      r_print("cull");
      break;
    case curl_command:
      r_print("curl");
      break;
    case delimiters:
      r_print("delimiters");
      break;
    case display_command:
      r_print("display");
      break;
    case double_colon:
      r_print("::");
      break;
    case end_group:
      r_print("endgroup");
      break;
    case every_job_command:
      r_print("everyjob");
      break;
    case exit_test:
      r_print("exitif");
      break;
    case expand_after:
      r_print("expandafter");
      break;
    case from_token:
      r_print("from");
      break;
    case in_window:
      r_print("inwindow");
      break;
    case interim_command:
      r_print("interim");
      break;
    case left_brace:
      r_print("{");
      break;
    case left_bracket:
      r_print("[");
      break;
    case let_command:
      r_print("let");
      break;
    case new_internal:
      r_print("newinternal");
      break;
    case of_token:
      r_print("of");
      break;
    case open_window:
      r_print("openwindow");
      break;
    case path_join:
      r_print("..");
      break;
    case random_seed:
      r_print("randomseed");
      break;
    case relax:
      print_char("\\");
      break;
    case right_brace:
      r_print("}");
      break;
    case right_bracket:
      r_print("]");
      break;
    case save_command:
      r_print("save");
      break;
    case scan_tokens:
      r_print("scantokens");
      break;
    case semicolon:
      r_print(";");
      break;
    case ship_out_command:
      r_print("shipout");
      break;
    case skip_to:
      r_print("skipto");
      break;
    case step_token:
      r_print("step");
      break;
    case str_op:
      r_print("str");
      break;
    case tension:
      r_print("tension");
      break;
    case to_token:
      r_print("to");
      break;
    case until_token:
      r_print("until");
      break;
    case macro_def:
      if (m <= var_def)
        if (m == start_def)
          r_print("def");
        else if (m < start_def)
          r_print("enddef");
        else
          r_print("vardef");
      else if (m == secondary_primary_macro)
        r_print("primarydef");
      else if (m == tertiary_secondary_macro)
        r_print("secondarydef");
      else
        r_print("tertiarydef");
      break;
    case iteration:
      if (m <= start_forever)
        if (m == start_forever)
          r_print("forever");
        else
          r_print("endfor");
      else
        if (m == expr_base)
          r_print("for");
        else
          r_print("forsuffixes");
      break;
    case macro_special:
      switch (m)
      {
        case macro_prefix:
          r_print("#@");
          break;
        case macro_at:
          print_char("@");
          break;
        case macro_suffix:
          r_print("@#");
          break;
        default:
          r_print("quote");
          break;
      }
      break;
    case param_type:
      if (m >= expr_base)
        if (m == expr_base)
          r_print("expr");
        else if (m == suffix_base)
          r_print("suffix");
        else
          r_print("text");
      else if (m < secondary_macro)
        r_print("primary");
      else if (m == secondary_macro)
        r_print("secondary");
      else
        r_print("tertiary");
      break;
    case input:
      if (m == 0)
        r_print("input");
      else
        r_print("endinput");
      break;
    case if_test:
    case fi_or_else:
      switch (m)
      {
        case if_code:
          r_print("if");
          break;
        case fi_code:
          r_print("fi");
          break;
        case else_code:
          r_print("else");
          break;
        default:
          r_print("elseif");
          break;
      }
      break;
    case nullary:
    case unary:
    case primary_binary:
    case secondary_binary:
    case tertiary_binary:
    case expression_binary:
    case cycle:
    case plus_or_minus:
    case slash:
    case ampersand:
    case equals:
    case and_command:
      print_op(m);
      break;
    case type_name:
      print_type(m);
      break;
    case stop:
      if (m == 0)
        r_print("end");
      else
        r_print("dump");
      break;
    case mode_command:
      switch (m)
      {
        case batch_mode:
          r_print("batchmode");
          break;
        case nonstop_mode:
          r_print("nonstopmode");
          break;
        case scroll_mode:
          r_print("scrollmode");
          break;
        default:
          r_print("errorstopmode");
          break;
      }
      break;
    case protection_command:
      if (m == 0)
        r_print("inner");
      else
        r_print("outer");
      break;
    case show_command:
      switch (m)
      {
        case show_token_code:
          r_print("showtoken");
          break;
        case show_stats_code:
          r_print("showstats");
          break;
        case show_code:
          r_print("show");
          break;
        case show_var_code:
          r_print("showvariable");
          break;
        default:
          r_print("showdependencies");
          break;
      }
      break;
    case left_delimiter:
    case right_delimiter:
      {
        if (c == left_delimiter)
          r_print("lef");
        else
          r_print("righ");
        r_print("t delimiter that matches ");
        slow_print(text(m));
      }
      break;
    case tag_token:
      if (m == null)
        r_print("tag");
      else
        r_print("variable");
      break;
    case defined_macro:
      r_print("macro:");
      break;
    case secondary_primary_macro:
    case tertiary_secondary_macro:
    case expression_tertiary_macro:
      {
        print_cmd_mod(macro_def, c);
        r_print("'d macro:");
        print_ln();
        show_token_list(link(link(m)), null, 1000, 0);
      }
      break;
    case repeat_loop:
      r_print("[repeat the loop]");
      break;
    case internal_quantity:
      slow_print(int_name[m]);
      break;
    case thing_to_add:
      if (m == contour_code)
        r_print("contour");
      else if (m == double_path_code)
        r_print("doublepath");
      else
        r_print("also");
      break;
    case with_option:
      if (m == pen_type)
        r_print("withpen");
      else
        r_print("withweight");
      break;
    case cull_op:
      if (m == drop_code)
        r_print("dropping");
      else
        r_print("keeping");
      break;
    case message_command:
      if (m < err_message_code)
        r_print("message");
      else if (m == err_message_code)
        r_print("errmessage");
      else
        r_print("errhelp");
      break;
    case tfm_command:
      switch (m)
      {
        case char_list_code:
          r_print("charlist");
          break;
        case lig_table_code:
          r_print("ligtable");
          break;
        case extensible_code:
          r_print("extensible");
          break;
        case header_byte_code:
          r_print("headerbyte");
          break;
        default:
          r_print("fontdimen");
          break;
      }
      break;
    case lig_kern_token:
      switch (m)
      {
        case 0:
          r_print("=:");
          break;
        case 1:
          r_print("=:|");
          break;
        case 2:
          r_print("|=:");
          break;
        case 3:
          r_print("|=:|");
          break;
        case 5:
          r_print("=:|>");
          break;
        case 6:
          r_print("|=:>");
          break;
        case 7:
          r_print("|=:|>");
          break;
        case 11:
          r_print("|=:|>>");
          break;
        default:
          r_print("kern");
          break;
      }
      break;
    case special_command:
      if (m == known)
        r_print("numspecial");
      else
        r_print("special");
      break;
    default:
      r_print("[unknown command code!]");
      break;
  }
}
/* 227 */
void show_macro (pointer p, integer q, integer l)
{
  pointer r;

  p = link(p);
  while (info(p) > text_macro)
  {
    r = link(p);
    link(p) = null;
    show_token_list(p, null, l, 0);
    link(p) = r;
    p = r;
    if (l > 0)
      l = l - tally;
    else
      goto l_exit;
  }
  tally = 0;
  switch (info(p))
  {
    case general_macro:
      r_print("->");
      break;
    case primary_macro:
    case secondary_macro:
    case tertiary_macro:
      {
        print_char("<");
        print_cmd_mod(param_type, info(p));
        r_print(">->");
      }
      break;
    case expr_macro:
      r_print("<expr>->");
      break;
    case of_macro:
      r_print("<expr>of<primary>->");
      break;
    case suffix_macro:
      r_print("<suffix>->");
      break;
    case text_macro:
      r_print("<text>->");
      break;
  }
  show_token_list(link(p), q, l - tally, 0);
l_exit:;
}
/* 232 */
void init_big_node (pointer p)
{
  pointer q;
  small_number s;

  s = big_node_size[type(p)];
  q = get_node(s);
  do {
    s = s - 2;
    new_indep(q + s);
    name_type(q + s) = half(s) + x_part_sector;
    link(q + s) = null;
  } while (!(s == 0));
  link(q) = p;
  value(p) = q;
}
/* 233 */
pointer id_transform (void)
{
  pointer p, q, r;
  
  p = get_node(value_node_size);
  type(p) = transform_type;
  name_type(p) = capsule;
  value(p) = null;
  init_big_node (p);
  q = value(p);
  r = q + transform_node_size;
  do {
    r = r - 2;
    type(r) = known;
    value(r) = 0;
  } while (!(r == q));
  value(xx_part_loc(q)) = unity;
  value(yy_part_loc(q)) = unity;
  return p;
}
/* 234 */
void new_root (pointer x)
{
  pointer p;

  p = get_node(value_node_size);
  type(p) = undefined;
  name_type(p) = root;
  link(p) = x;
  equiv(x) = p;
}
/* 235 */
void print_variable_name (pointer p)
{
  pointer q;
  pointer r;

  while (name_type(p) >= x_part_sector)
  {
    switch (name_type(p))
    {
      case x_part_sector:
        print_char('x');
        break;
      case y_part_sector:
        print_char('y');
        break;
      case xx_part_sector:
        r_print("xx");
        break;
      case xy_part_sector:
        r_print("xy");
        break;
      case yx_part_sector:
        r_print("yx");
        break;
      case yy_part_sector:
        r_print("yy");
        break;
      case capsule:
        {
          r_print("%CAPSULE");
          print_int(p - null);
          goto l_exit;
        }
        break;
    }
    r_print("part ");
    p = link(p - 2 * (name_type(p) - x_part_sector));
  }
  q = null;
  while (name_type(p) > saved_root)
  {
    if (name_type(p) == subscr)
    {
      r = new_num_tok(subscript(p));
      do {
        p = link(p);
      } while (!(name_type(p) == attr));
    }
    else if (name_type(p) == structured_root)
    {
      p = link(p);
      goto found;
    }
    else
    {
      if (name_type(p) != attr)
        confusion("var");
      r = get_avail();
      info(r) = attr_loc(p);
    }
    link(r) = q;
    q = r;
found:
	 	p = parent(p);
  }
  r = get_avail();
  info(r) = link(p);
  link(r) = q;
  if (name_type(p) == saved_root)
    r_print("(SAVED)");
  show_token_list(r, null, el_gordo, tally);
  flush_token_list(r);
l_exit:;
}
/* 238 */
boolean interesting (pointer p)
{
  small_number t;

  if (internal[tracing_online] > 0)
    return true;
  else
  {
    t = name_type(p);
    if (t >= x_part_sector)
      if (t != capsule)
        t = name_type(link(p - 2 * (t - x_part_sector)));
    return (t != capsule);
  }
}
/* 239 */
pointer new_structure (pointer p)
{
  pointer q, r;
  
  switch (name_type(p))
  {
    case root:
      {
        q = link(p);
        r = get_node(value_node_size);
        equiv(q) = r;
      }
      break;
    case subscr:
      {
        q = p;
        do {
          q = link(q);
        } while (!(name_type(q) == attr));
        q = parent(q);
        r = subscr_head_loc(q);
        do {
          q = r;
          r = link(r);
        } while (!(r == p));
        r = get_node(subscr_node_size);
        link(q) = r;
        subscript(r) = subscript(p);
      }
      break;
    case attr:
      {
        q = parent(p);
        r = attr_head(q);
        do {
          q = r;
          r = link(r);
        } while (!(r == p));
        r = get_node(attr_node_size);
        link(q) = r;
        mem[attr_loc_loc(r)] = mem[attr_loc_loc(p)];
        if (attr_loc(p) == collective_subscript)
        {
          q = subscr_head_loc(parent(p));
          while (link(q) != p)
            q = link(q);
          link(q) = r;
        }
      }
      break;
    default:
      confusion("struct");
      break;
  }
  link(r) = link(p);
  type(r) = structured;
  name_type(r) = name_type(p);
  attr_head(r) = p;
  name_type(p) = structured_root;
  q = get_node(attr_node_size);
  link(p) = q;
  subscr_head(r) = q;
  parent(q) = r;
  type(q) = undefined;
  name_type(q) = attr;
  link(q) = end_attr;
  attr_loc(q) = collective_subscript;
  return r;
}
/* 242 */
pointer find_variable (pointer t)
{
  pointer Result;
  pointer p, q, r, s;
  pointer pp, qq, rr, ss;
  integer n;
  memory_word save_word;
  
  p = info(t);
  t = link(t);
  if (eq_type(p) % outer_tag != tag_token)
    abort_find();
  if (eq_type(p) == null)
    new_root(p);
  p = equiv(p);
  pp = p;
  while (t != null)
  {
    if (type(pp) != structured)
    {
      if (type(pp) > structured)
        abort_find();
      ss = new_structure(pp);
      if (p == pp)
        p = ss;
      pp = ss;
    }
    if (type(p) != structured)
      p = new_structure(p);
    if (t < hi_mem_min)
    {
      n = value(t);
      pp = link(attr_head(pp));
      q = link(attr_head(p));
      save_word = mem[subscript_loc(q)];
      subscript(q) = el_gordo;
      s = subscr_head_loc(p);
      do {
        r = s;
        s = link(s);
      } while (!(n <= subscript(s)));
      if (n == subscript(s))
        p = s;
      else
      {
        p = get_node(subscr_node_size);
        link(r) = p;
        link(p) = s;
        subscript(p) = n;
        name_type(p) = subscr;
        type(p) = undefined;
      }
      mem[subscript_loc(q)] = save_word;
    }
    else
    {
      n = info(t);
      ss = attr_head(pp);
      do {
        rr = ss;
        ss = link(ss);
      } while (!(n <= attr_loc(ss)));
      if (n < attr_loc(ss))
      {
        qq = get_node(attr_node_size);
        link(rr) = qq;
        link(qq) = ss;
        attr_loc(qq) = n;
        name_type(qq) = attr;
        type(qq) = undefined;
        parent(qq) = pp;
        ss = qq;
      }
      if (p == pp)
      {
        p = ss;
        pp = ss;
      }
      else
      {
        pp = ss;
        s = attr_head(p);
        do {
          r = s;
          s = link(s);
        } while (!(n <= attr_loc(s)));
        if (n == attr_loc(s))
          p = s;
        else
        {
          q = get_node(attr_node_size);
          link(r) = q;
          link(q) = s;
          attr_loc(q) = n;
          name_type(q) = attr;
          type(q) = undefined;
          parent(q) = p;
          p = q;
        }
      }
    }
    t = link(t);
  }
  if (type(pp) >= structured)
    if (type(pp) == structured)
      pp = attr_head(pp);
    else
      abort_find();
  if (type(p) == structured)
    p = attr_head(p);
  if (type(p) == undefined)
  {
    if (type(pp) == undefined)
    {
      type(pp) = numeric_type;
      value(pp) = null;
    }
    type(p) = type(pp);
    value(p) = null;
  }
  Result = p;
l_exit:;
  return Result;
}
/* 257 */
void print_path (pointer h, str_number s, boolean nuline)
{
  pointer p, q;

  print_diagnostic("Path", s, nuline);
  print_ln();
  p = h;
  do {
    q = link(p);
    if ((p == null) || (q == null))
    {
      r_print_nl("???");
      goto done;
    }
    print_two(x_coord(p), y_coord(p));
    switch (right_type(p))
    {
      case endpoint:
        {
          if (left_type(p) == open)
            r_print("{open?}");
          if ((left_type(q) != endpoint) || (q != h))
            q = null;
          goto done1;
        }
        break;
      case explicit:
        {
          r_print("..controls ");
          print_two(right_x(p), right_y(p));
          r_print(" and ");
          if (left_type(q) != explicit)
            r_print("??");
          else
            print_two(left_x(q), left_y(q));
          goto done1;
        }
        break;
      case open:
        if ((left_type(p) != explicit) && (left_type(p) != open))
          r_print("{open?}");
        break;
      case curl:
      case given:
        {
          if (left_type(p) == open)
            r_print("??");
          if (right_type(p) == curl)
          {
            r_print("{curl ");
            print_scaled(right_curl(p));
          }
          else
          {
            n_sin_cos(right_given(p));
            print_char('{');
            print_scaled(n_cos);
            print_char(',');
            print_scaled(n_sin);
          }
          print_char('}');
        }
        break;
      default:
        r_print("???");
        break;
    }
    if (left_type(q) <= explicit)
      r_print("..control?");
    else if ((right_tension(p) != unity) || (left_tension(q) != unity))
    {
      r_print("..tension ");
      if (right_tension(p) < 0)
        r_print("atleast");
      print_scaled(abs(right_tension(p)));
      if (right_tension(p) != left_tension(q))
      {
        r_print(" and ");
        if (left_tension(q) < 0)
          r_print("atleast");
        print_scaled(abs(left_tension(q)));
      }
    }
done1:
    p = q;
    if ((p != h) || (left_type(h) != endpoint))
    {
      r_print_nl(" ..");
      if (left_type(p) == given)
      {
        n_sin_cos(left_given(p));
        print_char('{');
        print_scaled(n_cos);
        print_char(',');
        print_scaled(n_sin);
        print_char('}');
      }
      else if (left_type(p) == curl)
      {
        r_print("{curl ");
        print_scaled(left_curl(p));
        print_char('}');
      }
    }
  } while (!(p == h));
  if (left_type(h) != endpoint)
    r_print("cycle");
done:
  end_diagnostic(true);
}
/* 333 */
void print_weight (pointer q, integer x_off)
{
  integer w, m;
  integer d;

  d = ho(info(q));
  w = d % 8;
  m = (d / 8) - m_offset(cur_edges);
  if (file_offset > max_print_line - 9)
    print_nl(' ');
  else
    print_char(' ');
  print_int(m + x_off);
  while (w > zero_w)
  {
    print_char('+');
    decr(w);
  }
  while (w < zero_w)
  {
    print_char('-');
    incr(w);
  }
}
/* 332 */
void print_edges (str_number s, boolean nuline, integer x_off, integer y_off)
{
  pointer p, q, r;
  integer n;

  print_diagnostic("Edge structure", s, nuline);
  p = knil(cur_edges);
  n = n_max(cur_edges) - zero_field;
  while (p != cur_edges)
  {
    q = unsorted(p);
    r = sorted(p);
    if ((q > _void) || (r != sentinel))
    {
      r_print_nl("row ");
      print_int(n + y_off);
      print_char(':');
      while (q > _void)
      {
        print_weight(q, x_off);
        q = link(q);
      }
      r_print(" |");
      while (r != sentinel)
      {
        print_weight(r, x_off);
        r = link(r);
      }
    }
    p = knil(p);
    decr(n);
  }
  end_diagnostic(true);
}
/* 388 */
void unskew (scaled x, scaled y, small_number octant)
{
  switch (octant)
  {
    case first_octant:
      set_two(x + y, y);
      break;
    case second_octant:
      set_two(y, x + y);
      break;
    case third_octant:
      set_two(-y, x + y);
      break;
    case fourth_octant:
      set_two(-x - y, y);
      break;
    case fifth_octant:
      set_two(-x - y, -y);
      break;
    case sixth_octant:
      set_two(-y, -x - y);
      break;
    case seventh_octant:
      set_two(y, -x - y);
      break;
    case eighth_octant:
      set_two(x + y, -y);
      break;
  }
}
/* 473 */
void print_pen (pointer p, str_number s, boolean nuline)
{
  boolean nothing_printed;
  unsigned char k;
  pointer h;
  integer m, n;
  pointer w, ww;

  print_diagnostic("Pen polygon", s, nuline);
  nothing_printed = true;
  print_ln();
  for (k = 1; k <= 8; k++)
  {
    octant = octant_code[k];
    h = p + octant;
    n = info(h);
    w = link(h);
    if (!odd(k))
      w = knil(w);
    for (m = 1; m <= n + 1; m++)
    {
      if (odd(k))
        ww = link(w);
      else
        ww = knil(w);
      if ((x_coord(ww) != x_coord(w)) || (y_coord(ww) != y_coord(w)))
      {
        if (nothing_printed)
          nothing_printed = false;
        else
          r_print_nl(" .. ");
        print_two_true(x_coord(ww), y_coord(ww));
      }
      w = ww;
    }
  }
  if (nothing_printed)
  {
    w = link(p + first_octant);
    print_two(x_coord(w) + y_coord(w), y_coord(w));
  }
  r_print_nl(" .. cycle");
  end_diagnostic(true);
}
/* 589 */
void print_dependency (pointer p, small_number t)
{
  integer v;
  pointer pp, q;

  pp = p;
  while (true)
  {
    v = abs(value(p));
    q = info(p);
    if (q == null)
    {
      if ((v != 0) || (p == pp))
      {
        if (value(p) > 0)
          if (p != pp)
            print_char('+');
        print_scaled(value(p));
      }
      goto l_exit;
    }
    if (value(p) < 0)
      print_char('-');
    else if (p != pp)
      print_char('+');
    if (t == dependent)
      v = round_fraction(v);
    if (v != unity)
      print_scaled(v);
    if (type(q) != independent)
      confusion("dep");
    print_variable_name(q);
    v = value(q) % s_scale;
    while (v > 0)
    {
      r_print("*4");
      v = v - 2;
    }
    p = link(p);
  }
  l_exit:;
}
/* 805 */
void print_dp (small_number t, pointer p, small_number verbosity)
{
  pointer q;

  q = link(p);
  if ((info(q) == null) || (verbosity > 0))
    print_dependency(p, t);
  else
    r_print("linearform");
}
/* 799 */
pointer stash_cur_exp (void)
{
  pointer p;

  switch (cur_type)
  {
    case unknown_types:
    case transform_type:
    case pair_type:
    case dependent:
    case proto_dependent:
    case independent:
      p = cur_exp;
      break;
    default:
      {
        p = get_node(value_node_size);
        name_type(p) = capsule;
        type(p) = cur_type;
        value(p) = cur_exp;
      }
      break;
  }
  cur_type = vacuous;
  link(p) = _void;
  return p;
}
/* 800 */
void unstash_cur_exp (pointer p)
{
  cur_type = type(p);
  switch (cur_type)
  {
    case unknown_types:
    case transform_type:
    case pair_type:
    case dependent:
    case proto_dependent:
    case independent:
      cur_exp = p;
      break;
    default:
      {
        cur_exp = value(p);
        free_node(p, value_node_size);
      }
      break;
  }
}
/* 801 */
void print_exp (pointer p, small_number verbosity)
{
  boolean restore_cur_exp;
  small_number t;
  integer v;
  pointer q;
  
  if (p != null)
    restore_cur_exp = false;
  else
  {
    p = stash_cur_exp();
    restore_cur_exp = true;
  }
  t = type(p);
  if (t < dependent)
    v = value(p);
  else if (t < independent)
    v = dep_list(p);
  switch (t)
  {
    case vacuous:
      r_print("vacuous");
      break;
    case boolean_type:
      if (v == true_code)
        r_print("true");
      else
        r_print("false");
      break;
    case unknown_types:
    case numeric_type:
      {
        print_type(t);
        if (v != null)
        {
          print_char(' ');
          while ((name_type(v) == capsule) && (v != p))
            v = value(v);
          print_variable_name(v);
        }
      }
      break;
    case string_type:
      {
        print_char('"');
        slow_print(v);
        print_char('"');
      }
      break;
    case pen_type:
    case future_pen:
    case path_type:
    case picture_type:
      if (verbosity <= 1)
        print_type(t);
      else
      {
        if (selector == term_and_log)
          if (internal[tracing_online] <= 0)
          {
            selector = term_only;
            print_type(t);
            r_print(" (see the transcript file)");
            selector = term_and_log;
          }
        switch (t)
        {
          case pen_type:
            print_pen(v, "", false);
            break;
          case future_pen:
            print_path(v, " (future pen)", false);
            break;
          case path_type:
            print_path(v, "", false);
            break;
          case picture_type:
            {
              cur_edges = v;
              print_edges("", false, 0, 0);
            }
            break;
        }
      }
      break;
    case transform_type:
    case pair_type:
      if (v == null)
        print_type(t);
      else
      {
        print_char('(');
        q = v + big_node_size[t];
        do {
          if (type(v) == known)
            print_scaled(value(v));
          else if (type(v) == independent)
            print_variable_name(v);
          else
            print_dp(type(v), disp_list(v), verbosity);
          v = v + 2;
          if (v != q)
            print_char(',');
        } while (!(v == q));
        print_char(')');
      }
      break;
    case known:
      print_scaled(v);
      break;
    case dependent:
    case proto_dependent:
      print_dp(t, v, verbosity);
      break;
    case independent:
      print_variable_name(p);
      break;
    default:
      confusion("exp");
      break;
  }
  if (restore_cur_exp)
    unstash_cur_exp(p);
}
/* 807 */
void disp_err (pointer p, str_number s)
{
  if (interaction == error_stop_mode)
    wake_up_terminal();
  r_print_nl(">> ");
  print_exp(p, 1);
  if (s != "")
  {
    r_print_nl("! ");
    print(s);
  }
}
/* 594 */
pointer p_plus_fq (pointer p, integer f, pointer q, small_number t, small_number tt)
{
  pointer pp, qq;
  pointer r, s;
  integer threshold;
  integer v;

  if (t == dependent)
    threshold = fraction_threshold;
  else
    threshold = scaled_threshold;
  r = temp_head;
  pp = info(p);
  qq = info(q);
  while (true)
  {
    if (pp == qq)
      if (pp == null)
        goto done;
      else
      {
        if (tt == dependent)
          v = value(p) + take_fraction(f, value(q));
        else
          v = value(p) + take_scaled(f, value(q));
        value(p) = v;
        s = p;
        p = link(p);
        if (abs(v) < threshold)
          free_node(s, dep_node_size);
        else
        {
          if (abs(v) >= coef_bound)
          {
            if (watch_coefs)
            {
              type(qq) = independent_needing_fix;
              fix_needed = true;
            }
          }
          link(r) = s;
          r = s;
        }
        pp = info(p);
        q = link(q);
        qq = info(q);
      }
    else if (value(pp) < value(qq))
    {
      if (tt == dependent)
        v = take_fraction(f, value(q));
      else
        v = take_scaled(f, value(q));
      if (abs(v) > half(threshold))
      {
        s = get_node(dep_node_size);
        info(s) = qq;
        value(s) = v;
        if (abs(v) >= coef_bound)
        {
          if (watch_coefs)
          {
            type(qq) = independent_needing_fix;
            fix_needed = true;
          }
        }
        link(r) = s;
        r = s;
      }
      q = link(q);
      qq = info(q);
    }
    else
    {
      link(r) = p;
      r = p;
      p = link(p);
      pp = info(p);
    }
  }
done:
  if (t == dependent)
    value(p) = slow_add(value(p), take_fraction(value(q), f));
  else
    value(p) = slow_add(value(p), take_scaled(value(q), f));
  link(r) = p;
  dep_final = p;
  return link(temp_head);
}
/* 600 */
pointer p_over_v (pointer p, scaled v, small_number t0, small_number t1)
{
  pointer r, s;
  integer w;
  integer threshold;
  boolean scaling_down;
  
  if (t0 != t1)
    scaling_down = true;
  else
    scaling_down = false;
  if (t1 == dependent)
    threshold = half_fraction_threshold;
  else
    threshold = half_scaled_threshold;
  r = temp_head;
  while (info(p) != null)
  {
    if (scaling_down)
      if (abs(v) < 02000000)
        w = make_scaled(value(p), v * 010000);
      else
        w = make_scaled(round_fraction(value(p)), v);
    else
      w = make_scaled(value(p), v);
    if (abs(w) <= threshold)
    {
      s = link(p);
      free_node(p, dep_node_size);
      p = s;
    }
    else
    {
      if (abs(w) >= coef_bound)
      {
        fix_needed = true;
        type(info(p)) = independent_needing_fix;
      }
      link(r) = p;
      r = p;
      value(p) = w;
      p = link(p);
    }
  }
  link(r) = p;
  value(p) = make_scaled(value(p), v);
  return link(temp_head);
}
/* 602 */
void val_too_big (scaled x)
{
  if (internal[warning_check] > 0)
  {
    print_err("Value is too large (");
    print_scaled(x);
    print_char(')');
    help4("The equation I just processed has given some variable",
      "a value of 4096 or more. Continue and I'll try to cope",
      "with that big value; but it might be dangerous.",
      "(Set warningcheck:=0 to suppress this message.)");
    error();
  }
}
/* 603 */
void make_known (pointer p, pointer q)
{
  unsigned char t;

  prev_dep(link(q)) = prev_dep(p);
  link(prev_dep(p)) = link(q);
  t = type(p);
  type(p) = known;
  value(p) = value(q);
  free_node(q, dep_node_size);
  if (abs(value(p)) >= fraction_one)
    val_too_big(value(p));
  if (internal[tracing_equations] > 0)
    if (interesting(p))
    {
      begin_diagnostic();
      r_print_nl("#### ");
      print_variable_name(p);
      print_char('=');
      print_scaled(value(p));
      end_diagnostic(false);
    }
  if (cur_exp == p)
    if (cur_type == t)
    {
      cur_type = known;
      cur_exp = value(p);
      free_node(p, value_node_size);
    }
}
/* 604 */
void fix_dependencies (void)
{
  pointer p, q, r, s, t;
  pointer x;

  r = link(dep_head);
  s = null;
  while (r != dep_head)
  {
    t = r;
    r = value_loc(t);
    while (true)
    {
      q = link(r);
      x = info(q);
      if (x == null)
        goto done;
      if (type(x) <= independent_being_fixed)
      {
        if (type(x) < independent_being_fixed)
        {
          p = get_avail();
          link(p) = s;
          s = p;
          info(s) = x;
          type(x) = independent_being_fixed;
        }
        value(q) = value(q) / 4;
        if (value(q) == 0)
        {
          link(r) = link(q);
          free_node(q, dep_node_size);
          q = r;
        }
      }
      r = q;
    }
done:;
    r = link(q);
    if (q == dep_list(t))
      make_known(t, q);
  }
  while (s != null)
  {
    p = link(s);
    x = info(s);
    free_avail(s);
    s = p;
    type(x) = independent;
    value(x) = value(x) + 2;
  }
  fix_needed = false;
}
/* 268 */
void toss_knot_list (pointer p)
{
  pointer q;
  pointer r;

  q = p;
  do {
    r = link(q);
    free_node(q, knot_node_size);
    q = r;
  } while (!(q == p));
}
/* 385 */
void toss_edges (pointer h)
{
  pointer p, q;

  q = link(h);
  while (q != h)
  {
    flush_list(sorted(q));
    if (unsorted(q) > _void)
      flush_list(unsorted(q));
    p = q;
    q = link(q);
    free_node(p, row_node_size);
  }
  free_node(h, edge_header_size);
}
/* 487 */
void toss_pen (pointer p)
{
  unsigned char k;
  pointer w, ww;

  if (p != null_pen)
  {
    for (k = 1; k <= 8; k++)
    {
      w = link(p + k);
      do {
        ww = link(w);
        free_node(w, coord_node_size);
        w = ww;
      } while (!(w == link(p + k)));
    }
    free_node(p, pen_node_size);
  }
}
/* 620 */
void ring_delete (pointer p)
{
  pointer q;

  q = value(p);
  if (q != null)
    if (q != p)
    {
      while (value(q) != p)
        q = value(q);
      value(q) = value(p);
    }
}
/* 809 */
void recycle_value (pointer p)
{
  small_number t;
  integer v;
  integer vv;
  pointer q, r, s, pp;

  t = type(p);
  if (t < dependent)
    v = value(p);
  switch (t)
  {
    case undefined:
    case vacuous:
    case boolean_type:
    case known:
    case numeric_type:
      do_nothing();
      break;
    case unknown_types:
      ring_delete(p);
      break;
    case string_type:
      delete_str_ref(v);
      break;
    case pen_type:
      delete_pen_ref(v);
      break;
    case path_type:
    case future_pen:
      toss_knot_list(v);
      break;
    case picture_type:
      toss_edges(v);
      break;
    case pair_type:
    case transform_type:
      if (v != null)
      {
        q = v + big_node_size[t];
        do {
          q = q - 2;
          recycle_value(q);
        } while (!(q == v));
        free_node(v, big_node_size[t]);
      }
      break;
    case dependent:
    case proto_dependent:
      {
        q = dep_list(p);
        while (info(q) != null)
          q = link(q);
        link(prev_dep(p)) = link(q);
        prev_dep(link(q)) = prev_dep(link(p));
        link(q) = null;
        flush_node_list(dep_list(p));
      }
      break;
    case independent:
      {
        max_c[dependent] = 0;
        max_c[proto_dependent] = 0;
        max_link[dependent] = null;
        max_link[proto_dependent] = null;
        q = link(dep_head);
        while (q != dep_head)
        {
          s = value_loc(q);
          while (true)
          {
            r = link(s);
            if (info(r) == null)
              goto done;
            if (info(r) != p)
              s = r;
            else
            {
              t = type(q);
              link(s) = link(r);
              info(r) = q;
              if (abs(value(r)) > max_c[t])
              {
                if (max_c[t] > 0)
                {
                  link(max_ptr[t]) = max_link[t];
                  max_link[t] = max_ptr[t];
                }
                max_c[t] = abs(value(r));
                max_ptr[t] = r;
              }
              else
              {
                link(r) = max_link[t];
                max_link[t] = r;
              }
            }
          }
        done:
          q = link(r);
        }
        if ((max_c[dependent] > 0) || (max_c[proto_dependent] > 0))
        {
          if ((max_c[dependent] / 010000 >= max_c[proto_dependent]))
            t = dependent;
          else
            t = proto_dependent;
          s = max_ptr[t];
          pp = info(s);
          v = value(s);
          if (t == dependent)
            value(s) = -fraction_one;
          else
            value(s) = -unity;
          r = dep_list(pp);
          link(s) = r;
          while (info(r) != null)
            r = link(r);
          q = link(r);
          link(r) = null;
          prev_dep(q) = prev_dep(pp);
          link(prev_dep(pp)) = q;
          new_indep(pp);
          if (cur_exp == pp)
            if (cur_type == t)
              cur_type = independent;
          if (internal[tracing_online] > 0)
            if (interesting(p))
            {
              begin_diagnostic();
              r_print_nl("### ");
              if (v > 0)
                print_char('-');
              if (t == dependent)
                vv = round_fraction(max_c[dependent]);
              else
                vv = max_c[proto_dependent];
              if (vv != unity)
                print_scaled(vv);
              print_variable_name(p);
              while (value(p) % s_scale > 0)
              {
                r_print("*4");
                value(p) = value(p) - 2;
              }
              if (t == dependent)
                print_char('=');
              else
                r_print(" = ");
              print_dependency(s, t);
              end_diagnostic(false);
            }
          t = dependent + proto_dependent - t;
          if (max_c[t] > 0)
          {
            link(max_ptr[t]) = max_link[t];
            max_link[t] = max_ptr[t];
          }
          if (t != dependent)
            for (t = dependent; t <= proto_dependent; t++)
            {
              r = max_link[t];
              while (r != null)
              {
                q = info(r);
                dep_list(q) = p_plus_fq(dep_list(q), make_fraction(value(r), -v), s, t, dependent);
                if (dep_list(q) == dep_final)
                  make_known(q, dep_final);
                q = r;
                r = link(r);
                free_node(q, dep_node_size);
              }
            }
          else
            for (t = dependent; t <= proto_dependent; t++)
            {
              r = max_link[t];
              while (r != null)
              {
                q = info(r);
                if (t == dependent)
                {
                  if (cur_exp == q)
                    if (cur_type == dependent)
                      cur_type = proto_dependent;
                  dep_list(q) = p_over_v(dep_list(q), unity, dependent, proto_dependent);
                  type(q) = proto_dependent;
                  value(r) = round_fraction(value(r));
                }
                dep_list(r) = p_plus_fq(dep_list(q), make_scaled(value(r), -v), s, proto_dependent, proto_dependent);
                if (dep_list(q) == dep_final)
                  make_known(q, dep_final);
                q = r;
                r = link(r);
                free_node(q, dep_node_size);
              }
            }
          flush_node_list(s);
          if (fix_needed)
            fix_dependencies();
          check_arith();
        }
      }
      break;
    case token_list:
    case structured:
      confusion("recycle");
      break;
    case unsuffixed_macro:
    case suffixed_macro:
      delete_mac_ref(value(p));
      break;
  }
  type(p) = undefined;
}
/* 808 */
void flush_cur_exp (scaled v)
{
  switch (cur_type)
  {
    case unknown_types:
    case transform_type:
    case pair_type:
    case dependent:
    case proto_dependent:
    case independent:
      {
        recycle_value(cur_exp);
        free_node(cur_exp, value_node_size);
      }
      break;
    case pen_type:
      delete_pen_ref(cur_exp);
      break;
    case string_type:
      delete_str_ref(cur_exp);
      break;
    case future_pen:
    case path_type:
      toss_knot_list(cur_exp);
      break;
    case picture_type:
      toss_edges(cur_exp);
      break;
    default:
      do_nothing();
      break;
  }
  cur_type = known;
  cur_exp = v;
}
/* 820 */
void flush_error (scaled v)
{
  error();
  flush_cur_exp(v);
}
void back_error(void);
void get_x_next(void);
/* 820 */
void put_get_error (void)
{
  back_error();
  get_x_next();
}
/* 820 */
void put_get_flush_error (scaled v)
{
  put_get_error();
  flush_cur_exp(v);
}
/* 247 */
void flush_below_variable (pointer p)
{
  pointer q, r;

  if (type(p) != structured)
    recycle_value(p);
  else
  {
    q = subscr_head(p);
    while (name_type(q) == subscr)
    {
      flush_below_variable(q);
      r = q;
      q = link(q);
      free_node(r, subscr_node_size);
    }
    r = attr_head(p);
    q = link(r);
    recycle_value(r);
    if (name_type(p) <= saved_root)
      free_node(r, value_node_size);
    else
      free_node(r, subscr_node_size);
    do {
      flush_below_variable(q);
      r = q;
      q = link(q);
      free_node(r, attr_node_size);
    } while (!(q == end_attr));
    type(p) = undefined;
  }
}
/* 246 */
void flush_variable (pointer p, pointer t, boolean discard_suffixes)
{
  pointer q, r;
  pointer n;

  while (t != null)
  {
    if (type(p) != structured)
      goto l_exit;
    n = info(t);
    t = link(t);
    if (n == collective_subscript)
    {
      r = subscr_head_loc(p);
      q = link(r);
      while (name_type(q) == subscr)
      {
        flush_variable(q, t, discard_suffixes);
        if (t == null)
          if (type(q) == structured)
            r = q;
          else
          {
            link(r) = link(q);
            free_node(q, subscr_node_size);
          }
        else
          r = q;
        q = link(r);
      }
    }
    p = attr_head(p);
    do {
      r = p;
      p = link(p);
    } while (!(attr_loc(p) >= n));
    if (attr_loc(p) != n)
      goto l_exit;
  }
  if (discard_suffixes)
    flush_below_variable(p);
  else
  {
    if (type(p) == structured)
      p = attr_head(p);
    recycle_value(p);
  }
l_exit:;
}
/* 248 */
small_number und_type (pointer p)
{
  small_number Result;

  switch (type(p))
  {
    case undefined:
    case vacuous:
      Result = undefined;
      break;
    case boolean_type:
    case unknown_boolean:
      Result = unknown_boolean;
      break;
    case string_type:
    case unknown_string:
      Result = unknown_string;
      break;
    case pen_type:
    case unknown_pen:
    case future_pen:
      Result = unknown_pen;
      break;
    case path_type:
    case unknown_path:
      Result = unknown_path;
      break;
    case picture_type:
    case unknown_picture:
      Result = unknown_picture;
      break;
    case transform_type:
    case pair_type:
    case numeric_type:
      Result = type(p);
      break;
    case known:
    case dependent:
    case proto_dependent:
    case independent:
      Result = numeric_type;
      break;
  }
  return Result;
}
/* 249 */
void clear_symbol (pointer p, boolean saving)
{
  pointer q;

  q = equiv(p);
  switch (eq_type(p) % outer_tag)
  {
    case defined_macro:
    case secondary_primary_macro:
    case tertiary_secondary_macro:
    case expression_tertiary_macro:
      if (!saving)
        delete_mac_ref(q);
      break;
    case tag_token:
      if (q != null)
      {
        if (saving)
          name_type(q) = saved_root;
        else
        {
          flush_below_variable(q);
          free_node(q, value_node_size);
        }
      }
      break;
    default:
      do_nothing();
      break;
  }
  eqtb[p] = eqtb[frozen_undefined];
}
/* 252 */
void save_variable (pointer q)
{
  pointer p;

  if (save_ptr != null)
  {
    p = get_node(save_node_size);
    info(p) = q;
    link(p) = save_ptr;
    saved_equiv(p) = eqtb[q];
    save_ptr = p;
  }
  clear_symbol(q, (save_ptr != null));
}
/* 253 */
void save_internal (halfword q)
{
  pointer p;

  if (save_ptr != null)
  {
    p = get_node(save_node_size);
    info(p) = hash_end + q;
    link(p) = save_ptr;
    value(p) = internal[q];
    save_ptr = p;
  }
}
/* 254 */
void unsave (void)
{
  pointer q;
  pointer p;

  while (info(save_ptr) != 0)
  {
    q = info(save_ptr);
    if (q > hash_end)
    {
      if (internal[tracing_restores] > 0)
      {
        begin_diagnostic();
        r_print_nl("{restoring ");
        slow_print(int_name[q - (hash_end)]);
        print_char('=');
        print_scaled(value(save_ptr));
        print_char('}');
        end_diagnostic(false);
      }
      internal[q - (hash_end)] = value(save_ptr);
    }
    else
    {
      if (internal[tracing_restores] > 0)
      {
        begin_diagnostic();
        r_print_nl("{restoring ");
        slow_print(text(q));
        print_char('}');
        end_diagnostic(false);
      }
      clear_symbol(q, false);
      eqtb[q] = saved_equiv(save_ptr);
      if (eq_type(q) % outer_tag == tag_token)
      {
        p = equiv(q);
        if (p != null)
          name_type(q) = root;
      }
    }
    p = link(save_ptr);
    free_node(save_ptr, save_node_size);
    save_ptr = p;
  }
  p = link(save_ptr);
  free_avail(save_ptr);
  save_ptr = p;
}
/* 264 */
pointer copy_knot (pointer p)
{
  pointer q;
  uint32_t k;

  q = get_node(knot_node_size);
  for (k = 0; k <= knot_node_size - 1; k++)
    mem[q + k] = mem[p + k];
  return q;
}
/* 265 */
pointer copy_path (pointer p)
{
  pointer Result;
  pointer q, pp, qq;

  q = get_node(knot_node_size);
  qq = q;
  pp = p;
  while (true)
  {
    left_type(qq) = left_type(pp);
    right_type(qq) = right_type(pp);
    x_coord(qq) = x_coord(pp);
    y_coord(qq) = y_coord(pp);
    left_x(qq) = left_x(pp);
    left_y(qq) = left_y(pp);
    right_x(qq) = right_x(pp);
    right_y(qq) = right_y(pp);
    if (link(pp) == p)
    {
      link(qq) = q;
      Result = q;
      goto l_exit;
    }
    link(qq) = get_node(knot_node_size);
    qq = link(qq);
    pp = link(pp);
  }
l_exit:
  return Result;
}
/* 266 */
pointer htap_ypoc (pointer p)
{
  pointer Result;
  pointer q, pp, qq, rr;

  q = get_node(knot_node_size);
  qq = q;
  pp = p;
  while (true)
  {
    right_type(qq) = left_type(pp);
    left_type(qq) = right_type(pp);
    x_coord(qq) = x_coord(pp);
    y_coord(qq) = y_coord(pp);
    right_x(qq) = left_x(pp);
    right_y(qq) = left_y(pp);
    left_x(qq) = right_x(pp);
    left_y(qq) = right_y(pp);
    if (link(pp) == p)
    {
      link(q) = qq;
      path_tail = pp;
      Result = q;
      goto l_exit;
    }
    rr = get_node(knot_node_size);
    link(rr) = qq;
    qq = rr;
    pp = link(pp);
  }
l_exit:
  return Result;
}
/* 296 */
fraction curl_ratio (scaled gamma, scaled a_tension, scaled b_tension)
{
  fraction alpha, beta, num, denom, ff;

  alpha = make_fraction(unity, a_tension);
  beta = make_fraction(unity, b_tension);
  if (alpha <= beta)
  {
    ff = make_fraction(alpha, beta);
    ff = take_fraction(ff, ff);
    gamma = take_fraction(gamma, ff);
    beta = beta / 010000;
    denom = take_fraction(gamma, alpha) + three - beta;
    num = take_fraction(gamma, fraction_three - alpha) + beta;
  }
  else
  {
    ff = make_fraction(beta, alpha);
    ff = take_fraction(ff, ff);
    beta = take_fraction(beta, ff) / 010000;
    denom = take_fraction(gamma, alpha) + (ff / 1365) - beta;
    num = take_fraction(gamma, fraction_three - alpha) + beta;
  }
  if (num >= denom + denom + denom + denom)
    return fraction_four;
  else
    return make_fraction(num, denom);
}
/* 299 */
void set_controls (pointer p, pointer q, integer k)
{
  fraction rr, ss;
  scaled lt, rt;
  fraction sine;

  lt = abs(left_tension(q));
  rt = abs(right_tension(p));
  rr = velocity(st, ct, sf, cf, rt);
  ss = velocity(sf, cf, st, ct, lt);
  if ((right_tension(p) < 0) || (left_tension(q) < 0))
    if (((st >= 0) && (sf >= 0)) || ((st <= 0) && (sf <= 0)))
    {
      sine = take_fraction(abs(st), cf) + take_fraction(abs(sf), ct);
      if (sine > 0)
      {
        sine = take_fraction(sine, fraction_one + unity);
        if (right_tension(p) < 0)
          if (ab_vs_cd(abs(sf), fraction_one, rr, sine) < 0)
            rr = make_fraction(abs(sf), sine);
        if (left_tension(q) < 0)
          if (ab_vs_cd(abs(st), fraction_one, ss, sine) < 0)
            ss = make_fraction(abs(st), sine);
      }
    }
  right_x(p) = x_coord(p) + take_fraction(take_fraction(delta_x[k], ct) - take_fraction(delta_y[k], st), rr);
  right_y(p) = y_coord(p) + take_fraction(take_fraction(delta_y[k], ct) + take_fraction(delta_x[k], st), rr);
  left_x(q) = x_coord(q) - take_fraction(take_fraction(delta_x[k], cf) + take_fraction(delta_y[k], sf), ss);
  left_y(q) = y_coord(q) - take_fraction(take_fraction(delta_y[k], cf) - take_fraction(delta_x[k], sf), ss);
  right_type(p) = explicit;
  left_type(q) = explicit;
}
/* 284 */
void solve_choices (pointer p, pointer q, halfword n)
{
  integer k;
  pointer r, s, t;
  fraction aa, bb, cc, ff, acc;
  scaled dd, ee;
  scaled lt, rt;

  k = 0;
  s = p;
  while (true)
  {
    t = link(s);
    if (k == 0)
    {
      switch (right_type(s))
      {
        case given:
          if (left_type(p) == given)
          {
            aa = n_arg(delta_x[0], delta_y[0]);
            n_sin_cos(right_given(p) - aa);
            ct = n_cos;
            st = n_sin;
            n_sin_cos(left_given(q) - aa);
            cf = n_cos;
            sf = -n_sin;
            set_controls(p, q, 0);
            goto l_exit;
          }
          else
          {
            vv[0] = right_given(s) - n_arg(delta_x[0], delta_y[0]);
            reduce_angle(vv[0]);
            uu[0] = 0;
            ww[0] = 0;
          }
          break;
        case curl:
          if (left_type(t) == curl)
          {
            right_type(p) = explicit;
            left_type(q) = explicit;
            lt = abs(left_tension(q));
            rt = abs(right_tension(p));
            if (rt == unity)
            {
              if (delta_x[0] >= 0)
                right_x(p) = x_coord(p) + ((delta_x[0] + 1) / 3);
              else
                right_x(p) = x_coord(p) + ((delta_x[0] - 1) / 3);
              if (delta_y[0] >= 0)
                right_y(p) = y_coord(p) + ((delta_y[0] + 1) / 3);
              else
                right_y(p) = y_coord(p) + ((delta_y[0] - 1) / 3);
            }
            else
            {
              ff = make_fraction(unity, 3 * rt);
              right_x(p) = x_coord(p) + take_fraction(delta_x[0], ff);
              right_y(p) = y_coord(p) + take_fraction(delta_y[0], ff);
            }
            if (lt == unity)
            {
              if (delta_x[0] >= 0)
                left_x(q) = x_coord(q) - ((delta_x[0] + 1) / 3);
              else
                left_x(q) = x_coord(q) - ((delta_x[0] - 1) / 3);
              if (delta_y[0] >= 0)
                left_y(q) = y_coord(q) - ((delta_y[0] + 1) / 3);
              else
                left_y(q) = y_coord(q) - ((delta_y[0] - 1) / 3);
            }
            else
            {
              ff = make_fraction(unity, 3 * lt);
              left_x(q) = x_coord(q) - take_fraction(delta_x[0], ff);
              left_y(q) = y_coord(q) - take_fraction(delta_y[0], ff);
            }
            goto l_exit;
          }
          else
          {
            cc = right_curl(s);
            lt = abs(left_tension(t));
            rt = abs(right_tension(s));
            if ((rt == unity) && (lt == unity))
              uu[0] = make_fraction(cc + cc + unity, cc + two);
            else
              uu[0] = curl_ratio(cc, rt, lt);
            vv[0] = -take_fraction(psi[1], uu[0]);
            ww[0] = 0;
          }
          break;
        case open:
          {
            uu[0] = 0;
            vv[0] = 0;
            ww[0] = fraction_one;
          }
          break;
      }
    }
    else
    {
      switch (left_type(s))
      {
        case end_cycle:
        case open:
          {
            if (abs(right_tension(r)) == unity)
            {
              aa = fraction_half;
              dd = 2 * delta[k];
            }
            else
            {
              aa = make_fraction(unity, 3 * abs(right_tension(r)) - unity);
              dd = take_fraction(delta[k], fraction_three - make_fraction(unity, abs(right_tension(r))));
            }
            if (left_tension(t) == unity)
            {
              bb = fraction_half;
              ee = 2 * delta[k - 1];
            }
            else
            {
              bb = make_fraction(unity, 3 * abs(left_tension(t)) - unity);
              ee = take_fraction(delta[k - 1], fraction_three - make_fraction(unity, abs(left_tension(t))));
            }
            cc = fraction_one - take_fraction(uu[k - 1], aa);
            dd = take_fraction(dd, cc);
            lt = abs(left_tension(s));
            rt = abs(right_tension(s));
            if (lt != rt)
              if (lt < rt)
              {
                ff = make_fraction(lt, rt);
                ff = take_fraction(ff, ff);
                dd = take_fraction(dd, ff);
              }
              else
              {
                ff = make_fraction(rt, lt);
                ff = take_fraction(ff, ff);
                ee = take_fraction(ee, ff);
              }
            ff = make_fraction(ee, ee + dd);
            uu[k] = take_fraction(ff, bb);
            acc = -take_fraction(psi[k + 1], uu[k]);
            if (right_type(r) == curl)
            {
              ww[k] = 0;
              vv[k] = acc - take_fraction(psi[1], fraction_one - ff);
            }
            else
            {
              ff = make_fraction(fraction_one - ff, cc);
              acc = acc - take_fraction(psi[k], ff);
              ff = take_fraction(ff, aa);
              vv[k] = acc - take_fraction(vv[k - 1], ff);
              if (ww[k - 1] == 0)
                ww[k] = 0;
              else
                ww[k] = -take_fraction(ww[k - 1], ff);
            }
            if (left_type(s) == end_cycle)
            {
              aa = 0;
              bb = fraction_one;
              do {
                decr(k);
                if (k == 0)
                  k = n;
                aa = vv[k] - take_fraction(aa, uu[k]);
                bb = ww[k] - take_fraction(bb, uu[k]);
              } while (!(k == n));
              aa = make_fraction(aa, fraction_one - bb);
              theta[n] = aa;
              vv[0] = aa;
              for (k = 1; k <= n - 1; k++)
                vv[k] = vv[k] + take_fraction(aa, ww[k]);
              goto found;
            }
          }
          break;
        case curl:
          {
            cc = left_curl(s);
            lt = abs(left_tension(s));
            rt = abs(right_tension(r));
            if ((rt == unity) && (lt == unity))
              ff = make_fraction(cc + cc + unity, cc + two);
            else
              ff = curl_ratio(cc, lt, rt);
            theta[n] = -make_fraction(take_fraction(vv[n - 1], ff), fraction_one - take_fraction(ff, uu[n - 1]));
            goto found;
          }
          break;
        case given:
          {
            theta[n] = left_given(s) - n_arg(delta_x[n - 1], delta_y[n - 1]);
            reduce_angle(theta[n]);
            goto found;
          }
          break;
      }
    }
    r = s;
    s = t;
    incr(k);
  }
found:
  for (k = n - 1; k <= 0; k--)
    theta[k] = vv[k] - take_fraction(theta[k + 1], uu[k]);
  s = p;
  k = 0;
  do {
    t = link(s);
    n_sin_cos(theta[k]);
    st = n_sin;
    ct = n_cos;
    n_sin_cos(-psi[k + 1] - theta[k + 1]);
    sf = n_sin;
    cf = n_cos;
    set_controls(s, t, k);
    incr(k);
    s = t;
  } while (!(k == n));
l_exit:;
}
/* 269 */
void make_choices (pointer knots)
{
  pointer h;
  pointer p, q;
  integer k, n;
  pointer s, t;
  scaled delx, dely;
  fraction sine, cosine;

  check_arith();
  if (internal[tracing_choices] > 0)
    print_path(knots, ", before choices", true);
  p = knots;
  do {
    q = link(p);
    if (x_coord(p) == x_coord(q))
      if (y_coord(p) == y_coord(q))
        if (right_type(p) > explicit)
        {
          right_type(p) = explicit;
          if (left_type(p) == open)
          {
            left_type(p) = curl;
            left_curl(p) = unity;
          }
          left_type(q) = explicit;
          if (right_type(q) == open)
          {
            right_type(q) = curl;
            right_curl(q) = unity;
          }
          right_x(p) = x_coord(p);
          left_x(q) = x_coord(p);
          right_y(p) = y_coord(p);
          left_y(q) = y_coord(p);
        }
    p = q;
  } while (!(p == knots));
  h = knots;
  while (true)
  {
    if (left_type(h) != open)
      goto done;
    if (right_type(h) != open)
      goto done;
    h = link(h);
    if (h == knots)
    {
      left_type(h) = end_cycle;
      goto done;
    }
  }
done:;
  p = h;
  do {
    q = link(p);
    if (right_type(p) >= given)
    {
      while ((left_type(q) == open) && (right_type(q) == open))
        q = link(q);
      k = 0;
      s = p;
      n = path_size;
      do {
        t = link(s);
        delta_x[k] = x_coord(t) - x_coord(s);
        delta_y[k] = y_coord(t) - y_coord(s);
        delta[k] = pyth_add(delta_x[k], delta_y[k]);
        if (k > 0)
        {
          sine = make_fraction(delta_y[k - 1], delta[k - 1]);
          cosine = make_fraction(delta_x[k - 1], delta[k - 1]);
          psi[k] = n_arg(take_fraction(delta_x[k], cosine) +
            take_fraction(delta_y[k], sine), take_fraction(delta_y[k], cosine) - take_fraction(delta_x[k], sine));
        }
        incr(k);
        s = t;
        if (k == path_size)
          overflow ("path size", path_size);
        if (s == q)
          n = k;
      } while (!((k >= n) && (left_type(s) != end_cycle)));
      if (k == n)
        psi[n] = 0;
      else
        psi[k] = psi[1];
      if (left_type(q) == open)
      {
        delx = right_x(q) - x_coord(q);
        dely = right_y(q) - y_coord(q);
        if ((delx == 0) && (dely == 0))
        {
          left_type(q) = curl;
          left_curl(q) = unity;
        }
        else
        {
          left_type(q) = given;
          left_given(q) = n_arg(delx, dely);
        }
      }
      if ((right_type(p) == open) && (left_type(p) == explicit))
      {
        delx = x_coord(p) - left_x(p);
        dely = y_coord(p) - left_y(p);
        if ((delx == 0) && (dely == 0))
        {
          right_type(p) = curl;
          right_curl(p) = unity;
        }
        else
        {
          right_type(p) = given;
          right_given(p) = n_arg(delx, dely);
        }
      }
      solve_choices(p, q, n);
    }
    p = q;
  } while (!(p == h));
  if (internal[tracing_choices] > 0)
    print_path(knots, ", after choices", true);
  if (arith_error)
  {
    print_err("Some number got too big");
    help2("The path that I just computed is out of range.",
      "So it will probably look funny. Proceed, for a laugh.");
    put_get_error();
    arith_error = false;
  }
}
/* 311 */
void make_moves (scaled xx0, scaled xx1, scaled xx2, scaled xx3, scaled yy0, scaled yy1, scaled yy2, scaled yy3, small_number xi_corr, small_number eta_corr)
{
  integer x1, x2, x3, m, r, y1, y2, y3, n, s, l;
  integer q, t, u, x2a, x3a, y2a, y3a;

  if ((xx3 < xx0) || (yy3 < yy0))
    confusion("m");
  l = 16;
  bisect_ptr = 0;
  x1 = xx1 - xx0;
  x2 = xx2 - xx1;
  x3 = xx3 - xx2;
  if (xx0 >= xi_corr)
    r = (xx0 - xi_corr) % unity;
  else
    r = unity - 1 - ((-xx0 + xi_corr - 1) % unity);
  m = (xx3 - xx0 + r) / unity;
  y1 = yy1 - yy0;
  y2 = yy2 - yy1;
  y3 = yy3 - yy2;
  if (yy0 >= eta_corr)
    s = (yy0 - eta_corr) % unity;
  else
    s = unity - 1 - ((-yy0 + eta_corr - 1) % unity);
  n = (yy3 - yy0 + s) / unity;
  if ((xx3 - xx0 >= fraction_one) || (yy3 - yy0 >= fraction_one))
  {
    x1 = half(x1 + xi_corr);
    x2 = half(x2 + xi_corr);
    x3 = half(x3 + xi_corr);
    r = half(r + xi_corr);
    y1 = half(y1 + eta_corr);
    y2 = half(y2 + eta_corr);
    y3 = half(y3 + eta_corr);
    s = half(s + eta_corr);
    l = 15;
  }
  while (true)
  {
  l_continue:
    if (m == 0)
      while (n > 0)
      {
        incr(move_ptr);
        move[move_ptr] = 1;
        decr(n);
      }
    else if (n == 0)
      move[move_ptr] = move[move_ptr] + m;
    else if (m + n == 2)
    {
      r = two_to_the[l] - r;
      s = two_to_the[l] - s;
      while (l < 30)
      {
        x3a = x3;
        x2a = half(x2 + x3 + xi_corr);
        x2 = half(x1 + x2 + xi_corr);
        x3 = half(x2 + x2a + xi_corr);
        t = x1 + x2 + x3;
        r = r + r - xi_corr;
        y3a = y3;
        y2a = half(y2 + y3 + eta_corr);
        y2 = half(y1 + y2 + eta_corr);
        y3 = half(y2 + y2a + eta_corr);
        u = y1 + y2 + y3;
        s = s + s - eta_corr;
        if (t < r)
          if (u < s)
          {
            x1 = x3;
            x2 = x2a;
            x3 = x3a;
            r = r - t;
            y1 = y3;
            y2 = y2a;
            y3 = y3a;
            s = s - u;
          }
          else
          {
            {
              incr(move_ptr);
              move[move_ptr] = 2;
            }
            goto done;
          }
        else if (u < s)
        {
          {
            incr(move[move_ptr]);
            incr(move_ptr);
            move[move_ptr] = 1;
          }
          goto done;
        }
        incr(l);
      }
      r = r - xi_corr;
      s = s - eta_corr;
      if (ab_vs_cd(x1 + x2 + x3, s, y1 + y2 + y3, r) - xi_corr >= 0)
      {
        incr(move[move_ptr]);
        incr(move_ptr);
        move[move_ptr] = 1;
      }
      else
      {
        incr(move_ptr);
        move[move_ptr] = 2;
      }
      done:;
    }
    else
    {
      incr(l);
      stack_l = l;
      stack_x3 = x3;
      stack_x2 = half(x2 + x3 + xi_corr);
      x2 = half(x1 + x2 + xi_corr);
      x3 = half(x2 + stack_x2 + xi_corr);
      stack_x1 = x3;
      r = r + r + xi_corr;
      t = x1 + x2 + x3 + r;
      q = t / two_to_the[l];
      stack_r = t % two_to_the[l];
      stack_m = m - q;
      m = q;
      stack_y3 = y3;
      stack_y2 = half(y2 + y3 + eta_corr);
      y2 = half(y1 + y2 + eta_corr);
      y3 = half(y2 + stack_y2 + eta_corr);
      stack_y1 = y3;
      s = s + s + eta_corr;
      u = y1 + y2 + y3 + s;
      q = u / two_to_the[l];
      stack_s = u % two_to_the[l];
      stack_n = n - q;
      n = q;
      bisect_ptr = bisect_ptr + move_increment;
      goto l_continue;
    }
    if (bisect_ptr == 0)
      goto l_exit;
    bisect_ptr = bisect_ptr - move_increment;
    x1 = stack_x1;
    x2 = stack_x2;
    x3 = stack_x3;
    r = stack_r;
    m = stack_m;
    y1 = stack_y1;
    y2 = stack_y2;
    y3 = stack_y3;
    s = stack_s;
    n = stack_n;
    l = stack_l;
  }
l_exit:;
}
/* 321 */
void smooth_moves (integer b, integer t)
{
  integer k;
  integer a, aa, aaa;

  if (t - b >= 3)
  {
    k = b + 2;
    aa = move[k - 1];
    aaa = move[k - 2];
    do {
      a = move[k];
      if (abs(a - aa) > 1)
        if (a > aa)
        {
          if (aaa >= aa)
            if (a >= move[k + 1])
            {
              incr(move[k - 1]);
              move[k] = a - 1;
            }
        }
        else
        {
          if (aaa <= aa)
            if (a <= move[k + 1])
            {
              decr(move[k - 1]);
              move[k] = a + 1;
            }
        }
      incr(k);
      aaa = aa;
      aa = a;
    } while (!(k == t));
  }
}
/* 326 */
void init_edges (pointer h)
{
  knil(h) = h;
  link(h) = h;
  n_min(h) = zero_field + 4095;
  n_max(h) = zero_field - 4095;
  m_min(h) = zero_field + 4095;
  m_max(h) = zero_field - 4095;
  m_offset(h) = zero_field;
  last_window(h) = 0;
  last_window_time(h) = 0;
  n_rover(h) = h;
  n_pos(h) = 0;
}
/* 328 */
void fix_offset (void)
{
  pointer p, q;
  integer delta;

  delta = 8 * (m_offset(cur_edges) - zero_field);
  m_offset(cur_edges) = zero_field;
  q = link(cur_edges);
  while (q != cur_edges)
  {
    p = sorted(q);
    while (p != sentinel)
    {
      info(p) = info(p) - delta;
      p = link(p);
    }
    p = unsorted(q);
    while (p > _void)
    {
      info(p) = info(p) - delta;
      p = link(p);
    }
    q = link(q);
  }
}
/* 329 */
void edge_prep (integer ml, integer mr, integer nl, integer nr)
{
  halfword delta;
  pointer p, q;

  ml = ml + zero_field;
  mr = mr + zero_field;
  nl = nl + zero_field;
  nr = nr - 1 + zero_field;
  if (ml < m_min(cur_edges))
    m_min(cur_edges) = ml;
  if (mr > m_max(cur_edges))
    m_max(cur_edges) = mr;
  if (!valid_range(m_min(cur_edges) + m_offset(cur_edges) - zero_field) || !valid_range(m_max(cur_edges) + m_offset(cur_edges) - zero_field))
    fix_offset();
  if (empty_edges(cur_edges))
  {
    n_min(cur_edges) = nr + 1;
    n_max(cur_edges) = nr;
  }
  if (nl < n_min(cur_edges))
  {
    delta = n_min(cur_edges) - nl;
    n_min(cur_edges) = nl;
    p = link(cur_edges);
    do {
      q = get_node(row_node_size);
      sorted(q) = sentinel;
      unsorted(q) = _void;
      knil(p) = q;
      link(q) = p;
      p = q;
      decr(delta);
    } while (!(delta == 0));
    knil(p) = cur_edges;
    link(cur_edges) = p;
    if (n_rover(cur_edges) == cur_edges)
      n_pos(cur_edges) = nl - 1;
  }
  if (nr > n_max(cur_edges))
  {
    delta = nr - n_max(cur_edges);
    n_max(cur_edges) = nr;
    p = knil(cur_edges);
    do {
      q = get_node(row_node_size);
      sorted(q) = sentinel;
      unsorted(q) = _void;
      link(p) = q;
      knil(q) = p;
      p = q;
      decr(delta);
    } while (!(delta == 0));
    link(p) = cur_edges;
    knil(cur_edges) = p;
    if (n_rover(cur_edges) == cur_edges)
      n_pos(cur_edges) = nr + 1;
  }
}
/* 334 */
pointer copy_edges (pointer h)
{
  pointer p, r;
  pointer hh, pp, qq, rr, ss;

  hh = get_node(edge_header_size);
  mem[hh + 1] = mem[h + 1];
  mem[hh + 2] = mem[h + 2];
  mem[hh + 3] = mem[h + 3];
  mem[hh + 4] = mem[h + 4];
  n_pos(hh) = n_max(hh) + 1;
  n_rover(hh) = hh;
  p = link(h);
  qq = hh;
  while (p != h)
  {
    pp = get_node(row_node_size);
    link(qq) = pp;
    knil(pp) = qq;
    r = sorted(p);
    rr = sorted_loc(pp);
    while (r != sentinel)
    {
      ss = get_avail();
      link(rr) = ss;
      rr = ss;
      info(rr) = info(r);
      r = link(r);
    }
    link(rr) = sentinel;
    r = unsorted(p);
    rr = temp_head;
    while (r > _void)
    {
      ss = get_avail();
      link(rr) = ss;
      rr = ss;
      info(rr) = info(r);
      r = link(r);
    }
    link(rr) = r;
    unsorted(pp) = link(temp_head);
    p = link(p);
    qq = pp;
  }
  link(qq) = hh;
  knil(hh) = qq;
  return hh;
}
/* 336 */
void y_reflect_edges (void)
{
  pointer p, q, r;

  p = n_min(cur_edges);
  n_min(cur_edges) = zero_field + zero_field - 1 - n_max(cur_edges);
  n_max(cur_edges) = zero_field + zero_field - 1 - p;
  n_pos(cur_edges) = zero_field + zero_field - 1 - n_pos(cur_edges);
  p = link(cur_edges);
  q = cur_edges;
  do {
    r = link(p);
    link(p) = q;
    knil(q) = p;
    q = p;
    p = r;
  } while (!(q == cur_edges));
  last_window_time(cur_edges) = 0;
}
/* 337 */
void x_reflect_edges (void)
{
  pointer p, q, r, s;
  integer m;

  p = m_min(cur_edges);
  m_min(cur_edges) = zero_field + zero_field - m_max(cur_edges);
  m_max(cur_edges) = zero_field + zero_field - p;
  m = (zero_field + m_offset(cur_edges)) * 8 + zero_w + min_halfword + zero_w + min_halfword;
  m_offset(cur_edges) = zero_field;
  p = link(cur_edges);
  do {
    q = sorted(p);
    r = sentinel;
    while (q != sentinel)
    {
      s = link(q);
      link(q) = r;
      r = q;
      info(r) = m - info(q);
      q = s;
    }
    sorted(p) = r;
    q = unsorted(p);
    while (q > _void)
    {
      info(q) = m - info(q);
      q = link(q);
    }
    p = link(p);
  } while (!(p == cur_edges));
  last_window_time(cur_edges) = 0;
}
/* 340 */
void y_scale_edges (integer s)
{
  pointer p, q, pp, r, rr, ss;
  integer t;

  if ((s * (n_max(cur_edges) + 1 - zero_field) >= 4096) || (s * (n_min(cur_edges) - zero_field) <= -4096))
  {
    print_err("Scaled picture would be too big");
    help3("I can't yscale the picture as requested---it would",
      "make some coordinates too large or too small.",
      "Proceed, and I'll omit the transformation.");
    put_get_error();
  }
  else
  {
    n_max(cur_edges) = s * (n_max(cur_edges) + 1 - zero_field) - 1 + zero_field;
    n_min(cur_edges) = s * (n_min(cur_edges) - zero_field) + zero_field;
    p = cur_edges;
    do {
      q = p;
      p = link(p);
      for (t = 2; t <= s; t++)
      {
        pp = get_node(row_node_size);
        link(q) = pp;
        knil(p) = pp;
        link(pp) = p;
        knil(pp) = q;
        q = pp;
        r = sorted(p);
        rr = sorted_loc(pp);
        while (r != sentinel)
        {
          ss = get_avail();
          link(rr) = ss;
          rr = ss;
          info(rr) = info(r);
          r = link(r);
        }
        link(rr) = sentinel;
        r = unsorted(p);
        rr = temp_head;
        while (r > _void)
        {
          ss = get_avail();
          link(rr) = ss;
          rr = ss;
          info(rr) = info(r);
          r = link(r);
        }
        link(rr) = r;
        unsorted(pp) = link(temp_head);
      }
    } while (!(link(p) == cur_edges));
    last_window_time(cur_edges) = 0;
  }
}
/* 342 */
void x_scale_edges (integer s)
{
  pointer p, q;
  unsigned short t;
  unsigned char w;
  integer delta;

  if ((s * (m_max(cur_edges) - zero_field) >= 4096) || (s * (m_min(cur_edges) - zero_field) <= -4096))
  {
    print_err("Scaled picture would be too big");
    help3("I can't xscale the picture as requested---it would", 
      "make some coordinates too large or too small.",
      "Proceed, and I'll omit the transformation.");
    put_get_error();
  }
  else if ((m_max(cur_edges) != zero_field) || (m_min(cur_edges) != zero_field))
  {
    m_max(cur_edges) = s * (m_max(cur_edges) - zero_field) + zero_field;
    m_min(cur_edges) = s * (m_min(cur_edges) - zero_field) + zero_field;
    delta = 8 * (zero_field - s * m_offset(cur_edges)) + min_halfword;
    m_offset(cur_edges) = zero_field;
    q = link(cur_edges);
    do {
      p = sorted(q);
      while (p != sentinel)
      {
        t = ho(info(p));
        w = t % 8;
        info(p) = (t - w) * s + w + delta;
        p = link(p);
      }
      p = unsorted(q);
      while (p > _void)
      {
        t = ho(info(p));
        w = t % 8;
        info(p) = (t - w) * s + w + delta;
        p = link(p);
      }
      q = link(q);
    } while (!(q == cur_edges));
    last_window_time(cur_edges) = 0;
  }
}
/* 344 */
void negate_edges (pointer h)
{
  pointer p, q, r, s, t, u;

  p = link(h);
  while (p != h)
  {
    q = unsorted(p);
    while (q > _void)
    {
      info(q) = 8 - 2 * ((ho(info(q))) % 8) + info(q);
      q = link(q);
    }
    q = sorted(p);
    if (q != sentinel)
    {
      do {
        info(q) = 8 - 2 * ((ho(info(q))) % 8) + info(q);
        q = link(q);
      } while (!(q == sentinel));
      u = sorted_loc(p);
      q = link(u);
      r = q;
      s = link(r);
      while (true)
      {
        if (info(s) > info(r))
        {
          link(u) = q;
          if (s == sentinel)
            goto done;
          u = r;
          q = s;
          r = q;
          s = link(r);
        }
        else
        {
          t = s;
          s = link(t);
          link(t) = q;
          q = t;
        }
      }
    done:
      link(r) = sentinel;
    }
    p = link(p);
  }
  last_window_time(h) = 0;
}
/* 346 */
void sort_edges (pointer h)
{
  halfword k;
  pointer p, q, r, s;

  r = unsorted(h);
  unsorted(h) = null;
  p = link(r);
  link(r) = sentinel;
  link(temp_head) = r;
  while (p > _void)
  {
    k = info(p);
    q = temp_head;
    do {
      r = q;
      q = link(r);
    } while (!(k <= info(q)));
    link(r) = p;
    r = link(p);
    link(p) = q;
    p = r;
  }
  {
    r = sorted_loc(h);
    q = link(r);
    p = link(temp_head);
    while (true)
    {
      k = info(p);
      while (k > info(q))
      {
        r = q;
        q = link(r);
      }
      link(r) = p;
      s = link(p);
      link(p) = q;
      if (s == sentinel)
        goto done;
      r = p;
      p = s;
    }
    done:;
  }
}
/* 348 */
void cull_edges (integer w_lo, integer w_hi, integer w_out, integer w_in)
{
  pointer p, q, r, s;
  integer w;
  integer d;
  integer m;
  integer mm;
  integer ww;
  integer prev_w;
  pointer n, min_n, max_n;
  pointer min_d, max_d;

  min_d = max_halfword;
  max_d = min_halfword;
  min_n = max_halfword;
  max_n = min_halfword;
  p = link(cur_edges);
  n = n_min(cur_edges);
  while (p != cur_edges)
  {
    if (unsorted(p) > _void)
      sort_edges(p);
    if (sorted(p) != sentinel)
    {
      r = temp_head;
      q = sorted(p);
      ww = 0;
      m = 1000000;
      prev_w = 0;
      while (true)
      {
        if (q == sentinel)
          mm = 1000000;
        else
        {
          d = ho(info(q));
          mm = d / 8;
          ww = ww + (d % 8) - zero_w;
        }
        if (mm > m)
        {
          if (w != prev_w)
          {
            s = get_avail();
            link(r) = s;
            info(s) = 8 * m + min_halfword + zero_w + w - prev_w;
            r = s;
            prev_w = w;
          }
          if (q == sentinel)
            goto done;
        }
        m = mm;
        if (ww >= w_lo)
          if (ww <= w_hi)
            w = w_in;
          else
            w = w_out;
        else
          w = w_out;
        s = link(q);
        free_avail(q);
        q = s;
      }
    done:
      link(r) = sentinel;
      sorted(p) = link(temp_head);
      if (r != temp_head)
      {
        if (min_n == max_halfword)
          min_n = n;
        max_n = n;
        if (min_d > info(link(temp_head)))
          min_d = info(link(temp_head));
        if (max_d < info(r))
          max_d = info(r);
      }
    }
    p = link(p);
    incr(n);
  }
  if (min_n > max_n)
  {
    p = link(cur_edges);
    while (p != cur_edges)
    {
      q = link(p);
      free_node(p, row_node_size);
      p = q;
    }
    init_edges(cur_edges);
  }
  else
  {
    n = n_min(cur_edges);
    n_min(cur_edges) = min_n;
    while (min_n > n)
    {
      p = link(cur_edges);
      link(cur_edges) = link(p);
      knil(link(p)) = cur_edges;
      free_node(p, row_node_size);
      incr(n);
    }
    n = n_max(cur_edges);
    n_max(cur_edges) = max_n;
    n_pos(cur_edges) = max_n + 1;
    n_rover(cur_edges) = cur_edges;
    while (max_n < n)
    {
      p = knil(cur_edges);
      knil(cur_edges) = knil(p);
      link(knil(p)) = cur_edges;
      free_node(p, row_node_size);
      decr(n);
    }
    m_min(cur_edges) = ((ho(min_d)) / 8) - m_offset(cur_edges) + zero_field;
    m_max(cur_edges) = ((ho(max_d)) / 8) - m_offset(cur_edges) + zero_field;
  }
  last_window_time(cur_edges) = 0;
}
/* 354 */
void xy_swap_edges (void)
{
  integer m_magic, n_magic;
  pointer p, q, r, s;
  integer m_spread;
  integer j, jj;
  integer m, mm;
  integer pd, rd;
  integer pm, rm;
  integer w;
  integer ww;
  integer dw;
  integer extras;
  int8_t xw;
  integer k;

  m_spread = m_max(cur_edges) - m_min(cur_edges);
  if (m_spread > move_size)
    overflow ("move table size", move_size);
  for (j = 0; j <= m_spread; j++)
    move[j] = mem_top;
  p = get_node(row_node_size);
  sorted(p) = sentinel;
  unsorted(p) = null;
  knil(p) = cur_edges;
  knil(link(cur_edges)) = p;
  p = get_node(row_node_size);
  sorted(p) = sentinel;
  knil(p) = knil(cur_edges);
  m_magic = m_min(cur_edges) + m_offset(cur_edges) - zero_field;
  n_magic = 8 * n_max(cur_edges) + 8 + zero_w + min_halfword;
  do {
    q = knil(p);
    if (unsorted(q) > _void)
     sort_edges(q);
    r = sorted(p);
    free_node(p, row_node_size);
    p = r;
    pd = ho(info(p));
    pm = pd / 8;
    r = sorted(q);
    rd = ho(info(r));
    rm = rd / 8;
    w = 0;
    while (true)
    {
      if (pm < rm)
        mm = pm;
      else
        mm = rm;
      if (w != 0)
        if (m != mm)
        {
          if (mm - m_magic >= move_size)
            confusion("xy");
          extras = (abs(w) - 1) / 3;
          if (extras > 0)
          {
            if (w > 0)
              xw = 3;
            else
              xw = -3;
            ww = w - extras * xw;
          }
          else
            ww = w;
          do {
            j = m - m_magic;
            for (k = 1; k <= extras; k++)
            {
              s = get_avail();
              info(s) = n_magic + xw;
              link(s) = move[j];
              move[j] = s;
            }
            s = get_avail();
            info(s) = n_magic + ww;
            link(s) = move[j];
            move[j] = s;
            incr(m);
          } while (!(m == mm));
        }
      if (pd < rd)
      {
        dw = (pd % 8) - zero_w;
        s = link(p);
        free_avail(p);
        p = s;
        pd = ho(info(p));
        pm = pd / 8;
      }
      else
      {
        if (r == sentinel)
          goto done;
        dw = -((rd % 8) - zero_w);
        r = link(r);
        rd = ho(info(r));
        rm = rd / 8;
      }
      m = mm;
      w = w + dw;
    }
  done:
    p = q;
    n_magic = n_magic - 8;
  } while (!(knil(p) == cur_edges));
  free_node(p, row_node_size);
  move[m_spread] = 0;
  j = 0;
  while (move[j] == sentinel)
    incr(j);
  if (j == m_spread)
    init_edges(cur_edges);
  else
  {
    mm = m_min(cur_edges);
    m_min(cur_edges) = n_min(cur_edges);
    m_max(cur_edges) = n_max(cur_edges) + 1;
    m_offset(cur_edges) = zero_field;
    jj = m_spread - 1;
    while (move[jj] == sentinel)
      decr(jj);
    n_min(cur_edges) = j + mm;
    n_max(cur_edges) = jj + mm;
    q = cur_edges;
    do {
      p = get_node(row_node_size);
      link(q) = p;
      knil(p) = q;
      sorted(p) = move[j];
      unsorted(p) = null;
      incr(j);
      q = p;
    } while (!(j > jj));
    link(q) = cur_edges;
    knil(cur_edges) = q;
    n_pos(cur_edges) = n_max(cur_edges) + 1;
    n_rover(cur_edges) = cur_edges;
    last_window_time(cur_edges) = 0;
  }
}
/* 366 */
void merge_edges (pointer h)
{
  pointer p, q, r, pp, qq, rr;
  integer n;
  halfword k;
  integer delta;

  if (link(h) != h)
  {
    if ((m_min(h) < m_min(cur_edges)) || (m_max(h) > m_max(cur_edges)) ||
      (n_min(h) < n_min(cur_edges)) || (n_max(h) > n_max(cur_edges)))
      edge_prep(m_min(h) - zero_field, m_max(h) - zero_field, n_min(h) - zero_field, n_max(h) - zero_field + 1);
    if (m_offset(h) != m_offset(cur_edges))
    {
      pp = link(h);
      delta = 8 * (m_offset(cur_edges) - m_offset(h));
      do {
        qq = sorted(pp);
        while (qq != sentinel)
        {
          info(qq) = info(qq) + delta;
          qq = link(qq);
        }
        qq = unsorted(pp);
        while (qq > _void)
        {
          info(qq) = info(qq) + delta;
          qq = link(qq);
        }
        pp = link(pp);
      } while (!(pp == h));
    }
    n = n_min(cur_edges);
    p = link(cur_edges);
    pp = link(h);
    while (n < n_min(h))
    {
      incr(n);
      p = link(p);
    }
    do {
      qq = unsorted(pp);
      if (qq > _void)
        if (unsorted(p) <= _void)
          unsorted(p) = qq;
        else
        {
          while (link(qq) > _void)
            qq = link(qq);
          link(qq) = unsorted(p);
          unsorted(p) = unsorted(pp);
        }
      unsorted(pp) = null;
      qq = sorted(pp);
      if (qq != sentinel)
      {
        if (unsorted(p) == _void)
          unsorted(p) = null;
        sorted(pp) = sentinel;
        r = sorted_loc(p);
        q = link(r);
        if (q == sentinel)
          sorted(p) = qq;
        else
          while (true)
          {
            k = info(qq);
            while (k > info(q))
            {
              r = q;
              q = link(r);
            }
            link(r) = qq;
            rr = link(qq);
            link(qq) = q;
            if (rr == sentinel)
              goto done;
            r = qq;
            qq = rr;
          }
      }
    done:;
      pp = link(pp);
      p = link(p);
    } while (!(pp == h));
  }
}
/* 369 */
integer total_weight (pointer h)
{
  pointer p, q;
  integer n;
  unsigned short m;

  n = 0;
  p = link(h);
  while (p != h)
  {
    q = sorted(p);
    while (q != sentinel)
    {
      m = ho(info(q));
      n = n - ((m % 8) - zero_w) * (m / 8);
      q = link(q);
    }
    q = unsorted(p);
    while (q > _void)
    {
      m = ho(info(q));
      n = n - ((m % 8) - zero_w) * (m / 8);
      q = link(q);
    }
    p = link(p);
  }
  return n;
}
/* 372 */
void begin_edge_tracing (void)
{
  print_diagnostic("Tracing edges", "", true);
  r_print(" (weight ");
  print_int(cur_wt);
  print_char(')');
  trace_x = -4096;
}
/* 372 */
void trace_a_corner (void)
{
  if (file_offset > max_print_line - 13)
    r_print_nl("");
  print_char('(');
  print_int(trace_x);
  print_char(',');
  print_int(trace_yy);
  print_char(')');
  trace_y = trace_yy;
}
/* 372 */
void end_edge_tracing (void)
{
  if (trace_x == -4096)
    r_print_nl("(No new edges added.)");
  else
  {
    trace_a_corner();
    print_char('.');
  }
  end_diagnostic(true);
}
/* 373 */
void trace_new_edge (pointer r, integer n)
{
  integer d;
  int8_t w;
  integer m, n0, n1;

  d = ho(info(r));
  w = (d % 8) - zero_w;
  m = (d / 8) - m_offset(cur_edges);
  if (w == cur_wt)
  {
    n0 = n + 1;
    n1 = n;
  }
  else
  {
    n0 = n;
    n1 = n + 1;
  }
  if (m != trace_x)
  {
    if (trace_x == -4096)
    {
      r_print_nl("");
      trace_yy = n0;
    }
    else if (trace_yy != n0)
      print_char('?');
    else
      trace_a_corner();
    trace_x = m;
    trace_a_corner();
  }
  else
  {
    if (n0 != trace_yy)
      print_char('!');
    if (((n0 < n1) && (trace_y > trace_yy)) || ((n0 > n1) && (trace_y < trace_yy)))
      trace_a_corner();
  }
  trace_yy = n1;
}
/* 374 */
void line_edges (scaled x0, scaled y0, scaled x1, scaled y1)
{
  integer m0, n0, m1, n1;
  scaled delx, dely;
  scaled yt;
  scaled tx;
  pointer p, r;
  integer base;
  integer n;

  n0 = round_unscaled(y0);
  n1 = round_unscaled(y1);
  if (n0 != n1)
  {
    m0 = round_unscaled(x0);
    m1 = round_unscaled(x1);
    delx = x1 - x0;
    dely = y1 - y0;
    yt = n0 * unity - half_unit;
    y0 = y0 - yt;
    y1 = y1 - yt;
    if (n0 < n1)
    {
      base = 8 * m_offset(cur_edges) + min_halfword + zero_w - cur_wt;
      if (m0 <= m1)
        edge_prep(m0, m1, n0, n1);
      else
        edge_prep(m1, m0, n0, n1);
      n = n_pos(cur_edges) - zero_field;
      p = n_rover(cur_edges);
      if (n != n0)
        if (n < n0)
        {
          do {
            incr(n);
            p = link(p);
          } while (!(n == n0));
        }
        else
        {
          do {
            decr(n);
            p = knil(p);
          } while (!(n == n0));
        }
      y0 = unity - y0;
      while (true)
      {
        r = get_avail();
        link(r) = unsorted(p);
        unsorted(p) = r;
        tx = take_fraction(delx, make_fraction(y0, dely));
        if (ab_vs_cd(delx, y0, dely, tx) < 0)
          decr(tx);
        info(r) = 8 * round_unscaled(x0 + tx) + base;
        y1 = y1 - unity;
        if (internal[tracing_edges] > 0)
          trace_new_edge(r, n);
        if (y1 < unity)
          goto done;
        p = link(p);
        y0 = y0 + unity;
        incr(n);
      }
      done:;
    }
    else
    {
      base = 8 * m_offset(cur_edges) + min_halfword + zero_w + cur_wt;
      if (m0 <= m1)
        edge_prep(m0, m1, n1, n0);
      else
        edge_prep(m1, m0, n1, n0);
      decr(n0);
      n = n_pos(cur_edges) - zero_field;
      p = n_rover(cur_edges);
      if (n != n0)
        if (n < n0)
        {
          do {
            incr(n);
            p = link(p);
          } while (!(n == n0));
        }
        else
        {
          do {
            decr(n);
            p = knil(p);
          } while (!(n == n0));
        }
      while (true)
      {
        r = get_avail();
        link(r) = unsorted(p);
        unsorted(p) = r;
        tx = take_fraction(delx, make_fraction(y0, dely));
        if (ab_vs_cd(delx, y0, dely, tx) < 0)
          incr(tx);
        info(r) = 8 * round_unscaled(x0 - tx) + base;
        y1 = y1 + unity;
        if (internal[tracing_edges] > 0)
          trace_new_edge(r, n);
        if (y1 >= 0)
          goto done1;
        p = knil(p);
        y0 = y0 + unity; decr(n);
      }
      done1:;
    }
    n_rover(cur_edges) = p;
    n_pos(cur_edges) = n + zero_field;
  }
}
/* 378 */
void move_to_edges (integer m0, integer n0, integer m1, integer n1)
{
  integer delta;
  integer k;
  pointer p, r;
  integer dx;
  integer edge_and_weight;
  integer j;
  integer n;
#ifdef DEBUG
  integer sum;
#endif

  delta = n1 - n0;
#ifdef DEBUG
  sum = move[0];
  for (k = 1; k <= delta; k++)
    sum = sum + abs(move[k]);
  if (sum != m1 - m0)
    confusion("0");
#endif
  switch (octant)
  {
    case first_octant:
      {
        dx = 8;
        edge_prep(m0, m1, n0, n1);
        goto fast_case_up;
      }
      break;
    case second_octant:
      {
        dx = 8;
        edge_prep(n0, n1, m0, m1);
        goto slow_case_up;
      }
      break;
    case third_octant:
      {
        dx = -8;
        edge_prep(-n1, -n0, m0, m1);
        negate(n0);
        goto slow_case_up;
      }
      break;
    case fourth_octant:
      {
        dx = -8;
        edge_prep(-m1, -m0, n0, n1);
        negate(m0);
        goto fast_case_up;
      }
      break;
    case fifth_octant:
      {
        dx = -8;
        edge_prep(-m1, -m0, -n1, -n0);
        negate(m0);
        goto fast_case_down;
      }
      break;
    case sixth_octant:
      {
        dx = -8;
        edge_prep(-n1, -n0, -m1, -m0);
        negate(n0);
        goto slow_case_down;
      }
      break;
    case seventh_octant:
      {
        dx = 8;
        edge_prep(n0, n1, -m1, -m0);
        goto slow_case_down;
      }
      break;
    case eighth_octant:
      {
        dx = 8;
        edge_prep(m0, m1, -n1, -n0);
        goto fast_case_down;
      }
      break;
  }
fast_case_up:
  n = n_pos(cur_edges) - zero_field;
  p = n_rover(cur_edges);
  if (n != n0)
    if (n < n0)
    {
      do {
        incr(n);
        p = link(p);
      } while (!(n == n0));
    }
    else
    {
      do {
        decr(n);
        p = knil(p);
      } while (!(n == n0));
    }
  if (delta > 0)
  {
    k = 0;
    edge_and_weight = 8 * (m0 + m_offset(cur_edges)) + min_halfword + zero_w - cur_wt;
    do {
      edge_and_weight = edge_and_weight + dx * move[k];
      fast_get_avail(r);
      link(r) = unsorted(p);
      info(r) = edge_and_weight;
      if (internal[tracing_edges] > 0)
        trace_new_edge(r, n);
      unsorted(p) = r;
      p = link(p);
      incr(k);
      incr(n);
    } while (!(k == delta));
  }
  goto done;
fast_case_down:
  n0 = -n0 - 1;
  n = n_pos(cur_edges) - zero_field;
  p = n_rover(cur_edges);
  if (n != n0)
    if (n < n0)
    {
      do {
        incr(n);
        p = link(p);
      } while (!(n == n0));
    }
    else
    {
      do {
        decr(n);
        p = knil(p);
      } while (!(n == n0));
    }
  if (delta > 0)
  {
    k = 0;
    edge_and_weight = 8 * (m0 + m_offset(cur_edges)) + min_halfword + zero_w + cur_wt;
    do {
      edge_and_weight = edge_and_weight + dx * move[k];
      fast_get_avail(r);
      link(r) = unsorted(p);
      info(r) = edge_and_weight;
      if (internal[tracing_edges] > 0)
        trace_new_edge(r, n);
      unsorted(p) = r;
      p = knil(p);
      incr(k);
      decr(n);
    } while (!(k == delta));
  }
  goto done;
slow_case_up:
  edge_and_weight = 8 * (n0 + m_offset(cur_edges)) + min_halfword + zero_w - cur_wt;
  n0 = m0;
  k = 0;
  n = n_pos(cur_edges) - zero_field;
  p = n_rover(cur_edges);
  if (n != n0)
    if (n < n0)
    {
      do {
        incr(n);
        p = link(p);
      } while (!(n == n0));
    }
    else
    {
      do {
        decr(n);
        p = knil(p);
      } while (!(n == n0));
    }
  do {
    j = move[k];
    while (j > 0)
    {
      fast_get_avail(r);
      link(r) = unsorted(p);
      info(r) = edge_and_weight;
      if (internal[tracing_edges] > 0)
        trace_new_edge(r, n);
      unsorted(p) = r;
      p = link(p);
      decr(j);
      incr(n);
    }
    edge_and_weight = edge_and_weight + dx;
    incr(k);
  } while (!(k > delta));
  goto done;
slow_case_down:
  edge_and_weight = 8 * (n0 + m_offset(cur_edges)) + min_halfword + zero_w + cur_wt;
  n0 = -m0 - 1;
  k = 0;
  n = n_pos(cur_edges) - zero_field;
  p = n_rover(cur_edges);
  if (n != n0)
    if (n < n0)
    {
      do {
        incr(n);
        p = link(p);
      } while (!(n == n0));
    }
    else
    {
      do {
        decr(n);
        p = knil(p);
      } while (!(n == n0));
    }
  do {
    j = move[k];
    while (j > 0)
    {
      fast_get_avail(r);
      link(r) = unsorted(p);
      info(r) = edge_and_weight;
      if (internal[tracing_edges] > 0)
        trace_new_edge(r, n);
      unsorted(p) = r;
      p = knil(p);
      decr(j);
      decr(n);
    }
    edge_and_weight = edge_and_weight + dx;
    incr(k);
  } while (!(k > delta));
  goto done;
done:
  n_pos(cur_edges) = n + zero_field;
  n_rover(cur_edges) = p;
}
/* 387 */
void skew (scaled x, scaled y, small_number octant)
{
  switch (octant)
  {
    case first_octant:
      set_two(x - y, y);
      break;
    case second_octant:
      set_two(y - x, x);
      break;
    case third_octant:
      set_two(y + x, -x);
      break;
    case fourth_octant:
      set_two(-x - y, y);
      break;
    case fifth_octant:
      set_two(-x + y, -y);
      break;
    case sixth_octant:
      set_two(-y + x, -x);
      break;
    case seventh_octant:
      set_two(-y - x, x);
      break;
    case eighth_octant:
      set_two(x + y, -y);
      break;
  }
}
/* 390 */
void abnegate (scaled x, scaled y, small_number octant_before, small_number octant_after)
{
  if (odd(octant_before) == odd(octant_after))
    cur_x = x;
  else
    cur_x = -x;
  if ((octant_before > negate_y) == (octant_after > negate_y))
    cur_y = y;
  else
    cur_y = -y;
}
/* 391 */
fraction crossing_point (integer a, integer b, integer c)
{
  fraction Result;
  integer d;
  integer x, xx, x0, x1, x2;

  if (a < 0)
    zero_crossing();
  if (c >= 0)
  {
    if (b >= 0)
      if (c > 0)
        no_crossing();
      else if ((a == 0) && (b == 0))
        no_crossing();
      else
        one_crossing();
    if (a == 0)
      zero_crossing();
  }
  else if (a == 0)
    if (b <= 0)
      zero_crossing();
  d = 1;
  x0 = a;
  x1 = a - b;
  x2 = b - c;
  do {
    x = half(x1 + x2);
    if (x1 - x0 > x0)
    {
      x2 = x;
      _double(x0);
      _double(d);
    }
    else
    {
      xx = x1 + x - x0;
      if (xx > x0)
      {
        x2 = x;
        _double(x0);
        _double(d);
      }
      else
      {
        x0 = x0 - xx;
        if (x <= x0)
          if (x + x2 <= x0)
            no_crossing();
        x1 = x;
        d = d + d + 1;
      }
    }
  } while (!(d >= fraction_one));
  Result = d - fraction_one;
l_exit:;
  return Result;
}
/* 394 */
void print_spec (str_number s)
{
  pointer p, q;
  small_number octant;

  print_diagnostic("Cycle spec", s, true);
  p = cur_spec;
  octant = left_octant(p);
  print_ln();
  print_two_true(x_coord(cur_spec), y_coord(cur_spec));
  r_print(" % beginning in octant `");
  while (true)
  {
    print(octant_dir[octant]);
    print_char('\'');
    while (true)
    {
      q = link(p);
      if (right_type(p) == endpoint)
        goto not_found;
      {
        r_print_nl("   ..controls ");
        print_two_true(right_x(p), right_y(p));
        r_print(" and ");
        print_two_true(left_x(q), left_y(q));
        r_print_nl(" ..");
        print_two_true(x_coord(q), y_coord(q));
        r_print(" % segment ");
        print_int(left_type(q) - 1);
      }
      p = q;
    }
  not_found:
    if (q == cur_spec)
      goto done;
    p = q;
    octant = left_octant(p);
    r_print_nl("% entering octant `");
  }
done:
  r_print_nl(" & cycle");
  end_diagnostic(true);
}
/* 398 */
void print_strange (str_number s)
{
  pointer p;
  pointer f;
  pointer q;
  integer t;

  if (interaction == error_stop_mode)
    wake_up_terminal();
  r_print_nl(">");
  p = cur_spec;
  t = max_quarterword + 1;
  do {
    p = link(p);
    if (left_type(p) != endpoint)
    {
      if (left_type(p) < t)
        f = p;
      t = left_type(p);
    }
  } while (!(p == cur_spec));
  p = cur_spec;
  q = p;
  do {
    p = link(p);
    if (left_type(p) == endpoint)
      q = p;
  } while (!(p == f));
  t = 0;
  do {
    if (left_type(p) != endpoint)
    {
      if (left_type(p) != t)
      {
        t = left_type(p);
        print_char(" ");
        print_int(t - 1);
      }
      if (q != null)
      {
        if (left_type(link(q)) == endpoint)
        {
          r_print(" (");
          print(octant_dir[left_octant(q)]);
          q = link(q);
          while (left_type(link(q)) == endpoint)
          {
            print_char(" ");
            print(octant_dir[left_octant(q)]);
            q = link(q);
          }
          print_char(')');
        }
        print_char(" ");
        print(octant_dir[left_octant(q)]);
        q = null;
      }
    }
    else if (q == null)
      q = p;
    p = link(p);
  } while (!(p == f));
  print_char(" ");
  print_int(left_type(p) - 1);
  if (q != null)
  {
    if (left_type(link(q)) == endpoint)
    {
      r_print(" (");
      print(octant_dir[left_octant(q)]);
      q = link(q);
      while (left_type(link(q)) == endpoint)
      {
        print_char(" ");
        print(octant_dir[left_octant(q)]);
        q = link(q);
      }
      print_char(')');
    }
  }
  print_err(s);
}
/* 405 */
void remove_cubic (pointer p)
{
  pointer q;

  q = link(p);
  right_type(p) = right_type(q);
  link(p) = link(q);
  x_coord(p) = x_coord(q);
  y_coord(p) = y_coord(q);
  right_x(p) = right_x(q);
  right_y(p) = right_y(q);
  free_node(q, knot_node_size);
}
/* 410 */
void split_cubic (pointer p, fraction t, scaled xq, scaled yq)
{
  scaled v;
  pointer q, r;

  q = link(p);
  r = get_node(knot_node_size);
  link(p) = r;
  link(r) = q;
  left_type(r) = left_type(q);
  right_type(r) = right_type(p);
  v = t_of_the_way(right_x(p), left_x(q));
  right_x(p) = t_of_the_way(x_coord(p), right_x(p));
  left_x(q) = t_of_the_way(left_x(q), xq);
  left_x(r) = t_of_the_way(right_x(p), v);
  right_x(r) = t_of_the_way(v, left_x(q));
  x_coord(r) = t_of_the_way(left_x(r), right_x(r));
  v = t_of_the_way(right_y(p), left_y(q));
  right_y(p) = t_of_the_way(y_coord(p), right_y(p));
  left_y(q) = t_of_the_way(left_y(q), yq);
  left_y(r) = t_of_the_way(right_y(p), v);
  right_y(r) = t_of_the_way(v, left_y(q));
  y_coord(r) = t_of_the_way(left_y(r), right_y(r));
}
/* 406 */
void quadrant_subdivide (void)
{
  pointer p, q, r, s, pp, qq;
  scaled first_x, first_y;
  scaled del1, del2, del3, del, dmax;
  fraction t;
  scaled dest_x, dest_y;
  boolean constant_x;

  p = cur_spec;
  first_x = x_coord(cur_spec);
  first_y = y_coord(cur_spec);
  do {
l_continue:
    q = link(p);
    if (q == cur_spec)
    {
      dest_x = first_x;
      dest_y = first_y;
    }
    else
    {
      dest_x = x_coord(q);
      dest_y = y_coord(q);
    }
    del1 = right_x(p) - x_coord(p);
    del2 = left_x(q) - right_x(p);
    del3 = dest_x - left_x(q);
    if (del1 != 0)
      del = del1;
    else if (del2 != 0)
      del = del2;
    else
      del = del3;
    if (del != 0)
    {
      dmax = abs(del1);
      if (abs(del2) > dmax)
        dmax = abs(del2);
      if (abs(del3) > dmax)
        dmax = abs(del3);
      while (dmax < fraction_half)
      {
        _double(dmax);
        _double(del1);
        _double(del2);
        _double(del3);
      }
    }
    if (del == 0)
      constant_x = true;
    else
    {
      constant_x = false;
      if (del < 0)
      {
        negate(x_coord(p));
        negate(right_x(p));
        negate(left_x(q));
        negate(del1);
        negate(del2);
        negate(del3);
        negate(dest_x);
        right_type(p) = first_octant + negate_x;
      }
      t = crossing_point(del1, del2, del3);
      if (t < fraction_one)
      {
        split_cubic(p, t, dest_x, dest_y);
        r = link(p);
        if (right_type(r) > negate_x)
          right_type(r) = first_octant;
        else
          right_type(r) = first_octant + negate_x;
        if (x_coord(r) < x_coord(p))
          x_coord(r) = x_coord(p);
        left_x(r) = x_coord(r);
        if (right_x(p) > x_coord(r))
          right_x(p) = x_coord(r);
        negate(x_coord(r));
        right_x(r) = x_coord(r);
        negate(left_x(q));
        negate(dest_x);
        del2 = t_of_the_way(del2, del3);
        if (del2 > 0)
          del2 = 0;
        t = crossing_point(0, -del2, -del3);
        if (t < fraction_one)
        {
          split_cubic(r, t, dest_x, dest_y);
          s = link(r);
          if (x_coord(s) < dest_x)
            x_coord(s) = dest_x;
          if (x_coord(s) < x_coord(r))
            x_coord(s) = x_coord(r);
          right_type(s) = right_type(p);
          left_x(s) = x_coord(s);
          if (left_x(q) < dest_x)
            left_x(q) = -dest_x;
          else if (left_x(q) > x_coord(s))
            left_x(q) = -x_coord(s);
          else
            negate(left_x(q));
          negate(x_coord(s));
          right_x(s) = x_coord(s);
        }
        else
        {
          if (x_coord(r) > dest_x)
          {
            x_coord(r) = dest_x;
            left_x(r) = -x_coord(r);
            right_x(r) = x_coord(r);
          }
          if (left_x(q) > dest_x)
            left_x(q) = dest_x;
          else if (left_x(q) < x_coord(r))
            left_x(q) = x_coord(r);
        }
      }
    }
    pp = p;
    do {
      qq = link(pp);
      abnegate(x_coord(qq), y_coord(qq), right_type(qq), right_type(pp));
      dest_x = cur_x;
      dest_y = cur_y;
      del1 = right_y(pp) - y_coord(pp);
      del2 = left_y(qq) - right_y(pp);
      del3 = dest_y - left_y(qq);
      if (del1 != 0)
        del = del1;
      else if (del2 != 0)
        del = del2;
      else
        del = del3;
      if (del != 0)
      {
        dmax = abs(del1);
        if (abs(del2) > dmax)
          dmax = abs(del2);
        if (abs(del3) > dmax)
          dmax = abs(del3);
        while (dmax < fraction_half)
        {
          _double(dmax);
          _double(del1);
          _double(del2);
          _double(del3);
        }
      }
      if (del != 0)
      {
        if (del < 0)
        {
          negate(y_coord(pp));
          negate(right_y(pp));
          negate(left_y(qq));
          negate(del1);
          negate(del2);
          negate(del3);
          negate(dest_y);
          right_type(pp) = right_type(pp) + negate_y;
        }
        t = crossing_point(del1, del2, del3);
        if (t < fraction_one)
        {
          split_cubic(pp, t, dest_x, dest_y);
          r = link(pp);
          if (right_type(r) > negate_y)
            right_type(r) = right_type(r) - negate_y;
          else
            right_type(r) = right_type(r) + negate_y;
          if (y_coord(r) < y_coord(pp))
            y_coord(r) = y_coord(pp);
          left_y(r) = y_coord(r);
          if (right_y(pp) > y_coord(r))
            right_y(pp) = y_coord(r);
          negate(y_coord(r));
          right_y(r) = y_coord(r);
          negate(left_y(qq));
          negate(dest_y);
          if (x_coord(r) < x_coord(pp))
            x_coord(r) = x_coord(pp);
          else if (x_coord(r) > dest_x)
            x_coord(r) = dest_x;
          if (left_x(r) > x_coord(r))
          {
            left_x(r) = x_coord(r);
            if (right_x(pp) > x_coord(r))
              right_x(pp) = x_coord(r);
          }
          if (right_x(r) < x_coord(r))
          {
            right_x(r) = x_coord(r);
            if (left_x(qq) < x_coord(r))
              left_x(qq) = x_coord(r);
          }
          del2 = t_of_the_way(del2, del3);
          if (del2 > 0)
            del2 = 0;
          t = crossing_point(0, -del2, -del3);
          if (t < fraction_one)
          {
            split_cubic(r, t, dest_x, dest_y);
            s = link(r);
            if (y_coord(s) < dest_y)
              y_coord(s) = dest_y;
            if (y_coord(s) < y_coord(r))
              y_coord(s) = y_coord(r);
            right_type(s) = right_type(pp);
            left_y(s) = y_coord(s);
            if (left_y(qq) < dest_y)
              left_y(qq) = -dest_y;
            else if (left_y(qq) > y_coord(s))
              left_y(qq) = -y_coord(s);
            else
              negate(left_y(qq));
            negate(y_coord(s));
            right_y(s) = y_coord(s);
            if (x_coord(s) < x_coord(r))
              x_coord(s) = x_coord(r);
            else if (x_coord(s) > dest_x)
              x_coord(s) = dest_x;
            if (left_x(s) > x_coord(s))
            {
              left_x(s) = x_coord(s);
              if (right_x(r) > x_coord(s))
                right_x(r) = x_coord(s);
            }
            if (right_x(s) < x_coord(s))
            {
              right_x(s) = x_coord(s);
              if (left_x(qq) < x_coord(s))
                left_x(qq) = x_coord(s);
            }
          }
          else
          {
            if (y_coord(r) > dest_y)
            {
              y_coord(r) = dest_y;
              left_y(r) = -y_coord(r);
              right_y(r) = y_coord(r);
            }
            if (left_y(qq) > dest_y)
              left_y(qq) = dest_y;
            else if (left_y(qq) < y_coord(r))
              left_y(qq) = y_coord(r);
          }
        }
      }
      else if (constant_x)
      {
        if (q != p)
        {
          remove_cubic(p);
          if (cur_spec != q)
            goto l_continue;
          else
          {
            cur_spec = p;
            goto l_exit;
          }
        }
      }
      else if (!odd(right_type(pp)))
      {
        negate(y_coord(pp));
        negate(right_y(pp));
        negate(left_y(qq));
        negate(del1);
        negate(del2);
        negate(del3);
        negate(dest_y);
        right_type(pp) = right_type(pp) + negate_y;
      }
      pp = qq;
    } while (!(pp == q));
    if (constant_x)
    {
      pp = p;
      do {
        qq = link(pp);
        if (right_type(pp) > negate_y)
        {
          right_type(pp) = right_type(pp) + negate_x;
          negate(x_coord(pp));
          negate(right_x(pp));
          negate(left_x(qq));
        }
        pp = qq;
      } while (!(pp == q));
    }
    p = q;
  } while (!(p == cur_spec));
  l_exit:;
}
/* 419 */
void octant_subdivide (void)
{
  pointer p, q, r, s;
  scaled del1, del2, del3, del, dmax;
  fraction t;
  scaled dest_x, dest_y;

  p = cur_spec;
  do {
    q = link(p);
    x_coord(p) = x_coord(p) - y_coord(p);
    right_x(p) = right_x(p) - right_y(p);
    left_x(q) = left_x(q) - left_y(q);
    if (q == cur_spec)
    {
      unskew(x_coord(q), y_coord(q), right_type(q));
      skew(cur_x, cur_y, right_type(p));
      dest_x = cur_x;
      dest_y = cur_y;
    }
    else
    {
      abnegate(x_coord(q), y_coord(q), right_type(q), right_type(p));
      dest_x = cur_x - cur_y;
      dest_y = cur_y;
    }
    del1 = right_x(p) - x_coord(p);
    del2 = left_x(q) - right_x(p);
    del3 = dest_x - left_x(q);
    if (del1 != 0)
      del = del1;
    else if (del2 != 0)
      del = del2;
    else
      del = del3;
    if (del != 0)
    {
      dmax = abs(del1);
      if (abs(del2) > dmax)
        dmax = abs(del2);
      if (abs(del3) > dmax)
        dmax = abs(del3);
      while (dmax < fraction_half)
      {
        _double(dmax);
        _double(del1);
        _double(del2);
        _double(del3);
      }
    }
    if (del != 0)
    {
      if (del < 0)
      {
        y_coord(p) = x_coord(p) + y_coord(p);
        negate(x_coord(p));
        right_y(p) = right_x(p) + right_y(p);
        negate(right_x(p));
        left_y(q) = left_x(q) + left_y(q);
        negate(left_x(q));
        negate(del1);
        negate(del2);
        negate(del3);
        dest_y = dest_x + dest_y;
        negate(dest_x);
        right_type(p) = right_type(p) + switch_x_and_y;
      }
      t = crossing_point(del1, del2, del3);
      if (t < fraction_one)
      {
        split_cubic(p, t, dest_x, dest_y);
        r = link(p);
        if (right_type(r) > switch_x_and_y)
          right_type(r) = right_type(r) - switch_x_and_y;
        else
          right_type(r) = right_type(r) + switch_x_and_y;
        if (y_coord(r) < y_coord(p))
          y_coord(r) = y_coord(p);
        else if (y_coord(r) > dest_y)
          y_coord(r) = dest_y;
        if (x_coord(p) + y_coord(r) > dest_x + dest_y)
          y_coord(r) = dest_x + dest_y - x_coord(p);
        if (left_y(r) > y_coord(r))
        {
          left_y(r) = y_coord(r);
          if (right_y(p) > y_coord(r))
            right_y(p) = y_coord(r);
        }
        if (right_y(r) < y_coord(r))
        {
          right_y(r) = y_coord(r);
          if (left_y(q) < y_coord(r))
            left_y(q) = y_coord(r);
        }
        if (x_coord(r) < x_coord(p))
          x_coord(r) = x_coord(p);
        else if (x_coord(r) + y_coord(r) > dest_x + dest_y)
          x_coord(r) = dest_x + dest_y - y_coord(r);
        left_x(r) = x_coord(r);
        if (right_x(p) > x_coord(r))
          right_x(p) = x_coord(r);
        y_coord(r) = y_coord(r) + x_coord(r);
        right_y(r) = right_y(r) + x_coord(r);
        negate(x_coord(r));
        right_x(r) = x_coord(r);
        left_y(q) = left_y(q) + left_x(q);
        negate(left_x(q));
        dest_y = dest_y + dest_x;
        negate(dest_x);
        if (right_y(r) < y_coord(r))
        {
          right_y(r) = y_coord(r);
          if (left_y(q) < y_coord(r))
            left_y(q) = y_coord(r);
        }
        del2 = t_of_the_way(del2, del3);
        if (del2 > 0)
          del2 = 0;
        t = crossing_point(0, -del2, -del3);
        if (t < fraction_one)
        {
          split_cubic(r, t, dest_x, dest_y);
          s = link(r);
          if (y_coord(s) < y_coord(r))
            y_coord(s) = y_coord(r);
          else if (y_coord(s) > dest_y)
            y_coord(s) = dest_y;
          if (x_coord(r) + y_coord(s) > dest_x + dest_y)
            y_coord(s) = dest_x + dest_y - x_coord(r);
          if (left_y(s) > y_coord(s))
          {
            left_y(s) = y_coord(s);
            if (right_y(r) > y_coord(s))
              right_y(r) = y_coord(s);
          }
          if (right_y(s) < y_coord(s))
          {
            right_y(s) = y_coord(s);
            if (left_y(q) < y_coord(s))
              left_y(q) = y_coord(s);
          }
          if (x_coord(s) + y_coord(s) > dest_x + dest_y)
            x_coord(s) = dest_x + dest_y - y_coord(s);
          else
          {
            if (x_coord(s) < dest_x)
              x_coord(s) = dest_x;
            if (x_coord(s) < x_coord(r))
              x_coord(s) = x_coord(r);
          }
          right_type(s) = right_type(p);
          left_x(s) = x_coord(s);
          if (left_x(q) < dest_x)
          {
            left_y(q) = left_y(q) + dest_x;
            left_x(q) = -dest_x;
          }
          else if (left_x(q) > x_coord(s))
          {
            left_y(q) = left_y(q) + x_coord(s);
            left_x(q) = -x_coord(s);
          }
          else
          {
            left_y(q) = left_y(q) + left_x(q);
            negate(left_x(q));
          }
          y_coord(s) = y_coord(s) + x_coord(s);
          right_y(s) = right_y(s) + x_coord(s);
          negate(x_coord(s));
          right_x(s) = x_coord(s);
          if (right_y(s) < y_coord(s))
          {
            right_y(s) = y_coord(s);
            if (left_y(q) < y_coord(s))
              left_y(q) = y_coord(s);
          }
        }
        else
        {
          if (x_coord(r) > dest_x)
          {
            x_coord(r) = dest_x;
            left_x(r) = -x_coord(r);
            right_x(r) = x_coord(r);
          }
          if (left_x(q) > dest_x)
            left_x(q) = dest_x;
          else if (left_x(q) < x_coord(r))
            left_x(q) = x_coord(r);
        }
      }
    }
    p = q;
  } while (!(p == cur_spec));
}
/* 426 */
void make_safe (void)
{
  integer k;
  boolean all_safe;
  scaled next_a;
  scaled delta_a, delta_b;

  before[cur_rounding_ptr] = before[0];
  node_to_round[cur_rounding_ptr] = node_to_round[0];
  do {
    after[cur_rounding_ptr] = after[0];
    all_safe = true;
    next_a = after[0];
    for (k = 0; k <= cur_rounding_ptr - 1; k++)
    {
      delta_b = before[k + 1] - before[k];
      if (delta_b >= 0)
        delta_a = after[k + 1] - next_a;
      else
        delta_a = next_a - after[k + 1];
      next_a = after[k + 1];
      if ((delta_a < 0) || (delta_a > abs(delta_b + delta_b)))
      {
        all_safe = false;
        after[k] = before[k];
        if (k == cur_rounding_ptr - 1)
          after[0] = before[0];
        else
          after[k + 1] = before[k + 1];
      }
    }
  } while (!(all_safe));
}
/* 429 */
void before_and_after (scaled b, scaled a, pointer p)
{
  if (cur_rounding_ptr == max_rounding_ptr)
    if (max_rounding_ptr < max_wiggle)
      incr(max_rounding_ptr);
    else
      overflow("rounding table size", max_wiggle);
  after[cur_rounding_ptr] = a;
  before[cur_rounding_ptr] = b;
  node_to_round[cur_rounding_ptr] = p;
  incr(cur_rounding_ptr);
}
/* 431 */
scaled good_val (scaled b, scaled o)
{
  scaled a;

  a = b + o;
  if (a >= 0)
    a = a - (a % cur_gran) - o;
  else
    a = a + ((-(a + 1)) % cur_gran) - cur_gran + 1 - o;
  if (b - a < a + cur_gran - b)
    return a;
  else
    return a + cur_gran;
}
/* 432 */
scaled compromise (scaled u, scaled v)
{
  return half(good_val(u + u, -u - v));
}
/* 433 */
void xy_round (void)
{
  pointer p, q;
  scaled b, a;
  scaled pen_edge;
  fraction alpha;

  cur_gran = abs(internal[granularity]);
  if (cur_gran == 0)
    cur_gran = unity;
  p = cur_spec;
  cur_rounding_ptr = 0;
  do {
    q = link(p);
    if (odd(right_type(p)) != odd(right_type(q)))
    {
      if (odd(right_type(q)))
        b = x_coord(q);
      else
        b = -x_coord(q);
      if ((abs(x_coord(q) - right_x(q)) < 655) || (abs(x_coord(q) + left_x(q)) < 655))
      {
        if (cur_pen == null_pen)
          pen_edge = 0;
        else if (cur_path_type == double_path_code)
          pen_edge = compromise(east_edge(cur_pen), west_edge(cur_pen));
        else if (odd(right_type(q)))
          pen_edge = west_edge(cur_pen);
        else
          pen_edge = east_edge(cur_pen);
        a = good_val(b, pen_edge);
      }
      else
        a = b;
      if (abs(a) > max_allowed)
        if (a > 0)
          a = max_allowed;
        else
          a = -max_allowed;
      before_and_after(b, a, q);
    }
    p = q;
  } while (!(p == cur_spec));
  if (cur_rounding_ptr > 0)
  {
    make_safe();
    do {
      decr(cur_rounding_ptr);
      if ((after[cur_rounding_ptr] != before[cur_rounding_ptr]) || (after[cur_rounding_ptr + 1] != before[cur_rounding_ptr + 1]))
      {
        p = node_to_round[cur_rounding_ptr];
        if (odd(right_type(p)))
        {
          b = before[cur_rounding_ptr];
          a = after[cur_rounding_ptr];
        }
        else
        {
          b = -before[cur_rounding_ptr];
          a = -after[cur_rounding_ptr];
        }
        if (before[cur_rounding_ptr] == before[cur_rounding_ptr + 1])
          alpha = fraction_one;
        else
          alpha = make_fraction(after[cur_rounding_ptr + 1] - after[cur_rounding_ptr], before[cur_rounding_ptr + 1] - before[cur_rounding_ptr]);
        do {
          x_coord(p) = take_fraction(alpha, x_coord(p) - b) + a;
          right_x(p) = take_fraction(alpha, right_x(p) - b) + a;
          p = link(p);
          left_x(p) = take_fraction(alpha, left_x(p) - b) + a;
        } while (!(p == node_to_round[cur_rounding_ptr + 1]));
      }
    } while (!(cur_rounding_ptr == 0));
  }
  p = cur_spec;
  cur_rounding_ptr = 0;
  do {
    q = link(p);
    if ((right_type(p) > negate_y) != (right_type(q) > negate_y))
    {
      if (right_type(q) <= negate_y)
        b = y_coord(q);
      else
        b = -y_coord(q);
      if ((abs(y_coord(q) - right_y(q)) < 655) || (abs(y_coord(q) + left_y(q)) < 655))
      {
        if (cur_pen == null_pen)
          pen_edge = 0;
        else if (cur_path_type == double_path_code)
          pen_edge = compromise(north_edge(cur_pen), south_edge(cur_pen));
        else if (right_type(q) <= negate_y)
          pen_edge = south_edge(cur_pen);
        else
          pen_edge = north_edge(cur_pen);
        a = good_val(b, pen_edge);
      }
      else
        a = b;
      if (abs(a) > max_allowed)
        if (a > 0)
          a = max_allowed;
        else
          a = -max_allowed;
      before_and_after(b, a, q);
    }
    p = q;
  } while (!(p == cur_spec));
  if (cur_rounding_ptr > 0)
  {
    make_safe();
    do {
      decr(cur_rounding_ptr);
      if ((after[cur_rounding_ptr] != before[cur_rounding_ptr]) || (after[cur_rounding_ptr + 1] != before[cur_rounding_ptr + 1]))
      {
        p = node_to_round[cur_rounding_ptr];
        if (right_type(p) <= negate_y)
        {
          b = before[cur_rounding_ptr];
          a = after[cur_rounding_ptr];
        }
        else
        {
          b = -before[cur_rounding_ptr];
          a = -after[cur_rounding_ptr];
        }
        if (before[cur_rounding_ptr] == before[cur_rounding_ptr + 1])
          alpha = fraction_one;
        else
          alpha = make_fraction(after[cur_rounding_ptr + 1] - after[cur_rounding_ptr], before[cur_rounding_ptr + 1] - before[cur_rounding_ptr]);
        do {
          y_coord(p) = take_fraction(alpha, y_coord(p) - b) + a;
          right_y(p) = take_fraction(alpha, right_y(p) - b) + a;
          p = link(p);
          left_y(p) = take_fraction(alpha, left_y(p) - b) + a;
        } while (!(p == node_to_round[cur_rounding_ptr + 1]));
      }
    } while (!(cur_rounding_ptr == 0));
  }
}
/* 440 */
void diag_round (void)
{
  pointer p, q, pp;
  scaled b, a, bb, aa, d, c, dd, cc;
  scaled pen_edge;
  fraction alpha, beta;
  scaled next_a;
  boolean all_safe;
  integer k;
  scaled first_x, first_y;

  p = cur_spec;
  cur_rounding_ptr = 0;
  do {
    q = link(p);
    if (right_type(p) != right_type(q))
    {
      if (right_type(q) > switch_x_and_y)
        b = -x_coord(q);
      else
        b = x_coord(q);
      if (abs(right_type(q) - right_type(p)) == switch_x_and_y)
      {
        if ((abs(x_coord(q) - right_x(q)) < 655) || (abs(x_coord(q) + left_x(q)) < 655))
        {
          if (cur_pen == null_pen)
            pen_edge = 0;
          else if (cur_path_type == double_path_code)
            switch (right_type(q))
            {
              case first_octant:
              case second_octant:
                pen_edge = compromise(diag_offset(first_octant), -diag_offset(fifth_octant));
                break;
              case fifth_octant:
              case sixth_octant:
                pen_edge = -compromise(diag_offset(first_octant), -diag_offset(fifth_octant));
                break;
              case third_octant:
              case fourth_octant:
                pen_edge = compromise(diag_offset(fourth_octant), -diag_offset(eighth_octant));
                break;
              case seventh_octant:
              case eighth_octant:
                pen_edge = -compromise(diag_offset(fourth_octant), -diag_offset(eighth_octant));
                break;
            }
          else if (right_type(q) <= switch_x_and_y)
            pen_edge = diag_offset(right_type(q));
          else
            pen_edge = -diag_offset(right_type(q));
          if (odd(right_type(q)))
            a = good_val(b, pen_edge + half(cur_gran));
          else
            a = good_val(b - 1, pen_edge + half(cur_gran));
        }
        else
          a = b;
      }
      else
        a = b;
      before_and_after(b, a, q);
    }
    p = q;
  } while (!(p == cur_spec));
  if (cur_rounding_ptr > 0)
  {
    p = node_to_round[0];
    first_x = x_coord(p);
    first_y = y_coord(p);
    before[cur_rounding_ptr] = before[0];
    node_to_round[cur_rounding_ptr] = node_to_round[0];
    do {
      after[cur_rounding_ptr] = after[0];
      all_safe = true;
      next_a = after[0];
      for (k = 0; k <= cur_rounding_ptr - 1; k++)
      {
        a = next_a;
        b = before[k];
        next_a = after[k + 1];
        aa = next_a;
        bb = before[k + 1];
        if ((a != b) || (aa != bb))
        {
          p = node_to_round[k];
          pp = node_to_round[k + 1];
          if (aa == bb)
          {
            if (pp == node_to_round[0])
              unskew(first_x, first_y, right_type(pp));
            else
              unskew(x_coord(pp), y_coord(pp), right_type(pp));
            skew(cur_x, cur_y, right_type(p));
            bb = cur_x;
            aa = bb;
            dd = cur_y;
            cc = dd;
            if (right_type(p) > switch_x_and_y)
            {
              b = -b;
              a = -a;
            }
          }
          else
          {
            if (right_type(p) > switch_x_and_y)
            {
              bb = -bb;
              aa = -aa;
              b = -b;
              a = -a;
            }
            if (pp == node_to_round[0])
              dd = first_y - bb;
            else
              dd = y_coord(pp) - bb;
            if (odd(aa - bb))
              if (right_type(p) > switch_x_and_y)
                cc = dd - half(aa - bb + 1);
              else
                cc = dd - half(aa - bb - 1);
            else
              cc = dd - half(aa - bb);
          }
          d = y_coord(p);
          if (odd(a - b))
            if (right_type(p) > switch_x_and_y)
              c = d - half(a - b - 1);
            else
              c = d - half(a - b + 1);
          else
            c = d - half(a - b);
          if ((aa < a) || (cc < c) || (aa - a > 2 * (bb - b)) || (cc - c > 2 * (dd - d)))
          {
            all_safe = false;
            after[k] = before[k];
            if (k == cur_rounding_ptr - 1)
              after[0] = before[0];
            else
              after[k + 1] = before[k + 1];
          }
        }
      }
    } while (!(all_safe));
    for (k = 0; k <= cur_rounding_ptr - 1; k++)
    {
      a = after[k];
      b = before[k];
      aa = after[k + 1];
      bb = before[k + 1];
      if ((a != b) || (aa != bb))
      {
        p = node_to_round[k];
        pp = node_to_round[k + 1];
        if (aa == bb)
        {
          if (pp == node_to_round[0])
            unskew(first_x, first_y, right_type(pp));
          else
            unskew(x_coord(pp), y_coord(pp), right_type(pp));
          skew(cur_x, cur_y, right_type(p));
          bb = cur_x;
          aa = bb;
          dd = cur_y;
          cc = dd;
          if (right_type(p) > switch_x_and_y)
          {
            b = -b;
            a = -a;
          }
        }
        else
        {
          if (right_type(p) > switch_x_and_y)
          {
            bb = -bb;
            aa = -aa;
            b = -b;
            a = -a;
          }
          if (pp == node_to_round[0])
            dd = first_y - bb;
          else
            dd = y_coord(pp) - bb;
          if (odd(aa - bb))
            if (right_type(p) > switch_x_and_y)
              cc = dd - half(aa - bb + 1);
            else
              cc = dd - half(aa - bb - 1);
          else
            cc = dd - half(aa - bb);
        }
        d = y_coord(p);
        if (odd(a - b))
          if (right_type(p) > switch_x_and_y)
            c = d - half(a - b - 1);
          else
            c = d - half(a - b + 1);
        else
          c = d - half(a - b);
        if (b == bb)
          alpha = fraction_one;
        else
          alpha = make_fraction(aa - a, bb - b);
        if (d == dd)
          beta = fraction_one;
        else
          beta = make_fraction(cc - c, dd - d);
        do {
          x_coord(p) = take_fraction(alpha, x_coord(p) - b) + a;
          y_coord(p) = take_fraction(beta, y_coord(p) - d) + c;
          right_x(p) = take_fraction(alpha, right_x(p) - b) + a;
          right_y(p) = take_fraction(beta, right_y(p) - d) + c;
          p = link(p);
          left_x(p) = take_fraction(alpha, left_x(p) - b) + a;
          left_y(p) = take_fraction(beta, left_y(p) - d) + c;
        } while (!(p == pp));
      }
    }
  }
}
/* 451 */
void new_boundary (pointer p, small_number octant)
{
  pointer q, r;

  q = link(p);
  r = get_node(knot_node_size);
  link(r) = q;
  link(p) = r;
  left_type(r) = left_type(q);
  left_x(r) = left_x(q);
  left_y(r) = left_y(q);
  right_type(r) = endpoint;
  left_type(q) = endpoint;
  right_octant(r) = octant;
  left_octant(q) = right_type(q);
  unskew(x_coord(q), y_coord(q), right_type(q));
  skew(cur_x, cur_y, octant);
  x_coord(r) = cur_x;
  y_coord(r) = cur_y;
}
/* 402 */
pointer make_spec (pointer h, scaled safety_margin, integer tracing)
{
  pointer p, q, r, s;
  integer k;
  integer chopped;
  small_number o1, o2;
  boolean clockwise;
  integer dx1, dy1, dx2, dy2;
  integer dmax, del;

  cur_spec = h;
  if (tracing > 0)
    print_path(cur_spec, ", before subdivision into octants", true);
  max_allowed = fraction_one - half_unit - 1 - safety_margin;
  p = cur_spec;
  k = 1;
  chopped = 0;
  dmax = half(max_allowed);
  do {
    procrustes(left_x(p));
    procrustes(left_y(p));
    procrustes(x_coord(p));
    procrustes(y_coord(p));
    procrustes(right_x(p));
    procrustes(right_y(p));
    p = link(p);
    left_type(p) = k;
    if (k < max_quarterword)
      incr(k);
    else
      k = 1;
  } while (!(p == cur_spec));
  if (chopped > 0)
  {
    print_err("Curve out of range");
    help4("At least one of the coordinates in the path I'm about to",
      "digitize was really huge (potentially bigger than 4095).",
      "So I've cut it back to the maximum size.",
      "The results will probably be pretty wild.");
    put_get_error();
  }
  quadrant_subdivide();
  if ((internal[autorounding] > 0) && (chopped == 0))
    xy_round();
  octant_subdivide();
  if ((internal[autorounding] > unity) && (chopped == 0))
    diag_round();
  p = cur_spec;
  do {
  l_continue:
    q = link(p);
    if (p != q)
    {
      if (x_coord(p) == right_x(p))
        if (y_coord(p) == right_y(p))
          if (x_coord(p) == left_x(q))
            if (y_coord(p) == left_y(q))
            {
              unskew(x_coord(q), y_coord(q), right_type(q));
              skew(cur_x, cur_y, right_type(p));
              if (x_coord(p) == cur_x)
                if (y_coord(p) == cur_y)
                {
                  remove_cubic(p);
                  if (q != cur_spec)
                    goto l_continue;
                  cur_spec = p;
                  q = p;
                }
            }
    }
    p = q;
  } while (!(p == cur_spec));
  turning_number = 0;
  p = cur_spec;
  q = link(p);
  do {
    r = link(q);
    if ((right_type(p) != right_type(q)) || (q == r))
    {
      new_boundary(p, right_type(p));
      s = link(p);
      o1 = octant_number[right_type(p)];
      o2 = octant_number[right_type(q)];
      switch (o2 - o1)
      {
        case 1:
        case -7:
        case 7:
        case -1:
          goto done;
          break;
        case 2:
        case -6:
          clockwise = false;
          break;
        case 3:
        case -5:
        case 4:
        case -4:
        case 5:
        case -3:
          {
            dx1 = x_coord(s) - left_x(s);
            dy1 = y_coord(s) - left_y(s);
            if (dx1 == 0)
              if (dy1 == 0)
              {
                dx1 = x_coord(s) - right_x(p);
                dy1 = y_coord(s) - right_y(p);
                if (dx1 == 0)
                  if (dy1 == 0)
                  {
                    dx1 = x_coord(s) - x_coord(p);
                    dy1 = y_coord(s) - y_coord(p);
                  }
              }
            dmax = abs(dx1);
            if (abs(dy1) > dmax)
              dmax = abs(dy1);
            while (dmax < fraction_one)
            {
              _double(dmax);
              _double(dx1);
              _double(dy1);
            }
            dx2 = right_x(q) - x_coord(q);
            dy2 = right_y(q) - y_coord(q);
            if (dx2 == 0)
              if (dy2 == 0)
              {
                dx2 = left_x(r) - x_coord(q);
                dy2 = left_y(r) - y_coord(q);
                if (dx2 == 0)
                  if (dy2 == 0)
                  {
                    if (right_type(r) == endpoint)
                    {
                      cur_x = x_coord(r);
                      cur_y = y_coord(r);
                    }
                    else
                    {
                      unskew(x_coord(r), y_coord(r), right_type(r));
                      skew(cur_x, cur_y, right_type(q));
                    }
                    dx2 = cur_x - x_coord(q);
                    dy2 = cur_y - y_coord(q);
                  }
              }
            dmax = abs(dx2);
            if (abs(dy2) > dmax)
              dmax = abs(dy2);
            while (dmax < fraction_one)
            {
              _double(dmax);
              _double(dx2);
              _double(dy2);
            }
            unskew(dx1, dy1, right_type(p));
            del = pyth_add(cur_x, cur_y);
            dx1 = make_fraction(cur_x, del);
            dy1 = make_fraction(cur_y, del);
            unskew(dx2, dy2, right_type(q));
            del = pyth_add(cur_x, cur_y);
            dx2 = make_fraction(cur_x, del);
            dy2 = make_fraction(cur_y, del);
            del = take_fraction(dx1, dy2) - take_fraction(dx2, dy1);
            if (del > 4684844)
              clockwise = false;
            else if (del < -4684844)
              clockwise = true;
            else
              clockwise = rev_turns;
          }
          break;
        case 6:
        case -2:
          clockwise = true;
          break;
        case 0:
          clockwise = rev_turns;
          break;
      }
      while (true)
      {
        if (clockwise)
          if (o1 == 1)
            o1 = 8;
          else
            decr(o1);
        else if (o1 == 8)
          o1 = 1;
        else
          incr(o1);
        if (o1 == o2)
          goto done;
        new_boundary(s, octant_code[o1]);
        s = link(s);
        left_octant(s) = right_octant(s);
      }
done:
      if (q == r)
      {
        q = link(q);
        r = q;
        p = s;
        link(s) = q;
        left_octant(q) = right_octant(q);
        left_type(q) = endpoint;
        free_node(cur_spec, knot_node_size);
        cur_spec = q;
      }
      p = link(p);
      do {
        s = link(p);
        o1 = octant_number[right_octant(p)];
        o2 = octant_number[left_octant(s)];
        if (abs(o1 - o2) == 1)
        {
          if (o2 < o1)
            o2 = o1;
          if (odd(o2))
            right_transition(p) = axis;
          else
            right_transition(p) = diagonal;
        }
        else
        {
          if (o1 == 8)
            incr(turning_number);
          else
            decr(turning_number);
          right_transition(p) = axis;
        }
        left_transition(s) = right_transition(p);
        p = s;
      } while (!(p == q));
    }
    p = q;
    q = r;
  } while (!(p == cur_spec));
  while (left_type(cur_spec) != endpoint)
    cur_spec = link(cur_spec);
  if (tracing > 0)
  {
    if ((internal[autorounding] <= 0) || (chopped != 0))
      print_spec(", after subdivision");
    else if (internal[autorounding] > unity)
      print_spec(", after subdivision and double autorounding");
    else
      print_spec(", after subdivision and autorounding");
  }
  return cur_spec;
}
/* 463 */
void end_round (scaled x, scaled y)
{
  y = y + half_unit - y_corr[octant];
  x = x + y - x_corr[octant];
  m1 = floor_unscaled(x);
  n1 = floor_unscaled(y);
  if (x - unity * m1 >= y - unity * n1 + z_corr[octant])
    d1 = 1;
  else
    d1 = 0;
}
/* 465 */
void fill_spec (pointer h)
{
  pointer p, q, r, s;

  if (internal[tracing_edges] > 0)
    begin_edge_tracing();
  p = h;
  do {
    octant = left_octant(p);
    q = p;
    while (right_type(q) != endpoint)
      q = link(q);
    if (q != p)
    {
      end_round(x_coord(p), y_coord(p));
      m0 = m1;
      n0 = n1;
      d0 = d1;
      end_round(x_coord(q), y_coord(q));
      if (n1 - n0 >= move_size)
        overflow("move table size", move_size);
      move[0] = d0;
      move_ptr = 0;
      r = p;
      do {
        s = link(r);
        make_moves(x_coord(r), right_x(r), left_x(s), x_coord(s),
          y_coord(r) + half_unit, right_y(r) + half_unit, left_y(s) + half_unit, y_coord(s) + half_unit,
          xy_corr[octant], y_corr[octant]);
        r = s;
      } while (!(r == q));
      move[move_ptr] = move[move_ptr] - d1;
      if (internal[smoothing] > 0)
        smooth_moves(0, move_ptr);
      move_to_edges(m0, n0, m1, n1);
    }
    p = link(q);
  } while (!(p == h));
  toss_knot_list(h);
  if (internal[tracing_edges] > 0)
    end_edge_tracing();
}
/* 476 */
void dup_offset (pointer w)
{
  pointer r;

  r = get_node(coord_node_size);
  x_coord(r) = x_coord(w);
  y_coord(r) = y_coord(w);
  link(r) = link(w);
  knil(link(w)) = r;
  knil(r) = w;
  link(w) = r;
}
/* 477 */
pointer make_pen (pointer h)
{
  small_number o, oo, k;
  pointer p;
  pointer q, r, s, w, hh;
  integer n;
  scaled dx, dy;
  scaled mc;

  q = h;
  r = link(q);
  mc = abs(x_coord(h));
  if (q == r)
  {
    hh = h;
    right_type(h) = 0;
    if (mc < abs(y_coord(h)))
      mc = abs(y_coord(h));
  }
  else
  {
    o = 0;
    hh = null;
    while (true)
    {
      s = link(r);
      if (mc < abs(x_coord(r)))
        mc = abs(x_coord(r));
      if (mc < abs(y_coord(r)))
        mc = abs(y_coord(r));
      dx = x_coord(r) - x_coord(q);
      dy = y_coord(r) - y_coord(q);
      if (dx == 0)
        if (dy == 0)
          goto not_found;
      if (ab_vs_cd(dx, y_coord(s) - y_coord(r), dy, x_coord(s) - x_coord(r)) < 0)
        goto not_found;
      if (dx > 0)
        octant = first_octant;
      else if (dx == 0)
        if (dy > 0)
          octant = first_octant;
        else
          octant = first_octant + negate_x;
      else
      {
        negate(dx);
        octant = first_octant + negate_x;
      }
      if (dy < 0)
      {
        negate(dy);
        octant = octant + negate_y;
      }
      else if (dy == 0)
        if (octant > first_octant)
          octant = first_octant + negate_x + negate_y;
      if (dx < dy)
        octant = octant + switch_x_and_y;
      right_type(q) = octant;
      oo = octant_number[octant];
      if (o > oo)
      {
        if (hh != null)
          goto not_found;
        hh = q;
      }
      o = oo;
      if ((q == h) && (hh != null))
        goto done;
      q = r;
      r = s;
    }
    done:;
  }
  if (mc >= fraction_one - half_unit)
    goto not_found;
  p = get_node(pen_node_size);
  q = hh;
  max_offset(p) = mc;
  ref_count(p) = null;
  if (link(q) != q)
    link(p) = null + 1;
  for (k = 1; k <= 8; k++)
  {
    octant = octant_code[k];
    n = 0;
    h = p + octant;
    while (true)
    {
      r = get_node(coord_node_size);
      skew(x_coord(q), y_coord(q), octant);
      x_coord(r) = cur_x;
      y_coord(r) = cur_y;
      if (n == 0)
        link(h) = r;
      else if (odd(k))
      {
        link(w) = r;
        knil(r) = w;
      }
      else
      {
        knil(w) = r;
        link(r) = w;
      }
      w = r;
      if (right_type(q) != octant)
        goto done1;
      q = link(q);
      incr(n);
    }
  done1:
    r = link(h);
    if (odd(k))
    {
      link(w) = r;
      knil(r) = w;
    }
    else
    {
      knil(w) = r;
      link(r) = w;
      link(h) = w;
      r = w;
    }
    if ((y_coord(r) != y_coord(link(r))) || (n == 0))
    {
      dup_offset(r);
      incr(n);
    }
    r = knil(r);
    if (x_coord(r) != x_coord(knil(r)))
      dup_offset(r);
    else
      decr(n);
    if (n >= max_quarterword)
      overflow("pen polygon size", max_quarterword);
    info(h) = n;
  }
  goto found;
not_found:
  p = null_pen;
  if (mc >= fraction_one - half_unit)
  {
    print_err("Pen too large");
    help2("The cycle you specified has a coordinate of 4095.5 or more.",
      "So I've replaced it by the trivial path `(0,0)..cycle'.");
  }
  else
  {
    print_err("Pen cycle must be convex");
    help3("The cycle you specified either has consecutive equal points",
      "or turns right or turns through more than 360 degrees.",
      "So I've replaced it by the trivial path `(0,0)..cycle'.");
  }
  put_get_error();
found:
  if (internal[tracing_pens] > 0)
    print_pen(p, " (newly created)", true);
  return p;
}
/* 486 */
pointer trivial_knot (scaled x, scaled y)
{
  pointer p;

  p = get_node(knot_node_size);
  left_type(p) = explicit;
  right_type(p) = explicit;
  x_coord(p) = x;
  left_x(p) = x;
  right_x(p) = x;
  y_coord(p) = y;
  left_y(p) = y;
  right_y(p) = y;
  return p;
}
/* 484 */
pointer make_path (pointer pen_head)
{
  pointer p;
  unsigned char k;
  pointer h;
  integer m, n;
  pointer w, ww;

  p = temp_head;
  for (k = 1; k <= 8; k++)
  {
    octant = octant_code[k];
    h = pen_head + octant;
    n = info(h);
    w = link(h);
    if (!odd(k))
      w = knil(w);
    for (m = 1; m <= n + 1; m++)
    {
      if (odd(k))
        ww = link(w);
      else
        ww = knil(w);
      if ((x_coord(ww) != x_coord(w)) || (y_coord(ww) != y_coord(w)))
      {
        unskew(x_coord(ww), y_coord(ww), octant);
        link(p) = trivial_knot(cur_x, cur_y);
        p = link(p);
      }
      w = ww;
    }
  }
  if (p == temp_head)
  {
    w = link(pen_head + first_octant);
    p = trivial_knot(x_coord(w) + y_coord(w), y_coord(w));
    link(temp_head) = p;
  }
  link(p) = link(temp_head);
  return link(temp_head);
}
/* 488 */
void find_offset (scaled x, scaled y, pointer p)
{
  unsigned char octant;
  int8_t s;
  integer n;
  pointer h, w, ww;

  if (x > 0)
    octant = first_octant;
  else if (x == 0)
    if (y <= 0)
      if (y == 0)
      {
        cur_x = 0;
        cur_y = 0;
        goto l_exit;
      }
      else
        octant = first_octant + negate_x;
    else
      octant = first_octant;
  else
  {
    x = -x;
    if (y == 0)
      octant = first_octant + negate_x + negate_y;
    else
      octant = first_octant + negate_x;
  }
  if (y < 0)
  {
    octant = octant + negate_y;
    y = -y;
  }
  if (x >= y)
    x = x - y;
  else
  {
    octant = octant + switch_x_and_y;
    x = y - x;
    y = y - x;
  }
  if (odd(octant_number[octant]))
    s = -1;
  else
    s = 1;
  h = p + octant;
  w = link(link(h));
  ww = link(w);
  n = info(h);
  while (n > 1)
  {
    if (ab_vs_cd(x, y_coord(ww) - y_coord(w), y, x_coord(ww) - x_coord(w)) != s)
      goto done;
    w = ww;
    ww = link(w);
    decr(n);
  }
done:
  unskew(x_coord(w), y_coord(w), octant);
l_exit:;
}
/* 493 */
void split_for_offset (pointer p, fraction t)
{
  pointer q;
  pointer r;

  q = link(p);
  split_cubic(p, t, x_coord(q), y_coord(q));
  r = link(p);
  if (y_coord(r) < y_coord(p))
    y_coord(r) = y_coord(p);
  else if (y_coord(r) > y_coord(q))
    y_coord(r) = y_coord(q);
  if (x_coord(r) < x_coord(p))
    x_coord(r) = x_coord(p);
  else if (x_coord(r) > x_coord(q))
    x_coord(r) = x_coord(q);
}
/* 497 */
void fin_offset_prep (pointer p, halfword k, pointer w, integer x0, integer x1, integer x2, integer y0, integer y1, integer y2, boolean rising, integer n)
{
  pointer ww;
  scaled du, dv;
  integer t0, t1, t2;
  fraction t;
  fraction s;
  integer v;

  while (true)
  {
    right_type(p) = k;
    if (rising)
      if (k == n)
        goto l_exit;
      else
        ww = link(w);
    else if (k == 1)
      goto l_exit;
    else
      ww = knil(w);
    du = x_coord(ww) - x_coord(w);
    dv = y_coord(ww) - y_coord(w);
    if (abs(du) >= abs(dv))
    {
      s = make_fraction(dv, du);
      t0 = take_fraction(x0, s) - y0;
      t1 = take_fraction(x1, s) - y1;
      t2 = take_fraction(x2, s) - y2;
    }
    else
    {
      s = make_fraction(du, dv);
      t0 = x0 - take_fraction(y0, s);
      t1 = x1 - take_fraction(y1, s);
      t2 = x2 - take_fraction(y2, s);
    }
    t = crossing_point(t0, t1, t2);
    if (t >= fraction_one)
      goto l_exit;
    {
      split_for_offset(p, t);
      right_type(p) = k;
      p = link(p);
      v = t_of_the_way(x0, x1);
      x1 = t_of_the_way(x1, x2);
      x0 = t_of_the_way(v, x1);
      v = t_of_the_way(y0, y1);
      y1 = t_of_the_way(y1, y2);
      y0 = t_of_the_way(v, y1);
      t1 = t_of_the_way(t1, t2);
      if (t1 > 0)
        t1 = 0;
      t = crossing_point(0, -t1, -t2);
      if (t < fraction_one)
      {
        split_for_offset(p, t);
        right_type(link(p)) = k;
        v = t_of_the_way(x1, x2);
        x1 = t_of_the_way(x0, x1);
        x2 = t_of_the_way(x1, v);
        v = t_of_the_way(y1, y2);
        y1 = t_of_the_way(y0, y1);
        y2 = t_of_the_way(y1, v);
      }
    }
    if (rising)
      incr(k);
    else
      decr(k);
    w = ww;
  }
l_exit:;
}
/* 491 */
void offset_prep (pointer c, pointer h)
{
  halfword n;
  pointer p, q, r, lh, ww;
  halfword k;
  pointer w;
  integer x0, x1, x2, y0, y1, y2;
  integer t0, t1, t2;
  integer du, dv, dx, dy;
  integer max_coef;
  integer x0a, x1a, x2a, y0a, y1a, y2a;
  fraction t;
  fraction s;

  p = c;
  n = info(h);
  lh = link(h);
  while (right_type(p) != endpoint)
  {
    q = link(p);
    if (n <= 1)
      right_type(p) = 1;
    else
    {
      x0 = right_x(p) - x_coord(p);
      x2 = x_coord(q) - left_x(q);
      x1 = left_x(q) - right_x(p);
      y0 = right_y(p) - y_coord(p);
      y2 = y_coord(q) - left_y(q);
      y1 = left_y(q) - right_y(p);
      max_coef = abs(x0);
      if (abs(x1) > max_coef)
        max_coef = abs(x1);
      if (abs(x2) > max_coef)
        max_coef = abs(x2);
      if (abs(y0) > max_coef)
        max_coef = abs(y0);
      if (abs(y1) > max_coef)
        max_coef = abs(y1);
      if (abs(y2) > max_coef)
        max_coef = abs(y2);
      if (max_coef == 0)
        goto not_found;
      while (max_coef < fraction_half)
      {
        _double(max_coef);
        _double(x0);
        _double(x1);
        _double(x2);
        _double(y0);
        _double(y1);
        _double(y2);
      }
      dx = x0;
      dy = y0;
      if (dx == 0)
        if (dy == 0)
        {
          dx = x1;
          dy = y1;
          if (dx == 0)
            if (dy == 0)
            {
              dx = x2;
              dy = y2;
            }
        }
      if (dx == 0)
        fin_offset_prep(p, n, knil(knil(lh)), -x0, -x1, -x2, -y0, -y1, -y2, false, n);
      else
      {
        k = 1;
        w = link(lh);
        while (true)
        {
          if (k == n)
            goto done;
          ww = link(w);
          if (ab_vs_cd(dy, abs(x_coord(ww) - x_coord(w)), dx, abs(y_coord(ww) - y_coord(w))) >= 0)
          {
            incr(k);
            w = ww;
          }
          else
            goto done;
        }
        done:;
        if (k == 1)
          t = fraction_one + 1;
        else
        {
          ww = knil(w);
          du = x_coord(ww) - x_coord(w);
          dv = y_coord(ww) - y_coord(w);
          if (abs(du) >= abs(dv))
          {
            s = make_fraction(dv, du);
            t0 = take_fraction(x0, s) - y0;
            t1 = take_fraction(x1, s) - y1;
            t2 = take_fraction(x2, s) - y2;
          }
          else
          {
            s = make_fraction(du, dv);
            t0 = x0 - take_fraction(y0, s);
            t1 = x1 - take_fraction(y1, s);
            t2 = x2 - take_fraction(y2, s);
          }
          t = crossing_point(-t0, -t1, -t2);
        }
        if (t >= fraction_one)
          fin_offset_prep(p, k, w, x0, x1, x2, y0, y1, y2, true, n);
        else
        {
          split_for_offset(p, t);
          r = link(p);
          x1a = t_of_the_way(x0, x1);
          x1 = t_of_the_way(x1, x2);
          x2a = t_of_the_way(x1a, x1);
          y1a = t_of_the_way(y0, y1);
          y1 = t_of_the_way(y1, y2);
          y2a = t_of_the_way(y1a, y1);
          fin_offset_prep(p, k, w, x0, x1a, x2a, y0, y1a, y2a, true, n);
          x0 = x2a;
          y0 = y2a;
          t1 = t1 - take_fraction(t1 - t2, t);
          if (t1 < 0)
            t1 = 0;
          t = crossing_point(0, t1, t2);
          if (t < fraction_one)
          {
            split_for_offset(r, t);
            x1a = t_of_the_way(x1, x2);
            x1 = t_of_the_way(x0, x1);
            x0a = t_of_the_way(x1, x1a);
            y1a = t_of_the_way(y1, y2);
            y1 = t_of_the_way(y0, y1);
            y0a = t_of_the_way(y1, y1a);
            fin_offset_prep(link(r), k, w, x0a, x1a, x2, y0a, y1a, y2, true, n);
            x2 = x0a;
            y2 = y0a;
          }
          fin_offset_prep(r, k - 1, ww, -x0, -x1, -x2, -y0, -y1, -y2 , false, n);
        }
      }
      not_found:;
    }
    do {
      r = link(p);
      if (x_coord(p) == right_x(p))
        if (y_coord(p) == right_y(p))
          if (x_coord(p) == left_x(r))
            if (y_coord(p) == left_y(r))
              if (x_coord(p) == x_coord(r))
                if (y_coord(p) == y_coord(r))
                {
                  remove_cubic(p);
                  if (r == q)
                    q = p;
                  r = p;
                }
      p = r;
    } while (!(p == q));
  }
}
/* 510 */
void skew_line_edges (pointer p, pointer w, pointer ww)
{
  scaled x0, y0, x1, y1;

  if ((x_coord(w) != x_coord(ww)) || (y_coord(w) != y_coord(ww)))
  {
    x0 = x_coord(p) + x_coord(w);
    y0 = y_coord(p) + y_coord(w);
    x1 = x_coord(p) + x_coord(ww);
    y1 = y_coord(p) + y_coord(ww);
    unskew(x0, y0, octant);
    x0 = cur_x;
    y0 = cur_y;
    unskew(x1, y1, octant);
#ifdef STAT
    if (internal[tracing_edges] > unity)
    {
      r_print_nl("@ retrograde line from ");
      print_two(x0, y0);
      r_print(" to ");
      print_two(cur_x, cur_y);
      r_print_nl("");
    }
#endif
    line_edges(x0, y0, cur_x, cur_y);
  }
}
/* 518 */
void dual_moves (pointer h, pointer p, pointer q)
{
  pointer r, s;
  integer m, n;
  integer mm0, mm1;
  integer k;
  pointer w, ww;
  integer smooth_bot, smooth_top;
  scaled xx, yy, xp, yp, delx, dely, tx, ty;

  k = info(h) + 1;
  ww = link(h);
  w = knil(ww);
  mm0 = floor_unscaled(x_coord(p) + x_coord(w) - xy_corr[octant]);
  mm1 = floor_unscaled(x_coord(q) + x_coord(ww) - xy_corr[octant]);
  for (n = 1; n <= n1 - n0 + 1; n++)
    env_move[n] = mm1;
  env_move[0] = mm0;
  move_ptr = 0;
  m = mm0;
  r = p;
  while (true)
  {
    if (r == q)
      smooth_top = move_ptr;
    while (right_type(r) != k)
    {
      xx = x_coord(r) + x_coord(w);
      yy = y_coord(r) + y_coord(w) + half_unit;
#ifdef STAT
      if (internal[tracing_edges] > unity)
      {
        r_print_nl("@ transition line ");
        print_int(k);
        r_print(", from ");
        print_two_true(xx, yy - half_unit);
      }
#endif
      if (right_type(r) < k)
      {
        decr(k);
        w = knil(w);
        xp = x_coord(r) + x_coord(w);
        yp = y_coord(r) + y_coord(w) + half_unit;
        if (yp != yy)
        {
          ty = floor_scaled(yy - y_corr[octant]);
          dely = yp - yy;
          yy = yy - ty;
          ty = yp - y_corr[octant] - ty;
          if (ty >= unity)
          {
            delx = xp - xx;
            yy = unity - yy;
            while (true)
            {
              if (m < env_move[move_ptr])
                env_move[move_ptr] = m;
              tx = take_fraction(delx, make_fraction(yy, dely));
              if (ab_vs_cd(tx, dely, delx, yy) + xy_corr[octant] > 0)
                decr(tx);
              m = floor_unscaled(xx + tx);
              ty = ty - unity;
              incr(move_ptr);
              if (ty < unity)
                goto done1;
              yy = yy + unity;
            }
          done1:
            if (m < env_move[move_ptr])
              env_move[move_ptr] = m;
          }
        }
      }
      else
      {
        incr(k);
        w = link(w);
        xp = x_coord(r) + x_coord(w);
        yp = y_coord(r) + y_coord(w) + half_unit;
      }
#ifdef STAT
      if (internal[tracing_edges] > unity)
      {
        r_print(" to ");
        print_two_true(xp, yp - half_unit);
        r_print_nl("");
      }
#endif
      m = floor_unscaled(xp - xy_corr[octant]);
      move_ptr = floor_unscaled(yp - y_corr[octant]) - n0;
      if (m < env_move[move_ptr])
        env_move[move_ptr] = m;
    }
    if (r == p)
      smooth_bot = move_ptr;
    if (r == q)
      goto done;
    move[move_ptr] = 1;
    n = move_ptr;
    s = link(r);
    make_moves(x_coord(r) + x_coord(w), right_x(r) + x_coord(w), left_x(s) + x_coord(w),
      x_coord(s) + x_coord(w), y_coord(r) + y_coord(w) + half_unit, right_y(r) +
      y_coord(w) + half_unit, left_y(s) + y_coord(w) + half_unit, y_coord(s) + y_coord(w)
      + half_unit, xy_corr[octant], y_corr[octant]);
    do {
      if (m < env_move[n])
        env_move[n] = m;
      m = m + move[n] - 1;
      incr(n);
    } while (!(n > move_ptr));
    r = s;
  }
done:
#ifdef DEBUG
  if ((m != mm1) || (move_ptr != n1 - n0))
    confusion("2");
#endif
  move[0] = d0 + env_move[1] - mm0;
  for (n = 1; n <= move_ptr; n++)
    move[n] = env_move[n + 1] - env_move[n] + 1;
  move[move_ptr] = move[move_ptr] - d1;
  if (internal[smoothing] > 0)
    smooth_moves(smooth_bot, smooth_top);
  move_to_edges(m0, n0, m1, n1);
  if (right_transition(q) == diagonal)
  {
    w = link(h);
    skew_line_edges(q, w, knil(w));
  }
}
/* 506 */
void fill_envelope (pointer spec_head)
{
  pointer p, q, r, s;
  pointer h;
  pointer www;
  integer m, n;
  integer mm0, mm1;
  integer k;
  pointer w, ww;
  integer smooth_bot, smooth_top;
  scaled xx, yy, xp, yp, delx, dely, tx, ty;

  if (internal[tracing_edges] > 0)
    begin_edge_tracing();
  p = spec_head;
  do {
    octant = left_octant(p);
    h = cur_pen + octant;
    q = p;
    while (right_type(q) != endpoint)
      q = link(q);
    w = link(h);
    if (left_transition(p) == diagonal)
      w = knil(w);
#ifdef STAT
    if (internal[tracing_edges] > unity)
    {
      r_print_nl("@ Octant ");
      print(octant_dir[octant]);
      r_print(" (");
      print_int(info(h));
      r_print(" offset");
      if (info(h) != 1)
        print_char('s');
      r_print("), from ");
      print_two_true(x_coord(p) + x_coord(w), y_coord(p) + y_coord(w));
      ww = link(h);
      if (right_transition(q) == diagonal)
        ww = knil(ww);
      r_print(" to ");
      print_two_true(x_coord(q) + x_coord(ww), y_coord(q) + y_coord(ww));
    }
#endif
    ww = link(h);
    www = ww;
    if (odd(octant_number[octant]))
      www = knil(www);
    else
      ww = knil(ww);
    if (w != ww)
      skew_line_edges(p, w, ww);
    end_round(x_coord(p) + x_coord(ww), y_coord(p) + y_coord(ww));
    m0 = m1;
    n0 = n1;
    d0 = d1;
    end_round(x_coord(q) + x_coord(www), y_coord(q) + y_coord(www));
    if (n1 - n0 >= move_size)
      overflow("move table size", move_size);
    offset_prep(p, h);
    q = p;
    while (right_type(q) != endpoint)
      q = link(q);
    if (odd(octant_number[octant]))
    {
      k = 0;
      w = link(h);
      ww = knil(w);
      mm0 = floor_unscaled(x_coord(p) + x_coord(w) - xy_corr[octant]);
      mm1 = floor_unscaled(x_coord(q) + x_coord(ww) - xy_corr[octant]);
      for (n = 0; n <= n1 - n0; n++)
        env_move[n] = mm0;
      env_move[n1 - n0] = mm1;
      move_ptr = 0;
      m = mm0;
      r = p;
      right_type(q) = info(h) + 1;
      while (true)
      {
        if (r == q)
          smooth_top = move_ptr;
        while (right_type(r) != k)
        {
          xx = x_coord(r) + x_coord(w);
          yy = y_coord(r) + y_coord(w) + half_unit;
#ifdef STAT
          if (internal[tracing_edges] > unity)
          {
            r_print_nl("@ transition line ");
            print_int(k);
            r_print(", from ");
            print_two_true(xx, yy - half_unit);
          }
#endif
          if (right_type(r) > k)
          {
            incr(k);
            w = link(w);
            xp = x_coord(r) + x_coord(w);
            yp = y_coord(r) + y_coord(w) + half_unit;
            if (yp != yy)
            {
              ty = floor_scaled(yy - y_corr[octant]);
              dely = yp - yy;
              yy = yy - ty;
              ty = yp - y_corr[octant] - ty;
              if (ty >= unity)
              {
                delx = xp - xx;
                yy = unity - yy;
                while (true)
                {
                  tx = take_fraction(delx, make_fraction(yy, dely));
                  if (ab_vs_cd(tx, dely, delx, yy) + xy_corr[octant] > 0)
                    decr(tx);
                  m = floor_unscaled(xx + tx);
                  if (m > env_move[move_ptr])
                    env_move[move_ptr] = m;
                  ty = ty - unity;
                  if (ty < unity)
                    goto done1;
                  yy = yy + unity;
                  incr(move_ptr);
                }
                done1:;
              }
            }
          }
          else
          {
            decr(k);
            w = knil(w);
            xp = x_coord(r) + x_coord(w);
            yp = y_coord(r) + y_coord(w) + half_unit;
          }
#ifdef STAT
          if (internal[tracing_edges] > unity)
          {
            r_print(" to ");
            print_two_true(xp, yp - half_unit);
            r_print_nl("");
          }
#endif
          m = floor_unscaled(xp - xy_corr[octant]);
          move_ptr = floor_unscaled(yp - y_corr[octant]) - n0;
          if (m > env_move[move_ptr])
            env_move[move_ptr] = m;
        }
        if (r == p)
          smooth_bot = move_ptr;
        if (r == q)
          goto done;
        move[move_ptr] = 1;
        n = move_ptr;
        s = link(r);
        make_moves(x_coord(r) + x_coord(w), right_x(r) + x_coord(w), left_x(s) + x_coord(w),
          x_coord(s) + x_coord(w), y_coord(r) + y_coord(w) + half_unit, right_y(r) +
          y_coord(w) + half_unit, left_y(s) + y_coord(w) + half_unit, y_coord(s) + y_coord(w) + half_unit,
          xy_corr[octant], y_corr[octant]);
        do {
          m = m + move[n] - 1;
          if (m > env_move[n])
            env_move[n] = m;
          incr(n);
        } while (!(n > move_ptr));
        r = s;
      }
    done:
#ifdef DEBUG
      if ((m != mm1) || (move_ptr != n1 - n0))
        confusion("1");
#endif
      move[0] = d0 + env_move[0] - mm0;
      for (n = 1; n <= move_ptr; n++)
        move[n] = env_move[n] - env_move[n - 1] + 1;
      move[move_ptr] = move[move_ptr] - d1;
      if (internal[smoothing] > 0)
        smooth_moves(smooth_bot, smooth_top);
      move_to_edges(m0, n0, m1, n1);
      if (right_transition(q) == axis)
      {
        w = link(h);
        skew_line_edges(q, knil(w), w);
      }
    }
    else
      dual_moves(h, p, q);
    right_type(q) = endpoint;
    p = link(q);
  } while (!(p == spec_head));
  if (internal[tracing_edges] > 0)
    end_edge_tracing();
  toss_knot_list(spec_head);
}
/* 527 */
pointer make_ellipse (scaled major_axis, scaled minor_axis, angle theta)
{
  pointer p, q, r, s;
  pointer h;
  integer alpha, beta, gamma, delta;
  integer c, d;
  integer u, v;
  boolean symmetric;

  if ((major_axis == minor_axis) || (theta % ninety_deg == 0))
  {
    symmetric = true;
    alpha = 0;
    if (odd(theta / ninety_deg))
    {
      beta = major_axis;
      gamma = minor_axis;
      n_sin = fraction_one;
      n_cos = 0;
    }
    else
    {
      beta = minor_axis;
      gamma = major_axis;
      theta = 0;
    }
  }
  else
  {
    symmetric = false;
    n_sin_cos(theta);
    gamma = take_fraction(major_axis, n_sin);
    delta = take_fraction(minor_axis, n_cos);
    beta = pyth_add(gamma, delta);
    alpha = take_fraction(take_fraction(major_axis, make_fraction(gamma, beta)), n_cos)
      - take_fraction(take_fraction(major_axis, make_fraction(delta, beta)), n_sin);
    alpha = (alpha + half_unit) / unity;
    gamma = pyth_add(take_fraction(major_axis, n_cos), take_fraction(minor_axis, n_sin));
  }
  beta = (beta + half_unit) / unity;
  gamma = (gamma + half_unit) / unity;
  p = get_node(knot_node_size);
  q = get_node(knot_node_size);
  r = get_node(knot_node_size);
  if (symmetric)
    s = null;
  else
    s = get_node(knot_node_size);
  h = p;
  link(p) = q;
  link(q) = r;
  link(r) = s;
  if (beta == 0)
    beta = 1;
  if (gamma == 0)
    gamma = 1;
  if (gamma <= abs(alpha))
    if (alpha > 0)
      alpha = gamma - 1;
    else
      alpha = 1 - gamma;
  x_coord(p) = -alpha * half_unit;
  y_coord(p) = -beta * half_unit;
  x_coord(q) = gamma * half_unit;
  y_coord(q) = y_coord(p);
  x_coord(r) = x_coord(q);
  right_u(p) = 0;
  left_v(q) = -half_unit;
  right_u(q) = half_unit;
  left_v(r) = 0;
  right_u(r) = 0;
  right_class(p) = beta;
  right_class(q) = gamma;
  right_class(r) = beta;
  left_length(q) = gamma + alpha;
  if (symmetric)
  {
    y_coord(r) = 0;
    left_length(r) = beta;
  }
  else
  {
    y_coord(r) = -y_coord(p);
    left_length(r) = beta + beta;
    x_coord(s) = -x_coord(p);
    y_coord(s) = y_coord(r);
    left_v(s) = half_unit;
    left_length(s) = gamma - alpha;
  }
  while (true)
  {
    u = right_u(p) + right_u(q);
    v = left_v(q) + left_v(r);
    c = right_class(p) + right_class(q);
    delta = pyth_add(u, v);
    if (major_axis == minor_axis)
      d = major_axis;
    else
    {
      if (theta == 0)
      {
        alpha = u;
        beta = v;
      }
      else
      {
        alpha = take_fraction(u, n_cos) + take_fraction(v, n_sin);
        beta = take_fraction(v, n_cos) - take_fraction(u, n_sin);
      }
      alpha = make_fraction(alpha, delta);
      beta = make_fraction(beta, delta);
      d = pyth_add(take_fraction(major_axis, alpha), take_fraction(minor_axis, beta));
    }
    alpha = abs(u);
    beta = abs(v);
    if (alpha < beta)
    {
      alpha = abs(v);
      beta = abs(u);
    }
    if (internal[fillin] != 0)
      d = d - take_fraction(internal[fillin], make_fraction(beta + beta, delta));
    d = take_fraction ((d + 4) / 8, delta);
    alpha = alpha / half_unit;
    if (d < alpha)
      d = alpha;
    delta = c - d;
    if (delta > 0)
    {
      if (delta > left_length(r))
        delta = left_length(r);
      if (delta >= left_length(q))
      {
        delta = left_length(q);
        right_class(p) = c - delta;
        right_u(p) = u;
        left_v(q) = v;
        x_coord(q) = x_coord(q) - delta * left_v(r);
        y_coord(q) = y_coord(q) + delta * right_u(q);
        left_length(r) = left_length(r) - delta;
      }
      else
      {
        s = get_node(knot_node_size);
        link(p) = s;
        link(s) = q;
        x_coord(s) = x_coord(q) + delta * left_v(q);
        y_coord(s) = y_coord(q) - delta * right_u(p);
        x_coord(q) = x_coord(q) - delta * left_v(r);
        y_coord(q) = y_coord(q) + delta * right_u(q);
        left_v(s) = left_v(q);
        right_u(s) = u;
        left_v(q) = v;
        right_class(s) = c - delta;
        left_length(s) = left_length(q) - delta;
        left_length(q) = delta;
        left_length(r) = left_length(r) - delta;
      }
    }
    else
      p = q;
    while (true)
    {
      q = link(p);
      if (q == null)
        goto done;
      if (left_length(q) == 0)
      {
        link(p) = link(q);
        right_class(p) = right_class(q);
        right_u(p) = right_u(q);
        free_node(q, knot_node_size);
      }
      else
      {
        r = link(q);
        if (r == null)
          goto done;
        if (left_length(r) == 0)
        {
          link(p) = r;
          free_node(q, knot_node_size);
          p = r;
        }
        else
          goto found;
      }
    }
    found:;
  }
  done:;
  if (symmetric)
  {
    s = null;
    q = h;
    while (true)
    {
      r = get_node(knot_node_size);
      link(r) = s;
      s = r;
      x_coord(s) = x_coord(q);
      y_coord(s) = -y_coord(q);
      if (q == p)
        goto done1;
      q = link(q);
      if (y_coord(q) == 0)
        goto done1;
    }
  done1:
    if ((link(p) != null))
      free_node(link(p), knot_node_size);
    link(p) = s;
    beta = -y_coord(h);
    while (y_coord(p) != beta)
      p = link(p);
    q = link(p);
  }
  if (q != null)
  {
    if (right_u(h) == 0)
    {
      p = h;
      h = link(h);
      free_node(p, knot_node_size);
      x_coord(q) = -x_coord(h);
    }
    p = q;
  }
  else
    q = p;
  r = link(h);
  do {
    s = get_node(knot_node_size);
    link(p) = s;
    p = s;
    x_coord(p) = -x_coord(r);
    y_coord(p) = -y_coord(r);
    r = link(r);
  } while (!(r == q));
  link(p) = h;
  return h;
}
/* 539 */
scaled find_direction_time (scaled x, scaled y, pointer h)
{
  scaled Result;
  scaled max;
  pointer p, q;
  scaled n;
  scaled tt;
  scaled x1, x2, x3, y1, y2, y3;
  angle theta, phi;
  fraction t;

  if (abs(x) < abs(y))
  {
    x = make_fraction(x, abs(y));
    if (y > 0)
      y = fraction_one;
    else
      y = -fraction_one;
  }
  else if (x == 0)
  {
    Result = 0;
    goto l_exit;
  }
  else
  {
    y = make_fraction(y, abs(x));
    if (x > 0)
      x = fraction_one;
    else
      x = -fraction_one;
  }
  n = 0;
  p = h;
  while (true)
  {
    if (right_type(p) == endpoint)
      goto not_found;
    q = link(p);
    tt = 0;
    x1 = right_x(p) - x_coord(p);
    x2 = left_x(q) - right_x(p);
    x3 = x_coord(q) - left_x(q);
    y1 = right_y(p) - y_coord(p);
    y2 = left_y(q) - right_y(p);
    y3 = y_coord(q) - left_y(q);
    max = abs(x1);
    if (abs(x2) > max)
      max = abs(x2);
    if (abs(x3) > max)
      max = abs(x3);
    if (abs(y1) > max)
      max = abs(y1);
    if (abs(y2) > max)
      max = abs(y2);
    if (abs(y3) > max)
      max = abs(y3);
    if (max == 0)
      goto found;
    while (max < fraction_half)
    {
      _double(max);
      _double(x1);
      _double(x2);
      _double(x3);
      _double(y1);
      _double(y2);
      _double(y3);
    }
    t = x1;
    x1 = take_fraction(x1, x) + take_fraction(y1, y);
    y1 = take_fraction(y1, x) - take_fraction(t, y);
    t = x2;
    x2 = take_fraction(x2, x) + take_fraction(y2, y);
    y2 = take_fraction(y2, x) - take_fraction(t, y);
    t = x3;
    x3 = take_fraction(x3, x) + take_fraction(y3, y);
    y3 = take_fraction(y3, x) - take_fraction(t, y);
    if (y1 == 0)
      if (x1 >= 0)
        goto found;
    if (n > 0)
    {
      theta = n_arg(x1, y1);
      if (theta >= 0)
        if (phi <= 0)
          if (phi >= theta - one_eighty_deg)
            goto found;
      if (theta <= 0)
        if (phi >= 0)
          if (phi <= theta + one_eighty_deg)
            goto found;
      if (p == h)
        goto not_found;
    }
    if ((x3 != 0) || (y3 != 0))
      phi = n_arg(x3, y3);
    if (x1 < 0)
      if (x2 < 0)
        if (x3 < 0)
          goto done;
    if (ab_vs_cd(y1, y3, y2, y2) == 0)
    {
      if (ab_vs_cd(y1, y2, 0, 0) < 0)
      {
        t = make_fraction(y1, y1 - y2);
        x1 = t_of_the_way(x1, x2);
        x2 = t_of_the_way(x2, x3);
        if (t_of_the_way(x1, x2) >= 0)
          we_found_it();
      }
      else if (y3 == 0)
        if (y1 == 0)
        {
          t = crossing_point(-x1, -x2, -x3);
          if (t <= fraction_one)
            we_found_it();
          if (ab_vs_cd(x1, x3, x2, x2) <= 0)
          {
            t = make_fraction(x1, x1 - x2);
            we_found_it();
          }
        }
        else if (x3 >= 0)
        {
          tt = unity;
          goto found;
        }
      goto done;
    }
    if (y1 <= 0)
      if (y1 < 0)
      {
        y1 = -y1;
        y2 = -y2;
        y3 = -y3;
      }
      else if (y2 > 0)
      {
        y2 = -y2;
        y3 = -y3;
      }
    t = crossing_point(y1, y2, y3);
    if (t > fraction_one)
      goto done;
    y2 = t_of_the_way(y2, y3);
    x1 = t_of_the_way(x1, x2);
    x2 = t_of_the_way(x2, x3);
    x1 = t_of_the_way(x1, x2);
    if (x1 >= 0)
      we_found_it();
    if (y2 > 0)
      y2 = 0;
    tt = t;
    t = crossing_point(0, -y2, -y3);
    if (t > fraction_one)
      goto done;
    x1 = t_of_the_way(x1, x2);
    x2 = t_of_the_way(x2, x3);
    if (t_of_the_way(x1, x2) >= 0)
    {
      t = t_of_the_way(tt, fraction_one);
      we_found_it();
    }
  done:
    p = q;
    n = n + unity;
  }
not_found:
  Result = -unity;
  goto l_exit;
found:
  Result = n + tt;
l_exit:;
  return Result;
}
/* 556 */
void cubic_intersection (pointer p, pointer pp)
{
  pointer q, qq;

  time_to_go = max_patience;
  max_t = 2;
  q = link(p);
  qq = link(pp);
  bisect_ptr = int_packets;
  u1r = right_x(p) - x_coord(p);
  u2r = left_x(q) - right_x(p);
  u3r = x_coord(q) - left_x(q);
  set_min_max(ur_packet);
  v1r = right_y(p) - y_coord(p);
  v2r = left_y(q) - right_y(p);
  v3r = y_coord(q) - left_y(q);
  set_min_max(vr_packet);
  x1r = right_x(pp) - x_coord(pp);
  x2r = left_x(qq) - right_x(pp);
  x3r = x_coord(qq) - left_x(qq);
  set_min_max(xr_packet);
  y1r = right_y(pp) - y_coord(pp);
  y2r = left_y(qq) - right_y(pp);
  y3r = y_coord(qq) - left_y(qq);
  set_min_max(yr_packet);
  delx = x_coord(p) - x_coord(pp);
  dely = y_coord(p) - y_coord(pp);
  tol = 0;
  uv = r_packets;
  xy = r_packets;
  three_l = 0;
  cur_t = 1;
  cur_tt = 1;
  while (true)
  {
  l_continue:
    if (delx - tol <= stack_max(x_packet(xy)) - stack_min(u_packet(uv)))
      if (delx + tol >= stack_min(x_packet(xy)) - stack_max(u_packet(uv)))
        if (dely - tol <= stack_max(y_packet(xy)) - stack_min(v_packet(uv)))
          if (dely + tol >= stack_min(y_packet(xy)) - stack_max(v_packet(uv)))
          {
            if (cur_t >= max_t)
            {
              if (max_t == two)
              {
                cur_t = half(cur_t + 1);
                cur_tt = half(cur_tt + 1);
                goto l_exit;
              }
              _double(max_t);
              appr_t = cur_t;
              appr_tt = cur_tt;
            }
            stack_dx = delx;
            stack_dy = dely;
            stack_tol = tol;
            stack_uv = uv;
            stack_xy = xy;
            bisect_ptr = bisect_ptr + int_increment;
            _double(cur_t);
            _double(cur_tt);
            u1l = stack_1(u_packet(uv));
            u3r = stack_3(u_packet(uv));
            u2l = half(u1l + stack_2(u_packet(uv)));
            u2r = half(u3r + stack_2(u_packet(uv)));
            u3l = half(u2l + u2r);
            u1r = u3l;
            set_min_max(ul_packet);
            set_min_max(ur_packet);
            v1l = stack_1(v_packet(uv));
            v3r = stack_3(v_packet(uv));
            v2l = half(v1l + stack_2(v_packet(uv)));
            v2r = half(v3r + stack_2(v_packet(uv)));
            v3l = half(v2l + v2r);
            v1r = v3l;
            set_min_max(vl_packet);
            set_min_max(vr_packet);
            x1l = stack_1(x_packet(xy));
            x3r = stack_3(x_packet(xy));
            x2l = half(x1l + stack_2(x_packet(xy)));
            x2r = half(x3r + stack_2(x_packet(xy)));
            x3l = half(x2l + x2r);
            x1r = x3l;
            set_min_max(xl_packet);
            set_min_max(xr_packet);
            y1l = stack_1(y_packet(xy));
            y3r = stack_3(y_packet(xy));
            y2l = half(y1l + stack_2(y_packet(xy)));
            y2r = half(y3r + stack_2(y_packet(xy)));
            y3l = half(y2l + y2r);
            y1r = y3l;
            set_min_max(yl_packet);
            set_min_max(yr_packet);
            uv = l_packets;
            xy = l_packets;
            _double(delx);
            _double(dely);
            tol = tol - three_l + tol_step;
            _double(tol);
            three_l = three_l + tol_step;
            goto l_continue;
          }
    if (time_to_go > 0)
      decr(time_to_go);
    else
    {
      while (appr_t < unity)
      {
        _double(appr_t);
        _double(appr_tt);
      }
      cur_t = appr_t;
      cur_tt = appr_tt;
      goto l_exit;
    }
  not_found:
    if (odd(cur_tt))
      if (odd(cur_t))
      {
        cur_t = half(cur_t);
        cur_tt = half(cur_tt);
        if (cur_t == 0)
          goto l_exit;
        bisect_ptr = bisect_ptr - int_increment;
        three_l = three_l - tol_step;
        delx = stack_dx;
        dely = stack_dy;
        tol = stack_tol;
        uv = stack_uv;
        xy = stack_xy;
        goto not_found;
      }
      else
      {
        incr(cur_t);
        delx = delx + stack_1(u_packet(uv)) + stack_2(u_packet(uv)) + stack_3(u_packet(uv));
        dely = dely + stack_1(v_packet(uv)) + stack_2(v_packet(uv)) + stack_3(v_packet(uv));
        uv = uv + int_packets;
        decr(cur_tt);
        xy = xy - int_packets;
        delx = delx + stack_1(x_packet(xy)) + stack_2(x_packet(xy)) + stack_3(x_packet(xy));
        dely = dely + stack_1(y_packet(xy)) + stack_2(y_packet(xy)) + stack_3(y_packet(xy));
      }
    else
    {
      incr(cur_tt);
      tol = tol + three_l;
      delx = delx - stack_1(x_packet(xy)) - stack_2(x_packet(xy)) - stack_3(x_packet(xy));
      dely = dely - stack_1(y_packet(xy)) - stack_2(y_packet(xy)) - stack_3(y_packet(xy));
      xy = xy + int_packets;
    }
  }
  l_exit:;
}
/* 562 */
void path_intersection (pointer h, pointer hh)
{
  pointer p, pp;
  integer n, nn;

  if (right_type(h) == endpoint)
  {
    right_x(h) = x_coord(h);
    left_x(h) = x_coord(h);
    right_y(h) = y_coord(h);
    left_y(h) = y_coord(h);
    right_type(h) = explicit;
  }
  if (right_type(hh) == endpoint)
  {
    right_x(hh) = x_coord(hh);
    left_x(hh) = x_coord(hh);
    right_y(hh) = y_coord(hh);
    left_y(hh) = y_coord(hh);
    right_type(hh) = explicit;
  }
  tol_step = 0;
  do {
    n = -unity;
    p = h;
    do {
      if (right_type(p) != endpoint)
      {
        nn = -unity;
        pp = hh;
        do {
          if (right_type(pp) != endpoint)
          {
            cubic_intersection(p, pp);
            if (cur_t > 0)
            {
              cur_t = cur_t + n;
              cur_tt = cur_tt + nn;
              goto l_exit;
            }
          }
          nn = nn + unity;
          pp = link(pp);
        } while (!(pp == hh));
      }
      n = n + unity;
      p = link(p);
    } while (!(p == h));
    tol_step = tol_step + 3;
  } while (!(tol_step > 3));
  cur_t = -unity;
  cur_tt = -unity;
l_exit:;
}
/* 564 */
boolean init_screen (void)
{
  return false;
}
/* 564 */
void update_screen (void)
{
  if (0)
    wterm_ln("Calling UPDATESCREEN");
}
/* 567 */
void blank_rectangle(screen_col left_col, screen_col right_col, screen_row top_row, screen_row bot_row)
{
  screen_row r;
  screen_col c;
  for (r = top_row; r <= bot_row - 1; r++)
    for (c = left_col; c <= right_col - 1; r++)
      screen_pixel[r][c] = white;
  if (0)
  {
    wlog_cr();
    wlog_ln("Calling BLANKRECTANGLE(%d,%d,%d,%d)", left_col, right_col, top_row, bot_row);
  }
}
void paint_row (screen_row r, pixel_color b, trans_spec a, screen_col n)
{
  screen_col k;
  screen_col c;

  k = 0;
  c = a[0];
  do {
    incr(k);
    do {
      screen_pixel[r][c] = b;
      incr(c);
    } while (!(c == a[k]));
    k = black - b;
  } while (!(k == n));
  if (0)
  {
    wlog("Calling PAINTROW(%d,%d;", r, b);
    for (k = 0; k <= n; k++)
    {
      wlog("%d", a[k]);
      if (k != n)
        wlog(",");
    }
    wlog(")");
  }
}
/* 574 */
void open_a_window (window_number k, scaled r0, scaled c0, scaled r1, scaled c1, scaled x, scaled y)
{
  integer m, n;

  if (r0 < 0)
    r0 = 0;
  else
    r0 = round_unscaled(r0);
  r1 = round_unscaled(r1);
  if (r1 > screen_depth)
    r1 = screen_depth;
  if (r1 < r0)
    if (r0 > screen_depth)
      r0 = r1;
    else
      r1 = r0;
  if (c0 < 0)
    c0 = 0;
  else
    c0 = round_unscaled(c0);
  c1 = round_unscaled(c1);
  if (c1 > screen_width)
    c1 = screen_width;
  if (c1 < c0)
    if (c0 > screen_width)
      c0 = c1;
    else
      c1 = c0;
  window_open[k] = true;
  incr(window_time[k]);
  left_col[k] = c0;
  right_col[k] = c1;
  top_row[k] = r0;
  bot_row[k] = r1;
  m = round_unscaled(x);
  n = round_unscaled(y) - 1;
  m_window[k] = c0 - m;
  n_window[k] = r0 + n;
  start_screen();
  if (screen_OK)
  {
    blank_rectangle(c0, c1, r0, r1);
    update_screen();
  }
}
/* 577 */
void disp_edges (window_number k)
{
  pointer p, q;
  boolean already_there;
  integer r;
  screen_col n;
  integer w, ww;
  pixel_color b;
  integer m, mm;
  integer d;
  integer m_adjustment;
  integer right_edge;
  screen_col min_col;

  if (screen_OK)
    if (left_col[k] < right_col[k])
      if (top_row[k] < bot_row[k])
      {
        already_there = false;
        if (last_window(cur_edges) == k)
          if (last_window_time(cur_edges) == window_time[k])
            already_there = true;
        if (!already_there)
          blank_rectangle(left_col[k], right_col[k], top_row[k], bot_row[k]);
        m_adjustment = m_window[k] - m_offset(cur_edges);
        right_edge = 8 * (right_col[k] - m_adjustment);
        min_col = left_col[k];
        p = link(cur_edges);
        r = n_window[k] - (n_min(cur_edges) - zero_field);
        while ((p != cur_edges) && (r >= top_row[k]))
        {
          if (r < bot_row[k])
          {
            if (unsorted(p) > _void)
              sort_edges(p);
            else if (unsorted(p) == _void)
              if (already_there)
                goto done;
            unsorted(p) = _void;
            n = 0;
            ww = 0;
            m = -1;
            w = 0;
            q = sorted(p);
            row_transition[0] = min_col;
            while (true)
            {
              if (q == sentinel)
                d = right_edge;
              else
                d = ho(info(q));
              mm = (d / 8) + m_adjustment;
              if (mm != m)
              {
                if (w <= 0)
                {
                  if (ww > 0)
                    if (m > min_col)
                    {
                      if (n == 0)
                        if (already_there)
                        {
                          b = white;
                          incr(n);
                        }
                        else
                          b = black;
                      else
                        incr(n);
                      row_transition[n] = m;
                    }
                }
                else if (ww <= 0)
                  if (m > min_col)
                  {
                    if (n == 0)
                      b = black;
                    incr(n);
                    row_transition[n] = m;
                  }
                m = mm;
                w = ww;
              }
              if (d >= right_edge)
                goto found;
              ww = ww + (d % 8) - zero_w;
              q = link(q);
            }
          found:
            if (already_there || (ww > 0))
            {
              if (n == 0)
                if (ww > 0)
                  b = black;
                else
                  b = white;
              incr(n);
              row_transition[n] = right_col[k];
            }
            else if (n == 0)
              goto done;
            paint_row(r, b, row_transition, n);
          done:;
          }
          p = link(p);
          decr(r);
        }
        update_screen();
        incr(window_time[k]);
        last_window(cur_edges) = k;
        last_window_time(cur_edges) = window_time[k];
      }
}
/* 591 */
fraction max_coef (pointer p)
{
  fraction x;

  x = 0;
  while (info(p) != null)
  {
    if (abs(value(p)) > x)
      x = abs(value(p));
    p = link(p);
  }
  return x;
}
/* 597 */
pointer p_plus_q (pointer p, pointer q, small_number t)
{
  pointer pp, qq;
  pointer r, s;
  integer threshold;
  integer v;

  if (t == dependent)
    threshold = fraction_threshold;
  else
    threshold = scaled_threshold;
  r = temp_head;
  pp = info(p);
  qq = info(q);
  while (true)
    if (pp == qq)
      if (pp == null)
        goto done;
      else
      {
        v = value(p) + value(q);
        value(p) = v;
        s = p;
        p = link(p);
        pp = info(p);
        if (abs(v) < threshold)
          free_node(s, dep_node_size);
        else
        {
          if (abs(v) >= coef_bound)
            if (watch_coefs)
            {
              type(qq) = independent_needing_fix;
              fix_needed = true;
            }
          link(r) = s;
          r = s;
        }
        q = link(q);
        qq = info(q);
      }
    else
      if (value(pp) < value(qq))
      {
        s = get_node(dep_node_size);
        info(s) = qq;
        value(s) = value(q);
        q = link(q);
        qq = info(q);
        link(r) = s;
        r = s;
      }
      else
      {
        link(r) = p;
        r = p;
        p = link(p);
        pp = info(p);
      }
done:
  value(p) = slow_add(value(p), value(q));
  link(r) = p;
  dep_final = p;
  return link(temp_head);
}
/* 599 */
pointer p_times_v (pointer p, integer v, small_number t0, small_number t1, boolean v_is_scaled)
{
  pointer r, s;
  integer w;
  integer threshold;
  boolean scaling_down;

  if (t0 != t1)
    scaling_down = true;
  else
    scaling_down = !v_is_scaled;
  if (t1 == dependent)
    threshold = half_fraction_threshold;
  else
    threshold = half_scaled_threshold;
  r = temp_head;
  while (info(p) != null)
  {
    if (scaling_down)
      w = take_fraction(v, value(p));
    else
      w = take_scaled(v, value(p));
    if (abs(w) <= threshold)
    {
      s = link(p);
      free_node(p, dep_node_size);
      p = s;
    }
    else
    {
      if (abs(w) >= coef_bound)
      {
        fix_needed = true;
        type(info(p)) = independent_needing_fix;
      }
      link(r) = p;
      r = p;
      value(p) = w;
      p = link(p);
    }
  }
  link(r) = p;
  if (v_is_scaled)
    value(p) = take_scaled(value(p), v);
  else
    value(p) = take_fraction(value(p), v);
  return link(temp_head);
}
/* 601 */
pointer p_with_x_becoming_q (pointer p, pointer x, pointer q, small_number t)
{
  pointer r, s;
  integer v;
  integer sx;

  s = p;
  r = temp_head;
  sx = value(x);
  while (value(info(s)) > sx)
  {
    r = s;
    s = link(s);
  }
  if (info(s) != x)
    return p;
  else
  {
    link(temp_head) = p;
    link(r) = link(s);
    v = value(s);
    free_node(s, dep_node_size);
    return p_plus_fq(link(temp_head), v, q, t, dependent);
  }
}
/* 606 */
void new_dep (pointer q, pointer p)
{
  pointer r;

  dep_list(q) = p;
  prev_dep(q) = dep_head;
  r = link(dep_head);
  link(dep_final) = r;
  prev_dep(r) = dep_final;
  link(dep_head) = q;
}
/* 607 */
pointer const_dependency (scaled v)
{
  dep_final = get_node(dep_node_size);
  value(dep_final) = v;
  info(dep_final) = null;
  return dep_final;
}
/* 608 */
pointer single_dependency (pointer p)
{
  pointer q;
  integer m;

  m = value(p) % s_scale;
  if (m > 28)
    return const_dependency(0);
  else
  {
    q = get_node(dep_node_size);
    value(q) = two_to_the[28 - m];
    info(q) = p;
    link(q) = const_dependency(0);
    return q;
  }
}
/* 609 */
pointer copy_dep_list (pointer p)
{
  pointer q;

  q = get_node(dep_node_size);
  dep_final = q;
  while (true)
  {
    info(dep_final) = info(p);
    value(dep_final) = value(p);
    if (info(dep_final) == null)
      goto done;
    link(dep_final) = get_node(dep_node_size);
    dep_final = link(dep_final);
    p = link(p);
  }
done:
  return q;
}
/* 610 */
void linear_eq (pointer p, small_number t)
{
  pointer q, r, s;
  pointer x;
  integer n;
  integer v;
  pointer prev_r;
  pointer final_node;
  integer w;

  q = p;
  r = link(p);
  v = value(q);
  while (info(r) != null)
  {
    if (abs(value(r)) > abs(v))
    {
      q = r;
      v = value(r);
    }
    r = link(r);
  }
  x = info(q);
  n = value(x) % s_scale;
  s = temp_head;
  link(s) = p;
  r = p;
  do {
    if (r == q)
    {
      link(s) = link(r);
      free_node(r, dep_node_size);
    }
    else
    {
      w = make_fraction(value(r), v);
      if (abs(w) <= half_fraction_threshold)
      {
        link(s) = link(r);
        free_node(r, dep_node_size);
      }
      else
      {
        value(r) = -w;
        s = r;
      }
    }
    r = link(s);
  } while (!(info(r) == null));
  if (t == proto_dependent)
    value(r) = -make_scaled(value(r), v);
  else if (v != -fraction_one)
    value(r) = -make_fraction(value(r), v);
  final_node = r;
  p = link(temp_head);
  if (internal[tracing_equations] > 0)
  {
    if (interesting(x))
    {
      begin_diagnostic();
      r_print_nl("## ");
      print_variable_name(x);
      w = n;
      while (w > 0)
      {
        r_print("*4");
        w = w - 2;
      }
      print_char('=');
      print_dependency(p, dependent);
      end_diagnostic(false);
    }
  }
  prev_r = dep_head;
  r = link(dep_head);
  while (r != dep_head)
  {
    s = dep_list(r);
    q = p_with_x_becoming_q(s, x, p, type(r));
    if (info(q) == null)
      make_known(r, q);
    else
    {
      dep_list(r) = q;
      do {
        q = link(q);
      } while (!(info(q) == null));
      prev_r = q;
    }
    r = link(prev_r);
  }
  if (n > 0)
  {
    s = temp_head;
    link(temp_head) = p;
    r = p;
    do {
      if (n > 30)
        w = 0;
      else
        w = value(r) / two_to_the[n];
      if ((abs(w) <= half_fraction_threshold) && (info(r) != null))
      {
        link(s) = link(r);
        free_node(r, dep_node_size);
      }
      else
      {
        value(r) = w;
        s = r;
      }
      r = link(s);
    } while (!(info(s) == null));
    p = link(temp_head);
  }
  if (info(p) == null)
  {
    type(x) = known;
    value(x) = value(p);
    if (abs(value(x)) >= fraction_one)
      val_too_big(value(x));
    free_node(p, dep_node_size);
    if (cur_exp == x)
      if (cur_type == independent)
      {
        cur_exp = value(x);
        cur_type = known;
        free_node(x, value_node_size);
      }
  }
  else
  {
    type(x) = dependent;
    dep_final = final_node;
    new_dep(x, p);
    if (cur_exp == x)
      if (cur_type == independent)
        cur_type = dependent;
  }
  if (fix_needed)
    fix_dependencies();
}
/* 619 */
pointer new_ring_entry (pointer p)
{
  pointer q;

  q = get_node(value_node_size);
  name_type(q) = capsule;
  type(q) = type(p);
  if (value(p) == null)
    value(q) = p;
  else
    value(q) = value(p);
  value(p) = q;
  return q;
}
/* 621 */
void non_linear_eq (integer v, pointer p, boolean flush_p)
{
  small_number t;
  pointer q, r;

  t = type(p) - unknown_tag;
  q = value(p);
  if (flush_p)
    type(p) = vacuous;
  else
    p = q;
  do {
    r = value(q);
    type(q) = t;
    switch (t)
    {
      case boolean_type:
        value(q) = v;
        break;
      case string_type:
        {
          value(q) = v;
          add_str_ref(v);
        }
        break;
      case pen_type:
        {
          value(q) = v;
          add_pen_ref(v);
        }
        break;
      case path_type:
        value(q) = copy_path(v);
        break;
      case picture_type:
        value(q) = copy_edges(v);
        break;
    }
    q = r;
  } while (!(q == p));
}
/* 622 */
void ring_merge (pointer p, pointer q)
{
  pointer r;

  r = value(p);
  while (r != p)
  {
    if (r == q)
    {
      {
        print_err("Redundant equation");
        help2("I already knew that this equation was true.",
          "But perhaps no harm has been done; let's continue.");
        put_get_error();
      }
      goto l_exit;
    }
    r = value(r);
  }
  r = value(p);
  value(p) = value(q);
  value(q) = r;
l_exit:;
}
/* 626 */
void show_cmd_mod (integer c, integer m)
{
  begin_diagnostic();
  r_print_nl("{");
  print_cmd_mod(c, m);
  print_char('}');
  end_diagnostic(false);
}
/* 635 */
void show_context (void)
{
  unsigned char old_setting;
  integer i;
  integer l;
  integer m;
  integer n;
  integer p;
  integer q;

  file_ptr = input_ptr;
  input_stack[file_ptr] = cur_input;
  while (true)
  {
    cur_input = input_stack[file_ptr];
    if ((file_ptr == input_ptr) || file_state || (token_type != backed_up) || (loc != null))
    {
      tally = 0;
      old_setting = selector;
      if (file_state)
      {
        if (name <= 1)
        {
          if (terminal_input && (file_ptr == 0))
            r_print_nl("<*>");
          else
            r_print_nl("<insert>");
        }
        else if (name == 2)
          r_print_nl("<scantokens>");
        else
        {
          r_print_nl("l.");
          print_int(line);
        }
        print_char(' ');
        begin_pseudoprint();
        if (limit > 0)
          for (i = start; i <= limit - 1; i++)
          {
            if (i == loc)
              set_trick_count();
            print(buffer[i]);
          }
      }
      else
      {
        switch (token_type)
        {
          case forever_text:
            r_print_nl("<forever> ");
            break;
          case loop_text:
            {
              r_print_nl("<for(");
              p = param_stack[param_start];
              if (p != null)
              {
                if (link(p) == _void)
                  print_exp(p, 0);
                else
                  show_token_list(p, null, 20, tally);
              }
              r_print(")> ");
            }
            break;
          case parameter:
            r_print_nl("<argument> ");
            break;
          case backed_up:
            if (loc == null)
              r_print_nl("<recently read> ");
            else
              r_print_nl("<to be read again> ");
            break;
          case inserted:
            r_print_nl("<inserted text> ");
            break;
          case macro:
            {
              print_ln();
              if (name != null)
                slow_print(text(name));
              else
              {
                p = param_stack[param_start];
                if (p == null)
                  show_token_list(param_stack[param_start + 1], null, 20, tally);
                else
                {
                  q = p;
                  while (link(q) != null)
                    q = link(q);
                  link(q) = param_stack[param_start + 1];
                  show_token_list(p, null, 20, tally);
                  link(q) = null;
                }
              }
              r_print("->");
            }
            break;
          default:
            r_print_nl("?");
            break;
        }
        begin_pseudoprint();
        if (index != macro)
          show_token_list(start, loc, 100000, 0);
        else
          show_macro(start, loc, 100000);
      }
      selector = old_setting;
      if (trick_count == 1000000)
        set_trick_count();
      if (tally < trick_count)
        m = tally - first_count;
      else
        m = trick_count - first_count;
      if (l + first_count <= half_error_line)
      {
        p = 0;
        n = l + first_count;
      }
      else
      {
        r_print("...");
        p = l + first_count - half_error_line + 3;
        n = half_error_line;
      }
      for (q = p; q <= first_count - 1; q++)
        print_char(trick_buf[q % error_line]);
      print_ln();
      for (q = 1; q <= n; q++)
        print_char(' ');
      if (m + n <= error_line)
        p = first_count + m;
      else
        p = first_count + (error_line - n - 3);
      for (q = first_count; q <= p - 1; q++)
        print_char(trick_buf[q % error_line]);
      if (m + n > error_line)
        r_print("...");
    }
    if (file_state)
      if ((name > 2) || (file_ptr == 0))
        goto done;
    decr(file_ptr);
  }
done:
  cur_input = input_stack[input_ptr];
}
/* 649 */
void begin_token_list (pointer p, quarterword t)
{
  push_input();
  start = p;
  index = t;
  limit = param_ptr;
  loc = p;
}
/* 650 */
void end_token_list (void)
{
  pointer p;

  if (index >= backed_up)
    if (index <= inserted)
    {
      flush_token_list(start);
      goto done;
    }
    else
      delete_mac_ref(start);
  while (param_ptr > limit)
  {
    decr(param_ptr);
    p = param_stack[param_ptr];
    if (p != null)
    {
      if (link(p) == _void)
      {
        recycle_value(p);
        free_node(p, value_node_size);
      }
      else
        flush_token_list(p);
    }
  }
done:
  pop_input();
  check_interrupt();
}
/* 856 */
void encapsulate (pointer p)
{
  cur_exp = get_node(value_node_size);
  type(cur_exp) = cur_type;
  name_type(cur_exp) = capsule;
  new_dep(cur_exp, p);
}
/* 858 */
void install (pointer r, pointer q)
{
  pointer p;

  if (type(q) == known)
  {
    value(r) = value(q);
    type(r) = known;
  }
  else if (type(q) == independent)
  {
    p = single_dependency(q);
    if (p == dep_final)
    {
      type(r) = known;
      value(r) = 0;
      free_node(p, dep_node_size);
    }
    else
    {
      type(r) = dependent;
      new_dep(r, p);
    }
  }
  else
  {
    type(r) = type(q);
    new_dep(r, copy_dep_list(dep_list(q)));
  }
}
/* 855 */
void make_exp_copy (pointer p)
{
  pointer q, r, t;

l_restart:
  cur_type = type(p);
  switch (cur_type)
  {
    case vacuous:
    case boolean_type:
    case known:
      cur_exp = value(p);
      break;
    case unknown_types:
      cur_exp = new_ring_entry(p);
      break;
    case string_type:
      {
        cur_exp = value(p);
        add_str_ref(cur_exp);
      }
      break;
    case pen_type:
      {
        cur_exp = value(p);
        add_pen_ref(cur_exp);
      }
      break;
    case picture_type:
      cur_exp = copy_edges(value(p));
      break;
    case path_type:
    case future_pen:
      cur_exp = copy_path(value(p));
      break;
    case transform_type:
    case pair_type:
      {
        if (value(p) == null)
          init_big_node(p);
        t = get_node(value_node_size);
        name_type(t) = capsule;
        type(t) = cur_type;
        init_big_node(t);
        q = value(p) + big_node_size[cur_type];
        r = value(t) + big_node_size[cur_type];
        do {
          q = q - 2;
          r = r - 2;
          install(r, q);
        } while (!(q == value(p)));
        cur_exp = t;
      }
      break;
    case dependent:
    case proto_dependent:
      encapsulate(copy_dep_list(dep_list(p)));
      break;
    case numeric_type:
      {
        new_indep(p);
        goto l_restart;
      }
      break;
    case independent:
      {
        q = single_dependency(p);
        if (q == dep_final)
        {
          cur_type = known;
          cur_exp = 0;
          free_node(q, dep_node_size);
        }
        else
        {
          cur_type = dependent;
          encapsulate(q);
        }
      }
      break;
    default:
      confusion("copy");
      break;
  }
}
/* 651 */
pointer cur_tok (void)
{
  pointer p;
  small_number save_type;
  integer save_exp;

  if (cur_sym == 0)
    if (cur_cmd == capsule_token)
    {
      save_type = cur_type;
      save_exp = cur_exp;
      make_exp_copy(cur_mod);
      p = stash_cur_exp();
      link(p) = null;
      cur_type = save_type;
      cur_exp = save_exp;
    }
    else
    {
      p = get_node(token_node_size);
      value(p) = cur_mod;
      name_type(p) = token;
      if (cur_cmd == numeric_token)
        type(p) = known;
      else
        type(p) = string_type;
    }
  else
  {
    fast_get_avail(p);
    info(p) = cur_sym;
  }
  return p;
}
/* 652 */
void back_input (void)
{
  pointer p;

  p = cur_tok();
  while (token_state && (loc == null))
    end_token_list();
  back_list(p);
}
/* 653 */
void back_error (void)
{
  OK_to_interrupt = false;
  back_input();
  OK_to_interrupt = true;
  error();
}
/* 653 */
void ins_error (void)
{
  OK_to_interrupt = false;
  back_input();
  token_type = inserted;
  OK_to_interrupt = true;
  error();
}
/* 654 */
void begin_file_reading (void)
{
  if (in_open == max_in_open)
    overflow("text input levels", max_in_open);
  if (first == buf_size)
    overflow("buffer size", buf_size);
  incr(in_open);
  push_input();
  index = in_open;
  line_stack[index] = line;
  start = first;
  name = 0;
}
/* 655 */
void end_file_reading (void)
{
  first = start;
  line = line_stack[index];
  if (index != in_open)
    confusion("endinput");
  if (name > 2)
    a_close(cur_file);
  pop_input();
  decr(in_open);
}
/* 656 */
void clear_for_error_prompt (void)
{
  while (file_state && terminal_input && (input_ptr > 0) && (loc == limit))
    end_file_reading();
  print_ln();
  clear_terminal();
}
/* 661 */
boolean check_outer_validity (void)
{
  pointer p;

  if (scanner_status == normal)
    return true;
  else
  {
    deletions_allowed = false;
    if (cur_sym != 0)
    {
      p = get_avail();
      info(p) = cur_sym;
      back_list(p);
    }
    if (scanner_status > skipping)
    {
      runaway();
      if (cur_sym == 0)
        print_err("File ended");
      else
      {
        print_err("Forbidden token found");
      }
      r_print(" while scanning ");
      help4("I suspect you have forgotten an `enddef',",
        "causing me to read past where you wanted me to stop.",
        "I'll try to recover; but if the error is serious,",
        "you'd better type `E' or `X' now and fix your file.");
      switch (scanner_status)
      {
        case flushing:
          {
            r_print("to the end of the statement");
            help_line[3] = "A previous error seems to have propagated,";
            cur_sym = frozen_semicolon;
          }
          break;
        case absorbing:
          {
            r_print("a text argument");
            help_line[3] = "It seems that a right delimiter was left out,";
            if (warning_info == 0)
              cur_sym = frozen_end_group;
            else
            {
              cur_sym = frozen_right_delimiter;
              equiv(frozen_right_delimiter) = warning_info;
            }
          }
          break;
        case var_defining:
        case op_defining:
          {
            r_print("the definition of ");
            if (scanner_status == op_defining)
              slow_print(text(warning_info));
            else
              print_variable_name(warning_info);
            cur_sym = frozen_end_def;
          }
          break;
        case loop_defining:
          {
            r_print("the text of a ");
            slow_print(text(warning_info));
            r_print(" loop");
            help_line[3] = "I suspect you have forgotten an `enddef',";
            cur_sym = frozen_end_for;
          }
          break;
      }
      ins_error();
    }
    else
    {
      print_err("Incomplete if; all text was ignored after line ");
      print_int(warning_info);
      help3("A forbidden `outer' token occurred in skipped text.",
        "This kind of error happens when you say `if...' and forget",
        "the matching `fi'. I've inserted a `fi'; this might work.");
      if (cur_sym == 0)
        help_line[2] = "The file ended while I was skipping conditional text.";
      cur_sym = frozen_fi;
      ins_error();
    }
    deletions_allowed = true;
    return false;
  }
}
void firm_up_the_line(void);
/* 667 */
void get_next (void)
{
  integer k;
  ASCII_code c;
  ASCII_code cclass;
  integer n, f;

l_restart:
  cur_sym = 0;
  if ((index <= 15))
  {
l_switch:
    c = buffer[loc];
    incr(loc);
    cclass = char_class[c];
    switch (cclass)
    {
      case digit_class:
        goto lab_start_numeric_token;
        break;
      case period_class:
        {
          cclass = char_class[buffer[loc]];
          if (cclass > period_class)
            goto l_switch;
          else if (cclass < period_class)
          {
            n = 0;
            goto lab_start_decimal_token;
          }
        }
        break;
      case space_class:
        goto l_switch;
        break;
      case percent_class:
        {
          if (name > 2)
          {
            incr(line);
            first = start;
            if (!force_eof)
            {
              if (input_ln(cur_file, true))
                firm_up_the_line();
              else
                force_eof = true;
            }
            if (force_eof)
            {
              print_char(')');
              decr(open_parens);
              update_terminal();
              force_eof = false;
              end_file_reading();
              if (check_outer_validity())
                goto l_restart;
              else
                goto l_restart;
            }
            buffer[limit] = '%';
            first = limit + 1;
            loc = start;
          }
          else
          {
            if (input_ptr > 0)
            {
              end_file_reading();
              goto l_restart;
            }
            if (selector < log_only)
              open_log_file();
            if (interaction > nonstop_mode)
            {
              if (limit == start)
                r_print_nl("(Please type a command or say `end')");
              print_ln();
              first = start;
              prompt_input("*");
              limit = last;
              buffer[limit] = '%';
              first = limit + 1;
              loc = start;
            }
            else
              fatal_error("*** (job aborted, no legal end found)");
          }
          check_interrupt();
          goto l_switch;
        }
        break;
      case string_class:
        {
          if (buffer[loc] == '"')
            cur_mod = "";
          else
          {
            k = loc;
            buffer[limit + 1] = '"';
            do {
              incr(loc);
            } while (!(buffer[loc] == '"'));
            if (loc > limit)
            {
              loc = limit;
              print_err("Incomplete string token has been flushed");
              help3("Strings should finish on the same line as they began.",
                "I've deleted the partial string; you might want to",
                "insert another by typing, e.g., `I\"new string\"'.");
              deletions_allowed = false;
              error();
              deletions_allowed = true;
              goto l_restart;
            }
            if ((loc == k + 1) && (length(buffer[k]) == 1))
              cur_mod = buffer[k];
            else
            {
              str_room(loc - k);
              do {
                append_char(buffer[k]);
                incr(k);
              } while (!(k == loc));
              cur_mod = make_string();
            }
          }
          incr(loc);
          cur_cmd = string_token;
          goto l_exit;
        }
        break;
      case isolated_classes:
        {
          k = loc - 1;
          goto found;
        }
        break;
      case invalid_class:
        {
          print_err("Text line contains an invalid character");
          help2("A funny symbol that I can't read has just been input.",
            "Continue, and I'll forget that it ever happened.");
          deletions_allowed = false;
          error();
          deletions_allowed = true;
          goto l_restart;
        }
        break;
      default:
        do_nothing();
        break;
    }
    k = loc - 1;
    while (char_class[buffer[loc]] == cclass)
      incr(loc);
    goto found;
  lab_start_numeric_token:
    n = c - '0';
    while (char_class[buffer[loc]] == digit_class)
    {
      if (n < 4096)
        n = 10 * n + buffer[loc] - '0';
      incr(loc);
    }
    if (buffer[loc] == ".")
      if (char_class[buffer[loc + 1]] == digit_class)
        goto done;
    f = 0;
    goto lab_fin_numeric_token;
  done:
    incr(loc);
  lab_start_decimal_token:
    k = 0;
    do {
      if (k < 17)
      {
        dig[k] = buffer[loc] - '0';
        incr(k);
      }
      incr(loc);
    } while (!(char_class[buffer[loc]] != digit_class));
    f = round_decimals(k);
    if (f == unity)
    {
      incr(n);
      f = 0;
    }
  lab_fin_numeric_token:
    if (n < 4096)
      cur_mod = n * unity + f;
    else
    {
      print_err("Enormous number has been reduced");
      help2("I can't handle numbers bigger than about 4095.99998;",
        "so I've changed your constant to that maximum amount.");
      deletions_allowed = false;
      error();
      deletions_allowed = true;
      cur_mod = 01777777777;
    }
    cur_cmd = numeric_token;
    goto l_exit;
  found:
    cur_sym = id_lookup(k, loc - k);
  }
  else if (loc >= hi_mem_min)
  {
    cur_sym = info(loc);
    loc = link(loc);
    if (cur_sym >= expr_base)
      if (cur_sym >= suffix_base)
      {
        if (cur_sym >= text_base)
          cur_sym = cur_sym - param_size;
        begin_token_list(param_stack[param_start + cur_sym - (suffix_base)], parameter);
        goto l_restart;
      }
      else
      {
        cur_cmd = capsule_token;
        cur_mod = param_stack[param_start + cur_sym - (expr_base)];
        cur_sym = 0;
        goto l_exit;
      }
  }
  else if (loc > null)
  {
    if (name_type(loc) == token)
    {
      cur_mod = value(loc);
      if (type(loc) == known)
        cur_cmd = numeric_token;
      else
      {
        cur_cmd = string_token;
        add_str_ref(cur_mod);
      }
    }
    else
    {
      cur_mod = loc;
      cur_cmd = capsule_token;
    }
    loc = link(loc);
    goto l_exit;
  }
  else
  {
    end_token_list();
    goto l_restart;
  }
  cur_cmd = eq_type(cur_sym);
  cur_mod = equiv(cur_sym);
  if (cur_cmd >= outer_tag)
    if (check_outer_validity())
      cur_cmd = cur_cmd - outer_tag;
    else
      goto l_restart;
l_exit:;
}
/* 682 */
void firm_up_the_line (void)
{
  integer k;

  limit = last;
  if (internal[pausing] > 0)
  {
    if (interaction > nonstop_mode)
    {
      wakeup_terminal();
      print_ln();
      if (start < limit)
      {
        for (k = start; k <= limit - 1; k++)
          print(buffer[k]);
      }
      first = limit;
      prompt_input("=>");
      if (last > first)
      {
        for (k = first; k <= last - 1; k++)
          buffer[k + start - first] = buffer[k];
        limit = start + last - first;
      }
    }
  }
}
/* 685 */
pointer scan_toks (command_code terminator, pointer subst_list, pointer tail_end, small_number suffix_count)
{
  pointer p;
  pointer q;
  integer balance;

  p = hold_head;
  balance = 1;
  link(hold_head) = null;
  while (true)
  {
    get_next();
    if (cur_sym > 0)
    {
      {
        q = subst_list;
        while (q != null)
        {
          if (info(q) == cur_sym)
          {
            cur_sym = value(q);
            cur_cmd = relax;
            goto found;
          }
          q = link(q);
        }
        found:;
      }
      if (cur_cmd == terminator)
        if (cur_mod > 0)
          incr(balance);
        else
        {
          decr(balance);
          if (balance == 0)
            goto done;
        }
      else if (cur_cmd == macro_special)
      {
        if (cur_mod == quote)
          get_next();
        else if (cur_mod <= suffix_count)
          cur_sym = suffix_base - 1 + cur_mod;
      }
    }
    link(p) = cur_tok();
    p = link(p);
  }
done:
  link(p) = tail_end;
  flush_node_list(subst_list);
  return link(hold_head);
}
/* 691 */
void get_symbol (void)
{
l_restart:
  get_next();
  if ((cur_sym == 0) || (cur_sym > frozen_inaccessible))
  {
    print_err("Missing symbolic token inserted");
    help3("Sorry: You can't redefine a number, string, or expr.",
      "I've inserted an inaccessible symbol so that your",
      "definition will be completed without mixing me up too badly.");
    if (cur_sym > 0)
      help_line[2] = "Sorry: You cant redefine my error-recovery tokens.";
    else if (cur_cmd == string_token)
      delete_str_ref(cur_mod);
    cur_sym = frozen_inaccessible;
    ins_error();
    goto l_restart;
  }
}
/* 692 */
void get_clear_symbol (void)
{
  get_symbol();
  clear_symbol(cur_sym, false);
}
/* 693 */
void check_equals (void)
{
  if (cur_cmd != equals)
    if (cur_cmd != assignment)
    {
      missing_err("=");
      help5("The next thing in this `def' should have been `=',",
        "because I've already looked at the definition heading.",
        "But don't worry; I'll pretend that an equals sign",
        "was present. Everything from here to `enddef'",
        "will be the replacement text of this macro.");
      back_error();
    }
}
/* 694 */
void make_op_def (void)
{
  command_code m;
  pointer p, q, r;

  m = cur_mod;
  get_symbol();
  q = get_node(token_node_size);
  info(q) = cur_sym;
  value(q) = expr_base;
  get_clear_symbol();
  warning_info = cur_sym;
  get_symbol();
  p = get_node(token_node_size);
  info(p) = cur_sym;
  value(p) = expr_base + 1;
  link(p) = q;
  get_next();
  check_equals();
  scanner_status = op_defining;
  q = get_avail();
  ref_count(q) = null;
  r = get_avail();
  link(q) = r;
  info(r) = general_macro;
  link(r) = scan_toks(macro_def, p, null, 0);
  scanner_status = normal;
  eq_type(warning_info) = m;
  equiv(warning_info) = q;
  get_x_next();
}
/* 1032 */
void check_delimiter (pointer l_delim, pointer r_delim)
{
  if (cur_cmd == right_delimiter)
    if (cur_mod == l_delim)
      goto l_exit;
  if (cur_sym != r_delim)
  {
    missing_err(text(r_delim));
    help2("I found no right delimiter to match a left one. So I've",
      "put one in, behind the scenes; this may fix the problem.");
    back_error();
  }
  else
  {
    print_err("The token `");
    slow_print(text(r_delim));
    r_print("' is no longer a right delimiter");
    help3("Strange: This token has lost its former meaning!",
      "I'll read it as a right delimiter this time;",
      "but watch out, I'll probably miss it later.");
    error();
  }
l_exit:;
}
/* 1011 */
pointer scan_declared_variable (void)
{
  pointer x;
  pointer h, t;
  pointer l;

  get_symbol();
  x = cur_sym;
  if (cur_cmd != tag_token)
    clear_symbol(x, false);
  h = get_avail();
  info(h) = x;
  t = h;
  while (true)
  {
    get_x_next();
    if (cur_sym == 0)
      goto done;
    if (cur_cmd != tag_token)
      if (cur_cmd != internal_quantity)
        if (cur_cmd == left_bracket)
        {
          l = cur_sym;
          get_x_next();
          if (cur_cmd != right_bracket)
          {
            back_input();
            cur_sym = l;
            cur_cmd = left_bracket;
            goto done;
          }
          else
            cur_sym = collective_subscript;
        }
        else
          goto done;
    link(t) = get_avail();
    t = link(t);
    info(t) = cur_sym;
  }
done:
  if (eq_type(x) % outer_tag != tag_token)
    clear_symbol(x, false);
  if (equiv(x) == null)
    new_root(x);
  return h;
}
/* 697 */
void scan_def (void)
{
  unsigned char m;
  unsigned char n;
  unsigned char k;
  unsigned char c;
  pointer r;
  pointer q;
  pointer p;
  halfword base;
  pointer l_delim, r_delim;

  m = cur_mod;
  c = general_macro;
  link(hold_head) = null;
  q = get_avail();
  ref_count(q) = null;
  r = null;
  if (m == start_def)
  {
    get_clear_symbol();
    warning_info = cur_sym;
    get_next();
    scanner_status = op_defining;
    n = 0;
    eq_type(warning_info) = defined_macro;
    equiv(warning_info) = q;
  }
  else
  {
    p = scan_declared_variable();
    flush_variable(equiv(info(p)), link(p), true);
    warning_info = find_variable(p);
    flush_list(p);
    if (warning_info == null)
    {
      print_err("This variable already starts with a macro");
      help2("After `vardef a' you can't say `vardef a.b'.",
        "So I'll have to discard this definition.");
      error();
      warning_info = bad_vardef;
    }
    scanner_status = var_defining;
    n = 2;
    if (cur_cmd == macro_special)
      if (cur_mod == macro_suffix)
      {
        n = 3;
        get_next();
      }
    type(warning_info) = unsuffixed_macro - 2 + n;
    value(warning_info) = q;
  }
  k = n;
  if (cur_cmd == left_delimiter)
    do {
      l_delim = cur_sym;
      r_delim = cur_mod;
      get_next();
      if ((cur_cmd == param_type) && (cur_mod >= expr_base))
        base = cur_mod;
      else
      {
        print_err("Missing parameter type; `expr' will be assumed");
        help1("You should've had `expr' or `suffix' or `text' here.");
        back_error();
        base = expr_base;
      }
      do {
        link(q) = get_avail();
        q = link(q);
        info(q) = base + k;
        get_symbol();
        p = get_node(token_node_size);
        value(p) = base + k;
        info(p) = cur_sym;
        if (k == param_size)
          overflow("parameter stack size", param_size);
        incr(k);
        link(p) = r;
        r = p;
        get_next();
      } while (!(cur_cmd != comma));
      check_delimiter(l_delim, r_delim);
      get_next();
    } while (!(cur_cmd != left_delimiter));
  if (cur_cmd == param_type)
  {
    p = get_node(token_node_size);
    if (cur_mod < expr_base)
    {
      c = cur_mod;
      value(p) = expr_base + k;
    }
    else
    {
      value(p) = cur_mod + k;
      if (cur_mod == expr_base)
        c = expr_macro;
      else if (cur_mod == suffix_base)
        c = suffix_macro;
      else
        c = text_macro;
    }
    if (k == param_size)
      overflow("parameter stack size", param_size);
    incr(k);
    get_symbol();
    info(p) = cur_sym;
    link(p) = r;
    r = p;
    get_next();
    if (c == expr_macro)
      if (cur_cmd == of_token)
      {
        c = of_macro;
        p = get_node(token_node_size);
        if (k == param_size)
          overflow("parameter stack size", param_size);
        value(p) = expr_base + k;
        get_symbol();
        info(p) = cur_sym;
        link(p) = r;
        r = p;
        get_next();
      }
  }
  check_equals();
  p = get_avail();
  info(p) = c;
  link(q) = p;
  if (m == start_def)
    link(p) = scan_toks(macro_def, r, null, n);
  else
  {
    q = get_avail();
    info(q) = bg_loc;
    link(p) = q;
    p = get_avail();
    info(p) = eg_loc;
    link(q) = scan_toks(macro_def, r, p, n);
  }
  if (warning_info == bad_vardef)
    flush_token_list(value(bad_vardef));
  scanner_status = normal;
  get_x_next();
}
void scan_primary(void);
void scan_secondary(void); void scan_tertiary(void);
void scan_expression(void); void scan_suffix(void);
/* 722 */
void print_macro_name (pointer a, pointer n)
{
  pointer p, q;

  if (n != null)
    slow_print(text(n));
  else
  {
    p = info(a);
    if (p == null)
      slow_print(text(info(info(link(a)))));
    else
    {
      q = p;
      while (link(q) != null)
        q = link(q);
      link(q) = info(link(a));
      show_token_list(p, null, 1000, 0);
      link(q) = null;
    }
  }
}
/* 723 */
void print_arg (pointer q, integer n, pointer b)
{
  if (link(q) = _void)
    r_print_nl("(EXPR");
  else if ((b < text_base) && (b != text_macro))
    r_print_nl("(SUFFIX");
  else
    r_print_nl("(TEXT");
  print_int(n);
  r_print(")<-");
  if (link(q) = _void)
    print_exp(q, 1);
  else
    show_token_list(q, null, 1000, 0);
}
/* 730 */
void scan_text_arg (pointer l_delim, pointer r_delim)
{
  integer balance;
  pointer p;

  warning_info = l_delim;
  scanner_status = absorbing;
  p = hold_head;
  balance = 1;
  link(hold_head) = null;
  while (true)
  {
    get_next();
    if (l_delim == 0)
    {
      if (end_of_statement)
      {
        if (balance == 1)
          goto done;
        else if (cur_cmd == end_group)
          decr(balance);
      }
      else if (cur_cmd == begin_group)
        incr(balance);
    }
    else
    {
      if (cur_cmd == right_delimiter)
      {
        if (cur_mod == l_delim)
        {
          decr(balance);
          if (balance == 0)
            goto done;
        }
      }
      else if (cur_cmd == left_delimiter)
        if (cur_mod == r_delim)
          incr(balance);
    }
    link(p) = cur_tok();
    p = link(p);
  }
done:
  cur_exp = link(hold_head);
  cur_type = token_list;
  scanner_status = normal;
}
/* 720 */
void macro_call (pointer def_ref, pointer arg_list, pointer macro_name)
{
  pointer r;
  pointer p, q;
  integer n;
  pointer l_delim, r_delim;
  pointer tail;

  r = link(def_ref);
  add_mac_ref(def_ref);
  if (arg_list == null)
    n = 0;
  else
  {
    n = 1;
    tail = arg_list;
    while (link(tail) != null)
    {
      incr(n);
      tail = link(tail);
    }
  }
  if (internal[tracing_macros] > 0)
  {
    begin_diagnostic();
    print_ln();
    print_macro_name (arg_list, macro_name);
    if (n == 3)
      r_print("@#");
    show_macro(def_ref, 0, 100000);
    if (arg_list != null)
    {
      n = 0;
      p = arg_list;
      do {
        q = info(p);
        print_arg(q, n, 0);
        incr(n);
        p = link(p);
      } while (!(p == null));
    }
    end_diagnostic(false);
  }
  cur_cmd = comma + 1;
  while (info(r) >= expr_base)
  {
    if (cur_cmd != comma)
    {
      get_x_next();
      if (cur_cmd != left_delimiter)
      {
        print_err("Missing argument to ");
        print_macro_name (arg_list, macro_name);
        help3("That macro has more parameters than you thought.",
          "I'll continue by pretending that each missing argument",
          "is either zero or null.");
        if (info(r) >= suffix_base)
        {
          cur_exp = null;
          cur_type = token_list;
        }
        else
        {
          cur_exp = 0;
          cur_type = known;
        }
        back_error();
        cur_cmd = right_delimiter;
        goto found;
      }
      l_delim = cur_sym;
      r_delim = cur_mod;
    }
    if (info(r) >= text_base)
      scan_text_arg(l_delim, r_delim);
    else
    {
      get_x_next();
      if (info(r) >= suffix_base)
        scan_suffix();
      else
        scan_expression();
    }
    if (cur_cmd != comma)
      if ((cur_cmd != right_delimiter) || (cur_mod != l_delim))
        if (info(link(r)) >= expr_base)
        {
          missing_err(",");
          help3("I've finished reading a macro argument and am about to",
            "read another; the arguments weren't delimited correctly.",
            "You might want to delete some tokens before continuing.");
          back_error();
          cur_cmd = comma;
        }
        else
        {
          missing_err(text(r_delim));
          help2("I've gotten to the end of the macro parameter list.",
            "You might want to delete some tokens before continuing.");
          back_error();
        }
  found:
    {
      p = get_avail();
      if (cur_type == token_list)
        info(p) = cur_exp;
      else
        info(p) = stash_cur_exp();
      if (internal[tracing_macros] > 0)
      {
        begin_diagnostic();
        print_arg(info(p), n, info(r));
        end_diagnostic(false);
      }
      if (arg_list == null)
        arg_list = p;
      else
        link(tail) = p;
      tail = p;
      incr(n);
    }
    r = link(r);
  }
  if (cur_cmd == comma)
  {
    print_err("Too many arguments to ");
    print_macro_name(arg_list, macro_name);
    print_char(';');
    r_print_nl("  Missing `");
    slow_print(text(r_delim));
    r_print("' has been inserted");
    help3("I'm going to assume that the comma I just read was a",
      "right delimiter, and then I'll begin expanding the macro.",
      "You might want to delete some tokens before continuing.");
    error();
  }
  if (info(r) != general_macro)
  {
    if (info(r) < text_macro)
    {
      get_x_next();
      if (info(r) != suffix_macro)
        if ((cur_cmd == equals) || (cur_cmd == assignment))
          get_x_next();
    }
    switch (info(r))
    {
      case primary_macro:
        scan_primary();
        break;
      case secondary_macro:
        scan_secondary();
        break;
      case tertiary_macro:
        scan_tertiary();
        break;
      case expr_macro:
        scan_expression();
        break;
      case of_macro:
        {
          scan_expression();
          p = get_avail();
          info(p) = stash_cur_exp();
          if (internal[tracing_macros] > 0)
          {
            begin_diagnostic();
            print_arg(info(p), n, 0);
            end_diagnostic(false);
          }
          if (arg_list == null)
            arg_list = p;
          else
            link(tail) = p;
          tail = p;
          incr(n);
          if (cur_cmd != of_token)
          {
            missing_err(" of ");
            r_print(" for ");
            print_macro_name(arg_list, macro_name);
            help1("I've got the first argument; will look now for the other.");
            back_error();
          }
          get_x_next();
          scan_primary();
        }
        break;
      case suffix_macro:
        {
          if (cur_cmd != left_delimiter)
            l_delim = null;
          else
          {
            l_delim = cur_sym;
            r_delim = cur_mod;
            get_x_next();
          }
          scan_suffix();
          if (l_delim != null)
          {
            if ((cur_cmd != right_delimiter) || (cur_mod != l_delim))
            {
              missing_err(text(r_delim));
              help2("I've gotten to the end of the macro parameter list.", 
                "You might want to delete some tokens before continuing.");
              back_error();
            }
            get_x_next();
          }
        }
        break;
      case text_macro:
        scan_text_arg(0, 0);
        break;
    }
    back_input();
    {
      p = get_avail();
      if (cur_type == token_list)
        info(p) = cur_exp;
      else
        info(p) = stash_cur_exp();
      if (internal[tracing_macros] > 0)
      {
        begin_diagnostic();
        print_arg(info(p), n, info(r));
        end_diagnostic(false);
      }
      if (arg_list == null)
        arg_list = p;
      else
        link(tail) = p;
      tail = p;
      incr(n);
    }
  }
  r = link(r);
  while (token_state && (loc == null))
    end_token_list();
  if (param_ptr + n > max_param_stack)
  {
    max_param_stack = param_ptr + n;
    if (max_param_stack > param_size)
      overflow("parameter stack size", param_size);
  }
  begin_token_list(def_ref, macro);
  name = macro_name;
  loc = r;
  if (n > 0)
  {
    p = arg_list;
    do {
      param_stack[param_ptr] = info(p);
      incr(param_ptr);
      p = link(p);
    } while (!(p == null));
    flush_list(arg_list);
  }
}
void get_boolean(void); void pass_text(void);
void conditional(void); void start_input(void);
void begin_iteration(void); void resume_iteration(void);
void stop_iteration(void);
/* 707 */
void expand (void)
{
  pointer p;
  integer k;
  pool_pointer j;

  if (internal[tracing_commands] > unity)
    if (cur_cmd != defined_macro)
      show_cmd_mod(cur_cmd, cur_mod);
  switch (cur_cmd)
  {
    case if_test:
      conditional();
      break;
    case fi_or_else:
      if (cur_mod > if_limit)
        if (if_limit == if_code)
        {
          missing_err(":");
          back_input();
          cur_sym = frozen_colon;
          ins_error();
        }
        else
        {
          print_err("Extra ");
          print_cmd_mod(fi_or_else, cur_mod);
          help1("I'm ignoring this; it doesn't match any if.");
          error();
        }
      else
      {
        while (cur_mod != fi_code)
          pass_text();
        {
          p = cond_ptr;
          if_line = if_line_field(p);
          cur_if = name_type(p);
          if_limit = type(p);
          cond_ptr = link(p);
          free_node(p, if_node_size);
        }
      }
      break;
    case input:
      if (cur_mod > 0)
        force_eof = true;
      else
        start_input();
      break;
    case iteration:
      if (cur_mod == end_for)
      {
        print_err("Extra `endfor'");
        help2("I'm not currently working on a for loop,",
          "so I had better not try to end anything.");
        error();
      }
      else
        begin_iteration();
      break;
    case repeat_loop:
      {
        while (token_state && (loc == null))
          end_token_list();
        if (loop_ptr == null)
        {
          print_err("Lost loop");
          help2("I'm confused; after exiting from a loop, I still seem",
            "to want to repeat it. I'll try to forget the problem.");
          error();
        }
        else
          resume_iteration();
      }
      break;
    case exit_test:
      {
        get_boolean();
        if (internal[tracing_commands] > unity)
          show_cmd_mod(nullary, cur_exp);
        if (cur_exp == true_code)
          if (loop_ptr == null)
          {
            print_err("No loop is in progress");
            help1("Why say `exitif' when there's nothing to exit from?");
            if (cur_cmd == semicolon)
              error();
            else
              back_error();
          }
          else
          {
            p = null;
            do {
              if (file_state)
                end_file_reading();
              else
              {
                if (token_type <= loop_text)
                  p = start;
                end_token_list();
              }
            } while (!(p != null));
            if (p != info(loop_ptr))
              fatal_error("*** (loop confusion)");
            stop_iteration();
          }
        else if (cur_cmd != semicolon)
        {
          missing_err(";");
          help2("After `exitif <boolean exp>' I expect to see a semicolon.",
            "I shall pretend that one was there.");
          back_error();
        }
      }
      break;
    case relax:
      do_nothing();
      break;
    case expand_after:
      {
        get_next();
        p = cur_tok();
        get_next();
        if (cur_cmd < min_command)
          expand();
        else
          back_input();
        back_list(p);
      }
      break;
    case scan_tokens:
      {
        get_x_next();
        scan_primary();
        if (cur_type != string_type)
        {
          disp_err(null, "Not a string");
          help2("I'm going to flush this expression, since",
            "scantokens should be followed by a known string.");
          put_get_flush_error(0);
        }
        else
        {
          back_input();
          if (length(cur_exp) > 0)
          {
            begin_file_reading();
            name = 2;
            k = first + length(cur_exp);
            if (k >= max_buf_stack)
            {
              if (k >= buf_size)
              {
                max_buf_stack = buf_size;
                overflow("buffer size", buf_size);
              }
              max_buf_stack = k + 1;
            }
            j = str_start[cur_exp];
            limit = k;
            while (first < limit)
            {
              buffer[first] = so(str_pool[j]);
              incr(j);
              incr(first);
            }
            buffer[limit] = '%';
            first = limit + 1;
            loc = start;
            flush_cur_exp(0);
          }
        }
      }
      break;
    case defined_macro:
      macro_call(cur_mod, null, cur_sym);
      break;
  }
}
/* 718 */
void get_x_next (void)
{
  pointer save_exp;

  get_next();
  if (cur_cmd < min_command)
  {
    save_exp = stash_cur_exp();
    do {
      if (cur_cmd == defined_macro)
        macro_call(cur_mod, null, cur_sym);
      else
        expand();
      get_next();
    } while (!(cur_cmd >= min_command));
    unstash_cur_exp(save_exp);
  }
}
/* 737 */
void stack_argument (pointer p)
{
  if (param_ptr == max_param_stack)
  {
    incr(max_param_stack);
    if (max_param_stack > param_size)
      overflow("parameter stack size", param_size);
  }
  param_stack[param_ptr] = p;
  incr(param_ptr);
}
/* 742 */
void pass_text (void)
{
  integer l;

  scanner_status = skipping;
  l = 0;
  warning_info = line;
  while (true)
  {
    get_next();
    if (cur_cmd <= fi_or_else)
      if (cur_cmd < fi_or_else)
        incr(l);
      else
      {
        if (l == 0)
          goto done;
        if (cur_mod == fi_code)
          decr(l);
      }
    else if (cur_cmd == string_token)
      delete_str_ref(cur_mod);
  }
done:
  scanner_status = normal;
}
/* 746 */
void change_if_limit (small_number l, pointer p)
{
  pointer q;

  if (p == cond_ptr)
    if_limit = l;
  else
  {
    q = cond_ptr;
    while (true)
    {
      if (q == null)
        confusion("if");
      if (link(q) == p)
      {
        type(q) = l;
        goto l_exit;
      }
      q = link(q);
    }
  }
l_exit:;
}
/* 747 */
void check_colon (void)
{
  if (cur_cmd != colon)
  {
    missing_err(":");
    help2("There should've been a colon after the condition.",
      "I shall pretend that one was there.");
    back_error();
  }
}
/* 748 */
void conditional (void)
{
  pointer save_cond_ptr;
  unsigned char new_if_limit;
  pointer p;

  {
    p = get_node(if_node_size);
    link(p) = cond_ptr;
    type(p) = if_limit;
    name_type(p) = cur_if;
    if_line_field(p) = if_line;
    cond_ptr = p;
    if_limit = if_code;
    if_line = line;
    cur_if = if_code;
  }
  save_cond_ptr = cond_ptr;
lab_reswitch:
  get_boolean();
  new_if_limit = else_if_code;
  if (internal[tracing_commands] > unity)
  {
    begin_diagnostic();
    if (cur_exp == true_code)
      r_print("{true}");
    else
      r_print("{false}");
    end_diagnostic(false);
  }
found:
  check_colon();
  if (cur_exp == true_code)
  {
    change_if_limit(new_if_limit, save_cond_ptr);
    goto l_exit;
  }
  while (true)
  {
    pass_text();
    if (cond_ptr == save_cond_ptr)
      goto done;
    else if (cur_mod == fi_code)
    {
      p = cond_ptr;
      if_line = if_line_field(p);
      cur_if = name_type(p);
      if_limit = type(p);
      cond_ptr = link(p);
      free_node(p, if_node_size);
    }
  }
done:
  cur_if = cur_mod;
  if_line = line;
  if (cur_mod == fi_code)
  {
    p = cond_ptr;
    if_line = if_line_field(p);
    cur_if = name_type(p);
    if_limit = type(p);
    cond_ptr = link(p);
    free_node(p, if_node_size);
  }
  else if (cur_mod == else_if_code)
    goto lab_reswitch;
  else
  {
    cur_exp = true_code;
    new_if_limit = fi_code;
    get_x_next();
    goto found;
  }
l_exit:;
}
/* 754 */
void bad_for (str_number s)
{
  disp_err(null, "Improper ");
  print(s);
  r_print(" has been replaced by 0");
  help4("When you say `for x=a step b until c',",
    "the initial value `a' and the step size `b'",
    "and the final value `c' must have known numeric values.",
    "I'm zeroing this one. Proceed, with fingers crossed.");
  put_get_flush_error(0);
}
/* 755 */
void begin_iteration (void)
{
  halfword m;
  halfword n;
  pointer p, q, s, pp;

  m = cur_mod;
  n = cur_sym;
  s = get_node(loop_node_size);
  if (m == start_forever)
  {
    loop_type(s) = _void;
    p = null;
    get_x_next();
    goto found;
  }
  get_symbol();
  p = get_node(token_node_size);
  info(p) = cur_sym;
  value(p) = m;
  get_x_next();
  if ((cur_cmd != equals) && (cur_cmd != assignment))
  {
    missing_err("=");
    help3("The next thing in this loop should have been `=' or `:='.", 
      "But don't worry; I'll pretend that an equals sign", 
      "was present, and I'll look for the values next.");
    back_error();
  }
  loop_type(s) = null;
  q = loop_list_loc(s);
  link(q) = null;
  do {
    get_x_next();
    if (m != expr_base)
      scan_suffix();
    else
    {
      if (cur_cmd >= colon)
        if (cur_cmd <= comma)
          goto l_continue;
      scan_expression();
      if (cur_cmd == step_token)
        if (q == loop_list_loc(s))
        {
          if (cur_type != known)
            bad_for("initial value");
          pp = get_node(progression_node_size);
          value(pp) = cur_exp;
          get_x_next();
          scan_expression();
          if (cur_type != known)
            bad_for("step size");
          step_size(pp) = cur_exp;
          if (cur_cmd != until_token)
          {
            missing_err("until");
            help2("I assume you meant to say `until' after `step'.",
              "So I'll look for the final value and colon next.");
            back_error();
          }
          get_x_next();
          scan_expression();
          if (cur_type != known)
            bad_for("final value");
          final_value(pp) = cur_exp;
          loop_type(s) = pp;
          goto done;
        }
      cur_exp = stash_cur_exp();
    }
    link(q) = get_avail();
    q = link(q);
    info(q) = cur_exp;
    cur_type = vacuous;
  l_continue:;
  } while (!(cur_cmd != comma));
done:;
found:
  if (cur_cmd != colon)
  {
    missing_err(":");
    help3("The next thing in this loop should have been a `:'.",
      "So I'll pretend that a colon was present;",
      "everything from here to `endfor' will be iterated.");
    back_error();
  }
  q = get_avail();
  info(q) = frozen_repeat_loop;
  scanner_status = loop_defining;
  warning_info = n;
  info(s) = scan_toks(iteration, p, q, 0);
  scanner_status = normal;
  link(s) = loop_ptr;
  loop_ptr = s;
  resume_iteration();
}
/* 760 */
void resume_iteration (void)
{
  pointer p, q;

  p = loop_type(loop_ptr);
  if (p > _void)
  {
    cur_exp = value(p);
    if (((step_size(p) > 0) && (cur_exp > final_value(p))) || ((step_size(p) < 0) && (cur_exp < final_value(p))))
      goto not_found;
    cur_type = known;
    q = stash_cur_exp();
    value(p) = cur_exp + step_size(p);
  }
  else if (p < _void)
  {
    p = loop_list(loop_ptr);
    if (p == null)
      goto not_found;
    loop_list(loop_ptr) = link(p);
    q = info(p);
    free_avail(p);
  }
  else
  {
    begin_token_list(info(loop_ptr), forever_text);
    goto l_exit;
  }
  begin_token_list(info(loop_ptr), loop_text);
  stack_argument(q);
  if (internal[tracing_commands] > unity)
  {
    begin_diagnostic();
    r_print_nl("{loop value=");
    if ((q != null) && (link(q) = _void))
      print_exp(q, 1);
    else
      show_token_list(q, null, 50, 0);
    print_char('}');
    end_diagnostic (false);
  }
  goto l_exit;
not_found:
  stop_iteration();
l_exit:;
}
/* 763 */
void stop_iteration (void)
{
  pointer p, q;

  p = loop_type(loop_ptr);
  if (p > _void)
    free_node(p, progression_node_size);
  else if (p < _void)
  {
    q = loop_list(loop_ptr);
    while (q != null)
    {
      p = info(q);
      if (p != null)
        if (link(p) == _void)
        {
          recycle_value(p);
          free_node(p, value_node_size);
        }
        else
          flush_token_list(p);
      p = q;
      q = link(q);
      free_avail(p);
    }
  }
  p = loop_ptr;
  loop_ptr = link(p);
  flush_token_list(info(p));
  free_node(p, loop_node_size);
}
/* 770 */
void begin_name (void)
{
  area_delimiter = 0;
  ext_delimiter = 0;
}
/* 771 */
boolean more_name(ASCII_code c)
{
  if (c == ' ')
    return false;
  else
  {
    if ((c == '>') || (c == ':'))
    {
      area_delimiter = pool_ptr;
      ext_delimiter = 0;
    }
    else if ((c == '.') && (ext_delimiter == 0))
      ext_delimiter = pool_ptr;
    str_room(1);
    append_char(c);
    return true;
  }
}
/* 772 */
void end_name (void)
{
  if (str_ptr + 3 > max_str_ptr)
  {
    if (str_ptr + 3 > max_strings)
      overflow("number of strings", max_strings - init_str_ptr);
    max_str_ptr = str_ptr + 3;
  }
  {
    if (pool_ptr + 6 > max_pool_ptr)
    {
      if (pool_ptr + 6 > pool_size)
        overflow("pool size", pool_size - init_pool_ptr);
      max_pool_ptr = pool_ptr + 6;
    }
  }
  if (area_delimiter == 0)
    cur_area = "";
  else
  {
    cur_area = str_ptr;
    incr(str_ptr);
    str_start[str_ptr] = area_delimiter + 1;
  }
  if (ext_delimiter == 0)
  {
    cur_ext = "";
    cur_name = make_string();
  }
  else
  {
    cur_name = str_ptr;
    incr(str_ptr);
    str_start[str_ptr] = ext_delimiter;
    cur_ext = make_string();
  }
}
/* 774 */
void pack_file_name (str_number n, str_number a, str_number e)
{
  integer k;
  ASCII_code c;
  pool_pointer j;

  k = 0;
  for (j = str_start[a]; j <= str_start[a + 1] - 1; j++)
    append_to_name(so(str_pool[j]));
  for (j = str_start[n]; j <= str_start[n + 1] - 1; j++)
    append_to_name(so(str_pool[j]));
  for (j = str_start[e]; j <= str_start[e + 1] - 1; j++)
    append_to_name(so(str_pool[j]));
  if (k <= file_name_size)
    name_length = k;
  else
    name_length = file_name_size;
  for (k = name_length + 1; k <= file_name_size; k++)
    name_of_file[k] = ' ';
}
/* 778 */
void pack_buffered_name (small_number n, integer a, integer b)
{
  integer k;
  ASCII_code c;
  integer j;

  if (n + b - a + 1 + base_ext_length > file_name_size)
    b = a + file_name_size - n - 1 - base_ext_length;
  k = 0;
  for (j = 1; j <= n; j++)
    append_to_name(xord[MF_base_default[j]]);
  for (j = a; j <= b; j++)
    append_to_name(buffer[j]);
  for (j = base_default_length - 4; j <= base_default_length; j++)
    append_to_name(xord[MF_base_default[j]]);
  if (k <= file_name_size)
    name_length = k;
  else
    name_length = file_name_size;
  for (k = name_length + 1; k <= file_name_size; k++)
    name_of_file[k] = ' ';
}
/* 780 */
str_number make_name_string (void)
{
  integer k;

  if ((pool_ptr + name_length > pool_size) || (str_ptr == max_strings))
    return "?";
  else
  {
    for (k = 1; k <= name_length; k++)
      append_char(xord[name_of_file[k]]);
    return make_string();
  }
}
/* 780 */
str_number a_make_name_string (alpha_file f)
{  
  return make_name_string();
}
/* 780 */
str_number b_make_name_string (byte_file f)
{
  return make_name_string();
}
/* 780 */
str_number w_make_name_string (word_file f)
{
  return make_name_string();
}
/* 781 */
void scan_file_name (void)
{
  begin_name();
  while (buffer[loc] == ' ')
    incr(loc);
  while (true)
  {
    if ((buffer[loc] == ';') || (buffer[loc] == '%'))
      goto done;
    if (!more_name(buffer[loc]))
      goto done;
    incr(loc);
  }
done:
  end_name();
}
/* 784 */
void pack_job_name (str_number s)
{
  cur_area = "";
  cur_ext = s;
  cur_name = job_name;
  pack_cur_name();
}
/* 786 */
void prompt_file_name (str_number s, str_number e)
{
  integer k;
  str_number saved_cur_name;

  if (interaction == scroll_mode)
    wake_up_terminal();
  if (s == "input file name")
    print_err("I can't find file `");
  else
    print_err("I can't write on file `");
  print_file_name(cur_name, cur_area, cur_ext);
  r_print("'.");
  if (e == ".mf")
    show_context();
  r_print_nl("Please type another ");
  print(s);
  if (interaction < scroll_mode)
    fatal_error("*** (job aborted, file error in nonstop mode)");
  saved_cur_name = cur_name;
  prompt_input(": ");
  {
    begin_name();
    k = first;
    while ((buffer[k] == ' ') && (k < last))
      incr(k);
    while (true)
    {
      if (k == last)
        goto done;
      if (!more_name(buffer[k]))
        goto done;
      incr(k);
    }
  done:
    end_name();
  }
  if (cur_ext == "")
    cur_ext = e;
  pack_cur_name();
}
/* 788 */
void open_log_file (void)
{
  unsigned char old_setting;
  integer k;
  integer l;
  integer m;
  const char * months;

  old_setting = selector;
  if (job_name == 0)
    job_name = getjob_name("mfput");
  pack_job_name(".log");
  while (!a_open_out(log_file))
  {
    selector = term_only;
    prompt_file_name("transcript file name", ".log");
  }
  log_name = a_make_name_string(log_file);
  selector = log_only;
  log_opened = true;
  {
    wlog(banner);
    slow_print(base_ident);
    r_print("  ");
    print_int(round_unscaled(internal[day]));
    print_char(' ');
    months = " JANFEBMARAPRMAYJUNJULAUGSEPOCTNOVDEC";
    m = round_unscaled(internal[month]);
    for (k = 3 * m - 2; k <= 3 * m; k++)
      wlog(months[k], log_file);
    print_char(' ');
    print_int(round_unscaled(internal[year]));
    print_char(' ');
    m = round_unscaled(internal[time]);
    print_dd(m / 60);
    print_char(':');
    print_dd(m % 60);
  }
  input_stack[input_ptr] = cur_input;
  r_print_nl("**");
  l = input_stack[0].limit_field - 1;
  for (k = 1; k <= l; k++)
    print(buffer[k]);
  print_ln();
  selector = old_setting + 2;
}
/* 793 */
void start_input (void)
{
  while (token_state && (loc == null))
    end_token_list();
  if (token_state)
  {
    print_err("File names can't appear within macros");
    help3("Sorry...I've converted what follows to tokens,",
      "possibly garbaging the name you gave.",
      "Please delete the tokens and insert the name again.");
    error();
  }
  if (file_state)
    scan_file_name();
  else
  {
    cur_name = "";
    cur_ext = "";
    cur_area = "";
  }
  if (cur_ext == "")
    cur_ext = ".mf";
  pack_cur_name();
  while (true)
  {
    begin_file_reading();
    if (a_open_in(cur_file))
      goto done;
    if (cur_area == "")
    {
      pack_file_name(cur_name, MF_area, cur_ext);
      if (a_open_in(cur_file))
        goto done;
    }
    end_file_reading();
    prompt_file_name("input file name", ".mf");
  }
done:
  name = a_make_name_string(cur_file);
  str_ref[cur_name] = max_str_ptr;
  if (job_name == 0)
  {
    job_name = getjob_name(cur_name);
    open_log_file();
  }
  if (term_offset + length(name) > max_print_line - 2)
    print_ln();
  else if ((term_offset > 0) || (file_offset > 0))
    print_char(' ');
  print_char('(');
  incr(open_parens);
  slow_print(name);
  update_terminal();
  if (name == str_ptr - 1)
  {
    flush_string(name);
    name = cur_name;
  }
  {
    line = 1;
    if (input_ln(cur_file, false))
      do_nothing();
    firm_up_the_line();
    buffer[limit] = '%';
    first = limit + 1;
    loc = start;
  }
}
/* 824 */
void bad_exp (str_number s)
{
  unsigned char save_flag;

  print_err(s);
  r_print(" expression can't begin with `");
  print_cmd_mod (cur_cmd, cur_mod);
  print_char('\'');
  help4("I'm afraid I need some sort of value in order to continue,",
    "so I've tentatively inserted `0'. You may want to",
    "delete this zero and insert something else;",
    "see Chapter 27 of The METAFONTbook for an example.");
  back_input();
  cur_sym = 0;
  cur_cmd = numeric_token;
  cur_mod = 0;
  ins_error();
  save_flag = var_flag;
  var_flag = 0;
  get_x_next();
  var_flag = save_flag;
}
/* 827 */
void stash_in (pointer p)
{
  pointer q;

  type(p) = cur_type;
  if (cur_type == known)
    value(p) = cur_exp;
  else
  {
    if (cur_type == independent)
    {
      q = single_dependency(cur_exp);
      if (q == dep_final)
      {
        type(p) = known;
        value(p) = 0;
        free_node(q, dep_node_size);
      }
      else
      {
        type(p) = dependent;
        new_dep(p, q);
      }
      recycle_value(cur_exp);
    }
    else
    {
      mem[value_loc(p)] = mem[value_loc(cur_exp)];
      link(prev_dep(p)) = p;
    }
    free_node(cur_exp, value_node_size);
  }
  cur_type = vacuous;
}
/* 848 */
void back_expr (void)
{
  pointer p;

  p = stash_cur_exp();
  link(p) = null;
  back_list(p);
}
/* 849 */
void bad_sub_script (void)
{
  disp_err(null, "Improper subscript has been replaced by zero");
  help3("A bracketed subscript must have a known numeric value;",
    "unfortunately, what I found was the value that appears just",
    "above this error message. So I'll try a zero subscript.");
  flush_error(0);
}
/* 851 */
void obliterated (pointer q)
{
  print_err("Variable ");
  show_token_list(q, null, 1000, 0);
  r_print(" has been obliterated");
  help3("It seems you did a nasty thing---probably by accident,",
    "but nevertheless you nearly hornswoggled me...",
    "While I was evaluating the right-hand side of this",
    "command, something happened, and the left-hand side",
    "is no longer a variable! So I won't change anything.");
}
/* 863 */
void binary_mac (pointer p, pointer c, pointer n)
{
  pointer q, r;

  q = get_avail();
  r = get_avail();
  link(q) = r;
  info(q) = p;
  info(r) = stash_cur_exp;
  macro_call(c, q, n);
}
/* 865 */
void materialize_pen (void)
{
  scaled a_minus_b, a_plus_b, major_axis, minor_axis;
  angle theta;
  pointer p;
  pointer q;

  q = cur_exp;
  if (left_type(q) == endpoint)
  {
    print_err("Pen path must be a cycle");
    help2("I can't make a pen from the given path.",
      "So I've replaced it by the trivial path `(0,0)..cycle'.");
    put_get_error();
    cur_exp = null_pen;
    goto common_ending;
  }
  else if (left_type(q) == open)
  {
    tx = x_coord(q);
    ty = y_coord(q);
    txx = left_x(q) - tx;
    tyx = left_y(q) - ty;
    txy = right_x(q) - tx;
    tyy = right_y(q) - ty;
    a_minus_b = pyth_add(txx - tyy, tyx + txy);
    a_plus_b = pyth_add(txx + tyy, tyx - txy);
    major_axis = half(a_minus_b + a_plus_b);
    minor_axis = half(abs(a_plus_b - a_minus_b));
    if (major_axis == minor_axis)
      theta = 0;
    else
      theta = half(n_arg(txx - tyy, tyx + txy) + n_arg(txx + tyy, tyx - txy));
    free_node(q, knot_node_size);
    q = make_ellipse(major_axis, minor_axis, theta);
    if ((tx != 0) || (ty != 0))
    {
      p = q;
      do {
        x_coord(p) = x_coord(p) + tx;
        y_coord(p) = y_coord(p) + ty;
        p = link(p);
      } while (!(p == q));
    }
  }
  cur_exp = make_pen(q);
common_ending:
  toss_knot_list(q);
  cur_type = pen_type;
}
/* 872 */
void known_pair (void)
{
  pointer p;

  if (cur_type != pair_type)
  {
    exp_err("Undefined coordinates have been replaced by (0,0)");
    help5("I need x and y numbers for this part of the path.",
      "The value I found (see above) was no good;",
      "so I'll try to keep going by using zero instead.",
      "(Chapter 27 of The METAFONTbook explains that",
      "you might want to type `I ???' now.)");
    put_get_flush_error(0);
    cur_x = 0;
    cur_y = 0;
  }
  else
  {
    p = value(cur_exp);
    if (type(x_part_loc(p)) == known)
      cur_x = value(x_part_loc(p));
    else
    {
      disp_err(p, "Undefined x coordinate has been replaced by 0");
      help5("I need a `known' x value for this part of the path.",
        "The value I found (see above) was no good;",
        "so I'll try to keep going by using zero instead.",
        "(Chapter 27 of The METAFONTbook explains that",
        "you might want to type `I ???' now.)");
      put_get_error();
      recycle_value(p);
      cur_x = 0;
    }
    if (type(y_part_loc(p)) == known)
      cur_y = value(y_part_loc(p));
    else
    {
      disp_err(y_part_loc(p), "Undefined y coordinate has been replaced by 0");
      help5("I need a `known' y value for this part of the path.",
        "The value I found (see above) was no good;",
        "so I'll try to keep going by using zero instead.",
        "(Chapter 27 of The METAFONTbook explains that",
        "you might want to type `I ???' now.)");
      put_get_error();
      recycle_value(y_part_loc(p));
      cur_y = 0;
    }
    flush_cur_exp(0);
  }
}
/* 871 */
pointer new_knot (void)
{
  pointer q;

  q = get_node(knot_node_size);
  left_type(q) = endpoint;
  right_type(q) = endpoint;
  link(q) = q;
  known_pair();
  x_coord(q) = cur_x;
  y_coord(q) = cur_y;
  return q;
}
/* 875 */
small_number scan_direction (void)
{
  unsigned char t;
  scaled x;

  get_x_next();
  if (cur_cmd == curl_command)
  {
    get_x_next();
    scan_expression();
    if ((cur_type != known) || (cur_exp < 0))
    {
      disp_err(null, "Improper curl has been replaced by 1");
      help1("A curl must be a known, nonnegative number.");
      put_get_flush_error(unity);
    }
    t = curl;
  }
  else
  {
    scan_expression();
    if (cur_type > pair_type)
    {
      if (cur_type != known)
      {
        exp_err("Undefined x coordinate has been replaced by 0");
        help5("I need a `known' x value for this part of the path.", 
          "The value I found (see above) was no good;",
          "so I'll try to keep going by using zero instead.",
          "(Chapter 27 of The METAFONTbook explains that",
          "you might want to type `I ???' now.)");
        put_get_flush_error(0);
      }
      x = cur_exp;
      if (cur_cmd != comma)
      {
        missing_err(",");
        help2("I've got the x coordinate of a path direction;",
          "will look for the y coordinate next.");
        back_error();
      }
      get_x_next();
      scan_expression();
      if (cur_type != known)
      {
        disp_err(null, "Undefined y coordinate has been replaced by 0");
        help5("I need a `known' y value for this part of the path.",
          "The value I found (see above) was no good;",
          "so I'll try to keep going by using zero instead.",
          "(Chapter 27 of The METAFONTbook explains that",
          "you might want to type `I ???' now.)");
        put_get_flush_error(0);
      }
      cur_y = cur_exp;
      cur_x = x;
    }
    else
      known_pair();
    if ((cur_x == 0) && (cur_y == 0))
      t = open;
    else
    {
      t = given;
      cur_exp = n_arg(cur_x, cur_y);
    }
  }
  if (cur_cmd != right_brace)
  {
    missing_err("}");
    help3("I've scanned a direction spec for part of a path,",
      "so a right brace should have come next.",
      "I shall pretend that one was there.");
    back_error();
  }
  get_x_next();
  return t;
}
/* 895 */
void do_nullary (quarterword c)
{
  integer k;

  check_arith();
  if (internal[tracing_commands] > two)
    show_cmd_mod(nullary, c);
  switch (c)
  {
    case true_code:
    case false_code:
      {
        cur_type = boolean_type;
        cur_exp = c;
      }
      break;
    case null_picture_code:
      {
        cur_type = picture_type;
        cur_exp = get_node(edge_header_size);
        init_edges(cur_exp);
      }
      break;
    case null_pen_code:
      {
        cur_type = pen_type;
        cur_exp = null_pen;
      }
      break;
    case normal_deviate:
      {
        cur_type = known;
        cur_exp = norm_rand();
      }
      break;
    case pen_circle:
      {
        cur_type = future_pen;
        cur_exp = get_node(knot_node_size);
        left_type(cur_exp) = open;
        right_type(cur_exp) = open;
        link(cur_exp) = cur_exp;
        x_coord(cur_exp) = 0;
        y_coord(cur_exp) = 0;
        left_x(cur_exp) = unity;
        left_y(cur_exp) = 0;
        right_x(cur_exp) = 0;
        right_y(cur_exp) = unity;
      }
      break;
    case job_name_op:
      {
        if (job_name == 0)
          open_log_file();
        cur_type = string_type;
        cur_exp = job_name;
      }
      break;
    case read_string_op:
      {
        if (interaction <= nonstop_mode)
          fatal_error("*** (cannot readstring in nonstop modes)");
        begin_file_reading();
        name = 1;
        prompt_input("");
        str_room(last - start);
        for (k = start; k <= last - 1; k++)
          append_char(buffer[k]);
        end_file_reading();
        cur_type = string_type;
        cur_exp = make_string();
      }
      break;
  }
  check_arith();
}
/* 899 */
boolean nice_pair (integer p, quarterword t)
{
  boolean Result;

  if (t == pair_type)
  {
    p = value(p);
    if (type(x_part_loc(p)) == known)
      if (type(y_part_loc(p)) == known)
      {
        Result = true;
        goto l_exit;
      }
  }
  Result = false;
l_exit:;
  return Result;
}
/* 900 */
void print_known_or_unknown_type (small_number t, integer v)
{
  print_char('(');
  if (t < dependent)
  {
    if (t != pair_type)
      print_type (t);
    else if (nice_pair(v, pair_type))
      r_print("pair");
    else
      r_print("unknown pair");
  }
  else
    r_print("unknown numeric");
  print_char(')');
}
/* 901 */
void bad_unary (quarterword c)
{
  disp_err(null, "Not implemented: ");
  print_op(c);
  print_known_or_unknown_type(cur_type, cur_exp);
  help3("I'm afraid I don't know how to apply that operation to that",
    "particular type. Continue, and I'll simply return the",
    "argument (shown above) as the result of the operation.");
  put_get_error();
}
/* 904 */
void negate_dep_list (pointer p)
{
  while (true)
  {
    negate(value(p));
    if (info(p) == null)
      goto l_exit;
    p = link(p);
  }
l_exit:;
}
/* 908 */
void pair_to_path (void)
{
  cur_exp = new_knot();
  cur_type = path_type;
}
/* 910 */
void take_part (quarterword c)
{
  pointer p;

  p = value(cur_exp);
  value(temp_val) = p;
  type(temp_val) = cur_type;
  link(p) = temp_val;
  free_node(cur_exp, value_node_size);
  make_exp_copy(p + 2 * (c - x_part));
  recycle_value(temp_val);
}
/* 913 */
void str_to_num (quarterword c)
{
  integer n;
  ASCII_code m;
  pool_pointer k;
  unsigned char b;
  boolean bad_char;

  if (c == ASCII_op)
  {
    if (length(cur_exp) == 0)
      n = -1;
    else
      n = so(str_pool[str_start[cur_exp]]);
  }
  else
  {
    if (c == oct_op)
      b = 8;
    else
      b = 16;
    n = 0;
    bad_char = false;
    for (k = str_start[cur_exp]; k <= str_start[cur_exp + 1] - 1; k++)
    {
      m = so(str_pool[k]);
      if ((m >= '0') && (m <= '9'))
        m = m - '0';
      else if ((m >= 'A') && (m <= 'F'))
        m = m - 'A';
      else if ((m >= 'a') && (m <= 'f'))
        m = m - 'a';
      else
      {
        bad_char = true;
        m = 0;
      }
      if (m >= b)
      {
        bad_char = true;
        m = 0;
      }
      if (n < 32768 / b)
        n = n * b + m;
      else
        n = 32767;
    }
    if (bad_char)
    {
      exp_err("String contains illegal digits");
      if (c == oct_op)
        help1("I zeroed out characters that weren't in the range 0..7.");
      else
        help1("I zeroed out characters that weren't hex digits.");
      put_get_error();
    }
    if (n > 4095)
    {
      print_err("Number too large (");
      print_int(n);
      print_char(')');
      help1("I have trouble with numbers greater than 4095; watch out.");
      put_get_error();
    }
  }
  flush_cur_exp(n * unity);
}
/* 916 */
scaled path_length (void)
{
  scaled n;
  pointer p;

  p = cur_exp;
  if (left_type(p) == endpoint)
    n = -unity;
  else
    n = 0;
  do {
    p = link(p);
    n = n + unity;
  } while (!(p == cur_exp));
  return n;
}
/* 919 */
void test_known (quarterword c)
{
  unsigned char b;
  pointer p, q;

  b = false_code;
  switch (cur_type)
  {
    case vacuous:
    case boolean_type:
    case string_type:
    case pen_type:
    case future_pen:
    case path_type:
    case picture_type:
    case known:
      b = true_code;
      break;
    case transform_type:
    case pair_type:
      {
        p = value(cur_exp);
        q = p + big_node_size[cur_type];
        do {
          q = q - 2;
          if (type(q) != known)
            goto done;
        } while (!(q == p));
        b = true_code;
      done:;
      }
      break;
    default:
      do_nothing();
      break;
  }
  if (c == known_op)
    flush_cur_exp(b);
  else
    flush_cur_exp(true_code + false_code - b);
  cur_type = boolean_type;
}
/* 898 */
void do_unary (quarterword c)
{
  pointer p, q;
  integer x;

  check_arith();
  if (internal[tracing_commands] > two)
  {
    begin_diagnostic();
    r_print_nl("{");
    print_op(c);
    print_char('(');
    print_exp(null, 0);
    r_print(")}");
    end_diagnostic(false);
  }
  switch (c)
  {
    case plus:
      if (cur_type < pair_type)
        if (cur_type != picture_type)
          bad_unary(plus);
      break;
    case minus:
      switch (cur_type)
      {
        case pair_type:
        case independent:
          {
            q = cur_exp;
            make_exp_copy(q);
            if (cur_type == dependent)
              negate_dep_list(dep_list(cur_exp));
            else if (cur_type == pair_type)
            {
              p = value(cur_exp);
              if (type(x_part_loc(p)) == known)
                negate(value(x_part_loc(p)));
              else
                negate_dep_list(dep_list(x_part_loc(p)));
              if (type(y_part_loc(p)) == known)
                negate(value(y_part_loc(p)));
              else
                negate_dep_list(dep_list(y_part_loc(p)));
            }
            recycle_value(q);
            free_node(q, value_node_size);
          }
          break;
        case dependent:
        case proto_dependent:
          negate_dep_list(dep_list(cur_exp));
          break;
        case known:
          negate(cur_exp);
          break;
        case picture_type:
          negate_edges(cur_exp);
          break;
        default:
          bad_unary(minus);
          break;
      }
      break;
    case not_op:
      if (cur_type != boolean_type)
        bad_unary(not_op);
      else
        cur_exp = true_code + false_code - cur_exp;
      break;
    case sqrt_op:
    case m_exp_op:
    case m_log_op:
    case sin_d_op:
    case cos_d_op:
    case floor_op:
    case uniform_deviate:
    case odd_op:
    case char_exists_op:
      if (cur_type != known)
        bad_unary(c);
      else switch (c)
      {
        case sqrt_op:
          cur_exp = square_rt(cur_exp);
          break;
        case m_exp_op:
          cur_exp = m_exp(cur_exp);
          break;
        case m_log_op:
          cur_exp = m_log(cur_exp);
          break;
        case sin_d_op:
        case cos_d_op:
          {
            n_sin_cos((cur_exp % three_sixty_units) * 16);
            if (c == sin_d_op)
              cur_exp = round_fraction(n_sin);
            else
              cur_exp = round_fraction(n_cos);
          }
          break;
        case floor_op:
          cur_exp = floor_scaled(cur_exp);
          break;
        case uniform_deviate:
          cur_exp = unif_rand(cur_exp);
          break;
        case odd_op:
          {
            boolean_reset(odd(round_unscaled(cur_exp)));
            cur_type = boolean_type;
          }
          break;
        case char_exists_op:
          {
            cur_exp = round_unscaled(cur_exp) % 256;
            if (cur_exp < 0)
              cur_exp = cur_exp + 256;
            boolean_reset(char_exists[cur_exp]);
            cur_type = boolean_type;
          }
          break;
      }
      break;
    case angle_op:
      if (nice_pair(cur_exp, cur_type))
      {
        p = value(cur_exp);
        x = n_arg(value(x_part_loc(p)), value(y_part_loc(p)));
        if (x >= 0)
          flush_cur_exp((x + 8) / 16);
        else
          flush_cur_exp(-((-x + 8) / 16));
      }
      else
        bad_unary(angle_op);
      break;
    case x_part:
    case y_part:
      if ((cur_type <= pair_type) && (cur_type >= transform_type))
        take_part(c);
      else
        bad_unary(c);
      break;
    case xx_part:
    case xy_part:
    case yx_part:
    case yy_part:
      if (cur_type == transform_type)
        take_part(c);
      else
        bad_unary(c);
      break;
    case char_op:
      if (cur_type != known)
        bad_unary(char_op);
      else
      {
        cur_exp = round_unscaled(cur_exp) % 256;
        cur_type = string_type;
        if (cur_exp < 0)
          cur_exp = cur_exp + 256;
        if (length(cur_exp) != 1)
        {
          str_room(1);
          append_char(cur_exp);
          cur_exp = make_string();
        }
      }
      break;
    case decimal:
      if (cur_type != known)
        bad_unary(decimal);
      else
      {
        old_setting = selector;
        selector = new_string;
        print_scaled(cur_exp);
        cur_exp = make_string();
        selector = old_setting;
        cur_type = string_type;
      }
      break;
    case oct_op:
    case hex_op:
    case ASCII_op:
      if (cur_type != string_type)
        bad_unary(c);
      else
        str_to_num(c);
      break;
    case length_op:
      if (cur_type == string_type)
        flush_cur_exp(length(cur_exp) * unity);
      else if (cur_type == path_type)
        flush_cur_exp(path_length());
      else if (cur_type == known)
        cur_exp = abs(cur_exp);
      else if (nice_pair(cur_exp, cur_type))
        flush_cur_exp(pyth_add(value(x_part_loc(value(cur_exp))), value(y_part_loc(value(cur_exp)))));
      else
        bad_unary(c);
      break;
    case turning_op:
      if (cur_type == pair_type)
        flush_cur_exp(0);
      else if (cur_type != path_type)
        bad_unary(turning_op);
      else if (left_type(cur_exp) == endpoint)
        flush_cur_exp(0);
      else
      {
        cur_pen = null_pen;
        cur_path_type = contour_code;
        cur_exp = make_spec(cur_exp, fraction_one - half_unit - 1 - el_gordo, 0);
        flush_cur_exp(turning_number * unity);
      }
      break;
    case boolean_type:
      type_range(boolean_type, unknown_boolean);
      break;
    case string_type:
      type_range(string_type, unknown_string);
      break;
    case pen_type:
      type_range(pen_type, future_pen);
      break;
    case path_type:
      type_range(path_type, unknown_path);
      break;
    case picture_type:
      type_range(picture_type, unknown_picture);
      break;
    case transform_type:
    case pair_type:
      type_test(c);
      break;
    case numeric_type:
      type_range(known, independent);
      break;
    case known_op:
    case unknown_op:
      test_known(c);
      break;
    case cycle_op:
      {
        if (cur_type != path_type)
          flush_cur_exp(false_code);
        else if (left_type(cur_exp) != endpoint)
          flush_cur_exp(true_code);
        else
          flush_cur_exp(false_code);
        cur_type = boolean_type;
      }
      break;
    case make_pen_op:
      {
        if (cur_type == pair_type)
          pair_to_path();
        if (cur_type == path_type)
          cur_type = future_pen;
        else
          bad_unary(make_pen_op);
      }
      break;
    case make_path_op:
      {
        if (cur_type == future_pen)
          materialize_pen();
        if (cur_type != pen_type)
          bad_unary(make_path_op);
        else
        {
          flush_cur_exp(make_path(cur_exp));
          cur_type = path_type;
        }
      }
      break;
    case total_weight_op:
      if (cur_type != picture_type)
        bad_unary(total_weight_op);
      else
        flush_cur_exp(total_weight(cur_exp));
      break;
    case reverse:
      if (cur_type == path_type)
      {
        p = htap_ypoc(cur_exp);
        if (right_type(p) == endpoint)
          p = link(p);
        toss_knot_list(cur_exp);
        cur_exp = p;
      }
      else if (cur_type == pair_type)
        pair_to_path();
      else
        bad_unary(reverse);
      break;
  }
  check_arith();
}
/* 923 */
void bad_binary (pointer p, quarterword c)
{
  disp_err(p, "");
  disp_err(null, "Not implemented: ");
  if (c >= min_of)
    print_op(c);
  print_known_or_unknown_type(type(p), p);
  if (c >= min_of)
    r_print("of");
  else
    print_op(c);
  print_known_or_unknown_type(cur_type, cur_exp);
  help3("I'm afraid I don't know how to apply that operation to that", 
    "combination of types. Continue, and I'll return the second",
    "argument (see above) as the result of the operation.");
  put_get_error();
}
/* 928 */
pointer tarnished (pointer p)
{
  pointer Result;
  pointer q;
  pointer r;

  q = value(p);
  r = q + big_node_size[type(p)];
  do {
    r = r - 2;
    if (type(r) == independent)
    {
      Result = _void;
      goto l_exit;
    }
  } while (!(r == q));
  Result = null;
l_exit:;
  return Result;
}
/* 935 */
void dep_finish (pointer v, pointer q, small_number t)
{
  pointer p;
  scaled vv;

  if (q == null)
    p = cur_exp;
  else
    p = q;
  dep_list(p) = v;
  type(p) = t;
  if (info(v) == null)
  {
    vv = value(v);
    if (q == null)
      flush_cur_exp(vv);
    else
    {
      recycle_value(p);
      type(q) = known;
      value(q) = vv;
    }
  }
  else if (q == null)
    cur_type = t;
  if (fix_needed)
    fix_dependencies();
}
/* 930 */
void add_or_subtract (pointer p, pointer q, quarterword c)
{
  small_number s, t;
  pointer r;
  integer v;

  if (q == null)
  {
    t = cur_type;
    if (t < dependent)
      v = cur_exp;
    else
      v = dep_list(cur_exp);
  }
  else
  {
    t = type(q);
    if (t < dependent)
      v = value(q);
    else
      v = dep_list(q);
  }
  if (t == known)
  {
    if (c == minus)
      negate(v);
    if (type(p) == known)
    {
      v = slow_add(value(p), v);
      if (q == null)
        cur_exp = v;
      else
        value(q) = v;
      goto l_exit;
    }
    r = dep_list(p);
    while (info(r) != null)
      r = link(r);
    value(r) = slow_add(value(r), v);
    if (q == null)
    {
      q = get_node(value_node_size);
      cur_exp = q;
      cur_type = type(p);
      name_type(q) = capsule;
    }
    dep_list(q) = dep_list(p);
    type(q) = type(p);
    prev_dep(q) = prev_dep(p);
    link(prev_dep(p)) = q;
    type(p) = known;
  }
  else
  {
    if (c == minus)
      negate_dep_list(v);
    if (type(p) == known)
    {
      while (info(v) != null)
        v = link(v);
      value(v) = slow_add(value(p), value(v));
    }
    else
    {
      s = type(p);
      r = dep_list(p);
      if (t == dependent)
      {
        if (s == dependent)
        {
          if (max_coef(r) + max_coef(v) < coef_bound)
          {
            v = p_plus_q(v, r, dependent);
            goto done;
          }
        }
        t = proto_dependent;
        v = p_over_v(v, unity, dependent, proto_dependent);
      }
      if (s == proto_dependent)
        v = p_plus_q(v, r, proto_dependent);
      else
        v = p_plus_fq(v, unity, r, proto_dependent, dependent);
    done:
      if (q != null)
        dep_finish(v, q, t);
      else
      {
        cur_type = t;
        dep_finish(v, null, t);
      }
    }
  }
l_exit:;
}
/* 943 */
void dep_mult (pointer p, integer v, boolean v_is_scaled)
{
  pointer q;
  small_number s, t;

  if (p == null)
    q = cur_exp;
  else if (type(p) != known)
    q = p;
  else
  {
    if (v_is_scaled)
      value(p) = take_scaled(value(p), v);
    else
      value(p) = take_fraction(value(p), v);
    goto l_exit;
  }
  t = type(q);
  q = dep_list(q);
  s = t;
  if (t == dependent)
    if (v_is_scaled)
      if (ab_vs_cd(max_coef(q), abs(v), coef_bound - 1, unity) >= 0)
        t = proto_dependent;
  q = p_times_v(q, v, s, t, v_is_scaled);
  dep_finish(q, p, t);
l_exit:;
}
/* 946 */
void hard_times (pointer p)
{
  pointer q;
  pointer r;
  scaled u, v;

  if (type(p) == pair_type)
  {
    q = stash_cur_exp;
    unstash_cur_exp(p);
    p = q;
  }
  r = value(cur_exp);
  u = value(x_part_loc(r));
  v = value(y_part_loc(r));
  type(y_part_loc(r)) = type(p);
  new_dep(y_part_loc(r), copy_dep_list(dep_list(p)));
  type(x_part_loc(r)) = type(p);
  mem[value_loc(x_part_loc(r))] = mem[value_loc(p)];
  link(prev_dep(p)) = x_part_loc(r);
  free_node(p, value_node_size);
  dep_mult(x_part_loc(r), u, true);
  dep_mult(y_part_loc(r), v, true);
}
/* 949 */
void dep_div (pointer p, scaled v)
{
  pointer q;
  small_number s, t;

  if (p == null)
    q = cur_exp;
  else if (type(p) != known)
    q = p;
  else
  {
    value(p) = make_scaled(value(p), v);
    goto l_exit;
  }
  t = type(q);
  q = dep_list(q);
  s = t;
  if (t == dependent)
    if (ab_vs_cd(max_coef(q), unity, coef_bound - 1, abs(v)) >= 0)
      t = proto_dependent;
  q = p_over_v(q, v, s, t);
  dep_finish(q, p, t);
l_exit:;
}
/* 953 */
void set_up_trans (quarterword c)
{
  pointer p, q, r;

  if ((c != transformed_by) || (cur_type != transform_type))
  {
    p = stash_cur_exp();
    cur_exp = id_transform();
    cur_type = transform_type;
    q = value(cur_exp);
    switch (c)
    {
      case rotated_by:
        if (type(p) == known)
        {
          n_sin_cos((value(p) % three_sixty_units) * 16);
          value(xx_part_loc(q)) = round_fraction(n_cos);
          value(yx_part_loc(q)) = round_fraction(n_sin);
          value(xy_part_loc(q)) = -value(yx_part_loc(q));
          value(yy_part_loc(q)) = value(xx_part_loc(q));
          goto done;
        }
        break;
      case slanted_by:
        if (type(p) > pair_type)
        {
          install(xy_part_loc(q), p);
          goto done;
        }
        break;
      case scaled_by:
        if (type(p) > pair_type)
        {
          install(xx_part_loc(q), p);
          install(yy_part_loc(q), p);
          goto done;
        }
        break;
      case shifted_by:
        if (type(p) == pair_type)
        {
          r = value(p);
          install(x_part_loc(q), x_part_loc(r));
          install(y_part_loc(q), y_part_loc(r));
          goto done;
        }
        break;
      case x_scaled:
        if (type(p) > pair_type)
        {
          install(xx_part_loc(q), p);
          goto done;
        }
        break;
      case y_scaled:
        if (type(p) > pair_type)
        {
          install(yy_part_loc(q), p);
          goto done;
        }
        break;
      case z_scaled:
        if (type(p) == pair_type)
        {
          r = value(p);
          install(xx_part_loc(q), x_part_loc(r));
          install(yy_part_loc(q), x_part_loc(r));
          install(yx_part_loc(q), y_part_loc(r));
          if (type(y_part_loc(r)) == known)
            negate(value(y_part_loc(r)));
          else
            negate_dep_list(dep_list(y_part_loc(r)));
          install(xy_part_loc(q), y_part_loc(r));
          goto done;
        }
        break;
      case transformed_by:
        do_nothing();
        break;
    }
    disp_err(p, "Improper transformation argument");
    help3("The expression shown above has the wrong type,",
      "so I can't transform anything using it.",
      "Proceed, and I'll omit the transformation.");
    put_get_error();
  done:
    recycle_value(p);
    free_node(p, value_node_size);
  }
  q = value(cur_exp);
  r = q + transform_node_size;
  do {
    r = r - 2;
    if (type(r) != known)
      goto l_exit;
  } while (!(r == q));
  txx = value(xx_part_loc(q));
  txy = value(xy_part_loc(q));
  tyx = value(yx_part_loc(q));
  tyy = value(yy_part_loc(q));
  tx = value(x_part_loc(q));
  ty = value(y_part_loc(q));
  flush_cur_exp(0);
l_exit:;
}
/* 960 */
void set_up_known_trans (quarterword c)
{
  set_up_trans(c);
  if (cur_type != known)
  {
    exp_err("Transform components aren't all known");
    help3("I'm unable to apply a partially specified transformation",
      "except to a fully known pair or transform.",
      "Proceed, and I'll omit the transformation.");
    put_get_flush_error(0);
    txx = unity;
    txy = 0;
    tyx = 0;
    tyy = unity;
    tx = 0;
    ty = 0;
  }
}
/* 961 */
void trans (pointer p, pointer q)
{
  scaled v;

  v = take_scaled(mem[p].sc, txx) + take_scaled(mem[q].sc, txy) + tx;
  mem[q].sc = take_scaled(mem[p].sc, tyx) + take_scaled(mem[q].sc, tyy) + ty;
  mem[p].sc = v;
}
/* 962 */
void path_trans (pointer p, quarterword c)
{
  pointer q;

  set_up_known_trans(c);
  unstash_cur_exp(p);
  if (cur_type == pen_type)
  {
    if (max_offset(cur_exp) == 0)
      if (tx == 0)
        if (ty == 0)
          goto l_exit;
    flush_cur_exp(make_path(cur_exp));
    cur_type = future_pen;
  }
  q = cur_exp;
  do {
    if (left_type(q) != endpoint)
      trans(q + 3, q + 4);
    trans(q + 1, q + 2);
    if (right_type(q) != endpoint)
      trans(q + 5, q + 6);
    q = link(q);
  } while (!(q == cur_exp));
l_exit:;
}
/* 963 */
void edges_trans (pointer p, quarterword c)
{
  set_up_known_trans(c);
  unstash_cur_exp(p);
  cur_edges = cur_exp;
  if (empty_edges(cur_edges))
    goto l_exit;
  if (txx == 0)
    if (tyy == 0)
      if (txy % unity == 0)
        if (tyx % unity == 0)
        {
          xy_swap_edges();
          txx = txy;
          tyy = tyx;
          txy = 0;
          tyx = 0;
          if (empty_edges(cur_edges))
            goto l_exit;
        }
  if (txy == 0)
    if (tyx == 0)
      if (txx % unity == 0)
        if (tyy % unity == 0)
        {
          if ((txx == 0) || (tyy == 0))
          {
            toss_edges(cur_edges);
            cur_exp = get_node(edge_header_size);
            init_edges(cur_exp);
          }
          else
          {
            if (txx < 0)
            {
              x_reflect_edges();
              txx = -txx;
            }
            if (tyy < 0)
            {
              yreflect_edges();
              tyy = -tyy;
            }
            if (txx != unity)
              x_scale_edges(txx / unity);
            if (tyy != unity)
              y_scale_edges(tyy / unity);
            tx = round_unscaled(tx);
            ty = round_unscaled(ty);
            if ((m_min(cur_edges) + tx <= 0) || (m_max(cur_edges) + tx >= 8192) || 
              (n_min(cur_edges) + ty <= 0) || (n_max(cur_edges) + ty >= 8191) ||
              (abs(tx) >= 4096) || (abs(ty) >= 4096))
            {
              print_err("Too far to shift");
              help3("I can't shift the picture as requested---it would",
                "make some coordinates too large or too small.",
                "Proceed, and I'll omit the transformation.");
              put_get_error();
            }
            else
            {
              if (tx != 0)
              {
                if (!(valid_range(m_offset(cur_edges) - tx)))
                  fix_offset();
                m_min(cur_edges) = m_min(cur_edges) + tx;
                m_max(cur_edges) = m_max(cur_edges) + tx;
                m_offset(cur_edges) = m_offset(cur_edges) - tx;
                last_window_time(cur_edges) = 0;
              }
              if (ty != 0)
              {
                n_min(cur_edges) = n_min(cur_edges) + ty;
                n_max(cur_edges) = n_max(cur_edges) + ty;
                n_pos(cur_edges) = n_pos(cur_edges) + ty;
                last_window_time(cur_edges) = 0;
              }
            }
          }
          goto l_exit;
        }
  print_err("That transformation is too hard");
  help3("I can apply complicated transformations to paths,",
    "but I can only do integer operations on pictures.",
    "Proceed, and I'll omit the transformation.");
  put_get_error();
l_exit:;
}
/* 968 */
void bilin1 (pointer p, scaled t, pointer q, scaled u, scaled delta)
{
  pointer r;

  if (t != unity)
    dep_mult(p, t, true);
  if (u != 0)
    if (type(q) == known)
      delta = delta + take_scaled(value(q), u);
    else
    {
      if (type(p) != proto_dependent)
      {
        if (type(p) == known)
          new_dep(p, const_dependency(value(p)));
        else
          dep_list(p) = p_times_v(dep_list(p), unity, dependent, proto_dependent, true);
        type(p) = proto_dependent;
      }
      dep_list(p) = p_plus_fq(dep_list(p), u, dep_list(q), proto_dependent, type(q));
    }
  if (type(p) == known)
    value(p) = value(p) + delta;
  else
  {
    r = dep_list(p);
    while (info(r) != null)
      r = link(r);
    delta = value(r) + delta;
    if (r != dep_list(p))
      value(r) = delta;
    else
    {
      recycle_value(p);
      type(p) = known;
      value(p) = delta;
    }
  }
  if (fix_needed)
    fix_dependencies();
}
/* 971 */
void add_mult_dep (pointer p, scaled v, pointer r)
{
  if (type(r) == known)
    value(dep_final) = value(dep_final) + take_scaled(value(r), v);
  else
  {
    dep_list(p) = p_plus_fq(dep_list(p), v, dep_list(r), proto_dependent, type(r));
    if (fix_needed)
      fix_dependencies();
  }
}
/* 972 */
void bilin2 (pointer p, pointer t, scaled v, pointer u, pointer q)
{
  scaled vv;

  vv = value(p);
  type(p) = proto_dependent;
  new_dep(p, const_dependency(0));
  if (vv != 0)
    add_mult_dep(p, vv, t);
  if (v != 0)
    add_mult_dep(p, v, u);
  if (q != 0)
    add_mult_dep(p, unity, q);
  if (dep_list(p) == dep_final)
  {
    vv = value(dep_final);
    recycle_value(p);
    type(p) = known;
    value(p) = vv;
  }
}
/* 974 */
void bilin3 (pointer p, scaled t, scaled v, scaled u, scaled delta)
{
  if (t != unity)
    delta = delta + take_scaled(value(p), t);
  else
    delta = delta + value(p);
  if (u != 0)
    value(p) = delta + take_scaled(v, u);
  else
    value(p) = delta;
}
/* 966 */
void big_trans (pointer p, quarterword c)
{
  pointer q, r, pp, qq;
  small_number s;

  s = big_node_size[type(p)];
  q = value(p);
  r = q + s;
  do {
    r = r - 2;
    if (type(r) != known)
    {
      set_up_known_trans(c);
      make_exp_copy(p);
      r = value(cur_exp);
      if (cur_type == transform_type)
      {
        bilin1(yy_part_loc(r), tyy, xy_part_loc(q), tyx, 0);
        bilin1(yx_part_loc(r), tyy, xx_part_loc(q), tyx, 0);
        bilin1(xy_part_loc(r), txx, yy_part_loc(q), txy, 0);
        bilin1(xx_part_loc(r), txx, yx_part_loc(q), txy, 0);
      }
      bilin1(y_part_loc(r), tyy, x_part_loc(q), tyx, ty);
      bilin1(x_part_loc(r), txx, y_part_loc(q), txy, tx);
      goto l_exit;
    }
  } while (!(r == q));
  set_up_trans(c);
  if (cur_type == known)
  {
    make_exp_copy(p);
    r = value(cur_exp);
    if (cur_type == transform_type)
    {
      bilin3(yy_part_loc(r), tyy, value(xy_part_loc(q)), tyx, 0);
      bilin3(yx_part_loc(r), tyy, value(xx_part_loc(q)), tyx, 0);
      bilin3(xy_part_loc(r), txx, value(yy_part_loc(q)), txy, 0);
      bilin3(xx_part_loc(r), txx, value(yx_part_loc(q)), txy, 0);
    }
    bilin3(y_part_loc(r), tyy, value(x_part_loc(q)), tyx, ty);
    bilin3(x_part_loc(r), txx, value(y_part_loc(q)), txy, tx);
  }
  else
  {
    pp = stash_cur_exp();
    qq = value(pp);
    make_exp_copy(p);
    r = value(cur_exp);
    if (cur_type == transform_type)
    {
      bilin2(yy_part_loc(r), yy_part_loc(qq), value(xy_part_loc(q)), yx_part_loc(qq), null);
      bilin2(yx_part_loc(r), yy_part_loc(qq), value(xx_part_loc(q)), yx_part_loc(qq), null);
      bilin2(xy_part_loc(r), xx_part_loc(qq), value(yy_part_loc(q)), xy_part_loc(qq), null);
      bilin2(xx_part_loc(r), xx_part_loc(qq), value(yx_part_loc(q)), xy_part_loc(qq), null);
    }
    bilin2(y_part_loc(r), yy_part_loc(qq), value(x_part_loc(q)), yx_part_loc(qq), y_part_loc(qq));
    bilin2(x_part_loc(r), xx_part_loc(qq), value(y_part_loc(q)), xy_part_loc(qq), x_part_loc(qq));
    recycle_value(pp);
    free_node(pp, value_node_size);
  }
l_exit:;
}
/* 976 */
void cat (pointer p)
{
  str_number a, b;
  pool_pointer k;

  a = value(p);
  b = cur_exp;
  str_room(length(a) + length(b));
  for (k = str_start[a]; k <= str_start[a + 1] - 1; k++)
    append_char(so(str_pool[k]));
  for (k = str_start[b]; k <= str_start[b + 1] - 1; k++)
    append_char(so(str_pool[k]));
  cur_exp = make_string();
  delete_str_ref(b);
}
/* 977 */
void chop_string (pointer p)
{
  integer a, b;
  integer l;
  integer k;
  str_number s;
  boolean reversed;

  a = round_unscaled(value(x_part_loc(p)));
  b = round_unscaled(value(y_part_loc(p)));
  if (a <= b)
    reversed = false;
  else
  {
    reversed = true;
    k = a;
    a = b;
    b = k;
  }
  s = cur_exp;
  l = length(s);
  if (a < 0)
  {
    a = 0;
    if (b < 0)
      b = 0;
  }
  if (b > l)
  {
    b = l;
    if (a > l)
      a = l;
  }
  str_room(b - a);
  if (reversed)
    for (k = str_start[s] + b - 1; k <= str_start[s] + a; k--)
      append_char(so(str_pool[k]));
  else
    for (k = str_start[s] + a; k <= str_start[s] + b - 1; k++)
      append_char(so(str_pool[k]));
  cur_exp = make_string();
  delete_str_ref(s);
}
/* 978 */
void chop_path (pointer p)
{
  pointer q;
  pointer pp, qq, rr, ss;
  scaled a, b, k, l;
  boolean reversed;

  l = path_length;
  a = value(x_part_loc(p));
  b = value(y_part_loc(p));
  if (a <= b)
    reversed = false;
  else
  {
    reversed = true;
    k = a;
    a = b;
    b = k;
  }
  if (a < 0)
    if (left_type(cur_exp) == endpoint)
    {
      a = 0;
      if (b < 0)
        b = 0;
    }
    else
      do {
        a = a + l;
        b = b + l;
      } while (!(a >= 0));
  if (b > l)
    if (left_type(cur_exp) == endpoint)
    {
      b = l;
      if (a > l)
        a = l;
    }
    else
      while (a >= l)
      {
        a = a - l;
        b = b - l;
      }
  q = cur_exp;
  while (a >= unity)
  {
    q = link(q);
    a = a - unity;
    b = b - unity;
  }
  if (b == a)
  {
    if (a > 0)
    {
      qq = link(q);
      split_cubic(q, a * 010000, x_coord(qq), y_coord(qq));
      q = link(q);
    }
    pp = copy_knot(q);
    qq = pp;
  }
  else
  {
    pp = copy_knot(q);
    qq = pp;
    do {
      q = link(q);
      rr = qq;
      qq = copy_knot(q);
      link(rr) = qq;
      b = b - unity;
    } while (!(b <= 0));
    if (a > 0)
    {
      ss = pp;
      pp = link(pp);
      split_cubic(ss, a * 010000, x_coord(pp), y_coord(pp));
      pp = link(ss);
      free_node(ss, knot_node_size);
      if (rr == ss)
      {
        b = make_scaled(b, unity - a);
        rr = pp;
      }
    }
    if (b < 0)
    {
      split_cubic(rr, (b + unity) * 010000, x_coord(qq), y_coord(qq));
      free_node(qq, knot_node_size);
      qq = link(rr);
    }
  }
  left_type(pp) = endpoint;
  right_type(qq) = endpoint;
  link(qq) = pp;
  toss_knot_list(cur_exp);
  if (reversed)
  {
    cur_exp = link(htap_ypoc(pp));
    toss_knot_list(pp);
  }
  else
    cur_exp = pp;
}
/* 982 */
void pair_value (scaled x, scaled y)
{
  pointer p;

  p = get_node(value_node_size);
  flush_cur_exp(p);
  cur_type = pair_type;
  type(p) = pair_type;
  name_type(p) = capsule;
  init_big_node(p);
  p = value(p);
  type(x_part_loc(p)) = known;
  value(x_part_loc(p)) = x;
  type(y_part_loc(p)) = known;
  value(y_part_loc(p)) = y;
}
/* 984 */
void set_up_offset (pointer p)
{
  find_offset(value(x_part_loc(p)), value(y_part_loc(p)), cur_exp);
  pair_value(cur_x, cur_y);
}
/* 984 */
void set_up_direction_time (pointer p)
{
  flush_cur_exp(find_direction_time(value(x_part_loc(p)), value(y_part_loc(p)), cur_exp));
}
/* 985 */
void find_point (scaled v, quarterword c)
{
  pointer p;
  scaled n;
  pointer q;

  p = cur_exp;
  if (left_type(p) == endpoint)
    n = -unity;
  else
    n = 0;
  do {
    p = link(p);
    n = n + unity;
  } while (!(p == cur_exp));
  if (n == 0)
    v = 0;
  else if (v < 0)
    if (left_type(p) == endpoint)
      v = 0;
    else
      v = n - 1 - ((-v - 1) % n);
  else if (v > n)
    if (left_type(p) == endpoint)
      v = n;
    else
      v = v % n;
  p = cur_exp;
  while (v >= unity)
  {
    p = link(p);
    v = v - unity;
  }
  if (v != 0)
  {
    q = link(p);
    split_cubic(p, v * 010000, x_coord(q), y_coord(q));
    p = link(p);
  }
  switch (c)
  {
    case point_of:
      pair_value(x_coord(p), y_coord(p));
      break;
    case precontrol_of:
      if (left_type(p) == endpoint)
        pair_value(x_coord(p), y_coord(p));
      else
        pair_value(left_x(p), left_y(p));
      break;
    case postcontrol_of:
      if (right_type(p) == endpoint)
        pair_value(x_coord(p), y_coord(p));
      else
        pair_value(right_x(p), right_y(p));
      break;
  }
}
/* 922 */
void do_binary (pointer p, quarterword c)
{
  pointer q, r, rr;
  pointer old_p, old_exp;
  integer v;
 
  check_arith();
  if (internal[tracing_commands] > two)
  {
    begin_diagnostic();
    r_print_nl("{(");
    print_exp(p, 0);
    print_char(')');
    print_op(c);
    print_char('(');
    print_exp(null, 0);
    r_print(")}");
    end_diagnostic(false);
  }
  switch (type(p))
  {
    case transform_type:
    case pair_type:
      old_p = tarnished(p);
      break;
    case independent:
      old_p = _void;
      break;
    default:
      old_p = null;
      break;
  }
  if (old_p != null)
  {
    q = stash_cur_exp();
    old_p = p;
    make_exp_copy(old_p);
    p = stash_cur_exp();
    unstash_cur_exp(q);
  }
  switch (cur_type)
  {
    case transform_type:
    case pair_type:
      old_exp = tarnished(cur_exp);
      break;
    case independent:
      old_exp = _void;
      break;
    default:
      old_exp = null;
      break;
  }
  if (old_exp != null)
  {
    old_exp = cur_exp;
    make_exp_copy(old_exp);
  }
  switch (c)
  {
    case plus:
    case minus:
      if ((cur_type < pair_type) || (type(p) < pair_type))
        if ((cur_type == picture_type) && (type(p) == picture_type))
        {
          if (c == minus)
            negate_edges(cur_exp);
          cur_edges = cur_exp;
          merge_edges(value(p));
        }
        else
          bad_binary(p, c);
      else if (cur_type == pair_type)
        if (type(p) !=  pair_type)
          bad_binary(p, c);
        else
        {
          q = value(p);
          r = value(cur_exp);
          add_or_subtract(x_part_loc(q), x_part_loc(r), c);
          add_or_subtract(y_part_loc(q), y_part_loc(r), c);
        }
      else if (type(p) == pair_type)
        bad_binary(p, c);
      else
        add_or_sub_tract(p, null, c);
      break;
    case less_than:
    case less_or_equal:
    case greater_than:
    case greater_or_equal:
    case equal_to:
    case unequal_to:
      {
        if ((cur_type > pair_type) && (type(p) > pair_type))
          add_or_subtract(p, null, minus);
        else if (cur_type != type(p))
        {
          bad_binary(p, c);
          goto done;
        }
        else if (cur_type == string_type)
          flush_cur_exp(str_vs_str(value(p), cur_exp));
        else if ((cur_type == unknown_string) || (cur_type == unknown_boolean))
        {
          q = value(cur_exp);
          while ((q != cur_exp) && (q != p))
            q = value(q);
          if (q == p)
            flush_cur_exp(0);
        }
        else if ((cur_type == pair_type) || (cur_type == transform_type))
        {
          q = value(p);
          r = value(cur_exp);
          rr = r + big_node_size[cur_type] - 2;
          while (true)
          {
            add_or_subtract(q, r, minus);
            if (type(r) != known)
              goto done1;
            if (value(r) != 0)
              goto done1;
            if (r == rr)
              goto done1;
            q = q + 2;
            r = r + 2;
          }
        done1:
          take_part(x_part + half(r - value(cur_exp)));
        }
        else if (cur_type == boolean_type)
          flush_cur_exp(cur_exp - value(p));
        else
        {
          bad_binary(p, c);
          goto done;
        }
        if (cur_type != known)
        {
          if (cur_type < known)
          {
            disp_err(p, "");
            help1("The quantities shown above have not been equated.");
          }
          else
            help2("Oh dear. I can't decide if the expression above is positive,",
              "negative, or zero. So this comparison test won't be `true'.");
          exp_err("Unknown relation will be considered false");
          put_get_flush_error(false_code);
        }
        else switch (c)
        {
          case less_than:
            boolean_reset(cur_exp < 0);
            break;
          case less_or_equal:
            boolean_reset(cur_exp <= 0);
            break;
          case greater_than:
            boolean_reset(cur_exp > 0);
            break;
          case greater_or_equal:
            boolean_reset(cur_exp >= 0);
            break;
          case equal_to:
            boolean_reset(cur_exp == 0);
            break;
          case unequal_to:
            boolean_reset(cur_exp != 0);
            break;
        }
        cur_type = boolean_type;
      done:;
      }
      break;
    case and_op:
    case or_op:
      if ((type(p) != boolean_type) || (cur_type != boolean_type))
        bad_binary(p, c);
      else if (value(p) == c + false_code - and_op)
        cur_exp = value(p);
      break;
    case times:
      if ((cur_type < pair_type) || (type(p) < pair_type))
        bad_binary(p, times);
      else if ((cur_type == known) || (type(p) == known))
      {
        if (type(p) == known)
        {
          v = value(p);
          free_node(p, value_node_size);
        }
        else
        {
          v = cur_exp;
          unstash_cur_exp(p);
        }
        if (cur_type == known)
          cur_exp = take_scaled(cur_exp, v);
        else if (cur_type == pair_type)
        {
          p = value(cur_exp);
          dep_mult(x_part_loc(p), v, true);
          dep_mult(y_part_loc(p), v, true);
        }
        else
          dep_mult(null, v, true);
        goto l_exit;
      }
      else if ((nice_pair(p, type(p)) && (cur_type > pair_type)) || (nice_pair(cur_exp, cur_type) && (type(p) > pair_type)))
      {
        hard_times(p);
        goto l_exit;
      }
      else
        bad_binary(p, times);
      break;
    case over:
      if ((cur_type != known) || (type(p) < pair_type))
        bad_binary(p, over);
      else
      {
        v = cur_exp;
        unstash_cur_exp(p);
        if (v == 0)
        {
          exp_err("Division by zero");
          help2("You're trying to divide the quantity shown above the error",
            "message by zero. I'm going to divide it by one instead.");
          put_get_error();
        }
        else
        {
          if (cur_type == known)
            cur_exp = make_scaled(cur_exp, v);
          else if (cur_type == pair_type)
          {
            p = value(cur_exp);
            dep_div(x_part_loc(p), v);
            dep_div(y_part_loc(p), v);
          }
          else
            dep_div(null, v);
        }
        goto l_exit;
      }
      break;
    case pythag_add:
    case pythag_sub:
      if ((cur_type == known) && (type(p) == known))
        if (c == pythag_add)
          cur_exp = pyth_add(value(p), cur_exp);
        else
          cur_exp = pyth_sub(value(p), cur_exp);
      else
        bad_binary(p, c);
      break;
    case rotated_by:
    case slanted_by:
    case scaled_by:
    case shifted_by:
    case transformed_by:
    case x_scaled:
    case y_scaled:
    case z_scaled:
      if ((type(p) == path_type) || (type(p) == future_pen) || (type(p) == pen_type))
      {
        path_trans(p, c);
        goto l_exit;
      }
      else if ((type(p) == pair_type) || (type(p) == transform_type))
        big_trans(p, c);
      else if (type(p) == picture_type)
      {
        edges_trans(p, c);
        goto l_exit;
      }
      else
        bad_binary(p, c);
      break;
    case concatenate:
      if ((cur_type == string_type) && (type(p) == string_type))
        cat(p);
      else
        bad_binary(p, concatenate);
      break;
    case substring_of:
      if (nice_pair(p, type(p)) && (cur_type == string_type))
        chop_string(value(p));
      else
        bad_binary(p, substring_of);
      break;
    case subpath_of:
      {
        if (cur_type == pair_type)
          pair_to_path();
        if (nice_pair(p, type(p)) && (cur_type == path_type))
          chop_path(value(p));
        else
          bad_binary(p, subpath_of);
      }
      break;
    case point_of:
    case precontrol_of:
    case postcontrol_of:
      {
        if (cur_type == pair_type)
          pair_to_path();
        if ((cur_type == path_type) && (type(p) == known))
          find_point(value(p), c);
        else
          bad_binary(p, c);
      }
      break;
    case pen_offset_of:
      {
        if (cur_type == future_pen)
          materialize_pen();
        if ((cur_type == pen_type) && nice_pair(p, type(p)))
          set_up_offset(value(p));
        else
          bad_binary(p, pen_offset_of);
      }
      break;
    case direction_time_of:
      {
        if (cur_type == pair_type)
          pair_to_path();
        if ((cur_type == path_type) && nice_pair(p, type(p)))
          set_up_direction_time(value(p));
        else
          bad_binary(p, direction_time_of);
      }
      break;
    case intersect:
      {
        if (type(p) == pair_type)
        {
          q = stash_cur_exp();
          unstash_cur_exp(p);
          pair_to_path();
          p = stash_cur_exp();
          unstash_cur_exp(q);
        }
        if (cur_type == pair_type)
          pair_to_path();
        if ((cur_type == path_type) && (type(p) == path_type))
        {
          path_intersection(value(p), cur_exp);
          pair_value(cur_t, cur_tt);
        }
        else
          bad_binary(p, intersect);
      }
      break;
  }
  recycle_value(p);
  free_node(p, value_node_size);
l_exit:
  check_arith();
  if (old_p != null)
  {
    recycle_value(old_p);
    free_node(old_p, value_node_size);
  }
  if (old_exp != null)
  {
    recycle_value(old_exp);
    free_node(old_exp, value_node_size);
  }
}
/* 944 */
void frac_mult (scaled n, scaled d)
{
  pointer p;
  pointer old_exp;
  fraction v;

  if (internal[tracing_commands] > two)
  {
    begin_diagnostic();
    r_print_nl("{(");
    print_scaled(n);
    print_char('/');
    print_scaled(d);
    r_print(")*(");
    print_exp(null, 0);
    r_print(")}");
    end_diagnostic(false);
  }
  switch (cur_type)
  {
    case transform_type:
    case pair_type:
      old_exp = tarnished(cur_exp);
      break;
    case independent:
      old_exp = _void;
      break;
    default:
      old_exp = null;
      break;
  }
  if (old_exp != null)
  {
    old_exp = cur_exp;
    make_exp_copy(old_exp);
  }
  v = make_fraction(n, d);
  if (cur_type == known)
    cur_exp = take_fraction(cur_exp, v);
  else if (cur_type == pair_type)
  {
    p = value(cur_exp);
    dep_mult(x_part_loc(p), v, false);
    dep_mult(y_part_loc(p), v, false);
  }
  else
    dep_mult(null, v, false);
  if (old_exp != null)
  {
    recycle_value(old_exp);
    free_node(old_exp, value_node_size);
  }
}
/* 1154 */
void write_gf (gf_index a, gf_index b)
{
  gf_index k;

  for (k = a; k <= b; k++)
    write(gf_file, gf_buf[k]);
}
/* 1155 */
void gf_swap (void)
{
  if (gf_limit == gf_buf_size)
  {
    write_gf(0, half_buf - 1);
    gf_limit = half_buf;
    gf_offset = gf_offset + gf_buf_size;
    gf_ptr = 0;
  }
  else
  {
    write_gf(half_buf, gf_buf_size - 1);
    gf_limit = gf_buf_size;
  }
}
/* 1157 */
void gf_four (integer x)
{
  if (x >= 0)
    gf_out(x / three_bytes);
  else
  {
    x = x + 010000000000;
    x = x + 010000000000;
    gf_out((x / three_bytes) + 128);
  }
  x = x % three_bytes;
  gf_out(x / unity);
  x = x % unity;
  gf_out(x / 0400);
  gf_out(x % 0400);
}
/* 1158 */
void gf_two (integer x)
{
  gf_out(x / 0400);
  gf_out(x % 0400);
}
/* 1158 */
void gf_three (integer x)
{
  gf_out(x / unity);
  gf_out((x % unity) / 0400);
  gf_out(x % 0400);
}
/* 1159 */
void gf_paint (integer d)
{
  if (d < 64)
    gf_out(paint_0 + d);
  else if (d < 256)
  {
    gf_out(paint1);
    gf_out(d);
  }
  else
  {
    gf_out(paint1 + 1);
    gf_two(d);
  }
}
/* 1160 */
void gf_string (str_number s, str_number t)
{
  pool_pointer k;
  integer l;

  if (s != 0)
  {
    l = length(s);
    if (t != 0)
      l = l + length(t);
    if (l <= 255)
    {
      gf_out(xxx1);
      gf_out(l);
    }
    else
    {
      gf_out(xxx3);
      gf_three(l);
    }
    for (k = str_start[s]; k <= str_start[s + 1] - 1; k++)
      gf_out(so(str_pool[k]));
  }
  if (t != 0)
    for (k = str_start[t]; k <= str_start[t + 1] - 1; k++)
      gf_out(so(str_pool[k]));
}
/* 1161 */
void gf_boc (integer min_m, integer max_m, integer min_n, integer max_n)
{
  if (min_m < gf_min_m)
    gf_min_m = min_m;
  if (max_n > gf_max_n)
    gf_max_n = max_n;
  if (boc_p == -1)
    if (one_byte(boc_c))
      if (one_byte(max_m - min_m))
        if (one_byte(max_m))
          if (one_byte(max_n - min_n))
            if (one_byte(max_n))
            {
              gf_out(boc1);
              gf_out(boc_c);
              gf_out(max_m - min_m);
              gf_out(max_m);
              gf_out(max_n - min_n);
              gf_out(max_n);
              goto l_exit;
            }  
  gf_out(boc);
  gf_four(boc_c);
  gf_four(boc_p);
  gf_four(min_m);
  gf_four(max_m);
  gf_four(min_n);
  gf_four(max_n);
l_exit:;
}
/* 1163 */
void init_gf (void)
{
  short k;
  integer t;

  gf_min_m = 4096;
  gf_max_m = -4096;
  gf_min_n = 4096;
  gf_max_n = -4096;
  for (k = 0; k <= 255; k++)
    char_ptr[k] = -1;
  if (internal[hppp] <= 0)
    gf_ext = ".gf";
  else
  {
    old_setting = selector;
    selector = new_string;
    print_char('.');
    print_int(make_scaled(internal[hppp], 59429463));
    r_print("gf");
    gf_ext = make_string();
    selector = old_setting;
  }
  set_output_file_name();
  gf_out(pre);
  gf_out(gf_id_byte);
  old_setting = selector;
  selector = new_string;
  r_print(" METAFONT output ");
  print_int(round_unscaled(internal[year]));
  print_char('.');
  print_dd(round_unscaled(internal[month]));
  print_char('.');
  print_dd(round_unscaled(internal[day]));
  print_char(':');
  t = round_unscaled(internal[time]);
  print_dd(t / 60);
  print_dd(t % 60);
  selector = old_setting;
  gf_out(cur_length);
  gf_string(0, make_string());
  decr(str_ptr);
  pool_ptr = str_start[str_ptr];
  gf_prev_ptr = gf_offset + gf_ptr;
}
/* 1165 */
void ship_out (eight_bits c)
{
  integer f;
  integer prev_m, m, mm;
  integer prev_n, n;
  halfword p, q;
  integer prev_w, w, ww;
  integer d;
  integer delta;
  integer cur_min_m;
  integer x_off, y_off;

  check_gf();
  f = round_unscaled(internal[char_ext]);
  x_off = round_unscaled(internal[x_offset]);
  y_off = round_unscaled(internal[y_offset]);
  if (term_offset > max_print_line - 9)
    print_ln();
  else if ((term_offset > 0) || (file_offset > 0))
    print_char(' ');
  print_char('[');
  print_int(c);
  if (f != 0)
  {
    print_char('.');
    print_int(f);
  }
  update_terminal();
  boc_c = 256 * f + c;
  boc_p = char_ptr[c];
  char_ptr[c] = gf_prev_ptr;
  if (internal[proofing] > 0)
  {
    if (x_off != 0)
    {
      gf_string("xoffset", 0);
      gf_out(yyy);
      gf_four(x_off * unity);
    }
    if (y_off != 0)
    {
      gf_string("yoffset", 0);
      gf_out(yyy);
      gf_four(y_off * unity);
    }
  }
  prev_n = 4096;
  p = knil(cur_edges);
  n = n_max(cur_edges) - zero_field;
  while (p != cur_edges)
  {
    if (unsorted(p) > _void)
      sort_edges(p);
    q = sorted(p);
    w = 0;
    prev_m = -fraction_one;
    ww = 0;
    prev_w = 0;
    m = prev_m;
    do {
      if (q == sentinel)
        mm = fraction_one;
      else
      {
        d = ho(info(q));
        mm = d / 8;
        ww = ww + (d % 8) - zero_w;
      }
      if (mm != m)
      {
        if (prev_w <= 0)
        {
          if (w > 0)
          {
            if (prev_m == -fraction_one)
            {
              if (prev_n == 4096)
              {
                gf_boc(m_min(cur_edges) + x_off - zero_field, m_max(cur_edges) + x_off - zero_field,
                  n_min(cur_edges) + y_off - zero_field, n + y_off);
                cur_min_m = m_min(cur_edges) - zero_field + m_offset(cur_edges);
              }
              else if (prev_n > n + 1)
              {
                delta = prev_n - n - 1;
                if (delta < 0400)
                {
                  gf_out(skip1);
                  gf_out(delta);
                }
                else
                {
                  gf_out(skip1 + 1);
                  gf_two(delta);
                }
              }
              else
              {
                delta = m - cur_min_m;
                if (delta > max_new_row)
                  gf_out(skip0);
                else
                {
                  gf_out(new_row_0 + delta);
                  goto done;
                }
              }
              gf_paint(m - cur_min_m);
            done:
              prev_n = n;
            }
            else
              gf_paint(m - prev_m);
            prev_m = m;
            prev_w = w;
          }
        }
        else if (w <= 0)
        {
          gf_paint(m - prev_m);
          prev_m = m;
          prev_w = w;
        }
        m = mm;
      }
      w = ww;
      q = link(q);
    } while (!(mm == fraction_one));
    if (w != 0)
      r_print_nl("(There's unbounded black in character shipped out!)");
    if (prev_m - m_offset(cur_edges) + x_off > gf_max_m)
      gf_max_m = prev_m - m_offset(cur_edges) + x_off;
    p = knil(p);
    decr(n);
  }
  if (prev_n == 4096)
  {
    gf_boc(0, 0, 0, 0);
    if (gf_max_m < 0)
      gf_max_m = 0;
    if (gf_min_n > 0)
      gf_min_n = 0;
  }
  else if (prev_n + y_off < gf_min_n)
    gf_min_n = prev_n + y_off;
  gf_out(eoc);
  gf_prev_ptr = gf_offset + gf_ptr;
  incr(total_chars);
  print_char(']');
  update_terminal();
  if (internal[tracing_output] > 0)
    print_edges(" (just shipped out)", true, x_off, y_off);
}
/* 1006 */
void try_eq (pointer l, pointer r)
{
  pointer p;
  unsigned char t;
  pointer q;
  pointer pp;
  unsigned char tt;
  boolean copied;

  t = type(l);
  if (t == known)
  {
    t = dependent;
    p = const_dependency(-value(l));
    q = p;
  }
  else if (t == independent)
  {
    t = dependent;
    p = single_dependency(l);
    negate(value(p));
    q = dep_final;
  }
  else
  {
    p = dep_list(l);
    q = p;
    while (true)
    {
      negate(value(q));
      if (info(q) == null)
        goto done;
      q = link(q);
    }
  done:
    link(prev_dep(l)) = link(q);
    prev_dep(link(q)) = prev_dep(l);
    type(l) = known;
  }
  if (r == null)
    if (cur_type == known)
    {
      value(q) = value(q) + cur_exp;
      goto done1;
    }
    else
    {
      tt = cur_type;
      if (tt == independent)
        pp = single_dependency(cur_exp);
      else
        pp = dep_list(cur_exp);
    }
  else if (type(r) == known)
  {
    value(q) = value(q) + value(r);
    goto done1;
  }
  else
  {
    tt = type(r);
    if (tt == independent)
      pp = single_dependency(r);
    else
      pp = dep_list(r);
  }
  if (tt != independent)
    copied = false;
  else
  {
    copied = true;
    tt = dependent;
  }
  watch_coefs = false;
  if (t == tt)
    p = p_plus_q(p, pp, t);
  else if (t == proto_dependent)
    p = p_plus_fq(p, unity, pp, proto_dependent, dependent);
  else
  {
    q = p;
    while (info(q) != null)
    {
      value(q) = round_fraction(value(q));
      q = link(q);
    }
    t = proto_dependent;
    p = p_plus_q(p, pp, t);
  }
  watch_coefs = true;
  if (copied)
    flush_node_list(pp);
done1:;
  if (info(p) == null)
  {
    if (abs(value(p)) > 64)
    {
      print_err("Inconsistent equation");
      r_print(" (off by ");
      print_scaled(value(p));
      print_char(')');
      help2("The equation I just read contradicts what was said before.",
        "But don't worry; continue and I'll just ignore it.");
      put_get_error();
    }
    else if (r == null)
    {
      print_err("Redundant equation");
      help2("I already knew that this equation was true.",
        "But perhaps no harm has been done; let's continue.");
      put_get_error();
    }
    free_node(p, dep_node_size);
  }
  else
  {
    linear_eq(p, t);
    if (r == null)
      if (cur_type != known)
        if (type(cur_exp) == known)
        {
          pp = cur_exp;
          cur_exp = value(cur_exp);
          cur_type = known;
          free_node(pp, value_node_size);
        }
  }
}
/* 1001 */
void make_eq (pointer lhs)
{
  small_number t;
  integer v;
  pointer p, q;

l_restart:
  t = type(lhs);
  if (t <= pair_type)
    v = value(lhs);
  switch (t)
  {
    case boolean_type:
    case string_type:
    case pen_type:
    case path_type:
    case picture_type:
      if (cur_type == t + unknown_tag)
      {
        non_linear_eq(v, cur_exp, false);
        unstash_cur_exp(cur_exp);
        goto done;
      }
      else if (cur_type == t)
      {
        if (cur_type <= string_type)
        {
          if (cur_type == string_type)
          {
            if (str_vs_str(v, cur_exp) != 0)
              goto not_found;
          }
          else if (v != cur_exp)
            goto not_found;
          {
            print_err("Redundant equation");
            help2("I already knew that this equation was true.",
              "But perhaps no harm has been done; let's continue.");
            put_get_error();
          }
          goto done;
        }
        print_err("Redundant or inconsistent equation");
        help2("An equation between already-known quantities can't help.",
          "But don't worry; continue and I'll just ignore it.");
        put_get_error();
        goto done;
      not_found:
        print_err("Inconsistent equation");
        help2("The equation I just read contradicts what was said before.",
          "But don't worry; continue and I'll just ignore it.");
        put_get_error();
        goto done;
      }
      break;
    case unknown_types:
      if (cur_type == t - unknown_tag)
      {
        non_linear_eq(cur_exp, lhs, true);
        goto done;
      }
      else if (cur_type == t)
      {
        ring_merge(lhs, cur_exp);
        goto done;
      }
      else if (cur_type == pair_type)
        if (t == unknown_path)
        {
          pair_to_path();
          goto l_restart;
        }
      break;
    case transform_type:
    case pair_type:
      if (cur_type == t)
      {
        p = v + big_node_size[t];
        q = value(cur_exp) + big_node_size[t];
        do {
          p = p - 2;
          q = q - 2;
          try_eq(p, q);
        } while (!(p == v));
        goto done;
      }
      break;
    case known:
    case dependent:
    case proto_dependent:
    case independent:
      if (cur_type >= known)
      {
        try_eq(lhs, null);
        goto done;
      }
      break;
    case vacuous:
      do_nothing();
      break;
  }
  disp_err(lhs, "");
  exp_err("Equation cannot be performed (");
  if (type(lhs) <= pair_type)
    print_type(type(lhs));
  else
    r_print("numeric");
  print_char('=');
  if (cur_type <= pair_type)
    print_type(cur_type);
  else
    r_print("numeric");
  print_char(')');
  help2("I'm sorry, but I don't know how to make such things equal.",
    "(See the two expressions just above the error message.)");
  put_get_error();
done:
  check_arith();
  recycle_value(lhs);
  free_node(lhs, value_node_size);
}
void do_assignment(void);
/* 995 */
void do_equation (void)
{
  pointer lhs;
  pointer p;

  lhs = stash_cur_exp();
  get_x_next();
  var_flag = assignment;
  scan_expression();
  if (cur_cmd == equals)
    do_equation();
  else if (cur_cmd == assignment)
    do_assignment();
  if (internal[tracing_commands] > two)
  {
    begin_diagnostic();
    r_print_nl("{(");
    print_exp(lhs, 0);
    r_print(")=(");
    print_exp(null, 0);
    r_print(")}");
    end_diagnostic(false);
  }
  if (cur_type == unknown_path)
    if (type(lhs) == pair_type)
    {
      p = stash_cur_exp();
      unstash_cur_exp(lhs);
      lhs = p;
    }
  make_eq(lhs);
}
/* 996 */
void do_assignment (void)
{
  pointer lhs;
  pointer p;
  pointer q;

  if (cur_type != token_list)
  {
    exp_err("Improper `:=' will be changed to `='");
    help2("I didn't find a variable name at the left of the `:=',",
      "so I'm going to pretend that you said `=' instead.");
    error();
    do_equation();
  }
  else
  {
    lhs = cur_exp;
    cur_type = vacuous;
    get_x_next();
    var_flag = assignment;
    scan_expression();
    if (cur_cmd == equals)
      do_equation();
    else if (cur_cmd == assignment)
      do_assignment();
    if (internal[tracing_commands] > two)
    {
      begin_diagnostic();
      r_print_nl("{");
      if (info(lhs) > hash_end)
        slow_print(int_name[info(lhs) - (hash_end)]);
      else
        show_token_list(lhs, null, 1000, 0);
      r_print(":=");
      print_exp(null, 0);
      print_char('}');
      end_diagnostic(false);
    }
    if (info(lhs) > hash_end)
      if (cur_type == known)
        internal[info(lhs) - (hash_end)] = cur_exp;
      else
      {
        exp_err("Internal quantity `");
        slow_print(int_name[info(lhs) - (hash_end)]);
        r_print("' must receive a known value");
        help2("I can't set an internal quantity to anything but a known",
          "numeric value, so I'll have to ignore this assignment.");
        put_get_error();
      }
    else
    {
      p = find_variable(lhs);
      if (p != null)
      {
        q = stash_cur_exp();
        cur_type = und_type(p);
        recycle_value(p);
        type(p) = cur_type;
        value(p) = null;
        make_exp_copy(p);
        p = stash_cur_exp();
        unstash_cur_exp(q);
        make_eq(p);
      }
      else
      {
        obliterated(lhs);
        put_get_error();
      }
    }
    flush_node_list(lhs);
  }
}
/* 1015 */
void do_type_declaration (void)
{
  small_number t;
  pointer p;
  pointer q;

  if (cur_mod >= transform_type)
    t = cur_mod;
  else
    t = cur_mod + unknown_tag;
  do {
    p = scan_declared_variable();
    flush_variable(equiv(info(p)), link(p), false);
    q = find_variable(p);
    if (q != null)
    {
      type(q) = t;
      value(q) = null;
    }
    else
    {
      print_err("Declared variable conflicts with previous vardef");
      help2("You can't use, e.g., `numeric foo[]' after `vardef foo'.",
        "Proceed, and I'll ignore the illegal redeclaration.");
      put_get_error();
    }
    flush_list(p);
    if (cur_cmd < comma)
    {
      print_err("Illegal suffix of declared variable will be flushed");
      help5("Variables in declarations must consist entirely of",
        "names and collective subscripts, e.g., `x[]a'.",
        "Are you trying to use a reserved word in a variable name?",
        "I'm going to discard the junk I found here,",
        "up to the next comma or the end of the declaration.");
      if (cur_cmd == numeric_token)
        help_line[2] = "Explicit subscripts like `x15a' aren't permitted.";
      put_get_error();
      scanner_status = flushing;
      do {
        get_next();
        if (cur_cmd == string_token)
          delete_str_ref(cur_mod);
      } while (!(cur_cmd >= comma));
      scanner_status = normal;
    }
  } while (!(cur_cmd > comma));
}
/* 1021 */
void do_random_seed (void)
{
  get_x_next();
  if (cur_cmd != assignment)
  {
    missing_err(":=");
    help1("Always say `randomseed:=<numeric expression>'.");
    back_error();
  }
  get_x_next();
  scan_expression();
  if (cur_type != known)
  {
    exp_err("Unknown value will be ignored");
    help2("Your expression was too random for me to handle,",
      "so I won't change the random seed just now.");
    put_get_flush_error(0);
  }
  else
  {
    init_randoms(cur_exp);
    if (selector >= log_only)
    {
      old_setting = selector;
      selector = log_only;
      r_print_nl("{randomseed:=");
      print_scaled(cur_exp);
      print_char('}');
      r_print_nl("");
      selector = old_setting;
    }
  }
}
/* 1029 */
void do_protection (void)
{
  unsigned char m;
  halfword t;

  m = cur_mod;
  do {
    get_symbol();
    t = eq_type(cur_sym);
    if (m == 0)
    {
      if (t >= outer_tag)
        eq_type(cur_sym) = t - outer_tag;
    }
    else if (t < outer_tag)
      eq_type(cur_sym) = t + outer_tag;
    get_x_next();
  } while (!(cur_cmd != comma));
}
/* 1031 */
void def_delims (void)
{
  pointer l_delim, r_delim;

  get_clear_symbol();
  l_delim = cur_sym;
  get_clear_symbol();
  r_delim = cur_sym;
  eq_type(l_delim) = left_delimiter;
  equiv(l_delim) = r_delim;
  eq_type(r_delim) = right_delimiter;
  equiv(r_delim) = l_delim;
  get_x_next();
}
void do_statement(void);
/* 1034 */
void do_interim (void)
{
  get_x_next();
  if (cur_cmd != internal_quantity)
  {
    print_err("The token `");
    if (cur_sym == 0)
      r_print("(%CAPSULE)");
    else
      slow_print(text(cur_sym));
    r_print("' isn't an internal quantity");
    help1("Something like `tracingonline' should follow `interim'.");
    back_error();
  }
  else
  {
    save_internal(cur_mod);
    back_input();
  }
  do_statement();
}
/* 1035 */
void do_let (void)
{
  pointer l;

  get_symbol();
  l = cur_sym;
  get_x_next();
  if (cur_cmd != equals)
    if (cur_cmd != assignment)
    {
      missing_err("=");
      help3("You should have said `let symbol = something'.",
        "But don't worry; I'll pretend that an equals sign",
        "was present. The next token I read will be `something'.");
      back_error();
    }
  get_symbol();
  switch (cur_cmd)
  {
    case defined_macro:
    case secondary_primary_macro:
    case tertiary_secondary_macro:
    case expression_tertiary_macro:
      add_mac_ref(cur_mod);
      break;
    default:
      do_nothing();
      break;
  }
  clear_symbol(l, false);
  eq_type(l) = cur_cmd;
  if (cur_cmd == tag_token)
    equiv(l) = null;
  else
    equiv(l) = cur_mod;
  get_x_next();
}
/* 1036 */
void do_new_internal (void)
{
  do {
    if (int_ptr == max_internal)
      overflow("number of internals", max_internal);
    get_clear_symbol();
    incr(int_ptr);
    eq_type(cur_sym) = internal_quantity;
    equiv(cur_sym) = int_ptr;
    int_name[int_ptr] = text(cur_sym);
    internal[int_ptr] = 0;
    get_x_next();
  } while (!(cur_cmd != comma));
}
/* 1040 */
void do_show (void)
{
  do {
    get_x_next();
    scan_expression();
    r_print_nl(">> ");
    print_exp(null, 2);
    flush_cur_exp(0);
  } while (!(cur_cmd != comma));
}
/* 1041 */
void disp_token (void)
{
  r_print_nl("> ");
  if (cur_sym == 0)
  {
    if (cur_cmd == numeric_token)
      print_scaled(cur_mod);
    else if (cur_cmd == capsule_token)
    {
      g_pointer = cur_mod;
      print_capsule();
    }
    else
    {
      print_char('"');
      slow_print(cur_mod);
      print_char('"');
      delete_str_ref(cur_mod);
    }
  }
  else
  {
    slow_print(text(cur_sym));
    print_char('=');
    if (eq_type(cur_sym) >= outer_tag)
      r_print("(outer) ");
    print_cmd_mod(cur_cmd, cur_mod);
    if (cur_cmd == defined_macro)
    {
      print_ln();
      show_macro(cur_mod, null, 100000);
    }
  }
}
/* 1044 */
void do_show_token (void)
{
  do {
    get_next();
    disp_token();
    get_x_next();
  } while (!(cur_cmd != comma));
}
/* 1045 */
void do_show_stats (void)
{
  r_print_nl("Memory usage ");
#ifdef STAT
  print_int(var_used);
  print_char('&');
  print_int(dyn_used);
  if (false)
#endif
  r_print("unknown");
  r_print(" (");
  print_int(hi_mem_min - lo_mem_max - 1);
  r_print(" still untouched)");
  print_ln();
  r_print_nl("String usage ");
  print_int(str_ptr - init_str_ptr);
  print_char('&');
  print_int(pool_ptr - init_pool_ptr);
  r_print(" (");
  print_int(max_strings - max_str_ptr);
  print_char('&');
  print_int(pool_size - max_pool_ptr);
  r_print(" still untouched)");
  print_ln();
  get_x_next();
}
/* 1046 */
void disp_var (pointer p)
{
  pointer q;
  integer n;

  if (type(p) == structured)
  {
    q = attr_head(p);
    do {
      disp_var(q);
      q = link(q);
    } while (!(q == end_attr));
    q = subscr_head(p);
    while (name_type(q) == subscr)
    {
      disp_var(q);
      q = link(q);
    }
  }
  else if (type(p) >= unsuffixed_macro)
  {
    r_print_nl("");
    print_variable_name(p);
    if (type(p) > unsuffixed_macro)
      r_print("@#");
    r_print("=macro:");
    if (file_offset >= max_print_line - 20)
      n = 5;
    else
      n = max_print_line - file_offset - 15;
    show_macro(value(p), null, n);
  }
  else if (type(p) != undefined)
  {
    r_print_nl("");
    print_variable_name(p);
    print_char('=');
    print_exp(p, 0);
  }
}
/* 1049 */
void do_show_var (void)
{
  do {
    get_next();
    if (cur_sym > 0)
      if (cur_sym <= hash_end)
        if (cur_cmd == tag_token)
        
          if (cur_mod != null)
          {
            disp_var(cur_mod);
            goto done;
          }
    disp_token();
  done:
    get_x_next();
  } while (!(cur_cmd != comma));
}
/* 1050 */
void do_show_dependencies (void)
{
  pointer p;

  p = link(dep_head);
  while (p != dep_head)
  {
    if (interesting(p))
    {
      r_print_nl("");
      print_variable_name(p);
      if (type(p) == dependent)
        print_char('=');
      else
        r_print(" = ");
      print_dependency(dep_list(p), type(p));
    }
    p = dep_list(p);
    while (info(p) != null)
      p = link(p);
    p = link(p);
  }
  get_x_next();
}
/* 1051 */
void do_show_whatever (void)
{
  if (interaction == error_stop_mode)
    wake_up_terminal();
  switch (cur_mod)
  {
    case show_token_code:
      do_show_token();
      break;
    case show_stats_code:
      do_show_stats();
      break;
    case show_code:
      do_show();
      break;
    case show_var_code:
      do_show_var();
      break;
    case show_dependencies_code:
      do_show_dependencies();
      break;
  }
  if (internal[showstopping] > 0)
  {
    print_err("OK");
    if (interaction < error_stop_mode)
    {
      help0();
      decr(error_count);
    }
    else
      help1("This isn't an error message; I'm just showing something.");
    if (cur_cmd == semicolon)
      error();
    else
      put_get_error();
  }
}
/* 1054 */
boolean scan_with (void)
{
  small_number t;
  boolean result;

  t = cur_mod;
  cur_type = vacuous;
  get_x_next();
  scan_expression();
  result = false;
  if (cur_type != t)
  {
    exp_err("Improper type");
    help2("Next time say `withweight <known numeric expression>';",
      "I'll ignore the bad `with' clause and look for another.");
    if (t == pen_type)
      help_line[1] = "Next time say `withpen <known pen expression>';";
    put_get_flush_error(0);
  }
  else if (cur_type == pen_type)
    result = true;
  else
  {
    cur_exp = round_unscaled(cur_exp);
    if ((abs(cur_exp) < 4) && (cur_exp != 0))
      result = true;
    else
    {
      print_err("Weight must be -3, -2, -1, +1, +2, or +3");
      help1("I'll ignore the bad `with' clause and look for another.");
      put_get_flush_error(0);
    }
  }
  return result;
}
/* 1057 */
void find_edges_var (pointer t)
{
  pointer p;

  p = find_variable(t);
  cur_edges = null;
  if (p == null)
  {
    obliterated(t);
    put_get_error();
  }
  else if (type(p) != picture_type)
  {
    print_err("Variable ");
    show_token_list(t, null, 1000, 0);
    r_print(" is the wrong type (");
    print_type(type(p));
    print_char(')');
    help2("I was looking for a \"known\" picture variable.",
      "So I'll not change anything just now.");
    put_get_error();
  }
  else
    cur_edges = value(p);
  flush_node_list(t);
}
/* 1059 */
void do_add_to (void)
{
  pointer lhs, rhs;
  integer w;
  pointer p;
  pointer q;
  unsigned char add_to_type;

  get_x_next();
  var_flag = thing_to_add;
  scan_primary();
  if (cur_type != token_list)
  {
    exp_err("Not a suitable variable");
    help4("At this point I needed to see the name of a picture variable.",
      "(Or perhaps you have indeed presented me with one; I might",
      "have missed it, if it wasn't followed by the proper token.)", 
      "So I'll not change anything just now.");
    put_get_flush_error(0);
  }
  else
  {
    lhs = cur_exp;
    add_to_type = cur_mod;
    cur_type = vacuous;
    get_x_next();
    scan_expression();
    if (add_to_type == also_code)
    {
      find_edges_var(lhs);
      if (cur_edges == null)
        flush_cur_exp(0);
      else if (cur_type != picture_type)
      {
        exp_err("Improper `addto'");
        help2("This expression should have specified a known picture.",
          "So I'll not change anything just now.");
        put_get_flush_error(0);
      }
      else
      {
        merge_edges(cur_exp);
        flush_cur_exp(0);
      }
    }
    else
    {
      if (cur_type == pair_type)
        pair_to_path();
      if (cur_type != path_type)
      {
        exp_err("Improper `addto'");
        help2("This expression should have been a known path.", 
          "So I'll not change anything just now.");
        put_get_flush_error(0);
        flush_token_list(lhs);
      }
      else
      {
        rhs = cur_exp;
        w = 1;
        cur_pen = null_pen;
        while (cur_cmd == with_option)
          if (scan_with())
            if (cur_type == known)
              w = cur_exp;
            else
            {
              delete_pen_ref(cur_pen);
              cur_pen = cur_exp;
            }
        find_edges_var(lhs);
        if (cur_edges == null)
          toss_knot_list(rhs);
        else
        {
          lhs = null;
          cur_path_type = add_to_type;
          if (left_type(rhs) == endpoint)
            if (cur_path_type == double_path_code)
              if (link(rhs) == rhs)
              {
                right_x(rhs) = x_coord(rhs);
                right_y(rhs) = y_coord(rhs);
                left_x(rhs) = x_coord(rhs);
                left_y(rhs) = y_coord(rhs);
                left_type(rhs) = explicit;
                right_type(rhs) = explicit;
              }
              else
              {
                p = htap_ypoc(rhs);
                q = link(p);
                right_x(path_tail) = right_x(q);
                right_y(path_tail) = right_y(q);
                right_type(path_tail) = right_type(q);
                link(path_tail) = link(q);
                free_node(q, knot_node_size);
                right_x(p) = right_x(rhs);
                right_y(p) = right_y(rhs);
                right_type(p) = right_type(rhs);
                link(p) = link(rhs);
                free_node(rhs, knot_node_size);
                rhs = p;
              }
            else
            {
              print_err("Not a cycle");
              help2("That contour should have ended with `..cycle' or `&cycle'.",
                "So I'll not change anything just now.");
              put_get_error();
              toss_knot_list(rhs);
              goto not_found;
            }
          else if (cur_path_type == double_path_code)
            lhs = htap_ypoc(rhs);
          cur_wt = w;
          rhs = make_spec(rhs, max_offset(cur_pen), internal[tracing_specs]);
          if (turning_number <= 0)
            if (cur_path_type != double_path_code)
              if (internal[turning_check] > 0)
                if ((turning_number < 0) && (link(cur_pen) == null))
                  negate(cur_wt);
                else
                {
                  if (turning_number == 0)
                    if ((internal[turning_check] <= unity) && (link(cur_pen) == null))
                      goto done;
                    else
                      print_strange("Strange path (turning number is zero)");
                  else
                    print_strange("Backwards path (turning number is negative)");
                  help3("The path doesn't have a counterclockwise orientation,",
                    "so I'll probably have trouble drawing it.",
                    "(See Chapter 27 of The METAFONTbook for more help.)");
                  put_get_error();
                }
          done:;
          if (max_offset(cur_pen) == 0)
            fill_spec(rhs);
          else
            fill_envelope(rhs);
          if (lhs != null)
          {
            rev_turns = true;
            lhs = make_spec(lhs, max_offset(cur_pen), internal[tracing_specs]);
            rev_turns = false;
            if (max_offset(cur_pen) == 0)
              fill_spec(lhs);
            else
              fill_envelope(lhs);
          }
        not_found:;
        }
        delete_pen_ref(cur_pen);
      }
    }
  }
}
/* 1098 */
scaled tfm_check (small_number m)
{
  if (abs(internal[m]) >= fraction_half)
  {
    print_err("Enormous ");
    print(int_name[m]);
    r_print(" has been reduced");
    help1("Font metric dimensions must be less than 2048pt.");
    put_get_error();
    if (internal[m] > 0)
      return fraction_half - 1;
    else
      return 1 - fraction_half;
  }
  else
    return internal[m];
}
/* 1070 */
void do_ship_out (void)
{
  integer c;

  get_x_next();
  var_flag = semicolon;
  scan_expression();
  if (cur_type != token_list)
    if (cur_type == picture_type)
      cur_edges = cur_exp;
    else
    {
      {
        exp_err("Not a suitable variable");
        help4("At this point I needed to see the name of a picture variable.",
          "(Or perhaps you have indeed presented me with one; I might",
          "have missed it, if it wasn't followed by the proper token.)", 
          "So I'll not change anything just now.");
        put_get_flush_error(0);
      }
      goto l_exit;
    }
  else
  {
    find_edges_var(cur_exp);
    cur_type = vacuous;
  }
  if (cur_edges != null)
  {
    c = round_unscaled(internal[char_code]) % 256;
    if (c < 0)
      c = c + 256;
    if (c < bc)
      bc = c;
    if (c > ec)
      ec = c;
    char_exists[c] = true;
    gf_dx[c] = internal[char_dx];
    gf_dy[c] = internal[char_dy];
    tfm_width[c] = tfm_check(char_wd);
    tfm_height[c] = tfm_check(char_ht);
    tfm_depth[c] = tfm_check(char_dp);
    tfm_ital_corr[c] = tfm_check(char_ic);
    if (internal[proofing] >= 0)
      ship_out(c);
  }
  flush_cur_exp(0);
l_exit:;
}
/* 1071 */
void do_display (void)
{
  pointer e;

  get_x_next();
  var_flag = in_window;
  scan_primary();
  if (cur_type != token_list)
  {
    exp_err("Not a suitable variable");
    help4("At this point I needed to see the name of a picture variable.",
      "(Or perhaps you have indeed presented me with one; I might",
      "have missed it, if it wasn't followed by the proper token.)",
      "So I'll not change anything just now.");
    put_get_flush_error(0);
  }
  else
  {
    e = cur_exp;
    cur_type = vacuous;
    get_x_next();
    scan_expression();
    if (cur_type != known)
      goto common_ending;
    cur_exp = round_unscaled(cur_exp);
    if (cur_exp < 0)
      goto not_found;
    if (cur_exp > 15)
      goto not_found;
    if (!window_open[cur_exp])
      goto not_found;
    find_edges_var(e);
    if (cur_edges != null)
      disp_edges(cur_exp);
    goto l_exit;
  not_found:
    cur_exp = cur_exp * unity;
  common_ending:
    disp_err(null, "Bad window number");
    help1("It should be the number of an open window.");
    put_get_flush_error(0);
    flush_token_list(e);
  }
l_exit:;
}
/* 1072 */
boolean get_pair (command_code c)
{
  pointer p;
  boolean b;

  if (cur_cmd != c)
    return false;
  else
  {
    get_x_next();
    scan_expression();
    if (nice_pair(cur_exp, cur_type))
    {
      p = value(cur_exp);
      cur_x = value(x_part_loc(p));
      cur_y = value(y_part_loc(p));
      b = true;
    }
    else
      b = false;
    flush_cur_exp(0);
    return b;
  }
}
/* 1073 */
void do_open_window (void)
{
  integer k;
  scaled r0, c0, r1, c1;

  get_x_next();
  scan_expression();
  if (cur_type != known)
    goto not_found;
  k = round_unscaled(cur_exp);
  if (k < 0)
    goto not_found;
  if (k > 15)
    goto not_found;
  if (!get_pair(from_token))
    goto not_found;
  r0 = cur_x;
  c0 = cur_y;
  if (!get_pair(to_token))
    goto not_found;
  r1 = cur_x;
  c1 = cur_y;
  if (!get_pair(at_token))
    goto not_found;
  open_a_window(k, r0, c0, r1, c1, cur_x, cur_y);
  goto l_exit;
not_found:
  print_err("Improper `openwindow'");
  help2("Say `openwindow k from (r0,c0) to (r1,c1) at (x,y)',",
    "where all quantities are known and k is between 0 and 15.");
  put_get_error();
l_exit:;
}
/* 1074 */
void do_cull (void)
{
  pointer e;
  unsigned char keeping;
  integer w, w_in, w_out;

  w = 1;
  get_x_next();
  var_flag = cull_op;
  scan_primary();
  if (cur_type != token_list)
  {
    exp_err("Not a suitable variable");
    help4("At this point I needed to see the name of a picture variable.",
      "(Or perhaps you have indeed presented me with one; I might",
      "have missed it, if it wasn't followed by the proper token.)",
      "So I'll not change anything just now.");
    put_get_flush_error(0);
  }
  else
  {
    e = cur_exp;
    cur_type = vacuous;
    keeping = cur_mod;
    if (!get_pair (cull_op))
      goto not_found;
    while ((cur_cmd == with_option) && (cur_mod == known))
      if (scan_with())
        w = cur_exp;
    if (cur_x > cur_y)
      goto not_found;
    if (keeping == drop_code)
    {
      if ((cur_x > 0) || (cur_y < 0))
        goto not_found;
      w_out = w;
      w_in = 0;
    }
    else
    {
      if ((cur_x <= 0) && (cur_y >= 0))
        goto not_found;
      w_out = 0;
      w_in = w;
    }
    find_edges_var(e);
    if (cur_edges != null)
      cull_edges(floor_unscaled(cur_x + unity - 1), floor_unscaled(cur_y), w_out, w_in);
    goto l_exit;
  not_found:
    print_err("Bad culling amounts");
    help1("Always cull by known amounts that exclude 0.");
    put_get_error();
    flush_token_list(e);
  }
l_exit:;
}
/* 1082 */
void do_message (void)
{
  unsigned char m;

  m = cur_mod;
  get_x_next();
  scan_expression();
  if (cur_type != string_type)
  {
    disp_err(null, "Not a string");
    help1("A message should be a known string expression.");
    put_get_error();
  }
  else
    switch (m)
    {
      case message_code:
        {
          r_print_nl("");
          slow_print(cur_exp);
        }
        break;
      case err_message_code:
        {
          print_err("");
          slow_print(cur_exp);
          if (err_help != 0)
            use_err_help = true;
          else if (long_help_seen)
            help1("(That was another `errmessage'.)");
          else
          {
            if (interaction < error_stop_mode)
              long_help_seen = true;
            help4("This error message was generated by an `errmessage'",
              "command, so I can't give any explicit help.",
              "Pretend that you're Miss Marple: Examine all clues,",
              "and deduce the truth by inspired guesses.");
          }
          put_get_error();
          use_err_help = false;
        }
        break;
      case err_help_code:
        {
          if (err_help != 0)
            delete_str_ref(err_help);
          if (length(cur_exp) == 0)
            err_help = 0;
          else
          {
            err_help = cur_exp;
            add_str_ref(err_help);
          }
        }
        break;
    }
  flush_cur_exp(0);
}
/* 1103 */
eight_bits get_code (void)
{
  integer c;

  get_x_next();
  scan_expression();
  if (cur_type == known)
  {
    c = round_unscaled(cur_exp);
    if (c >= 0)
      if (c < 256)
        goto found;
  }
  else if (cur_type == string_type)
    if (length(cur_exp) == 1)
    {
      c = str_pool[str_start[cur_exp]];
      goto found;
    }
  exp_err("Invalid code has been replaced by 0");
  help2("I was looking for a number between 0 and 255, or for a",
    "string of length 1. Didn't find it; will use 0 instead.");
  put_get_flush_error(0);
  c = 0;
found:
  return c;
}
/* 1104 */
void set_tag (halfword c, small_number t, halfword r)
{
  if (char_tag[c] == no_tag)
  {
    char_tag[c] = t;
    char_remainder[c] = r;
    if (t == lig_tag)
    {
      incr(label_ptr);
      label_loc[label_ptr] = r;
      label_char[label_ptr] = c;
    }
  }
  else
  {
    print_err("Character ");
    if ((c > ' ') && (c < 127))
      print(c);
    else if (c == 256)
      r_print("||");
    else
    {
      r_print("code ");
      print_int(c);
    }
    r_print(" is already ");
    switch (char_tag[c])
    {
      case lig_tag:
        r_print("in a ligtable");
        break;
      case list_tag:
        r_print("in a charlist");
        break;
      case ext_tag:
        r_print("extensible");
        break;
    }
    help2("It's not legal to label a character more than once.",
      "So I'll not change anything just now.");
    put_get_error();
  }
}
/* 1106 */
void do_tfm_command (void)
{
  short c, cc;
  integer k;
  integer j;

  switch (cur_mod)
  {
    case char_list_code:
      {
        c = get_code();
        while (cur_cmd == colon)
        {
          cc = get_code();
          set_tag(c, list_tag, cc);
          c = cc;
        }
      }
      break;
    case lig_table_code:
      {
        lk_started = false;
      l_continue:
        get_x_next();
        if ((cur_cmd == skip_to) && lk_started)
        {
          c = get_code();
          if (nl - skip_table[c] > 128)
          {
            skip_error(skip_table[c]);
            skip_table[c] = undefined_label;
          }
          if (skip_table[c] == undefined_label)
            skip_byte(nl - 1) = qi(0);
          else
            skip_byte(nl - 1) = qi(nl - skip_table[c] - 1);
          skip_table[c] = nl - 1;
          goto done;
        }
        if (cur_cmd == bchar_label)
        {
          c = 256;
          cur_cmd = colon;
        }
        else
        {
          back_input();
          c = get_code();
        }
        if ((cur_cmd == colon) || (cur_cmd == double_colon))
        {
          if (cur_cmd == colon)
          {
            if (c == 256)
              bch_label = nl;
            else
              set_tag(c, lig_tag, nl);
          }
          else if (skip_table[c] < undefined_label)
          {
            ll = skip_table[c];
            skip_table[c] = undefined_label;
            do {
              lll = qo(skip_byte(ll));
              if (nl - ll > 128)
              {
                skip_error(ll);
                goto l_continue;
              }
              skip_byte(ll) = qi(nl - ll - 1);
              ll = ll - lll;
            } while (!(lll == 0));
          }
          goto l_continue;
        }
        if (cur_cmd == lig_kern_token)
        {
          next_char(nl) = qi(c);
          skip_byte(nl) = qi(0);
          if (cur_mod < 128)
          {
            op_byte(nl) = qi(cur_mod);
            rem_byte(nl) = qi(get_code());
          }
          else
          {
            get_x_next();
            scan_expression();
            if (cur_type != known)
            {
              exp_err("Improper kern");
              help2("The amount of kern should be a known numeric value.",
                "I'm zeroing this one. Proceed, with fingers crossed.");
              put_get_flush_error(0);
            }
            kern[nk] = cur_exp;
            k = 0;
            while (kern[k]!= cur_exp)
              incr(k);
            if (k == nk)
            {
              if (nk == max_kerns)
                overflow("kern", max_kerns);
              incr(nk);
            }
            op_byte(nl) = kern_flag + (k / 256);
            rem_byte(nl) = qi((k % 256));
          }
          lk_started = true;
        }
        else
        {
          print_err("Illegal ligtable step");
          help1("I was looking for `=:' or `kern' here.");
          back_error();
          next_char(nl) = qi(0);
          op_byte(nl) = qi(0);
          rem_byte(nl) = qi(0);
          skip_byte(nl) = stop_flag + 1;
        }
        if (nl == lig_table_size)
          overflow("ligtable size", lig_table_size);
        incr(nl);
        if (cur_cmd == comma)
          goto l_continue;
        if (skip_byte(nl - 1) < stop_flag)
          skip_byte(nl - 1) = stop_flag;
      done:;
      }
      break;
    case extensible_code:
      {
        if (ne == 256)
          overflow("extensible", 256);
        c = get_code();
        set_tag(c, ext_tag, ne);
        if (cur_cmd != colon)
          missing_extensible_punctuation(":");
        ext_top(ne) = qi(get_code());
        if (cur_cmd != comma)
          missing_extensible_punctuation(",");
        ext_mid(ne) = qi(get_code());
        if (cur_cmd != comma)
          missing_extensible_punctuation(",");
        ext_bot(ne) = qi(get_code());
        if (cur_cmd != comma)
          missing_extensible_punctuation(",");
        ext_rep(ne) = qi(get_code());
        incr(ne);
      }
      break;
    case header_byte_code:
    case font_dimen_code:
      {
        c = cur_mod;
        get_x_next();
        scan_expression();
        if ((cur_type != known) || (cur_exp < half_unit))
        {
          exp_err("Improper location");
          help2("I was looking for a known, positive number.",
            "For safety's sake I'll ignore the present command.");
          put_get_error();
        }
        else
        {
          j = round_unscaled(cur_exp);
          if (cur_cmd != colon)
          {
            missing_err(":");
            help1("A colon should follow a headerbyte or fontinfo location.");
            back_error();
          }
          if (c == header_byte_code)
            do {
              if (j > header_size)
                overflow("headerbyte", header_size);
              header_byte[j] = get_code();
              incr(j);
            } while (!(cur_cmd != comma));
          else
            do {
              if (j > max_font_dimen)
                overflow("fontdimen", max_font_dimen);
              while (j > np)
              {
                incr(np);
                param[np] = 0;
              }
              get_x_next();
              scan_expression();
              if (cur_type != known)
              {
                exp_err("Improper font parameter");
                help1("I'm zeroing this one. Proceed, with fingers crossed.");
                put_get_flush_error(0);
              }
              param[j] = cur_exp;
              incr(j);
            } while (!(cur_cmd != comma));
        }
      }
      break;
  }
}
/* 1177 */
void do_special (void)
{
  small_number m;

  m = cur_mod;
  get_x_next();
  scan_expression();
  if (internal[proofing] >= 0)
    if (cur_type != m)
    {
      exp_err("Unsuitable expression");
      help1("The expression shown above has the wrong type to be output.");
      put_get_error();
    }
    else
    {
      check_gf();
      if (m == string_type)
        gf_string(cur_exp, 0);
      else
      {
        gf_out(yyy);
        gf_four(cur_exp);
      }
    }
  flush_cur_exp(0);
}
/* 1186 */
void store_base_file (void)
{
  integer k;
  halfword p, q;
  integer x;
  four_quarters w;

  selector = new_string;
  r_print(" (preloaded base=");
  print(job_name);
  print_char(' ');
  print_int(round_unscaled(internal[year]));
  print_char('.');
  print_int(round_unscaled(internal[month]));
  print_char('.');
  print_int(round_unscaled(internal[day]));
  print_char(')');
  if (interaction == batch_mode)
    selector = log_only;
  else
    selector = term_and_log;
  str_room(1);
  base_ident = make_string();
  str_ref[base_ident] = max_str_ref;
  pack_job_name(base_extension);
  while (!w_open_out(base_file))
    prompt_file_name("base name file", base_extension);
  r_print_nl("Beginning to dump on file ");
  slow_print(w_make_name_string(base_file));
  flush_string(str_ptr - 1);
  r_print_nl("");
  slow_print(base_ident);
  dump_int(4795517L);
  dump_int(mem_min);
  dump_int(mem_top);
  dump_int(hash_size);
  dump_int(hash_prime);
  dump_int(max_in_open);
  dump_int(pool_ptr);
  dump_int(str_ptr);
  for (k = 0; k <= str_ptr; k++)
    dump_int(str_start[k]);
  k = 0;
  while (k + 4 < pool_ptr)
  {
    dump_four_ASCII();
    k = k + 4;
  }
  k = pool_ptr - 4;
  dump_four_ASCII();
  print_ln();
  print_int(str_ptr);
  r_print(" strings of total length ");
  print_int(pool_ptr);
  sort_avail();
  var_used = 0;
  dump_int(lo_mem_max);
  dump_int(rover);
  p = mem_min;
  q = rover;
  x = 0;
  do {
    for (k = p; k <= q + 1; k++)
      dump_wd(mem[k]);
    x = x + q + 2 - p;
    var_used = var_used + q - p;
    p = q + node_size(q);
    q = rlink(q);
  } while (!(q == rover));
  var_used = var_used + lo_mem_max - p;
  dyn_used = mem_end + 1 - hi_mem_min;
  for (k = p; k <= lo_mem_max; k ++)
    dump_wd(mem[k]);
  x = x + lo_mem_max + 1 - p;
  dump_int(hi_mem_min);
  dump_int(avail);
  for (k = hi_mem_min; k <= mem_end; k++)
    dump_wd(mem[k]);
  x = x + mem_end + 1 - hi_mem_min;
  p = avail;
  while (p != null)
  {
    decr(dyn_used);
    p = link(p);
  }
  dump_int(var_used);
  dump_int(dyn_used);
  print_ln();
  print_int(x);
  r_print(" memory locations dumped; current usage is ");
  print_int(var_used);
  print_char('&');
  print_int(dyn_used);
  dump_int(hash_used);
  st_count = frozen_inaccessible - 1 - hash_used;
  for (p = 1; p <= hash_used; p++)
  {
    if (text(p) != 0)
    {
      dump_int(p);
      dump_hh(hash[p]);
      dump_hh(eqtb[p]);
      incr(st_count);
    }
  }
  for (p = hash_used + 1; p <= hash_end; p++)
  {
    dump_hh(hash[p]);
    dump_hh(eqtb[p]);
  }
  dump_int(st_count);
  print_ln();
  print_int(st_count);
  r_print(" symbolic tokens");
  dump_int(int_ptr);
  for (k = 1; k <= int_ptr; k++)
  {
    dump_int(internal[k]);
    dump_int(int_name[k]);
  }
  dump_int(start_sym);
  dump_int(interaction);
  dump_int(base_ident);
  dump_int(bg_loc);
  dump_int(eg_loc);
  dump_int(serial_no);
  dump_int(69069);
  internal[tracing_stats] = 0;
  w_close(base_file);
}
/* 989 */
void do_statement (void)
{
  cur_type = vacuous;
  get_x_next();
  if (cur_cmd > max_primary_command)
  {
    if (cur_cmd < semicolon)
    {
      print_err("A statement can't begin with `");
      print_cmd_mod(cur_cmd, cur_mod);
      print_char('\'');
      help5("I was looking for the beginning of a new statement.",
        "If you just proceed without changing anything, I'll ignore",
        "everything up to the next `;'. Please insert a semicolon",
        "now in front of anything that you don't want me to delete.",
        "(See Chapter 27 of The METAFONTbook for an example.)");
      back_error();
      get_x_next();
    }
  }
  else if (cur_cmd > max_statement_command)
  {
    var_flag = assignment;
    scan_expression();
    if (cur_cmd < end_group)
    {
      if (cur_cmd == equals)
        do_equation();
      else if (cur_cmd == assignment)
        do_assignment();
      else if (cur_type == string_type)
      {
        if (internal[tracing_titles] > 0)
        {
          r_print_nl("");
          slow_print(cur_exp);
          update_terminal();
        }
        if (internal[proofing] > 0)
        {
          check_gf();
          gf_string("title ", cur_exp);
        }
      }
      else if (cur_type != vacuous)
      {
        exp_err("Isolated expression");
        help3("I couldn't find an `=' or `:=' after the",
          "expression that is shown above this error message,",
          "so I guess I'll just ignore it and carry on.");
        put_get_error();
      }
      flush_cur_exp(0);
      cur_type = vacuous;
    }
  }
  else
  {
    if (internal[tracing_commands] > 0)
      show_cmd_mod(cur_cmd, cur_mod);
    switch (cur_cmd)
    {
      case type_name:
        do_type_declaration();
        break;
      case macro_def:
        if (cur_mod > var_def)
          make_op_def();
        else if (cur_mod > end_def)
          scan_def();
        break;
      case random_seed:
        do_random_seed();
        break;
      case mode_command:
        {
          print_ln();
          interaction = cur_mod;
          if (interaction == batch_mode)
            selector = no_print;
          else
            selector = term_only;
          if (log_opened)
            selector = selector + 2;
          get_x_next();
        }
        break;
      case protection_command:
        do_protection();
        break;
      case delimiters:
        def_delims();
        break;
      case save_command:
        do {
          get_symbol();
          save_variable(cur_sym);
          get_x_next();
        } while (!(cur_cmd != comma));
        break;
      case interim_command:
        do_interim();
        break;
      case let_command:
        do_let();
        break;
      case new_internal:
        do_new_internal();
        break;
      case show_command:
        do_show_whatever();
        break;
      case add_to_command:
        do_add_to();
        break;
      case ship_out_command:
        do_ship_out();
        break;
      case display_command:
        do_display();
        break;
      case open_window:
        do_open_window();
        break;
      case cull_command:
        do_cull();
        break;
      case every_job_command:
        {
          get_symbol();
          start_sym = cur_sym;
          get_x_next();
        }
        break;
      case message_command:
        do_message();
        break;
      case tfm_command:
        do_tfm_command();
        break;
      case special_command:
        do_special();
        break;
    }
    cur_type = vacuous;
  }
  if (cur_cmd < semicolon)
  {
    print_err("Extra tokens will be flushed");
    help6("I've just read as much of that statement as I could fathom,",
      "so a semicolon should have been next. It's very puzzling...",
      "but I'll try to get myself back together, by ignoring",
      "everything up to the next `;'. Please insert a semicolon",
      "now in front of anything that you don't want me to delete.",
      "(See Chapter 27 of The METAFONTbook for an example.)");
    back_error();
    scanner_status = flushing;
    do {
      get_next();
      if (cur_cmd == string_token)
        delete_str_ref(cur_mod);
    } while (!(cur_cmd > comma));
    scanner_status = normal;
  }
  error_count = 0;
}
/* 1017 */
void main_control (void)
{
  do {
    do_statement();
    if (cur_cmd == end_group)
    {
      print_err("Extra `endgroup'");
      help2("I'm not currently working on a `begingroup',", 
        "so I had better not try to end anything.");
      flush_error(0);
    }
  } while (!(cur_cmd == stop));
}
/* 1117 */
pointer sort_in (scaled v)
{
  pointer p, q, r;

  p = temp_head;
  while (true)
  {
    q = link(p);
    if (v <= value(q))
      goto found;
    p = q;
  }
found:
  if (v < value(q))
  {
    r = get_node(value_node_size);
    value(r) = v;
    link(r) = q;
    link(p) = r;
  }
  return link(p);
}
/* 1118 */
integer min_cover (scaled d)
{
  pointer p;
  scaled l;
  integer m;

  m = 0;
  p = link(temp_head);
  perturbation = el_gordo;
  while (p != inf_val)
  {
    incr(m);
    l = value(p);
    do {
      p = link(p);
    } while (!(value(p) > l + d));
    if (value(p) - l < perturbation)
      perturbation = value(p) - l;
  }
  return m;
}
/* 1120 */
scaled threshold (integer m)
{
  scaled d;

  excess = min_cover(0) - m;
  if (excess <= 0)
    return 0;
  else
  {
    do {
      d = perturbation;
    } while (!(min_cover(d + d) <= m));
    while (min_cover(d) > m)
      d = perturbation;
    return d;
  }
}
/* 1121 */
integer skimp (integer m)
{
  scaled d;
  pointer p, q, r;
  scaled l;
  scaled v;

  d = threshold(m);
  perturbation = 0;
  q = temp_head;
  m = 0;
  p = link(temp_head);
  while (p != inf_val)
  {
    incr(m);
    l = value(p);
    info(p) = m;
    if (value(link(p)) <= l + d)
    {
      do {
        p = link(p);
        info(p) = m;
        decr(excess);
        if (excess == 0)
          d = 0;
      } while (!(value(link(p)) > l + d));
      v = l + half(value(p) - l);
      if (value(p) - v > perturbation)
        perturbation = value(p) - v;
      r = q;
      do {
        r = link(r);
        value(r) = v;
      } while (!(r == p));
      link(q) = p;
    }
    q = p;
    p = link(p);
  }
  return m;
}
/* 1123 */
void tfm_warning (small_number m)
{
  print_nl(1041);
  print(int_name[m]);
  print(1042);
  print_scaled(perturbation);
  print(1043);
}
/* 1128 */
void fix_design_size (void)
{
  scaled d;

  d = internal[design_size];
  if ((d < unity) || (d >= fraction_half))
  {
    if (d != 0)
      r_print_nl("(illegal design size has been changed to 128pt)");
    d = 040000000;
    internal[design_size] = d;
  }
  if (header_byte[5] < 0)
    if (header_byte[6] < 0)
      if (header_byte[7] < 0)
        if (header_byte[8] < 0)
        {
          header_byte[5] = d / 04000000;
          header_byte[6] = (d / 4096) % 256;
          header_byte[7] = (d / 16) % 256;
          header_byte[8] = (d % 16) * 16;
        }
  max_tfm_dimen = 16 * internal[design_size] - 1 - internal[design_size] / 010000000;
  if (max_tfm_dimen >= fraction_half)
    max_tfm_dimen = fraction_half - 1;
}
/* 1129 */
integer dimen_out (scaled x)
{
  if (abs(x) > max_tfm_dimen)
  {
    incr(tfm_changed);
    if (x > 0)
      x = max_tfm_dimen;
    else
      x = -max_tfm_dimen;
  }
  x = make_scaled(x * 16, internal[design_size]);
  return x;
}
/* 1131 */
void fix_check_sum (void)
{
  eight_bits k;
  eight_bits b1, b2, b3, b4;
  integer x;

  if (header_byte[1] < 0)
    if (header_byte[2] < 0)
      if (header_byte[3] < 0)
        if (header_byte[4] < 0)
        {
          b1 = bc;
          b2 = ec;
          b3 = bc;
          b4 = ec;
          tfm_changed = 0;
          for (k = bc; k <= ec; k++)
            if (char_exists[k])
            {
              x = dimen_out(value(tfm_width[k])) + (k + 4) * 020000000;
              b1 = (b1 + b1 + x) % 255;
              b2 = (b2 + b2 + x) % 253;
              b3 = (b3 + b3 + x) % 251;
              b4 = (b4 + b4 + x) % 247;
            }
          header_byte[1] = b1;
          header_byte[2] = b2;
          header_byte[3] = b3;
          header_byte[4] = b4;
          goto l_exit;
        }
  for (k = 1; k <= 4; k++)
    if (header_byte[k] < 0)
      header_byte[k] = 0;
l_exit:;
}
/* 1133 */
void tfm_qqqq (four_quarters x)
{
  tfm_out(qo(x.b0));
  tfm_out(qo(x.b1));
  tfm_out(qo(x.b2));
  tfm_out(qo(x.b3));
}
/* 779 */
boolean open_base_file (void)
{
  boolean Result;
  integer j;

  j = loc;
  if (buffer[loc] == '&')
  {
    incr(loc);
    j = loc;
    buffer[last] = ' ';
    while (buffer[j] != ' ')
      incr(j);
    pack_buffered_name(0, loc, j - 1);
    if (w_open_in(base_file))
      goto found;
    wake_up_terminal();
    wterm_ln("Sorry, I can't find the base `", " will try PLAIN.");
    update_terminal();
  }
  pack_buffered_name(base_default_length - base_ext_length, 1, 0);
  if (!w_open_in(base_file))
  {
    wake_up_terminal();
    wterm_ln("I can't find the PLAIN base file!");
    Result = false;
    goto l_exit;
  }
found:
  loc = j;
  Result = true;
l_exit:
  return Result;
}
/* 1187 */
boolean load_base_file (void)
{
  boolean Result;
  integer k;
  halfword p, q;
  integer x;
  four_quarters w;

  undump_int(x);
  if (x != 1462914374L)
    goto off_base;
  undump_int(x);
  if (x != mem_min)
    goto off_base;
  undump_int(x);
  if (x != mem_top)
    goto off_base;
  undump_int(x);
  if (x != hash_size)
    goto off_base;
  undump_int(x);
  if (x != hash_prime)
    goto off_base;
  undump_int(x);
  if (x != max_in_open)
    goto off_base;
  undump_size(0, pool_size, "string pool size", pool_ptr);
  undump_size(0, max_strings, "max strings", str_ptr);
  for (k = 0; k <= str_ptr; k++)
  {
    undump(0, pool_ptr, str_start[k]);
    str_ref[k] = max_str_ptr;
  }
  k = 0;
  while (k + 4 < pool_ptr)
  {
    undump_four_ASCII();
    k = k + 4;
  }
  k = pool_ptr - 4;
  undump_four_ASCII();
  init_str_ptr = str_ptr;
  init_pool_ptr = pool_ptr;
  max_str_ptr = str_ptr;
  max_pool_ptr = pool_ptr;
  undump(lo_mem_stat_max + 1000, hi_mem_stat_min - 1, lo_mem_max);
  undump(lo_mem_stat_max + 1, lo_mem_max, rover);
  p = mem_min;
  q = rover;
  do {
    for (k = p; k <= q + 1; k++)
      undump_wd(mem[k]);
    p = q + node_size(q);
    if ((p > lo_mem_max) || ((q >= rlink(q)) && (rlink(q) != rover)))
      goto off_base;
    q = rlink(q);
  } while (!(q == rover));
  for (k = p; k <= lo_mem_max; k++)
    undump_wd(mem[k]);
  undump(lo_mem_max + 1, hi_mem_stat_min, hi_mem_min);
  undump(null, mem_top, avail);
  mem_end = mem_top;
  for (k = hi_mem_min; k <= mem_end; k++)
    undump_wd(mem[k]);
  undump_int(var_used);
  undump_int(dyn_used);
  undump(1, frozen_inaccessible, hash_used);
  p = 0;
  do {
    undump(p + 1, hash_used, p);
    undump_hh(hash[p]);
    undump_hh(eqtb[p]);
  } while (!(p == hash_used));
  for (p = hash_used + 1; p <= hash_end; p++)
  {
    undump_hh(hash[p]);
    undump_hh(eqtb[p]);
  }
  undump_int(st_count);
  undump(max_given_internal, max_internal, int_ptr);
  for (k = 1; k <= int_ptr; k++)
  {
    undump_int(internal[k]);
    undump(0, str_ptr, int_name[k]);
  }
  undump(0, frozen_inaccessible, start_sym);
  undump(batch_mode, error_stop_mode, interaction);
  undump(0, str_ptr, base_ident);
  undump(1, hash_end, bg_loc);
  undump(1, hash_end, eg_loc);
  undump_int(serial_no);
  undump_int(x);
  if (x != 69069L)
    goto off_base;
  Result = true;
  goto l_exit;
off_base:
  fprintf(stdout, "%s\n", "(Fatal base file error; I'm stymied)");
  Result = false;
l_exit:
  return Result;
}
/* 823 */
void scan_primary (void)
{
  pointer p, q, r;
  quarterword c;
  unsigned char my_var_flag;
  pointer l_delim, r_delim;
  integer group_line;
  scaled num, denom;
  pointer pre_head, post_head, tail;
  small_number tt;
  pointer t;
  pointer macro_ref;

  my_var_flag = var_flag;
  var_flag = 0;
l_restart:
  check_arith();
#ifdef DEBUG
  if (panicking)
    check_mem(false);
#endif
  if (interrupt != 0)
    if (OK_to_interrupt)
    {
      back_input();
      check_interrupt();
      get_x_next();
    }
  switch (cur_cmd)
  {
    case left_delimiter:
      {
        l_delim = cur_sym;
        r_delim = cur_mod;
        get_x_next();
        scan_expression();
        if ((cur_cmd == comma) && (cur_type >= known))
        {
          p = get_node(value_node_size);
          type(p) = pair_type;
          name_type(p) = capsule;
          init_big_node(p);
          q = value(p);
          stash_in(x_part_loc(q));
          get_x_next();
          scan_expression();
          if (cur_type < known)
          {
            exp_err("Nonnumeric ypart has been replaced by 0");
            help4("I thought you were giving me a pair `(x,y)'; but",
              "after finding a nice xpart `x' I found a ypart `y'",
              "that isn't of numeric type. So I've changed y to zero.",
              "(The y that I didn't like appears above the error message.)");
            put_get_flush_error(0);
          }
          stash_in(y_part_loc(q));
          check_delimiter(l_delim, r_delim);
          cur_type = pair_type;
          cur_exp = p;
        }
        else
          check_delimiter(l_delim, r_delim);
      }
      break;
    case begin_group:
      {
        group_line = line;
        if (internal[tracing_commands] > 0)
          show_cmd_mod(cur_cmd, cur_mod);
        save_boundary_item(p);
        do {
          do_statement();
        } while (!(cur_cmd != semicolon));
        if (cur_cmd != end_group)
        {
          print_err("A group begun on line ");
          print_int(group_line);
          r_print(" never ended");
          help2("I saw a `begingroup' back there that hasn't been matched",
            "by `endgroup'. So I've inserted `endgroup' now.");
          back_error();
          cur_cmd = end_group;
        }
        unsave();
        if (internal[tracing_commands] > 0)
          show_cmd_mod(cur_cmd, cur_mod);
      }
      break;
    case string_token:
      {
        cur_type = string_type;
        cur_exp = cur_mod;
      }
      break;
    case numeric_token:
      {
        cur_exp = cur_mod;
        cur_type = known;
        get_x_next();
        if (cur_cmd != slash)
        {
          num = 0;
          denom = 0;
        }
        else
        {
          get_x_next();
          if (cur_cmd != numeric_token)
          {
            back_input();
            cur_cmd = slash;
            cur_mod = over;
            cur_sym = frozen_slash;
            goto done;
          }
          num = cur_exp;
          denom = cur_mod;
          if (denom == 0)
          {
            print_err("Division by zero");
            help1("I'll pretend that you meant to divide by 1.");
            error();
          }
          else
            cur_exp = make_scaled(num, denom);
          check_arith();
          get_x_next();
        }
        if (cur_cmd >= min_primary_command)
          if (cur_cmd < numeric_token)
          {
            p = stash_cur_exp();
            scan_primary();
            if ((abs(num) >= abs(denom)) || (cur_type < pair_type))
              do_binary(p, times);
            else
            {
              frac_mult(num, denom);
              free_node(p, value_node_size);
            }
          }
        goto done;
      }
      break;
    case nullary:
      do_nullary(cur_mod);
      break;
    case unary:
    case type_name:
    case cycle:
    case plus_or_minus:
      {
        c = cur_mod;
        get_x_next();
        scan_primary();
        do_unary(c);
        goto done;
      }
      break;
    case primary_binary:
      {
        c = cur_mod;
        get_x_next();
        scan_expression();
        if (cur_cmd != of_token)
        {
          missing_err("of");
          r_print(" for ");
          print_cmd_mod(primary_binary, c);
          help1("I've got the first argument; will look now for the other.");
          back_error();
        }
        p = stash_cur_exp();
        get_x_next();
        scan_primary();
        do_binary(p, c);
        goto done;
      }
      break;
    case str_op:
      {
        get_x_next();
        scan_suffix();
        old_setting = selector;
        selector = new_string;
        show_token_list(cur_exp, null, 100000, 0);
        flush_token_list(cur_exp);
        cur_exp = make_string();
        selector = old_setting;
        cur_type = string_type;
        goto done;
      }
      break;
    case internal_quantity:
      {
        q = cur_mod;
        if (my_var_flag == assignment)
        {
          get_x_next();
          if (cur_cmd == assignment)
          {
            cur_exp = get_avail();
            info(cur_exp) = q + hash_end;
            cur_type = token_list;
            goto done;
          }
          back_input();
        }
        cur_type = known;
        cur_exp = internal[q];
      }
      break;
    case capsule_token:
      make_exp_copy(cur_mod);
      break;
    case tag_token:
      {
        fast_get_avail(pre_head);
        tail = pre_head;
        post_head = null;
        tt = vacuous;
        while (true)
        {
          t = cur_tok();
          link(tail) = t;
          if (tt != undefined)
          {
            {
              p = link(pre_head);
              q = info(p);
              tt = undefined;
              if (eq_type(q) % outer_tag == tag_token)
              {
                q = equiv(q);
                if (q == null)
                  goto done2;
                while (true)
                {
                  p = link(p);
                  if (p == null)
                  {
                    tt = type(q);
                    goto done2;
                  }
                  if (type(q) != structured)
                    goto done2;
                  q = link(attr_head(q));
                  if (p >= hi_mem_min)
                  {
                    do {
                      q = link(q);
                    } while (!(attr_loc(q) >= info(p)));
                    if (attr_loc(q) > info(p))
                      goto done2;
                  }
                }
              }
            done2:;
            }
            if (tt >= unsuffixed_macro)
            {
              link(tail) = null;
              if (tt > unsuffixed_macro)
              {
                post_head = get_avail();
                tail = post_head;
                link(tail) = t;
                tt = undefined;
                macro_ref = value(q);
                add_mac_ref(macro_ref);
              }
              else
              {
                p = get_avail();
                info(pre_head) = link(pre_head);
                link(pre_head) = p;
                info(p) = t;
                macro_call(value(q), pre_head, null);
                get_x_next();
                goto l_restart;
              }
            }
          }
          get_x_next();
          tail = t;
          if (cur_cmd == left_bracket)
          {
            get_x_next();
            scan_expression();
            if (cur_cmd != right_bracket)
            {
              back_input();
              back_expr();
              cur_cmd = left_bracket;
              cur_mod = 0;
              cur_sym = frozen_left_bracket;
            }
            else
            {
              if (cur_type != known)
                bad_subscript();
              cur_cmd = numeric_token;
              cur_mod = cur_exp;
              cur_sym = 0;
            }
          }
          if (cur_cmd > numeric_token)
            goto done1;
          if (cur_cmd < internal_quantity)
            goto done1;
        }
      done1:
        if (post_head != null)
        {
          back_input();
          p = get_avail();
          q = link(post_head);
          info(pre_head) = link(pre_head);
          link(pre_head) = post_head;
          info(post_head) = q;
          link(post_head) = p;
          info(p) = link(q);
          link(q) = null;
          macro_call(macro_ref, pre_head, null);
          decr(ref_count(macro_ref));
          get_x_next();
          goto l_restart;
        }
        q = link(pre_head);
        free_avail(pre_head);
        if (cur_cmd == my_var_flag)
        {
          cur_type = token_list;
          cur_exp = q;
          goto done;
        }
        p = find_variable(q);
        if (p != null)
          make_exp_copy(p);
        else
        {
          obliterated(q);
          help_line[2] = "While I was evaluating the suffix of this variable,";
          help_line[1] = "something was redefined, and it's no longer a variable!";
          help_line[0] = "In order to get back on my feet, I've inserted `0' instead.";
          put_get_flush_error(0);
        }
        flush_node_list(q);
        goto done;
      }
      break;
    default:
      {
        bad_exp("A primary");
        goto l_restart;
      }
      break;
  }
  get_x_next();
done:
  if (cur_cmd == left_bracket)
    if (cur_type >= known)
    {
      p = stash_cur_exp();
      get_x_next();
      scan_expression();
      if (cur_cmd != comma)
      {
        {
          back_input();
          back_expr();
          cur_cmd = left_bracket;
          cur_mod = 0;
          cur_sym = frozen_left_bracket;
        }
        unstash_cur_exp(p);
      }
      else
      {
        q = stash_cur_exp();
        get_x_next();
        scan_expression();
        if (cur_cmd != right_bracket)
        {
          missing_err("]");
          help3("I've scanned an expression of the form `a[b,c',",
            "so a right bracket should have come next.", 
            "I shall pretend that one was there.");
          back_error();
        }
        r = stash_cur_exp();
        make_exp_copy(q);
        do_binary(r, minus);
        do_binary(p, times);
        do_binary(q, plus);
        get_x_next();
      }
    }
}
/* 860 */
void scan_suffix (void)
{
  pointer h, t;
  pointer p;

  h = get_avail();
  t = h;
  while (true)
  {
    if (cur_cmd == left_bracket)
    {
      get_x_next();
      scan_expression();
      if (cur_type != known)
        bad_subscript();
      if (cur_cmd != right_bracket)
      {
        missing_err("]");
        help3("I've seen a `[' and a subscript value, in a suffix,",
          "so a right bracket should have come next.",
          "I shall pretend that one was there.");
        back_error();
      }
      cur_cmd = numeric_token;
      cur_mod = cur_exp;
    }
    if (cur_cmd == numeric_token)
      p = new_num_tok(cur_mod);
    else if ((cur_cmd == tag_token) || (cur_cmd == internal_quantity))
    {
      p = get_avail();
      info(p) = cur_sym;
    }
    else
      goto done;
    link(t) = p;
    t = p;
    get_x_next();
  }
done:
  cur_exp = link(h);
  free_avail(h);
  cur_type = token_list;
}
/* 862 */
void scan_secondary (void)
{
  pointer p;
  halfword c, d;
  pointer mac_name;

l_restart:
  if ((cur_cmd < min_primary_command) || (cur_cmd > max_primary_command))
    bad_exp("A secondary");
  scan_primary();
l_continue:
  if (cur_cmd <= max_secondary_command)
    if (cur_cmd >= min_secondary_command)
    {
      p = stash_cur_exp();
      c = cur_mod;
      d = cur_cmd;
      if (d == secondary_primary_macro)
      {
        mac_name = cur_sym;
        add_mac_ref(c);
      }
      get_x_next();
      scan_primary();
      if (d != secondary_primary_macro)
       do_binary(p, c);
      else
      {
        back_input();
        binary_mac(p, c, mac_name);
        decr(ref_count(c));
        get_x_next();
        goto l_restart;
      }
      goto l_continue;
    }
}
/* 864 */
void scan_tertiary (void)
{
  pointer p;
  halfword c, d;
  halfword mac_name;

l_restart:
  if ((cur_cmd < min_primary_command) || (cur_cmd > max_primary_command))
    bad_exp("A tertiary");
  scan_secondary();
  if (cur_type == future_pen)
    materialize_pen();
l_continue:
  if (cur_cmd <= max_tertiary_command)
    if (cur_cmd >= min_tertiary_command)
    {
      p = stash_cur_exp();
      c = cur_mod;
      d = cur_cmd;
      if (d == tertiary_secondary_macro)
      {
        mac_name = cur_sym;
        add_mac_ref(c);
      }
      get_x_next();
      scan_secondary();
      if (d != tertiary_secondary_macro)
        do_binary(p, c);
      else
      {
        back_input();
        binary_mac(p, c, mac_name);
        decr(ref_count(c));
        get_x_next();
        goto l_restart;
      }
      goto l_continue;
    }
}
/* 868 */
void scan_expression (void)
{
  pointer p, q, r, pp, qq;
  halfword c, d;
  unsigned char my_var_flag;
  halfword mac_name;
  boolean cycle_hit;
  scaled x, y;
  unsigned char t;

  my_var_flag = var_flag;
l_restart:
  if ((cur_cmd < min_primary_command) || (cur_cmd > max_primary_command))
    bad_exp("An");
  scan_tertiary();
l_continue:
  if (cur_cmd <= max_expression_command)
  {
    if (cur_cmd >= min_expression_command)
    {
      if ((cur_cmd != equals) || (my_var_flag != assignment))
      {
        p = stash_cur_exp();
        c = cur_mod;
        d = cur_cmd;
        if (d == expression_tertiary_macro)
        {
          mac_name = cur_sym;
          add_mac_ref(c);
        }
        if ((d < ampersand) || ((d == ampersand) && ((type(p) == pair_type) || (type(p) == path_type))))
        {
          cycle_hit = false;
          {
            unstash_cur_exp(p);
            if (cur_type == pair_type)
              p = new_knot();
            else if (cur_type == path_type)
              p = cur_exp;
            else
              goto l_exit;
            q = p;
            while (link(q) != p)
              q = link(q);
            if (left_type(p) != endpoint)
            {
              r = copy_knot(p);
              link(q) = r;
              q = r;
            }
            left_type(p) = open;
            right_type(q) = open;
          }
        lab25:
          if (cur_cmd == left_brace)
          {
            t = scan_direction();
            if (t != open)
            {
              right_type(q) = t;
              right_given(q) = cur_exp;
              if (left_type(q) == open)
              {
                left_type(q) = t;
                left_given(q) = cur_exp;
              }
            }
          }
          d = cur_cmd;
          if (d == path_join)
          {
            get_x_next();
            if (cur_cmd == tension)
            {
              get_x_next();
              y = cur_cmd;
              if (cur_cmd == at_least)
                get_x_next();
              scan_primary();
              if ((cur_type != known) || (cur_exp < three_quarter_unit))
              {
                exp_err("Improper tension has been set to 1");
                help1("The expression above should have been a number >=3/4.");
                put_get_flush_error(unity);
              }
              if (y == at_least)
                negate(cur_exp);
              right_tension(q) = cur_exp;
              if (cur_cmd == and_command)
              {
                get_x_next();
                y = cur_cmd;
                if (cur_cmd == at_least)
                  get_x_next();
                scan_primary();
                if ((cur_type != known) || (cur_exp < three_quarter_unit))
                {
                  exp_err("Improper tension has been set to 1");
                  help1("The expression above should have been a number >=3/4.");
                  put_get_flush_error(unity);
                }
                if (y == at_least)
                  negate(cur_exp);
              }
              y = cur_exp;
            }
            else if (cur_cmd == controls)
            {
              right_type(q) = explicit;
              t = explicit;
              get_x_next();
              scan_primary();
              known_pair();
              right_x(q) = cur_x;
              right_y(q) = cur_y;
              if (cur_cmd != and_command)
              {
                x = right_x(q);
                y = right_y(q);
              }
              else
              {
                get_x_next();
                scan_primary();
                known_pair();
                x = cur_x;
                y = cur_y;
              }
            }
            else
            {
              right_tension(q) = unity;
              y = unity;
              back_input();
              goto done;
            }
            if (cur_cmd != path_join)
            {
              missing_err("..");
              help1("A path join command should end with two dots.");
              back_error();
            }
          done:;
          }
          else if (d != ampersand)
            goto lab26;
          get_x_next();
          if (cur_cmd == left_brace)
          {
            t = scan_direction();
            if (right_type(q) != explicit)
              x = cur_exp;
            else
              t = explicit;
          }
          else if (right_type(q) != explicit)
          {
            t = open;
            x = 0;
          }
          if (cur_cmd == cycle)
          {
            cycle_hit = true;
            get_x_next();
            pp = p;
            qq = p;
            if (d == ampersand)
              if (p == q)
              {
                d = path_join;
                right_tension(q) = unity;
                y = unity;
              }
          }
          else
          {
            scan_tertiary();
            {
              if (cur_type != path_type)
                pp = new_knot();
              else
                pp = cur_exp;
              qq = pp;
              while (link(qq) != pp)
                qq = link(qq);
              if (left_type(pp) != endpoint)
              {
                r = copy_knot(pp);
                link(qq) = r;
                qq = r;
              }
              left_type(pp) = open;
              right_type(qq) = open;
            }
          }
          {
            if (d == ampersand)
            {
              if ((x_coord(q) != x_coord(pp)) || (y_coord(q) != y_coord(pp)))
              {
                print_err("Paths don't touch; `&' will be changed to `..'");
                help3("When you join paths `p&q', the ending point of p",
                  "must be exactly equal to the starting point of q.",
                  "So I'm going to pretend that you said `p..q' instead.");
                put_get_error();
                d = path_join;
                right_tension(q) = unity;
                y = unity;
              }
            }
            if (right_type(pp) == open)
              if ((t == curl) || (t == given))
              {
                right_type(pp) = t;
                right_given(pp) = x;
              }
            if (d == ampersand)
            {
              if (left_type(q) == open)
                if (right_type(q) == open)
                {
                  left_type(q) = curl;
                  left_curl(q) = unity;
                }
              if (right_type(pp) == open)
                if (t == open)
                {
                  right_type(pp) = curl;
                  right_curl(pp) = unity;
                }
              right_type(q) = right_type(pp);
              link(q) = link(pp);
              right_x(q) = right_x(pp);
              right_y(q) = right_y(pp);
              free_node(pp, knot_node_size);
              if (qq == pp)
                qq = q;
            }
            else
            {
              if (right_type(q) == open)
                if ((left_type(q) == curl) || (left_type(q) == given))
                {
                  right_type(q) = left_type(q);
                  right_given(q) = left_given(q);
                }
              link(q) = pp;
              left_y(pp) = y;
              if (t != open)
              {
                left_x(pp) = x;
                left_type(pp) = t;
              }
            }
            q = qq;
          }
          if (cur_cmd >= min_expression_command)
            if (cur_cmd <= ampersand)
              if (!cycle_hit)
                goto lab25;
        lab26:
          if (cycle_hit)
          {
            if (d == ampersand)
              p = q;
          }
          else
          {
            left_type(p) = endpoint;
            if (right_type(p) == open)
            {
              right_type(p) = curl;
              right_curl(p) = unity;
            }
            right_type(q) = endpoint;
            if (left_type(q) == open)
            {
              left_type(q) = curl;
              left_curl(q) = unity;
            }
            link(q) = p;
          }
          make_choices(p);
          cur_type = path_type;
          cur_exp = p;
        }
        else
        {
          get_x_next();
          scan_tertiary();
          if (d != expression_tertiary_macro)
            do_binary(p, c);
          else
          {
            back_input();
            binary_mac(p, c, mac_name);
            decr(ref_count(c));
            get_x_next();
            goto l_restart;
          }
        }
        goto l_continue;
      }
    }
  }
l_exit:;
}
/* 892 */
void get_boolean (void)
{
  get_x_next();
  scan_expression();
  if (cur_type != boolean_type)
  {
    exp_err("Undefined condition will be treated as `false'");
    help2("The expression shown above should have had a definite",
      "true-or-false value. I'm changing it to `false'.");
    put_get_flush_error(false_code);
    cur_type = boolean_type;
  }
}
/* 224 */
void print_capsule (void)
{
  print_char('(');
  print_exp(g_pointer, 0);
  print_char(')');
}
/* 224 */
void token_recycle (void)
{
  recycle_value(g_pointer);
}
/* 1205 */
void close_files_and_terminate (void)
{
  integer k;
  integer lh;
  short lk_offset;
  halfword p;
  scaled x;

#ifdef STAT
  if (internal[tracing_stats] > 0)
  {
    if (log_opened)
    {
      wlog_ln(" ");
      wlog_ln("%s%s\n", "Here is how much of METAFONT's memory", " you used:");
      wlog_ln("%c%ld%s", ' ', (long)max_str_ptr - init_str_ptr, " string");
      if (max_str_ptr != init_str_ptr + 1)
        wlog('s');
      wlog_ln("%s%ld\n", " out of ", (long)max_strings - init_str_ptr);
      wlog_ln("%c%ld%s%ld\n", ' ', (long)max_pool_ptr - init_pool_ptr, " string characters out of ", (long)pool_size - init_pool_ptr);
      wlog_ln("%c%ld%s%ld\n", ' ', (long)lo_mem_max + 0 + mem_end - hi_mem_min + 2, " words of memory out of ", (long)mem_end + 1);
      wlog_ln("%c%ld%s%ld\n", ' ', (long)st_count, " symbolic tokens out of ", (long)hash_size);
      wlog_ln("%c%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%c\n", ' ', (long)max_in_stack, "i,", (long)int_ptr, "n,",       (long)max_rounding_ptr, "r,", (long)max_param_stack, "p,", (long)max_buf_stack + 1,       "b stack positions out of ", (long)stack_size, "i,", (long)max_internal, "n,", (long)max_wiggle, "r,", (long)150, "p,", (long)buf_size, 'b');
    }
  }
#endif
  wake_up_terminal();
  if ((gf_prev_ptr > 0) || (internal[fontmaking] > 0))
  {
    rover = lo_mem_stat_max + 1;
    link(rover) = empty_flag;
    lo_mem_max = hi_mem_min - 1;
    if (lo_mem_max - rover > max_halfword)
      lo_mem_max = max_halfword + rover;
    node_size(rover) = lo_mem_max - rover;
    llink(rover) = rover;
    rlink(rover) = rover;
    link(lo_mem_max) = null;
    info(lo_mem_max) = null;
    clear_the_list();
    for (k = bc; k <= ec; k++)
      if (char_exists[k])
        tfm_width[k] = sort_in(tfm_width[k]);
    nw = skimp(255) + 1;
    dimen_head[1] = link(temp_head);
    if (perturbation >= 010000)
      tfm_warning(char_wd);
    fix_design_size();
    fix_check_sum();
    if (internal[fontmaking] > 0)
    {
      clear_the_list();
      for (k = bc; k <= ec; k++)
      {
        if (char_exists[k])
          if (tfm_height[k] == 0)
            tfm_height[k] = zero_val;
          else
            tfm_height[k] = sort_in(tfm_height[k]);
      }
      nh = skimp(15) + 1;
      dimen_head[2] = link(temp_head);
      if (perturbation >= 010000)
        tfm_warning(char_ht);
      clear_the_list();
      for (k = bc; k <= ec; k++)
        if (char_exists[k])
          if (tfm_depth[k] == 0)
            tfm_depth[k] = zero_val;
          else
            tfm_depth[k] = sort_in(tfm_depth[k]);
      nd = skimp(15) + 1;
      dimen_head[3] = link(temp_head);
      if (perturbation >= 010000)
        tfm_warning(char_dp);
      clear_the_list();
      for (k = bc; k <= ec; k++)
        if (char_exists[k])
          if (tfm_ital_corr[k] == 0)
            tfm_ital_corr[k] = zero_val;
          else
            tfm_ital_corr[k] = sort_in (tfm_ital_corr[k]);
      ni = skimp(63) + 1;
      dimen_head[4] = link(temp_head);
      if (perturbation >= 010000)
        tfm_warning(char_ic);
      internal[fontmaking] = 0;
      if (job_name == 0)
        open_log_file();
      pack_job_name(".tfm");
      while (!b_open_out(tfm_file))
        prompt_file_name("file name for font metrics", ".tfm");
      metric_file_name = b_make_name_string(tfm_file);
      k = header_size;
      while (header_byte[k] < 0)
        decr(k);
      lh = (k + 3) / 4;
      if (bc > ec)
        bc = 1;
      bchar = round_unscaled(internal[boundary_char]);
      if ((bchar < 0) || (bchar > 255))
      {
        bchar = -1;
        lk_started = false;
        lk_offset = 0;
      }
      else
      {
        lk_started = true;
        lk_offset = 1;
      }
      k = label_ptr;
      if (label_loc[k]+ lk_offset > 255)
      {
        lk_offset = 0;
        lk_started = false;
        do {
          char_remainder[label_char[k]] = lk_offset;
          while (label_loc[k - 1] == label_loc[k])
          {
            decr(k);
            char_remainder[label_char[k]] = lk_offset;
          }
          incr(lk_offset);
          decr(k);
        } while (!(lk_offset + label_loc[k] < 256));
      }
      if (lk_offset > 0)
        while (k > 0)
        {
          char_remainder[label_char[k]] = char_remainder[label_char[k]] + lk_offset;
          decr(k);
        }
      if (bch_label < undefined_label)
      {
        skip_byte(nl) = qi(255);
        next_char(nl) = qi(0);
        op_byte(nl) = qi(((bch_label + lk_offset) / 256));
        rem_byte(nl) = qi(((bch_label + lk_offset) % 256));
        incr(nl);
      }
      tfm_two(6 + lh + (ec - bc + 1) + nw + nh + nd + ni + nl + lk_offset + nk + ne + np);
      tfm_two(lh);
      tfm_two(bc);
      tfm_two(ec);
      tfm_two(nw);
      tfm_two(nh);
      tfm_two(nd);
      tfm_two(ni);
      tfm_two(nl + lk_offset);
      tfm_two(nk);
      tfm_two(ne);
      tfm_two(np);
      for (k = 1; k <= 4 * lh; k++)
      {
        if (header_byte[k] < 0)
          header_byte[k] = 0;
        tfm_out(header_byte[k]);
      }
      for (k = bc; k <= ec; k++)
        if (!char_exists[k])
          tfm_four(0);
        else
        {
          tfm_out(info(tfm_width[k]));
          tfm_out((info(tfm_height[k])) * 16 + info(tfm_depth[k]));
          tfm_out((info(tfm_ital_corr[k])) * 4 + char_tag[k]);
          tfm_out(char_remainder[k]);
        }
      tfm_changed = 0;
      for (k = 1; k <= 4; k++)
      {
        tfm_four(0);
        p = dimen_head[k];
        while (p != inf_val)
        {
          tfm_four(dimen_out(value(p)));
          p = link(p);
        }
      }
      for (k = 0; k <= 255; k++)
        if (skip_table[k] < lig_table_size)
        {
          r_print_nl("(local label ");
          print_int(k);
          r_print(":: was missing)");
          cancel_skips(skip_table[k]);
        }
      if (lk_started)
      {
        tfm_out(255);
        tfm_out(bchar);
        tfm_two(0);
      }
      else
        for (k = 1; k <= lk_offset; k++)
        {
          ll = label_loc[label_ptr];
          if (bchar < 0)
          {
            tfm_out(254);
            tfm_out(0);
          }
          else
          {
            tfm_out(255);
            tfm_out(bchar);
          }
          tfm_two(ll + lk_offset);
          do {
            decr(label_ptr);
          } while (!(label_loc[label_ptr] < ll));
        }
      for (k = 0; k <= nl - 1; k++)
        tfm_qqqq(lig_kern[k]);
      for (k = 0; k <= nk - 1; k++)
        tfm_four(dimen_out(kern[k]));
      for (k = 0; k <= ne - 1; k++)
        tfm_qqqq(exten[k]);
      for (k = 1; k <= np; k++)
        if (k == 1)
        {
          if (abs(param[1]) < fraction_half)
            tfm_four(param[1] * 16);
          else
          {
            incr(tfm_changed);
            if (param[1] > 0)
              tfm_four(el_gordo);
            else
              tfm_four(-el_gordo);
          }
        }
        else
          tfm_four(dimen_out(param[k]));
      if (tfm_changed > 0)
      {
        if (tfm_changed == 1)
          r_print_nl("(a font metric dimension");
        else
        {
          r_print_nl("(");
          print_int(tfm_changed);
          r_print(" font metric dimensions");
        }
        r_print(" had to be decreased)");
      }
#ifdef STAT
      if (internal[tracing_stats] > 0)
      {
        wlog_ln(" ");
        { putc (' ', log_file);  putc ('\n', log_file); }
        if (bch_label < lig_table_size)
          decr(nl);
        wlog_ln("%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s\n", "(You used ", (long)nw, "w,", (long)nh, "h,", (long)nd, "d,", (long)ni, "i,", (long)nl, "l,", (long)nk, "k,", (long)ne, "e,", (long)np, "p metric file positions");
        wlog_ln("%s%s%ld%s%ld%s%ld%s\n", "  out of ", "256w,16h,16d,64i,", (long)lig_table_size, "l,", (long)max_kerns, "k,256e,", (long)max_font_dimen, "p)");
      }
#endif
      r_print_nl("Font metrics written on ");
      slow_print(metric_file_name);
      print_char('.');
      b_close(tfm_file);
    }
    if (gf_prev_ptr > 0)
    {
      gf_out(post);
      gf_four(gf_prev_ptr);
      gf_prev_ptr = gf_offset + gf_ptr - 5;
      gf_four(internal[design_size] * 16);
      for (k = 1; k <= 4; k++)
        gf_out(header_byte[k]);
      gf_four(internal[hppp]);
      gf_four(internal[vppp]);
      gf_four(gf_min_m);
      gf_four(gf_max_m);
      gf_four(gf_min_n);
      gf_four(gf_max_n);
      for (k = 0; k <= 255; k++)
        if (char_exists[k])
        {
          x = gf_dx[k] / unity;
          if ((gf_dy[k] == 0) && (x >= 0) && (x < 256) && (gf_dx[k] == x * unity))
          {
            gf_out(char_loc + 1);
            gf_out(k);
            gf_out(x);
          }
          else
          {
            gf_out(char_loc);
            gf_out(k);
            gf_four(gf_dx[k]);
            gf_four(gf_dy[k]);
          }
          x = mem[tfm_width[k]+ 1].cint;
          if (abs(x) > max_tfm_dimen)
            if (x > 0)
              x = three_bytes - 1;
            else
              x = 1 - three_bytes;
          else
            x = make_scaled(x * 16, internal[design_size]);
          gf_four(x);
          gf_four(char_ptr[k]);
        }
      gf_out(post_post);
      gf_four(gf_prev_ptr);
      gf_out(gf_id_byte);
      k = 4 + ((gf_buf_size - gf_ptr) % 4);
      while (k > 0)
      {
        gf_out(233);
        decr(k);
      }
      if (gf_limit == half_buf)
        write_gf(half_buf, gf_buf_size - 1);
      if (gf_ptr > 0)
        write_gf(0, gf_ptr - 1);
      r_print_nl("Output written on ");
      slow_print(output_file_name);
      r_print(" (");
      print_int(total_chars);
      r_print(" character");
      if (total_chars != 1)
        print_char('s');
      r_print(", ");
      print_int(gf_offset + gf_ptr);
      r_print(" bytes).");
      b_close(gf_file);
    }
  }
  if (log_opened)
  {
    wlog_cr();
    a_close(log_file);
    selector = selector - 2;
    if (selector == term_only)
    {
      r_print_nl("Transcript written on ");
      slow_print(log_name);
      print_char('.');
    }
  }
  print_ln();
}
/* 1209 */
void final_cleanup (void)
{
  small_number c;

  c = cur_mod;
  if (job_name == 0)
    open_log_file();
  while (input_ptr > 0)
    if (token_state)
      end_token_list();
    else
      end_file_reading();
  while (loop_ptr != null)
    stop_iteration();
  while (open_parens > 0)
  {
    r_print(" )");
    decr(open_parens);
  }
  while (cond_ptr != null)
  {
    r_print_nl("(end occurred when ");
    print_cmd_mod(fi_or_else, cur_if);
    if (if_line != 0)
    {
      r_print(" on line ");
      print_int(if_line);
    }
    r_print(" was incomplete)");
    if_line = if_line_field(cond_ptr);
    cur_if = name_type(cond_ptr);
    loop_ptr = cond_ptr;
    cond_ptr = link(cond_ptr);
    free_node(loop_ptr, if_node_size);
  }
  if (history != spotless)
    if (((history == warning_issued) || (interaction < term_and_log)))
      if (selector == term_and_log)
      {
        selector = term_only;
        r_print_nl("(see the transcript file for additional information)");
        selector = term_and_log;
      }
  if (c == 1)
  {
#ifdef INIMF
    if (iniversion)
    {
      store_base_file();
      goto l_exit;
    }
#endif
    r_print_nl("(dump is performed only by INIMF)");
    goto l_exit;
  }
l_exit:;
}
/* 1210 */
void init_prim (void)
{
  primitive("tracingtitles", internal_quantity, tracing_titles);
  primitive("tracingequations", internal_quantity, tracing_equations);
  primitive("tracingcapsules", internal_quantity, tracing_capsules);
  primitive("tracingchoices", internal_quantity, tracing_choices);
  primitive("tracingspecs", internal_quantity, tracing_specs);
  primitive("tracingpens", internal_quantity, tracing_pens);
  primitive("tracingcommands", internal_quantity, tracing_commands);
  primitive("tracingrestores", internal_quantity, tracing_restores);
  primitive("tracingmacros", internal_quantity, tracing_macros);
  primitive("tracingedges", internal_quantity, tracing_edges);
  primitive("tracingoutput", internal_quantity, tracing_output);
  primitive("tracingstats", internal_quantity, tracing_stats);
  primitive("tracingonline", internal_quantity, tracing_online);
  primitive("year", internal_quantity, year);
  primitive("month", internal_quantity, month);
  primitive("day", internal_quantity, day);
  primitive("time", internal_quantity, time);
  primitive("charcode", internal_quantity, char_code);
  primitive("charext", internal_quantity, char_ext);
  primitive("charwd", internal_quantity, char_wd);
  primitive("charht", internal_quantity, char_ht);
  primitive("chardp", internal_quantity, char_dp);
  primitive("charic", internal_quantity, char_ic);
  primitive("chardx", internal_quantity, char_dx);
  primitive("chardy", internal_quantity, char_dy);
  primitive("designsize", internal_quantity, design_size);
  primitive("hppp", internal_quantity, hppp);
  primitive("vppp", internal_quantity, vppp);
  primitive("xoffset", internal_quantity, x_offset);
  primitive("yoffset", internal_quantity, y_offset);
  primitive("pausing", internal_quantity, pausing);
  primitive("showstopping", internal_quantity, showstopping);
  primitive("fontmaking", internal_quantity, fontmaking);
  primitive("proofing", internal_quantity, proofing);
  primitive("smoothing", internal_quantity, smoothing);
  primitive("autorounding", internal_quantity, autorounding);
  primitive("granularity", internal_quantity, granularity);
  primitive("fillin", internal_quantity, fillin);
  primitive("turningcheck", internal_quantity, turning_check);
  primitive("warningcheck", internal_quantity, warning_check);
  primitive("boundarychar", internal_quantity, boundary_char);
  primitive("..", path_join, 0);
  primitive("[", left_bracket, 0);
  eqtb[frozen_left_bracket] = eqtb[cur_sym];
  primitive("]", right_bracket, 0);
  primitive("}", right_brace, 0);
  primitive("{", left_brace, 0);
  primitive(":", colon, 0);
  eqtb[frozen_colon] = eqtb[cur_sym];
  primitive("::", double_colon, 0);
  primitive("||:", bchar_label, 0);
  primitive(":=", assignment, 0);
  primitive(",", comma, 0);
  primitive(";", semicolon, 0);
  eqtb[frozen_semicolon] = eqtb[cur_sym];
  primitive("\\", relax, 0);
  primitive("addto", add_to_command, 0);
  primitive("at", at_token, 0);
  primitive("atleast", at_least, 0);
  primitive("begingroup", begin_group, 0);
  bg_loc = cur_sym;
  primitive("controls", controls, 0);
  primitive("cull", cull_command, 0);
  primitive("curl", curl_command, 0);
  primitive("delimiters", delimiters, 0);
  primitive("display", display_command, 0);
  primitive("endgroup", end_group, 0);
  eqtb[frozen_end_group] = eqtb[cur_sym];
  eg_loc = cur_sym;
  primitive("everyjob", every_job_command, 0);
  primitive("exitif", exit_test, 0);
  primitive("expandafter", expand_after, 0);
  primitive("from", from_token, 0);
  primitive("inwindow", in_window, 0);
  primitive("interim", interim_command, 0);
  primitive("let", let_command, 0);
  primitive("newinternal", new_internal, 0);
  primitive("of", of_token, 0);
  primitive("openwindow", open_window, 0);
  primitive("randomseed", random_seed, 0);
  primitive("save", save_command, 0);
  primitive("scantokens", scan_tokens, 0);
  primitive("shipout", ship_out_command, 0);
  primitive("skipto", skip_to, 0);
  primitive("step", step_token, 0);
  primitive("str", str_op, 0);
  primitive("tension", tension, 0);
  primitive("to", to_token, 0);
  primitive("until", until_token, 0);
  primitive("def", macro_def, start_def);
  primitive("vardef", macro_def, var_def);
  primitive("primarydef", macro_def, secondary_primary_macro);
  primitive("secondarydef", macro_def, tertiary_secondary_macro);
  primitive("tertiarydef", macro_def, expression_tertiary_macro);
  primitive("enddef", macro_def, end_def);
  eqtb[frozen_end_def] = eqtb[cur_sym];
  primitive("for", iteration, expr_base);
  primitive("forsuffixes", iteration, suffix_base);
  primitive("forever", iteration, start_forever);
  primitive("endfor", iteration, end_for);
  eqtb[frozen_end_for] = eqtb[cur_sym];
  primitive("quote", macro_special, quote);
  primitive("#@", macro_special, macro_prefix);
  primitive("@", macro_special, macro_at);
  primitive("@#", macro_special, macro_suffix);
  primitive("expr", param_type, expr_base);
  primitive("suffix", param_type, suffix_base);
  primitive("text", param_type, text_base);
  primitive("primary", param_type, primary_macro);
  primitive("secondary", param_type, secondary_macro);
  primitive("tertiary", param_type, tertiary_macro);
  primitive("input", input, 0);
  primitive("endinput", input, 1);
  primitive("if", if_test, if_code);
  primitive("fi", fi_or_else, fi_code);
  eqtb[frozen_fi] = eqtb[cur_sym];
  primitive("else", fi_or_else, else_code);
  primitive("elseif", fi_or_else, else_if_code);
  primitive("true", nullary, true_code);
  primitive("false", nullary, false_code);
  primitive("nullpicture", nullary, null_picture_code);
  primitive("nullpen", nullary, null_pen_code);
  primitive("jobname", nullary, job_name_op);
  primitive("readstring", nullary, read_string_op);
  primitive("pencircle", nullary, pen_circle);
  primitive("normaldeviate", nullary, normal_deviate);
  primitive("odd", unary, odd_op);
  primitive("known", unary, known_op);
  primitive("unknown", unary, unknown_op);
  primitive("not", unary, not_op);
  primitive("decimal", unary, decimal);
  primitive("reverse", unary, reverse);
  primitive("makepath", unary, make_path_op);
  primitive("makepen", unary, make_pen_op);
  primitive("totalweight", unary, total_weight_op);
  primitive("oct", unary, oct_op);
  primitive("hex", unary, hex_op);
  primitive("ASCII", unary, ASCII_op);
  primitive("char", unary, char_op);
  primitive("length", unary, length_op);
  primitive("turningnumber", unary, turning_op);
  primitive("xpart", unary, x_part);
  primitive("ypart", unary, y_part);
  primitive("xxpart", unary, xx_part);
  primitive("xypart", unary, xy_part);
  primitive("yxpart", unary, yx_part);
  primitive("yypart", unary, yy_part);
  primitive("sqrt", unary, sqrt_op);
  primitive("mexp", unary, m_exp_op);
  primitive("mlog", unary, m_log_op);
  primitive("sind", unary, sin_d_op);
  primitive("cosd", unary, cos_d_op);
  primitive("floor", unary, floor_op);
  primitive("uniformdeviate", unary, uniform_deviate);
  primitive("charexists", unary, char_exists_op);
  primitive("angle", unary, angle_op);
  primitive("cycle", cycle, cycle_op);
  primitive("+", plus_or_minus, plus);
  primitive("-", plus_or_minus, minus);
  primitive("*", secondary_binary, times);
  primitive("/", slash, over);
  eqtb[frozen_slash] = eqtb[cur_sym];
  primitive("++", tertiary_binary, pythag_add);
  primitive("+-+", tertiary_binary, pythag_sub);
  primitive("and", and_command, and_op);
  primitive("or", tertiary_binary, or_op);
  primitive("<", expression_binary, less_than);
  primitive("<=", expression_binary, less_or_equal);
  primitive(">", expression_binary, greater_than);
  primitive(">=", expression_binary, greater_or_equal);
  primitive("=", equals, equal_to);
  primitive("<>", expression_binary, unequal_to);
  primitive("substring", primary_binary, substring_of);
  primitive("subpath", primary_binary, subpath_of);
  primitive("directiontime", primary_binary, direction_time_of);
  primitive("point", primary_binary, point_of);
  primitive("precontrol", primary_binary, precontrol_of);
  primitive("postcontrol", primary_binary, postcontrol_of);
  primitive("penoffset", primary_binary, pen_offset_of);
  primitive("&", ampersand, concatenate);
  primitive("rotated", secondary_binary, rotated_by);
  primitive("slanted", secondary_binary, slanted_by);
  primitive("scaled", secondary_binary, scaled_by);
  primitive("shifted", secondary_binary, shifted_by);
  primitive("transformed", secondary_binary, transformed_by);
  primitive("xscaled", secondary_binary, x_scaled);
  primitive("yscaled", secondary_binary, y_scaled);
  primitive("zscaled", secondary_binary, z_scaled);
  primitive("intersectiontimes", tertiary_binary, intersect);
  primitive("numeric", type_name, numeric_type);
  primitive("string", type_name, string_type);
  primitive("boolean", type_name, boolean_type);
  primitive("path", type_name, path_type);
  primitive("pen", type_name, pen_type);
  primitive("picture", type_name, picture_type);
  primitive("transform", type_name, transform_type);
  primitive("pair", type_name, pair_type);
  primitive("end", stop, 0);
  primitive("dump", stop, 1);
  primitive("batchmode", mode_command, batch_mode);
  primitive("nonstopmode", mode_command, nonstop_mode);
  primitive("scrollmode", mode_command, scroll_mode);
  primitive("errorstopmode", mode_command, error_stop_mode);
  primitive("inner", protection_command, 0);
  primitive("outer", protection_command, 1);
  primitive("showtoken", show_command, show_token_code);
  primitive("showstats", show_command, show_stats_code);
  primitive("show", show_command, show_code);
  primitive("showvariable", show_command, show_var_code);
  primitive("showdependencies", show_command, show_dependencies_code);
  primitive("contour", thing_to_add, contour_code);
  primitive("doublepath", thing_to_add, double_path_code);
  primitive("also", thing_to_add, also_code);
  primitive("withpen", with_option, pen_type);
  primitive("withweight", with_option, known);
  primitive("dropping", cull_op, drop_code);
  primitive("keeping", cull_op, keep_code);
  primitive("message", message_command, message_code);
  primitive("errmessage", message_command, err_message_code);
  primitive("errhelp", message_command, err_help_code);
  primitive("charlist", tfm_command, char_list_code);
  primitive("ligtable", tfm_command, lig_table_code);
  primitive("extensible", tfm_command, extensible_code);
  primitive("headerbyte", tfm_command, header_byte_code);
  primitive("fontdimen", tfm_command, font_dimen_code);
  primitive("=:", lig_kern_token, 0);
  primitive("=:|", lig_kern_token, 1);
  primitive("=:|>", lig_kern_token, 5);
  primitive("|=:", lig_kern_token, 2);
  primitive("|=:>", lig_kern_token, 6);
  primitive("|=:|", lig_kern_token, 3);
  primitive("|=:|>", lig_kern_token, 7);
  primitive("|=:|>>", lig_kern_token, 11);
  primitive("kern", lig_kern_token, 128);
  primitive("special", special_command, string_type);
  primitive("numspecial", special_command, known);
}
/* 1210 */
void init_tab (void)
{
  integer k;

  rover = lo_mem_stat_max + 1;
  link(rover) = empty_flag;
  node_size(rover) = 1000;
  llink(rover) = rover;
  rlink(rover) = rover;
  lo_mem_max = rover + 1000;
  link(lo_mem_max) = null;
  info(lo_mem_max) = null;
  for (k = mem_top - 2; k <= mem_top; k++)
    mem[k] = mem[lo_mem_max];
  avail = null;
  mem_end = mem_top;
  hi_mem_min = hi_mem_stat_min;
  var_used = lo_mem_stat_max + 1 - mem_min;
  dyn_used = mem_top + 1 - hi_mem_min;
  int_name[tracing_titles] = "tracingtitles";
  int_name[tracing_equations] = "tracingequations";
  int_name[tracing_capsules] = "tracingcapsules";
  int_name[tracing_choices] = "tracingchoices";
  int_name[tracing_specs] = "tracingspecs";
  int_name[tracing_pens] = "tracingpens";
  int_name[tracing_commands] = "tracingcommands";
  int_name[tracing_restores] = "tracingrestores";
  int_name[tracing_macros] = "tracingmacros";
  int_name[tracing_edges] = "tracingedges";
  int_name[tracing_output] = "tracingoutput";
  int_name[tracing_stats] = "tracingstats";
  int_name[tracing_online] = "tracingonline";
  int_name[year] = "year";
  int_name[month] = "month";
  int_name[day] = "day";
  int_name[time] = "time";
  int_name[char_code] = "charcode";
  int_name[char_ext] = "charext";
  int_name[char_wd] = "charwd";
  int_name[char_ht] = "charht";
  int_name[char_dp] = "chardp";
  int_name[char_ic] = "charic";
  int_name[char_dx] = "chardx";
  int_name[char_dy] = "chardy";
  int_name[design_size] = "designsize";
  int_name[hppp] = "hppp";
  int_name[vppp] = "vppp";
  int_name[x_offset] = "xoffset";
  int_name[y_offset] = "yoffset";
  int_name[pausing] = "pausing";
  int_name[showstopping] = "showstopping";
  int_name[fontmaking] = "fontmaking";
  int_name[proofing] = "proofing";
  int_name[smoothing] = "smoothing";
  int_name[autorounding] = "autorounding";
  int_name[granularity] = "granularity";
  int_name[fillin] = "fillin";
  int_name[turning_check] = "turningcheck";
  int_name[warning_check] = "warningcheck";
  int_name[boundary_char] = "boundarychar";
  hash_used = frozen_inaccessible;
  st_count = 0;
  text(frozen_bad_vardef) = "a bad variable";
  text(frozen_fi) = "fi";
  text(frozen_end_group) = "endgroup";
  text(frozen_end_def) = "enddef";
  text(frozen_end_for) = "endfor";
  text(frozen_semicolon) = ";";
  text(frozen_colon) = ":";
  text(frozen_slash) = "/";
  text(frozen_left_bracket) = "[";
  text(frozen_right_delimiter) = ")";
  text(frozen_inaccessible) = " INACCESSIBLE";
  eq_type(frozen_right_delimiter) = right_delimiter;
  attr_loc(end_attr) = hash_end + 1;
  parent(end_attr) = null;
  info(sentinel) = max_halfword;
  ref_count(null_pen) = null;
  link(null_pen) = null;
  info(null_pen + 1) = 1;
  link(null_pen + 1) = null_coords;
  for (k = null_pen + 2; k <= null_pen + 8; k++)
    mem[k] = mem[null_pen + 1];
  max_offset(null_pen) = 0;
  link(null_coords) = null_coords;
  knil(null_coords) = null_coords;
  x_coord(null_coords) = 0;
  y_coord(null_coords) = 0;
  serial_no = 0;
  link(dep_head) = dep_head;
  prev_dep(dep_head) = dep_head;
  info(dep_head) = null;
  dep_list(dep_head) = null;
  name_type(bad_vardef) = root;
  link(bad_vardef) = frozen_bad_vardef;
  equiv(frozen_bad_vardef) = bad_vardef;
  eq_type(frozen_bad_vardef) = tag_token;
  eq_type(frozen_repeat_loop) = repeat_loop + outer_tag;
  text(frozen_repeat_loop) = " ENDFOR";
  name_type(temp_val) = capsule;
  value(inf_val) = fraction_four;
  value(zero_val) = 0;
  info(zero_val) = 0;
  if (inimf)
    base_ident = " (INIMF)";
}

/* 1212 */
#ifdef DEBUG
void debug_help (void)
{
  integer k, l, m, n;

  while (true)
  {
    wake_up_terminal();
    r_print_nl("debug # (-1 to exit):");
    unpated_terminal();
    read(term_in, m);
    if (m < 0)
      goto l_exit;
    else if (m == 0)
    {
      goto lab888;
      lab888: m = 0;
    }
    else
    {
      read(term_in, n);
      switch (m)
      {
        case 1:
          print_word(mem[n]);
          break;
        case 2:
          print_int(info(n));
          break;
        case 3:
          print_int(link(n));
          break;
        case 4:
          {
            print_int(eq_type(n));
            print_char(':');
            print_int(equiv(n));
          }
          break;
        case 5:
          print_variable_name(n);
          break;
        case 6:
          print_int(internal[n]);
          break;
        case 7:
          do_show_dependencies();
          break;
        case 9:
          show_token_list(n, null, 100000, 0);
          break;
        case 10:
          slow_print(n);
          break;
        case 11:
          check_mem(n > 0);
          break;
        case 12:
          search_mem(n);
          break;
        case 13:
          {
            read(term_in, l);
            print_cmd_mod(n, l);
          }
          break;
        case 14:
          for (k = 0; k <= n; k++)
            print(buffer[k]);
          break;
        case 15:
          panicking = !panicking;
          break;
        default:
          r_print("?");
          break;
      }
    }
  }
l_exit:;
}
#endif /* TEXMF_DEBUG */
/* main */
void main_program (void)
{
  history = fatal_error_stop;
  t_open_out();
  if (ready_already == 314159)
    goto start_of_MF;
  bad = 0;
  if ((half_error_line < 30) || (half_error_line > error_line - 15))
    bad = 1;
  if (max_print_line < 60)
    bad = 2;
  if (gf_buf_size % 8 != 0)
    bad = 3;
  if (mem_min + 1100 > mem_top)
    bad = 4;
  if (hash_prime > hash_size)
    bad = 5;
  if (header_size % 4 != 0)
    bad = 6;
  if ((lig_table_size < 255) || (lig_table_size > 32510))
    bad = 7;
#ifdef INIMF
  if (mem_max != mem_top)
    bad = 10;
#endif
  if (mem_max < mem_top)
    bad = 10;
  if ((min_quarterword > 0) || (max_quarterword < 127))
    bad = 11;
  if ((min_halfword > 0) || (max_halfword < 32767))
    bad = 12;
  if ((min_quarterword < min_halfword) || (max_quarterword > max_halfword))
    bad = 13;
  if ((mem_min < min_halfword) || (mem_max >= max_halfword))
    bad = 14;
  if (max_strings > max_halfword)
    bad = 15;
  if (buf_size > max_halfword)
    bad = 16;
  if ((max_quarterword - min_quarterword < 255) || (max_halfword - min_halfword < 65535))
    bad = 17;
  if (hash_end + max_internal > max_halfword)
    bad = 21;
  if (text_base + param_size > max_halfword)
    bad = 22;
  if (15 * move_increment > bistack_size)
    bad = 31;
  if (int_packets + 17 * int_increment > bistack_size)
    bad = 32;
  if (base_default_length > file_name_size)
    bad = 41;
  if (bad > 0)
  {
    wterm_ln("%s%s%ld\n", "Ouch---my internal constants have been clobbered!", "---case ", (long) bad);
    goto final_end;
  }
  initialize();
#ifdef INIMF
  if (iniversion)
  {
    if (!get_strings_started())
      goto final_end;
    init_tab();
    init_prim();
    init_str_ptr = str_ptr;
    init_pool_ptr = pool_ptr;
    max_str_ptr = str_ptr;
    max_pool_ptr = pool_ptr;
    fix_date_and_time();
  }
#endif
  ready_already = 314159;
start_of_MF:
  selector = term_only;
  tally = 0;
  term_offset = 0;
  file_offset = 0;
  wterm(banner);
  if (base_ident == 0)
    wterm_ln("%s%s%c\n", " (preloaded base=", dump_name, ')');
  else
  {
    slow_print(base_ident);
    print_ln();
  }
  update_terminal();
  job_name = 0;
  log_opened = false;
  output_file_name = 0;
  {
    {
      input_ptr = 0;
      max_in_stack = 0;
      in_open = 0;
      open_parens = 0;
      max_buf_stack = 0;
      param_ptr = 0;
      max_param_stack = 0;
      first = 1;
      start = 1;
      index = 0;
      line = 0;
      name = 0;
      force_eof = false;
      if (!init_terminal())
        goto final_end;
      limit = last;
      first = last + 1;
    }
    scanner_status = normal;
    if ((base_ident == 0) || (buffer[loc] == '&'))
    {
      if (base_ident != 0)
        initialize();
      if (!open_base_file())
        goto final_end;
      if (!load_base_file())
      {
        w_close(base_file);
        goto final_end;
      }
      w_close(base_file);
      while ((loc < limit) && (buffer[loc] == ' '))
        incr(loc);
    }
    buffer[limit] = '%';
    fix_date_and_time();
    init_randoms((internal[time] / unity) + internal[day]);
    if (interaction == batch_mode)
      selector = no_print;
    else
      selector = term_only;
    if (loc < limit)
      if (buffer[loc] != '\\')
        start_input();
  }
  history = spotless;
  if (start_sym > 0)
  {
    cur_sym = start_sym;
    back_input();
  }
  main_control();
  final_cleanup();
  close_files_and_terminate();
final_end:
  ready_already = 0;
}
