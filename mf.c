#include "mf.h"

/* 4 */
void initialize (void)
{
  integer i;
  integer k;

  xchr[32] = ' ';
  xchr[33] = '!';
  xchr[34] = '"';
  xchr[35] = '#';
  xchr[36] = '$';
  xchr[37] = '%';
  xchr[38] = '&';
  xchr[39] = '\'';
  xchr[40] = '(';
  xchr[41] = ')';
  xchr[42] = '*';
  xchr[43] = '+';
  xchr[44] = ',';
  xchr[45] = '-';
  xchr[46] = '.';
  xchr[47] = '/';
  xchr[48] = '0';
  xchr[49] = '1';
  xchr[50] = '2';
  xchr[51] = '3';
  xchr[52] = '4';
  xchr[53] = '5';
  xchr[54] = '6';
  xchr[55] = '7';
  xchr[56] = '8';
  xchr[57] = '9';
  xchr[58] = ':';
  xchr[59] = ';';
  xchr[60] = '<';
  xchr[61] = '=';
  xchr[62] = '>';
  xchr[63] = '?';
  xchr[64] = '@';
  xchr[65] = 'A';
  xchr[66] = 'B';
  xchr[67] = 'C';
  xchr[68] = 'D';
  xchr[69] = 'E';
  xchr[70] = 'F';
  xchr[71] = 'G';
  xchr[72] = 'H';
  xchr[73] = 'I';
  xchr[74] = 'J';
  xchr[75] = 'K';
  xchr[76] = 'L';
  xchr[77] = 'M';
  xchr[78] = 'N';
  xchr[79] = 'O';
  xchr[80] = 'P';
  xchr[81] = 'Q';
  xchr[82] = 'R';
  xchr[83] = 'S';
  xchr[84] = 'T';
  xchr[85] = 'U';
  xchr[86] = 'V';
  xchr[87] = 'W';
  xchr[88] = 'X';
  xchr[89] = 'Y';
  xchr[90] = 'Z';
  xchr[91] = '[';
  xchr[92] = '\\';
  xchr[93] = ']';
  xchr[94] = '^';
  xchr[95] = '_';
  xchr[96] = '`';
  xchr[97] = 'a';
  xchr[98] = 'b';
  xchr[99] = 'c';
  xchr[100] = 'd';
  xchr[101] = 'e';
  xchr[102] = 'f';
  xchr[103] = 'g';
  xchr[104] = 'h';
  xchr[105] = 'i';
  xchr[106] = 'j';
  xchr[107] = 'k';
  xchr[108] = 'l';
  xchr[109] = 'm';
  xchr[110] = 'n';
  xchr[111] = 'o';
  xchr[112] = 'p';
  xchr[113] = 'q';
  xchr[114] = 'r';
  xchr[115] = 's';
  xchr[116] = 't';
  xchr[117] = 'u';
  xchr[118] = 'v';
  xchr[119] = 'w';
  xchr[120] = 'x';
  xchr[121] = 'y';
  xchr[122] = 'z';
  xchr[123] = '{';
  xchr[124] = '|';
  xchr[125] = '}';
  xchr[126] = '~';
  for (i = 0; i <= 037; i++)
  {
    xchr[i] = ' ';
  }
  for (i = 0177; i <= 0377; i++)
  {
    xchr[i] = ' ';
  }
  for (i = first_text_char; i <= last_text_char; i++)
  {
    xord[chr (i)] = 0177;
  }
  for (i = 0200; i <= 0377; i++)
  {
    xord[xchr[i]] = i;
  }
  for (i = 0; i <= 0176; i++)
  {
    xord[xchr[i]] = i;
  }
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
#ifdef TEXMF_DEBUG
  was_mem_end = mem_min;
  was_lo_max = mem_min;
  was_hi_min = mem_max;
  panicking = false;
#endif /* TEXMF_DEBUG */
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
  octant_dir[first_octant] = 548;
  octant_dir[second_octant] = 549;
  octant_dir[third_octant] = 550;
  octant_dir[fourth_octant] = 551;
  octant_dir[fifth_octant] = 552;
  octant_dir[sixth_octant] = 553;
  octant_dir[seventh_octant] = 554;
  octant_dir[eighth_octant] = 555;
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
  {
    octant_number[octant_code[k]] = k;
  }
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
  {
    z_corr[k] = xy_corr[k] - x_corr[k];
  }
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
  {
    header_byte[k] = -1;
  }
  bc = 255;
  ec = 0;
  nl = 0;
  nk = 0;
  ne = 0;
  np = 0;
  internal[boundary_char] = -65536;
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
        putc('\n', stdout);
        putc('\n', log_file);
        term_offset = 0;
        file_offset = 0;
      }
      break;
    case log_only:
      {
        putc('\n', log_file);
        file_offset = 0;
      }
      break;
    case term_only:
      {
        putc('\n', stdout);
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
        putc(xchr[s], stdout);
        putc(xchr[s], log_file);
        incr(term_offset);
        incr(file_offset);
        if (term_offset == max_print_line)
        {
          putc('\n', stdout);
          term_offset = 0;
        }
        if (file_offset == max_print_line)
        {
          putc('\n', log_file);
          file_offset = 0;
        }
      }
      break;
    case log_only:
      {
        putc(xchr[s], log_file);
        incr(file_offset);
        if (file_offset == max_print_line)
          print_ln();
      }
      break;
    case term_only:
      {
        putc(xchr[s], stdout);
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
    s = 259;
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
/* 60 */
void slow_print (integer s)
{
  pool_pointer j;

  if ((s < 0) || (s >= str_ptr))
    s = 259;
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
      print("vacuous");
      break;
    case boolean_type:
      print("boolean");
      break;
    case unknown_boolean:
      print("unknown boolean");
      break;
    case string_type:
      print("string");
      break;
    case unknown_string:
      print("unknown string");
      break;
    case pen_type:
      print("pen");
      break;
    case unknown_pen:
      print("unknown pen");
      break;
    case future_pen:
      print("future pen");
      break;
    case path_type:
      print("path");
      break;
    case unknown_path:
      print("unknown path");
      break;
    case picture_type:
      print("picture");
      break;
    case unknown_picture:
      print("unknown picture");
      break;
    case transform_type:
      print("transform");
      break;
    case pair_type:
      print("pair");
      break;
    case known:
      print("known numeric");
      break;
    case dependent:
      print("dependent");
      break;
    case proto_dependent:
      print("proto-dependent");
      break;
    case numeric_type:
      print("numeric");
      break;
    case independent:
      print("independent");
      break;
    case token_list:
      print("token list");
      break;
    case structured:
      print("structured");
      break;
    case unsuffixed_macro:
      print("unsuffixed macro");
      break;
    case suffixed_macro:
      print("suffixed macro");
      break;
    default:
      print("undefined");
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
  print_nl("");
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
  print(450);
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
    do {
      decr(str_ptr);
    } while (!(str_ref[str_ptr - 1] != 0));
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
    lab_continue:
      clear_for_error_prompt();
      prompt_input("? ");
      if (last == first)
        goto lab_exit;
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
            goto lab_continue;
          }
          break;
#ifdef TEXMF_DEBUG
        case 'D':
          {
            debug_help();
            goto lab_continue;
          }
          break;
#endif /* TEXMF_DEBUG */
        case 'E':
          if (file_ptr > 0)
          {
            print_nl("You want to edit file ");
            slow_print(input_stack[file_ptr].name_field);
            print(" at line ");
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
                else if (str_pool[j + 1] != 37)
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
            goto lab_continue;
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
            goto lab_exit;
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
                  print(273);
                  decr(selector);
                }
                break;
              case 'R':
                print(274);
                break;
              case 'S':
                print(275);
                break;
            }
            print(276);
            print_ln();
            fflush(stdout);
            goto lab_exit;
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
        print("Type <return> to proceed, S to scroll future error messages,");
        print_nl("R to run without stopping, Q to run quietly,");
        print_nl("I to insert something, ");
        if (file_ptr > 0)
          print("E to edit your file,");
        if (deletions_allowed)
          print_nl("1 or ... or 9 to ignore the next 1 to 9 tokens of input,");
        print_nl("H for help, X to quit.");
      }
    }
  }
  incr(error_count);
  if (error_count == 100)
  {
    print_nl(264);
    history = fatal_error_stop;
    jump_out ();
  }
  if (interaction > batch_mode)
    decr(selector);
  if (use_err_help)
  {
    print_nl(261);
    j = str_start[err_help];
    while (j < str_start[err_help + 1])
    {
      if (str_pool[j]!= 37)
        print(str_pool[j]);
      else if (j + 1 == str_start[err_help + 1])
        print_ln();
      else if (str_pool[j + 1]!= 37)
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
  lab_exit:;
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
      goto lab_exit;
    }
  }
  while (true)
  {
    fputs("**", stdout);
    fflush(stdout);
    if (!input_ln(stdin, true))
    {
      putc('\n', stdout);
      fprintf(stdout, "%s\n", "!End of file on the terminal... why?");
      Result = false;
      goto lab_exit;
    }
    loc = first;
    while ((loc < last) && (buffer[loc] == ' '))
      incr(loc);
    if (loc < last)
    {
      Result = true;
      goto lab_exit;
    }
    fprintf(stdout, "%s\n", "Please type the name of your input file.");
  }
lab_exit:;
  return Result;
}
/* 44 */
str_number make_string (void)
{
  str_number Result;
  
  if (str_ptr == max_str_ptr)
  {
    if (str_ptr == max_strings)
      overflow("number of strings", max_strings - init_str_ptr);
    incr(max_str_ptr);
  }
  str_ref[str_ptr] = 1;
  incr(str_ptr);
  str_start[str_ptr] = pool_ptr;
  Result = str_ptr - 1;
  return Result;
}
/* 45 */
boolean str_eq_buf (str_number s, integer k)
{
  boolean Result;
  pool_pointer j;
  boolean result;

  j = str_start[s];
  while (j < str_start[s + 1])
  {
    if (str_pool[j]!= buffer[k])
    {
      result = false;
      goto not_found;
    }
    incr(j);
    incr(k);
  }
  result = true;
not_found:
  Result = result;
  return Result;
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
      goto lab_exit;
    }
    incr(j);
    incr(k);
    decr(l);
  }
  Result = ls - lt;
lab_exit:;
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
    goto lab_exit;
  }
  Result = true;
lab_exit:;
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
  {
    for (k = first; k <= last - 1; k++)
      print(buffer[k]);
  }
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
  print(299);
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
  integer Result;

  if (x >= 0)
  {
    if (y <= el_gordo - x)
      Result = x + y;
    else
    {
      arith_error = true;
      Result = el_gordo;
    }
  }
  else if (-y <= el_gordo + x)
    Result = x + y;
  else
  {
    arith_error = true;
    Result = -el_gordo;
  }
  return Result;
}
/* 102 */
scaled round_decimals (small_number k)
{
  scaled Result;
  integer a;
  
  a = 0;
  while (k > 0)
  {
    decr(k);
    a = (a + dig[k] * two) / 10;
  }
  Result = half(a + 1);
  return Result;
}
/* 107 */
fraction make_fraction (integer p, integer q)
{
  fraction Result;
  integer f;
  integer n;
  boolean negative;
  integer be_careful;
  
  if (p >= 0)
    negative = false;
  else
  {
    p = -p;
    negative = true;
  }
  if (q <= 0)
  {
#ifdef TEXMF_DEBUG
    if (q == 0)
      confusion("/");
#endif /* TEXMF_DEBUG */
    negate(q);
    negative = !negative;
  }
  n = p / q;
  p = p % q;
  if (n >= 8)
  {
    arith_error = true;
    if (negative)
      Result = -el_gordo;
    else
      Result = el_gordo;
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
        f = f + f;
        p = p + q;
      }
    } while (!(f >= fraction_one));
    be_careful = p - q;
    if (be_careful + p >= 0)
      incr(f);
    if (negative)
      Result = -(f + n);
    else
      Result = f + n;
  }
  return Result;
}
/* 109 */
integer take_fraction (integer q, fraction f)
{
  integer Result;
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
  {
    do {
      if (odd(f))
        p = half(p + q);
      else
        p = half(p);
      f = half(f);
    } while (!(f == 1));
  }
  else
  {
    do {
      if (odd(f))
        p = p + half(q - p);
      else
        p = half(p);
      f = half(f);
    } while (!(f == 1));
  }
  be_careful = n - el_gordo;
  if (be_careful + p > 0)
  {
    arith_error = true;
    n = el_gordo - p;
  }
  if (negative)
    Result = -(n + p);
  else
    Result = n + p;
  return Result;
}
/* 112 */
integer take_scaled (integer q, scaled f)
{
  integer Result;
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
  {
    do {
      if (odd(f))
        p = half(p + q);
      else
        p = half(p);
      f = half(f);
    } while (!(f == 1));
  }
  else
  {
    do {
      if (odd(f))
        p = p + half(q - p);
      else
        p = half(p);
      f = half(f);
    } while (!(f == 1));
  }
  be_careful = n - el_gordo;
  if (be_careful + p > 0)
  {
    arith_error = true;
    n = el_gordo - p;
  }
  if (negative)
    Result = -(n + p);
  else
    Result = n + p;
  return Result;
}
/* 114 */
scaled make_scaled (integer p, integer q)
{
  scaled Result;
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
#ifdef TEXMF_DEBUG
    if (q == 0)
      confusion("/");
#endif /* TEXMF_DEBUG */
    negate(q);
    negative = !negative;
  }
  n = p / q;
  p = p % q;
  if (n >= half_unit)
  {
    arith_error = true;
    if (negative)
      Result = -el_gordo;
    else
      Result = el_gordo;
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
      Result = -(f + n);
    else
      Result = f + n;
  }
  return Result;
}
/* 116 */
fraction velocity (fraction st, fraction ct, fraction sf, fraction cf, scaled t)
{
  fraction Result;
  integer acc, num, denom;

  acc = take_fraction(st - (sf / 16), sf - (st / 16));
  acc = take_fraction(acc, ct - cf);
  num = fraction_two + take_fraction(acc, 379625062);
  denom = fraction_three + take_fraction(ct, 497706707) + take_fraction(cf, 307599661);
  if (t != unity)
    num = make_scaled(num, t);
  if (num / 4 >= denom)
    Result = fraction_four;
  else
    Result = make_fraction(num, denom);
  return Result;
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
  lab_exit:;
  return Result;
}
/* 121 */
scaled square_rt (scaled x)
{
  scaled Result;
  small_number k;
  integer y, q;
  
  if (x <= 0)
  {
    if (x < 0)
    {
      print_err("Square root of ");
      print_scaled(x);
      print(306);
      help2("Since I don't take square roots of negative numbers,",
        "I'm zeroing this one. Proceed, with fingers crossed.");
      error();
    }
    Result = 0;
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
      x = x + x;
      y = y + y;
      if (x >= fraction_four)
      {
        x = x - fraction_four;
        incr(y);
      }
      x = x + x;
      y = y + y - q;
      q = q + q;
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
    Result = half(q);
  }
  return Result;
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
  Result = a;
  return Result;
}
/* 126 */
integer pyth_sub (integer a, integer b)
{
  integer Result;
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
      print(310);
      print_scaled(b);
      print(306);
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
  Result = a;
  return Result;
}
/* 132 */
scaled m_log (scaled x)
{
  scaled Result;
  integer y, z;
  integer k;

  if (x <= 0)
  {
    print_err("Logarithm of ");
    print_scaled(x);
    print(306);
    help2("Since I don't take logs of non-positive numbers,",
      "I'm zeroing this one. Proceed, with fingers crossed.");
    error();
    Result = 0;
  }
  else
  {
    y = 1302456956 + 4 - 100;
    z = 27595 + 6553600;
    while (x < fraction_four)
    {
      x = x + x;
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
    Result = y / 8;
  }
  return Result;
}
/* 135 */
scaled m_exp (scaled x)
{
  scaled Result;
  small_number k;
  integer y, z;
  
  if (x > 174436200)
  {
    arith_error = true;
    Result = el_gordo;
  }
  else if (x < -197694359)
    Result = 0;
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
      Result = (y + 8) / 16;
    else
      Result = y;
  }
  return Result;
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
  scaled Result;
  scaled y;
  
  next_random();
  y = take_fraction(abs(x), randoms[j_random]);
  if (y == abs(x))
    Result = 0;
  else if (x > 0)
    Result = y;
  else
    Result = -y;
  return Result;
}
/* 152 */
scaled norm_rand (void)
{
  scaled Result;
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
  Result = x;
  return Result;
}
/* 157 */
#ifdef TEXMF_DEBUG
void print_word (memory_word w)
{
  print_int(w.sc);
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
#endif /* TEXMF_DEBUG */
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
    {
      first_count = tally;
      trick_count = tally + 1 + error_line - half_error_line;
      if (trick_count < error_line)
        trick_count = error_line;
    }
    c = letter_class;
    if ((p < mem_min) || (p > mem_end))
    {
      print(493);
      goto lab_exit;
    }
    if (p < hi_mem_min)
    {
      if (name_type(p) == token)
      {
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
            c = 0;
          }
        }
        else if (type(p) != string_type)
          print(496);
        else
        {
          print_char('"');
          slow_print(value(p));
          print_char('"');
          c = string_class;
        }
      }
      else if ((name_type(p) != capsule) || (type(p) < vacuous) || (type(p) > independent))
        print(496);
      else
      {
        g_pointer = p;
        print_capsule();
        c = right_paren_class;
      }
    }
    else
    {
      r = info(p);
      if (r >= expr_base)
      {
        if (r < suffix_base)
        {
          print(498);
          r = r - (expr_base);
        }
        else if (r < text_base)
        {
          print(499);
          r = r - (suffix_base);
        }
        else
        {
          print(500);
          r = r - (text_base);
        }
        print_int(r);
        print_char(')');
        c = right_paren_class;
      }
      else if (r < 1)
      {
        if (r == 0)
        {
          if (cclass == left_bracket_class)
            print_char(' ');
          print(497);
          c = right_bracket_class;
        }
        else
          print(494);
      }
      else
      {
        r = text(r);
        if ((r < 0) || (r >= str_ptr))
          print(495);
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
    print(492);
  lab_exit:;
}
/* 665 */
void runaway (void)
{
  if (scanner_status > flushing)
  {
    print_nl("Runaway ");
    switch (scanner_status)
    {
      case absorbing:
        print("text?");
        break;
      case var_defining:
      case op_defining:
        print("definition?");
        break;
      case loop_defining:
        print("loop?");
        break;
    }
    print_ln();
    show_token_list(link(hold_head), null, error_line - 10, 0);
  }
}
/* 163 */
pointer get_avail (void)
{
  pointer Result;
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
#endif /* STAT */
  Result = p;
  return Result;
}
/* 167 */
pointer get_node (integer s)
{
  pointer Result;
  pointer p;
  pointer q;
  integer r;
  integer t, tt;
  
lab_restart:
  p = rover;
  do {
    q = p + node_size(p);
    while (is_empty(q))
    {
      t = rlink(q); tt = llink(q);
      if (q == rover)
        rover = t;
      llink(t) = tt; rlink(tt) = t;
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
    {
      if (rlink(p) != p)
      {
        rover = rlink(p); t = llink(p);
        llink(rover) = t; rlink(t) = rover;
        goto found;
      }
    }
    node_size(p) = q - p;
    p = rlink(p);
  } while (!(p == rover));
  if (s == 010000000000)
  {
    Result = max_halfword;
    goto lab_exit;
  }
  if (lo_mem_max + 2 < hi_mem_min)
  {
    if (lo_mem_max + 2 <= mem_min + max_halfword)
    {
      if (hi_mem_min - lo_mem_max >= 1998)
        t = lo_mem_max + 1000;
      else
        t = lo_mem_max + 1 + (hi_mem_min - lo_mem_max) / 2;
      if (t > mem_min + max_halfword)
        t = mem_min + max_halfword;
      p = llink(rover); q = lo_mem_max; rlink(p) = q; llink(rover) = q;
      rlink(q) = rover; llink(q) = p; link(q) = empty_flag; node_size(q) = t - lo_mem_max;
      lo_mem_max = t; link(lo_mem_max) = null; info(lo_mem_max) = null;
      rover = q; goto lab_restart;
    }
  }
  overflow("main memory size", mem_max + 1);
found:
  link(r) = null;
#ifdef STAT
  var_used = var_used + s;
#endif /* STAT */
  Result = r;
lab_exit:;
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
#endif /* STAT */
}
/* 173 */
void sort_avail (void)
{
  halfword p, q, r;
  halfword old_rover;

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
        q = rlink(q);;
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
  {
    if (p != sentinel)
    {
      r = p;
      do {
        q = r;
        r = link(r);
#ifdef STAT
        decr(dyn_used);
#endif /* STAT */
        if (r < hi_mem_min)
          goto done;
      } while (!(r == sentinel));
    done:
      link(q) = avail;
      avail = p;
    }
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
#ifdef TEXMF_DEBUG
void check_mem (boolean print_locs)
{
  halfword p, q, r;
  boolean clobbered;
  
  for (p = 0; p <= lo_mem_max; p++)
  {
    freearr[p] = false;
  }
  for (p = hi_mem_min; p <= mem_end; p++)
  {
    freearr[p] = false;
  }
  p = avail;
  q = 0;
  clobbered = false;
  while (p != 0)
  {
    if ((p > mem_end) || (p < hi_mem_min))
      clobbered = true;
    else if (freearr[p])
      clobbered = true;
    if (clobbered)
    {
      print_nl(316);
      print_int(q);
      goto done1;
    }
    freearr[p] = true;
    q = p;
    p = mem[q].hh.rh;
  }
  done1:;
  p = rover;
  q = 0;
  clobbered = false;
  do {
    if ((p >= lo_mem_max))
      clobbered = true;
    else if ((mem[p + 1].hh.rh >= lo_mem_max))
      clobbered = true;
    else if (!((mem[p].hh.rh == 268435455)) || (mem[p].hh.lh < 2) ||
      (p + mem[p].hh.lh > lo_mem_max) || (mem[mem[p + 1].hh.rh + 1].hh.lh != p))
      clobbered = true;
    if (clobbered)
    {
      print_nl(317);
      print_int(q);
      goto done2;
    }
    for (q = p; q <= p + mem[p].hh.lh - 1; q++)
    {
      if (freearr[q])
      {
        print_nl(318);
        print_int(q);
        goto done2;
      }
      freearr[q] = true;
    }
    q = p;
    p = mem[p + 1].hh.rh;
  } while (!(p == rover));
  done2:;
  p = 0;
  while (p <= lo_mem_max)
  {
    if ((mem[p].hh.rh == 268435455L))
    {
      print_nl(319);
      print_int(p);
    }
    while ((p <= lo_mem_max) && !freearr[p])
      incr(p);
    while ((p <= lo_mem_max) && freearr[p])
      incr(p);
  }
  q = 13;
  p = mem[q].hh.rh;
  while (p != 13)
  {
    if (mem[p + 1].hh.lh != q)
    {
      print_nl(598);
      print_int(p);
    }
    p = mem[p + 1].hh.rh;
    r = 19;
    do {
      if (mem[mem[p].hh.lh + 1].cint >= mem[r + 1].cint)
      {
        print_nl(599);
        print_int(p);
      }
      r = mem[p].hh.lh;
      q = p;
      p = mem[q].hh.rh;
    } while (!(r == 0));
  }
  if (print_locs)
  {
    print_nl(320);
    for (p = 0; p <= lo_mem_max; p++)
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
  {
    was_free[p] = freearr[p];
  }
  for (p = hi_mem_min; p <= mem_end; p++)
  {
    was_free[p] = freearr[p];
  }
  was_mem_end = mem_end;
  was_lo_max = lo_mem_max;
  was_hi_min = hi_mem_min;
}
#endif /* TEXMF_DEBUG */
/* 185 */
#ifdef TEXMF_DEBUG
void search_mem (halfword p)
{
  integer q;

  for (q = 0; q <= lo_mem_max; q++)
  {
    if (mem[q].hh.rh == p)
    {
      print_nl(321);
      print_int(q);
      print_char(')');
    }
    if (mem[q].hh.lh == p)
    {
      print_nl(322);
      print_int(q);
      print_char(')');
    }
  }
  for (q = hi_mem_min; q <= mem_end; q++)
  {
    if (mem[q].hh.rh == p)
    {
      print_nl(321);
      print_int(q);
      print_char(')');
    }
    if (mem[q].hh.lh == p)
    {
      print_nl(322);
      print_int(q);
      print_char(')');
    }
  }
  for (q = 1; q <= 9769; q++)
  {
    if (eqtb[q].rh == p)
    {
      print_nl(458);
      print_int(q);
      print_char(')');
    }
  }
}
#endif /* TEXMF_DEBUG */
/* 189 */
void print_op (quarterword c)
{
  if (c <= 15)
    print_type(c);
  else
    switch (c)
    {
      case true_code:
        print("true");
        break;
      case false_code:
        print("false");
        break;
      case null_picture_code:
        print("nullpicture");
        break;
      case null_pen_code:
        print("nullpen");
        break;
      case job_name_op:
        print("jobname");
        break;
      case read_string_op:
        print("readstring");
        break;
      case pen_circle:
        print("pencircle");
        break;
      case normal_deviate:
        print("normaldeviate");
        break;
      case odd_op:
        print("odd");
        break;
      case known_op:
        print("known");
        break;
      case unknown_op:
        print("unknown");
        break;
      case not_op:
        print("not");
        break;
      case decimal:
        print("decimal");
        break;
      case reverse:
        print("reverse");
        break;
      case make_path_op:
        print("makepath");
        break;
      case make_pen_op:
        print("makepen");
        break;
      case total_weight_op:
        print("totalweight");
        break;
      case oct_op:
        print("oct");
        break;
      case hex_op:
        print("hex");
        break;
      case ASCII_op:
        print("ASCII");
        break;
      case char_op:
        print("char");
        break;
      case length_op:
        print("length");
        break;
      case turning_op:
        print("turningnumber");
        break;
      case x_part:
        print("xpart");
        break;
      case y_part:
        print("ypart");
        break;
      case xx_part:
        print("xxpart");
        break;
      case xy_part:
        print("xypart");
        break;
      case yx_part:
        print("yxpart");
        break;
      case yy_part:
        print("yypart");
        break;
      case sqrt_op:
        print("sqrt");
        break;
      case m_exp_op:
        print("mexp");
        break;
      case m_log_op:
        print("mlog");
        break;
      case sin_d_op:
        print("sind");
        break;
      case cos_d_op:
        print("cosd");
        break;
      case floor_op:
        print("floor");
        break;
      case uniform_deviate:
        print("uniformdeviate");
        break;
      case char_exists_op:
        print("charexists");
        break;
      case angle_op:
        print("angle");
        break;
      case cycle_op:
        print("cycle");
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
        print("++");
        break;
      case pythag_sub:
        print("+-+");
        break;
      case or_op:
        print("or");
        break;
      case and_op:
        print("and");
        break;
      case less_than:
        print_char('<');
        break;
      case less_or_equal:
        print("<=");
        break;
      case greater_than:
        print_char(">");
        break;
      case greater_or_equal:
        print(">=");
        break;
      case equal_to:
        print_char("=");
        break;
      case unequal_to:
        print("<>");
        break;
      case concatenate:
        print("&");
        break;
      case rotated_by:
        print("rotated");
        break;
      case slanted_by:
        print("slanted");
        break;
      case scaled_by:
        print("scaled");
        break;
      case shifted_by:
        print("shifted");
        break;
      case transformed_by:
        print("transformed");
        break;
      case x_scaled:
        print("xscaled");
        break;
      case y_scaled:
        print("yscaled");
        break;
      case z_scaled:
        print("zscaled");
        break;
      case intersect:
        print("intersectiontimes");
        break;
      case substring_of:
        print("substring");
        break;
      case subpath_of:
        print("subpath");
        break;
      case direction_time_of:
        print("directiontime");
        break;
      case point_of:
        print("point");
        break;
      case precontrol_of:
        print("precontrol");
        break;
      case postcontrol_of:
        print("postcontrol");
        break;
      case pen_offset_of:
        print("penoffset");
        break;
      default:
        print("..");
        break;
  }
}
/* 194 */
void fix_date_and_time (void)
{
  dateandtime(internal[time], internal[day], internal[month], internal[year]);
  internal[time] = internal[time] * unity;
  internal[day] = internal[day] * unity;
  internal[month] = internal[month] * unity;
  internal[year] = internal[year] * unity;
}
/* 205 */
pointer id_lookup (integer j, integer l)
{
  halfword Result;
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
    {
      if (length(text(p)) == l)
      {
        if (str_eq_buf(text(p), j))
          goto found;
      }
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
#endif /* STAT */
      goto found;
    }
    p = next(p);
  }
found:
  Result = p;
  return Result;
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
  pointer Result;
  pointer p;

  p = get_node(token_node_size);
  value(p) = v;
  type(p) = known;
  name_type(p) = token;
  Result = p;
  return Result;
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
    case add_to_command:print("addto"); break;
    case assignment:print(":="); break;
    case at_least:print("atleast"); break;
    case at_token:print("at"); break;
    case bchar_label:print("||:"); break;
    case begin_group:print("begingroup"); break;
    case colon:print(":"); break;
    case comma:print(","); break;
    case controls:print("controls"); break;
    case cull_command:print("cull"); break;
    case curl_command:print("curl"); break;
    case delimiters:print("delimiters"); break;
    case display_command:print("display"); break;
    case double_colon:print("::"); break;
    case end_group:print("endgroup"); break;
    case every_job_command:print("everyjob"); break;
    case exit_test:print("exitif"); break;
    case expand_after:print("expandafter"); break;
    case from_token:print("from"); break;
    case in_window:print("inwindow"); break;
    case interim_command:print("interim"); break;
    case left_brace:print("{"); break;
    case left_bracket:print("["); break;
    case let_command:print("let"); break;
    case new_internal:print("newinternal"); break;
    case of_token:print("of"); break;
    case open_window:print("openwindow"); break;
    case path_join:print(".."); break;
    case random_seed:print("randomseed"); break;
    case relax:print_char("\\");break;
    case right_brace:print("}"); break;
    case right_bracket:print("]"); break;
    case save_command:print("save"); break;
    case scan_tokens:print("scantokens"); break;
    case semicolon:print(";"); break;
    case ship_out_command:print("shipout"); break;
    case skip_to:print("skipto"); break;
    case step_token:print("step"); break;
    case str_op:print("str"); break;
    case tension:print("tension"); break;
    case to_token:print("to"); break;
    case until_token:print("until"); break;
    case macro_def:
      if (m <= var_def)
      if (m == start_def) print("def");
      else if (m < start_def) print("enddef");
      else print("vardef");
      else if (m == secondary_primary_macro) print("primarydef");
      else if (m == tertiary_secondary_macro) print("secondarydef");
      else print("tertiarydef");
      break;
    case iteration:
      if (m <= start_forever)
        if (m == start_forever) print("forever"); else print("endfor");
      else if (m == expr_base) print("for"); else print("forsuffixes");
      break;
    case macro_special:
      switch (m)
      {
        case macro_prefix: print("#@@"); break;
        case macro_at: print_char("@@"); break;
        case macro_suffix: print("@@#"); break;
        default: print("quote"); break;
      }
      break;
    case param_type:
      if (m >= expr_base)
      if (m == expr_base) print("expr");
      else if (m == suffix_base) print("suffix");
      else print("text");
      else if (m < secondary_macro) print("primary");
      else if (m == secondary_macro) print("secondary");
      else print("tertiary");
      break;
    case input:
      if (m == 0) print("input"); else print("endinput");
      break;
    case if_test:
    case fi_or_else:
      switch (m)
      {
        case if_code: print("if"); break;
        case fi_code:print("fi"); break;
        case else_code:print("else"); break;
        default: print("elseif"); break;
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
      if (m == 0) print("end"); else print("dump");
      break;
    case mode_command:
      switch (m)
      {
        case batch_mode: print("batchmode"); break;
        case nonstop_mode: print("nonstopmode"); break;
        case scroll_mode: print("scrollmode"); break;
        default: print("errorstopmode"); break;
      }
      break;
    case protection_command:
      if (m == 0) print("inner"); else print("outer");
      break;
    case show_command:
      switch (m)
      {
        case show_token_code: print("showtoken"); break;
        case show_stats_code:print("showstats"); break;
        case show_code:print("show"); break;
        case show_var_code:print("showvariable"); break;
        default: print("showdependencies"); break;
      }
      break;
    case left_delimiter:
    case right_delimiter:
      {
        if (c == left_delimiter) print("lef");
        else print("righ");
        print("t delimiter that matches "); slow_print(text(m));
      }
      break;
    case tag_token:
      if (m == null) print("tag"); else print("variable");
      break;
    case defined_macro:
      print("macro:");
      break;
    case secondary_primary_macro:
    case tertiary_secondary_macro:
    case expression_tertiary_macro:
      {
        print_cmd_mod(macro_def, c); print("'d macro:");
        print_ln(); show_token_list(link(link(m)), null, 1000, 0);
      }
      break;
    case repeat_loop:
      print("[repeat the loop]");
      break;
    case internal_quantity:
      slow_print(int_name[m]);
      break;
    case thing_to_add:
      if (m == contour_code) print("contour");
      else if (m == double_path_code) print("doublepath");
      else print("also");
      break;
    case with_option:
      if (m == pen_type) print("withpen");
      else print("withweight");
      break;
    case cull_op:
      if (m == drop_code) print("dropping");
      else print("keeping");
      break;
    case message_command:
      if (m < err_message_code) print("message");
      else if (m == err_message_code) print("errmessage");
      else print("errhelp");
      break;
    case tfm_command:
      switch (m)
      {
        case char_list_code:print("charlist"); break;
        case lig_table_code:print("ligtable"); break;
        case extensible_code:print("extensible"); break;
        case header_byte_code:print("headerbyte"); break;
        default: print("fontdimen"); break;
      }
      break;
    case lig_kern_token:
      switch (m)
      {
        case 0:print("=:"); break;
        case 1:print("=:|"); break;
        case 2:print("|=:"); break;
        case 3:print("|=:|"); break;
        case 5:print("=:|>"); break;
        case 6:print("|=:>"); break;
        case 7:print("|=:|>"); break;
        case 11:print("|=:|>>"); break;
        default: print("kern"); break;
      }
      break;
    case special_command:
      if (m == known) print("numspecial");
      else print("special");
      break;
    default:
      print("[unknown command code!]");
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
    r = link(p); link(p) = null;
    show_token_list(p, null, l, 0); link(p) = r; p = r;
    if (l > 0)
      l = l - tally;
    else
      goto lab_exit;
  }
  tally = 0;
  switch (info(p))
  {
    case primary_macro:
    case secondary_macro:
    case tertiary_macro:
      {
        print_char("<");
        print_cmd_mod(param_type, info(p)); print(">->");
      }
      break;
    case expr_macro:
      print("<expr>->");
      break;
    case of_macro:
      print("<expr>of<primary>->");
      break;
    case suffix_macro:
      print("<suffix>->");
      break;
    case text_macro:
      print("<text>->");
      break;
  }
  show_token_list(link(p), q, l - tally, 0);
lab_exit:;
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
    new_index(q + s);
    name_type(q + s) = half(s) + x_part_sector;
    link(q + s) = null;
  } while (!(s == 0));
  link(q) = p;
  value(p) = q;
}
/* 233 */
pointer id_transform (void)
{
  pointer Result;
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
  Result = p;
  return Result;
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
        print("xx");
        break;
      case xy_part_sector:
        print("xy");
        break;
      case yx_part_sector:
        print("yx");
        break;
      case yy_part_sector:
        print("yy");
        break;
      case capsule:
        {
          print("%CAPSULE");
          print_int(p - 0);
          goto lab_exit;
        }
        break;
    }
    print("part ");
    p = link(p - 2 * (name_type(p) - x_part_sector));
  }
  q = null;
  while (name_type(p) > saved_root)
  {
    if (name_type(p) == subscr)
    {
      r = new_num_tok (subscript(p));
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
    print("(SAVED)");
  show_token_list(r, null, el_gordo, tally);
  flush_token_list(r);
lab_exit:;
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
    {
      if (t != capsule)
        t = name_type(link(p - 2 * (t - x_part_sector)));
    }
    return (t != capsule);
  }
}
/* 239 */
pointer new_structure (pointer p)
{
  pointer Result;
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
  Result = r;
  return Result;
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
  {
    Result = 0;
    goto lab_exit;
  }
  if (eq_type(p) == null)
    new_root (p);
  p = equiv(p);
  pp = p;
  while (t != null)
  {
    if (type(pp) != structured)
    {
      if (type(pp) > structured)
      {
        Result = 0;
        goto lab_exit;
      }
      ss = new_structure (pp);
      if (p == pp)
        p = ss;
      pp = ss;
    }
    if (type(p) != structured)
      p = new_structure (p);
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
        qq = get_node (attr_node_size);
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
  {
    if (type(pp) == structured)
      pp = attr_head(pp);
    else
    {
      abort_find();
    }
  }
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
lab_exit:;
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
      print_nl("???");
      goto done;
    }
    print_two(x_coord(p), y_coord(p));
    switch (right_type(p))
    {
      case endpoint:
        {
          if (left_type(p) == open)
            print("{open?}");
          if ((left_type(q) != endpoint) || (q != h))
            q = null;
          goto done1;
        }
        break;
      case explicit:
        {
          print("..controls ");
          print_two(right_x(p), right_y(p));
          print(" and ");
          if (left_type(q) != explicit)
            print("??");
          else
            print_two(left_x(q), left_y(q));
          goto done1;
        }
        break;
      case open:
        if ((left_type(p) != explicit) && (left_type(p) != open))
          print("{open?}");
        break;
      case curl:
      case given:
        {
          if (left_type(p) == open)
            print("??");
          if (right_type(p) == curl)
          {
            print("{curl ");
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
        print("???");
        break;
    }
    if (left_type(q) <= explicit)
      print("..control?");
    else if ((right_tension(p) != unity) || (left_tension(q) != unity))
    {
      print("..tension ");
      if (right_tension(p) < 0)
        print("atleast");
      print_scaled(abs(right_tension(p)));
      if (right_tension(p) != left_tension(q))
      {
        print(" and ");
        if (left_tension(q) < 0)
          print("atleast");
        print_scaled(abs(left_tension(q)));
      }
    }
done1:
    p = q;
    if ((p != h) || (left_type(h) != endpoint))
    {
      print_nl(" ..");
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
        print("{curl ");
        print_scaled(left_curl(p));
        print_char('}');
      }
    }
  } while (!(p == h));
  if (left_type(h) != endpoint)
    print("cycle");
done:
  end_diagnostic(true);
}
/* 333 */
void print_weight (pointer q, integer x_off)
{
  integer w, m;
  integer d;

  d = info(q);
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
    if ((q > _void) || (r != mem_top))
    {
      print_nl("row ");
      print_int(n + y_off);
      print_char(':');
      while (q > _void)
      {
        print_weight(q, x_off);
        q = mem[q].hh.rh;
      }
      print(" |");
      while (r != mem_top)
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
        ww = knile(w);
      if ((x_coord(ww) != x_coord(w)) || (y_coord(ww) != y_coord(w)))
      {
        if (nothing_printed)
          nothing_printed = false;
        else
          print_nl(" .. ");
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
  print_nl(" .. cycle");
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
        {
          if (p != pp)
            print_char('+');
        }
        print_scaled(value(p));
      }
      goto lab_exit;
    }
    if (value(p) < 0)
      print_char('-');
    else if (p != pp)
      print_char('+');
    if (t == 17)
      v = round_fraction (v);
    if (v != unity)
      print_scaled(v);
    if (type(q) != independent)
      confusion("dep");
    print_variable_name(q);
    v = value(q) % s_scale;
    while (v > 0)
    {
      print("*4");
      v = v - 2;
    }
    p = link(p);
  }
  lab_exit:;
}
/* 805 */
void print_dp (small_number t, pointer p, small_number verbosity)
{
  pointer q;

  q = link(p);
  if ((info(q) == null) || (verbosity > 0))
    print_dependency(p, t);
  else
    print("linearform");
}
/* 799 */
halfword stash_cur_exp (void)
{
  pointer Result;
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
        p = get_node (value_node_size);
        name_type(p) = capsule;
        type(p) = cur_type;
        value(p) = cur_exp;
      }
      break;
  }
  cur_type = vacuous;
  link(p) = _void;
  Result = p;
  return Result;
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
        free_node (p, value_node_size);
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
      print("vacuous");
      break;
    case boolean_type:
      if (v == true_code)
        print("true");
      else
        print("false");
      break;
    case unknown_types:
    case numeric_type:
      {
        print_type (t);
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
        {
          if (internal[tracing_online] <= 0)
          {
            selector = term_only;
            print_type(t);
            print(" (see the transcript file)");
            selector = term_and_log;
          }
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
    unstash_cur_exp (p);
}
/* 807 */
void disp_err (halfword p, str_number s)
{
  if (interaction == error_stop_mode)
    wake_up_terminal();
  print_nl(">> ");
  print_exp(p, 1);
  if (s != "")
  {
    print_nl("! ");
    print(s);
  }
}
/* 594 */
halfword p_plus_fq(pointer p, integer f, pointer q, small_number t, small_number tt)
{
  pointer Result;
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
    {
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
              type(qq) = 0;
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
            type(qq) = null;
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
  Result = link(temp_head);
  return Result;
}
/* 600 */
pointer p_over_v (pointer p, scaled v, small_number t0, small_number t1)
{
  pointer Result;
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
    {
      if (abs(v) < 02000000)
        w = make_scaled(value(p), v * 010000);
      else
        w = make_scaled(round_fraction(value(p)), v);
    }
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
  Result = link(temp_head);
  return Result;
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
void make_known (halfword p, halfword q)
{
  unsigned char t;

  prev_dep(link(q)) = prev_dep(p);
  link(prev_dep(p)) = link(q);
  t = type(p);
  type(p) = known;
  value(p) = value(q);
  free_node (q, dep_node_size);
  if (abs(value(p)) >= fraction_one)
    val_too_big(value(p));
  if (internal[tracing_equations] > 0)
  {
    if (interesting(p))
    {
      begin_diagnostic();
      print_nl("#### ");
      print_variable_name(p);
      print_char('=');
      print_scaled(value(p));
      end_diagnostic (false);
    }
  }
  if (cur_exp == p)
  {
    if (cur_type == t)
    {
      cur_type = known;
      cur_exp = value(p);
      free_node(p, value_node_size);
    }
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
          free_node (q, dep_node_size);
          q = r;
        }
      }
      r = q;
    }
done:;
    r = link(q);
    if (q == dep_list(t))
      make_known (t, q);
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
  {
    if (q != p)
    {
      while (value(q) != p)
        q = value(q);
      value(q) = value(p);
    }
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
          recycle_value (q);
        } while (!(q == v));
        free_node (v, big_node_size[t]);
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
        max_link[dependent] = 0;
        max_link[proto_dependent] = 0;
        q = link(dep_head);
        while (q != dep_head)
        {
          s = value(q);
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
          link(r) = s;
          prev_dep(q) = prev_dep(pp);
          link(prev_dep(pp)) = q;
          new_indep(pp);
          if (cur_exp == pp)
          {
            if (cur_type == t)
              cur_type = independent;
          }
          if (internal[tracing_online] > 0)
          {
            if (interesting(p))
            {
              begin_diagnostic();
              print_nl("### ");
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
                print("*4");
                value(p) = value(p) - 2;
              }
              if (t == dependent)
                print_char('=');
              else
                print(" = ");
              print_dependency(s, t);
              end_diagnostic(false);
            }
          }
          t = dependent + proto_dependent - t;
          if (max_c[t] > 0)
          {
            link(max_ptr[t]) = max_link[t];
            max_link[t] = max_ptr[t];
          }
          if (t != dependent)
          {
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
          }
          else
          {
            for (t = dependent; t <= proto_dependent; t++)
            {
              r = max_link[t];
              while (r != null)
              {
                q = info(r);
                if (t == dependent)
                {
                  if (cur_exp == q)
                  {
                    if (cur_type == dependent)
                      cur_type = proto_dependent;
                  }
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
      goto lab_exit;
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
        {
          if (type(q) == structured)
            r = q;
          else
          {
            link(r) = link(q);
            free_node(q, subscr_node_size);
          }
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
      goto lab_exit;
  }
  if (discard_suffixes)
    flush_below_variable(p);
  else
  {
    if (type(p) == structured)
      p = attr_head(p);
    recycle_value(p);
  }
lab_exit:;
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
        print_nl("{restoring ");
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
        print_nl("restoring");
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
  pointer Result;
  pointer q;
  unsigned char k;

  q = get_node(knot_node_size);
  for (k = 0; k <= knot_node_size - 1; k++)
  {
    mem[q + k] = mem[p + k];
  }
  Result = q;
  return Result;
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
      goto lab_exit;
    }
    link(qq) = get_node(knot_node_size);
    qq = link(qq);
    pp = link(pp);
  }
lab_exit:;
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
      goto lab_exit;
    }
    rr = get_node(knot_node_size);
    link(rr) = qq;
    qq = rr;
    pp = link(pp);
  }
lab_exit:;
  return Result;
}
/* 296 */
fraction curl_ratio (scaled gamma, scaled a_tension, scaled b_tension)
{
  fraction Result;
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
    Result = fraction_four;
  else
    Result = make_fraction(num, denom);
  return Result;
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
  {
    if (((st >= 0) && (sf >= 0)) || ((st <= 0) && (sf <= 0)))
    {
      sine = take_fraction(abs(st), cf) + take_fraction(abs(sf), ct);
      if (sine > 0)
      {
        sine = take_fraction(sine, fraction_one + unity);
        if (right_tension(p) < 0)
        {
          if (ab_vs_cd(abs(sf), fraction_one, rr, sine) < 0)
            rr = make_fraction(abs(sf), sine);
        }
        if (left_tension(q) < 0)
        {
          if (ab_vs_cd(abs(st), fraction_one, ss, sine) < 0)
            ss = make_fraction(abs(st), sine);
        }
      }
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
            goto lab_exit;
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
              mem[p + 5].cint = x_coord(p) + take_fraction(delta_x[0], ff);
              mem[p + 6].cint = y_coord(p) + take_fraction(delta_y[0], ff);
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
            goto lab_exit;
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
            {
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
              {
                vv[k] = vv[k] + take_fraction(aa, ww[k]);
              }
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
  {
    theta[k] = vv[k] - take_fraction (theta[k + 1], uu[k]);
  }
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
lab_exit:;
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
    print_path (knots, ", before choices", true);
  p = knots;
  do {
    q = link(p);
    if (x_coord(p) == x_coord(q))
    {
      if (y_coord(p) == y_coord(q))
      {
        if (right_type(p) > explicit)
        {
          right_type(p) = explicit;
          if (left_type(p) == open)
          {
            left_type(p) = curl;
            left_curl(p) = unity;
          }
          left_type(q) = 1;
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
      }
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
          psi[k] = n_arg(take_fraction (delta_x[k], cosine) +
            take_fraction(delta_y[k], sine), take_fraction(delta_y[k], cosine) - take_fraction (delta_x[k], sine));
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
    print_path (knots, ", after choices", true);
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
  lab_continue:
    if (m == 0)
    {
      while (n > 0)
      {
        incr(move_ptr);
        move[move_ptr] = 1;
        decr(n);
      }
    }
    else if (n == 0)
    {
      move[move_ptr] = move[move_ptr] + m;
    }
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
        {
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
      goto lab_continue;
    }
    if (bisect_ptr == 0)
      goto lab_exit;
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
lab_exit:;
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
      {
        if (a > aa)
        {
          if (aaa >= aa)
          {
            if (a >= move[k + 1])
            {
              incr(move[k - 1]);
              move[k] = a - 1;
            }
          }
        }
        else
        {
          if (aaa <= aa)
          {
            if (a <= move[k + 1])
            {
              decr(move[k - 1]);
              move[k] = a + 1;
            }
          }
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
  integer temp;
  pointer p, q;

  ml = ml + zero_field;
  mr = mr + zero_field;
  nl = nl + zero_field;
  nr = nr + zero_field;
  if (ml < m_min(cur_edges))
    m_min(cur_edges) = ml;
  if (mr > m_max(cur_edges))
    m_max(cur_edges) = mr;
  temp = m_offset(cur_edges) - zero_field;
  if (!valid_range(m_min(cur_edges) + m_offset(cur_edges) - zero_field) ||
    !valid_range(m_max(cur_edges) + m_offset(cur_edges) - zero_field))
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
halfword copy_edges (pointer h)
{
  pointer Result;
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
  Result = hh;
  return Result;
}
/* 336 */
void y_reflect_edges (void)
{
  pointer p, q, r;

  p = n_min(cur_edges);
  n_min(cur_edges) = zero_field + zero_field - 1 - n_max(cur_edges);
  n_max(cur_edges) = zero_field + zero_field - 1 - p;
  n_pos(cur_edges) = zero_field + zero_field - 1 - n_pos(cur_edges);
  p = link(cur_edges); q = cur_edges; //{we assume that |p<>q|}
  do {
    r = link(p); link(p) = q; knil(q) = p; q = p; p = r;
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
    q = sorted(p); r = sentinel;
    while (q != sentinel)
    {
      s = link(q); link(q) = r; r = q; info(r) = m - info(q); q = s;
    }
    sorted(p) = r;
    q = unsorted(p);
    while (q > _void)
    {
      info(q) = m - info(q); q = link(q);
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

  if ((s*(n_max(cur_edges) + 1 - zero_field) >= 4096) ||
    (s*(n_min(cur_edges) - zero_field) <= -4096))
  {
    print_err("Scaled picture would be too big");
    help3("I can't yscale the picture as requested---it would",
      "make some coordinates too large or too small.",
      "Proceed, and I'll omit the transformation.");
    put_get_error();
  }
  else
  {
    n_max(cur_edges) = s*(n_max(cur_edges) + 1 - zero_field) - 1 + zero_field;
    n_min(cur_edges) = s*(n_min(cur_edges) - zero_field) + zero_field;
    p = cur_edges;
    do {
      q = p; p = link(p);
      for (t = 2; t <= s; t++)
      {
        pp = get_node(row_node_size); link(q) = pp; knil(p) = pp;
        link(pp) = p; knil(pp) = q; q = pp;
        r = sorted(p); rr = sorted_loc(pp);
        while (r != sentinel)
        {
          ss = get_avail(); link(rr) = ss; rr = ss; info(rr) = info(r);
          r = link(r);
        }
        link(rr) = sentinel;
        r = unsorted(p); rr = temp_head;
        while (r > _void)
        {
          ss = get_avail; link(rr) = ss; rr = ss; info(rr) = info(r);
          r = link(r);
        }
        link(rr) = r; unsorted(pp) = link(temp_head);
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

  if ((s * (m_max(cur_edges) - zero_field) >= 4096) ||
    (s * (m_min(cur_edges) - zero_field) <= -4096))
  {
    print_err("Scaled picture would be too big");
    help3("I can't xscale the picture as requested---it would", 
      "make some coordinates too large or too small.",
      "Proceed, and I'll omit the transformation.");
    put_get_error();
  }
  else if ((m_max(cur_edges) != zero_field) || (m_min(cur_edges) != zero_field))
  {
    m_max(cur_edges) = s*(m_max(cur_edges) - zero_field) + zero_field;
    m_min(cur_edges) = s*(m_min(cur_edges) - zero_field) + zero_field;
    delta = 8 * (zero_field - s*m_offset(cur_edges)) + min_halfword;
    m_offset(cur_edges) = zero_field;
    q = link(cur_edges);
    do {
      p = sorted(q);
      while (p != sentinel)
      {
        t = ho(info(p)); w = t % 8; info(p) = (t - w) * s + w + delta; p = link(p);
      }
      p = unsorted(q);
      while (p > _void)
      {
        t = ho(info(p)); w = t % 8; info(p) = (t - w) * s + w + delta; p = link(p);
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
      info(q) = 8 - 2 * ((ho(info(q))) % 8) + info(q); q = link(q);
    }
    q = sorted(p);
    if (q != sentinel)
    {
      do {
        info(q) = 8 - 2 * ((ho(info(q))) % 8) + info(q); q = link(q);
      } while (!(q == sentinel));
      u = sorted_loc(p); q = link(u); r = q; s = link(r);
      while (true)
      {
        if (info(s) > info(r))
        {
          link(u) = q;
          if (s == sentinel)
            goto done;
          u = r; q = s; r = q; s = link(r);
        }
        else
        {
          t = s; s = link(t); link(t) = q; q = t;
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

  r = unsorted(h); unsorted(h) = null;
  p = link(r); link(r) = sentinel; link(temp_head) = r;
  while (p > _void)
  {
    k = info(p); q = temp_head;
    do {
      r = q; q = link(r);
    } while (!(k <= info(q)));
    link(r) = p; r = link(p); link(p) = q; p = r;
  }
  {
    r = sorted_loc(h); q = link(r); p = link(temp_head);
    while (true)
    {
      k = info(p);
      while (k > info(q))
      {
        r = q; q = link(r);
      }
      link(r) = p; s = link(p); link(p) = q;
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

  min_d = max_halfword; max_d = min_halfword;
  min_n = max_halfword; max_n = min_halfword;
  p = link(cur_edges); n = n_min(cur_edges);
  while (p != cur_edges)
  {
    if (unsorted(p) > _void)
      sort_edges(p);
    if (sorted(p) != sentinel)
    {
      r = temp_head; q = sorted(p); ww = 0; m = 1000000; prev_w = 0;
      while (true)
      {
        if (q == sentinel)
          mm = 1000000;
        else
        {
          d = ho(info(q)); mm = d / 8; ww = ww + (d % 8) - zero_w;
        }
        if (mm > m)
        {
          if (w != prev_w)
          {
            s = get_avail(); link(r) = s;
            info(s) = 8 * m + min_halfword + zero_w + w - prev_w;
            r = s; prev_w = w;
          }
          if (q == sentinel)
            goto done;
        }
        m = mm;
        if (ww >= w_lo)
        {
          if (ww <= w_hi)
            w = w_in;
          else
            w = w_out;
        }
        else
          w = w_out;
        s = link(q); free_avail(q); q = s;
      }
    done:
      link(r) = sentinel; sorted(p) = link(temp_head);
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
    p = link(p); incr(n);
  }
  if (min_n > max_n)
  {
    p = link(cur_edges);
    while (p != cur_edges)
    {
      q = link(p); free_node(p, row_node_size); p = q;
    }
    init_edges(cur_edges);
  }
  else
  {
    n = n_min(cur_edges); n_min(cur_edges) = min_n;
    while (min_n > n)
    {
      p = link(cur_edges); link(cur_edges) = link(p);
      knil(link(p)) = cur_edges;
      free_node(p, row_node_size); incr(n);
    }
    n = n_max(cur_edges); n_max(cur_edges) = max_n;
    n_pos(cur_edges) = max_n + 1; n_rover(cur_edges) = cur_edges;
    while (max_n < n)
    {
      p = knil(cur_edges); knil(cur_edges) = knil(p);
      link(knil(p)) = cur_edges;
      free_node(p, row_node_size); decr(n);
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
  {
    move[j] = mem_top;
  }
  p = get_node(row_node_size); sorted(p) = sentinel; unsorted(p) = null;
  knil(p) = cur_edges; knil(link(cur_edges)) = p; //{the new bottom row}
  p = get_node(row_node_size); sorted(p) = sentinel;
  knil(p) = knil(cur_edges); //{the new top row}
  m_magic = m_min(cur_edges) + m_offset(cur_edges) - zero_field;
  n_magic = 8 * n_max(cur_edges) + 8 + zero_w + min_halfword;
  do {
    q = knil(p);
    if (unsorted(q) > _void)
     sort_edges(q);
    r = sorted(p); free_node(p, row_node_size); p = r;
    pd = ho(info(p)); pm = pd / 8;
    r = sorted(q); rd = ho(info(r)); rm = rd / 8; w = 0;
    while (true)
    {
      if (pm < rm)
        mm = pm;
      else
        mm = rm;
      if (w != 0)
      {
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
              s = get_avail; info(s) = n_magic + xw;
              link(s) = move[j]; move[j] = s;
            }
            s = get_avail; info(s) = n_magic + ww;
            link(s) = move[j]; move[j] = s;
            incr(m);
          } while (!(m == mm));
        }
      }
      if (pd < rd)
      {
        s = link(p); free_avail(p); p = s; pd = ho(info(p)); pm = pd / 8;
      }
      else
      {
        if (r == sentinel)
          goto done;
        dw = -((rd % 8) - zero_w);
        r = link(r); rd = ho(info(r)); rm = rd / 8;
      }
      m = mm;
      w = w + dw;
    }
    done:;
    p = q;
    n_magic = n_magic - 8;
  } while (!(knil(p) == cur_edges));
  free_node(p, row_node_size);
  move[m_spread] = 0; j = 0;
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
    n_min(cur_edges) = j + mm; n_max(cur_edges) = jj + mm; q = cur_edges;
    do {
      p = get_node(row_node_size); link(q) = p; knil(p) = q;
      sorted(p) = move[j]; unsorted(p) = null; incr(j); q = p;
    } while (!(j > jj));
    link(q) = cur_edges; knil(cur_edges) = q;
    n_pos(cur_edges) = n_max(cur_edges) + 1; n_rover(cur_edges) = cur_edges;
    last_window_time(cur_edges) = 0;
  }
}
/* 366 */
void merge_edges (halfword h)
{
  pointer p, q, r, pp, qq, rr;
  integer n;
  halfword k;
  integer delta;

  if (link(h) != h)
  {
    if ((m_min(h)<m_min(cur_edges)) || (m_max(h)>m_max(cur_edges)) ||
      (n_min(h)<n_min(cur_edges)) || (n_max(h)>n_max(cur_edges)))
      edge_prep(m_min(h) - zero_field, m_max(h) - zero_field,
        n_min(h) - zero_field, n_max(h) - zero_field + 1);
    if (m_offset(h) != m_offset(cur_edges))
    {
      pp = link(h); delta = 8 * (m_offset(cur_edges) - m_offset(h));
      do {
        qq = sorted(pp);
        while (qq != sentinel)
        {
          info(qq) = info(qq) + delta; qq = link(qq);
        }
        qq = unsorted(pp);
        while (qq > _void)
        {
          info(qq) = info(qq) + delta; qq = link(qq);
        }
        pp = link(pp);
      } while (!(pp == h));
    }
    n = n_min(cur_edges); p = link(cur_edges); pp = link(h);
    while (n < n_min(h))
    {
      incr(n); p = link(p);
    }
    do {
      qq = unsorted(pp);
      if (qq > _void)
      {
        if (unsorted(p) <= _void)
          unsorted(p) = qq;
        else
        {
          while (link(qq) > _void)
            qq = link(qq);
          link(qq) = unsorted(p); unsorted(p) = unsorted(pp);
        }
      }
      unsorted(pp) = null; qq = sorted(pp);
      if (qq != sentinel)
      {
        if (unsorted(p) == _void)
          unsorted(p) = null;
        sorted(pp) = sentinel; r = sorted_loc(p); q = link(r);
        if (q == sentinel)
          sorted(p) = qq;
        else
          while (true)
          {
            k = info(qq);
            while (k > info(q))
            {
              r = q; q = link(r);
            }
            link(r) = qq; rr = link(qq); link(qq) = q;
            if (rr == sentinel)
              goto done;
            r = qq;
            qq = rr;
          }
      }
    done:;
      pp = link(pp); p = link(p);
    } while (!(pp == h));
  }
}
/* 369 */
integer total_weight (pointer h)
{
  integer Result;
  pointer p, q;
  integer n;
  unsigned short m;

  n = 0; p = link(h);
  while (p != h)
  {
    q = sorted(p);
    while (q != sentinel)
    {
      m = ho(info(q)); n = n - ((m % 8) - zero_w)*(m / 8);
      q = link(q);
    }
    q = unsorted(p);
    while (q > 1)
    {
      m = ho(info(q)); n = n - ((m % 8) - zero_w)*(m / 8);
      q = link(q);
    }
    p = link(p);
  }
  Result = n;
  return Result;
}
/* 654 */
void begin_edge_tracing (void)
{
  print_diagnostic("Tracing edges", "", true);
  print(" (weight ");
  print_int(cur_wt);
  print_char(')');
  trace_x = -4096;
}
/* 372 */
void trace_a_corner (void)
{
  if (file_offset > max_print_line - 13)
    print_nl(261);
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
    print_nl("(No new edges added.)");
  else
  {
    trace_a_corner();
    print_char('.');
  }
  end_diagnostic(true);
}
/* 273 */
void trace_new_edge (pointer r, integer n)
{
  integer d;
  int8_t w;
  integer m, n0, n1;

  d = ho(info(r)); w = (d % 8) - zero_w; m = (d / 8) - m_offset(cur_edges);
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
      print_nl("");
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
      n = n_pos(cur_edges) - zero_field; p = n_rover(cur_edges);
      if (n != n0)
      {
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
      }
      y0 = unity - y0;
      while (true)
      {
        r = get_avail(); link(r) = unsorted(p); unsorted(p) = r;
        tx = take_fraction(delx, make_fraction(y0, dely));
        if (ab_vs_cd(delx, y0, dely, tx) < 0)
          decr(tx);
        info(r) = 8 * round_unscaled(x0 + tx) + base;
        y1 = y1 - unity;
        if (internal[tracing_edges] > 0)
          trace_new_edge(r, n);
        if (y1 < unity)
          goto done;
        p = link(p); y0 = y0 + unity; incr(n);
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
      n = n_pos(cur_edges) - zero_field; p = n_rover(cur_edges);
      if (n != n0)
      {
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
      }
      while (true)
      {
        r = get_avail(); link(r) = unsorted(p); unsorted(p) = r;
        tx = take_fraction(delx, make_fraction(y0, dely));
        if (ab_vs_cd(delx, y0, dely, tx) < 0)
          incr(tx);
        info(r) = 8 * round_unscaled(x0 - tx) + base;
        y1 = y1 + unity;
        if (internal[tracing_edges] > 0)
          trace_new_edge(r, n);
        if (y1 >= 0)
          goto done1;
        p = knil(p); y0 = y0 + unity; decr(n);
      }
      done1:;
    }
    n_rover(cur_edges) = p; n_pos(cur_edges) = n + zero_field;
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
#ifdef TEXMF_DEBUG
  integer sum;
#endif /* TEXMF_DEBUG */

  delta = n1 - n0;
#ifdef TEXMF_DEBUG
  sum = move[0];
  for (k = 1; k <= delta; k++)
  {
    sum = sum + abs(move[k]);
  }
  if (sum != m1 - m0)
    confusion("0");
#endif /* TEXMF_DEBUG */
  switch (octant)
  {
    case first_octant:
      {
        dx = 8; edge_prep(m0, m1, n0, n1); goto fast_case_up;
      }
      break;
    case second_octant:
      {
        dx = 8; edge_prep(n0, n1, m0, m1); goto slow_case_up;
      }
      break;
    case third_octant:
      {
        dx = -8; edge_prep(-n1, -n0, m0, m1); negate(n0);
        goto slow_case_up;
      }
      break;
    case fourth_octant:
      {
        dx = -8; edge_prep(-m1, -m0, n0, n1); negate(m0);
        goto fast_case_up;
      }
      break;
    case fifth_octant:
      {
        dx = -8; edge_prep(-m1, -m0, -n1, -n0); negate(m0);
        goto fast_case_down;
      }
      break;
    case sixth_octant:
      {
        dx = -8; edge_prep(-n1, -n0, -m1, -m0); negate(n0);
        goto slow_case_down;
      }
      break;
    case seventh_octant:
      {
        dx = 8; edge_prep(n0, n1, -m1, -m0); goto slow_case_down;
      }
      break;
    case eighth_octant:
      {
        dx = 8; edge_prep(m0, m1, -n1, -n0); goto fast_case_down;
      }
      break;
  }
fast_case_up:
  n = n_pos(cur_edges) - zero_field; p = n_rover(cur_edges);
  if (n != n0)
  {
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
  }
  if (delta > 0)
  {
    k = 0;
    edge_and_weight = 8 * (m0 + m_offset(cur_edges)) + min_halfword + zero_w - cur_wt;
    do {
      edge_and_weight = edge_and_weight + dx*move[k];
      fast_get_avail(r); link(r) = unsorted(p); info(r) = edge_and_weight;
      if (internal[tracing_edges] > 0)
        trace_new_edge(r, n);
      unsorted(p) = r; p = link(p); incr(k); incr(n);
    } while (!(k == delta));
  }
  goto done;
fast_case_down:
  n0 = -n0 - 1;
  n = n_pos(cur_edges) - zero_field; p = n_rover(cur_edges);
  if (n != n0)
  {
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
  }
  if (delta > 0)
  {
    k = 0;
    edge_and_weight = 8 * (m0 + m_offset(cur_edges)) + min_halfword + zero_w + cur_wt;
    do {
      edge_and_weight = edge_and_weight + dx*move[k];
      fast_get_avail(r); link(r) = unsorted(p); info(r) = edge_and_weight;
      if (internal[tracing_edges] > 0)
        trace_new_edge(r, n);
      unsorted(p) = r; p = knil(p); incr(k); decr(n);
    } while (!(k == delta));
  }
  goto done;
slow_case_up:
  edge_and_weight = 8 * (n0 + m_offset(cur_edges)) + min_halfword + zero_w - cur_wt;
  n0 = m0; k = 0;
  n = n_pos(cur_edges) - zero_field; p = n_rover(cur_edges);
  if (n != n0)
  {
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
  }
  do {
    j = move[k];
    while (j > 0)
    {
      fast_get_avail(r); link(r) = unsorted(p); info(r) = edge_and_weight;
      if (internal[tracing_edges] > 0)
        trace_new_edge(r, n);
      unsorted(p) = r; p = link(p); decr(j); incr(n);
    }
    edge_and_weight = edge_and_weight + dx; incr(k);
  } while (!(k > delta));
  goto done;
slow_case_down:
  edge_and_weight = 8 * (n0 + m_offset(cur_edges)) + min_halfword + zero_w + cur_wt;
  n0 = -m0 - 1; k = 0;
  n = n_pos(cur_edges) - zero_field; p = n_rover(cur_edges);
  if (n != n0)
  {
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
  }
  do {
    j = move[k];
    while (j > 0)
    {
      fast_get_avail(r); link(r) = unsorted(p); info(r) = edge_and_weight;
      if (internal[tracing_edges] > 0)
        trace_new_edge(r, n);
      unsorted(p) = r; p = knil(p); decr(j); decr(n);
    }
    edge_and_weight = edge_and_weight + dx; incr(k);
  } while (!(k > delta));
  goto done;
done:
  n_pos(cur_edges) = n + zero_field; n_rover(cur_edges) = p;
}
/* 387 */
void skew (scaled x, scaled y, small_number octant)
{
  switch (octant)
  {
    case first_octant: set_two(x - y, y); break;
    case second_octant: set_two(y - x, x); break;
    case third_octant: set_two(y + x, -x); break;
    case fourth_octant: set_two(-x - y, y); break;
    case fifth_octant: set_two(-x + y, -y); break;
    case sixth_octant: set_two(-y + x, -x); break;
    case seventh_octant: set_two(-y - x, x); break;
    case eighth_octant: set_two(x + y, -y); break;
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
    {
      if (c > 0)
        no_crossing();
      else if ((a == 0) && (b == 0))
        no_crossing();
      else
        one_crossing();
    }
    if (a == 0)
      zero_crossing();
  }
  else if (a == 0)
  {
    if (b <= 0)
      zero_crossing();
  }
  d = 1; x0 = a; x1 = a - b; x2 = b - c;
  do {
    x = half(x1 + x2);
    if (x1 - x0 > x0)
    {
      x2 = x; _double(x0); _double(d);
    }
    else
    {
      xx = x1 + x - x0;
      if (xx > x0)
      {
        x2 = x; _double(x0); _double(d);
      }
      else
      {
        x0 = x0 - xx;
        if (x <= x0)
        {
          if (x + x2 <= x0)
            no_crossing();
        }
        x1 = x;
        d = d + d + 1;
      }
    }
  } while (!(d >= fraction_one));
  Result = d - fraction_one;
lab_exit:;
  return Result;
}
/* 394 */
void print_spec (str_number s)
{
  pointer p, q;
  small_number octant;

  print_diagnostic("Cycle spec", s, true);
  p = cur_spec; octant = left_octant(p); print_ln();
  print_two_true(x_coord(cur_spec), y_coord(cur_spec));
  print(" % beginning in octant `");
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
        print_nl("   ..controls ");
        print_two_true(right_x(p), right_y(p));
        print(" and ");
        print_two_true(left_x(q), left_y(q));
        print_nl(" ..");
        print_two_true(x_coord(q), y_coord(q));
        print(" % segment "); print_int(left_type(q) - 1);
      }
      p = q;
    }
  not_found:
    if (q == cur_spec)
      goto done;
    p = q; octant = left_octant(p); print_nl("% entering octant `");
  }
done:
  print_nl(" & cycle"); end_diagnostic(true);
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
  print_nl(">");
  p = cur_spec; t = max_quarterword + 1;
  do {
    p = link(p);
    if (left_type(p) != endpoint)
    {
      if (left_type(p) < t)
        f = p;
      t = left_type(p);
    }
  } while (!(p == cur_spec));
  p = cur_spec; q = p;
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
        t = left_type(p); print_char(" "); print_int(t - 1);
      }
      if (q != null)
      {
        if (left_type(link(q)) == endpoint)
        {
          print(" ("); print(octant_dir[left_octant(q)]); q = link(q);
          while (left_type(link(q)) == endpoint)
          {
            print_char(" "); print(octant_dir[left_octant(q)]); q = link(q);
          }
          print_char(')');
        }
        print_char(" "); print(octant_dir[left_octant(q)]); q = null;
      }
    }
    else if (q == null)
      q = p;
    p = link(p);
  } while (!(p == f));
  print_char(" "); print_int(left_type(p) - 1);
  if (q != null)
  {
    if (left_type(link(q)) == endpoint)
    {
      print(" ("); print(octant_dir[left_octant(q)]); q = link(q);
      while (left_type(link(q)) == endpoint)
      {
        print_char(" "); print(octant_dir[left_octant(q)]); q = link(q);
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

  q = link(p); right_type(p) = right_type(q); link(p) = link(q);
  x_coord(p) = x_coord(q); y_coord(p) = y_coord(q);
  right_x(p) = right_x(q); right_y(p) = right_y(q);
  free_node(q, knot_node_size);
}
/* 410 */
void split_cubic (pointer p, fraction t, scaled xq, scaled yq)
{
  scaled v;
  pointer q, r;

  q = link(p); r = get_node(knot_node_size); link(p) = r; link(r) = q;
  left_type(r) = left_type(q); right_type(r) = right_type(p);
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
  scaled destx, desty;
  boolean constantx;

  p = cur_spec; first_x = x_coord(cur_spec); first_y = y_coord(cur_spec);
  do {
lab_continue:
    q = mem[p].hh.rh;
    if (q == cur_spec)
    {
      destx = first_x;
      desty = first_y;
    }
    else
    {
      destx = mem[q + 1].cint;
      desty = mem[q + 2].cint;
    }
    del1 = mem[p + 5].cint - mem[p + 1].cint;
    del2 = mem[q + 3].cint - mem[p + 5].cint;
    del3 = destx - mem[q + 3].cint;
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
        dmax = dmax + dmax;
        del1 = del1 + del1;
        del2 = del2 + del2;
        del3 = del3 + del3;
      }
    }
    if (del == 0)
      constantx = true;
    else
    {
      constantx = false;
      if (del < 0)
      {
        mem[p + 1].cint = -mem[p + 1].cint;
        mem[p + 5].cint = -mem[p + 5].cint;
        mem[q + 3].cint = -mem[q + 3].cint;
        del1 = -del1;
        del2 = -del2;
        del3 = -del3;
        destx = -destx;
        mem[p].hh.b1 = 2;
      }
      t = crossing_point (del1, del2, del3);
      if (t < fraction_one)
      {
        split_cubic (p, t, destx, desty);
        r = mem[p].hh.rh;
        if (mem[r].hh.b1 > 1)
          mem[r].hh.b1 = 1;
        else
          mem[r].hh.b1 = 2;
        if (mem[r + 1].cint < mem[p + 1].cint)
          mem[r + 1].cint = mem[p + 1].cint;
        mem[r + 3].cint = mem[r + 1].cint;
        if (mem[p + 5].cint > mem[r + 1].cint)
          mem[p + 5].cint = mem[r + 1].cint;
        mem[r + 1].cint = -mem[r + 1].cint;
        mem[r + 5].cint = mem[r + 1].cint;
        mem[q + 3].cint = -mem[q + 3].cint;
        destx = -destx;
        del2 = del2 - take_fraction (del2 - del3, t);
        if (del2 > 0)
          del2 = 0;
        t = crossing_point (0, -del2, -del3);
        if (t < fraction_one)
        {
          split_cubic (r, t, destx, desty);
          s = mem[r].hh.rh;
          if (mem[s + 1].cint < destx)
            mem[s + 1].cint = destx;
          if (mem[s + 1].cint < mem[r + 1].cint)
            mem[s + 1].cint = mem[r + 1].cint;
          mem[s].hh.b1 = mem[p].hh.b1;
          mem[s + 3].cint = mem[s + 1].cint;
          if (mem[q + 3].cint < destx)
            mem[q + 3].cint = -destx;
          else if (mem[q + 3].cint > mem[s + 1].cint)
            mem[q + 3].cint = -mem[s + 1].cint;
          else mem[q + 3].cint = -mem[q + 3].cint;
            mem[s + 1].cint = -mem[s + 1].cint;
          mem[s + 5].cint = mem[s + 1].cint;
        }
        else
        {
          if (mem[r + 1].cint > destx)
          {
            mem[r + 1].cint = destx;
            mem[r + 3].cint = -mem[r + 1].cint;
            mem[r + 5].cint = mem[r + 1].cint;
          }
          if (mem[q + 3].cint > destx)
            mem[q + 3].cint = destx;
          else if (mem[q + 3].cint < mem[r + 1].cint)
            mem[q + 3].cint = mem[r + 1].cint;
        }
      }
    }
    pp = p;
    do {
      qq = mem[pp].hh.rh;
      abnegate (mem[qq + 1].cint, mem[qq + 2].cint, mem[qq].hh.b1, mem[pp].hh.b1);
      destx = cur_x;
      desty = cur_y;
      del1 = mem[pp + 6].cint - mem[pp + 2].cint;
      del2 = mem[qq + 4].cint - mem[pp + 6].cint;
      del3 = desty - mem[qq + 4].cint;
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
          dmax = dmax + dmax;
          del1 = del1 + del1;
          del2 = del2 + del2;
          del3 = del3 + del3;
        }
      }
      if (del != 0)
      {
        if (del < 0)
        {
          mem[pp + 2].cint = -mem[pp + 2].cint;
          mem[pp + 6].cint = -mem[pp + 6].cint;
          mem[qq + 4].cint = -mem[qq + 4].cint;
          del1 = -del1;
          del2 = -del2;
          del3 = -del3;
          desty = -desty;
          mem[pp].hh.b1 = mem[pp].hh.b1 + 2;
        }
        t = crossing_point (del1, del2, del3);
        if (t < fraction_one)
        {
          split_cubic (pp, t, destx, desty);
          r = mem[pp].hh.rh;
          if (mem[r].hh.b1 > 2)
            mem[r].hh.b1 = mem[r].hh.b1 - 2;
          else
            mem[r].hh.b1 = mem[r].hh.b1 + 2;
          if (mem[r + 2].cint < mem[pp + 2].cint)
            mem[r + 2].cint = mem[pp + 2].cint;
          mem[r + 4].cint = mem[r + 2].cint;
          if (mem[pp + 6].cint > mem[r + 2].cint)
            mem[pp + 6].cint = mem[r + 2].cint;
          mem[r + 2].cint = -mem[r + 2].cint;
          mem[r + 6].cint = mem[r + 2].cint;
          mem[qq + 4].cint = -mem[qq + 4].cint;
          desty = -desty;
          if (mem[r + 1].cint < mem[pp + 1].cint)
            mem[r + 1].cint = mem[pp + 1].cint;
          else if (mem[r + 1].cint > destx)
            mem[r + 1].cint = destx;
          if (mem[r + 3].cint > mem[r + 1].cint)
          {
            mem[r + 3].cint = mem[r + 1].cint;
            if (mem[pp + 5].cint > mem[r + 1].cint)
              mem[pp + 5].cint = mem[r + 1].cint;
          }
          if (mem[r + 5].cint < mem[r + 1].cint)
          {
            mem[r + 5].cint = mem[r + 1].cint;
            if (mem[qq + 3].cint < mem[r + 1].cint)
              mem[qq + 3].cint = mem[r + 1].cint;
          }
          del2 = del2 - take_fraction (del2 - del3, t);
          if (del2 > 0)
            del2 = 0;
          t = crossing_point (0, -del2, -del3);
          if (t < fraction_one)
          {
            split_cubic (r, t, destx, desty);
            s = mem[r].hh.rh;
            if (mem[s + 2].cint < desty)
              mem[s + 2].cint = desty;
            if (mem[s + 2].cint < mem[r + 2].cint)
              mem[s + 2].cint = mem[r + 2].cint;
            mem[s].hh.b1 = mem[pp].hh.b1;
            mem[s + 4].cint = mem[s + 2].cint;
            if (mem[qq + 4].cint < desty)
              mem[qq + 4].cint = -desty;
            else if (mem[qq + 4].cint > mem[s + 2].cint)
              mem[qq + 4].cint = -mem[s + 2].cint;
            else
              mem[qq + 4].cint = -mem[qq + 4].cint;
            mem[s + 2].cint = -mem[s + 2].cint;
            mem[s + 6].cint = mem[s + 2].cint;
            if (mem[s + 1].cint < mem[r + 1].cint)
              mem[s + 1].cint = mem[r + 1].cint;
            else if (mem[s + 1].cint > destx)
              mem[s + 1].cint = destx;
            if (mem[s + 3].cint > mem[s + 1].cint)
            {
              mem[s + 3].cint = mem[s + 1].cint;
              if (mem[r + 5].cint > mem[s + 1].cint)
                mem[r + 5].cint = mem[s + 1].cint;
            }
            if (mem[s + 5].cint < mem[s + 1].cint)
            {
              mem[s + 5].cint = mem[s + 1].cint;
              if (mem[qq + 3].cint < mem[s + 1].cint)
                mem[qq + 3].cint = mem[s + 1].cint;
            }
          }
          else
          {
            if (mem[r + 2].cint > desty)
            {
              mem[r + 2].cint = desty;
              mem[r + 4].cint = -mem[r + 2].cint;
              mem[r + 6].cint = mem[r + 2].cint;
            }
            if (mem[qq + 4].cint > desty)
              mem[qq + 4].cint = desty;
            else if (mem[qq + 4].cint < mem[r + 2].cint)
              mem[qq + 4].cint = mem[r + 2].cint;
          }
        }
      }
      else if (constantx)
      {
        if (q != p)
        {
          remove_cubic (p);
          if (cur_spec != q)
            goto lab_continue;
          else
          {
            cur_spec = p;
            goto lab_exit;
          }
        }
      }
      else if (!odd(mem[pp].hh.b1))
      {
        mem[pp + 2].cint = -mem[pp + 2].cint;
        mem[pp + 6].cint = -mem[pp + 6].cint;
        mem[qq + 4].cint = -mem[qq + 4].cint;
        del1 = -del1;
        del2 = -del2;
        del3 = -del3;
        desty = -desty;
        mem[pp].hh.b1 = mem[pp].hh.b1 + 2;
      }
      pp = qq;
    } while (!(pp == q));
    if (constantx)
    {
      pp = p;
      do {
        qq = mem[pp].hh.rh;
        if (mem[pp].hh.b1 > 2)
        {
          mem[pp].hh.b1 = mem[pp].hh.b1 + 1;
          mem[pp + 1].cint = -mem[pp + 1].cint;
          mem[pp + 5].cint = -mem[pp + 5].cint;
          mem[qq + 3].cint = -mem[qq + 3].cint;
        }
        pp = qq;
      } while (!(pp == q));
    }
    p = q;
  } while (!(p == cur_spec));
  lab_exit:;
}
/* 419 */
void octant_subdivide (void)
{
  halfword p, q, r, s;
  scaled del1, del2, del3, del, dmax;
  fraction t;
  scaled destx, desty;

  p = cur_spec;
  do {
    q = mem[p].hh.rh;
    mem[p + 1].cint = mem[p + 1].cint - mem[p + 2].cint;
    mem[p + 5].cint = mem[p + 5].cint - mem[p + 6].cint;
    mem[q + 3].cint = mem[q + 3].cint - mem[q + 4].cint;
    if (q == cur_spec)
    {
      unskew (mem[q + 1].cint, mem[q + 2].cint, mem[q].hh.b1);
      skew (cur_x, cur_y, mem[p].hh.b1);
      destx = cur_x;
      desty = cur_y;
    }
    else
    {
      abnegate (mem[q + 1].cint, mem[q + 2].cint, mem[q].hh.b1, mem[p].hh.b1);
      destx = cur_x - cur_y;
      desty = cur_y;
    }
    del1 = mem[p + 5].cint - mem[p + 1].cint;
    del2 = mem[q + 3].cint - mem[p + 5].cint;
    del3 = destx - mem[q + 3].cint;
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
        dmax = dmax + dmax;
        del1 = del1 + del1;
        del2 = del2 + del2;
        del3 = del3 + del3;
      }
    }
    if (del != 0)
    {
      if (del < 0)
      {
        mem[p + 2].cint = mem[p + 1].cint + mem[p + 2].cint;
        mem[p + 1].cint = -mem[p + 1].cint;
        mem[p + 6].cint = mem[p + 5].cint + mem[p + 6].cint;
        mem[p + 5].cint = -mem[p + 5].cint;
        mem[q + 4].cint = mem[q + 3].cint + mem[q + 4].cint;
        mem[q + 3].cint = -mem[q + 3].cint;
        del1 = -del1;
        del2 = -del2;
        del3 = -del3;
        desty = destx + desty;
        destx = -destx;
        mem[p].hh.b1 = mem[p].hh.b1 + 4;
      }
      t = crossing_point (del1, del2, del3);
      if (t < fraction_one)
      {
        split_cubic (p, t, destx, desty);
        r = mem[p].hh.rh;
        if (mem[r].hh.b1 > 4)
          mem[r].hh.b1 = mem[r].hh.b1 - 4;
        else
          mem[r].hh.b1 = mem[r].hh.b1 + 4;
        if (mem[r + 2].cint < mem[p + 2].cint)
          mem[r + 2].cint = mem[p + 2].cint;
        else if (mem[r + 2].cint > desty)
          mem[r + 2].cint = desty;
        if (mem[p + 1].cint + mem[r + 2].cint > destx + desty)
          mem[r + 2].cint = destx + desty - mem[p + 1].cint;
        if (mem[r + 4].cint > mem[r + 2].cint)
        {
          mem[r + 4].cint = mem[r + 2].cint;
          if (mem[p + 6].cint > mem[r + 2].cint)
            mem[p + 6].cint = mem[r + 2].cint;
        }
        if (mem[r + 6].cint < mem[r + 2].cint)
        {
          mem[r + 6].cint = mem[r + 2].cint;
          if (mem[q + 4].cint < mem[r + 2].cint)
            mem[q + 4].cint = mem[r + 2].cint;
        }
        if (mem[r + 1].cint < mem[p + 1].cint)
          mem[r + 1].cint = mem[p + 1].cint;
        else if (mem[r + 1].cint + mem[r + 2].cint > destx + desty)
          mem[r + 1].cint = destx + desty - mem[r + 2].cint;
        mem[r + 3].cint = mem[r + 1].cint;
        if (mem[p + 5].cint > mem[r + 1].cint)
          mem[p + 5].cint = mem[r + 1].cint;
        mem[r + 2].cint = mem[r + 2].cint + mem[r + 1].cint;
        mem[r + 6].cint = mem[r + 6].cint + mem[r + 1].cint;
        mem[r + 1].cint = -mem[r + 1].cint;
        mem[r + 5].cint = mem[r + 1].cint;
        mem[q + 4].cint = mem[q + 4].cint + mem[q + 3].cint;
        mem[q + 3].cint = -mem[q + 3].cint;
        desty = desty + destx;
        destx = -destx;
        if (mem[r + 6].cint < mem[r + 2].cint)
        {
          mem[r + 6].cint = mem[r + 2].cint;
          if (mem[q + 4].cint < mem[r + 2].cint)
            mem[q + 4].cint = mem[r + 2].cint;
        }
        del2 = del2 - take_fraction (del2 - del3, t);
        if (del2 > 0)
          del2 = 0;
        t = crossing_point (0, -del2, -del3);
        if (t < fraction_one)
        {
          split_cubic (r, t, destx, desty);
          s = mem[r].hh.rh;
          if (mem[s + 2].cint < mem[r + 2].cint)
            mem[s + 2].cint = mem[r + 2].cint;
          else if (mem[s + 2].cint > desty)
            mem[s + 2].cint = desty;
          if (mem[r + 1].cint + mem[s + 2].cint > destx + desty)
            mem[s + 2].cint = destx + desty - mem[r + 1].cint;
          if (mem[s + 4].cint > mem[s + 2].cint)
          {
            mem[s + 4].cint = mem[s + 2].cint;
            if (mem[r + 6].cint > mem[s + 2].cint)
              mem[r + 6].cint = mem[s + 2].cint;
          }
          if (mem[s + 6].cint < mem[s + 2].cint)
          {
            mem[s + 6].cint = mem[s + 2].cint;
            if (mem[q + 4].cint < mem[s + 2].cint)
              mem[q + 4].cint = mem[s + 2].cint;
          }
          if (mem[s + 1].cint + mem[s + 2].cint > destx + desty)
            mem[s + 1].cint = destx + desty - mem[s + 2].cint;
          else
          {
            if (mem[s + 1].cint < destx)
              mem[s + 1].cint = destx;
            if (mem[s + 1].cint < mem[r + 1].cint)
              mem[s + 1].cint = mem[r + 1].cint;
          }
          mem[s].hh.b1 = mem[p].hh.b1;
          mem[s + 3].cint = mem[s + 1].cint;
          if (mem[q + 3].cint < destx)
          {
            mem[q + 4].cint = mem[q + 4].cint + destx;
            mem[q + 3].cint = -destx;
          }
          else if (mem[q + 3].cint > mem[s + 1].cint)
          {
            mem[q + 4].cint = mem[q + 4].cint + mem[s + 1].cint;
            mem[q + 3].cint = -mem[s + 1].cint;
          }
          else
          {
            mem[q + 4].cint = mem[q + 4].cint + mem[q + 3].cint;
            mem[q + 3].cint = -mem[q + 3].cint;
          }
          mem[s + 2].cint = mem[s + 2].cint + mem[s + 1].cint;
          mem[s + 6].cint = mem[s + 6].cint + mem[s + 1].cint;
          mem[s + 1].cint = -mem[s + 1].cint;
          mem[s + 5].cint = mem[s + 1].cint;
          if (mem[s + 6].cint < mem[s + 2].cint)
          {
            mem[s + 6].cint = mem[s + 2].cint;
            if (mem[q + 4].cint < mem[s + 2].cint)
              mem[q + 4].cint = mem[s + 2].cint;
          }
        }
        else
        {
          if (mem[r + 1].cint > destx)
          {
            mem[r + 1].cint = destx;
            mem[r + 3].cint = -mem[r + 1].cint;
            mem[r + 5].cint = mem[r + 1].cint;
          }
          if (mem[q + 3].cint > destx)
            mem[q + 3].cint = destx;
          else if (mem[q + 3].cint < mem[r + 1].cint)
            mem[q + 3].cint = mem[r + 1].cint;
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
    after[cur_rounding_ptr] = after[0]; all_safe = true; next_a = after[0];
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
  {
    if (max_rounding_ptr < max_wiggle)
      incr(max_rounding_ptr);
    else
      overflow("rounding table size", max_wiggle);
  }
  after[cur_rounding_ptr] = a;
  before[cur_rounding_ptr] = b;
  node_to_round[cur_rounding_ptr] = p;
  incr(cur_rounding_ptr);
}
/* 431 */
scaled good_val (scaled b, scaled o)
{
  scaled Result;
  scaled a;

  a = b + o;
  if (a >= 0)
    a = a - (a % cur_gran) - o;
  else
    a = a + ((-(a + 1)) % cur_gran) - cur_gran + 1 - o;
  if (b - a < a + cur_gran - b)
    Result = a;
  else
    Result = a + cur_gran;
  return Result;
}
/* 432 */
scaled compromise (scaled u, scaled v)
{
  scaled Result;
  
  Result = half(good_val(u + u, -u - v));
  return Result;
}
/* 433 */
void xy_round (void)
{
  halfword p, q;
  scaled b, a;
  scaled penedge;
  fraction alpha;

  cur_gran = abs(internal[granularity]);
  if (cur_gran == 0)
    cur_gran = unity;
  p = cur_spec;
  cur_rounding_ptr = 0;
  do {
    q = mem[p].hh.rh;
    if (odd(mem[p].hh.b1) != odd(mem[q].hh.b1))
    {
      if (odd(mem[q].hh.b1))
        b = mem[q + 1].cint;
      else
        b = -mem[q + 1].cint;
      if ((abs(mem[q + 1].cint - mem[q + 5].cint) < 655) || (abs(mem[q + 1].cint + mem[q + 3].cint) < 655))
      {
        if (cur_pen == 3)
          penedge = 0;
        else if (cur_path_type == double_path_code)
         penedge = compromise (mem[mem[cur_pen + 5].hh.rh + 2].cint, mem[mem[cur_pen + 7].hh.rh + 2].cint);
        else if (odd(mem[q].hh.b1))
          penedge = mem[mem[cur_pen + 7].hh.rh + 2].cint;
        else
          penedge = mem[mem[cur_pen + 5].hh.rh + 2].cint;
        a = good_val (b, penedge);
      }
      else
        a = b;
      if (abs(a) > max_allowed)
      {
        if (a > 0)
          a = max_allowed;
        else
          a = -max_allowed;
      }
      before_and_after (b, a, q);
    }
    p = q;
  } while (!(p == cur_spec));
  if (cur_rounding_ptr > 0)
  {
    make_safe();
    do {
      decr(cur_rounding_ptr);
      if ((after[cur_rounding_ptr]!= before[cur_rounding_ptr]) || (after[cur_rounding_ptr + 1]!= before[cur_rounding_ptr + 1]))
      {
        p = node_to_round[cur_rounding_ptr];
        if (odd(mem[p].hh.b1))
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
          alpha = make_fraction (after[cur_rounding_ptr + 1] - after[
        cur_rounding_ptr], before[cur_rounding_ptr + 1] - before[
        cur_rounding_ptr]);
        do {
          mem[p + 1].cint = take_fraction (alpha, mem[p + 1].cint - b) + a;
          mem[p + 5].cint = take_fraction (alpha, mem[p + 5].cint - b) + a;
          p = mem[p].hh.rh;
          mem[p + 3].cint = take_fraction (alpha, mem[p + 3].cint - b) + a;
        } while (!(p == node_to_round[cur_rounding_ptr + 1]));
      }
    } while (!(cur_rounding_ptr == 0));
  }
  p = cur_spec;
  cur_rounding_ptr = 0;
  do {
    q = mem[p].hh.rh;
    if ((mem[p].hh.b1 > 2) != (mem[q].hh.b1 > 2))
    {
      if (mem[q].hh.b1 <= 2)
        b = mem[q + 2].cint;
      else
        b = -mem[q + 2].cint;
      if ((abs(mem[q + 2].cint - mem[q + 6].cint) < 655) || (abs(mem[q + 2].cint + mem[q + 4].cint) < 655))
      {
        if (cur_pen == 3)
          penedge = 0;
        else if (cur_path_type == double_path_code)
          penedge = compromise (mem[mem[cur_pen + 2].hh.rh + 2].cint, mem[mem[cur_pen + 1].hh.rh + 2].cint);
        else if (mem[q].hh.b1 <= 2)
          penedge = mem[mem[cur_pen + 1].hh.rh + 2].cint;
        else
          penedge = mem[mem[cur_pen + 2].hh.rh + 2].cint;
        a = good_val (b, penedge);
      }
      else
        a = b;
      if (abs(a) > max_allowed)
      {
        if (a > 0)
          a = max_allowed;
        else
          a = -max_allowed;
      }
      before_and_after (b, a, q);
    }
    p = q;
  } while (!(p == cur_spec));
  if (cur_rounding_ptr > 0)
  {
    make_safe();
    do {
      decr(cur_rounding_ptr);
      if ((after[cur_rounding_ptr]!= before[cur_rounding_ptr]) || (after[cur_rounding_ptr + 1]!= before[cur_rounding_ptr + 1]))
      {
        p = node_to_round[cur_rounding_ptr];
        if (mem[p].hh.b1 <= 2)
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
          alpha = make_fraction (after[cur_rounding_ptr + 1] - after[cur_rounding_ptr], before[cur_rounding_ptr + 1] - before[cur_rounding_ptr]);
        do {
          mem[p + 2].cint = take_fraction (alpha, mem[p + 2].cint - b) + a;
          mem[p + 6].cint = take_fraction (alpha, mem[p + 6].cint - b) + a;
          p = mem[p].hh.rh;
          mem[p + 4].cint = take_fraction (alpha, mem[p + 4].cint - b) + a;
        } while (!(p == node_to_round[cur_rounding_ptr + 1]));
      }
    } while (!(cur_rounding_ptr == 0));
  }
}
/* 440 */
void diag_round (void)
{
  halfword p, q, pp;
  scaled b, a, bb, aa, d, c, dd, cc;
  scaled penedge;
  fraction alpha, beta;
  scaled nexta;
  boolean allsafe;
  integer k;
  scaled first_x, first_y;

  p = cur_spec;
  cur_rounding_ptr = 0;
  do {
    q = mem[p].hh.rh;
    if (mem[p].hh.b1 != mem[q].hh.b1)
    {
      if (mem[q].hh.b1 > 4)
        b = -mem[q + 1].cint;
      else
        b = mem[q + 1].cint;
      if (abs(mem[q].hh.b1 - mem[p].hh.b1) == 4)
      {
        if ((abs(mem[q + 1].cint - mem[q + 5].cint) < 655) || (abs(mem[q + 1].cint + mem[q + 3].cint) < 655))
        {
          if (cur_pen == 3)
            penedge = 0;
          else if (cur_path_type == double_path_code)
            switch (mem[q].hh.b1)
            {
              case 1:
              case 5:
                penedge = compromise (mem[mem[mem[cur_pen + 1].hh.rh].hh.lh + 1].cint, -mem[mem[mem[cur_pen + 4].hh.rh].hh.lh + 1].cint);
                break;
              case 4:
              case 8:
                penedge = -compromise (mem[mem[mem[cur_pen + 1].hh.rh].hh.lh + 1].cint, -mem[mem[mem[cur_pen + 4].hh.rh].hh.lh + 1].cint);
                break;
              case 6:
              case 2:
                penedge = compromise (mem[mem[mem[cur_pen + 2].hh.rh].hh.lh + 1].cint, -mem[mem[mem[cur_pen + 3].hh.rh].hh.lh + 1].cint);
                break;
              case 7:
              case 3:
                penedge = -compromise (mem[mem[mem[cur_pen + 2].hh.rh].hh.lh + 1].cint, -mem[mem[mem[cur_pen + 3].hh.rh].hh.lh + 1].cint);
                break;
            }
            else if (mem[q].hh.b1 <= 4)
              penedge = mem[mem[mem[cur_pen + mem[q].hh.b1].hh.rh].hh.lh + 1].cint;
            else
              penedge = -mem[mem[mem[cur_pen + mem[q].hh.b1].hh.rh].hh.lh + 1].cint;
            if (odd(mem[q].hh.b1))
              a = good_val (b, penedge + half(cur_gran));
            else
              a = good_val (b - 1, penedge + half(cur_gran));
          }
        else
          a = b;
      }
      else
        a = b;
      before_and_after (b, a, q);
    }
    p = q;
  } while (!(p == cur_spec));
  if (cur_rounding_ptr > 0)
  {
    p = node_to_round[0];
    first_x = mem[p + 1].cint;
    first_y = mem[p + 2].cint;
    before[cur_rounding_ptr] = before[0];
    node_to_round[cur_rounding_ptr] = node_to_round[0];
    do {
      after[cur_rounding_ptr] = after[0];
      allsafe = true;
      nexta = after[0];
      for (k = 0; k <= cur_rounding_ptr - 1; k++)
      {
        a = nexta;
        b = before[k];
        nexta = after[k + 1];
        aa = nexta;
        bb = before[k + 1];
        if ((a != b) || (aa != bb))
        {
          p = node_to_round[k];
          pp = node_to_round[k + 1];
          if (aa == bb)
          {
            if (pp == node_to_round[0])
              unskew (first_x, first_y, mem[pp].hh.b1);
            else
              unskew (mem[pp + 1].cint, mem[pp + 2].cint, mem[pp].hh.b1);
            skew (cur_x, cur_y, mem[p].hh.b1);
            bb = cur_x;
            aa = bb;
            dd = cur_y;
            cc = dd;
            if (mem[p].hh.b1 > 4)
            {
              b = -b;
              a = -a;
            }
          }
          else
          {
            if (mem[p].hh.b1 > 4)
            {
              bb = -bb;
              aa = -aa;
              b = -b;
              a = -a;
            }
            if (pp == node_to_round[0])
              dd = first_y - bb;
            else
              dd = mem[pp + 2].cint - bb;
            if (odd(aa - bb))
            {
              if (mem[p].hh.b1 > 4)
                cc = dd - half(aa - bb + 1);
              else
                cc = dd - half(aa - bb - 1);
            }
            else
              cc = dd - half(aa - bb);
          }
          d = mem[p + 2].cint;
          if (odd(a - b))
          {
            if (mem[p].hh.b1 > 4)
              c = d - half(a - b - 1);
            else
              c = d - half(a - b + 1);
          }
          else
            c = d - half(a - b);
          if ((aa < a) || (cc < c) || (aa - a > 2 * (bb - b)) || (cc - c > 2 * (dd - d)))
          {
            allsafe = false;
            after[k] = before[k];
            if (k == cur_rounding_ptr - 1)
              after[0] = before[0];
            else
              after[k + 1] = before[k + 1];
          }
        }
      }
    } while (!(allsafe));
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
            unskew (first_x, first_y, mem[pp].hh.b1);
          else
            unskew (mem[pp + 1].cint, mem[pp + 2].cint, mem[pp].hh.b1);
          skew (cur_x, cur_y, mem[p].hh.b1);
          bb = cur_x;
          aa = bb;
          dd = cur_y;
          cc = dd;
          if (mem[p].hh.b1 > 4)
          {
            b = -b;
            a = -a;
          }
        }
        else
        {
          if (mem[p].hh.b1 > 4)
          {
            bb = -bb;
            aa = -aa;
            b = -b;
            a = -a;
          }
          if (pp == node_to_round[0])
            dd = first_y - bb;
          else
            dd = mem[pp + 2].cint - bb;
          if (odd(aa - bb))
          {
            if (mem[p].hh.b1 > 4)
              cc = dd - half(aa - bb + 1);
            else
              cc = dd - half(aa - bb - 1);
          }
          else
            cc = dd - half(aa - bb);
        }
        d = mem[p + 2].cint;
        if (odd(a - b))
        {
          if (mem[p].hh.b1 > 4)
            c = d - half(a - b - 1);
          else
            c = d - half(a - b + 1);
        }
        else
          c = d - half(a - b);
        if (b == bb)
          alpha = fraction_one;
        else
          alpha = make_fraction (aa - a, bb - b);
        if (d == dd)
          beta = fraction_one;
        else
          beta = make_fraction (cc - c, dd - d);
        do {
          mem[p + 1].cint = take_fraction (alpha, mem[p + 1].cint - b) + a;
          mem[p + 2].cint = take_fraction (beta, mem[p + 2].cint - d) + c;
          mem[p + 5].cint = take_fraction (alpha, mem[p + 5].cint - b) + a;
          mem[p + 6].cint = take_fraction (beta, mem[p + 6].cint - d) + c;
          p = mem[p].hh.rh;
          mem[p + 3].cint = take_fraction (alpha, mem[p + 3].cint - b) + a;
          mem[p + 4].cint = take_fraction (beta, mem[p + 4].cint - d) + c;
        } while (!(p == pp));
      }
    }
  }
}
/* 451 */
void new_boundary (halfword p, small_number octant)
{
  halfword q, r;

  q = mem[p].hh.rh;
  r = get_node (7);
  mem[r].hh.rh = q;
  mem[p].hh.rh = r;
  mem[r].hh.b0 = mem[q].hh.b0;
  mem[r + 3].cint = mem[q + 3].cint;
  mem[r + 4].cint = mem[q + 4].cint;
  mem[r].hh.b1 = 0;
  mem[q].hh.b0 = 0;
  mem[r + 5].cint = octant;
  mem[q + 3].cint = mem[q].hh.b1;
  unskew (mem[q + 1].cint, mem[q + 2].cint, mem[q].hh.b1);
  skew (cur_x, cur_y, octant);
  mem[r + 1].cint = cur_x;
  mem[r + 2].cint = cur_y;
}
/* 402 */
halfword make_spec (halfword h, scaled safetymargin, integer tracing)
{
  halfword Result;
  halfword p, q, r, s;
  integer k;
  integer chopped;
  small_number o1, o2;
  boolean clockwise;
  integer dx1, dy1, dx2, dy2;
  integer dmax, del;

  cur_spec = h;
  if (tracing > 0)
    print_path (cur_spec, 559, true);
  max_allowed = 268402687L - safetymargin;
  p = cur_spec;
  k = 1;
  chopped = 0;
  dmax = half(max_allowed);
  do {
    if (abs(mem[p + 3].cint) >= dmax)
    {
      if (abs(mem[p + 3].cint) > max_allowed)
      {
        chopped = 1;
        if (mem[p + 3].cint > 0)
          mem[p + 3].cint = max_allowed;
        else
          mem[p + 3].cint = -max_allowed;
      }
      else if (chopped == 0)
        chopped = -1;
    }
    if (abs(mem[p + 4].cint) >= dmax)
    {
      if (abs(mem[p + 4].cint) > max_allowed)
      {
        chopped = 1;
        if (mem[p + 4].cint > 0)
          mem[p + 4].cint = max_allowed;
        else
          mem[p + 4].cint = -max_allowed;
      }
      else if (chopped == 0)
        chopped = -1;
    }
    if (abs(mem[p + 1].cint) >= dmax)
    {
      if (abs(mem[p + 1].cint) > max_allowed)
      {
        chopped = 1;
        if (mem[p + 1].cint > 0)
          mem[p + 1].cint = max_allowed;
        else
          mem[p + 1].cint = -max_allowed;
      }
      else if (chopped == 0)
        chopped = -1;
    }
    if (abs(mem[p + 2].cint) >= dmax)
    {
      if (abs(mem[p + 2].cint) > max_allowed)
      {
        chopped = 1;
        if (mem[p + 2].cint > 0)
          mem[p + 2].cint = max_allowed;
        else
          mem[p + 2].cint = -max_allowed;
      }
      else if (chopped == 0)
        chopped = -1;
    }
    if (abs(mem[p + 5].cint) >= dmax)
    {
      if (abs(mem[p + 5].cint) > max_allowed)
      {
        chopped = 1;
        if (mem[p + 5].cint > 0)
          mem[p + 5].cint = max_allowed;
        else
          mem[p + 5].cint = -max_allowed;
      }
      else if (chopped == 0)
        chopped = -1;
    }
    if (abs(mem[p + 6].cint) >= dmax)
    {
      if (abs(mem[p + 6].cint) > max_allowed)
      {
        chopped = 1;
        if (mem[p + 6].cint > 0)
          mem[p + 6].cint = max_allowed;
        else
          mem[p + 6].cint = -max_allowed;
      }
      else if (chopped == 0)
        chopped = -1;
    }
    p = mem[p].hh.rh;
    mem[p].hh.b0 = k;
    if (k < 255)
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
    lab_continue: q = mem[p].hh.rh;
    if (p != q)
    {
      if (mem[p + 1].cint == mem[p + 5].cint)
      {
        if (mem[p + 2].cint == mem[p + 6].cint)
        {
          if (mem[p + 1].cint == mem[q + 3].cint)
          {
            if (mem[p + 2].cint == mem[q + 4].cint)
            {
              unskew (mem[q + 1].cint, mem[q + 2].cint, mem[q].hh.b1);
              skew (cur_x, cur_y, mem[p].hh.b1);
              if (mem[p + 1].cint == cur_x)
              {
                if (mem[p + 2].cint == cur_y)
                {
                  remove_cubic (p);
                  if (q != cur_spec)
                    goto lab_continue;
                  cur_spec = p;
                  q = p;
                }
              }
            }
          }
        }
      }
    }
    p = q;
  } while (!(p == cur_spec));
  turning_number = 0;
  p = cur_spec;
  q = mem[p].hh.rh;
  do {
    r = mem[q].hh.rh;
    if ((mem[p].hh.b1 != mem[q].hh.b1) || (q == r))
    {
      new_boundary (p, mem[p].hh.b1);
      s = mem[p].hh.rh;
      o1 = octant_number[mem[p].hh.b1];
      o2 = octant_number[mem[q].hh.b1];
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
            dx1 = mem[s + 1].cint - mem[s + 3].cint;
            dy1 = mem[s + 2].cint - mem[s + 4].cint;
            if (dx1 == 0)
            {
              if (dy1 == 0)
              {
                dx1 = mem[s + 1].cint - mem[p + 5].cint;
                dy1 = mem[s + 2].cint - mem[p + 6].cint;
                if (dx1 == 0)
                {
                  if (dy1 == 0)
                  {
                    dx1 = mem[s + 1].cint - mem[p + 1].cint;
                    dy1 = mem[s + 2].cint - mem[p + 2].cint;
                  }
                }
              }
            }
            dmax = abs(dx1);
            if (abs(dy1) > dmax)
              dmax = abs(dy1);
            while (dmax < fraction_one)
            {
              dmax = dmax + dmax;
              dx1 = dx1 + dx1;
              dy1 = dy1 + dy1;
            }
            dx2 = mem[q + 5].cint - mem[q + 1].cint;
            dy2 = mem[q + 6].cint - mem[q + 2].cint;
            if (dx2 == 0)
            {
              if (dy2 == 0)
              {
                dx2 = mem[r + 3].cint - mem[q + 1].cint;
                dy2 = mem[r + 4].cint - mem[q + 2].cint;
                if (dx2 == 0)
                {
                  if (dy2 == 0)
                  {
                    if (mem[r].hh.b1 == 0)
                    {
                      cur_x = mem[r + 1].cint;
                      cur_y = mem[r + 2].cint;
                    }
                    else
                    {
                      unskew (mem[r + 1].cint, mem[r + 2].cint, mem[r].hh.b1);
                      skew (cur_x, cur_y, mem[q].hh.b1);
                    }
                    dx2 = cur_x - mem[q + 1].cint;
                    dy2 = cur_y - mem[q + 2].cint;
                  }
                }
              }
            }
            dmax = abs(dx2);
            if (abs(dy2) > dmax)
              dmax = abs(dy2);
            while (dmax < fraction_one)
            {
              dmax = dmax + dmax;
              dx2 = dx2 + dx2;
              dy2 = dy2 + dy2;
            }
            unskew (dx1, dy1, mem[p].hh.b1);
            del = pyth_add (cur_x, cur_y);
            dx1 = make_fraction (cur_x, del);
            dy1 = make_fraction (cur_y, del);
            unskew (dx2, dy2, mem[q].hh.b1);
            del = pyth_add (cur_x, cur_y);
            dx2 = make_fraction (cur_x, del);
            dy2 = make_fraction (cur_y, del);
            del = take_fraction (dx1, dy2) - take_fraction (dx2, dy1);
            if (del > 4684844L)
              clockwise = false;
            else if (del < -4684844L)
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
        {
          if (o1 == 1)
            o1 = 8;
          else
            decr(o1);
        }
        else if (o1 == 8)
          o1 = 1;
        else
          incr(o1);
        if (o1 == o2)
          goto done;
        new_boundary (s, octant_code[o1]);
        s = mem[s].hh.rh;
        mem[s + 3].cint = mem[s + 5].cint;
      }
done:
      if (q == r)
      {
        q = mem[q].hh.rh;
        r = q;
        p = s;
        mem[s].hh.rh = q;
        mem[q + 3].cint = mem[q + 5].cint;
        mem[q].hh.b0 = 0;
        free_node (cur_spec, 7);
        cur_spec = q;
      }
      p = mem[p].hh.rh;
      do {
        s = mem[p].hh.rh;
        o1 = octant_number[mem[p + 5].cint];
        o2 = octant_number[mem[s + 3].cint];
        if (abs(o1 - o2) == 1)
        {
          if (o2 < o1)
            o2 = o1;
          if (odd(o2))
            mem[p + 6].cint = 0;
          else
            mem[p + 6].cint = 1;
        }
        else
        {
          if (o1 == 8)
            incr(turning_number);
          else
            decr(turning_number);
          mem[p + 6].cint = 0;
        }
        mem[s + 4].cint = mem[p + 6].cint;
        p = s;
      } while (!(p == q));
    }
    p = q;
    q = r;
  } while (!(p == cur_spec));
  while (mem[cur_spec].hh.b0 != 0)
    cur_spec = mem[cur_spec].hh.rh;
  if (tracing > 0)
  {
    if ((internal[autorounding] <= 0) || (chopped != 0))
      print_spec (560);
    else if (internal[autorounding] > unity)
      print_spec (561);
    else
      print_spec (562);
  }
  Result = cur_spec;
  return Result;
}
/* 463 */
void end_round (scaled x, scaled y)
{
  y = y + half_unit - y_corr[octant];
  x = x + y - x_corr[octant];
  m1 = floor_unscaled (x);
  n1 = floor_unscaled (y);
  if (x - unity * m1 >= y - unity * n1 + z_corr[octant])
    d1 = 1;
  else
    d1 = 0;
}
/* 465 */
void fill_spec (halfword h)
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
        make_moves(x_coord(r), right_x(r), left_x(s), x_coord(s), y_coord(r) +
          half_unit, right_y(r) + half_unit, left_y(s) + half_unit, y_coord(s) + half_unit,
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
halfword make_pen (halfword h)
{
  halfword Result;
  small_number o, oo, k;
  halfword p;
  halfword q, r, s, w, hh;
  integer n;
  scaled dx, dy;
  scaled mc;

  q = h;
  r = mem[q].hh.rh;
  mc = abs(mem[h + 1].cint);
  if (q == r)
  {
    hh = h;
    mem[h].hh.b1 = 0;
    if (mc < abs(mem[h + 2].cint))
      mc = abs(mem[h + 2].cint);
  }
  else
  {
    o = 0;
    hh = 0;
    while (true)
    {
      s = mem[r].hh.rh;
      if (mc < abs(mem[r + 1].cint))
        mc = abs(mem[r + 1].cint);
      if (mc < abs(mem[r + 2].cint))
        mc = abs(mem[r + 2].cint);
      dx = mem[r + 1].cint - mem[q + 1].cint;
      dy = mem[r + 2].cint - mem[q + 2].cint;
      if (dx == 0)
      {
        if (dy == 0)
          goto not_found;
      }
      if (ab_vs_cd (dx, mem[s + 2].cint - mem[r + 2].cint, dy, mem[s + 1].cint - mem[r + 1].cint) < 0)
        goto not_found;
      if (dx > 0)
        octant = 1;
      else if (dx == 0)
      {
        if (dy > 0)
          octant = 1;
        else
          octant = 2;
      }
      else
      {
        dx = -dx;
        octant = 2;
      }
      if (dy < 0)
      {
        dy = -dy;
        octant = octant + 2;
      }
      else if (dy == 0)
      {
        if (octant > 1)
          octant = 4;
      }
      if (dx < dy)
        octant = octant + 4;
      mem[q].hh.b1 = octant;
      oo = octant_number[octant];
      if (o > oo)
      {
        if (hh != 0)
        goto not_found;
        hh = q;
      }
      o = oo;
      if ((q == h) && (hh != 0))
        goto done;
      q = r;
      r = s;
    }
    done:;
  }
  if (mc >= 268402688L)
    goto not_found;
  p = get_node (10);
  q = hh;
  mem[p + 9].cint = mc;
  mem[p].hh.lh = 0;
  if (mem[q].hh.rh != q)
    mem[p].hh.rh = 1;
  for (k = 1; k <= 8; k++)
  {
    octant = octant_code[k];
    n = 0;
    h = p + octant;
    while (true)
    {
      r = get_node (3);
      skew (mem[q + 1].cint, mem[q + 2].cint, octant);
      mem[r + 1].cint = cur_x;
      mem[r + 2].cint = cur_y;
      if (n == 0)
        mem[h].hh.rh = r;
      else if (odd(k))
      {
        mem[w].hh.rh = r;
        mem[r].hh.lh = w;
      }
      else
      {
        mem[w].hh.lh = r;
        mem[r].hh.rh = w;
      }
      w = r;
      if (mem[q].hh.b1 != octant)
        goto done1;
      q = mem[q].hh.rh;
      incr(n);
    }
  done1:
    r = mem[h].hh.rh;
    if (odd(k))
    {
      mem[w].hh.rh = r;
      mem[r].hh.lh = w;
    }
    else
    {
      mem[w].hh.lh = r;
      mem[r].hh.rh = w;
      mem[h].hh.rh = w;
      r = w;
    }
    if ((mem[r + 2].cint != mem[mem[r].hh.rh + 2].cint) || (n == 0))
    {
      dup_offset (r);
      incr(n);
    }
    r = mem[r].hh.lh;
    if (mem[r + 1].cint != mem[mem[r].hh.lh + 1].cint)
      dup_offset (r);
    else
      decr(n);
    if (n >= 255)
      overflow("pen polygon size", 255);
    mem[h].hh.lh = n;
  }
  goto found;
not_found:
  p = 3;
  if (mc >= 268402688L)
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
    print_pen (p, 572, true);
  Result = p;
  return Result;
}
/* 486 */
halfword trivial_knot (scaled x, scaled y)
{
  pointer Result;
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
  Result = p;
  return Result;
}
/* 484 */
halfword make_path (halfword pen_head)
{
  pointer Result;
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
  Result = link(temp_head);
  return Result;
}
/* 488 */
void find_offset (scaled x, scaled y, halfword p)
{
  unsigned char octant;
  int8_t s;
  integer n;
  halfword h, w, ww;

  if (x > 0)
    octant = 1;
  else if (x == 0)
  {
    if (y <= 0)
    {
      if (y == 0)
      {
        cur_x = 0;
        cur_y = 0;
        goto lab_exit;
      }
      else
        octant = 2;
    }
    else
      octant = 1;
  }
  else
  {
    x = -x;
    if (y == 0)
      octant = 4;
    else
      octant = 2;
  }
  if (y < 0)
  {
    octant = octant + 2;
    y = -y;
  }
  if (x >= y)
    x = x - y;
  else
  {
    octant = octant + 4;
    x = y - x;
    y = y - x;
  }
  if (odd(octant_number[octant]))
    s = -1;
  else
    s = 1;
  h = p + octant;
  w = mem[mem[h].hh.rh].hh.rh;
  ww = mem[w].hh.rh;
  n = mem[h].hh.lh;
  while (n > 1)
  {
    if (ab_vs_cd (x, mem[ww + 2].cint - mem[w + 2].cint, y, mem[ww + 1].cint - mem[w + 1].cint) != s)
      goto done;
    w = ww;
    ww = mem[w].hh.rh;
    decr(n);
  }
  done: unskew (mem[w + 1].cint, mem[w + 2].cint, octant);
  lab_exit:;
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
void fin_offset_prep (halfword p, halfword k, halfword w, integer x0, integer x1, integer x2, integer y0, integer y1, integer y2, boolean rising, integer n)
{
  halfword ww;
  scaled du, dv;
  integer t0, t1, t2;
  fraction t;
  fraction s;
  integer v;

  while (true)
  {
    mem[p].hh.b1 = k;
    if (rising)
    {
      if (k == n)
        goto lab_exit;
      else
        ww = mem[w].hh.rh;
    }
    else if (k == 1)
      goto lab_exit;
    else
      ww = mem[w].hh.lh;
    du = mem[ww + 1].cint - mem[w + 1].cint;
    dv = mem[ww + 2].cint - mem[w + 2].cint;
    if (abs(du) >= abs(dv))
    {
      s = make_fraction (dv, du);
      t0 = take_fraction (x0, s) - y0;
      t1 = take_fraction (x1, s) - y1;
      t2 = take_fraction (x2, s) - y2;
    }
    else
    {
      s = make_fraction (du, dv);
      t0 = x0 - take_fraction (y0, s);
      t1 = x1 - take_fraction (y1, s);
      t2 = x2 - take_fraction (y2, s);
    }
    t = crossing_point (t0, t1, t2);
    if (t >= fraction_one)
      goto lab_exit;
    {
      split_for_offset (p, t);
      mem[p].hh.b1 = k;
      p = mem[p].hh.rh;
      v = x0 - take_fraction (x0 - x1, t);
      x1 = x1 - take_fraction (x1 - x2, t);
      x0 = v - take_fraction (v - x1, t);
      v = y0 - take_fraction (y0 - y1, t);
      y1 = y1 - take_fraction (y1 - y2, t);
      y0 = v - take_fraction (v - y1, t);
      t1 = t1 - take_fraction (t1 - t2, t);
      if (t1 > 0)
        t1 = 0;
      t = crossing_point (0, -t1, -t2);
      if (t < fraction_one)
      {
        split_for_offset (p, t);
        mem[mem[p].hh.rh].hh.b1 = k;
        v = x1 - take_fraction (x1 - x2, t);
        x1 = x0 - take_fraction (x0 - x1, t);
        x2 = x1 - take_fraction (x1 - v, t);
        v = y1 - take_fraction (y1 - y2, t);
        y1 = y0 - take_fraction (y0 - y1, t);
        y2 = y1 - take_fraction (y1 - v, t);
      }
    }
    if (rising)
      incr(k);
    else
      decr(k);
    w = ww;
  }
  lab_exit:;
}
/* 491 */
void offset_prep (halfword c, halfword h)
{
  halfword n;
  halfword p, q, r, lh, ww;
  halfword k;
  halfword w;
  integer x0, x1, x2, y0, y1, y2;
  integer t0, t1, t2;
  integer du, dv, dx, dy;
  integer lmax_coef;
  integer x0a, x1a, x2a, y0a, y1a, y2a;
  fraction t;
  fraction s;

  p = c;
  n = mem[h].hh.lh;
  lh = mem[h].hh.rh;
  while (mem[p].hh.b1 != 0)
  {
    q = mem[p].hh.rh;
    if (n <= 1)
      mem[p].hh.b1 = 1;
    else
    {
      x0 = mem[p + 5].cint - mem[p + 1].cint;
      x2 = mem[q + 1].cint - mem[q + 3].cint;
      x1 = mem[q + 3].cint - mem[p + 5].cint;
      y0 = mem[p + 6].cint - mem[p + 2].cint;
      y2 = mem[q + 2].cint - mem[q + 4].cint;
      y1 = mem[q + 4].cint - mem[p + 6].cint;
      lmax_coef = abs(x0);
      if (abs(x1) > lmax_coef)
        lmax_coef = abs(x1);
      if (abs(x2) > lmax_coef)
        lmax_coef = abs(x2);
      if (abs(y0) > lmax_coef)
        lmax_coef = abs(y0);
      if (abs(y1) > lmax_coef)
        lmax_coef = abs(y1);
      if (abs(y2) > lmax_coef)
        lmax_coef = abs(y2);
      if (lmax_coef == 0)
        goto not_found;
      while (lmax_coef < fraction_half)
      {
        lmax_coef = lmax_coef + lmax_coef;
        x0 = x0 + x0;
        x1 = x1 + x1;
        x2 = x2 + x2;
        y0 = y0 + y0;
        y1 = y1 + y1;
        y2 = y2 + y2;
      }
      dx = x0;
      dy = y0;
      if (dx == 0)
      {
        if (dy == 0)
        {
          dx = x1;
          dy = y1;
          if (dx == 0)
          {
            if (dy == 0)
            {
              dx = x2;
              dy = y2;
            }
          }
        }
      }
      if (dx == 0)
        fin_offset_prep (p, n, mem[mem[lh].hh.lh].hh.lh, -x0, -x1, -x2 , -y0, -y1, -y2, false, n);
      else
      {
        k = 1;
        w = mem[lh].hh.rh;
        while (true)
        {
          if (k == n)
            goto done;
          ww = mem[w].hh.rh;
          if (ab_vs_cd (dy, abs(mem[ww + 1].cint - mem[w + 1].cint), dx, abs(mem[ww + 2].cint - mem[w + 2].cint)) >= 0)
          {
            incr(k);
            w = ww;
          }
          else
            goto done;
        }
        done:;
        if (k == 1)
          t = 268435457L;
        else
        {
          ww = mem[w].hh.lh;
          du = mem[ww + 1].cint - mem[w + 1].cint;
          dv = mem[ww + 2].cint - mem[w + 2].cint;
          if (abs(du) >= abs(dv))
          {
            s = make_fraction (dv, du);
            t0 = take_fraction (x0, s) - y0;
            t1 = take_fraction (x1, s) - y1;
            t2 = take_fraction (x2, s) - y2;
          }
          else
          {
            s = make_fraction (du, dv);
            t0 = x0 - take_fraction (y0, s);
            t1 = x1 - take_fraction (y1, s);
            t2 = x2 - take_fraction (y2, s);
          }
          t = crossing_point (-t0, -t1, -t2);
        }
        if (t >= fraction_one)
          fin_offset_prep (p, k, w, x0, x1, x2, y0, y1, y2, true, n);
        else
        {
          split_for_offset (p, t);
          r = mem[p].hh.rh;
          x1a = x0 - take_fraction (x0 - x1, t);
          x1 = x1 - take_fraction (x1 - x2, t);
          x2a = x1a - take_fraction (x1a - x1, t);
          y1a = y0 - take_fraction (y0 - y1, t);
          y1 = y1 - take_fraction (y1 - y2, t);
          y2a = y1a - take_fraction (y1a - y1, t);
          fin_offset_prep (p, k, w, x0, x1a, x2a, y0, y1a, y2a, true, n);
          x0 = x2a;
          y0 = y2a;
          t1 = t1 - take_fraction (t1 - t2, t);
          if (t1 < 0)
            t1 = 0;
          t = crossing_point (0, t1, t2);
          if (t < fraction_one)
          {
            split_for_offset (r, t);
            x1a = x1 - take_fraction (x1 - x2, t);
            x1 = x0 - take_fraction (x0 - x1, t);
            x0a = x1 - take_fraction (x1 - x1a, t);
            y1a = y1 - take_fraction (y1 - y2, t);
            y1 = y0 - take_fraction (y0 - y1, t);
            y0a = y1 - take_fraction (y1 - y1a, t);
            fin_offset_prep (mem[r].hh.rh, k, w, x0a, x1a, x2, y0a, y1a, y2, true, n);
            x2 = x0a;
            y2 = y0a;
          }
          fin_offset_prep (r, k - 1, ww, -x0, -x1, -x2, -y0, -y1, -y2 , false, n);
        }
      }
      not_found:;
    }
    do {
      r = mem[p].hh.rh;
      if (mem[p + 1].cint == mem[p + 5].cint)
      {
        if (mem[p + 2].cint == mem[p + 6].cint)
        {
          if (mem[p + 1].cint == mem[r + 3].cint)
          {
            if (mem[p + 2].cint == mem[r + 4].cint)
            {
              if (mem[p + 1].cint == mem[r + 1].cint)
              {
                if (mem[p + 2].cint == mem[r + 2].cint)
                {
                  remove_cubic (p);
                  if (r == q)
                    q = p;
                  r = p;
                }
              }
            }
          }
        }
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
      print_nl(585);
      print_two(x0, y0);
      print(584);
      print_two(cur_x, cur_y);
      print_nl(261);
    }
#endif /* STAT */
    line_edges(x0, y0, cur_x, cur_y);
  }
}
/* 518 */
void dual_moves (halfword h, halfword p, halfword q)
{
  halfword r, s;
  integer m, n;
  integer mm0, mm1;
  integer k;
  halfword w, ww;
  integer smoothbot, smoothtop;
  scaled xx, yy, xp, yp, delx, dely, tx, ty;

  k = mem[h].hh.lh + 1;
  ww = mem[h].hh.rh;
  w = mem[ww].hh.lh;
  mm0 = floorunscaled (mem[p + 1].cint + mem[w + 1].cint - xy_corr[octant]);
  mm1 = floorunscaled (mem[q + 1].cint + mem[ww + 1].cint - xy_corr[octant]);
  for (n = 1; n <= n1 - n0 + 1; n++)
  {
    env_move[n] = mm1;
  }
  env_move[0] = mm0;
  move_ptr = 0;
  m = mm0;
  r = p;
  while (true)
  {
    if (r == q)
      smoothtop = move_ptr;
    while (mem[r].hh.b1 != k)
    {
      xx = mem[r + 1].cint + mem[w + 1].cint;
      yy = mem[r + 2].cint + mem[w + 2].cint + half_unit;
      ;
#ifdef STAT
      if (internal[tracing_edges] > unity)
      {
        print_nl(586);
        print_int(k);
        print(587);
        unskew (xx, yy - half_unit, octant);
        print_two (cur_x, cur_y);
      }
#endif /* STAT */
      if (mem[r].hh.b1 < k)
      {
        decr(k);
        w = mem[w].hh.lh;
        xp = mem[r + 1].cint + mem[w + 1].cint;
        yp = mem[r + 2].cint + mem[w + 2].cint + half_unit;
        if (yp != yy)
        {
          ty = floorscaled (yy - y_corr[octant]);
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
              tx = take_fraction (delx, make_fraction (yy, dely));
              if (ab_vs_cd (tx, dely, delx, yy) + xy_corr[octant] > 0)
                decr(tx);
              m = floorunscaled (xx + tx);
              ty = ty - unity;
              incr(move_ptr);
              if (ty < unity)
                goto done1;
              yy = yy + unity;
            }
            done1: if (m < env_move[move_ptr])
              env_move[move_ptr] = m;
          }
        }
      }
      else
      {
        incr(k);
        w = mem[w].hh.rh;
        xp = mem[r + 1].cint + mem[w + 1].cint;
        yp = mem[r + 2].cint + mem[w + 2].cint + half_unit;
      }
      ;
#ifdef STAT
      if (internal[tracing_edges] > unity)
      {
        print(584);
        unskew (xp, yp - half_unit, octant);
        print_two (cur_x, cur_y);
        print_nl(261);
      }
#endif /* STAT */
      m = floorunscaled (xp - xy_corr[octant]);
      move_ptr = floorunscaled (yp - y_corr[octant]) - n0;
      if (m < env_move[move_ptr])
        env_move[move_ptr] = m;
    }
    if (r == p)
      smoothbot = move_ptr;
    if (r == q)
      goto done;
    move[move_ptr] = 1;
    n = move_ptr;
    s = mem[r].hh.rh;
    make_moves (mem[r + 1].cint + mem[w + 1].cint, mem[r + 5].cint + mem[w + 1].cint, mem[s + 3].cint + mem[w + 1].cint ,
    mem[s + 1].cint + mem[w + 1].cint, mem[r + 2].cint + mem[w + 2].cint + half_unit, mem[r + 6].cint + mem[w + 2].cint + half_unit, mem[s + 4].cint + mem[w + 2].cint + half_unit, mem[s + 2].cint + mem[w + 2].cint + half_unit, xy_corr[octant], y_corr[octant]);
    do {
      if (m < env_move[n])
        env_move[n] = m;
      m = m + move[n] - 1;
      incr(n);
    } while (!(n > move_ptr));
    r = s;
  }
  done:
  ;
#ifdef TEXMF_DEBUG
  if ((m != mm1) || (move_ptr != n1 - n0))
    confusion("2");
#endif /* TEXMF_DEBUG */
  move[0] = d0 + env_move[1] - mm0;
  for (n = 1; n <= move_ptr; n++)
  {
    move[n] = env_move[n + 1] - env_move[n]+ 1;
  }
  move[move_ptr] = move[move_ptr] - d1;
  if (internal[smoothing] > 0)
    smooth_moves (smoothbot, smoothtop);
  move_to_edges (m0, n0, m1, n1);
  if (mem[q + 6].cint == 1)
  {
    w = mem[h].hh.rh;
    skew_line_edges (q, w, mem[w].hh.lh);
  }
}
/* 506 */
void fill_envelope (halfword spechead)
{
  halfword p, q, r, s;
  halfword h;
  halfword www;
  integer m, n;
  integer mm0, mm1;
  integer k;
  halfword w, ww;
  integer smoothbot, smoothtop;
  scaled xx, yy, xp, yp, delx, dely, tx, ty;

  if (internal[tracing_edges] > 0)
    begin_edge_tracing();
  p = spechead;
  do {
    octant = mem[p + 3].cint;
    h = cur_pen + octant;
    q = p;
    while (mem[q].hh.b1 != 0)
      q = mem[q].hh.rh;
    w = mem[h].hh.rh;
    if (mem[p + 4].cint == 1)
      w = mem[w].hh.lh;
#ifdef STAT
    if (internal[tracing_edges] > unity)
    {
      print_nl(580);
      print(octant_dir[octant]);
      print(558);
      print_int(mem[h].hh.lh);
      if (mem[h].hh.lh != 1)
        print(581);
      else
        print(582);
      print(583);
      unskew (mem[p + 1].cint + mem[w + 1].cint, mem[p + 2].cint + mem[w + 2].cint, octant);
      print_two (cur_x, cur_y);
      ww = mem[h].hh.rh;
      if (mem[q + 6].cint == 1)
        ww = mem[ww].hh.lh;
      print(584);
      unskew (mem[q + 1].cint + mem[ww + 1].cint, mem[q + 2].cint + mem[ww + 2].cint, octant);
      print_two (cur_x, cur_y);
    }
#endif /* STAT */
    ww = mem[h].hh.rh;
    www = ww;
    if (odd(octant_number[octant]))
      www = mem[www].hh.lh;
    else
      ww = mem[ww].hh.lh;
    if (w != ww)
      skew_line_edges (p, w, ww);
    end_round (mem[p + 1].cint + mem[ww + 1].cint, mem[p + 2].cint + mem[ww + 2].cint);
    m0 = m1;
    n0 = n1;
    d0 = d1;
    end_round (mem[q + 1].cint + mem[www + 1].cint, mem[q + 2].cint + mem[www + 2].cint);
    if (n1 - n0 >= move_size)
      overflow("move table size", move_size);
    offset_prep (p, h);
    q = p;
    while (mem[q].hh.b1 != 0)
      q = mem[q].hh.rh;
    if (odd(octant_number[octant]))
    {
      k = 0;
      w = mem[h].hh.rh;
      ww = mem[w].hh.lh;
      mm0 = floorunscaled (mem[p + 1].cint + mem[w + 1].cint - xy_corr[octant]);
      mm1 = floorunscaled (mem[q + 1].cint + mem[ww + 1].cint - xy_corr[octant]);
      for (n = 0; n <= n1 - n0; n++)
      {
        env_move[n] = mm0;
      }
      env_move[n1 - n0] = mm1;
      move_ptr = 0;
      m = mm0;
      r = p;
      mem[q].hh.b1 = mem[h].hh.lh + 1;
      while (true)
      {
        if (r == q)
          smoothtop = move_ptr;
        while (mem[r].hh.b1 != k)
        {
          xx = mem[r + 1].cint + mem[w + 1].cint;
          yy = mem[r + 2].cint + mem[w + 2].cint + half_unit;
          ;
#ifdef STAT
          if (internal[tracing_edges] > unity)
          {
            print_nl(586);
            print_int(k);
            print(587);
            unskew (xx, yy - half_unit, octant);
            print_two (cur_x, cur_y);
          }
#endif /* STAT */
          if (mem[r].hh.b1 > k)
          {
            incr(k);
            w = mem[w].hh.rh;
            xp = mem[r + 1].cint + mem[w + 1].cint;
            yp = mem[r + 2].cint + mem[w + 2].cint + half_unit;
            if (yp != yy)
            {
              ty = floorscaled (yy - y_corr[octant]);
              dely = yp - yy;
              yy = yy - ty;
              ty = yp - y_corr[octant] - ty;
              if (ty >= unity)
              {
                delx = xp - xx;
                yy = unity - yy;
                while (true)
                {
                  tx = take_fraction (delx, make_fraction (yy, dely));
                  if (ab_vs_cd (tx, dely, delx, yy) + xy_corr[octant] > 0)
                    decr(tx);
                  m = floorunscaled (xx + tx);
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
            w = mem[w].hh.lh;
            xp = mem[r + 1].cint + mem[w + 1].cint;
            yp = mem[r + 2].cint + mem[w + 2].cint + half_unit;
          }
          ;
#ifdef STAT
          if (internal[tracing_edges] > unity)
          {
            print(584);
            unskew (xp, yp - half_unit, octant);
            print_two (cur_x, cur_y);
            print_nl(261);
          }
#endif /* STAT */
          m = floorunscaled (xp - xy_corr[octant]);
          move_ptr = floorunscaled (yp - y_corr[octant]) - n0;
          if (m > env_move[move_ptr])
            env_move[move_ptr] = m;
        }
        if (r == p)
          smoothbot = move_ptr;
        if (r == q)
          goto done;
        move[move_ptr] = 1;
        n = move_ptr;
        s = mem[r].hh.rh;
        make_moves (mem[r + 1].cint + mem[w + 1].cint, mem[r + 5].cint + mem[w + 1].cint, mem[s + 3].cint + mem[w + 1].cint, mem[s + 1].cint + mem[w + 1].cint, mem[r + 2].cint + mem[w + 2].cint + half_unit, mem[r + 6].cint + mem[w + 2].cint + half_unit, mem[s + 4].cint + mem[w + 2].cint + half_unit, mem[s + 2].cint + mem[w + 2].cint + half_unit, xy_corr[octant], y_corr[octant]);
        do {
          m = m + move[n] - 1;
          if (m > env_move[n])
            env_move[n] = m;
          incr(n);
        } while (!(n > move_ptr));
        r = s;
      }
      done:
      ;
#ifdef TEXMF_DEBUG
      if ((m != mm1) || (move_ptr != n1 - n0))
        confusion("1");
#endif /* TEXMF_DEBUG */
      move[0] = d0 + env_move[0] - mm0;
      for (n = 1; n <= move_ptr; n++)
      {
        move[n] = env_move[n] - env_move[n - 1]+ 1;
      }
      move[move_ptr] = move[move_ptr] - d1;
      if (internal[smoothing] > 0)
        smooth_moves (smoothbot, smoothtop);
      move_to_edges (m0, n0, m1, n1);
      if (mem[q + 6].cint == 0)
      {
        w = mem[h].hh.rh;
        skew_line_edges (q, mem[w].hh.lh, w);
      }
    }
    else
      dual_moves (h, p, q);
    mem[q].hh.b1 = 0;
    p = mem[q].hh.rh;
  } while (!(p == spechead));
  if (internal[tracing_edges] > 0)
    end_edge_tracing();
  toss_knot_list (spechead);
}
/* 527 */
halfword make_ellipse (scaled major_axis, scaled minor_axis, angle theta)
{
  halfword Result;
  halfword p, q, r, s;
  halfword h;
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
    gamma = take_fraction (major_axis, n_sin);
    delta = take_fraction (minor_axis, n_cos);
    beta = pyth_add (gamma, delta);
    alpha = make_fraction (gamma, beta);
    alpha = take_fraction (major_axis, alpha);
    alpha = take_fraction (alpha, n_cos);
    alpha = (alpha + half_unit) / unity;
    gamma = take_fraction (minor_axis, n_sin);
    gamma = pyth_add (take_fraction (major_axis, n_cos), gamma);
  }
  beta = (beta + half_unit) / unity;
  gamma = (gamma + half_unit) / unity;
  p = get_node (7);
  q = get_node (7);
  r = get_node (7);
  if (symmetric)
    s = 0;
  else
    s = get_node (7);
  h = p;
  mem[p].hh.rh = q;
  mem[q].hh.rh = r;
  mem[r].hh.rh = s;
  if (beta == 0)
    beta = 1;
  if (gamma == 0)
    gamma = 1;
  if (gamma <= abs(alpha))
  {
    if (alpha > 0)
      alpha = gamma - 1;
    else
      alpha = 1 - gamma;
  }
  mem[p + 1].cint = -alpha * half_unit;
  mem[p + 2].cint = -beta * half_unit;
  mem[q + 1].cint = gamma * half_unit;
  mem[q + 2].cint = mem[p + 2].cint;
  mem[r + 1].cint = mem[q + 1].cint;
  mem[p + 5].cint = 0;
  mem[q + 3].cint = -half_unit;
  mem[q + 5].cint = half_unit;
  mem[r + 3].cint = 0;
  mem[r + 5].cint = 0;
  mem[p + 6].cint = beta;
  mem[q + 6].cint = gamma;
  mem[r + 6].cint = beta;
  mem[q + 4].cint = gamma + alpha;
  if (symmetric)
  {
    mem[r + 2].cint = 0;
    mem[r + 4].cint = beta;
  }
  else
  {
    mem[r + 2].cint = -mem[p + 2].cint;
    mem[r + 4].cint = beta + beta;
    mem[s + 1].cint = -mem[p + 1].cint;
    mem[s + 2].cint = mem[r + 2].cint;
    mem[s + 3].cint = half_unit;
    mem[s + 4].cint = gamma - alpha;
  }
  while (true)
  {
    u = mem[p + 5].cint + mem[q + 5].cint;
    v = mem[q + 3].cint + mem[r + 3].cint;
    c = mem[p + 6].cint + mem[q + 6].cint;
    delta = pyth_add (u, v);
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
        alpha = take_fraction (u, n_cos) + take_fraction (v, n_sin);
        beta = take_fraction (v, n_cos) - take_fraction (u, n_sin);
      }
      alpha = make_fraction (alpha, delta);
      beta = make_fraction (beta, delta);
      d = pyth_add (take_fraction (major_axis, alpha), take_fraction (minor_axis, beta));
    }
    alpha = abs(u);
    beta = abs(v);
    if (alpha < beta)
    {
      alpha = abs(v);
      beta = abs(u);
    }
    if (internal[fillin] != 0)
      d = d - take_fraction (internal[fillin], make_fraction (beta + beta, delta));
    d = take_fraction ((d + 4) / 8, delta);
    alpha = alpha / half_unit;
    if (d < alpha)
      d = alpha;
    delta = c - d;
    if (delta > 0)
    {
      if (delta > mem[r + 4].cint)
        delta = mem[r + 4].cint;
      if (delta >= mem[q + 4].cint)
      {
        delta = mem[q + 4].cint;
        mem[p + 6].cint = c - delta;
        mem[p + 5].cint = u;
        mem[q + 3].cint = v;
        mem[q + 1].cint = mem[q + 1].cint - delta * mem[r + 3].cint;
        mem[q + 2].cint = mem[q + 2].cint + delta * mem[q + 5].cint;
        mem[r + 4].cint = mem[r + 4].cint - delta;
      }
      else
      {
        s = get_node (7);
        mem[p].hh.rh = s;
        mem[s].hh.rh = q;
        mem[s + 1].cint = mem[q + 1].cint + delta * mem[q + 3].cint;
        mem[s + 2].cint = mem[q + 2].cint - delta * mem[p + 5].cint;
        mem[q + 1].cint = mem[q + 1].cint - delta * mem[r + 3].cint;
        mem[q + 2].cint = mem[q + 2].cint + delta * mem[q + 5].cint;
        mem[s + 3].cint = mem[q + 3].cint;
        mem[s + 5].cint = u;
        mem[q + 3].cint = v;
        mem[s + 6].cint = c - delta;
        mem[s + 4].cint = mem[q + 4].cint - delta;
        mem[q + 4].cint = delta;
        mem[r + 4].cint = mem[r + 4].cint - delta;
      }
    }
    else
      p = q;
    while (true)
    {
      q = mem[p].hh.rh;
      if (q == 0)
        goto done;
      if (mem[q + 4].cint == 0)
      {
        mem[p].hh.rh = mem[q].hh.rh;
        mem[p + 6].cint = mem[q + 6].cint;
        mem[p + 5].cint = mem[q + 5].cint;
        free_node (q, 7);
      }
      else
      {
        r = mem[q].hh.rh;
        if (r == 0)
          goto done;
        if (mem[r + 4].cint == 0)
        {
          mem[p].hh.rh = r;
          free_node (q, 7);
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
    s = 0;
    q = h;
    while (true)
    {
      r = get_node (7);
      mem[r].hh.rh = s;
      s = r;
      mem[s + 1].cint = mem[q + 1].cint;
      mem[s + 2].cint = -mem[q + 2].cint;
      if (q == p)
        goto done1;
      q = mem[q].hh.rh;
      if (mem[q + 2].cint == 0)
        goto done1;
    }
  done1:
    if ((mem[p].hh.rh != 0))
      free_node (mem[p].hh.rh, 7);
    mem[p].hh.rh = s;
    beta = -mem[h + 2].cint;
    while (mem[p + 2].cint != beta)
      p = mem[p].hh.rh;
    q = mem[p].hh.rh;
  }
  if (q != 0)
  {
    if (mem[h + 5].cint == 0)
    {
      p = h;
      h = mem[h].hh.rh;
      free_node (p, 7);
      mem[q + 1].cint = -mem[h + 1].cint;
    }
    p = q;
  }
  else
    q = p;
  r = mem[h].hh.rh;
  do {
    s = get_node (7);
    mem[p].hh.rh = s;
    p = s;
    mem[p + 1].cint = -mem[r + 1].cint;
    mem[p + 2].cint = -mem[r + 2].cint;
    r = mem[r].hh.rh;
  } while (!(r == q));
  mem[p].hh.rh = h;
  Result = h;
  return Result;
}
/* 539 */
scaled find_direction_time (scaled x, scaled y, halfword h)
{
  scaled Result;
  scaled max;
  halfword p, q;
  scaled n;
  scaled tt;
  scaled x1, x2, x3, y1, y2, y3;
  angle theta, phi;
  fraction t;

  if (abs(x) < abs(y))
  {
    x = make_fraction (x, abs(y));
    if (y > 0)
      y = fraction_one;
    else
      y = -fraction_one;
  }
  else if (x == 0)
  {
    Result = 0;
    goto lab_exit;
  }
  else
  {
    y = make_fraction (y, abs(x));
    if (x > 0)
      x = fraction_one;
    else
      x = -fraction_one;
  }
  n = 0;
  p = h;
  while (true)
  {
    if (mem[p].hh.b1 == 0)
      goto not_found;
    q = mem[p].hh.rh;
    tt = 0;
    x1 = mem[p + 5].cint - mem[p + 1].cint;
    x2 = mem[q + 3].cint - mem[p + 5].cint;
    x3 = mem[q + 1].cint - mem[q + 3].cint;
    y1 = mem[p + 6].cint - mem[p + 2].cint;
    y2 = mem[q + 4].cint - mem[p + 6].cint;
    y3 = mem[q + 2].cint - mem[q + 4].cint;
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
      max = max + max;
      x1 = x1 + x1;
      x2 = x2 + x2;
      x3 = x3 + x3;
      y1 = y1 + y1;
      y2 = y2 + y2;
      y3 = y3 + y3;
    }
    t = x1;
    x1 = take_fraction (x1, x) + take_fraction (y1, y);
    y1 = take_fraction (y1, x) - take_fraction (t, y);
    t = x2;
    x2 = take_fraction (x2, x) + take_fraction (y2, y);
    y2 = take_fraction (y2, x) - take_fraction (t, y);
    t = x3;
    x3 = take_fraction (x3, x) + take_fraction (y3, y);
    y3 = take_fraction (y3, x) - take_fraction (t, y);
    if (y1 == 0)
    {
      if (x1 >= 0)
        goto found;
    }
    if (n > 0)
    {
      theta = n_arg (x1, y1);
      if (theta >= 0)
      {
        if (phi <= 0)
        {
          if (phi >= theta - one_eighty_deg)
          goto found;
        }
      }
      if (theta <= 0)
      {
        if (phi >= 0)
        {
          if (phi <= theta + one_eighty_deg)
            goto found;
        }
      }
      if (p == h)
        goto not_found;
    }
    if ((x3 != 0) || (y3 != 0))
      phi = n_arg (x3, y3);
    if (x1 < 0)
    {
      if (x2 < 0)
      {
        if (x3 < 0)
          goto done;
      }
    }
    if (ab_vs_cd (y1, y3, y2, y2) == 0)
    {
      if (ab_vs_cd (y1, y2, 0, 0) < 0)
      {
        t = make_fraction (y1, y1 - y2);
        x1 = x1 - take_fraction (x1 - x2, t);
        x2 = x2 - take_fraction (x2 - x3, t);
        if (x1 - take_fraction (x1 - x2, t) >= 0)
        {
          tt = (t + 2048) / 4096;
          goto found;
        }
      }
      else if (y3 == 0)
      {
        if (y1 == 0)
        {
          t = crossing_point (-x1, -x2, -x3);
          if (t <= fraction_one)
          {
            tt = (t + 2048) / 4096;
            goto found;
          }
          if (ab_vs_cd (x1, x3, x2, x2) <= 0)
          {
            t = make_fraction (x1, x1 - x2);
            {
              tt = (t + 2048) / 4096;
              goto found;
            }
          }
        }
        else if (x3 >= 0)
        {
          tt = unity;
          goto found;
        }
      }
      goto done;
    }
    if (y1 <= 0)
    {
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
    }
    t = crossing_point (y1, y2, y3);
    if (t > fraction_one)
      goto done;
    y2 = y2 - take_fraction (y2 - y3, t);
    x1 = x1 - take_fraction (x1 - x2, t);
    x2 = x2 - take_fraction (x2 - x3, t);
    x1 = x1 - take_fraction (x1 - x2, t);
    if (x1 >= 0)
    {
      tt = (t + 2048) / 4096;
      goto found;
    }
    if (y2 > 0)
      y2 = 0;
    tt = t;
    t = crossing_point (0, -y2, -y3);
    if (t > fraction_one)
      goto done;
    x1 = x1 - take_fraction (x1 - x2, t);
    x2 = x2 - take_fraction (x2 - x3, t);
    if (x1 - take_fraction (x1 - x2, t) >= 0)
    {
      t = tt - take_fraction (tt - fraction_one, t);
      {
        tt = (t + 2048) / 4096;
        goto found;
      }
    }
    done:;
    p = q;
    n = n + unity;
  }
  not_found: Result = -unity;
  goto lab_exit;
  found: Result = n + tt;
  lab_exit:;
  return Result;
}
/* 556 */
void cubic_intersection (halfword p, halfword pp)
{
  halfword q, qq;

  time_to_go = 5000;
  max_t = 2;
  q = mem[p].hh.rh;
  qq = mem[pp].hh.rh;
  bisect_ptr = 20;
  bisect_stack[bisect_ptr - 5] = mem[p + 5].cint - mem[p + 1].cint;
  bisect_stack[bisect_ptr - 4] = mem[q + 3].cint - mem[p + 5].cint;
  bisect_stack[bisect_ptr - 3] = mem[q + 1].cint - mem[q + 3].cint;
  if (bisect_stack[bisect_ptr - 5]< 0)
  {
    if (bisect_stack[bisect_ptr - 3] >= 0)
    {
      if (bisect_stack[bisect_ptr - 4]< 0)
        bisect_stack[bisect_ptr - 2] = bisect_stack[bisect_ptr - 5]+ bisect_stack[bisect_ptr - 4];
      else
        bisect_stack[bisect_ptr - 2] = bisect_stack[bisect_ptr - 5];
      bisect_stack[bisect_ptr - 1] = bisect_stack[bisect_ptr - 5] + bisect_stack[bisect_ptr - 4]+ bisect_stack[bisect_ptr - 3];
      if (bisect_stack[bisect_ptr - 1] < 0)
        bisect_stack[bisect_ptr - 1] = 0;
    }
    else
    {
      bisect_stack[bisect_ptr - 2] = bisect_stack[bisect_ptr - 5] + bisect_stack[bisect_ptr - 4]+ bisect_stack[bisect_ptr - 3];
      if (bisect_stack[bisect_ptr - 2] > bisect_stack[bisect_ptr - 5])
        bisect_stack[bisect_ptr - 2] = bisect_stack[bisect_ptr - 5];
      bisect_stack[bisect_ptr - 1] = bisect_stack[bisect_ptr - 5] + bisect_stack[bisect_ptr - 4];
      if (bisect_stack[bisect_ptr - 1]< 0)
        bisect_stack[bisect_ptr - 1] = 0;
    }
  }
  else if (bisect_stack[bisect_ptr - 3]<= 0)
  {
    if (bisect_stack[bisect_ptr - 4] > 0)
      bisect_stack[bisect_ptr - 1] = bisect_stack[bisect_ptr - 5] + bisect_stack[bisect_ptr - 4];
    else
      bisect_stack[bisect_ptr - 1] = bisect_stack[bisect_ptr - 5];
    bisect_stack[bisect_ptr - 2] = bisect_stack[bisect_ptr - 5] + bisect_stack[bisect_ptr - 4]+ bisect_stack[bisect_ptr - 3];
    if (bisect_stack[bisect_ptr - 2] > 0)
      bisect_stack[bisect_ptr - 2] = 0;
  }
  else
  {
    bisect_stack[bisect_ptr - 1] = bisect_stack[bisect_ptr - 5] + bisect_stack[bisect_ptr - 4]+ bisect_stack[bisect_ptr - 3];
    if (bisect_stack[bisect_ptr - 1]< bisect_stack[bisect_ptr - 5])
      bisect_stack[bisect_ptr - 1] = bisect_stack[bisect_ptr - 5];
    bisect_stack[bisect_ptr - 2] = bisect_stack[bisect_ptr - 5] + bisect_stack[bisect_ptr - 4];
    if (bisect_stack[bisect_ptr - 2] > 0)
      bisect_stack[bisect_ptr - 2] = 0;
  }
  bisect_stack[bisect_ptr - 10] = mem[p + 6].cint - mem[p + 2].cint;
  bisect_stack[bisect_ptr - 9] = mem[q + 4].cint - mem[p + 6].cint;
  bisect_stack[bisect_ptr - 8] = mem[q + 2].cint - mem[q + 4].cint;
  if (bisect_stack[bisect_ptr - 10]< 0)
  {
    if (bisect_stack[bisect_ptr - 8] >= 0)
    {
      if (bisect_stack[bisect_ptr - 9] < 0)
        bisect_stack[bisect_ptr - 7] = bisect_stack[bisect_ptr - 10] + bisect_stack[bisect_ptr - 9];
      else
        bisect_stack[bisect_ptr - 7] = bisect_stack[bisect_ptr - 10];
      bisect_stack[bisect_ptr - 6] = bisect_stack[bisect_ptr - 10] + bisect_stack[bisect_ptr - 9]+ bisect_stack[bisect_ptr - 8];
      if (bisect_stack[bisect_ptr - 6] < 0)
        bisect_stack[bisect_ptr - 6] = 0;
    }
    else
    {
      bisect_stack[bisect_ptr - 7] = bisect_stack[bisect_ptr - 10] + bisect_stack[bisect_ptr - 9]+ bisect_stack[bisect_ptr - 8];
      if (bisect_stack[bisect_ptr - 7] > bisect_stack[bisect_ptr - 10])
        bisect_stack[bisect_ptr - 7] = bisect_stack[bisect_ptr - 10];
      bisect_stack[bisect_ptr - 6] = bisect_stack[bisect_ptr - 10] + bisect_stack[bisect_ptr - 9];
      if (bisect_stack[bisect_ptr - 6]< 0)
        bisect_stack[bisect_ptr - 6] = 0;
    }
  }
  else if (bisect_stack[bisect_ptr - 8]<= 0)
  {
    if (bisect_stack[bisect_ptr - 9] > 0)
      bisect_stack[bisect_ptr - 6] = bisect_stack[bisect_ptr - 10] + bisect_stack[bisect_ptr - 9];
    else
      bisect_stack[bisect_ptr - 6] = bisect_stack[bisect_ptr - 10];
    bisect_stack[bisect_ptr - 7] = bisect_stack[bisect_ptr - 10] + bisect_stack[bisect_ptr - 9]+ bisect_stack[bisect_ptr - 8];
    if (bisect_stack[bisect_ptr - 7] > 0)
      bisect_stack[bisect_ptr - 7] = 0;
  }
  else
  {
    bisect_stack[bisect_ptr - 6] = bisect_stack[bisect_ptr - 10] + bisect_stack[bisect_ptr - 9]+ bisect_stack[bisect_ptr - 8];
    if (bisect_stack[bisect_ptr - 6]< bisect_stack[bisect_ptr - 10])
      bisect_stack[bisect_ptr - 6] = bisect_stack[bisect_ptr - 10];
    bisect_stack[bisect_ptr - 7] = bisect_stack[bisect_ptr - 10] + bisect_stack[bisect_ptr - 9];
    if (bisect_stack[bisect_ptr - 7] > 0)
      bisect_stack[bisect_ptr - 7] = 0;
  }
  bisect_stack[bisect_ptr - 15] = mem[pp + 5].cint - mem[pp + 1].cint;
  bisect_stack[bisect_ptr - 14] = mem[qq + 3].cint - mem[pp + 5].cint;
  bisect_stack[bisect_ptr - 13] = mem[qq + 1].cint - mem[qq + 3].cint;
  if (bisect_stack[bisect_ptr - 15]< 0)
  {
    if (bisect_stack[bisect_ptr - 13] >= 0)
    {
      if (bisect_stack[bisect_ptr - 14]< 0)
        bisect_stack[bisect_ptr - 12] = bisect_stack[bisect_ptr - 15] + bisect_stack[bisect_ptr - 14];
      else
        bisect_stack[bisect_ptr - 12] = bisect_stack[bisect_ptr - 15];
      bisect_stack[bisect_ptr - 11] = bisect_stack[bisect_ptr - 15] + bisect_stack[bisect_ptr - 14]+ bisect_stack[bisect_ptr - 13];
      if (bisect_stack[bisect_ptr - 11] < 0)
        bisect_stack[bisect_ptr - 11] = 0;
    }
    else
    {
      bisect_stack[bisect_ptr - 12] = bisect_stack[bisect_ptr - 15] + bisect_stack[bisect_ptr - 14]+ bisect_stack[bisect_ptr - 13];
      if (bisect_stack[bisect_ptr - 12] > bisect_stack[bisect_ptr - 15])
        bisect_stack[bisect_ptr - 12] = bisect_stack[bisect_ptr - 15];
      bisect_stack[bisect_ptr - 11] = bisect_stack[bisect_ptr - 15] + bisect_stack[bisect_ptr - 14];
      if (bisect_stack[bisect_ptr - 11] < 0)
        bisect_stack[bisect_ptr - 11] = 0;
    }
  }
  else if (bisect_stack[bisect_ptr - 13]<= 0)
  {
    if (bisect_stack[bisect_ptr - 14] > 0)
      bisect_stack[bisect_ptr - 11] = bisect_stack[bisect_ptr - 15] + bisect_stack[bisect_ptr - 14];
    else
      bisect_stack[bisect_ptr - 11] = bisect_stack[bisect_ptr - 15];
    bisect_stack[bisect_ptr - 12] = bisect_stack[bisect_ptr - 15] + bisect_stack[bisect_ptr - 14]+ bisect_stack[bisect_ptr - 13];
    if (bisect_stack[bisect_ptr - 12] > 0)
      bisect_stack[bisect_ptr - 12] = 0;
  }
  else
  {
    bisect_stack[bisect_ptr - 11] = bisect_stack[bisect_ptr - 15] + bisect_stack[bisect_ptr - 14] + bisect_stack[bisect_ptr - 13];
    if (bisect_stack[bisect_ptr - 11] < bisect_stack[bisect_ptr - 15])
      bisect_stack[bisect_ptr - 11] = bisect_stack[bisect_ptr - 15];
    bisect_stack[bisect_ptr - 12] = bisect_stack[bisect_ptr - 15] + bisect_stack[bisect_ptr - 14];
    if (bisect_stack[bisect_ptr - 12] > 0)
      bisect_stack[bisect_ptr - 12] = 0;
  }
  bisect_stack[bisect_ptr - 20] = mem[pp + 6].cint - mem[pp + 2].cint;
  bisect_stack[bisect_ptr - 19] = mem[qq + 4].cint - mem[pp + 6].cint;
  bisect_stack[bisect_ptr - 18] = mem[qq + 2].cint - mem[qq + 4].cint;
  if (bisect_stack[bisect_ptr - 20]< 0)
  {
    if (bisect_stack[bisect_ptr - 18] >= 0)
    {
      if (bisect_stack[bisect_ptr - 19]< 0)
        bisect_stack[bisect_ptr - 17] = bisect_stack[bisect_ptr - 20] + bisect_stack[bisect_ptr - 19];
      else
        bisect_stack[bisect_ptr - 17] = bisect_stack[bisect_ptr - 20];
      bisect_stack[bisect_ptr - 16] = bisect_stack[bisect_ptr - 20] + bisect_stack[bisect_ptr - 19]+ bisect_stack[bisect_ptr - 18];
      if (bisect_stack[bisect_ptr - 16] < 0)
        bisect_stack[bisect_ptr - 16] = 0;
    }
    else
    {
      bisect_stack[bisect_ptr - 17] = bisect_stack[bisect_ptr - 20] + bisect_stack[bisect_ptr - 19]+ bisect_stack[bisect_ptr - 18];
      if (bisect_stack[bisect_ptr - 17] > bisect_stack[bisect_ptr - 20])
        bisect_stack[bisect_ptr - 17] = bisect_stack[bisect_ptr - 20];
      bisect_stack[bisect_ptr - 16] = bisect_stack[bisect_ptr - 20] + bisect_stack[bisect_ptr - 19];
      if (bisect_stack[bisect_ptr - 16] < 0)
        bisect_stack[bisect_ptr - 16] = 0;
    }
  }
  else if (bisect_stack[bisect_ptr - 18]<= 0)
  {
    if (bisect_stack[bisect_ptr - 19] > 0)
      bisect_stack[bisect_ptr - 16] = bisect_stack[bisect_ptr - 20] + bisect_stack[bisect_ptr - 19];
    else
      bisect_stack[bisect_ptr - 16] = bisect_stack[bisect_ptr - 20];
    bisect_stack[bisect_ptr - 17] = bisect_stack[bisect_ptr - 20] + bisect_stack[bisect_ptr - 19]+ bisect_stack[bisect_ptr - 18];
    if (bisect_stack[bisect_ptr - 17] > 0)
      bisect_stack[bisect_ptr - 17] = 0;
  }
  else
  {
    bisect_stack[bisect_ptr - 16] = bisect_stack[bisect_ptr - 20] + bisect_stack[bisect_ptr - 19]+ bisect_stack[bisect_ptr - 18];
    if (bisect_stack[bisect_ptr - 16]< bisect_stack[bisect_ptr - 20])
      bisect_stack[bisect_ptr - 16] = bisect_stack[bisect_ptr - 20];
    bisect_stack[bisect_ptr - 17] = bisect_stack[bisect_ptr - 20] + bisect_stack[bisect_ptr - 19];
    if (bisect_stack[bisect_ptr - 17] > 0)
      bisect_stack[bisect_ptr - 17] = 0;
  }
  delx = mem[p + 1].cint - mem[pp + 1].cint;
  dely = mem[p + 2].cint - mem[pp + 2].cint;
  tol = 0;
  uv = bisect_ptr;
  xy = bisect_ptr;
  three_l = 0;
  cur_t = 1;
  cur_tt = 1;
  while (true)
  {
  lab_continue:
    if (delx - tol <= bisect_stack[xy - 11] - bisect_stack[uv - 2])
    {
      if (delx + tol >= bisect_stack[xy - 12] - bisect_stack[uv - 1])
      {
        if (dely - tol <= bisect_stack[xy - 16] - bisect_stack[uv - 7])
        {
          if (dely + tol >= bisect_stack[xy - 17] - bisect_stack[uv - 6])
          {
            if (cur_t >= max_t)
            {
              if (max_t == two)
              {
                cur_t = half(cur_t + 1);
                cur_tt = half(cur_tt + 1);
                goto lab_exit;
              }
              max_t = max_t + max_t;
              appr_t = cur_t;
              appr_tt = cur_tt;
            }
            bisect_stack[bisect_ptr] = delx;
            bisect_stack[bisect_ptr + 1] = dely;
            bisect_stack[bisect_ptr + 2] = tol;
            bisect_stack[bisect_ptr + 3] = uv;
            bisect_stack[bisect_ptr + 4] = xy;
            bisect_ptr = bisect_ptr + 45;
            cur_t = cur_t + cur_t;
            cur_tt = cur_tt + cur_tt;
            bisect_stack[bisect_ptr - 25] = bisect_stack[uv - 5];
            bisect_stack[bisect_ptr - 3] = bisect_stack[uv - 3];
            bisect_stack[bisect_ptr - 24] = half(bisect_stack[bisect_ptr - 25]+ bisect_stack[uv - 4]);
            bisect_stack[bisect_ptr - 4] = half(bisect_stack[bisect_ptr - 3]+ bisect_stack[uv - 4]);
            bisect_stack[bisect_ptr - 23] = half(bisect_stack[bisect_ptr - 24]+ bisect_stack[bisect_ptr - 4]);
            bisect_stack[bisect_ptr - 5] = bisect_stack[bisect_ptr - 23];
            if (bisect_stack[bisect_ptr - 25]< 0)
            {
              if (bisect_stack[bisect_ptr - 23] >= 0)
              {
                if (bisect_stack[bisect_ptr - 24] < 0)
                  bisect_stack[bisect_ptr - 22] = bisect_stack[bisect_ptr - 25] + bisect_stack[bisect_ptr - 24];
                else
                  bisect_stack[bisect_ptr - 22] = bisect_stack[bisect_ptr - 25];
                bisect_stack[bisect_ptr - 21] = bisect_stack[bisect_ptr - 25]+ bisect_stack[bisect_ptr - 24]+ bisect_stack[bisect_ptr - 23];
                if (bisect_stack[bisect_ptr - 21]< 0)
                  bisect_stack[bisect_ptr - 21] = 0;
              }
              else
              {
                bisect_stack[bisect_ptr - 22] = bisect_stack[bisect_ptr - 25]+ bisect_stack[bisect_ptr - 24]+ bisect_stack[bisect_ptr - 23];
                if (bisect_stack[bisect_ptr - 22] > bisect_stack[bisect_ptr - 25])
                  bisect_stack[bisect_ptr - 22] = bisect_stack[bisect_ptr - 25];
                bisect_stack[bisect_ptr - 21] = bisect_stack[bisect_ptr - 25] + bisect_stack[bisect_ptr - 24];
                if (bisect_stack[bisect_ptr - 21] < 0)
                  bisect_stack[bisect_ptr - 21] = 0;
              }
            }
            else if (bisect_stack[bisect_ptr - 23]<= 0)
            {
              if (bisect_stack[bisect_ptr - 24] > 0)
                bisect_stack[bisect_ptr - 21] = bisect_stack[bisect_ptr - 25] + bisect_stack[bisect_ptr - 24];
              else
                bisect_stack[bisect_ptr - 21] = bisect_stack[bisect_ptr - 25];
              bisect_stack[bisect_ptr - 22] = bisect_stack[bisect_ptr - 25] + bisect_stack[bisect_ptr - 24]+ bisect_stack[bisect_ptr - 23];
              if (bisect_stack[bisect_ptr - 22] > 0)
                bisect_stack[bisect_ptr - 22] = 0;
            }
            else
            {
              bisect_stack[bisect_ptr - 21] = bisect_stack[bisect_ptr - 25] + bisect_stack[bisect_ptr - 24]+ bisect_stack[bisect_ptr - 23];
              if (bisect_stack[bisect_ptr - 21]< bisect_stack[bisect_ptr - 25])
                bisect_stack[bisect_ptr - 21] = bisect_stack[bisect_ptr - 25];
              bisect_stack[bisect_ptr - 22] = bisect_stack[bisect_ptr - 25] + bisect_stack[bisect_ptr - 24];
              if (bisect_stack[bisect_ptr - 22] > 0)
                bisect_stack[bisect_ptr - 22] = 0;
            }
            if (bisect_stack[bisect_ptr - 5]< 0)
            {
              if (bisect_stack[bisect_ptr - 3] >= 0)
              {
                if (bisect_stack[bisect_ptr - 4]< 0)
                  bisect_stack[bisect_ptr - 2] = bisect_stack[bisect_ptr - 5] + bisect_stack[bisect_ptr - 4];
                else
                  bisect_stack[bisect_ptr - 2] = bisect_stack[bisect_ptr - 5];
                bisect_stack[bisect_ptr - 1] = bisect_stack[bisect_ptr - 5] + bisect_stack[bisect_ptr - 4]+ bisect_stack[bisect_ptr - 3];
                if (bisect_stack[bisect_ptr - 1] < 0)
                  bisect_stack[bisect_ptr - 1] = 0;
              }
              else
              {
                bisect_stack[bisect_ptr - 2] = bisect_stack[bisect_ptr - 5] + bisect_stack[bisect_ptr - 4]+ bisect_stack[bisect_ptr - 3];
                if (bisect_stack[bisect_ptr - 2] > bisect_stack[bisect_ptr - 5])
                  bisect_stack[bisect_ptr - 2] = bisect_stack[bisect_ptr - 5];
                bisect_stack[bisect_ptr - 1] = bisect_stack[bisect_ptr - 5] + bisect_stack[bisect_ptr - 4];
                if (bisect_stack[bisect_ptr - 1] < 0)
                  bisect_stack[bisect_ptr - 1] = 0;
              }
            }
            else if (bisect_stack[bisect_ptr - 3]<= 0)
            {
              if (bisect_stack[bisect_ptr - 4] > 0)
                bisect_stack[bisect_ptr - 1] = bisect_stack[bisect_ptr - 5] + bisect_stack[bisect_ptr - 4];
              else
                bisect_stack[bisect_ptr - 1] = bisect_stack[bisect_ptr - 5];
              bisect_stack[bisect_ptr - 2] = bisect_stack[bisect_ptr - 5] + bisect_stack[bisect_ptr - 4]+ bisect_stack[bisect_ptr - 3];
              if (bisect_stack[bisect_ptr - 2] > 0)
                bisect_stack[bisect_ptr - 2] = 0;
            }
            else
            {
              bisect_stack[bisect_ptr - 1] = bisect_stack[bisect_ptr - 5] + bisect_stack[bisect_ptr - 4]+ bisect_stack[bisect_ptr - 3];
              if (bisect_stack[bisect_ptr - 1]< bisect_stack[bisect_ptr - 5])
                bisect_stack[bisect_ptr - 1] = bisect_stack[bisect_ptr - 5];
              bisect_stack[bisect_ptr - 2] = bisect_stack[bisect_ptr - 5] + bisect_stack[bisect_ptr - 4];
              if (bisect_stack[bisect_ptr - 2] > 0)
                bisect_stack[bisect_ptr - 2] = 0;
            }
            bisect_stack[bisect_ptr - 30] = bisect_stack[uv - 10];
            bisect_stack[bisect_ptr - 8] = bisect_stack[uv - 8];
            bisect_stack[bisect_ptr - 29] = half(bisect_stack[bisect_ptr - 30]+ bisect_stack[uv - 9]);
            bisect_stack[bisect_ptr - 9] = half(bisect_stack[bisect_ptr - 8] + bisect_stack[uv - 9]);
            bisect_stack[bisect_ptr - 28] = half(bisect_stack[bisect_ptr - 29]+ bisect_stack[bisect_ptr - 9]);
            bisect_stack[bisect_ptr - 10] = bisect_stack[bisect_ptr - 28];
            if (bisect_stack[bisect_ptr - 30] < 0)
            {
              if (bisect_stack[bisect_ptr - 28] >= 0)
              {
                if (bisect_stack[bisect_ptr - 29]< 0)
                  bisect_stack[bisect_ptr - 27] = bisect_stack[bisect_ptr - 30]+ bisect_stack[bisect_ptr - 29];
                else
                  bisect_stack[bisect_ptr - 27] = bisect_stack[bisect_ptr - 30];
                bisect_stack[bisect_ptr - 26] = bisect_stack[bisect_ptr - 30] + bisect_stack[bisect_ptr - 29]+ bisect_stack[bisect_ptr - 28];
                if (bisect_stack[bisect_ptr - 26] < 0)
                  bisect_stack[bisect_ptr - 26] = 0;
              }
              else
              {
                bisect_stack[bisect_ptr - 27] = bisect_stack[bisect_ptr - 30] + bisect_stack[bisect_ptr - 29]+ bisect_stack[bisect_ptr - 28];
                if (bisect_stack[bisect_ptr - 27] > bisect_stack[bisect_ptr - 30])
                  bisect_stack[bisect_ptr - 27] = bisect_stack[bisect_ptr - 30];
                bisect_stack[bisect_ptr - 26] = bisect_stack[bisect_ptr - 30]+ bisect_stack[bisect_ptr - 29];
                if (bisect_stack[bisect_ptr - 26] < 0)
                  bisect_stack[bisect_ptr - 26] = 0;
              }
            }
            else if (bisect_stack[bisect_ptr - 28] <= 0)
            {
              if (bisect_stack[bisect_ptr - 29] > 0)
                bisect_stack[bisect_ptr - 26] = bisect_stack[bisect_ptr - 30] + bisect_stack[bisect_ptr - 29];
              else
                bisect_stack[bisect_ptr - 26] = bisect_stack[bisect_ptr - 30];
              bisect_stack[bisect_ptr - 27] = bisect_stack[bisect_ptr - 30] + bisect_stack[bisect_ptr - 29]+ bisect_stack[bisect_ptr - 28];
              if (bisect_stack[bisect_ptr - 27] > 0)
                bisect_stack[bisect_ptr - 27] = 0;
            }
            else
            {
              bisect_stack[bisect_ptr - 26] = bisect_stack[bisect_ptr - 30] + bisect_stack[bisect_ptr - 29]+ bisect_stack[bisect_ptr - 28];
              if (bisect_stack[bisect_ptr - 26]< bisect_stack[bisect_ptr - 30])
                bisect_stack[bisect_ptr - 26] = bisect_stack[bisect_ptr - 30];
              bisect_stack[bisect_ptr - 27] = bisect_stack[bisect_ptr - 30] + bisect_stack[bisect_ptr - 29];
              if (bisect_stack[bisect_ptr - 27] > 0)
                bisect_stack[bisect_ptr - 27] = 0;
            }
            if (bisect_stack[bisect_ptr - 10] < 0)
            {
              if (bisect_stack[bisect_ptr - 8] >= 0)
              {
                if (bisect_stack[bisect_ptr - 9] < 0)
                 bisect_stack[bisect_ptr - 7] = bisect_stack[bisect_ptr - 10] + bisect_stack[bisect_ptr - 9];
                else
                  bisect_stack[bisect_ptr - 7] = bisect_stack[bisect_ptr - 10];
                bisect_stack[bisect_ptr - 6] = bisect_stack[bisect_ptr - 10] + bisect_stack[bisect_ptr - 9]+ bisect_stack[bisect_ptr - 8];
                if (bisect_stack[bisect_ptr - 6] < 0)
                  bisect_stack[bisect_ptr - 6] = 0;
              }
              else
              {
                bisect_stack[bisect_ptr - 7] = bisect_stack[bisect_ptr - 10] + bisect_stack[bisect_ptr - 9]+ bisect_stack[bisect_ptr - 8];
                if (bisect_stack[bisect_ptr - 7] > bisect_stack[bisect_ptr - 10])
                  bisect_stack[bisect_ptr - 7] = bisect_stack[bisect_ptr - 10];
                bisect_stack[bisect_ptr - 6] = bisect_stack[bisect_ptr - 10] + bisect_stack[bisect_ptr - 9];
                if (bisect_stack[bisect_ptr - 6] < 0)
                  bisect_stack[bisect_ptr - 6] = 0;
              }
            }
            else if (bisect_stack[bisect_ptr - 8] <= 0)
            {
              if (bisect_stack[bisect_ptr - 9] > 0)
                bisect_stack[bisect_ptr - 6] = bisect_stack[bisect_ptr - 10] + bisect_stack[bisect_ptr - 9];
              else
                bisect_stack[bisect_ptr - 6] = bisect_stack[bisect_ptr - 10];
              bisect_stack[bisect_ptr - 7] = bisect_stack[bisect_ptr - 10] + bisect_stack[bisect_ptr - 9]+ bisect_stack[bisect_ptr - 8];
              if (bisect_stack[bisect_ptr - 7] > 0)
                bisect_stack[bisect_ptr - 7] = 0;
            }
            else
            {
              bisect_stack[bisect_ptr - 6] = bisect_stack[bisect_ptr - 10] + bisect_stack[bisect_ptr - 9]+ bisect_stack[bisect_ptr - 8];
              if (bisect_stack[bisect_ptr - 6]< bisect_stack[bisect_ptr - 10])
                bisect_stack[bisect_ptr - 6] = bisect_stack[bisect_ptr - 10];
              bisect_stack[bisect_ptr - 7] = bisect_stack[bisect_ptr - 10] + bisect_stack[bisect_ptr - 9];
              if (bisect_stack[bisect_ptr - 7] > 0)
                bisect_stack[bisect_ptr - 7] = 0;
            }
            bisect_stack[bisect_ptr - 35] = bisect_stack[xy - 15];
            bisect_stack[bisect_ptr - 13] = bisect_stack[xy - 13];
            bisect_stack[bisect_ptr - 34] = half(bisect_stack[bisect_ptr - 35]+ bisect_stack[xy - 14]);
            bisect_stack[bisect_ptr - 14] = half(bisect_stack[bisect_ptr - 13]+ bisect_stack[xy - 14]);
            bisect_stack[bisect_ptr - 33] = half(bisect_stack[bisect_ptr - 34]+ bisect_stack[bisect_ptr - 14]);
            bisect_stack[bisect_ptr - 15] = bisect_stack[bisect_ptr - 33];
            if (bisect_stack[bisect_ptr - 35] < 0)
            {
              if (bisect_stack[bisect_ptr - 33] >= 0)
              {
                if (bisect_stack[bisect_ptr - 34] < 0)
                  bisect_stack[bisect_ptr - 32] = bisect_stack[bisect_ptr - 35]+ bisect_stack[bisect_ptr - 34];
                else
                  bisect_stack[bisect_ptr - 32] = bisect_stack[bisect_ptr - 35];
                bisect_stack[bisect_ptr - 31] = bisect_stack[bisect_ptr - 35]+ bisect_stack[bisect_ptr - 34]+ bisect_stack[bisect_ptr - 33];
                if (bisect_stack[bisect_ptr - 31] < 0)
                  bisect_stack[bisect_ptr - 31] = 0;
              }
              else
              {
                bisect_stack[bisect_ptr - 32] = bisect_stack[bisect_ptr - 35]+ bisect_stack[bisect_ptr - 34]+ bisect_stack[bisect_ptr - 33];
                if (bisect_stack[bisect_ptr - 32] > bisect_stack[bisect_ptr - 35])
                  bisect_stack[bisect_ptr - 32] = bisect_stack[bisect_ptr - 35];
                bisect_stack[bisect_ptr - 31] = bisect_stack[bisect_ptr - 35] + bisect_stack[bisect_ptr - 34];
                if (bisect_stack[bisect_ptr - 31] < 0)
                  bisect_stack[bisect_ptr - 31] = 0;
              }
            }
            else if (bisect_stack[bisect_ptr - 33] <= 0)
            {
              if (bisect_stack[bisect_ptr - 34] > 0)
                bisect_stack[bisect_ptr - 31] = bisect_stack[bisect_ptr - 35] + bisect_stack[bisect_ptr - 34];
              else
                bisect_stack[bisect_ptr - 31] = bisect_stack[bisect_ptr - 35];
              bisect_stack[bisect_ptr - 32] = bisect_stack[bisect_ptr - 35] + bisect_stack[bisect_ptr - 34]+ bisect_stack[bisect_ptr - 33];
              if (bisect_stack[bisect_ptr - 32] > 0)
                bisect_stack[bisect_ptr - 32] = 0;
            }
            else
            {
              bisect_stack[bisect_ptr - 31] = bisect_stack[bisect_ptr - 35] + bisect_stack[bisect_ptr - 34]+ bisect_stack[bisect_ptr - 33];
              if (bisect_stack[bisect_ptr - 31]< bisect_stack[bisect_ptr - 35])
                bisect_stack[bisect_ptr - 31] = bisect_stack[bisect_ptr - 35];
              bisect_stack[bisect_ptr - 32] = bisect_stack[bisect_ptr - 35] + bisect_stack[bisect_ptr - 34];
              if (bisect_stack[bisect_ptr - 32] > 0)
                bisect_stack[bisect_ptr - 32] = 0;
            }
            if (bisect_stack[bisect_ptr - 15] < 0)
            {
              if (bisect_stack[bisect_ptr - 13] >= 0)
              {
                if (bisect_stack[bisect_ptr - 14] < 0)
                  bisect_stack[bisect_ptr - 12] = bisect_stack[bisect_ptr - 15] + bisect_stack[bisect_ptr - 14];
                else
                  bisect_stack[bisect_ptr - 12] = bisect_stack[bisect_ptr - 15];
                bisect_stack[bisect_ptr - 11] = bisect_stack[bisect_ptr - 15]+ bisect_stack[bisect_ptr - 14]+ bisect_stack[bisect_ptr - 13];
                if (bisect_stack[bisect_ptr - 11] < 0)
                  bisect_stack[bisect_ptr - 11] = 0;
              }
              else
              {
                bisect_stack[bisect_ptr - 12] = bisect_stack[bisect_ptr - 15]+ bisect_stack[bisect_ptr - 14]+ bisect_stack[bisect_ptr - 13];
                if (bisect_stack[bisect_ptr - 12] > bisect_stack[bisect_ptr - 15])
                  bisect_stack[bisect_ptr - 12] = bisect_stack[bisect_ptr - 15];
                bisect_stack[bisect_ptr - 11] = bisect_stack[bisect_ptr - 15] + bisect_stack[bisect_ptr - 14];
                if (bisect_stack[bisect_ptr - 11] < 0)
                  bisect_stack[bisect_ptr - 11] = 0;
              }
            }
            else if (bisect_stack[bisect_ptr - 13]<= 0)
            {
              if (bisect_stack[bisect_ptr - 14] > 0)
                bisect_stack[bisect_ptr - 11] = bisect_stack[bisect_ptr - 15] + bisect_stack[bisect_ptr - 14];
              else
                bisect_stack[bisect_ptr - 11] = bisect_stack[bisect_ptr - 15];
              bisect_stack[bisect_ptr - 12] = bisect_stack[bisect_ptr - 15] + bisect_stack[bisect_ptr - 14]+ bisect_stack[bisect_ptr - 13];
              if (bisect_stack[bisect_ptr - 12] > 0)
                bisect_stack[bisect_ptr - 12] = 0;
            }
            else
            {
              bisect_stack[bisect_ptr - 11] = bisect_stack[bisect_ptr - 15] + bisect_stack[bisect_ptr - 14]+ bisect_stack[bisect_ptr - 13];
              if (bisect_stack[bisect_ptr - 11]< bisect_stack[bisect_ptr - 15])
                bisect_stack[bisect_ptr - 11] = bisect_stack[bisect_ptr - 15];
              bisect_stack[bisect_ptr - 12] = bisect_stack[bisect_ptr - 15] + bisect_stack[bisect_ptr - 14];
              if (bisect_stack[bisect_ptr - 12] > 0)
                bisect_stack[bisect_ptr - 12] = 0;
            }
            bisect_stack[bisect_ptr - 40] = bisect_stack[xy - 20];
            bisect_stack[bisect_ptr - 18] = bisect_stack[xy - 18];
            bisect_stack[bisect_ptr - 39] = half(bisect_stack[bisect_ptr - 40] + bisect_stack[xy - 19]);
            bisect_stack[bisect_ptr - 19] = half(bisect_stack[bisect_ptr - 18] + bisect_stack[xy - 19]);
            bisect_stack[bisect_ptr - 38] = half(bisect_stack[bisect_ptr - 39] + bisect_stack[bisect_ptr - 19]);
            bisect_stack[bisect_ptr - 20] = bisect_stack[bisect_ptr - 38];
            if (bisect_stack[bisect_ptr - 40] < 0)
            {
              if (bisect_stack[bisect_ptr - 38] >= 0)
              {
                if (bisect_stack[bisect_ptr - 39] < 0)
                  bisect_stack[bisect_ptr - 37] = bisect_stack[bisect_ptr - 40] + bisect_stack[bisect_ptr - 39];
                else
                  bisect_stack[bisect_ptr - 37] = bisect_stack[bisect_ptr - 40];
                bisect_stack[bisect_ptr - 36] = bisect_stack[bisect_ptr - 40] + bisect_stack[bisect_ptr - 39]+ bisect_stack[bisect_ptr - 38];
                if (bisect_stack[bisect_ptr - 36] < 0)
                  bisect_stack[bisect_ptr - 36] = 0;
              }
              else
              {
                bisect_stack[bisect_ptr - 37] = bisect_stack[bisect_ptr - 40]+ bisect_stack[bisect_ptr - 39]+ bisect_stack[bisect_ptr - 38];
                if (bisect_stack[bisect_ptr - 37] > bisect_stack[bisect_ptr - 40])
                  bisect_stack[bisect_ptr - 37] = bisect_stack[bisect_ptr - 40];
                bisect_stack[bisect_ptr - 36] = bisect_stack[bisect_ptr - 40]+ bisect_stack[bisect_ptr - 39];
                if (bisect_stack[bisect_ptr - 36] < 0)
                  bisect_stack[bisect_ptr - 36] = 0;
              }
            }
            else if (bisect_stack[bisect_ptr - 38]<= 0)
            {
              if (bisect_stack[bisect_ptr - 39] > 0)
                bisect_stack[bisect_ptr - 36] = bisect_stack[bisect_ptr - 40] + bisect_stack[bisect_ptr - 39];
              else
                bisect_stack[bisect_ptr - 36] = bisect_stack[bisect_ptr - 40];
              bisect_stack[bisect_ptr - 37] = bisect_stack[bisect_ptr - 40] + bisect_stack[bisect_ptr - 39]+ bisect_stack[bisect_ptr - 38];
              if (bisect_stack[bisect_ptr - 37] > 0)
                bisect_stack[bisect_ptr - 37] = 0;
            }
            else
            {
              bisect_stack[bisect_ptr - 36] = bisect_stack[bisect_ptr - 40] + bisect_stack[bisect_ptr - 39]+ bisect_stack[bisect_ptr - 38];
              if (bisect_stack[bisect_ptr - 36]< bisect_stack[bisect_ptr - 40])
                bisect_stack[bisect_ptr - 36] = bisect_stack[bisect_ptr - 40];
              bisect_stack[bisect_ptr - 37] = bisect_stack[bisect_ptr - 40] + bisect_stack[bisect_ptr - 39];
              if (bisect_stack[bisect_ptr - 37] > 0)
                bisect_stack[bisect_ptr - 37] = 0;
            }
            if (bisect_stack[bisect_ptr - 20] < 0)
            {
              if (bisect_stack[bisect_ptr - 18] >= 0)
              {
                if (bisect_stack[bisect_ptr - 19] < 0)
                  bisect_stack[bisect_ptr - 17] = bisect_stack[bisect_ptr - 20] + bisect_stack[bisect_ptr - 19];
                else
                  bisect_stack[bisect_ptr - 17] = bisect_stack[bisect_ptr - 20];
                bisect_stack[bisect_ptr - 16] = bisect_stack[bisect_ptr - 20] + bisect_stack[bisect_ptr - 19]+ bisect_stack[bisect_ptr - 18];
                if (bisect_stack[bisect_ptr - 16] < 0)
                  bisect_stack[bisect_ptr - 16] = 0;
              }
              else
              {
                bisect_stack[bisect_ptr - 17] = bisect_stack[bisect_ptr - 20] + bisect_stack[bisect_ptr - 19]+ bisect_stack[bisect_ptr - 18];
                if (bisect_stack[bisect_ptr - 17] > bisect_stack[bisect_ptr - 20])
                  bisect_stack[bisect_ptr - 17] = bisect_stack[bisect_ptr - 20];
                bisect_stack[bisect_ptr - 16] = bisect_stack[bisect_ptr - 20] + bisect_stack[bisect_ptr - 19];
                if (bisect_stack[bisect_ptr - 16] < 0)
                  bisect_stack[bisect_ptr - 16] = 0;
              }
            }
            else if (bisect_stack[bisect_ptr - 18]<= 0)
            {
              if (bisect_stack[bisect_ptr - 19] > 0)
                bisect_stack[bisect_ptr - 16] = bisect_stack[bisect_ptr - 20] + bisect_stack[bisect_ptr - 19];
              else
                bisect_stack[bisect_ptr - 16] = bisect_stack[bisect_ptr - 20];
              bisect_stack[bisect_ptr - 17] = bisect_stack[bisect_ptr - 20] + bisect_stack[bisect_ptr - 19] + bisect_stack[bisect_ptr - 18];
              if (bisect_stack[bisect_ptr - 17] > 0)
                bisect_stack[bisect_ptr - 17] = 0;
            }
            else
            {
              bisect_stack[bisect_ptr - 16] = bisect_stack[bisect_ptr - 20] + bisect_stack[bisect_ptr - 19]+ bisect_stack[bisect_ptr - 18];
              if (bisect_stack[bisect_ptr - 16]< bisect_stack[bisect_ptr - 20])
                bisect_stack[bisect_ptr - 16] = bisect_stack[bisect_ptr - 20];
              bisect_stack[bisect_ptr - 17] = bisect_stack[bisect_ptr - 20] + bisect_stack[bisect_ptr - 19];
              if (bisect_stack[bisect_ptr - 17] > 0)
                bisect_stack[bisect_ptr - 17] = 0;
            }
            uv = bisect_ptr - 20;
            xy = bisect_ptr - 20;
            delx = delx + delx;
            dely = dely + dely;
            tol = tol - three_l + tol_step;
            tol = tol + tol;
            three_l = three_l + tol_step;
            goto lab_continue;
          }
        }
      }
    }
    if (time_to_go > 0)
      decr(time_to_go);
    else
    {
      while (appr_t < unity)
      {
        appr_t = appr_t + appr_t;
        appr_tt = appr_tt + appr_tt;
      }
      cur_t = appr_t;
      cur_tt = appr_tt;
      goto lab_exit;
    }
  not_found:
    if (odd(cur_tt))
    {
      if (odd(cur_t))
      {
        cur_t = half(cur_t);
        cur_tt = half(cur_tt);
        if (cur_t == 0)
          goto lab_exit;
        bisect_ptr = bisect_ptr - 45;
        three_l = three_l - tol_step;
        delx = bisect_stack[bisect_ptr];
        dely = bisect_stack[bisect_ptr + 1];
        tol = bisect_stack[bisect_ptr + 2];
        uv = bisect_stack[bisect_ptr + 3];
        xy = bisect_stack[bisect_ptr + 4];
        goto not_found;
      }
      else
      {
        incr(cur_t);
        delx = delx + bisect_stack[uv - 5]+ bisect_stack[uv - 4]+
        bisect_stack[uv - 3];
        dely = dely + bisect_stack[uv - 10]+ bisect_stack[uv - 9]+
        bisect_stack[uv - 8];
        uv = uv + 20;
        decr(cur_tt);
        xy = xy - 20;
        delx = delx + bisect_stack[xy - 15]+ bisect_stack[xy - 14]+
        bisect_stack[xy - 13];
        dely = dely + bisect_stack[xy - 20]+ bisect_stack[xy - 19]+
        bisect_stack[xy - 18];
      }
    }
    else
    {
      incr(cur_tt);
      tol = tol + three_l;
      delx = delx - bisect_stack[xy - 15] - bisect_stack[xy - 14] -
      bisect_stack[xy - 13];
      dely = dely - bisect_stack[xy - 20] - bisect_stack[xy - 19] -
      bisect_stack[xy - 18];
      xy = xy + 20;
    }
  }
  lab_exit:;
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
              goto lab_exit;
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
  lab_exit:;
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
  if (r1 > screendepth)
    r1 = screendepth;
  if (r1 < r0)
  {
    if (r0 > screendepth)
      r0 = r1;
    else
      r1 = r0;
  }
  if (c0 < 0)
    c0 = 0;
  else
    c0 = round_unscaled(c0);
  c1 = round_unscaled(c1);
  if (c1 > screenwidth)
    c1 = screenwidth;
  if (c1 < c0)
  {
    if (c0 > screenwidth)
      c0 = c1;
    else
      c1 = c0;
  }
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
  {
    if (!screen_started)
    {
      screen_OK = initscreen();
      screen_started = true;
    }
  }
  if (screen_OK)
  {
    blankrectangle (c0, c1, r0, r1);
    updatescreen();
  }
}
/* 577 */
void disp_edges (window_number k)
{
  halfword p, q;
  boolean alreadythere;
  integer r;
  screen_col n;
  integer w, ww;
  pixel_color b;
  integer m, mm;
  integer d;
  integer madjustment;
  integer rightedge;
  screen_col mincol;

  if (screen_OK)
  {
    if (left_col[k] < right_col[k])
    {
      if (top_row[k] < bot_row[k])
      {
        alreadythere = false;
        if (mem[cur_edges + 3].hh.rh == k)
        {
          if (mem[cur_edges + 4].cint == window_time[k])
            alreadythere = true;
        }
        if (!alreadythere)
          blankrectangle (left_col[k], right_col[k], top_row[k],
        bot_row[k]);
        madjustment = m_window[k] - mem[cur_edges + 3].hh.lh;
        rightedge = 8 * (right_col[k] - madjustment);
        mincol = left_col[k];
        p = mem[cur_edges].hh.rh;
        r = n_window[k] - (mem[cur_edges + 1].hh.lh - 4096);
        while ((p != cur_edges) && (r >= top_row[k]))
        {
          if (r < bot_row[k])
          {
            if (mem[p + 1].hh.lh > 1)
              sort_edges (p);
            else if (mem[p + 1].hh.lh == 1)
            {
              if (alreadythere)
                goto done;
            }
            mem[p + 1].hh.lh = 1;
            n = 0;
            ww = 0;
            m = -1;
            w = 0;
            q = mem[p + 1].hh.rh;
            row_transition[0] = mincol;
            while (true)
            {
              if (q == mem_top)
                d = rightedge;
              else
                d = mem[q].hh.lh;
              mm = (d / 8) + madjustment;
              if (mm != m)
              {
                if (w <= 0)
                {
                  if (ww > 0)
                  {
                    if (m > mincol)
                    {
                      if (n == 0)
                      {
                        if (alreadythere)
                        {
                          b = 0;
                          incr(n);
                        }
                        else
                          b = 1;
                      }
                      else
                        incr(n);
                      row_transition[n] = m;
                    }
                  }
                }
                else if (ww <= 0)
                {
                  if (m > mincol)
                  {
                    if (n == 0)
                      b = 1;
                    incr(n);
                    row_transition[n] = m;
                  }
                }
                m = mm;
                w = ww;
              }
              if (d >= rightedge)
                goto found;
              ww = ww + (d % 8) - 4;
              q = mem[q].hh.rh;
            }
            found: if (alreadythere || (ww > 0))
            {
              if (n == 0)
              {
                if (ww > 0)
                  b = 1;
                else
                  b = 0;
              }
              incr(n);
              row_transition[n] = right_col[k];
            }
            else if (n == 0)
              goto done;
            paintrow (r, b, row_transition, n);
            done:;
          }
          p = mem[p].hh.rh;
          decr(r);
        }
        updatescreen();
        incr(window_time[k]);
        mem[cur_edges + 3].hh.rh = k;
        mem[cur_edges + 4].cint = window_time[k];
      }
    }
  }
}
/* 495 */
fraction max_coef (pointer p)
{
  fraction Result;
  fraction x;

  x = 0;
  while (info(p) != null)
  {
    if (abs(value(p)) > x)
      x = abs(value(p));
    p = link(p);
  }
  Result = x;
  return Result;
}
/* 597 */
halfword p_plus_q (halfword p, halfword q, small_number t)
{
  halfword Result;
  halfword pp, qq;
  halfword r, s;
  integer threshold;
  integer v;

  if (t == 17)
    threshold = 2685;
  else
    threshold = 8;
  r = mem_top - 1;
  pp = mem[p].hh.lh;
  qq = mem[q].hh.lh;
  while (true) if (pp == qq)
  {
    if (pp == 0)
      goto done;
    else
    {
      v = mem[p + 1].cint + mem[q + 1].cint;
      mem[p + 1].cint = v;
      s = p;
      p = mem[p].hh.rh;
      pp = mem[p].hh.lh;
      if (abs(v) < threshold)
        free_node (s, 2);
      else
      {
        if (abs(v) >= 626349397L)
        {
          if (watch_coefs)
          {
            mem[qq].hh.b0 = 0;
            fix_needed = true;
          }
        }
        mem[r].hh.rh = s;
        r = s;
      }
      q = mem[q].hh.rh;
      qq = mem[q].hh.lh;
    }
  }
  else if (mem[pp + 1].cint < mem[qq + 1].cint)
  {
    s = get_node (2);
    mem[s].hh.lh = qq;
    mem[s + 1].cint = mem[q + 1].cint;
    q = mem[q].hh.rh;
    qq = mem[q].hh.lh;
    mem[r].hh.rh = s;
    r = s;
  }
  else
  {
    mem[r].hh.rh = p;
    r = p;
    p = mem[p].hh.rh;
    pp = mem[p].hh.lh;
  }
  done: mem[p + 1].cint = slow_add (mem[p + 1].cint, mem[q + 1].cint);
  mem[r].hh.rh = p;
  dep_final = p;
  Result = mem[mem_top - 1].hh.rh;
  return Result;
}
/* 599 */
halfword p_times_v (halfword p, integer v, small_number t0, small_number t1, boolean v_is_scaled)
{
  halfword Result;
  halfword r, s;
  integer w;
  integer threshold;
  boolean scalingdown;

  if (t0 != t1)
    scalingdown = true;
  else
    scalingdown = !v_is_scaled;
  if (t1 == 17)
    threshold = 1342;
  else
    threshold = 4;
  r = mem_top - 1;
  while (mem[p].hh.lh != 0)
  {
    if (scalingdown)
      w = take_fraction (v, mem[p + 1].cint);
    else
      w = take_scaled (v, mem[p + 1].cint);
    if (abs(w) <= threshold)
    {
      s = mem[p].hh.rh;
      free_node (p, 2);
      p = s;
    }
    else
    {
      if (abs(w) >= 626349397L)
      {
        fix_needed = true;
        mem[mem[p].hh.lh].hh.b0 = 0;
      }
      mem[r].hh.rh = p;
      r = p;
      mem[p + 1].cint = w;
      p = mem[p].hh.rh;
    }
  }
  mem[r].hh.rh = p;
  if (v_is_scaled)
    mem[p + 1].cint = take_scaled (mem[p + 1].cint, v);
  else
    mem[p + 1].cint = take_fraction (mem[p + 1].cint, v);
  Result = mem[mem_top - 1].hh.rh;
  return Result;
}
/* 601 */
halfword p_with_x_becoming_q (halfword p, halfword x, halfword q, small_number t)
{
  halfword Result;
  halfword r, s;
  integer v;
  integer sx;

  s = p;
  r = mem_top - 1;
  sx = mem[x + 1].cint;
  while (mem[mem[s].hh.lh + 1].cint > sx)
  {
    r = s;
    s = mem[s].hh.rh;
  }
  if (mem[s].hh.lh != x)
    Result = p;
  else
  {
    mem[mem_top - 1].hh.rh = p;
    mem[r].hh.rh = mem[s].hh.rh;
    v = mem[s + 1].cint;
    free_node (s, 2);
    Result = p_plus_fq (mem[mem_top - 1].hh.rh, v, q, t, 17);
  }
  return Result;
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
  pointer Result;

  dep_final = get_node(dep_node_size);
  value(dep_final) = v;
  info(dep_final) = null;
  Result = dep_final;
  return Result;
}
/* 608 */
pointer single_dependency (pointer p)
{
  pointer Result;
  pointer q;
  integer m;

  m = value(p) % s_scale;
  if (m > 28)
    Result = const_dependency(0);
  else
  {
    q = get_node(dep_node_size);
    value(q) = two_to_the[28 - m];
    info(q) = p;
    link(q) = const_dependency(0);
    Result = q;
  }
  return Result;
}
/* 609 */
pointer copy_dep_list (pointer p)
{
  pointer Result;
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
  done: Result = q;
  return Result;
}
/* 610 */
void linear_eq (halfword p, small_number t)
{
  halfword q, r, s;
  halfword x;
  integer n;
  integer v;
  halfword prevr;
  halfword finalnode;
  integer w;

  q = p;
  r = mem[p].hh.rh;
  v = mem[q + 1].cint;
  while (mem[r].hh.lh != 0)
  {
    if (abs(mem[r + 1].cint) > abs(v))
    {
      q = r;
      v = mem[r + 1].cint;
    }
    r = mem[r].hh.rh;
  }
  x = mem[q].hh.lh;
  n = mem[x + 1].cint % 64;
  s = mem_top - 1;
  mem[s].hh.rh = p;
  r = p;
  do {
    if (r == q)
    {
      mem[s].hh.rh = mem[r].hh.rh;
      free_node (r, 2);
    }
    else
    {
      w = make_fraction (mem[r + 1].cint, v);
      if (abs(w) <= 1342)
      {
        mem[s].hh.rh = mem[r].hh.rh;
        free_node (r, 2);
      }
      else
      {
        mem[r + 1].cint = -w;
        s = r;
      }
    }
    r = mem[s].hh.rh;
  } while (!(mem[r].hh.lh == 0));
  if (t == 18)
    mem[r + 1].cint = -make_scaled (mem[r + 1].cint, v);
  else if (v != -fraction_one)
    mem[r + 1].cint = -make_fraction (mem[r + 1].cint, v);
  finalnode = r;
  p = mem[mem_top - 1].hh.rh;
  if (internal[tracing_equations] > 0)
  {
    if (interesting (x))
    {
      begin_diagnostic();
      print_nl(597);
      print_variable_name(x);
      w = n;
      while (w > 0)
      {
        print(590);
        w = w - 2;
      }
      print_char('=');
      print_dependency(p, 17);
      end_diagnostic (false);
    }
  }
  prevr = 13;
  r = mem[13].hh.rh;
  while (r != 13)
  {
    s = mem[r + 1].hh.rh;
    q = p_with_x_becoming_q (s, x, p, mem[r].hh.b0);
    if (mem[q].hh.lh == 0)
      make_known (r, q);
    else
    {
      mem[r + 1].hh.rh = q;
      do {
        q = mem[q].hh.rh;
      } while (!(mem[q].hh.lh == 0));
      prevr = q;
    }
    r = mem[prevr].hh.rh;
  }
  if (n > 0)
  {
    s = mem_top - 1;
    mem[mem_top - 1].hh.rh = p;
    r = p;
    do {
      if (n > 30)
        w = 0;
      else
        w = mem[r + 1].cint / two_to_the[n];
      if ((abs(w) <= 1342) && (mem[r].hh.lh != 0))
      {
        mem[s].hh.rh = mem[r].hh.rh;
        free_node (r, 2);
      }
      else
      {
        mem[r + 1].cint = w;
        s = r;
      }
      r = mem[s].hh.rh;
    } while (!(mem[s].hh.lh == 0));
    p = mem[mem_top - 1].hh.rh;
  }
  if (mem[p].hh.lh == 0)
  {
    mem[x].hh.b0 = 16;
    mem[x + 1].cint = mem[p + 1].cint;
    if (abs(mem[x + 1].cint) >= fraction_one)
      val_too_big (mem[x + 1].cint);
    free_node (p, 2);
    if (cur_exp == x)
    {
      if (cur_type == 19)
      {
        cur_exp = mem[x + 1].cint;
        cur_type = 16;
        free_node (x, 2);
      }
    }
  }
  else
  {
    mem[x].hh.b0 = 17;
    dep_final = finalnode;
    new_dep (x, p);
    if (cur_exp == x)
    {
      if (cur_type == 19)
        cur_type = 17;
    }
  }
  if (fix_needed)
    fix_dependencies();
}
/* 619 */
pointer new_ring_entry (pointer p)
{
  pointer Result;
  pointer q;

  q = get_node(value_node_size);
  name_type(q) = capsule;
  type(q) = type(p);
  if (value(p) == null)
    value(q) = p;
  else
    value(q) = value(p);
  value(p) = q;
  Result = q;
  return Result;
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
      goto lab_exit;
    }
    r = value(r);
  }
  r = value(p);
  value(p) = value(q);
  value(q) = r;
  lab_exit:;
}
/* 626 */
void show_cmd_mod (integer c, integer m)
{
  begin_diagnostic();
  print_nl(123);
  print_cmd_mod (c, m);
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
    if ((file_ptr == input_ptr) || (index <= 15) || (index != 19) || (loc != 0))
    {
      tally = 0;
      old_setting = selector;
      if ((index <= 15))
      {
        if (name <= 1)
        {
          if ((name == 0) && (file_ptr == 0))
            print_nl(604);
          else
            print_nl(605);
        }
        else if (name == 2)
          print_nl(606);
        else
        {
          print_nl(607);
          print_int(line);
        }
        print_char(' ');
        {
          l = tally;
          tally = 0;
          selector = pseudo;
          trick_count = 1000000L;
        }
        if (limit > 0)
        {
          for (i = start; i <= limit - 1; i++)
          {
            if (i == loc)
            {
              first_count = tally;
              trick_count = tally + 1 + error_line - half_error_line;
              if (trick_count < error_line)
                trick_count = error_line;
            }
            print(buffer[i]);
          }
        }
      }
      else
      {
        switch (index)
        {
          case 16:
            print_nl(608);
            break;
          case 17:
            {
              print_nl(613);
              p = param_stack[limit];
              if (p != 0)
              {
                if (mem[p].hh.rh == 1)
                  print_exp (p, 0);
                else
                  show_token_list (p, 0, 20, tally);
              }
              print(614);
            }
            break;
          case 18:
            print_nl(609);
            break;
          case 19:
            if (loc == 0)
              print_nl(610);
            else
              print_nl(611);
            break;
          case 20:
            print_nl(612);
            break;
          case 21:
            {
              print_ln();
              if (name != 0)
                slow_print(hash[name].rh);
              else
              {
                p = param_stack[limit];
                if (p == 0)
                  show_token_list (param_stack[limit + 1], 0, 20, tally);
                else
                {
                  q = p;
                  while (mem[q].hh.rh != 0)
                    q = mem[q].hh.rh;
                  mem[q].hh.rh = param_stack[limit + 1];
                  show_token_list (p, 0, 20, tally);
                  mem[q].hh.rh = 0;
                }
              }
              print(501);
            }
            break;
          default:
            print_nl(63);
            break;
        }
        {
          l = tally;
          tally = 0;
          selector = pseudo;
          trick_count = 1000000L;
        }
        if (index != 21)
          show_token_list (start, loc, 100000L, 0);
        else
          show_macro (start, loc, 100000L);
      }
      selector = old_setting;
      if (trick_count == 1000000L)
      {
        first_count = tally;
        trick_count = tally + 1 + error_line - half_error_line;
        if (trick_count < error_line)
          trick_count = error_line;
      }
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
        print(276);
        p = l + first_count - half_error_line + 3;
        n = half_error_line;
      }
      for (q = p; q <= first_count - 1; q++)
      {
        print_char(trick_buf[q % error_line]);
      }
      print_ln();
      for (q = 1; q <= n; q++)
      {
        print_char(' ');
      }
      if (m + n <= error_line)
        p = first_count + m;
      else
        p = first_count + (error_line - n - 3);
      for (q = first_count; q <= p - 1; q++)
      {
        print_char(trick_buf[q % error_line]);
      }
      if (m + n > error_line)
        print(276);
    }
    if ((index <= 15))
    {
      if ((name > 2) || (file_ptr == 0))
        goto done;
    }
    decr(file_ptr);
  }
  done: cur_input = input_stack[input_ptr];
}
/* 649 */
void begin_token_list (halfword p, quarterword t)
{
  {
    if (input_ptr > max_in_stack)
    {
      max_in_stack = input_ptr;
      if (input_ptr == stack_size)
        overflow("input stack size", stack_size);
    }
    input_stack[input_ptr] = cur_input;
    incr(input_ptr);
  }
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
  {
    if (index <= inserted)
    {
      flush_token_list(start);
      goto done;
    }
    else
      delete_mac_ref(start);
  }
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
void encapsulate (halfword p)
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
void make_exp_copy (halfword p)
{
  halfword q, r, t;

lab_restart:
  cur_type = mem[p].hh.b0;
  switch (cur_type)
  {
    case 1:
    case 2:
    case 16:
      cur_exp = mem[p + 1].cint;
      break;
    case 3:
    case 5:
    case 7:
    case 12:
    case 10:
      cur_exp = new_ring_entry (p);
      break;
    case 4:
      {
        cur_exp = mem[p + 1].cint;
        {
          if (str_ref[cur_exp] < 127)
            incr(str_ref[cur_exp]);
        }
      }
      break;
    case 6:
      {
        cur_exp = mem[p + 1].cint;
        incr(mem[cur_exp].hh.lh);
      }
      break;
    case 11:
      cur_exp = copy_edges (mem[p + 1].cint);
      break;
    case 9:
    case 8:
      cur_exp = copy_path (mem[p + 1].cint);
      break;
    case 13:
    case 14:
      {
        if (mem[p + 1].cint == 0)
          init_big_node (p);
        t = get_node (2);
        mem[t].hh.b1 = 11;
        mem[t].hh.b0 = cur_type;
        init_big_node (t);
        q = mem[p + 1].cint + big_node_size[cur_type];
        r = mem[t + 1].cint + big_node_size[cur_type];
        do {
          q = q - 2;
          r = r - 2;
          install (r, q);
        } while (!(q == mem[p + 1].cint));
        cur_exp = t;
      }
      break;
    case 17:
    case 18:
      encapsulate (copy_dep_list (mem[p + 1].hh.rh));
      break;
    case 15:
      {
        {
          if (serial_no > 2147483583L)
            overflow("independent variables", serial_no / 64);
          mem[p].hh.b0 = 19;
          serial_no = serial_no + 64;
          mem[p + 1].cint = serial_no;
        }
        goto lab_restart;
      }
      break;
    case 19:
      {
        q = single_dependency (p);
        if (q == dep_final)
        {
          cur_type = 16;
          cur_exp = 0;
          free_node (q, 2);
        }
        else
        {
          cur_type = 17;
          encapsulate (q);
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
  pointer Result;
  pointer p;
  small_number save_type;
  integer save_exp;

  if (cur_sym == 0)
  {
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
  }
  else
  {
    fast_get_avail(p);
    info(p) = cur_sym;
  }
  Result = p;
  return Result;
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
  if (in_open == 15)
    overflow("text input levels", 15);
  if (first == buf_size)
    overflow("buffer size", buf_size);
  incr(in_open);
  {
    if (input_ptr > max_in_stack)
    {
      max_in_stack = input_ptr;
      if (input_ptr == stack_size)
        overflow("input stack size", stack_size);
    }
    input_stack[input_ptr] = cur_input;
    incr(input_ptr);
  }
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
    a_close(input_file[index]);
  pop_input();
  decr(in_open);
}
/* 656 */
void clear_for_error_prompt (void)
{
  while (file_state && terminal_input && (input_ptr > 0) && (loc == limit))
    end_file_reading();
  print_ln();
}
/* 661 */
boolean check_outer_validity (void)
{
  boolean Result;
  halfword p;

  if (scanner_status == 0)
    Result = true;
  else
  {
    deletions_allowed = false;
    if (cur_sym != 0)
    {
      p = get_avail();
      mem[p].hh.lh = cur_sym;
      begin_token_list (p, 19);
    }
    if (scanner_status > 1)
    {
      runaway();
      if (cur_sym == 0)
        print_err("File ended");
      else
      {
        print_err("Forbidden token found");
      }
      print(625);
      help4("I suspect you have forgotten an `enddef',",
        "causing me to read past where you wanted me to stop.",
        "I'll try to recover; but if the error is serious,",
        "you'd better type `E' or `X' now and fix your file.");
      switch (scanner_status)
      {
        case 2:
          {
            print(630);
            help_line[3] = 631;
            cur_sym = 9763;
          }
          break;
        case 3:
          {
            print(632);
            help_line[3] = 633;
            if (warning_info == 0)
              cur_sym = 9767;
            else
            {
              cur_sym = 9759;
              eqtb[9759].rh = warning_info;
            }
          }
          break;
        case 4:
        case 5:
          {
            print(634);
            if (scanner_status == 5)
              slow_print(hash[warning_info].rh);
            else
              print_variable_name(warning_info);
            cur_sym = 9765;
          }
          break;
        case 6:
          {
            print(635);
            slow_print(hash[warning_info].rh);
            print(636);
            help_line[3] = 637;
            cur_sym = 9764;
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
        help_line[2] = 622;
      cur_sym = 9766;
      ins_error();
    }
    deletions_allowed = true;
    Result = false;
  }
  return Result;
}
void firm_up_the_line(void);
/* 667 */
void get_next (void)
{
  integer k;
  ASCII_code c;
  ASCII_code cclass;
  integer n, f;

lab_restart:
  cur_sym = 0;
  if ((index <= 15))
  {
lab25:
    c = buffer[loc];
    incr(loc);
    cclass = char_class[c];
    switch (cclass)
    {
      case 0:
        goto lab85;
        break;
      case 1:
        {
          cclass = char_class[buffer[loc]];
          if (cclass > 1)
            goto lab25;
          else if (cclass < 1)
          {
            n = 0;
            goto lab86;
          }
        }
        break;
      case 2:
        goto lab25;
        break;
      case 3:
        {
          if (name > 2)
          {
            incr(line);
            first = start;
            if (!force_eof)
            {
              if (inputln (input_file[index], true))
                firm_up_the_line();
              else
                force_eof = true;
            }
            if (force_eof)
            {
              print_char(')');
              decr(open_parens);
              fflush (stdout);
              force_eof = false;
              end_file_reading();
              if (check_outer_validity ())
                goto lab_restart;
              else
                goto lab_restart;
            }
            buffer[limit] = 37;
            first = limit + 1;
            loc = start;
          }
          else
          {
            if (input_ptr > 0)
            {
              end_file_reading();
              goto lab_restart;
            }
            if (selector < 2)
              open_log_file();
            if (interaction > nonstop_mode)
            {
              if (limit == start)
                print_nl(652);
              print_ln();
              first = start;
              prompt_input("*");
              limit = last;
              buffer[limit] = 37;
              first = limit + 1;
              loc = start;
            }
            else
              fatal_error("*** (job aborted, no legal end found)");
          }
          check_interrupt();
          goto lab25;
        }
        break;
      case 4:
        {
          if (buffer[loc] == 34)
            cur_mod = 261;
          else
          {
            k = loc;
            buffer[limit + 1] = 34;
            do {
              incr(loc);
            } while (!(buffer[loc] == 34));
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
              goto lab_restart;
            }
            if ((loc == k + 1) && ((str_start[buffer[k] + 1] - str_start[buffer[k]]) == 1))
              cur_mod = buffer[k];
            else
            {
              {
                if (pool_ptr + loc - k > max_pool_ptr)
                {
                  if (pool_ptr + loc - k > pool_size)
                    overflow("pool size", pool_size - init_pool_ptr);
                  max_pool_ptr = pool_ptr + loc - k;
                }
              }
              do {
                {
                  str_pool[pool_ptr] = buffer[k];
                  incr(pool_ptr);
                }
                incr(k);
              } while (!(k == loc));
              cur_mod = make_string();
            }
          }
          incr(loc);
          cur_cmd = string_token;
          goto lab_exit;
        }
        break;
      case 5:
      case 6:
      case 7:
      case 8:
        {
          k = loc - 1;
          goto found;
        }
        break;
      case 20:
        {
          print_err("Text line contains an invalid character");
          help2("A funny symbol that I can't read has just been input.",
            "Continue, and I'll forget that it ever happened.");
          deletions_allowed = false;
          error();
          deletions_allowed = true;
          goto lab_restart;
        }
        break;
      default:
        ;
        break;
    }
    k = loc - 1;
    while (char_class[buffer[loc]] == cclass)
      incr(loc);
    goto found;
  lab85:
    n = c - 48;
    while (char_class[buffer[loc]] == 0)
    {
      if (n < 4096)
        n = 10 * n + buffer[loc] - 48;
      incr(loc);
    }
    if (buffer[loc] == 46)
    {
      if (char_class[buffer[loc + 1]] == 0)
        goto done;
    }
    f = 0;
    goto lab87;
  done:
    incr(loc);
  lab86:
    k = 0;
    do {
      if (k < 17)
      {
        dig[k] = buffer[loc] - 48;
        incr(k);
      }
      incr(loc);
    } while (!(char_class[buffer[loc]]!= 0));
    f = round_decimals (k);
    if (f == unity)
    {
      incr(n);
      f = 0;
    }
  lab87:
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
      cur_mod = 268435455L;
    }
    cur_cmd = numeric_token;
    goto lab_exit;
  found:
    cur_sym = id_lookup (k, loc - k);
  }
  else if (loc >= hi_mem_min)
  {
    cur_sym = mem[loc].hh.lh;
    loc = mem[loc].hh.rh;
    if (cur_sym >= 9770)
    {
      if (cur_sym >= 9920)
      {
        if (cur_sym >= 10070)
        cur_sym = cur_sym - 150;
        begin_token_list (param_stack[limit + cur_sym - (9920)], 18);
        goto lab_restart;
      }
      else
      {
        cur_cmd = capsule_token;
        cur_mod = param_stack[limit + cur_sym - (9770)];
        cur_sym = 0;
        goto lab_exit;
      }
    }
  }
  else if (loc > 0)
  {
    if (mem[loc].hh.b1 == 12)
    {
      cur_mod = mem[loc + 1].cint;
      if (mem[loc].hh.b0 == 16)
        cur_cmd = numeric_token;
      else
      {
        cur_cmd = string_token;
        {
          if (str_ref[cur_mod]< 127)
            incr(str_ref[cur_mod]);
        }
      }
    }
    else
    {
      cur_mod = loc;
      cur_cmd = capsule_token;
    }
    loc = mem[loc].hh.rh;
    goto lab_exit;
  }
  else
  {
    end_token_list();
    goto lab_restart;
  }
  cur_cmd = eqtb[cur_sym].lh;
  cur_mod = eqtb[cur_sym].rh;
  if (cur_cmd >= outer_tag)
  {
    if (check_outer_validity ())
      cur_cmd = cur_cmd - outer_tag;
    else
      goto lab_restart;
  }
  lab_exit:;
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
        {
          buffer[k + start - first] = buffer[k];
        }
        limit = start + last - first;
      }
    }
  }
}
/* 685 */
pointer scan_toks (command_code terminator, pointer subst_list, pointer tail_end, small_number suffix_count)
{
  pointer Result;
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
      {
        if (cur_mod > 0)
          incr(balance);
        else
        {
          decr(balance);
          if (balance == 0)
            goto done;
        }
      }
      else if (cur_cmd == macro_special)
      {
        if (cur_mod == 0)
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
  Result = link(hold_head);
  return Result;
}
/* 691 */
void get_symbol (void)
{
lab_restart:
  get_next();
  if ((cur_sym == 0) || (cur_sym > frozen_inaccessible))
  {
    print_err("Missing symbolic token inserted");
    help3("Sorry: You can't redefine a number, string, or expr.",
      "I've inserted an inaccessible symbol so that your",
      "definition will be completed without mixing me up too badly.");
    if (cur_sym > 0)
      help_line[2] = 670;
    else if (cur_cmd == string_token)
      delete_str_ref(cur_mod);
    cur_sym = frozen_inaccessible;
    ins_error();
    goto lab_restart;
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
  {
    if (cur_cmd != assignment)
    {
      missing_err(61);
      help5("The next thing in this `def' should have been `=',",
        "because I've already looked at the definition heading.",
        "But don't worry; I'll pretend that an equals sign",
        "was present. Everything from here to `enddef'",
        "will be the replacement text of this macro.");
      back_error();
    }
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
void check_delimiter (pointer ldelim, pointer rdelim)
{
  if (cur_cmd == right_delimiter)
  {
    if (cur_mod == ldelim)
      goto lab_exit;
  }
  if (cur_sym != rdelim)
  {
    missing_err(hash[rdelim].rh);
    help2("I found no right delimiter to match a left one. So I've",
      "put one in, behind the scenes; this may fix the problem.");
    back_error();
  }
  else
  {
    print_err("The token `");
    slow_print(hash[rdelim].rh);
    print(925);
    help3("Strange: This token has lost its former meaning!",
      "I'll read it as a right delimiter this time;",
      "but watch out, I'll probably miss it later.");
    error();
  }
  lab_exit:;
}
/* 1011 */
pointer scan_declared_variable (void)
{
  pointer Result;
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
    {
      if (cur_cmd != internal_quantity)
      {
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
      }
    }
    link(t) = get_avail();
    t = link(t);
    info(t) = cur_sym;
  }
done:
  if (eq_type(x) % outer_tag != tag_token)
    clear_symbol(x, false);
  if (equiv(x) == null)
    new_root(x);
  Result = h;
  return Result;
}
/* 697 */
void scan_def (void)
{
  unsigned char m;
  unsigned char n;
  unsigned char k;
  unsigned char c;
  halfword r;
  halfword q;
  halfword p;
  halfword base;
  halfword ldelim, rdelim;

  m = cur_mod;
  c = 0;
  mem[mem_top - 2].hh.rh = 0;
  q = get_avail();
  mem[q].hh.lh = 0;
  r = 0;
  if (m == 1)
  {
    get_clear_symbol();
    warning_info = cur_sym;
    get_next();
    scanner_status = 5;
    n = 0;
    eqtb[warning_info].lh = 10;
    eqtb[warning_info].rh = q;
  }
  else
  {
    p = scan_declared_variable();
    flush_variable (eqtb[mem[p].hh.lh].rh, mem[p].hh.rh, true);
    warning_info = find_variable (p);
    flush_list (p);
    if (warning_info == 0)
    {
      print_err("This variable already starts with a macro");
      help2("After `vardef a' you can't say `vardef a.b'.",
        "So I'll have to discard this definition.");
      error();
      warning_info = 21;
    }
    scanner_status = 4;
    n = 2;
    if (cur_cmd == macro_special)
    {
      if (cur_mod == 3)
      {
        n = 3;
        get_next();
      }
    }
    mem[warning_info].hh.b0 = 20 + n;
    mem[warning_info + 1].cint = q;
  }
  k = n;
  if (cur_cmd == left_delimiter)
    do {
      ldelim = cur_sym;
      rdelim = cur_mod;
      get_next();
      if ((cur_cmd == param_type) && (cur_mod >= 9770))
        base = cur_mod;
      else
      {
        print_err("Missing parameter type; `expr' will be assumed");
        help1("You should've had `expr' or `suffix' or `text' here.");
        back_error();
        base = 9770;
      }
      do {
        mem[q].hh.rh = get_avail();
        q = mem[q].hh.rh;
        mem[q].hh.lh = base + k;
        get_symbol();
        p = get_node (2);
        mem[p + 1].cint = base + k;
        mem[p].hh.lh = cur_sym;
        if (k == 150)
          overflow("parameter stack size", 150);
        incr(k);
        mem[p].hh.rh = r;
        r = p;
        get_next();
      } while (!(cur_cmd != comma));
      check_delimiter (ldelim, rdelim);
      get_next();
    } while (!(cur_cmd != left_delimiter));
  if (cur_cmd == param_type)
  {
    p = get_node (2);
    if (cur_mod < 9770)
    {
      c = cur_mod;
      mem[p + 1].cint = 9770 + k;
    }
    else
    {
      mem[p + 1].cint = cur_mod + k;
      if (cur_mod == 9770)
        c = 4;
      else if (cur_mod == 9920)
        c = 6;
      else
        c = 7;
    }
    if (k == 150)
      overflow("parameter stack size", 150);
    incr(k);
    get_symbol();
    mem[p].hh.lh = cur_sym;
    mem[p].hh.rh = r;
    r = p;
    get_next();
    if (c == 4)
    {
      if (cur_cmd == of_token)
      {
        c = 5;
        p = get_node (2);
        if (k == 150)
          overflow("parameter stack size", 150);
        mem[p + 1].cint = 9770 + k;
        get_symbol();
        mem[p].hh.lh = cur_sym;
        mem[p].hh.rh = r;
        r = p;
        get_next();
      }
    }
  }
  check_equals();
  p = get_avail();
  mem[p].hh.lh = c;
  mem[q].hh.rh = p;
  if (m == 1)
    mem[p].hh.rh = scan_toks (16, r, 0, n);
  else
  {
    q = get_avail();
    mem[q].hh.lh = bg_loc;
    mem[p].hh.rh = q;
    p = get_avail();
    mem[p].hh.lh = eg_loc;
    mem[q].hh.rh = scan_toks (16, r, p, n);
  }
  if (warning_info == 21)
    flush_token_list (mem[22].cint);
  scanner_status = 0;
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
    print_nl(498);
  else if ((b < text_base) && (b != text_macro))
    print_nl(499);
  else
    print_nl(500);
  print_int(n);
  print(703);
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
      {
        if (cur_mod == r_delim)
          incr(balance);
      }
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
void macro_call (halfword defref, halfword arg_list, halfword macro_name)
{
  halfword r;
  halfword p, q;
  integer n;
  halfword ldelim, rdelim;
  halfword tail;

  r = mem[defref].hh.rh;
  incr(mem[defref].hh.lh);
  if (arg_list == 0)
    n = 0;
  else
  {
    n = 1;
    tail = arg_list;
    while (mem[tail].hh.rh != 0)
    {
      incr(n);
      tail = mem[tail].hh.rh;
    }
  }
  if (internal[tracing_macros] > 0)
  {
    begin_diagnostic();
    print_ln();
    print_macro_name (arg_list, macro_name);
    if (n == 3)
      print(665);
    show_macro (defref, 0, 100000L);
    if (arg_list != 0)
    {
      n = 0;
      p = arg_list;
      do {
        q = mem[p].hh.lh;
        print_arg (q, n, 0);
        incr(n);
        p = mem[p].hh.rh;
      } while (!(p == 0));
    }
    end_diagnostic (false);
  }
  cur_cmd = semicolon;
  while (mem[r].hh.lh >= 9770)
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
        if (mem[r].hh.lh >= 9920)
        {
          cur_exp = 0;
          cur_type = 20;
        }
        else
        {
          cur_exp = 0;
          cur_type = 16;
        }
        back_error();
        cur_cmd = right_delimiter;
        goto found;
      }
      ldelim = cur_sym;
      rdelim = cur_mod;
    }
    if (mem[r].hh.lh >= 10070)
      scan_text_arg (ldelim, rdelim);
    else
    {
      get_x_next();
      if (mem[r].hh.lh >= 9920)
        scan_suffix();
      else
        scan_expression();
    }
    if (cur_cmd != comma)
    {
      if ((cur_cmd != right_delimiter) || (cur_mod != ldelim))
      {
        if (mem[mem[r].hh.rh].hh.lh >= 9770)
        {
          missing_err (44);
          help3("I've finished reading a macro argument and am about to",
            "read another; the arguments weren't delimited correctly.",
            "You might want to delete some tokens before continuing.");
          back_error();
          cur_cmd = comma;
        }
        else
        {
          missing_err (hash[rdelim].rh);
          help2("I've gotten to the end of the macro parameter list.",
            "You might want to delete some tokens before continuing.");
          back_error();
        }
      }
    }
  found:
    {
      p = get_avail();
      if (cur_type == 20)
        mem[p].hh.lh = cur_exp;
      else
        mem[p].hh.lh = stash_cur_exp();
      if (internal[tracing_macros] > 0)
      {
        begin_diagnostic();
        print_arg (mem[p].hh.lh, n, mem[r].hh.lh);
        end_diagnostic (false);
      }
      if (arg_list == 0)
        arg_list = p;
      else
        mem[tail].hh.rh = p;
      tail = p;
      incr(n);
    }
    r = mem[r].hh.rh;
  }
  if (cur_cmd == comma)
  {
    print_err("Too many arguments to ");
    print_macro_name (arg_list, macro_name);
    print_char(';');
    print_nl(705);
    slow_print(hash[rdelim].rh);
    print(299);
    help3("I'm going to assume that the comma I just read was a",
      "right delimiter, and then I'll begin expanding the macro.",
      "You might want to delete some tokens before continuing.");
    error();
  }
  if (mem[r].hh.lh != 0)
  {
    if (mem[r].hh.lh < 7)
    {
      get_x_next();
      if (mem[r].hh.lh != 6)
      {
        if ((cur_cmd == equals) || (cur_cmd == assignment))
          get_x_next();
      }
    }
    switch (mem[r].hh.lh)
    {
      case 1:
        scan_primary();
        break;
      case 2:
        scan_secondary();
        break;
      case 3:
        scan_tertiary();
        break;
      case 4:
        scan_expression();
        break;
      case 5:
        {
          scan_expression();
          p = get_avail();
          mem[p].hh.lh = stash_cur_exp();
          if (internal[tracing_macros] > 0)
          {
            begin_diagnostic();
            print_arg (mem[p].hh.lh, n, 0);
            end_diagnostic (false);
          }
          if (arg_list == 0)
            arg_list = p;
          else
            mem[tail].hh.rh = p;
          tail = p;
          incr(n);
          if (cur_cmd != of_token)
          {
            missing_err (479);
            print(716);
            print_macro_name (arg_list, macro_name);
            help1("I've got the first argument; will look now for the other.");
            back_error();
          }
          get_x_next();
          scan_primary();
        }
        break;
      case 6:
        {
          if (cur_cmd != left_delimiter)
            ldelim = 0;
          else
          {
            ldelim = cur_sym;
            rdelim = cur_mod;
            get_x_next();
          }
          scan_suffix();
          if (ldelim != 0)
          {
            if ((cur_cmd != right_delimiter) || (cur_mod != ldelim))
            {
              missing_err (hash[rdelim].rh);
              help2("I've gotten to the end of the macro parameter list.", 
                "You might want to delete some tokens before continuing.");
              back_error();
            }
            get_x_next();
          }
        }
        break;
      case 7:
        scan_text_arg (0, 0);
        break;
    }
    back_input();
    {
      p = get_avail();
      if (cur_type == 20)
        mem[p].hh.lh = cur_exp;
      else
        mem[p].hh.lh = stash_cur_exp();
      if (internal[tracing_macros] > 0)
      {
        begin_diagnostic();
        print_arg (mem[p].hh.lh, n, mem[r].hh.lh);
        end_diagnostic (false);
      }
      if (arg_list == 0)
        arg_list = p;
      else
        mem[tail].hh.rh = p;
      tail = p;
      incr(n);
    }
  }
  r = mem[r].hh.rh;
  while ((index > 15) && (loc == 0))
    end_token_list();
  if (param_ptr + n > max_param_stack)
  {
    max_param_stack = param_ptr + n;
    if (max_param_stack > 150)
      overflow("parameter stack size", 150);
  }
  begin_token_list (defref, 21);
  name = macro_name;
  loc = r;
  if (n > 0)
  {
    p = arg_list;
    do {
      param_stack[param_ptr] = mem[p].hh.lh;
      incr(param_ptr);
      p = mem[p].hh.rh;
    } while (!(p == 0));
    flush_list (arg_list);
  }
}
void get_boolean(void); void pass_text(void);
void conditional(void); void start_input(void);
void begin_iteration(void); void resume_iteration(void);
void stop_iteration(void);
/* 707 */
void expand (void)
{
  halfword p;
  integer k;
  pool_pointer j;

  if (internal[tracing_commands] > unity)
  {
    if (cur_cmd != defined_macro)
      show_cmd_mod (cur_cmd, cur_mod);
  }
  switch (cur_cmd)
  {
    case if_test:
      conditional();
      break;
    case fi_or_else:
      if (cur_mod > if_limit)
      {
        if (if_limit == 1)
        {
          missing_err (58);
          back_input();
          cur_sym = 9762;
          ins_error();
        }
        else
        {
          print_err("Extra ");
          print_cmd_mod (2, cur_mod);
          help1("I'm ignoring this; it doesn't match any if.");
          error();
        }
      }
      else
      {
        while (cur_mod != 2) pass_text();
        {
          p = cond_ptr;
          if_line = mem[p + 1].cint;
          cur_if = mem[p].hh.b1;
          if_limit = mem[p].hh.b0;
          cond_ptr = mem[p].hh.rh;
          free_node (p, 2);
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
      if (cur_mod == 0)
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
        while ((index > 15) && (loc == 0))
          end_token_list();
        if (loop_ptr == 0)
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
          show_cmd_mod (33, cur_exp);
        if (cur_exp == 30)
        {
          if (loop_ptr == 0)
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
            p = 0;
            do {
              if ((index <= 15))
                end_file_reading();
              else
              {
                if (index <= 17)
                  p = start;
                end_token_list();
              }
            } while (!(p != 0));
            if (p != mem[loop_ptr].hh.lh)
              fatal_error("*** (loop confusion)");
            stop_iteration();
          }
        }
        else if (cur_cmd != semicolon)
        {
          missing_err (59);
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
        if (cur_cmd < display_command)
          expand();
        else
          back_input();
        begin_token_list (p, 19);
      }
      break;
    case scan_tokens:
      {
        get_x_next();
        scan_primary();
        if (cur_type != 4)
        {
          disp_err(null, "Not a string");
          help2("I'm going to flush this expression, since",
            "scantokens should be followed by a known string.");
          put_get_flush_error (0);
        }
        else
        {
          back_input();
          if ((str_start[cur_exp + 1] - str_start[cur_exp]) > 0)
          {
            begin_file_reading();
            name = 2;
            k = first + (str_start[cur_exp + 1] - str_start[cur_exp]);
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
              buffer[first] = str_pool[j];
              incr(j);
              incr(first);
            }
            buffer[limit] = 37;
            first = limit + 1;
            loc = start;
            flush_cur_exp (0);
          }
        }
      }
      break;
    case defined_macro:
      macro_call (cur_mod, 0, cur_sym);
      break;
  }
}
/* 718 */
void get_x_next (void)
{
  halfword save_exp;

  get_next();
  if (cur_cmd < display_command)
  {
    save_exp = stash_cur_exp();
    do {
      if (cur_cmd == defined_macro)
        macro_call(cur_mod, 0, cur_sym);
      else
        expand();
      get_next();
    } while (!(cur_cmd >= display_command));
    unstash_cur_exp (save_exp);
  }
}
/* 737 */
void stack_argument (halfword p)
{
  if (param_ptr == max_param_stack)
  {
    incr(max_param_stack);
    if (max_param_stack > 150)
      overflow("parameter stack size", 150);
  }
  param_stack[param_ptr] = p;
  incr(param_ptr);
}
/* 742 */
void pass_text (void)
{
  integer l;

  scanner_status = 1;
  l = 0;
  warning_info = line;
  while (true)
  {
    get_next();
    if (cur_cmd <= fi_or_else)
    {
      if (cur_cmd < fi_or_else)
        incr(l);
      else
      {
        if (l == 0)
          goto done;
        if (cur_mod == 2)
          decr(l);
      }
    }
    else if (cur_cmd == string_token)
    {
      if (str_ref[cur_mod] < 127)
      {
        if (str_ref[cur_mod] > 1)
          decr(str_ref[cur_mod]);
        else
          flush_string (cur_mod);
      }
    }
  }
done:
  scanner_status = 0;
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
      if (mem[q].hh.rh == p)
      {
        mem[q].hh.b0 = l;
        goto lab_exit;
      }
      q = link(q);
    }
  }
  lab_exit:;
}
/* 747 */
void check_colon (void)
{
  if (cur_cmd != colon)
  {
    missing_err(58);
    help2("There should've been a colon after the condition.",
      "I shall pretend that one was there.");
    back_error();
  }
}
/* 748 */
void conditional (void)
{
  halfword savecond_ptr;
  unsigned char new_if_limit;
  halfword p;

  {
    p = get_node (2);
    mem[p].hh.rh = cond_ptr;
    mem[p].hh.b0 = if_limit;
    mem[p].hh.b1 = cur_if;
    mem[p + 1].cint = if_line;
    cond_ptr = p;
    if_limit = 1;
    if_line = line;
    cur_if = 1;
  }
  savecond_ptr = cond_ptr;
  lab_reswitch: get_boolean();
  new_if_limit = 4;
  if (internal[tracing_commands] > unity)
  {
    begin_diagnostic();
    if (cur_exp == 30)
      print(722);
    else
      print(723);
    end_diagnostic (false);
  }
found:
  check_colon();
  if (cur_exp == 30)
  {
    change_if_limit (new_if_limit, savecond_ptr);
    goto lab_exit;
  }
  while (true)
  {
    pass_text();
    if (cond_ptr == savecond_ptr)
      goto done;
    else if (cur_mod == 2)
    {
      p = cond_ptr;
      if_line = mem[p + 1].cint;
      cur_if = mem[p].hh.b1;
      if_limit = mem[p].hh.b0;
      cond_ptr = mem[p].hh.rh;
      free_node (p, 2);
    }
  }
done:
  cur_if = cur_mod;
  if_line = line;
  if (cur_mod == 2)
  {
    p = cond_ptr;
    if_line = mem[p + 1].cint;
    cur_if = mem[p].hh.b1;
    if_limit = mem[p].hh.b0;
    cond_ptr = mem[p].hh.rh;
    free_node (p, 2);
  }
  else if (cur_mod == 4)
    goto lab_reswitch;
  else
  {
    cur_exp = 30;
    new_if_limit = 2;
    get_x_next();
    goto found;
  }
  lab_exit:;
}
/* 754 */
void bad_for (str_number s)
{
  disp_err(null, "Improper ");
  print(s);
  print(306);
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
    missing_err(61);
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
      {
        if (cur_cmd <= comma)
          goto lab_continue;
      }
      scan_expression();
      if (cur_cmd == step_token)
      {
        if (q == loop_list_loc(s))
        {
          if (cur_type != known)
            bad_for(737);
          pp = get_node(progression_node_size);
          value(pp) = cur_exp;
          get_x_next();
          scan_expression();
          if (cur_type != known)
            bad_for(738);
          step_size(pp) = cur_exp;
          if (cur_cmd != until_token)
          {
            missing_err(490);
            help2("I assume you meant to say `until' after `step'.",
              "So I'll look for the final value and colon next.");
            back_error();
          }
          get_x_next();
          scan_expression();
          if (cur_type != known)
            bad_for(741);
          final_value(pp) = cur_exp;
          loop_type(s) = pp;
          goto done;
        }
      }
      cur_exp = stash_cur_exp();
    }
    link(q) = get_avail();
    q = link(q);
    info(q) = cur_exp;
    cur_type = vacuous;
    lab_continue:;
  } while (!(cur_cmd != comma));
done:;
found:
  if (cur_cmd != colon)
  {
    missing_err(58);
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
    if (((step_size(p) > 0) && (cur_exp > final_value(p))) || ((step_size(p) < 0)
      && (cur_exp < final_value(p))))
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
    goto lab_exit;
  }
  begin_token_list(info(loop_ptr), loop_text);
  stack_argument(q);
  if (internal[tracing_commands] > unity)
  {
    begin_diagnostic();
    print_nl(736);
    if ((q != null) && (link(q) = _void))
      print_exp(q, 1);
    else
      show_token_list(q, null, 50, 0);
    print_char('}');
    end_diagnostic (false);
  }
  goto lab_exit;
not_found:
  stop_iteration();
lab_exit:;
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
      {
        if (link(p) == _void)
        {
          recycle_value(p);
          free_node(p, value_node_size);
        }
        else
          flush_token_list(p);
      }
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
boolean more_name (ASCII_code c)
{
  boolean Result;

  if (c == 34)
  {
    quotedfilename = !quotedfilename;
    Result = true;
  }
  else if (((c == 32) || (c == 9)) && stopatspace && (!quotedfilename))
    Result = false;
  else
  {
    if (ISDIRSEP (c))
    {
      area_delimiter = pool_ptr;
      ext_delimiter = 0;
    }
    else if (c == 46)
      ext_delimiter = pool_ptr;
    {
      if (pool_ptr + 1 > max_pool_ptr)
      {
        if (pool_ptr + 1 > pool_size)
          overflow("pool size", pool_size - init_pool_ptr);
        max_pool_ptr = pool_ptr + 1;
      }
    }
    {
      str_pool[pool_ptr] = c;
      incr(pool_ptr);
    }
    Result = true;
  }
  return Result;
}
/* 772 */
void end_name (void)
{
  boolean mustquote;
  pool_pointer j, s, t;

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
    cur_area = 261;
  else
  {
    mustquote = false;
    s = str_start[str_ptr];
    t = area_delimiter + 1;
    j = s;
    while ((!mustquote) && (j < t))
    {
      mustquote = str_pool[j] == 32;
      incr(j);
    }
    if (mustquote)
    {
      for (j = pool_ptr - 1; j <= t; j++)
      {
        str_pool[j + 2] = str_pool[j];
      }
      str_pool[t + 1] = 34;
      for (j = t - 1; j <= s; j++)
      {
        str_pool[j + 1] = str_pool[j];
      }
      str_pool[s] = 34;
      pool_ptr = pool_ptr + 2;
      area_delimiter = area_delimiter + 2;
      if (ext_delimiter != 0)
        ext_delimiter = ext_delimiter + 2;
    }
    cur_area = str_ptr;
    incr(str_ptr);
    str_start[str_ptr] = area_delimiter + 1;
  }
  if (ext_delimiter == 0)
    cur_ext = 261;
  else
  {
    mustquote = false;
    s = str_start[str_ptr];
    t = ext_delimiter;
    j = s;
    while ((!mustquote) && (j < t))
    {
      mustquote = str_pool[j] == 32;
      incr(j);
    }
    if (mustquote)
    {
      for (j = pool_ptr - 1; j <= t; j++)
      {
        str_pool[j + 2] = str_pool[j];
      }
      str_pool[t + 1] = 34;
      for (j = t - 1; j <= s; j++)
      {
        str_pool[j + 1] = str_pool[j];
      }
      str_pool[s] = 34;
      pool_ptr = pool_ptr + 2;
      ext_delimiter = ext_delimiter + 2;
    }
    cur_name = str_ptr;
    incr(str_ptr);
    str_start[str_ptr] = ext_delimiter;
  }
  mustquote = false;
  s = str_start[str_ptr];
  t = pool_ptr;
  j = s;
  while ((!mustquote) && (j < t))
  {
    mustquote = str_pool[j] == 32;
    incr(j);
  }
  if (mustquote)
  {
    str_pool[t + 1] = 34;
    for (j = t - 1; j <= s; j++)
    {
      str_pool[j + 1] = str_pool[j];
    }
    str_pool[s] = 34;
    pool_ptr = pool_ptr + 2;
  }
  if (ext_delimiter == 0)
    cur_name = make_string();
  else
    cur_ext = make_string();
}
/* 774 */
void pack_file_name (str_number n, str_number a, str_number e)
{
  integer k;
  ASCII_code c;
  pool_pointer j;

  k = 0;
  for (j = str_start[a]; j <= str_start[a + 1] - 1; j++)
  {
    append_to_name(so(str_pool[j]));
  }
  for (j = str_start[n]; j <= str_start[n + 1] - 1; j++)
  {
    append_to_name(so(str_pool[j]));
  }
  for (j = str_start[e]; j <= str_start[e + 1] - 1; j++)
  {
    append_to_name(so(str_pool[j]));
  }
  if (k <= file_name_size)
    name_length = k;
  else
    name_length = file_name_size;
  name_of_file[name_length + 1] = 0;
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
  {
    append_to_name(xord[MF_base_default[j]]);
  }
  for (j = a; j <= b; j++)
  {
    append_to_name(buffer[j]);
  }
  for (j = base_default_length - 4; j <= base_default_length; j++)
  {
    append_to_name(xord[MF_base_default[j]]);
  }
  if (k <= maxint)
    name_length = k;
  else
    name_length = maxint;
  name_of_file[name_length + 1] = 0;
}
/* 780 */
str_number make_name_string (void)
{
  str_number Result;
  integer k;

  if ((pool_ptr + name_length > pool_size) || (str_ptr == max_strings))
    Result = 63;
  else
  {
    for (k = 1; k <= name_length; k++)
    {
      str_pool[pool_ptr] = xord[name_of_file[k]];
      incr(pool_ptr);
    }
    Result = make_string();
  }
  k = 1;
  begin_name();
  stopatspace = false;
  while ((k <= name_length) && (more_name (name_of_file[k])))
    incr(k);
  stopatspace = true;
  end_name();
  return Result;
}
/* 780 */
str_number a_make_name_string (alpha_file f)
{
  str_number Result;
  
  Result = make_name_string();
  return Result;
}
/* 780 */
str_number b_make_name_string (byte_file f)
{
  str_number Result;
  
  Result = make_name_string();
  return Result;
}
/* 780 */
str_number w_make_name_string (word_file f)
{
  str_number Result;
  
  Result = make_name_string();
  return Result;
}
/* 781 */
void scan_file_name (void)
{
  begin_name();
  while ((buffer[loc] == 32) || (buffer[loc] == 9))
    incr(loc);
  while (true)
  {
    if ((buffer[loc] == 59) || (buffer[loc] == 37))
      goto done;
    if (!more_name (buffer[loc]))
      goto done;
    incr(loc);
  }
done:
  end_name();
}
/* 784 */
void pack_job_name (str_number s)
{
  cur_area = 261;
  cur_ext = s;
  cur_name = job_name;
  pack_file_name (cur_name, cur_area, cur_ext);
}
/* 786 */
void prompt_file_name (str_number s, str_number e)
{
  integer k;
  str_number saved_cur_name;

  if (interaction == scroll_mode)
    ;
  if (s == 743)
    print_err("I can't find file `");
  else
    print_err("I can't write on file `");
  print_file_name(cur_name, cur_area, cur_ext);
  print(746);
  if (e == 747)
    show_context();
  print_nl(748);
  print(s);
  if (interaction < scroll_mode)
    fatal_error("*** (job aborted, file error in nonstop mode)");
  saved_cur_name = cur_name;
  prompt_input(": ");
  {
    begin_name();
    k = first;
    while (((buffer[k] == 32) || (buffer[k] == 9)) && (k < last))
      incr(k);
    while (true)
    {
      if (k == last)
        goto done;
      if (!more_name (buffer[k]))
        goto done;
      incr(k);
    }
  done:
    end_name();
  }
  if (cur_ext == 261)
    cur_ext = e;
  if ((str_start[cur_name + 1] - str_start[cur_name]) == 0)
    cur_name = saved_cur_name;
  pack_file_name (cur_name, cur_area, cur_ext);
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
    job_name = getjob_name (750);
  pack_job_name (751);
  recorderchangefilename (stringcast (name_of_file + 1));
  pack_job_name (752);
  while (!aopenout (log_file))
  {
    selector = term_only;
    prompt_file_name (754, 752);
  }
  texmflogname = a_make_name_string (log_file);
  selector = log_only;
  log_opened = true;
  {
    Fputs(log_file, "This is METAFONT, Version 2.7182818");
    Fputs(log_file, versionstring);
    slow_print(base_ident);
    print(755);
    print_int(round_unscaled(internal[day]));
    print_char(' ');
    months = " JANFEBMARAPRMAYJUNJULAUGSEPOCTNOVDEC";
    m = round_unscaled(internal[month]);
    for (k = 3 * m - 2; k <= 3 * m; k++)
    {
      putc (months[k], log_file);
    }
    print_char(' ');
    print_int(round_unscaled(internal[year]));
    print_char(' ');
    m = round_unscaled(internal[time]);
    print_dd (m / 60);
    print_char(':');
    print_dd (m % 60);
  }
  input_stack[input_ptr] = cur_input;
  print_nl(753);
  l = input_stack[0].limit_field - 1;
  for (k = 1; k <= l; k++)
  {
    print(buffer[k]);
  }
  print_ln();
  selector = old_setting + 2;
}
/* 793 */
void start_input (void)
{
  while ((index > 15) && (loc == 0))
    end_token_list();
  if ((index > 15))
  {
    print_err("File names can't appear within macros");
    help3("Sorry...I've converted what follows to tokens,",
      "possibly garbaging the name you gave.",
      "Please delete the tokens and insert the name again.");
    error();
  }
  if ((index <= 15))
    scan_file_name();
  else
  {
    cur_name = 261;
    cur_ext = 261;
    cur_area = 261;
  }
  pack_file_name(cur_name, cur_area, cur_ext);
  while (true)
  {
    begin_file_reading();
    if (cur_ext == 747)
    {
      cur_ext = 261;
      pack_file_name(cur_name, cur_area, cur_ext);
    }
    if (kpseinnameok (stringcast (name_of_file + 1)) && aopenin (input_file[index], kpsemfformat))
      goto done;
    end_file_reading();
    prompt_file_name(743, 747);
  }
done:
  name = a_make_name_string(input_file[index]);
  str_ref[cur_name] = 127;
  if (job_name == 0)
  {
    job_name = getjob_name(cur_name);
    open_log_file();
  }
  if (term_offset + (str_start[name + 1] - str_start[name]) > max_print_line - 2)
    print_ln();
  else if ((term_offset > 0) || (file_offset > 0))
    print_char(' ');
  print_char('(');
  incr(open_parens);
  slow_print(name);
  fflush (stdout);
  {
    line = 1;
    if (inputln(input_file[index], false))
      ;
    firm_up_the_line();
    buffer[limit] = 37;
    first = limit + 1;
    loc = start;
  }
}
/* 824 */
void bad_exp (str_number s)
{
  unsigned char saveflag;

  print_err(s);
  print(770);
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
  saveflag = var_flag;
  var_flag = 0;
  get_x_next();
  var_flag = saveflag;
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
  disp_err (null, "Improper subscript has been replaced by zero");
  help3("A bracketed subscript must have a known numeric value;",
    "unfortunately, what I found was the value that appears just",
    "above this error message. So I'll try a zero subscript.");
  flush_error(0);
}
/* 851 */
void obliterated (halfword q)
{
  print_err("Variable ");
  show_token_list(q, null, 1000, 0);
  print(791);
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
    disp_err(null, "Undefined coordinates have been replaced by (0,0)");
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
  pointer Result;
  pointer q;

  q = get_node(knot_node_size);
  left_type(q) = endpoint;
  right_type(q) = endpoint;
  link(q) = q;
  known_pair();
  x_coord(q) = cur_x;
  y_coord(q) = cur_y;
  Result = q;
  return Result;
}
/* 875 */
small_number scan_direction (void)
{
  small_number Result;
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
        disp_err(null, "Undefined x coordinate has been replaced by 0");
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
        missing_err(44);
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
    missing_err(125);
    help3("I've scanned a direction spec for part of a path,",
      "so a right brace should have come next.",
      "I shall pretend that one was there.");
    back_error();
  }
  get_x_next();
  Result = t;
  return Result;
}
/* 895 */
void do_nullary (quarterword c)
{
  integer k;

  check_arith();
  if (internal[tracing_commands] > two)
    show_cmd_mod (33, c);
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
        {
          append_char(buffer[k]);
        }
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
    {
      if (type(y_part_loc(p)) == known)
      {
        Result = true;
        goto lab_exit;
      }
    }
  }
  Result = false;
  lab_exit:;
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
      print(336);
    else
      print(836);
  }
  else
    print(837);
  print_char(')');
}
/* 901 */
void bad_unary (quarterword c)
{
  disp_err(null, "Not implemented: ");
  print_op(c);
  print_known_or_unknown_type (cur_type, cur_exp);
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
      goto lab_exit;
    p = link(p);
  }
  lab_exit:;
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
      if ((m >= 48) && (m <= 57))
        m = m - 48;
      else if ((m >= 65) && (m <= 70))
        m = m - 55;
      else if ((m >= 97) && (m <= 102))
        m = m - 87;
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
      if (n < half_unit / b)
        n = n * b + m;
      else
        n = 32767;
    }
    if (bad_char)
    {
      disp_err(null, "String contains illegal digits");
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
  scaled Result;
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
  Result = n;
  return Result;
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
/* 895 */
void do_unary (quarterword c)
{
  pointer p, q;
  integer x;

  check_arith();
  if (internal[tracing_commands] > two)
  {
    begin_diagnostic();
    print_nl(123);
    print_op(c);
    print_char('(');
    print_exp (0, 0);
    print(842);
    end_diagnostic(false);
  }
  switch (c)
  {
    case 69:
      if (cur_type < 14)
      {
        if (cur_type != 11)
          bad_unary (69);
      }
      break;
    case 70:
      switch (cur_type)
      {
        case 14:
        case 19:
          {
            q = cur_exp;
            make_exp_copy (q);
            if (cur_type == 17)
              negate_dep_list (mem[cur_exp + 1].hh.rh);
            else if (cur_type == 14)
            {
              p = mem[cur_exp + 1].cint;
              if (mem[p].hh.b0 == 16)
                mem[p + 1].cint = -mem[p + 1].cint;
              else
                negate_dep_list (mem[p + 1].hh.rh);
              if (mem[p + 2].hh.b0 == 16)
                mem[p + 3].cint = -mem[p + 3].cint;
              else
                negate_dep_list (mem[p + 3].hh.rh);
            }
            recycle_value (q);
            free_node (q, 2);
          }
          break;
        case 17:
        case 18:
          negate_dep_list (mem[cur_exp + 1].hh.rh);
          break;
        case 16:
          cur_exp = -cur_exp;
          break;
        case 11:
          negate_edges (cur_exp);
          break;
        default:
          bad_unary (70);
          break;
      }
      break;
    case 41:
      if (cur_type != 2)
        bad_unary (41);
      else
        cur_exp = 61 - cur_exp;
      break;
    case 59:
    case 60:
    case 61:
    case 62:
    case 63:
    case 64:
    case 65:
    case 38:
    case 66:
      if (cur_type != 16)
        bad_unary (c);
      else switch (c)
      {
        case 59:
          cur_exp = square_rt (cur_exp);
          break;
        case 60:
          cur_exp = m_exp (cur_exp);
          break;
        case 61:
          cur_exp = m_log (cur_exp);
          break;
        case 62:
        case 63:
          {
            n_sin_cos((cur_exp % 23592960L) * 16);
            if (c == 62)
              cur_exp = round_fraction (n_sin);
            else
              cur_exp = round_fraction (n_cos);
          }
          break;
        case 64:
          cur_exp = floorscaled (cur_exp);
          break;
        case 65:
          cur_exp = unif_rand (cur_exp);
          break;
        case 38:
          {
            if (odd(round_unscaled(cur_exp)))
              cur_exp = 30;
            else
              cur_exp = 31;
            cur_type = 2;
          }
          break;
        case 66:
          {
            cur_exp = round_unscaled(cur_exp) % 256;
            if (cur_exp < 0)
              cur_exp = cur_exp + 256;
            if (char_exists[cur_exp])
              cur_exp = 30;
            else
              cur_exp = 31;
            cur_type = 2;
          }
          break;
      }
      break;
    case 67:
      if (nice_pair (cur_exp, cur_type))
      {
        p = mem[cur_exp + 1].cint;
        x = n_arg (mem[p + 1].cint, mem[p + 3].cint);
        if (x >= 0)
          flush_cur_exp ((x + 8) / 16);
        else
          flush_cur_exp (-((-x + 8) / 16));
      }
      else
        bad_unary (67);
      break;
    case 53:
    case 54:
      if ((cur_type <= 14) && (cur_type >= 13))
        take_part (c);
      else
        bad_unary (c);
      break;
    case 55:
    case 56:
    case 57:
    case 58:
      if (cur_type == 13)
        take_part (c);
      else
        bad_unary (c);
      break;
    case 50:
      if (cur_type != 16)
        bad_unary (50);
      else
      {
        cur_exp = round_unscaled(cur_exp) % 256;
        cur_type = 4;
        if (cur_exp < 0)
          cur_exp = cur_exp + 256;
        if ((str_start[cur_exp + 1] - str_start[cur_exp]) != 1)
        {
          {
            if (pool_ptr + 1 > max_pool_ptr)
            {
              if (pool_ptr + 1 > pool_size)
                overflow("pool size", pool_size - init_pool_ptr);
              max_pool_ptr = pool_ptr + 1;
            }
          }
          {
            str_pool[pool_ptr] = cur_exp;
            incr(pool_ptr);
          }
          cur_exp = make_string();
        }
      }
      break;
    case 42:
      if (cur_type != 16)
        bad_unary (42);
      else
      {
        old_setting = selector;
        selector = new_string;
        print_scaled(cur_exp);
        cur_exp = make_string();
        selector = old_setting;
        cur_type = 4;
      }
      break;
    case 47:
    case 48:
    case 49:
      if (cur_type != 4)
        bad_unary (c);
      else
        str_to_num (c);
      break;
    case 51:
      if (cur_type == 4)
        flush_cur_exp ((str_start[cur_exp + 1] - str_start[cur_exp]) * unity);
      else if (cur_type == 9)
        flush_cur_exp (path_length ());
      else if (cur_type == 16)
        cur_exp = abs(cur_exp);
      else if (nice_pair (cur_exp, cur_type))
        flush_cur_exp (pyth_add (mem[mem[cur_exp + 1].cint + 1].cint, mem[mem[cur_exp + 1].cint + 3].cint));
      else
        bad_unary (c);
      break;
    case 52:
      if (cur_type == 14)
        flush_cur_exp (0);
      else if (cur_type != 9)
        bad_unary (52);
      else if (mem[cur_exp].hh.b0 == 0)
        flush_cur_exp (0);
      else
      {
        cur_pen = 3;
        cur_path_type = contour_code;
        cur_exp = make_spec (cur_exp, -1879080960L, 0);
        flush_cur_exp (turning_number * unity);
      }
      break;
    case 2:
      {
        if ((cur_type >= 2) && (cur_type <= 3))
          flush_cur_exp (30);
        else
          flush_cur_exp (31);
        cur_type = 2;
      }
      break;
    case 4:
      {
        if ((cur_type >= 4) && (cur_type <= 5))
          flush_cur_exp (30);
        else
          flush_cur_exp (31);
        cur_type = 2;
      }
      break;
    case 6:
      {
        if ((cur_type >= 6) && (cur_type <= 8))
          flush_cur_exp (30);
        else
          flush_cur_exp (31);
        cur_type = 2;
      }
      break;
    case 9:
      {
        if ((cur_type >= 9) && (cur_type <= 10))
          flush_cur_exp (30);
        else
          flush_cur_exp (31);
        cur_type = 2;
      }
      break;
    case 11:
      {
        if ((cur_type >= 11) && (cur_type <= 12))
          flush_cur_exp (30);
        else
          flush_cur_exp (31);
        cur_type = 2;
      }
      break;
    case 13:
    case 14:
      {
        if (cur_type == c)
          flush_cur_exp (30);
        else
          flush_cur_exp (31);
        cur_type = 2;
      }
      break;
    case 15:
      {
        if ((cur_type >= 16) && (cur_type <= 19))
          flush_cur_exp (30);
        else
          flush_cur_exp (31);
        cur_type = 2;
      }
      break;
    case 39:
    case 40:
      test_known (c);
      break;
    case 68:
      {
        if (cur_type != 9)
          flush_cur_exp (31);
        else if (mem[cur_exp].hh.b0 != 0)
          flush_cur_exp (30);
        else
          flush_cur_exp (31);
        cur_type = 2;
      }
      break;
    case 45:
      {
        if (cur_type == 14)
          pair_to_path();
        if (cur_type == 9)
          cur_type = 8;
        else
          bad_unary (45);
      }
      break;
    case 44 :
      {
        if (cur_type == 8)
          materialize_pen();
        if (cur_type != 6)
          bad_unary (44);
        else
        {
          flush_cur_exp (make_path (cur_exp));
          cur_type = 9;
        }
      }
      break;
    case 46:
      if (cur_type != 11)
        bad_unary (46);
      else
        flush_cur_exp (total_weight (cur_exp));
      break;
    case 43:
      if (cur_type == 9)
      {
        p = htap_ypoc (cur_exp);
        if (mem[p].hh.b1 == 0)
          p = mem[p].hh.rh;
        toss_knot_list (cur_exp);
        cur_exp = p;
      }
      else if (cur_type == 14)
        pair_to_path();
      else
        bad_unary (43);
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
    print(479);
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
      Result = 1;
      goto lab_exit;
    }
  } while (!(r == q));
  Result = null;
  lab_exit:;
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
    v = dep_list(cur_exp);
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
      goto lab_exit;
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
          if (max_coef (r) + max_coef (v) < coef_bound)
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
  lab_exit:;
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
    goto lab_exit;
  }
  t = type(q);
  q = dep_list(q);
  s = t;
  if (t == dependent)
  {
    if (v_is_scaled)
    {
      if (ab_vs_cd(max_coef(q), abs(v), coef_bound - 1, unity) >= 0)
        t = proto_dependent;
    }
  }
  q = p_times_v(q, v, s, t, v_is_scaled);
  dep_finish(q, p, t);
  lab_exit:;
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
    goto lab_exit;
  }
  t = type(q);
  q = dep_list(q);
  s = t;
  if (t == dependent)
  {
    if (ab_vs_cd(max_coef(q), unity, coef_bound - 1, abs(v)) >= 0)
      t = proto_dependent;
  }
  q = p_over_v(q, v, s, t);
  dep_finish(q, p, t);
  lab_exit:;
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
      goto lab_exit;
  } while (!(r == q));
  txx = value(xx_part_loc(q));
  txy = value(xy_part_loc(q));
  tyx = value(yx_part_loc(q));
  tyy = value(yy_part_loc(q));
  tx = value(x_part_loc(q));
  ty = value(y_part_loc(q));
  flush_cur_exp(0);
  lab_exit:;
}
/* 960 */
void set_up_known_trans (quarterword c)
{
  set_up_trans(c);
  if (cur_type != known)
  {
    disp_err(null, "Transform components aren't all known");
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
    {
      if (tx == 0)
      {
        if (ty == 0)
          goto lab_exit;
      }
    }
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
  lab_exit:;
}
/* 963 */
void edges_trans (pointer p, quarterword c)
{
  set_up_known_trans(c);
  unstash_cur_exp(p);
  cur_edges = cur_exp;
  if (empty_edges(cur_edges))
    goto lab_exit;
  if (txx == 0)
  {
    if (tyy == 0)
    {
      if (txy % unity == 0)
      {
        if (tyx % unity == 0)
        {
          xy_swap_edges();
          txx = txy;
          tyy = tyx;
          txy = 0;
          tyx = 0;
          if (empty_edges(cur_edges))
            goto lab_exit;
        }
      }
    }
  }
  if (txy == 0)
  {
    if (tyx == 0)
    {
      if (txx % unity == 0)
      {
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
          goto lab_exit;
        }
      }
    }
  }
  print_err("That transformation is too hard");
  help3("I can apply complicated transformations to paths,",
    "but I can only do integer operations on pictures.",
    "Proceed, and I'll omit the transformation.");
  put_get_error();
  lab_exit:;
}
/* 968 */
void bilin1 (pointer p, scaled t, pointer q, scaled u, scaled delta)
{
  pointer r;

  if (t != unity)
    dep_mult(p, t, true);
  if (u != 0)
  {
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
    value(p) = delta + take_scaled (v, u);
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
      goto lab_exit;
    }
  } while (!(r == q));
  set_up_trans(c);
  if (cur_type == known)
  {
    make_exp_copy(p);
    r = value(cur_exp);
    if (cur_type == 13)
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
    pp = stash_cur_exp;
    qq = value(pp);
    make_exp_copy(p);
    r = value(cur_exp);
    if (cur_type == 13)
    {
      bilin2(yy_part_loc(r), yy_part_loc(qq), value(xy_part_loc(q)), yx_part_loc(qq), null);
      bilin2(yx_part_loc(r), yy_part_loc(qq), value(xx_part_loc(q)), yx_part_loc(qq), null);
      bilin2(xy_part_loc(r), xx_part_loc(qq), value(yy_part_loc(q)), xy_part_loc(qq), null);
      bilin2(xx_part_loc(r), xx_part_loc(qq), value(yx_part_loc(q)), xy_part_loc(qq), null);
    }
    bilin2(y_part_loc(r), yy_part_loc(qq), value(x_part_loc(q)), yx_part_loc(qq), y_part_loc(qq));
    bilin2(x_part_loc(r), xx_part_loc(qq), value(y_part_loc(q)), xy_part_loc(qq), x_part_loc(qq));
    recycle_value(pp); free_node(pp, value_node_size);
  }
  lab_exit:;
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
  {
    append_char(so(str_pool[k]));
  }
  for (k = str_start[b]; k <= str_start[b + 1] - 1; k++)
  {
    append_char(so(str_pool[k]));
  }
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
  {
    for (k = str_start[s] + b - 1; k <= str_start[s] + a; k--)
    {
      append_char(so(str_pool[k]));
    }
  }
  else
  {
    for (k = str_start[s] + a; k <= str_start[s] + b - 1; k++)
    {
      append_char(so(str_pool[k]));
    }
  }
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
  {
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
  }
  if (b > l)
  {
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
      split_cubic(q, a * 4096, x_coord(qq), y_coord(qq));
      q = link(q);
    }
    pp = copy_knot(q);
    qq = pp;
  }
  else
  {
    pp = copy_knot (q);
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
      split_cubic(ss, a * 4096, x_coord(pp), y_coord(pp));
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
      split_cubic(rr, (b + unity) * 4096, x_coord(qq), y_coord(qq));
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
  {
    if (left_type(p) == endpoint)
      v = 0;
    else
      v = n - 1 - ((-v - 1) % n);
  }
  else if (v > n)
  {
    if (left_type(p) == endpoint)
      v = n;
    else
      v = v % n;
  }
  p = cur_exp;
  while (v >= unity)
  {
    p = link(p);
    v = v - unity;
  }
  if (v != 0)
  {
    q = link(p);
    split_cubic(p, v * 4096, x_coord(q), y_coord(q));
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
void do_binary (halfword p, quarterword c)
{
  halfword q, r, rr;
  halfword oldp, oldexp;
  integer v;
 
  check_arith();
  if (internal[tracing_commands] > two)
  {
    begin_diagnostic();
    print_nl(850);
    print_exp (p, 0);
    print_char(')');
    print_op (c);
    print_char('(');
    print_exp (0, 0);
    print(842);
    end_diagnostic (false);
  }
  switch (mem[p].hh.b0)
  {
    case 13:
    case 14:
      oldp = tarnished (p);
      break;
    case 19:
      oldp = 1;
      break;
    default:
      oldp = 0;
      break;
  }
  if (oldp != 0)
  {
    q = stash_cur_exp();
    oldp = p;
    make_exp_copy (oldp);
    p = stash_cur_exp();
    unstash_cur_exp (q);
  }
  switch (cur_type)
  {
    case 13:
    case 14:
      oldexp = tarnished (cur_exp);
      break;
    case 19:
      oldexp = 1;
      break;
    default:
      oldexp = 0;
      break;
  }
  if (oldexp != 0)
  {
    oldexp = cur_exp;
    make_exp_copy (oldexp);
  }
  switch (c)
  {
    case 69:
    case 70:
      if ((cur_type < 14) || (mem[p].hh.b0 < 14))
      {
        if ((cur_type == 11) && (mem[p].hh.b0 == 11))
        {
          if (c == 70)
            negate_edges (cur_exp);
          cur_edges = cur_exp;
          merge_edges (mem[p + 1].cint);
        }
        else
          bad_binary (p, c);
      }
      else if (cur_type == 14)
      {
        if (mem[p].hh.b0 != 14)
          bad_binary (p, c);
        else
        {
          q = mem[p + 1].cint;
          r = mem[cur_exp + 1].cint;
          add_or_sub_tract (q, r, c);
          add_or_sub_tract (q + 2, r + 2, c);
        }
      }
      else if (mem[p].hh.b0 == 14)
        bad_binary (p, c);
      else
        add_or_sub_tract (p, 0, c);
      break;
    case 77:
    case 78:
    case 79:
    case 80:
    case 81:
    case 82:
      {
        if ((cur_type > 14) && (mem[p].hh.b0 > 14))
          add_or_sub_tract (p, 0, 70);
        else if (cur_type != mem[p].hh.b0)
        {
          bad_binary (p, c);
          goto done;
        }
        else if (cur_type == 4)
          flush_cur_exp (str_vs_str (mem[p + 1].cint, cur_exp));
        else if ((cur_type == 5) || (cur_type == 3))
        {
          q = mem[cur_exp + 1].cint;
          while ((q != cur_exp) && (q != p))
            q = mem[q + 1].cint;
          if (q == p)
            flush_cur_exp (0);
        }
        else if ((cur_type == 14) || (cur_type == 13))
        {
          q = mem[p + 1].cint;
          r = mem[cur_exp + 1].cint;
          rr = r + big_node_size[cur_type] - 2;
          while (true)
          {
            add_or_sub_tract (q, r, 70);
            if (mem[r].hh.b0 != 16)
              goto done1;
            if (mem[r + 1].cint != 0)
              goto done1;
            if (r == rr)
              goto done1;
            q = q + 2;
            r = r + 2;
          }
          done1: take_part (53 + half(r - mem[cur_exp + 1].cint));
        }
        else if (cur_type == 2)
          flush_cur_exp (cur_exp - mem[p + 1].cint);
        else
        {
          bad_binary (p, c);
          goto done;
        }
        if (cur_type != 16)
        {
          if (cur_type < 16)
          {
            disp_err(p, "");
            help1("The quantities shown above have not been equated.");
          }
          else
            help2("Oh dear. I can't decide if the expression above is positive,",
              "negative, or zero. So this comparison test won't be `true'.");
          disp_err (null, "Unknown relation will be considered false");
          put_get_flush_error (31);
        }
        else switch (c)
        {
          case 77:
            if (cur_exp < 0)
              cur_exp = 30;
            else
              cur_exp = 31;
            break;
          case 78:
            if (cur_exp <= 0)
              cur_exp = 30;
            else
              cur_exp = 31;
            break;
          case 79:
            if (cur_exp > 0)
              cur_exp = 30;
            else
              cur_exp = 31;
            break;
          case 80 :
            if (cur_exp >= 0)
              cur_exp = 30;
            else
              cur_exp = 31;
            break;
          case 81 :
            if (cur_exp == 0)
              cur_exp = 30;
            else
              cur_exp = 31;
            break;
          case 82 :
            if (cur_exp != 0)
              cur_exp = 30;
            else
              cur_exp = 31;
            break;
        }
        cur_type = 2;
        done:;
      }
      break;
    case 76:
    case 75:
      if ((mem[p].hh.b0 != 2) || (cur_type != 2))
        bad_binary (p, c);
      else if (mem[p + 1].cint == c - 45)
        cur_exp = mem[p + 1].cint;
      break;
    case 71:
      if ((cur_type < 14) || (mem[p].hh.b0 < 14))
        bad_binary (p, 71);
      else if ((cur_type == 16) || (mem[p].hh.b0 == 16))
      {
        if (mem[p].hh.b0 == 16)
        {
          v = mem[p + 1].cint;
          free_node (p, 2);
        }
        else
        {
          v = cur_exp;
          unstash_cur_exp (p);
        }
        if (cur_type == 16)
          cur_exp = take_scaled (cur_exp, v);
        else if (cur_type == 14)
        {
          p = mem[cur_exp + 1].cint;
          dep_mult (p, v, true);
          dep_mult (p + 2, v, true);
        }
        else
          dep_mult (0, v, true);
        goto lab_exit;
      }
      else if ((nice_pair (p, mem[p].hh.b0) && (cur_type > 14)) || (nice_pair (cur_exp, cur_type) && (mem[p].hh.b0 > 14)))
      {
        hard_times (p);
        goto lab_exit;
      }
      else
        bad_binary (p, 71);
      break;
    case 72:
      if ((cur_type != 16) || (mem[p].hh.b0 < 14))
        bad_binary (p, 72);
      else
      {
        v = cur_exp;
        unstash_cur_exp (p);
        if (v == 0)
        {
          disp_err(null, "Division by zero");
          help2("You're trying to divide the quantity shown above the error",
            "message by zero. I'm going to divide it by one instead.");
          put_get_error();
        }
        else
        {
          if (cur_type == 16)
            cur_exp = make_scaled (cur_exp, v);
          else if (cur_type == 14)
          {
            p = mem[cur_exp + 1].cint;
            dep_div (p, v);
            dep_div (p + 2, v);
          }
          else
            dep_div (0, v);
        }
        goto lab_exit;
      }
      break;
    case 73:
    case 74:
      if ((cur_type == 16) && (mem[p].hh.b0 == 16))
      {
        if (c == 73)
          cur_exp = pyth_add (mem[p + 1].cint, cur_exp);
        else
          cur_exp = pyth_sub (mem[p + 1].cint, cur_exp);
      }
      else
        bad_binary (p, c);
      break;
    case 84:
    case 85:
    case 86:
    case 87:
    case 88:
    case 89:
    case 90:
    case 91:
      if ((mem[p].hh.b0 == 9) || (mem[p].hh.b0 == 8) || (mem[p].hh.b0 == 6))
      {
        path_trans (p, c);
        goto lab_exit;
      }
      else if ((mem[p].hh.b0 == 14) || (mem[p].hh.b0 == 13))
        big_trans (p, c);
      else if (mem[p].hh.b0 == 11)
      {
        edges_trans (p, c);
        goto lab_exit;
      }
      else
        bad_binary (p, c);
      break;
    case 83:
      if ((cur_type == 4) && (mem[p].hh.b0 == 4))
        cat (p);
      else
        bad_binary (p, 83);
      break;
    case 94:
      if (nice_pair (p, mem[p].hh.b0) && (cur_type == 4))
        chop_string (mem[p + 1].cint);
      else
        bad_binary (p, 94);
      break;
    case 95:
      {
        if (cur_type == 14)
          pair_to_path();
        if (nice_pair (p, mem[p].hh.b0) && (cur_type == 9))
          chop_path (mem[p + 1].cint);
        else
          bad_binary (p, 95);
      }
      break;
    case 97:
    case 98:
    case 99:
      {
        if (cur_type == 14)
          pair_to_path();
        if ((cur_type == 9) && (mem[p].hh.b0 == 16))
          find_point (mem[p + 1].cint, c);
        else
          bad_binary (p, c);
      }
      break;
    case 100:
      {
        if (cur_type == 8)
          materialize_pen();
        if ((cur_type == 6) && nice_pair (p, mem[p].hh.b0))
          set_up_offset (mem[p + 1].cint);
        else
          bad_binary (p, 100);
      }
      break;
    case 96:
      {
        if (cur_type == 14)
          pair_to_path();
        if ((cur_type == 9) && nice_pair (p, mem[p].hh.b0))
          set_up_direction_time (mem[p + 1].cint);
        else
          bad_binary (p, 96);
      }
      break;
    case 92:
      {
        if (mem[p].hh.b0 == 14)
        {
          q = stash_cur_exp();
          unstash_cur_exp (p);
          pair_to_path();
          p = stash_cur_exp();
          unstash_cur_exp (q);
        }
        if (cur_type == 14)
          pair_to_path();
        if ((cur_type == 9) && (mem[p].hh.b0 == 9))
        {
          path_intersection (mem[p + 1].cint, cur_exp);
          pair_value (cur_t, cur_tt);
        }
        else
          bad_binary (p, 92);
      }
      break;
  }
  recycle_value (p);
  free_node (p, 2);
lab_exit:
  check_arith();
  if (oldp != 0)
  {
    recycle_value (oldp);
    free_node (oldp, 2);
  }
  if (oldexp != 0)
  {
    recycle_value (oldexp);
    free_node (oldexp, 2);
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
    print_nl(850);
    print_scaled(n);
    print_char('/');
    print_scaled(d);
    print(855);
    print_exp(0, 0);
    print(842);
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
  if (old_exp != 0)
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
    x = x + fraction_four;
    x = x + fraction_four;
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
  {
    for (k = str_start[t]; k <= str_start[t + 1] - 1; k++)
      gf_out(so(str_pool[k]));
  }
}
/* 1161 */
void gf_boc (integer min_m, integer max_m, integer min_n, integer max_n)
{
  if (min_m < gf_min_m)
    gf_min_m = min_m;
  if (max_n > gf_max_n)
    gf_max_n = max_n;
  if (boc_p == -1)
  {
    if (one_byte(boc_c))
    {
      if (one_byte(max_m - min_m))
      {
        if (one_byte(max_m))
        {
          if (one_byte(max_n - min_n))
          {
            if (one_byte(max_n))
            {
              gf_out(boc1);
              gf_out(boc_c);
              gf_out(max_m - min_m);
              gf_out(max_m);
              gf_out(max_n - min_n);
              gf_out(max_n);
              goto lab_exit;
            }
          }
        } 
      } 
    }
  }
  gf_out(boc);
  gf_four(boc_c);
  gf_four(boc_p);
  gf_four(min_m);
  gf_four(max_m);
  gf_four(min_n);
  gf_four(max_n);
  lab_exit:;
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
  {
    char_ptr[k] = -1;
  }
  if (internal[hppp] <= 0)
    gf_ext = 1055;
  else
  {
    old_setting = selector;
    selector = new_string;
    print_char('.');
    print_int(make_scaled(internal[hppp], 59429463));
    print(1056);
    gf_ext = make_string();
    selector = old_setting;
  }
  set_output_file_name();
  gf_out(pre);
  gf_out(gf_id_byte);
  old_setting = selector;
  selector = new_string;
  print(1054);
  print_int(round_unscaled(internal[year]));
  print_char('.');
  print_dd (round_unscaled(internal[month]));
  print_char('.');
  print_dd (round_unscaled(internal[day]));
  print_char(':');
  t = round_unscaled(internal[time]);
  print_dd(t / 60);
  print_dd(t % 60);
  selector = old_setting;
  gf_out(cur_length);
  gf_string(0, make_string ());
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

  if (output_file_name == 0)
    init_gf();
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
      gf_string(437, 0);
      gf_out(yyy);
      gf_four(x_off * unity);
    }
    if (y_off != 0)
    {
      gf_string(438, 0);
      gf_out(yyy);
      gf_four(y_off * unity);
    }
  }
  prev_n = 4096;
  p = knil(cur_edges);
  n = n_max(cur_edges) - zero_field;
  while (p != cur_edges)
  {
    if (mem[p + 1].hh.lh > 1)
      sort_edges(p);
    q = mem[p + 1].hh.rh;
    w = 0;
    prev_m = -fraction_one;
    ww = 0;
    prev_w = 0;
    m = prev_m;
    do {
      if (q == mem_top)
        mm = fraction_one;
      else
      {
        d = mem[q].hh.lh;
        mm = d / 8;
        ww = ww + (d % 8) - 4;
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
                gf_boc (mem[cur_edges + 2].hh.lh + x_off - 4096, mem[cur_edges + 2].hh.rh + x_off - 4096, mem[cur_edges + 1].hh.lh + y_off - 4096, n + y_off);
                cur_min_m = mem[cur_edges + 2].hh.lh - 4096 + mem[cur_edges + 3].hh.lh;
              }
              else if (prev_n > n + 1)
              {
                delta = prev_n - n - 1;
                if (delta < 0400)
                {
                  gf_out (skip1);
                  gf_out (delta);
                }
                else
                {
                  gf_out (skip1 + 1);
                  gf_two (delta);
                }
              }
              else
              {
                delta = m - cur_min_m;
                if (delta > max_new_row)
                  gf_out (skip0);
                else
                {
                  gf_out (new_row_0 + delta);
                  goto done;
                }
              }
              gf_paint (m - cur_min_m);
              done: prev_n = n;
            }
            else
              gf_paint (m - prev_m);
            prev_m = m;
            prev_w = w;
          }
        }
        else if (w <= 0)
        {
          gf_paint (m - prev_m);
          prev_m = m;
          prev_w = w;
        }
        m = mm;
      }
      w = ww;
      q = mem[q].hh.rh;
    } while (!(mm == fraction_one));
    if (w != 0)
      print_nl(1058);
    if (prev_m - mem[cur_edges + 3].hh.lh + x_off > gf_max_m)
      gf_max_m = prev_m - mem[cur_edges + 3].hh.lh + x_off;
    p = mem[p].hh.lh;
    decr(n);
  }
  if (prev_n == 4096)
  {
    gf_boc (0, 0, 0, 0);
    if (gf_max_m < 0)
      gf_max_m = 0;
    if (gf_min_n > 0)
      gf_min_n = 0;
  }
  else if (prev_n + y_off < gf_min_n)
    gf_min_n = prev_n + y_off;
  gf_out (eoc);
  gf_prev_ptr = gf_offset + gf_ptr;
  incr(total_chars);
  print_char(']');
  fflush (stdout);
  if (internal[tracing_output] > 0)
    print_edges (1057, true, x_off, y_off);
}
/* 1006 */
void try_eq (halfword l, halfword r)
{
  halfword p;
  unsigned char t;
  halfword q;
  halfword pp;
  unsigned char tt;
  boolean copied;

  t = mem[l].hh.b0;
  if (t == 16)
  {
    t = 17;
    p = const_dependency (-mem[l + 1].cint);
    q = p;
  }
  else if (t == 19)
  {
    t = 17;
    p = single_dependency (l);
    mem[p + 1].cint = -mem[p + 1].cint;
    q = dep_final;
  }
  else
  {
    p = mem[l + 1].hh.rh;
    q = p;
    while (true)
    {
      mem[q + 1].cint = -mem[q + 1].cint;
      if (mem[q].hh.lh == 0)
        goto done;
      q = mem[q].hh.rh;
    }
    done: mem[mem[l + 1].hh.lh].hh.rh = mem[q].hh.rh;
    mem[mem[q].hh.rh + 1].hh.lh = mem[l + 1].hh.lh;
    mem[l].hh.b0 = 16;
  }
  if (r == 0)
  {
    if (cur_type == 16)
    {
      mem[q + 1].cint = mem[q + 1].cint + cur_exp;
      goto done1;
    }
    else
    {
      tt = cur_type;
      if (tt == 19)
        pp = single_dependency (cur_exp);
      else
        pp = mem[cur_exp + 1].hh.rh;
    }
  }
  else if (mem[r].hh.b0 == 16)
  {
    mem[q + 1].cint = mem[q + 1].cint + mem[r + 1].cint;
    goto done1;
  }
  else
  {
    tt = mem[r].hh.b0;
    if (tt == 19)
      pp = single_dependency (r);
    else
      pp = mem[r + 1].hh.rh;
  }
  if (tt != 19)
    copied = false;
  else
  {
    copied = true;
    tt = 17;
  }
  watch_coefs = false;
  if (t == tt)
    p = p_plus_q (p, pp, t);
  else if (t == 18)
    p = p_plus_fq (p, unity, pp, 18, 17);
  else
  {
    q = p;
    while (mem[q].hh.lh != 0)
    {
      mem[q + 1].cint = round_fraction (mem[q + 1].cint);
      q = mem[q].hh.rh;
    }
    t = 18;
    p = p_plus_q (p, pp, t);
  }
  watch_coefs = true;
  if (copied)
    flush_node_list (pp);
  done1:;
  if (mem[p].hh.lh == 0)
  {
    if (abs(mem[p + 1].cint) > 64)
    {
      print_err("Inconsistent equation");
      print(899);
      print_scaled(mem[p + 1].cint);
      print_char(')');
      help2("The equation I just read contradicts what was said before.",
        "But don't worry; continue and I'll just ignore it.");
      put_get_error();
    }
    else if (r == 0)
    {
      print_err("Redundant equation");
      help2("I already knew that this equation was true.",
        "But perhaps no harm has been done; let's continue.");
      put_get_error();
    }
    free_node (p, 2);
  }
  else
  {
    linear_eq (p, t);
    if (r == 0)
    {
      if (cur_type != 16)
      {
        if (mem[cur_exp].hh.b0 == 16)
        {
          pp = cur_exp;
          cur_exp = mem[cur_exp + 1].cint;
          cur_type = 16;
          free_node (pp, 2);
        }
      }
    }
  }
}
/* 1001 */
void make_eq (pointer lhs)
{
  small_number t;
  integer v;
  pointer p, q;

lab_restart:
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
      {
        if (t == unknown_path)
        {
          pair_to_path();
          goto lab_restart;
        }
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
          try_eq (p, q);
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
  disp_err(null, "Equation cannot be performed (");
  if (type(lhs) <= pair_type)
    print_type(type(lhs));
  else
    print(340);
  print_char('=');
  if (cur_type <= pair_type)
    print_type(cur_type);
  else
    print(340);
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
    print_nl(850);
    print_exp(lhs, 0);
    print(886);
    print_exp(null, 0);
    print(842);
    end_diagnostic(false);
  }
  if (cur_type == unknown_path)
  {
    if (type(lhs) == pair_type)
    {
      p = stash_cur_exp();
      unstash_cur_exp(lhs);
      lhs = p;
    }
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
    disp_err(null, "Improper `:=' will be changed to `='");
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
      print_nl(123);
      if (info(lhs) > hash_end)
        slow_print(int_name[info(lhs) - (hash_end)]);
      else
        show_token_list(lhs, null, 1000, 0);
      print(461);
      print_exp(null, 0);
      print_char('}');
      end_diagnostic(false);
    }
    if (info(lhs) > hash_end)
    {
      if (cur_type == known)
        internal[info(lhs) - (hash_end)] = cur_exp;
      else
      {
        disp_err(null, "Internal quantity `");
        slow_print(int_name[mem[lhs].hh.lh - (9769)]);
        print(888);
        help2("I can't set an internal quantity to anything but a known",
          "numeric value, so I'll have to ignore this assignment.");
        put_get_error();
      }
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
        make_eq (p);
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
        help_line[2] = 909;
      put_get_error();
      scanner_status = flushing;
      do {
        get_next();
        if (cur_cmd == string_token)
        {
          delete_str_ref(cur_mod);
        }
      } while (!(cur_cmd >= comma));
      scanner_status = 0;
    }
  } while (!(cur_cmd > comma));
}
/* 1021 */
void do_random_seed (void)
{
  get_x_next();
  if (cur_cmd != assignment)
  {
    missing_err(461);
    help1("Always say `randomseed:=<numeric expression>'.");
    back_error();
  }
  get_x_next();
  scan_expression();
  if (cur_type != 16)
  {
    disp_err(null, "Unknown value will be ignored");
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
      print_nl(918);
      print_scaled(cur_exp);
      print_char('}');
      print_nl(261);
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
    t = eqtb[cur_sym].lh;
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
      print(929);
    else
      slow_print(text(cur_sym));
    print(930);
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
  {
    if (cur_cmd != assignment)
    {
      missing_err(61);
      help3("You should have said `let symbol = something'.",
        "But don't worry; I'll pretend that an equals sign",
        "was present. The next token I read will be `something'.");
      back_error();
    }
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
    print_nl(765);
    print_exp(0, 2);
    flush_cur_exp(0);
  } while (!(cur_cmd != comma));
}
/* 1041 */
void disp_token (void)
{
  print_nl(940);
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
      print(941);
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
  print_nl(950);
#ifdef STAT
  print_int(var_used);
  print_char('&');
  print_int(dyn_used);
  if (false)
#endif /* STAT */
  print(357);
  print(558);
  print_int(hi_mem_min - lo_mem_max - 1);
  print(951);
  print_ln();
  print_nl(952);
  print_int(str_ptr - init_str_ptr);
  print_char('&');
  print_int(pool_ptr - init_pool_ptr);
  print(558);
  print_int(max_strings - max_str_ptr);
  print_char('&');
  print_int(pool_size - max_pool_ptr);
  print(951);
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
    print_nl(261);
    print_variable_name(p);
    if (type(p) > unsuffixed_macro)
      print(665);
    print(953);
    if (file_offset >= max_print_line - 20)
      n = 5;
    else
      n = max_print_line - file_offset - 15;
    show_macro(value(p), null, n);
  }
  else if (type(p) != undefined)
  {
    print_nl(261);
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
    {
      if (cur_sym <= hash_end)
      {
        if (cur_cmd == tag_token)
        {
          if (cur_mod != null)
          {
            disp_var(cur_mod);
            goto done;
          }
        }
      }
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
      print_nl(261);
      print_variable_name(p);
      if (type(p) == dependent)
        print_char('=');
      else
        print(768);
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
      help_ptr = 0;
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
  boolean Result;
  small_number t;
  boolean result;

  t = cur_mod;
  cur_type = vacuous;
  get_x_next();
  scan_expression();
  result = false;
  if (cur_type != t)
  {
    disp_err(null, "Improper type");
    help2("Next time say `withweight <known numeric expression>';",
      "I'll ignore the bad `with' clause and look for another.");
    if (t == 6)
      help_line[1] = 966;
    put_get_flush_error(0);
  }
  else if (cur_type == 6)
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
  Result = result;
  return Result;
}
/* 1057 */
void find_edges_var (halfword t)
{
  halfword p;

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
    print(968);
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
    disp_err(null, "Not a suitable variable");
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
        disp_err(null, "Improper `addto'");
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
        disp_err(null, "Improper `addto'");
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
          if (scan_with ())
          {
            if (cur_type == known)
              w = cur_exp;
            else
            {
              delete_pen_ref(cur_pen);
              cur_pen = cur_exp;
            }
          }
        find_edges_var(lhs);
        if (cur_edges == null)
          toss_knot_list(rhs);
        else
        {
          lhs = null;
          cur_path_type = add_to_type;
          if (left_type(rhs) == endpoint)
          {
            if (cur_path_type == double_path_code)
            {
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
          }
          else if (cur_path_type == double_path_code)
            lhs = htap_ypoc(rhs);
          cur_wt = w;
          rhs = make_spec(rhs, max_offset(cur_pen), internal[tracing_specs]);
          if (turning_number <= 0)
          {
            if (cur_path_type != double_path_code)
            {
              if (internal[turning_check] > 0)
              {
                if ((turning_number < 0) && (link(cur_pen) == null))
                  cur_wt = -cur_wt;
                else
                {
                  if (turning_number == 0)
                  {
                    if ((internal[turning_check] <= unity) && (link(cur_pen) == null))
                      goto done;
                    else
                      print_strange(980);
                  }
                  else
                    print_strange(981);
                  help3("The path doesn't have a counterclockwise orientation,",
                    "so I'll probably have trouble drawing it.",
                    "(See Chapter 27 of The METAFONTbook for more help.)");
                  put_get_error();
                }
              }
            }
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
  scaled Result;
  if (abs(internal[m]) >= fraction_half)
  {
    print_err("Enormous ");
    print(int_name[m]);
    print(1002);
    help1("Font metric dimensions must be less than 2048pt.");
    put_get_error();
    if (internal[m] > 0)
      Result = fraction_half - 1;
    else
      Result = 1 - fraction_half;
  }
  else
    Result = internal[m];
  return Result;
}
/* 1070 */
void do_ship_out (void)
{
  integer c;

  get_x_next();
  var_flag = semicolon;
  scan_expression();
  if (cur_type != token_list)
  {
    if (cur_type == picture_type)
      cur_edges = cur_exp;
    else
    {
      {
        disp_err(null, "Not a suitable variable");
        help4("At this point I needed to see the name of a picture variable.",
          "(Or perhaps you have indeed presented me with one; I might",
          "have missed it, if it wasn't followed by the proper token.)", 
          "So I'll not change anything just now.");
        put_get_flush_error(0);
      }
      goto lab_exit;
    }
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
  lab_exit:;
}
/* 1071 */
void do_display (void)
{
  halfword e;

  get_x_next();
  var_flag = in_window;
  scan_primary();
  if (cur_type != token_list)
  {
    disp_err(null, "Not a suitable variable");
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
    if (cur_edges != 0)
      disp_edges(cur_exp);
    goto lab_exit;
  not_found:
    cur_exp = cur_exp * unity;
  common_ending:
    disp_err(null, "Bad window number");
    help1("It should be the number of an open window.");
    put_get_flush_error(0);
    flush_token_list(e);
  }
  lab_exit:;
}
/* 1072 */
boolean get_pair (command_code c)
{
  boolean Result;
  pointer p;
  boolean b;

  if (cur_cmd != c)
    Result = false;
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
    Result = b;
  }
  return Result;
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
  goto lab_exit;
not_found:
  print_err("Improper `openwindow'");
  help2("Say `openwindow k from (r0,c0) to (r1,c1) at (x,y)',",
    "where all quantities are known and k is between 0 and 15.");
  put_get_error();
  lab_exit:;
}
/* 1047 */
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
    disp_err(null, "Not a suitable variable");
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
    if (keeping == 0)
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
    goto lab_exit;
  not_found:
    print_err("Bad culling amounts");
    help1("Always cull by known amounts that exclude 0.");
    put_get_error();
    flush_token_list(e);
  }
  lab_exit:;
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
          print_nl(261);
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
          {
            delete_str_ref(err_help);
          }
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
  eight_bits Result;
  integer c;

  get_x_next();
  scan_expression();
  if (cur_type == known)
  {
    c = round_unscaled(cur_exp);
    if (c >= 0)
    {
      if (c < 256)
        goto found;
    }
  }
  else if (cur_type == string_type)
  {
    if (length(cur_exp) == 1)
    {
      c = str_pool[str_start[cur_exp]];
      goto found;
    }
  }
  disp_err(null, "Invalid code has been replaced by 0");
  help2("I was looking for a number between 0 and 255, or for a",
    "string of length 1. Didn't find it; will use 0 instead.");
  put_get_flush_error(0);
  c = 0;
found:
  Result = c;
  return Result;
}
/* 1104 */
void set_tag (halfword c, small_number t, halfword r)
{
  if (char_tag[c] == no_tag)
  {
    char_tag[c] = t;
    char_remainder[c] = r;
    if (t == 1)
    {
      incr(label_ptr);
      label_loc[label_ptr] = r;
      label_char[label_ptr] = c;
    }
  }
  else
  {
    print_err("Character ");
    if ((c > 32) && (c < 127))
      print(c);
    else if (c == 256)
      print(1013);
    else
    {
      print(1014);
      print_int(c);
    }
    print(1015);
    switch (char_tag[c])
    {
      case lig_tag:
        print(1016);
        break;
      case list_tag:
        print(1017);
        break;
      case ext_tag:
        print(1006);
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
      lab_continue:
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
                goto lab_continue;
              }
              skip_byte(ll) = qi(nl - ll - 1);
              ll = ll - lll;
            } while (!(lll == 0));
          }
          goto lab_continue;
        }
        if (cur_cmd == lig_kern_token)
        {
          next_char(nl) = qi(c);
          skip_byte(nl) = qi(0);
          if (cur_mod < 128)
          {
            op_byte(nl) = qi(cur_mod);
            rem_byte(nl) = qi(get_code);
          }
          else
          {
            get_x_next();
            scan_expression();
            if (cur_type != known)
            {
              disp_err(null, "Improper kern");
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
          goto lab_continue;
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
          missing_extensible_punctuation(58);
        ext_top(ne) = qi(get_code);
        if (cur_cmd != comma)
          missing_extensible_punctuation(44);
        ext_mid(ne) = qi(get_code);
        if (cur_cmd != comma)
          missing_extensible_punctuation(44);
        ext_bot(ne) = qi(get_code);
        if (cur_cmd != comma)
          missing_extensible_punctuation(44);
        ext_rep(ne) = qi(get_code);
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
          disp_err(null, "Improper location");
          help2("I was looking for a known, positive number.",
            "For safety's sake I'll ignore the present command.");
          put_get_error();
        }
        else
        {
          j = round_unscaled(cur_exp);
          if (cur_cmd != colon)
          {
            missing_err(58);
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
                disp_err(null, "Improper font parameter");
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
  {
    if (cur_type != m)
    {
      disp_err(null, "Unsuitable expression");
      help1("The expression shown above has the wrong type to be output.");
      put_get_error();
    }
    else
    {
      if (output_file_name == 0)
        init_gf();
      if (m == string_type)
        gf_string(cur_exp, 0);
      else
      {
        gf_out(yyy);
        gf_four(cur_exp);
      }
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
  ASCII_code * baseengine;

  selector = new_string;
  print(1073);
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
  pack_job_name(742);
  while (!w_open_out(base_file))
    prompt_file_name(1074, 742);
  print_nl("Beginning to dump on file ");
  slow_print(w_make_name_string(base_file));
  flush_string(str_ptr - 1);
  print_nl("");
  slow_print(base_ident);
  dump_int(1462914374L);
  x = strlen(enginename);
  baseengine = xmallocarray(ASCII_code, x + 4);
  strcpy(stringcast(baseengine), enginename);
  for (k = x; k <= x + 3; k++)
  {
    baseengine[k] = 0;
  }
  x = x + 4 - (x % 4);
  dump_int(x);
  dumpthings(baseengine[0], x);
  libcfree(baseengine);
  dump_int(4795517L);
  dumpthings(xord[0], 256);
  dumpthings(xchr[0], 256);
  dump_int(0);
  dump_int(mem_top);
  dump_int(9500);
  dump_int(7919);
  dump_int(15);
  dump_int(pool_ptr);
  dump_int(str_ptr);
  for (k = 0; k <= str_ptr; k++)
  {
    dump_int(str_start[k]);
  }
  k = 0;
  while (k + 4 < pool_ptr)
  {
    w.b0 = str_pool[k];
    w.b1 = str_pool[k + 1];
    w.b2 = str_pool[k + 2];
    w.b3 = str_pool[k + 3];
    dump_qqqq(w);
    k = k + 4;
  }
  k = pool_ptr - 4;
  w.b0 = str_pool[k];
  w.b1 = str_pool[k + 1];
  w.b2 = str_pool[k + 2];
  w.b3 = str_pool[k + 3];
  dump_qqqq(w);
  print_ln();
  print_int(str_ptr);
  print(1070);
  print_int(pool_ptr);
  sort_avail();
  var_used = 0;
  dump_int(lo_mem_max);
  dump_int(rover);
  p = 0;
  q = rover;
  x = 0;
  do {
    for (k = p; k <= q + 1; k++)
    {
      dumpwd(mem[k]);
    }
    x = x + q + 2 - p;
    var_used = var_used + q - p;
    p = q + mem[q].hh.lh;
    q = mem[q + 1].hh.rh;
  } while (!(q == rover));
  var_used = var_used + lo_mem_max - p;
  dyn_used = mem_end + 1 - hi_mem_min;
  for (k = p; k <= lo_mem_max; k ++)
  {
    dumpwd(mem[k]);
  }
  x = x + lo_mem_max + 1 - p;
  dump_int(hi_mem_min);
  dump_int(avail);
  for (k = hi_mem_min; k <= mem_end; k++)
  {
    dumpwd(mem[k]);
  }
  x = x + mem_end + 1 - hi_mem_min;
  p = avail;
  while (p != 0)
  {
    decr(dyn_used);
    p = mem[p].hh.rh;
  }
  dump_int(var_used);
  dump_int(dyn_used);
  print_ln();
  print_int(x);
  print(1071);
  print_int(var_used);
  print_char('&');
  print_int(dyn_used);
  dump_int(hash_used);
  st_count = 9756 - hash_used;
  for (p = 1; p <= hash_used; p++)
  {
    if (hash[p].rh != 0)
    {
      dump_int(p);
      dumphh(hash[p]);
      dumphh(eqtb[p]);
      incr(st_count);
    }
  }
  for (p = hash_used + 1; p <= 9769; p++)
  {
    dumphh(hash[p]);
    dumphh(eqtb[p]);
  }
  dump_int(st_count);
  print_ln();
  print_int(st_count);
  print(1072);
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
  dump_int(69069L);
  internal[tracing_stats] = 0;
  wclose(base_file);
}
/* 989 */
void do_statement (void)
{
  cur_type = vacuous;
  get_x_next();
  if (cur_cmd > plus_or_minus)
  {
    if (cur_cmd < semicolon)
    {
      print_err("A statement can't begin with `");
      print_cmd_mod (cur_cmd, cur_mod);
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
          print_nl(261);
          slow_print(cur_exp);
          fflush(stdout);
        }
        if (internal[proofing] > 0)
        {
          if (output_file_name == 0)
            init_gf();
          gf_string(1063, cur_exp);
        }
      }
      else if (cur_type != vacuous)
      {
        disp_err(null, "Isolated expression");
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
        doopen_window();
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
      {
        delete_str_ref(cur_mod);
      }
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
  pointer Result;
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
  Result = link(p);
  return Result;
}
/* 1118 */
integer min_cover (scaled d)
{
  integer Result;
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
  Result = m;
  return Result;
}
/* 1120 */
scaled threshold (integer m)
{
  scaled Result;
  scaled d;

  excess = min_cover(0) - m;
  if (excess <= 0)
    Result = 0;
  else
  {
    do {
      d = perturbation;
    } while (!(min_cover(d + d) <= m));
    while (min_cover(d) > m)
      d = perturbation;
    Result = d;
  }
  return Result;
}
/* 1121 */
integer skimp (integer m)
{
  integer Result;
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
  Result = m;
  return Result;
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
      print_nl(1044);
    d = 8388608;
    internal[design_size] = d;
  }
  if (header_byte[5] < 0)
  {
    if (header_byte[6] < 0)
    {
      if (header_byte[7] < 0)
      {
        if (header_byte[8] < 0)
        {
          header_byte[5] = d / 1048576;
          header_byte[6] = (d / 4096) % 256;
          header_byte[7] = (d / 16) % 256;
          header_byte[8] = (d % 16) * 16;
        }
      }
    }
  }
  max_tfm_dimen = 16 * internal[design_size] - 1 - internal[design_size] / 2097152;
  if (max_tfm_dimen >= fraction_half)
    max_tfm_dimen = fraction_half - 1;
}
/* 1129 */
integer dimen_out (scaled x)
{
  integer Result;

  if (abs(x) > max_tfm_dimen)
  {
    incr(tfm_changed);
    if (x > 0)
      x = max_tfm_dimen;
    else
      x = -max_tfm_dimen;
  }
  x = make_scaled(x * 16, internal[design_size]);
  Result = x;
  return Result;
}
/* 1131 */
void fix_check_sum (void)
{
  eight_bits k;
  eight_bits lb1, lb2, lb3, b4;
  integer x;

  if (header_byte[1] < 0)
  {
    if (header_byte[2] < 0)
    {
      if (header_byte[3] < 0)
      {
        if (header_byte[4] < 0)
        {
          lb1 = bc;
          lb2 = ec;
          lb3 = bc;
          b4 = ec;
          tfm_changed = 0;
          for (k = bc; k <= ec; k++)
          {
            if (char_exists[k])
            {
              x = dimen_out(value(tfm_width[k])) + (k + 4) * 4194304;
              lb1 = (lb1 + lb1 + x) % 255;
              lb2 = (lb2 + lb2 + x) % 253;
              lb3 = (lb3 + lb3 + x) % 251;
              b4 = (b4 + b4 + x) % 247;
            }
          }
          header_byte[1] = lb1;
          header_byte[2] = lb2;
          header_byte[3] = lb3;
          header_byte[4] = b4;
          goto lab_exit;
        }
      }
    }
  }
  for (k = 1; k <= 4; k++)
  {
    if (header_byte[k] < 0)
      header_byte[k] = 0;
  }
lab_exit:;
}
/* 1133 */
void tfm_qqqq (four_quarters x)
{
  putbyte(x.b0, tfm_file);
  putbyte(x.b1, tfm_file);
  putbyte(x.b2, tfm_file);
  putbyte(x.b3, tfm_file);
}
/* 779 */
boolean open_base_file (void)
{
  boolean Result;
  integer j;

  j = loc;
  if (buffer[loc] == 38)
  {
    incr(loc);
    j = loc;
    buffer[last] = 32;
    while (buffer[j] != 32)
      incr(j);
    pack_buffered_name(0, loc, j - 1);
    if (w_open_in(base_file))
      goto found;
    fputs(stdout, "Sorry, I can't find the base `");
    fputs(stringcast(name_of_file + 1), stdout);
    Fputs(stdout, "'; will try `");
    fputs(MF_base_default + 1, stdout);
    fprintf(stdout, "%s\n", "'.");
    fflush(stdout);
  }
  pack_buffered_name(base_default_length - 5, 1, 0);
  if (!w_open_in(base_file))
  {
    fputs(stdout, "I can't find the base file `");
    fputs(MF_base_default + 1, stdout);
    fprintf(stdout, "%s\n", "'!");
    Result = false;
    goto lab_exit;
  }
found:
  loc = j;
  Result = true;
  lab_exit:;
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
  ASCII_code * baseengine;
  ASCII_code dummyxord;
  ASCII_code dummyxchr;

  undump_int(x);
  if (x != 1462914374L)
    goto lab6666;
  undump_int(x);
  if ((x < 0) || (x > 256))
    goto lab6666;
  baseengine = xmallocarray(ASCII_code, x);
  undumpthings(baseengine[0], x);
  baseengine[x - 1] = 0;
  if (strcmp(enginename, stringcast(baseengine)))
  {
    fprintf(stdout, "%s%s%s%s\n", "---! ", stringcast(name_of_file + 1), " was written by ", stringcast(baseengine));
    libcfree(baseengine);
    goto lab6666;
  }
  libcfree(baseengine);
  undump_int(x);
  if (x != 4795517L)
  {
    ;
    fprintf(stdout, "%s%s%s%s\n", "---! ", stringcast(name_of_file + 1), " doesn't match ", pool_name);
    goto lab6666;
  }
  {
    undumpthings(xord[0], 256);
    undumpthings(xchr[0], 256);
  }
  undump_int(x);
  if (x != 0)
    goto lab6666;
  ;
#ifdef INIMF
  if (iniversion)
  {
    libcfree(mem);
  }
#endif /* INIMF */
  undump_int(mem_top);
  if (mem_max < mem_top)
    mem_max = mem_top;
  if (1100 > mem_top)
    goto lab6666;
  mem = xmallocarray(memory_word, mem_max + 1);
  undump_int(x);
  if (x != 9500)
    goto lab6666;
  undump_int(x);
  if (x != 7919)
    goto lab6666;
  undump_int(x);
  if (x != 15)
    goto lab6666;
  {
    undump_int(x);
    if (x < 0)
      goto lab6666;
    if (x > pool_size)
    {
      ;
      fprintf(stdout, "%s%s\n", "---! Must increase the ", "string pool size");
      goto lab6666;
    }
    else pool_ptr = x;
  }
  {
    undump_int(x);
    if (x < 0)
      goto lab6666;
    if (x > max_strings)
    {
      ;
      fprintf(stdout, "%s%s\n", "---! Must increase the ", "max strings");
      goto lab6666;
    }
    else str_ptr = x;
  }
  for (k = 0; k <= str_ptr; k++)
  {
    {
      undump_int(x);
      if ((x < 0) || (x > pool_ptr))
        goto lab6666;
      else str_start[k] = x;
    }
    str_ref[k] = 127;
  }
  k = 0;
  while (k + 4 < pool_ptr)
  {
    undumpqqqq(w);
    str_pool[k] = w.b0;
    str_pool[k + 1] = w.b1;
    str_pool[k + 2] = w.b2;
    str_pool[k + 3] = w.b3;
    k = k + 4;
  }
  k = pool_ptr - 4;
  undumpqqqq(w);
  str_pool[k] = w.b0;
  str_pool[k + 1] = w.b1;
  str_pool[k + 2] = w.b2;
  str_pool[k + 3] = w.b3;
  init_str_ptr = str_ptr;
  init_pool_ptr = pool_ptr;
  max_str_ptr = str_ptr;
  max_pool_ptr = pool_ptr;
  {
    undump_int(x);
    if ((x < 1022) || (x > mem_top - 3))
      goto lab6666;
    else
      lo_mem_max = x;
  }
  {
    undump_int(x);
    if ((x < 23) || (x > lo_mem_max))
      goto lab6666;
    else
      rover = x;
  }
  p = 0;
  q = rover;
  do {
    for (k = p; k <= q + 1; k++)
    {
      undumpwd(mem[k]);
    }
    p = q + mem[q].hh.lh;
    if ((p > lo_mem_max) || ((q >= mem[q + 1].hh.rh) && (mem[q + 1].hh.rh != rover)))
      goto lab6666;
    q = mem[q + 1].hh.rh;
  } while (!(q == rover));
  for (k = p; k <= lo_mem_max; k++)
  {
    undumpwd(mem[k]);
  }
  {
    undump_int(x);
    if ((x < lo_mem_max + 1) || (x > mem_top - 2))
      goto lab6666;
    else
      hi_mem_min = x;
  }
  {
    undump_int(x);
    if ((x < 0) || (x > mem_top))
      goto lab6666;
    else
      avail = x;
  }
  mem_end = mem_top;
  for (k = hi_mem_min; k <= mem_end; k++)
  {
    undumpwd(mem[k]);
  }
  undump_int(var_used);
  undump_int(dyn_used);
  {
    undump_int(x);
    if ((x < 1) || (x > 9757))
      goto lab6666;
    else
      hash_used = x;
  }
  p = 0;
  do {
    {
      undump_int(x);
      if ((x < p + 1) || (x > hash_used))
        goto lab6666;
      else
        p = x;
    }
    undumphh(hash[p]);
    undumphh(eqtb[p]);
  } while (!(p == hash_used));
  for (p = hash_used + 1; p <= 9769; p++)
  {
    undumphh(hash[p]);
    undumphh(eqtb[p]);
  }
  undump_int(st_count);
  {
    undump_int(x);
    if ((x < 41) || (x > max_internal))
      goto lab6666;
    else
      int_ptr = x;
  }
  for (k = 1; k <= int_ptr; k++)
  {
    undump_int(internal[k]);
    {
      undump_int(x);
      if ((x < 0) || (x > str_ptr))
        goto lab6666;
      else
        int_name[k] = x;
    }
  }
  {
    undump_int(x);
    if ((x < 0) || (x > 9757))
      goto lab6666;
    else
      start_sym = x;
  }
  {
    undump_int(x);
    if ((x < 0) || (x > 3))
      goto lab6666;
    else
      interaction = x;
  }
  {
    undump_int(x);
    if ((x < 0) || (x > str_ptr))
      goto lab6666;
    else
      base_ident = x;
  }
  {
    undump_int(x);
    if ((x < 1) || (x > 9769))
      goto lab6666;
    else
      bg_loc = x;
  }
  {
    undump_int(x);
    if ((x < 1) || (x > 9769))
      goto lab6666;
    else
      eg_loc = x;
  }
  undump_int(serial_no);
  undump_int(x);
  if (x != 69069L)
    goto lab6666;
  Result = true;
  goto lab_exit;
lab6666:;
  fprintf(stdout, "%s\n", "(Fatal base file error; I'm stymied)");
  Result = false;
lab_exit:;
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
lab_restart:
  check_arith();
#ifdef TEXMF_DEBUG
  if (panicking)
    check_mem(false);
#endif /* TEXMF_DEBUG */
  if (interrupt != 0)
  {
    if (OK_to_interrupt)
    {
      back_input();
      check_interrupt();
      get_x_next();
    }
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
            disp_err(null, "Nonnumeric ypart has been replaced by 0");
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
          show_cmd_mod (cur_cmd, cur_mod);
        save_boundary_item(p);
        do {
          do_statement();
        } while (!(cur_cmd != semicolon));
        if (cur_cmd != end_group)
        {
          print_err("A group begun on line ");
          print_int(group_line);
          print(781);
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
        {
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
          missing_err (479);
          print(716);
          print_cmd_mod(37, c);
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
        cur_type = 4;
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
                goto lab_restart;
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
                bad_sub_script();
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
          goto lab_restart;
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
          help_line[2] = 797;
          help_line[1] = 798;
          help_line[0] = 799;
          put_get_flush_error(0);
        }
        flush_node_list(q);
        goto done;
      }
      break;
    default:
      {
        bad_exp(769);
        goto lab_restart;
      }
      break;
  }
  get_x_next();
done:
  if (cur_cmd == left_bracket)
  {
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
          missing_err(93);
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
        bad_sub_script();
      if (cur_cmd != right_bracket)
      {
        missing_err(93);
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

lab_restart:
  if ((cur_cmd < min_primary_command) || (cur_cmd > max_primary_command))
    bad_exp(804);
  scan_primary();
lab_continue:
  if (cur_cmd <= max_secondary_command)
  {
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
        goto lab_restart;
      }
      goto lab_continue;
    }
  }
}
/* 864 */
void scan_tertiary (void)
{
  pointer p;
  halfword c, d;
  halfword mac_name;

lab_restart:
  if ((cur_cmd < min_primary_command) || (cur_cmd > max_primary_command))
    bad_exp(805);
  scan_secondary();
  if (cur_type == future_pen)
    materialize_pen();
lab_continue:
  if (cur_cmd <= max_tertiary_command)
  {
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
        goto lab_restart;
      }
      goto lab_continue;
    }
  }
}
/* 868 */
void scan_expression (void)
{
  halfword p, q, r, pp, qq;
  halfword c, d;
  unsigned char myvar_flag;
  halfword macname;
  boolean cyclehit;
  scaled x, y;
  unsigned char t;

  myvar_flag = var_flag;
lab_restart:
  if ((cur_cmd < type_name) || (cur_cmd > plus_or_minus))
    bad_exp (808);
  scan_tertiary();
lab_continue:
  if (cur_cmd <= equals)
  {
    if (cur_cmd >= left_brace)
    {
      if ((cur_cmd != equals) || (myvar_flag != 77))
      {
        p = stash_cur_exp();
        c = cur_mod;
        d = cur_cmd;
        if (d == 49)
        {
          macname = cur_sym;
          incr(mem[c].hh.lh);
        }
        if ((d < 48) || ((d == 48) && ((mem[p].hh.b0 == 14) || (mem[p].hh.b0 == 9))))
        {
          cyclehit = false;
          {
            unstash_cur_exp (p);
            if (cur_type == 14)
              p = new_knot();
            else if (cur_type == 9)
              p = cur_exp;
            else
              goto lab_exit;
            q = p;
            while (mem[q].hh.rh != p)
              q = mem[q].hh.rh;
            if (mem[p].hh.b0 != 0)
            {
              r = copy_knot (p);
              mem[q].hh.rh = r;
              q = r;
            }
            mem[p].hh.b0 = 4;
            mem[q].hh.b1 = 4;
          }
        lab25:
          if (cur_cmd == left_brace)
          {
            t = scan_direction();
            if (t != 4)
            {
              mem[q].hh.b1 = t;
              mem[q + 5].cint = cur_exp;
              if (mem[q].hh.b0 == 4)
              {
                mem[q].hh.b0 = t;
                mem[q + 3].cint = cur_exp;
              }
            }
          }
          d = cur_cmd;
          if (d == 47)
          {
            get_x_next();
            if (cur_cmd == tension)
            {
              get_x_next();
              y = cur_cmd;
              if (cur_cmd == at_least)
                get_x_next();
              scan_primary();
              if ((cur_type != 16) || (cur_exp < three_quarter_unit))
              {
                disp_err (null, "Improper tension has been set to 1");
                help1("The expression above should have been a number >=3/4.");
                put_get_flush_error (unity);
              }
              if (y == 59)
                cur_exp = -cur_exp;
              mem[q + 6].cint = cur_exp;
              if (cur_cmd == and_command)
              {
                get_x_next();
                y = cur_cmd;
                if (cur_cmd == at_least)
                  get_x_next();
                scan_primary();
                if ((cur_type != 16) || (cur_exp < three_quarter_unit))
                {
                  disp_err(null, "Improper tension has been set to 1");
                  help1("The expression above should have been a number >=3/4.");
                  put_get_flush_error (unity);
                }
                if (y == 59)
                  cur_exp = -cur_exp;
              }
              y = cur_exp;
            }
            else if (cur_cmd == controls)
            {
              mem[q].hh.b1 = 1;
              t = 1;
              get_x_next();
              scan_primary();
              known_pair();
              mem[q + 5].cint = cur_x;
              mem[q + 6].cint = cur_y;
              if (cur_cmd != and_command)
              {
                x = mem[q + 5].cint;
                y = mem[q + 6].cint;
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
              mem[q + 6].cint = unity;
              y = unity;
              back_input();
              goto done;
            }
            if (cur_cmd != path_join)
            {
              missing_err (408);
              help1("A path join command should end with two dots.");
              back_error();
            }
            done:;
          }
          else if (d != 48)
            goto lab26;
          get_x_next();
          if (cur_cmd == left_brace)
          {
            t = scan_direction();
            if (mem[q].hh.b1 != 1)
              x = cur_exp;
            else
              t = 1;
          }
          else if (mem[q].hh.b1 != 1)
          {
            t = 4;
            x = 0;
          }
          if (cur_cmd == cycle)
          {
            cyclehit = true;
            get_x_next();
            pp = p;
            qq = p;
            if (d == 48)
            {
              if (p == q)
              {
                d = 47;
                mem[q + 6].cint = unity;
                y = unity;
              }
            }
          }
          else
          {
            scan_tertiary();
            {
              if (cur_type != 9)
                pp = new_knot();
              else
                pp = cur_exp;
              qq = pp;
              while (mem[qq].hh.rh != pp)
                qq = mem[qq].hh.rh;
              if (mem[pp].hh.b0 != 0)
              {
                r = copy_knot (pp);
                mem[qq].hh.rh = r;
                qq = r;
              }
              mem[pp].hh.b0 = 4;
              mem[qq].hh.b1 = 4;
            }
          }
          {
            if (d == 48)
            {
              if ((mem[q + 1].cint != mem[pp + 1].cint) || (mem[q + 2].cint != mem[pp + 2].cint))
              {
                print_err("Paths don't touch; `&' will be changed to `..'");
                help3("When you join paths `p&q', the ending point of p",
                  "must be exactly equal to the starting point of q.",
                  "So I'm going to pretend that you said `p..q' instead.");
                put_get_error();
                d = 47;
                mem[q + 6].cint = unity;
                y = unity;
              }
            }
            if (mem[pp].hh.b1 == 4)
            {
              if ((t == 3) || (t == 2))
              {
                mem[pp].hh.b1 = t;
                mem[pp + 5].cint = x;
              }
            }
            if (d == 48)
            {
              if (mem[q].hh.b0 == 4)
              {
                if (mem[q].hh.b1 == 4)
                {
                  mem[q].hh.b0 = 3;
                  mem[q + 3].cint = unity;
                }
              }
              if (mem[pp].hh.b1 == 4)
              {
                if (t == 4)
                {
                  mem[pp].hh.b1 = 3;
                  mem[pp + 5].cint = unity;
                }
              }
              mem[q].hh.b1 = mem[pp].hh.b1;
              mem[q].hh.rh = mem[pp].hh.rh;
              mem[q + 5].cint = mem[pp + 5].cint;
              mem[q + 6].cint = mem[pp + 6].cint;
              free_node (pp, 7);
              if (qq == pp)
                qq = q;
            }
            else
            {
              if (mem[q].hh.b1 == 4)
              {
                if ((mem[q].hh.b0 == 3) || (mem[q].hh.b0 == 2))
                {
                  mem[q].hh.b1 = mem[q].hh.b0;
                  mem[q + 5].cint = mem[q + 3].cint;
                }
              }
              mem[q].hh.rh = pp;
              mem[pp + 4].cint = y;
              if (t != 4)
              {
                mem[pp + 3].cint = x;
                mem[pp].hh.b0 = t;
              }
            }
            q = qq;
          }
          if (cur_cmd >= left_brace)
          {
            if (cur_cmd <= ampersand)
            {
              if (!cyclehit)
                goto lab25;
            }
          }
        lab26:
          if (cyclehit)
          {
            if (d == 48)
              p = q;
          }
          else
          {
            mem[p].hh.b0 = 0;
            if (mem[p].hh.b1 == 4)
            {
              mem[p].hh.b1 = 3;
              mem[p + 5].cint = unity;
            }
            mem[q].hh.b1 = 0;
            if (mem[q].hh.b0 == 4)
            {
              mem[q].hh.b0 = 3;
              mem[q + 3].cint = unity;
            }
            mem[q].hh.rh = p;
          }
          make_choices (p);
          cur_type = 9;
          cur_exp = p;
        }
        else
        {
          get_x_next();
          scan_tertiary();
          if (d != 49)
            do_binary (p, c);
          else
          {
            back_input();
            binary_mac (p, c, macname);
            decr(mem[c].hh.lh);
            get_x_next();
            goto lab_restart;
          }
        }
        goto lab_continue;
      }
    }
  }
  lab_exit:;
}
/* 892 */
void get_boolean (void)
{
  get_x_next();
  scan_expression();
  if (cur_type != boolean_type)
  {
    disp_err(null, "Undefined condition will be treated as `false'");
    help2("The expression shown above should have had a definite",
      "true-or-false value. I'm changing it to `false'.");
    put_get_flush_error(31);
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
      { putc (' ', log_file); putc ('\n', log_file); }
      fprintf (log_file, "%s%s\n", "Here is how much of METAFONT's memory", " you used:");
      fprintf (log_file, "%c%ld%s", ' ', (long)max_str_ptr - init_str_ptr, " string");
      if (max_str_ptr != init_str_ptr + 1)
        putc ('s', log_file);
      fprintf (log_file, "%s%ld\n", " out of ", (long)max_strings - init_str_ptr);
      fprintf (log_file, "%c%ld%s%ld\n", ' ', (long)max_pool_ptr - init_pool_ptr, " string characters out of ", (long)pool_size - init_pool_ptr);
      fprintf (log_file, "%c%ld%s%ld\n", ' ', (long)lo_mem_max + 0 + mem_end - hi_mem_min + 2, " words of memory out of ", (long)mem_end + 1);
      fprintf (log_file, "%c%ld%s%ld\n", ' ', (long)st_count, " symbolic tokens out of ", (long)9500);
      fprintf (log_file, "%c%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%c\n", ' ', (long)max_in_stack, "i,", (long)int_ptr, "n,",       (long)max_rounding_ptr, "r,", (long)max_param_stack, "p,", (long)max_buf_stack + 1,       "b stack positions out of ", (long)stack_size, "i,", (long)max_internal, "n,", (long)max_wiggle, "r,", (long)150, "p,", (long)buf_size, 'b');
    }
  }
#endif /* STAT */
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
    {
      if (char_exists[k])
        tfm_width[k] = sort_in(tfm_width[k]);
    }
    nw = skimp(255) + 1;
    dimen_head[1] = link(temp_head);
    if (perturbation >= 4096)
      tfm_warning(char_wd);
    fix_design_size();
    fix_check_sum();
    if (internal[fontmaking] > 0)
    {
      clear_the_list();
      for (k = bc; k <= ec; k++)
      {
        if (char_exists[k])
        {
          if (tfm_height[k] == 0)
            tfm_height[k] = zero_val;
          else
            tfm_height[k] = sort_in(tfm_height[k]);
        }
      }
      nh = skimp(15) + 1;
      dimen_head[2] = link(temp_head);
      if (perturbation >= 4096)
        tfm_warning(char_ht);
      mem[mem_top - 1].hh.rh = 19;
      for (k = bc; k <= ec; k++)
      {
        if (char_exists[k])
        {
          if (tfm_depth[k] == 0)
            tfm_depth[k] = zero_val;
          else
            tfm_depth[k] = sort_in(tfm_depth[k]);
        }
      }
      nd = skimp(15) + 1;
      dimen_head[3] = link(temp_head);
      if (perturbation >= 4096)
        tfm_warning(char_dp);
      clear_the_list();
      for (k = bc; k <= ec; k++)
      {
        if (char_exists[k])
        {
          if (tfm_ital_corr[k] == 0)
            tfm_ital_corr[k] = zero_val;
          else
            tfm_ital_corr[k] = sort_in (tfm_ital_corr[k]);
        }
      }
      ni = skimp(63) + 1;
      dimen_head[4] = link(temp_head);
      if (perturbation >= 4096)
        tfm_warning(char_ic);
      internal[fontmaking] = 0;
      if (job_name == 0)
        open_log_file();
      pack_job_name(1045);
      while (!b_open_out(tfm_file))
        prompt_file_name(1046, 1045);
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
        if (header_byte[k]< 0)
          header_byte[k] = 0;
        tfm_out(header_byte[k]);
      }
      for (k = bc; k <= ec; k++)
      {
        if (!char_exists[k])
          tfm_four(0);
        else
        {
          tfm_out(info(tfm_width[k]));
          tfm_out((info(tfm_height[k])) * 16 + info(tfm_depth[k]));
          tfm_out((info(tfm_ital_corr[k])) * 4 + char_tag[k]);
          tfm_out(char_remainder[k]);
        }
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
      {
        if (skip_table[k] < lig_table_size)
        {
          print_nl(1048);
          print_int(k);
          print(1049);
          cancel_skips(skip_table[k]);
        }
      }
      if (lk_started)
      {
        tfm_out(255);
        tfm_out(bchar);
        tfm_two(0);
      }
      else
      {
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
      }
      for (k = 0; k <= nl - 1; k++)
      {
        tfm_qqqq(lig_kern[k]);
      }
      for (k = 0; k <= nk - 1; k++)
      {
        tfm_four(dimen_out(kern[k]));
      }
      for (k = 0; k <= ne - 1; k++)
      {
        tfm_qqqq(exten[k]);
      }
      for (k = 1; k <= np; k++)
      {
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
      }
      if (tfm_changed > 0)
      {
        if (tfm_changed == 1)
          print_nl(1050);
        else
        {
          print_nl(40);
          print_int(tfm_changed);
          print(1051);
        }
        print(1052);
      }
#ifdef STAT
      if (internal[tracing_stats] > 0)
      {
        { putc (' ', log_file);  putc ('\n', log_file); }
        if (bch_label < lig_table_size)
          decr(nl);
        fprintf(log_file, "%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s\n", "(You used ", (long)nw, "w,", (long)nh, "h,", (long)nd, "d,", (long)ni, "i,", (long)nl, "l,", (long)nk, "k,", (long)ne, "e,", (long)np, "p metric file positions");
        fprintf(log_file, "%s%s%ld%s%ld%s%ld%s\n", "  out of ", "256w,16h,16d,64i,", (long)lig_table_size, "l,", (long)max_kerns, "k,256e,", (long)max_font_dimen, "p)");
      }
#endif /* STAT */
      print_nl(1047);
      print_file_name(0, metric_file_name, 0);
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
      {
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
          {
            if (x > 0)
              x = 16777215L;
            else
              x = -16777215L;
          }
          else
            x = make_scaled(x * 16, internal[design_size]);
          gf_four(x);
          gf_four(char_ptr[k]);
        }
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
      if (gf_ptr > (2147483647L - gf_offset))
      {
        gf_prev_ptr = 0;
        fatal_error("gf length exceeds \"7FFFFFFF");
      }
      if (gf_ptr > 0)
        write_gf(0, gf_ptr - 1);
      print_nl(1064);
      print_file_name(0, output_file_name, 0);
      print(558);
      print_int(total_chars);
      if (total_chars != 1)
        print(1065);
      else
        print(1066);
      print(1067);
      print_int(gf_offset + gf_ptr);
      print(1068);
      b_close(gf_file);
    }
  }
  if (log_opened)
  {
    putc('\n', log_file);
    aclose(log_file);
    selector = selector - 2;
    if (selector == term_only)
    {
      print_nl(1076);
      print_file_name(0, texmflogname, 0);
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
  {
    if ((index > 15))
      end_token_list();
    else
      end_file_reading();
  }
  while (loop_ptr != 0)
    stop_iteration();
  while (open_parens > 0)
  {
    print(1077);
    decr(open_parens);
  }
  while (cond_ptr != 0)
  {
    print_nl("(end occurred when ");
    print_cmd_mod(2, cur_if);
    if (if_line != 0)
    {
      print(1079);
      print_int(if_line);
    }
    print(1080);
    if_line = if_line_field(cond_ptr);
    cur_if = name_type(cond_ptr);
    loop_ptr = cond_ptr;
    cond_ptr = link(cond_ptr);
    free_node(loop_ptr, if_node_size);
  }
  if (history != spotless)
  {
    if (((history == warning_issued) || (interaction < term_and_log)))
    {
      if (selector == term_and_log)
      {
        selector = term_only;
        print_nl("(see the transcript file for additional information)");
        selector = term_and_log;
      }
    }
  }
  if (c == 1)
  {
#ifdef INIMF
    if (iniversion)
    {
      store_base_file();
      goto lab_exit;
    }
#endif /* INIMF */
    print_nl("(dump is performed only by INIMF)");
    goto lab_exit;
  }
lab_exit:;
}
/* 1210 */
void init_prim (void)
{
  primitive("def", macro_def, start_def);
  primitive("vardef", macro_def, var_def);
  primitive("primarydef", macro_def, secondary_primary_macro);
  primitive("secondarydef", macro_def, tertiary_secondary_macro);
  primitive("tertiarydef", macro_def, expression_tertiary_macro);
  primitive("enddef", macro_def, end_def); eqtb[frozen_end_def] = eqtb[cur_sym];
  primitive("for", iteration, expr_base);
  primitive("forsuffixes", iteration, suffix_base);
  primitive("forever", iteration, start_forever);
  primitive("endfor", iteration, end_for); eqtb[frozen_end_for] = eqtb[cur_sym];
  primitive("quote", macro_special, quote);
  primitive("#@@", macro_special, macro_prefix);
  primitive("@@", macro_special, macro_at);
  primitive("@@#", macro_special, macro_suffix);
  primitive("expr", param_type, expr_base);
  primitive("suffix", param_type, suffix_base);
  primitive("text", param_type, text_base);
  primitive("primary", param_type, primary_macro);
  primitive("secondary", param_type, secondary_macro);
  primitive("tertiary", param_type, tertiary_macro);
  primitive("input", input, 0);
  primitive("endinput", input, 1);
  primitive("if", if_test, if_code);
  primitive("fi", fi_or_else, fi_code); eqtb[frozen_fi] = eqtb[cur_sym];
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
  primitive("/", slash, over); eqtb[frozen_slash] = eqtb[cur_sym];
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
  {
    mem[k] = mem[lo_mem_max];
  }
  avail = null;
  mem_end = mem_top;
  hi_mem_min = hi_mem_stat_min;
  var_used = lo_mem_stat_max + 1 - mem_min;
  dyn_used = mem_top + 1 - hi_mem_min;
  int_name[tracing_titles] = 409;
  int_name[tracing_equations] = 410;
  int_name[tracing_capsules] = 411;
  int_name[tracing_choices] = 412;
  int_name[tracing_specs] = 413;
  int_name[tracing_pens] = 414;
  int_name[tracing_commands] = 415;
  int_name[tracing_restores] = 416;
  int_name[tracing_macros] = 417;
  int_name[tracing_edges] = 418;
  int_name[tracing_output] = 419;
  int_name[tracing_stats] = 420;
  int_name[tracing_online] = 421;
  int_name[year] = 422;
  int_name[month] = 423;
  int_name[day] = 424;
  int_name[time] = 425;
  int_name[char_code] = 426;
  int_name[char_ext] = 427;
  int_name[char_wd] = 428;
  int_name[char_ht] = 429;
  int_name[char_dp] = 430;
  int_name[char_ic] = 431;
  int_name[char_dx] = 432;
  int_name[char_dy] = 433;
  int_name[design_size] = 434;
  int_name[hppp] = 435;
  int_name[vppp] = 436;
  int_name[x_offset] = 437;
  int_name[y_offset] = 438;
  int_name[pausing] = 439;
  int_name[showstopping] = 440;
  int_name[fontmaking] = 441;
  int_name[proofing] = 442;
  int_name[smoothing] = 443;
  int_name[autorounding] = 444;
  int_name[granularity] = 445;
  int_name[fillin] = 446;
  int_name[turning_check] = 447;
  int_name[warning_check] = 448;
  int_name[boundary_char] = 449;
  hash_used = frozen_inaccessible;
  st_count = 0;
  text(frozen_bad_vardef) = 449;
  text(frozen_fi) = 450;
  text(frozen_end_group) = 451;
  text(frozen_end_def) = 452;
  text(frozen_end_for) = 453;
  text(frozen_semicolon) = 59;
  text(frozen_colon) = 58;
  text(frozen_slash) = 47;
  text(frozen_left_bracket) = 91;
  text(frozen_right_delimiter) = 41;
  text(frozen_inaccessible) = 454;
  eq_type(frozen_right_delimiter) = right_delimiter;
  attr_loc(end_attr) = hash_end + 1;
  parent(end_attr) = null;
  info(sentinel) = max_halfword;
  ref_count(null_pen) = null;
  link(null_pen) = null;
  info(null_pen + 1) = 1;
  link(null_pen + 1) = null_coords;
  for (k = null_pen + 2; k <= null_pen + 8; k++)
  {
    mem[k] = mem[null_pen + 1];
  }
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
  text(frozen_repeat_loop) = 730;
  name_type(temp_val) = capsule;
  value(inf_val) = fraction_four;
  value(zero_val) = 0;
  info(zero_val) = 0;
  if (iniversion)
    base_ident = 1069;
}

/* 1212 */
#ifdef TEXMF_DEBUG
void debug_help (void)
{
  integer k, l, m, n;

  while (true)
  {
    wake_up_terminal();
    print_nl(1083);
    unpated_terminal();
    read(stdin, m);
    if (m < 0)
      goto lab_exit;
    else if (m == 0)
    {
      goto lab888;
      lab888: m = 0;
    }
    else
    {
      read (stdin, n);
      switch (m)
      {
        case 1:
          print_word(mem[n]);
          break;
        case 2:
          print_int(mem[n].hh.lh);
          break;
        case 3:
          print_int(mem[n].hh.rh);
          break;
        case 4:
          {
            print_int(eqtb[n].lh);
            print_char(':');
            print_int(eqtb[n].rh);
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
          show_token_list(n, null, 100000L, 0);
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
            read(stdin, l);
            print_cmd_mod(n, l);
          }
          break;
        case 14:
          for (k = 0; k <= n; k++)
          {
            print(buffer[k]);
          }
          break;
        case 15:
          panicking = !panicking;
          break;
        default:
          print(63);
          break;
      }
    }
  }
  lab_exit:;
}
#endif /* TEXMF_DEBUG */
/* main */
void main_program (void)
{
  history = fatal_error_stop;
  t_open_out();
  if (ready_already == 314159)
    goto lab_start_of_MF;
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
#endif /* INIMF */
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
    fprintf(stdout, "%s%s%ld\n", "Ouch---my internal constants have been clobbered!", "---case ", (long) bad);
    goto lab_final_end;
  }
  initialize();
#ifdef INIMF
  if (iniversion)
  {
    if (!get_strings_started())
      goto lab_final_end;
    init_tab();
    init_prim();
    init_str_ptr = str_ptr;
    init_pool_ptr = pool_ptr;
    max_str_ptr = str_ptr;
    max_pool_ptr = pool_ptr;
    fix_date_and_time();
  }
#endif /* INIMF */
  ready_already = 314159;
lab_start_of_MF:
  selector = term_only;
  tally = 0;
  term_offset = 0;
  file_offset = 0;
  fputs("This is METAFONT, Version 2.7182818", stdout);
  if (base_ident == 0)
    fprintf(stdout, "%s%s%c\n", " (preloaded base=", dump_name, ')');
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
        goto lab_final_end;
      limit = last;
      first = last + 1;
    }
    scanner_status = normal;
    if ((base_ident == 0) || (buffer[loc] == '&'))
    {
      if (base_ident != 0)
        initialize();
      if (!open_base_file())
        goto lab_final_end;
      if (!load_base_file())
      {
        w_close(base_file);
        goto lab_final_end;
      }
      w_close(base_file);
      while ((loc < limit) && (buffer[loc] == ' '))
        incr(loc);
    }
    buffer[limit] = '%';
    fix_date_and_time();
    ini_trandoms((internal[time] / unity) + internal[day]);
    if (interaction == batch_mode)
      selector = no_print;
    else
      selector = term_only;
    if (loc < limit)
    {
      if (buffer[loc] != '\\')
        start_input();
    }
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
lab_final_end:
  ready_already = 0;
}