#define EXTERN extern
#include "mfd.h"

void 
initialize (void) 
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
  {register integer for_end; i = 0;for_end = 31; if (i <= for_end) do 
    xchr[i] = i;
  while (i++ < for_end);} 
  {register integer for_end; i = 127;for_end = 255; if (i <= for_end) do 
    xchr[i] = i;
  while (i++ < for_end);} 
  {register integer for_end; i = 0;for_end = 255; if (i <= for_end) do 
    xord[chr (i)] = 127;
  while (i++ < for_end);} 
  {register integer for_end; i = 128;for_end = 255; if (i <= for_end) do 
    xord[xchr[i]] = i;
  while (i++ < for_end);} 
  {register integer for_end; i = 0;for_end = 126; if (i <= for_end) do 
    xord[xchr[i]] = i;
  while (i++ < for_end);} 
  {register integer for_end; i = 0;for_end = 255; if (i <= for_end) do 
    xprn[i] = (eightbitp || ((i >= 32) && (i <= 126)));
  while (i++ < for_end);} 
  if (translatefilename) 
  readtcxfile ();
  if (interactionoption == 4) 
  interaction = 3;
  else interaction = interactionoption;
  deletions_allowed = true;
  error_count = 0;
  help_ptr = 0;
  use_err_help = false;
  err_help = 0;
  interrupt = 0;
  OK_to_interrupt = true;
  arith_error = false;
  two_to_the[0] = 1;
  {register integer for_end; k = 1;for_end = 30; if (k <= for_end) do 
    two_to_the[k] = 2 * two_to_the[k - 1];
  while (k++ < for_end);} 
  spec_log[1] = 93032640L;
  spec_log[2] = 38612034L;
  spec_log[3] = 17922280L;
  spec_log[4] = 8662214L;
  spec_log[5] = 4261238L;
  spec_log[6] = 2113709L;
  spec_log[7] = 1052693L;
  spec_log[8] = 525315L;
  spec_log[9] = 262400L;
  spec_log[10] = 131136L;
  spec_log[11] = 65552L;
  spec_log[12] = 32772L;
  spec_log[13] = 16385;
  {register integer for_end; k = 14;for_end = 27; if (k <= for_end) do 
    spec_log[k] = two_to_the[27 - k];
  while (k++ < for_end);} 
  spec_log[28] = 1;
  spec_atan[1] = 27855475L;
  spec_atan[2] = 14718068L;
  spec_atan[3] = 7471121L;
  spec_atan[4] = 3750058L;
  spec_atan[5] = 1876857L;
  spec_atan[6] = 938658L;
  spec_atan[7] = 469357L;
  spec_atan[8] = 234682L;
  spec_atan[9] = 117342L;
  spec_atan[10] = 58671L;
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
	;
#ifdef TEXMF_DEBUG
  was_mem_end = 0;
  was_lo_max = 0;
  was_hi_min = memmax;
  panicking = false;
#endif /* TEXMF_DEBUG */
  {register integer for_end; k = 1;for_end = 41; if (k <= for_end) do 
    internal[k] = 0;
  while (k++ < for_end);} 
  int_ptr = 41;
  {register integer for_end; k = 48;for_end = 57; if (k <= for_end) do 
    char_class[k] = 0;
  while (k++ < for_end);} 
  char_class[46] = 1;
  char_class[32] = 2;
  char_class[37] = 3;
  char_class[34] = 4;
  char_class[44] = 5;
  char_class[59] = 6;
  char_class[40] = 7;
  char_class[41] = 8;
  {register integer for_end; k = 65;for_end = 90; if (k <= for_end) do 
    char_class[k] = 9;
  while (k++ < for_end);} 
  {register integer for_end; k = 97;for_end = 122; if (k <= for_end) do 
    char_class[k] = 9;
  while (k++ < for_end);} 
  char_class[95] = 9;
  char_class[60] = 10;
  char_class[61] = 10;
  char_class[62] = 10;
  char_class[58] = 10;
  char_class[124] = 10;
  char_class[96] = 11;
  char_class[39] = 11;
  char_class[43] = 12;
  char_class[45] = 12;
  char_class[47] = 13;
  char_class[42] = 13;
  char_class[92] = 13;
  char_class[33] = 14;
  char_class[63] = 14;
  char_class[35] = 15;
  char_class[38] = 15;
  char_class[64] = 15;
  char_class[36] = 15;
  char_class[94] = 16;
  char_class[126] = 16;
  char_class[91] = 17;
  char_class[93] = 18;
  char_class[123] = 19;
  char_class[125] = 19;
  {register integer for_end; k = 0;for_end = 31; if (k <= for_end) do 
    char_class[k] = 20;
  while (k++ < for_end);} 
  {register integer for_end; k = 127;for_end = 255; if (k <= for_end) do 
    char_class[k] = 20;
  while (k++ < for_end);} 
  char_class[9] = 2;
  char_class[12] = 2;
  hash[1].lhfield = 0;
  hash[1].v.RH = 0;
  eqtb[1].lhfield = 41;
  eqtb[1].v.RH = 0;
  {register integer for_end; k = 2;for_end = 9769; if (k <= for_end) do 
    {
      hash[k] = hash[1];
      eqtb[k] = eqtb[1];
    } 
  while (k++ < for_end);} 
  big_node_size[13] = 12;
  big_node_size[14] = 4;
  save_ptr = 0;
  octant_dir[1] = 548;
  octant_dir[5] = 549;
  octant_dir[6] = 550;
  octant_dir[2] = 551;
  octant_dir[4] = 552;
  octant_dir[8] = 553;
  octant_dir[7] = 554;
  octant_dir[3] = 555;
  max_rounding_ptr = 0;
  octant_code[1] = 1;
  octant_code[2] = 5;
  octant_code[3] = 6;
  octant_code[4] = 2;
  octant_code[5] = 4;
  octant_code[6] = 8;
  octant_code[7] = 7;
  octant_code[8] = 3;
  {register integer for_end; k = 1;for_end = 8; if (k <= for_end) do 
    octant_number[octant_code[k]] = k;
  while (k++ < for_end);} 
  rev_turns = false;
  x_corr[1] = 0;
  y_corr[1] = 0;
  xy_corr[1] = 0;
  x_corr[5] = 0;
  y_corr[5] = 0;
  xy_corr[5] = 1;
  x_corr[6] = -1;
  y_corr[6] = 1;
  xy_corr[6] = 0;
  x_corr[2] = 1;
  y_corr[2] = 0;
  xy_corr[2] = 1;
  x_corr[4] = 0;
  y_corr[4] = 1;
  xy_corr[4] = 1;
  x_corr[8] = 0;
  y_corr[8] = 1;
  xy_corr[8] = 0;
  x_corr[7] = 1;
  y_corr[7] = 0;
  xy_corr[7] = 1;
  x_corr[3] = -1;
  y_corr[3] = 1;
  xy_corr[3] = 0;
  {register integer for_end; k = 1;for_end = 8; if (k <= for_end) do 
    z_corr[k] = xy_corr[k] - x_corr[k];
  while (k++ < for_end);} 
  screen_started = false;
  screen_OK = false;
  {register integer for_end; k = 0;for_end = 15; if (k <= for_end) do 
    {
      window_open[k] = false;
      window_time[k] = 0;
    } 
  while (k++ < for_end);} 
  fix_needed = false;
  watch_coefs = true;
  cond_ptr = 0;
  if_limit = 0;
  cur_if = 0;
  if_line = 0;
  loop_ptr = 0;
  cur_exp = 0;
  var_flag = 0;
  start_sym = 0;
  long_help_seen = false;
  {register integer for_end; k = 0;for_end = 255; if (k <= for_end) do 
    {
      tfm_width[k] = 0;
      tfm_height[k] = 0;
      tfm_depth[k] = 0;
      tfm_ital_corr[k] = 0;
      char_exists[k] = false;
      char_tag[k] = 0;
      char_remainder[k] = 0;
      skip_table[k] = lig_table_size;
    } 
  while (k++ < for_end);} 
  {register integer for_end; k = 1;for_end = header_size; if (k <= 
  for_end) do 
    header_byte[k] = -1;
  while (k++ < for_end);} 
  bc = 255;
  ec = 0;
  nl = 0;
  nk = 0;
  ne = 0;
  np = 0;
  internal[41] = -65536L;
  bch_label = lig_table_size;
  label_loc[0] = -1;
  label_ptr = 0;
  gf_prev_ptr = 0;
  total_chars = 0;
  half_buf = gf_buf_size / 2;
  gf_limit = gf_buf_size;
  gf_ptr = 0;
  gf_offset = 0;
  base_ident = 0;
  editnamestart = 0;
  stopatspace = true;
} 
void 
print_ln (void) 
{
  switch (selector) 
  {case 3 : 
    {
      putc ('\n',  stdout);
      putc ('\n',  log_file);
      term_offset = 0;
      file_offset = 0;
    } 
    break;
  case 2 : 
    {
      putc ('\n',  log_file);
      file_offset = 0;
    } 
    break;
  case 1 : 
    {
      putc ('\n',  stdout);
      term_offset = 0;
    } 
    break;
  case 0 : 
  case 4 : 
  case 5 : 
;
    break;
  } 
} 
void 
print_char (ASCII_code s) 
{
  switch (selector) 
  {case 3 : 
    {
      putc (xchr[s],  stdout);
      putc (xchr[s],  log_file);
      incr (term_offset);
      incr (file_offset);
      if (term_offset == maxprintline) 
      {
	putc ('\n',  stdout);
	term_offset = 0;
      } 
      if (file_offset == maxprintline) 
      {
	putc ('\n',  log_file);
	file_offset = 0;
      } 
    } 
    break;
  case 2 : 
    {
      putc (xchr[s],  log_file);
      incr (file_offset);
      if (file_offset == maxprintline) 
      print_ln ();
    } 
    break;
  case 1 : 
    {
      putc (xchr[s],  stdout);
      incr (term_offset);
      if (term_offset == maxprintline) 
      print_ln ();
    } 
    break;
  case 0 : 
;
    break;
  case 4 : 
    if (tally < trick_count) 
    trick_buf[tally % errorline] = s;
    break;
  case 5 : 
    {
      if (pool_ptr < pool_size) 
      {
	str_pool[pool_ptr] = s;
	incr (pool_ptr);
      } 
    } 
    break;
  } 
  incr (tally);
} 
void 
print (integer s) 
{
  pool_pointer j;
  if ((s < 0) || (s >= str_ptr)) 
  s = 259;
  if ((s < 256) && ((selector > 4) || xprn[s])) 
  print_char (s);
  else {
      
    j = str_start[s];
    while (j < str_start[s + 1]) {
	
      print_char (str_pool[j]);
      incr (j);
    } 
  } 
} 
void 
slow_print (integer s) 
{
  pool_pointer j;
  if ((s < 0) || (s >= str_ptr)) 
  s = 259;
  if ((s < 256) && ((selector > 4) || xprn[s])) 
  print_char (s);
  else {
      
    j = str_start[s];
    while (j < str_start[s + 1]) {
	
      print (str_pool[j]);
      incr (j);
    } 
  } 
} 
void 
print_nl (str_number s) 
{
  if (((term_offset > 0) && (odd (selector))) || ((file_offset > 0 
) && (selector >= 2))) 
  print_ln ();
  print (s);
} 
void 
print_the_digs (eight_bits k) 
{
  while (k > 0) {
      
    decr (k);
    print_char (48 + dig[k]);
  } 
} 
void 
print_int (integer n) 
{
  unsigned char k;
  integer m;
  k = 0;
  if (n < 0) 
  {
    print_char (45);
    if (n > -100000000L) 
    n = - (integer) n;
    else {
	
      m = -1 - n;
      n = m / 10;
      m = (m % 10) + 1;
      k = 1;
      if (m < 10) 
      dig[0] = m;
      else {
	  
	dig[0] = 0;
	incr (n);
      } 
    } 
  } 
  do {
      dig[k] = n % 10;
    n = n / 10;
    incr (k);
  } while (!(n == 0));
  print_the_digs (k);
} 
void 
print_scaled (scaled s) 
{
  scaled delta;
  if (s < 0) 
  {
    print_char (45);
    s = - (integer) s;
  } 
  print_int (s / 65536L);
  s = 10 * (s % 65536L) + 5;
  if (s != 5) 
  {
    delta = 10;
    print_char (46);
    do {
	if (delta > 65536L) 
      s = s + 32768L - (delta / 2);
      print_char (48 + (s / 65536L));
      s = 10 * (s % 65536L);
      delta = delta * 10;
    } while (!(s <= delta));
  } 
} 
void 
print_two (scaled x , scaled y) 
{
  print_char (40);
  print_scaled (x);
  print_char (44);
  print_scaled (y);
  print_char (41);
} 
void 
print_type (small_number t) 
{
  switch (t) 
  {case 1 : 
    print (323);
    break;
  case 2 : 
    print (324);
    break;
  case 3 : 
    print (325);
    break;
  case 4 : 
    print (326);
    break;
  case 5 : 
    print (327);
    break;
  case 6 : 
    print (328);
    break;
  case 7 : 
    print (329);
    break;
  case 8 : 
    print (330);
    break;
  case 9 : 
    print (331);
    break;
  case 10 : 
    print (332);
    break;
  case 11 : 
    print (333);
    break;
  case 12 : 
    print (334);
    break;
  case 13 : 
    print (335);
    break;
  case 14 : 
    print (336);
    break;
  case 16 : 
    print (337);
    break;
  case 17 : 
    print (338);
    break;
  case 18 : 
    print (339);
    break;
  case 15 : 
    print (340);
    break;
  case 19 : 
    print (341);
    break;
  case 20 : 
    print (342);
    break;
  case 21 : 
    print (343);
    break;
  case 22 : 
    print (344);
    break;
  case 23 : 
    print (345);
    break;
    default: 
    print (346);
    break;
  } 
} 
void 
begin_diagnostic (void) 
{
  old_setting = selector;
  if ((internal[13]<= 0) && (selector == 3)) 
  {
    decr (selector);
    if (history == 0) 
    history = 1;
  } 
} 
void 
end_diagnostic (boolean blankline) 
{
  print_nl (261);
  if (blankline) 
  print_ln ();
  selector = old_setting;
} 
void 
print_diagnostic (str_number s , str_number t , boolean nuline) 
{
  begin_diagnostic ();
  if (nuline) 
  print_nl (s);
  else print (s);
  print (450);
  print_int (line);
  print (t);
  print_char (58);
} 
void 
print_file_name (integer n , integer a , integer e) 
{
  boolean mustquote;
  pool_pointer j;
  mustquote = false;
  if (a != 0) 
  {
    j = str_start[a];
    while ((!mustquote) && (j < str_start[a + 1])) {
	
      mustquote = str_pool[j] == 32;
      incr (j);
    } 
  } 
  if (n != 0) 
  {
    j = str_start[n];
    while ((!mustquote) && (j < str_start[n + 1])) {
	
      mustquote = str_pool[j] == 32;
      incr (j);
    } 
  } 
  if (e != 0) 
  {
    j = str_start[e];
    while ((!mustquote) && (j < str_start[e + 1])) {
	
      mustquote = str_pool[j] == 32;
      incr (j);
    } 
  } 
  if (mustquote) 
  slow_print (34);
  if (a != 0) 
  {register integer for_end; j = str_start[a];for_end = str_start[a + 1 
] - 1; if (j <= for_end) do 
    if (str_pool[j]!= 34) 
    print (str_pool[j]);
  while (j++ < for_end);} 
  if (n != 0) 
  {register integer for_end; j = str_start[n];for_end = str_start[n + 1 
] - 1; if (j <= for_end) do 
    if (str_pool[j]!= 34) 
    print (str_pool[j]);
  while (j++ < for_end);} 
  if (e != 0) 
  {register integer for_end; j = str_start[e];for_end = str_start[e + 1 
] - 1; if (j <= for_end) do 
    if (str_pool[j]!= 34) 
    print (str_pool[j]);
  while (j++ < for_end);} 
  if (mustquote) 
  slow_print (34);
} 
#ifdef TEXMF_DEBUG
#endif /* TEXMF_DEBUG */
void 
flush_string (str_number s) 
{
  if (s < str_ptr - 1) 
  str_ref[s] = 0;
  else do {
      decr (str_ptr);
  } while (!(str_ref[str_ptr - 1]!= 0));
  pool_ptr = str_start[str_ptr];
} 
void 
jump_out (void) 
{
  close_files_and_terminate ();
  {
    fflush (stdout);
    ready_already = 0;
    if ((history != 0) && (history != 1)) 
    uexit (1);
    else uexit (0);
  } 
} 
void 
error (void) 
{
  /* 22 10 */ ASCII_code c;
  integer s1, s2, s3;
  pool_pointer j;
  if (history < 2) 
  history = 2;
  print_char (46);
  showcontext ();
  if ((haltonerrorp)) 
  {
    history = 3;
    jump_out ();
  } 
  if (interaction == 3) 
  while (true) {
      
    lab22: clearforerrorprompt ();
    {
;
      print (265);
      term_input ();
    } 
    if (last == first) 
    goto lab10;
    c = buffer[first];
    if (c >= 97) 
    c = c - 32;
    switch (c) 
    {case 48 : 
    case 49 : 
    case 50 : 
    case 51 : 
    case 52 : 
    case 53 : 
    case 54 : 
    case 55 : 
    case 56 : 
    case 57 : 
      if (deletions_allowed) 
      {
	s1 = cur_cmd;
	s2 = cur_mod;
	s3 = cur_sym;
	OK_to_interrupt = false;
	if ((last > first + 1) && (buffer[first + 1] >= 48) && (
	buffer[first + 1]<= 57)) 
	c = c * 10 + buffer[first + 1] - 48 * 11;
	else c = c - 48;
	while (c > 0) {
	    
	  getnext ();
	  if (cur_cmd == 39) 
	  {
	    if (str_ref[cur_mod]< 127) {
		
	      if (str_ref[cur_mod] > 1) 
	      decr (str_ref[cur_mod]);
	      else flush_string (cur_mod);
	    } 
	  } 
	  decr (c);
	} 
	cur_cmd = s1;
	cur_mod = s2;
	cur_sym = s3;
	OK_to_interrupt = true;
	{
	  help_ptr = 2;
	  help_line[1] = 278;
	  help_line[0] = 279;
	} 
	showcontext ();
	goto lab22;
      } 
      break;
	;
#ifdef TEXMF_DEBUG
    case 68 : 
      {
	debughelp ();
	goto lab22;
      } 
      break;
#endif /* TEXMF_DEBUG */
    case 69 : 
      if (file_ptr > 0) 
      {
	editnamestart = str_start[input_stack[file_ptr].name_field];
	editname_length = str_start[input_stack[file_ptr].name_field + 1] - 
	str_start[input_stack[file_ptr].name_field];
	editline = line;
	jump_out ();
      } 
      break;
    case 72 : 
      {
	if (use_err_help) 
	{
	  j = str_start[err_help];
	  while (j < str_start[err_help + 1]) {
	      
	    if (str_pool[j]!= 37) 
	    print (str_pool[j]);
	    else if (j + 1 == str_start[err_help + 1]) 
	    print_ln ();
	    else if (str_pool[j + 1]!= 37) 
	    print_ln ();
	    else {
		
	      incr (j);
	      print_char (37);
	    } 
	    incr (j);
	  } 
	  use_err_help = false;
	} 
	else {
	    
	  if (help_ptr == 0) 
	  {
	    help_ptr = 2;
	    help_line[1] = 280;
	    help_line[0] = 281;
	  } 
	  do {
	      decr (help_ptr);
	    print (help_line[help_ptr]);
	    print_ln ();
	  } while (!(help_ptr == 0));
	} 
	{
	  help_ptr = 4;
	  help_line[3] = 282;
	  help_line[2] = 281;
	  help_line[1] = 283;
	  help_line[0] = 284;
	} 
	goto lab22;
      } 
      break;
    case 73 : 
      {
	beginfilereading ();
	if (last > first + 1) 
	{
	  cur_input.loc_field = first + 1;
	  buffer[first] = 32;
	} 
	else {
	    
	  {
	;
	    print (277);
	    term_input ();
	  } 
	  cur_input.loc_field = first;
	} 
	first = last + 1;
	cur_input .limit_field = last;
	goto lab10;
      } 
      break;
    case 81 : 
    case 82 : 
    case 83 : 
      {
	error_count = 0;
	interaction = 0 + c - 81;
	print (272);
	switch (c) 
	{case 81 : 
	  {
	    print (273);
	    decr (selector);
	  } 
	  break;
	case 82 : 
	  print (274);
	  break;
	case 83 : 
	  print (275);
	  break;
	} 
	print (276);
	print_ln ();
	fflush (stdout);
	goto lab10;
      } 
      break;
    case 88 : 
      {
	interaction = 2;
	jump_out ();
      } 
      break;
      default: 
;
      break;
    } 
    {
      print (266);
      print_nl (267);
      print_nl (268);
      if (file_ptr > 0) 
      print (269);
      if (deletions_allowed) 
      print_nl (270);
      print_nl (271);
    } 
  } 
  incr (error_count);
  if (error_count == 100) 
  {
    print_nl (264);
    history = 3;
    jump_out ();
  } 
  if (interaction > 0) 
  decr (selector);
  if (use_err_help) 
  {
    print_nl (261);
    j = str_start[err_help];
    while (j < str_start[err_help + 1]) {
	
      if (str_pool[j]!= 37) 
      print (str_pool[j]);
      else if (j + 1 == str_start[err_help + 1]) 
      print_ln ();
      else if (str_pool[j + 1]!= 37) 
      print_ln ();
      else {
	  
	incr (j);
	print_char (37);
      } 
      incr (j);
    } 
  } 
  else while (help_ptr > 0) {
      
    decr (help_ptr);
    print_nl (help_line[help_ptr]);
  } 
  print_ln ();
  if (interaction > 0) 
  incr (selector);
  print_ln ();
  lab10:;
} 
void 
fatal_error (str_number s) 
{
  normalize_selector ();
  {
    if (interaction == 3) 
;
    if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
    {
      print_nl (261);
      print (fullsourcefilenamestack[in_open]);
      print (58);
      print_int (line);
      print (262);
      print (285);
    } 
    else {
	
      print_nl (263);
      print (285);
    } 
  } 
  {
    help_ptr = 1;
    help_line[0] = s;
  } 
  {
    if (interaction == 3) 
    interaction = 2;
    if (log_opened) 
    error ();
	;
#ifdef TEXMF_DEBUG
    if (interaction > 0) 
    debughelp ();
#endif /* TEXMF_DEBUG */
    history = 3;
    jump_out ();
  } 
} 
void 
overflow (str_number s , integer n) 
{
  normalize_selector ();
  {
    if (interaction == 3) 
;
    if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
    {
      print_nl (261);
      print (fullsourcefilenamestack[in_open]);
      print (58);
      print_int (line);
      print (262);
      print (286);
    } 
    else {
	
      print_nl (263);
      print (286);
    } 
  } 
  print (s);
  print_char (61);
  print_int (n);
  print_char (93);
  {
    help_ptr = 2;
    help_line[1] = 287;
    help_line[0] = 288;
  } 
  {
    if (interaction == 3) 
    interaction = 2;
    if (log_opened) 
    error ();
	;
#ifdef TEXMF_DEBUG
    if (interaction > 0) 
    debughelp ();
#endif /* TEXMF_DEBUG */
    history = 3;
    jump_out ();
  } 
} 
void 
confusion (str_number s) 
{
  normalize_selector ();
  if (history < 2) 
  {
    {
      if (interaction == 3) 
;
      if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[in_open]);
	print (58);
	print_int (line);
	print (262);
	print (289);
      } 
      else {
	  
	print_nl (263);
	print (289);
      } 
    } 
    print (s);
    print_char (41);
    {
      help_ptr = 1;
      help_line[0] = 290;
    } 
  } 
  else {
      
    {
      if (interaction == 3) 
;
      if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[in_open]);
	print (58);
	print_int (line);
	print (262);
	print (291);
      } 
      else {
	  
	print_nl (263);
	print (291);
      } 
    } 
    {
      help_ptr = 2;
      help_line[1] = 292;
      help_line[0] = 293;
    } 
  } 
  {
    if (interaction == 3) 
    interaction = 2;
    if (log_opened) 
    error ();
	;
#ifdef TEXMF_DEBUG
    if (interaction > 0) 
    debughelp ();
#endif /* TEXMF_DEBUG */
    history = 3;
    jump_out ();
  } 
} 
boolean 
init_terminal (void) 
{
  /* 10 */ register boolean Result; topenin ();
  if (last > first) 
  {
    cur_input.loc_field = first;
    while ((cur_input.loc_field < last) && (buffer[cur_input.loc_field]
    == ' ')) incr (cur_input.loc_field);
    if (cur_input.loc_field < last) 
    {
      Result = true;
      goto lab10;
    } 
  } 
  while (true) {
      
;
    Fputs (stdout ,  "**");
    fflush (stdout);
    if (!inputln (stdin , true)) 
    {
      putc ('\n',  stdout);
      fprintf (stdout , "%s\n",  "!End of file on the terminal... why?");
      Result = false;
      goto lab10;
    } 
    cur_input.loc_field = first;
    while ((cur_input.loc_field < last) && (buffer[cur_input.loc_field]
    == 32)) incr (cur_input.loc_field);
    if (cur_input.loc_field < last) 
    {
      Result = true;
      goto lab10;
    } 
    fprintf (stdout , "%s\n",  "Please type the name of your input file.");
  } 
  lab10:;
  return Result;
} 
str_number 
make_string (void) 
{
  register str_number Result; if (str_ptr == max_str_ptr) 
  {
    if (str_ptr == max_strings) 
    overflow (258 , max_strings - init_str_ptr);
    incr (max_str_ptr);
  } 
  str_ref[str_ptr] = 1;
  incr (str_ptr);
  str_start[str_ptr] = pool_ptr;
  Result = str_ptr - 1;
  return Result;
} 
boolean 
str_eq_buf (str_number s , integer k) 
{
  /* 45 */ register boolean Result; pool_pointer j;
  boolean result;
  j = str_start[s];
  while (j < str_start[s + 1]) {
      
    if (str_pool[j]!= buffer[k]) 
    {
      result = false;
      goto not_found;
    } 
    incr (j);
    incr (k);
  } 
  result = true;
  not_found: Result = result;
  return Result;
} 
integer 
str_vs_str (str_number s , str_number t) 
{
  /* 10 */ register integer Result; pool_pointer j, k;
  integer ls, lt;
  integer l;
  ls = (str_start[s + 1] - str_start[s]);
  lt = (str_start[t + 1] - str_start[t]);
  if (ls <= lt) 
  l = ls;
  else l = lt;
  j = str_start[s];
  k = str_start[t];
  while (l > 0) {
      
    if (str_pool[j]!= str_pool[k]) 
    {
      Result = str_pool[j] - str_pool[k];
      goto lab10;
    } 
    incr (j);
    incr (k);
    decr (l);
  } 
  Result = ls - lt;
  lab10:;
  return Result;
} 
void 
print_dd (integer n) 
{
  n = abs (n) % 100;
  print_char (48 + (n / 10));
  print_char (48 + (n % 10));
} 
void 
term_input (void) 
{
  integer k;
  fflush (stdout);
  if (!inputln (stdin , true)) 
  fatal_error (260);
  term_offset = 0;
  decr (selector);
  if (last != first) 
  {register integer for_end; k = first;for_end = last - 1; if (k <= 
  for_end) do 
    print (buffer[k]);
  while (k++ < for_end);} 
  print_ln ();
  buffer[last] = 37;
  incr (selector);
} 
void 
normalize_selector (void) 
{
  if (log_opened) 
  selector = 3;
  else selector = 1;
  if (job_name == 0) 
  open_log_file ();
  if (interaction == 0) 
  decr (selector);
} 
void 
pause_for_instructions (void) 
{
  if (OK_to_interrupt) 
  {
    interaction = 3;
    if ((selector == 2) || (selector == 0)) 
    incr (selector);
    {
      if (interaction == 3) 
;
      if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[in_open]);
	print (58);
	print_int (line);
	print (262);
	print (294);
      } 
      else {
	  
	print_nl (263);
	print (294);
      } 
    } 
    {
      help_ptr = 3;
      help_line[2] = 295;
      help_line[1] = 296;
      help_line[0] = 297;
    } 
    deletions_allowed = false;
    error ();
    deletions_allowed = true;
    interrupt = 0;
  } 
} 
void 
missing_err (str_number s) 
{
  {
    if (interaction == 3) 
;
    if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
    {
      print_nl (261);
      print (fullsourcefilenamestack[in_open]);
      print (58);
      print_int (line);
      print (262);
      print (298);
    } 
    else {
	
      print_nl (263);
      print (298);
    } 
  } 
  print (s);
  print (299);
} 
void 
clear_arith (void) 
{
  {
    if (interaction == 3) 
;
    if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
    {
      print_nl (261);
      print (fullsourcefilenamestack[in_open]);
      print (58);
      print_int (line);
      print (262);
      print (300);
    } 
    else {
	
      print_nl (263);
      print (300);
    } 
  } 
  {
    help_ptr = 4;
    help_line[3] = 301;
    help_line[2] = 302;
    help_line[1] = 303;
    help_line[0] = 304;
  } 
  error ();
  arith_error = false;
} 
integer 
slow_add (integer x , integer y) 
{
  register integer Result; if (x >= 0) {
      
    if (y <= 2147483647L - x) 
    Result = x + y;
    else {
	
      arith_error = true;
      Result = 2147483647L;
    } 
  } 
  else if (- (integer) y <= 2147483647L + x) 
  Result = x + y;
  else {
      
    arith_error = true;
    Result = -2147483647L;
  } 
  return Result;
} 
scaled 
round_decimals (small_number k) 
{
  register scaled Result; integer a;
  a = 0;
  while (k > 0) {
      
    decr (k);
    a = (a + dig[k]* 131072L) / 10;
  } 
  Result = halfp (a + 1);
  return Result;
} 
#ifdef FIXPT
fraction 
zmakefraction (integer p , integer q) 
{
  register fraction Result; integer f;
  integer n;
  boolean negative;
  integer becareful;
  if (p >= 0) 
  negative = false;
  else {
      
    p = - (integer) p;
    negative = true;
  } 
  if (q <= 0) 
  {
	;
#ifdef TEXMF_DEBUG
    if (q == 0) 
    confusion (47);
#endif /* TEXMF_DEBUG */
    q = - (integer) q;
    negative = !negative;
  } 
  n = p / q;
  p = p % q;
  if (n >= 8) 
  {
    arith_error = true;
    if (negative) 
    Result = -2147483647L;
    else Result = 2147483647L;
  } 
  else {
      
    n = (n - 1) * 268435456L;
    f = 1;
    do {
	becareful = p - q;
      p = becareful + p;
      if (p >= 0) 
      f = f + f + 1;
      else {
	  
	f = f + f;
	p = p + q;
      } 
    } while (!(f >= 268435456L));
    becareful = p - q;
    if (becareful + p >= 0) 
    incr (f);
    if (negative) 
    Result = - (integer) (f + n);
    else Result = f + n;
  } 
  return Result;
} 
#endif /* FIXPT */
#ifdef FIXPT
integer 
ztakefraction (integer q , fraction f) 
{
  register integer Result; integer p;
  boolean negative;
  integer n;
  integer becareful;
  if (f >= 0) 
  negative = false;
  else {
      
    f = - (integer) f;
    negative = true;
  } 
  if (q < 0) 
  {
    q = - (integer) q;
    negative = !negative;
  } 
  if (f < 268435456L) 
  n = 0;
  else {
      
    n = f / 268435456L;
    f = f % 268435456L;
    if (q <= 2147483647L / n) 
    n = n * q;
    else {
	
      arith_error = true;
      n = 2147483647L;
    } 
  } 
  f = f + 268435456L;
  p = 134217728L;
  if (q < 1073741824L) 
  do {
      if (odd (f)) 
    p = halfp (p + q);
    else p = halfp (p);
    f = halfp (f);
  } while (!(f == 1));
  else do {
      if (odd (f)) 
    p = p + halfp (q - p);
    else p = halfp (p);
    f = halfp (f);
  } while (!(f == 1));
  becareful = n - 2147483647L;
  if (becareful + p > 0) 
  {
    arith_error = true;
    n = 2147483647L - p;
  } 
  if (negative) 
  Result = - (integer) (n + p);
  else Result = n + p;
  return Result;
} 
#endif /* FIXPT */
#ifdef FIXPT
integer 
ztakescaled (integer q , scaled f) 
{
  register integer Result; integer p;
  boolean negative;
  integer n;
  integer becareful;
  if (f >= 0) 
  negative = false;
  else {
      
    f = - (integer) f;
    negative = true;
  } 
  if (q < 0) 
  {
    q = - (integer) q;
    negative = !negative;
  } 
  if (f < 65536L) 
  n = 0;
  else {
      
    n = f / 65536L;
    f = f % 65536L;
    if (q <= 2147483647L / n) 
    n = n * q;
    else {
	
      arith_error = true;
      n = 2147483647L;
    } 
  } 
  f = f + 65536L;
  p = 32768L;
  if (q < 1073741824L) 
  do {
      if (odd (f)) 
    p = halfp (p + q);
    else p = halfp (p);
    f = halfp (f);
  } while (!(f == 1));
  else do {
      if (odd (f)) 
    p = p + halfp (q - p);
    else p = halfp (p);
    f = halfp (f);
  } while (!(f == 1));
  becareful = n - 2147483647L;
  if (becareful + p > 0) 
  {
    arith_error = true;
    n = 2147483647L - p;
  } 
  if (negative) 
  Result = - (integer) (n + p);
  else Result = n + p;
  return Result;
} 
#endif /* FIXPT */
#ifdef FIXPT
scaled 
zmakescaled (integer p , integer q) 
{
  register scaled Result; integer f;
  integer n;
  boolean negative;
  integer becareful;
  if (p >= 0) 
  negative = false;
  else {
      
    p = - (integer) p;
    negative = true;
  } 
  if (q <= 0) 
  {
	;
#ifdef TEXMF_DEBUG
    if (q == 0) 
    confusion (47);
#endif /* TEXMF_DEBUG */
    q = - (integer) q;
    negative = !negative;
  } 
  n = p / q;
  p = p % q;
  if (n >= 32768L) 
  {
    arith_error = true;
    if (negative) 
    Result = -2147483647L;
    else Result = 2147483647L;
  } 
  else {
      
    n = (n - 1) * 65536L;
    f = 1;
    do {
	becareful = p - q;
      p = becareful + p;
      if (p >= 0) 
      f = f + f + 1;
      else {
	  
	f = f + f;
	p = p + q;
      } 
    } while (!(f >= 65536L));
    becareful = p - q;
    if (becareful + p >= 0) 
    incr (f);
    if (negative) 
    Result = - (integer) (f + n);
    else Result = f + n;
  } 
  return Result;
} 
#endif /* FIXPT */
fraction 
velocity (fraction st , fraction ct , fraction sf , fraction cf , scaled t) 
{
  register fraction Result; integer acc, num, denom;
  acc = takefraction (st - (sf / 16) , sf - (st / 16));
  acc = takefraction (acc , ct - cf);
  num = 536870912L + takefraction (acc , 379625062L);
  denom = 805306368L + takefraction (ct , 497706707L) + takefraction (cf , 
  307599661L);
  if (t != 65536L) 
  num = makescaled (num , t);
  if (num / 4 >= denom) 
  Result = 1073741824L;
  else Result = makefraction (num , denom);
  return Result;
} 
integer 
ab_vs_cd (integer a , integer b , integer c , integer d) 
{
  /* 10 */ register integer Result; integer q, r;
  if (a < 0) 
  {
    a = - (integer) a;
    b = - (integer) b;
  } 
  if (c < 0) 
  {
    c = - (integer) c;
    d = - (integer) d;
  } 
  if (d <= 0) 
  {
    if (b >= 0) {
	
      if (((a == 0) || (b == 0)) && ((c == 0) || (d == 0))) 
      {
	Result = 0;
	goto lab10;
      } 
      else {
	  
	Result = 1;
	goto lab10;
      } 
    } 
    if (d == 0) {
	
      if (a == 0) 
      {
	Result = 0;
	goto lab10;
      } 
      else {
	  
	Result = -1;
	goto lab10;
      } 
    } 
    q = a;
    a = c;
    c = q;
    q = - (integer) b;
    b = - (integer) d;
    d = q;
  } 
  else if (b <= 0) 
  {
    if (b < 0) {
	
      if (a > 0) 
      {
	Result = -1;
	goto lab10;
      } 
    } 
    if (c == 0) 
    {
      Result = 0;
      goto lab10;
    } 
    else {
	
      Result = -1;
      goto lab10;
    } 
  } 
  while (true) {
      
    q = a / d;
    r = c / b;
    if (q != r) {
	
      if (q > r) 
      {
	Result = 1;
	goto lab10;
      } 
      else {
	  
	Result = -1;
	goto lab10;
      } 
    } 
    q = a % d;
    r = c % b;
    if (r == 0) {
	
      if (q == 0) 
      {
	Result = 0;
	goto lab10;
      } 
      else {
	  
	Result = 1;
	goto lab10;
      } 
    } 
    if (q == 0) 
    {
      Result = -1;
      goto lab10;
    } 
    a = b;
    b = q;
    c = d;
    d = r;
  } 
  lab10:;
  return Result;
} 
scaled 
zsquarert (scaled x) 
{
  register scaled Result; small_number k;
  integer y, q;
  if (x <= 0) 
  {
    if (x < 0) 
    {
      {
	if (interaction == 3) 
	;
	if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
	{
	  print_nl (261);
	  print (fullsourcefilenamestack[in_open]);
	  print (58);
	  print_int (line);
	  print (262);
	  print (305);
	} 
	else {
	    
	  print_nl (263);
	  print (305);
	} 
      } 
      print_scaled (x);
      print (306);
      {
	help_ptr = 2;
	help_line[1] = 307;
	help_line[0] = 308;
      } 
      error ();
    } 
    Result = 0;
  } 
  else {
      
    k = 23;
    q = 2;
    while (x < 536870912L) {
	
      decr (k);
      x = x + x + x + x;
    } 
    if (x < 1073741824L) 
    y = 0;
    else {
	
      x = x - 1073741824L;
      y = 1;
    } 
    do {
	x = x + x;
      y = y + y;
      if (x >= 1073741824L) 
      {
	x = x - 1073741824L;
	incr (y);
      } 
      x = x + x;
      y = y + y - q;
      q = q + q;
      if (x >= 1073741824L) 
      {
	x = x - 1073741824L;
	incr (y);
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
      decr (k);
    } while (!(k == 0));
    Result = halfp (q);
  } 
  return Result;
} 
integer 
pyth_add (integer a , integer b) 
{
  /* 30 */ register integer Result; fraction r;
  boolean big;
  a = abs (a);
  b = abs (b);
  if (a < b) 
  {
    r = b;
    b = a;
    a = r;
  } 
  if (b > 0) 
  {
    if (a < 536870912L) 
    big = false;
    else {
	
      a = a / 4;
      b = b / 4;
      big = true;
    } 
    while (true) {
	
      r = makefraction (b , a);
      r = takefraction (r , r);
      if (r == 0) 
      goto done;
      r = makefraction (r , 1073741824L + r);
      a = a + takefraction (a + a , r);
      b = takefraction (b , r);
    } 
    done:;
    if (big) {
	
      if (a < 536870912L) 
      a = a + a + a + a;
      else {
	  
	arith_error = true;
	a = 2147483647L;
      } 
    } 
  } 
  Result = a;
  return Result;
} 
integer 
pyth_sub (integer a , integer b) 
{
  /* 30 */ register integer Result; fraction r;
  boolean big;
  a = abs (a);
  b = abs (b);
  if (a <= b) 
  {
    if (a < b) 
    {
      {
	if (interaction == 3) 
	;
	if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
	{
	  print_nl (261);
	  print (fullsourcefilenamestack[in_open]);
	  print (58);
	  print_int (line);
	  print (262);
	  print (309);
	} 
	else {
	    
	  print_nl (263);
	  print (309);
	} 
      } 
      print_scaled (a);
      print (310);
      print_scaled (b);
      print (306);
      {
	help_ptr = 2;
	help_line[1] = 307;
	help_line[0] = 308;
      } 
      error ();
    } 
    a = 0;
  } 
  else {
      
    if (a < 1073741824L) 
    big = false;
    else {
	
      a = halfp (a);
      b = halfp (b);
      big = true;
    } 
    while (true) {
	
      r = makefraction (b , a);
      r = takefraction (r , r);
      if (r == 0) 
      goto done;
      r = makefraction (r , 1073741824L - r);
      a = a - takefraction (a + a , r);
      b = takefraction (b , r);
    } 
    done:;
    if (big) 
    a = a + a;
  } 
  Result = a;
  return Result;
} 
scaled 
m_log (scaled x) 
{
  register scaled Result; integer y, z;
  integer k;
  if (x <= 0) 
  {
    {
      if (interaction == 3) 
;
      if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[in_open]);
	print (58);
	print_int (line);
	print (262);
	print (311);
      } 
      else {
	  
	print_nl (263);
	print (311);
      } 
    } 
    print_scaled (x);
    print (306);
    {
      help_ptr = 2;
      help_line[1] = 312;
      help_line[0] = 308;
    } 
    error ();
    Result = 0;
  } 
  else {
      
    y = 1302456860L;
    z = 6581195L;
    while (x < 1073741824L) {
	
      x = x + x;
      y = y - 93032639L;
      z = z - 48782L;
    } 
    y = y + (z / 65536L);
    k = 2;
    while (x > 1073741828L) {
	
      z = ((x - 1) / two_to_the[k]) + 1;
      while (x < 1073741824L + z) {
	  
	z = halfp (z + 1);
	k = k + 1;
      } 
      y = y + spec_log[k];
      x = x - z;
    } 
    Result = y / 8;
  } 
  return Result;
} 
scaled 
m_exp (scaled x) 
{
  register scaled Result; small_number k;
  integer y, z;
  if (x > 174436200L) 
  {
    arith_error = true;
    Result = 2147483647L;
  } 
  else if (x < -197694359L) 
  Result = 0;
  else {
      
    if (x <= 0) 
    {
      z = -8 * x;
      y = 1048576L;
    } 
    else {
	
      if (x <= 127919879L) 
      z = 1023359037L - 8 * x;
      else z = 8 * (174436200L - x);
      y = 2147483647L;
    } 
    k = 1;
    while (z > 0) {
	
      while (z >= spec_log[k]) {
	  
	z = z - spec_log[k];
	y = y - 1 - ((y - two_to_the[k - 1]) / two_to_the[k]);
      } 
      incr (k);
    } 
    if (x <= 127919879L) 
    Result = (y + 8) / 16;
    else Result = y;
  } 
  return Result;
} 
angle 
n_arg (integer x , integer y) 
{
  register angle Result; angle z;
  integer t;
  small_number k;
  unsigned char octant;
  if (x >= 0) 
  octant = 1;
  else {
      
    x = - (integer) x;
    octant = 2;
  } 
  if (y < 0) 
  {
    y = - (integer) y;
    octant = octant + 2;
  } 
  if (x < y) 
  {
    t = y;
    y = x;
    x = t;
    octant = octant + 4;
  } 
  if (x == 0) 
  {
    {
      if (interaction == 3) 
;
      if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[in_open]);
	print (58);
	print_int (line);
	print (262);
	print (313);
      } 
      else {
	  
	print_nl (263);
	print (313);
      } 
    } 
    {
      help_ptr = 2;
      help_line[1] = 314;
      help_line[0] = 308;
    } 
    error ();
    Result = 0;
  } 
  else {
      
    while (x >= 536870912L) {
	
      x = halfp (x);
      y = halfp (y);
    } 
    z = 0;
    if (y > 0) 
    {
      while (x < 268435456L) {
	  
	x = x + x;
	y = y + y;
      } 
      k = 0;
      do {
	  y = y + y;
	incr (k);
	if (y > x) 
	{
	  z = z + spec_atan[k];
	  t = x;
	  x = x + (y / two_to_the[k + k]);
	  y = y - t;
	} 
      } while (!(k == 15));
      do {
	  y = y + y;
	incr (k);
	if (y > x) 
	{
	  z = z + spec_atan[k];
	  y = y - x;
	} 
      } while (!(k == 26));
    } 
    switch (octant) 
    {case 1 : 
      Result = z;
      break;
    case 5 : 
      Result = 94371840L - z;
      break;
    case 6 : 
      Result = 94371840L + z;
      break;
    case 2 : 
      Result = 188743680L - z;
      break;
    case 4 : 
      Result = z - 188743680L;
      break;
    case 8 : 
      Result = - (integer) z - 94371840L;
      break;
    case 7 : 
      Result = z - 94371840L;
      break;
    case 3 : 
      Result = - (integer) z;
      break;
    } 
  } 
  return Result;
} 
void 
n_sin_cos (angle z) 
{
  small_number k;
  unsigned char q;
  fraction r;
  integer x, y, t;
  while (z < 0) z = z + 377487360L;
  z = z % 377487360L;
  q = z / 47185920L;
  z = z % 47185920L;
  x = 268435456L;
  y = x;
  if (!odd (q)) 
  z = 47185920L - z;
  k = 1;
  while (z > 0) {
      
    if (z >= spec_atan[k]) 
    {
      z = z - spec_atan[k];
      t = x;
      x = t + y / two_to_the[k];
      y = y - t / two_to_the[k];
    } 
    incr (k);
  } 
  if (y < 0) 
  y = 0;
  switch (q) 
  {case 0 : 
;
    break;
  case 1 : 
    {
      t = x;
      x = y;
      y = t;
    } 
    break;
  case 2 : 
    {
      t = x;
      x = - (integer) y;
      y = t;
    } 
    break;
  case 3 : 
    x = - (integer) x;
    break;
  case 4 : 
    {
      x = - (integer) x;
      y = - (integer) y;
    } 
    break;
  case 5 : 
    {
      t = x;
      x = - (integer) y;
      y = - (integer) t;
    } 
    break;
  case 6 : 
    {
      t = x;
      x = y;
      y = - (integer) t;
    } 
    break;
  case 7 : 
    y = - (integer) y;
    break;
  } 
  r = pyth_add (x , y);
  n_cos = makefraction (x , r);
  n_sin = makefraction (y , r);
} 
void 
new_randoms (void) 
{
  unsigned char k;
  fraction x;
  {register integer for_end; k = 0;for_end = 23; if (k <= for_end) do 
    {
      x = randoms[k] - randoms[k + 31];
      if (x < 0) 
      x = x + 268435456L;
      randoms[k] = x;
    } 
  while (k++ < for_end);} 
  {register integer for_end; k = 24;for_end = 54; if (k <= for_end) do 
    {
      x = randoms[k] - randoms[k - 24];
      if (x < 0) 
      x = x + 268435456L;
      randoms[k] = x;
    } 
  while (k++ < for_end);} 
  j_random = 54;
} 
void 
init_randoms (scaled seed) 
{
  fraction j, jj, k;
  unsigned char i;
  j = abs (seed);
  while (j >= 268435456L) j = halfp (j);
  k = 1;
  {register integer for_end; i = 0;for_end = 54; if (i <= for_end) do 
    {
      jj = k;
      k = j - k;
      j = jj;
      if (k < 0) 
      k = k + 268435456L;
      randoms[(i * 21) % 55] = j;
    } 
  while (i++ < for_end);} 
  new_randoms ();
  new_randoms ();
  new_randoms ();
} 
scaled 
unif_rand (scaled x) 
{
  register scaled Result; scaled y;
  if (j_random == 0) 
  new_randoms ();
  else decr (j_random);
  y = takefraction (abs (x) , randoms[j_random]);
  if (y == abs (x)) 
  Result = 0;
  else if (x > 0) 
  Result = y;
  else Result = - (integer) y;
  return Result;
} 
scaled 
norm_rand (void) 
{
  register scaled Result; integer x, u, l;
  do {
      do { if (j_random == 0) 
      new_randoms ();
      else decr (j_random);
      x = takefraction (112429L , randoms[j_random] - 134217728L);
      if (j_random == 0) 
      new_randoms ();
      else decr (j_random);
      u = randoms[j_random];
    } while (!(abs (x) < u));
    x = makefraction (x , u);
    l = 139548960L - m_log (u);
  } while (!(ab_vs_cd (1024 , l , x , x) >= 0));
  Result = x;
  return Result;
} 
#ifdef TEXMF_DEBUG
void 
zprintword (memoryword w) 
{
  print_int (w .cint);
  print_char (32);
  print_scaled (w .cint);
  print_char (32);
  print_scaled (w .cint / 4096);
  print_ln ();
  print_int (w .hhfield.lhfield);
  print_char (61);
  print_int (w .hhfield.b0);
  print_char (58);
  print_int (w .hhfield.b1);
  print_char (59);
  print_int (w .hhfield.v.RH);
  print_char (32);
  print_int (w .qqqq.b0);
  print_char (58);
  print_int (w .qqqq.b1);
  print_char (58);
  print_int (w .qqqq .b2);
  print_char (58);
  print_int (w .qqqq .b3);
} 
#endif /* TEXMF_DEBUG */
void 
show_token_list (integer p , integer q , integer l , integer nulltally) 
{
  /* 10 */ small_number cclass, c;
  integer r, v;
  cclass = 3;
  tally = nulltally;
  while ((p != 0) && (tally < l)) {
      
    if (p == q) 
    {
      first_count = tally;
      trick_count = tally + 1 + errorline - halferrorline;
      if (trick_count < errorline) 
      trick_count = errorline;
    } 
    c = 9;
    if ((p < 0) || (p > mem_end)) 
    {
      print (493);
      goto lab10;
    } 
    if (p < hi_mem_min) {
	
      if (mem[p].hhfield.b1 == 12) {
	  
	if (mem[p].hhfield.b0 == 16) 
	{
	  if (cclass == 0) 
	  print_char (32);
	  v = mem[p + 1].cint;
	  if (v < 0) 
	  {
	    if (cclass == 17) 
	    print_char (32);
	    print_char (91);
	    print_scaled (v);
	    print_char (93);
	    c = 18;
	  } 
	  else {
	      
	    print_scaled (v);
	    c = 0;
	  } 
	} 
	else if (mem[p].hhfield.b0 != 4) 
	print (496);
	else {
	    
	  print_char (34);
	  slow_print (mem[p + 1].cint);
	  print_char (34);
	  c = 4;
	} 
      } 
      else if ((mem[p].hhfield.b1 != 11) || (mem[p].hhfield.b0 < 
      1) || (mem[p].hhfield.b0 > 19)) 
      print (496);
      else {
	  
	g_pointer = p;
	print_capsule ();
	c = 8;
      } 
    } 
    else {
	
      r = mem[p].hhfield.lhfield;
      if (r >= 9770) 
      {
	if (r < 9920) 
	{
	  print (498);
	  r = r - (9770);
	} 
	else if (r < 10070) 
	{
	  print (499);
	  r = r - (9920);
	} 
	else {
	    
	  print (500);
	  r = r - (10070);
	} 
	print_int (r);
	print_char (41);
	c = 8;
      } 
      else if (r < 1) {
	  
	if (r == 0) 
	{
	  if (cclass == 17) 
	  print_char (32);
	  print (497);
	  c = 18;
	} 
	else print (494);
      } 
      else {
	  
	r = hash[r].v.RH;
	if ((r < 0) || (r >= str_ptr)) 
	print (495);
	else {
	    
	  c = char_class[str_pool[str_start[r]]];
	  if (c == cclass) 
	  switch (c) 
	  {case 9 : 
	    print_char (46);
	    break;
	  case 5 : 
	  case 6 : 
	  case 7 : 
	  case 8 : 
	;
	    break;
	    default: 
	    print_char (32);
	    break;
	  } 
	  slow_print (r);
	} 
      } 
    } 
    cclass = c;
    p = mem[p].hhfield.v.RH;
  } 
  if (p != 0) 
  print (492);
  lab10:;
} 
void 
runaway (void) 
{
  if (scanner_status > 2) 
  {
    print_nl (638);
    switch (scanner_status) 
    {case 3 : 
      print (639);
      break;
    case 4 : 
    case 5 : 
      print (640);
      break;
    case 6 : 
      print (641);
      break;
    } 
    print_ln ();
    show_token_list (mem[memtop - 2].hhfield.v.RH , 0 , errorline - 10 , 0 
 );
  } 
} 
halfword 
get_avail (void) 
{
  register halfword Result; halfword p;
  p = avail;
  if (p != 0) 
  avail = mem[avail].hhfield.v.RH;
  else if (mem_end < memmax) 
  {
    incr (mem_end);
    p = mem_end;
  } 
  else {
      
    decr (hi_mem_min);
    p = hi_mem_min;
    if (hi_mem_min <= lo_mem_max) 
    {
      runaway ();
      overflow (315 , memmax + 1);
    } 
  } 
  mem[p].hhfield.v.RH = 0;
	;
#ifdef STAT
  incr (dyn_used);
#endif /* STAT */
  Result = p;
  return Result;
} 
halfword 
get_node (integer s) 
{
  /* 40 10 20 */ register halfword Result; halfword p;
  halfword q;
  integer r;
  integer t, tt;
  lab20: p = rover;
  do {
      q = p + mem[p].hhfield.lhfield;
    while ((mem[q].hhfield.v.RH == 268435455L)) {
	
      t = mem[q + 1].hhfield.v.RH;
      tt = mem[q + 1].hhfield.lhfield;
      if (q == rover) 
      rover = t;
      mem[t + 1].hhfield.lhfield = tt;
      mem[tt + 1].hhfield.v.RH = t;
      q = q + mem[q].hhfield.lhfield;
    } 
    r = q - s;
    if (r > p + 1) 
    {
      mem[p].hhfield.lhfield = r - p;
      rover = p;
      goto found;
    } 
    if (r == p) {
	
      if (mem[p + 1].hhfield.v.RH != p) 
      {
	rover = mem[p + 1].hhfield.v.RH;
	t = mem[p + 1].hhfield.lhfield;
	mem[rover + 1].hhfield.lhfield = t;
	mem[t + 1].hhfield.v.RH = rover;
	goto found;
      } 
    } 
    mem[p].hhfield.lhfield = q - p;
    p = mem[p + 1].hhfield.v.RH;
  } while (!(p == rover));
  if (s == 1073741824L) 
  {
    Result = 268435455L;
    goto lab10;
  } 
  if (lo_mem_max + 2 < hi_mem_min) {
      
    if (lo_mem_max + 2 <= 268435455L) 
    {
      if (hi_mem_min - lo_mem_max >= 1998) 
      t = lo_mem_max + 1000;
      else t = lo_mem_max + 1 + (hi_mem_min - lo_mem_max) / 2;
      if (t > 268435455L) 
      t = 268435455L;
      p = mem[rover + 1].hhfield.lhfield;
      q = lo_mem_max;
      mem[p + 1].hhfield.v.RH = q;
      mem[rover + 1].hhfield.lhfield = q;
      mem[q + 1].hhfield.v.RH = rover;
      mem[q + 1].hhfield.lhfield = p;
      mem[q].hhfield.v.RH = 268435455L;
      mem[q].hhfield.lhfield = t - lo_mem_max;
      lo_mem_max = t;
      mem[lo_mem_max].hhfield.v.RH = 0;
      mem[lo_mem_max].hhfield.lhfield = 0;
      rover = q;
      goto lab20;
    } 
  } 
  overflow (315 , memmax + 1);
  found: mem[r].hhfield.v.RH = 0;
	;
#ifdef STAT
  var_used = var_used + s;
#endif /* STAT */
  Result = r;
  lab10:;
  return Result;
} 
void 
free_node (halfword p , halfword s) 
{
  halfword q;
  mem[p].hhfield.lhfield = s;
  mem[p].hhfield.v.RH = 268435455L;
  q = mem[rover + 1].hhfield.lhfield;
  mem[p + 1].hhfield.lhfield = q;
  mem[p + 1].hhfield.v.RH = rover;
  mem[rover + 1].hhfield.lhfield = p;
  mem[q + 1].hhfield.v.RH = p;
	;
#ifdef STAT
  var_used = var_used - s;
#endif /* STAT */
} 
void 
flush_list (halfword p) 
{
  /* 30 */ halfword q, r;
  if (p >= hi_mem_min) {
      
    if (p != memtop) 
    {
      r = p;
      do {
	  q = r;
	r = mem[r].hhfield.v.RH;
	;
#ifdef STAT
	decr (dyn_used);
#endif /* STAT */
	if (r < hi_mem_min) 
	goto done;
      } while (!(r == memtop));
      done: mem[q].hhfield.v.RH = avail;
      avail = p;
    } 
  } 
} 
void 
flush_node_list (halfword p) 
{
  halfword q;
  while (p != 0) {
      
    q = p;
    p = mem[p].hhfield.v.RH;
    if (q < hi_mem_min) 
    free_node (q , 2);
    else {
	
      mem[q].hhfield.v.RH = avail;
      avail = q;
	;
#ifdef STAT
      decr (dyn_used);
#endif /* STAT */
    } 
  } 
} 
#ifdef TEXMF_DEBUG
void 
zcheckmem (boolean printlocs) 
{
  /* 31 32 */ halfword p, q, r;
  boolean clobbered;
  {register integer for_end; p = 0;for_end = lo_mem_max; if (p <= for_end) 
  do 
    freearr[p] = false;
  while (p++ < for_end);} 
  {register integer for_end; p = hi_mem_min;for_end = mem_end; if (p <= 
  for_end) do 
    freearr[p] = false;
  while (p++ < for_end);} 
  p = avail;
  q = 0;
  clobbered = false;
  while (p != 0) {
      
    if ((p > mem_end) || (p < hi_mem_min)) 
    clobbered = true;
    else if (freearr[p]) 
    clobbered = true;
    if (clobbered) 
    {
      print_nl (316);
      print_int (q);
      goto done1;
    } 
    freearr[p] = true;
    q = p;
    p = mem[q].hhfield.v.RH;
  } 
  done1:;
  p = rover;
  q = 0;
  clobbered = false;
  do {
      if ((p >= lo_mem_max)) 
    clobbered = true;
    else if ((mem[p + 1].hhfield.v.RH >= lo_mem_max)) 
    clobbered = true;
    else if (!((mem[p].hhfield.v.RH == 268435455L)) || (mem[p]
    .hhfield.lhfield < 2) || (p + mem[p].hhfield.lhfield > lo_mem_max) 
    || (mem[mem[p + 1].hhfield.v.RH + 1].hhfield.lhfield != p)) 
    clobbered = true;
    if (clobbered) 
    {
      print_nl (317);
      print_int (q);
      goto done2;
    } 
    {register integer for_end; q = p;for_end = p + mem[p].hhfield 
  .lhfield - 1; if (q <= for_end) do 
      {
	if (freearr[q]) 
	{
	  print_nl (318);
	  print_int (q);
	  goto done2;
	} 
	freearr[q] = true;
      } 
    while (q++ < for_end);} 
    q = p;
    p = mem[p + 1].hhfield.v.RH;
  } while (!(p == rover));
  done2:;
  p = 0;
  while (p <= lo_mem_max) {
      
    if ((mem[p].hhfield.v.RH == 268435455L)) 
    {
      print_nl (319);
      print_int (p);
    } 
    while ((p <= lo_mem_max) && !freearr[p]) incr (p);
    while ((p <= lo_mem_max) && freearr[p]) incr (p);
  } 
  q = 13;
  p = mem[q].hhfield.v.RH;
  while (p != 13) {
      
    if (mem[p + 1].hhfield.lhfield != q) 
    {
      print_nl (598);
      print_int (p);
    } 
    p = mem[p + 1].hhfield.v.RH;
    r = 19;
    do {
	if (mem[mem[p].hhfield.lhfield + 1].cint >= mem[r + 1]
      .cint) 
      {
	print_nl (599);
	print_int (p);
      } 
      r = mem[p].hhfield.lhfield;
      q = p;
      p = mem[q].hhfield.v.RH;
    } while (!(r == 0));
  } 
  if (printlocs) 
  {
    print_nl (320);
    {register integer for_end; p = 0;for_end = lo_mem_max; if (p <= 
    for_end) do 
      if (!freearr[p]&& ((p > was_lo_max) || was_free[p])) 
      {
	print_char (32);
	print_int (p);
      } 
    while (p++ < for_end);} 
    {register integer for_end; p = hi_mem_min;for_end = mem_end; if (p <= 
    for_end) do 
      if (!freearr[p]&& ((p < was_hi_min) || (p > was_mem_end) || 
      was_free[p])) 
      {
	print_char (32);
	print_int (p);
      } 
    while (p++ < for_end);} 
  } 
  {register integer for_end; p = 0;for_end = lo_mem_max; if (p <= for_end) 
  do 
    was_free[p] = freearr[p];
  while (p++ < for_end);} 
  {register integer for_end; p = hi_mem_min;for_end = mem_end; if (p <= 
  for_end) do 
    was_free[p] = freearr[p];
  while (p++ < for_end);} 
  was_mem_end = mem_end;
  was_lo_max = lo_mem_max;
  was_hi_min = hi_mem_min;
} 
#endif /* TEXMF_DEBUG */
#ifdef TEXMF_DEBUG
void 
zsearchmem (halfword p) 
{
  integer q;
  {register integer for_end; q = 0;for_end = lo_mem_max; if (q <= for_end) 
  do 
    {
      if (mem[q].hhfield.v.RH == p) 
      {
	print_nl (321);
	print_int (q);
	print_char (41);
      } 
      if (mem[q].hhfield.lhfield == p) 
      {
	print_nl (322);
	print_int (q);
	print_char (41);
      } 
    } 
  while (q++ < for_end);} 
  {register integer for_end; q = hi_mem_min;for_end = mem_end; if (q <= 
  for_end) do 
    {
      if (mem[q].hhfield.v.RH == p) 
      {
	print_nl (321);
	print_int (q);
	print_char (41);
      } 
      if (mem[q].hhfield.lhfield == p) 
      {
	print_nl (322);
	print_int (q);
	print_char (41);
      } 
    } 
  while (q++ < for_end);} 
  {register integer for_end; q = 1;for_end = 9769; if (q <= for_end) do 
    {
      if (eqtb[q].v.RH == p) 
      {
	print_nl (458);
	print_int (q);
	print_char (41);
      } 
    } 
  while (q++ < for_end);} 
} 
#endif /* TEXMF_DEBUG */
void 
print_op (quarterword c) 
{
  if (c <= 15) 
  print_type (c);
  else switch (c) 
  {case 30 : 
    print (347);
    break;
  case 31 : 
    print (348);
    break;
  case 32 : 
    print (349);
    break;
  case 33 : 
    print (350);
    break;
  case 34 : 
    print (351);
    break;
  case 35 : 
    print (352);
    break;
  case 36 : 
    print (353);
    break;
  case 37 : 
    print (354);
    break;
  case 38 : 
    print (355);
    break;
  case 39 : 
    print (356);
    break;
  case 40 : 
    print (357);
    break;
  case 41 : 
    print (358);
    break;
  case 42 : 
    print (359);
    break;
  case 43 : 
    print (360);
    break;
  case 44 : 
    print (361);
    break;
  case 45 : 
    print (362);
    break;
  case 46 : 
    print (363);
    break;
  case 47 : 
    print (364);
    break;
  case 48 : 
    print (365);
    break;
  case 49 : 
    print (366);
    break;
  case 50 : 
    print (367);
    break;
  case 51 : 
    print (368);
    break;
  case 52 : 
    print (369);
    break;
  case 53 : 
    print (370);
    break;
  case 54 : 
    print (371);
    break;
  case 55 : 
    print (372);
    break;
  case 56 : 
    print (373);
    break;
  case 57 : 
    print (374);
    break;
  case 58 : 
    print (375);
    break;
  case 59 : 
    print (376);
    break;
  case 60 : 
    print (377);
    break;
  case 61 : 
    print (378);
    break;
  case 62 : 
    print (379);
    break;
  case 63 : 
    print (380);
    break;
  case 64 : 
    print (381);
    break;
  case 65 : 
    print (382);
    break;
  case 66 : 
    print (383);
    break;
  case 67 : 
    print (384);
    break;
  case 68 : 
    print (385);
    break;
  case 69 : 
    print_char (43);
    break;
  case 70 : 
    print_char (45);
    break;
  case 71 : 
    print_char (42);
    break;
  case 72 : 
    print_char (47);
    break;
  case 73 : 
    print (386);
    break;
  case 74 : 
    print (310);
    break;
  case 75 : 
    print (387);
    break;
  case 76 : 
    print (388);
    break;
  case 77 : 
    print_char (60);
    break;
  case 78 : 
    print (389);
    break;
  case 79 : 
    print_char (62);
    break;
  case 80 : 
    print (390);
    break;
  case 81 : 
    print_char (61);
    break;
  case 82 : 
    print (391);
    break;
  case 83 : 
    print (38);
    break;
  case 84 : 
    print (392);
    break;
  case 85 : 
    print (393);
    break;
  case 86 : 
    print (394);
    break;
  case 87 : 
    print (395);
    break;
  case 88 : 
    print (396);
    break;
  case 89 : 
    print (397);
    break;
  case 90 : 
    print (398);
    break;
  case 91 : 
    print (399);
    break;
  case 92 : 
    print (400);
    break;
  case 94 : 
    print (401);
    break;
  case 95 : 
    print (402);
    break;
  case 96 : 
    print (403);
    break;
  case 97 : 
    print (404);
    break;
  case 98 : 
    print (405);
    break;
  case 99 : 
    print (406);
    break;
  case 100 : 
    print (407);
    break;
    default: 
    print (408);
    break;
  } 
} 
void 
fix_date_and_time (void) 
{
  dateandtime (internal[17], internal[16], internal[15], 
  internal[14]);
  internal[17] = internal[17]* 65536L;
  internal[16] = internal[16]* 65536L;
  internal[15] = internal[15]* 65536L;
  internal[14] = internal[14]* 65536L;
} 
halfword 
id_lookup (integer j , integer l) 
{
  /* 40 */ register halfword Result; integer h;
  halfword p;
  halfword k;
  if (l == 1) 
  {
    p = buffer[j]+ 1;
    hash[p].v.RH = p - 1;
    goto found;
  } 
  h = buffer[j];
  {register integer for_end; k = j + 1;for_end = j + l - 1; if (k <= 
  for_end) do 
    {
      h = h + h + buffer[k];
      while (h >= 7919) h = h - 7919;
    } 
  while (k++ < for_end);} 
  p = h + 257;
  while (true) {
      
    if (hash[p].v.RH > 0) {
	
      if ((str_start[hash[p].v.RH + 1] - str_start[hash[p].v.RH]
   ) == l) {
	  
	if (str_eq_buf (hash[p].v.RH , j)) 
	goto found;
      } 
    } 
    if (hash[p].lhfield == 0) 
    {
      if (hash[p].v.RH > 0) 
      {
	do {
	    if ((hash_used == 257)) 
	  overflow (457 , 9500);
	  decr (hash_used);
	} while (!(hash[hash_used].v.RH == 0));
	hash[p].lhfield = hash_used;
	p = hash_used;
      } 
      {
	if (pool_ptr + l > max_pool_ptr) 
	{
	  if (pool_ptr + l > pool_size) 
	  overflow (257 , pool_size - init_pool_ptr);
	  max_pool_ptr = pool_ptr + l;
	} 
      } 
      {register integer for_end; k = j;for_end = j + l - 1; if (k <= 
      for_end) do 
	{
	  str_pool[pool_ptr] = buffer[k];
	  incr (pool_ptr);
	} 
      while (k++ < for_end);} 
      hash[p].v.RH = make_string ();
      str_ref[hash[p].v.RH] = 127;
	;
#ifdef STAT
      incr (st_count);
#endif /* STAT */
      goto found;
    } 
    p = hash[p].lhfield;
  } 
  found: Result = p;
  return Result;
} 
halfword 
new_num_tok (scaled v) 
{
  register halfword Result; halfword p;
  p = get_node (2);
  mem[p + 1].cint = v;
  mem[p].hhfield.b0 = 16;
  mem[p].hhfield.b1 = 12;
  Result = p;
  return Result;
} 
void 
flush_token_list (halfword p) 
{
  halfword q;
  while (p != 0) {
      
    q = p;
    p = mem[p].hhfield.v.RH;
    if (q >= hi_mem_min) 
    {
      mem[q].hhfield.v.RH = avail;
      avail = q;
	;
#ifdef STAT
      decr (dyn_used);
#endif /* STAT */
    } 
    else {
	
      switch (mem[q].hhfield.b0) 
      {case 1 : 
      case 2 : 
      case 16 : 
	;
	break;
      case 4 : 
	{
	  if (str_ref[mem[q + 1].cint]< 127) {
	      
	    if (str_ref[mem[q + 1].cint] > 1) 
	    decr (str_ref[mem[q + 1].cint]);
	    else flush_string (mem[q + 1].cint);
	  } 
	} 
	break;
      case 3 : 
      case 5 : 
      case 7 : 
      case 12 : 
      case 10 : 
      case 6 : 
      case 9 : 
      case 8 : 
      case 11 : 
      case 14 : 
      case 13 : 
      case 17 : 
      case 18 : 
      case 19 : 
	{
	  g_pointer = q;
	  token_recycle ();
	} 
	break;
	default: 
	confusion (491);
	break;
      } 
      free_node (q , 2);
    } 
  } 
} 
void 
delete_mac_ref (halfword p) 
{
  if (mem[p].hhfield.lhfield == 0) 
  flush_token_list (p);
  else decr (mem[p].hhfield.lhfield);
} 
void 
print_cmd_mod (integer c , integer m) 
{
  switch (c) 
  {case 18 : 
    print (462);
    break;
  case 77 : 
    print (461);
    break;
  case 59 : 
    print (464);
    break;
  case 72 : 
    print (463);
    break;
  case 79 : 
    print (460);
    break;
  case 32 : 
    print (465);
    break;
  case 81 : 
    print (58);
    break;
  case 82 : 
    print (44);
    break;
  case 57 : 
    print (466);
    break;
  case 19 : 
    print (467);
    break;
  case 60 : 
    print (468);
    break;
  case 27 : 
    print (469);
    break;
  case 11 : 
    print (470);
    break;
  case 80 : 
    print (459);
    break;
  case 84 : 
    print (453);
    break;
  case 26 : 
    print (471);
    break;
  case 6 : 
    print (472);
    break;
  case 9 : 
    print (473);
    break;
  case 70 : 
    print (474);
    break;
  case 73 : 
    print (475);
    break;
  case 13 : 
    print (476);
    break;
  case 46 : 
    print (123);
    break;
  case 63 : 
    print (91);
    break;
  case 14 : 
    print (477);
    break;
  case 15 : 
    print (478);
    break;
  case 69 : 
    print (479);
    break;
  case 28 : 
    print (480);
    break;
  case 47 : 
    print (408);
    break;
  case 24 : 
    print (481);
    break;
  case 7 : 
    print_char (92);
    break;
  case 65 : 
    print (125);
    break;
  case 64 : 
    print (93);
    break;
  case 12 : 
    print (482);
    break;
  case 8 : 
    print (483);
    break;
  case 83 : 
    print (59);
    break;
  case 17 : 
    print (484);
    break;
  case 78 : 
    print (485);
    break;
  case 74 : 
    print (486);
    break;
  case 35 : 
    print (487);
    break;
  case 58 : 
    print (488);
    break;
  case 71 : 
    print (489);
    break;
  case 75 : 
    print (490);
    break;
  case 16 : 
    if (m <= 2) {
	
      if (m == 1) 
      print (655);
      else if (m < 1) 
      print (454);
      else print (656);
    } 
    else if (m == 53) 
    print (657);
    else if (m == 44) 
    print (658);
    else print (659);
    break;
  case 4 : 
    if (m <= 1) {
	
      if (m == 1) 
      print (662);
      else print (455);
    } 
    else if (m == 9770) 
    print (660);
    else print (661);
    break;
  case 61 : 
    switch (m) 
    {case 1 : 
      print (664);
      break;
    case 2 : 
      print_char (64);
      break;
    case 3 : 
      print (665);
      break;
      default: 
      print (663);
      break;
    } 
    break;
  case 56 : 
    if (m >= 9770) {
	
      if (m == 9770) 
      print (676);
      else if (m == 9920) 
      print (677);
      else print (678);
    } 
    else if (m < 2) 
    print (679);
    else if (m == 2) 
    print (680);
    else print (681);
    break;
  case 3 : 
    if (m == 0) 
    print (691);
    else print (617);
    break;
  case 1 : 
  case 2 : 
    switch (m) 
    {case 1 : 
      print (718);
      break;
    case 2 : 
      print (452);
      break;
    case 3 : 
      print (719);
      break;
      default: 
      print (720);
      break;
    } 
    break;
  case 33 : 
  case 34 : 
  case 37 : 
  case 55 : 
  case 45 : 
  case 50 : 
  case 36 : 
  case 43 : 
  case 54 : 
  case 48 : 
  case 51 : 
  case 52 : 
    print_op (m);
    break;
  case 30 : 
    print_type (m);
    break;
  case 85 : 
    if (m == 0) 
    print (912);
    else print (913);
    break;
  case 23 : 
    switch (m) 
    {case 0 : 
      print (273);
      break;
    case 1 : 
      print (274);
      break;
    case 2 : 
      print (275);
      break;
      default: 
      print (919);
      break;
    } 
    break;
  case 21 : 
    if (m == 0) 
    print (920);
    else print (921);
    break;
  case 22 : 
    switch (m) 
    {case 0 : 
      print (935);
      break;
    case 1 : 
      print (936);
      break;
    case 2 : 
      print (937);
      break;
    case 3 : 
      print (938);
      break;
      default: 
      print (939);
      break;
    } 
    break;
  case 31 : 
  case 62 : 
    {
      if (c == 31) 
      print (942);
      else print (943);
      print (944);
      slow_print (hash[m].v.RH);
    } 
    break;
  case 41 : 
    if (m == 0) 
    print (945);
    else print (946);
    break;
  case 10 : 
    print (947);
    break;
  case 53 : 
  case 44 : 
  case 49 : 
    {
      print_cmd_mod (16 , c);
      print (948);
      print_ln ();
      show_token_list (mem[mem[m].hhfield.v.RH].hhfield.v.RH , 0 , 
      1000 , 0);
    } 
    break;
  case 5 : 
    print (949);
    break;
  case 40 : 
    slow_print (int_name[m]);
    break;
  case 68 : 
    if (m == 1) 
    print (956);
    else if (m == 0) 
    print (957);
    else print (958);
    break;
  case 66 : 
    if (m == 6) 
    print (959);
    else print (960);
    break;
  case 67 : 
    if (m == 0) 
    print (961);
    else print (962);
    break;
  case 25 : 
    if (m < 1) 
    print (992);
    else if (m == 1) 
    print (993);
    else print (994);
    break;
  case 20 : 
    switch (m) 
    {case 0 : 
      print (1004);
      break;
    case 1 : 
      print (1005);
      break;
    case 2 : 
      print (1006);
      break;
    case 3 : 
      print (1007);
      break;
      default: 
      print (1008);
      break;
    } 
    break;
  case 76 : 
    switch (m) 
    {case 0 : 
      print (1026);
      break;
    case 1 : 
      print (1027);
      break;
    case 2 : 
      print (1029);
      break;
    case 3 : 
      print (1031);
      break;
    case 5 : 
      print (1028);
      break;
    case 6 : 
      print (1030);
      break;
    case 7 : 
      print (1032);
      break;
    case 11 : 
      print (1033);
      break;
      default: 
      print (1034);
      break;
    } 
    break;
  case 29 : 
    if (m == 16) 
    print (1060);
    else print (1059);
    break;
    default: 
    print (603);
    break;
  } 
} 
void 
show_macro (halfword p , integer q , integer l) 
{
  /* 10 */ halfword r;
  p = mem[p].hhfield.v.RH;
  while (mem[p].hhfield.lhfield > 7) {
      
    r = mem[p].hhfield.v.RH;
    mem[p].hhfield.v.RH = 0;
    show_token_list (p , 0 , l , 0);
    mem[p].hhfield.v.RH = r;
    p = r;
    if (l > 0) 
    l = l - tally;
    else goto lab10;
  } 
  tally = 0;
  switch (mem[p].hhfield.lhfield) 
  {case 0 : 
    print (501);
    break;
  case 1 : 
  case 2 : 
  case 3 : 
    {
      print_char (60);
      print_cmd_mod (56 , mem[p].hhfield.lhfield);
      print (502);
    } 
    break;
  case 4 : 
    print (503);
    break;
  case 5 : 
    print (504);
    break;
  case 6 : 
    print (505);
    break;
  case 7 : 
    print (506);
    break;
  } 
  show_token_list (mem[p].hhfield.v.RH , q , l - tally , 0);
  lab10:;
} 
void 
init_big_node (halfword p) 
{
  halfword q;
  small_number s;
  s = big_node_size[mem[p].hhfield.b0];
  q = get_node (s);
  do {
      s = s - 2;
    {
      if (serial_no > 2147483583L) 
      overflow (588 , serial_no / 64);
      mem[q + s].hhfield.b0 = 19;
      serial_no = serial_no + 64;
      mem[q + s + 1].cint = serial_no;
    } 
    mem[q + s].hhfield.b1 = halfp (s) + 5;
    mem[q + s].hhfield.v.RH = 0;
  } while (!(s == 0));
  mem[q].hhfield.v.RH = p;
  mem[p + 1].cint = q;
} 
halfword 
id_transform (void) 
{
  register halfword Result; halfword p, q, r;
  p = get_node (2);
  mem[p].hhfield.b0 = 13;
  mem[p].hhfield.b1 = 11;
  mem[p + 1].cint = 0;
  init_big_node (p);
  q = mem[p + 1].cint;
  r = q + 12;
  do {
      r = r - 2;
    mem[r].hhfield.b0 = 16;
    mem[r + 1].cint = 0;
  } while (!(r == q));
  mem[q + 5].cint = 65536L;
  mem[q + 11].cint = 65536L;
  Result = p;
  return Result;
} 
void 
new_root (halfword x) 
{
  halfword p;
  p = get_node (2);
  mem[p].hhfield.b0 = 0;
  mem[p].hhfield.b1 = 0;
  mem[p].hhfield.v.RH = x;
  eqtb[x].v.RH = p;
} 
void 
print_variable_name (halfword p) 
{
  /* 40 10 */ halfword q;
  halfword r;
  while (mem[p].hhfield.b1 >= 5) {
      
    switch (mem[p].hhfield.b1) 
    {case 5 : 
      print_char (120);
      break;
    case 6 : 
      print_char (121);
      break;
    case 7 : 
      print (509);
      break;
    case 8 : 
      print (510);
      break;
    case 9 : 
      print (511);
      break;
    case 10 : 
      print (512);
      break;
    case 11 : 
      {
	print (513);
	print_int (p - 0);
	goto lab10;
      } 
      break;
    } 
    print (514);
    p = mem[p - 2 * (mem[p].hhfield.b1 - 5)].hhfield.v.RH;
  } 
  q = 0;
  while (mem[p].hhfield.b1 > 1) {
      
    if (mem[p].hhfield.b1 == 3) 
    {
      r = new_num_tok (mem[p + 2].cint);
      do {
	  p = mem[p].hhfield.v.RH;
      } while (!(mem[p].hhfield.b1 == 4));
    } 
    else if (mem[p].hhfield.b1 == 2) 
    {
      p = mem[p].hhfield.v.RH;
      goto found;
    } 
    else {
	
      if (mem[p].hhfield.b1 != 4) 
      confusion (508);
      r = get_avail ();
      mem[r].hhfield.lhfield = mem[p + 2].hhfield.lhfield;
    } 
    mem[r].hhfield.v.RH = q;
    q = r;
    found: p = mem[p + 2].hhfield.v.RH;
  } 
  r = get_avail ();
  mem[r].hhfield.lhfield = mem[p].hhfield.v.RH;
  mem[r].hhfield.v.RH = q;
  if (mem[p].hhfield.b1 == 1) 
  print (507);
  show_token_list (r , 0 , 2147483647L , tally);
  flush_token_list (r);
  lab10:;
} 
boolean 
zinteresting (halfword p) 
{
  register boolean Result; small_number t;
  if (internal[3] > 0) 
  Result = true;
  else {
      
    t = mem[p].hhfield.b1;
    if (t >= 5) {
	
      if (t != 11) 
      t = mem[mem[p - 2 * (t - 5)].hhfield.v.RH].hhfield.b1;
    } 
    Result = (t != 11);
  } 
  return Result;
} 
halfword 
new_structure (halfword p) 
{
  register halfword Result; halfword q, r;
  switch (mem[p].hhfield.b1) 
  {case 0 : 
    {
      q = mem[p].hhfield.v.RH;
      r = get_node (2);
      eqtb[q].v.RH = r;
    } 
    break;
  case 3 : 
    {
      q = p;
      do {
	  q = mem[q].hhfield.v.RH;
      } while (!(mem[q].hhfield.b1 == 4));
      q = mem[q + 2].hhfield.v.RH;
      r = q + 1;
      do {
	  q = r;
	r = mem[r].hhfield.v.RH;
      } while (!(r == p));
      r = get_node (3);
      mem[q].hhfield.v.RH = r;
      mem[r + 2].cint = mem[p + 2].cint;
    } 
    break;
  case 4 : 
    {
      q = mem[p + 2].hhfield.v.RH;
      r = mem[q + 1].hhfield.lhfield;
      do {
	  q = r;
	r = mem[r].hhfield.v.RH;
      } while (!(r == p));
      r = get_node (3);
      mem[q].hhfield.v.RH = r;
      mem[r + 2] = mem[p + 2];
      if (mem[p + 2].hhfield.lhfield == 0) 
      {
	q = mem[p + 2].hhfield.v.RH + 1;
	while (mem[q].hhfield.v.RH != p) q = mem[q].hhfield.v.RH;
	mem[q].hhfield.v.RH = r;
      } 
    } 
    break;
    default: 
    confusion (515);
    break;
  } 
  mem[r].hhfield.v.RH = mem[p].hhfield.v.RH;
  mem[r].hhfield.b0 = 21;
  mem[r].hhfield.b1 = mem[p].hhfield.b1;
  mem[r + 1].hhfield.lhfield = p;
  mem[p].hhfield.b1 = 2;
  q = get_node (3);
  mem[p].hhfield.v.RH = q;
  mem[r + 1].hhfield.v.RH = q;
  mem[q + 2].hhfield.v.RH = r;
  mem[q].hhfield.b0 = 0;
  mem[q].hhfield.b1 = 4;
  mem[q].hhfield.v.RH = 17;
  mem[q + 2].hhfield.lhfield = 0;
  Result = r;
  return Result;
} 
halfword 
find_variable (halfword t) 
{
  /* 10 */ register halfword Result; halfword p, q, r, s;
  halfword pp, qq, rr, ss;
  integer n;
  memoryword saveword;
  p = mem[t].hhfield.lhfield;
  t = mem[t].hhfield.v.RH;
  if (eqtb[p].lhfield % 86 != 41) 
  {
    Result = 0;
    goto lab10;
  } 
  if (eqtb[p].v.RH == 0) 
  new_root (p);
  p = eqtb[p].v.RH;
  pp = p;
  while (t != 0) {
      
    if (mem[pp].hhfield.b0 != 21) 
    {
      if (mem[pp].hhfield.b0 > 21) 
      {
	Result = 0;
	goto lab10;
      } 
      ss = new_structure (pp);
      if (p == pp) 
      p = ss;
      pp = ss;
    } 
    if (mem[p].hhfield.b0 != 21) 
    p = new_structure (p);
    if (t < hi_mem_min) 
    {
      n = mem[t + 1].cint;
      pp = mem[mem[pp + 1].hhfield.lhfield].hhfield.v.RH;
      q = mem[mem[p + 1].hhfield.lhfield].hhfield.v.RH;
      saveword = mem[q + 2];
      mem[q + 2].cint = 2147483647L;
      s = p + 1;
      do {
	  r = s;
	s = mem[s].hhfield.v.RH;
      } while (!(n <= mem[s + 2].cint));
      if (n == mem[s + 2].cint) 
      p = s;
      else {
	  
	p = get_node (3);
	mem[r].hhfield.v.RH = p;
	mem[p].hhfield.v.RH = s;
	mem[p + 2].cint = n;
	mem[p].hhfield.b1 = 3;
	mem[p].hhfield.b0 = 0;
      } 
      mem[q + 2] = saveword;
    } 
    else {
	
      n = mem[t].hhfield.lhfield;
      ss = mem[pp + 1].hhfield.lhfield;
      do {
	  rr = ss;
	ss = mem[ss].hhfield.v.RH;
      } while (!(n <= mem[ss + 2].hhfield.lhfield));
      if (n < mem[ss + 2].hhfield.lhfield) 
      {
	qq = get_node (3);
	mem[rr].hhfield.v.RH = qq;
	mem[qq].hhfield.v.RH = ss;
	mem[qq + 2].hhfield.lhfield = n;
	mem[qq].hhfield.b1 = 4;
	mem[qq].hhfield.b0 = 0;
	mem[qq + 2].hhfield.v.RH = pp;
	ss = qq;
      } 
      if (p == pp) 
      {
	p = ss;
	pp = ss;
      } 
      else {
	  
	pp = ss;
	s = mem[p + 1].hhfield.lhfield;
	do {
	    r = s;
	  s = mem[s].hhfield.v.RH;
	} while (!(n <= mem[s + 2].hhfield.lhfield));
	if (n == mem[s + 2].hhfield.lhfield) 
	p = s;
	else {
	    
	  q = get_node (3);
	  mem[r].hhfield.v.RH = q;
	  mem[q].hhfield.v.RH = s;
	  mem[q + 2].hhfield.lhfield = n;
	  mem[q].hhfield.b1 = 4;
	  mem[q].hhfield.b0 = 0;
	  mem[q + 2].hhfield.v.RH = p;
	  p = q;
	} 
      } 
    } 
    t = mem[t].hhfield.v.RH;
  } 
  if (mem[pp].hhfield.b0 >= 21) {
      
    if (mem[pp].hhfield.b0 == 21) 
    pp = mem[pp + 1].hhfield.lhfield;
    else {
	
      Result = 0;
      goto lab10;
    } 
  } 
  if (mem[p].hhfield.b0 == 21) 
  p = mem[p + 1].hhfield.lhfield;
  if (mem[p].hhfield.b0 == 0) 
  {
    if (mem[pp].hhfield.b0 == 0) 
    {
      mem[pp].hhfield.b0 = 15;
      mem[pp + 1].cint = 0;
    } 
    mem[p].hhfield.b0 = mem[pp].hhfield.b0;
    mem[p + 1].cint = 0;
  } 
  Result = p;
  lab10:;
  return Result;
} 
void 
print_path (halfword h , str_number s , boolean nuline) 
{
  /* 30 31 */ halfword p, q;
  print_diagnostic (517 , s , nuline);
  print_ln ();
  p = h;
  do {
      q = mem[p].hhfield.v.RH;
    if ((p == 0) || (q == 0)) 
    {
      print_nl (259);
      goto done;
    } 
    print_two (mem[p + 1].cint , mem[p + 2].cint);
    switch (mem[p].hhfield.b1) 
    {case 0 : 
      {
	if (mem[p].hhfield.b0 == 4) 
	print (518);
	if ((mem[q].hhfield.b0 != 0) || (q != h)) 
	q = 0;
	goto done1;
      } 
      break;
    case 1 : 
      {
	print (524);
	print_two (mem[p + 5].cint , mem[p + 6].cint);
	print (523);
	if (mem[q].hhfield.b0 != 1) 
	print (525);
	else print_two (mem[q + 3].cint , mem[q + 4].cint);
	goto done1;
      } 
      break;
    case 4 : 
      if ((mem[p].hhfield.b0 != 1) && (mem[p].hhfield.b0 != 4) 
   ) 
      print (518);
      break;
    case 3 : 
    case 2 : 
      {
	if (mem[p].hhfield.b0 == 4) 
	print (525);
	if (mem[p].hhfield.b1 == 3) 
	{
	  print (521);
	  print_scaled (mem[p + 5].cint);
	} 
	else {
	    
	  n_sin_cos (mem[p + 5].cint);
	  print_char (123);
	  print_scaled (n_cos);
	  print_char (44);
	  print_scaled (n_sin);
	} 
	print_char (125);
      } 
      break;
      default: 
      print (259);
      break;
    } 
    if (mem[q].hhfield.b0 <= 1) 
    print (519);
    else if ((mem[p + 6].cint != 65536L) || (mem[q + 4].cint != 
    65536L)) 
    {
      print (522);
      if (mem[p + 6].cint < 0) 
      print (464);
      print_scaled (abs (mem[p + 6].cint));
      if (mem[p + 6].cint != mem[q + 4].cint) 
      {
	print (523);
	if (mem[q + 4].cint < 0) 
	print (464);
	print_scaled (abs (mem[q + 4].cint));
      } 
    } 
    done1:;
    p = q;
    if ((p != h) || (mem[h].hhfield.b0 != 0)) 
    {
      print_nl (520);
      if (mem[p].hhfield.b0 == 2) 
      {
	n_sin_cos (mem[p + 3].cint);
	print_char (123);
	print_scaled (n_cos);
	print_char (44);
	print_scaled (n_sin);
	print_char (125);
      } 
      else if (mem[p].hhfield.b0 == 3) 
      {
	print (521);
	print_scaled (mem[p + 3].cint);
	print_char (125);
      } 
    } 
  } while (!(p == h));
  if (mem[h].hhfield.b0 != 0) 
  print (385);
  done: end_diagnostic (true);
} 
void 
print_weight (halfword q , integer xoff) 
{
  integer w, m;
  integer d;
  d = mem[q].hhfield.lhfield;
  w = d % 8;
  m = (d / 8) - mem[cur_edges + 3].hhfield.lhfield;
  if (file_offset > maxprintline - 9) 
  print_nl (32);
  else print_char (32);
  print_int (m + xoff);
  while (w > 4) {
      
    print_char (43);
    decr (w);
  } 
  while (w < 4) {
      
    print_char (45);
    incr (w);
  } 
} 
void 
print_edges (str_number s , boolean nuline , integer xoff , integer yoff) 
{
  halfword p, q, r;
  integer n;
  print_diagnostic (532 , s , nuline);
  p = mem[cur_edges].hhfield.lhfield;
  n = mem[cur_edges + 1].hhfield.v.RH - 4096;
  while (p != cur_edges) {
      
    q = mem[p + 1].hhfield.lhfield;
    r = mem[p + 1].hhfield.v.RH;
    if ((q > 1) || (r != memtop)) 
    {
      print_nl (533);
      print_int (n + yoff);
      print_char (58);
      while (q > 1) {
	  
	print_weight (q , xoff);
	q = mem[q].hhfield.v.RH;
      } 
      print (534);
      while (r != memtop) {
	  
	print_weight (r , xoff);
	r = mem[r].hhfield.v.RH;
      } 
    } 
    p = mem[p].hhfield.lhfield;
    decr (n);
  } 
  end_diagnostic (true);
} 
void 
unskew (scaled x , scaled y , small_number octant) 
{
  switch (octant) 
  {case 1 : 
    {
      cur_x = x + y;
      cur_y = y;
    } 
    break;
  case 5 : 
    {
      cur_x = y;
      cur_y = x + y;
    } 
    break;
  case 6 : 
    {
      cur_x = - (integer) y;
      cur_y = x + y;
    } 
    break;
  case 2 : 
    {
      cur_x = - (integer) x - y;
      cur_y = y;
    } 
    break;
  case 4 : 
    {
      cur_x = - (integer) x - y;
      cur_y = - (integer) y;
    } 
    break;
  case 8 : 
    {
      cur_x = - (integer) y;
      cur_y = - (integer) x - y;
    } 
    break;
  case 7 : 
    {
      cur_x = y;
      cur_y = - (integer) x - y;
    } 
    break;
  case 3 : 
    {
      cur_x = x + y;
      cur_y = - (integer) y;
    } 
    break;
  } 
} 
void 
print_pen (halfword p , str_number s , boolean nuline) 
{
  boolean nothingprinted;
  unsigned char k;
  halfword h;
  integer m, n;
  halfword w, ww;
  print_diagnostic (569 , s , nuline);
  nothingprinted = true;
  print_ln ();
  {register integer for_end; k = 1;for_end = 8; if (k <= for_end) do 
    {
      octant = octant_code[k];
      h = p + octant;
      n = mem[h].hhfield.lhfield;
      w = mem[h].hhfield.v.RH;
      if (!odd (k)) 
      w = mem[w].hhfield.lhfield;
      {register integer for_end; m = 1;for_end = n + 1; if (m <= for_end) 
      do 
	{
	  if (odd (k)) 
	  ww = mem[w].hhfield.v.RH;
	  else ww = mem[w].hhfield.lhfield;
	  if ((mem[ww + 1].cint != mem[w + 1].cint) || (mem[ww + 
	  2].cint != mem[w + 2].cint)) 
	  {
	    if (nothingprinted) 
	    nothingprinted = false;
	    else print_nl (571);
	    unskew (mem[ww + 1].cint , mem[ww + 2].cint , octant);
	    print_two (cur_x , cur_y);
	  } 
	  w = ww;
	} 
      while (m++ < for_end);} 
    } 
  while (k++ < for_end);} 
  if (nothingprinted) 
  {
    w = mem[p + 1].hhfield.v.RH;
    print_two (mem[w + 1].cint + mem[w + 2].cint , mem[w + 2].cint 
 );
  } 
  print_nl (570);
  end_diagnostic (true);
} 
void 
print_dependency (halfword p , small_number t) 
{
  /* 10 */ integer v;
  halfword pp, q;
  pp = p;
  while (true) {
      
    v = abs (mem[p + 1].cint);
    q = mem[p].hhfield.lhfield;
    if (q == 0) 
    {
      if ((v != 0) || (p == pp)) 
      {
	if (mem[p + 1].cint > 0) {
	    
	  if (p != pp) 
	  print_char (43);
	} 
	print_scaled (mem[p + 1].cint);
      } 
      goto lab10;
    } 
    if (mem[p + 1].cint < 0) 
    print_char (45);
    else if (p != pp) 
    print_char (43);
    if (t == 17) 
    v = roundfraction (v);
    if (v != 65536L) 
    print_scaled (v);
    if (mem[q].hhfield.b0 != 19) 
    confusion (589);
    print_variable_name (q);
    v = mem[q + 1].cint % 64;
    while (v > 0) {
	
      print (590);
      v = v - 2;
    } 
    p = mem[p].hhfield.v.RH;
  } 
  lab10:;
} 
void 
print_dp (small_number t , halfword p , small_number verbosity) 
{
  halfword q;
  q = mem[p].hhfield.v.RH;
  if ((mem[q].hhfield.lhfield == 0) || (verbosity > 0)) 
  print_dependency (p , t);
  else print (764);
} 
halfword 
stash_cur_exp (void) 
{
  register halfword Result; halfword p;
  switch (cur_type) 
  {case 3 : 
  case 5 : 
  case 7 : 
  case 12 : 
  case 10 : 
  case 13 : 
  case 14 : 
  case 17 : 
  case 18 : 
  case 19 : 
    p = cur_exp;
    break;
    default: 
    {
      p = get_node (2);
      mem[p].hhfield.b1 = 11;
      mem[p].hhfield.b0 = cur_type;
      mem[p + 1].cint = cur_exp;
    } 
    break;
  } 
  cur_type = 1;
  mem[p].hhfield.v.RH = 1;
  Result = p;
  return Result;
} 
void 
unstash_cur_exp (halfword p) 
{
  cur_type = mem[p].hhfield.b0;
  switch (cur_type) 
  {case 3 : 
  case 5 : 
  case 7 : 
  case 12 : 
  case 10 : 
  case 13 : 
  case 14 : 
  case 17 : 
  case 18 : 
  case 19 : 
    cur_exp = p;
    break;
    default: 
    {
      cur_exp = mem[p + 1].cint;
      free_node (p , 2);
    } 
    break;
  } 
} 
void 
print_exp (halfword p , small_number verbosity) 
{
  boolean restorecur_exp;
  small_number t;
  integer v;
  halfword q;
  if (p != 0) 
  restorecur_exp = false;
  else {
      
    p = stash_cur_exp ();
    restorecur_exp = true;
  } 
  t = mem[p].hhfield.b0;
  if (t < 17) 
  v = mem[p + 1].cint;
  else if (t < 19) 
  v = mem[p + 1].hhfield.v.RH;
  switch (t) 
  {case 1 : 
    print (323);
    break;
  case 2 : 
    if (v == 30) 
    print (347);
    else print (348);
    break;
  case 3 : 
  case 5 : 
  case 7 : 
  case 12 : 
  case 10 : 
  case 15 : 
    {
      print_type (t);
      if (v != 0) 
      {
	print_char (32);
	while ((mem[v].hhfield.b1 == 11) && (v != p)) v = mem[v + 
	1].cint;
	print_variable_name (v);
      } 
    } 
    break;
  case 4 : 
    {
      print_char (34);
      slow_print (v);
      print_char (34);
    } 
    break;
  case 6 : 
  case 8 : 
  case 9 : 
  case 11 : 
    if (verbosity <= 1) 
    print_type (t);
    else {
	
      if (selector == 3) {
	  
	if (internal[13]<= 0) 
	{
	  selector = 1;
	  print_type (t);
	  print (762);
	  selector = 3;
	} 
      } 
      switch (t) 
      {case 6 : 
	print_pen (v , 261 , false);
	break;
      case 8 : 
	print_path (v , 763 , false);
	break;
      case 9 : 
	print_path (v , 261 , false);
	break;
      case 11 : 
	{
	  cur_edges = v;
	  print_edges (261 , false , 0 , 0);
	} 
	break;
      } 
    } 
    break;
  case 13 : 
  case 14 : 
    if (v == 0) 
    print_type (t);
    else {
	
      print_char (40);
      q = v + big_node_size[t];
      do {
	  if (mem[v].hhfield.b0 == 16) 
	print_scaled (mem[v + 1].cint);
	else if (mem[v].hhfield.b0 == 19) 
	print_variable_name (v);
	else print_dp (mem[v].hhfield.b0 , mem[v + 1].hhfield.v.RH , 
	verbosity);
	v = v + 2;
	if (v != q) 
	print_char (44);
      } while (!(v == q));
      print_char (41);
    } 
    break;
  case 16 : 
    print_scaled (v);
    break;
  case 17 : 
  case 18 : 
    print_dp (t , v , verbosity);
    break;
  case 19 : 
    print_variable_name (p);
    break;
    default: 
    confusion (761);
    break;
  } 
  if (restorecur_exp) 
  unstash_cur_exp (p);
} 
void 
disp_err (halfword p , str_number s) 
{
  if (interaction == 3) 
;
  print_nl (765);
  print_exp (p , 1);
  if (s != 261) 
  {
    print_nl (263);
    print (s);
  } 
} 
halfword 
p_plus_fq (halfword p , integer f , halfword q , small_number t , small_number 
tt) 
{
  /* 30 */ register halfword Result; halfword pp, qq;
  halfword r, s;
  integer threshold;
  integer v;
  if (t == 17) 
  threshold = 2685;
  else threshold = 8;
  r = memtop - 1;
  pp = mem[p].hhfield.lhfield;
  qq = mem[q].hhfield.lhfield;
  while (true) if (pp == qq) {
      
    if (pp == 0) 
    goto done;
    else {
	
      if (tt == 17) 
      v = mem[p + 1].cint + takefraction (f , mem[q + 1].cint);
      else v = mem[p + 1].cint + takescaled (f , mem[q + 1].cint);
      mem[p + 1].cint = v;
      s = p;
      p = mem[p].hhfield.v.RH;
      if (abs (v) < threshold) 
      free_node (s , 2);
      else {
	  
	if (abs (v) >= 626349397L) {
	    
	  if (watch_coefs) 
	  {
	    mem[qq].hhfield.b0 = 0;
	    fix_needed = true;
	  } 
	} 
	mem[r].hhfield.v.RH = s;
	r = s;
      } 
      pp = mem[p].hhfield.lhfield;
      q = mem[q].hhfield.v.RH;
      qq = mem[q].hhfield.lhfield;
    } 
  } 
  else if (mem[pp + 1].cint < mem[qq + 1].cint) 
  {
    if (tt == 17) 
    v = takefraction (f , mem[q + 1].cint);
    else v = takescaled (f , mem[q + 1].cint);
    if (abs (v) > halfp (threshold)) 
    {
      s = get_node (2);
      mem[s].hhfield.lhfield = qq;
      mem[s + 1].cint = v;
      if (abs (v) >= 626349397L) {
	  
	if (watch_coefs) 
	{
	  mem[qq].hhfield.b0 = 0;
	  fix_needed = true;
	} 
      } 
      mem[r].hhfield.v.RH = s;
      r = s;
    } 
    q = mem[q].hhfield.v.RH;
    qq = mem[q].hhfield.lhfield;
  } 
  else {
      
    mem[r].hhfield.v.RH = p;
    r = p;
    p = mem[p].hhfield.v.RH;
    pp = mem[p].hhfield.lhfield;
  } 
  done: if (t == 17) 
  mem[p + 1].cint = slow_add (mem[p + 1].cint , takefraction (mem[q 
  + 1].cint , f));
  else mem[p + 1].cint = slow_add (mem[p + 1].cint , takescaled (mem 
[q + 1].cint , f));
  mem[r].hhfield.v.RH = p;
  dep_final = p;
  Result = mem[memtop - 1].hhfield.v.RH;
  return Result;
} 
halfword 
p_over_v (halfword p , scaled v , small_number t0 , small_number t1) 
{
  register halfword Result; halfword r, s;
  integer w;
  integer threshold;
  boolean scalingdown;
  if (t0 != t1) 
  scalingdown = true;
  else scalingdown = false;
  if (t1 == 17) 
  threshold = 1342;
  else threshold = 4;
  r = memtop - 1;
  while (mem[p].hhfield.lhfield != 0) {
      
    if (scalingdown) {
	
      if (abs (v) < 524288L) 
      w = makescaled (mem[p + 1].cint , v * 4096);
      else w = makescaled (roundfraction (mem[p + 1].cint) , v);
    } 
    else w = makescaled (mem[p + 1].cint , v);
    if (abs (w) <= threshold) 
    {
      s = mem[p].hhfield.v.RH;
      free_node (p , 2);
      p = s;
    } 
    else {
	
      if (abs (w) >= 626349397L) 
      {
	fix_needed = true;
	mem[mem[p].hhfield.lhfield].hhfield.b0 = 0;
      } 
      mem[r].hhfield.v.RH = p;
      r = p;
      mem[p + 1].cint = w;
      p = mem[p].hhfield.v.RH;
    } 
  } 
  mem[r].hhfield.v.RH = p;
  mem[p + 1].cint = makescaled (mem[p + 1].cint , v);
  Result = mem[memtop - 1].hhfield.v.RH;
  return Result;
} 
void 
val_too_big (scaled x) 
{
  if (internal[40] > 0) 
  {
    {
      if (interaction == 3) 
;
      if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[in_open]);
	print (58);
	print_int (line);
	print (262);
	print (591);
      } 
      else {
	  
	print_nl (263);
	print (591);
      } 
    } 
    print_scaled (x);
    print_char (41);
    {
      help_ptr = 4;
      help_line[3] = 592;
      help_line[2] = 593;
      help_line[1] = 594;
      help_line[0] = 595;
    } 
    error ();
  } 
} 
void 
make_known (halfword p , halfword q) 
{
  unsigned char t;
  mem[mem[q].hhfield.v.RH + 1].hhfield.lhfield = mem[p + 1]
  .hhfield.lhfield;
  mem[mem[p + 1].hhfield.lhfield].hhfield.v.RH = mem[q].hhfield 
.v.RH;
  t = mem[p].hhfield.b0;
  mem[p].hhfield.b0 = 16;
  mem[p + 1].cint = mem[q + 1].cint;
  free_node (q , 2);
  if (abs (mem[p + 1].cint) >= 268435456L) 
  val_too_big (mem[p + 1].cint);
  if (internal[2] > 0) {
      
    if (interesting (p)) 
    {
      begin_diagnostic ();
      print_nl (596);
      print_variable_name (p);
      print_char (61);
      print_scaled (mem[p + 1].cint);
      end_diagnostic (false);
    } 
  } 
  if (cur_exp == p) {
      
    if (cur_type == t) 
    {
      cur_type = 16;
      cur_exp = mem[p + 1].cint;
      free_node (p , 2);
    } 
  } 
} 
void 
fix_dependencies (void) 
{
  /* 30 */ halfword p, q, r, s, t;
  halfword x;
  r = mem[13].hhfield.v.RH;
  s = 0;
  while (r != 13) {
      
    t = r;
    r = t + 1;
    while (true) {
	
      q = mem[r].hhfield.v.RH;
      x = mem[q].hhfield.lhfield;
      if (x == 0) 
      goto done;
      if (mem[x].hhfield.b0 <= 1) 
      {
	if (mem[x].hhfield.b0 < 1) 
	{
	  p = get_avail ();
	  mem[p].hhfield.v.RH = s;
	  s = p;
	  mem[s].hhfield.lhfield = x;
	  mem[x].hhfield.b0 = 1;
	} 
	mem[q + 1].cint = mem[q + 1].cint / 4;
	if (mem[q + 1].cint == 0) 
	{
	  mem[r].hhfield.v.RH = mem[q].hhfield.v.RH;
	  free_node (q , 2);
	  q = r;
	} 
      } 
      r = q;
    } 
    done:;
    r = mem[q].hhfield.v.RH;
    if (q == mem[t + 1].hhfield.v.RH) 
    make_known (t , q);
  } 
  while (s != 0) {
      
    p = mem[s].hhfield.v.RH;
    x = mem[s].hhfield.lhfield;
    {
      mem[s].hhfield.v.RH = avail;
      avail = s;
	;
#ifdef STAT
      decr (dyn_used);
#endif /* STAT */
    } 
    s = p;
    mem[x].hhfield.b0 = 19;
    mem[x + 1].cint = mem[x + 1].cint + 2;
  } 
  fix_needed = false;
} 
void 
toss_knot_list (halfword p) 
{
  halfword q;
  halfword r;
  q = p;
  do {
      r = mem[q].hhfield.v.RH;
    free_node (q , 7);
    q = r;
  } while (!(q == p));
} 
void 
toss_edges (halfword h) 
{
  halfword p, q;
  q = mem[h].hhfield.v.RH;
  while (q != h) {
      
    flush_list (mem[q + 1].hhfield.v.RH);
    if (mem[q + 1].hhfield.lhfield > 1) 
    flush_list (mem[q + 1].hhfield.lhfield);
    p = q;
    q = mem[q].hhfield.v.RH;
    free_node (p , 2);
  } 
  free_node (h , 6);
} 
void 
toss_pen (halfword p) 
{
  unsigned char k;
  halfword w, ww;
  if (p != 3) 
  {
    {register integer for_end; k = 1;for_end = 8; if (k <= for_end) do 
      {
	w = mem[p + k].hhfield.v.RH;
	do {
	    ww = mem[w].hhfield.v.RH;
	  free_node (w , 3);
	  w = ww;
	} while (!(w == mem[p + k].hhfield.v.RH));
      } 
    while (k++ < for_end);} 
    free_node (p , 10);
  } 
} 
void 
ring_delete (halfword p) 
{
  halfword q;
  q = mem[p + 1].cint;
  if (q != 0) {
      
    if (q != p) 
    {
      while (mem[q + 1].cint != p) q = mem[q + 1].cint;
      mem[q + 1].cint = mem[p + 1].cint;
    } 
  } 
} 
void 
recycle_value (halfword p) 
{
  /* 30 */ small_number t;
  integer v;
  integer vv;
  halfword q, r, s, pp;
  t = mem[p].hhfield.b0;
  if (t < 17) 
  v = mem[p + 1].cint;
  switch (t) 
  {case 0 : 
  case 1 : 
  case 2 : 
  case 16 : 
  case 15 : 
;
    break;
  case 3 : 
  case 5 : 
  case 7 : 
  case 12 : 
  case 10 : 
    ring_delete (p);
    break;
  case 4 : 
    {
      if (str_ref[v]< 127) {
	  
	if (str_ref[v] > 1) 
	decr (str_ref[v]);
	else flush_string (v);
      } 
    } 
    break;
  case 6 : 
    if (mem[v].hhfield.lhfield == 0) 
    toss_pen (v);
    else decr (mem[v].hhfield.lhfield);
    break;
  case 9 : 
  case 8 : 
    toss_knot_list (v);
    break;
  case 11 : 
    toss_edges (v);
    break;
  case 14 : 
  case 13 : 
    if (v != 0) 
    {
      q = v + big_node_size[t];
      do {
	  q = q - 2;
	recycle_value (q);
      } while (!(q == v));
      free_node (v , big_node_size[t]);
    } 
    break;
  case 17 : 
  case 18 : 
    {
      q = mem[p + 1].hhfield.v.RH;
      while (mem[q].hhfield.lhfield != 0) q = mem[q].hhfield.v.RH 
;
      mem[mem[p + 1].hhfield.lhfield].hhfield.v.RH = mem[q]
      .hhfield.v.RH;
      mem[mem[q].hhfield.v.RH + 1].hhfield.lhfield = mem[p + 1]
      .hhfield.lhfield;
      mem[q].hhfield.v.RH = 0;
      flush_node_list (mem[p + 1].hhfield.v.RH);
    } 
    break;
  case 19 : 
    {
      max_c[17] = 0;
      max_c[18] = 0;
      max_link[17] = 0;
      max_link[18] = 0;
      q = mem[13].hhfield.v.RH;
      while (q != 13) {
	  
	s = q + 1;
	while (true) {
	    
	  r = mem[s].hhfield.v.RH;
	  if (mem[r].hhfield.lhfield == 0) 
	  goto done;
	  if (mem[r].hhfield.lhfield != p) 
	  s = r;
	  else {
	      
	    t = mem[q].hhfield.b0;
	    mem[s].hhfield.v.RH = mem[r].hhfield.v.RH;
	    mem[r].hhfield.lhfield = q;
	    if (abs (mem[r + 1].cint) > max_c[t]) 
	    {
	      if (max_c[t] > 0) 
	      {
		mem[max_ptr[t]].hhfield.v.RH = max_link[t];
		max_link[t] = max_ptr[t];
	      } 
	      max_c[t] = abs (mem[r + 1].cint);
	      max_ptr[t] = r;
	    } 
	    else {
		
	      mem[r].hhfield.v.RH = max_link[t];
	      max_link[t] = r;
	    } 
	  } 
	} 
	done: q = mem[r].hhfield.v.RH;
      } 
      if ((max_c[17] > 0) || (max_c[18] > 0)) 
      {
	if ((max_c[17]/ 4096 >= max_c[18])) 
	t = 17;
	else t = 18;
	s = max_ptr[t];
	pp = mem[s].hhfield.lhfield;
	v = mem[s + 1].cint;
	if (t == 17) 
	mem[s + 1].cint = -268435456L;
	else mem[s + 1].cint = -65536L;
	r = mem[pp + 1].hhfield.v.RH;
	mem[s].hhfield.v.RH = r;
	while (mem[r].hhfield.lhfield != 0) r = mem[r].hhfield 
	.v.RH;
	q = mem[r].hhfield.v.RH;
	mem[r].hhfield.v.RH = 0;
	mem[q + 1].hhfield.lhfield = mem[pp + 1].hhfield.lhfield;
	mem[mem[pp + 1].hhfield.lhfield].hhfield.v.RH = q;
	{
	  if (serial_no > 2147483583L) 
	  overflow (588 , serial_no / 64);
	  mem[pp].hhfield.b0 = 19;
	  serial_no = serial_no + 64;
	  mem[pp + 1].cint = serial_no;
	} 
	if (cur_exp == pp) {
	    
	  if (cur_type == t) 
	  cur_type = 19;
	} 
	if (internal[2] > 0) {
	    
	  if (interesting (p)) 
	  {
	    begin_diagnostic ();
	    print_nl (767);
	    if (v > 0) 
	    print_char (45);
	    if (t == 17) 
	    vv = roundfraction (max_c[17]);
	    else vv = max_c[18];
	    if (vv != 65536L) 
	    print_scaled (vv);
	    print_variable_name (p);
	    while (mem[p + 1].cint % 64 > 0) {
		
	      print (590);
	      mem[p + 1].cint = mem[p + 1].cint - 2;
	    } 
	    if (t == 17) 
	    print_char (61);
	    else print (768);
	    print_dependency (s , t);
	    end_diagnostic (false);
	  } 
	} 
	t = 35 - t;
	if (max_c[t] > 0) 
	{
	  mem[max_ptr[t]].hhfield.v.RH = max_link[t];
	  max_link[t] = max_ptr[t];
	} 
	if (t != 17) 
	{register integer for_end; t = 17;for_end = 18; if (t <= for_end) 
	do 
	  {
	    r = max_link[t];
	    while (r != 0) {
		
	      q = mem[r].hhfield.lhfield;
	      mem[q + 1].hhfield.v.RH = p_plus_fq (mem[q + 1].hhfield 
	    .v.RH , makefraction (mem[r + 1].cint , - (integer) v) , s 
	      , t , 17);
	      if (mem[q + 1].hhfield.v.RH == dep_final) 
	      make_known (q , dep_final);
	      q = r;
	      r = mem[r].hhfield.v.RH;
	      free_node (q , 2);
	    } 
	  } 
	while (t++ < for_end);} 
	else {
	    register integer for_end; t = 17;for_end = 18; if (t <= 
	for_end) do 
	  {
	    r = max_link[t];
	    while (r != 0) {
		
	      q = mem[r].hhfield.lhfield;
	      if (t == 17) 
	      {
		if (cur_exp == q) {
		    
		  if (cur_type == 17) 
		  cur_type = 18;
		} 
		mem[q + 1].hhfield.v.RH = p_over_v (mem[q + 1].hhfield 
		.v.RH , 65536L , 17 , 18);
		mem[q].hhfield.b0 = 18;
		mem[r + 1].cint = roundfraction (mem[r + 1].cint);
	      } 
	      mem[q + 1].hhfield.v.RH = p_plus_fq (mem[q + 1].hhfield 
	    .v.RH , makescaled (mem[r + 1].cint , - (integer) v) , s , 
	      18 , 18);
	      if (mem[q + 1].hhfield.v.RH == dep_final) 
	      make_known (q , dep_final);
	      q = r;
	      r = mem[r].hhfield.v.RH;
	      free_node (q , 2);
	    } 
	  } 
	while (t++ < for_end);} 
	flush_node_list (s);
	if (fix_needed) 
	fix_dependencies ();
	{
	  if (arith_error) 
	  clear_arith ();
	} 
      } 
    } 
    break;
  case 20 : 
  case 21 : 
    confusion (766);
    break;
  case 22 : 
  case 23 : 
    delete_mac_ref (mem[p + 1].cint);
    break;
  } 
  mem[p].hhfield.b0 = 0;
} 
void 
flush_cur_exp (scaled v) 
{
  switch (cur_type) 
  {case 3 : 
  case 5 : 
  case 7 : 
  case 12 : 
  case 10 : 
  case 13 : 
  case 14 : 
  case 17 : 
  case 18 : 
  case 19 : 
    {
      recycle_value (cur_exp);
      free_node (cur_exp , 2);
    } 
    break;
  case 6 : 
    if (mem[cur_exp].hhfield.lhfield == 0) 
    toss_pen (cur_exp);
    else decr (mem[cur_exp].hhfield.lhfield);
    break;
  case 4 : 
    {
      if (str_ref[cur_exp]< 127) {
	  
	if (str_ref[cur_exp] > 1) 
	decr (str_ref[cur_exp]);
	else flush_string (cur_exp);
      } 
    } 
    break;
  case 8 : 
  case 9 : 
    toss_knot_list (cur_exp);
    break;
  case 11 : 
    toss_edges (cur_exp);
    break;
    default: 
;
    break;
  } 
  cur_type = 16;
  cur_exp = v;
} 
void 
flush_error (scaled v) 
{
  error ();
  flush_cur_exp (v);
} 
void 
put_get_error (void) 
{
  backerror ();
  getxnext ();
} 
void 
zput_get_flush_error (scaled v) 
{
  put_get_error ();
  flush_cur_exp (v);
} 
void 
zflushbelowvariable (halfword p) 
{
  halfword q, r;
  if (mem[p].hhfield.b0 != 21) 
  recycle_value (p);
  else {
      
    q = mem[p + 1].hhfield.v.RH;
    while (mem[q].hhfield.b1 == 3) {
	
      flushbelowvariable (q);
      r = q;
      q = mem[q].hhfield.v.RH;
      free_node (r , 3);
    } 
    r = mem[p + 1].hhfield.lhfield;
    q = mem[r].hhfield.v.RH;
    recycle_value (r);
    if (mem[p].hhfield.b1 <= 1) 
    free_node (r , 2);
    else free_node (r , 3);
    do {
	flushbelowvariable (q);
      r = q;
      q = mem[q].hhfield.v.RH;
      free_node (r , 3);
    } while (!(q == 17));
    mem[p].hhfield.b0 = 0;
  } 
} 
void 
zflushvariable (halfword p , halfword t , boolean discardsuffixes) 
{
  /* 10 */ halfword q, r;
  halfword n;
  while (t != 0) {
      
    if (mem[p].hhfield.b0 != 21) 
    goto lab10;
    n = mem[t].hhfield.lhfield;
    t = mem[t].hhfield.v.RH;
    if (n == 0) 
    {
      r = p + 1;
      q = mem[r].hhfield.v.RH;
      while (mem[q].hhfield.b1 == 3) {
	  
	flushvariable (q , t , discardsuffixes);
	if (t == 0) {
	    
	  if (mem[q].hhfield.b0 == 21) 
	  r = q;
	  else {
	      
	    mem[r].hhfield.v.RH = mem[q].hhfield.v.RH;
	    free_node (q , 3);
	  } 
	} 
	else r = q;
	q = mem[r].hhfield.v.RH;
      } 
    } 
    p = mem[p + 1].hhfield.lhfield;
    do {
	r = p;
      p = mem[p].hhfield.v.RH;
    } while (!(mem[p + 2].hhfield.lhfield >= n));
    if (mem[p + 2].hhfield.lhfield != n) 
    goto lab10;
  } 
  if (discardsuffixes) 
  flushbelowvariable (p);
  else {
      
    if (mem[p].hhfield.b0 == 21) 
    p = mem[p + 1].hhfield.lhfield;
    recycle_value (p);
  } 
  lab10:;
} 
small_number 
zundtype (halfword p) 
{
  register small_number Result; switch (mem[p].hhfield.b0) 
  {case 0 : 
  case 1 : 
    Result = 0;
    break;
  case 2 : 
  case 3 : 
    Result = 3;
    break;
  case 4 : 
  case 5 : 
    Result = 5;
    break;
  case 6 : 
  case 7 : 
  case 8 : 
    Result = 7;
    break;
  case 9 : 
  case 10 : 
    Result = 10;
    break;
  case 11 : 
  case 12 : 
    Result = 12;
    break;
  case 13 : 
  case 14 : 
  case 15 : 
    Result = mem[p].hhfield.b0;
    break;
  case 16 : 
  case 17 : 
  case 18 : 
  case 19 : 
    Result = 15;
    break;
  } 
  return Result;
} 
void 
zclearsymbol (halfword p , boolean saving) 
{
  halfword q;
  q = eqtb[p].v.RH;
  switch (eqtb[p].lhfield % 86) 
  {case 10 : 
  case 53 : 
  case 44 : 
  case 49 : 
    if (!saving) 
    delete_mac_ref (q);
    break;
  case 41 : 
    if (q != 0) {
	
      if (saving) 
      mem[q].hhfield.b1 = 1;
      else {
	  
	flushbelowvariable (q);
	free_node (q , 2);
      } 
    } 
    break;
    default: 
;
    break;
  } 
  eqtb[p] = eqtb[9769];
} 
void 
zsavevariable (halfword q) 
{
  halfword p;
  if (save_ptr != 0) 
  {
    p = get_node (2);
    mem[p].hhfield.lhfield = q;
    mem[p].hhfield.v.RH = save_ptr;
    mem[p + 1].hhfield = eqtb[q];
    save_ptr = p;
  } 
  clearsymbol (q , (save_ptr != 0));
} 
void 
zsaveinternal (halfword q) 
{
  halfword p;
  if (save_ptr != 0) 
  {
    p = get_node (2);
    mem[p].hhfield.lhfield = 9769 + q;
    mem[p].hhfield.v.RH = save_ptr;
    mem[p + 1].cint = internal[q];
    save_ptr = p;
  } 
} 
void 
unsave (void) 
{
  halfword q;
  halfword p;
  while (mem[save_ptr].hhfield.lhfield != 0) {
      
    q = mem[save_ptr].hhfield.lhfield;
    if (q > 9769) 
    {
      if (internal[8] > 0) 
      {
	begin_diagnostic ();
	print_nl (516);
	slow_print (int_name[q - (9769)]);
	print_char (61);
	print_scaled (mem[save_ptr + 1].cint);
	print_char (125);
	end_diagnostic (false);
      } 
      internal[q - (9769)] = mem[save_ptr + 1].cint;
    } 
    else {
	
      if (internal[8] > 0) 
      {
	begin_diagnostic ();
	print_nl (516);
	slow_print (hash[q].v.RH);
	print_char (125);
	end_diagnostic (false);
      } 
      clearsymbol (q , false);
      eqtb[q] = mem[save_ptr + 1].hhfield;
      if (eqtb[q].lhfield % 86 == 41) 
      {
	p = eqtb[q].v.RH;
	if (p != 0) 
	mem[p].hhfield.b1 = 0;
      } 
    } 
    p = mem[save_ptr].hhfield.v.RH;
    free_node (save_ptr , 2);
    save_ptr = p;
  } 
  p = mem[save_ptr].hhfield.v.RH;
  {
    mem[save_ptr].hhfield.v.RH = avail;
    avail = save_ptr;
	;
#ifdef STAT
    decr (dyn_used);
#endif /* STAT */
  } 
  save_ptr = p;
} 
halfword 
zcopyknot (halfword p) 
{
  register halfword Result; halfword q;
  unsigned char k;
  q = get_node (7);
  {register integer for_end; k = 0;for_end = 6; if (k <= for_end) do 
    mem[q + k] = mem[p + k];
  while (k++ < for_end);} 
  Result = q;
  return Result;
} 
halfword 
zcopypath (halfword p) 
{
  /* 10 */ register halfword Result; halfword q, pp, qq;
  q = get_node (7);
  qq = q;
  pp = p;
  while (true) {
      
    mem[qq].hhfield.b0 = mem[pp].hhfield.b0;
    mem[qq].hhfield.b1 = mem[pp].hhfield.b1;
    mem[qq + 1].cint = mem[pp + 1].cint;
    mem[qq + 2].cint = mem[pp + 2].cint;
    mem[qq + 3].cint = mem[pp + 3].cint;
    mem[qq + 4].cint = mem[pp + 4].cint;
    mem[qq + 5].cint = mem[pp + 5].cint;
    mem[qq + 6].cint = mem[pp + 6].cint;
    if (mem[pp].hhfield.v.RH == p) 
    {
      mem[qq].hhfield.v.RH = q;
      Result = q;
      goto lab10;
    } 
    mem[qq].hhfield.v.RH = get_node (7);
    qq = mem[qq].hhfield.v.RH;
    pp = mem[pp].hhfield.v.RH;
  } 
  lab10:;
  return Result;
} 
halfword 
zhtapypoc (halfword p) 
{
  /* 10 */ register halfword Result; halfword q, pp, qq, rr;
  q = get_node (7);
  qq = q;
  pp = p;
  while (true) {
      
    mem[qq].hhfield.b1 = mem[pp].hhfield.b0;
    mem[qq].hhfield.b0 = mem[pp].hhfield.b1;
    mem[qq + 1].cint = mem[pp + 1].cint;
    mem[qq + 2].cint = mem[pp + 2].cint;
    mem[qq + 5].cint = mem[pp + 3].cint;
    mem[qq + 6].cint = mem[pp + 4].cint;
    mem[qq + 3].cint = mem[pp + 5].cint;
    mem[qq + 4].cint = mem[pp + 6].cint;
    if (mem[pp].hhfield.v.RH == p) 
    {
      mem[q].hhfield.v.RH = qq;
      path_tail = pp;
      Result = q;
      goto lab10;
    } 
    rr = get_node (7);
    mem[rr].hhfield.v.RH = qq;
    qq = rr;
    pp = mem[pp].hhfield.v.RH;
  } 
  lab10:;
  return Result;
} 
fraction 
curl_ratio (scaled gamma , scaled atension , scaled btension) 
{
  register fraction Result; fraction alpha, beta, num, denom, ff;
  alpha = makefraction (65536L , atension);
  beta = makefraction (65536L , btension);
  if (alpha <= beta) 
  {
    ff = makefraction (alpha , beta);
    ff = takefraction (ff , ff);
    gamma = takefraction (gamma , ff);
    beta = beta / 4096;
    denom = takefraction (gamma , alpha) + 196608L - beta;
    num = takefraction (gamma , 805306368L - alpha) + beta;
  } 
  else {
      
    ff = makefraction (beta , alpha);
    ff = takefraction (ff , ff);
    beta = takefraction (beta , ff) / 4096;
    denom = takefraction (gamma , alpha) + (ff / 1365) - beta;
    num = takefraction (gamma , 805306368L - alpha) + beta;
  } 
  if (num >= denom + denom + denom + denom) 
  Result = 1073741824L;
  else Result = makefraction (num , denom);
  return Result;
} 
void 
set_controls (halfword p , halfword q , integer k) 
{
  fraction rr, ss;
  scaled lt, rt;
  fraction sine;
  lt = abs (mem[q + 4].cint);
  rt = abs (mem[p + 6].cint);
  rr = velocity (st , ct , sf , cf , rt);
  ss = velocity (sf , cf , st , ct , lt);
  if ((mem[p + 6].cint < 0) || (mem[q + 4].cint < 0)) {
      
    if (((st >= 0) && (sf >= 0)) || ((st <= 0) && (sf <= 0))) 
    {
      sine = takefraction (abs (st) , cf) + takefraction (abs (sf) , ct 
   );
      if (sine > 0) 
      {
	sine = takefraction (sine , 268500992L);
	if (mem[p + 6].cint < 0) {
	    
	  if (ab_vs_cd (abs (sf) , 268435456L , rr , sine) < 0) 
	  rr = makefraction (abs (sf) , sine);
	} 
	if (mem[q + 4].cint < 0) {
	    
	  if (ab_vs_cd (abs (st) , 268435456L , ss , sine) < 0) 
	  ss = makefraction (abs (st) , sine);
	} 
      } 
    } 
  } 
  mem[p + 5].cint = mem[p + 1].cint + takefraction (takefraction (
  delta_x[k], ct) - takefraction (delta_y[k], st) , rr);
  mem[p + 6].cint = mem[p + 2].cint + takefraction (takefraction (
  delta_y[k], ct) + takefraction (delta_x[k], st) , rr);
  mem[q + 3].cint = mem[q + 1].cint - takefraction (takefraction (
  delta_x[k], cf) + takefraction (delta_y[k], sf) , ss);
  mem[q + 4].cint = mem[q + 2].cint - takefraction (takefraction (
  delta_y[k], cf) - takefraction (delta_x[k], sf) , ss);
  mem[p].hhfield.b1 = 1;
  mem[q].hhfield.b0 = 1;
} 
void 
solve_choices (halfword p , halfword q , halfword n) 
{
  /* 40 10 */ integer k;
  halfword r, s, t;
  fraction aa, bb, cc, ff, acc;
  scaled dd, ee;
  scaled lt, rt;
  k = 0;
  s = p;
  while (true) {
      
    t = mem[s].hhfield.v.RH;
    if (k == 0) 
    switch (mem[s].hhfield.b1) 
    {case 2 : 
      if (mem[t].hhfield.b0 == 2) 
      {
	aa = n_arg (delta_x[0], delta_y[0]);
	n_sin_cos (mem[p + 5].cint - aa);
	ct = n_cos;
	st = n_sin;
	n_sin_cos (mem[q + 3].cint - aa);
	cf = n_cos;
	sf = - (integer) n_sin;
	set_controls (p , q , 0);
	goto lab10;
      } 
      else {
	  
	vv[0] = mem[s + 5].cint - n_arg (delta_x[0], delta_y[0]) 
	;
	if (abs (vv[0]) > 188743680L) {
	    
	  if (vv[0] > 0) 
	  vv[0] = vv[0] - 377487360L;
	  else vv[0] = vv[0]+ 377487360L;
	} 
	uu[0] = 0;
	ww[0] = 0;
      } 
      break;
    case 3 : 
      if (mem[t].hhfield.b0 == 3) 
      {
	mem[p].hhfield.b1 = 1;
	mem[q].hhfield.b0 = 1;
	lt = abs (mem[q + 4].cint);
	rt = abs (mem[p + 6].cint);
	if (rt == 65536L) 
	{
	  if (delta_x[0] >= 0) 
	  mem[p + 5].cint = mem[p + 1].cint + ((delta_x[0]+ 1) / 
	  3);
	  else mem[p + 5].cint = mem[p + 1].cint + ((delta_x[0] - 
	  1) / 3);
	  if (delta_y[0] >= 0) 
	  mem[p + 6].cint = mem[p + 2].cint + ((delta_y[0]+ 1) / 
	  3);
	  else mem[p + 6].cint = mem[p + 2].cint + ((delta_y[0] - 
	  1) / 3);
	} 
	else {
	    
	  ff = makefraction (65536L , 3 * rt);
	  mem[p + 5].cint = mem[p + 1].cint + takefraction (delta_x[
	  0], ff);
	  mem[p + 6].cint = mem[p + 2].cint + takefraction (delta_y[
	  0], ff);
	} 
	if (lt == 65536L) 
	{
	  if (delta_x[0] >= 0) 
	  mem[q + 3].cint = mem[q + 1].cint - ((delta_x[0]+ 1) / 
	  3);
	  else mem[q + 3].cint = mem[q + 1].cint - ((delta_x[0] - 
	  1) / 3);
	  if (delta_y[0] >= 0) 
	  mem[q + 4].cint = mem[q + 2].cint - ((delta_y[0]+ 1) / 
	  3);
	  else mem[q + 4].cint = mem[q + 2].cint - ((delta_y[0] - 
	  1) / 3);
	} 
	else {
	    
	  ff = makefraction (65536L , 3 * lt);
	  mem[q + 3].cint = mem[q + 1].cint - takefraction (delta_x[
	  0], ff);
	  mem[q + 4].cint = mem[q + 2].cint - takefraction (delta_y[
	  0], ff);
	} 
	goto lab10;
      } 
      else {
	  
	cc = mem[s + 5].cint;
	lt = abs (mem[t + 4].cint);
	rt = abs (mem[s + 6].cint);
	if ((rt == 65536L) && (lt == 65536L)) 
	uu[0] = makefraction (cc + cc + 65536L , cc + 131072L);
	else uu[0] = curl_ratio (cc , rt , lt);
	vv[0] = - (integer) takefraction (psi[1], uu[0]);
	ww[0] = 0;
      } 
      break;
    case 4 : 
      {
	uu[0] = 0;
	vv[0] = 0;
	ww[0] = 268435456L;
      } 
      break;
    } 
    else switch (mem[s].hhfield.b0) 
    {case 5 : 
    case 4 : 
      {
	if (abs (mem[r + 6].cint) == 65536L) 
	{
	  aa = 134217728L;
	  dd = 2 * delta[k];
	} 
	else {
	    
	  aa = makefraction (65536L , 3 * abs (mem[r + 6].cint) - 
	  65536L);
	  dd = takefraction (delta[k], 805306368L - makefraction (65536L 
	  , abs (mem[r + 6].cint)));
	} 
	if (abs (mem[t + 4].cint) == 65536L) 
	{
	  bb = 134217728L;
	  ee = 2 * delta[k - 1];
	} 
	else {
	    
	  bb = makefraction (65536L , 3 * abs (mem[t + 4].cint) - 
	  65536L);
	  ee = takefraction (delta[k - 1], 805306368L - makefraction (
	  65536L , abs (mem[t + 4].cint)));
	} 
	cc = 268435456L - takefraction (uu[k - 1], aa);
	dd = takefraction (dd , cc);
	lt = abs (mem[s + 4].cint);
	rt = abs (mem[s + 6].cint);
	if (lt != rt) {
	    
	  if (lt < rt) 
	  {
	    ff = makefraction (lt , rt);
	    ff = takefraction (ff , ff);
	    dd = takefraction (dd , ff);
	  } 
	  else {
	      
	    ff = makefraction (rt , lt);
	    ff = takefraction (ff , ff);
	    ee = takefraction (ee , ff);
	  } 
	} 
	ff = makefraction (ee , ee + dd);
	uu[k] = takefraction (ff , bb);
	acc = - (integer) takefraction (psi[k + 1], uu[k]);
	if (mem[r].hhfield.b1 == 3) 
	{
	  ww[k] = 0;
	  vv[k] = acc - takefraction (psi[1], 268435456L - ff);
	} 
	else {
	    
	  ff = makefraction (268435456L - ff , cc);
	  acc = acc - takefraction (psi[k], ff);
	  ff = takefraction (ff , aa);
	  vv[k] = acc - takefraction (vv[k - 1], ff);
	  if (ww[k - 1] == 0) 
	  ww[k] = 0;
	  else ww[k] = - (integer) takefraction (ww[k - 1], ff);
	} 
	if (mem[s].hhfield.b0 == 5) 
	{
	  aa = 0;
	  bb = 268435456L;
	  do {
	      decr (k);
	    if (k == 0) 
	    k = n;
	    aa = vv[k] - takefraction (aa , uu[k]);
	    bb = ww[k] - takefraction (bb , uu[k]);
	  } while (!(k == n));
	  aa = makefraction (aa , 268435456L - bb);
	  theta[n] = aa;
	  vv[0] = aa;
	  {register integer for_end; k = 1;for_end = n - 1; if (k <= 
	  for_end) do 
	    vv[k] = vv[k]+ takefraction (aa , ww[k]);
	  while (k++ < for_end);} 
	  goto found;
	} 
      } 
      break;
    case 3 : 
      {
	cc = mem[s + 3].cint;
	lt = abs (mem[s + 4].cint);
	rt = abs (mem[r + 6].cint);
	if ((rt == 65536L) && (lt == 65536L)) 
	ff = makefraction (cc + cc + 65536L , cc + 131072L);
	else ff = curl_ratio (cc , lt , rt);
	theta[n] = - (integer) makefraction (takefraction (vv[n - 1], 
	ff) , 268435456L - takefraction (ff , uu[n - 1]));
	goto found;
      } 
      break;
    case 2 : 
      {
	theta[n] = mem[s + 3].cint - n_arg (delta_x[n - 1], delta_y[
	n - 1]);
	if (abs (theta[n]) > 188743680L) {
	    
	  if (theta[n] > 0) 
	  theta[n] = theta[n] - 377487360L;
	  else theta[n] = theta[n]+ 377487360L;
	} 
	goto found;
      } 
      break;
    } 
    r = s;
    s = t;
    incr (k);
  } 
  found: {
      register integer for_end; k = n - 1;for_end = 0; if (k >= 
  for_end) do 
    theta[k] = vv[k] - takefraction (theta[k + 1], uu[k]);
  while (k-- > for_end);} 
  s = p;
  k = 0;
  do {
      t = mem[s].hhfield.v.RH;
    n_sin_cos (theta[k]);
    st = n_sin;
    ct = n_cos;
    n_sin_cos (- (integer) psi[k + 1] - theta[k + 1]);
    sf = n_sin;
    cf = n_cos;
    set_controls (s , t , k);
    incr (k);
    s = t;
  } while (!(k == n));
  lab10:;
} 
void 
make_choices (halfword knots) 
{
  /* 30 */ halfword h;
  halfword p, q;
  integer k, n;
  halfword s, t;
  scaled delx, dely;
  fraction sine, cosine;
  {
    if (arith_error) 
    clear_arith ();
  } 
  if (internal[4] > 0) 
  print_path (knots , 526 , true);
  p = knots;
  do {
      q = mem[p].hhfield.v.RH;
    if (mem[p + 1].cint == mem[q + 1].cint) {
	
      if (mem[p + 2].cint == mem[q + 2].cint) {
	  
	if (mem[p].hhfield.b1 > 1) 
	{
	  mem[p].hhfield.b1 = 1;
	  if (mem[p].hhfield.b0 == 4) 
	  {
	    mem[p].hhfield.b0 = 3;
	    mem[p + 3].cint = 65536L;
	  } 
	  mem[q].hhfield.b0 = 1;
	  if (mem[q].hhfield.b1 == 4) 
	  {
	    mem[q].hhfield.b1 = 3;
	    mem[q + 5].cint = 65536L;
	  } 
	  mem[p + 5].cint = mem[p + 1].cint;
	  mem[q + 3].cint = mem[p + 1].cint;
	  mem[p + 6].cint = mem[p + 2].cint;
	  mem[q + 4].cint = mem[p + 2].cint;
	} 
      } 
    } 
    p = q;
  } while (!(p == knots));
  h = knots;
  while (true) {
      
    if (mem[h].hhfield.b0 != 4) 
    goto done;
    if (mem[h].hhfield.b1 != 4) 
    goto done;
    h = mem[h].hhfield.v.RH;
    if (h == knots) 
    {
      mem[h].hhfield.b0 = 5;
      goto done;
    } 
  } 
  done:;
  p = h;
  do {
      q = mem[p].hhfield.v.RH;
    if (mem[p].hhfield.b1 >= 2) 
    {
      while ((mem[q].hhfield.b0 == 4) && (mem[q].hhfield.b1 == 4 
   )) q = mem[q].hhfield.v.RH;
      k = 0;
      s = p;
      n = pathsize;
      do {
	  t = mem[s].hhfield.v.RH;
	delta_x[k] = mem[t + 1].cint - mem[s + 1].cint;
	delta_y[k] = mem[t + 2].cint - mem[s + 2].cint;
	delta[k] = pyth_add (delta_x[k], delta_y[k]);
	if (k > 0) 
	{
	  sine = makefraction (delta_y[k - 1], delta[k - 1]);
	  cosine = makefraction (delta_x[k - 1], delta[k - 1]);
	  psi[k] = n_arg (takefraction (delta_x[k], cosine) + 
	  takefraction (delta_y[k], sine) , takefraction (delta_y[k], 
	  cosine) - takefraction (delta_x[k], sine));
	} 
	incr (k);
	s = t;
	if (k == pathsize) 
	overflow (531 , pathsize);
	if (s == q) 
	n = k;
      } while (!((k >= n) && (mem[s].hhfield.b0 != 5)));
      if (k == n) 
      psi[n] = 0;
      else psi[k] = psi[1];
      if (mem[q].hhfield.b0 == 4) 
      {
	delx = mem[q + 5].cint - mem[q + 1].cint;
	dely = mem[q + 6].cint - mem[q + 2].cint;
	if ((delx == 0) && (dely == 0)) 
	{
	  mem[q].hhfield.b0 = 3;
	  mem[q + 3].cint = 65536L;
	} 
	else {
	    
	  mem[q].hhfield.b0 = 2;
	  mem[q + 3].cint = n_arg (delx , dely);
	} 
      } 
      if ((mem[p].hhfield.b1 == 4) && (mem[p].hhfield.b0 == 1) 
   ) 
      {
	delx = mem[p + 1].cint - mem[p + 3].cint;
	dely = mem[p + 2].cint - mem[p + 4].cint;
	if ((delx == 0) && (dely == 0)) 
	{
	  mem[p].hhfield.b1 = 3;
	  mem[p + 5].cint = 65536L;
	} 
	else {
	    
	  mem[p].hhfield.b1 = 2;
	  mem[p + 5].cint = n_arg (delx , dely);
	} 
      } 
      solve_choices (p , q , n);
    } 
    p = q;
  } while (!(p == h));
  if (internal[4] > 0) 
  print_path (knots , 527 , true);
  if (arith_error) 
  {
    {
      if (interaction == 3) 
;
      if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[in_open]);
	print (58);
	print_int (line);
	print (262);
	print (528);
      } 
      else {
	  
	print_nl (263);
	print (528);
      } 
    } 
    {
      help_ptr = 2;
      help_line[1] = 529;
      help_line[0] = 530;
    } 
    put_get_error ();
    arith_error = false;
  } 
} 
void 
make_moves (scaled xx0 , scaled xx1 , scaled xx2 , scaled xx3 , scaled yy0 , 
scaled yy1 , scaled yy2 , scaled yy3 , small_number xicorr , small_number 
etacorr) 
{
  /* 22 30 10 */ integer x1, x2, x3, m, r, y1, y2, y3, n, s, l;
  integer q, t, u, x2a, x3a, y2a, y3a;
  if ((xx3 < xx0) || (yy3 < yy0)) 
  confusion (109);
  l = 16;
  bisect_ptr = 0;
  x1 = xx1 - xx0;
  x2 = xx2 - xx1;
  x3 = xx3 - xx2;
  if (xx0 >= xicorr) 
  r = (xx0 - xicorr) % 65536L;
  else r = 65535L - ((- (integer) xx0 + xicorr - 1) % 65536L);
  m = (xx3 - xx0 + r) / 65536L;
  y1 = yy1 - yy0;
  y2 = yy2 - yy1;
  y3 = yy3 - yy2;
  if (yy0 >= etacorr) 
  s = (yy0 - etacorr) % 65536L;
  else s = 65535L - ((- (integer) yy0 + etacorr - 1) % 65536L);
  n = (yy3 - yy0 + s) / 65536L;
  if ((xx3 - xx0 >= 268435456L) || (yy3 - yy0 >= 268435456L)) 
  {
    x1 = half (x1 + xicorr);
    x2 = half (x2 + xicorr);
    x3 = half (x3 + xicorr);
    r = half (r + xicorr);
    y1 = half (y1 + etacorr);
    y2 = half (y2 + etacorr);
    y3 = half (y3 + etacorr);
    s = half (s + etacorr);
    l = 15;
  } 
  while (true) {
      
    lab22: if (m == 0) 
    while (n > 0) {
	
      incr (move_ptr);
      move[move_ptr] = 1;
      decr (n);
    } 
    else if (n == 0) 
    move[move_ptr] = move[move_ptr]+ m;
    else if (m + n == 2) 
    {
      r = two_to_the[l] - r;
      s = two_to_the[l] - s;
      while (l < 30) {
	  
	x3a = x3;
	x2a = half (x2 + x3 + xicorr);
	x2 = half (x1 + x2 + xicorr);
	x3 = half (x2 + x2a + xicorr);
	t = x1 + x2 + x3;
	r = r + r - xicorr;
	y3a = y3;
	y2a = half (y2 + y3 + etacorr);
	y2 = half (y1 + y2 + etacorr);
	y3 = half (y2 + y2a + etacorr);
	u = y1 + y2 + y3;
	s = s + s - etacorr;
	if (t < r) {
	    
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
	  else {
	      
	    {
	      incr (move_ptr);
	      move[move_ptr] = 2;
	    } 
	    goto done;
	  } 
	} 
	else if (u < s) 
	{
	  {
	    incr (move[move_ptr]);
	    incr (move_ptr);
	    move[move_ptr] = 1;
	  } 
	  goto done;
	} 
	incr (l);
      } 
      r = r - xicorr;
      s = s - etacorr;
      if (ab_vs_cd (x1 + x2 + x3 , s , y1 + y2 + y3 , r) - xicorr >= 0) 
      {
	incr (move[move_ptr]);
	incr (move_ptr);
	move[move_ptr] = 1;
      } 
      else {
	  
	incr (move_ptr);
	move[move_ptr] = 2;
      } 
      done:;
    } 
    else {
	
      incr (l);
      bisect_stack[bisect_ptr + 10] = l;
      bisect_stack[bisect_ptr + 2] = x3;
      bisect_stack[bisect_ptr + 1] = half (x2 + x3 + xicorr);
      x2 = half (x1 + x2 + xicorr);
      x3 = half (x2 + bisect_stack[bisect_ptr + 1]+ xicorr);
      bisect_stack[bisect_ptr] = x3;
      r = r + r + xicorr;
      t = x1 + x2 + x3 + r;
      q = t / two_to_the[l];
      bisect_stack[bisect_ptr + 3] = t % two_to_the[l];
      bisect_stack[bisect_ptr + 4] = m - q;
      m = q;
      bisect_stack[bisect_ptr + 7] = y3;
      bisect_stack[bisect_ptr + 6] = half (y2 + y3 + etacorr);
      y2 = half (y1 + y2 + etacorr);
      y3 = half (y2 + bisect_stack[bisect_ptr + 6]+ etacorr);
      bisect_stack[bisect_ptr + 5] = y3;
      s = s + s + etacorr;
      u = y1 + y2 + y3 + s;
      q = u / two_to_the[l];
      bisect_stack[bisect_ptr + 8] = u % two_to_the[l];
      bisect_stack[bisect_ptr + 9] = n - q;
      n = q;
      bisect_ptr = bisect_ptr + 11;
      goto lab22;
    } 
    if (bisect_ptr == 0) 
    goto lab10;
    bisect_ptr = bisect_ptr - 11;
    x1 = bisect_stack[bisect_ptr];
    x2 = bisect_stack[bisect_ptr + 1];
    x3 = bisect_stack[bisect_ptr + 2];
    r = bisect_stack[bisect_ptr + 3];
    m = bisect_stack[bisect_ptr + 4];
    y1 = bisect_stack[bisect_ptr + 5];
    y2 = bisect_stack[bisect_ptr + 6];
    y3 = bisect_stack[bisect_ptr + 7];
    s = bisect_stack[bisect_ptr + 8];
    n = bisect_stack[bisect_ptr + 9];
    l = bisect_stack[bisect_ptr + 10];
  } 
  lab10:;
} 
void 
smooth_moves (integer b , integer t) 
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
      if (abs (a - aa) > 1) {
	  
	if (a > aa) 
	{
	  if (aaa >= aa) {
	      
	    if (a >= move[k + 1]) 
	    {
	      incr (move[k - 1]);
	      move[k] = a - 1;
	    } 
	  } 
	} 
	else {
	    
	  if (aaa <= aa) {
	      
	    if (a <= move[k + 1]) 
	    {
	      decr (move[k - 1]);
	      move[k] = a + 1;
	    } 
	  } 
	} 
      } 
      incr (k);
      aaa = aa;
      aa = a;
    } while (!(k == t));
  } 
} 
void 
init_edges (halfword h) 
{
  mem[h].hhfield.lhfield = h;
  mem[h].hhfield.v.RH = h;
  mem[h + 1].hhfield.lhfield = 8191;
  mem[h + 1].hhfield.v.RH = 1;
  mem[h + 2].hhfield.lhfield = 8191;
  mem[h + 2].hhfield.v.RH = 1;
  mem[h + 3].hhfield.lhfield = 4096;
  mem[h + 3].hhfield.v.RH = 0;
  mem[h + 4].cint = 0;
  mem[h + 5].hhfield.v.RH = h;
  mem[h + 5].hhfield.lhfield = 0;
} 
void 
fix_offset (void) 
{
  halfword p, q;
  integer delta;
  delta = 8 * (mem[cur_edges + 3].hhfield.lhfield - 4096);
  mem[cur_edges + 3].hhfield.lhfield = 4096;
  q = mem[cur_edges].hhfield.v.RH;
  while (q != cur_edges) {
      
    p = mem[q + 1].hhfield.v.RH;
    while (p != memtop) {
	
      mem[p].hhfield.lhfield = mem[p].hhfield.lhfield - delta;
      p = mem[p].hhfield.v.RH;
    } 
    p = mem[q + 1].hhfield.lhfield;
    while (p > 1) {
	
      mem[p].hhfield.lhfield = mem[p].hhfield.lhfield - delta;
      p = mem[p].hhfield.v.RH;
    } 
    q = mem[q].hhfield.v.RH;
  } 
} 
void 
edge_prep (integer ml , integer mr , integer nl , integer nr) 
{
  halfword delta;
  integer temp;
  halfword p, q;
  ml = ml + 4096;
  mr = mr + 4096;
  nl = nl + 4096;
  nr = nr + 4095;
  if (ml < mem[cur_edges + 2].hhfield.lhfield) 
  mem[cur_edges + 2].hhfield.lhfield = ml;
  if (mr > mem[cur_edges + 2].hhfield.v.RH) 
  mem[cur_edges + 2].hhfield.v.RH = mr;
  temp = mem[cur_edges + 3].hhfield.lhfield - 4096;
  if (!(abs (mem[cur_edges + 2].hhfield.lhfield + temp - 4096) < 4096 
) || !(abs (mem[cur_edges + 2].hhfield.v.RH + temp - 4096) < 4096) 
) 
  fix_offset ();
  if (mem[cur_edges].hhfield.v.RH == cur_edges) 
  {
    mem[cur_edges + 1].hhfield.lhfield = nr + 1;
    mem[cur_edges + 1].hhfield.v.RH = nr;
  } 
  if (nl < mem[cur_edges + 1].hhfield.lhfield) 
  {
    delta = mem[cur_edges + 1].hhfield.lhfield - nl;
    mem[cur_edges + 1].hhfield.lhfield = nl;
    p = mem[cur_edges].hhfield.v.RH;
    do {
	q = get_node (2);
      mem[q + 1].hhfield.v.RH = memtop;
      mem[q + 1].hhfield.lhfield = 1;
      mem[p].hhfield.lhfield = q;
      mem[q].hhfield.v.RH = p;
      p = q;
      decr (delta);
    } while (!(delta == 0));
    mem[p].hhfield.lhfield = cur_edges;
    mem[cur_edges].hhfield.v.RH = p;
    if (mem[cur_edges + 5].hhfield.v.RH == cur_edges) 
    mem[cur_edges + 5].hhfield.lhfield = nl - 1;
  } 
  if (nr > mem[cur_edges + 1].hhfield.v.RH) 
  {
    delta = nr - mem[cur_edges + 1].hhfield.v.RH;
    mem[cur_edges + 1].hhfield.v.RH = nr;
    p = mem[cur_edges].hhfield.lhfield;
    do {
	q = get_node (2);
      mem[q + 1].hhfield.v.RH = memtop;
      mem[q + 1].hhfield.lhfield = 1;
      mem[p].hhfield.v.RH = q;
      mem[q].hhfield.lhfield = p;
      p = q;
      decr (delta);
    } while (!(delta == 0));
    mem[p].hhfield.v.RH = cur_edges;
    mem[cur_edges].hhfield.lhfield = p;
    if (mem[cur_edges + 5].hhfield.v.RH == cur_edges) 
    mem[cur_edges + 5].hhfield.lhfield = nr + 1;
  } 
} 
halfword 
copy_edges (halfword h) 
{
  register halfword Result; halfword p, r;
  halfword hh, pp, qq, rr, ss;
  hh = get_node (6);
  mem[hh + 1] = mem[h + 1];
  mem[hh + 2] = mem[h + 2];
  mem[hh + 3] = mem[h + 3];
  mem[hh + 4] = mem[h + 4];
  mem[hh + 5].hhfield.lhfield = mem[hh + 1].hhfield.v.RH + 1;
  mem[hh + 5].hhfield.v.RH = hh;
  p = mem[h].hhfield.v.RH;
  qq = hh;
  while (p != h) {
      
    pp = get_node (2);
    mem[qq].hhfield.v.RH = pp;
    mem[pp].hhfield.lhfield = qq;
    r = mem[p + 1].hhfield.v.RH;
    rr = pp + 1;
    while (r != memtop) {
	
      ss = get_avail ();
      mem[rr].hhfield.v.RH = ss;
      rr = ss;
      mem[rr].hhfield.lhfield = mem[r].hhfield.lhfield;
      r = mem[r].hhfield.v.RH;
    } 
    mem[rr].hhfield.v.RH = memtop;
    r = mem[p + 1].hhfield.lhfield;
    rr = memtop - 1;
    while (r > 1) {
	
      ss = get_avail ();
      mem[rr].hhfield.v.RH = ss;
      rr = ss;
      mem[rr].hhfield.lhfield = mem[r].hhfield.lhfield;
      r = mem[r].hhfield.v.RH;
    } 
    mem[rr].hhfield.v.RH = r;
    mem[pp + 1].hhfield.lhfield = mem[memtop - 1].hhfield.v.RH;
    p = mem[p].hhfield.v.RH;
    qq = pp;
  } 
  mem[qq].hhfield.v.RH = hh;
  mem[hh].hhfield.lhfield = qq;
  Result = hh;
  return Result;
} 
void 
reflect_edges (void) 
{
  halfword p, q, r;
  p = mem[cur_edges + 1].hhfield.lhfield;
  mem[cur_edges + 1].hhfield.lhfield = 8191 - mem[cur_edges + 1]
  .hhfield.v.RH;
  mem[cur_edges + 1].hhfield.v.RH = 8191 - p;
  mem[cur_edges + 5].hhfield.lhfield = 8191 - mem[cur_edges + 5]
  .hhfield.lhfield;
  p = mem[cur_edges].hhfield.v.RH;
  q = cur_edges;
  do {
      r = mem[p].hhfield.v.RH;
    mem[p].hhfield.v.RH = q;
    mem[q].hhfield.lhfield = p;
    q = p;
    p = r;
  } while (!(q == cur_edges));
  mem[cur_edges + 4].cint = 0;
} 
void 
x_reflect_edges (void) 
{
  halfword p, q, r, s;
  integer m;
  p = mem[cur_edges + 2].hhfield.lhfield;
  mem[cur_edges + 2].hhfield.lhfield = 8192 - mem[cur_edges + 2]
  .hhfield.v.RH;
  mem[cur_edges + 2].hhfield.v.RH = 8192 - p;
  m = (4096 + mem[cur_edges + 3].hhfield.lhfield) * 8 + 8;
  mem[cur_edges + 3].hhfield.lhfield = 4096;
  p = mem[cur_edges].hhfield.v.RH;
  do {
      q = mem[p + 1].hhfield.v.RH;
    r = memtop;
    while (q != memtop) {
	
      s = mem[q].hhfield.v.RH;
      mem[q].hhfield.v.RH = r;
      r = q;
      mem[r].hhfield.lhfield = m - mem[q].hhfield.lhfield;
      q = s;
    } 
    mem[p + 1].hhfield.v.RH = r;
    q = mem[p + 1].hhfield.lhfield;
    while (q > 1) {
	
      mem[q].hhfield.lhfield = m - mem[q].hhfield.lhfield;
      q = mem[q].hhfield.v.RH;
    } 
    p = mem[p].hhfield.v.RH;
  } while (!(p == cur_edges));
  mem[cur_edges + 4].cint = 0;
} 
void 
y_scale_edges (integer s) 
{
  halfword p, q, pp, r, rr, ss;
  integer t;
  if ((s * (mem[cur_edges + 1].hhfield.v.RH - 4095) >= 4096) || (s * 
  (mem[cur_edges + 1].hhfield.lhfield - 4096) <= -4096)) 
  {
    {
      if (interaction == 3) 
;
      if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[in_open]);
	print (58);
	print_int (line);
	print (262);
	print (535);
      } 
      else {
	  
	print_nl (263);
	print (535);
      } 
    } 
    {
      help_ptr = 3;
      help_line[2] = 536;
      help_line[1] = 537;
      help_line[0] = 538;
    } 
    put_get_error ();
  } 
  else {
      
    mem[cur_edges + 1].hhfield.v.RH = s * (mem[cur_edges + 1].hhfield 
  .v.RH - 4095) + 4095;
    mem[cur_edges + 1].hhfield.lhfield = s * (mem[cur_edges + 1]
    .hhfield.lhfield - 4096) + 4096;
    p = cur_edges;
    do {
	q = p;
      p = mem[p].hhfield.v.RH;
      {register integer for_end; t = 2;for_end = s; if (t <= for_end) do 
	{
	  pp = get_node (2);
	  mem[q].hhfield.v.RH = pp;
	  mem[p].hhfield.lhfield = pp;
	  mem[pp].hhfield.v.RH = p;
	  mem[pp].hhfield.lhfield = q;
	  q = pp;
	  r = mem[p + 1].hhfield.v.RH;
	  rr = pp + 1;
	  while (r != memtop) {
	      
	    ss = get_avail ();
	    mem[rr].hhfield.v.RH = ss;
	    rr = ss;
	    mem[rr].hhfield.lhfield = mem[r].hhfield.lhfield;
	    r = mem[r].hhfield.v.RH;
	  } 
	  mem[rr].hhfield.v.RH = memtop;
	  r = mem[p + 1].hhfield.lhfield;
	  rr = memtop - 1;
	  while (r > 1) {
	      
	    ss = get_avail ();
	    mem[rr].hhfield.v.RH = ss;
	    rr = ss;
	    mem[rr].hhfield.lhfield = mem[r].hhfield.lhfield;
	    r = mem[r].hhfield.v.RH;
	  } 
	  mem[rr].hhfield.v.RH = r;
	  mem[pp + 1].hhfield.lhfield = mem[memtop - 1].hhfield.v.RH 
	;
	} 
      while (t++ < for_end);} 
    } while (!(mem[p].hhfield.v.RH == cur_edges));
    mem[cur_edges + 4].cint = 0;
  } 
} 
void 
x_scale_edges (integer s) 
{
  halfword p, q;
  unsigned short t;
  unsigned char w;
  integer delta;
  if ((s * (mem[cur_edges + 2].hhfield.v.RH - 4096) >= 4096) || (s * 
  (mem[cur_edges + 2].hhfield.lhfield - 4096) <= -4096)) 
  {
    {
      if (interaction == 3) 
;
      if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[in_open]);
	print (58);
	print_int (line);
	print (262);
	print (535);
      } 
      else {
	  
	print_nl (263);
	print (535);
      } 
    } 
    {
      help_ptr = 3;
      help_line[2] = 539;
      help_line[1] = 537;
      help_line[0] = 538;
    } 
    put_get_error ();
  } 
  else if ((mem[cur_edges + 2].hhfield.v.RH != 4096) || (mem[
  cur_edges + 2].hhfield.lhfield != 4096)) 
  {
    mem[cur_edges + 2].hhfield.v.RH = s * (mem[cur_edges + 2].hhfield 
  .v.RH - 4096) + 4096;
    mem[cur_edges + 2].hhfield.lhfield = s * (mem[cur_edges + 2]
    .hhfield.lhfield - 4096) + 4096;
    delta = 8 * (4096 - s * mem[cur_edges + 3].hhfield.lhfield) + 0;
    mem[cur_edges + 3].hhfield.lhfield = 4096;
    q = mem[cur_edges].hhfield.v.RH;
    do {
	p = mem[q + 1].hhfield.v.RH;
      while (p != memtop) {
	  
	t = mem[p].hhfield.lhfield;
	w = t % 8;
	mem[p].hhfield.lhfield = (t - w) * s + w + delta;
	p = mem[p].hhfield.v.RH;
      } 
      p = mem[q + 1].hhfield.lhfield;
      while (p > 1) {
	  
	t = mem[p].hhfield.lhfield;
	w = t % 8;
	mem[p].hhfield.lhfield = (t - w) * s + w + delta;
	p = mem[p].hhfield.v.RH;
      } 
      q = mem[q].hhfield.v.RH;
    } while (!(q == cur_edges));
    mem[cur_edges + 4].cint = 0;
  } 
} 
void 
negate_edges (halfword h) 
{
  /* 30 */ halfword p, q, r, s, t, u;
  p = mem[h].hhfield.v.RH;
  while (p != h) {
      
    q = mem[p + 1].hhfield.lhfield;
    while (q > 1) {
	
      mem[q].hhfield.lhfield = 8 - 2 * ((mem[q].hhfield.lhfield) 
      % 8) + mem[q].hhfield.lhfield;
      q = mem[q].hhfield.v.RH;
    } 
    q = mem[p + 1].hhfield.v.RH;
    if (q != memtop) 
    {
      do {
	  mem[q].hhfield.lhfield = 8 - 2 * ((mem[q].hhfield 
	.lhfield) % 8) + mem[q].hhfield.lhfield;
	q = mem[q].hhfield.v.RH;
      } while (!(q == memtop));
      u = p + 1;
      q = mem[u].hhfield.v.RH;
      r = q;
      s = mem[r].hhfield.v.RH;
      while (true) if (mem[s].hhfield.lhfield > mem[r].hhfield 
    .lhfield) 
      {
	mem[u].hhfield.v.RH = q;
	if (s == memtop) 
	goto done;
	u = r;
	q = s;
	r = q;
	s = mem[r].hhfield.v.RH;
      } 
      else {
	  
	t = s;
	s = mem[t].hhfield.v.RH;
	mem[t].hhfield.v.RH = q;
	q = t;
      } 
      done: mem[r].hhfield.v.RH = memtop;
    } 
    p = mem[p].hhfield.v.RH;
  } 
  mem[h + 4].cint = 0;
} 
void 
sort_edges (halfword h) 
{
  /* 30 */ halfword k;
  halfword p, q, r, s;
  r = mem[h + 1].hhfield.lhfield;
  mem[h + 1].hhfield.lhfield = 0;
  p = mem[r].hhfield.v.RH;
  mem[r].hhfield.v.RH = memtop;
  mem[memtop - 1].hhfield.v.RH = r;
  while (p > 1) {
      
    k = mem[p].hhfield.lhfield;
    q = memtop - 1;
    do {
	r = q;
      q = mem[r].hhfield.v.RH;
    } while (!(k <= mem[q].hhfield.lhfield));
    mem[r].hhfield.v.RH = p;
    r = mem[p].hhfield.v.RH;
    mem[p].hhfield.v.RH = q;
    p = r;
  } 
  {
    r = h + 1;
    q = mem[r].hhfield.v.RH;
    p = mem[memtop - 1].hhfield.v.RH;
    while (true) {
	
      k = mem[p].hhfield.lhfield;
      while (k > mem[q].hhfield.lhfield) {
	  
	r = q;
	q = mem[r].hhfield.v.RH;
      } 
      mem[r].hhfield.v.RH = p;
      s = mem[p].hhfield.v.RH;
      mem[p].hhfield.v.RH = q;
      if (s == memtop) 
      goto done;
      r = p;
      p = s;
    } 
    done:;
  } 
} 
void 
cull_edges (integer wlo , integer whi , integer wout , integer win) 
{
  /* 30 */ halfword p, q, r, s;
  integer w;
  integer d;
  integer m;
  integer mm;
  integer ww;
  integer prevw;
  halfword n, minn, maxn;
  halfword mind, maxd;
  mind = 268435455L;
  maxd = 0;
  minn = 268435455L;
  maxn = 0;
  p = mem[cur_edges].hhfield.v.RH;
  n = mem[cur_edges + 1].hhfield.lhfield;
  while (p != cur_edges) {
      
    if (mem[p + 1].hhfield.lhfield > 1) 
    sort_edges (p);
    if (mem[p + 1].hhfield.v.RH != memtop) 
    {
      r = memtop - 1;
      q = mem[p + 1].hhfield.v.RH;
      ww = 0;
      m = 1000000L;
      prevw = 0;
      while (true) {
	  
	if (q == memtop) 
	mm = 1000000L;
	else {
	    
	  d = mem[q].hhfield.lhfield;
	  mm = d / 8;
	  ww = ww + (d % 8) - 4;
	} 
	if (mm > m) 
	{
	  if (w != prevw) 
	  {
	    s = get_avail ();
	    mem[r].hhfield.v.RH = s;
	    mem[s].hhfield.lhfield = 8 * m + 4 + w - prevw;
	    r = s;
	    prevw = w;
	  } 
	  if (q == memtop) 
	  goto done;
	} 
	m = mm;
	if (ww >= wlo) {
	    
	  if (ww <= whi) 
	  w = win;
	  else w = wout;
	} 
	else w = wout;
	s = mem[q].hhfield.v.RH;
	{
	  mem[q].hhfield.v.RH = avail;
	  avail = q;
	;
#ifdef STAT
	  decr (dyn_used);
#endif /* STAT */
	} 
	q = s;
      } 
      done: mem[r].hhfield.v.RH = memtop;
      mem[p + 1].hhfield.v.RH = mem[memtop - 1].hhfield.v.RH;
      if (r != memtop - 1) 
      {
	if (minn == 268435455L) 
	minn = n;
	maxn = n;
	if (mind > mem[mem[memtop - 1].hhfield.v.RH].hhfield 
	.lhfield) 
	mind = mem[mem[memtop - 1].hhfield.v.RH].hhfield.lhfield;
	if (maxd < mem[r].hhfield.lhfield) 
	maxd = mem[r].hhfield.lhfield;
      } 
    } 
    p = mem[p].hhfield.v.RH;
    incr (n);
  } 
  if (minn > maxn) 
  {
    p = mem[cur_edges].hhfield.v.RH;
    while (p != cur_edges) {
	
      q = mem[p].hhfield.v.RH;
      free_node (p , 2);
      p = q;
    } 
    init_edges (cur_edges);
  } 
  else {
      
    n = mem[cur_edges + 1].hhfield.lhfield;
    mem[cur_edges + 1].hhfield.lhfield = minn;
    while (minn > n) {
	
      p = mem[cur_edges].hhfield.v.RH;
      mem[cur_edges].hhfield.v.RH = mem[p].hhfield.v.RH;
      mem[mem[p].hhfield.v.RH].hhfield.lhfield = cur_edges;
      free_node (p , 2);
      incr (n);
    } 
    n = mem[cur_edges + 1].hhfield.v.RH;
    mem[cur_edges + 1].hhfield.v.RH = maxn;
    mem[cur_edges + 5].hhfield.lhfield = maxn + 1;
    mem[cur_edges + 5].hhfield.v.RH = cur_edges;
    while (maxn < n) {
	
      p = mem[cur_edges].hhfield.lhfield;
      mem[cur_edges].hhfield.lhfield = mem[p].hhfield.lhfield;
      mem[mem[p].hhfield.lhfield].hhfield.v.RH = cur_edges;
      free_node (p , 2);
      decr (n);
    } 
    mem[cur_edges + 2].hhfield.lhfield = ((mind) / 8) - mem[cur_edges 
    + 3].hhfield.lhfield + 4096;
    mem[cur_edges + 2].hhfield.v.RH = ((maxd) / 8) - mem[cur_edges + 
    3].hhfield.lhfield + 4096;
  } 
  mem[cur_edges + 4].cint = 0;
} 
void 
xy_swap_edges (void) 
{
  /* 30 */ integer mmagic, nmagic;
  halfword p, q, r, s;
  integer mspread;
  integer j, jj;
  integer m, mm;
  integer pd, rd;
  integer pm, rm;
  integer w;
  integer ww;
  integer dw;
  integer extras;
  schar xw;
  integer k;
  mspread = mem[cur_edges + 2].hhfield.v.RH - mem[cur_edges + 2]
  .hhfield.lhfield;
  if (mspread > move_size) 
  overflow (540 , move_size);
  {register integer for_end; j = 0;for_end = mspread; if (j <= for_end) 
  do 
    move[j] = memtop;
  while (j++ < for_end);} 
  p = get_node (2);
  mem[p + 1].hhfield.v.RH = memtop;
  mem[p + 1].hhfield.lhfield = 0;
  mem[p].hhfield.lhfield = cur_edges;
  mem[mem[cur_edges].hhfield.v.RH].hhfield.lhfield = p;
  p = get_node (2);
  mem[p + 1].hhfield.v.RH = memtop;
  mem[p].hhfield.lhfield = mem[cur_edges].hhfield.lhfield;
  mmagic = mem[cur_edges + 2].hhfield.lhfield + mem[cur_edges + 3]
  .hhfield.lhfield - 4096;
  nmagic = 8 * mem[cur_edges + 1].hhfield.v.RH + 12;
  do {
      q = mem[p].hhfield.lhfield;
    if (mem[q + 1].hhfield.lhfield > 1) 
    sort_edges (q);
    r = mem[p + 1].hhfield.v.RH;
    free_node (p , 2);
    p = r;
    pd = mem[p].hhfield.lhfield;
    pm = pd / 8;
    r = mem[q + 1].hhfield.v.RH;
    rd = mem[r].hhfield.lhfield;
    rm = rd / 8;
    w = 0;
    while (true) {
	
      if (pm < rm) 
      mm = pm;
      else mm = rm;
      if (w != 0) {
	  
	if (m != mm) 
	{
	  if (mm - mmagic >= move_size) 
	  confusion (510);
	  extras = (abs (w) - 1) / 3;
	  if (extras > 0) 
	  {
	    if (w > 0) 
	    xw = 3;
	    else xw = -3;
	    ww = w - extras * xw;
	  } 
	  else ww = w;
	  do {
	      j = m - mmagic;
	    {register integer for_end; k = 1;for_end = extras; if (k <= 
	    for_end) do 
	      {
		s = get_avail ();
		mem[s].hhfield.lhfield = nmagic + xw;
		mem[s].hhfield.v.RH = move[j];
		move[j] = s;
	      } 
	    while (k++ < for_end);} 
	    s = get_avail ();
	    mem[s].hhfield.lhfield = nmagic + ww;
	    mem[s].hhfield.v.RH = move[j];
	    move[j] = s;
	    incr (m);
	  } while (!(m == mm));
	} 
      } 
      if (pd < rd) 
      {
	dw = (pd % 8) - 4;
	s = mem[p].hhfield.v.RH;
	{
	  mem[p].hhfield.v.RH = avail;
	  avail = p;
	;
#ifdef STAT
	  decr (dyn_used);
#endif /* STAT */
	} 
	p = s;
	pd = mem[p].hhfield.lhfield;
	pm = pd / 8;
      } 
      else {
	  
	if (r == memtop) 
	goto done;
	dw = - (integer) ((rd % 8) - 4);
	r = mem[r].hhfield.v.RH;
	rd = mem[r].hhfield.lhfield;
	rm = rd / 8;
      } 
      m = mm;
      w = w + dw;
    } 
    done:;
    p = q;
    nmagic = nmagic - 8;
  } while (!(mem[p].hhfield.lhfield == cur_edges));
  free_node (p , 2);
  move[mspread] = 0;
  j = 0;
  while (move[j] == memtop) incr (j);
  if (j == mspread) 
  init_edges (cur_edges);
  else {
      
    mm = mem[cur_edges + 2].hhfield.lhfield;
    mem[cur_edges + 2].hhfield.lhfield = mem[cur_edges + 1].hhfield 
  .lhfield;
    mem[cur_edges + 2].hhfield.v.RH = mem[cur_edges + 1].hhfield.v.RH 
    + 1;
    mem[cur_edges + 3].hhfield.lhfield = 4096;
    jj = mspread - 1;
    while (move[jj] == memtop) decr (jj);
    mem[cur_edges + 1].hhfield.lhfield = j + mm;
    mem[cur_edges + 1].hhfield.v.RH = jj + mm;
    q = cur_edges;
    do {
	p = get_node (2);
      mem[q].hhfield.v.RH = p;
      mem[p].hhfield.lhfield = q;
      mem[p + 1].hhfield.v.RH = move[j];
      mem[p + 1].hhfield.lhfield = 0;
      incr (j);
      q = p;
    } while (!(j > jj));
    mem[q].hhfield.v.RH = cur_edges;
    mem[cur_edges].hhfield.lhfield = q;
    mem[cur_edges + 5].hhfield.lhfield = mem[cur_edges + 1].hhfield 
  .v.RH + 1;
    mem[cur_edges + 5].hhfield.v.RH = cur_edges;
    mem[cur_edges + 4].cint = 0;
  } 
} 
void 
merge_edges (halfword h) 
{
  /* 30 */ halfword p, q, r, pp, qq, rr;
  integer n;
  halfword k;
  integer delta;
  if (mem[h].hhfield.v.RH != h) 
  {
    if ((mem[h + 2].hhfield.lhfield < mem[cur_edges + 2].hhfield 
  .lhfield) || (mem[h + 2].hhfield.v.RH > mem[cur_edges + 2]
    .hhfield.v.RH) || (mem[h + 1].hhfield.lhfield < mem[cur_edges + 1 
  ].hhfield.lhfield) || (mem[h + 1].hhfield.v.RH > mem[cur_edges + 
    1].hhfield.v.RH)) 
    edge_prep (mem[h + 2].hhfield.lhfield - 4096 , mem[h + 2].hhfield 
  .v.RH - 4096 , mem[h + 1].hhfield.lhfield - 4096 , mem[h + 1]
    .hhfield.v.RH - 4095);
    if (mem[h + 3].hhfield.lhfield != mem[cur_edges + 3].hhfield 
  .lhfield) 
    {
      pp = mem[h].hhfield.v.RH;
      delta = 8 * (mem[cur_edges + 3].hhfield.lhfield - mem[h + 3]
      .hhfield.lhfield);
      do {
	  qq = mem[pp + 1].hhfield.v.RH;
	while (qq != memtop) {
	    
	  mem[qq].hhfield.lhfield = mem[qq].hhfield.lhfield + delta 
	;
	  qq = mem[qq].hhfield.v.RH;
	} 
	qq = mem[pp + 1].hhfield.lhfield;
	while (qq > 1) {
	    
	  mem[qq].hhfield.lhfield = mem[qq].hhfield.lhfield + delta 
	;
	  qq = mem[qq].hhfield.v.RH;
	} 
	pp = mem[pp].hhfield.v.RH;
      } while (!(pp == h));
    } 
    n = mem[cur_edges + 1].hhfield.lhfield;
    p = mem[cur_edges].hhfield.v.RH;
    pp = mem[h].hhfield.v.RH;
    while (n < mem[h + 1].hhfield.lhfield) {
	
      incr (n);
      p = mem[p].hhfield.v.RH;
    } 
    do {
	qq = mem[pp + 1].hhfield.lhfield;
      if (qq > 1) {
	  
	if (mem[p + 1].hhfield.lhfield <= 1) 
	mem[p + 1].hhfield.lhfield = qq;
	else {
	    
	  while (mem[qq].hhfield.v.RH > 1) qq = mem[qq].hhfield 
	.v.RH;
	  mem[qq].hhfield.v.RH = mem[p + 1].hhfield.lhfield;
	  mem[p + 1].hhfield.lhfield = mem[pp + 1].hhfield.lhfield;
	} 
      } 
      mem[pp + 1].hhfield.lhfield = 0;
      qq = mem[pp + 1].hhfield.v.RH;
      if (qq != memtop) 
      {
	if (mem[p + 1].hhfield.lhfield == 1) 
	mem[p + 1].hhfield.lhfield = 0;
	mem[pp + 1].hhfield.v.RH = memtop;
	r = p + 1;
	q = mem[r].hhfield.v.RH;
	if (q == memtop) 
	mem[p + 1].hhfield.v.RH = qq;
	else while (true) {
	    
	  k = mem[qq].hhfield.lhfield;
	  while (k > mem[q].hhfield.lhfield) {
	      
	    r = q;
	    q = mem[r].hhfield.v.RH;
	  } 
	  mem[r].hhfield.v.RH = qq;
	  rr = mem[qq].hhfield.v.RH;
	  mem[qq].hhfield.v.RH = q;
	  if (rr == memtop) 
	  goto done;
	  r = qq;
	  qq = rr;
	} 
      } 
      done:;
      pp = mem[pp].hhfield.v.RH;
      p = mem[p].hhfield.v.RH;
    } while (!(pp == h));
  } 
} 
integer 
total_weight (halfword h) 
{
  register integer Result; halfword p, q;
  integer n;
  unsigned short m;
  n = 0;
  p = mem[h].hhfield.v.RH;
  while (p != h) {
      
    q = mem[p + 1].hhfield.v.RH;
    while (q != memtop) {
	
      m = mem[q].hhfield.lhfield;
      n = n - ((m % 8) - 4) * (m / 8);
      q = mem[q].hhfield.v.RH;
    } 
    q = mem[p + 1].hhfield.lhfield;
    while (q > 1) {
	
      m = mem[q].hhfield.lhfield;
      n = n - ((m % 8) - 4) * (m / 8);
      q = mem[q].hhfield.v.RH;
    } 
    p = mem[p].hhfield.v.RH;
  } 
  Result = n;
  return Result;
} 
void 
begin_edge_tracing (void) 
{
  print_diagnostic (541 , 261 , true);
  print (542);
  print_int (cur_wt);
  print_char (41);
  trace_x = -4096;
} 
void 
trace_a_corner (void) 
{
  if (file_offset > maxprintline - 13) 
  print_nl (261);
  print_char (40);
  print_int (trace_x);
  print_char (44);
  print_int (trace_yy);
  print_char (41);
  trace_y = trace_yy;
} 
void 
end_edge_tracing (void) 
{
  if (trace_x == -4096) 
  print_nl (543);
  else {
      
    trace_a_corner ();
    print_char (46);
  } 
  end_diagnostic (true);
} 
void 
trace_new_edge (halfword r , integer n) 
{
  integer d;
  schar w;
  integer m, n0, n1;
  d = mem[r].hhfield.lhfield;
  w = (d % 8) - 4;
  m = (d / 8) - mem[cur_edges + 3].hhfield.lhfield;
  if (w == cur_wt) 
  {
    n0 = n + 1;
    n1 = n;
  } 
  else {
      
    n0 = n;
    n1 = n + 1;
  } 
  if (m != trace_x) 
  {
    if (trace_x == -4096) 
    {
      print_nl (261);
      trace_yy = n0;
    } 
    else if (trace_yy != n0) 
    print_char (63);
    else trace_a_corner ();
    trace_x = m;
    trace_a_corner ();
  } 
  else {
      
    if (n0 != trace_yy) 
    print_char (33);
    if (((n0 < n1) && (trace_y > trace_yy)) || ((n0 > n1) && (trace_y 
    < trace_yy))) 
    trace_a_corner ();
  } 
  trace_yy = n1;
} 
void 
line_edges (scaled x0 , scaled y0 , scaled x1 , scaled y1) 
{
  /* 30 31 */ integer m0, n0, m1, n1;
  scaled delx, dely;
  scaled yt;
  scaled tx;
  halfword p, r;
  integer base;
  integer n;
  n0 = roundunscaled (y0);
  n1 = roundunscaled (y1);
  if (n0 != n1) 
  {
    m0 = roundunscaled (x0);
    m1 = roundunscaled (x1);
    delx = x1 - x0;
    dely = y1 - y0;
    yt = n0 * 65536L - 32768L;
    y0 = y0 - yt;
    y1 = y1 - yt;
    if (n0 < n1) 
    {
      base = 8 * mem[cur_edges + 3].hhfield.lhfield + 4 - cur_wt;
      if (m0 <= m1) 
      edge_prep (m0 , m1 , n0 , n1);
      else edge_prep (m1 , m0 , n0 , n1);
      n = mem[cur_edges + 5].hhfield.lhfield - 4096;
      p = mem[cur_edges + 5].hhfield.v.RH;
      if (n != n0) {
	  
	if (n < n0) 
	do {
	    incr (n);
	  p = mem[p].hhfield.v.RH;
	} while (!(n == n0));
	else do {
	    decr (n);
	  p = mem[p].hhfield.lhfield;
	} while (!(n == n0));
      } 
      y0 = 65536L - y0;
      while (true) {
	  
	r = get_avail ();
	mem[r].hhfield.v.RH = mem[p + 1].hhfield.lhfield;
	mem[p + 1].hhfield.lhfield = r;
	tx = takefraction (delx , makefraction (y0 , dely));
	if (ab_vs_cd (delx , y0 , dely , tx) < 0) 
	decr (tx);
	mem[r].hhfield.lhfield = 8 * roundunscaled (x0 + tx) + base;
	y1 = y1 - 65536L;
	if (internal[10] > 0) 
	trace_new_edge (r , n);
	if (y1 < 65536L) 
	goto done;
	p = mem[p].hhfield.v.RH;
	y0 = y0 + 65536L;
	incr (n);
      } 
      done:;
    } 
    else {
	
      base = 8 * mem[cur_edges + 3].hhfield.lhfield + 4 + cur_wt;
      if (m0 <= m1) 
      edge_prep (m0 , m1 , n1 , n0);
      else edge_prep (m1 , m0 , n1 , n0);
      decr (n0);
      n = mem[cur_edges + 5].hhfield.lhfield - 4096;
      p = mem[cur_edges + 5].hhfield.v.RH;
      if (n != n0) {
	  
	if (n < n0) 
	do {
	    incr (n);
	  p = mem[p].hhfield.v.RH;
	} while (!(n == n0));
	else do {
	    decr (n);
	  p = mem[p].hhfield.lhfield;
	} while (!(n == n0));
      } 
      while (true) {
	  
	r = get_avail ();
	mem[r].hhfield.v.RH = mem[p + 1].hhfield.lhfield;
	mem[p + 1].hhfield.lhfield = r;
	tx = takefraction (delx , makefraction (y0 , dely));
	if (ab_vs_cd (delx , y0 , dely , tx) < 0) 
	incr (tx);
	mem[r].hhfield.lhfield = 8 * roundunscaled (x0 - tx) + base;
	y1 = y1 + 65536L;
	if (internal[10] > 0) 
	trace_new_edge (r , n);
	if (y1 >= 0) 
	goto done1;
	p = mem[p].hhfield.lhfield;
	y0 = y0 + 65536L;
	decr (n);
      } 
      done1:;
    } 
    mem[cur_edges + 5].hhfield.v.RH = p;
    mem[cur_edges + 5].hhfield.lhfield = n + 4096;
  } 
} 
void 
move_to_edges (integer m0 , integer n0 , integer m1 , integer n1) 
{
  /* 60 61 62 63 30 */ integer delta;
  integer k;
  halfword p, r;
  integer dx;
  integer edgeandweight;
  integer j;
  integer n;
#ifdef TEXMF_DEBUG
  integer sum;
#endif /* TEXMF_DEBUG */
  delta = n1 - n0;
	;
#ifdef TEXMF_DEBUG
  sum = move[0];
  {register integer for_end; k = 1;for_end = delta; if (k <= for_end) do 
    sum = sum + abs (move[k]);
  while (k++ < for_end);} 
  if (sum != m1 - m0) 
  confusion (48);
#endif /* TEXMF_DEBUG */
  switch (octant) 
  {case 1 : 
    {
      dx = 8;
      edge_prep (m0 , m1 , n0 , n1);
      goto lab60;
    } 
    break;
  case 5 : 
    {
      dx = 8;
      edge_prep (n0 , n1 , m0 , m1);
      goto lab62;
    } 
    break;
  case 6 : 
    {
      dx = -8;
      edge_prep (- (integer) n1 , - (integer) n0 , m0 , m1);
      n0 = - (integer) n0;
      goto lab62;
    } 
    break;
  case 2 : 
    {
      dx = -8;
      edge_prep (- (integer) m1 , - (integer) m0 , n0 , n1);
      m0 = - (integer) m0;
      goto lab60;
    } 
    break;
  case 4 : 
    {
      dx = -8;
      edge_prep (- (integer) m1 , - (integer) m0 , - (integer) n1 , 
      - (integer) n0);
      m0 = - (integer) m0;
      goto lab61;
    } 
    break;
  case 8 : 
    {
      dx = -8;
      edge_prep (- (integer) n1 , - (integer) n0 , - (integer) m1 , 
      - (integer) m0);
      n0 = - (integer) n0;
      goto lab63;
    } 
    break;
  case 7 : 
    {
      dx = 8;
      edge_prep (n0 , n1 , - (integer) m1 , - (integer) m0);
      goto lab63;
    } 
    break;
  case 3 : 
    {
      dx = 8;
      edge_prep (m0 , m1 , - (integer) n1 , - (integer) n0);
      goto lab61;
    } 
    break;
  } 
  lab60: n = mem[cur_edges + 5].hhfield.lhfield - 4096;
  p = mem[cur_edges + 5].hhfield.v.RH;
  if (n != n0) {
      
    if (n < n0) 
    do {
	incr (n);
      p = mem[p].hhfield.v.RH;
    } while (!(n == n0));
    else do {
	decr (n);
      p = mem[p].hhfield.lhfield;
    } while (!(n == n0));
  } 
  if (delta > 0) 
  {
    k = 0;
    edgeandweight = 8 * (m0 + mem[cur_edges + 3].hhfield.lhfield) + 4 - 
    cur_wt;
    do {
	edgeandweight = edgeandweight + dx * move[k];
      {
	r = avail;
	if (r == 0) 
	r = get_avail ();
	else {
	    
	  avail = mem[r].hhfield.v.RH;
	  mem[r].hhfield.v.RH = 0;
	;
#ifdef STAT
	  incr (dyn_used);
#endif /* STAT */
	} 
      } 
      mem[r].hhfield.v.RH = mem[p + 1].hhfield.lhfield;
      mem[r].hhfield.lhfield = edgeandweight;
      if (internal[10] > 0) 
      trace_new_edge (r , n);
      mem[p + 1].hhfield.lhfield = r;
      p = mem[p].hhfield.v.RH;
      incr (k);
      incr (n);
    } while (!(k == delta));
  } 
  goto done;
  lab61: n0 = - (integer) n0 - 1;
  n = mem[cur_edges + 5].hhfield.lhfield - 4096;
  p = mem[cur_edges + 5].hhfield.v.RH;
  if (n != n0) {
      
    if (n < n0) 
    do {
	incr (n);
      p = mem[p].hhfield.v.RH;
    } while (!(n == n0));
    else do {
	decr (n);
      p = mem[p].hhfield.lhfield;
    } while (!(n == n0));
  } 
  if (delta > 0) 
  {
    k = 0;
    edgeandweight = 8 * (m0 + mem[cur_edges + 3].hhfield.lhfield) + 4 + 
    cur_wt;
    do {
	edgeandweight = edgeandweight + dx * move[k];
      {
	r = avail;
	if (r == 0) 
	r = get_avail ();
	else {
	    
	  avail = mem[r].hhfield.v.RH;
	  mem[r].hhfield.v.RH = 0;
	;
#ifdef STAT
	  incr (dyn_used);
#endif /* STAT */
	} 
      } 
      mem[r].hhfield.v.RH = mem[p + 1].hhfield.lhfield;
      mem[r].hhfield.lhfield = edgeandweight;
      if (internal[10] > 0) 
      trace_new_edge (r , n);
      mem[p + 1].hhfield.lhfield = r;
      p = mem[p].hhfield.lhfield;
      incr (k);
      decr (n);
    } while (!(k == delta));
  } 
  goto done;
  lab62: edgeandweight = 8 * (n0 + mem[cur_edges + 3].hhfield.lhfield) + 
  4 - cur_wt;
  n0 = m0;
  k = 0;
  n = mem[cur_edges + 5].hhfield.lhfield - 4096;
  p = mem[cur_edges + 5].hhfield.v.RH;
  if (n != n0) {
      
    if (n < n0) 
    do {
	incr (n);
      p = mem[p].hhfield.v.RH;
    } while (!(n == n0));
    else do {
	decr (n);
      p = mem[p].hhfield.lhfield;
    } while (!(n == n0));
  } 
  do {
      j = move[k];
    while (j > 0) {
	
      {
	r = avail;
	if (r == 0) 
	r = get_avail ();
	else {
	    
	  avail = mem[r].hhfield.v.RH;
	  mem[r].hhfield.v.RH = 0;
	;
#ifdef STAT
	  incr (dyn_used);
#endif /* STAT */
	} 
      } 
      mem[r].hhfield.v.RH = mem[p + 1].hhfield.lhfield;
      mem[r].hhfield.lhfield = edgeandweight;
      if (internal[10] > 0) 
      trace_new_edge (r , n);
      mem[p + 1].hhfield.lhfield = r;
      p = mem[p].hhfield.v.RH;
      decr (j);
      incr (n);
    } 
    edgeandweight = edgeandweight + dx;
    incr (k);
  } while (!(k > delta));
  goto done;
  lab63: edgeandweight = 8 * (n0 + mem[cur_edges + 3].hhfield.lhfield) + 
  4 + cur_wt;
  n0 = - (integer) m0 - 1;
  k = 0;
  n = mem[cur_edges + 5].hhfield.lhfield - 4096;
  p = mem[cur_edges + 5].hhfield.v.RH;
  if (n != n0) {
      
    if (n < n0) 
    do {
	incr (n);
      p = mem[p].hhfield.v.RH;
    } while (!(n == n0));
    else do {
	decr (n);
      p = mem[p].hhfield.lhfield;
    } while (!(n == n0));
  } 
  do {
      j = move[k];
    while (j > 0) {
	
      {
	r = avail;
	if (r == 0) 
	r = get_avail ();
	else {
	    
	  avail = mem[r].hhfield.v.RH;
	  mem[r].hhfield.v.RH = 0;
	;
#ifdef STAT
	  incr (dyn_used);
#endif /* STAT */
	} 
      } 
      mem[r].hhfield.v.RH = mem[p + 1].hhfield.lhfield;
      mem[r].hhfield.lhfield = edgeandweight;
      if (internal[10] > 0) 
      trace_new_edge (r , n);
      mem[p + 1].hhfield.lhfield = r;
      p = mem[p].hhfield.lhfield;
      decr (j);
      decr (n);
    } 
    edgeandweight = edgeandweight + dx;
    incr (k);
  } while (!(k > delta));
  goto done;
  done: mem[cur_edges + 5].hhfield.lhfield = n + 4096;
  mem[cur_edges + 5].hhfield.v.RH = p;
} 
void 
zskew (scaled x , scaled y , small_number octant) 
{
  switch (octant) 
  {case 1 : 
    {
      cur_x = x - y;
      cur_y = y;
    } 
    break;
  case 5 : 
    {
      cur_x = y - x;
      cur_y = x;
    } 
    break;
  case 6 : 
    {
      cur_x = y + x;
      cur_y = - (integer) x;
    } 
    break;
  case 2 : 
    {
      cur_x = - (integer) x - y;
      cur_y = y;
    } 
    break;
  case 4 : 
    {
      cur_x = - (integer) x + y;
      cur_y = - (integer) y;
    } 
    break;
  case 8 : 
    {
      cur_x = - (integer) y + x;
      cur_y = - (integer) x;
    } 
    break;
  case 7 : 
    {
      cur_x = - (integer) y - x;
      cur_y = x;
    } 
    break;
  case 3 : 
    {
      cur_x = x + y;
      cur_y = - (integer) y;
    } 
    break;
  } 
} 
void 
zabnegate (scaled x , scaled y , small_number octantbefore , small_number 
octantafter) 
{
  if (odd (octantbefore) == odd (octantafter)) 
  cur_x = x;
  else cur_x = - (integer) x;
  if ((octantbefore > 2) == (octantafter > 2)) 
  cur_y = y;
  else cur_y = - (integer) y;
} 
fraction 
zcrossingpoint (integer a , integer b , integer c) 
{
  /* 10 */ register fraction Result; integer d;
  integer x, xx, x0, x1, x2;
  if (a < 0) 
  {
    Result = 0;
    goto lab10;
  } 
  if (c >= 0) 
  {
    if (b >= 0) {
	
      if (c > 0) 
      {
	Result = 268435457L;
	goto lab10;
      } 
      else if ((a == 0) && (b == 0)) 
      {
	Result = 268435457L;
	goto lab10;
      } 
      else {
	  
	Result = 268435456L;
	goto lab10;
      } 
    } 
    if (a == 0) 
    {
      Result = 0;
      goto lab10;
    } 
  } 
  else if (a == 0) {
      
    if (b <= 0) 
    {
      Result = 0;
      goto lab10;
    } 
  } 
  d = 1;
  x0 = a;
  x1 = a - b;
  x2 = b - c;
  do {
      x = half (x1 + x2);
    if (x1 - x0 > x0) 
    {
      x2 = x;
      x0 = x0 + x0;
      d = d + d;
    } 
    else {
	
      xx = x1 + x - x0;
      if (xx > x0) 
      {
	x2 = x;
	x0 = x0 + x0;
	d = d + d;
      } 
      else {
	  
	x0 = x0 - xx;
	if (x <= x0) {
	    
	  if (x + x2 <= x0) 
	  {
	    Result = 268435457L;
	    goto lab10;
	  } 
	} 
	x1 = x;
	d = d + d + 1;
      } 
    } 
  } while (!(d >= 268435456L));
  Result = d - 268435456L;
  lab10:;
  return Result;
} 
void 
zprintspec (str_number s) 
{
  /* 45 30 */ halfword p, q;
  small_number octant;
  print_diagnostic (544 , s , true);
  p = cur_spec;
  octant = mem[p + 3].cint;
  print_ln ();
  unskew (mem[cur_spec + 1].cint , mem[cur_spec + 2].cint , octant);
  print_two (cur_x , cur_y);
  print (545);
  while (true) {
      
    print (octant_dir[octant]);
    print_char (39);
    while (true) {
	
      q = mem[p].hhfield.v.RH;
      if (mem[p].hhfield.b1 == 0) 
      goto not_found;
      {
	print_nl (556);
	unskew (mem[p + 5].cint , mem[p + 6].cint , octant);
	print_two (cur_x , cur_y);
	print (523);
	unskew (mem[q + 3].cint , mem[q + 4].cint , octant);
	print_two (cur_x , cur_y);
	print_nl (520);
	unskew (mem[q + 1].cint , mem[q + 2].cint , octant);
	print_two (cur_x , cur_y);
	print (557);
	print_int (mem[q].hhfield.b0 - 1);
      } 
      p = q;
    } 
    not_found: if (q == cur_spec) 
    goto done;
    p = q;
    octant = mem[p + 3].cint;
    print_nl (546);
  } 
  done: print_nl (547);
  end_diagnostic (true);
} 
void 
zprintstrange (str_number s) 
{
  halfword p;
  halfword f;
  halfword q;
  integer t;
  if (interaction == 3) 
;
  print_nl (62);
  p = cur_spec;
  t = 256;
  do {
      p = mem[p].hhfield.v.RH;
    if (mem[p].hhfield.b0 != 0) 
    {
      if (mem[p].hhfield.b0 < t) 
      f = p;
      t = mem[p].hhfield.b0;
    } 
  } while (!(p == cur_spec));
  p = cur_spec;
  q = p;
  do {
      p = mem[p].hhfield.v.RH;
    if (mem[p].hhfield.b0 == 0) 
    q = p;
  } while (!(p == f));
  t = 0;
  do {
      if (mem[p].hhfield.b0 != 0) 
    {
      if (mem[p].hhfield.b0 != t) 
      {
	t = mem[p].hhfield.b0;
	print_char (32);
	print_int (t - 1);
      } 
      if (q != 0) 
      {
	if (mem[mem[q].hhfield.v.RH].hhfield.b0 == 0) 
	{
	  print (558);
	  print (octant_dir[mem[q + 3].cint]);
	  q = mem[q].hhfield.v.RH;
	  while (mem[mem[q].hhfield.v.RH].hhfield.b0 == 0) {
	      
	    print_char (32);
	    print (octant_dir[mem[q + 3].cint]);
	    q = mem[q].hhfield.v.RH;
	  } 
	  print_char (41);
	} 
	print_char (32);
	print (octant_dir[mem[q + 3].cint]);
	q = 0;
      } 
    } 
    else if (q == 0) 
    q = p;
    p = mem[p].hhfield.v.RH;
  } while (!(p == f));
  print_char (32);
  print_int (mem[p].hhfield.b0 - 1);
  if (q != 0) {
      
    if (mem[mem[q].hhfield.v.RH].hhfield.b0 == 0) 
    {
      print (558);
      print (octant_dir[mem[q + 3].cint]);
      q = mem[q].hhfield.v.RH;
      while (mem[mem[q].hhfield.v.RH].hhfield.b0 == 0) {
	  
	print_char (32);
	print (octant_dir[mem[q + 3].cint]);
	q = mem[q].hhfield.v.RH;
      } 
      print_char (41);
    } 
  } 
  {
    if (interaction == 3) 
;
    if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
    {
      print_nl (261);
      print (fullsourcefilenamestack[in_open]);
      print (58);
      print_int (line);
      print (262);
      print (s);
    } 
    else {
	
      print_nl (263);
      print (s);
    } 
  } 
} 
void 
zremovecubic (halfword p) 
{
  halfword q;
  q = mem[p].hhfield.v.RH;
  mem[p].hhfield.b1 = mem[q].hhfield.b1;
  mem[p].hhfield.v.RH = mem[q].hhfield.v.RH;
  mem[p + 1].cint = mem[q + 1].cint;
  mem[p + 2].cint = mem[q + 2].cint;
  mem[p + 5].cint = mem[q + 5].cint;
  mem[p + 6].cint = mem[q + 6].cint;
  free_node (q , 7);
} 
void 
zsplitcubic (halfword p , fraction t , scaled xq , scaled yq) 
{
  scaled v;
  halfword q, r;
  q = mem[p].hhfield.v.RH;
  r = get_node (7);
  mem[p].hhfield.v.RH = r;
  mem[r].hhfield.v.RH = q;
  mem[r].hhfield.b0 = mem[q].hhfield.b0;
  mem[r].hhfield.b1 = mem[p].hhfield.b1;
  v = mem[p + 5].cint - takefraction (mem[p + 5].cint - mem[q + 3]
  .cint , t);
  mem[p + 5].cint = mem[p + 1].cint - takefraction (mem[p + 1]
  .cint - mem[p + 5].cint , t);
  mem[q + 3].cint = mem[q + 3].cint - takefraction (mem[q + 3]
  .cint - xq , t);
  mem[r + 3].cint = mem[p + 5].cint - takefraction (mem[p + 5]
  .cint - v , t);
  mem[r + 5].cint = v - takefraction (v - mem[q + 3].cint , t);
  mem[r + 1].cint = mem[r + 3].cint - takefraction (mem[r + 3]
  .cint - mem[r + 5].cint , t);
  v = mem[p + 6].cint - takefraction (mem[p + 6].cint - mem[q + 4]
  .cint , t);
  mem[p + 6].cint = mem[p + 2].cint - takefraction (mem[p + 2]
  .cint - mem[p + 6].cint , t);
  mem[q + 4].cint = mem[q + 4].cint - takefraction (mem[q + 4]
  .cint - yq , t);
  mem[r + 4].cint = mem[p + 6].cint - takefraction (mem[p + 6]
  .cint - v , t);
  mem[r + 6].cint = v - takefraction (v - mem[q + 4].cint , t);
  mem[r + 2].cint = mem[r + 4].cint - takefraction (mem[r + 4]
  .cint - mem[r + 6].cint , t);
} 
void 
quadrantsubdivide (void) 
{
  /* 22 10 */ halfword p, q, r, s, pp, qq;
  scaled firstx, firsty;
  scaled del1, del2, del3, del, dmax;
  fraction t;
  scaled destx, desty;
  boolean constantx;
  p = cur_spec;
  firstx = mem[cur_spec + 1].cint;
  firsty = mem[cur_spec + 2].cint;
  do {
      lab22: q = mem[p].hhfield.v.RH;
    if (q == cur_spec) 
    {
      destx = firstx;
      desty = firsty;
    } 
    else {
	
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
    else del = del3;
    if (del != 0) 
    {
      dmax = abs (del1);
      if (abs (del2) > dmax) 
      dmax = abs (del2);
      if (abs (del3) > dmax) 
      dmax = abs (del3);
      while (dmax < 134217728L) {
	  
	dmax = dmax + dmax;
	del1 = del1 + del1;
	del2 = del2 + del2;
	del3 = del3 + del3;
      } 
    } 
    if (del == 0) 
    constantx = true;
    else {
	
      constantx = false;
      if (del < 0) 
      {
	mem[p + 1].cint = - (integer) mem[p + 1].cint;
	mem[p + 5].cint = - (integer) mem[p + 5].cint;
	mem[q + 3].cint = - (integer) mem[q + 3].cint;
	del1 = - (integer) del1;
	del2 = - (integer) del2;
	del3 = - (integer) del3;
	destx = - (integer) destx;
	mem[p].hhfield.b1 = 2;
      } 
      t = crossingpoint (del1 , del2 , del3);
      if (t < 268435456L) 
      {
	splitcubic (p , t , destx , desty);
	r = mem[p].hhfield.v.RH;
	if (mem[r].hhfield.b1 > 1) 
	mem[r].hhfield.b1 = 1;
	else mem[r].hhfield.b1 = 2;
	if (mem[r + 1].cint < mem[p + 1].cint) 
	mem[r + 1].cint = mem[p + 1].cint;
	mem[r + 3].cint = mem[r + 1].cint;
	if (mem[p + 5].cint > mem[r + 1].cint) 
	mem[p + 5].cint = mem[r + 1].cint;
	mem[r + 1].cint = - (integer) mem[r + 1].cint;
	mem[r + 5].cint = mem[r + 1].cint;
	mem[q + 3].cint = - (integer) mem[q + 3].cint;
	destx = - (integer) destx;
	del2 = del2 - takefraction (del2 - del3 , t);
	if (del2 > 0) 
	del2 = 0;
	t = crossingpoint (0 , - (integer) del2 , - (integer) del3);
	if (t < 268435456L) 
	{
	  splitcubic (r , t , destx , desty);
	  s = mem[r].hhfield.v.RH;
	  if (mem[s + 1].cint < destx) 
	  mem[s + 1].cint = destx;
	  if (mem[s + 1].cint < mem[r + 1].cint) 
	  mem[s + 1].cint = mem[r + 1].cint;
	  mem[s].hhfield.b1 = mem[p].hhfield.b1;
	  mem[s + 3].cint = mem[s + 1].cint;
	  if (mem[q + 3].cint < destx) 
	  mem[q + 3].cint = - (integer) destx;
	  else if (mem[q + 3].cint > mem[s + 1].cint) 
	  mem[q + 3].cint = - (integer) mem[s + 1].cint;
	  else mem[q + 3].cint = - (integer) mem[q + 3].cint;
	  mem[s + 1].cint = - (integer) mem[s + 1].cint;
	  mem[s + 5].cint = mem[s + 1].cint;
	} 
	else {
	    
	  if (mem[r + 1].cint > destx) 
	  {
	    mem[r + 1].cint = destx;
	    mem[r + 3].cint = - (integer) mem[r + 1].cint;
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
	qq = mem[pp].hhfield.v.RH;
      abnegate (mem[qq + 1].cint , mem[qq + 2].cint , mem[qq]
      .hhfield.b1 , mem[pp].hhfield.b1);
      destx = cur_x;
      desty = cur_y;
      del1 = mem[pp + 6].cint - mem[pp + 2].cint;
      del2 = mem[qq + 4].cint - mem[pp + 6].cint;
      del3 = desty - mem[qq + 4].cint;
      if (del1 != 0) 
      del = del1;
      else if (del2 != 0) 
      del = del2;
      else del = del3;
      if (del != 0) 
      {
	dmax = abs (del1);
	if (abs (del2) > dmax) 
	dmax = abs (del2);
	if (abs (del3) > dmax) 
	dmax = abs (del3);
	while (dmax < 134217728L) {
	    
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
	  mem[pp + 2].cint = - (integer) mem[pp + 2].cint;
	  mem[pp + 6].cint = - (integer) mem[pp + 6].cint;
	  mem[qq + 4].cint = - (integer) mem[qq + 4].cint;
	  del1 = - (integer) del1;
	  del2 = - (integer) del2;
	  del3 = - (integer) del3;
	  desty = - (integer) desty;
	  mem[pp].hhfield.b1 = mem[pp].hhfield.b1 + 2;
	} 
	t = crossingpoint (del1 , del2 , del3);
	if (t < 268435456L) 
	{
	  splitcubic (pp , t , destx , desty);
	  r = mem[pp].hhfield.v.RH;
	  if (mem[r].hhfield.b1 > 2) 
	  mem[r].hhfield.b1 = mem[r].hhfield.b1 - 2;
	  else mem[r].hhfield.b1 = mem[r].hhfield.b1 + 2;
	  if (mem[r + 2].cint < mem[pp + 2].cint) 
	  mem[r + 2].cint = mem[pp + 2].cint;
	  mem[r + 4].cint = mem[r + 2].cint;
	  if (mem[pp + 6].cint > mem[r + 2].cint) 
	  mem[pp + 6].cint = mem[r + 2].cint;
	  mem[r + 2].cint = - (integer) mem[r + 2].cint;
	  mem[r + 6].cint = mem[r + 2].cint;
	  mem[qq + 4].cint = - (integer) mem[qq + 4].cint;
	  desty = - (integer) desty;
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
	  del2 = del2 - takefraction (del2 - del3 , t);
	  if (del2 > 0) 
	  del2 = 0;
	  t = crossingpoint (0 , - (integer) del2 , - (integer) del3);
	  if (t < 268435456L) 
	  {
	    splitcubic (r , t , destx , desty);
	    s = mem[r].hhfield.v.RH;
	    if (mem[s + 2].cint < desty) 
	    mem[s + 2].cint = desty;
	    if (mem[s + 2].cint < mem[r + 2].cint) 
	    mem[s + 2].cint = mem[r + 2].cint;
	    mem[s].hhfield.b1 = mem[pp].hhfield.b1;
	    mem[s + 4].cint = mem[s + 2].cint;
	    if (mem[qq + 4].cint < desty) 
	    mem[qq + 4].cint = - (integer) desty;
	    else if (mem[qq + 4].cint > mem[s + 2].cint) 
	    mem[qq + 4].cint = - (integer) mem[s + 2].cint;
	    else mem[qq + 4].cint = - (integer) mem[qq + 4].cint;
	    mem[s + 2].cint = - (integer) mem[s + 2].cint;
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
	  else {
	      
	    if (mem[r + 2].cint > desty) 
	    {
	      mem[r + 2].cint = desty;
	      mem[r + 4].cint = - (integer) mem[r + 2].cint;
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
	  removecubic (p);
	  if (cur_spec != q) 
	  goto lab22;
	  else {
	      
	    cur_spec = p;
	    goto lab10;
	  } 
	} 
      } 
      else if (!odd (mem[pp].hhfield.b1)) 
      {
	mem[pp + 2].cint = - (integer) mem[pp + 2].cint;
	mem[pp + 6].cint = - (integer) mem[pp + 6].cint;
	mem[qq + 4].cint = - (integer) mem[qq + 4].cint;
	del1 = - (integer) del1;
	del2 = - (integer) del2;
	del3 = - (integer) del3;
	desty = - (integer) desty;
	mem[pp].hhfield.b1 = mem[pp].hhfield.b1 + 2;
      } 
      pp = qq;
    } while (!(pp == q));
    if (constantx) 
    {
      pp = p;
      do {
	  qq = mem[pp].hhfield.v.RH;
	if (mem[pp].hhfield.b1 > 2) 
	{
	  mem[pp].hhfield.b1 = mem[pp].hhfield.b1 + 1;
	  mem[pp + 1].cint = - (integer) mem[pp + 1].cint;
	  mem[pp + 5].cint = - (integer) mem[pp + 5].cint;
	  mem[qq + 3].cint = - (integer) mem[qq + 3].cint;
	} 
	pp = qq;
      } while (!(pp == q));
    } 
    p = q;
  } while (!(p == cur_spec));
  lab10:;
} 
void 
octantsubdivide (void) 
{
  halfword p, q, r, s;
  scaled del1, del2, del3, del, dmax;
  fraction t;
  scaled destx, desty;
  p = cur_spec;
  do {
      q = mem[p].hhfield.v.RH;
    mem[p + 1].cint = mem[p + 1].cint - mem[p + 2].cint;
    mem[p + 5].cint = mem[p + 5].cint - mem[p + 6].cint;
    mem[q + 3].cint = mem[q + 3].cint - mem[q + 4].cint;
    if (q == cur_spec) 
    {
      unskew (mem[q + 1].cint , mem[q + 2].cint , mem[q].hhfield 
     .b1);
      skew (cur_x , cur_y , mem[p].hhfield.b1);
      destx = cur_x;
      desty = cur_y;
    } 
    else {
	
      abnegate (mem[q + 1].cint , mem[q + 2].cint , mem[q]
      .hhfield.b1 , mem[p].hhfield.b1);
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
    else del = del3;
    if (del != 0) 
    {
      dmax = abs (del1);
      if (abs (del2) > dmax) 
      dmax = abs (del2);
      if (abs (del3) > dmax) 
      dmax = abs (del3);
      while (dmax < 134217728L) {
	  
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
	mem[p + 1].cint = - (integer) mem[p + 1].cint;
	mem[p + 6].cint = mem[p + 5].cint + mem[p + 6].cint;
	mem[p + 5].cint = - (integer) mem[p + 5].cint;
	mem[q + 4].cint = mem[q + 3].cint + mem[q + 4].cint;
	mem[q + 3].cint = - (integer) mem[q + 3].cint;
	del1 = - (integer) del1;
	del2 = - (integer) del2;
	del3 = - (integer) del3;
	desty = destx + desty;
	destx = - (integer) destx;
	mem[p].hhfield.b1 = mem[p].hhfield.b1 + 4;
      } 
      t = crossingpoint (del1 , del2 , del3);
      if (t < 268435456L) 
      {
	splitcubic (p , t , destx , desty);
	r = mem[p].hhfield.v.RH;
	if (mem[r].hhfield.b1 > 4) 
	mem[r].hhfield.b1 = mem[r].hhfield.b1 - 4;
	else mem[r].hhfield.b1 = mem[r].hhfield.b1 + 4;
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
	mem[r + 1].cint = - (integer) mem[r + 1].cint;
	mem[r + 5].cint = mem[r + 1].cint;
	mem[q + 4].cint = mem[q + 4].cint + mem[q + 3].cint;
	mem[q + 3].cint = - (integer) mem[q + 3].cint;
	desty = desty + destx;
	destx = - (integer) destx;
	if (mem[r + 6].cint < mem[r + 2].cint) 
	{
	  mem[r + 6].cint = mem[r + 2].cint;
	  if (mem[q + 4].cint < mem[r + 2].cint) 
	  mem[q + 4].cint = mem[r + 2].cint;
	} 
	del2 = del2 - takefraction (del2 - del3 , t);
	if (del2 > 0) 
	del2 = 0;
	t = crossingpoint (0 , - (integer) del2 , - (integer) del3);
	if (t < 268435456L) 
	{
	  splitcubic (r , t , destx , desty);
	  s = mem[r].hhfield.v.RH;
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
	  else {
	      
	    if (mem[s + 1].cint < destx) 
	    mem[s + 1].cint = destx;
	    if (mem[s + 1].cint < mem[r + 1].cint) 
	    mem[s + 1].cint = mem[r + 1].cint;
	  } 
	  mem[s].hhfield.b1 = mem[p].hhfield.b1;
	  mem[s + 3].cint = mem[s + 1].cint;
	  if (mem[q + 3].cint < destx) 
	  {
	    mem[q + 4].cint = mem[q + 4].cint + destx;
	    mem[q + 3].cint = - (integer) destx;
	  } 
	  else if (mem[q + 3].cint > mem[s + 1].cint) 
	  {
	    mem[q + 4].cint = mem[q + 4].cint + mem[s + 1].cint;
	    mem[q + 3].cint = - (integer) mem[s + 1].cint;
	  } 
	  else {
	      
	    mem[q + 4].cint = mem[q + 4].cint + mem[q + 3].cint;
	    mem[q + 3].cint = - (integer) mem[q + 3].cint;
	  } 
	  mem[s + 2].cint = mem[s + 2].cint + mem[s + 1].cint;
	  mem[s + 6].cint = mem[s + 6].cint + mem[s + 1].cint;
	  mem[s + 1].cint = - (integer) mem[s + 1].cint;
	  mem[s + 5].cint = mem[s + 1].cint;
	  if (mem[s + 6].cint < mem[s + 2].cint) 
	  {
	    mem[s + 6].cint = mem[s + 2].cint;
	    if (mem[q + 4].cint < mem[s + 2].cint) 
	    mem[q + 4].cint = mem[s + 2].cint;
	  } 
	} 
	else {
	    
	  if (mem[r + 1].cint > destx) 
	  {
	    mem[r + 1].cint = destx;
	    mem[r + 3].cint = - (integer) mem[r + 1].cint;
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
void 
makesafe (void) 
{
  integer k;
  boolean allsafe;
  scaled nexta;
  scaled deltaa, deltab;
  before[cur_rounding_ptr] = before[0];
  node_to_round[cur_rounding_ptr] = node_to_round[0];
  do {
      after[cur_rounding_ptr] = after[0];
    allsafe = true;
    nexta = after[0];
    {register integer for_end; k = 0;for_end = cur_rounding_ptr - 1; if (k 
    <= for_end) do 
      {
	deltab = before[k + 1] - before[k];
	if (deltab >= 0) 
	deltaa = after[k + 1] - nexta;
	else deltaa = nexta - after[k + 1];
	nexta = after[k + 1];
	if ((deltaa < 0) || (deltaa > abs (deltab + deltab))) 
	{
	  allsafe = false;
	  after[k] = before[k];
	  if (k == cur_rounding_ptr - 1) 
	  after[0] = before[0];
	  else after[k + 1] = before[k + 1];
	} 
      } 
    while (k++ < for_end);} 
  } while (!(allsafe));
} 
void 
zbeforeandafter (scaled b , scaled a , halfword p) 
{
  if (cur_rounding_ptr == max_rounding_ptr) {
      
    if (max_rounding_ptr < max_wiggle) 
    incr (max_rounding_ptr);
    else overflow (568 , max_wiggle);
  } 
  after[cur_rounding_ptr] = a;
  before[cur_rounding_ptr] = b;
  node_to_round[cur_rounding_ptr] = p;
  incr (cur_rounding_ptr);
} 
scaled 
zgoodval (scaled b , scaled o) 
{
  register scaled Result; scaled a;
  a = b + o;
  if (a >= 0) 
  a = a - (a % cur_gran) - o;
  else a = a + ((- (integer) (a + 1)) % cur_gran) - cur_gran + 1 - o;
  if (b - a < a + cur_gran - b) 
  Result = a;
  else Result = a + cur_gran;
  return Result;
} 
scaled 
zcompromise (scaled u , scaled v) 
{
  register scaled Result; Result = half (goodval (u + u , - (integer) u - 
  v));
  return Result;
} 
void 
xyround (void) 
{
  halfword p, q;
  scaled b, a;
  scaled penedge;
  fraction alpha;
  cur_gran = abs (internal[37]);
  if (cur_gran == 0) 
  cur_gran = 65536L;
  p = cur_spec;
  cur_rounding_ptr = 0;
  do {
      q = mem[p].hhfield.v.RH;
    if (odd (mem[p].hhfield.b1) != odd (mem[q].hhfield.b1)) 
    {
      if (odd (mem[q].hhfield.b1)) 
      b = mem[q + 1].cint;
      else b = - (integer) mem[q + 1].cint;
      if ((abs (mem[q + 1].cint - mem[q + 5].cint) < 655) || (
      abs (mem[q + 1].cint + mem[q + 3].cint) < 655)) 
      {
	if (cur_pen == 3) 
	penedge = 0;
	else if (cur_path_type == 0) 
	penedge = compromise (mem[mem[cur_pen + 5].hhfield.v.RH + 2]
	.cint , mem[mem[cur_pen + 7].hhfield.v.RH + 2].cint);
	else if (odd (mem[q].hhfield.b1)) 
	penedge = mem[mem[cur_pen + 7].hhfield.v.RH + 2].cint;
	else penedge = mem[mem[cur_pen + 5].hhfield.v.RH + 2].cint;
	a = goodval (b , penedge);
      } 
      else a = b;
      if (abs (a) > max_allowed) {
	  
	if (a > 0) 
	a = max_allowed;
	else a = - (integer) max_allowed;
      } 
      beforeandafter (b , a , q);
    } 
    p = q;
  } while (!(p == cur_spec));
  if (cur_rounding_ptr > 0) 
  {
    makesafe ();
    do {
	decr (cur_rounding_ptr);
      if ((after[cur_rounding_ptr]!= before[cur_rounding_ptr]) || (
      after[cur_rounding_ptr + 1]!= before[cur_rounding_ptr + 1])) 
      {
	p = node_to_round[cur_rounding_ptr];
	if (odd (mem[p].hhfield.b1)) 
	{
	  b = before[cur_rounding_ptr];
	  a = after[cur_rounding_ptr];
	} 
	else {
	    
	  b = - (integer) before[cur_rounding_ptr];
	  a = - (integer) after[cur_rounding_ptr];
	} 
	if (before[cur_rounding_ptr] == before[cur_rounding_ptr + 1]) 
	alpha = 268435456L;
	else alpha = makefraction (after[cur_rounding_ptr + 1] - after[
	cur_rounding_ptr], before[cur_rounding_ptr + 1] - before[
	cur_rounding_ptr]);
	do {
	    mem[p + 1].cint = takefraction (alpha , mem[p + 1].cint 
	  - b) + a;
	  mem[p + 5].cint = takefraction (alpha , mem[p + 5].cint - b 
	) + a;
	  p = mem[p].hhfield.v.RH;
	  mem[p + 3].cint = takefraction (alpha , mem[p + 3].cint - b 
	) + a;
	} while (!(p == node_to_round[cur_rounding_ptr + 1]));
      } 
    } while (!(cur_rounding_ptr == 0));
  } 
  p = cur_spec;
  cur_rounding_ptr = 0;
  do {
      q = mem[p].hhfield.v.RH;
    if ((mem[p].hhfield.b1 > 2) != (mem[q].hhfield.b1 > 2)) 
    {
      if (mem[q].hhfield.b1 <= 2) 
      b = mem[q + 2].cint;
      else b = - (integer) mem[q + 2].cint;
      if ((abs (mem[q + 2].cint - mem[q + 6].cint) < 655) || (
      abs (mem[q + 2].cint + mem[q + 4].cint) < 655)) 
      {
	if (cur_pen == 3) 
	penedge = 0;
	else if (cur_path_type == 0) 
	penedge = compromise (mem[mem[cur_pen + 2].hhfield.v.RH + 2]
	.cint , mem[mem[cur_pen + 1].hhfield.v.RH + 2].cint);
	else if (mem[q].hhfield.b1 <= 2) 
	penedge = mem[mem[cur_pen + 1].hhfield.v.RH + 2].cint;
	else penedge = mem[mem[cur_pen + 2].hhfield.v.RH + 2].cint;
	a = goodval (b , penedge);
      } 
      else a = b;
      if (abs (a) > max_allowed) {
	  
	if (a > 0) 
	a = max_allowed;
	else a = - (integer) max_allowed;
      } 
      beforeandafter (b , a , q);
    } 
    p = q;
  } while (!(p == cur_spec));
  if (cur_rounding_ptr > 0) 
  {
    makesafe ();
    do {
	decr (cur_rounding_ptr);
      if ((after[cur_rounding_ptr]!= before[cur_rounding_ptr]) || (
      after[cur_rounding_ptr + 1]!= before[cur_rounding_ptr + 1])) 
      {
	p = node_to_round[cur_rounding_ptr];
	if (mem[p].hhfield.b1 <= 2) 
	{
	  b = before[cur_rounding_ptr];
	  a = after[cur_rounding_ptr];
	} 
	else {
	    
	  b = - (integer) before[cur_rounding_ptr];
	  a = - (integer) after[cur_rounding_ptr];
	} 
	if (before[cur_rounding_ptr] == before[cur_rounding_ptr + 1]) 
	alpha = 268435456L;
	else alpha = makefraction (after[cur_rounding_ptr + 1] - after[
	cur_rounding_ptr], before[cur_rounding_ptr + 1] - before[
	cur_rounding_ptr]);
	do {
	    mem[p + 2].cint = takefraction (alpha , mem[p + 2].cint 
	  - b) + a;
	  mem[p + 6].cint = takefraction (alpha , mem[p + 6].cint - b 
	) + a;
	  p = mem[p].hhfield.v.RH;
	  mem[p + 4].cint = takefraction (alpha , mem[p + 4].cint - b 
	) + a;
	} while (!(p == node_to_round[cur_rounding_ptr + 1]));
      } 
    } while (!(cur_rounding_ptr == 0));
  } 
} 
void 
diaground (void) 
{
  halfword p, q, pp;
  scaled b, a, bb, aa, d, c, dd, cc;
  scaled penedge;
  fraction alpha, beta;
  scaled nexta;
  boolean allsafe;
  integer k;
  scaled firstx, firsty;
  p = cur_spec;
  cur_rounding_ptr = 0;
  do {
      q = mem[p].hhfield.v.RH;
    if (mem[p].hhfield.b1 != mem[q].hhfield.b1) 
    {
      if (mem[q].hhfield.b1 > 4) 
      b = - (integer) mem[q + 1].cint;
      else b = mem[q + 1].cint;
      if (abs (mem[q].hhfield.b1 - mem[p].hhfield.b1) == 4) {
	  
	if ((abs (mem[q + 1].cint - mem[q + 5].cint) < 655) || (
	abs (mem[q + 1].cint + mem[q + 3].cint) < 655)) 
	{
	  if (cur_pen == 3) 
	  penedge = 0;
	  else if (cur_path_type == 0) 
	  switch (mem[q].hhfield.b1) 
	  {case 1 : 
	  case 5 : 
	    penedge = compromise (mem[mem[mem[cur_pen + 1].hhfield 
	  .v.RH].hhfield.lhfield + 1].cint , - (integer) mem[mem[
	    mem[cur_pen + 4].hhfield.v.RH].hhfield.lhfield + 1].cint 
	 );
	    break;
	  case 4 : 
	  case 8 : 
	    penedge = - (integer) compromise (mem[mem[mem[cur_pen + 1]
	    .hhfield.v.RH].hhfield.lhfield + 1].cint , - (integer) mem[
	    mem[mem[cur_pen + 4].hhfield.v.RH].hhfield.lhfield + 1]
	    .cint);
	    break;
	  case 6 : 
	  case 2 : 
	    penedge = compromise (mem[mem[mem[cur_pen + 2].hhfield 
	  .v.RH].hhfield.lhfield + 1].cint , - (integer) mem[mem[
	    mem[cur_pen + 3].hhfield.v.RH].hhfield.lhfield + 1].cint 
	 );
	    break;
	  case 7 : 
	  case 3 : 
	    penedge = - (integer) compromise (mem[mem[mem[cur_pen + 2]
	    .hhfield.v.RH].hhfield.lhfield + 1].cint , - (integer) mem[
	    mem[mem[cur_pen + 3].hhfield.v.RH].hhfield.lhfield + 1]
	    .cint);
	    break;
	  } 
	  else if (mem[q].hhfield.b1 <= 4) 
	  penedge = mem[mem[mem[cur_pen + mem[q].hhfield.b1]
	  .hhfield.v.RH].hhfield.lhfield + 1].cint;
	  else penedge = - (integer) mem[mem[mem[cur_pen + mem[q]
	  .hhfield.b1].hhfield.v.RH].hhfield.lhfield + 1].cint;
	  if (odd (mem[q].hhfield.b1)) 
	  a = goodval (b , penedge + halfp (cur_gran));
	  else a = goodval (b - 1 , penedge + halfp (cur_gran));
	} 
	else a = b;
      } 
      else a = b;
      beforeandafter (b , a , q);
    } 
    p = q;
  } while (!(p == cur_spec));
  if (cur_rounding_ptr > 0) 
  {
    p = node_to_round[0];
    firstx = mem[p + 1].cint;
    firsty = mem[p + 2].cint;
    before[cur_rounding_ptr] = before[0];
    node_to_round[cur_rounding_ptr] = node_to_round[0];
    do {
	after[cur_rounding_ptr] = after[0];
      allsafe = true;
      nexta = after[0];
      {register integer for_end; k = 0;for_end = cur_rounding_ptr - 1; if (
      k <= for_end) do 
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
	      unskew (firstx , firsty , mem[pp].hhfield.b1);
	      else unskew (mem[pp + 1].cint , mem[pp + 2].cint , mem 
	    [pp].hhfield.b1);
	      skew (cur_x , cur_y , mem[p].hhfield.b1);
	      bb = cur_x;
	      aa = bb;
	      dd = cur_y;
	      cc = dd;
	      if (mem[p].hhfield.b1 > 4) 
	      {
		b = - (integer) b;
		a = - (integer) a;
	      } 
	    } 
	    else {
		
	      if (mem[p].hhfield.b1 > 4) 
	      {
		bb = - (integer) bb;
		aa = - (integer) aa;
		b = - (integer) b;
		a = - (integer) a;
	      } 
	      if (pp == node_to_round[0]) 
	      dd = firsty - bb;
	      else dd = mem[pp + 2].cint - bb;
	      if (odd (aa - bb)) {
		  
		if (mem[p].hhfield.b1 > 4) 
		cc = dd - half (aa - bb + 1);
		else cc = dd - half (aa - bb - 1);
	      } 
	      else cc = dd - half (aa - bb);
	    } 
	    d = mem[p + 2].cint;
	    if (odd (a - b)) {
		
	      if (mem[p].hhfield.b1 > 4) 
	      c = d - half (a - b - 1);
	      else c = d - half (a - b + 1);
	    } 
	    else c = d - half (a - b);
	    if ((aa < a) || (cc < c) || (aa - a > 2 * (bb - b)) || (
	    cc - c > 2 * (dd - d))) 
	    {
	      allsafe = false;
	      after[k] = before[k];
	      if (k == cur_rounding_ptr - 1) 
	      after[0] = before[0];
	      else after[k + 1] = before[k + 1];
	    } 
	  } 
	} 
      while (k++ < for_end);} 
    } while (!(allsafe));
    {register integer for_end; k = 0;for_end = cur_rounding_ptr - 1; if (k 
    <= for_end) do 
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
	    unskew (firstx , firsty , mem[pp].hhfield.b1);
	    else unskew (mem[pp + 1].cint , mem[pp + 2].cint , mem[
	    pp].hhfield.b1);
	    skew (cur_x , cur_y , mem[p].hhfield.b1);
	    bb = cur_x;
	    aa = bb;
	    dd = cur_y;
	    cc = dd;
	    if (mem[p].hhfield.b1 > 4) 
	    {
	      b = - (integer) b;
	      a = - (integer) a;
	    } 
	  } 
	  else {
	      
	    if (mem[p].hhfield.b1 > 4) 
	    {
	      bb = - (integer) bb;
	      aa = - (integer) aa;
	      b = - (integer) b;
	      a = - (integer) a;
	    } 
	    if (pp == node_to_round[0]) 
	    dd = firsty - bb;
	    else dd = mem[pp + 2].cint - bb;
	    if (odd (aa - bb)) {
		
	      if (mem[p].hhfield.b1 > 4) 
	      cc = dd - half (aa - bb + 1);
	      else cc = dd - half (aa - bb - 1);
	    } 
	    else cc = dd - half (aa - bb);
	  } 
	  d = mem[p + 2].cint;
	  if (odd (a - b)) {
	      
	    if (mem[p].hhfield.b1 > 4) 
	    c = d - half (a - b - 1);
	    else c = d - half (a - b + 1);
	  } 
	  else c = d - half (a - b);
	  if (b == bb) 
	  alpha = 268435456L;
	  else alpha = makefraction (aa - a , bb - b);
	  if (d == dd) 
	  beta = 268435456L;
	  else beta = makefraction (cc - c , dd - d);
	  do {
	      mem[p + 1].cint = takefraction (alpha , mem[p + 1]
	    .cint - b) + a;
	    mem[p + 2].cint = takefraction (beta , mem[p + 2].cint - 
	    d) + c;
	    mem[p + 5].cint = takefraction (alpha , mem[p + 5].cint - 
	    b) + a;
	    mem[p + 6].cint = takefraction (beta , mem[p + 6].cint - 
	    d) + c;
	    p = mem[p].hhfield.v.RH;
	    mem[p + 3].cint = takefraction (alpha , mem[p + 3].cint - 
	    b) + a;
	    mem[p + 4].cint = takefraction (beta , mem[p + 4].cint - 
	    d) + c;
	  } while (!(p == pp));
	} 
      } 
    while (k++ < for_end);} 
  } 
} 
void 
znewboundary (halfword p , small_number octant) 
{
  halfword q, r;
  q = mem[p].hhfield.v.RH;
  r = get_node (7);
  mem[r].hhfield.v.RH = q;
  mem[p].hhfield.v.RH = r;
  mem[r].hhfield.b0 = mem[q].hhfield.b0;
  mem[r + 3].cint = mem[q + 3].cint;
  mem[r + 4].cint = mem[q + 4].cint;
  mem[r].hhfield.b1 = 0;
  mem[q].hhfield.b0 = 0;
  mem[r + 5].cint = octant;
  mem[q + 3].cint = mem[q].hhfield.b1;
  unskew (mem[q + 1].cint , mem[q + 2].cint , mem[q].hhfield.b1 
);
  skew (cur_x , cur_y , octant);
  mem[r + 1].cint = cur_x;
  mem[r + 2].cint = cur_y;
} 
halfword 
zmakespec (halfword h , scaled safetymargin , integer tracing) 
{
  /* 22 30 */ register halfword Result; halfword p, q, r, s;
  integer k;
  integer chopped;
  small_number o1, o2;
  boolean clockwise;
  integer dx1, dy1, dx2, dy2;
  integer dmax, del;
  cur_spec = h;
  if (tracing > 0) 
  print_path (cur_spec , 559 , true);
  max_allowed = 268402687L - safetymargin;
  p = cur_spec;
  k = 1;
  chopped = 0;
  dmax = half (max_allowed);
  do {
      if (abs (mem[p + 3].cint) >= dmax) { 
      if (abs (mem[p + 3].cint) > max_allowed) 
      {
	chopped = 1;
	if (mem[p + 3].cint > 0) 
	mem[p + 3].cint = max_allowed;
	else mem[p + 3].cint = - (integer) max_allowed;
      } 
      else if (chopped == 0) 
      chopped = -1;
    } 
    if (abs (mem[p + 4].cint) >= dmax) {
	
      if (abs (mem[p + 4].cint) > max_allowed) 
      {
	chopped = 1;
	if (mem[p + 4].cint > 0) 
	mem[p + 4].cint = max_allowed;
	else mem[p + 4].cint = - (integer) max_allowed;
      } 
      else if (chopped == 0) 
      chopped = -1;
    } 
    if (abs (mem[p + 1].cint) >= dmax) {
	
      if (abs (mem[p + 1].cint) > max_allowed) 
      {
	chopped = 1;
	if (mem[p + 1].cint > 0) 
	mem[p + 1].cint = max_allowed;
	else mem[p + 1].cint = - (integer) max_allowed;
      } 
      else if (chopped == 0) 
      chopped = -1;
    } 
    if (abs (mem[p + 2].cint) >= dmax) {
	
      if (abs (mem[p + 2].cint) > max_allowed) 
      {
	chopped = 1;
	if (mem[p + 2].cint > 0) 
	mem[p + 2].cint = max_allowed;
	else mem[p + 2].cint = - (integer) max_allowed;
      } 
      else if (chopped == 0) 
      chopped = -1;
    } 
    if (abs (mem[p + 5].cint) >= dmax) {
	
      if (abs (mem[p + 5].cint) > max_allowed) 
      {
	chopped = 1;
	if (mem[p + 5].cint > 0) 
	mem[p + 5].cint = max_allowed;
	else mem[p + 5].cint = - (integer) max_allowed;
      } 
      else if (chopped == 0) 
      chopped = -1;
    } 
    if (abs (mem[p + 6].cint) >= dmax) {
	
      if (abs (mem[p + 6].cint) > max_allowed) 
      {
	chopped = 1;
	if (mem[p + 6].cint > 0) 
	mem[p + 6].cint = max_allowed;
	else mem[p + 6].cint = - (integer) max_allowed;
      } 
      else if (chopped == 0) 
      chopped = -1;
    } 
    p = mem[p].hhfield.v.RH;
    mem[p].hhfield.b0 = k;
    if (k < 255) 
    incr (k);
    else k = 1;
  } while (!(p == cur_spec));
  if (chopped > 0) 
  {
    {
      if (interaction == 3) 
;
      if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[in_open]);
	print (58);
	print_int (line);
	print (262);
	print (563);
      } 
      else {
	  
	print_nl (263);
	print (563);
      } 
    } 
    {
      help_ptr = 4;
      help_line[3] = 564;
      help_line[2] = 565;
      help_line[1] = 566;
      help_line[0] = 567;
    } 
    put_get_error ();
  } 
  quadrantsubdivide ();
  if ((internal[36] > 0) && (chopped == 0)) 
  xyround ();
  octantsubdivide ();
  if ((internal[36] > 65536L) && (chopped == 0)) 
  diaground ();
  p = cur_spec;
  do {
      lab22: q = mem[p].hhfield.v.RH;
    if (p != q) 
    {
      if (mem[p + 1].cint == mem[p + 5].cint) {
	  
	if (mem[p + 2].cint == mem[p + 6].cint) {
	    
	  if (mem[p + 1].cint == mem[q + 3].cint) {
	      
	    if (mem[p + 2].cint == mem[q + 4].cint) 
	    {
	      unskew (mem[q + 1].cint , mem[q + 2].cint , mem[q]
	      .hhfield.b1);
	      skew (cur_x , cur_y , mem[p].hhfield.b1);
	      if (mem[p + 1].cint == cur_x) {
		  
		if (mem[p + 2].cint == cur_y) 
		{
		  removecubic (p);
		  if (q != cur_spec) 
		  goto lab22;
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
  q = mem[p].hhfield.v.RH;
  do {
      r = mem[q].hhfield.v.RH;
    if ((mem[p].hhfield.b1 != mem[q].hhfield.b1) || (q == r)) 
    {
      newboundary (p , mem[p].hhfield.b1);
      s = mem[p].hhfield.v.RH;
      o1 = octant_number[mem[p].hhfield.b1];
      o2 = octant_number[mem[q].hhfield.b1];
      switch (o2 - o1) 
      {case 1 : 
      case -7 : 
      case 7 : 
      case -1 : 
	goto done;
	break;
      case 2 : 
      case -6 : 
	clockwise = false;
	break;
      case 3 : 
      case -5 : 
      case 4 : 
      case -4 : 
      case 5 : 
      case -3 : 
	{
	  dx1 = mem[s + 1].cint - mem[s + 3].cint;
	  dy1 = mem[s + 2].cint - mem[s + 4].cint;
	  if (dx1 == 0) {
	      
	    if (dy1 == 0) 
	    {
	      dx1 = mem[s + 1].cint - mem[p + 5].cint;
	      dy1 = mem[s + 2].cint - mem[p + 6].cint;
	      if (dx1 == 0) {
		  
		if (dy1 == 0) 
		{
		  dx1 = mem[s + 1].cint - mem[p + 1].cint;
		  dy1 = mem[s + 2].cint - mem[p + 2].cint;
		} 
	      } 
	    } 
	  } 
	  dmax = abs (dx1);
	  if (abs (dy1) > dmax) 
	  dmax = abs (dy1);
	  while (dmax < 268435456L) {
	      
	    dmax = dmax + dmax;
	    dx1 = dx1 + dx1;
	    dy1 = dy1 + dy1;
	  } 
	  dx2 = mem[q + 5].cint - mem[q + 1].cint;
	  dy2 = mem[q + 6].cint - mem[q + 2].cint;
	  if (dx2 == 0) {
	      
	    if (dy2 == 0) 
	    {
	      dx2 = mem[r + 3].cint - mem[q + 1].cint;
	      dy2 = mem[r + 4].cint - mem[q + 2].cint;
	      if (dx2 == 0) {
		  
		if (dy2 == 0) 
		{
		  if (mem[r].hhfield.b1 == 0) 
		  {
		    cur_x = mem[r + 1].cint;
		    cur_y = mem[r + 2].cint;
		  } 
		  else {
		      
		    unskew (mem[r + 1].cint , mem[r + 2].cint , mem[
		    r].hhfield.b1);
		    skew (cur_x , cur_y , mem[q].hhfield.b1);
		  } 
		  dx2 = cur_x - mem[q + 1].cint;
		  dy2 = cur_y - mem[q + 2].cint;
		} 
	      } 
	    } 
	  } 
	  dmax = abs (dx2);
	  if (abs (dy2) > dmax) 
	  dmax = abs (dy2);
	  while (dmax < 268435456L) {
	      
	    dmax = dmax + dmax;
	    dx2 = dx2 + dx2;
	    dy2 = dy2 + dy2;
	  } 
	  unskew (dx1 , dy1 , mem[p].hhfield.b1);
	  del = pyth_add (cur_x , cur_y);
	  dx1 = makefraction (cur_x , del);
	  dy1 = makefraction (cur_y , del);
	  unskew (dx2 , dy2 , mem[q].hhfield.b1);
	  del = pyth_add (cur_x , cur_y);
	  dx2 = makefraction (cur_x , del);
	  dy2 = makefraction (cur_y , del);
	  del = takefraction (dx1 , dy2) - takefraction (dx2 , dy1);
	  if (del > 4684844L) 
	  clockwise = false;
	  else if (del < -4684844L) 
	  clockwise = true;
	  else clockwise = rev_turns;
	} 
	break;
      case 6 : 
      case -2 : 
	clockwise = true;
	break;
      case 0 : 
	clockwise = rev_turns;
	break;
      } 
      while (true) {
	  
	if (clockwise) {
	    
	  if (o1 == 1) 
	  o1 = 8;
	  else decr (o1);
	} 
	else if (o1 == 8) 
	o1 = 1;
	else incr (o1);
	if (o1 == o2) 
	goto done;
	newboundary (s , octant_code[o1]);
	s = mem[s].hhfield.v.RH;
	mem[s + 3].cint = mem[s + 5].cint;
      } 
      done: if (q == r) 
      {
	q = mem[q].hhfield.v.RH;
	r = q;
	p = s;
	mem[s].hhfield.v.RH = q;
	mem[q + 3].cint = mem[q + 5].cint;
	mem[q].hhfield.b0 = 0;
	free_node (cur_spec , 7);
	cur_spec = q;
      } 
      p = mem[p].hhfield.v.RH;
      do {
	  s = mem[p].hhfield.v.RH;
	o1 = octant_number[mem[p + 5].cint];
	o2 = octant_number[mem[s + 3].cint];
	if (abs (o1 - o2) == 1) 
	{
	  if (o2 < o1) 
	  o2 = o1;
	  if (odd (o2)) 
	  mem[p + 6].cint = 0;
	  else mem[p + 6].cint = 1;
	} 
	else {
	    
	  if (o1 == 8) 
	  incr (turning_number);
	  else decr (turning_number);
	  mem[p + 6].cint = 0;
	} 
	mem[s + 4].cint = mem[p + 6].cint;
	p = s;
      } while (!(p == q));
    } 
    p = q;
    q = r;
  } while (!(p == cur_spec));
  while (mem[cur_spec].hhfield.b0 != 0) cur_spec = mem[cur_spec]
  .hhfield.v.RH;
  if (tracing > 0) {
      
    if ((internal[36]<= 0) || (chopped != 0)) 
    printspec (560);
    else if (internal[36] > 65536L) 
    printspec (561);
    else printspec (562);
  } 
  Result = cur_spec;
  return Result;
} 
void 
zendround (scaled x , scaled y) 
{
  y = y + 32768L - y_corr[octant];
  x = x + y - x_corr[octant];
  m1 = floorunscaled (x);
  n1 = floorunscaled (y);
  if (x - 65536L * m1 >= y - 65536L * n1 + z_corr[octant]) 
  d1 = 1;
  else d1 = 0;
} 
void 
zfillspec (halfword h) 
{
  halfword p, q, r, s;
  if (internal[10] > 0) 
  begin_edge_tracing ();
  p = h;
  do {
      octant = mem[p + 3].cint;
    q = p;
    while (mem[q].hhfield.b1 != 0) q = mem[q].hhfield.v.RH;
    if (q != p) 
    {
      endround (mem[p + 1].cint , mem[p + 2].cint);
      m0 = m1;
      n0 = n1;
      d0 = d1;
      endround (mem[q + 1].cint , mem[q + 2].cint);
      if (n1 - n0 >= move_size) 
      overflow (540 , move_size);
      move[0] = d0;
      move_ptr = 0;
      r = p;
      do {
	  s = mem[r].hhfield.v.RH;
	make_moves (mem[r + 1].cint , mem[r + 5].cint , mem[s + 3]
	.cint , mem[s + 1].cint , mem[r + 2].cint + 32768L , mem[r + 
	6].cint + 32768L , mem[s + 4].cint + 32768L , mem[s + 2]
	.cint + 32768L , xy_corr[octant], y_corr[octant]);
	r = s;
      } while (!(r == q));
      move[move_ptr] = move[move_ptr] - d1;
      if (internal[35] > 0) 
      smooth_moves (0 , move_ptr);
      move_to_edges (m0 , n0 , m1 , n1);
    } 
    p = mem[q].hhfield.v.RH;
  } while (!(p == h));
  toss_knot_list (h);
  if (internal[10] > 0) 
  end_edge_tracing ();
} 
void 
zdupoffset (halfword w) 
{
  halfword r;
  r = get_node (3);
  mem[r + 1].cint = mem[w + 1].cint;
  mem[r + 2].cint = mem[w + 2].cint;
  mem[r].hhfield.v.RH = mem[w].hhfield.v.RH;
  mem[mem[w].hhfield.v.RH].hhfield.lhfield = r;
  mem[r].hhfield.lhfield = w;
  mem[w].hhfield.v.RH = r;
} 
halfword 
zmakepen (halfword h) 
{
  /* 30 31 45 40 */ register halfword Result; small_number o, oo, k;
  halfword p;
  halfword q, r, s, w, hh;
  integer n;
  scaled dx, dy;
  scaled mc;
  q = h;
  r = mem[q].hhfield.v.RH;
  mc = abs (mem[h + 1].cint);
  if (q == r) 
  {
    hh = h;
    mem[h].hhfield.b1 = 0;
    if (mc < abs (mem[h + 2].cint)) 
    mc = abs (mem[h + 2].cint);
  } 
  else {
      
    o = 0;
    hh = 0;
    while (true) {
	
      s = mem[r].hhfield.v.RH;
      if (mc < abs (mem[r + 1].cint)) 
      mc = abs (mem[r + 1].cint);
      if (mc < abs (mem[r + 2].cint)) 
      mc = abs (mem[r + 2].cint);
      dx = mem[r + 1].cint - mem[q + 1].cint;
      dy = mem[r + 2].cint - mem[q + 2].cint;
      if (dx == 0) {
	  
	if (dy == 0) 
	goto not_found;
      } 
      if (ab_vs_cd (dx , mem[s + 2].cint - mem[r + 2].cint , dy , mem 
    [s + 1].cint - mem[r + 1].cint) < 0) 
      goto not_found;
      if (dx > 0) 
      octant = 1;
      else if (dx == 0) {
	  
	if (dy > 0) 
	octant = 1;
	else octant = 2;
      } 
      else {
	  
	dx = - (integer) dx;
	octant = 2;
      } 
      if (dy < 0) 
      {
	dy = - (integer) dy;
	octant = octant + 2;
      } 
      else if (dy == 0) {
	  
	if (octant > 1) 
	octant = 4;
      } 
      if (dx < dy) 
      octant = octant + 4;
      mem[q].hhfield.b1 = octant;
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
  mem[p].hhfield.lhfield = 0;
  if (mem[q].hhfield.v.RH != q) 
  mem[p].hhfield.v.RH = 1;
  {register integer for_end; k = 1;for_end = 8; if (k <= for_end) do 
    {
      octant = octant_code[k];
      n = 0;
      h = p + octant;
      while (true) {
	  
	r = get_node (3);
	skew (mem[q + 1].cint , mem[q + 2].cint , octant);
	mem[r + 1].cint = cur_x;
	mem[r + 2].cint = cur_y;
	if (n == 0) 
	mem[h].hhfield.v.RH = r;
	else if (odd (k)) 
	{
	  mem[w].hhfield.v.RH = r;
	  mem[r].hhfield.lhfield = w;
	} 
	else {
	    
	  mem[w].hhfield.lhfield = r;
	  mem[r].hhfield.v.RH = w;
	} 
	w = r;
	if (mem[q].hhfield.b1 != octant) 
	goto done1;
	q = mem[q].hhfield.v.RH;
	incr (n);
      } 
      done1: r = mem[h].hhfield.v.RH;
      if (odd (k)) 
      {
	mem[w].hhfield.v.RH = r;
	mem[r].hhfield.lhfield = w;
      } 
      else {
	  
	mem[w].hhfield.lhfield = r;
	mem[r].hhfield.v.RH = w;
	mem[h].hhfield.v.RH = w;
	r = w;
      } 
      if ((mem[r + 2].cint != mem[mem[r].hhfield.v.RH + 2].cint 
   ) || (n == 0)) 
      {
	dupoffset (r);
	incr (n);
      } 
      r = mem[r].hhfield.lhfield;
      if (mem[r + 1].cint != mem[mem[r].hhfield.lhfield + 1]
      .cint) 
      dupoffset (r);
      else decr (n);
      if (n >= 255) 
      overflow (579 , 255);
      mem[h].hhfield.lhfield = n;
    } 
  while (k++ < for_end);} 
  goto found;
  not_found: p = 3;
  if (mc >= 268402688L) 
  {
    {
      if (interaction == 3) 
;
      if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[in_open]);
	print (58);
	print_int (line);
	print (262);
	print (573);
      } 
      else {
	  
	print_nl (263);
	print (573);
      } 
    } 
    {
      help_ptr = 2;
      help_line[1] = 574;
      help_line[0] = 575;
    } 
  } 
  else {
      
    {
      if (interaction == 3) 
;
      if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[in_open]);
	print (58);
	print_int (line);
	print (262);
	print (576);
      } 
      else {
	  
	print_nl (263);
	print (576);
      } 
    } 
    {
      help_ptr = 3;
      help_line[2] = 577;
      help_line[1] = 578;
      help_line[0] = 575;
    } 
  } 
  put_get_error ();
  found: if (internal[6] > 0) 
  print_pen (p , 572 , true);
  Result = p;
  return Result;
} 
halfword 
ztrivialknot (scaled x , scaled y) 
{
  register halfword Result; halfword p;
  p = get_node (7);
  mem[p].hhfield.b0 = 1;
  mem[p].hhfield.b1 = 1;
  mem[p + 1].cint = x;
  mem[p + 3].cint = x;
  mem[p + 5].cint = x;
  mem[p + 2].cint = y;
  mem[p + 4].cint = y;
  mem[p + 6].cint = y;
  Result = p;
  return Result;
} 
halfword 
zmakepath (halfword penhead) 
{
  register halfword Result; halfword p;
  unsigned char k;
  halfword h;
  integer m, n;
  halfword w, ww;
  p = memtop - 1;
  {register integer for_end; k = 1;for_end = 8; if (k <= for_end) do 
    {
      octant = octant_code[k];
      h = penhead + octant;
      n = mem[h].hhfield.lhfield;
      w = mem[h].hhfield.v.RH;
      if (!odd (k)) 
      w = mem[w].hhfield.lhfield;
      {register integer for_end; m = 1;for_end = n + 1; if (m <= for_end) 
      do 
	{
	  if (odd (k)) 
	  ww = mem[w].hhfield.v.RH;
	  else ww = mem[w].hhfield.lhfield;
	  if ((mem[ww + 1].cint != mem[w + 1].cint) || (mem[ww + 
	  2].cint != mem[w + 2].cint)) 
	  {
	    unskew (mem[ww + 1].cint , mem[ww + 2].cint , octant);
	    mem[p].hhfield.v.RH = trivialknot (cur_x , cur_y);
	    p = mem[p].hhfield.v.RH;
	  } 
	  w = ww;
	} 
      while (m++ < for_end);} 
    } 
  while (k++ < for_end);} 
  if (p == memtop - 1) 
  {
    w = mem[penhead + 1].hhfield.v.RH;
    p = trivialknot (mem[w + 1].cint + mem[w + 2].cint , mem[w + 2 
  ].cint);
    mem[memtop - 1].hhfield.v.RH = p;
  } 
  mem[p].hhfield.v.RH = mem[memtop - 1].hhfield.v.RH;
  Result = mem[memtop - 1].hhfield.v.RH;
  return Result;
} 
void 
zfindoffset (scaled x , scaled y , halfword p) 
{
  /* 30 10 */ unsigned char octant;
  schar s;
  integer n;
  halfword h, w, ww;
  if (x > 0) 
  octant = 1;
  else if (x == 0) {
      
    if (y <= 0) {
	
      if (y == 0) 
      {
	cur_x = 0;
	cur_y = 0;
	goto lab10;
      } 
      else octant = 2;
    } 
    else octant = 1;
  } 
  else {
      
    x = - (integer) x;
    if (y == 0) 
    octant = 4;
    else octant = 2;
  } 
  if (y < 0) 
  {
    octant = octant + 2;
    y = - (integer) y;
  } 
  if (x >= y) 
  x = x - y;
  else {
      
    octant = octant + 4;
    x = y - x;
    y = y - x;
  } 
  if (odd (octant_number[octant])) 
  s = -1;
  else s = 1;
  h = p + octant;
  w = mem[mem[h].hhfield.v.RH].hhfield.v.RH;
  ww = mem[w].hhfield.v.RH;
  n = mem[h].hhfield.lhfield;
  while (n > 1) {
      
    if (ab_vs_cd (x , mem[ww + 2].cint - mem[w + 2].cint , y , mem[
    ww + 1].cint - mem[w + 1].cint) != s) 
    goto done;
    w = ww;
    ww = mem[w].hhfield.v.RH;
    decr (n);
  } 
  done: unskew (mem[w + 1].cint , mem[w + 2].cint , octant);
  lab10:;
} 
void 
zsplitforoffset (halfword p , fraction t) 
{
  halfword q;
  halfword r;
  q = mem[p].hhfield.v.RH;
  splitcubic (p , t , mem[q + 1].cint , mem[q + 2].cint);
  r = mem[p].hhfield.v.RH;
  if (mem[r + 2].cint < mem[p + 2].cint) 
  mem[r + 2].cint = mem[p + 2].cint;
  else if (mem[r + 2].cint > mem[q + 2].cint) 
  mem[r + 2].cint = mem[q + 2].cint;
  if (mem[r + 1].cint < mem[p + 1].cint) 
  mem[r + 1].cint = mem[p + 1].cint;
  else if (mem[r + 1].cint > mem[q + 1].cint) 
  mem[r + 1].cint = mem[q + 1].cint;
} 
void 
zfinoffsetprep (halfword p , halfword k , halfword w , integer x0 , integer 
x1 , integer x2 , integer y0 , integer y1 , integer y2 , boolean rising , 
integer n) 
{
  /* 10 */ halfword ww;
  scaled du, dv;
  integer t0, t1, t2;
  fraction t;
  fraction s;
  integer v;
  while (true) {
      
    mem[p].hhfield.b1 = k;
    if (rising) {
	
      if (k == n) 
      goto lab10;
      else ww = mem[w].hhfield.v.RH;
    } 
    else if (k == 1) 
    goto lab10;
    else ww = mem[w].hhfield.lhfield;
    du = mem[ww + 1].cint - mem[w + 1].cint;
    dv = mem[ww + 2].cint - mem[w + 2].cint;
    if (abs (du) >= abs (dv)) 
    {
      s = makefraction (dv , du);
      t0 = takefraction (x0 , s) - y0;
      t1 = takefraction (x1 , s) - y1;
      t2 = takefraction (x2 , s) - y2;
    } 
    else {
	
      s = makefraction (du , dv);
      t0 = x0 - takefraction (y0 , s);
      t1 = x1 - takefraction (y1 , s);
      t2 = x2 - takefraction (y2 , s);
    } 
    t = crossingpoint (t0 , t1 , t2);
    if (t >= 268435456L) 
    goto lab10;
    {
      splitforoffset (p , t);
      mem[p].hhfield.b1 = k;
      p = mem[p].hhfield.v.RH;
      v = x0 - takefraction (x0 - x1 , t);
      x1 = x1 - takefraction (x1 - x2 , t);
      x0 = v - takefraction (v - x1 , t);
      v = y0 - takefraction (y0 - y1 , t);
      y1 = y1 - takefraction (y1 - y2 , t);
      y0 = v - takefraction (v - y1 , t);
      t1 = t1 - takefraction (t1 - t2 , t);
      if (t1 > 0) 
      t1 = 0;
      t = crossingpoint (0 , - (integer) t1 , - (integer) t2);
      if (t < 268435456L) 
      {
	splitforoffset (p , t);
	mem[mem[p].hhfield.v.RH].hhfield.b1 = k;
	v = x1 - takefraction (x1 - x2 , t);
	x1 = x0 - takefraction (x0 - x1 , t);
	x2 = x1 - takefraction (x1 - v , t);
	v = y1 - takefraction (y1 - y2 , t);
	y1 = y0 - takefraction (y0 - y1 , t);
	y2 = y1 - takefraction (y1 - v , t);
      } 
    } 
    if (rising) 
    incr (k);
    else decr (k);
    w = ww;
  } 
  lab10:;
} 
void 
zoffsetprep (halfword c , halfword h) 
{
  /* 30 45 */ halfword n;
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
  n = mem[h].hhfield.lhfield;
  lh = mem[h].hhfield.v.RH;
  while (mem[p].hhfield.b1 != 0) {
      
    q = mem[p].hhfield.v.RH;
    if (n <= 1) 
    mem[p].hhfield.b1 = 1;
    else {
	
      x0 = mem[p + 5].cint - mem[p + 1].cint;
      x2 = mem[q + 1].cint - mem[q + 3].cint;
      x1 = mem[q + 3].cint - mem[p + 5].cint;
      y0 = mem[p + 6].cint - mem[p + 2].cint;
      y2 = mem[q + 2].cint - mem[q + 4].cint;
      y1 = mem[q + 4].cint - mem[p + 6].cint;
      lmax_coef = abs (x0);
      if (abs (x1) > lmax_coef) 
      lmax_coef = abs (x1);
      if (abs (x2) > lmax_coef) 
      lmax_coef = abs (x2);
      if (abs (y0) > lmax_coef) 
      lmax_coef = abs (y0);
      if (abs (y1) > lmax_coef) 
      lmax_coef = abs (y1);
      if (abs (y2) > lmax_coef) 
      lmax_coef = abs (y2);
      if (lmax_coef == 0) 
      goto not_found;
      while (lmax_coef < 134217728L) {
	  
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
      if (dx == 0) {
	  
	if (dy == 0) 
	{
	  dx = x1;
	  dy = y1;
	  if (dx == 0) {
	      
	    if (dy == 0) 
	    {
	      dx = x2;
	      dy = y2;
	    } 
	  } 
	} 
      } 
      if (dx == 0) 
      finoffsetprep (p , n , mem[mem[lh].hhfield.lhfield].hhfield 
    .lhfield , - (integer) x0 , - (integer) x1 , - (integer) x2 , 
      - (integer) y0 , - (integer) y1 , - (integer) y2 , false , n);
      else {
	  
	k = 1;
	w = mem[lh].hhfield.v.RH;
	while (true) {
	    
	  if (k == n) 
	  goto done;
	  ww = mem[w].hhfield.v.RH;
	  if (ab_vs_cd (dy , abs (mem[ww + 1].cint - mem[w + 1].cint 
	) , dx , abs (mem[ww + 2].cint - mem[w + 2].cint)) >= 0) 
	  {
	    incr (k);
	    w = ww;
	  } 
	  else goto done;
	} 
	done:;
	if (k == 1) 
	t = 268435457L;
	else {
	    
	  ww = mem[w].hhfield.lhfield;
	  du = mem[ww + 1].cint - mem[w + 1].cint;
	  dv = mem[ww + 2].cint - mem[w + 2].cint;
	  if (abs (du) >= abs (dv)) 
	  {
	    s = makefraction (dv , du);
	    t0 = takefraction (x0 , s) - y0;
	    t1 = takefraction (x1 , s) - y1;
	    t2 = takefraction (x2 , s) - y2;
	  } 
	  else {
	      
	    s = makefraction (du , dv);
	    t0 = x0 - takefraction (y0 , s);
	    t1 = x1 - takefraction (y1 , s);
	    t2 = x2 - takefraction (y2 , s);
	  } 
	  t = crossingpoint (- (integer) t0 , - (integer) t1 , - (integer) t2 
	);
	} 
	if (t >= 268435456L) 
	finoffsetprep (p , k , w , x0 , x1 , x2 , y0 , y1 , y2 , true , n);
	else {
	    
	  splitforoffset (p , t);
	  r = mem[p].hhfield.v.RH;
	  x1a = x0 - takefraction (x0 - x1 , t);
	  x1 = x1 - takefraction (x1 - x2 , t);
	  x2a = x1a - takefraction (x1a - x1 , t);
	  y1a = y0 - takefraction (y0 - y1 , t);
	  y1 = y1 - takefraction (y1 - y2 , t);
	  y2a = y1a - takefraction (y1a - y1 , t);
	  finoffsetprep (p , k , w , x0 , x1a , x2a , y0 , y1a , y2a , true , 
	  n);
	  x0 = x2a;
	  y0 = y2a;
	  t1 = t1 - takefraction (t1 - t2 , t);
	  if (t1 < 0) 
	  t1 = 0;
	  t = crossingpoint (0 , t1 , t2);
	  if (t < 268435456L) 
	  {
	    splitforoffset (r , t);
	    x1a = x1 - takefraction (x1 - x2 , t);
	    x1 = x0 - takefraction (x0 - x1 , t);
	    x0a = x1 - takefraction (x1 - x1a , t);
	    y1a = y1 - takefraction (y1 - y2 , t);
	    y1 = y0 - takefraction (y0 - y1 , t);
	    y0a = y1 - takefraction (y1 - y1a , t);
	    finoffsetprep (mem[r].hhfield.v.RH , k , w , x0a , x1a , x2 
	    , y0a , y1a , y2 , true , n);
	    x2 = x0a;
	    y2 = y0a;
	  } 
	  finoffsetprep (r , k - 1 , ww , - (integer) x0 , - (integer) x1 , 
	  - (integer) x2 , - (integer) y0 , - (integer) y1 , - (integer) y2 , 
	  false , n);
	} 
      } 
      not_found:;
    } 
    do {
	r = mem[p].hhfield.v.RH;
      if (mem[p + 1].cint == mem[p + 5].cint) {
	  
	if (mem[p + 2].cint == mem[p + 6].cint) {
	    
	  if (mem[p + 1].cint == mem[r + 3].cint) {
	      
	    if (mem[p + 2].cint == mem[r + 4].cint) {
		
	      if (mem[p + 1].cint == mem[r + 1].cint) {
		  
		if (mem[p + 2].cint == mem[r + 2].cint) 
		{
		  removecubic (p);
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
void 
zskewline_edges (halfword p , halfword w , halfword ww) 
{
  scaled x0, y0, x1, y1;
  if ((mem[w + 1].cint != mem[ww + 1].cint) || (mem[w + 2]
  .cint != mem[ww + 2].cint)) 
  {
    x0 = mem[p + 1].cint + mem[w + 1].cint;
    y0 = mem[p + 2].cint + mem[w + 2].cint;
    x1 = mem[p + 1].cint + mem[ww + 1].cint;
    y1 = mem[p + 2].cint + mem[ww + 2].cint;
    unskew (x0 , y0 , octant);
    x0 = cur_x;
    y0 = cur_y;
    unskew (x1 , y1 , octant);
	;
#ifdef STAT
    if (internal[10] > 65536L) 
    {
      print_nl (585);
      print_two (x0 , y0);
      print (584);
      print_two (cur_x , cur_y);
      print_nl (261);
    } 
#endif /* STAT */
    line_edges (x0 , y0 , cur_x , cur_y);
  } 
} 
void 
zdualmoves (halfword h , halfword p , halfword q) 
{
  /* 30 31 */ halfword r, s;
  integer m, n;
  integer mm0, mm1;
  integer k;
  halfword w, ww;
  integer smoothbot, smoothtop;
  scaled xx, yy, xp, yp, delx, dely, tx, ty;
  k = mem[h].hhfield.lhfield + 1;
  ww = mem[h].hhfield.v.RH;
  w = mem[ww].hhfield.lhfield;
  mm0 = floorunscaled (mem[p + 1].cint + mem[w + 1].cint - xy_corr[
  octant]);
  mm1 = floorunscaled (mem[q + 1].cint + mem[ww + 1].cint - xy_corr[
  octant]);
  {register integer for_end; n = 1;for_end = n1 - n0 + 1; if (n <= 
  for_end) do 
    env_move[n] = mm1;
  while (n++ < for_end);} 
  env_move[0] = mm0;
  move_ptr = 0;
  m = mm0;
  r = p;
  while (true) {
      
    if (r == q) 
    smoothtop = move_ptr;
    while (mem[r].hhfield.b1 != k) {
	
      xx = mem[r + 1].cint + mem[w + 1].cint;
      yy = mem[r + 2].cint + mem[w + 2].cint + 32768L;
	;
#ifdef STAT
      if (internal[10] > 65536L) 
      {
	print_nl (586);
	print_int (k);
	print (587);
	unskew (xx , yy - 32768L , octant);
	print_two (cur_x , cur_y);
      } 
#endif /* STAT */
      if (mem[r].hhfield.b1 < k) 
      {
	decr (k);
	w = mem[w].hhfield.lhfield;
	xp = mem[r + 1].cint + mem[w + 1].cint;
	yp = mem[r + 2].cint + mem[w + 2].cint + 32768L;
	if (yp != yy) 
	{
	  ty = floorscaled (yy - y_corr[octant]);
	  dely = yp - yy;
	  yy = yy - ty;
	  ty = yp - y_corr[octant] - ty;
	  if (ty >= 65536L) 
	  {
	    delx = xp - xx;
	    yy = 65536L - yy;
	    while (true) {
		
	      if (m < env_move[move_ptr]) 
	      env_move[move_ptr] = m;
	      tx = takefraction (delx , makefraction (yy , dely));
	      if (ab_vs_cd (tx , dely , delx , yy) + xy_corr[octant] > 0) 
	      decr (tx);
	      m = floorunscaled (xx + tx);
	      ty = ty - 65536L;
	      incr (move_ptr);
	      if (ty < 65536L) 
	      goto done1;
	      yy = yy + 65536L;
	    } 
	    done1: if (m < env_move[move_ptr]) 
	    env_move[move_ptr] = m;
	  } 
	} 
      } 
      else {
	  
	incr (k);
	w = mem[w].hhfield.v.RH;
	xp = mem[r + 1].cint + mem[w + 1].cint;
	yp = mem[r + 2].cint + mem[w + 2].cint + 32768L;
      } 
	;
#ifdef STAT
      if (internal[10] > 65536L) 
      {
	print (584);
	unskew (xp , yp - 32768L , octant);
	print_two (cur_x , cur_y);
	print_nl (261);
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
    s = mem[r].hhfield.v.RH;
    make_moves (mem[r + 1].cint + mem[w + 1].cint , mem[r + 5]
    .cint + mem[w + 1].cint , mem[s + 3].cint + mem[w + 1].cint , 
    mem[s + 1].cint + mem[w + 1].cint , mem[r + 2].cint + mem[w 
    + 2].cint + 32768L , mem[r + 6].cint + mem[w + 2].cint + 32768L 
    , mem[s + 4].cint + mem[w + 2].cint + 32768L , mem[s + 2].cint 
    + mem[w + 2].cint + 32768L , xy_corr[octant], y_corr[octant]);
    do {
	if (m < env_move[n]) 
      env_move[n] = m;
      m = m + move[n] - 1;
      incr (n);
    } while (!(n > move_ptr));
    r = s;
  } 
  done: 
	;
#ifdef TEXMF_DEBUG
  if ((m != mm1) || (move_ptr != n1 - n0)) 
  confusion (50);
#endif /* TEXMF_DEBUG */
  move[0] = d0 + env_move[1] - mm0;
  {register integer for_end; n = 1;for_end = move_ptr; if (n <= for_end) 
  do 
    move[n] = env_move[n + 1] - env_move[n]+ 1;
  while (n++ < for_end);} 
  move[move_ptr] = move[move_ptr] - d1;
  if (internal[35] > 0) 
  smooth_moves (smoothbot , smoothtop);
  move_to_edges (m0 , n0 , m1 , n1);
  if (mem[q + 6].cint == 1) 
  {
    w = mem[h].hhfield.v.RH;
    skewline_edges (q , w , mem[w].hhfield.lhfield);
  } 
} 
void 
zfillenvelope (halfword spechead) 
{
  /* 30 31 */ halfword p, q, r, s;
  halfword h;
  halfword www;
  integer m, n;
  integer mm0, mm1;
  integer k;
  halfword w, ww;
  integer smoothbot, smoothtop;
  scaled xx, yy, xp, yp, delx, dely, tx, ty;
  if (internal[10] > 0) 
  begin_edge_tracing ();
  p = spechead;
  do {
      octant = mem[p + 3].cint;
    h = cur_pen + octant;
    q = p;
    while (mem[q].hhfield.b1 != 0) q = mem[q].hhfield.v.RH;
    w = mem[h].hhfield.v.RH;
    if (mem[p + 4].cint == 1) 
    w = mem[w].hhfield.lhfield;
	;
#ifdef STAT
    if (internal[10] > 65536L) 
    {
      print_nl (580);
      print (octant_dir[octant]);
      print (558);
      print_int (mem[h].hhfield.lhfield);
      if (mem[h].hhfield.lhfield != 1) 
      print (581);
      else print (582);
      print (583);
      unskew (mem[p + 1].cint + mem[w + 1].cint , mem[p + 2].cint 
      + mem[w + 2].cint , octant);
      print_two (cur_x , cur_y);
      ww = mem[h].hhfield.v.RH;
      if (mem[q + 6].cint == 1) 
      ww = mem[ww].hhfield.lhfield;
      print (584);
      unskew (mem[q + 1].cint + mem[ww + 1].cint , mem[q + 2]
      .cint + mem[ww + 2].cint , octant);
      print_two (cur_x , cur_y);
    } 
#endif /* STAT */
    ww = mem[h].hhfield.v.RH;
    www = ww;
    if (odd (octant_number[octant])) 
    www = mem[www].hhfield.lhfield;
    else ww = mem[ww].hhfield.lhfield;
    if (w != ww) 
    skewline_edges (p , w , ww);
    endround (mem[p + 1].cint + mem[ww + 1].cint , mem[p + 2]
    .cint + mem[ww + 2].cint);
    m0 = m1;
    n0 = n1;
    d0 = d1;
    endround (mem[q + 1].cint + mem[www + 1].cint , mem[q + 2]
    .cint + mem[www + 2].cint);
    if (n1 - n0 >= move_size) 
    overflow (540 , move_size);
    offsetprep (p , h);
    q = p;
    while (mem[q].hhfield.b1 != 0) q = mem[q].hhfield.v.RH;
    if (odd (octant_number[octant])) 
    {
      k = 0;
      w = mem[h].hhfield.v.RH;
      ww = mem[w].hhfield.lhfield;
      mm0 = floorunscaled (mem[p + 1].cint + mem[w + 1].cint - xy_corr 
    [octant]);
      mm1 = floorunscaled (mem[q + 1].cint + mem[ww + 1].cint - 
      xy_corr[octant]);
      {register integer for_end; n = 0;for_end = n1 - n0; if (n <= 
      for_end) do 
	env_move[n] = mm0;
      while (n++ < for_end);} 
      env_move[n1 - n0] = mm1;
      move_ptr = 0;
      m = mm0;
      r = p;
      mem[q].hhfield.b1 = mem[h].hhfield.lhfield + 1;
      while (true) {
	  
	if (r == q) 
	smoothtop = move_ptr;
	while (mem[r].hhfield.b1 != k) {
	    
	  xx = mem[r + 1].cint + mem[w + 1].cint;
	  yy = mem[r + 2].cint + mem[w + 2].cint + 32768L;
	;
#ifdef STAT
	  if (internal[10] > 65536L) 
	  {
	    print_nl (586);
	    print_int (k);
	    print (587);
	    unskew (xx , yy - 32768L , octant);
	    print_two (cur_x , cur_y);
	  } 
#endif /* STAT */
	  if (mem[r].hhfield.b1 > k) 
	  {
	    incr (k);
	    w = mem[w].hhfield.v.RH;
	    xp = mem[r + 1].cint + mem[w + 1].cint;
	    yp = mem[r + 2].cint + mem[w + 2].cint + 32768L;
	    if (yp != yy) 
	    {
	      ty = floorscaled (yy - y_corr[octant]);
	      dely = yp - yy;
	      yy = yy - ty;
	      ty = yp - y_corr[octant] - ty;
	      if (ty >= 65536L) 
	      {
		delx = xp - xx;
		yy = 65536L - yy;
		while (true) {
		    
		  tx = takefraction (delx , makefraction (yy , dely));
		  if (ab_vs_cd (tx , dely , delx , yy) + xy_corr[octant] > 
		  0) 
		  decr (tx);
		  m = floorunscaled (xx + tx);
		  if (m > env_move[move_ptr]) 
		  env_move[move_ptr] = m;
		  ty = ty - 65536L;
		  if (ty < 65536L) 
		  goto done1;
		  yy = yy + 65536L;
		  incr (move_ptr);
		} 
		done1:;
	      } 
	    } 
	  } 
	  else {
	      
	    decr (k);
	    w = mem[w].hhfield.lhfield;
	    xp = mem[r + 1].cint + mem[w + 1].cint;
	    yp = mem[r + 2].cint + mem[w + 2].cint + 32768L;
	  } 
	;
#ifdef STAT
	  if (internal[10] > 65536L) 
	  {
	    print (584);
	    unskew (xp , yp - 32768L , octant);
	    print_two (cur_x , cur_y);
	    print_nl (261);
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
	s = mem[r].hhfield.v.RH;
	make_moves (mem[r + 1].cint + mem[w + 1].cint , mem[r + 5]
	.cint + mem[w + 1].cint , mem[s + 3].cint + mem[w + 1]
	.cint , mem[s + 1].cint + mem[w + 1].cint , mem[r + 2]
	.cint + mem[w + 2].cint + 32768L , mem[r + 6].cint + mem[w + 
	2].cint + 32768L , mem[s + 4].cint + mem[w + 2].cint + 
	32768L , mem[s + 2].cint + mem[w + 2].cint + 32768L , xy_corr[
	octant], y_corr[octant]);
	do {
	    m = m + move[n] - 1;
	  if (m > env_move[n]) 
	  env_move[n] = m;
	  incr (n);
	} while (!(n > move_ptr));
	r = s;
      } 
      done: 
	;
#ifdef TEXMF_DEBUG
      if ((m != mm1) || (move_ptr != n1 - n0)) 
      confusion (49);
#endif /* TEXMF_DEBUG */
      move[0] = d0 + env_move[0] - mm0;
      {register integer for_end; n = 1;for_end = move_ptr; if (n <= 
      for_end) do 
	move[n] = env_move[n] - env_move[n - 1]+ 1;
      while (n++ < for_end);} 
      move[move_ptr] = move[move_ptr] - d1;
      if (internal[35] > 0) 
      smooth_moves (smoothbot , smoothtop);
      move_to_edges (m0 , n0 , m1 , n1);
      if (mem[q + 6].cint == 0) 
      {
	w = mem[h].hhfield.v.RH;
	skewline_edges (q , mem[w].hhfield.lhfield , w);
      } 
    } 
    else dualmoves (h , p , q);
    mem[q].hhfield.b1 = 0;
    p = mem[q].hhfield.v.RH;
  } while (!(p == spechead));
  if (internal[10] > 0) 
  end_edge_tracing ();
  toss_knot_list (spechead);
} 
halfword 
zmakeellipse (scaled majoraxis , scaled minoraxis , angle theta) 
{
  /* 30 31 40 */ register halfword Result; halfword p, q, r, s;
  halfword h;
  integer alpha, beta, gamma, delta;
  integer c, d;
  integer u, v;
  boolean symmetric;
  if ((majoraxis == minoraxis) || (theta % 94371840L == 0)) 
  {
    symmetric = true;
    alpha = 0;
    if (odd (theta / 94371840L)) 
    {
      beta = majoraxis;
      gamma = minoraxis;
      n_sin = 268435456L;
      n_cos = 0;
    } 
    else {
	
      beta = minoraxis;
      gamma = majoraxis;
      theta = 0;
    } 
  } 
  else {
      
    symmetric = false;
    n_sin_cos (theta);
    gamma = takefraction (majoraxis , n_sin);
    delta = takefraction (minoraxis , n_cos);
    beta = pyth_add (gamma , delta);
    alpha = makefraction (gamma , beta);
    alpha = takefraction (majoraxis , alpha);
    alpha = takefraction (alpha , n_cos);
    alpha = (alpha + 32768L) / 65536L;
    gamma = takefraction (minoraxis , n_sin);
    gamma = pyth_add (takefraction (majoraxis , n_cos) , gamma);
  } 
  beta = (beta + 32768L) / 65536L;
  gamma = (gamma + 32768L) / 65536L;
  p = get_node (7);
  q = get_node (7);
  r = get_node (7);
  if (symmetric) 
  s = 0;
  else s = get_node (7);
  h = p;
  mem[p].hhfield.v.RH = q;
  mem[q].hhfield.v.RH = r;
  mem[r].hhfield.v.RH = s;
  if (beta == 0) 
  beta = 1;
  if (gamma == 0) 
  gamma = 1;
  if (gamma <= abs (alpha)) {
      
    if (alpha > 0) 
    alpha = gamma - 1;
    else alpha = 1 - gamma;
  } 
  mem[p + 1].cint = - (integer) alpha * 32768L;
  mem[p + 2].cint = - (integer) beta * 32768L;
  mem[q + 1].cint = gamma * 32768L;
  mem[q + 2].cint = mem[p + 2].cint;
  mem[r + 1].cint = mem[q + 1].cint;
  mem[p + 5].cint = 0;
  mem[q + 3].cint = -32768L;
  mem[q + 5].cint = 32768L;
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
  else {
      
    mem[r + 2].cint = - (integer) mem[p + 2].cint;
    mem[r + 4].cint = beta + beta;
    mem[s + 1].cint = - (integer) mem[p + 1].cint;
    mem[s + 2].cint = mem[r + 2].cint;
    mem[s + 3].cint = 32768L;
    mem[s + 4].cint = gamma - alpha;
  } 
  while (true) {
      
    u = mem[p + 5].cint + mem[q + 5].cint;
    v = mem[q + 3].cint + mem[r + 3].cint;
    c = mem[p + 6].cint + mem[q + 6].cint;
    delta = pyth_add (u , v);
    if (majoraxis == minoraxis) 
    d = majoraxis;
    else {
	
      if (theta == 0) 
      {
	alpha = u;
	beta = v;
      } 
      else {
	  
	alpha = takefraction (u , n_cos) + takefraction (v , n_sin);
	beta = takefraction (v , n_cos) - takefraction (u , n_sin);
      } 
      alpha = makefraction (alpha , delta);
      beta = makefraction (beta , delta);
      d = pyth_add (takefraction (majoraxis , alpha) , takefraction (
      minoraxis , beta));
    } 
    alpha = abs (u);
    beta = abs (v);
    if (alpha < beta) 
    {
      alpha = abs (v);
      beta = abs (u);
    } 
    if (internal[38]!= 0) 
    d = d - takefraction (internal[38], makefraction (beta + beta , 
    delta));
    d = takefraction ((d + 4) / 8 , delta);
    alpha = alpha / 32768L;
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
	mem[q + 1].cint = mem[q + 1].cint - delta * mem[r + 3]
	.cint;
	mem[q + 2].cint = mem[q + 2].cint + delta * mem[q + 5]
	.cint;
	mem[r + 4].cint = mem[r + 4].cint - delta;
      } 
      else {
	  
	s = get_node (7);
	mem[p].hhfield.v.RH = s;
	mem[s].hhfield.v.RH = q;
	mem[s + 1].cint = mem[q + 1].cint + delta * mem[q + 3]
	.cint;
	mem[s + 2].cint = mem[q + 2].cint - delta * mem[p + 5]
	.cint;
	mem[q + 1].cint = mem[q + 1].cint - delta * mem[r + 3]
	.cint;
	mem[q + 2].cint = mem[q + 2].cint + delta * mem[q + 5]
	.cint;
	mem[s + 3].cint = mem[q + 3].cint;
	mem[s + 5].cint = u;
	mem[q + 3].cint = v;
	mem[s + 6].cint = c - delta;
	mem[s + 4].cint = mem[q + 4].cint - delta;
	mem[q + 4].cint = delta;
	mem[r + 4].cint = mem[r + 4].cint - delta;
      } 
    } 
    else p = q;
    while (true) {
	
      q = mem[p].hhfield.v.RH;
      if (q == 0) 
      goto done;
      if (mem[q + 4].cint == 0) 
      {
	mem[p].hhfield.v.RH = mem[q].hhfield.v.RH;
	mem[p + 6].cint = mem[q + 6].cint;
	mem[p + 5].cint = mem[q + 5].cint;
	free_node (q , 7);
      } 
      else {
	  
	r = mem[q].hhfield.v.RH;
	if (r == 0) 
	goto done;
	if (mem[r + 4].cint == 0) 
	{
	  mem[p].hhfield.v.RH = r;
	  free_node (q , 7);
	  p = r;
	} 
	else goto found;
      } 
    } 
    found:;
  } 
  done:;
  if (symmetric) 
  {
    s = 0;
    q = h;
    while (true) {
	
      r = get_node (7);
      mem[r].hhfield.v.RH = s;
      s = r;
      mem[s + 1].cint = mem[q + 1].cint;
      mem[s + 2].cint = - (integer) mem[q + 2].cint;
      if (q == p) 
      goto done1;
      q = mem[q].hhfield.v.RH;
      if (mem[q + 2].cint == 0) 
      goto done1;
    } 
    done1: if ((mem[p].hhfield.v.RH != 0)) 
    free_node (mem[p].hhfield.v.RH , 7);
    mem[p].hhfield.v.RH = s;
    beta = - (integer) mem[h + 2].cint;
    while (mem[p + 2].cint != beta) p = mem[p].hhfield.v.RH;
    q = mem[p].hhfield.v.RH;
  } 
  if (q != 0) 
  {
    if (mem[h + 5].cint == 0) 
    {
      p = h;
      h = mem[h].hhfield.v.RH;
      free_node (p , 7);
      mem[q + 1].cint = - (integer) mem[h + 1].cint;
    } 
    p = q;
  } 
  else q = p;
  r = mem[h].hhfield.v.RH;
  do {
      s = get_node (7);
    mem[p].hhfield.v.RH = s;
    p = s;
    mem[p + 1].cint = - (integer) mem[r + 1].cint;
    mem[p + 2].cint = - (integer) mem[r + 2].cint;
    r = mem[r].hhfield.v.RH;
  } while (!(r == q));
  mem[p].hhfield.v.RH = h;
  Result = h;
  return Result;
} 
scaled 
zfinddirectiontime (scaled x , scaled y , halfword h) 
{
  /* 10 40 45 30 */ register scaled Result; scaled max;
  halfword p, q;
  scaled n;
  scaled tt;
  scaled x1, x2, x3, y1, y2, y3;
  angle theta, phi;
  fraction t;
  if (abs (x) < abs (y)) 
  {
    x = makefraction (x , abs (y));
    if (y > 0) 
    y = 268435456L;
    else y = -268435456L;
  } 
  else if (x == 0) 
  {
    Result = 0;
    goto lab10;
  } 
  else {
      
    y = makefraction (y , abs (x));
    if (x > 0) 
    x = 268435456L;
    else x = -268435456L;
  } 
  n = 0;
  p = h;
  while (true) {
      
    if (mem[p].hhfield.b1 == 0) 
    goto not_found;
    q = mem[p].hhfield.v.RH;
    tt = 0;
    x1 = mem[p + 5].cint - mem[p + 1].cint;
    x2 = mem[q + 3].cint - mem[p + 5].cint;
    x3 = mem[q + 1].cint - mem[q + 3].cint;
    y1 = mem[p + 6].cint - mem[p + 2].cint;
    y2 = mem[q + 4].cint - mem[p + 6].cint;
    y3 = mem[q + 2].cint - mem[q + 4].cint;
    max = abs (x1);
    if (abs (x2) > max) 
    max = abs (x2);
    if (abs (x3) > max) 
    max = abs (x3);
    if (abs (y1) > max) 
    max = abs (y1);
    if (abs (y2) > max) 
    max = abs (y2);
    if (abs (y3) > max) 
    max = abs (y3);
    if (max == 0) 
    goto found;
    while (max < 134217728L) {
	
      max = max + max;
      x1 = x1 + x1;
      x2 = x2 + x2;
      x3 = x3 + x3;
      y1 = y1 + y1;
      y2 = y2 + y2;
      y3 = y3 + y3;
    } 
    t = x1;
    x1 = takefraction (x1 , x) + takefraction (y1 , y);
    y1 = takefraction (y1 , x) - takefraction (t , y);
    t = x2;
    x2 = takefraction (x2 , x) + takefraction (y2 , y);
    y2 = takefraction (y2 , x) - takefraction (t , y);
    t = x3;
    x3 = takefraction (x3 , x) + takefraction (y3 , y);
    y3 = takefraction (y3 , x) - takefraction (t , y);
    if (y1 == 0) {
	
      if (x1 >= 0) 
      goto found;
    } 
    if (n > 0) 
    {
      theta = n_arg (x1 , y1);
      if (theta >= 0) {
	  
	if (phi <= 0) {
	    
	  if (phi >= theta - 188743680L) 
	  goto found;
	} 
      } 
      if (theta <= 0) {
	  
	if (phi >= 0) {
	    
	  if (phi <= theta + 188743680L) 
	  goto found;
	} 
      } 
      if (p == h) 
      goto not_found;
    } 
    if ((x3 != 0) || (y3 != 0)) 
    phi = n_arg (x3 , y3);
    if (x1 < 0) {
	
      if (x2 < 0) {
	  
	if (x3 < 0) 
	goto done;
      } 
    } 
    if (ab_vs_cd (y1 , y3 , y2 , y2) == 0) 
    {
      if (ab_vs_cd (y1 , y2 , 0 , 0) < 0) 
      {
	t = makefraction (y1 , y1 - y2);
	x1 = x1 - takefraction (x1 - x2 , t);
	x2 = x2 - takefraction (x2 - x3 , t);
	if (x1 - takefraction (x1 - x2 , t) >= 0) 
	{
	  tt = (t + 2048) / 4096;
	  goto found;
	} 
      } 
      else if (y3 == 0) {
	  
	if (y1 == 0) 
	{
	  t = crossingpoint (- (integer) x1 , - (integer) x2 , - (integer) x3 
	);
	  if (t <= 268435456L) 
	  {
	    tt = (t + 2048) / 4096;
	    goto found;
	  } 
	  if (ab_vs_cd (x1 , x3 , x2 , x2) <= 0) 
	  {
	    t = makefraction (x1 , x1 - x2);
	    {
	      tt = (t + 2048) / 4096;
	      goto found;
	    } 
	  } 
	} 
	else if (x3 >= 0) 
	{
	  tt = 65536L;
	  goto found;
	} 
      } 
      goto done;
    } 
    if (y1 <= 0) {
	
      if (y1 < 0) 
      {
	y1 = - (integer) y1;
	y2 = - (integer) y2;
	y3 = - (integer) y3;
      } 
      else if (y2 > 0) 
      {
	y2 = - (integer) y2;
	y3 = - (integer) y3;
      } 
    } 
    t = crossingpoint (y1 , y2 , y3);
    if (t > 268435456L) 
    goto done;
    y2 = y2 - takefraction (y2 - y3 , t);
    x1 = x1 - takefraction (x1 - x2 , t);
    x2 = x2 - takefraction (x2 - x3 , t);
    x1 = x1 - takefraction (x1 - x2 , t);
    if (x1 >= 0) 
    {
      tt = (t + 2048) / 4096;
      goto found;
    } 
    if (y2 > 0) 
    y2 = 0;
    tt = t;
    t = crossingpoint (0 , - (integer) y2 , - (integer) y3);
    if (t > 268435456L) 
    goto done;
    x1 = x1 - takefraction (x1 - x2 , t);
    x2 = x2 - takefraction (x2 - x3 , t);
    if (x1 - takefraction (x1 - x2 , t) >= 0) 
    {
      t = tt - takefraction (tt - 268435456L , t);
      {
	tt = (t + 2048) / 4096;
	goto found;
      } 
    } 
    done:;
    p = q;
    n = n + 65536L;
  } 
  not_found: Result = -65536L;
  goto lab10;
  found: Result = n + tt;
  lab10:;
  return Result;
} 
void 
zcubicintersection (halfword p , halfword pp) 
{
  /* 22 45 10 */ halfword q, qq;
  time_to_go = 5000;
  max_t = 2;
  q = mem[p].hhfield.v.RH;
  qq = mem[pp].hhfield.v.RH;
  bisect_ptr = 20;
  bisect_stack[bisect_ptr - 5] = mem[p + 5].cint - mem[p + 1].cint;
  bisect_stack[bisect_ptr - 4] = mem[q + 3].cint - mem[p + 5].cint;
  bisect_stack[bisect_ptr - 3] = mem[q + 1].cint - mem[q + 3].cint;
  if (bisect_stack[bisect_ptr - 5]< 0) {
      
    if (bisect_stack[bisect_ptr - 3] >= 0) 
    {
      if (bisect_stack[bisect_ptr - 4]< 0) 
      bisect_stack[bisect_ptr - 2] = bisect_stack[bisect_ptr - 5]+ 
      bisect_stack[bisect_ptr - 4];
      else bisect_stack[bisect_ptr - 2] = bisect_stack[bisect_ptr - 5];
      bisect_stack[bisect_ptr - 1] = bisect_stack[bisect_ptr - 5]+ 
      bisect_stack[bisect_ptr - 4]+ bisect_stack[bisect_ptr - 3];
      if (bisect_stack[bisect_ptr - 1]< 0) 
      bisect_stack[bisect_ptr - 1] = 0;
    } 
    else {
	
      bisect_stack[bisect_ptr - 2] = bisect_stack[bisect_ptr - 5]+ 
      bisect_stack[bisect_ptr - 4]+ bisect_stack[bisect_ptr - 3];
      if (bisect_stack[bisect_ptr - 2] > bisect_stack[bisect_ptr - 5]) 
      bisect_stack[bisect_ptr - 2] = bisect_stack[bisect_ptr - 5];
      bisect_stack[bisect_ptr - 1] = bisect_stack[bisect_ptr - 5]+ 
      bisect_stack[bisect_ptr - 4];
      if (bisect_stack[bisect_ptr - 1]< 0) 
      bisect_stack[bisect_ptr - 1] = 0;
    } 
  } 
  else if (bisect_stack[bisect_ptr - 3]<= 0) 
  {
    if (bisect_stack[bisect_ptr - 4] > 0) 
    bisect_stack[bisect_ptr - 1] = bisect_stack[bisect_ptr - 5]+ 
    bisect_stack[bisect_ptr - 4];
    else bisect_stack[bisect_ptr - 1] = bisect_stack[bisect_ptr - 5];
    bisect_stack[bisect_ptr - 2] = bisect_stack[bisect_ptr - 5]+ 
    bisect_stack[bisect_ptr - 4]+ bisect_stack[bisect_ptr - 3];
    if (bisect_stack[bisect_ptr - 2] > 0) 
    bisect_stack[bisect_ptr - 2] = 0;
  } 
  else {
      
    bisect_stack[bisect_ptr - 1] = bisect_stack[bisect_ptr - 5]+ 
    bisect_stack[bisect_ptr - 4]+ bisect_stack[bisect_ptr - 3];
    if (bisect_stack[bisect_ptr - 1]< bisect_stack[bisect_ptr - 5]) 
    bisect_stack[bisect_ptr - 1] = bisect_stack[bisect_ptr - 5];
    bisect_stack[bisect_ptr - 2] = bisect_stack[bisect_ptr - 5]+ 
    bisect_stack[bisect_ptr - 4];
    if (bisect_stack[bisect_ptr - 2] > 0) 
    bisect_stack[bisect_ptr - 2] = 0;
  } 
  bisect_stack[bisect_ptr - 10] = mem[p + 6].cint - mem[p + 2].cint;
  bisect_stack[bisect_ptr - 9] = mem[q + 4].cint - mem[p + 6].cint;
  bisect_stack[bisect_ptr - 8] = mem[q + 2].cint - mem[q + 4].cint;
  if (bisect_stack[bisect_ptr - 10]< 0) {
      
    if (bisect_stack[bisect_ptr - 8] >= 0) 
    {
      if (bisect_stack[bisect_ptr - 9]< 0) 
      bisect_stack[bisect_ptr - 7] = bisect_stack[bisect_ptr - 10]+ 
      bisect_stack[bisect_ptr - 9];
      else bisect_stack[bisect_ptr - 7] = bisect_stack[bisect_ptr - 10];
      bisect_stack[bisect_ptr - 6] = bisect_stack[bisect_ptr - 10]+ 
      bisect_stack[bisect_ptr - 9]+ bisect_stack[bisect_ptr - 8];
      if (bisect_stack[bisect_ptr - 6]< 0) 
      bisect_stack[bisect_ptr - 6] = 0;
    } 
    else {
	
      bisect_stack[bisect_ptr - 7] = bisect_stack[bisect_ptr - 10]+ 
      bisect_stack[bisect_ptr - 9]+ bisect_stack[bisect_ptr - 8];
      if (bisect_stack[bisect_ptr - 7] > bisect_stack[bisect_ptr - 10]) 
      bisect_stack[bisect_ptr - 7] = bisect_stack[bisect_ptr - 10];
      bisect_stack[bisect_ptr - 6] = bisect_stack[bisect_ptr - 10]+ 
      bisect_stack[bisect_ptr - 9];
      if (bisect_stack[bisect_ptr - 6]< 0) 
      bisect_stack[bisect_ptr - 6] = 0;
    } 
  } 
  else if (bisect_stack[bisect_ptr - 8]<= 0) 
  {
    if (bisect_stack[bisect_ptr - 9] > 0) 
    bisect_stack[bisect_ptr - 6] = bisect_stack[bisect_ptr - 10]+ 
    bisect_stack[bisect_ptr - 9];
    else bisect_stack[bisect_ptr - 6] = bisect_stack[bisect_ptr - 10];
    bisect_stack[bisect_ptr - 7] = bisect_stack[bisect_ptr - 10]+ 
    bisect_stack[bisect_ptr - 9]+ bisect_stack[bisect_ptr - 8];
    if (bisect_stack[bisect_ptr - 7] > 0) 
    bisect_stack[bisect_ptr - 7] = 0;
  } 
  else {
      
    bisect_stack[bisect_ptr - 6] = bisect_stack[bisect_ptr - 10]+ 
    bisect_stack[bisect_ptr - 9]+ bisect_stack[bisect_ptr - 8];
    if (bisect_stack[bisect_ptr - 6]< bisect_stack[bisect_ptr - 10]) 
    bisect_stack[bisect_ptr - 6] = bisect_stack[bisect_ptr - 10];
    bisect_stack[bisect_ptr - 7] = bisect_stack[bisect_ptr - 10]+ 
    bisect_stack[bisect_ptr - 9];
    if (bisect_stack[bisect_ptr - 7] > 0) 
    bisect_stack[bisect_ptr - 7] = 0;
  } 
  bisect_stack[bisect_ptr - 15] = mem[pp + 5].cint - mem[pp + 1].cint 
;
  bisect_stack[bisect_ptr - 14] = mem[qq + 3].cint - mem[pp + 5].cint 
;
  bisect_stack[bisect_ptr - 13] = mem[qq + 1].cint - mem[qq + 3].cint 
;
  if (bisect_stack[bisect_ptr - 15]< 0) {
      
    if (bisect_stack[bisect_ptr - 13] >= 0) 
    {
      if (bisect_stack[bisect_ptr - 14]< 0) 
      bisect_stack[bisect_ptr - 12] = bisect_stack[bisect_ptr - 15]+ 
      bisect_stack[bisect_ptr - 14];
      else bisect_stack[bisect_ptr - 12] = bisect_stack[bisect_ptr - 15];
      bisect_stack[bisect_ptr - 11] = bisect_stack[bisect_ptr - 15]+ 
      bisect_stack[bisect_ptr - 14]+ bisect_stack[bisect_ptr - 13];
      if (bisect_stack[bisect_ptr - 11]< 0) 
      bisect_stack[bisect_ptr - 11] = 0;
    } 
    else {
	
      bisect_stack[bisect_ptr - 12] = bisect_stack[bisect_ptr - 15]+ 
      bisect_stack[bisect_ptr - 14]+ bisect_stack[bisect_ptr - 13];
      if (bisect_stack[bisect_ptr - 12] > bisect_stack[bisect_ptr - 15]) 
      bisect_stack[bisect_ptr - 12] = bisect_stack[bisect_ptr - 15];
      bisect_stack[bisect_ptr - 11] = bisect_stack[bisect_ptr - 15]+ 
      bisect_stack[bisect_ptr - 14];
      if (bisect_stack[bisect_ptr - 11]< 0) 
      bisect_stack[bisect_ptr - 11] = 0;
    } 
  } 
  else if (bisect_stack[bisect_ptr - 13]<= 0) 
  {
    if (bisect_stack[bisect_ptr - 14] > 0) 
    bisect_stack[bisect_ptr - 11] = bisect_stack[bisect_ptr - 15]+ 
    bisect_stack[bisect_ptr - 14];
    else bisect_stack[bisect_ptr - 11] = bisect_stack[bisect_ptr - 15];
    bisect_stack[bisect_ptr - 12] = bisect_stack[bisect_ptr - 15]+ 
    bisect_stack[bisect_ptr - 14]+ bisect_stack[bisect_ptr - 13];
    if (bisect_stack[bisect_ptr - 12] > 0) 
    bisect_stack[bisect_ptr - 12] = 0;
  } 
  else {
      
    bisect_stack[bisect_ptr - 11] = bisect_stack[bisect_ptr - 15]+ 
    bisect_stack[bisect_ptr - 14]+ bisect_stack[bisect_ptr - 13];
    if (bisect_stack[bisect_ptr - 11]< bisect_stack[bisect_ptr - 15]) 
    bisect_stack[bisect_ptr - 11] = bisect_stack[bisect_ptr - 15];
    bisect_stack[bisect_ptr - 12] = bisect_stack[bisect_ptr - 15]+ 
    bisect_stack[bisect_ptr - 14];
    if (bisect_stack[bisect_ptr - 12] > 0) 
    bisect_stack[bisect_ptr - 12] = 0;
  } 
  bisect_stack[bisect_ptr - 20] = mem[pp + 6].cint - mem[pp + 2].cint 
;
  bisect_stack[bisect_ptr - 19] = mem[qq + 4].cint - mem[pp + 6].cint 
;
  bisect_stack[bisect_ptr - 18] = mem[qq + 2].cint - mem[qq + 4].cint 
;
  if (bisect_stack[bisect_ptr - 20]< 0) {
      
    if (bisect_stack[bisect_ptr - 18] >= 0) 
    {
      if (bisect_stack[bisect_ptr - 19]< 0) 
      bisect_stack[bisect_ptr - 17] = bisect_stack[bisect_ptr - 20]+ 
      bisect_stack[bisect_ptr - 19];
      else bisect_stack[bisect_ptr - 17] = bisect_stack[bisect_ptr - 20];
      bisect_stack[bisect_ptr - 16] = bisect_stack[bisect_ptr - 20]+ 
      bisect_stack[bisect_ptr - 19]+ bisect_stack[bisect_ptr - 18];
      if (bisect_stack[bisect_ptr - 16]< 0) 
      bisect_stack[bisect_ptr - 16] = 0;
    } 
    else {
	
      bisect_stack[bisect_ptr - 17] = bisect_stack[bisect_ptr - 20]+ 
      bisect_stack[bisect_ptr - 19]+ bisect_stack[bisect_ptr - 18];
      if (bisect_stack[bisect_ptr - 17] > bisect_stack[bisect_ptr - 20]) 
      bisect_stack[bisect_ptr - 17] = bisect_stack[bisect_ptr - 20];
      bisect_stack[bisect_ptr - 16] = bisect_stack[bisect_ptr - 20]+ 
      bisect_stack[bisect_ptr - 19];
      if (bisect_stack[bisect_ptr - 16]< 0) 
      bisect_stack[bisect_ptr - 16] = 0;
    } 
  } 
  else if (bisect_stack[bisect_ptr - 18]<= 0) 
  {
    if (bisect_stack[bisect_ptr - 19] > 0) 
    bisect_stack[bisect_ptr - 16] = bisect_stack[bisect_ptr - 20]+ 
    bisect_stack[bisect_ptr - 19];
    else bisect_stack[bisect_ptr - 16] = bisect_stack[bisect_ptr - 20];
    bisect_stack[bisect_ptr - 17] = bisect_stack[bisect_ptr - 20]+ 
    bisect_stack[bisect_ptr - 19]+ bisect_stack[bisect_ptr - 18];
    if (bisect_stack[bisect_ptr - 17] > 0) 
    bisect_stack[bisect_ptr - 17] = 0;
  } 
  else {
      
    bisect_stack[bisect_ptr - 16] = bisect_stack[bisect_ptr - 20]+ 
    bisect_stack[bisect_ptr - 19]+ bisect_stack[bisect_ptr - 18];
    if (bisect_stack[bisect_ptr - 16]< bisect_stack[bisect_ptr - 20]) 
    bisect_stack[bisect_ptr - 16] = bisect_stack[bisect_ptr - 20];
    bisect_stack[bisect_ptr - 17] = bisect_stack[bisect_ptr - 20]+ 
    bisect_stack[bisect_ptr - 19];
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
  while (true) {
      
    lab22: if (delx - tol <= bisect_stack[xy - 11] - bisect_stack[uv - 2]
 ) {
	
      if (delx + tol >= bisect_stack[xy - 12] - bisect_stack[uv - 1]) {
	  
	if (dely - tol <= bisect_stack[xy - 16] - bisect_stack[uv - 7]) 
	{
	  if (dely + tol >= bisect_stack[xy - 17] - bisect_stack[uv - 6]
	) 
	  {
	    if (cur_t >= max_t) 
	    {
	      if (max_t == 131072L) 
	      {
		cur_t = halfp (cur_t + 1);
		cur_tt = halfp (cur_tt + 1);
		goto lab10;
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
	    bisect_stack[bisect_ptr - 24] = half (bisect_stack[bisect_ptr - 
	    25]+ bisect_stack[uv - 4]);
	    bisect_stack[bisect_ptr - 4] = half (bisect_stack[bisect_ptr - 3 
	  ]+ bisect_stack[uv - 4]);
	    bisect_stack[bisect_ptr - 23] = half (bisect_stack[bisect_ptr - 
	    24]+ bisect_stack[bisect_ptr - 4]);
	    bisect_stack[bisect_ptr - 5] = bisect_stack[bisect_ptr - 23];
	    if (bisect_stack[bisect_ptr - 25]< 0) {
		
	      if (bisect_stack[bisect_ptr - 23] >= 0) 
	      {
		if (bisect_stack[bisect_ptr - 24]< 0) 
		bisect_stack[bisect_ptr - 22] = bisect_stack[bisect_ptr - 25 
		]+ bisect_stack[bisect_ptr - 24];
		else bisect_stack[bisect_ptr - 22] = bisect_stack[bisect_ptr 
		- 25];
		bisect_stack[bisect_ptr - 21] = bisect_stack[bisect_ptr - 25 
		]+ bisect_stack[bisect_ptr - 24]+ bisect_stack[bisect_ptr - 
		23];
		if (bisect_stack[bisect_ptr - 21]< 0) 
		bisect_stack[bisect_ptr - 21] = 0;
	      } 
	      else {
		  
		bisect_stack[bisect_ptr - 22] = bisect_stack[bisect_ptr - 25 
		]+ bisect_stack[bisect_ptr - 24]+ bisect_stack[bisect_ptr - 
		23];
		if (bisect_stack[bisect_ptr - 22] > bisect_stack[bisect_ptr 
		- 25]) 
		bisect_stack[bisect_ptr - 22] = bisect_stack[bisect_ptr - 25 
		];
		bisect_stack[bisect_ptr - 21] = bisect_stack[bisect_ptr - 25 
		]+ bisect_stack[bisect_ptr - 24];
		if (bisect_stack[bisect_ptr - 21]< 0) 
		bisect_stack[bisect_ptr - 21] = 0;
	      } 
	    } 
	    else if (bisect_stack[bisect_ptr - 23]<= 0) 
	    {
	      if (bisect_stack[bisect_ptr - 24] > 0) 
	      bisect_stack[bisect_ptr - 21] = bisect_stack[bisect_ptr - 25]
	      + bisect_stack[bisect_ptr - 24];
	      else bisect_stack[bisect_ptr - 21] = bisect_stack[bisect_ptr - 
	      25];
	      bisect_stack[bisect_ptr - 22] = bisect_stack[bisect_ptr - 25]
	      + bisect_stack[bisect_ptr - 24]+ bisect_stack[bisect_ptr - 23 
	    ];
	      if (bisect_stack[bisect_ptr - 22] > 0) 
	      bisect_stack[bisect_ptr - 22] = 0;
	    } 
	    else {
		
	      bisect_stack[bisect_ptr - 21] = bisect_stack[bisect_ptr - 25]
	      + bisect_stack[bisect_ptr - 24]+ bisect_stack[bisect_ptr - 23 
	    ];
	      if (bisect_stack[bisect_ptr - 21]< bisect_stack[bisect_ptr - 
	      25]) 
	      bisect_stack[bisect_ptr - 21] = bisect_stack[bisect_ptr - 25]
	;
	      bisect_stack[bisect_ptr - 22] = bisect_stack[bisect_ptr - 25]
	      + bisect_stack[bisect_ptr - 24];
	      if (bisect_stack[bisect_ptr - 22] > 0) 
	      bisect_stack[bisect_ptr - 22] = 0;
	    } 
	    if (bisect_stack[bisect_ptr - 5]< 0) {
		
	      if (bisect_stack[bisect_ptr - 3] >= 0) 
	      {
		if (bisect_stack[bisect_ptr - 4]< 0) 
		bisect_stack[bisect_ptr - 2] = bisect_stack[bisect_ptr - 5]
		+ bisect_stack[bisect_ptr - 4];
		else bisect_stack[bisect_ptr - 2] = bisect_stack[bisect_ptr - 
		5];
		bisect_stack[bisect_ptr - 1] = bisect_stack[bisect_ptr - 5]
		+ bisect_stack[bisect_ptr - 4]+ bisect_stack[bisect_ptr - 3 
		];
		if (bisect_stack[bisect_ptr - 1]< 0) 
		bisect_stack[bisect_ptr - 1] = 0;
	      } 
	      else {
		  
		bisect_stack[bisect_ptr - 2] = bisect_stack[bisect_ptr - 5]
		+ bisect_stack[bisect_ptr - 4]+ bisect_stack[bisect_ptr - 3 
		];
		if (bisect_stack[bisect_ptr - 2] > bisect_stack[bisect_ptr - 
		5]) 
		bisect_stack[bisect_ptr - 2] = bisect_stack[bisect_ptr - 5]
		;
		bisect_stack[bisect_ptr - 1] = bisect_stack[bisect_ptr - 5]
		+ bisect_stack[bisect_ptr - 4];
		if (bisect_stack[bisect_ptr - 1]< 0) 
		bisect_stack[bisect_ptr - 1] = 0;
	      } 
	    } 
	    else if (bisect_stack[bisect_ptr - 3]<= 0) 
	    {
	      if (bisect_stack[bisect_ptr - 4] > 0) 
	      bisect_stack[bisect_ptr - 1] = bisect_stack[bisect_ptr - 5]+ 
	      bisect_stack[bisect_ptr - 4];
	      else bisect_stack[bisect_ptr - 1] = bisect_stack[bisect_ptr - 5 
	    ];
	      bisect_stack[bisect_ptr - 2] = bisect_stack[bisect_ptr - 5]+ 
	      bisect_stack[bisect_ptr - 4]+ bisect_stack[bisect_ptr - 3];
	      if (bisect_stack[bisect_ptr - 2] > 0) 
	      bisect_stack[bisect_ptr - 2] = 0;
	    } 
	    else {
		
	      bisect_stack[bisect_ptr - 1] = bisect_stack[bisect_ptr - 5]+ 
	      bisect_stack[bisect_ptr - 4]+ bisect_stack[bisect_ptr - 3];
	      if (bisect_stack[bisect_ptr - 1]< bisect_stack[bisect_ptr - 5 
	    ]) 
	      bisect_stack[bisect_ptr - 1] = bisect_stack[bisect_ptr - 5];
	      bisect_stack[bisect_ptr - 2] = bisect_stack[bisect_ptr - 5]+ 
	      bisect_stack[bisect_ptr - 4];
	      if (bisect_stack[bisect_ptr - 2] > 0) 
	      bisect_stack[bisect_ptr - 2] = 0;
	    } 
	    bisect_stack[bisect_ptr - 30] = bisect_stack[uv - 10];
	    bisect_stack[bisect_ptr - 8] = bisect_stack[uv - 8];
	    bisect_stack[bisect_ptr - 29] = half (bisect_stack[bisect_ptr - 
	    30]+ bisect_stack[uv - 9]);
	    bisect_stack[bisect_ptr - 9] = half (bisect_stack[bisect_ptr - 8 
	  ]+ bisect_stack[uv - 9]);
	    bisect_stack[bisect_ptr - 28] = half (bisect_stack[bisect_ptr - 
	    29]+ bisect_stack[bisect_ptr - 9]);
	    bisect_stack[bisect_ptr - 10] = bisect_stack[bisect_ptr - 28];
	    if (bisect_stack[bisect_ptr - 30]< 0) {
		
	      if (bisect_stack[bisect_ptr - 28] >= 0) 
	      {
		if (bisect_stack[bisect_ptr - 29]< 0) 
		bisect_stack[bisect_ptr - 27] = bisect_stack[bisect_ptr - 30 
		]+ bisect_stack[bisect_ptr - 29];
		else bisect_stack[bisect_ptr - 27] = bisect_stack[bisect_ptr 
		- 30];
		bisect_stack[bisect_ptr - 26] = bisect_stack[bisect_ptr - 30 
		]+ bisect_stack[bisect_ptr - 29]+ bisect_stack[bisect_ptr - 
		28];
		if (bisect_stack[bisect_ptr - 26]< 0) 
		bisect_stack[bisect_ptr - 26] = 0;
	      } 
	      else {
		  
		bisect_stack[bisect_ptr - 27] = bisect_stack[bisect_ptr - 30 
		]+ bisect_stack[bisect_ptr - 29]+ bisect_stack[bisect_ptr - 
		28];
		if (bisect_stack[bisect_ptr - 27] > bisect_stack[bisect_ptr 
		- 30]) 
		bisect_stack[bisect_ptr - 27] = bisect_stack[bisect_ptr - 30 
		];
		bisect_stack[bisect_ptr - 26] = bisect_stack[bisect_ptr - 30 
		]+ bisect_stack[bisect_ptr - 29];
		if (bisect_stack[bisect_ptr - 26]< 0) 
		bisect_stack[bisect_ptr - 26] = 0;
	      } 
	    } 
	    else if (bisect_stack[bisect_ptr - 28]<= 0) 
	    {
	      if (bisect_stack[bisect_ptr - 29] > 0) 
	      bisect_stack[bisect_ptr - 26] = bisect_stack[bisect_ptr - 30]
	      + bisect_stack[bisect_ptr - 29];
	      else bisect_stack[bisect_ptr - 26] = bisect_stack[bisect_ptr - 
	      30];
	      bisect_stack[bisect_ptr - 27] = bisect_stack[bisect_ptr - 30]
	      + bisect_stack[bisect_ptr - 29]+ bisect_stack[bisect_ptr - 28 
	    ];
	      if (bisect_stack[bisect_ptr - 27] > 0) 
	      bisect_stack[bisect_ptr - 27] = 0;
	    } 
	    else {
		
	      bisect_stack[bisect_ptr - 26] = bisect_stack[bisect_ptr - 30]
	      + bisect_stack[bisect_ptr - 29]+ bisect_stack[bisect_ptr - 28 
	    ];
	      if (bisect_stack[bisect_ptr - 26]< bisect_stack[bisect_ptr - 
	      30]) 
	      bisect_stack[bisect_ptr - 26] = bisect_stack[bisect_ptr - 30]
	;
	      bisect_stack[bisect_ptr - 27] = bisect_stack[bisect_ptr - 30]
	      + bisect_stack[bisect_ptr - 29];
	      if (bisect_stack[bisect_ptr - 27] > 0) 
	      bisect_stack[bisect_ptr - 27] = 0;
	    } 
	    if (bisect_stack[bisect_ptr - 10]< 0) {
		
	      if (bisect_stack[bisect_ptr - 8] >= 0) 
	      {
		if (bisect_stack[bisect_ptr - 9]< 0) 
		bisect_stack[bisect_ptr - 7] = bisect_stack[bisect_ptr - 10]
		+ bisect_stack[bisect_ptr - 9];
		else bisect_stack[bisect_ptr - 7] = bisect_stack[bisect_ptr - 
		10];
		bisect_stack[bisect_ptr - 6] = bisect_stack[bisect_ptr - 10]
		+ bisect_stack[bisect_ptr - 9]+ bisect_stack[bisect_ptr - 8 
		];
		if (bisect_stack[bisect_ptr - 6]< 0) 
		bisect_stack[bisect_ptr - 6] = 0;
	      } 
	      else {
		  
		bisect_stack[bisect_ptr - 7] = bisect_stack[bisect_ptr - 10]
		+ bisect_stack[bisect_ptr - 9]+ bisect_stack[bisect_ptr - 8 
		];
		if (bisect_stack[bisect_ptr - 7] > bisect_stack[bisect_ptr - 
		10]) 
		bisect_stack[bisect_ptr - 7] = bisect_stack[bisect_ptr - 10]
		;
		bisect_stack[bisect_ptr - 6] = bisect_stack[bisect_ptr - 10]
		+ bisect_stack[bisect_ptr - 9];
		if (bisect_stack[bisect_ptr - 6]< 0) 
		bisect_stack[bisect_ptr - 6] = 0;
	      } 
	    } 
	    else if (bisect_stack[bisect_ptr - 8]<= 0) 
	    {
	      if (bisect_stack[bisect_ptr - 9] > 0) 
	      bisect_stack[bisect_ptr - 6] = bisect_stack[bisect_ptr - 10]+ 
	      bisect_stack[bisect_ptr - 9];
	      else bisect_stack[bisect_ptr - 6] = bisect_stack[bisect_ptr - 
	      10];
	      bisect_stack[bisect_ptr - 7] = bisect_stack[bisect_ptr - 10]+ 
	      bisect_stack[bisect_ptr - 9]+ bisect_stack[bisect_ptr - 8];
	      if (bisect_stack[bisect_ptr - 7] > 0) 
	      bisect_stack[bisect_ptr - 7] = 0;
	    } 
	    else {
		
	      bisect_stack[bisect_ptr - 6] = bisect_stack[bisect_ptr - 10]+ 
	      bisect_stack[bisect_ptr - 9]+ bisect_stack[bisect_ptr - 8];
	      if (bisect_stack[bisect_ptr - 6]< bisect_stack[bisect_ptr - 
	      10]) 
	      bisect_stack[bisect_ptr - 6] = bisect_stack[bisect_ptr - 10];
	      bisect_stack[bisect_ptr - 7] = bisect_stack[bisect_ptr - 10]+ 
	      bisect_stack[bisect_ptr - 9];
	      if (bisect_stack[bisect_ptr - 7] > 0) 
	      bisect_stack[bisect_ptr - 7] = 0;
	    } 
	    bisect_stack[bisect_ptr - 35] = bisect_stack[xy - 15];
	    bisect_stack[bisect_ptr - 13] = bisect_stack[xy - 13];
	    bisect_stack[bisect_ptr - 34] = half (bisect_stack[bisect_ptr - 
	    35]+ bisect_stack[xy - 14]);
	    bisect_stack[bisect_ptr - 14] = half (bisect_stack[bisect_ptr - 
	    13]+ bisect_stack[xy - 14]);
	    bisect_stack[bisect_ptr - 33] = half (bisect_stack[bisect_ptr - 
	    34]+ bisect_stack[bisect_ptr - 14]);
	    bisect_stack[bisect_ptr - 15] = bisect_stack[bisect_ptr - 33];
	    if (bisect_stack[bisect_ptr - 35]< 0) {
		
	      if (bisect_stack[bisect_ptr - 33] >= 0) 
	      {
		if (bisect_stack[bisect_ptr - 34]< 0) 
		bisect_stack[bisect_ptr - 32] = bisect_stack[bisect_ptr - 35 
		]+ bisect_stack[bisect_ptr - 34];
		else bisect_stack[bisect_ptr - 32] = bisect_stack[bisect_ptr 
		- 35];
		bisect_stack[bisect_ptr - 31] = bisect_stack[bisect_ptr - 35 
		]+ bisect_stack[bisect_ptr - 34]+ bisect_stack[bisect_ptr - 
		33];
		if (bisect_stack[bisect_ptr - 31]< 0) 
		bisect_stack[bisect_ptr - 31] = 0;
	      } 
	      else {
		  
		bisect_stack[bisect_ptr - 32] = bisect_stack[bisect_ptr - 35 
		]+ bisect_stack[bisect_ptr - 34]+ bisect_stack[bisect_ptr - 
		33];
		if (bisect_stack[bisect_ptr - 32] > bisect_stack[bisect_ptr 
		- 35]) 
		bisect_stack[bisect_ptr - 32] = bisect_stack[bisect_ptr - 35 
		];
		bisect_stack[bisect_ptr - 31] = bisect_stack[bisect_ptr - 35 
		]+ bisect_stack[bisect_ptr - 34];
		if (bisect_stack[bisect_ptr - 31]< 0) 
		bisect_stack[bisect_ptr - 31] = 0;
	      } 
	    } 
	    else if (bisect_stack[bisect_ptr - 33]<= 0) 
	    {
	      if (bisect_stack[bisect_ptr - 34] > 0) 
	      bisect_stack[bisect_ptr - 31] = bisect_stack[bisect_ptr - 35]
	      + bisect_stack[bisect_ptr - 34];
	      else bisect_stack[bisect_ptr - 31] = bisect_stack[bisect_ptr - 
	      35];
	      bisect_stack[bisect_ptr - 32] = bisect_stack[bisect_ptr - 35]
	      + bisect_stack[bisect_ptr - 34]+ bisect_stack[bisect_ptr - 33 
	    ];
	      if (bisect_stack[bisect_ptr - 32] > 0) 
	      bisect_stack[bisect_ptr - 32] = 0;
	    } 
	    else {
		
	      bisect_stack[bisect_ptr - 31] = bisect_stack[bisect_ptr - 35]
	      + bisect_stack[bisect_ptr - 34]+ bisect_stack[bisect_ptr - 33 
	    ];
	      if (bisect_stack[bisect_ptr - 31]< bisect_stack[bisect_ptr - 
	      35]) 
	      bisect_stack[bisect_ptr - 31] = bisect_stack[bisect_ptr - 35]
	;
	      bisect_stack[bisect_ptr - 32] = bisect_stack[bisect_ptr - 35]
	      + bisect_stack[bisect_ptr - 34];
	      if (bisect_stack[bisect_ptr - 32] > 0) 
	      bisect_stack[bisect_ptr - 32] = 0;
	    } 
	    if (bisect_stack[bisect_ptr - 15]< 0) {
		
	      if (bisect_stack[bisect_ptr - 13] >= 0) 
	      {
		if (bisect_stack[bisect_ptr - 14]< 0) 
		bisect_stack[bisect_ptr - 12] = bisect_stack[bisect_ptr - 15 
		]+ bisect_stack[bisect_ptr - 14];
		else bisect_stack[bisect_ptr - 12] = bisect_stack[bisect_ptr 
		- 15];
		bisect_stack[bisect_ptr - 11] = bisect_stack[bisect_ptr - 15 
		]+ bisect_stack[bisect_ptr - 14]+ bisect_stack[bisect_ptr - 
		13];
		if (bisect_stack[bisect_ptr - 11]< 0) 
		bisect_stack[bisect_ptr - 11] = 0;
	      } 
	      else {
		  
		bisect_stack[bisect_ptr - 12] = bisect_stack[bisect_ptr - 15 
		]+ bisect_stack[bisect_ptr - 14]+ bisect_stack[bisect_ptr - 
		13];
		if (bisect_stack[bisect_ptr - 12] > bisect_stack[bisect_ptr 
		- 15]) 
		bisect_stack[bisect_ptr - 12] = bisect_stack[bisect_ptr - 15 
		];
		bisect_stack[bisect_ptr - 11] = bisect_stack[bisect_ptr - 15 
		]+ bisect_stack[bisect_ptr - 14];
		if (bisect_stack[bisect_ptr - 11]< 0) 
		bisect_stack[bisect_ptr - 11] = 0;
	      } 
	    } 
	    else if (bisect_stack[bisect_ptr - 13]<= 0) 
	    {
	      if (bisect_stack[bisect_ptr - 14] > 0) 
	      bisect_stack[bisect_ptr - 11] = bisect_stack[bisect_ptr - 15]
	      + bisect_stack[bisect_ptr - 14];
	      else bisect_stack[bisect_ptr - 11] = bisect_stack[bisect_ptr - 
	      15];
	      bisect_stack[bisect_ptr - 12] = bisect_stack[bisect_ptr - 15]
	      + bisect_stack[bisect_ptr - 14]+ bisect_stack[bisect_ptr - 13 
	    ];
	      if (bisect_stack[bisect_ptr - 12] > 0) 
	      bisect_stack[bisect_ptr - 12] = 0;
	    } 
	    else {
		
	      bisect_stack[bisect_ptr - 11] = bisect_stack[bisect_ptr - 15]
	      + bisect_stack[bisect_ptr - 14]+ bisect_stack[bisect_ptr - 13 
	    ];
	      if (bisect_stack[bisect_ptr - 11]< bisect_stack[bisect_ptr - 
	      15]) 
	      bisect_stack[bisect_ptr - 11] = bisect_stack[bisect_ptr - 15]
	;
	      bisect_stack[bisect_ptr - 12] = bisect_stack[bisect_ptr - 15]
	      + bisect_stack[bisect_ptr - 14];
	      if (bisect_stack[bisect_ptr - 12] > 0) 
	      bisect_stack[bisect_ptr - 12] = 0;
	    } 
	    bisect_stack[bisect_ptr - 40] = bisect_stack[xy - 20];
	    bisect_stack[bisect_ptr - 18] = bisect_stack[xy - 18];
	    bisect_stack[bisect_ptr - 39] = half (bisect_stack[bisect_ptr - 
	    40]+ bisect_stack[xy - 19]);
	    bisect_stack[bisect_ptr - 19] = half (bisect_stack[bisect_ptr - 
	    18]+ bisect_stack[xy - 19]);
	    bisect_stack[bisect_ptr - 38] = half (bisect_stack[bisect_ptr - 
	    39]+ bisect_stack[bisect_ptr - 19]);
	    bisect_stack[bisect_ptr - 20] = bisect_stack[bisect_ptr - 38];
	    if (bisect_stack[bisect_ptr - 40]< 0) {
		
	      if (bisect_stack[bisect_ptr - 38] >= 0) 
	      {
		if (bisect_stack[bisect_ptr - 39]< 0) 
		bisect_stack[bisect_ptr - 37] = bisect_stack[bisect_ptr - 40 
		]+ bisect_stack[bisect_ptr - 39];
		else bisect_stack[bisect_ptr - 37] = bisect_stack[bisect_ptr 
		- 40];
		bisect_stack[bisect_ptr - 36] = bisect_stack[bisect_ptr - 40 
		]+ bisect_stack[bisect_ptr - 39]+ bisect_stack[bisect_ptr - 
		38];
		if (bisect_stack[bisect_ptr - 36]< 0) 
		bisect_stack[bisect_ptr - 36] = 0;
	      } 
	      else {
		  
		bisect_stack[bisect_ptr - 37] = bisect_stack[bisect_ptr - 40 
		]+ bisect_stack[bisect_ptr - 39]+ bisect_stack[bisect_ptr - 
		38];
		if (bisect_stack[bisect_ptr - 37] > bisect_stack[bisect_ptr 
		- 40]) 
		bisect_stack[bisect_ptr - 37] = bisect_stack[bisect_ptr - 40 
		];
		bisect_stack[bisect_ptr - 36] = bisect_stack[bisect_ptr - 40 
		]+ bisect_stack[bisect_ptr - 39];
		if (bisect_stack[bisect_ptr - 36]< 0) 
		bisect_stack[bisect_ptr - 36] = 0;
	      } 
	    } 
	    else if (bisect_stack[bisect_ptr - 38]<= 0) 
	    {
	      if (bisect_stack[bisect_ptr - 39] > 0) 
	      bisect_stack[bisect_ptr - 36] = bisect_stack[bisect_ptr - 40]
	      + bisect_stack[bisect_ptr - 39];
	      else bisect_stack[bisect_ptr - 36] = bisect_stack[bisect_ptr - 
	      40];
	      bisect_stack[bisect_ptr - 37] = bisect_stack[bisect_ptr - 40]
	      + bisect_stack[bisect_ptr - 39]+ bisect_stack[bisect_ptr - 38 
	    ];
	      if (bisect_stack[bisect_ptr - 37] > 0) 
	      bisect_stack[bisect_ptr - 37] = 0;
	    } 
	    else {
		
	      bisect_stack[bisect_ptr - 36] = bisect_stack[bisect_ptr - 40]
	      + bisect_stack[bisect_ptr - 39]+ bisect_stack[bisect_ptr - 38 
	    ];
	      if (bisect_stack[bisect_ptr - 36]< bisect_stack[bisect_ptr - 
	      40]) 
	      bisect_stack[bisect_ptr - 36] = bisect_stack[bisect_ptr - 40]
	;
	      bisect_stack[bisect_ptr - 37] = bisect_stack[bisect_ptr - 40]
	      + bisect_stack[bisect_ptr - 39];
	      if (bisect_stack[bisect_ptr - 37] > 0) 
	      bisect_stack[bisect_ptr - 37] = 0;
	    } 
	    if (bisect_stack[bisect_ptr - 20]< 0) {
		
	      if (bisect_stack[bisect_ptr - 18] >= 0) 
	      {
		if (bisect_stack[bisect_ptr - 19]< 0) 
		bisect_stack[bisect_ptr - 17] = bisect_stack[bisect_ptr - 20 
		]+ bisect_stack[bisect_ptr - 19];
		else bisect_stack[bisect_ptr - 17] = bisect_stack[bisect_ptr 
		- 20];
		bisect_stack[bisect_ptr - 16] = bisect_stack[bisect_ptr - 20 
		]+ bisect_stack[bisect_ptr - 19]+ bisect_stack[bisect_ptr - 
		18];
		if (bisect_stack[bisect_ptr - 16]< 0) 
		bisect_stack[bisect_ptr - 16] = 0;
	      } 
	      else {
		  
		bisect_stack[bisect_ptr - 17] = bisect_stack[bisect_ptr - 20 
		]+ bisect_stack[bisect_ptr - 19]+ bisect_stack[bisect_ptr - 
		18];
		if (bisect_stack[bisect_ptr - 17] > bisect_stack[bisect_ptr 
		- 20]) 
		bisect_stack[bisect_ptr - 17] = bisect_stack[bisect_ptr - 20 
		];
		bisect_stack[bisect_ptr - 16] = bisect_stack[bisect_ptr - 20 
		]+ bisect_stack[bisect_ptr - 19];
		if (bisect_stack[bisect_ptr - 16]< 0) 
		bisect_stack[bisect_ptr - 16] = 0;
	      } 
	    } 
	    else if (bisect_stack[bisect_ptr - 18]<= 0) 
	    {
	      if (bisect_stack[bisect_ptr - 19] > 0) 
	      bisect_stack[bisect_ptr - 16] = bisect_stack[bisect_ptr - 20]
	      + bisect_stack[bisect_ptr - 19];
	      else bisect_stack[bisect_ptr - 16] = bisect_stack[bisect_ptr - 
	      20];
	      bisect_stack[bisect_ptr - 17] = bisect_stack[bisect_ptr - 20]
	      + bisect_stack[bisect_ptr - 19]+ bisect_stack[bisect_ptr - 18 
	    ];
	      if (bisect_stack[bisect_ptr - 17] > 0) 
	      bisect_stack[bisect_ptr - 17] = 0;
	    } 
	    else {
		
	      bisect_stack[bisect_ptr - 16] = bisect_stack[bisect_ptr - 20]
	      + bisect_stack[bisect_ptr - 19]+ bisect_stack[bisect_ptr - 18 
	    ];
	      if (bisect_stack[bisect_ptr - 16]< bisect_stack[bisect_ptr - 
	      20]) 
	      bisect_stack[bisect_ptr - 16] = bisect_stack[bisect_ptr - 20]
	;
	      bisect_stack[bisect_ptr - 17] = bisect_stack[bisect_ptr - 20]
	      + bisect_stack[bisect_ptr - 19];
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
	    goto lab22;
	  } 
	} 
      } 
    } 
    if (time_to_go > 0) 
    decr (time_to_go);
    else {
	
      while (appr_t < 65536L) {
	  
	appr_t = appr_t + appr_t;
	appr_tt = appr_tt + appr_tt;
      } 
      cur_t = appr_t;
      cur_tt = appr_tt;
      goto lab10;
    } 
    not_found: if (odd (cur_tt)) {
	
      if (odd (cur_t)) 
      {
	cur_t = halfp (cur_t);
	cur_tt = halfp (cur_tt);
	if (cur_t == 0) 
	goto lab10;
	bisect_ptr = bisect_ptr - 45;
	three_l = three_l - tol_step;
	delx = bisect_stack[bisect_ptr];
	dely = bisect_stack[bisect_ptr + 1];
	tol = bisect_stack[bisect_ptr + 2];
	uv = bisect_stack[bisect_ptr + 3];
	xy = bisect_stack[bisect_ptr + 4];
	goto not_found;
      } 
      else {
	  
	incr (cur_t);
	delx = delx + bisect_stack[uv - 5]+ bisect_stack[uv - 4]+ 
	bisect_stack[uv - 3];
	dely = dely + bisect_stack[uv - 10]+ bisect_stack[uv - 9]+ 
	bisect_stack[uv - 8];
	uv = uv + 20;
	decr (cur_tt);
	xy = xy - 20;
	delx = delx + bisect_stack[xy - 15]+ bisect_stack[xy - 14]+ 
	bisect_stack[xy - 13];
	dely = dely + bisect_stack[xy - 20]+ bisect_stack[xy - 19]+ 
	bisect_stack[xy - 18];
      } 
    } 
    else {
	
      incr (cur_tt);
      tol = tol + three_l;
      delx = delx - bisect_stack[xy - 15] - bisect_stack[xy - 14] - 
      bisect_stack[xy - 13];
      dely = dely - bisect_stack[xy - 20] - bisect_stack[xy - 19] - 
      bisect_stack[xy - 18];
      xy = xy + 20;
    } 
  } 
  lab10:;
} 
void 
zpathintersection (halfword h , halfword hh) 
{
  /* 10 */ halfword p, pp;
  integer n, nn;
  if (mem[h].hhfield.b1 == 0) 
  {
    mem[h + 5].cint = mem[h + 1].cint;
    mem[h + 3].cint = mem[h + 1].cint;
    mem[h + 6].cint = mem[h + 2].cint;
    mem[h + 4].cint = mem[h + 2].cint;
    mem[h].hhfield.b1 = 1;
  } 
  if (mem[hh].hhfield.b1 == 0) 
  {
    mem[hh + 5].cint = mem[hh + 1].cint;
    mem[hh + 3].cint = mem[hh + 1].cint;
    mem[hh + 6].cint = mem[hh + 2].cint;
    mem[hh + 4].cint = mem[hh + 2].cint;
    mem[hh].hhfield.b1 = 1;
  } 
  tol_step = 0;
  do {
      n = -65536L;
    p = h;
    do {
	if (mem[p].hhfield.b1 != 0) 
      {
	nn = -65536L;
	pp = hh;
	do {
	    if (mem[pp].hhfield.b1 != 0) 
	  {
	    cubicintersection (p , pp);
	    if (cur_t > 0) 
	    {
	      cur_t = cur_t + n;
	      cur_tt = cur_tt + nn;
	      goto lab10;
	    } 
	  } 
	  nn = nn + 65536L;
	  pp = mem[pp].hhfield.v.RH;
	} while (!(pp == hh));
      } 
      n = n + 65536L;
      p = mem[p].hhfield.v.RH;
    } while (!(p == h));
    tol_step = tol_step + 3;
  } while (!(tol_step > 3));
  cur_t = -65536L;
  cur_tt = -65536L;
  lab10:;
} 
void 
zopenawindow (window_number k , scaled r0 , scaled c0 , scaled r1 , scaled c1 
, scaled x , scaled y) 
{
  integer m, n;
  if (r0 < 0) 
  r0 = 0;
  else r0 = roundunscaled (r0);
  r1 = roundunscaled (r1);
  if (r1 > screendepth) 
  r1 = screendepth;
  if (r1 < r0) {
      
    if (r0 > screendepth) 
    r0 = r1;
    else r1 = r0;
  } 
  if (c0 < 0) 
  c0 = 0;
  else c0 = roundunscaled (c0);
  c1 = roundunscaled (c1);
  if (c1 > screenwidth) 
  c1 = screenwidth;
  if (c1 < c0) {
      
    if (c0 > screenwidth) 
    c0 = c1;
    else c1 = c0;
  } 
  window_open[k] = true;
  incr (window_time[k]);
  left_col[k] = c0;
  right_col[k] = c1;
  top_row[k] = r0;
  bot_row[k] = r1;
  m = roundunscaled (x);
  n = roundunscaled (y) - 1;
  m_window[k] = c0 - m;
  n_window[k] = r0 + n;
  {
    if (!screen_started) 
    {
      screen_OK = initscreen ();
      screen_started = true;
    } 
  } 
  if (screen_OK) 
  {
    blankrectangle (c0 , c1 , r0 , r1);
    updatescreen ();
  } 
} 
void 
zdispedges (window_number k) 
{
  /* 30 40 */ halfword p, q;
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
  if (screen_OK) {
      
    if (left_col[k]< right_col[k]) {
	
      if (top_row[k]< bot_row[k]) 
      {
	alreadythere = false;
	if (mem[cur_edges + 3].hhfield.v.RH == k) {
	    
	  if (mem[cur_edges + 4].cint == window_time[k]) 
	  alreadythere = true;
	} 
	if (!alreadythere) 
	blankrectangle (left_col[k], right_col[k], top_row[k], 
	bot_row[k]);
	madjustment = m_window[k] - mem[cur_edges + 3].hhfield.lhfield;
	rightedge = 8 * (right_col[k] - madjustment);
	mincol = left_col[k];
	p = mem[cur_edges].hhfield.v.RH;
	r = n_window[k] - (mem[cur_edges + 1].hhfield.lhfield - 4096) 
	;
	while ((p != cur_edges) && (r >= top_row[k])) {
	    
	  if (r < bot_row[k]) 
	  {
	    if (mem[p + 1].hhfield.lhfield > 1) 
	    sort_edges (p);
	    else if (mem[p + 1].hhfield.lhfield == 1) {
		
	      if (alreadythere) 
	      goto done;
	    } 
	    mem[p + 1].hhfield.lhfield = 1;
	    n = 0;
	    ww = 0;
	    m = -1;
	    w = 0;
	    q = mem[p + 1].hhfield.v.RH;
	    row_transition[0] = mincol;
	    while (true) {
		
	      if (q == memtop) 
	      d = rightedge;
	      else d = mem[q].hhfield.lhfield;
	      mm = (d / 8) + madjustment;
	      if (mm != m) 
	      {
		if (w <= 0) 
		{
		  if (ww > 0) {
		      
		    if (m > mincol) 
		    {
		      if (n == 0) {
			  
			if (alreadythere) 
			{
			  b = 0;
			  incr (n);
			} 
			else b = 1;
		      } 
		      else incr (n);
		      row_transition[n] = m;
		    } 
		  } 
		} 
		else if (ww <= 0) {
		    
		  if (m > mincol) 
		  {
		    if (n == 0) 
		    b = 1;
		    incr (n);
		    row_transition[n] = m;
		  } 
		} 
		m = mm;
		w = ww;
	      } 
	      if (d >= rightedge) 
	      goto found;
	      ww = ww + (d % 8) - 4;
	      q = mem[q].hhfield.v.RH;
	    } 
	    found: if (alreadythere || (ww > 0)) 
	    {
	      if (n == 0) {
		  
		if (ww > 0) 
		b = 1;
		else b = 0;
	      } 
	      incr (n);
	      row_transition[n] = right_col[k];
	    } 
	    else if (n == 0) 
	    goto done;
	    paintrow (r , b , row_transition , n);
	    done:;
	  } 
	  p = mem[p].hhfield.v.RH;
	  decr (r);
	} 
	updatescreen ();
	incr (window_time[k]);
	mem[cur_edges + 3].hhfield.v.RH = k;
	mem[cur_edges + 4].cint = window_time[k];
      } 
    } 
  } 
} 
fraction 
zmax_coef (halfword p) 
{
  register fraction Result; fraction x;
  x = 0;
  while (mem[p].hhfield.lhfield != 0) {
      
    if (abs (mem[p + 1].cint) > x) 
    x = abs (mem[p + 1].cint);
    p = mem[p].hhfield.v.RH;
  } 
  Result = x;
  return Result;
} 
halfword 
zpplusq (halfword p , halfword q , small_number t) 
{
  /* 30 */ register halfword Result; halfword pp, qq;
  halfword r, s;
  integer threshold;
  integer v;
  if (t == 17) 
  threshold = 2685;
  else threshold = 8;
  r = memtop - 1;
  pp = mem[p].hhfield.lhfield;
  qq = mem[q].hhfield.lhfield;
  while (true) if (pp == qq) {
      
    if (pp == 0) 
    goto done;
    else {
	
      v = mem[p + 1].cint + mem[q + 1].cint;
      mem[p + 1].cint = v;
      s = p;
      p = mem[p].hhfield.v.RH;
      pp = mem[p].hhfield.lhfield;
      if (abs (v) < threshold) 
      free_node (s , 2);
      else {
	  
	if (abs (v) >= 626349397L) {
	    
	  if (watch_coefs) 
	  {
	    mem[qq].hhfield.b0 = 0;
	    fix_needed = true;
	  } 
	} 
	mem[r].hhfield.v.RH = s;
	r = s;
      } 
      q = mem[q].hhfield.v.RH;
      qq = mem[q].hhfield.lhfield;
    } 
  } 
  else if (mem[pp + 1].cint < mem[qq + 1].cint) 
  {
    s = get_node (2);
    mem[s].hhfield.lhfield = qq;
    mem[s + 1].cint = mem[q + 1].cint;
    q = mem[q].hhfield.v.RH;
    qq = mem[q].hhfield.lhfield;
    mem[r].hhfield.v.RH = s;
    r = s;
  } 
  else {
      
    mem[r].hhfield.v.RH = p;
    r = p;
    p = mem[p].hhfield.v.RH;
    pp = mem[p].hhfield.lhfield;
  } 
  done: mem[p + 1].cint = slow_add (mem[p + 1].cint , mem[q + 1]
  .cint);
  mem[r].hhfield.v.RH = p;
  dep_final = p;
  Result = mem[memtop - 1].hhfield.v.RH;
  return Result;
} 
halfword 
zptimesv (halfword p , integer v , small_number t0 , small_number t1 , boolean 
visscaled) 
{
  register halfword Result; halfword r, s;
  integer w;
  integer threshold;
  boolean scalingdown;
  if (t0 != t1) 
  scalingdown = true;
  else scalingdown = !visscaled;
  if (t1 == 17) 
  threshold = 1342;
  else threshold = 4;
  r = memtop - 1;
  while (mem[p].hhfield.lhfield != 0) {
      
    if (scalingdown) 
    w = takefraction (v , mem[p + 1].cint);
    else w = takescaled (v , mem[p + 1].cint);
    if (abs (w) <= threshold) 
    {
      s = mem[p].hhfield.v.RH;
      free_node (p , 2);
      p = s;
    } 
    else {
	
      if (abs (w) >= 626349397L) 
      {
	fix_needed = true;
	mem[mem[p].hhfield.lhfield].hhfield.b0 = 0;
      } 
      mem[r].hhfield.v.RH = p;
      r = p;
      mem[p + 1].cint = w;
      p = mem[p].hhfield.v.RH;
    } 
  } 
  mem[r].hhfield.v.RH = p;
  if (visscaled) 
  mem[p + 1].cint = takescaled (mem[p + 1].cint , v);
  else mem[p + 1].cint = takefraction (mem[p + 1].cint , v);
  Result = mem[memtop - 1].hhfield.v.RH;
  return Result;
} 
halfword 
zpwithxbecomingq (halfword p , halfword x , halfword q , small_number t) 
{
  register halfword Result; halfword r, s;
  integer v;
  integer sx;
  s = p;
  r = memtop - 1;
  sx = mem[x + 1].cint;
  while (mem[mem[s].hhfield.lhfield + 1].cint > sx) {
      
    r = s;
    s = mem[s].hhfield.v.RH;
  } 
  if (mem[s].hhfield.lhfield != x) 
  Result = p;
  else {
      
    mem[memtop - 1].hhfield.v.RH = p;
    mem[r].hhfield.v.RH = mem[s].hhfield.v.RH;
    v = mem[s + 1].cint;
    free_node (s , 2);
    Result = p_plus_fq (mem[memtop - 1].hhfield.v.RH , v , q , t , 17);
  } 
  return Result;
} 
void 
znewdep (halfword q , halfword p) 
{
  halfword r;
  mem[q + 1].hhfield.v.RH = p;
  mem[q + 1].hhfield.lhfield = 13;
  r = mem[13].hhfield.v.RH;
  mem[dep_final].hhfield.v.RH = r;
  mem[r + 1].hhfield.lhfield = dep_final;
  mem[13].hhfield.v.RH = q;
} 
halfword 
zconstdependency (scaled v) 
{
  register halfword Result; dep_final = get_node (2);
  mem[dep_final + 1].cint = v;
  mem[dep_final].hhfield.lhfield = 0;
  Result = dep_final;
  return Result;
} 
halfword 
zsingledependency (halfword p) 
{
  register halfword Result; halfword q;
  integer m;
  m = mem[p + 1].cint % 64;
  if (m > 28) 
  Result = constdependency (0);
  else {
      
    q = get_node (2);
    mem[q + 1].cint = two_to_the[28 - m];
    mem[q].hhfield.lhfield = p;
    mem[q].hhfield.v.RH = constdependency (0);
    Result = q;
  } 
  return Result;
} 
halfword 
zcopydeplist (halfword p) 
{
  /* 30 */ register halfword Result; halfword q;
  q = get_node (2);
  dep_final = q;
  while (true) {
      
    mem[dep_final].hhfield.lhfield = mem[p].hhfield.lhfield;
    mem[dep_final + 1].cint = mem[p + 1].cint;
    if (mem[dep_final].hhfield.lhfield == 0) 
    goto done;
    mem[dep_final].hhfield.v.RH = get_node (2);
    dep_final = mem[dep_final].hhfield.v.RH;
    p = mem[p].hhfield.v.RH;
  } 
  done: Result = q;
  return Result;
} 
void 
zlineareq (halfword p , small_number t) 
{
  halfword q, r, s;
  halfword x;
  integer n;
  integer v;
  halfword prevr;
  halfword finalnode;
  integer w;
  q = p;
  r = mem[p].hhfield.v.RH;
  v = mem[q + 1].cint;
  while (mem[r].hhfield.lhfield != 0) {
      
    if (abs (mem[r + 1].cint) > abs (v)) 
    {
      q = r;
      v = mem[r + 1].cint;
    } 
    r = mem[r].hhfield.v.RH;
  } 
  x = mem[q].hhfield.lhfield;
  n = mem[x + 1].cint % 64;
  s = memtop - 1;
  mem[s].hhfield.v.RH = p;
  r = p;
  do {
      if (r == q) 
    {
      mem[s].hhfield.v.RH = mem[r].hhfield.v.RH;
      free_node (r , 2);
    } 
    else {
	
      w = makefraction (mem[r + 1].cint , v);
      if (abs (w) <= 1342) 
      {
	mem[s].hhfield.v.RH = mem[r].hhfield.v.RH;
	free_node (r , 2);
      } 
      else {
	  
	mem[r + 1].cint = - (integer) w;
	s = r;
      } 
    } 
    r = mem[s].hhfield.v.RH;
  } while (!(mem[r].hhfield.lhfield == 0));
  if (t == 18) 
  mem[r + 1].cint = - (integer) makescaled (mem[r + 1].cint , v);
  else if (v != -268435456L) 
  mem[r + 1].cint = - (integer) makefraction (mem[r + 1].cint , v);
  finalnode = r;
  p = mem[memtop - 1].hhfield.v.RH;
  if (internal[2] > 0) {
      
    if (interesting (x)) 
    {
      begin_diagnostic ();
      print_nl (597);
      print_variable_name (x);
      w = n;
      while (w > 0) {
	  
	print (590);
	w = w - 2;
      } 
      print_char (61);
      print_dependency (p , 17);
      end_diagnostic (false);
    } 
  } 
  prevr = 13;
  r = mem[13].hhfield.v.RH;
  while (r != 13) {
      
    s = mem[r + 1].hhfield.v.RH;
    q = pwithxbecomingq (s , x , p , mem[r].hhfield.b0);
    if (mem[q].hhfield.lhfield == 0) 
    make_known (r , q);
    else {
	
      mem[r + 1].hhfield.v.RH = q;
      do {
	  q = mem[q].hhfield.v.RH;
      } while (!(mem[q].hhfield.lhfield == 0));
      prevr = q;
    } 
    r = mem[prevr].hhfield.v.RH;
  } 
  if (n > 0) 
  {
    s = memtop - 1;
    mem[memtop - 1].hhfield.v.RH = p;
    r = p;
    do {
	if (n > 30) 
      w = 0;
      else w = mem[r + 1].cint / two_to_the[n];
      if ((abs (w) <= 1342) && (mem[r].hhfield.lhfield != 0)) 
      {
	mem[s].hhfield.v.RH = mem[r].hhfield.v.RH;
	free_node (r , 2);
      } 
      else {
	  
	mem[r + 1].cint = w;
	s = r;
      } 
      r = mem[s].hhfield.v.RH;
    } while (!(mem[s].hhfield.lhfield == 0));
    p = mem[memtop - 1].hhfield.v.RH;
  } 
  if (mem[p].hhfield.lhfield == 0) 
  {
    mem[x].hhfield.b0 = 16;
    mem[x + 1].cint = mem[p + 1].cint;
    if (abs (mem[x + 1].cint) >= 268435456L) 
    val_too_big (mem[x + 1].cint);
    free_node (p , 2);
    if (cur_exp == x) {
	
      if (cur_type == 19) 
      {
	cur_exp = mem[x + 1].cint;
	cur_type = 16;
	free_node (x , 2);
      } 
    } 
  } 
  else {
      
    mem[x].hhfield.b0 = 17;
    dep_final = finalnode;
    newdep (x , p);
    if (cur_exp == x) {
	
      if (cur_type == 19) 
      cur_type = 17;
    } 
  } 
  if (fix_needed) 
  fix_dependencies ();
} 
halfword 
znewringentry (halfword p) 
{
  register halfword Result; halfword q;
  q = get_node (2);
  mem[q].hhfield.b1 = 11;
  mem[q].hhfield.b0 = mem[p].hhfield.b0;
  if (mem[p + 1].cint == 0) 
  mem[q + 1].cint = p;
  else mem[q + 1].cint = mem[p + 1].cint;
  mem[p + 1].cint = q;
  Result = q;
  return Result;
} 
void 
znonlineareq (integer v , halfword p , boolean flushp) 
{
  small_number t;
  halfword q, r;
  t = mem[p].hhfield.b0 - 1;
  q = mem[p + 1].cint;
  if (flushp) 
  mem[p].hhfield.b0 = 1;
  else p = q;
  do {
      r = mem[q + 1].cint;
    mem[q].hhfield.b0 = t;
    switch (t) 
    {case 2 : 
      mem[q + 1].cint = v;
      break;
    case 4 : 
      {
	mem[q + 1].cint = v;
	{
	  if (str_ref[v]< 127) 
	  incr (str_ref[v]);
	} 
      } 
      break;
    case 6 : 
      {
	mem[q + 1].cint = v;
	incr (mem[v].hhfield.lhfield);
      } 
      break;
    case 9 : 
      mem[q + 1].cint = copypath (v);
      break;
    case 11 : 
      mem[q + 1].cint = copy_edges (v);
      break;
    } 
    q = r;
  } while (!(q == p));
} 
void 
zringmerge (halfword p , halfword q) 
{
  /* 10 */ halfword r;
  r = mem[p + 1].cint;
  while (r != p) {
      
    if (r == q) 
    {
      {
	{
	  if (interaction == 3) 
	;
	  if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
	  {
	    print_nl (261);
	    print (fullsourcefilenamestack[in_open]);
	    print (58);
	    print_int (line);
	    print (262);
	    print (600);
	  } 
	  else {
	      
	    print_nl (263);
	    print (600);
	  } 
	} 
	{
	  help_ptr = 2;
	  help_line[1] = 601;
	  help_line[0] = 602;
	} 
	put_get_error ();
      } 
      goto lab10;
    } 
    r = mem[r + 1].cint;
  } 
  r = mem[p + 1].cint;
  mem[p + 1].cint = mem[q + 1].cint;
  mem[q + 1].cint = r;
  lab10:;
} 
void 
zshow_cmd_mod (integer c , integer m) 
{
  begin_diagnostic ();
  print_nl (123);
  print_cmd_mod (c , m);
  print_char (125);
  end_diagnostic (false);
} 
void 
showcontext (void) 
{
  /* 30 */ unsigned char old_setting;
  integer i;
  integer l;
  integer m;
  integer n;
  integer p;
  integer q;
  file_ptr = input_ptr;
  input_stack[file_ptr] = cur_input;
  while (true) {
      
    cur_input = input_stack[file_ptr];
    if ((file_ptr == input_ptr) || (cur_input.index_field <= 15) || (
    cur_input.index_field != 19) || (cur_input.loc_field != 0)) 
    {
      tally = 0;
      old_setting = selector;
      if ((cur_input.index_field <= 15)) 
      {
	if (cur_input .name_field <= 1) {
	    
	  if ((cur_input .name_field == 0) && (file_ptr == 0)) 
	  print_nl (604);
	  else print_nl (605);
	} 
	else if (cur_input .name_field == 2) 
	print_nl (606);
	else {
	    
	  print_nl (607);
	  print_int (line);
	} 
	print_char (32);
	{
	  l = tally;
	  tally = 0;
	  selector = 4;
	  trick_count = 1000000L;
	} 
	if (cur_input .limit_field > 0) 
	{register integer for_end; i = cur_input .start_field;for_end = 
	cur_input .limit_field - 1; if (i <= for_end) do 
	  {
	    if (i == cur_input.loc_field) 
	    {
	      first_count = tally;
	      trick_count = tally + 1 + errorline - halferrorline;
	      if (trick_count < errorline) 
	      trick_count = errorline;
	    } 
	    print (buffer[i]);
	  } 
	while (i++ < for_end);} 
      } 
      else {
	  
	switch (cur_input.index_field) 
	{case 16 : 
	  print_nl (608);
	  break;
	case 17 : 
	  {
	    print_nl (613);
	    p = param_stack[cur_input .limit_field];
	    if (p != 0) {
		
	      if (mem[p].hhfield.v.RH == 1) 
	      print_exp (p , 0);
	      else show_token_list (p , 0 , 20 , tally);
	    } 
	    print (614);
	  } 
	  break;
	case 18 : 
	  print_nl (609);
	  break;
	case 19 : 
	  if (cur_input.loc_field == 0) 
	  print_nl (610);
	  else print_nl (611);
	  break;
	case 20 : 
	  print_nl (612);
	  break;
	case 21 : 
	  {
	    print_ln ();
	    if (cur_input .name_field != 0) 
	    slow_print (hash[cur_input .name_field].v.RH);
	    else {
		
	      p = param_stack[cur_input .limit_field];
	      if (p == 0) 
	      show_token_list (param_stack[cur_input .limit_field + 1], 0 , 20 
	      , tally);
	      else {
		  
		q = p;
		while (mem[q].hhfield.v.RH != 0) q = mem[q].hhfield 
		.v.RH;
		mem[q].hhfield.v.RH = param_stack[cur_input .limit_field + 
		1];
		show_token_list (p , 0 , 20 , tally);
		mem[q].hhfield.v.RH = 0;
	      } 
	    } 
	    print (501);
	  } 
	  break;
	  default: 
	  print_nl (63);
	  break;
	} 
	{
	  l = tally;
	  tally = 0;
	  selector = 4;
	  trick_count = 1000000L;
	} 
	if (cur_input.index_field != 21) 
	show_token_list (cur_input .start_field , cur_input.loc_field , 100000L , 
	0);
	else show_macro (cur_input .start_field , cur_input.loc_field , 100000L) 
	;
      } 
      selector = old_setting;
      if (trick_count == 1000000L) 
      {
	first_count = tally;
	trick_count = tally + 1 + errorline - halferrorline;
	if (trick_count < errorline) 
	trick_count = errorline;
      } 
      if (tally < trick_count) 
      m = tally - first_count;
      else m = trick_count - first_count;
      if (l + first_count <= halferrorline) 
      {
	p = 0;
	n = l + first_count;
      } 
      else {
	  
	print (276);
	p = l + first_count - halferrorline + 3;
	n = halferrorline;
      } 
      {register integer for_end; q = p;for_end = first_count - 1; if (q <= 
      for_end) do 
	print_char (trick_buf[q % errorline]);
      while (q++ < for_end);} 
      print_ln ();
      {register integer for_end; q = 1;for_end = n; if (q <= for_end) do 
	print_char (32);
      while (q++ < for_end);} 
      if (m + n <= errorline) 
      p = first_count + m;
      else p = first_count + (errorline - n - 3);
      {register integer for_end; q = first_count;for_end = p - 1; if (q <= 
      for_end) do 
	print_char (trick_buf[q % errorline]);
      while (q++ < for_end);} 
      if (m + n > errorline) 
      print (276);
    } 
    if ((cur_input.index_field <= 15)) {
	
      if ((cur_input .name_field > 2) || (file_ptr == 0)) 
      goto done;
    } 
    decr (file_ptr);
  } 
  done: cur_input = input_stack[input_ptr];
} 
void 
zbegintokenlist (halfword p , quarterword t) 
{
  {
    if (input_ptr > max_in_stack) 
    {
      max_in_stack = input_ptr;
      if (input_ptr == stack_size) 
      overflow (615 , stack_size);
    } 
    input_stack[input_ptr] = cur_input;
    incr (input_ptr);
  } 
  cur_input .start_field = p;
  cur_input.index_field = t;
  cur_input .limit_field = param_ptr;
  cur_input.loc_field = p;
} 
void 
endtokenlist (void) 
{
  /* 30 */ halfword p;
  if (cur_input.index_field >= 19) {
      
    if (cur_input.index_field <= 20) 
    {
      flush_token_list (cur_input .start_field);
      goto done;
    } 
    else delete_mac_ref (cur_input .start_field);
  } 
  while (param_ptr > cur_input .limit_field) {
      
    decr (param_ptr);
    p = param_stack[param_ptr];
    if (p != 0) {
	
      if (mem[p].hhfield.v.RH == 1) 
      {
	recycle_value (p);
	free_node (p , 2);
      } 
      else flush_token_list (p);
    } 
  } 
  done: {
      
    decr (input_ptr);
    cur_input = input_stack[input_ptr];
  } 
  {
    if (interrupt != 0) 
    pause_for_instructions ();
  } 
} 
void 
zencapsulate (halfword p) 
{
  cur_exp = get_node (2);
  mem[cur_exp].hhfield.b0 = cur_type;
  mem[cur_exp].hhfield.b1 = 11;
  newdep (cur_exp , p);
} 
void 
zinstall (halfword r , halfword q) 
{
  halfword p;
  if (mem[q].hhfield.b0 == 16) 
  {
    mem[r + 1].cint = mem[q + 1].cint;
    mem[r].hhfield.b0 = 16;
  } 
  else if (mem[q].hhfield.b0 == 19) 
  {
    p = singledependency (q);
    if (p == dep_final) 
    {
      mem[r].hhfield.b0 = 16;
      mem[r + 1].cint = 0;
      free_node (p , 2);
    } 
    else {
	
      mem[r].hhfield.b0 = 17;
      newdep (r , p);
    } 
  } 
  else {
      
    mem[r].hhfield.b0 = mem[q].hhfield.b0;
    newdep (r , copydeplist (mem[q + 1].hhfield.v.RH));
  } 
} 
void 
zmakeexpcopy (halfword p) 
{
  /* 20 */ halfword q, r, t;
  lab20: cur_type = mem[p].hhfield.b0;
  switch (cur_type) 
  {case 1 : 
  case 2 : 
  case 16 : 
    cur_exp = mem[p + 1].cint;
    break;
  case 3 : 
  case 5 : 
  case 7 : 
  case 12 : 
  case 10 : 
    cur_exp = newringentry (p);
    break;
  case 4 : 
    {
      cur_exp = mem[p + 1].cint;
      {
	if (str_ref[cur_exp]< 127) 
	incr (str_ref[cur_exp]);
      } 
    } 
    break;
  case 6 : 
    {
      cur_exp = mem[p + 1].cint;
      incr (mem[cur_exp].hhfield.lhfield);
    } 
    break;
  case 11 : 
    cur_exp = copy_edges (mem[p + 1].cint);
    break;
  case 9 : 
  case 8 : 
    cur_exp = copypath (mem[p + 1].cint);
    break;
  case 13 : 
  case 14 : 
    {
      if (mem[p + 1].cint == 0) 
      init_big_node (p);
      t = get_node (2);
      mem[t].hhfield.b1 = 11;
      mem[t].hhfield.b0 = cur_type;
      init_big_node (t);
      q = mem[p + 1].cint + big_node_size[cur_type];
      r = mem[t + 1].cint + big_node_size[cur_type];
      do {
	  q = q - 2;
	r = r - 2;
	install (r , q);
      } while (!(q == mem[p + 1].cint));
      cur_exp = t;
    } 
    break;
  case 17 : 
  case 18 : 
    encapsulate (copydeplist (mem[p + 1].hhfield.v.RH));
    break;
  case 15 : 
    {
      {
	if (serial_no > 2147483583L) 
	overflow (588 , serial_no / 64);
	mem[p].hhfield.b0 = 19;
	serial_no = serial_no + 64;
	mem[p + 1].cint = serial_no;
      } 
      goto lab20;
    } 
    break;
  case 19 : 
    {
      q = singledependency (p);
      if (q == dep_final) 
      {
	cur_type = 16;
	cur_exp = 0;
	free_node (q , 2);
      } 
      else {
	  
	cur_type = 17;
	encapsulate (q);
      } 
    } 
    break;
    default: 
    confusion (800);
    break;
  } 
} 
halfword 
cur_tok (void) 
{
  register halfword Result; halfword p;
  small_number savetype;
  integer saveexp;
  if (cur_sym == 0) {
      
    if (cur_cmd == 38) 
    {
      savetype = cur_type;
      saveexp = cur_exp;
      makeexpcopy (cur_mod);
      p = stash_cur_exp ();
      mem[p].hhfield.v.RH = 0;
      cur_type = savetype;
      cur_exp = saveexp;
    } 
    else {
	
      p = get_node (2);
      mem[p + 1].cint = cur_mod;
      mem[p].hhfield.b1 = 12;
      if (cur_cmd == 42) 
      mem[p].hhfield.b0 = 16;
      else mem[p].hhfield.b0 = 4;
    } 
  } 
  else {
      
    {
      p = avail;
      if (p == 0) 
      p = get_avail ();
      else {
	  
	avail = mem[p].hhfield.v.RH;
	mem[p].hhfield.v.RH = 0;
	;
#ifdef STAT
	incr (dyn_used);
#endif /* STAT */
      } 
    } 
    mem[p].hhfield.lhfield = cur_sym;
  } 
  Result = p;
  return Result;
} 
void 
backinput (void) 
{
  halfword p;
  p = cur_tok ();
  while ((cur_input.index_field > 15) && (cur_input.loc_field == 0)) 
  endtokenlist ();
  begintokenlist (p , 19);
} 
void 
backerror (void) 
{
  OK_to_interrupt = false;
  backinput ();
  OK_to_interrupt = true;
  error ();
} 
void 
inserror (void) 
{
  OK_to_interrupt = false;
  backinput ();
  cur_input.index_field = 20;
  OK_to_interrupt = true;
  error ();
} 
void 
beginfilereading (void) 
{
  if (in_open == 15) 
  overflow (616 , 15);
  if (first == bufsize) 
  overflow (256 , bufsize);
  incr (in_open);
  {
    if (input_ptr > max_in_stack) 
    {
      max_in_stack = input_ptr;
      if (input_ptr == stack_size) 
      overflow (615 , stack_size);
    } 
    input_stack[input_ptr] = cur_input;
    incr (input_ptr);
  } 
  cur_input.index_field = in_open;
  line_stack[cur_input.index_field] = line;
  cur_input .start_field = first;
  cur_input .name_field = 0;
} 
void 
endfilereading (void) 
{
  first = cur_input .start_field;
  line = line_stack[cur_input.index_field];
  if (cur_input.index_field != in_open) 
  confusion (617);
  if (cur_input .name_field > 2) 
  aclose (input_file[cur_input.index_field]);
  {
    decr (input_ptr);
    cur_input = input_stack[input_ptr];
  } 
  decr (in_open);
} 
void 
clearforerrorprompt (void) 
{
  while ((cur_input.index_field <= 15) && (cur_input .name_field == 0) && 
  (input_ptr > 0) && (cur_input.loc_field == cur_input .limit_field)) 
  endfilereading ();
  print_ln ();
} 
boolean 
checkoutervalidity (void) 
{
  register boolean Result; halfword p;
  if (scanner_status == 0) 
  Result = true;
  else {
      
    deletions_allowed = false;
    if (cur_sym != 0) 
    {
      p = get_avail ();
      mem[p].hhfield.lhfield = cur_sym;
      begintokenlist (p , 19);
    } 
    if (scanner_status > 1) 
    {
      runaway ();
      if (cur_sym == 0) 
      {
	if (interaction == 3) 
	;
	if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
	{
	  print_nl (261);
	  print (fullsourcefilenamestack[in_open]);
	  print (58);
	  print_int (line);
	  print (262);
	  print (623);
	} 
	else {
	    
	  print_nl (263);
	  print (623);
	} 
      } 
      else {
	  
	{
	  if (interaction == 3) 
	;
	  if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
	  {
	    print_nl (261);
	    print (fullsourcefilenamestack[in_open]);
	    print (58);
	    print_int (line);
	    print (262);
	    print (624);
	  } 
	  else {
	      
	    print_nl (263);
	    print (624);
	  } 
	} 
      } 
      print (625);
      {
	help_ptr = 4;
	help_line[3] = 626;
	help_line[2] = 627;
	help_line[1] = 628;
	help_line[0] = 629;
      } 
      switch (scanner_status) 
      {case 2 : 
	{
	  print (630);
	  help_line[3] = 631;
	  cur_sym = 9763;
	} 
	break;
      case 3 : 
	{
	  print (632);
	  help_line[3] = 633;
	  if (warning_info == 0) 
	  cur_sym = 9767;
	  else {
	      
	    cur_sym = 9759;
	    eqtb[9759].v.RH = warning_info;
	  } 
	} 
	break;
      case 4 : 
      case 5 : 
	{
	  print (634);
	  if (scanner_status == 5) 
	  slow_print (hash[warning_info].v.RH);
	  else print_variable_name (warning_info);
	  cur_sym = 9765;
	} 
	break;
      case 6 : 
	{
	  print (635);
	  slow_print (hash[warning_info].v.RH);
	  print (636);
	  help_line[3] = 637;
	  cur_sym = 9764;
	} 
	break;
      } 
      inserror ();
    } 
    else {
	
      {
	if (interaction == 3) 
	;
	if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
	{
	  print_nl (261);
	  print (fullsourcefilenamestack[in_open]);
	  print (58);
	  print_int (line);
	  print (262);
	  print (618);
	} 
	else {
	    
	  print_nl (263);
	  print (618);
	} 
      } 
      print_int (warning_info);
      {
	help_ptr = 3;
	help_line[2] = 619;
	help_line[1] = 620;
	help_line[0] = 621;
      } 
      if (cur_sym == 0) 
      help_line[2] = 622;
      cur_sym = 9766;
      inserror ();
    } 
    deletions_allowed = true;
    Result = false;
  } 
  return Result;
} 
void 
getnext (void) 
{
  /* 20 10 40 25 85 86 87 30 */ integer k;
  ASCII_code c;
  ASCII_code cclass;
  integer n, f;
  lab20: cur_sym = 0;
  if ((cur_input.index_field <= 15)) 
  {
    lab25: c = buffer[cur_input.loc_field];
    incr (cur_input.loc_field);
    cclass = char_class[c];
    switch (cclass) 
    {case 0 : 
      goto lab85;
      break;
    case 1 : 
      {
	cclass = char_class[buffer[cur_input.loc_field]];
	if (cclass > 1) 
	goto lab25;
	else if (cclass < 1) 
	{
	  n = 0;
	  goto lab86;
	} 
      } 
      break;
    case 2 : 
      goto lab25;
      break;
    case 3 : 
      {
	if (cur_input .name_field > 2) 
	{
	  incr (line);
	  first = cur_input .start_field;
	  if (!force_eof) 
	  {
	    if (inputln (input_file[cur_input.index_field], true)) 
	    firmuptheline ();
	    else force_eof = true;
	  } 
	  if (force_eof) 
	  {
	    print_char (41);
	    decr (open_parens);
	    fflush (stdout);
	    force_eof = false;
	    endfilereading ();
	    if (checkoutervalidity ()) 
	    goto lab20;
	    else goto lab20;
	  } 
	  buffer[cur_input .limit_field] = 37;
	  first = cur_input .limit_field + 1;
	  cur_input.loc_field = cur_input .start_field;
	} 
	else {
	    
	  if (input_ptr > 0) 
	  {
	    endfilereading ();
	    goto lab20;
	  } 
	  if (selector < 2) 
	  open_log_file ();
	  if (interaction > 1) 
	  {
	    if (cur_input .limit_field == cur_input .start_field) 
	    print_nl (652);
	    print_ln ();
	    first = cur_input .start_field;
	    {
	;
	      print (42);
	      term_input ();
	    } 
	    cur_input .limit_field = last;
	    buffer[cur_input .limit_field] = 37;
	    first = cur_input .limit_field + 1;
	    cur_input.loc_field = cur_input .start_field;
	  } 
	  else fatal_error (653);
	} 
	{
	  if (interrupt != 0) 
	  pause_for_instructions ();
	} 
	goto lab25;
      } 
      break;
    case 4 : 
      {
	if (buffer[cur_input.loc_field] == 34) 
	cur_mod = 261;
	else {
	    
	  k = cur_input.loc_field;
	  buffer[cur_input .limit_field + 1] = 34;
	  do {
	      incr (cur_input.loc_field);
	  } while (!(buffer[cur_input.loc_field] == 34));
	  if (cur_input.loc_field > cur_input .limit_field) 
	  {
	    cur_input.loc_field = cur_input .limit_field;
	    {
	      if (interaction == 3) 
	;
	      if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
	      {
		print_nl (261);
		print (fullsourcefilenamestack[in_open]);
		print (58);
		print_int (line);
		print (262);
		print (645);
	      } 
	      else {
		  
		print_nl (263);
		print (645);
	      } 
	    } 
	    {
	      help_ptr = 3;
	      help_line[2] = 646;
	      help_line[1] = 647;
	      help_line[0] = 648;
	    } 
	    deletions_allowed = false;
	    error ();
	    deletions_allowed = true;
	    goto lab20;
	  } 
	  if ((cur_input.loc_field == k + 1) && ((str_start[buffer[k]
	  + 1] - str_start[buffer[k]]) == 1)) 
	  cur_mod = buffer[k];
	  else {
	      
	    {
	      if (pool_ptr + cur_input.loc_field - k > max_pool_ptr) 
	      {
		if (pool_ptr + cur_input.loc_field - k > pool_size) 
		overflow (257 , pool_size - init_pool_ptr);
		max_pool_ptr = pool_ptr + cur_input.loc_field - k;
	      } 
	    } 
	    do {
		{ 
		str_pool[pool_ptr] = buffer[k];
		incr (pool_ptr);
	      } 
	      incr (k);
	    } while (!(k == cur_input.loc_field));
	    cur_mod = make_string ();
	  } 
	} 
	incr (cur_input.loc_field);
	cur_cmd = 39;
	goto lab10;
      } 
      break;
    case 5 : 
    case 6 : 
    case 7 : 
    case 8 : 
      {
	k = cur_input.loc_field - 1;
	goto found;
      } 
      break;
    case 20 : 
      {
	{
	  if (interaction == 3) 
	;
	  if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
	  {
	    print_nl (261);
	    print (fullsourcefilenamestack[in_open]);
	    print (58);
	    print_int (line);
	    print (262);
	    print (642);
	  } 
	  else {
	      
	    print_nl (263);
	    print (642);
	  } 
	} 
	{
	  help_ptr = 2;
	  help_line[1] = 643;
	  help_line[0] = 644;
	} 
	deletions_allowed = false;
	error ();
	deletions_allowed = true;
	goto lab20;
      } 
      break;
      default: 
;
      break;
    } 
    k = cur_input.loc_field - 1;
    while (char_class[buffer[cur_input.loc_field]] == cclass) incr (
    cur_input.loc_field);
    goto found;
    lab85: n = c - 48;
    while (char_class[buffer[cur_input.loc_field]] == 0) {
	
      if (n < 4096) 
      n = 10 * n + buffer[cur_input.loc_field] - 48;
      incr (cur_input.loc_field);
    } 
    if (buffer[cur_input.loc_field] == 46) {
	
      if (char_class[buffer[cur_input.loc_field + 1]] == 0) 
      goto done;
    } 
    f = 0;
    goto lab87;
    done: incr (cur_input.loc_field);
    lab86: k = 0;
    do {
	if (k < 17) 
      {
	dig[k] = buffer[cur_input.loc_field] - 48;
	incr (k);
      } 
      incr (cur_input.loc_field);
    } while (!(char_class[buffer[cur_input.loc_field]]!= 0));
    f = round_decimals (k);
    if (f == 65536L) 
    {
      incr (n);
      f = 0;
    } 
    lab87: if (n < 4096) 
    cur_mod = n * 65536L + f;
    else {
	
      {
	if (interaction == 3) 
	;
	if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
	{
	  print_nl (261);
	  print (fullsourcefilenamestack[in_open]);
	  print (58);
	  print_int (line);
	  print (262);
	  print (649);
	} 
	else {
	    
	  print_nl (263);
	  print (649);
	} 
      } 
      {
	help_ptr = 2;
	help_line[1] = 650;
	help_line[0] = 651;
      } 
      deletions_allowed = false;
      error ();
      deletions_allowed = true;
      cur_mod = 268435455L;
    } 
    cur_cmd = 42;
    goto lab10;
    found: cur_sym = id_lookup (k , cur_input.loc_field - k);
  } 
  else if (cur_input.loc_field >= hi_mem_min) 
  {
    cur_sym = mem[cur_input.loc_field].hhfield.lhfield;
    cur_input.loc_field = mem[cur_input.loc_field].hhfield.v.RH;
    if (cur_sym >= 9770) {
	
      if (cur_sym >= 9920) 
      {
	if (cur_sym >= 10070) 
	cur_sym = cur_sym - 150;
	begintokenlist (param_stack[cur_input .limit_field + cur_sym - (9920) 
	], 18);
	goto lab20;
      } 
      else {
	  
	cur_cmd = 38;
	cur_mod = param_stack[cur_input .limit_field + cur_sym - (9770)];
	cur_sym = 0;
	goto lab10;
      } 
    } 
  } 
  else if (cur_input.loc_field > 0) 
  {
    if (mem[cur_input.loc_field].hhfield.b1 == 12) 
    {
      cur_mod = mem[cur_input.loc_field + 1].cint;
      if (mem[cur_input.loc_field].hhfield.b0 == 16) 
      cur_cmd = 42;
      else {
	  
	cur_cmd = 39;
	{
	  if (str_ref[cur_mod]< 127) 
	  incr (str_ref[cur_mod]);
	} 
      } 
    } 
    else {
	
      cur_mod = cur_input.loc_field;
      cur_cmd = 38;
    } 
    cur_input.loc_field = mem[cur_input.loc_field].hhfield.v.RH;
    goto lab10;
  } 
  else {
      
    endtokenlist ();
    goto lab20;
  } 
  cur_cmd = eqtb[cur_sym].lhfield;
  cur_mod = eqtb[cur_sym].v.RH;
  if (cur_cmd >= 86) {
      
    if (checkoutervalidity ()) 
    cur_cmd = cur_cmd - 86;
    else goto lab20;
  } 
  lab10:;
} 
void 
firmuptheline (void) 
{
  integer k;
  cur_input .limit_field = last;
  if (internal[31] > 0) {
      
    if (interaction > 1) 
    {
;
      print_ln ();
      if (cur_input .start_field < cur_input .limit_field) 
      {register integer for_end; k = cur_input .start_field;for_end = 
      cur_input .limit_field - 1; if (k <= for_end) do 
	print (buffer[k]);
      while (k++ < for_end);} 
      first = cur_input .limit_field;
      {
	;
	print (654);
	term_input ();
      } 
      if (last > first) 
      {
	{register integer for_end; k = first;for_end = last - 1; if (k <= 
	for_end) do 
	  buffer[k + cur_input .start_field - first] = buffer[k];
	while (k++ < for_end);} 
	cur_input .limit_field = cur_input .start_field + last - first;
      } 
    } 
  } 
} 
halfword 
zscantoks (commandcode terminator , halfword substlist , halfword tailend , 
small_number suffixcount) 
{
  /* 30 40 */ register halfword Result; halfword p;
  halfword q;
  integer balance;
  p = memtop - 2;
  balance = 1;
  mem[memtop - 2].hhfield.v.RH = 0;
  while (true) {
      
    getnext ();
    if (cur_sym > 0) 
    {
      {
	q = substlist;
	while (q != 0) {
	    
	  if (mem[q].hhfield.lhfield == cur_sym) 
	  {
	    cur_sym = mem[q + 1].cint;
	    cur_cmd = 7;
	    goto found;
	  } 
	  q = mem[q].hhfield.v.RH;
	} 
	found:;
      } 
      if (cur_cmd == terminator) {
	  
	if (cur_mod > 0) 
	incr (balance);
	else {
	    
	  decr (balance);
	  if (balance == 0) 
	  goto done;
	} 
      } 
      else if (cur_cmd == 61) 
      {
	if (cur_mod == 0) 
	getnext ();
	else if (cur_mod <= suffixcount) 
	cur_sym = 9919 + cur_mod;
      } 
    } 
    mem[p].hhfield.v.RH = cur_tok ();
    p = mem[p].hhfield.v.RH;
  } 
  done: mem[p].hhfield.v.RH = tailend;
  flush_node_list (substlist);
  Result = mem[memtop - 2].hhfield.v.RH;
  return Result;
} 
void 
getsymbol (void) 
{
  /* 20 */ lab20: getnext ();
  if ((cur_sym == 0) || (cur_sym > 9757)) 
  {
    {
      if (interaction == 3) 
;
      if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[in_open]);
	print (58);
	print_int (line);
	print (262);
	print (666);
      } 
      else {
	  
	print_nl (263);
	print (666);
      } 
    } 
    {
      help_ptr = 3;
      help_line[2] = 667;
      help_line[1] = 668;
      help_line[0] = 669;
    } 
    if (cur_sym > 0) 
    help_line[2] = 670;
    else if (cur_cmd == 39) 
    {
      if (str_ref[cur_mod]< 127) {
	  
	if (str_ref[cur_mod] > 1) 
	decr (str_ref[cur_mod]);
	else flush_string (cur_mod);
      } 
    } 
    cur_sym = 9757;
    inserror ();
    goto lab20;
  } 
} 
void 
getclearsymbol (void) 
{
  getsymbol ();
  clearsymbol (cur_sym , false);
} 
void 
checkequals (void) 
{
  if (cur_cmd != 51) {
      
    if (cur_cmd != 77) 
    {
      missing_err (61);
      {
	help_ptr = 5;
	help_line[4] = 671;
	help_line[3] = 672;
	help_line[2] = 673;
	help_line[1] = 674;
	help_line[0] = 675;
      } 
      backerror ();
    } 
  } 
} 
void 
makeopdef (void) 
{
  commandcode m;
  halfword p, q, r;
  m = cur_mod;
  getsymbol ();
  q = get_node (2);
  mem[q].hhfield.lhfield = cur_sym;
  mem[q + 1].cint = 9770;
  getclearsymbol ();
  warning_info = cur_sym;
  getsymbol ();
  p = get_node (2);
  mem[p].hhfield.lhfield = cur_sym;
  mem[p + 1].cint = 9771;
  mem[p].hhfield.v.RH = q;
  getnext ();
  checkequals ();
  scanner_status = 5;
  q = get_avail ();
  mem[q].hhfield.lhfield = 0;
  r = get_avail ();
  mem[q].hhfield.v.RH = r;
  mem[r].hhfield.lhfield = 0;
  mem[r].hhfield.v.RH = scantoks (16 , p , 0 , 0);
  scanner_status = 0;
  eqtb[warning_info].lhfield = m;
  eqtb[warning_info].v.RH = q;
  getxnext ();
} 
void 
zcheckdelimiter (halfword ldelim , halfword rdelim) 
{
  /* 10 */ if (cur_cmd == 62) {
      
    if (cur_mod == ldelim) 
    goto lab10;
  } 
  if (cur_sym != rdelim) 
  {
    missing_err (hash[rdelim].v.RH);
    {
      help_ptr = 2;
      help_line[1] = 922;
      help_line[0] = 923;
    } 
    backerror ();
  } 
  else {
      
    {
      if (interaction == 3) 
;
      if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[in_open]);
	print (58);
	print_int (line);
	print (262);
	print (924);
      } 
      else {
	  
	print_nl (263);
	print (924);
      } 
    } 
    slow_print (hash[rdelim].v.RH);
    print (925);
    {
      help_ptr = 3;
      help_line[2] = 926;
      help_line[1] = 927;
      help_line[0] = 928;
    } 
    error ();
  } 
  lab10:;
} 
halfword 
scandeclaredvariable (void) 
{
  /* 30 */ register halfword Result; halfword x;
  halfword h, t;
  halfword l;
  getsymbol ();
  x = cur_sym;
  if (cur_cmd != 41) 
  clearsymbol (x , false);
  h = get_avail ();
  mem[h].hhfield.lhfield = x;
  t = h;
  while (true) {
      
    getxnext ();
    if (cur_sym == 0) 
    goto done;
    if (cur_cmd != 41) {
	
      if (cur_cmd != 40) {
	  
	if (cur_cmd == 63) 
	{
	  l = cur_sym;
	  getxnext ();
	  if (cur_cmd != 64) 
	  {
	    backinput ();
	    cur_sym = l;
	    cur_cmd = 63;
	    goto done;
	  } 
	  else cur_sym = 0;
	} 
	else goto done;
      } 
    } 
    mem[t].hhfield.v.RH = get_avail ();
    t = mem[t].hhfield.v.RH;
    mem[t].hhfield.lhfield = cur_sym;
  } 
  done: if (eqtb[x].lhfield % 86 != 41) 
  clearsymbol (x , false);
  if (eqtb[x].v.RH == 0) 
  new_root (x);
  Result = h;
  return Result;
} 
void 
scandef (void) 
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
  mem[memtop - 2].hhfield.v.RH = 0;
  q = get_avail ();
  mem[q].hhfield.lhfield = 0;
  r = 0;
  if (m == 1) 
  {
    getclearsymbol ();
    warning_info = cur_sym;
    getnext ();
    scanner_status = 5;
    n = 0;
    eqtb[warning_info].lhfield = 10;
    eqtb[warning_info].v.RH = q;
  } 
  else {
      
    p = scandeclaredvariable ();
    flushvariable (eqtb[mem[p].hhfield.lhfield].v.RH , mem[p]
    .hhfield.v.RH , true);
    warning_info = find_variable (p);
    flush_list (p);
    if (warning_info == 0) 
    {
      {
	if (interaction == 3) 
	;
	if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
	{
	  print_nl (261);
	  print (fullsourcefilenamestack[in_open]);
	  print (58);
	  print_int (line);
	  print (262);
	  print (682);
	} 
	else {
	    
	  print_nl (263);
	  print (682);
	} 
      } 
      {
	help_ptr = 2;
	help_line[1] = 683;
	help_line[0] = 684;
      } 
      error ();
      warning_info = 21;
    } 
    scanner_status = 4;
    n = 2;
    if (cur_cmd == 61) {
	
      if (cur_mod == 3) 
      {
	n = 3;
	getnext ();
      } 
    } 
    mem[warning_info].hhfield.b0 = 20 + n;
    mem[warning_info + 1].cint = q;
  } 
  k = n;
  if (cur_cmd == 31) 
  do {
      ldelim = cur_sym;
    rdelim = cur_mod;
    getnext ();
    if ((cur_cmd == 56) && (cur_mod >= 9770)) 
    base = cur_mod;
    else {
	
      {
	if (interaction == 3) 
	;
	if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
	{
	  print_nl (261);
	  print (fullsourcefilenamestack[in_open]);
	  print (58);
	  print_int (line);
	  print (262);
	  print (685);
	} 
	else {
	    
	  print_nl (263);
	  print (685);
	} 
      } 
      {
	help_ptr = 1;
	help_line[0] = 686;
      } 
      backerror ();
      base = 9770;
    } 
    do {
	mem[q].hhfield.v.RH = get_avail ();
      q = mem[q].hhfield.v.RH;
      mem[q].hhfield.lhfield = base + k;
      getsymbol ();
      p = get_node (2);
      mem[p + 1].cint = base + k;
      mem[p].hhfield.lhfield = cur_sym;
      if (k == 150) 
      overflow (687 , 150);
      incr (k);
      mem[p].hhfield.v.RH = r;
      r = p;
      getnext ();
    } while (!(cur_cmd != 82));
    checkdelimiter (ldelim , rdelim);
    getnext ();
  } while (!(cur_cmd != 31));
  if (cur_cmd == 56) 
  {
    p = get_node (2);
    if (cur_mod < 9770) 
    {
      c = cur_mod;
      mem[p + 1].cint = 9770 + k;
    } 
    else {
	
      mem[p + 1].cint = cur_mod + k;
      if (cur_mod == 9770) 
      c = 4;
      else if (cur_mod == 9920) 
      c = 6;
      else c = 7;
    } 
    if (k == 150) 
    overflow (687 , 150);
    incr (k);
    getsymbol ();
    mem[p].hhfield.lhfield = cur_sym;
    mem[p].hhfield.v.RH = r;
    r = p;
    getnext ();
    if (c == 4) {
	
      if (cur_cmd == 69) 
      {
	c = 5;
	p = get_node (2);
	if (k == 150) 
	overflow (687 , 150);
	mem[p + 1].cint = 9770 + k;
	getsymbol ();
	mem[p].hhfield.lhfield = cur_sym;
	mem[p].hhfield.v.RH = r;
	r = p;
	getnext ();
      } 
    } 
  } 
  checkequals ();
  p = get_avail ();
  mem[p].hhfield.lhfield = c;
  mem[q].hhfield.v.RH = p;
  if (m == 1) 
  mem[p].hhfield.v.RH = scantoks (16 , r , 0 , n);
  else {
      
    q = get_avail ();
    mem[q].hhfield.lhfield = bg_loc;
    mem[p].hhfield.v.RH = q;
    p = get_avail ();
    mem[p].hhfield.lhfield = eg_loc;
    mem[q].hhfield.v.RH = scantoks (16 , r , p , n);
  } 
  if (warning_info == 21) 
  flush_token_list (mem[22].cint);
  scanner_status = 0;
  getxnext ();
} 
void 
zprintmacroname (halfword a , halfword n) 
{
  halfword p, q;
  if (n != 0) 
  slow_print (hash[n].v.RH);
  else {
      
    p = mem[a].hhfield.lhfield;
    if (p == 0) 
    slow_print (hash[mem[mem[mem[a].hhfield.v.RH].hhfield 
  .lhfield].hhfield.lhfield].v.RH);
    else {
	
      q = p;
      while (mem[q].hhfield.v.RH != 0) q = mem[q].hhfield.v.RH;
      mem[q].hhfield.v.RH = mem[mem[a].hhfield.v.RH].hhfield 
    .lhfield;
      show_token_list (p , 0 , 1000 , 0);
      mem[q].hhfield.v.RH = 0;
    } 
  } 
} 
void 
zprintarg (halfword q , integer n , halfword b) 
{
  if (mem[q].hhfield.v.RH == 1) 
  print_nl (498);
  else if ((b < 10070) && (b != 7)) 
  print_nl (499);
  else print_nl (500);
  print_int (n);
  print (703);
  if (mem[q].hhfield.v.RH == 1) 
  print_exp (q , 1);
  else show_token_list (q , 0 , 1000 , 0);
} 
void 
zscantextarg (halfword ldelim , halfword rdelim) 
{
  /* 30 */ integer balance;
  halfword p;
  warning_info = ldelim;
  scanner_status = 3;
  p = memtop - 2;
  balance = 1;
  mem[memtop - 2].hhfield.v.RH = 0;
  while (true) {
      
    getnext ();
    if (ldelim == 0) 
    {
      if (cur_cmd > 82) 
      {
	if (balance == 1) 
	goto done;
	else if (cur_cmd == 84) 
	decr (balance);
      } 
      else if (cur_cmd == 32) 
      incr (balance);
    } 
    else {
	
      if (cur_cmd == 62) 
      {
	if (cur_mod == ldelim) 
	{
	  decr (balance);
	  if (balance == 0) 
	  goto done;
	} 
      } 
      else if (cur_cmd == 31) {
	  
	if (cur_mod == rdelim) 
	incr (balance);
      } 
    } 
    mem[p].hhfield.v.RH = cur_tok ();
    p = mem[p].hhfield.v.RH;
  } 
  done: cur_exp = mem[memtop - 2].hhfield.v.RH;
  cur_type = 20;
  scanner_status = 0;
} 
void 
zmacrocall (halfword defref , halfword arglist , halfword macroname) 
{
  /* 40 */ halfword r;
  halfword p, q;
  integer n;
  halfword ldelim, rdelim;
  halfword tail;
  r = mem[defref].hhfield.v.RH;
  incr (mem[defref].hhfield.lhfield);
  if (arglist == 0) 
  n = 0;
  else {
      
    n = 1;
    tail = arglist;
    while (mem[tail].hhfield.v.RH != 0) {
	
      incr (n);
      tail = mem[tail].hhfield.v.RH;
    } 
  } 
  if (internal[9] > 0) 
  {
    begin_diagnostic ();
    print_ln ();
    printmacroname (arglist , macroname);
    if (n == 3) 
    print (665);
    show_macro (defref , 0 , 100000L);
    if (arglist != 0) 
    {
      n = 0;
      p = arglist;
      do {
	  q = mem[p].hhfield.lhfield;
	printarg (q , n , 0);
	incr (n);
	p = mem[p].hhfield.v.RH;
      } while (!(p == 0));
    } 
    end_diagnostic (false);
  } 
  cur_cmd = 83;
  while (mem[r].hhfield.lhfield >= 9770) {
      
    if (cur_cmd != 82) 
    {
      getxnext ();
      if (cur_cmd != 31) 
      {
	{
	  if (interaction == 3) 
	;
	  if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
	  {
	    print_nl (261);
	    print (fullsourcefilenamestack[in_open]);
	    print (58);
	    print_int (line);
	    print (262);
	    print (709);
	  } 
	  else {
	      
	    print_nl (263);
	    print (709);
	  } 
	} 
	printmacroname (arglist , macroname);
	{
	  help_ptr = 3;
	  help_line[2] = 710;
	  help_line[1] = 711;
	  help_line[0] = 712;
	} 
	if (mem[r].hhfield.lhfield >= 9920) 
	{
	  cur_exp = 0;
	  cur_type = 20;
	} 
	else {
	    
	  cur_exp = 0;
	  cur_type = 16;
	} 
	backerror ();
	cur_cmd = 62;
	goto found;
      } 
      ldelim = cur_sym;
      rdelim = cur_mod;
    } 
    if (mem[r].hhfield.lhfield >= 10070) 
    scantextarg (ldelim , rdelim);
    else {
	
      getxnext ();
      if (mem[r].hhfield.lhfield >= 9920) 
      scan_suffix ();
      else scan_expression ();
    } 
    if (cur_cmd != 82) {
	
      if ((cur_cmd != 62) || (cur_mod != ldelim)) {
	  
	if (mem[mem[r].hhfield.v.RH].hhfield.lhfield >= 9770) 
	{
	  missing_err (44);
	  {
	    help_ptr = 3;
	    help_line[2] = 713;
	    help_line[1] = 714;
	    help_line[0] = 708;
	  } 
	  backerror ();
	  cur_cmd = 82;
	} 
	else {
	    
	  missing_err (hash[rdelim].v.RH);
	  {
	    help_ptr = 2;
	    help_line[1] = 715;
	    help_line[0] = 708;
	  } 
	  backerror ();
	} 
      } 
    } 
    found: {
	
      p = get_avail ();
      if (cur_type == 20) 
      mem[p].hhfield.lhfield = cur_exp;
      else mem[p].hhfield.lhfield = stash_cur_exp ();
      if (internal[9] > 0) 
      {
	begin_diagnostic ();
	printarg (mem[p].hhfield.lhfield , n , mem[r].hhfield 
	.lhfield);
	end_diagnostic (false);
      } 
      if (arglist == 0) 
      arglist = p;
      else mem[tail].hhfield.v.RH = p;
      tail = p;
      incr (n);
    } 
    r = mem[r].hhfield.v.RH;
  } 
  if (cur_cmd == 82) 
  {
    {
      if (interaction == 3) 
;
      if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[in_open]);
	print (58);
	print_int (line);
	print (262);
	print (704);
      } 
      else {
	  
	print_nl (263);
	print (704);
      } 
    } 
    printmacroname (arglist , macroname);
    print_char (59);
    print_nl (705);
    slow_print (hash[rdelim].v.RH);
    print (299);
    {
      help_ptr = 3;
      help_line[2] = 706;
      help_line[1] = 707;
      help_line[0] = 708;
    } 
    error ();
  } 
  if (mem[r].hhfield.lhfield != 0) 
  {
    if (mem[r].hhfield.lhfield < 7) 
    {
      getxnext ();
      if (mem[r].hhfield.lhfield != 6) {
	  
	if ((cur_cmd == 51) || (cur_cmd == 77)) 
	getxnext ();
      } 
    } 
    switch (mem[r].hhfield.lhfield) 
    {case 1 : 
      scan_primary ();
      break;
    case 2 : 
      scan_secondary ();
      break;
    case 3 : 
      scan_tertiary ();
      break;
    case 4 : 
      scan_expression ();
      break;
    case 5 : 
      {
	scan_expression ();
	p = get_avail ();
	mem[p].hhfield.lhfield = stash_cur_exp ();
	if (internal[9] > 0) 
	{
	  begin_diagnostic ();
	  printarg (mem[p].hhfield.lhfield , n , 0);
	  end_diagnostic (false);
	} 
	if (arglist == 0) 
	arglist = p;
	else mem[tail].hhfield.v.RH = p;
	tail = p;
	incr (n);
	if (cur_cmd != 69) 
	{
	  missing_err (479);
	  print (716);
	  printmacroname (arglist , macroname);
	  {
	    help_ptr = 1;
	    help_line[0] = 717;
	  } 
	  backerror ();
	} 
	getxnext ();
	scan_primary ();
      } 
      break;
    case 6 : 
      {
	if (cur_cmd != 31) 
	ldelim = 0;
	else {
	    
	  ldelim = cur_sym;
	  rdelim = cur_mod;
	  getxnext ();
	} 
	scan_suffix ();
	if (ldelim != 0) 
	{
	  if ((cur_cmd != 62) || (cur_mod != ldelim)) 
	  {
	    missing_err (hash[rdelim].v.RH);
	    {
	      help_ptr = 2;
	      help_line[1] = 715;
	      help_line[0] = 708;
	    } 
	    backerror ();
	  } 
	  getxnext ();
	} 
      } 
      break;
    case 7 : 
      scantextarg (0 , 0);
      break;
    } 
    backinput ();
    {
      p = get_avail ();
      if (cur_type == 20) 
      mem[p].hhfield.lhfield = cur_exp;
      else mem[p].hhfield.lhfield = stash_cur_exp ();
      if (internal[9] > 0) 
      {
	begin_diagnostic ();
	printarg (mem[p].hhfield.lhfield , n , mem[r].hhfield 
	.lhfield);
	end_diagnostic (false);
      } 
      if (arglist == 0) 
      arglist = p;
      else mem[tail].hhfield.v.RH = p;
      tail = p;
      incr (n);
    } 
  } 
  r = mem[r].hhfield.v.RH;
  while ((cur_input.index_field > 15) && (cur_input.loc_field == 0)) 
  endtokenlist ();
  if (param_ptr + n > max_param_stack) 
  {
    max_param_stack = param_ptr + n;
    if (max_param_stack > 150) 
    overflow (687 , 150);
  } 
  begintokenlist (defref , 21);
  cur_input .name_field = macroname;
  cur_input.loc_field = r;
  if (n > 0) 
  {
    p = arglist;
    do {
	param_stack[param_ptr] = mem[p].hhfield.lhfield;
      incr (param_ptr);
      p = mem[p].hhfield.v.RH;
    } while (!(p == 0));
    flush_list (arglist);
  } 
} 
void 
expand (void) 
{
  halfword p;
  integer k;
  pool_pointer j;
  if (internal[7] > 65536L) {
      
    if (cur_cmd != 10) 
    show_cmd_mod (cur_cmd , cur_mod);
  } 
  switch (cur_cmd) 
  {case 1 : 
    conditional ();
    break;
  case 2 : 
    if (cur_mod > if_limit) {
	
      if (if_limit == 1) 
      {
	missing_err (58);
	backinput ();
	cur_sym = 9762;
	inserror ();
      } 
      else {
	  
	{
	  if (interaction == 3) 
	;
	  if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
	  {
	    print_nl (261);
	    print (fullsourcefilenamestack[in_open]);
	    print (58);
	    print_int (line);
	    print (262);
	    print (724);
	  } 
	  else {
	      
	    print_nl (263);
	    print (724);
	  } 
	} 
	print_cmd_mod (2 , cur_mod);
	{
	  help_ptr = 1;
	  help_line[0] = 725;
	} 
	error ();
      } 
    } 
    else {
	
      while (cur_mod != 2) passtext ();
      {
	p = cond_ptr;
	if_line = mem[p + 1].cint;
	cur_if = mem[p].hhfield.b1;
	if_limit = mem[p].hhfield.b0;
	cond_ptr = mem[p].hhfield.v.RH;
	free_node (p , 2);
      } 
    } 
    break;
  case 3 : 
    if (cur_mod > 0) 
    force_eof = true;
    else start_input ();
    break;
  case 4 : 
    if (cur_mod == 0) 
    {
      {
	if (interaction == 3) 
	;
	if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
	{
	  print_nl (261);
	  print (fullsourcefilenamestack[in_open]);
	  print (58);
	  print_int (line);
	  print (262);
	  print (688);
	} 
	else {
	    
	  print_nl (263);
	  print (688);
	} 
      } 
      {
	help_ptr = 2;
	help_line[1] = 689;
	help_line[0] = 690;
      } 
      error ();
    } 
    else beginiteration ();
    break;
  case 5 : 
    {
      while ((cur_input.index_field > 15) && (cur_input.loc_field == 0)) 
      endtokenlist ();
      if (loop_ptr == 0) 
      {
	{
	  if (interaction == 3) 
	;
	  if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
	  {
	    print_nl (261);
	    print (fullsourcefilenamestack[in_open]);
	    print (58);
	    print_int (line);
	    print (262);
	    print (692);
	  } 
	  else {
	      
	    print_nl (263);
	    print (692);
	  } 
	} 
	{
	  help_ptr = 2;
	  help_line[1] = 693;
	  help_line[0] = 694;
	} 
	error ();
      } 
      else resumeiteration ();
    } 
    break;
  case 6 : 
    {
      get_boolean ();
      if (internal[7] > 65536L) 
      show_cmd_mod (33 , cur_exp);
      if (cur_exp == 30) {
	  
	if (loop_ptr == 0) 
	{
	  {
	    if (interaction == 3) 
	;
	    if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
	    {
	      print_nl (261);
	      print (fullsourcefilenamestack[in_open]);
	      print (58);
	      print_int (line);
	      print (262);
	      print (695);
	    } 
	    else {
		
	      print_nl (263);
	      print (695);
	    } 
	  } 
	  {
	    help_ptr = 1;
	    help_line[0] = 696;
	  } 
	  if (cur_cmd == 83) 
	  error ();
	  else backerror ();
	} 
	else {
	    
	  p = 0;
	  do {
	      if ((cur_input.index_field <= 15)) 
	    endfilereading ();
	    else {
		
	      if (cur_input.index_field <= 17) 
	      p = cur_input .start_field;
	      endtokenlist ();
	    } 
	  } while (!(p != 0));
	  if (p != mem[loop_ptr].hhfield.lhfield) 
	  fatal_error (699);
	  stop_iteration ();
	} 
      } 
      else if (cur_cmd != 83) 
      {
	missing_err (59);
	{
	  help_ptr = 2;
	  help_line[1] = 697;
	  help_line[0] = 698;
	} 
	backerror ();
      } 
    } 
    break;
  case 7 : 
;
    break;
  case 9 : 
    {
      getnext ();
      p = cur_tok ();
      getnext ();
      if (cur_cmd < 11) 
      expand ();
      else backinput ();
      begintokenlist (p , 19);
    } 
    break;
  case 8 : 
    {
      getxnext ();
      scan_primary ();
      if (cur_type != 4) 
      {
	disp_err (0 , 700);
	{
	  help_ptr = 2;
	  help_line[1] = 701;
	  help_line[0] = 702;
	} 
	put_get_flush_error (0);
      } 
      else {
	  
	backinput ();
	if ((str_start[cur_exp + 1] - str_start[cur_exp]) > 0) 
	{
	  beginfilereading ();
	  cur_input .name_field = 2;
	  k = first + (str_start[cur_exp + 1] - str_start[cur_exp]);
	  if (k >= max_buf_stack) 
	  {
	    if (k >= bufsize) 
	    {
	      max_buf_stack = bufsize;
	      overflow (256 , bufsize);
	    } 
	    max_buf_stack = k + 1;
	  } 
	  j = str_start[cur_exp];
	  cur_input .limit_field = k;
	  while (first < cur_input .limit_field) {
	      
	    buffer[first] = str_pool[j];
	    incr (j);
	    incr (first);
	  } 
	  buffer[cur_input .limit_field] = 37;
	  first = cur_input .limit_field + 1;
	  cur_input.loc_field = cur_input .start_field;
	  flush_cur_exp (0);
	} 
      } 
    } 
    break;
  case 10 : 
    macrocall (cur_mod , 0 , cur_sym);
    break;
  } 
} 
void 
getxnext (void) 
{
  halfword saveexp;
  getnext ();
  if (cur_cmd < 11) 
  {
    saveexp = stash_cur_exp ();
    do {
	if (cur_cmd == 10) 
      macrocall (cur_mod , 0 , cur_sym);
      else expand ();
      getnext ();
    } while (!(cur_cmd >= 11));
    unstash_cur_exp (saveexp);
  } 
} 
void 
zstackargument (halfword p) 
{
  if (param_ptr == max_param_stack) 
  {
    incr (max_param_stack);
    if (max_param_stack > 150) 
    overflow (687 , 150);
  } 
  param_stack[param_ptr] = p;
  incr (param_ptr);
} 
void 
passtext (void) 
{
  /* 30 */ integer l;
  scanner_status = 1;
  l = 0;
  warning_info = line;
  while (true) {
      
    getnext ();
    if (cur_cmd <= 2) {
	
      if (cur_cmd < 2) 
      incr (l);
      else {
	  
	if (l == 0) 
	goto done;
	if (cur_mod == 2) 
	decr (l);
      } 
    } 
    else if (cur_cmd == 39) 
    {
      if (str_ref[cur_mod]< 127) {
	  
	if (str_ref[cur_mod] > 1) 
	decr (str_ref[cur_mod]);
	else flush_string (cur_mod);
      } 
    } 
  } 
  done: scanner_status = 0;
} 
void 
zchangeif_limit (small_number l , halfword p) 
{
  /* 10 */ halfword q;
  if (p == cond_ptr) 
  if_limit = l;
  else {
      
    q = cond_ptr;
    while (true) {
	
      if (q == 0) 
      confusion (718);
      if (mem[q].hhfield.v.RH == p) 
      {
	mem[q].hhfield.b0 = l;
	goto lab10;
      } 
      q = mem[q].hhfield.v.RH;
    } 
  } 
  lab10:;
} 
void 
checkcolon (void) 
{
  if (cur_cmd != 81) 
  {
    missing_err (58);
    {
      help_ptr = 2;
      help_line[1] = 721;
      help_line[0] = 698;
    } 
    backerror ();
  } 
} 
void 
conditional (void) 
{
  /* 10 30 21 40 */ halfword savecond_ptr;
  unsigned char newif_limit;
  halfword p;
  {
    p = get_node (2);
    mem[p].hhfield.v.RH = cond_ptr;
    mem[p].hhfield.b0 = if_limit;
    mem[p].hhfield.b1 = cur_if;
    mem[p + 1].cint = if_line;
    cond_ptr = p;
    if_limit = 1;
    if_line = line;
    cur_if = 1;
  } 
  savecond_ptr = cond_ptr;
  lab21: get_boolean ();
  newif_limit = 4;
  if (internal[7] > 65536L) 
  {
    begin_diagnostic ();
    if (cur_exp == 30) 
    print (722);
    else print (723);
    end_diagnostic (false);
  } 
  found: checkcolon ();
  if (cur_exp == 30) 
  {
    changeif_limit (newif_limit , savecond_ptr);
    goto lab10;
  } 
  while (true) {
      
    passtext ();
    if (cond_ptr == savecond_ptr) 
    goto done;
    else if (cur_mod == 2) 
    {
      p = cond_ptr;
      if_line = mem[p + 1].cint;
      cur_if = mem[p].hhfield.b1;
      if_limit = mem[p].hhfield.b0;
      cond_ptr = mem[p].hhfield.v.RH;
      free_node (p , 2);
    } 
  } 
  done: cur_if = cur_mod;
  if_line = line;
  if (cur_mod == 2) 
  {
    p = cond_ptr;
    if_line = mem[p + 1].cint;
    cur_if = mem[p].hhfield.b1;
    if_limit = mem[p].hhfield.b0;
    cond_ptr = mem[p].hhfield.v.RH;
    free_node (p , 2);
  } 
  else if (cur_mod == 4) 
  goto lab21;
  else {
      
    cur_exp = 30;
    newif_limit = 2;
    getxnext ();
    goto found;
  } 
  lab10:;
} 
void 
bad_for (str_number s) 
{
  disp_err (0 , 726);
  print (s);
  print (306);
  {
    help_ptr = 4;
    help_line[3] = 727;
    help_line[2] = 728;
    help_line[1] = 729;
    help_line[0] = 308;
  } 
  put_get_flush_error (0);
} 
void 
beginiteration (void) 
{
  /* 22 30 40 */ halfword m;
  halfword n;
  halfword p, q, s, pp;
  m = cur_mod;
  n = cur_sym;
  s = get_node (2);
  if (m == 1) 
  {
    mem[s + 1].hhfield.lhfield = 1;
    p = 0;
    getxnext ();
    goto found;
  } 
  getsymbol ();
  p = get_node (2);
  mem[p].hhfield.lhfield = cur_sym;
  mem[p + 1].cint = m;
  getxnext ();
  if ((cur_cmd != 51) && (cur_cmd != 77)) 
  {
    missing_err (61);
    {
      help_ptr = 3;
      help_line[2] = 730;
      help_line[1] = 673;
      help_line[0] = 731;
    } 
    backerror ();
  } 
  mem[s + 1].hhfield.lhfield = 0;
  q = s + 1;
  mem[q].hhfield.v.RH = 0;
  do {
      getxnext ();
    if (m != 9770) 
    scan_suffix ();
    else {
	
      if (cur_cmd >= 81) {
	  
	if (cur_cmd <= 82) 
	goto lab22;
      } 
      scan_expression ();
      if (cur_cmd == 74) {
	  
	if (q == s + 1) 
	{
	  if (cur_type != 16) 
	  bad_for (737);
	  pp = get_node (4);
	  mem[pp + 1].cint = cur_exp;
	  getxnext ();
	  scan_expression ();
	  if (cur_type != 16) 
	  bad_for (738);
	  mem[pp + 2].cint = cur_exp;
	  if (cur_cmd != 75) 
	  {
	    missing_err (490);
	    {
	      help_ptr = 2;
	      help_line[1] = 739;
	      help_line[0] = 740;
	    } 
	    backerror ();
	  } 
	  getxnext ();
	  scan_expression ();
	  if (cur_type != 16) 
	  bad_for (741);
	  mem[pp + 3].cint = cur_exp;
	  mem[s + 1].hhfield.lhfield = pp;
	  goto done;
	} 
      } 
      cur_exp = stash_cur_exp ();
    } 
    mem[q].hhfield.v.RH = get_avail ();
    q = mem[q].hhfield.v.RH;
    mem[q].hhfield.lhfield = cur_exp;
    cur_type = 1;
    lab22:;
  } while (!(cur_cmd != 82));
  done:;
  found: if (cur_cmd != 81) 
  {
    missing_err (58);
    {
      help_ptr = 3;
      help_line[2] = 732;
      help_line[1] = 733;
      help_line[0] = 734;
    } 
    backerror ();
  } 
  q = get_avail ();
  mem[q].hhfield.lhfield = 9758;
  scanner_status = 6;
  warning_info = n;
  mem[s].hhfield.lhfield = scantoks (4 , p , q , 0);
  scanner_status = 0;
  mem[s].hhfield.v.RH = loop_ptr;
  loop_ptr = s;
  resumeiteration ();
} 
void 
resumeiteration (void) 
{
  /* 45 10 */ halfword p, q;
  p = mem[loop_ptr + 1].hhfield.lhfield;
  if (p > 1) 
  {
    cur_exp = mem[p + 1].cint;
    if (((mem[p + 2].cint > 0) && (cur_exp > mem[p + 3].cint)) 
    || ((mem[p + 2].cint < 0) && (cur_exp < mem[p + 3].cint))) 
    goto not_found;
    cur_type = 16;
    q = stash_cur_exp ();
    mem[p + 1].cint = cur_exp + mem[p + 2].cint;
  } 
  else if (p < 1) 
  {
    p = mem[loop_ptr + 1].hhfield.v.RH;
    if (p == 0) 
    goto not_found;
    mem[loop_ptr + 1].hhfield.v.RH = mem[p].hhfield.v.RH;
    q = mem[p].hhfield.lhfield;
    {
      mem[p].hhfield.v.RH = avail;
      avail = p;
	;
#ifdef STAT
      decr (dyn_used);
#endif /* STAT */
    } 
  } 
  else {
      
    begintokenlist (mem[loop_ptr].hhfield.lhfield , 16);
    goto lab10;
  } 
  begintokenlist (mem[loop_ptr].hhfield.lhfield , 17);
  stackargument (q);
  if (internal[7] > 65536L) 
  {
    begin_diagnostic ();
    print_nl (736);
    if ((q != 0) && (mem[q].hhfield.v.RH == 1)) 
    print_exp (q , 1);
    else show_token_list (q , 0 , 50 , 0);
    print_char (125);
    end_diagnostic (false);
  } 
  goto lab10;
  not_found: stop_iteration ();
  lab10:;
} 
void 
stop_iteration (void) 
{
  halfword p, q;
  p = mem[loop_ptr + 1].hhfield.lhfield;
  if (p > 1) 
  free_node (p , 4);
  else if (p < 1) 
  {
    q = mem[loop_ptr + 1].hhfield.v.RH;
    while (q != 0) {
	
      p = mem[q].hhfield.lhfield;
      if (p != 0) {
	  
	if (mem[p].hhfield.v.RH == 1) 
	{
	  recycle_value (p);
	  free_node (p , 2);
	} 
	else flush_token_list (p);
      } 
      p = q;
      q = mem[q].hhfield.v.RH;
      {
	mem[p].hhfield.v.RH = avail;
	avail = p;
	;
#ifdef STAT
	decr (dyn_used);
#endif /* STAT */
      } 
    } 
  } 
  p = loop_ptr;
  loop_ptr = mem[p].hhfield.v.RH;
  flush_token_list (mem[p].hhfield.lhfield);
  free_node (p , 2);
} 
void 
begin_name (void) 
{
  area_delimiter = 0;
  ext_delimiter = 0;
  quotedfilename = false;
} 
boolean 
more_name (ASCII_code c) 
{
  register boolean Result; if (c == 34) 
  {
    quotedfilename = !quotedfilename;
    Result = true;
  } 
  else if (((c == 32) || (c == 9)) && stopatspace && (!quotedfilename 
)) 
  Result = false;
  else {
      
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
	overflow (257 , pool_size - init_pool_ptr);
	max_pool_ptr = pool_ptr + 1;
      } 
    } 
    {
      str_pool[pool_ptr] = c;
      incr (pool_ptr);
    } 
    Result = true;
  } 
  return Result;
} 
void 
end_name (void) 
{
  boolean mustquote;
  pool_pointer j, s, t;
  if (str_ptr + 3 > max_str_ptr) 
  {
    if (str_ptr + 3 > max_strings) 
    overflow (258 , max_strings - init_str_ptr);
    max_str_ptr = str_ptr + 3;
  } 
  {
    if (pool_ptr + 6 > max_pool_ptr) 
    {
      if (pool_ptr + 6 > pool_size) 
      overflow (257 , pool_size - init_pool_ptr);
      max_pool_ptr = pool_ptr + 6;
    } 
  } 
  if (area_delimiter == 0) 
  cur_area = 261;
  else {
      
    mustquote = false;
    s = str_start[str_ptr];
    t = area_delimiter + 1;
    j = s;
    while ((!mustquote) && (j < t)) {
	
      mustquote = str_pool[j] == 32;
      incr (j);
    } 
    if (mustquote) 
    {
      {register integer for_end; j = pool_ptr - 1;for_end = t; if (j >= 
      for_end) do 
	str_pool[j + 2] = str_pool[j];
      while (j-- > for_end);} 
      str_pool[t + 1] = 34;
      {register integer for_end; j = t - 1;for_end = s; if (j >= for_end) 
      do 
	str_pool[j + 1] = str_pool[j];
      while (j-- > for_end);} 
      str_pool[s] = 34;
      pool_ptr = pool_ptr + 2;
      area_delimiter = area_delimiter + 2;
      if (ext_delimiter != 0) 
      ext_delimiter = ext_delimiter + 2;
    } 
    cur_area = str_ptr;
    incr (str_ptr);
    str_start[str_ptr] = area_delimiter + 1;
  } 
  if (ext_delimiter == 0) 
  cur_ext = 261;
  else {
      
    mustquote = false;
    s = str_start[str_ptr];
    t = ext_delimiter;
    j = s;
    while ((!mustquote) && (j < t)) {
	
      mustquote = str_pool[j] == 32;
      incr (j);
    } 
    if (mustquote) 
    {
      {register integer for_end; j = pool_ptr - 1;for_end = t; if (j >= 
      for_end) do 
	str_pool[j + 2] = str_pool[j];
      while (j-- > for_end);} 
      str_pool[t + 1] = 34;
      {register integer for_end; j = t - 1;for_end = s; if (j >= for_end) 
      do 
	str_pool[j + 1] = str_pool[j];
      while (j-- > for_end);} 
      str_pool[s] = 34;
      pool_ptr = pool_ptr + 2;
      ext_delimiter = ext_delimiter + 2;
    } 
    cur_name = str_ptr;
    incr (str_ptr);
    str_start[str_ptr] = ext_delimiter;
  } 
  mustquote = false;
  s = str_start[str_ptr];
  t = pool_ptr;
  j = s;
  while ((!mustquote) && (j < t)) {
      
    mustquote = str_pool[j] == 32;
    incr (j);
  } 
  if (mustquote) 
  {
    str_pool[t + 1] = 34;
    {register integer for_end; j = t - 1;for_end = s; if (j >= for_end) 
    do 
      str_pool[j + 1] = str_pool[j];
    while (j-- > for_end);} 
    str_pool[s] = 34;
    pool_ptr = pool_ptr + 2;
  } 
  if (ext_delimiter == 0) 
  cur_name = make_string ();
  else cur_ext = make_string ();
} 
void 
zpackfilename (str_number n , str_number a , str_number e) 
{
  integer k;
  ASCII_code c;
  pool_pointer j;
  k = 0;
  if (name_of_file) 
  libcfree (name_of_file);
  name_of_file = xmallocarray (ASCII_code , (str_start[a + 1] - str_start[a 
]) + (str_start[n + 1] - str_start[n]) + (str_start[e + 1] - 
  str_start[e]) + 1);
  {register integer for_end; j = str_start[a];for_end = str_start[a + 1 
] - 1; if (j <= for_end) do 
    {
      c = str_pool[j];
      if (!(c == 34)) 
      {
	incr (k);
	if (k <= maxint) 
	name_of_file[k] = xchr[c];
      } 
    } 
  while (j++ < for_end);} 
  {register integer for_end; j = str_start[n];for_end = str_start[n + 1 
] - 1; if (j <= for_end) do 
    {
      c = str_pool[j];
      if (!(c == 34)) 
      {
	incr (k);
	if (k <= maxint) 
	name_of_file[k] = xchr[c];
      } 
    } 
  while (j++ < for_end);} 
  {register integer for_end; j = str_start[e];for_end = str_start[e + 1 
] - 1; if (j <= for_end) do 
    {
      c = str_pool[j];
      if (!(c == 34)) 
      {
	incr (k);
	if (k <= maxint) 
	name_of_file[k] = xchr[c];
      } 
    } 
  while (j++ < for_end);} 
  if (k <= maxint) 
  name_length = k;
  else name_length = maxint;
  name_of_file[name_length + 1] = 0;
} 
void 
zpackbufferedname (small_number n , integer a , integer b) 
{
  integer k;
  ASCII_code c;
  integer j;
  if (n + b - a + 6 > maxint) 
  b = a + maxint - n - 6;
  k = 0;
  if (name_of_file) 
  libcfree (name_of_file);
  name_of_file = xmallocarray (ASCII_code , n + (b - a + 1) + 6);
  {register integer for_end; j = 1;for_end = n; if (j <= for_end) do 
    {
      c = xord[ucharcast (MF_base_default[j])];
      if (!(c == 34)) 
      {
	incr (k);
	if (k <= maxint) 
	name_of_file[k] = xchr[c];
      } 
    } 
  while (j++ < for_end);} 
  {register integer for_end; j = a;for_end = b; if (j <= for_end) do 
    {
      c = buffer[j];
      if (!(c == 34)) 
      {
	incr (k);
	if (k <= maxint) 
	name_of_file[k] = xchr[c];
      } 
    } 
  while (j++ < for_end);} 
  {register integer for_end; j = basedefaultlength - 4;for_end = 
  basedefaultlength; if (j <= for_end) do 
    {
      c = xord[ucharcast (MF_base_default[j])];
      if (!(c == 34)) 
      {
	incr (k);
	if (k <= maxint) 
	name_of_file[k] = xchr[c];
      } 
    } 
  while (j++ < for_end);} 
  if (k <= maxint) 
  name_length = k;
  else name_length = maxint;
  name_of_file[name_length + 1] = 0;
} 
str_number 
makenamestring (void) 
{
  register str_number Result; integer k;
  if ((pool_ptr + name_length > pool_size) || (str_ptr == max_strings)) 
  Result = 63;
  else {
      
    {register integer for_end; k = 1;for_end = name_length; if (k <= 
    for_end) do 
      {
	str_pool[pool_ptr] = xord[name_of_file[k]];
	incr (pool_ptr);
      } 
    while (k++ < for_end);} 
    Result = make_string ();
  } 
  k = 1;
  begin_name ();
  stopatspace = false;
  while ((k <= name_length) && (more_name (name_of_file[k]))) incr (k 
);
  stopatspace = true;
  end_name ();
  return Result;
} 
str_number 
zamakenamestring (alpha_file f) 
{
  register str_number Result; Result = makenamestring ();
  return Result;
} 
str_number 
zbmakenamestring (byte_file f) 
{
  register str_number Result; Result = makenamestring ();
  return Result;
} 
str_number 
zwmakenamestring (word_file f) 
{
  register str_number Result; Result = makenamestring ();
  return Result;
} 
void 
scan_file_name (void) 
{
  /* 30 */ begin_name ();
  while ((buffer[cur_input.loc_field] == 32) || (buffer[cur_input 
 .loc_field] == 9)) incr (cur_input.loc_field);
  while (true) {
      
    if ((buffer[cur_input.loc_field] == 59) || (buffer[cur_input 
   .loc_field] == 37)) 
    goto done;
    if (!more_name (buffer[cur_input.loc_field])) 
    goto done;
    incr (cur_input.loc_field);
  } 
  done: end_name ();
} 
void 
zpackjob_name (str_number s) 
{
  cur_area = 261;
  cur_ext = s;
  cur_name = job_name;
  packfilename (cur_name , cur_area , cur_ext);
} 
void 
zpromptfilename (str_number s , str_number e) 
{
  /* 30 */ integer k;
  str_number savedcur_name;
  if (interaction == 2) 
;
  if (s == 743) 
  {
    if (interaction == 3) 
;
    if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
    {
      print_nl (261);
      print (fullsourcefilenamestack[in_open]);
      print (58);
      print_int (line);
      print (262);
      print (744);
    } 
    else {
	
      print_nl (263);
      print (744);
    } 
  } 
  else {
      
    if (interaction == 3) 
;
    if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
    {
      print_nl (261);
      print (fullsourcefilenamestack[in_open]);
      print (58);
      print_int (line);
      print (262);
      print (745);
    } 
    else {
	
      print_nl (263);
      print (745);
    } 
  } 
  print_file_name (cur_name , cur_area , cur_ext);
  print (746);
  if (e == 747) 
  showcontext ();
  print_nl (748);
  print (s);
  if (interaction < 2) 
  fatal_error (749);
  savedcur_name = cur_name;
  {
;
    print (262);
    term_input ();
  } 
  {
    begin_name ();
    k = first;
    while (((buffer[k] == 32) || (buffer[k] == 9)) && (k < last 
 )) incr (k);
    while (true) {
	
      if (k == last) 
      goto done;
      if (!more_name (buffer[k])) 
      goto done;
      incr (k);
    } 
    done: end_name ();
  } 
  if (cur_ext == 261) 
  cur_ext = e;
  if ((str_start[cur_name + 1] - str_start[cur_name]) == 0) 
  cur_name = savedcur_name;
  packfilename (cur_name , cur_area , cur_ext);
} 
void 
open_log_file (void) 
{
  unsigned char old_setting;
  integer k;
  integer l;
  integer m;
  constcstring months;
  old_setting = selector;
  if (job_name == 0) 
  job_name = getjob_name (750);
  packjob_name (751);
  recorderchangefilename (stringcast (name_of_file + 1));
  packjob_name (752);
  while (!aopenout (log_file)) {
      
    selector = 1;
    promptfilename (754 , 752);
  } 
  texmflogname = amakenamestring (log_file);
  selector = 2;
  log_opened = true;
  {
    Fputs (log_file ,  "This is METAFONT, Version 2.7182818");
    Fputs (log_file ,  versionstring);
    slow_print (base_ident);
    print (755);
    print_int (roundunscaled (internal[16]));
    print_char (32);
    months = " JANFEBMARAPRMAYJUNJULAUGSEPOCTNOVDEC";
    m = roundunscaled (internal[15]);
    {register integer for_end; k = 3 * m - 2;for_end = 3 * m; if (k <= 
    for_end) do 
      putc (months[k],  log_file);
    while (k++ < for_end);} 
    print_char (32);
    print_int (roundunscaled (internal[14]));
    print_char (32);
    m = roundunscaled (internal[17]);
    print_dd (m / 60);
    print_char (58);
    print_dd (m % 60);
    if (translatefilename) 
    {
      putc ('\n',  log_file);
      putc ('(' ,  log_file);
      fputs (translatefilename , log_file);
      putc (')' ,  log_file);
    } 
  } 
  input_stack[input_ptr] = cur_input;
  print_nl (753);
  l = input_stack[0].limit_field - 1;
  {register integer for_end; k = 1;for_end = l; if (k <= for_end) do 
    print (buffer[k]);
  while (k++ < for_end);} 
  print_ln ();
  selector = old_setting + 2;
} 
void 
start_input (void) 
{
  /* 30 */ while ((cur_input.index_field > 15) && (cur_input.loc_field == 
  0)) endtokenlist ();
  if ((cur_input.index_field > 15)) 
  {
    {
      if (interaction == 3) 
;
      if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[in_open]);
	print (58);
	print_int (line);
	print (262);
	print (757);
      } 
      else {
	  
	print_nl (263);
	print (757);
      } 
    } 
    {
      help_ptr = 3;
      help_line[2] = 758;
      help_line[1] = 759;
      help_line[0] = 760;
    } 
    error ();
  } 
  if ((cur_input.index_field <= 15)) 
  scan_file_name ();
  else {
      
    cur_name = 261;
    cur_ext = 261;
    cur_area = 261;
  } 
  packfilename (cur_name , cur_area , cur_ext);
  while (true) {
      
    beginfilereading ();
    if (cur_ext == 747) 
    {
      cur_ext = 261;
      packfilename (cur_name , cur_area , cur_ext);
    } 
    if (kpseinnameok (stringcast (name_of_file + 1)) && aopenin (input_file 
  [cur_input.index_field], kpsemfformat)) 
    goto done;
    endfilereading ();
    promptfilename (743 , 747);
  } 
  done: cur_input .name_field = amakenamestring (input_file[cur_input 
 .index_field]);
  str_ref[cur_name] = 127;
  if (job_name == 0) 
  {
    job_name = getjob_name (cur_name);
    open_log_file ();
  } 
  if (term_offset + (str_start[cur_input .name_field + 1] - str_start[
  cur_input .name_field]) > maxprintline - 2) 
  print_ln ();
  else if ((term_offset > 0) || (file_offset > 0)) 
  print_char (32);
  print_char (40);
  incr (open_parens);
  slow_print (cur_input .name_field);
  fflush (stdout);
  {
    line = 1;
    if (inputln (input_file[cur_input.index_field], false)) 
;
    firmuptheline ();
    buffer[cur_input .limit_field] = 37;
    first = cur_input .limit_field + 1;
    cur_input.loc_field = cur_input .start_field;
  } 
} 
void 
zbadexp (str_number s) 
{
  unsigned char saveflag;
  {
    if (interaction == 3) 
;
    if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
    {
      print_nl (261);
      print (fullsourcefilenamestack[in_open]);
      print (58);
      print_int (line);
      print (262);
      print (s);
    } 
    else {
	
      print_nl (263);
      print (s);
    } 
  } 
  print (770);
  print_cmd_mod (cur_cmd , cur_mod);
  print_char (39);
  {
    help_ptr = 4;
    help_line[3] = 771;
    help_line[2] = 772;
    help_line[1] = 773;
    help_line[0] = 774;
  } 
  backinput ();
  cur_sym = 0;
  cur_cmd = 42;
  cur_mod = 0;
  inserror ();
  saveflag = var_flag;
  var_flag = 0;
  getxnext ();
  var_flag = saveflag;
} 
void 
zstashin (halfword p) 
{
  halfword q;
  mem[p].hhfield.b0 = cur_type;
  if (cur_type == 16) 
  mem[p + 1].cint = cur_exp;
  else {
      
    if (cur_type == 19) 
    {
      q = singledependency (cur_exp);
      if (q == dep_final) 
      {
	mem[p].hhfield.b0 = 16;
	mem[p + 1].cint = 0;
	free_node (q , 2);
      } 
      else {
	  
	mem[p].hhfield.b0 = 17;
	newdep (p , q);
      } 
      recycle_value (cur_exp);
    } 
    else {
	
      mem[p + 1] = mem[cur_exp + 1];
      mem[mem[p + 1].hhfield.lhfield].hhfield.v.RH = p;
    } 
    free_node (cur_exp , 2);
  } 
  cur_type = 1;
} 
void 
backexpr (void) 
{
  halfword p;
  p = stash_cur_exp ();
  mem[p].hhfield.v.RH = 0;
  begintokenlist (p , 19);
} 
void 
badsubscript (void) 
{
  disp_err (0 , 786);
  {
    help_ptr = 3;
    help_line[2] = 787;
    help_line[1] = 788;
    help_line[0] = 789;
  } 
  flush_error (0);
} 
void 
zobliterated (halfword q) 
{
  {
    if (interaction == 3) 
;
    if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
    {
      print_nl (261);
      print (fullsourcefilenamestack[in_open]);
      print (58);
      print_int (line);
      print (262);
      print (790);
    } 
    else {
	
      print_nl (263);
      print (790);
    } 
  } 
  show_token_list (q , 0 , 1000 , 0);
  print (791);
  {
    help_ptr = 5;
    help_line[4] = 792;
    help_line[3] = 793;
    help_line[2] = 794;
    help_line[1] = 795;
    help_line[0] = 796;
  } 
} 
void 
zbinarymac (halfword p , halfword c , halfword n) 
{
  halfword q, r;
  q = get_avail ();
  r = get_avail ();
  mem[q].hhfield.v.RH = r;
  mem[q].hhfield.lhfield = p;
  mem[r].hhfield.lhfield = stash_cur_exp ();
  macrocall (c , q , n);
} 
void 
materializepen (void) 
{
  /* 50 */ scaled aminusb, aplusb, majoraxis, minoraxis;
  angle theta;
  halfword p;
  halfword q;
  q = cur_exp;
  if (mem[q].hhfield.b0 == 0) 
  {
    {
      if (interaction == 3) 
;
      if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[in_open]);
	print (58);
	print_int (line);
	print (262);
	print (806);
      } 
      else {
	  
	print_nl (263);
	print (806);
      } 
    } 
    {
      help_ptr = 2;
      help_line[1] = 807;
      help_line[0] = 575;
    } 
    put_get_error ();
    cur_exp = 3;
    goto common_ending;
  } 
  else if (mem[q].hhfield.b0 == 4) 
  {
    tx = mem[q + 1].cint;
    ty = mem[q + 2].cint;
    txx = mem[q + 3].cint - tx;
    tyx = mem[q + 4].cint - ty;
    txy = mem[q + 5].cint - tx;
    tyy = mem[q + 6].cint - ty;
    aminusb = pyth_add (txx - tyy , tyx + txy);
    aplusb = pyth_add (txx + tyy , tyx - txy);
    majoraxis = halfp (aminusb + aplusb);
    minoraxis = halfp (abs (aplusb - aminusb));
    if (majoraxis == minoraxis) 
    theta = 0;
    else theta = half (n_arg (txx - tyy , tyx + txy) + n_arg (txx + tyy , 
    tyx - txy));
    free_node (q , 7);
    q = makeellipse (majoraxis , minoraxis , theta);
    if ((tx != 0) || (ty != 0)) 
    {
      p = q;
      do {
	  mem[p + 1].cint = mem[p + 1].cint + tx;
	mem[p + 2].cint = mem[p + 2].cint + ty;
	p = mem[p].hhfield.v.RH;
      } while (!(p == q));
    } 
  } 
  cur_exp = makepen (q);
  common_ending: toss_knot_list (q);
  cur_type = 6;
} 
void 
knownpair (void) 
{
  halfword p;
  if (cur_type != 14) 
  {
    disp_err (0 , 809);
    {
      help_ptr = 5;
      help_line[4] = 810;
      help_line[3] = 811;
      help_line[2] = 812;
      help_line[1] = 813;
      help_line[0] = 814;
    } 
    put_get_flush_error (0);
    cur_x = 0;
    cur_y = 0;
  } 
  else {
      
    p = mem[cur_exp + 1].cint;
    if (mem[p].hhfield.b0 == 16) 
    cur_x = mem[p + 1].cint;
    else {
	
      disp_err (p , 815);
      {
	help_ptr = 5;
	help_line[4] = 816;
	help_line[3] = 811;
	help_line[2] = 812;
	help_line[1] = 813;
	help_line[0] = 814;
      } 
      put_get_error ();
      recycle_value (p);
      cur_x = 0;
    } 
    if (mem[p + 2].hhfield.b0 == 16) 
    cur_y = mem[p + 3].cint;
    else {
	
      disp_err (p + 2 , 817);
      {
	help_ptr = 5;
	help_line[4] = 818;
	help_line[3] = 811;
	help_line[2] = 812;
	help_line[1] = 813;
	help_line[0] = 814;
      } 
      put_get_error ();
      recycle_value (p + 2);
      cur_y = 0;
    } 
    flush_cur_exp (0);
  } 
} 
halfword 
newknot (void) 
{
  register halfword Result; halfword q;
  q = get_node (7);
  mem[q].hhfield.b0 = 0;
  mem[q].hhfield.b1 = 0;
  mem[q].hhfield.v.RH = q;
  knownpair ();
  mem[q + 1].cint = cur_x;
  mem[q + 2].cint = cur_y;
  Result = q;
  return Result;
} 
small_number 
scandirection (void) 
{
  register small_number Result; unsigned char t;
  scaled x;
  getxnext ();
  if (cur_cmd == 60) 
  {
    getxnext ();
    scan_expression ();
    if ((cur_type != 16) || (cur_exp < 0)) 
    {
      disp_err (0 , 821);
      {
	help_ptr = 1;
	help_line[0] = 822;
      } 
      put_get_flush_error (65536L);
    } 
    t = 3;
  } 
  else {
      
    scan_expression ();
    if (cur_type > 14) 
    {
      if (cur_type != 16) 
      {
	disp_err (0 , 815);
	{
	  help_ptr = 5;
	  help_line[4] = 816;
	  help_line[3] = 811;
	  help_line[2] = 812;
	  help_line[1] = 813;
	  help_line[0] = 814;
	} 
	put_get_flush_error (0);
      } 
      x = cur_exp;
      if (cur_cmd != 82) 
      {
	missing_err (44);
	{
	  help_ptr = 2;
	  help_line[1] = 823;
	  help_line[0] = 824;
	} 
	backerror ();
      } 
      getxnext ();
      scan_expression ();
      if (cur_type != 16) 
      {
	disp_err (0 , 817);
	{
	  help_ptr = 5;
	  help_line[4] = 818;
	  help_line[3] = 811;
	  help_line[2] = 812;
	  help_line[1] = 813;
	  help_line[0] = 814;
	} 
	put_get_flush_error (0);
      } 
      cur_y = cur_exp;
      cur_x = x;
    } 
    else knownpair ();
    if ((cur_x == 0) && (cur_y == 0)) 
    t = 4;
    else {
	
      t = 2;
      cur_exp = n_arg (cur_x , cur_y);
    } 
  } 
  if (cur_cmd != 65) 
  {
    missing_err (125);
    {
      help_ptr = 3;
      help_line[2] = 819;
      help_line[1] = 820;
      help_line[0] = 698;
    } 
    backerror ();
  } 
  getxnext ();
  Result = t;
  return Result;
} 
void 
zdonullary (quarterword c) 
{
  integer k;
  {
    if (arith_error) 
    clear_arith ();
  } 
  if (internal[7] > 131072L) 
  show_cmd_mod (33 , c);
  switch (c) 
  {case 30 : 
  case 31 : 
    {
      cur_type = 2;
      cur_exp = c;
    } 
    break;
  case 32 : 
    {
      cur_type = 11;
      cur_exp = get_node (6);
      init_edges (cur_exp);
    } 
    break;
  case 33 : 
    {
      cur_type = 6;
      cur_exp = 3;
    } 
    break;
  case 37 : 
    {
      cur_type = 16;
      cur_exp = norm_rand ();
    } 
    break;
  case 36 : 
    {
      cur_type = 8;
      cur_exp = get_node (7);
      mem[cur_exp].hhfield.b0 = 4;
      mem[cur_exp].hhfield.b1 = 4;
      mem[cur_exp].hhfield.v.RH = cur_exp;
      mem[cur_exp + 1].cint = 0;
      mem[cur_exp + 2].cint = 0;
      mem[cur_exp + 3].cint = 65536L;
      mem[cur_exp + 4].cint = 0;
      mem[cur_exp + 5].cint = 0;
      mem[cur_exp + 6].cint = 65536L;
    } 
    break;
  case 34 : 
    {
      if (job_name == 0) 
      open_log_file ();
      cur_type = 4;
      cur_exp = job_name;
    } 
    break;
  case 35 : 
    {
      if (interaction <= 1) 
      fatal_error (835);
      beginfilereading ();
      cur_input .name_field = 1;
      {
	;
	print (261);
	term_input ();
      } 
      {
	if (pool_ptr + last - cur_input .start_field > max_pool_ptr) 
	{
	  if (pool_ptr + last - cur_input .start_field > pool_size) 
	  overflow (257 , pool_size - init_pool_ptr);
	  max_pool_ptr = pool_ptr + last - cur_input .start_field;
	} 
      } 
      {register integer for_end; k = cur_input .start_field;for_end = last - 
      1; if (k <= for_end) do 
	{
	  str_pool[pool_ptr] = buffer[k];
	  incr (pool_ptr);
	} 
      while (k++ < for_end);} 
      endfilereading ();
      cur_type = 4;
      cur_exp = make_string ();
    } 
    break;
  } 
  {
    if (arith_error) 
    clear_arith ();
  } 
} 
boolean 
znicepair (integer p , quarterword t) 
{
  /* 10 */ register boolean Result; if (t == 14) 
  {
    p = mem[p + 1].cint;
    if (mem[p].hhfield.b0 == 16) {
	
      if (mem[p + 2].hhfield.b0 == 16) 
      {
	Result = true;
	goto lab10;
      } 
    } 
  } 
  Result = false;
  lab10:;
  return Result;
} 
void 
zprintknownorunknowntype (small_number t , integer v) 
{
  print_char (40);
  if (t < 17) {
      
    if (t != 14) 
    print_type (t);
    else if (nicepair (v , 14)) 
    print (336);
    else print (836);
  } 
  else print (837);
  print_char (41);
} 
void 
zbadunary (quarterword c) 
{
  disp_err (0 , 838);
  print_op (c);
  printknownorunknowntype (cur_type , cur_exp);
  {
    help_ptr = 3;
    help_line[2] = 839;
    help_line[1] = 840;
    help_line[0] = 841;
  } 
  put_get_error ();
} 
void 
znegatedeplist (halfword p) 
{
  /* 10 */ while (true) {
      
    mem[p + 1].cint = - (integer) mem[p + 1].cint;
    if (mem[p].hhfield.lhfield == 0) 
    goto lab10;
    p = mem[p].hhfield.v.RH;
  } 
  lab10:;
} 
void 
pairtopath (void) 
{
  cur_exp = newknot ();
  cur_type = 9;
} 
void 
ztakepart (quarterword c) 
{
  halfword p;
  p = mem[cur_exp + 1].cint;
  mem[18].cint = p;
  mem[17].hhfield.b0 = cur_type;
  mem[p].hhfield.v.RH = 17;
  free_node (cur_exp , 2);
  makeexpcopy (p + 2 * (c - 53));
  recycle_value (17);
} 
void 
zstrtonum (quarterword c) 
{
  integer n;
  ASCII_code m;
  pool_pointer k;
  unsigned char b;
  boolean badchar;
  if (c == 49) {
      
    if ((str_start[cur_exp + 1] - str_start[cur_exp]) == 0) 
    n = -1;
    else n = str_pool[str_start[cur_exp]];
  } 
  else {
      
    if (c == 47) 
    b = 8;
    else b = 16;
    n = 0;
    badchar = false;
    {register integer for_end; k = str_start[cur_exp];for_end = str_start[
    cur_exp + 1] - 1; if (k <= for_end) do 
      {
	m = str_pool[k];
	if ((m >= 48) && (m <= 57)) 
	m = m - 48;
	else if ((m >= 65) && (m <= 70)) 
	m = m - 55;
	else if ((m >= 97) && (m <= 102)) 
	m = m - 87;
	else {
	    
	  badchar = true;
	  m = 0;
	} 
	if (m >= b) 
	{
	  badchar = true;
	  m = 0;
	} 
	if (n < 32768L / b) 
	n = n * b + m;
	else n = 32767;
      } 
    while (k++ < for_end);} 
    if (badchar) 
    {
      disp_err (0 , 843);
      if (c == 47) 
      {
	help_ptr = 1;
	help_line[0] = 844;
      } 
      else {
	  
	help_ptr = 1;
	help_line[0] = 845;
      } 
      put_get_error ();
    } 
    if (n > 4095) 
    {
      {
	if (interaction == 3) 
	;
	if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
	{
	  print_nl (261);
	  print (fullsourcefilenamestack[in_open]);
	  print (58);
	  print_int (line);
	  print (262);
	  print (846);
	} 
	else {
	    
	  print_nl (263);
	  print (846);
	} 
      } 
      print_int (n);
      print_char (41);
      {
	help_ptr = 1;
	help_line[0] = 847;
      } 
      put_get_error ();
    } 
  } 
  flush_cur_exp (n * 65536L);
} 
scaled 
pathlength (void) 
{
  register scaled Result; scaled n;
  halfword p;
  p = cur_exp;
  if (mem[p].hhfield.b0 == 0) 
  n = -65536L;
  else n = 0;
  do {
      p = mem[p].hhfield.v.RH;
    n = n + 65536L;
  } while (!(p == cur_exp));
  Result = n;
  return Result;
} 
void 
ztestknown (quarterword c) 
{
  /* 30 */ unsigned char b;
  halfword p, q;
  b = 31;
  switch (cur_type) 
  {case 1 : 
  case 2 : 
  case 4 : 
  case 6 : 
  case 8 : 
  case 9 : 
  case 11 : 
  case 16 : 
    b = 30;
    break;
  case 13 : 
  case 14 : 
    {
      p = mem[cur_exp + 1].cint;
      q = p + big_node_size[cur_type];
      do {
	  q = q - 2;
	if (mem[q].hhfield.b0 != 16) 
	goto done;
      } while (!(q == p));
      b = 30;
      done:;
    } 
    break;
    default: 
;
    break;
  } 
  if (c == 39) 
  flush_cur_exp (b);
  else flush_cur_exp (61 - b);
  cur_type = 2;
} 
void 
zdounary (quarterword c) 
{
  halfword p, q;
  integer x;
  {
    if (arith_error) 
    clear_arith ();
  } 
  if (internal[7] > 131072L) 
  {
    begin_diagnostic ();
    print_nl (123);
    print_op (c);
    print_char (40);
    print_exp (0 , 0);
    print (842);
    end_diagnostic (false);
  } 
  switch (c) 
  {case 69 : 
    if (cur_type < 14) {
	
      if (cur_type != 11) 
      badunary (69);
    } 
    break;
  case 70 : 
    switch (cur_type) 
    {case 14 : 
    case 19 : 
      {
	q = cur_exp;
	makeexpcopy (q);
	if (cur_type == 17) 
	negatedeplist (mem[cur_exp + 1].hhfield.v.RH);
	else if (cur_type == 14) 
	{
	  p = mem[cur_exp + 1].cint;
	  if (mem[p].hhfield.b0 == 16) 
	  mem[p + 1].cint = - (integer) mem[p + 1].cint;
	  else negatedeplist (mem[p + 1].hhfield.v.RH);
	  if (mem[p + 2].hhfield.b0 == 16) 
	  mem[p + 3].cint = - (integer) mem[p + 3].cint;
	  else negatedeplist (mem[p + 3].hhfield.v.RH);
	} 
	recycle_value (q);
	free_node (q , 2);
      } 
      break;
    case 17 : 
    case 18 : 
      negatedeplist (mem[cur_exp + 1].hhfield.v.RH);
      break;
    case 16 : 
      cur_exp = - (integer) cur_exp;
      break;
    case 11 : 
      negate_edges (cur_exp);
      break;
      default: 
      badunary (70);
      break;
    } 
    break;
  case 41 : 
    if (cur_type != 2) 
    badunary (41);
    else cur_exp = 61 - cur_exp;
    break;
  case 59 : 
  case 60 : 
  case 61 : 
  case 62 : 
  case 63 : 
  case 64 : 
  case 65 : 
  case 38 : 
  case 66 : 
    if (cur_type != 16) 
    badunary (c);
    else switch (c) 
    {case 59 : 
      cur_exp = squarert (cur_exp);
      break;
    case 60 : 
      cur_exp = m_exp (cur_exp);
      break;
    case 61 : 
      cur_exp = m_log (cur_exp);
      break;
    case 62 : 
    case 63 : 
      {
	n_sin_cos ((cur_exp % 23592960L) * 16);
	if (c == 62) 
	cur_exp = roundfraction (n_sin);
	else cur_exp = roundfraction (n_cos);
      } 
      break;
    case 64 : 
      cur_exp = floorscaled (cur_exp);
      break;
    case 65 : 
      cur_exp = unif_rand (cur_exp);
      break;
    case 38 : 
      {
	if (odd (roundunscaled (cur_exp))) 
	cur_exp = 30;
	else cur_exp = 31;
	cur_type = 2;
      } 
      break;
    case 66 : 
      {
	cur_exp = roundunscaled (cur_exp) % 256;
	if (cur_exp < 0) 
	cur_exp = cur_exp + 256;
	if (char_exists[cur_exp]) 
	cur_exp = 30;
	else cur_exp = 31;
	cur_type = 2;
      } 
      break;
    } 
    break;
  case 67 : 
    if (nicepair (cur_exp , cur_type)) 
    {
      p = mem[cur_exp + 1].cint;
      x = n_arg (mem[p + 1].cint , mem[p + 3].cint);
      if (x >= 0) 
      flush_cur_exp ((x + 8) / 16);
      else flush_cur_exp (- (integer) ((- (integer) x + 8) / 16));
    } 
    else badunary (67);
    break;
  case 53 : 
  case 54 : 
    if ((cur_type <= 14) && (cur_type >= 13)) 
    takepart (c);
    else badunary (c);
    break;
  case 55 : 
  case 56 : 
  case 57 : 
  case 58 : 
    if (cur_type == 13) 
    takepart (c);
    else badunary (c);
    break;
  case 50 : 
    if (cur_type != 16) 
    badunary (50);
    else {
	
      cur_exp = roundunscaled (cur_exp) % 256;
      cur_type = 4;
      if (cur_exp < 0) 
      cur_exp = cur_exp + 256;
      if ((str_start[cur_exp + 1] - str_start[cur_exp]) != 1) 
      {
	{
	  if (pool_ptr + 1 > max_pool_ptr) 
	  {
	    if (pool_ptr + 1 > pool_size) 
	    overflow (257 , pool_size - init_pool_ptr);
	    max_pool_ptr = pool_ptr + 1;
	  } 
	} 
	{
	  str_pool[pool_ptr] = cur_exp;
	  incr (pool_ptr);
	} 
	cur_exp = make_string ();
      } 
    } 
    break;
  case 42 : 
    if (cur_type != 16) 
    badunary (42);
    else {
	
      old_setting = selector;
      selector = 5;
      print_scaled (cur_exp);
      cur_exp = make_string ();
      selector = old_setting;
      cur_type = 4;
    } 
    break;
  case 47 : 
  case 48 : 
  case 49 : 
    if (cur_type != 4) 
    badunary (c);
    else strtonum (c);
    break;
  case 51 : 
    if (cur_type == 4) 
    flush_cur_exp ((str_start[cur_exp + 1] - str_start[cur_exp]) * 65536L) 
;
    else if (cur_type == 9) 
    flush_cur_exp (pathlength ());
    else if (cur_type == 16) 
    cur_exp = abs (cur_exp);
    else if (nicepair (cur_exp , cur_type)) 
    flush_cur_exp (pyth_add (mem[mem[cur_exp + 1].cint + 1].cint , mem[
    mem[cur_exp + 1].cint + 3].cint));
    else badunary (c);
    break;
  case 52 : 
    if (cur_type == 14) 
    flush_cur_exp (0);
    else if (cur_type != 9) 
    badunary (52);
    else if (mem[cur_exp].hhfield.b0 == 0) 
    flush_cur_exp (0);
    else {
	
      cur_pen = 3;
      cur_path_type = 1;
      cur_exp = makespec (cur_exp , -1879080960L , 0);
      flush_cur_exp (turning_number * 65536L);
    } 
    break;
  case 2 : 
    {
      if ((cur_type >= 2) && (cur_type <= 3)) 
      flush_cur_exp (30);
      else flush_cur_exp (31);
      cur_type = 2;
    } 
    break;
  case 4 : 
    {
      if ((cur_type >= 4) && (cur_type <= 5)) 
      flush_cur_exp (30);
      else flush_cur_exp (31);
      cur_type = 2;
    } 
    break;
  case 6 : 
    {
      if ((cur_type >= 6) && (cur_type <= 8)) 
      flush_cur_exp (30);
      else flush_cur_exp (31);
      cur_type = 2;
    } 
    break;
  case 9 : 
    {
      if ((cur_type >= 9) && (cur_type <= 10)) 
      flush_cur_exp (30);
      else flush_cur_exp (31);
      cur_type = 2;
    } 
    break;
  case 11 : 
    {
      if ((cur_type >= 11) && (cur_type <= 12)) 
      flush_cur_exp (30);
      else flush_cur_exp (31);
      cur_type = 2;
    } 
    break;
  case 13 : 
  case 14 : 
    {
      if (cur_type == c) 
      flush_cur_exp (30);
      else flush_cur_exp (31);
      cur_type = 2;
    } 
    break;
  case 15 : 
    {
      if ((cur_type >= 16) && (cur_type <= 19)) 
      flush_cur_exp (30);
      else flush_cur_exp (31);
      cur_type = 2;
    } 
    break;
  case 39 : 
  case 40 : 
    testknown (c);
    break;
  case 68 : 
    {
      if (cur_type != 9) 
      flush_cur_exp (31);
      else if (mem[cur_exp].hhfield.b0 != 0) 
      flush_cur_exp (30);
      else flush_cur_exp (31);
      cur_type = 2;
    } 
    break;
  case 45 : 
    {
      if (cur_type == 14) 
      pairtopath ();
      if (cur_type == 9) 
      cur_type = 8;
      else badunary (45);
    } 
    break;
  case 44 : 
    {
      if (cur_type == 8) 
      materializepen ();
      if (cur_type != 6) 
      badunary (44);
      else {
	  
	flush_cur_exp (makepath (cur_exp));
	cur_type = 9;
      } 
    } 
    break;
  case 46 : 
    if (cur_type != 11) 
    badunary (46);
    else flush_cur_exp (total_weight (cur_exp));
    break;
  case 43 : 
    if (cur_type == 9) 
    {
      p = htapypoc (cur_exp);
      if (mem[p].hhfield.b1 == 0) 
      p = mem[p].hhfield.v.RH;
      toss_knot_list (cur_exp);
      cur_exp = p;
    } 
    else if (cur_type == 14) 
    pairtopath ();
    else badunary (43);
    break;
  } 
  {
    if (arith_error) 
    clear_arith ();
  } 
} 
void 
zbadbinary (halfword p , quarterword c) 
{
  disp_err (p , 261);
  disp_err (0 , 838);
  if (c >= 94) 
  print_op (c);
  printknownorunknowntype (mem[p].hhfield.b0 , p);
  if (c >= 94) 
  print (479);
  else print_op (c);
  printknownorunknowntype (cur_type , cur_exp);
  {
    help_ptr = 3;
    help_line[2] = 839;
    help_line[1] = 848;
    help_line[0] = 849;
  } 
  put_get_error ();
} 
halfword 
ztarnished (halfword p) 
{
  /* 10 */ register halfword Result; halfword q;
  halfword r;
  q = mem[p + 1].cint;
  r = q + big_node_size[mem[p].hhfield.b0];
  do {
      r = r - 2;
    if (mem[r].hhfield.b0 == 19) 
    {
      Result = 1;
      goto lab10;
    } 
  } while (!(r == q));
  Result = 0;
  lab10:;
  return Result;
} 
void 
zdepfinish (halfword v , halfword q , small_number t) 
{
  halfword p;
  scaled vv;
  if (q == 0) 
  p = cur_exp;
  else p = q;
  mem[p + 1].hhfield.v.RH = v;
  mem[p].hhfield.b0 = t;
  if (mem[v].hhfield.lhfield == 0) 
  {
    vv = mem[v + 1].cint;
    if (q == 0) 
    flush_cur_exp (vv);
    else {
	
      recycle_value (p);
      mem[q].hhfield.b0 = 16;
      mem[q + 1].cint = vv;
    } 
  } 
  else if (q == 0) 
  cur_type = t;
  if (fix_needed) 
  fix_dependencies ();
} 
void 
zaddorsubtract (halfword p , halfword q , quarterword c) 
{
  /* 30 10 */ small_number s, t;
  halfword r;
  integer v;
  if (q == 0) 
  {
    t = cur_type;
    if (t < 17) 
    v = cur_exp;
    else v = mem[cur_exp + 1].hhfield.v.RH;
  } 
  else {
      
    t = mem[q].hhfield.b0;
    if (t < 17) 
    v = mem[q + 1].cint;
    else v = mem[q + 1].hhfield.v.RH;
  } 
  if (t == 16) 
  {
    if (c == 70) 
    v = - (integer) v;
    if (mem[p].hhfield.b0 == 16) 
    {
      v = slow_add (mem[p + 1].cint , v);
      if (q == 0) 
      cur_exp = v;
      else mem[q + 1].cint = v;
      goto lab10;
    } 
    r = mem[p + 1].hhfield.v.RH;
    while (mem[r].hhfield.lhfield != 0) r = mem[r].hhfield.v.RH;
    mem[r + 1].cint = slow_add (mem[r + 1].cint , v);
    if (q == 0) 
    {
      q = get_node (2);
      cur_exp = q;
      cur_type = mem[p].hhfield.b0;
      mem[q].hhfield.b1 = 11;
    } 
    mem[q + 1].hhfield.v.RH = mem[p + 1].hhfield.v.RH;
    mem[q].hhfield.b0 = mem[p].hhfield.b0;
    mem[q + 1].hhfield.lhfield = mem[p + 1].hhfield.lhfield;
    mem[mem[p + 1].hhfield.lhfield].hhfield.v.RH = q;
    mem[p].hhfield.b0 = 16;
  } 
  else {
      
    if (c == 70) 
    negatedeplist (v);
    if (mem[p].hhfield.b0 == 16) 
    {
      while (mem[v].hhfield.lhfield != 0) v = mem[v].hhfield.v.RH 
;
      mem[v + 1].cint = slow_add (mem[p + 1].cint , mem[v + 1]
      .cint);
    } 
    else {
	
      s = mem[p].hhfield.b0;
      r = mem[p + 1].hhfield.v.RH;
      if (t == 17) 
      {
	if (s == 17) {
	    
	  if (max_coef (r) + max_coef (v) < 626349397L) 
	  {
	    v = pplusq (v , r , 17);
	    goto done;
	  } 
	} 
	t = 18;
	v = p_over_v (v , 65536L , 17 , 18);
      } 
      if (s == 18) 
      v = pplusq (v , r , 18);
      else v = p_plus_fq (v , 65536L , r , 18 , 17);
      done: if (q != 0) 
      depfinish (v , q , t);
      else {
	  
	cur_type = t;
	depfinish (v , 0 , t);
      } 
    } 
  } 
  lab10:;
} 
void 
zdepmult (halfword p , integer v , boolean visscaled) 
{
  /* 10 */ halfword q;
  small_number s, t;
  if (p == 0) 
  q = cur_exp;
  else if (mem[p].hhfield.b0 != 16) 
  q = p;
  else {
      
    if (visscaled) 
    mem[p + 1].cint = takescaled (mem[p + 1].cint , v);
    else mem[p + 1].cint = takefraction (mem[p + 1].cint , v);
    goto lab10;
  } 
  t = mem[q].hhfield.b0;
  q = mem[q + 1].hhfield.v.RH;
  s = t;
  if (t == 17) {
      
    if (visscaled) {
	
      if (ab_vs_cd (max_coef (q) , abs (v) , 626349396L , 65536L) >= 0) 
      t = 18;
    } 
  } 
  q = ptimesv (q , v , s , t , visscaled);
  depfinish (q , p , t);
  lab10:;
} 
void 
zhardtimes (halfword p) 
{
  halfword q;
  halfword r;
  scaled u, v;
  if (mem[p].hhfield.b0 == 14) 
  {
    q = stash_cur_exp ();
    unstash_cur_exp (p);
    p = q;
  } 
  r = mem[cur_exp + 1].cint;
  u = mem[r + 1].cint;
  v = mem[r + 3].cint;
  mem[r + 2].hhfield.b0 = mem[p].hhfield.b0;
  newdep (r + 2 , copydeplist (mem[p + 1].hhfield.v.RH));
  mem[r].hhfield.b0 = mem[p].hhfield.b0;
  mem[r + 1] = mem[p + 1];
  mem[mem[p + 1].hhfield.lhfield].hhfield.v.RH = r;
  free_node (p , 2);
  depmult (r , u , true);
  depmult (r + 2 , v , true);
} 
void 
zdepdiv (halfword p , scaled v) 
{
  /* 10 */ halfword q;
  small_number s, t;
  if (p == 0) 
  q = cur_exp;
  else if (mem[p].hhfield.b0 != 16) 
  q = p;
  else {
      
    mem[p + 1].cint = makescaled (mem[p + 1].cint , v);
    goto lab10;
  } 
  t = mem[q].hhfield.b0;
  q = mem[q + 1].hhfield.v.RH;
  s = t;
  if (t == 17) {
      
    if (ab_vs_cd (max_coef (q) , 65536L , 626349396L , abs (v)) >= 0) 
    t = 18;
  } 
  q = p_over_v (q , v , s , t);
  depfinish (q , p , t);
  lab10:;
} 
void 
zsetuptrans (quarterword c) 
{
  /* 30 10 */ halfword p, q, r;
  if ((c != 88) || (cur_type != 13)) 
  {
    p = stash_cur_exp ();
    cur_exp = id_transform ();
    cur_type = 13;
    q = mem[cur_exp + 1].cint;
    switch (c) 
    {case 84 : 
      if (mem[p].hhfield.b0 == 16) 
      {
	n_sin_cos ((mem[p + 1].cint % 23592960L) * 16);
	mem[q + 5].cint = roundfraction (n_cos);
	mem[q + 9].cint = roundfraction (n_sin);
	mem[q + 7].cint = - (integer) mem[q + 9].cint;
	mem[q + 11].cint = mem[q + 5].cint;
	goto done;
      } 
      break;
    case 85 : 
      if (mem[p].hhfield.b0 > 14) 
      {
	install (q + 6 , p);
	goto done;
      } 
      break;
    case 86 : 
      if (mem[p].hhfield.b0 > 14) 
      {
	install (q + 4 , p);
	install (q + 10 , p);
	goto done;
      } 
      break;
    case 87 : 
      if (mem[p].hhfield.b0 == 14) 
      {
	r = mem[p + 1].cint;
	install (q , r);
	install (q + 2 , r + 2);
	goto done;
      } 
      break;
    case 89 : 
      if (mem[p].hhfield.b0 > 14) 
      {
	install (q + 4 , p);
	goto done;
      } 
      break;
    case 90 : 
      if (mem[p].hhfield.b0 > 14) 
      {
	install (q + 10 , p);
	goto done;
      } 
      break;
    case 91 : 
      if (mem[p].hhfield.b0 == 14) 
      {
	r = mem[p + 1].cint;
	install (q + 4 , r);
	install (q + 10 , r);
	install (q + 8 , r + 2);
	if (mem[r + 2].hhfield.b0 == 16) 
	mem[r + 3].cint = - (integer) mem[r + 3].cint;
	else negatedeplist (mem[r + 3].hhfield.v.RH);
	install (q + 6 , r + 2);
	goto done;
      } 
      break;
    case 88 : 
;
      break;
    } 
    disp_err (p , 858);
    {
      help_ptr = 3;
      help_line[2] = 859;
      help_line[1] = 860;
      help_line[0] = 538;
    } 
    put_get_error ();
    done: recycle_value (p);
    free_node (p , 2);
  } 
  q = mem[cur_exp + 1].cint;
  r = q + 12;
  do {
      r = r - 2;
    if (mem[r].hhfield.b0 != 16) 
    goto lab10;
  } while (!(r == q));
  txx = mem[q + 5].cint;
  txy = mem[q + 7].cint;
  tyx = mem[q + 9].cint;
  tyy = mem[q + 11].cint;
  tx = mem[q + 1].cint;
  ty = mem[q + 3].cint;
  flush_cur_exp (0);
  lab10:;
} 
void 
zsetupknowntrans (quarterword c) 
{
  setuptrans (c);
  if (cur_type != 16) 
  {
    disp_err (0 , 861);
    {
      help_ptr = 3;
      help_line[2] = 862;
      help_line[1] = 863;
      help_line[0] = 538;
    } 
    put_get_flush_error (0);
    txx = 65536L;
    txy = 0;
    tyx = 0;
    tyy = 65536L;
    tx = 0;
    ty = 0;
  } 
} 
void 
ztrans (halfword p , halfword q) 
{
  scaled v;
  v = takescaled (mem[p].cint , txx) + takescaled (mem[q].cint , 
  txy) + tx;
  mem[q].cint = takescaled (mem[p].cint , tyx) + takescaled (mem[
  q].cint , tyy) + ty;
  mem[p].cint = v;
} 
void 
zpathtrans (halfword p , quarterword c) 
{
  /* 10 */ halfword q;
  setupknowntrans (c);
  unstash_cur_exp (p);
  if (cur_type == 6) 
  {
    if (mem[cur_exp + 9].cint == 0) {
	
      if (tx == 0) {
	  
	if (ty == 0) 
	goto lab10;
      } 
    } 
    flush_cur_exp (makepath (cur_exp));
    cur_type = 8;
  } 
  q = cur_exp;
  do {
      if (mem[q].hhfield.b0 != 0) 
    trans (q + 3 , q + 4);
    trans (q + 1 , q + 2);
    if (mem[q].hhfield.b1 != 0) 
    trans (q + 5 , q + 6);
    q = mem[q].hhfield.v.RH;
  } while (!(q == cur_exp));
  lab10:;
} 
void 
zedgestrans (halfword p , quarterword c) 
{
  /* 10 */ setupknowntrans (c);
  unstash_cur_exp (p);
  cur_edges = cur_exp;
  if (mem[cur_edges].hhfield.v.RH == cur_edges) 
  goto lab10;
  if (txx == 0) {
      
    if (tyy == 0) {
	
      if (txy % 65536L == 0) {
	  
	if (tyx % 65536L == 0) 
	{
	  xy_swap_edges ();
	  txx = txy;
	  tyy = tyx;
	  txy = 0;
	  tyx = 0;
	  if (mem[cur_edges].hhfield.v.RH == cur_edges) 
	  goto lab10;
	} 
      } 
    } 
  } 
  if (txy == 0) {
      
    if (tyx == 0) {
	
      if (txx % 65536L == 0) {
	  
	if (tyy % 65536L == 0) 
	{
	  if ((txx == 0) || (tyy == 0)) 
	  {
	    toss_edges (cur_edges);
	    cur_exp = get_node (6);
	    init_edges (cur_exp);
	  } 
	  else {
	      
	    if (txx < 0) 
	    {
	      x_reflect_edges ();
	      txx = - (integer) txx;
	    } 
	    if (tyy < 0) 
	    {
	      yreflect_edges ();
	      tyy = - (integer) tyy;
	    } 
	    if (txx != 65536L) 
	    x_scale_edges (txx / 65536L);
	    if (tyy != 65536L) 
	    y_scale_edges (tyy / 65536L);
	    tx = roundunscaled (tx);
	    ty = roundunscaled (ty);
	    if ((mem[cur_edges + 2].hhfield.lhfield + tx <= 0) || (mem 
	  [cur_edges + 2].hhfield.v.RH + tx >= 8192) || (mem[cur_edges 
	    + 1].hhfield.lhfield + ty <= 0) || (mem[cur_edges + 1]
	    .hhfield.v.RH + ty >= 8191) || (abs (tx) >= 4096) || (abs (
	    ty) >= 4096)) 
	    {
	      {
		if (interaction == 3) 
		;
		if ((filelineerrorstylep && !(cur_input .name_field == 0)) 
		) 
		{
		  print_nl (261);
		  print (fullsourcefilenamestack[in_open]);
		  print (58);
		  print_int (line);
		  print (262);
		  print (867);
		} 
		else {
		    
		  print_nl (263);
		  print (867);
		} 
	      } 
	      {
		help_ptr = 3;
		help_line[2] = 868;
		help_line[1] = 537;
		help_line[0] = 538;
	      } 
	      put_get_error ();
	    } 
	    else {
		
	      if (tx != 0) 
	      {
		if (!(abs (mem[cur_edges + 3].hhfield.lhfield - tx - 
		4096) < 4096)) 
		fix_offset ();
		mem[cur_edges + 2].hhfield.lhfield = mem[cur_edges + 2]
		.hhfield.lhfield + tx;
		mem[cur_edges + 2].hhfield.v.RH = mem[cur_edges + 2]
		.hhfield.v.RH + tx;
		mem[cur_edges + 3].hhfield.lhfield = mem[cur_edges + 3]
		.hhfield.lhfield - tx;
		mem[cur_edges + 4].cint = 0;
	      } 
	      if (ty != 0) 
	      {
		mem[cur_edges + 1].hhfield.lhfield = mem[cur_edges + 1]
		.hhfield.lhfield + ty;
		mem[cur_edges + 1].hhfield.v.RH = mem[cur_edges + 1]
		.hhfield.v.RH + ty;
		mem[cur_edges + 5].hhfield.lhfield = mem[cur_edges + 5]
		.hhfield.lhfield + ty;
		mem[cur_edges + 4].cint = 0;
	      } 
	    } 
	  } 
	  goto lab10;
	} 
      } 
    } 
  } 
  {
    if (interaction == 3) 
;
    if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
    {
      print_nl (261);
      print (fullsourcefilenamestack[in_open]);
      print (58);
      print_int (line);
      print (262);
      print (864);
    } 
    else {
	
      print_nl (263);
      print (864);
    } 
  } 
  {
    help_ptr = 3;
    help_line[2] = 865;
    help_line[1] = 866;
    help_line[0] = 538;
  } 
  put_get_error ();
  lab10:;
} 
void 
zbilin1 (halfword p , scaled t , halfword q , scaled u , scaled delta) 
{
  halfword r;
  if (t != 65536L) 
  depmult (p , t , true);
  if (u != 0) {
      
    if (mem[q].hhfield.b0 == 16) 
    delta = delta + takescaled (mem[q + 1].cint , u);
    else {
	
      if (mem[p].hhfield.b0 != 18) 
      {
	if (mem[p].hhfield.b0 == 16) 
	newdep (p , constdependency (mem[p + 1].cint));
	else mem[p + 1].hhfield.v.RH = ptimesv (mem[p + 1].hhfield 
	.v.RH , 65536L , 17 , 18 , true);
	mem[p].hhfield.b0 = 18;
      } 
      mem[p + 1].hhfield.v.RH = p_plus_fq (mem[p + 1].hhfield.v.RH , 
      u , mem[q + 1].hhfield.v.RH , 18 , mem[q].hhfield.b0);
    } 
  } 
  if (mem[p].hhfield.b0 == 16) 
  mem[p + 1].cint = mem[p + 1].cint + delta;
  else {
      
    r = mem[p + 1].hhfield.v.RH;
    while (mem[r].hhfield.lhfield != 0) r = mem[r].hhfield.v.RH;
    delta = mem[r + 1].cint + delta;
    if (r != mem[p + 1].hhfield.v.RH) 
    mem[r + 1].cint = delta;
    else {
	
      recycle_value (p);
      mem[p].hhfield.b0 = 16;
      mem[p + 1].cint = delta;
    } 
  } 
  if (fix_needed) 
  fix_dependencies ();
} 
void 
zaddmultdep (halfword p , scaled v , halfword r) 
{
  if (mem[r].hhfield.b0 == 16) 
  mem[dep_final + 1].cint = mem[dep_final + 1].cint + takescaled (mem[
  r + 1].cint , v);
  else {
      
    mem[p + 1].hhfield.v.RH = p_plus_fq (mem[p + 1].hhfield.v.RH , v 
    , mem[r + 1].hhfield.v.RH , 18 , mem[r].hhfield.b0);
    if (fix_needed) 
    fix_dependencies ();
  } 
} 
void 
zbilin2 (halfword p , halfword t , scaled v , halfword u , halfword q) 
{
  scaled vv;
  vv = mem[p + 1].cint;
  mem[p].hhfield.b0 = 18;
  newdep (p , constdependency (0));
  if (vv != 0) 
  addmultdep (p , vv , t);
  if (v != 0) 
  addmultdep (p , v , u);
  if (q != 0) 
  addmultdep (p , 65536L , q);
  if (mem[p + 1].hhfield.v.RH == dep_final) 
  {
    vv = mem[dep_final + 1].cint;
    recycle_value (p);
    mem[p].hhfield.b0 = 16;
    mem[p + 1].cint = vv;
  } 
} 
void 
zbilin3 (halfword p , scaled t , scaled v , scaled u , scaled delta) 
{
  if (t != 65536L) 
  delta = delta + takescaled (mem[p + 1].cint , t);
  else delta = delta + mem[p + 1].cint;
  if (u != 0) 
  mem[p + 1].cint = delta + takescaled (v , u);
  else mem[p + 1].cint = delta;
} 
void 
zbigtrans (halfword p , quarterword c) 
{
  /* 10 */ halfword q, r, pp, qq;
  small_number s;
  s = big_node_size[mem[p].hhfield.b0];
  q = mem[p + 1].cint;
  r = q + s;
  do {
      r = r - 2;
    if (mem[r].hhfield.b0 != 16) 
    {
      setupknowntrans (c);
      makeexpcopy (p);
      r = mem[cur_exp + 1].cint;
      if (cur_type == 13) 
      {
	bilin1 (r + 10 , tyy , q + 6 , tyx , 0);
	bilin1 (r + 8 , tyy , q + 4 , tyx , 0);
	bilin1 (r + 6 , txx , q + 10 , txy , 0);
	bilin1 (r + 4 , txx , q + 8 , txy , 0);
      } 
      bilin1 (r + 2 , tyy , q , tyx , ty);
      bilin1 (r , txx , q + 2 , txy , tx);
      goto lab10;
    } 
  } while (!(r == q));
  setuptrans (c);
  if (cur_type == 16) 
  {
    makeexpcopy (p);
    r = mem[cur_exp + 1].cint;
    if (cur_type == 13) 
    {
      bilin3 (r + 10 , tyy , mem[q + 7].cint , tyx , 0);
      bilin3 (r + 8 , tyy , mem[q + 5].cint , tyx , 0);
      bilin3 (r + 6 , txx , mem[q + 11].cint , txy , 0);
      bilin3 (r + 4 , txx , mem[q + 9].cint , txy , 0);
    } 
    bilin3 (r + 2 , tyy , mem[q + 1].cint , tyx , ty);
    bilin3 (r , txx , mem[q + 3].cint , txy , tx);
  } 
  else {
      
    pp = stash_cur_exp ();
    qq = mem[pp + 1].cint;
    makeexpcopy (p);
    r = mem[cur_exp + 1].cint;
    if (cur_type == 13) 
    {
      bilin2 (r + 10 , qq + 10 , mem[q + 7].cint , qq + 8 , 0);
      bilin2 (r + 8 , qq + 10 , mem[q + 5].cint , qq + 8 , 0);
      bilin2 (r + 6 , qq + 4 , mem[q + 11].cint , qq + 6 , 0);
      bilin2 (r + 4 , qq + 4 , mem[q + 9].cint , qq + 6 , 0);
    } 
    bilin2 (r + 2 , qq + 10 , mem[q + 1].cint , qq + 8 , qq + 2);
    bilin2 (r , qq + 4 , mem[q + 3].cint , qq + 6 , qq);
    recycle_value (pp);
    free_node (pp , 2);
  } 
  lab10:;
} 
void 
zcat (halfword p) 
{
  str_number a, b;
  pool_pointer k;
  a = mem[p + 1].cint;
  b = cur_exp;
  {
    if (pool_ptr + (str_start[a + 1] - str_start[a]) + (str_start[b + 
    1] - str_start[b]) > max_pool_ptr) 
    {
      if (pool_ptr + (str_start[a + 1] - str_start[a]) + (str_start[b 
      + 1] - str_start[b]) > pool_size) 
      overflow (257 , pool_size - init_pool_ptr);
      max_pool_ptr = pool_ptr + (str_start[a + 1] - str_start[a]) + (
      str_start[b + 1] - str_start[b]);
    } 
  } 
  {register integer for_end; k = str_start[a];for_end = str_start[a + 1 
] - 1; if (k <= for_end) do 
    {
      str_pool[pool_ptr] = str_pool[k];
      incr (pool_ptr);
    } 
  while (k++ < for_end);} 
  {register integer for_end; k = str_start[b];for_end = str_start[b + 1 
] - 1; if (k <= for_end) do 
    {
      str_pool[pool_ptr] = str_pool[k];
      incr (pool_ptr);
    } 
  while (k++ < for_end);} 
  cur_exp = make_string ();
  {
    if (str_ref[b]< 127) {
	
      if (str_ref[b] > 1) 
      decr (str_ref[b]);
      else flush_string (b);
    } 
  } 
} 
void 
zchopstring (halfword p) 
{
  integer a, b;
  integer l;
  integer k;
  str_number s;
  boolean reversed;
  a = roundunscaled (mem[p + 1].cint);
  b = roundunscaled (mem[p + 3].cint);
  if (a <= b) 
  reversed = false;
  else {
      
    reversed = true;
    k = a;
    a = b;
    b = k;
  } 
  s = cur_exp;
  l = (str_start[s + 1] - str_start[s]);
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
  {
    if (pool_ptr + b - a > max_pool_ptr) 
    {
      if (pool_ptr + b - a > pool_size) 
      overflow (257 , pool_size - init_pool_ptr);
      max_pool_ptr = pool_ptr + b - a;
    } 
  } 
  if (reversed) 
  {register integer for_end; k = str_start[s]+ b - 1;for_end = str_start 
[s]+ a; if (k >= for_end) do 
    {
      str_pool[pool_ptr] = str_pool[k];
      incr (pool_ptr);
    } 
  while (k-- > for_end);} 
  else {
      register integer for_end; k = str_start[s]+ a;for_end = str_start 
[s]+ b - 1; if (k <= for_end) do 
    {
      str_pool[pool_ptr] = str_pool[k];
      incr (pool_ptr);
    } 
  while (k++ < for_end);} 
  cur_exp = make_string ();
  {
    if (str_ref[s]< 127) {
	
      if (str_ref[s] > 1) 
      decr (str_ref[s]);
      else flush_string (s);
    } 
  } 
} 
void 
zchoppath (halfword p) 
{
  halfword q;
  halfword pp, qq, rr, ss;
  scaled a, b, k, l;
  boolean reversed;
  l = pathlength ();
  a = mem[p + 1].cint;
  b = mem[p + 3].cint;
  if (a <= b) 
  reversed = false;
  else {
      
    reversed = true;
    k = a;
    a = b;
    b = k;
  } 
  if (a < 0) {
      
    if (mem[cur_exp].hhfield.b0 == 0) 
    {
      a = 0;
      if (b < 0) 
      b = 0;
    } 
    else do {
	a = a + l;
      b = b + l;
    } while (!(a >= 0));
  } 
  if (b > l) {
      
    if (mem[cur_exp].hhfield.b0 == 0) 
    {
      b = l;
      if (a > l) 
      a = l;
    } 
    else while (a >= l) {
	
      a = a - l;
      b = b - l;
    } 
  } 
  q = cur_exp;
  while (a >= 65536L) {
      
    q = mem[q].hhfield.v.RH;
    a = a - 65536L;
    b = b - 65536L;
  } 
  if (b == a) 
  {
    if (a > 0) 
    {
      qq = mem[q].hhfield.v.RH;
      splitcubic (q , a * 4096 , mem[qq + 1].cint , mem[qq + 2].cint 
   );
      q = mem[q].hhfield.v.RH;
    } 
    pp = copyknot (q);
    qq = pp;
  } 
  else {
      
    pp = copyknot (q);
    qq = pp;
    do {
	q = mem[q].hhfield.v.RH;
      rr = qq;
      qq = copyknot (q);
      mem[rr].hhfield.v.RH = qq;
      b = b - 65536L;
    } while (!(b <= 0));
    if (a > 0) 
    {
      ss = pp;
      pp = mem[pp].hhfield.v.RH;
      splitcubic (ss , a * 4096 , mem[pp + 1].cint , mem[pp + 2].cint 
   );
      pp = mem[ss].hhfield.v.RH;
      free_node (ss , 7);
      if (rr == ss) 
      {
	b = makescaled (b , 65536L - a);
	rr = pp;
      } 
    } 
    if (b < 0) 
    {
      splitcubic (rr , (b + 65536L) * 4096 , mem[qq + 1].cint , mem[
      qq + 2].cint);
      free_node (qq , 7);
      qq = mem[rr].hhfield.v.RH;
    } 
  } 
  mem[pp].hhfield.b0 = 0;
  mem[qq].hhfield.b1 = 0;
  mem[qq].hhfield.v.RH = pp;
  toss_knot_list (cur_exp);
  if (reversed) 
  {
    cur_exp = mem[htapypoc (pp)].hhfield.v.RH;
    toss_knot_list (pp);
  } 
  else cur_exp = pp;
} 
void 
zpairvalue (scaled x , scaled y) 
{
  halfword p;
  p = get_node (2);
  flush_cur_exp (p);
  cur_type = 14;
  mem[p].hhfield.b0 = 14;
  mem[p].hhfield.b1 = 11;
  init_big_node (p);
  p = mem[p + 1].cint;
  mem[p].hhfield.b0 = 16;
  mem[p + 1].cint = x;
  mem[p + 2].hhfield.b0 = 16;
  mem[p + 3].cint = y;
} 
void 
zsetupoffset (halfword p) 
{
  findoffset (mem[p + 1].cint , mem[p + 3].cint , cur_exp);
  pairvalue (cur_x , cur_y);
} 
void 
zsetupdirectiontime (halfword p) 
{
  flush_cur_exp (finddirectiontime (mem[p + 1].cint , mem[p + 3]
  .cint , cur_exp));
} 
void 
zfindpoint (scaled v , quarterword c) 
{
  halfword p;
  scaled n;
  halfword q;
  p = cur_exp;
  if (mem[p].hhfield.b0 == 0) 
  n = -65536L;
  else n = 0;
  do {
      p = mem[p].hhfield.v.RH;
    n = n + 65536L;
  } while (!(p == cur_exp));
  if (n == 0) 
  v = 0;
  else if (v < 0) {
      
    if (mem[p].hhfield.b0 == 0) 
    v = 0;
    else v = n - 1 - ((- (integer) v - 1) % n);
  } 
  else if (v > n) {
      
    if (mem[p].hhfield.b0 == 0) 
    v = n;
    else v = v % n;
  } 
  p = cur_exp;
  while (v >= 65536L) {
      
    p = mem[p].hhfield.v.RH;
    v = v - 65536L;
  } 
  if (v != 0) 
  {
    q = mem[p].hhfield.v.RH;
    splitcubic (p , v * 4096 , mem[q + 1].cint , mem[q + 2].cint);
    p = mem[p].hhfield.v.RH;
  } 
  switch (c) 
  {case 97 : 
    pairvalue (mem[p + 1].cint , mem[p + 2].cint);
    break;
  case 98 : 
    if (mem[p].hhfield.b0 == 0) 
    pairvalue (mem[p + 1].cint , mem[p + 2].cint);
    else pairvalue (mem[p + 3].cint , mem[p + 4].cint);
    break;
  case 99 : 
    if (mem[p].hhfield.b1 == 0) 
    pairvalue (mem[p + 1].cint , mem[p + 2].cint);
    else pairvalue (mem[p + 5].cint , mem[p + 6].cint);
    break;
  } 
} 
void 
zdobinary (halfword p , quarterword c) 
{
  /* 30 31 10 */ halfword q, r, rr;
  halfword oldp, oldexp;
  integer v;
  {
    if (arith_error) 
    clear_arith ();
  } 
  if (internal[7] > 131072L) 
  {
    begin_diagnostic ();
    print_nl (850);
    print_exp (p , 0);
    print_char (41);
    print_op (c);
    print_char (40);
    print_exp (0 , 0);
    print (842);
    end_diagnostic (false);
  } 
  switch (mem[p].hhfield.b0) 
  {case 13 : 
  case 14 : 
    oldp = tarnished (p);
    break;
  case 19 : 
    oldp = 1;
    break;
    default: 
    oldp = 0;
    break;
  } 
  if (oldp != 0) 
  {
    q = stash_cur_exp ();
    oldp = p;
    makeexpcopy (oldp);
    p = stash_cur_exp ();
    unstash_cur_exp (q);
  } 
  switch (cur_type) 
  {case 13 : 
  case 14 : 
    oldexp = tarnished (cur_exp);
    break;
  case 19 : 
    oldexp = 1;
    break;
    default: 
    oldexp = 0;
    break;
  } 
  if (oldexp != 0) 
  {
    oldexp = cur_exp;
    makeexpcopy (oldexp);
  } 
  switch (c) 
  {case 69 : 
  case 70 : 
    if ((cur_type < 14) || (mem[p].hhfield.b0 < 14)) {
	
      if ((cur_type == 11) && (mem[p].hhfield.b0 == 11)) 
      {
	if (c == 70) 
	negate_edges (cur_exp);
	cur_edges = cur_exp;
	merge_edges (mem[p + 1].cint);
      } 
      else badbinary (p , c);
    } 
    else if (cur_type == 14) {
	
      if (mem[p].hhfield.b0 != 14) 
      badbinary (p , c);
      else {
	  
	q = mem[p + 1].cint;
	r = mem[cur_exp + 1].cint;
	addorsubtract (q , r , c);
	addorsubtract (q + 2 , r + 2 , c);
      } 
    } 
    else if (mem[p].hhfield.b0 == 14) 
    badbinary (p , c);
    else addorsubtract (p , 0 , c);
    break;
  case 77 : 
  case 78 : 
  case 79 : 
  case 80 : 
  case 81 : 
  case 82 : 
    {
      if ((cur_type > 14) && (mem[p].hhfield.b0 > 14)) 
      addorsubtract (p , 0 , 70);
      else if (cur_type != mem[p].hhfield.b0) 
      {
	badbinary (p , c);
	goto done;
      } 
      else if (cur_type == 4) 
      flush_cur_exp (str_vs_str (mem[p + 1].cint , cur_exp));
      else if ((cur_type == 5) || (cur_type == 3)) 
      {
	q = mem[cur_exp + 1].cint;
	while ((q != cur_exp) && (q != p)) q = mem[q + 1].cint;
	if (q == p) 
	flush_cur_exp (0);
      } 
      else if ((cur_type == 14) || (cur_type == 13)) 
      {
	q = mem[p + 1].cint;
	r = mem[cur_exp + 1].cint;
	rr = r + big_node_size[cur_type] - 2;
	while (true) {
	    
	  addorsubtract (q , r , 70);
	  if (mem[r].hhfield.b0 != 16) 
	  goto done1;
	  if (mem[r + 1].cint != 0) 
	  goto done1;
	  if (r == rr) 
	  goto done1;
	  q = q + 2;
	  r = r + 2;
	} 
	done1: takepart (53 + half (r - mem[cur_exp + 1].cint));
      } 
      else if (cur_type == 2) 
      flush_cur_exp (cur_exp - mem[p + 1].cint);
      else {
	  
	badbinary (p , c);
	goto done;
      } 
      if (cur_type != 16) 
      {
	if (cur_type < 16) 
	{
	  disp_err (p , 261);
	  {
	    help_ptr = 1;
	    help_line[0] = 851;
	  } 
	} 
	else {
	    
	  help_ptr = 2;
	  help_line[1] = 852;
	  help_line[0] = 853;
	} 
	disp_err (0 , 854);
	put_get_flush_error (31);
      } 
      else switch (c) 
      {case 77 : 
	if (cur_exp < 0) 
	cur_exp = 30;
	else cur_exp = 31;
	break;
      case 78 : 
	if (cur_exp <= 0) 
	cur_exp = 30;
	else cur_exp = 31;
	break;
      case 79 : 
	if (cur_exp > 0) 
	cur_exp = 30;
	else cur_exp = 31;
	break;
      case 80 : 
	if (cur_exp >= 0) 
	cur_exp = 30;
	else cur_exp = 31;
	break;
      case 81 : 
	if (cur_exp == 0) 
	cur_exp = 30;
	else cur_exp = 31;
	break;
      case 82 : 
	if (cur_exp != 0) 
	cur_exp = 30;
	else cur_exp = 31;
	break;
      } 
      cur_type = 2;
      done:;
    } 
    break;
  case 76 : 
  case 75 : 
    if ((mem[p].hhfield.b0 != 2) || (cur_type != 2)) 
    badbinary (p , c);
    else if (mem[p + 1].cint == c - 45) 
    cur_exp = mem[p + 1].cint;
    break;
  case 71 : 
    if ((cur_type < 14) || (mem[p].hhfield.b0 < 14)) 
    badbinary (p , 71);
    else if ((cur_type == 16) || (mem[p].hhfield.b0 == 16)) 
    {
      if (mem[p].hhfield.b0 == 16) 
      {
	v = mem[p + 1].cint;
	free_node (p , 2);
      } 
      else {
	  
	v = cur_exp;
	unstash_cur_exp (p);
      } 
      if (cur_type == 16) 
      cur_exp = takescaled (cur_exp , v);
      else if (cur_type == 14) 
      {
	p = mem[cur_exp + 1].cint;
	depmult (p , v , true);
	depmult (p + 2 , v , true);
      } 
      else depmult (0 , v , true);
      goto lab10;
    } 
    else if ((nicepair (p , mem[p].hhfield.b0) && (cur_type > 14)) 
    || (nicepair (cur_exp , cur_type) && (mem[p].hhfield.b0 > 14))) 
    {
      hardtimes (p);
      goto lab10;
    } 
    else badbinary (p , 71);
    break;
  case 72 : 
    if ((cur_type != 16) || (mem[p].hhfield.b0 < 14)) 
    badbinary (p , 72);
    else {
	
      v = cur_exp;
      unstash_cur_exp (p);
      if (v == 0) 
      {
	disp_err (0 , 784);
	{
	  help_ptr = 2;
	  help_line[1] = 856;
	  help_line[0] = 857;
	} 
	put_get_error ();
      } 
      else {
	  
	if (cur_type == 16) 
	cur_exp = makescaled (cur_exp , v);
	else if (cur_type == 14) 
	{
	  p = mem[cur_exp + 1].cint;
	  depdiv (p , v);
	  depdiv (p + 2 , v);
	} 
	else depdiv (0 , v);
      } 
      goto lab10;
    } 
    break;
  case 73 : 
  case 74 : 
    if ((cur_type == 16) && (mem[p].hhfield.b0 == 16)) {
	
      if (c == 73) 
      cur_exp = pyth_add (mem[p + 1].cint , cur_exp);
      else cur_exp = pyth_sub (mem[p + 1].cint , cur_exp);
    } 
    else badbinary (p , c);
    break;
  case 84 : 
  case 85 : 
  case 86 : 
  case 87 : 
  case 88 : 
  case 89 : 
  case 90 : 
  case 91 : 
    if ((mem[p].hhfield.b0 == 9) || (mem[p].hhfield.b0 == 8) || 
    (mem[p].hhfield.b0 == 6)) 
    {
      pathtrans (p , c);
      goto lab10;
    } 
    else if ((mem[p].hhfield.b0 == 14) || (mem[p].hhfield.b0 == 
    13)) 
    bigtrans (p , c);
    else if (mem[p].hhfield.b0 == 11) 
    {
      edgestrans (p , c);
      goto lab10;
    } 
    else badbinary (p , c);
    break;
  case 83 : 
    if ((cur_type == 4) && (mem[p].hhfield.b0 == 4)) 
    cat (p);
    else badbinary (p , 83);
    break;
  case 94 : 
    if (nicepair (p , mem[p].hhfield.b0) && (cur_type == 4)) 
    chopstring (mem[p + 1].cint);
    else badbinary (p , 94);
    break;
  case 95 : 
    {
      if (cur_type == 14) 
      pairtopath ();
      if (nicepair (p , mem[p].hhfield.b0) && (cur_type == 9)) 
      choppath (mem[p + 1].cint);
      else badbinary (p , 95);
    } 
    break;
  case 97 : 
  case 98 : 
  case 99 : 
    {
      if (cur_type == 14) 
      pairtopath ();
      if ((cur_type == 9) && (mem[p].hhfield.b0 == 16)) 
      findpoint (mem[p + 1].cint , c);
      else badbinary (p , c);
    } 
    break;
  case 100 : 
    {
      if (cur_type == 8) 
      materializepen ();
      if ((cur_type == 6) && nicepair (p , mem[p].hhfield.b0)) 
      setupoffset (mem[p + 1].cint);
      else badbinary (p , 100);
    } 
    break;
  case 96 : 
    {
      if (cur_type == 14) 
      pairtopath ();
      if ((cur_type == 9) && nicepair (p , mem[p].hhfield.b0)) 
      setupdirectiontime (mem[p + 1].cint);
      else badbinary (p , 96);
    } 
    break;
  case 92 : 
    {
      if (mem[p].hhfield.b0 == 14) 
      {
	q = stash_cur_exp ();
	unstash_cur_exp (p);
	pairtopath ();
	p = stash_cur_exp ();
	unstash_cur_exp (q);
      } 
      if (cur_type == 14) 
      pairtopath ();
      if ((cur_type == 9) && (mem[p].hhfield.b0 == 9)) 
      {
	pathintersection (mem[p + 1].cint , cur_exp);
	pairvalue (cur_t , cur_tt);
      } 
      else badbinary (p , 92);
    } 
    break;
  } 
  recycle_value (p);
  free_node (p , 2);
  lab10: {
      
    if (arith_error) 
    clear_arith ();
  } 
  if (oldp != 0) 
  {
    recycle_value (oldp);
    free_node (oldp , 2);
  } 
  if (oldexp != 0) 
  {
    recycle_value (oldexp);
    free_node (oldexp , 2);
  } 
} 
void 
zfracmult (scaled n , scaled d) 
{
  halfword p;
  halfword oldexp;
  fraction v;
  if (internal[7] > 131072L) 
  {
    begin_diagnostic ();
    print_nl (850);
    print_scaled (n);
    print_char (47);
    print_scaled (d);
    print (855);
    print_exp (0 , 0);
    print (842);
    end_diagnostic (false);
  } 
  switch (cur_type) 
  {case 13 : 
  case 14 : 
    oldexp = tarnished (cur_exp);
    break;
  case 19 : 
    oldexp = 1;
    break;
    default: 
    oldexp = 0;
    break;
  } 
  if (oldexp != 0) 
  {
    oldexp = cur_exp;
    makeexpcopy (oldexp);
  } 
  v = makefraction (n , d);
  if (cur_type == 16) 
  cur_exp = takefraction (cur_exp , v);
  else if (cur_type == 14) 
  {
    p = mem[cur_exp + 1].cint;
    depmult (p , v , false);
    depmult (p + 2 , v , false);
  } 
  else depmult (0 , v , false);
  if (oldexp != 0) 
  {
    recycle_value (oldexp);
    free_node (oldexp , 2);
  } 
} 
void 
gf_swap (void) 
{
  if (gf_ptr > (2147483647L - gf_offset)) 
  {
    gf_prev_ptr = 0;
    fatal_error (1053);
  } 
  if (gf_limit == gf_buf_size) 
  {
    write_gf (0 , half_buf - 1);
    gf_limit = half_buf;
    gf_offset = gf_offset + gf_buf_size;
    gf_ptr = 0;
  } 
  else {
      
    write_gf (half_buf , gf_buf_size - 1);
    gf_limit = gf_buf_size;
  } 
} 
void 
zgffour (integer x) 
{
  if (x >= 0) 
  {
    gf_buf[gf_ptr] = x / 16777216L;
    incr (gf_ptr);
    if (gf_ptr == gf_limit) 
    gf_swap ();
  } 
  else {
      
    x = x + 1073741824L;
    x = x + 1073741824L;
    {
      gf_buf[gf_ptr] = (x / 16777216L) + 128;
      incr (gf_ptr);
      if (gf_ptr == gf_limit) 
      gf_swap ();
    } 
  } 
  x = x % 16777216L;
  {
    gf_buf[gf_ptr] = x / 65536L;
    incr (gf_ptr);
    if (gf_ptr == gf_limit) 
    gf_swap ();
  } 
  x = x % 65536L;
  {
    gf_buf[gf_ptr] = x / 256;
    incr (gf_ptr);
    if (gf_ptr == gf_limit) 
    gf_swap ();
  } 
  {
    gf_buf[gf_ptr] = x % 256;
    incr (gf_ptr);
    if (gf_ptr == gf_limit) 
    gf_swap ();
  } 
} 
void 
zgftwo (integer x) 
{
  {
    gf_buf[gf_ptr] = x / 256;
    incr (gf_ptr);
    if (gf_ptr == gf_limit) 
    gf_swap ();
  } 
  {
    gf_buf[gf_ptr] = x % 256;
    incr (gf_ptr);
    if (gf_ptr == gf_limit) 
    gf_swap ();
  } 
} 
void 
zgfthree (integer x) 
{
  {
    gf_buf[gf_ptr] = x / 65536L;
    incr (gf_ptr);
    if (gf_ptr == gf_limit) 
    gf_swap ();
  } 
  {
    gf_buf[gf_ptr] = (x % 65536L) / 256;
    incr (gf_ptr);
    if (gf_ptr == gf_limit) 
    gf_swap ();
  } 
  {
    gf_buf[gf_ptr] = x % 256;
    incr (gf_ptr);
    if (gf_ptr == gf_limit) 
    gf_swap ();
  } 
} 
void 
zgf_paint (integer d) 
{
  if (d < 64) 
  {
    gf_buf[gf_ptr] = 0 + d;
    incr (gf_ptr);
    if (gf_ptr == gf_limit) 
    gf_swap ();
  } 
  else if (d < 256) 
  {
    {
      gf_buf[gf_ptr] = 64;
      incr (gf_ptr);
      if (gf_ptr == gf_limit) 
      gf_swap ();
    } 
    {
      gf_buf[gf_ptr] = d;
      incr (gf_ptr);
      if (gf_ptr == gf_limit) 
      gf_swap ();
    } 
  } 
  else {
      
    {
      gf_buf[gf_ptr] = 65;
      incr (gf_ptr);
      if (gf_ptr == gf_limit) 
      gf_swap ();
    } 
    gftwo (d);
  } 
} 
void 
zgfstring (str_number s , str_number t) 
{
  pool_pointer k;
  integer l;
  if (s != 0) 
  {
    l = (str_start[s + 1] - str_start[s]);
    if (t != 0) 
    l = l + (str_start[t + 1] - str_start[t]);
    if (l <= 255) 
    {
      {
	gf_buf[gf_ptr] = 239;
	incr (gf_ptr);
	if (gf_ptr == gf_limit) 
	gf_swap ();
      } 
      {
	gf_buf[gf_ptr] = l;
	incr (gf_ptr);
	if (gf_ptr == gf_limit) 
	gf_swap ();
      } 
    } 
    else {
	
      {
	gf_buf[gf_ptr] = 241;
	incr (gf_ptr);
	if (gf_ptr == gf_limit) 
	gf_swap ();
      } 
      gfthree (l);
    } 
    {register integer for_end; k = str_start[s];for_end = str_start[s + 
    1] - 1; if (k <= for_end) do 
      {
	gf_buf[gf_ptr] = str_pool[k];
	incr (gf_ptr);
	if (gf_ptr == gf_limit) 
	gf_swap ();
      } 
    while (k++ < for_end);} 
  } 
  if (t != 0) 
  {register integer for_end; k = str_start[t];for_end = str_start[t + 1 
] - 1; if (k <= for_end) do 
    {
      gf_buf[gf_ptr] = str_pool[k];
      incr (gf_ptr);
      if (gf_ptr == gf_limit) 
      gf_swap ();
    } 
  while (k++ < for_end);} 
} 
void 
zgfboc (integer minm , integer maxm , integer minn , integer maxn) 
{
  /* 10 */ if (minm < gf_min_m) 
  gf_min_m = minm;
  if (maxn > gf_max_n) 
  gf_max_n = maxn;
  if (boc_p == -1) {
      
    if (boc_c >= 0) {
	
      if (boc_c < 256) {
	  
	if (maxm - minm >= 0) {
	    
	  if (maxm - minm < 256) {
	      
	    if (maxm >= 0) {
		
	      if (maxm < 256) {
		  
		if (maxn - minn >= 0) {
		    
		  if (maxn - minn < 256) {
		      
		    if (maxn >= 0) {
			
		      if (maxn < 256) 
		      {
			{
			  gf_buf[gf_ptr] = 68;
			  incr (gf_ptr);
			  if (gf_ptr == gf_limit) 
			  gf_swap ();
			} 
			{
			  gf_buf[gf_ptr] = boc_c;
			  incr (gf_ptr);
			  if (gf_ptr == gf_limit) 
			  gf_swap ();
			} 
			{
			  gf_buf[gf_ptr] = maxm - minm;
			  incr (gf_ptr);
			  if (gf_ptr == gf_limit) 
			  gf_swap ();
			} 
			{
			  gf_buf[gf_ptr] = maxm;
			  incr (gf_ptr);
			  if (gf_ptr == gf_limit) 
			  gf_swap ();
			} 
			{
			  gf_buf[gf_ptr] = maxn - minn;
			  incr (gf_ptr);
			  if (gf_ptr == gf_limit) 
			  gf_swap ();
			} 
			{
			  gf_buf[gf_ptr] = maxn;
			  incr (gf_ptr);
			  if (gf_ptr == gf_limit) 
			  gf_swap ();
			} 
			goto lab10;
		      } 
		    } 
		  } 
		} 
	      } 
	    } 
	  } 
	} 
      } 
    } 
  } 
  {
    gf_buf[gf_ptr] = 67;
    incr (gf_ptr);
    if (gf_ptr == gf_limit) 
    gf_swap ();
  } 
  gffour (boc_c);
  gffour (boc_p);
  gffour (minm);
  gffour (maxm);
  gffour (minn);
  gffour (maxn);
  lab10:;
} 
void 
init_gf (void) 
{
  short k;
  integer t;
  gf_min_m = 4096;
  gf_max_m = -4096;
  gf_min_n = 4096;
  gf_max_n = -4096;
  {register integer for_end; k = 0;for_end = 255; if (k <= for_end) do 
    char_ptr[k] = -1;
  while (k++ < for_end);} 
  if (internal[27]<= 0) 
  gf_ext = 1055;
  else {
      
    old_setting = selector;
    selector = 5;
    print_char (46);
    print_int (makescaled (internal[27], 59429463L));
    print (1056);
    gf_ext = make_string ();
    selector = old_setting;
  } 
  {
    if (job_name == 0) 
    open_log_file ();
    packjob_name (gf_ext);
    while (!bopenout (gf_file)) promptfilename (756 , gf_ext);
    output_file_name = bmakenamestring (gf_file);
  } 
  {
    gf_buf[gf_ptr] = 247;
    incr (gf_ptr);
    if (gf_ptr == gf_limit) 
    gf_swap ();
  } 
  {
    gf_buf[gf_ptr] = 131;
    incr (gf_ptr);
    if (gf_ptr == gf_limit) 
    gf_swap ();
  } 
  old_setting = selector;
  selector = 5;
  print (1054);
  print_int (roundunscaled (internal[14]));
  print_char (46);
  print_dd (roundunscaled (internal[15]));
  print_char (46);
  print_dd (roundunscaled (internal[16]));
  print_char (58);
  t = roundunscaled (internal[17]);
  print_dd (t / 60);
  print_dd (t % 60);
  selector = old_setting;
  {
    gf_buf[gf_ptr] = (pool_ptr - str_start[str_ptr]);
    incr (gf_ptr);
    if (gf_ptr == gf_limit) 
    gf_swap ();
  } 
  gfstring (0 , make_string ());
  decr (str_ptr);
  pool_ptr = str_start[str_ptr];
  gf_prev_ptr = gf_offset + gf_ptr;
} 
void 
zshipout (eight_bits c) 
{
  /* 30 */ integer f;
  integer prevm, m, mm;
  integer prevn, n;
  halfword p, q;
  integer prevw, w, ww;
  integer d;
  integer delta;
  integer curminm;
  integer xoff, yoff;
  if (output_file_name == 0) 
  init_gf ();
  f = roundunscaled (internal[19]);
  xoff = roundunscaled (internal[29]);
  yoff = roundunscaled (internal[30]);
  if (term_offset > maxprintline - 9) 
  print_ln ();
  else if ((term_offset > 0) || (file_offset > 0)) 
  print_char (32);
  print_char (91);
  print_int (c);
  if (f != 0) 
  {
    print_char (46);
    print_int (f);
  } 
  fflush (stdout);
  boc_c = 256 * f + c;
  boc_p = char_ptr[c];
  char_ptr[c] = gf_prev_ptr;
  if (internal[34] > 0) 
  {
    if (xoff != 0) 
    {
      gfstring (437 , 0);
      {
	gf_buf[gf_ptr] = 243;
	incr (gf_ptr);
	if (gf_ptr == gf_limit) 
	gf_swap ();
      } 
      gffour (xoff * 65536L);
    } 
    if (yoff != 0) 
    {
      gfstring (438 , 0);
      {
	gf_buf[gf_ptr] = 243;
	incr (gf_ptr);
	if (gf_ptr == gf_limit) 
	gf_swap ();
      } 
      gffour (yoff * 65536L);
    } 
  } 
  prevn = 4096;
  p = mem[cur_edges].hhfield.lhfield;
  n = mem[cur_edges + 1].hhfield.v.RH - 4096;
  while (p != cur_edges) {
      
    if (mem[p + 1].hhfield.lhfield > 1) 
    sort_edges (p);
    q = mem[p + 1].hhfield.v.RH;
    w = 0;
    prevm = -268435456L;
    ww = 0;
    prevw = 0;
    m = prevm;
    do {
	if (q == memtop) 
      mm = 268435456L;
      else {
	  
	d = mem[q].hhfield.lhfield;
	mm = d / 8;
	ww = ww + (d % 8) - 4;
      } 
      if (mm != m) 
      {
	if (prevw <= 0) 
	{
	  if (w > 0) 
	  {
	    if (prevm == -268435456L) 
	    {
	      if (prevn == 4096) 
	      {
		gfboc (mem[cur_edges + 2].hhfield.lhfield + xoff - 4096 , 
		mem[cur_edges + 2].hhfield.v.RH + xoff - 4096 , mem[
		cur_edges + 1].hhfield.lhfield + yoff - 4096 , n + yoff);
		curminm = mem[cur_edges + 2].hhfield.lhfield - 4096 + mem 
		[cur_edges + 3].hhfield.lhfield;
	      } 
	      else if (prevn > n + 1) 
	      {
		delta = prevn - n - 1;
		if (delta < 256) 
		{
		  {
		    gf_buf[gf_ptr] = 71;
		    incr (gf_ptr);
		    if (gf_ptr == gf_limit) 
		    gf_swap ();
		  } 
		  {
		    gf_buf[gf_ptr] = delta;
		    incr (gf_ptr);
		    if (gf_ptr == gf_limit) 
		    gf_swap ();
		  } 
		} 
		else {
		    
		  {
		    gf_buf[gf_ptr] = 72;
		    incr (gf_ptr);
		    if (gf_ptr == gf_limit) 
		    gf_swap ();
		  } 
		  gftwo (delta);
		} 
	      } 
	      else {
		  
		delta = m - curminm;
		if (delta > 164) 
		{
		  gf_buf[gf_ptr] = 70;
		  incr (gf_ptr);
		  if (gf_ptr == gf_limit) 
		  gf_swap ();
		} 
		else {
		    
		  {
		    gf_buf[gf_ptr] = 74 + delta;
		    incr (gf_ptr);
		    if (gf_ptr == gf_limit) 
		    gf_swap ();
		  } 
		  goto done;
		} 
	      } 
	      gf_paint (m - curminm);
	      done: prevn = n;
	    } 
	    else gf_paint (m - prevm);
	    prevm = m;
	    prevw = w;
	  } 
	} 
	else if (w <= 0) 
	{
	  gf_paint (m - prevm);
	  prevm = m;
	  prevw = w;
	} 
	m = mm;
      } 
      w = ww;
      q = mem[q].hhfield.v.RH;
    } while (!(mm == 268435456L));
    if (w != 0) 
    print_nl (1058);
    if (prevm - mem[cur_edges + 3].hhfield.lhfield + xoff > gf_max_m) 
    gf_max_m = prevm - mem[cur_edges + 3].hhfield.lhfield + xoff;
    p = mem[p].hhfield.lhfield;
    decr (n);
  } 
  if (prevn == 4096) 
  {
    gfboc (0 , 0 , 0 , 0);
    if (gf_max_m < 0) 
    gf_max_m = 0;
    if (gf_min_n > 0) 
    gf_min_n = 0;
  } 
  else if (prevn + yoff < gf_min_n) 
  gf_min_n = prevn + yoff;
  {
    gf_buf[gf_ptr] = 69;
    incr (gf_ptr);
    if (gf_ptr == gf_limit) 
    gf_swap ();
  } 
  gf_prev_ptr = gf_offset + gf_ptr;
  incr (total_chars);
  print_char (93);
  fflush (stdout);
  if (internal[11] > 0) 
  print_edges (1057 , true , xoff , yoff);
} 
void 
ztryeq (halfword l , halfword r) 
{
  /* 30 31 */ halfword p;
  unsigned char t;
  halfword q;
  halfword pp;
  unsigned char tt;
  boolean copied;
  t = mem[l].hhfield.b0;
  if (t == 16) 
  {
    t = 17;
    p = constdependency (- (integer) mem[l + 1].cint);
    q = p;
  } 
  else if (t == 19) 
  {
    t = 17;
    p = singledependency (l);
    mem[p + 1].cint = - (integer) mem[p + 1].cint;
    q = dep_final;
  } 
  else {
      
    p = mem[l + 1].hhfield.v.RH;
    q = p;
    while (true) {
	
      mem[q + 1].cint = - (integer) mem[q + 1].cint;
      if (mem[q].hhfield.lhfield == 0) 
      goto done;
      q = mem[q].hhfield.v.RH;
    } 
    done: mem[mem[l + 1].hhfield.lhfield].hhfield.v.RH = mem[q]
    .hhfield.v.RH;
    mem[mem[q].hhfield.v.RH + 1].hhfield.lhfield = mem[l + 1]
    .hhfield.lhfield;
    mem[l].hhfield.b0 = 16;
  } 
  if (r == 0) {
      
    if (cur_type == 16) 
    {
      mem[q + 1].cint = mem[q + 1].cint + cur_exp;
      goto done1;
    } 
    else {
	
      tt = cur_type;
      if (tt == 19) 
      pp = singledependency (cur_exp);
      else pp = mem[cur_exp + 1].hhfield.v.RH;
    } 
  } 
  else if (mem[r].hhfield.b0 == 16) 
  {
    mem[q + 1].cint = mem[q + 1].cint + mem[r + 1].cint;
    goto done1;
  } 
  else {
      
    tt = mem[r].hhfield.b0;
    if (tt == 19) 
    pp = singledependency (r);
    else pp = mem[r + 1].hhfield.v.RH;
  } 
  if (tt != 19) 
  copied = false;
  else {
      
    copied = true;
    tt = 17;
  } 
  watch_coefs = false;
  if (t == tt) 
  p = pplusq (p , pp , t);
  else if (t == 18) 
  p = p_plus_fq (p , 65536L , pp , 18 , 17);
  else {
      
    q = p;
    while (mem[q].hhfield.lhfield != 0) {
	
      mem[q + 1].cint = roundfraction (mem[q + 1].cint);
      q = mem[q].hhfield.v.RH;
    } 
    t = 18;
    p = pplusq (p , pp , t);
  } 
  watch_coefs = true;
  if (copied) 
  flush_node_list (pp);
  done1:;
  if (mem[p].hhfield.lhfield == 0) 
  {
    if (abs (mem[p + 1].cint) > 64) 
    {
      {
	if (interaction == 3) 
	;
	if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
	{
	  print_nl (261);
	  print (fullsourcefilenamestack[in_open]);
	  print (58);
	  print_int (line);
	  print (262);
	  print (897);
	} 
	else {
	    
	  print_nl (263);
	  print (897);
	} 
      } 
      print (899);
      print_scaled (mem[p + 1].cint);
      print_char (41);
      {
	help_ptr = 2;
	help_line[1] = 898;
	help_line[0] = 896;
      } 
      put_get_error ();
    } 
    else if (r == 0) 
    {
      {
	if (interaction == 3) 
	;
	if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
	{
	  print_nl (261);
	  print (fullsourcefilenamestack[in_open]);
	  print (58);
	  print_int (line);
	  print (262);
	  print (600);
	} 
	else {
	    
	  print_nl (263);
	  print (600);
	} 
      } 
      {
	help_ptr = 2;
	help_line[1] = 601;
	help_line[0] = 602;
      } 
      put_get_error ();
    } 
    free_node (p , 2);
  } 
  else {
      
    lineareq (p , t);
    if (r == 0) {
	
      if (cur_type != 16) {
	  
	if (mem[cur_exp].hhfield.b0 == 16) 
	{
	  pp = cur_exp;
	  cur_exp = mem[cur_exp + 1].cint;
	  cur_type = 16;
	  free_node (pp , 2);
	} 
      } 
    } 
  } 
} 
void 
zmakeeq (halfword lhs) 
{
  /* 20 30 45 */ small_number t;
  integer v;
  halfword p, q;
  lab20: t = mem[lhs].hhfield.b0;
  if (t <= 14) 
  v = mem[lhs + 1].cint;
  switch (t) 
  {case 2 : 
  case 4 : 
  case 6 : 
  case 9 : 
  case 11 : 
    if (cur_type == t + 1) 
    {
      nonlineareq (v , cur_exp , false);
      unstash_cur_exp (cur_exp);
      goto done;
    } 
    else if (cur_type == t) 
    {
      if (cur_type <= 4) 
      {
	if (cur_type == 4) 
	{
	  if (str_vs_str (v , cur_exp) != 0) 
	  goto not_found;
	} 
	else if (v != cur_exp) 
	goto not_found;
	{
	  {
	    if (interaction == 3) 
	;
	    if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
	    {
	      print_nl (261);
	      print (fullsourcefilenamestack[in_open]);
	      print (58);
	      print_int (line);
	      print (262);
	      print (600);
	    } 
	    else {
		
	      print_nl (263);
	      print (600);
	    } 
	  } 
	  {
	    help_ptr = 2;
	    help_line[1] = 601;
	    help_line[0] = 602;
	  } 
	  put_get_error ();
	} 
	goto done;
      } 
      {
	if (interaction == 3) 
	;
	if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
	{
	  print_nl (261);
	  print (fullsourcefilenamestack[in_open]);
	  print (58);
	  print_int (line);
	  print (262);
	  print (894);
	} 
	else {
	    
	  print_nl (263);
	  print (894);
	} 
      } 
      {
	help_ptr = 2;
	help_line[1] = 895;
	help_line[0] = 896;
      } 
      put_get_error ();
      goto done;
      not_found: {
	  
	if (interaction == 3) 
	;
	if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
	{
	  print_nl (261);
	  print (fullsourcefilenamestack[in_open]);
	  print (58);
	  print_int (line);
	  print (262);
	  print (897);
	} 
	else {
	    
	  print_nl (263);
	  print (897);
	} 
      } 
      {
	help_ptr = 2;
	help_line[1] = 898;
	help_line[0] = 896;
      } 
      put_get_error ();
      goto done;
    } 
    break;
  case 3 : 
  case 5 : 
  case 7 : 
  case 12 : 
  case 10 : 
    if (cur_type == t - 1) 
    {
      nonlineareq (cur_exp , lhs , true);
      goto done;
    } 
    else if (cur_type == t) 
    {
      ringmerge (lhs , cur_exp);
      goto done;
    } 
    else if (cur_type == 14) {
	
      if (t == 10) 
      {
	pairtopath ();
	goto lab20;
      } 
    } 
    break;
  case 13 : 
  case 14 : 
    if (cur_type == t) 
    {
      p = v + big_node_size[t];
      q = mem[cur_exp + 1].cint + big_node_size[t];
      do {
	  p = p - 2;
	q = q - 2;
	tryeq (p , q);
      } while (!(p == v));
      goto done;
    } 
    break;
  case 16 : 
  case 17 : 
  case 18 : 
  case 19 : 
    if (cur_type >= 16) 
    {
      tryeq (lhs , 0);
      goto done;
    } 
    break;
  case 1 : 
;
    break;
  } 
  disp_err (lhs , 261);
  disp_err (0 , 891);
  if (mem[lhs].hhfield.b0 <= 14) 
  print_type (mem[lhs].hhfield.b0);
  else print (340);
  print_char (61);
  if (cur_type <= 14) 
  print_type (cur_type);
  else print (340);
  print_char (41);
  {
    help_ptr = 2;
    help_line[1] = 892;
    help_line[0] = 893;
  } 
  put_get_error ();
  done: {
      
    if (arith_error) 
    clear_arith ();
  } 
  recycle_value (lhs);
  free_node (lhs , 2);
} 
void 
doequation (void) 
{
  halfword lhs;
  halfword p;
  lhs = stash_cur_exp ();
  getxnext ();
  var_flag = 77;
  scan_expression ();
  if (cur_cmd == 51) 
  doequation ();
  else if (cur_cmd == 77) 
  doassignment ();
  if (internal[7] > 131072L) 
  {
    begin_diagnostic ();
    print_nl (850);
    print_exp (lhs , 0);
    print (886);
    print_exp (0 , 0);
    print (842);
    end_diagnostic (false);
  } 
  if (cur_type == 10) {
      
    if (mem[lhs].hhfield.b0 == 14) 
    {
      p = stash_cur_exp ();
      unstash_cur_exp (lhs);
      lhs = p;
    } 
  } 
  makeeq (lhs);
} 
void 
doassignment (void) 
{
  halfword lhs;
  halfword p;
  halfword q;
  if (cur_type != 20) 
  {
    disp_err (0 , 883);
    {
      help_ptr = 2;
      help_line[1] = 884;
      help_line[0] = 885;
    } 
    error ();
    doequation ();
  } 
  else {
      
    lhs = cur_exp;
    cur_type = 1;
    getxnext ();
    var_flag = 77;
    scan_expression ();
    if (cur_cmd == 51) 
    doequation ();
    else if (cur_cmd == 77) 
    doassignment ();
    if (internal[7] > 131072L) 
    {
      begin_diagnostic ();
      print_nl (123);
      if (mem[lhs].hhfield.lhfield > 9769) 
      slow_print (int_name[mem[lhs].hhfield.lhfield - (9769)]);
      else show_token_list (lhs , 0 , 1000 , 0);
      print (461);
      print_exp (0 , 0);
      print_char (125);
      end_diagnostic (false);
    } 
    if (mem[lhs].hhfield.lhfield > 9769) {
	
      if (cur_type == 16) 
      internal[mem[lhs].hhfield.lhfield - (9769)] = cur_exp;
      else {
	  
	disp_err (0 , 887);
	slow_print (int_name[mem[lhs].hhfield.lhfield - (9769)]);
	print (888);
	{
	  help_ptr = 2;
	  help_line[1] = 889;
	  help_line[0] = 890;
	} 
	put_get_error ();
      } 
    } 
    else {
	
      p = find_variable (lhs);
      if (p != 0) 
      {
	q = stash_cur_exp ();
	cur_type = undtype (p);
	recycle_value (p);
	mem[p].hhfield.b0 = cur_type;
	mem[p + 1].cint = 0;
	makeexpcopy (p);
	p = stash_cur_exp ();
	unstash_cur_exp (q);
	makeeq (p);
      } 
      else {
	  
	obliterated (lhs);
	put_get_error ();
      } 
    } 
    flush_node_list (lhs);
  } 
} 
void 
dotypedeclaration (void) 
{
  small_number t;
  halfword p;
  halfword q;
  if (cur_mod >= 13) 
  t = cur_mod;
  else t = cur_mod + 1;
  do {
      p = scandeclaredvariable ();
    flushvariable (eqtb[mem[p].hhfield.lhfield].v.RH , mem[p]
    .hhfield.v.RH , false);
    q = find_variable (p);
    if (q != 0) 
    {
      mem[q].hhfield.b0 = t;
      mem[q + 1].cint = 0;
    } 
    else {
	
      {
	if (interaction == 3) 
	;
	if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
	{
	  print_nl (261);
	  print (fullsourcefilenamestack[in_open]);
	  print (58);
	  print_int (line);
	  print (262);
	  print (900);
	} 
	else {
	    
	  print_nl (263);
	  print (900);
	} 
      } 
      {
	help_ptr = 2;
	help_line[1] = 901;
	help_line[0] = 902;
      } 
      put_get_error ();
    } 
    flush_list (p);
    if (cur_cmd < 82) 
    {
      {
	if (interaction == 3) 
	;
	if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
	{
	  print_nl (261);
	  print (fullsourcefilenamestack[in_open]);
	  print (58);
	  print_int (line);
	  print (262);
	  print (903);
	} 
	else {
	    
	  print_nl (263);
	  print (903);
	} 
      } 
      {
	help_ptr = 5;
	help_line[4] = 904;
	help_line[3] = 905;
	help_line[2] = 906;
	help_line[1] = 907;
	help_line[0] = 908;
      } 
      if (cur_cmd == 42) 
      help_line[2] = 909;
      put_get_error ();
      scanner_status = 2;
      do {
	  getnext ();
	if (cur_cmd == 39) 
	{
	  if (str_ref[cur_mod]< 127) {
	      
	    if (str_ref[cur_mod] > 1) 
	    decr (str_ref[cur_mod]);
	    else flush_string (cur_mod);
	  } 
	} 
      } while (!(cur_cmd >= 82));
      scanner_status = 0;
    } 
  } while (!(cur_cmd > 82));
} 
void 
dorandomseed (void) 
{
  getxnext ();
  if (cur_cmd != 77) 
  {
    missing_err (461);
    {
      help_ptr = 1;
      help_line[0] = 914;
    } 
    backerror ();
  } 
  getxnext ();
  scan_expression ();
  if (cur_type != 16) 
  {
    disp_err (0 , 915);
    {
      help_ptr = 2;
      help_line[1] = 916;
      help_line[0] = 917;
    } 
    put_get_flush_error (0);
  } 
  else {
      
    init_randoms (cur_exp);
    if (selector >= 2) 
    {
      old_setting = selector;
      selector = 2;
      print_nl (918);
      print_scaled (cur_exp);
      print_char (125);
      print_nl (261);
      selector = old_setting;
    } 
  } 
} 
void 
doprotection (void) 
{
  unsigned char m;
  halfword t;
  m = cur_mod;
  do {
      getsymbol ();
    t = eqtb[cur_sym].lhfield;
    if (m == 0) 
    {
      if (t >= 86) 
      eqtb[cur_sym].lhfield = t - 86;
    } 
    else if (t < 86) 
    eqtb[cur_sym].lhfield = t + 86;
    getxnext ();
  } while (!(cur_cmd != 82));
} 
void 
defdelims (void) 
{
  halfword ldelim, rdelim;
  getclearsymbol ();
  ldelim = cur_sym;
  getclearsymbol ();
  rdelim = cur_sym;
  eqtb[ldelim].lhfield = 31;
  eqtb[ldelim].v.RH = rdelim;
  eqtb[rdelim].lhfield = 62;
  eqtb[rdelim].v.RH = ldelim;
  getxnext ();
} 
void 
dointerim (void) 
{
  getxnext ();
  if (cur_cmd != 40) 
  {
    {
      if (interaction == 3) 
;
      if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[in_open]);
	print (58);
	print_int (line);
	print (262);
	print (924);
      } 
      else {
	  
	print_nl (263);
	print (924);
      } 
    } 
    if (cur_sym == 0) 
    print (929);
    else slow_print (hash[cur_sym].v.RH);
    print (930);
    {
      help_ptr = 1;
      help_line[0] = 931;
    } 
    backerror ();
  } 
  else {
      
    saveinternal (cur_mod);
    backinput ();
  } 
  dostatement ();
} 
void 
dolet (void) 
{
  halfword l;
  getsymbol ();
  l = cur_sym;
  getxnext ();
  if (cur_cmd != 51) {
      
    if (cur_cmd != 77) 
    {
      missing_err (61);
      {
	help_ptr = 3;
	help_line[2] = 932;
	help_line[1] = 673;
	help_line[0] = 933;
      } 
      backerror ();
    } 
  } 
  getsymbol ();
  switch (cur_cmd) 
  {case 10 : 
  case 53 : 
  case 44 : 
  case 49 : 
    incr (mem[cur_mod].hhfield.lhfield);
    break;
    default: 
;
    break;
  } 
  clearsymbol (l , false);
  eqtb[l].lhfield = cur_cmd;
  if (cur_cmd == 41) 
  eqtb[l].v.RH = 0;
  else eqtb[l].v.RH = cur_mod;
  getxnext ();
} 
void 
donewinternal (void) 
{
  do {
      if (int_ptr == max_internal) 
    overflow (934 , max_internal);
    getclearsymbol ();
    incr (int_ptr);
    eqtb[cur_sym].lhfield = 40;
    eqtb[cur_sym].v.RH = int_ptr;
    int_name[int_ptr] = hash[cur_sym].v.RH;
    internal[int_ptr] = 0;
    getxnext ();
  } while (!(cur_cmd != 82));
} 
void 
doshow (void) 
{
  do {
      getxnext ();
    scan_expression ();
    print_nl (765);
    print_exp (0 , 2);
    flush_cur_exp (0);
  } while (!(cur_cmd != 82));
} 
void 
disptoken (void) 
{
  print_nl (940);
  if (cur_sym == 0) 
  {
    if (cur_cmd == 42) 
    print_scaled (cur_mod);
    else if (cur_cmd == 38) 
    {
      g_pointer = cur_mod;
      print_capsule ();
    } 
    else {
	
      print_char (34);
      slow_print (cur_mod);
      print_char (34);
      {
	if (str_ref[cur_mod]< 127) {
	    
	  if (str_ref[cur_mod] > 1) 
	  decr (str_ref[cur_mod]);
	  else flush_string (cur_mod);
	} 
      } 
    } 
  } 
  else {
      
    slow_print (hash[cur_sym].v.RH);
    print_char (61);
    if (eqtb[cur_sym].lhfield >= 86) 
    print (941);
    print_cmd_mod (cur_cmd , cur_mod);
    if (cur_cmd == 10) 
    {
      print_ln ();
      show_macro (cur_mod , 0 , 100000L);
    } 
  } 
} 
void 
doshowtoken (void) 
{
  do {
      getnext ();
    disptoken ();
    getxnext ();
  } while (!(cur_cmd != 82));
} 
void 
doshowstats (void) 
{
  print_nl (950);
	;
#ifdef STAT
  print_int (var_used);
  print_char (38);
  print_int (dyn_used);
  if (false) 
#endif /* STAT */
  print (357);
  print (558);
  print_int (hi_mem_min - lo_mem_max - 1);
  print (951);
  print_ln ();
  print_nl (952);
  print_int (str_ptr - init_str_ptr);
  print_char (38);
  print_int (pool_ptr - init_pool_ptr);
  print (558);
  print_int (max_strings - max_str_ptr);
  print_char (38);
  print_int (pool_size - max_pool_ptr);
  print (951);
  print_ln ();
  getxnext ();
} 
void 
zdispvar (halfword p) 
{
  halfword q;
  integer n;
  if (mem[p].hhfield.b0 == 21) 
  {
    q = mem[p + 1].hhfield.lhfield;
    do {
	dispvar (q);
      q = mem[q].hhfield.v.RH;
    } while (!(q == 17));
    q = mem[p + 1].hhfield.v.RH;
    while (mem[q].hhfield.b1 == 3) {
	
      dispvar (q);
      q = mem[q].hhfield.v.RH;
    } 
  } 
  else if (mem[p].hhfield.b0 >= 22) 
  {
    print_nl (261);
    print_variable_name (p);
    if (mem[p].hhfield.b0 > 22) 
    print (665);
    print (953);
    if (file_offset >= maxprintline - 20) 
    n = 5;
    else n = maxprintline - file_offset - 15;
    show_macro (mem[p + 1].cint , 0 , n);
  } 
  else if (mem[p].hhfield.b0 != 0) 
  {
    print_nl (261);
    print_variable_name (p);
    print_char (61);
    print_exp (p , 0);
  } 
} 
void 
doshowvar (void) 
{
  /* 30 */ do {
      getnext ();
    if (cur_sym > 0) {
	
      if (cur_sym <= 9769) {
	  
	if (cur_cmd == 41) {
	    
	  if (cur_mod != 0) 
	  {
	    dispvar (cur_mod);
	    goto done;
	  } 
	} 
      } 
    } 
    disptoken ();
    done: getxnext ();
  } while (!(cur_cmd != 82));
} 
void 
doshowdependencies (void) 
{
  halfword p;
  p = mem[13].hhfield.v.RH;
  while (p != 13) {
      
    if (interesting (p)) 
    {
      print_nl (261);
      print_variable_name (p);
      if (mem[p].hhfield.b0 == 17) 
      print_char (61);
      else print (768);
      print_dependency (mem[p + 1].hhfield.v.RH , mem[p].hhfield.b0 
   );
    } 
    p = mem[p + 1].hhfield.v.RH;
    while (mem[p].hhfield.lhfield != 0) p = mem[p].hhfield.v.RH;
    p = mem[p].hhfield.v.RH;
  } 
  getxnext ();
} 
void 
doshowwhatever (void) 
{
  if (interaction == 3) 
;
  switch (cur_mod) 
  {case 0 : 
    doshowtoken ();
    break;
  case 1 : 
    doshowstats ();
    break;
  case 2 : 
    doshow ();
    break;
  case 3 : 
    doshowvar ();
    break;
  case 4 : 
    doshowdependencies ();
    break;
  } 
  if (internal[32] > 0) 
  {
    {
      if (interaction == 3) 
;
      if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[in_open]);
	print (58);
	print_int (line);
	print (262);
	print (954);
      } 
      else {
	  
	print_nl (263);
	print (954);
      } 
    } 
    if (interaction < 3) 
    {
      help_ptr = 0;
      decr (error_count);
    } 
    else {
	
      help_ptr = 1;
      help_line[0] = 955;
    } 
    if (cur_cmd == 83) 
    error ();
    else put_get_error ();
  } 
} 
boolean 
scanwith (void) 
{
  register boolean Result; small_number t;
  boolean result;
  t = cur_mod;
  cur_type = 1;
  getxnext ();
  scan_expression ();
  result = false;
  if (cur_type != t) 
  {
    disp_err (0 , 963);
    {
      help_ptr = 2;
      help_line[1] = 964;
      help_line[0] = 965;
    } 
    if (t == 6) 
    help_line[1] = 966;
    put_get_flush_error (0);
  } 
  else if (cur_type == 6) 
  result = true;
  else {
      
    cur_exp = roundunscaled (cur_exp);
    if ((abs (cur_exp) < 4) && (cur_exp != 0)) 
    result = true;
    else {
	
      {
	if (interaction == 3) 
	;
	if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
	{
	  print_nl (261);
	  print (fullsourcefilenamestack[in_open]);
	  print (58);
	  print_int (line);
	  print (262);
	  print (967);
	} 
	else {
	    
	  print_nl (263);
	  print (967);
	} 
      } 
      {
	help_ptr = 1;
	help_line[0] = 965;
      } 
      put_get_flush_error (0);
    } 
  } 
  Result = result;
  return Result;
} 
void 
zfindedgesvar (halfword t) 
{
  halfword p;
  p = find_variable (t);
  cur_edges = 0;
  if (p == 0) 
  {
    obliterated (t);
    put_get_error ();
  } 
  else if (mem[p].hhfield.b0 != 11) 
  {
    {
      if (interaction == 3) 
;
      if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[in_open]);
	print (58);
	print_int (line);
	print (262);
	print (790);
      } 
      else {
	  
	print_nl (263);
	print (790);
      } 
    } 
    show_token_list (t , 0 , 1000 , 0);
    print (968);
    print_type (mem[p].hhfield.b0);
    print_char (41);
    {
      help_ptr = 2;
      help_line[1] = 969;
      help_line[0] = 970;
    } 
    put_get_error ();
  } 
  else cur_edges = mem[p + 1].cint;
  flush_node_list (t);
} 
void 
doaddto (void) 
{
  /* 30 45 */ halfword lhs, rhs;
  integer w;
  halfword p;
  halfword q;
  unsigned char addtotype;
  getxnext ();
  var_flag = 68;
  scan_primary ();
  if (cur_type != 20) 
  {
    disp_err (0 , 971);
    {
      help_ptr = 4;
      help_line[3] = 972;
      help_line[2] = 973;
      help_line[1] = 974;
      help_line[0] = 970;
    } 
    put_get_flush_error (0);
  } 
  else {
      
    lhs = cur_exp;
    addtotype = cur_mod;
    cur_type = 1;
    getxnext ();
    scan_expression ();
    if (addtotype == 2) 
    {
      findedgesvar (lhs);
      if (cur_edges == 0) 
      flush_cur_exp (0);
      else if (cur_type != 11) 
      {
	disp_err (0 , 975);
	{
	  help_ptr = 2;
	  help_line[1] = 976;
	  help_line[0] = 970;
	} 
	put_get_flush_error (0);
      } 
      else {
	  
	merge_edges (cur_exp);
	flush_cur_exp (0);
      } 
    } 
    else {
	
      if (cur_type == 14) 
      pairtopath ();
      if (cur_type != 9) 
      {
	disp_err (0 , 975);
	{
	  help_ptr = 2;
	  help_line[1] = 977;
	  help_line[0] = 970;
	} 
	put_get_flush_error (0);
	flush_token_list (lhs);
      } 
      else {
	  
	rhs = cur_exp;
	w = 1;
	cur_pen = 3;
	while (cur_cmd == 66) if (scanwith ()) {
	    
	  if (cur_type == 16) 
	  w = cur_exp;
	  else {
	      
	    if (mem[cur_pen].hhfield.lhfield == 0) 
	    toss_pen (cur_pen);
	    else decr (mem[cur_pen].hhfield.lhfield);
	    cur_pen = cur_exp;
	  } 
	} 
	findedgesvar (lhs);
	if (cur_edges == 0) 
	toss_knot_list (rhs);
	else {
	    
	  lhs = 0;
	  cur_path_type = addtotype;
	  if (mem[rhs].hhfield.b0 == 0) {
	      
	    if (cur_path_type == 0) {
		
	      if (mem[rhs].hhfield.v.RH == rhs) 
	      {
		mem[rhs + 5].cint = mem[rhs + 1].cint;
		mem[rhs + 6].cint = mem[rhs + 2].cint;
		mem[rhs + 3].cint = mem[rhs + 1].cint;
		mem[rhs + 4].cint = mem[rhs + 2].cint;
		mem[rhs].hhfield.b0 = 1;
		mem[rhs].hhfield.b1 = 1;
	      } 
	      else {
		  
		p = htapypoc (rhs);
		q = mem[p].hhfield.v.RH;
		mem[path_tail + 5].cint = mem[q + 5].cint;
		mem[path_tail + 6].cint = mem[q + 6].cint;
		mem[path_tail].hhfield.b1 = mem[q].hhfield.b1;
		mem[path_tail].hhfield.v.RH = mem[q].hhfield.v.RH;
		free_node (q , 7);
		mem[p + 5].cint = mem[rhs + 5].cint;
		mem[p + 6].cint = mem[rhs + 6].cint;
		mem[p].hhfield.b1 = mem[rhs].hhfield.b1;
		mem[p].hhfield.v.RH = mem[rhs].hhfield.v.RH;
		free_node (rhs , 7);
		rhs = p;
	      } 
	    } 
	    else {
		
	      {
		if (interaction == 3) 
		;
		if ((filelineerrorstylep && !(cur_input .name_field == 0)) 
		) 
		{
		  print_nl (261);
		  print (fullsourcefilenamestack[in_open]);
		  print (58);
		  print_int (line);
		  print (262);
		  print (978);
		} 
		else {
		    
		  print_nl (263);
		  print (978);
		} 
	      } 
	      {
		help_ptr = 2;
		help_line[1] = 979;
		help_line[0] = 970;
	      } 
	      put_get_error ();
	      toss_knot_list (rhs);
	      goto not_found;
	    } 
	  } 
	  else if (cur_path_type == 0) 
	  lhs = htapypoc (rhs);
	  cur_wt = w;
	  rhs = makespec (rhs , mem[cur_pen + 9].cint , internal[5]);
	  if (turning_number <= 0) {
	      
	    if (cur_path_type != 0) {
		
	      if (internal[39] > 0) {
		  
		if ((turning_number < 0) && (mem[cur_pen].hhfield.v.RH 
		== 0)) 
		cur_wt = - (integer) cur_wt;
		else {
		    
		  if (turning_number == 0) {
		      
		    if ((internal[39]<= 65536L) && (mem[cur_pen]
		    .hhfield.v.RH == 0)) 
		    goto done;
		    else printstrange (980);
		  } 
		  else printstrange (981);
		  {
		    help_ptr = 3;
		    help_line[2] = 982;
		    help_line[1] = 983;
		    help_line[0] = 984;
		  } 
		  put_get_error ();
		} 
	      } 
	    } 
	  } 
	  done:;
	  if (mem[cur_pen + 9].cint == 0) 
	  fillspec (rhs);
	  else fillenvelope (rhs);
	  if (lhs != 0) 
	  {
	    rev_turns = true;
	    lhs = makespec (lhs , mem[cur_pen + 9].cint , internal[5]) 
	;
	    rev_turns = false;
	    if (mem[cur_pen + 9].cint == 0) 
	    fillspec (lhs);
	    else fillenvelope (lhs);
	  } 
	  not_found:;
	} 
	if (mem[cur_pen].hhfield.lhfield == 0) 
	toss_pen (cur_pen);
	else decr (mem[cur_pen].hhfield.lhfield);
      } 
    } 
  } 
} 
scaled 
ztfmcheck (small_number m) 
{
  register scaled Result; if (abs (internal[m]) >= 134217728L) 
  {
    {
      if (interaction == 3) 
;
      if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[in_open]);
	print (58);
	print_int (line);
	print (262);
	print (1001);
      } 
      else {
	  
	print_nl (263);
	print (1001);
      } 
    } 
    print (int_name[m]);
    print (1002);
    {
      help_ptr = 1;
      help_line[0] = 1003;
    } 
    put_get_error ();
    if (internal[m] > 0) 
    Result = 134217727L;
    else Result = -134217727L;
  } 
  else Result = internal[m];
  return Result;
} 
void 
doshipout (void) 
{
  /* 10 */ integer c;
  getxnext ();
  var_flag = 83;
  scan_expression ();
  if (cur_type != 20) {
      
    if (cur_type == 11) 
    cur_edges = cur_exp;
    else {
	
      {
	disp_err (0 , 971);
	{
	  help_ptr = 4;
	  help_line[3] = 972;
	  help_line[2] = 973;
	  help_line[1] = 974;
	  help_line[0] = 970;
	} 
	put_get_flush_error (0);
      } 
      goto lab10;
    } 
  } 
  else {
      
    findedgesvar (cur_exp);
    cur_type = 1;
  } 
  if (cur_edges != 0) 
  {
    c = roundunscaled (internal[18]) % 256;
    if (c < 0) 
    c = c + 256;
    if (c < bc) 
    bc = c;
    if (c > ec) 
    ec = c;
    char_exists[c] = true;
    gf_dx[c] = internal[24];
    gf_dy[c] = internal[25];
    tfm_width[c] = tfmcheck (20);
    tfm_height[c] = tfmcheck (21);
    tfm_depth[c] = tfmcheck (22);
    tfm_ital_corr[c] = tfmcheck (23);
    if (internal[34] >= 0) 
    shipout (c);
  } 
  flush_cur_exp (0);
  lab10:;
} 
void 
dodisplay (void) 
{
  /* 45 50 10 */ halfword e;
  getxnext ();
  var_flag = 73;
  scan_primary ();
  if (cur_type != 20) 
  {
    disp_err (0 , 971);
    {
      help_ptr = 4;
      help_line[3] = 972;
      help_line[2] = 973;
      help_line[1] = 974;
      help_line[0] = 970;
    } 
    put_get_flush_error (0);
  } 
  else {
      
    e = cur_exp;
    cur_type = 1;
    getxnext ();
    scan_expression ();
    if (cur_type != 16) 
    goto common_ending;
    cur_exp = roundunscaled (cur_exp);
    if (cur_exp < 0) 
    goto not_found;
    if (cur_exp > 15) 
    goto not_found;
    if (!window_open[cur_exp]) 
    goto not_found;
    findedgesvar (e);
    if (cur_edges != 0) 
    dispedges (cur_exp);
    goto lab10;
    not_found: cur_exp = cur_exp * 65536L;
    common_ending: disp_err (0 , 985);
    {
      help_ptr = 1;
      help_line[0] = 986;
    } 
    put_get_flush_error (0);
    flush_token_list (e);
  } 
  lab10:;
} 
boolean 
zgetpair (commandcode c) 
{
  register boolean Result; halfword p;
  boolean b;
  if (cur_cmd != c) 
  Result = false;
  else {
      
    getxnext ();
    scan_expression ();
    if (nicepair (cur_exp , cur_type)) 
    {
      p = mem[cur_exp + 1].cint;
      cur_x = mem[p + 1].cint;
      cur_y = mem[p + 3].cint;
      b = true;
    } 
    else b = false;
    flush_cur_exp (0);
    Result = b;
  } 
  return Result;
} 
void 
doopen_window (void) 
{
  /* 45 10 */ integer k;
  scaled r0, c0, r1, c1;
  getxnext ();
  scan_expression ();
  if (cur_type != 16) 
  goto not_found;
  k = roundunscaled (cur_exp);
  if (k < 0) 
  goto not_found;
  if (k > 15) 
  goto not_found;
  if (!getpair (70)) 
  goto not_found;
  r0 = cur_x;
  c0 = cur_y;
  if (!getpair (71)) 
  goto not_found;
  r1 = cur_x;
  c1 = cur_y;
  if (!getpair (72)) 
  goto not_found;
  openawindow (k , r0 , c0 , r1 , c1 , cur_x , cur_y);
  goto lab10;
  not_found: {
      
    if (interaction == 3) 
;
    if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
    {
      print_nl (261);
      print (fullsourcefilenamestack[in_open]);
      print (58);
      print_int (line);
      print (262);
      print (987);
    } 
    else {
	
      print_nl (263);
      print (987);
    } 
  } 
  {
    help_ptr = 2;
    help_line[1] = 988;
    help_line[0] = 989;
  } 
  put_get_error ();
  lab10:;
} 
void 
docull (void) 
{
  /* 45 10 */ halfword e;
  unsigned char keeping;
  integer w, win, wout;
  w = 1;
  getxnext ();
  var_flag = 67;
  scan_primary ();
  if (cur_type != 20) 
  {
    disp_err (0 , 971);
    {
      help_ptr = 4;
      help_line[3] = 972;
      help_line[2] = 973;
      help_line[1] = 974;
      help_line[0] = 970;
    } 
    put_get_flush_error (0);
  } 
  else {
      
    e = cur_exp;
    cur_type = 1;
    keeping = cur_mod;
    if (!getpair (67)) 
    goto not_found;
    while ((cur_cmd == 66) && (cur_mod == 16)) if (scanwith ()) 
    w = cur_exp;
    if (cur_x > cur_y) 
    goto not_found;
    if (keeping == 0) 
    {
      if ((cur_x > 0) || (cur_y < 0)) 
      goto not_found;
      wout = w;
      win = 0;
    } 
    else {
	
      if ((cur_x <= 0) && (cur_y >= 0)) 
      goto not_found;
      wout = 0;
      win = w;
    } 
    findedgesvar (e);
    if (cur_edges != 0) 
    cull_edges (floorunscaled (cur_x + 65535L) , floorunscaled (cur_y) , 
    wout , win);
    goto lab10;
    not_found: {
	
      if (interaction == 3) 
;
      if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[in_open]);
	print (58);
	print_int (line);
	print (262);
	print (990);
      } 
      else {
	  
	print_nl (263);
	print (990);
      } 
    } 
    {
      help_ptr = 1;
      help_line[0] = 991;
    } 
    put_get_error ();
    flush_token_list (e);
  } 
  lab10:;
} 
void 
domessage (void) 
{
  unsigned char m;
  m = cur_mod;
  getxnext ();
  scan_expression ();
  if (cur_type != 4) 
  {
    disp_err (0 , 700);
    {
      help_ptr = 1;
      help_line[0] = 995;
    } 
    put_get_error ();
  } 
  else switch (m) 
  {case 0 : 
    {
      print_nl (261);
      slow_print (cur_exp);
    } 
    break;
  case 1 : 
    {
      {
	if (interaction == 3) 
	;
	if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
	{
	  print_nl (261);
	  print (fullsourcefilenamestack[in_open]);
	  print (58);
	  print_int (line);
	  print (262);
	  print (261);
	} 
	else {
	    
	  print_nl (263);
	  print (261);
	} 
      } 
      slow_print (cur_exp);
      if (err_help != 0) 
      use_err_help = true;
      else if (long_help_seen) 
      {
	help_ptr = 1;
	help_line[0] = 996;
      } 
      else {
	  
	if (interaction < 3) 
	long_help_seen = true;
	{
	  help_ptr = 4;
	  help_line[3] = 997;
	  help_line[2] = 998;
	  help_line[1] = 999;
	  help_line[0] = 1000;
	} 
      } 
      put_get_error ();
      use_err_help = false;
    } 
    break;
  case 2 : 
    {
      if (err_help != 0) 
      {
	if (str_ref[err_help]< 127) {
	    
	  if (str_ref[err_help] > 1) 
	  decr (str_ref[err_help]);
	  else flush_string (err_help);
	} 
      } 
      if ((str_start[cur_exp + 1] - str_start[cur_exp]) == 0) 
      err_help = 0;
      else {
	  
	err_help = cur_exp;
	{
	  if (str_ref[err_help]< 127) 
	  incr (str_ref[err_help]);
	} 
      } 
    } 
    break;
  } 
  flush_cur_exp (0);
} 
eight_bits 
getcode (void) 
{
  /* 40 */ register eight_bits Result; integer c;
  getxnext ();
  scan_expression ();
  if (cur_type == 16) 
  {
    c = roundunscaled (cur_exp);
    if (c >= 0) {
	
      if (c < 256) 
      goto found;
    } 
  } 
  else if (cur_type == 4) {
      
    if ((str_start[cur_exp + 1] - str_start[cur_exp]) == 1) 
    {
      c = str_pool[str_start[cur_exp]];
      goto found;
    } 
  } 
  disp_err (0 , 1009);
  {
    help_ptr = 2;
    help_line[1] = 1010;
    help_line[0] = 1011;
  } 
  put_get_flush_error (0);
  c = 0;
  found: Result = c;
  return Result;
} 
void 
zsettag (halfword c , small_number t , halfword r) 
{
  if (char_tag[c] == 0) 
  {
    char_tag[c] = t;
    char_remainder[c] = r;
    if (t == 1) 
    {
      incr (label_ptr);
      label_loc[label_ptr] = r;
      label_char[label_ptr] = c;
    } 
  } 
  else {
      
    {
      if (interaction == 3) 
;
      if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[in_open]);
	print (58);
	print_int (line);
	print (262);
	print (1012);
      } 
      else {
	  
	print_nl (263);
	print (1012);
      } 
    } 
    if ((c > 32) && (c < 127)) 
    print (c);
    else if (c == 256) 
    print (1013);
    else {
	
      print (1014);
      print_int (c);
    } 
    print (1015);
    switch (char_tag[c]) 
    {case 1 : 
      print (1016);
      break;
    case 2 : 
      print (1017);
      break;
    case 3 : 
      print (1006);
      break;
    } 
    {
      help_ptr = 2;
      help_line[1] = 1018;
      help_line[0] = 970;
    } 
    put_get_error ();
  } 
} 
void 
dotfmcommand (void) 
{
  /* 22 30 */ short c, cc;
  integer k;
  integer j;
  switch (cur_mod) 
  {case 0 : 
    {
      c = getcode ();
      while (cur_cmd == 81) {
	  
	cc = getcode ();
	settag (c , 2 , cc);
	c = cc;
      } 
    } 
    break;
  case 1 : 
    {
      lk_started = false;
      lab22: getxnext ();
      if ((cur_cmd == 78) && lk_started) 
      {
	c = getcode ();
	if (nl - skip_table[c] > 128) 
	{
	  {
	    {
	      if (interaction == 3) 
	;
	      if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
	      {
		print_nl (261);
		print (fullsourcefilenamestack[in_open]);
		print (58);
		print_int (line);
		print (262);
		print (1035);
	      } 
	      else {
		  
		print_nl (263);
		print (1035);
	      } 
	    } 
	    {
	      help_ptr = 1;
	      help_line[0] = 1036;
	    } 
	    error ();
	    ll = skip_table[c];
	    do {
		lll = lig_kern[ll].b0;
	      lig_kern[ll].b0 = 128;
	      ll = ll - lll;
	    } while (!(lll == 0));
	  } 
	  skip_table[c] = lig_table_size;
	} 
	if (skip_table[c] == lig_table_size) 
	lig_kern[nl - 1].b0 = 0;
	else lig_kern[nl - 1].b0 = nl - skip_table[c] - 1;
	skip_table[c] = nl - 1;
	goto done;
      } 
      if (cur_cmd == 79) 
      {
	c = 256;
	cur_cmd = 81;
      } 
      else {
	  
	backinput ();
	c = getcode ();
      } 
      if ((cur_cmd == 81) || (cur_cmd == 80)) 
      {
	if (cur_cmd == 81) {
	    
	  if (c == 256) 
	  bch_label = nl;
	  else settag (c , 1 , nl);
	} 
	else if (skip_table[c]< lig_table_size) 
	{
	  ll = skip_table[c];
	  skip_table[c] = lig_table_size;
	  do {
	      lll = lig_kern[ll].b0;
	    if (nl - ll > 128) 
	    {
	      {
		{
		  if (interaction == 3) 
		;
		  if ((filelineerrorstylep && !(cur_input .name_field == 0) 
		)) 
		  {
		    print_nl (261);
		    print (fullsourcefilenamestack[in_open]);
		    print (58);
		    print_int (line);
		    print (262);
		    print (1035);
		  } 
		  else {
		      
		    print_nl (263);
		    print (1035);
		  } 
		} 
		{
		  help_ptr = 1;
		  help_line[0] = 1036;
		} 
		error ();
		ll = ll;
		do {
		    lll = lig_kern[ll].b0;
		  lig_kern[ll].b0 = 128;
		  ll = ll - lll;
		} while (!(lll == 0));
	      } 
	      goto lab22;
	    } 
	    lig_kern[ll].b0 = nl - ll - 1;
	    ll = ll - lll;
	  } while (!(lll == 0));
	} 
	goto lab22;
      } 
      if (cur_cmd == 76) 
      {
	lig_kern[nl].b1 = c;
	lig_kern[nl].b0 = 0;
	if (cur_mod < 128) 
	{
	  lig_kern[nl].b2 = cur_mod;
	  lig_kern[nl].b3 = getcode ();
	} 
	else {
	    
	  getxnext ();
	  scan_expression ();
	  if (cur_type != 16) 
	  {
	    disp_err (0 , 1037);
	    {
	      help_ptr = 2;
	      help_line[1] = 1038;
	      help_line[0] = 308;
	    } 
	    put_get_flush_error (0);
	  } 
	  kern[nk] = cur_exp;
	  k = 0;
	  while (kern[k]!= cur_exp) incr (k);
	  if (k == nk) 
	  {
	    if (nk == max_kerns) 
	    overflow (1034 , max_kerns);
	    incr (nk);
	  } 
	  lig_kern[nl].b2 = 128 + (k / 256);
	  lig_kern[nl].b3 = (k % 256);
	} 
	lk_started = true;
      } 
      else {
	  
	{
	  if (interaction == 3) 
	;
	  if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
	  {
	    print_nl (261);
	    print (fullsourcefilenamestack[in_open]);
	    print (58);
	    print_int (line);
	    print (262);
	    print (1023);
	  } 
	  else {
	      
	    print_nl (263);
	    print (1023);
	  } 
	} 
	{
	  help_ptr = 1;
	  help_line[0] = 1024;
	} 
	backerror ();
	lig_kern[nl].b1 = 0;
	lig_kern[nl].b2 = 0;
	lig_kern[nl].b3 = 0;
	lig_kern[nl].b0 = 129;
      } 
      if (nl == lig_table_size) 
      overflow (1025 , lig_table_size);
      incr (nl);
      if (cur_cmd == 82) 
      goto lab22;
      if (lig_kern[nl - 1].b0 < 128) 
      lig_kern[nl - 1].b0 = 128;
      done:;
    } 
    break;
  case 2 : 
    {
      if (ne == 256) 
      overflow (1006 , 256);
      c = getcode ();
      settag (c , 3 , ne);
      if (cur_cmd != 81) 
      {
	missing_err (58);
	{
	  help_ptr = 1;
	  help_line[0] = 1039;
	} 
	backerror ();
      } 
      exten[ne].b0 = getcode ();
      if (cur_cmd != 82) 
      {
	missing_err (44);
	{
	  help_ptr = 1;
	  help_line[0] = 1039;
	} 
	backerror ();
      } 
      exten[ne].b1 = getcode ();
      if (cur_cmd != 82) 
      {
	missing_err (44);
	{
	  help_ptr = 1;
	  help_line[0] = 1039;
	} 
	backerror ();
      } 
      exten[ne].b2 = getcode ();
      if (cur_cmd != 82) 
      {
	missing_err (44);
	{
	  help_ptr = 1;
	  help_line[0] = 1039;
	} 
	backerror ();
      } 
      exten[ne].b3 = getcode ();
      incr (ne);
    } 
    break;
  case 3 : 
  case 4 : 
    {
      c = cur_mod;
      getxnext ();
      scan_expression ();
      if ((cur_type != 16) || (cur_exp < 32768L)) 
      {
	disp_err (0 , 1019);
	{
	  help_ptr = 2;
	  help_line[1] = 1020;
	  help_line[0] = 1021;
	} 
	put_get_error ();
      } 
      else {
	  
	j = roundunscaled (cur_exp);
	if (cur_cmd != 81) 
	{
	  missing_err (58);
	  {
	    help_ptr = 1;
	    help_line[0] = 1022;
	  } 
	  backerror ();
	} 
	if (c == 3) 
	do {
	    if (j > header_size) 
	  overflow (1007 , header_size);
	  header_byte[j] = getcode ();
	  incr (j);
	} while (!(cur_cmd != 82));
	else do {
	    if (j > max_font_dimen) 
	  overflow (1008 , max_font_dimen);
	  while (j > np) {
	      
	    incr (np);
	    param[np] = 0;
	  } 
	  getxnext ();
	  scan_expression ();
	  if (cur_type != 16) 
	  {
	    disp_err (0 , 1040);
	    {
	      help_ptr = 1;
	      help_line[0] = 308;
	    } 
	    put_get_flush_error (0);
	  } 
	  param[j] = cur_exp;
	  incr (j);
	} while (!(cur_cmd != 82));
      } 
    } 
    break;
  } 
} 
void 
dospecial (void) 
{
  small_number m;
  m = cur_mod;
  getxnext ();
  scan_expression ();
  if (internal[34] >= 0) {
      
    if (cur_type != m) 
    {
      disp_err (0 , 1061);
      {
	help_ptr = 1;
	help_line[0] = 1062;
      } 
      put_get_error ();
    } 
    else {
	
      if (output_file_name == 0) 
      init_gf ();
      if (m == 4) 
      gfstring (cur_exp , 0);
      else {
	  
	{
	  gf_buf[gf_ptr] = 243;
	  incr (gf_ptr);
	  if (gf_ptr == gf_limit) 
	  gf_swap ();
	} 
	gffour (cur_exp);
      } 
    } 
  } 
  flush_cur_exp (0);
} 
void 
dostatement (void) 
{
  cur_type = 1;
  getxnext ();
  if (cur_cmd > 43) 
  {
    if (cur_cmd < 83) 
    {
      {
	if (interaction == 3) 
	;
	if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
	{
	  print_nl (261);
	  print (fullsourcefilenamestack[in_open]);
	  print (58);
	  print_int (line);
	  print (262);
	  print (869);
	} 
	else {
	    
	  print_nl (263);
	  print (869);
	} 
      } 
      print_cmd_mod (cur_cmd , cur_mod);
      print_char (39);
      {
	help_ptr = 5;
	help_line[4] = 870;
	help_line[3] = 871;
	help_line[2] = 872;
	help_line[1] = 873;
	help_line[0] = 874;
      } 
      backerror ();
      getxnext ();
    } 
  } 
  else if (cur_cmd > 30) 
  {
    var_flag = 77;
    scan_expression ();
    if (cur_cmd < 84) 
    {
      if (cur_cmd == 51) 
      doequation ();
      else if (cur_cmd == 77) 
      doassignment ();
      else if (cur_type == 4) 
      {
	if (internal[1] > 0) 
	{
	  print_nl (261);
	  slow_print (cur_exp);
	  fflush (stdout);
	} 
	if (internal[34] > 0) 
	{
	  if (output_file_name == 0) 
	  init_gf ();
	  gfstring (1063 , cur_exp);
	} 
      } 
      else if (cur_type != 1) 
      {
	disp_err (0 , 879);
	{
	  help_ptr = 3;
	  help_line[2] = 880;
	  help_line[1] = 881;
	  help_line[0] = 882;
	} 
	put_get_error ();
      } 
      flush_cur_exp (0);
      cur_type = 1;
    } 
  } 
  else {
      
    if (internal[7] > 0) 
    show_cmd_mod (cur_cmd , cur_mod);
    switch (cur_cmd) 
    {case 30 : 
      dotypedeclaration ();
      break;
    case 16 : 
      if (cur_mod > 2) 
      makeopdef ();
      else if (cur_mod > 0) 
      scandef ();
      break;
    case 24 : 
      dorandomseed ();
      break;
    case 23 : 
      {
	print_ln ();
	interaction = cur_mod;
	if (interaction == 0) 
	kpsemaketexdiscarderrors = 1;
	else kpsemaketexdiscarderrors = 0;
	if (interaction == 0) 
	selector = 0;
	else selector = 1;
	if (log_opened) 
	selector = selector + 2;
	getxnext ();
      } 
      break;
    case 21 : 
      doprotection ();
      break;
    case 27 : 
      defdelims ();
      break;
    case 12 : 
      do {
	  getsymbol ();
	savevariable (cur_sym);
	getxnext ();
      } while (!(cur_cmd != 82));
      break;
    case 13 : 
      dointerim ();
      break;
    case 14 : 
      dolet ();
      break;
    case 15 : 
      donewinternal ();
      break;
    case 22 : 
      doshowwhatever ();
      break;
    case 18 : 
      doaddto ();
      break;
    case 17 : 
      doshipout ();
      break;
    case 11 : 
      dodisplay ();
      break;
    case 28 : 
      doopen_window ();
      break;
    case 19 : 
      docull ();
      break;
    case 26 : 
      {
	getsymbol ();
	start_sym = cur_sym;
	getxnext ();
      } 
      break;
    case 25 : 
      domessage ();
      break;
    case 20 : 
      dotfmcommand ();
      break;
    case 29 : 
      dospecial ();
      break;
    } 
    cur_type = 1;
  } 
  if (cur_cmd < 83) 
  {
    {
      if (interaction == 3) 
;
      if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[in_open]);
	print (58);
	print_int (line);
	print (262);
	print (875);
      } 
      else {
	  
	print_nl (263);
	print (875);
      } 
    } 
    {
      help_ptr = 6;
      help_line[5] = 876;
      help_line[4] = 877;
      help_line[3] = 878;
      help_line[2] = 872;
      help_line[1] = 873;
      help_line[0] = 874;
    } 
    backerror ();
    scanner_status = 2;
    do {
	getnext ();
      if (cur_cmd == 39) 
      {
	if (str_ref[cur_mod]< 127) {
	    
	  if (str_ref[cur_mod] > 1) 
	  decr (str_ref[cur_mod]);
	  else flush_string (cur_mod);
	} 
      } 
    } while (!(cur_cmd > 82));
    scanner_status = 0;
  } 
  error_count = 0;
} 
void 
maincontrol (void) 
{
  do {
      dostatement ();
    if (cur_cmd == 84) 
    {
      {
	if (interaction == 3) 
	;
	if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
	{
	  print_nl (261);
	  print (fullsourcefilenamestack[in_open]);
	  print (58);
	  print_int (line);
	  print (262);
	  print (910);
	} 
	else {
	    
	  print_nl (263);
	  print (910);
	} 
      } 
      {
	help_ptr = 2;
	help_line[1] = 911;
	help_line[0] = 690;
      } 
      flush_error (0);
    } 
  } while (!(cur_cmd == 85));
} 
halfword 
zsortin (scaled v) 
{
  /* 40 */ register halfword Result; halfword p, q, r;
  p = memtop - 1;
  while (true) {
      
    q = mem[p].hhfield.v.RH;
    if (v <= mem[q + 1].cint) 
    goto found;
    p = q;
  } 
  found: if (v < mem[q + 1].cint) 
  {
    r = get_node (2);
    mem[r + 1].cint = v;
    mem[r].hhfield.v.RH = q;
    mem[p].hhfield.v.RH = r;
  } 
  Result = mem[p].hhfield.v.RH;
  return Result;
} 
integer 
zmincover (scaled d) 
{
  register integer Result; halfword p;
  scaled l;
  integer m;
  m = 0;
  p = mem[memtop - 1].hhfield.v.RH;
  perturbation = 2147483647L;
  while (p != 19) {
      
    incr (m);
    l = mem[p + 1].cint;
    do {
	p = mem[p].hhfield.v.RH;
    } while (!(mem[p + 1].cint > l + d));
    if (mem[p + 1].cint - l < perturbation) 
    perturbation = mem[p + 1].cint - l;
  } 
  Result = m;
  return Result;
} 
scaled 
zthresholdfn (integer m) 
{
  register scaled Result; scaled d;
  excess = mincover (0) - m;
  if (excess <= 0) 
  Result = 0;
  else {
      
    do {
	d = perturbation;
    } while (!(mincover (d + d) <= m));
    while (mincover (d) > m) d = perturbation;
    Result = d;
  } 
  return Result;
} 
integer 
zskimp (integer m) 
{
  register integer Result; scaled d;
  halfword p, q, r;
  scaled l;
  scaled v;
  d = thresholdfn (m);
  perturbation = 0;
  q = memtop - 1;
  m = 0;
  p = mem[memtop - 1].hhfield.v.RH;
  while (p != 19) {
      
    incr (m);
    l = mem[p + 1].cint;
    mem[p].hhfield.lhfield = m;
    if (mem[mem[p].hhfield.v.RH + 1].cint <= l + d) 
    {
      do {
	  p = mem[p].hhfield.v.RH;
	mem[p].hhfield.lhfield = m;
	decr (excess);
	if (excess == 0) 
	d = 0;
      } while (!(mem[mem[p].hhfield.v.RH + 1].cint > l + d));
      v = l + halfp (mem[p + 1].cint - l);
      if (mem[p + 1].cint - v > perturbation) 
      perturbation = mem[p + 1].cint - v;
      r = q;
      do {
	  r = mem[r].hhfield.v.RH;
	mem[r + 1].cint = v;
      } while (!(r == p));
      mem[q].hhfield.v.RH = p;
    } 
    q = p;
    p = mem[p].hhfield.v.RH;
  } 
  Result = m;
  return Result;
} 
void 
ztfmwarning (small_number m) 
{
  print_nl (1041);
  print (int_name[m]);
  print (1042);
  print_scaled (perturbation);
  print (1043);
} 
void 
fixdesignsize (void) 
{
  scaled d;
  d = internal[26];
  if ((d < 65536L) || (d >= 134217728L)) 
  {
    if (d != 0) 
    print_nl (1044);
    d = 8388608L;
    internal[26] = d;
  } 
  if (header_byte[5]< 0) {
      
    if (header_byte[6]< 0) {
	
      if (header_byte[7]< 0) {
	  
	if (header_byte[8]< 0) 
	{
	  header_byte[5] = d / 1048576L;
	  header_byte[6] = (d / 4096) % 256;
	  header_byte[7] = (d / 16) % 256;
	  header_byte[8] = (d % 16) * 16;
	} 
      } 
    } 
  } 
  max_tfm_dimen = 16 * internal[26] - 1 - internal[26]/ 2097152L;
  if (max_tfm_dimen >= 134217728L) 
  max_tfm_dimen = 134217727L;
} 
integer 
zdimenout (scaled x) 
{
  register integer Result; if (abs (x) > max_tfm_dimen) 
  {
    incr (tfm_changed);
    if (x > 0) 
    x = max_tfm_dimen;
    else x = - (integer) max_tfm_dimen;
  } 
  x = makescaled (x * 16 , internal[26]);
  Result = x;
  return Result;
} 
void 
fixchecksum (void) 
{
  /* 10 */ eight_bits k;
  eight_bits lb1, lb2, lb3, b4;
  integer x;
  if (header_byte[1]< 0) {
      
    if (header_byte[2]< 0) {
	
      if (header_byte[3]< 0) {
	  
	if (header_byte[4]< 0) 
	{
	  lb1 = bc;
	  lb2 = ec;
	  lb3 = bc;
	  b4 = ec;
	  tfm_changed = 0;
	  {register integer for_end; k = bc;for_end = ec; if (k <= 
	  for_end) do 
	    if (char_exists[k]) 
	    {
	      x = dimenout (mem[tfm_width[k]+ 1].cint) + (k + 4) * 
	      4194304L;
	      lb1 = (lb1 + lb1 + x) % 255;
	      lb2 = (lb2 + lb2 + x) % 253;
	      lb3 = (lb3 + lb3 + x) % 251;
	      b4 = (b4 + b4 + x) % 247;
	    } 
	  while (k++ < for_end);} 
	  header_byte[1] = lb1;
	  header_byte[2] = lb2;
	  header_byte[3] = lb3;
	  header_byte[4] = b4;
	  goto lab10;
	} 
      } 
    } 
  } 
  {register integer for_end; k = 1;for_end = 4; if (k <= for_end) do 
    if (header_byte[k]< 0) 
    header_byte[k] = 0;
  while (k++ < for_end);} 
  lab10:;
} 
void 
tfm_qqqq (fourquarters x) 
{
  putbyte (x.b0 , tfm_file);
  putbyte (x.b1 , tfm_file);
  putbyte (x .b2 , tfm_file);
  putbyte (x .b3 , tfm_file);
} 
boolean 
open_base_file (void) 
{
  /* 40 10 */ register boolean Result; integer j;
  j = cur_input.loc_field;
  if (buffer[cur_input.loc_field] == 38) 
  {
    incr (cur_input.loc_field);
    j = cur_input.loc_field;
    buffer[last] = 32;
    while (buffer[j]!= 32) incr (j);
    packbufferedname (0 , cur_input.loc_field , j - 1);
    if (wopenin (base_file)) 
    goto found;
    Fputs (stdout ,  "Sorry, I can't find the base `");
    fputs (stringcast (name_of_file + 1) , stdout);
    Fputs (stdout ,  "'; will try `");
    fputs (MF_base_default + 1 , stdout);
    fprintf (stdout , "%s\n",  "'.");
    fflush (stdout);
  } 
  packbufferedname (basedefaultlength - 5 , 1 , 0);
  if (!wopenin (base_file)) 
  {
;
    Fputs (stdout ,  "I can't find the base file `");
    fputs (MF_base_default + 1 , stdout);
    fprintf (stdout , "%s\n",  "'!");
    Result = false;
    goto lab10;
  } 
  found: cur_input.loc_field = j;
  Result = true;
  lab10:;
  return Result;
} 
void 
scan_primary (void) 
{
  /* 20 30 31 32 */ halfword p, q, r;
  quarterword c;
  unsigned char myvar_flag;
  halfword ldelim, rdelim;
  integer groupline;
  scaled num, denom;
  halfword prehead, posthead, tail;
  small_number tt;
  halfword t;
  halfword macroref;
  myvar_flag = var_flag;
  var_flag = 0;
  lab20: {
      
    if (arith_error) 
    clear_arith ();
  } 
	;
#ifdef TEXMF_DEBUG
  if (panicking) 
  checkmem (false);
#endif /* TEXMF_DEBUG */
  if (interrupt != 0) {
      
    if (OK_to_interrupt) 
    {
      backinput ();
      {
	if (interrupt != 0) 
	pause_for_instructions ();
      } 
      getxnext ();
    } 
  } 
  switch (cur_cmd) 
  {case 31 : 
    {
      ldelim = cur_sym;
      rdelim = cur_mod;
      getxnext ();
      scan_expression ();
      if ((cur_cmd == 82) && (cur_type >= 16)) 
      {
	p = get_node (2);
	mem[p].hhfield.b0 = 14;
	mem[p].hhfield.b1 = 11;
	init_big_node (p);
	q = mem[p + 1].cint;
	stashin (q);
	getxnext ();
	scan_expression ();
	if (cur_type < 16) 
	{
	  disp_err (0 , 775);
	  {
	    help_ptr = 4;
	    help_line[3] = 776;
	    help_line[2] = 777;
	    help_line[1] = 778;
	    help_line[0] = 779;
	  } 
	  put_get_flush_error (0);
	} 
	stashin (q + 2);
	checkdelimiter (ldelim , rdelim);
	cur_type = 14;
	cur_exp = p;
      } 
      else checkdelimiter (ldelim , rdelim);
    } 
    break;
  case 32 : 
    {
      groupline = line;
      if (internal[7] > 0) 
      show_cmd_mod (cur_cmd , cur_mod);
      {
	p = get_avail ();
	mem[p].hhfield.lhfield = 0;
	mem[p].hhfield.v.RH = save_ptr;
	save_ptr = p;
      } 
      do {
	  dostatement ();
      } while (!(cur_cmd != 83));
      if (cur_cmd != 84) 
      {
	{
	  if (interaction == 3) 
	;
	  if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
	  {
	    print_nl (261);
	    print (fullsourcefilenamestack[in_open]);
	    print (58);
	    print_int (line);
	    print (262);
	    print (780);
	  } 
	  else {
	      
	    print_nl (263);
	    print (780);
	  } 
	} 
	print_int (groupline);
	print (781);
	{
	  help_ptr = 2;
	  help_line[1] = 782;
	  help_line[0] = 783;
	} 
	backerror ();
	cur_cmd = 84;
      } 
      unsave ();
      if (internal[7] > 0) 
      show_cmd_mod (cur_cmd , cur_mod);
    } 
    break;
  case 39 : 
    {
      cur_type = 4;
      cur_exp = cur_mod;
    } 
    break;
  case 42 : 
    {
      cur_exp = cur_mod;
      cur_type = 16;
      getxnext ();
      if (cur_cmd != 54) 
      {
	num = 0;
	denom = 0;
      } 
      else {
	  
	getxnext ();
	if (cur_cmd != 42) 
	{
	  backinput ();
	  cur_cmd = 54;
	  cur_mod = 72;
	  cur_sym = 9761;
	  goto done;
	} 
	num = cur_exp;
	denom = cur_mod;
	if (denom == 0) 
	{
	  {
	    if (interaction == 3) 
	;
	    if ((filelineerrorstylep && !(cur_input .name_field == 0))) 
	    {
	      print_nl (261);
	      print (fullsourcefilenamestack[in_open]);
	      print (58);
	      print_int (line);
	      print (262);
	      print (784);
	    } 
	    else {
		
	      print_nl (263);
	      print (784);
	    } 
	  } 
	  {
	    help_ptr = 1;
	    help_line[0] = 785;
	  } 
	  error ();
	} 
	else cur_exp = makescaled (num , denom);
	{
	  if (arith_error) 
	  clear_arith ();
	} 
	getxnext ();
      } 
      if (cur_cmd >= 30) {
	  
	if (cur_cmd < 42) 
	{
	  p = stash_cur_exp ();
	  scan_primary ();
	  if ((abs (num) >= abs (denom)) || (cur_type < 14)) 
	  dobinary (p , 71);
	  else {
	      
	    fracmult (num , denom);
	    free_node (p , 2);
	  } 
	} 
      } 
      goto done;
    } 
    break;
  case 33 : 
    donullary (cur_mod);
    break;
  case 34 : 
  case 30 : 
  case 36 : 
  case 43 : 
    {
      c = cur_mod;
      getxnext ();
      scan_primary ();
      dounary (c);
      goto done;
    } 
    break;
  case 37 : 
    {
      c = cur_mod;
      getxnext ();
      scan_expression ();
      if (cur_cmd != 69) 
      {
	missing_err (479);
	print (716);
	print_cmd_mod (37 , c);
	{
	  help_ptr = 1;
	  help_line[0] = 717;
	} 
	backerror ();
      } 
      p = stash_cur_exp ();
      getxnext ();
      scan_primary ();
      dobinary (p , c);
      goto done;
    } 
    break;
  case 35 : 
    {
      getxnext ();
      scan_suffix ();
      old_setting = selector;
      selector = 5;
      show_token_list (cur_exp , 0 , 100000L , 0);
      flush_token_list (cur_exp);
      cur_exp = make_string ();
      selector = old_setting;
      cur_type = 4;
      goto done;
    } 
    break;
  case 40 : 
    {
      q = cur_mod;
      if (myvar_flag == 77) 
      {
	getxnext ();
	if (cur_cmd == 77) 
	{
	  cur_exp = get_avail ();
	  mem[cur_exp].hhfield.lhfield = q + 9769;
	  cur_type = 20;
	  goto done;
	} 
	backinput ();
      } 
      cur_type = 16;
      cur_exp = internal[q];
    } 
    break;
  case 38 : 
    makeexpcopy (cur_mod);
    break;
  case 41 : 
    {
      {
	prehead = avail;
	if (prehead == 0) 
	prehead = get_avail ();
	else {
	    
	  avail = mem[prehead].hhfield.v.RH;
	  mem[prehead].hhfield.v.RH = 0;
	;
#ifdef STAT
	  incr (dyn_used);
#endif /* STAT */
	} 
      } 
      tail = prehead;
      posthead = 0;
      tt = 1;
      while (true) {
	  
	t = cur_tok ();
	mem[tail].hhfield.v.RH = t;
	if (tt != 0) 
	{
	  {
	    p = mem[prehead].hhfield.v.RH;
	    q = mem[p].hhfield.lhfield;
	    tt = 0;
	    if (eqtb[q].lhfield % 86 == 41) 
	    {
	      q = eqtb[q].v.RH;
	      if (q == 0) 
	      goto done2;
	      while (true) {
		  
		p = mem[p].hhfield.v.RH;
		if (p == 0) 
		{
		  tt = mem[q].hhfield.b0;
		  goto done2;
		} 
		if (mem[q].hhfield.b0 != 21) 
		goto done2;
		q = mem[mem[q + 1].hhfield.lhfield].hhfield.v.RH;
		if (p >= hi_mem_min) 
		{
		  do {
		      q = mem[q].hhfield.v.RH;
		  } while (!(mem[q + 2].hhfield.lhfield >= mem[p]
		  .hhfield.lhfield));
		  if (mem[q + 2].hhfield.lhfield > mem[p].hhfield 
		.lhfield) 
		  goto done2;
		} 
	      } 
	    } 
	    done2:;
	  } 
	  if (tt >= 22) 
	  {
	    mem[tail].hhfield.v.RH = 0;
	    if (tt > 22) 
	    {
	      posthead = get_avail ();
	      tail = posthead;
	      mem[tail].hhfield.v.RH = t;
	      tt = 0;
	      macroref = mem[q + 1].cint;
	      incr (mem[macroref].hhfield.lhfield);
	    } 
	    else {
		
	      p = get_avail ();
	      mem[prehead].hhfield.lhfield = mem[prehead].hhfield 
	    .v.RH;
	      mem[prehead].hhfield.v.RH = p;
	      mem[p].hhfield.lhfield = t;
	      macrocall (mem[q + 1].cint , prehead , 0);
	      getxnext ();
	      goto lab20;
	    } 
	  } 
	} 
	getxnext ();
	tail = t;
	if (cur_cmd == 63) 
	{
	  getxnext ();
	  scan_expression ();
	  if (cur_cmd != 64) 
	  {
	    backinput ();
	    backexpr ();
	    cur_cmd = 63;
	    cur_mod = 0;
	    cur_sym = 9760;
	  } 
	  else {
	      
	    if (cur_type != 16) 
	    badsubscript ();
	    cur_cmd = 42;
	    cur_mod = cur_exp;
	    cur_sym = 0;
	  } 
	} 
	if (cur_cmd > 42) 
	goto done1;
	if (cur_cmd < 40) 
	goto done1;
      } 
      done1: if (posthead != 0) 
      {
	backinput ();
	p = get_avail ();
	q = mem[posthead].hhfield.v.RH;
	mem[prehead].hhfield.lhfield = mem[prehead].hhfield.v.RH;
	mem[prehead].hhfield.v.RH = posthead;
	mem[posthead].hhfield.lhfield = q;
	mem[posthead].hhfield.v.RH = p;
	mem[p].hhfield.lhfield = mem[q].hhfield.v.RH;
	mem[q].hhfield.v.RH = 0;
	macrocall (macroref , prehead , 0);
	decr (mem[macroref].hhfield.lhfield);
	getxnext ();
	goto lab20;
      } 
      q = mem[prehead].hhfield.v.RH;
      {
	mem[prehead].hhfield.v.RH = avail;
	avail = prehead;
	;
#ifdef STAT
	decr (dyn_used);
#endif /* STAT */
      } 
      if (cur_cmd == myvar_flag) 
      {
	cur_type = 20;
	cur_exp = q;
	goto done;
      } 
      p = find_variable (q);
      if (p != 0) 
      makeexpcopy (p);
      else {
	  
	obliterated (q);
	help_line[2] = 797;
	help_line[1] = 798;
	help_line[0] = 799;
	put_get_flush_error (0);
      } 
      flush_node_list (q);
      goto done;
    } 
    break;
    default: 
    {
      badexp (769);
      goto lab20;
    } 
    break;
  } 
  getxnext ();
  done: if (cur_cmd == 63) {
      
    if (cur_type >= 16) 
    {
      p = stash_cur_exp ();
      getxnext ();
      scan_expression ();
      if (cur_cmd != 82) 
      {
	{
	  backinput ();
	  backexpr ();
	  cur_cmd = 63;
	  cur_mod = 0;
	  cur_sym = 9760;
	} 
	unstash_cur_exp (p);
      } 
      else {
	  
	q = stash_cur_exp ();
	getxnext ();
	scan_expression ();
	if (cur_cmd != 64) 
	{
	  missing_err (93);
	  {
	    help_ptr = 3;
	    help_line[2] = 801;
	    help_line[1] = 802;
	    help_line[0] = 698;
	  } 
	  backerror ();
	} 
	r = stash_cur_exp ();
	makeexpcopy (q);
	dobinary (r , 70);
	dobinary (p , 71);
	dobinary (q , 69);
	getxnext ();
      } 
    } 
  } 
} 
void 
scan_suffix (void) 
{
  /* 30 */ halfword h, t;
  halfword p;
  h = get_avail ();
  t = h;
  while (true) {
      
    if (cur_cmd == 63) 
    {
      getxnext ();
      scan_expression ();
      if (cur_type != 16) 
      badsubscript ();
      if (cur_cmd != 64) 
      {
	missing_err (93);
	{
	  help_ptr = 3;
	  help_line[2] = 803;
	  help_line[1] = 802;
	  help_line[0] = 698;
	} 
	backerror ();
      } 
      cur_cmd = 42;
      cur_mod = cur_exp;
    } 
    if (cur_cmd == 42) 
    p = new_num_tok (cur_mod);
    else if ((cur_cmd == 41) || (cur_cmd == 40)) 
    {
      p = get_avail ();
      mem[p].hhfield.lhfield = cur_sym;
    } 
    else goto done;
    mem[t].hhfield.v.RH = p;
    t = p;
    getxnext ();
  } 
  done: cur_exp = mem[h].hhfield.v.RH;
  {
    mem[h].hhfield.v.RH = avail;
    avail = h;
	;
#ifdef STAT
    decr (dyn_used);
#endif /* STAT */
  } 
  cur_type = 20;
} 
void 
scan_secondary (void) 
{
  /* 20 22 */ halfword p;
  halfword c, d;
  halfword macname;
  lab20: if ((cur_cmd < 30) || (cur_cmd > 43)) 
  badexp (804);
  scan_primary ();
  lab22: if (cur_cmd <= 55) {
      
    if (cur_cmd >= 52) 
    {
      p = stash_cur_exp ();
      c = cur_mod;
      d = cur_cmd;
      if (d == 53) 
      {
	macname = cur_sym;
	incr (mem[c].hhfield.lhfield);
      } 
      getxnext ();
      scan_primary ();
      if (d != 53) 
      dobinary (p , c);
      else {
	  
	backinput ();
	binarymac (p , c , macname);
	decr (mem[c].hhfield.lhfield);
	getxnext ();
	goto lab20;
      } 
      goto lab22;
    } 
  } 
} 
void 
scan_tertiary (void) 
{
  /* 20 22 */ halfword p;
  halfword c, d;
  halfword macname;
  lab20: if ((cur_cmd < 30) || (cur_cmd > 43)) 
  badexp (805);
  scan_secondary ();
  if (cur_type == 8) 
  materializepen ();
  lab22: if (cur_cmd <= 45) {
      
    if (cur_cmd >= 43) 
    {
      p = stash_cur_exp ();
      c = cur_mod;
      d = cur_cmd;
      if (d == 44) 
      {
	macname = cur_sym;
	incr (mem[c].hhfield.lhfield);
      } 
      getxnext ();
      scan_secondary ();
      if (d != 44) 
      dobinary (p , c);
      else {
	  
	backinput ();
	binarymac (p , c , macname);
	decr (mem[c].hhfield.lhfield);
	getxnext ();
	goto lab20;
      } 
      goto lab22;
    } 
  } 
} 
void 
scan_expression (void) 
{
  /* 20 30 22 25 26 10 */ halfword p, q, r, pp, qq;
  halfword c, d;
  unsigned char myvar_flag;
  halfword macname;
  boolean cyclehit;
  scaled x, y;
  unsigned char t;
  myvar_flag = var_flag;
  lab20: if ((cur_cmd < 30) || (cur_cmd > 43)) 
  badexp (808);
  scan_tertiary ();
  lab22: if (cur_cmd <= 51) {
      
    if (cur_cmd >= 46) {
	
      if ((cur_cmd != 51) || (myvar_flag != 77)) 
      {
	p = stash_cur_exp ();
	c = cur_mod;
	d = cur_cmd;
	if (d == 49) 
	{
	  macname = cur_sym;
	  incr (mem[c].hhfield.lhfield);
	} 
	if ((d < 48) || ((d == 48) && ((mem[p].hhfield.b0 == 14) 
	|| (mem[p].hhfield.b0 == 9)))) 
	{
	  cyclehit = false;
	  {
	    unstash_cur_exp (p);
	    if (cur_type == 14) 
	    p = newknot ();
	    else if (cur_type == 9) 
	    p = cur_exp;
	    else goto lab10;
	    q = p;
	    while (mem[q].hhfield.v.RH != p) q = mem[q].hhfield 
	  .v.RH;
	    if (mem[p].hhfield.b0 != 0) 
	    {
	      r = copyknot (p);
	      mem[q].hhfield.v.RH = r;
	      q = r;
	    } 
	    mem[p].hhfield.b0 = 4;
	    mem[q].hhfield.b1 = 4;
	  } 
	  lab25: if (cur_cmd == 46) 
	  {
	    t = scandirection ();
	    if (t != 4) 
	    {
	      mem[q].hhfield.b1 = t;
	      mem[q + 5].cint = cur_exp;
	      if (mem[q].hhfield.b0 == 4) 
	      {
		mem[q].hhfield.b0 = t;
		mem[q + 3].cint = cur_exp;
	      } 
	    } 
	  } 
	  d = cur_cmd;
	  if (d == 47) 
	  {
	    getxnext ();
	    if (cur_cmd == 58) 
	    {
	      getxnext ();
	      y = cur_cmd;
	      if (cur_cmd == 59) 
	      getxnext ();
	      scan_primary ();
	      if ((cur_type != 16) || (cur_exp < 49152L)) 
	      {
		disp_err (0 , 826);
		{
		  help_ptr = 1;
		  help_line[0] = 827;
		} 
		put_get_flush_error (65536L);
	      } 
	      if (y == 59) 
	      cur_exp = - (integer) cur_exp;
	      mem[q + 6].cint = cur_exp;
	      if (cur_cmd == 52) 
	      {
		getxnext ();
		y = cur_cmd;
		if (cur_cmd == 59) 
		getxnext ();
		scan_primary ();
		if ((cur_type != 16) || (cur_exp < 49152L)) 
		{
		  disp_err (0 , 826);
		  {
		    help_ptr = 1;
		    help_line[0] = 827;
		  } 
		  put_get_flush_error (65536L);
		} 
		if (y == 59) 
		cur_exp = - (integer) cur_exp;
	      } 
	      y = cur_exp;
	    } 
	    else if (cur_cmd == 57) 
	    {
	      mem[q].hhfield.b1 = 1;
	      t = 1;
	      getxnext ();
	      scan_primary ();
	      knownpair ();
	      mem[q + 5].cint = cur_x;
	      mem[q + 6].cint = cur_y;
	      if (cur_cmd != 52) 
	      {
		x = mem[q + 5].cint;
		y = mem[q + 6].cint;
	      } 
	      else {
		  
		getxnext ();
		scan_primary ();
		knownpair ();
		x = cur_x;
		y = cur_y;
	      } 
	    } 
	    else {
		
	      mem[q + 6].cint = 65536L;
	      y = 65536L;
	      backinput ();
	      goto done;
	    } 
	    if (cur_cmd != 47) 
	    {
	      missing_err (408);
	      {
		help_ptr = 1;
		help_line[0] = 825;
	      } 
	      backerror ();
	    } 
	    done:;
	  } 
	  else if (d != 48) 
	  goto lab26;
	  getxnext ();
	  if (cur_cmd == 46) 
	  {
	    t = scandirection ();
	    if (mem[q].hhfield.b1 != 1) 
	    x = cur_exp;
	    else t = 1;
	  } 
	  else if (mem[q].hhfield.b1 != 1) 
	  {
	    t = 4;
	    x = 0;
	  } 
	  if (cur_cmd == 36) 
	  {
	    cyclehit = true;
	    getxnext ();
	    pp = p;
	    qq = p;
	    if (d == 48) {
		
	      if (p == q) 
	      {
		d = 47;
		mem[q + 6].cint = 65536L;
		y = 65536L;
	      } 
	    } 
	  } 
	  else {
	      
	    scan_tertiary ();
	    {
	      if (cur_type != 9) 
	      pp = newknot ();
	      else pp = cur_exp;
	      qq = pp;
	      while (mem[qq].hhfield.v.RH != pp) qq = mem[qq]
	      .hhfield.v.RH;
	      if (mem[pp].hhfield.b0 != 0) 
	      {
		r = copyknot (pp);
		mem[qq].hhfield.v.RH = r;
		qq = r;
	      } 
	      mem[pp].hhfield.b0 = 4;
	      mem[qq].hhfield.b1 = 4;
	    } 
	  } 
	  {
	    if (d == 48) {
		
	      if ((mem[q + 1].cint != mem[pp + 1].cint) || (mem[
	      q + 2].cint != mem[pp + 2].cint)) 
	      {
		{
		  if (interaction == 3) 
		;
		  if ((filelineerrorstylep && !(cur_input .name_field == 0) 
		)) 
		  {
		    print_nl (261);
		    print (fullsourcefilenamestack[in_open]);
		    print (58);
		    print_int (line);
		    print (262);
		    print (828);
		  } 
		  else {
		      
		    print_nl (263);
		    print (828);
		  } 
		} 
		{
		  help_ptr = 3;
		  help_line[2] = 829;
		  help_line[1] = 830;
		  help_line[0] = 831;
		} 
		put_get_error ();
		d = 47;
		mem[q + 6].cint = 65536L;
		y = 65536L;
	      } 
	    } 
	    if (mem[pp].hhfield.b1 == 4) {
		
	      if ((t == 3) || (t == 2)) 
	      {
		mem[pp].hhfield.b1 = t;
		mem[pp + 5].cint = x;
	      } 
	    } 
	    if (d == 48) 
	    {
	      if (mem[q].hhfield.b0 == 4) {
		  
		if (mem[q].hhfield.b1 == 4) 
		{
		  mem[q].hhfield.b0 = 3;
		  mem[q + 3].cint = 65536L;
		} 
	      } 
	      if (mem[pp].hhfield.b1 == 4) {
		  
		if (t == 4) 
		{
		  mem[pp].hhfield.b1 = 3;
		  mem[pp + 5].cint = 65536L;
		} 
	      } 
	      mem[q].hhfield.b1 = mem[pp].hhfield.b1;
	      mem[q].hhfield.v.RH = mem[pp].hhfield.v.RH;
	      mem[q + 5].cint = mem[pp + 5].cint;
	      mem[q + 6].cint = mem[pp + 6].cint;
	      free_node (pp , 7);
	      if (qq == pp) 
	      qq = q;
	    } 
	    else {
		
	      if (mem[q].hhfield.b1 == 4) {
		  
		if ((mem[q].hhfield.b0 == 3) || (mem[q].hhfield 
		.b0 == 2)) 
		{
		  mem[q].hhfield.b1 = mem[q].hhfield.b0;
		  mem[q + 5].cint = mem[q + 3].cint;
		} 
	      } 
	      mem[q].hhfield.v.RH = pp;
	      mem[pp + 4].cint = y;
	      if (t != 4) 
	      {
		mem[pp + 3].cint = x;
		mem[pp].hhfield.b0 = t;
	      } 
	    } 
	    q = qq;
	  } 
	  if (cur_cmd >= 46) {
	      
	    if (cur_cmd <= 48) {
		
	      if (!cyclehit) 
	      goto lab25;
	    } 
	  } 
	  lab26: if (cyclehit) 
	  {
	    if (d == 48) 
	    p = q;
	  } 
	  else {
	      
	    mem[p].hhfield.b0 = 0;
	    if (mem[p].hhfield.b1 == 4) 
	    {
	      mem[p].hhfield.b1 = 3;
	      mem[p + 5].cint = 65536L;
	    } 
	    mem[q].hhfield.b1 = 0;
	    if (mem[q].hhfield.b0 == 4) 
	    {
	      mem[q].hhfield.b0 = 3;
	      mem[q + 3].cint = 65536L;
	    } 
	    mem[q].hhfield.v.RH = p;
	  } 
	  make_choices (p);
	  cur_type = 9;
	  cur_exp = p;
	} 
	else {
	    
	  getxnext ();
	  scan_tertiary ();
	  if (d != 49) 
	  dobinary (p , c);
	  else {
	      
	    backinput ();
	    binarymac (p , c , macname);
	    decr (mem[c].hhfield.lhfield);
	    getxnext ();
	    goto lab20;
	  } 
	} 
	goto lab22;
      } 
    } 
  } 
  lab10:;
} 
void 
get_boolean (void) 
{
  getxnext ();
  scan_expression ();
  if (cur_type != 2) 
  {
    disp_err (0 , 832);
    {
      help_ptr = 2;
      help_line[1] = 833;
      help_line[0] = 834;
    } 
    put_get_flush_error (31);
    cur_type = 2;
  } 
} 
void 
print_capsule (void) 
{
  print_char (40);
  print_exp (g_pointer , 0);
  print_char (41);
} 
void 
token_recycle (void) 
{
  recycle_value (g_pointer);
} 
void 
close_files_and_terminate (void) 
{
  integer k;
  integer lh;
  short lkoffset;
  halfword p;
  scaled x;
	;
#ifdef STAT
  if (internal[12] > 0) {
      
    if (log_opened) 
    {
      { putc (' ' ,  log_file);  putc ('\n',  log_file); }
      fprintf (log_file , "%s%s\n",  "Here is how much of METAFONT's memory" ,       " you used:");
      fprintf (log_file , "%c%ld%s",  ' ' , (long)max_str_ptr - init_str_ptr , " string");
      if (max_str_ptr != init_str_ptr + 1) 
      putc ('s' ,  log_file);
      fprintf (log_file , "%s%ld\n",  " out of " , (long)max_strings - init_str_ptr);
      fprintf (log_file , "%c%ld%s%ld\n",  ' ' , (long)max_pool_ptr - init_pool_ptr ,       " string characters out of " , (long)pool_size - init_pool_ptr);
      fprintf (log_file , "%c%ld%s%ld\n",  ' ' , (long)lo_mem_max + 0 + mem_end - hi_mem_min + 2 ,       " words of memory out of " , (long)mem_end + 1);
      fprintf (log_file , "%c%ld%s%ld\n",  ' ' , (long)st_count , " symbolic tokens out of " , (long)9500) 
;
      fprintf (log_file , "%c%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%c\n",  ' ' , (long)max_in_stack , "i," , (long)int_ptr , "n," ,       (long)max_rounding_ptr , "r," , (long)max_param_stack , "p," , (long)max_buf_stack + 1 ,       "b stack positions out of " , (long)stack_size , "i," , (long)max_internal , "n," ,       (long)max_wiggle , "r," , (long)150 , "p," , (long)bufsize , 'b');
    } 
  } 
#endif /* STAT */
  if ((gf_prev_ptr > 0) || (internal[33] > 0)) 
  {
    rover = 23;
    mem[rover].hhfield.v.RH = 268435455L;
    lo_mem_max = hi_mem_min - 1;
    if (lo_mem_max - rover > 268435455L) 
    lo_mem_max = 268435455L + rover;
    mem[rover].hhfield.lhfield = lo_mem_max - rover;
    mem[rover + 1].hhfield.lhfield = rover;
    mem[rover + 1].hhfield.v.RH = rover;
    mem[lo_mem_max].hhfield.v.RH = 0;
    mem[lo_mem_max].hhfield.lhfield = 0;
    mem[memtop - 1].hhfield.v.RH = 19;
    {register integer for_end; k = bc;for_end = ec; if (k <= for_end) do 
      if (char_exists[k]) 
      tfm_width[k] = sortin (tfm_width[k]);
    while (k++ < for_end);} 
    nw = skimp (255) + 1;
    dimen_head[1] = mem[memtop - 1].hhfield.v.RH;
    if (perturbation >= 4096) 
    tfmwarning (20);
    fixdesignsize ();
    fixchecksum ();
    if (internal[33] > 0) 
    {
      mem[memtop - 1].hhfield.v.RH = 19;
      {register integer for_end; k = bc;for_end = ec; if (k <= for_end) 
      do 
	if (char_exists[k]) {
	    
	  if (tfm_height[k] == 0) 
	  tfm_height[k] = 15;
	  else tfm_height[k] = sortin (tfm_height[k]);
	} 
      while (k++ < for_end);} 
      nh = skimp (15) + 1;
      dimen_head[2] = mem[memtop - 1].hhfield.v.RH;
      if (perturbation >= 4096) 
      tfmwarning (21);
      mem[memtop - 1].hhfield.v.RH = 19;
      {register integer for_end; k = bc;for_end = ec; if (k <= for_end) 
      do 
	if (char_exists[k]) {
	    
	  if (tfm_depth[k] == 0) 
	  tfm_depth[k] = 15;
	  else tfm_depth[k] = sortin (tfm_depth[k]);
	} 
      while (k++ < for_end);} 
      nd = skimp (15) + 1;
      dimen_head[3] = mem[memtop - 1].hhfield.v.RH;
      if (perturbation >= 4096) 
      tfmwarning (22);
      mem[memtop - 1].hhfield.v.RH = 19;
      {register integer for_end; k = bc;for_end = ec; if (k <= for_end) 
      do 
	if (char_exists[k]) {
	    
	  if (tfm_ital_corr[k] == 0) 
	  tfm_ital_corr[k] = 15;
	  else tfm_ital_corr[k] = sortin (tfm_ital_corr[k]);
	} 
      while (k++ < for_end);} 
      ni = skimp (63) + 1;
      dimen_head[4] = mem[memtop - 1].hhfield.v.RH;
      if (perturbation >= 4096) 
      tfmwarning (23);
      internal[33] = 0;
      if (job_name == 0) 
      open_log_file ();
      packjob_name (1045);
      while (!bopenout (tfm_file)) promptfilename (1046 , 1045);
      metric_file_name = bmakenamestring (tfm_file);
      k = header_size;
      while (header_byte[k]< 0) decr (k);
      lh = (k + 3) / 4;
      if (bc > ec) 
      bc = 1;
      bchar = roundunscaled (internal[41]);
      if ((bchar < 0) || (bchar > 255)) 
      {
	bchar = -1;
	lk_started = false;
	lkoffset = 0;
      } 
      else {
	  
	lk_started = true;
	lkoffset = 1;
      } 
      k = label_ptr;
      if (label_loc[k]+ lkoffset > 255) 
      {
	lkoffset = 0;
	lk_started = false;
	do {
	    char_remainder[label_char[k]] = lkoffset;
	  while (label_loc[k - 1] == label_loc[k]) {
	      
	    decr (k);
	    char_remainder[label_char[k]] = lkoffset;
	  } 
	  incr (lkoffset);
	  decr (k);
	} while (!(lkoffset + label_loc[k]< 256));
      } 
      if (lkoffset > 0) 
      while (k > 0) {
	  
	char_remainder[label_char[k]] = char_remainder[label_char[k]]
	+ lkoffset;
	decr (k);
      } 
      if (bch_label < lig_table_size) 
      {
	lig_kern[nl].b0 = 255;
	lig_kern[nl].b1 = 0;
	lig_kern[nl].b2 = ((bch_label + lkoffset) / 256);
	lig_kern[nl].b3 = ((bch_label + lkoffset) % 256);
	incr (nl);
      } 
      put2bytes (tfm_file , 6 + lh + (ec - bc + 1) + nw + nh + nd + ni + nl 
      + lkoffset + nk + ne + np);
      put2bytes (tfm_file , lh);
      put2bytes (tfm_file , bc);
      put2bytes (tfm_file , ec);
      put2bytes (tfm_file , nw);
      put2bytes (tfm_file , nh);
      put2bytes (tfm_file , nd);
      put2bytes (tfm_file , ni);
      put2bytes (tfm_file , nl + lkoffset);
      put2bytes (tfm_file , nk);
      put2bytes (tfm_file , ne);
      put2bytes (tfm_file , np);
      {register integer for_end; k = 1;for_end = 4 * lh; if (k <= 
      for_end) do 
	{
	  if (header_byte[k]< 0) 
	  header_byte[k] = 0;
	  putbyte (header_byte[k], tfm_file);
	} 
      while (k++ < for_end);} 
      {register integer for_end; k = bc;for_end = ec; if (k <= for_end) 
      do 
	if (!char_exists[k]) 
	put4bytes (tfm_file , 0);
	else {
	    
	  putbyte (mem[tfm_width[k]].hhfield.lhfield , tfm_file);
	  putbyte ((mem[tfm_height[k]].hhfield.lhfield) * 16 + mem[
	  tfm_depth[k]].hhfield.lhfield , tfm_file);
	  putbyte ((mem[tfm_ital_corr[k]].hhfield.lhfield) * 4 + 
	  char_tag[k], tfm_file);
	  putbyte (char_remainder[k], tfm_file);
	} 
      while (k++ < for_end);} 
      tfm_changed = 0;
      {register integer for_end; k = 1;for_end = 4; if (k <= for_end) do 
	{
	  put4bytes (tfm_file , 0);
	  p = dimen_head[k];
	  while (p != 19) {
	      
	    put4bytes (tfm_file , dimenout (mem[p + 1].cint));
	    p = mem[p].hhfield.v.RH;
	  } 
	} 
      while (k++ < for_end);} 
      {register integer for_end; k = 0;for_end = 255; if (k <= for_end) 
      do 
	if (skip_table[k]< lig_table_size) 
	{
	  print_nl (1048);
	  print_int (k);
	  print (1049);
	  ll = skip_table[k];
	  do {
	      lll = lig_kern[ll].b0;
	    lig_kern[ll].b0 = 128;
	    ll = ll - lll;
	  } while (!(lll == 0));
	} 
      while (k++ < for_end);} 
      if (lk_started) 
      {
	putbyte (255 , tfm_file);
	putbyte (bchar , tfm_file);
	put2bytes (tfm_file , 0);
      } 
      else {
	  register integer for_end; k = 1;for_end = lkoffset; if (k <= 
      for_end) do 
	{
	  ll = label_loc[label_ptr];
	  if (bchar < 0) 
	  {
	    putbyte (254 , tfm_file);
	    putbyte (0 , tfm_file);
	  } 
	  else {
	      
	    putbyte (255 , tfm_file);
	    putbyte (bchar , tfm_file);
	  } 
	  put2bytes (tfm_file , ll + lkoffset);
	  do {
	      decr (label_ptr);
	  } while (!(label_loc[label_ptr]< ll));
	} 
      while (k++ < for_end);} 
      {register integer for_end; k = 0;for_end = nl - 1; if (k <= 
      for_end) do 
	tfm_qqqq (lig_kern[k]);
      while (k++ < for_end);} 
      {register integer for_end; k = 0;for_end = nk - 1; if (k <= 
      for_end) do 
	put4bytes (tfm_file , dimenout (kern[k]));
      while (k++ < for_end);} 
      {register integer for_end; k = 0;for_end = ne - 1; if (k <= 
      for_end) do 
	tfm_qqqq (exten[k]);
      while (k++ < for_end);} 
      {register integer for_end; k = 1;for_end = np; if (k <= for_end) do 
	if (k == 1) {
	    
	  if (abs (param[1]) < 134217728L) 
	  put4bytes (tfm_file , param[1]* 16);
	  else {
	      
	    incr (tfm_changed);
	    if (param[1] > 0) 
	    put4bytes (tfm_file , 2147483647L);
	    else put4bytes (tfm_file , -2147483647L);
	  } 
	} 
	else put4bytes (tfm_file , dimenout (param[k]));
      while (k++ < for_end);} 
      if (tfm_changed > 0) 
      {
	if (tfm_changed == 1) 
	print_nl (1050);
	else {
	    
	  print_nl (40);
	  print_int (tfm_changed);
	  print (1051);
	} 
	print (1052);
      } 
	;
#ifdef STAT
      if (internal[12] > 0) 
      {
	{ putc (' ' ,  log_file);  putc ('\n',  log_file); }
	if (bch_label < lig_table_size) 
	decr (nl);
	fprintf (log_file , "%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s\n",  "(You used " , (long)nw , "w," , (long)nh , "h," , (long)nd , "d," ,         (long)ni , "i," , (long)nl , "l," , (long)nk , "k," , (long)ne , "e," , (long)np ,         "p metric file positions");
	fprintf (log_file , "%s%s%ld%s%ld%s%ld%s\n",  "  out of " , "256w,16h,16d,64i," , (long)lig_table_size ,         "l," , (long)max_kerns , "k,256e," , (long)max_font_dimen , "p)");
      } 
#endif /* STAT */
      print_nl (1047);
      print_file_name (0 , metric_file_name , 0);
      print_char (46);
      bclose (tfm_file);
    } 
    if (gf_prev_ptr > 0) 
    {
      {
	gf_buf[gf_ptr] = 248;
	incr (gf_ptr);
	if (gf_ptr == gf_limit) 
	gf_swap ();
      } 
      gffour (gf_prev_ptr);
      gf_prev_ptr = gf_offset + gf_ptr - 5;
      gffour (internal[26]* 16);
      {register integer for_end; k = 1;for_end = 4; if (k <= for_end) do 
	{
	  gf_buf[gf_ptr] = header_byte[k];
	  incr (gf_ptr);
	  if (gf_ptr == gf_limit) 
	  gf_swap ();
	} 
      while (k++ < for_end);} 
      gffour (internal[27]);
      gffour (internal[28]);
      gffour (gf_min_m);
      gffour (gf_max_m);
      gffour (gf_min_n);
      gffour (gf_max_n);
      {register integer for_end; k = 0;for_end = 255; if (k <= for_end) 
      do 
	if (char_exists[k]) 
	{
	  x = gf_dx[k]/ 65536L;
	  if ((gf_dy[k] == 0) && (x >= 0) && (x < 256) && (gf_dx[k 
	] == x * 65536L)) 
	  {
	    {
	      gf_buf[gf_ptr] = 246;
	      incr (gf_ptr);
	      if (gf_ptr == gf_limit) 
	      gf_swap ();
	    } 
	    {
	      gf_buf[gf_ptr] = k;
	      incr (gf_ptr);
	      if (gf_ptr == gf_limit) 
	      gf_swap ();
	    } 
	    {
	      gf_buf[gf_ptr] = x;
	      incr (gf_ptr);
	      if (gf_ptr == gf_limit) 
	      gf_swap ();
	    } 
	  } 
	  else {
	      
	    {
	      gf_buf[gf_ptr] = 245;
	      incr (gf_ptr);
	      if (gf_ptr == gf_limit) 
	      gf_swap ();
	    } 
	    {
	      gf_buf[gf_ptr] = k;
	      incr (gf_ptr);
	      if (gf_ptr == gf_limit) 
	      gf_swap ();
	    } 
	    gffour (gf_dx[k]);
	    gffour (gf_dy[k]);
	  } 
	  x = mem[tfm_width[k]+ 1].cint;
	  if (abs (x) > max_tfm_dimen) {
	      
	    if (x > 0) 
	    x = 16777215L;
	    else x = -16777215L;
	  } 
	  else x = makescaled (x * 16 , internal[26]);
	  gffour (x);
	  gffour (char_ptr[k]);
	} 
      while (k++ < for_end);} 
      {
	gf_buf[gf_ptr] = 249;
	incr (gf_ptr);
	if (gf_ptr == gf_limit) 
	gf_swap ();
      } 
      gffour (gf_prev_ptr);
      {
	gf_buf[gf_ptr] = 131;
	incr (gf_ptr);
	if (gf_ptr == gf_limit) 
	gf_swap ();
      } 
      k = 4 + ((gf_buf_size - gf_ptr) % 4);
      while (k > 0) {
	  
	{
	  gf_buf[gf_ptr] = 223;
	  incr (gf_ptr);
	  if (gf_ptr == gf_limit) 
	  gf_swap ();
	} 
	decr (k);
      } 
      if (gf_limit == half_buf) 
      write_gf (half_buf , gf_buf_size - 1);
      if (gf_ptr > (2147483647L - gf_offset)) 
      {
	gf_prev_ptr = 0;
	fatal_error (1053);
      } 
      if (gf_ptr > 0) 
      write_gf (0 , gf_ptr - 1);
      print_nl (1064);
      print_file_name (0 , output_file_name , 0);
      print (558);
      print_int (total_chars);
      if (total_chars != 1) 
      print (1065);
      else print (1066);
      print (1067);
      print_int (gf_offset + gf_ptr);
      print (1068);
      bclose (gf_file);
    } 
  } 
  if (log_opened) 
  {
    putc ('\n',  log_file);
    aclose (log_file);
    selector = selector - 2;
    if (selector == 1) 
    {
      print_nl (1076);
      print_file_name (0 , texmflogname , 0);
      print_char (46);
    } 
  } 
  print_ln ();
  if ((editnamestart != 0) && (interaction > 0)) 
  calledit (str_pool , editnamestart , editname_length , editline);
} 
#ifdef TEXMF_DEBUG
void 
debughelp (void) 
{
  /* 888 10 */ integer k, l, m, n;
  while (true) {
      
;
    print_nl (1083);
    fflush (stdout);
    read (stdin , m);
    if (m < 0) 
    goto lab10;
    else if (m == 0) 
    {
      goto lab888;
      lab888: m = 0;
    } 
    else {
	
      read (stdin , n);
      switch (m) 
      {case 1 : 
	printword (mem[n]);
	break;
      case 2 : 
	print_int (mem[n].hhfield.lhfield);
	break;
      case 3 : 
	print_int (mem[n].hhfield.v.RH);
	break;
      case 4 : 
	{
	  print_int (eqtb[n].lhfield);
	  print_char (58);
	  print_int (eqtb[n].v.RH);
	} 
	break;
      case 5 : 
	print_variable_name (n);
	break;
      case 6 : 
	print_int (internal[n]);
	break;
      case 7 : 
	doshowdependencies ();
	break;
      case 9 : 
	show_token_list (n , 0 , 100000L , 0);
	break;
      case 10 : 
	slow_print (n);
	break;
      case 11 : 
	checkmem (n > 0);
	break;
      case 12 : 
	searchmem (n);
	break;
      case 13 : 
	{
	  read (stdin , l);
	  print_cmd_mod (n , l);
	} 
	break;
      case 14 : 
	{register integer for_end; k = 0;for_end = n; if (k <= for_end) 
	do 
	  print (buffer[k]);
	while (k++ < for_end);} 
	break;
      case 15 : 
	panicking = !panicking;
	break;
	default: 
	print (63);
	break;
      } 
    } 
  } 
  lab10:;
} 
#endif /* TEXMF_DEBUG */
