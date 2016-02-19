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
  deletionsallowed = true;
  errorcount = 0;
  help_ptr = 0;
  useerrhelp = false;
  errhelp = 0;
  interrupt = 0;
  OKtointerrupt = true;
  aritherror = false;
  twotothe[0] = 1;
  {register integer for_end; k = 1;for_end = 30; if (k <= for_end) do 
    twotothe[k] = 2 * twotothe[k - 1];
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
    spec_log[k] = twotothe[27 - k];
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
  wasmemend = 0;
  waslomax = 0;
  washimin = memmax;
  panicking = false;
#endif /* TEXMF_DEBUG */
  {register integer for_end; k = 1;for_end = 41; if (k <= for_end) do 
    internal[k] = 0;
  while (k++ < for_end);} 
  intptr = 41;
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
  bignodesize[13] = 12;
  bignodesize[14] = 4;
  saveptr = 0;
  octant_dir[1] = 548;
  octant_dir[5] = 549;
  octant_dir[6] = 550;
  octant_dir[2] = 551;
  octant_dir[4] = 552;
  octant_dir[8] = 553;
  octant_dir[7] = 554;
  octant_dir[3] = 555;
  maxroundingptr = 0;
  octant_code[1] = 1;
  octant_code[2] = 5;
  octant_code[3] = 6;
  octant_code[4] = 2;
  octant_code[5] = 4;
  octant_code[6] = 8;
  octant_code[7] = 7;
  octant_code[8] = 3;
  {register integer for_end; k = 1;for_end = 8; if (k <= for_end) do 
    octantnumber[octant_code[k]] = k;
  while (k++ < for_end);} 
  revturns = false;
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
    zcorr[k] = xy_corr[k] - x_corr[k];
  while (k++ < for_end);} 
  screenstarted = false;
  screenOK = false;
  {register integer for_end; k = 0;for_end = 15; if (k <= for_end) do 
    {
      windowopen[k] = false;
      windowtime[k] = 0;
    } 
  while (k++ < for_end);} 
  fixneeded = false;
  watchcoefs = true;
  condptr = 0;
  iflimit = 0;
  curif = 0;
  ifline = 0;
  loopptr = 0;
  cur_exp = 0;
  varflag = 0;
  startsym = 0;
  longhelpseen = false;
  {register integer for_end; k = 0;for_end = 255; if (k <= for_end) do 
    {
      tfmwidth[k] = 0;
      tfmheight[k] = 0;
      tfmdepth[k] = 0;
      tfmitalcorr[k] = 0;
      charexists[k] = false;
      chartag[k] = 0;
      charremainder[k] = 0;
      skiptable[k] = ligtablesize;
    } 
  while (k++ < for_end);} 
  {register integer for_end; k = 1;for_end = headersize; if (k <= 
  for_end) do 
    headerbyte[k] = -1;
  while (k++ < for_end);} 
  bc = 255;
  ec = 0;
  nl = 0;
  nk = 0;
  ne = 0;
  np = 0;
  internal[41] = -65536L;
  bchlabel = ligtablesize;
  labelloc[0] = -1;
  labelptr = 0;
  gfprevptr = 0;
  totalchars = 0;
  halfbuf = gf_buf_size / 2;
  gf_limit = gf_buf_size;
  gf_ptr = 0;
  gf_offset = 0;
  baseident = 0;
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
      putc ('\n',  logfile);
      term_offset = 0;
      file_offset = 0;
    } 
    break;
  case 2 : 
    {
      putc ('\n',  logfile);
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
      putc (xchr[s],  logfile);
      incr (term_offset);
      incr (file_offset);
      if (term_offset == maxprintline) 
      {
	putc ('\n',  stdout);
	term_offset = 0;
      } 
      if (file_offset == maxprintline) 
      {
	putc ('\n',  logfile);
	file_offset = 0;
      } 
    } 
    break;
  case 2 : 
    {
      putc (xchr[s],  logfile);
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
    if (tally < trickcount) 
    trickbuf[tally % errorline] = s;
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
  oldsetting = selector;
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
  selector = oldsetting;
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
  strref[s] = 0;
  else do {
      decr (str_ptr);
  } while (!(strref[str_ptr - 1]!= 0));
  pool_ptr = str_start[str_ptr];
} 
void 
jump_out (void) 
{
  closefilesandterminate ();
  {
    fflush (stdout);
    readyalready = 0;
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
      if (deletionsallowed) 
      {
	s1 = curcmd;
	s2 = curmod;
	s3 = cursym;
	OKtointerrupt = false;
	if ((last > first + 1) && (buffer[first + 1] >= 48) && (
	buffer[first + 1]<= 57)) 
	c = c * 10 + buffer[first + 1] - 48 * 11;
	else c = c - 48;
	while (c > 0) {
	    
	  getnext ();
	  if (curcmd == 39) 
	  {
	    if (strref[curmod]< 127) {
		
	      if (strref[curmod] > 1) 
	      decr (strref[curmod]);
	      else flush_string (curmod);
	    } 
	  } 
	  decr (c);
	} 
	curcmd = s1;
	curmod = s2;
	cursym = s3;
	OKtointerrupt = true;
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
      if (fileptr > 0) 
      {
	editnamestart = str_start[inputstack[fileptr].namefield];
	editnamelength = str_start[inputstack[fileptr].namefield + 1] - 
	str_start[inputstack[fileptr].namefield];
	editline = line;
	jump_out ();
      } 
      break;
    case 72 : 
      {
	if (useerrhelp) 
	{
	  j = str_start[errhelp];
	  while (j < str_start[errhelp + 1]) {
	      
	    if (str_pool[j]!= 37) 
	    print (str_pool[j]);
	    else if (j + 1 == str_start[errhelp + 1]) 
	    print_ln ();
	    else if (str_pool[j + 1]!= 37) 
	    print_ln ();
	    else {
		
	      incr (j);
	      print_char (37);
	    } 
	    incr (j);
	  } 
	  useerrhelp = false;
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
	  curinput.locfield = first + 1;
	  buffer[first] = 32;
	} 
	else {
	    
	  {
	;
	    print (277);
	    term_input ();
	  } 
	  curinput.locfield = first;
	} 
	first = last + 1;
	curinput .limitfield = last;
	goto lab10;
      } 
      break;
    case 81 : 
    case 82 : 
    case 83 : 
      {
	errorcount = 0;
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
      if (fileptr > 0) 
      print (269);
      if (deletionsallowed) 
      print_nl (270);
      print_nl (271);
    } 
  } 
  incr (errorcount);
  if (errorcount == 100) 
  {
    print_nl (264);
    history = 3;
    jump_out ();
  } 
  if (interaction > 0) 
  decr (selector);
  if (useerrhelp) 
  {
    print_nl (261);
    j = str_start[errhelp];
    while (j < str_start[errhelp + 1]) {
	
      if (str_pool[j]!= 37) 
      print (str_pool[j]);
      else if (j + 1 == str_start[errhelp + 1]) 
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
    if ((filelineerrorstylep && !(curinput .namefield == 0))) 
    {
      print_nl (261);
      print (fullsourcefilenamestack[inopen]);
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
    if (logopened) 
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
    if ((filelineerrorstylep && !(curinput .namefield == 0))) 
    {
      print_nl (261);
      print (fullsourcefilenamestack[inopen]);
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
    if (logopened) 
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
      if ((filelineerrorstylep && !(curinput .namefield == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[inopen]);
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
      if ((filelineerrorstylep && !(curinput .namefield == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[inopen]);
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
    if (logopened) 
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
    curinput.locfield = first;
    while ((curinput.locfield < last) && (buffer[curinput.locfield]
    == ' ')) incr (curinput.locfield);
    if (curinput.locfield < last) 
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
    curinput.locfield = first;
    while ((curinput.locfield < last) && (buffer[curinput.locfield]
    == 32)) incr (curinput.locfield);
    if (curinput.locfield < last) 
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
  register str_number Result; if (str_ptr == maxstr_ptr) 
  {
    if (str_ptr == maxstrings) 
    overflow (258 , maxstrings - initstr_ptr);
    incr (maxstr_ptr);
  } 
  strref[str_ptr] = 1;
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
  if (logopened) 
  selector = 3;
  else selector = 1;
  if (jobname == 0) 
  open_log_file ();
  if (interaction == 0) 
  decr (selector);
} 
void 
pause_for_instructions (void) 
{
  if (OKtointerrupt) 
  {
    interaction = 3;
    if ((selector == 2) || (selector == 0)) 
    incr (selector);
    {
      if (interaction == 3) 
  ;
      if ((filelineerrorstylep && !(curinput .namefield == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[inopen]);
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
    deletionsallowed = false;
    error ();
    deletionsallowed = true;
    interrupt = 0;
  } 
} 
void 
missing_err (str_number s) 
{
  {
    if (interaction == 3) 
;
    if ((filelineerrorstylep && !(curinput .namefield == 0))) 
    {
      print_nl (261);
      print (fullsourcefilenamestack[inopen]);
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
    if ((filelineerrorstylep && !(curinput .namefield == 0))) 
    {
      print_nl (261);
      print (fullsourcefilenamestack[inopen]);
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
  aritherror = false;
} 
integer 
slow_add (integer x , integer y) 
{
  register integer Result; if (x >= 0) {
      
    if (y <= 2147483647L - x) 
    Result = x + y;
    else {
	
      aritherror = true;
      Result = 2147483647L;
    } 
  } 
  else if (- (integer) y <= 2147483647L + x) 
  Result = x + y;
  else {
      
    aritherror = true;
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
    aritherror = true;
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
	
      aritherror = true;
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
    aritherror = true;
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
	
      aritherror = true;
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
    aritherror = true;
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
    aritherror = true;
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
	if ((filelineerrorstylep && !(curinput .namefield == 0))) 
	{
	  print_nl (261);
	  print (fullsourcefilenamestack[inopen]);
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
	  
	aritherror = true;
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
	if ((filelineerrorstylep && !(curinput .namefield == 0))) 
	{
	  print_nl (261);
	  print (fullsourcefilenamestack[inopen]);
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
      if ((filelineerrorstylep && !(curinput .namefield == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[inopen]);
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
	
      z = ((x - 1) / twotothe[k]) + 1;
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
    aritherror = true;
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
	y = y - 1 - ((y - twotothe[k - 1]) / twotothe[k]);
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
      if ((filelineerrorstylep && !(curinput .namefield == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[inopen]);
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
	  x = x + (y / twotothe[k + k]);
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
      x = t + y / twotothe[k];
      y = y - t / twotothe[k];
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
  ncos = makefraction (x , r);
  nsin = makefraction (y , r);
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
  jrandom = 54;
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
  if (jrandom == 0) 
  new_randoms ();
  else decr (jrandom);
  y = takefraction (abs (x) , randoms[jrandom]);
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
      do { if (jrandom == 0) 
      new_randoms ();
      else decr (jrandom);
      x = takefraction (112429L , randoms[jrandom] - 134217728L);
      if (jrandom == 0) 
      new_randoms ();
      else decr (jrandom);
      u = randoms[jrandom];
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
      firstcount = tally;
      trickcount = tally + 1 + errorline - halferrorline;
      if (trickcount < errorline) 
      trickcount = errorline;
    } 
    c = 9;
    if ((p < 0) || (p > memend)) 
    {
      print (493);
      goto lab10;
    } 
    if (p < himemmin) {
	
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
	  
	gpointer = p;
	printcapsule ();
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
  if (scannerstatus > 2) 
  {
    print_nl (638);
    switch (scannerstatus) 
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
  else if (memend < memmax) 
  {
    incr (memend);
    p = memend;
  } 
  else {
      
    decr (himemmin);
    p = himemmin;
    if (himemmin <= lomemmax) 
    {
      runaway ();
      overflow (315 , memmax + 1);
    } 
  } 
  mem[p].hhfield.v.RH = 0;
	;
#ifdef STAT
  incr (dynused);
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
  if (lomemmax + 2 < himemmin) {
      
    if (lomemmax + 2 <= 268435455L) 
    {
      if (himemmin - lomemmax >= 1998) 
      t = lomemmax + 1000;
      else t = lomemmax + 1 + (himemmin - lomemmax) / 2;
      if (t > 268435455L) 
      t = 268435455L;
      p = mem[rover + 1].hhfield.lhfield;
      q = lomemmax;
      mem[p + 1].hhfield.v.RH = q;
      mem[rover + 1].hhfield.lhfield = q;
      mem[q + 1].hhfield.v.RH = rover;
      mem[q + 1].hhfield.lhfield = p;
      mem[q].hhfield.v.RH = 268435455L;
      mem[q].hhfield.lhfield = t - lomemmax;
      lomemmax = t;
      mem[lomemmax].hhfield.v.RH = 0;
      mem[lomemmax].hhfield.lhfield = 0;
      rover = q;
      goto lab20;
    } 
  } 
  overflow (315 , memmax + 1);
  found: mem[r].hhfield.v.RH = 0;
	;
#ifdef STAT
  varused = varused + s;
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
  varused = varused - s;
#endif /* STAT */
} 
void 
flush_list (halfword p) 
{
  /* 30 */ halfword q, r;
  if (p >= himemmin) {
      
    if (p != memtop) 
    {
      r = p;
      do {
	  q = r;
	r = mem[r].hhfield.v.RH;
	;
#ifdef STAT
	decr (dynused);
#endif /* STAT */
	if (r < himemmin) 
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
    if (q < himemmin) 
    free_node (q , 2);
    else {
	
      mem[q].hhfield.v.RH = avail;
      avail = q;
	;
#ifdef STAT
      decr (dynused);
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
  {register integer for_end; p = 0;for_end = lomemmax; if (p <= for_end) 
  do 
    freearr[p] = false;
  while (p++ < for_end);} 
  {register integer for_end; p = himemmin;for_end = memend; if (p <= 
  for_end) do 
    freearr[p] = false;
  while (p++ < for_end);} 
  p = avail;
  q = 0;
  clobbered = false;
  while (p != 0) {
      
    if ((p > memend) || (p < himemmin)) 
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
      if ((p >= lomemmax)) 
    clobbered = true;
    else if ((mem[p + 1].hhfield.v.RH >= lomemmax)) 
    clobbered = true;
    else if (!((mem[p].hhfield.v.RH == 268435455L)) || (mem[p]
    .hhfield.lhfield < 2) || (p + mem[p].hhfield.lhfield > lomemmax) 
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
  while (p <= lomemmax) {
      
    if ((mem[p].hhfield.v.RH == 268435455L)) 
    {
      print_nl (319);
      print_int (p);
    } 
    while ((p <= lomemmax) && !freearr[p]) incr (p);
    while ((p <= lomemmax) && freearr[p]) incr (p);
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
    {register integer for_end; p = 0;for_end = lomemmax; if (p <= 
    for_end) do 
      if (!freearr[p]&& ((p > waslomax) || wasfree[p])) 
      {
	print_char (32);
	print_int (p);
      } 
    while (p++ < for_end);} 
    {register integer for_end; p = himemmin;for_end = memend; if (p <= 
    for_end) do 
      if (!freearr[p]&& ((p < washimin) || (p > wasmemend) || 
      wasfree[p])) 
      {
	print_char (32);
	print_int (p);
      } 
    while (p++ < for_end);} 
  } 
  {register integer for_end; p = 0;for_end = lomemmax; if (p <= for_end) 
  do 
    wasfree[p] = freearr[p];
  while (p++ < for_end);} 
  {register integer for_end; p = himemmin;for_end = memend; if (p <= 
  for_end) do 
    wasfree[p] = freearr[p];
  while (p++ < for_end);} 
  wasmemend = memend;
  waslomax = lomemmax;
  washimin = himemmin;
} 
#endif /* TEXMF_DEBUG */
#ifdef TEXMF_DEBUG
void 
zsearchmem (halfword p) 
{
  integer q;
  {register integer for_end; q = 0;for_end = lomemmax; if (q <= for_end) 
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
  {register integer for_end; q = himemmin;for_end = memend; if (q <= 
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
	    if ((hashused == 257)) 
	  overflow (457 , 9500);
	  decr (hashused);
	} while (!(hash[hashused].v.RH == 0));
	hash[p].lhfield = hashused;
	p = hashused;
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
      strref[hash[p].v.RH] = 127;
	;
#ifdef STAT
      incr (stcount);
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
    if (q >= himemmin) 
    {
      mem[q].hhfield.v.RH = avail;
      avail = q;
	;
#ifdef STAT
      decr (dynused);
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
	  if (strref[mem[q + 1].cint]< 127) {
	      
	    if (strref[mem[q + 1].cint] > 1) 
	    decr (strref[mem[q + 1].cint]);
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
	  gpointer = q;
	  tokenrecycle ();
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
    slow_print (intname[m]);
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
  s = bignodesize[mem[p].hhfield.b0];
  q = get_node (s);
  do {
      s = s - 2;
    {
      if (serialno > 2147483583L) 
      overflow (588 , serialno / 64);
      mem[q + s].hhfield.b0 = 19;
      serialno = serialno + 64;
      mem[q + s + 1].cint = serialno;
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
    if (t < himemmin) 
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
	  print_scaled (ncos);
	  print_char (44);
	  print_scaled (nsin);
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
	print_scaled (ncos);
	print_char (44);
	print_scaled (nsin);
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
  m = (d / 8) - mem[curedges + 3].hhfield.lhfield;
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
  p = mem[curedges].hhfield.lhfield;
  n = mem[curedges + 1].hhfield.v.RH - 4096;
  while (p != curedges) {
      
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
	  curedges = v;
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
      q = v + bignodesize[t];
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
	    
	  if (watchcoefs) 
	  {
	    mem[qq].hhfield.b0 = 0;
	    fixneeded = true;
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
	  
	if (watchcoefs) 
	{
	  mem[qq].hhfield.b0 = 0;
	  fixneeded = true;
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
  depfinal = p;
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
	fixneeded = true;
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
      if ((filelineerrorstylep && !(curinput .namefield == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[inopen]);
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
      decr (dynused);
#endif /* STAT */
    } 
    s = p;
    mem[x].hhfield.b0 = 19;
    mem[x + 1].cint = mem[x + 1].cint + 2;
  } 
  fixneeded = false;
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
      if (strref[v]< 127) {
	  
	if (strref[v] > 1) 
	decr (strref[v]);
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
      q = v + bignodesize[t];
      do {
	  q = q - 2;
	recycle_value (q);
      } while (!(q == v));
      free_node (v , bignodesize[t]);
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
      maxc[17] = 0;
      maxc[18] = 0;
      maxlink[17] = 0;
      maxlink[18] = 0;
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
	    if (abs (mem[r + 1].cint) > maxc[t]) 
	    {
	      if (maxc[t] > 0) 
	      {
		mem[maxptr[t]].hhfield.v.RH = maxlink[t];
		maxlink[t] = maxptr[t];
	      } 
	      maxc[t] = abs (mem[r + 1].cint);
	      maxptr[t] = r;
	    } 
	    else {
		
	      mem[r].hhfield.v.RH = maxlink[t];
	      maxlink[t] = r;
	    } 
	  } 
	} 
	done: q = mem[r].hhfield.v.RH;
      } 
      if ((maxc[17] > 0) || (maxc[18] > 0)) 
      {
	if ((maxc[17]/ 4096 >= maxc[18])) 
	t = 17;
	else t = 18;
	s = maxptr[t];
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
	  if (serialno > 2147483583L) 
	  overflow (588 , serialno / 64);
	  mem[pp].hhfield.b0 = 19;
	  serialno = serialno + 64;
	  mem[pp + 1].cint = serialno;
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
	    vv = roundfraction (maxc[17]);
	    else vv = maxc[18];
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
	if (maxc[t] > 0) 
	{
	  mem[maxptr[t]].hhfield.v.RH = maxlink[t];
	  maxlink[t] = maxptr[t];
	} 
	if (t != 17) 
	{register integer for_end; t = 17;for_end = 18; if (t <= for_end) 
	do 
	  {
	    r = maxlink[t];
	    while (r != 0) {
		
	      q = mem[r].hhfield.lhfield;
	      mem[q + 1].hhfield.v.RH = p_plus_fq (mem[q + 1].hhfield 
	    .v.RH , makefraction (mem[r + 1].cint , - (integer) v) , s 
	      , t , 17);
	      if (mem[q + 1].hhfield.v.RH == depfinal) 
	      make_known (q , depfinal);
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
	    r = maxlink[t];
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
	      if (mem[q + 1].hhfield.v.RH == depfinal) 
	      make_known (q , depfinal);
	      q = r;
	      r = mem[r].hhfield.v.RH;
	      free_node (q , 2);
	    } 
	  } 
	while (t++ < for_end);} 
	flush_node_list (s);
	if (fixneeded) 
	fix_dependencies ();
	{
	  if (aritherror) 
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
      if (strref[cur_exp]< 127) {
	  
	if (strref[cur_exp] > 1) 
	decr (strref[cur_exp]);
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
  if (saveptr != 0) 
  {
    p = get_node (2);
    mem[p].hhfield.lhfield = q;
    mem[p].hhfield.v.RH = saveptr;
    mem[p + 1].hhfield = eqtb[q];
    saveptr = p;
  } 
  clearsymbol (q , (saveptr != 0));
} 
void 
zsaveinternal (halfword q) 
{
  halfword p;
  if (saveptr != 0) 
  {
    p = get_node (2);
    mem[p].hhfield.lhfield = 9769 + q;
    mem[p].hhfield.v.RH = saveptr;
    mem[p + 1].cint = internal[q];
    saveptr = p;
  } 
} 
void 
unsave (void) 
{
  halfword q;
  halfword p;
  while (mem[saveptr].hhfield.lhfield != 0) {
      
    q = mem[saveptr].hhfield.lhfield;
    if (q > 9769) 
    {
      if (internal[8] > 0) 
      {
	begin_diagnostic ();
	print_nl (516);
	slow_print (intname[q - (9769)]);
	print_char (61);
	print_scaled (mem[saveptr + 1].cint);
	print_char (125);
	end_diagnostic (false);
      } 
      internal[q - (9769)] = mem[saveptr + 1].cint;
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
      eqtb[q] = mem[saveptr + 1].hhfield;
      if (eqtb[q].lhfield % 86 == 41) 
      {
	p = eqtb[q].v.RH;
	if (p != 0) 
	mem[p].hhfield.b1 = 0;
      } 
    } 
    p = mem[saveptr].hhfield.v.RH;
    free_node (saveptr , 2);
    saveptr = p;
  } 
  p = mem[saveptr].hhfield.v.RH;
  {
    mem[saveptr].hhfield.v.RH = avail;
    avail = saveptr;
	;
#ifdef STAT
    decr (dynused);
#endif /* STAT */
  } 
  saveptr = p;
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
      pathtail = pp;
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
zcurlratio (scaled gamma , scaled atension , scaled btension) 
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
zsetcontrols (halfword p , halfword q , integer k) 
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
  deltax[k], ct) - takefraction (deltay[k], st) , rr);
  mem[p + 6].cint = mem[p + 2].cint + takefraction (takefraction (
  deltay[k], ct) + takefraction (deltax[k], st) , rr);
  mem[q + 3].cint = mem[q + 1].cint - takefraction (takefraction (
  deltax[k], cf) + takefraction (deltay[k], sf) , ss);
  mem[q + 4].cint = mem[q + 2].cint - takefraction (takefraction (
  deltay[k], cf) - takefraction (deltax[k], sf) , ss);
  mem[p].hhfield.b1 = 1;
  mem[q].hhfield.b0 = 1;
} 
void 
zsolvechoices (halfword p , halfword q , halfword n) 
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
	aa = n_arg (deltax[0], deltay[0]);
	n_sin_cos (mem[p + 5].cint - aa);
	ct = ncos;
	st = nsin;
	n_sin_cos (mem[q + 3].cint - aa);
	cf = ncos;
	sf = - (integer) nsin;
	setcontrols (p , q , 0);
	goto lab10;
      } 
      else {
	  
	vv[0] = mem[s + 5].cint - n_arg (deltax[0], deltay[0]) 
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
	  if (deltax[0] >= 0) 
	  mem[p + 5].cint = mem[p + 1].cint + ((deltax[0]+ 1) / 
	  3);
	  else mem[p + 5].cint = mem[p + 1].cint + ((deltax[0] - 
	  1) / 3);
	  if (deltay[0] >= 0) 
	  mem[p + 6].cint = mem[p + 2].cint + ((deltay[0]+ 1) / 
	  3);
	  else mem[p + 6].cint = mem[p + 2].cint + ((deltay[0] - 
	  1) / 3);
	} 
	else {
	    
	  ff = makefraction (65536L , 3 * rt);
	  mem[p + 5].cint = mem[p + 1].cint + takefraction (deltax[
	  0], ff);
	  mem[p + 6].cint = mem[p + 2].cint + takefraction (deltay[
	  0], ff);
	} 
	if (lt == 65536L) 
	{
	  if (deltax[0] >= 0) 
	  mem[q + 3].cint = mem[q + 1].cint - ((deltax[0]+ 1) / 
	  3);
	  else mem[q + 3].cint = mem[q + 1].cint - ((deltax[0] - 
	  1) / 3);
	  if (deltay[0] >= 0) 
	  mem[q + 4].cint = mem[q + 2].cint - ((deltay[0]+ 1) / 
	  3);
	  else mem[q + 4].cint = mem[q + 2].cint - ((deltay[0] - 
	  1) / 3);
	} 
	else {
	    
	  ff = makefraction (65536L , 3 * lt);
	  mem[q + 3].cint = mem[q + 1].cint - takefraction (deltax[
	  0], ff);
	  mem[q + 4].cint = mem[q + 2].cint - takefraction (deltay[
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
	else uu[0] = curlratio (cc , rt , lt);
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
	else ff = curlratio (cc , lt , rt);
	theta[n] = - (integer) makefraction (takefraction (vv[n - 1], 
	ff) , 268435456L - takefraction (ff , uu[n - 1]));
	goto found;
      } 
      break;
    case 2 : 
      {
	theta[n] = mem[s + 3].cint - n_arg (deltax[n - 1], deltay[
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
    st = nsin;
    ct = ncos;
    n_sin_cos (- (integer) psi[k + 1] - theta[k + 1]);
    sf = nsin;
    cf = ncos;
    setcontrols (s , t , k);
    incr (k);
    s = t;
  } while (!(k == n));
  lab10:;
} 
void 
zmakechoices (halfword knots) 
{
  /* 30 */ halfword h;
  halfword p, q;
  integer k, n;
  halfword s, t;
  scaled delx, dely;
  fraction sine, cosine;
  {
    if (aritherror) 
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
	deltax[k] = mem[t + 1].cint - mem[s + 1].cint;
	deltay[k] = mem[t + 2].cint - mem[s + 2].cint;
	delta[k] = pyth_add (deltax[k], deltay[k]);
	if (k > 0) 
	{
	  sine = makefraction (deltay[k - 1], delta[k - 1]);
	  cosine = makefraction (deltax[k - 1], delta[k - 1]);
	  psi[k] = n_arg (takefraction (deltax[k], cosine) + 
	  takefraction (deltay[k], sine) , takefraction (deltay[k], 
	  cosine) - takefraction (deltax[k], sine));
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
      solvechoices (p , q , n);
    } 
    p = q;
  } while (!(p == h));
  if (internal[4] > 0) 
  print_path (knots , 527 , true);
  if (aritherror) 
  {
    {
      if (interaction == 3) 
  ;
      if ((filelineerrorstylep && !(curinput .namefield == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[inopen]);
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
    aritherror = false;
  } 
} 
void 
zmakemoves (scaled xx0 , scaled xx1 , scaled xx2 , scaled xx3 , scaled yy0 , 
scaled yy1 , scaled yy2 , scaled yy3 , small_number xicorr , small_number 
etacorr) 
{
  /* 22 30 10 */ integer x1, x2, x3, m, r, y1, y2, y3, n, s, l;
  integer q, t, u, x2a, x3a, y2a, y3a;
  if ((xx3 < xx0) || (yy3 < yy0)) 
  confusion (109);
  l = 16;
  bisectptr = 0;
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
	
      incr (moveptr);
      move[moveptr] = 1;
      decr (n);
    } 
    else if (n == 0) 
    move[moveptr] = move[moveptr]+ m;
    else if (m + n == 2) 
    {
      r = twotothe[l] - r;
      s = twotothe[l] - s;
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
	      incr (moveptr);
	      move[moveptr] = 2;
	    } 
	    goto done;
	  } 
	} 
	else if (u < s) 
	{
	  {
	    incr (move[moveptr]);
	    incr (moveptr);
	    move[moveptr] = 1;
	  } 
	  goto done;
	} 
	incr (l);
      } 
      r = r - xicorr;
      s = s - etacorr;
      if (ab_vs_cd (x1 + x2 + x3 , s , y1 + y2 + y3 , r) - xicorr >= 0) 
      {
	incr (move[moveptr]);
	incr (moveptr);
	move[moveptr] = 1;
      } 
      else {
	  
	incr (moveptr);
	move[moveptr] = 2;
      } 
      done:;
    } 
    else {
	
      incr (l);
      bisectstack[bisectptr + 10] = l;
      bisectstack[bisectptr + 2] = x3;
      bisectstack[bisectptr + 1] = half (x2 + x3 + xicorr);
      x2 = half (x1 + x2 + xicorr);
      x3 = half (x2 + bisectstack[bisectptr + 1]+ xicorr);
      bisectstack[bisectptr] = x3;
      r = r + r + xicorr;
      t = x1 + x2 + x3 + r;
      q = t / twotothe[l];
      bisectstack[bisectptr + 3] = t % twotothe[l];
      bisectstack[bisectptr + 4] = m - q;
      m = q;
      bisectstack[bisectptr + 7] = y3;
      bisectstack[bisectptr + 6] = half (y2 + y3 + etacorr);
      y2 = half (y1 + y2 + etacorr);
      y3 = half (y2 + bisectstack[bisectptr + 6]+ etacorr);
      bisectstack[bisectptr + 5] = y3;
      s = s + s + etacorr;
      u = y1 + y2 + y3 + s;
      q = u / twotothe[l];
      bisectstack[bisectptr + 8] = u % twotothe[l];
      bisectstack[bisectptr + 9] = n - q;
      n = q;
      bisectptr = bisectptr + 11;
      goto lab22;
    } 
    if (bisectptr == 0) 
    goto lab10;
    bisectptr = bisectptr - 11;
    x1 = bisectstack[bisectptr];
    x2 = bisectstack[bisectptr + 1];
    x3 = bisectstack[bisectptr + 2];
    r = bisectstack[bisectptr + 3];
    m = bisectstack[bisectptr + 4];
    y1 = bisectstack[bisectptr + 5];
    y2 = bisectstack[bisectptr + 6];
    y3 = bisectstack[bisectptr + 7];
    s = bisectstack[bisectptr + 8];
    n = bisectstack[bisectptr + 9];
    l = bisectstack[bisectptr + 10];
  } 
  lab10:;
} 
void 
zsmoothmoves (integer b , integer t) 
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
zinitedges (halfword h) 
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
fixoffset (void) 
{
  halfword p, q;
  integer delta;
  delta = 8 * (mem[curedges + 3].hhfield.lhfield - 4096);
  mem[curedges + 3].hhfield.lhfield = 4096;
  q = mem[curedges].hhfield.v.RH;
  while (q != curedges) {
      
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
zedgeprep (integer ml , integer mr , integer nl , integer nr) 
{
  halfword delta;
  integer temp;
  halfword p, q;
  ml = ml + 4096;
  mr = mr + 4096;
  nl = nl + 4096;
  nr = nr + 4095;
  if (ml < mem[curedges + 2].hhfield.lhfield) 
  mem[curedges + 2].hhfield.lhfield = ml;
  if (mr > mem[curedges + 2].hhfield.v.RH) 
  mem[curedges + 2].hhfield.v.RH = mr;
  temp = mem[curedges + 3].hhfield.lhfield - 4096;
  if (!(abs (mem[curedges + 2].hhfield.lhfield + temp - 4096) < 4096 
) || !(abs (mem[curedges + 2].hhfield.v.RH + temp - 4096) < 4096) 
) 
  fixoffset ();
  if (mem[curedges].hhfield.v.RH == curedges) 
  {
    mem[curedges + 1].hhfield.lhfield = nr + 1;
    mem[curedges + 1].hhfield.v.RH = nr;
  } 
  if (nl < mem[curedges + 1].hhfield.lhfield) 
  {
    delta = mem[curedges + 1].hhfield.lhfield - nl;
    mem[curedges + 1].hhfield.lhfield = nl;
    p = mem[curedges].hhfield.v.RH;
    do {
	q = get_node (2);
      mem[q + 1].hhfield.v.RH = memtop;
      mem[q + 1].hhfield.lhfield = 1;
      mem[p].hhfield.lhfield = q;
      mem[q].hhfield.v.RH = p;
      p = q;
      decr (delta);
    } while (!(delta == 0));
    mem[p].hhfield.lhfield = curedges;
    mem[curedges].hhfield.v.RH = p;
    if (mem[curedges + 5].hhfield.v.RH == curedges) 
    mem[curedges + 5].hhfield.lhfield = nl - 1;
  } 
  if (nr > mem[curedges + 1].hhfield.v.RH) 
  {
    delta = nr - mem[curedges + 1].hhfield.v.RH;
    mem[curedges + 1].hhfield.v.RH = nr;
    p = mem[curedges].hhfield.lhfield;
    do {
	q = get_node (2);
      mem[q + 1].hhfield.v.RH = memtop;
      mem[q + 1].hhfield.lhfield = 1;
      mem[p].hhfield.v.RH = q;
      mem[q].hhfield.lhfield = p;
      p = q;
      decr (delta);
    } while (!(delta == 0));
    mem[p].hhfield.v.RH = curedges;
    mem[curedges].hhfield.lhfield = p;
    if (mem[curedges + 5].hhfield.v.RH == curedges) 
    mem[curedges + 5].hhfield.lhfield = nr + 1;
  } 
} 
halfword 
zcopyedges (halfword h) 
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
yreflectedges (void) 
{
  halfword p, q, r;
  p = mem[curedges + 1].hhfield.lhfield;
  mem[curedges + 1].hhfield.lhfield = 8191 - mem[curedges + 1]
  .hhfield.v.RH;
  mem[curedges + 1].hhfield.v.RH = 8191 - p;
  mem[curedges + 5].hhfield.lhfield = 8191 - mem[curedges + 5]
  .hhfield.lhfield;
  p = mem[curedges].hhfield.v.RH;
  q = curedges;
  do {
      r = mem[p].hhfield.v.RH;
    mem[p].hhfield.v.RH = q;
    mem[q].hhfield.lhfield = p;
    q = p;
    p = r;
  } while (!(q == curedges));
  mem[curedges + 4].cint = 0;
} 
void 
xreflectedges (void) 
{
  halfword p, q, r, s;
  integer m;
  p = mem[curedges + 2].hhfield.lhfield;
  mem[curedges + 2].hhfield.lhfield = 8192 - mem[curedges + 2]
  .hhfield.v.RH;
  mem[curedges + 2].hhfield.v.RH = 8192 - p;
  m = (4096 + mem[curedges + 3].hhfield.lhfield) * 8 + 8;
  mem[curedges + 3].hhfield.lhfield = 4096;
  p = mem[curedges].hhfield.v.RH;
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
  } while (!(p == curedges));
  mem[curedges + 4].cint = 0;
} 
void 
zyscaleedges (integer s) 
{
  halfword p, q, pp, r, rr, ss;
  integer t;
  if ((s * (mem[curedges + 1].hhfield.v.RH - 4095) >= 4096) || (s * 
  (mem[curedges + 1].hhfield.lhfield - 4096) <= -4096)) 
  {
    {
      if (interaction == 3) 
  ;
      if ((filelineerrorstylep && !(curinput .namefield == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[inopen]);
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
      
    mem[curedges + 1].hhfield.v.RH = s * (mem[curedges + 1].hhfield 
  .v.RH - 4095) + 4095;
    mem[curedges + 1].hhfield.lhfield = s * (mem[curedges + 1]
    .hhfield.lhfield - 4096) + 4096;
    p = curedges;
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
    } while (!(mem[p].hhfield.v.RH == curedges));
    mem[curedges + 4].cint = 0;
  } 
} 
void 
zxscaleedges (integer s) 
{
  halfword p, q;
  unsigned short t;
  unsigned char w;
  integer delta;
  if ((s * (mem[curedges + 2].hhfield.v.RH - 4096) >= 4096) || (s * 
  (mem[curedges + 2].hhfield.lhfield - 4096) <= -4096)) 
  {
    {
      if (interaction == 3) 
  ;
      if ((filelineerrorstylep && !(curinput .namefield == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[inopen]);
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
  else if ((mem[curedges + 2].hhfield.v.RH != 4096) || (mem[
  curedges + 2].hhfield.lhfield != 4096)) 
  {
    mem[curedges + 2].hhfield.v.RH = s * (mem[curedges + 2].hhfield 
  .v.RH - 4096) + 4096;
    mem[curedges + 2].hhfield.lhfield = s * (mem[curedges + 2]
    .hhfield.lhfield - 4096) + 4096;
    delta = 8 * (4096 - s * mem[curedges + 3].hhfield.lhfield) + 0;
    mem[curedges + 3].hhfield.lhfield = 4096;
    q = mem[curedges].hhfield.v.RH;
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
    } while (!(q == curedges));
    mem[curedges + 4].cint = 0;
  } 
} 
void 
znegateedges (halfword h) 
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
zsortedges (halfword h) 
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
zculledges (integer wlo , integer whi , integer wout , integer win) 
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
  p = mem[curedges].hhfield.v.RH;
  n = mem[curedges + 1].hhfield.lhfield;
  while (p != curedges) {
      
    if (mem[p + 1].hhfield.lhfield > 1) 
    sortedges (p);
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
	  decr (dynused);
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
    p = mem[curedges].hhfield.v.RH;
    while (p != curedges) {
	
      q = mem[p].hhfield.v.RH;
      free_node (p , 2);
      p = q;
    } 
    initedges (curedges);
  } 
  else {
      
    n = mem[curedges + 1].hhfield.lhfield;
    mem[curedges + 1].hhfield.lhfield = minn;
    while (minn > n) {
	
      p = mem[curedges].hhfield.v.RH;
      mem[curedges].hhfield.v.RH = mem[p].hhfield.v.RH;
      mem[mem[p].hhfield.v.RH].hhfield.lhfield = curedges;
      free_node (p , 2);
      incr (n);
    } 
    n = mem[curedges + 1].hhfield.v.RH;
    mem[curedges + 1].hhfield.v.RH = maxn;
    mem[curedges + 5].hhfield.lhfield = maxn + 1;
    mem[curedges + 5].hhfield.v.RH = curedges;
    while (maxn < n) {
	
      p = mem[curedges].hhfield.lhfield;
      mem[curedges].hhfield.lhfield = mem[p].hhfield.lhfield;
      mem[mem[p].hhfield.lhfield].hhfield.v.RH = curedges;
      free_node (p , 2);
      decr (n);
    } 
    mem[curedges + 2].hhfield.lhfield = ((mind) / 8) - mem[curedges 
    + 3].hhfield.lhfield + 4096;
    mem[curedges + 2].hhfield.v.RH = ((maxd) / 8) - mem[curedges + 
    3].hhfield.lhfield + 4096;
  } 
  mem[curedges + 4].cint = 0;
} 
void 
xyswapedges (void) 
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
  mspread = mem[curedges + 2].hhfield.v.RH - mem[curedges + 2]
  .hhfield.lhfield;
  if (mspread > movesize) 
  overflow (540 , movesize);
  {register integer for_end; j = 0;for_end = mspread; if (j <= for_end) 
  do 
    move[j] = memtop;
  while (j++ < for_end);} 
  p = get_node (2);
  mem[p + 1].hhfield.v.RH = memtop;
  mem[p + 1].hhfield.lhfield = 0;
  mem[p].hhfield.lhfield = curedges;
  mem[mem[curedges].hhfield.v.RH].hhfield.lhfield = p;
  p = get_node (2);
  mem[p + 1].hhfield.v.RH = memtop;
  mem[p].hhfield.lhfield = mem[curedges].hhfield.lhfield;
  mmagic = mem[curedges + 2].hhfield.lhfield + mem[curedges + 3]
  .hhfield.lhfield - 4096;
  nmagic = 8 * mem[curedges + 1].hhfield.v.RH + 12;
  do {
      q = mem[p].hhfield.lhfield;
    if (mem[q + 1].hhfield.lhfield > 1) 
    sortedges (q);
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
	  if (mm - mmagic >= movesize) 
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
	  decr (dynused);
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
  } while (!(mem[p].hhfield.lhfield == curedges));
  free_node (p , 2);
  move[mspread] = 0;
  j = 0;
  while (move[j] == memtop) incr (j);
  if (j == mspread) 
  initedges (curedges);
  else {
      
    mm = mem[curedges + 2].hhfield.lhfield;
    mem[curedges + 2].hhfield.lhfield = mem[curedges + 1].hhfield 
  .lhfield;
    mem[curedges + 2].hhfield.v.RH = mem[curedges + 1].hhfield.v.RH 
    + 1;
    mem[curedges + 3].hhfield.lhfield = 4096;
    jj = mspread - 1;
    while (move[jj] == memtop) decr (jj);
    mem[curedges + 1].hhfield.lhfield = j + mm;
    mem[curedges + 1].hhfield.v.RH = jj + mm;
    q = curedges;
    do {
	p = get_node (2);
      mem[q].hhfield.v.RH = p;
      mem[p].hhfield.lhfield = q;
      mem[p + 1].hhfield.v.RH = move[j];
      mem[p + 1].hhfield.lhfield = 0;
      incr (j);
      q = p;
    } while (!(j > jj));
    mem[q].hhfield.v.RH = curedges;
    mem[curedges].hhfield.lhfield = q;
    mem[curedges + 5].hhfield.lhfield = mem[curedges + 1].hhfield 
  .v.RH + 1;
    mem[curedges + 5].hhfield.v.RH = curedges;
    mem[curedges + 4].cint = 0;
  } 
} 
void 
zmergeedges (halfword h) 
{
  /* 30 */ halfword p, q, r, pp, qq, rr;
  integer n;
  halfword k;
  integer delta;
  if (mem[h].hhfield.v.RH != h) 
  {
    if ((mem[h + 2].hhfield.lhfield < mem[curedges + 2].hhfield 
  .lhfield) || (mem[h + 2].hhfield.v.RH > mem[curedges + 2]
    .hhfield.v.RH) || (mem[h + 1].hhfield.lhfield < mem[curedges + 1 
  ].hhfield.lhfield) || (mem[h + 1].hhfield.v.RH > mem[curedges + 
    1].hhfield.v.RH)) 
    edgeprep (mem[h + 2].hhfield.lhfield - 4096 , mem[h + 2].hhfield 
  .v.RH - 4096 , mem[h + 1].hhfield.lhfield - 4096 , mem[h + 1]
    .hhfield.v.RH - 4095);
    if (mem[h + 3].hhfield.lhfield != mem[curedges + 3].hhfield 
  .lhfield) 
    {
      pp = mem[h].hhfield.v.RH;
      delta = 8 * (mem[curedges + 3].hhfield.lhfield - mem[h + 3]
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
    n = mem[curedges + 1].hhfield.lhfield;
    p = mem[curedges].hhfield.v.RH;
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
ztotalweight (halfword h) 
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
beginedgetracing (void) 
{
  print_diagnostic (541 , 261 , true);
  print (542);
  print_int (curwt);
  print_char (41);
  tracex = -4096;
} 
void 
traceacorner (void) 
{
  if (file_offset > maxprintline - 13) 
  print_nl (261);
  print_char (40);
  print_int (tracex);
  print_char (44);
  print_int (traceyy);
  print_char (41);
  tracey = traceyy;
} 
void 
endedgetracing (void) 
{
  if (tracex == -4096) 
  print_nl (543);
  else {
      
    traceacorner ();
    print_char (46);
  } 
  end_diagnostic (true);
} 
void 
ztracenewedge (halfword r , integer n) 
{
  integer d;
  schar w;
  integer m, n0, n1;
  d = mem[r].hhfield.lhfield;
  w = (d % 8) - 4;
  m = (d / 8) - mem[curedges + 3].hhfield.lhfield;
  if (w == curwt) 
  {
    n0 = n + 1;
    n1 = n;
  } 
  else {
      
    n0 = n;
    n1 = n + 1;
  } 
  if (m != tracex) 
  {
    if (tracex == -4096) 
    {
      print_nl (261);
      traceyy = n0;
    } 
    else if (traceyy != n0) 
    print_char (63);
    else traceacorner ();
    tracex = m;
    traceacorner ();
  } 
  else {
      
    if (n0 != traceyy) 
    print_char (33);
    if (((n0 < n1) && (tracey > traceyy)) || ((n0 > n1) && (tracey 
    < traceyy))) 
    traceacorner ();
  } 
  traceyy = n1;
} 
void 
zlineedges (scaled x0 , scaled y0 , scaled x1 , scaled y1) 
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
      base = 8 * mem[curedges + 3].hhfield.lhfield + 4 - curwt;
      if (m0 <= m1) 
      edgeprep (m0 , m1 , n0 , n1);
      else edgeprep (m1 , m0 , n0 , n1);
      n = mem[curedges + 5].hhfield.lhfield - 4096;
      p = mem[curedges + 5].hhfield.v.RH;
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
	tracenewedge (r , n);
	if (y1 < 65536L) 
	goto done;
	p = mem[p].hhfield.v.RH;
	y0 = y0 + 65536L;
	incr (n);
      } 
      done:;
    } 
    else {
	
      base = 8 * mem[curedges + 3].hhfield.lhfield + 4 + curwt;
      if (m0 <= m1) 
      edgeprep (m0 , m1 , n1 , n0);
      else edgeprep (m1 , m0 , n1 , n0);
      decr (n0);
      n = mem[curedges + 5].hhfield.lhfield - 4096;
      p = mem[curedges + 5].hhfield.v.RH;
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
	tracenewedge (r , n);
	if (y1 >= 0) 
	goto done1;
	p = mem[p].hhfield.lhfield;
	y0 = y0 + 65536L;
	decr (n);
      } 
      done1:;
    } 
    mem[curedges + 5].hhfield.v.RH = p;
    mem[curedges + 5].hhfield.lhfield = n + 4096;
  } 
} 
void 
zmovetoedges (integer m0 , integer n0 , integer m1 , integer n1) 
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
      edgeprep (m0 , m1 , n0 , n1);
      goto lab60;
    } 
    break;
  case 5 : 
    {
      dx = 8;
      edgeprep (n0 , n1 , m0 , m1);
      goto lab62;
    } 
    break;
  case 6 : 
    {
      dx = -8;
      edgeprep (- (integer) n1 , - (integer) n0 , m0 , m1);
      n0 = - (integer) n0;
      goto lab62;
    } 
    break;
  case 2 : 
    {
      dx = -8;
      edgeprep (- (integer) m1 , - (integer) m0 , n0 , n1);
      m0 = - (integer) m0;
      goto lab60;
    } 
    break;
  case 4 : 
    {
      dx = -8;
      edgeprep (- (integer) m1 , - (integer) m0 , - (integer) n1 , 
      - (integer) n0);
      m0 = - (integer) m0;
      goto lab61;
    } 
    break;
  case 8 : 
    {
      dx = -8;
      edgeprep (- (integer) n1 , - (integer) n0 , - (integer) m1 , 
      - (integer) m0);
      n0 = - (integer) n0;
      goto lab63;
    } 
    break;
  case 7 : 
    {
      dx = 8;
      edgeprep (n0 , n1 , - (integer) m1 , - (integer) m0);
      goto lab63;
    } 
    break;
  case 3 : 
    {
      dx = 8;
      edgeprep (m0 , m1 , - (integer) n1 , - (integer) n0);
      goto lab61;
    } 
    break;
  } 
  lab60: n = mem[curedges + 5].hhfield.lhfield - 4096;
  p = mem[curedges + 5].hhfield.v.RH;
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
    edgeandweight = 8 * (m0 + mem[curedges + 3].hhfield.lhfield) + 4 - 
    curwt;
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
	  incr (dynused);
#endif /* STAT */
	} 
      } 
      mem[r].hhfield.v.RH = mem[p + 1].hhfield.lhfield;
      mem[r].hhfield.lhfield = edgeandweight;
      if (internal[10] > 0) 
      tracenewedge (r , n);
      mem[p + 1].hhfield.lhfield = r;
      p = mem[p].hhfield.v.RH;
      incr (k);
      incr (n);
    } while (!(k == delta));
  } 
  goto done;
  lab61: n0 = - (integer) n0 - 1;
  n = mem[curedges + 5].hhfield.lhfield - 4096;
  p = mem[curedges + 5].hhfield.v.RH;
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
    edgeandweight = 8 * (m0 + mem[curedges + 3].hhfield.lhfield) + 4 + 
    curwt;
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
	  incr (dynused);
#endif /* STAT */
	} 
      } 
      mem[r].hhfield.v.RH = mem[p + 1].hhfield.lhfield;
      mem[r].hhfield.lhfield = edgeandweight;
      if (internal[10] > 0) 
      tracenewedge (r , n);
      mem[p + 1].hhfield.lhfield = r;
      p = mem[p].hhfield.lhfield;
      incr (k);
      decr (n);
    } while (!(k == delta));
  } 
  goto done;
  lab62: edgeandweight = 8 * (n0 + mem[curedges + 3].hhfield.lhfield) + 
  4 - curwt;
  n0 = m0;
  k = 0;
  n = mem[curedges + 5].hhfield.lhfield - 4096;
  p = mem[curedges + 5].hhfield.v.RH;
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
	  incr (dynused);
#endif /* STAT */
	} 
      } 
      mem[r].hhfield.v.RH = mem[p + 1].hhfield.lhfield;
      mem[r].hhfield.lhfield = edgeandweight;
      if (internal[10] > 0) 
      tracenewedge (r , n);
      mem[p + 1].hhfield.lhfield = r;
      p = mem[p].hhfield.v.RH;
      decr (j);
      incr (n);
    } 
    edgeandweight = edgeandweight + dx;
    incr (k);
  } while (!(k > delta));
  goto done;
  lab63: edgeandweight = 8 * (n0 + mem[curedges + 3].hhfield.lhfield) + 
  4 + curwt;
  n0 = - (integer) m0 - 1;
  k = 0;
  n = mem[curedges + 5].hhfield.lhfield - 4096;
  p = mem[curedges + 5].hhfield.v.RH;
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
	  incr (dynused);
#endif /* STAT */
	} 
      } 
      mem[r].hhfield.v.RH = mem[p + 1].hhfield.lhfield;
      mem[r].hhfield.lhfield = edgeandweight;
      if (internal[10] > 0) 
      tracenewedge (r , n);
      mem[p + 1].hhfield.lhfield = r;
      p = mem[p].hhfield.lhfield;
      decr (j);
      decr (n);
    } 
    edgeandweight = edgeandweight + dx;
    incr (k);
  } while (!(k > delta));
  goto done;
  done: mem[curedges + 5].hhfield.lhfield = n + 4096;
  mem[curedges + 5].hhfield.v.RH = p;
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
  p = curspec;
  octant = mem[p + 3].cint;
  print_ln ();
  unskew (mem[curspec + 1].cint , mem[curspec + 2].cint , octant);
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
    not_found: if (q == curspec) 
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
  p = curspec;
  t = 256;
  do {
      p = mem[p].hhfield.v.RH;
    if (mem[p].hhfield.b0 != 0) 
    {
      if (mem[p].hhfield.b0 < t) 
      f = p;
      t = mem[p].hhfield.b0;
    } 
  } while (!(p == curspec));
  p = curspec;
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
    if ((filelineerrorstylep && !(curinput .namefield == 0))) 
    {
      print_nl (261);
      print (fullsourcefilenamestack[inopen]);
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
  p = curspec;
  firstx = mem[curspec + 1].cint;
  firsty = mem[curspec + 2].cint;
  do {
      lab22: q = mem[p].hhfield.v.RH;
    if (q == curspec) 
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
	  if (curspec != q) 
	  goto lab22;
	  else {
	      
	    curspec = p;
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
  } while (!(p == curspec));
  lab10:;
} 
void 
octantsubdivide (void) 
{
  halfword p, q, r, s;
  scaled del1, del2, del3, del, dmax;
  fraction t;
  scaled destx, desty;
  p = curspec;
  do {
      q = mem[p].hhfield.v.RH;
    mem[p + 1].cint = mem[p + 1].cint - mem[p + 2].cint;
    mem[p + 5].cint = mem[p + 5].cint - mem[p + 6].cint;
    mem[q + 3].cint = mem[q + 3].cint - mem[q + 4].cint;
    if (q == curspec) 
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
  } while (!(p == curspec));
} 
void 
makesafe (void) 
{
  integer k;
  boolean allsafe;
  scaled nexta;
  scaled deltaa, deltab;
  before[curroundingptr] = before[0];
  nodetoround[curroundingptr] = nodetoround[0];
  do {
      after[curroundingptr] = after[0];
    allsafe = true;
    nexta = after[0];
    {register integer for_end; k = 0;for_end = curroundingptr - 1; if (k 
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
	  if (k == curroundingptr - 1) 
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
  if (curroundingptr == maxroundingptr) {
      
    if (maxroundingptr < maxwiggle) 
    incr (maxroundingptr);
    else overflow (568 , maxwiggle);
  } 
  after[curroundingptr] = a;
  before[curroundingptr] = b;
  nodetoround[curroundingptr] = p;
  incr (curroundingptr);
} 
scaled 
zgoodval (scaled b , scaled o) 
{
  register scaled Result; scaled a;
  a = b + o;
  if (a >= 0) 
  a = a - (a % curgran) - o;
  else a = a + ((- (integer) (a + 1)) % curgran) - curgran + 1 - o;
  if (b - a < a + curgran - b) 
  Result = a;
  else Result = a + curgran;
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
  curgran = abs (internal[37]);
  if (curgran == 0) 
  curgran = 65536L;
  p = curspec;
  curroundingptr = 0;
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
	if (curpen == 3) 
	penedge = 0;
	else if (curpathtype == 0) 
	penedge = compromise (mem[mem[curpen + 5].hhfield.v.RH + 2]
	.cint , mem[mem[curpen + 7].hhfield.v.RH + 2].cint);
	else if (odd (mem[q].hhfield.b1)) 
	penedge = mem[mem[curpen + 7].hhfield.v.RH + 2].cint;
	else penedge = mem[mem[curpen + 5].hhfield.v.RH + 2].cint;
	a = goodval (b , penedge);
      } 
      else a = b;
      if (abs (a) > maxallowed) {
	  
	if (a > 0) 
	a = maxallowed;
	else a = - (integer) maxallowed;
      } 
      beforeandafter (b , a , q);
    } 
    p = q;
  } while (!(p == curspec));
  if (curroundingptr > 0) 
  {
    makesafe ();
    do {
	decr (curroundingptr);
      if ((after[curroundingptr]!= before[curroundingptr]) || (
      after[curroundingptr + 1]!= before[curroundingptr + 1])) 
      {
	p = nodetoround[curroundingptr];
	if (odd (mem[p].hhfield.b1)) 
	{
	  b = before[curroundingptr];
	  a = after[curroundingptr];
	} 
	else {
	    
	  b = - (integer) before[curroundingptr];
	  a = - (integer) after[curroundingptr];
	} 
	if (before[curroundingptr] == before[curroundingptr + 1]) 
	alpha = 268435456L;
	else alpha = makefraction (after[curroundingptr + 1] - after[
	curroundingptr], before[curroundingptr + 1] - before[
	curroundingptr]);
	do {
	    mem[p + 1].cint = takefraction (alpha , mem[p + 1].cint 
	  - b) + a;
	  mem[p + 5].cint = takefraction (alpha , mem[p + 5].cint - b 
	) + a;
	  p = mem[p].hhfield.v.RH;
	  mem[p + 3].cint = takefraction (alpha , mem[p + 3].cint - b 
	) + a;
	} while (!(p == nodetoround[curroundingptr + 1]));
      } 
    } while (!(curroundingptr == 0));
  } 
  p = curspec;
  curroundingptr = 0;
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
	if (curpen == 3) 
	penedge = 0;
	else if (curpathtype == 0) 
	penedge = compromise (mem[mem[curpen + 2].hhfield.v.RH + 2]
	.cint , mem[mem[curpen + 1].hhfield.v.RH + 2].cint);
	else if (mem[q].hhfield.b1 <= 2) 
	penedge = mem[mem[curpen + 1].hhfield.v.RH + 2].cint;
	else penedge = mem[mem[curpen + 2].hhfield.v.RH + 2].cint;
	a = goodval (b , penedge);
      } 
      else a = b;
      if (abs (a) > maxallowed) {
	  
	if (a > 0) 
	a = maxallowed;
	else a = - (integer) maxallowed;
      } 
      beforeandafter (b , a , q);
    } 
    p = q;
  } while (!(p == curspec));
  if (curroundingptr > 0) 
  {
    makesafe ();
    do {
	decr (curroundingptr);
      if ((after[curroundingptr]!= before[curroundingptr]) || (
      after[curroundingptr + 1]!= before[curroundingptr + 1])) 
      {
	p = nodetoround[curroundingptr];
	if (mem[p].hhfield.b1 <= 2) 
	{
	  b = before[curroundingptr];
	  a = after[curroundingptr];
	} 
	else {
	    
	  b = - (integer) before[curroundingptr];
	  a = - (integer) after[curroundingptr];
	} 
	if (before[curroundingptr] == before[curroundingptr + 1]) 
	alpha = 268435456L;
	else alpha = makefraction (after[curroundingptr + 1] - after[
	curroundingptr], before[curroundingptr + 1] - before[
	curroundingptr]);
	do {
	    mem[p + 2].cint = takefraction (alpha , mem[p + 2].cint 
	  - b) + a;
	  mem[p + 6].cint = takefraction (alpha , mem[p + 6].cint - b 
	) + a;
	  p = mem[p].hhfield.v.RH;
	  mem[p + 4].cint = takefraction (alpha , mem[p + 4].cint - b 
	) + a;
	} while (!(p == nodetoround[curroundingptr + 1]));
      } 
    } while (!(curroundingptr == 0));
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
  p = curspec;
  curroundingptr = 0;
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
	  if (curpen == 3) 
	  penedge = 0;
	  else if (curpathtype == 0) 
	  switch (mem[q].hhfield.b1) 
	  {case 1 : 
	  case 5 : 
	    penedge = compromise (mem[mem[mem[curpen + 1].hhfield 
	  .v.RH].hhfield.lhfield + 1].cint , - (integer) mem[mem[
	    mem[curpen + 4].hhfield.v.RH].hhfield.lhfield + 1].cint 
	  );
	    break;
	  case 4 : 
	  case 8 : 
	    penedge = - (integer) compromise (mem[mem[mem[curpen + 1]
	    .hhfield.v.RH].hhfield.lhfield + 1].cint , - (integer) mem[
	    mem[mem[curpen + 4].hhfield.v.RH].hhfield.lhfield + 1]
	    .cint);
	    break;
	  case 6 : 
	  case 2 : 
	    penedge = compromise (mem[mem[mem[curpen + 2].hhfield 
	  .v.RH].hhfield.lhfield + 1].cint , - (integer) mem[mem[
	    mem[curpen + 3].hhfield.v.RH].hhfield.lhfield + 1].cint 
	  );
	    break;
	  case 7 : 
	  case 3 : 
	    penedge = - (integer) compromise (mem[mem[mem[curpen + 2]
	    .hhfield.v.RH].hhfield.lhfield + 1].cint , - (integer) mem[
	    mem[mem[curpen + 3].hhfield.v.RH].hhfield.lhfield + 1]
	    .cint);
	    break;
	  } 
	  else if (mem[q].hhfield.b1 <= 4) 
	  penedge = mem[mem[mem[curpen + mem[q].hhfield.b1]
	  .hhfield.v.RH].hhfield.lhfield + 1].cint;
	  else penedge = - (integer) mem[mem[mem[curpen + mem[q]
	  .hhfield.b1].hhfield.v.RH].hhfield.lhfield + 1].cint;
	  if (odd (mem[q].hhfield.b1)) 
	  a = goodval (b , penedge + halfp (curgran));
	  else a = goodval (b - 1 , penedge + halfp (curgran));
	} 
	else a = b;
      } 
      else a = b;
      beforeandafter (b , a , q);
    } 
    p = q;
  } while (!(p == curspec));
  if (curroundingptr > 0) 
  {
    p = nodetoround[0];
    firstx = mem[p + 1].cint;
    firsty = mem[p + 2].cint;
    before[curroundingptr] = before[0];
    nodetoround[curroundingptr] = nodetoround[0];
    do {
	after[curroundingptr] = after[0];
      allsafe = true;
      nexta = after[0];
      {register integer for_end; k = 0;for_end = curroundingptr - 1; if (
      k <= for_end) do 
	{
	  a = nexta;
	  b = before[k];
	  nexta = after[k + 1];
	  aa = nexta;
	  bb = before[k + 1];
	  if ((a != b) || (aa != bb)) 
	  {
	    p = nodetoround[k];
	    pp = nodetoround[k + 1];
	    if (aa == bb) 
	    {
	      if (pp == nodetoround[0]) 
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
	      if (pp == nodetoround[0]) 
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
	      if (k == curroundingptr - 1) 
	      after[0] = before[0];
	      else after[k + 1] = before[k + 1];
	    } 
	  } 
	} 
      while (k++ < for_end);} 
    } while (!(allsafe));
    {register integer for_end; k = 0;for_end = curroundingptr - 1; if (k 
    <= for_end) do 
      {
	a = after[k];
	b = before[k];
	aa = after[k + 1];
	bb = before[k + 1];
	if ((a != b) || (aa != bb)) 
	{
	  p = nodetoround[k];
	  pp = nodetoround[k + 1];
	  if (aa == bb) 
	  {
	    if (pp == nodetoround[0]) 
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
	    if (pp == nodetoround[0]) 
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
  curspec = h;
  if (tracing > 0) 
  print_path (curspec , 559 , true);
  maxallowed = 268402687L - safetymargin;
  p = curspec;
  k = 1;
  chopped = 0;
  dmax = half (maxallowed);
  do {
      if (abs (mem[p + 3].cint) >= dmax) { 
      if (abs (mem[p + 3].cint) > maxallowed) 
      {
	chopped = 1;
	if (mem[p + 3].cint > 0) 
	mem[p + 3].cint = maxallowed;
	else mem[p + 3].cint = - (integer) maxallowed;
      } 
      else if (chopped == 0) 
      chopped = -1;
    } 
    if (abs (mem[p + 4].cint) >= dmax) {
	
      if (abs (mem[p + 4].cint) > maxallowed) 
      {
	chopped = 1;
	if (mem[p + 4].cint > 0) 
	mem[p + 4].cint = maxallowed;
	else mem[p + 4].cint = - (integer) maxallowed;
      } 
      else if (chopped == 0) 
      chopped = -1;
    } 
    if (abs (mem[p + 1].cint) >= dmax) {
	
      if (abs (mem[p + 1].cint) > maxallowed) 
      {
	chopped = 1;
	if (mem[p + 1].cint > 0) 
	mem[p + 1].cint = maxallowed;
	else mem[p + 1].cint = - (integer) maxallowed;
      } 
      else if (chopped == 0) 
      chopped = -1;
    } 
    if (abs (mem[p + 2].cint) >= dmax) {
	
      if (abs (mem[p + 2].cint) > maxallowed) 
      {
	chopped = 1;
	if (mem[p + 2].cint > 0) 
	mem[p + 2].cint = maxallowed;
	else mem[p + 2].cint = - (integer) maxallowed;
      } 
      else if (chopped == 0) 
      chopped = -1;
    } 
    if (abs (mem[p + 5].cint) >= dmax) {
	
      if (abs (mem[p + 5].cint) > maxallowed) 
      {
	chopped = 1;
	if (mem[p + 5].cint > 0) 
	mem[p + 5].cint = maxallowed;
	else mem[p + 5].cint = - (integer) maxallowed;
      } 
      else if (chopped == 0) 
      chopped = -1;
    } 
    if (abs (mem[p + 6].cint) >= dmax) {
	
      if (abs (mem[p + 6].cint) > maxallowed) 
      {
	chopped = 1;
	if (mem[p + 6].cint > 0) 
	mem[p + 6].cint = maxallowed;
	else mem[p + 6].cint = - (integer) maxallowed;
      } 
      else if (chopped == 0) 
      chopped = -1;
    } 
    p = mem[p].hhfield.v.RH;
    mem[p].hhfield.b0 = k;
    if (k < 255) 
    incr (k);
    else k = 1;
  } while (!(p == curspec));
  if (chopped > 0) 
  {
    {
      if (interaction == 3) 
  ;
      if ((filelineerrorstylep && !(curinput .namefield == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[inopen]);
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
  p = curspec;
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
		  if (q != curspec) 
		  goto lab22;
		  curspec = p;
		  q = p;
		} 
	      } 
	    } 
	  } 
	} 
      } 
    } 
    p = q;
  } while (!(p == curspec));
  turningnumber = 0;
  p = curspec;
  q = mem[p].hhfield.v.RH;
  do {
      r = mem[q].hhfield.v.RH;
    if ((mem[p].hhfield.b1 != mem[q].hhfield.b1) || (q == r)) 
    {
      newboundary (p , mem[p].hhfield.b1);
      s = mem[p].hhfield.v.RH;
      o1 = octantnumber[mem[p].hhfield.b1];
      o2 = octantnumber[mem[q].hhfield.b1];
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
	  else clockwise = revturns;
	} 
	break;
      case 6 : 
      case -2 : 
	clockwise = true;
	break;
      case 0 : 
	clockwise = revturns;
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
	free_node (curspec , 7);
	curspec = q;
      } 
      p = mem[p].hhfield.v.RH;
      do {
	  s = mem[p].hhfield.v.RH;
	o1 = octantnumber[mem[p + 5].cint];
	o2 = octantnumber[mem[s + 3].cint];
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
	  incr (turningnumber);
	  else decr (turningnumber);
	  mem[p + 6].cint = 0;
	} 
	mem[s + 4].cint = mem[p + 6].cint;
	p = s;
      } while (!(p == q));
    } 
    p = q;
    q = r;
  } while (!(p == curspec));
  while (mem[curspec].hhfield.b0 != 0) curspec = mem[curspec]
  .hhfield.v.RH;
  if (tracing > 0) {
      
    if ((internal[36]<= 0) || (chopped != 0)) 
    printspec (560);
    else if (internal[36] > 65536L) 
    printspec (561);
    else printspec (562);
  } 
  Result = curspec;
  return Result;
} 
void 
zendround (scaled x , scaled y) 
{
  y = y + 32768L - y_corr[octant];
  x = x + y - x_corr[octant];
  m1 = floorunscaled (x);
  n1 = floorunscaled (y);
  if (x - 65536L * m1 >= y - 65536L * n1 + zcorr[octant]) 
  d1 = 1;
  else d1 = 0;
} 
void 
zfillspec (halfword h) 
{
  halfword p, q, r, s;
  if (internal[10] > 0) 
  beginedgetracing ();
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
      if (n1 - n0 >= movesize) 
      overflow (540 , movesize);
      move[0] = d0;
      moveptr = 0;
      r = p;
      do {
	  s = mem[r].hhfield.v.RH;
	makemoves (mem[r + 1].cint , mem[r + 5].cint , mem[s + 3]
	.cint , mem[s + 1].cint , mem[r + 2].cint + 32768L , mem[r + 
	6].cint + 32768L , mem[s + 4].cint + 32768L , mem[s + 2]
	.cint + 32768L , xy_corr[octant], y_corr[octant]);
	r = s;
      } while (!(r == q));
      move[moveptr] = move[moveptr] - d1;
      if (internal[35] > 0) 
      smoothmoves (0 , moveptr);
      movetoedges (m0 , n0 , m1 , n1);
    } 
    p = mem[q].hhfield.v.RH;
  } while (!(p == h));
  toss_knot_list (h);
  if (internal[10] > 0) 
  endedgetracing ();
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
      oo = octantnumber[octant];
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
      if ((filelineerrorstylep && !(curinput .namefield == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[inopen]);
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
      if ((filelineerrorstylep && !(curinput .namefield == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[inopen]);
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
  if (odd (octantnumber[octant])) 
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
  integer lmaxcoef;
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
      lmaxcoef = abs (x0);
      if (abs (x1) > lmaxcoef) 
      lmaxcoef = abs (x1);
      if (abs (x2) > lmaxcoef) 
      lmaxcoef = abs (x2);
      if (abs (y0) > lmaxcoef) 
      lmaxcoef = abs (y0);
      if (abs (y1) > lmaxcoef) 
      lmaxcoef = abs (y1);
      if (abs (y2) > lmaxcoef) 
      lmaxcoef = abs (y2);
      if (lmaxcoef == 0) 
      goto not_found;
      while (lmaxcoef < 134217728L) {
	  
	lmaxcoef = lmaxcoef + lmaxcoef;
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
zskewlineedges (halfword p , halfword w , halfword ww) 
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
    lineedges (x0 , y0 , cur_x , cur_y);
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
    envmove[n] = mm1;
  while (n++ < for_end);} 
  envmove[0] = mm0;
  moveptr = 0;
  m = mm0;
  r = p;
  while (true) {
      
    if (r == q) 
    smoothtop = moveptr;
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
		
	      if (m < envmove[moveptr]) 
	      envmove[moveptr] = m;
	      tx = takefraction (delx , makefraction (yy , dely));
	      if (ab_vs_cd (tx , dely , delx , yy) + xy_corr[octant] > 0) 
	      decr (tx);
	      m = floorunscaled (xx + tx);
	      ty = ty - 65536L;
	      incr (moveptr);
	      if (ty < 65536L) 
	      goto done1;
	      yy = yy + 65536L;
	    } 
	    done1: if (m < envmove[moveptr]) 
	    envmove[moveptr] = m;
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
      moveptr = floorunscaled (yp - y_corr[octant]) - n0;
      if (m < envmove[moveptr]) 
      envmove[moveptr] = m;
    } 
    if (r == p) 
    smoothbot = moveptr;
    if (r == q) 
    goto done;
    move[moveptr] = 1;
    n = moveptr;
    s = mem[r].hhfield.v.RH;
    makemoves (mem[r + 1].cint + mem[w + 1].cint , mem[r + 5]
    .cint + mem[w + 1].cint , mem[s + 3].cint + mem[w + 1].cint , 
    mem[s + 1].cint + mem[w + 1].cint , mem[r + 2].cint + mem[w 
    + 2].cint + 32768L , mem[r + 6].cint + mem[w + 2].cint + 32768L 
    , mem[s + 4].cint + mem[w + 2].cint + 32768L , mem[s + 2].cint 
    + mem[w + 2].cint + 32768L , xy_corr[octant], y_corr[octant]);
    do {
	if (m < envmove[n]) 
      envmove[n] = m;
      m = m + move[n] - 1;
      incr (n);
    } while (!(n > moveptr));
    r = s;
  } 
  done: 
	;
#ifdef TEXMF_DEBUG
  if ((m != mm1) || (moveptr != n1 - n0)) 
  confusion (50);
#endif /* TEXMF_DEBUG */
  move[0] = d0 + envmove[1] - mm0;
  {register integer for_end; n = 1;for_end = moveptr; if (n <= for_end) 
  do 
    move[n] = envmove[n + 1] - envmove[n]+ 1;
  while (n++ < for_end);} 
  move[moveptr] = move[moveptr] - d1;
  if (internal[35] > 0) 
  smoothmoves (smoothbot , smoothtop);
  movetoedges (m0 , n0 , m1 , n1);
  if (mem[q + 6].cint == 1) 
  {
    w = mem[h].hhfield.v.RH;
    skewlineedges (q , w , mem[w].hhfield.lhfield);
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
  beginedgetracing ();
  p = spechead;
  do {
      octant = mem[p + 3].cint;
    h = curpen + octant;
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
    if (odd (octantnumber[octant])) 
    www = mem[www].hhfield.lhfield;
    else ww = mem[ww].hhfield.lhfield;
    if (w != ww) 
    skewlineedges (p , w , ww);
    endround (mem[p + 1].cint + mem[ww + 1].cint , mem[p + 2]
    .cint + mem[ww + 2].cint);
    m0 = m1;
    n0 = n1;
    d0 = d1;
    endround (mem[q + 1].cint + mem[www + 1].cint , mem[q + 2]
    .cint + mem[www + 2].cint);
    if (n1 - n0 >= movesize) 
    overflow (540 , movesize);
    offsetprep (p , h);
    q = p;
    while (mem[q].hhfield.b1 != 0) q = mem[q].hhfield.v.RH;
    if (odd (octantnumber[octant])) 
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
	envmove[n] = mm0;
      while (n++ < for_end);} 
      envmove[n1 - n0] = mm1;
      moveptr = 0;
      m = mm0;
      r = p;
      mem[q].hhfield.b1 = mem[h].hhfield.lhfield + 1;
      while (true) {
	  
	if (r == q) 
	smoothtop = moveptr;
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
		  if (m > envmove[moveptr]) 
		  envmove[moveptr] = m;
		  ty = ty - 65536L;
		  if (ty < 65536L) 
		  goto done1;
		  yy = yy + 65536L;
		  incr (moveptr);
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
	  moveptr = floorunscaled (yp - y_corr[octant]) - n0;
	  if (m > envmove[moveptr]) 
	  envmove[moveptr] = m;
	} 
	if (r == p) 
	smoothbot = moveptr;
	if (r == q) 
	goto done;
	move[moveptr] = 1;
	n = moveptr;
	s = mem[r].hhfield.v.RH;
	makemoves (mem[r + 1].cint + mem[w + 1].cint , mem[r + 5]
	.cint + mem[w + 1].cint , mem[s + 3].cint + mem[w + 1]
	.cint , mem[s + 1].cint + mem[w + 1].cint , mem[r + 2]
	.cint + mem[w + 2].cint + 32768L , mem[r + 6].cint + mem[w + 
	2].cint + 32768L , mem[s + 4].cint + mem[w + 2].cint + 
	32768L , mem[s + 2].cint + mem[w + 2].cint + 32768L , xy_corr[
	octant], y_corr[octant]);
	do {
	    m = m + move[n] - 1;
	  if (m > envmove[n]) 
	  envmove[n] = m;
	  incr (n);
	} while (!(n > moveptr));
	r = s;
      } 
      done: 
	;
#ifdef TEXMF_DEBUG
      if ((m != mm1) || (moveptr != n1 - n0)) 
      confusion (49);
#endif /* TEXMF_DEBUG */
      move[0] = d0 + envmove[0] - mm0;
      {register integer for_end; n = 1;for_end = moveptr; if (n <= 
      for_end) do 
	move[n] = envmove[n] - envmove[n - 1]+ 1;
      while (n++ < for_end);} 
      move[moveptr] = move[moveptr] - d1;
      if (internal[35] > 0) 
      smoothmoves (smoothbot , smoothtop);
      movetoedges (m0 , n0 , m1 , n1);
      if (mem[q + 6].cint == 0) 
      {
	w = mem[h].hhfield.v.RH;
	skewlineedges (q , mem[w].hhfield.lhfield , w);
      } 
    } 
    else dualmoves (h , p , q);
    mem[q].hhfield.b1 = 0;
    p = mem[q].hhfield.v.RH;
  } while (!(p == spechead));
  if (internal[10] > 0) 
  endedgetracing ();
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
      nsin = 268435456L;
      ncos = 0;
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
    gamma = takefraction (majoraxis , nsin);
    delta = takefraction (minoraxis , ncos);
    beta = pyth_add (gamma , delta);
    alpha = makefraction (gamma , beta);
    alpha = takefraction (majoraxis , alpha);
    alpha = takefraction (alpha , ncos);
    alpha = (alpha + 32768L) / 65536L;
    gamma = takefraction (minoraxis , nsin);
    gamma = pyth_add (takefraction (majoraxis , ncos) , gamma);
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
	  
	alpha = takefraction (u , ncos) + takefraction (v , nsin);
	beta = takefraction (v , ncos) - takefraction (u , nsin);
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
  timetogo = 5000;
  maxt = 2;
  q = mem[p].hhfield.v.RH;
  qq = mem[pp].hhfield.v.RH;
  bisectptr = 20;
  bisectstack[bisectptr - 5] = mem[p + 5].cint - mem[p + 1].cint;
  bisectstack[bisectptr - 4] = mem[q + 3].cint - mem[p + 5].cint;
  bisectstack[bisectptr - 3] = mem[q + 1].cint - mem[q + 3].cint;
  if (bisectstack[bisectptr - 5]< 0) {
      
    if (bisectstack[bisectptr - 3] >= 0) 
    {
      if (bisectstack[bisectptr - 4]< 0) 
      bisectstack[bisectptr - 2] = bisectstack[bisectptr - 5]+ 
      bisectstack[bisectptr - 4];
      else bisectstack[bisectptr - 2] = bisectstack[bisectptr - 5];
      bisectstack[bisectptr - 1] = bisectstack[bisectptr - 5]+ 
      bisectstack[bisectptr - 4]+ bisectstack[bisectptr - 3];
      if (bisectstack[bisectptr - 1]< 0) 
      bisectstack[bisectptr - 1] = 0;
    } 
    else {
	
      bisectstack[bisectptr - 2] = bisectstack[bisectptr - 5]+ 
      bisectstack[bisectptr - 4]+ bisectstack[bisectptr - 3];
      if (bisectstack[bisectptr - 2] > bisectstack[bisectptr - 5]) 
      bisectstack[bisectptr - 2] = bisectstack[bisectptr - 5];
      bisectstack[bisectptr - 1] = bisectstack[bisectptr - 5]+ 
      bisectstack[bisectptr - 4];
      if (bisectstack[bisectptr - 1]< 0) 
      bisectstack[bisectptr - 1] = 0;
    } 
  } 
  else if (bisectstack[bisectptr - 3]<= 0) 
  {
    if (bisectstack[bisectptr - 4] > 0) 
    bisectstack[bisectptr - 1] = bisectstack[bisectptr - 5]+ 
    bisectstack[bisectptr - 4];
    else bisectstack[bisectptr - 1] = bisectstack[bisectptr - 5];
    bisectstack[bisectptr - 2] = bisectstack[bisectptr - 5]+ 
    bisectstack[bisectptr - 4]+ bisectstack[bisectptr - 3];
    if (bisectstack[bisectptr - 2] > 0) 
    bisectstack[bisectptr - 2] = 0;
  } 
  else {
      
    bisectstack[bisectptr - 1] = bisectstack[bisectptr - 5]+ 
    bisectstack[bisectptr - 4]+ bisectstack[bisectptr - 3];
    if (bisectstack[bisectptr - 1]< bisectstack[bisectptr - 5]) 
    bisectstack[bisectptr - 1] = bisectstack[bisectptr - 5];
    bisectstack[bisectptr - 2] = bisectstack[bisectptr - 5]+ 
    bisectstack[bisectptr - 4];
    if (bisectstack[bisectptr - 2] > 0) 
    bisectstack[bisectptr - 2] = 0;
  } 
  bisectstack[bisectptr - 10] = mem[p + 6].cint - mem[p + 2].cint;
  bisectstack[bisectptr - 9] = mem[q + 4].cint - mem[p + 6].cint;
  bisectstack[bisectptr - 8] = mem[q + 2].cint - mem[q + 4].cint;
  if (bisectstack[bisectptr - 10]< 0) {
      
    if (bisectstack[bisectptr - 8] >= 0) 
    {
      if (bisectstack[bisectptr - 9]< 0) 
      bisectstack[bisectptr - 7] = bisectstack[bisectptr - 10]+ 
      bisectstack[bisectptr - 9];
      else bisectstack[bisectptr - 7] = bisectstack[bisectptr - 10];
      bisectstack[bisectptr - 6] = bisectstack[bisectptr - 10]+ 
      bisectstack[bisectptr - 9]+ bisectstack[bisectptr - 8];
      if (bisectstack[bisectptr - 6]< 0) 
      bisectstack[bisectptr - 6] = 0;
    } 
    else {
	
      bisectstack[bisectptr - 7] = bisectstack[bisectptr - 10]+ 
      bisectstack[bisectptr - 9]+ bisectstack[bisectptr - 8];
      if (bisectstack[bisectptr - 7] > bisectstack[bisectptr - 10]) 
      bisectstack[bisectptr - 7] = bisectstack[bisectptr - 10];
      bisectstack[bisectptr - 6] = bisectstack[bisectptr - 10]+ 
      bisectstack[bisectptr - 9];
      if (bisectstack[bisectptr - 6]< 0) 
      bisectstack[bisectptr - 6] = 0;
    } 
  } 
  else if (bisectstack[bisectptr - 8]<= 0) 
  {
    if (bisectstack[bisectptr - 9] > 0) 
    bisectstack[bisectptr - 6] = bisectstack[bisectptr - 10]+ 
    bisectstack[bisectptr - 9];
    else bisectstack[bisectptr - 6] = bisectstack[bisectptr - 10];
    bisectstack[bisectptr - 7] = bisectstack[bisectptr - 10]+ 
    bisectstack[bisectptr - 9]+ bisectstack[bisectptr - 8];
    if (bisectstack[bisectptr - 7] > 0) 
    bisectstack[bisectptr - 7] = 0;
  } 
  else {
      
    bisectstack[bisectptr - 6] = bisectstack[bisectptr - 10]+ 
    bisectstack[bisectptr - 9]+ bisectstack[bisectptr - 8];
    if (bisectstack[bisectptr - 6]< bisectstack[bisectptr - 10]) 
    bisectstack[bisectptr - 6] = bisectstack[bisectptr - 10];
    bisectstack[bisectptr - 7] = bisectstack[bisectptr - 10]+ 
    bisectstack[bisectptr - 9];
    if (bisectstack[bisectptr - 7] > 0) 
    bisectstack[bisectptr - 7] = 0;
  } 
  bisectstack[bisectptr - 15] = mem[pp + 5].cint - mem[pp + 1].cint 
;
  bisectstack[bisectptr - 14] = mem[qq + 3].cint - mem[pp + 5].cint 
;
  bisectstack[bisectptr - 13] = mem[qq + 1].cint - mem[qq + 3].cint 
;
  if (bisectstack[bisectptr - 15]< 0) {
      
    if (bisectstack[bisectptr - 13] >= 0) 
    {
      if (bisectstack[bisectptr - 14]< 0) 
      bisectstack[bisectptr - 12] = bisectstack[bisectptr - 15]+ 
      bisectstack[bisectptr - 14];
      else bisectstack[bisectptr - 12] = bisectstack[bisectptr - 15];
      bisectstack[bisectptr - 11] = bisectstack[bisectptr - 15]+ 
      bisectstack[bisectptr - 14]+ bisectstack[bisectptr - 13];
      if (bisectstack[bisectptr - 11]< 0) 
      bisectstack[bisectptr - 11] = 0;
    } 
    else {
	
      bisectstack[bisectptr - 12] = bisectstack[bisectptr - 15]+ 
      bisectstack[bisectptr - 14]+ bisectstack[bisectptr - 13];
      if (bisectstack[bisectptr - 12] > bisectstack[bisectptr - 15]) 
      bisectstack[bisectptr - 12] = bisectstack[bisectptr - 15];
      bisectstack[bisectptr - 11] = bisectstack[bisectptr - 15]+ 
      bisectstack[bisectptr - 14];
      if (bisectstack[bisectptr - 11]< 0) 
      bisectstack[bisectptr - 11] = 0;
    } 
  } 
  else if (bisectstack[bisectptr - 13]<= 0) 
  {
    if (bisectstack[bisectptr - 14] > 0) 
    bisectstack[bisectptr - 11] = bisectstack[bisectptr - 15]+ 
    bisectstack[bisectptr - 14];
    else bisectstack[bisectptr - 11] = bisectstack[bisectptr - 15];
    bisectstack[bisectptr - 12] = bisectstack[bisectptr - 15]+ 
    bisectstack[bisectptr - 14]+ bisectstack[bisectptr - 13];
    if (bisectstack[bisectptr - 12] > 0) 
    bisectstack[bisectptr - 12] = 0;
  } 
  else {
      
    bisectstack[bisectptr - 11] = bisectstack[bisectptr - 15]+ 
    bisectstack[bisectptr - 14]+ bisectstack[bisectptr - 13];
    if (bisectstack[bisectptr - 11]< bisectstack[bisectptr - 15]) 
    bisectstack[bisectptr - 11] = bisectstack[bisectptr - 15];
    bisectstack[bisectptr - 12] = bisectstack[bisectptr - 15]+ 
    bisectstack[bisectptr - 14];
    if (bisectstack[bisectptr - 12] > 0) 
    bisectstack[bisectptr - 12] = 0;
  } 
  bisectstack[bisectptr - 20] = mem[pp + 6].cint - mem[pp + 2].cint 
;
  bisectstack[bisectptr - 19] = mem[qq + 4].cint - mem[pp + 6].cint 
;
  bisectstack[bisectptr - 18] = mem[qq + 2].cint - mem[qq + 4].cint 
;
  if (bisectstack[bisectptr - 20]< 0) {
      
    if (bisectstack[bisectptr - 18] >= 0) 
    {
      if (bisectstack[bisectptr - 19]< 0) 
      bisectstack[bisectptr - 17] = bisectstack[bisectptr - 20]+ 
      bisectstack[bisectptr - 19];
      else bisectstack[bisectptr - 17] = bisectstack[bisectptr - 20];
      bisectstack[bisectptr - 16] = bisectstack[bisectptr - 20]+ 
      bisectstack[bisectptr - 19]+ bisectstack[bisectptr - 18];
      if (bisectstack[bisectptr - 16]< 0) 
      bisectstack[bisectptr - 16] = 0;
    } 
    else {
	
      bisectstack[bisectptr - 17] = bisectstack[bisectptr - 20]+ 
      bisectstack[bisectptr - 19]+ bisectstack[bisectptr - 18];
      if (bisectstack[bisectptr - 17] > bisectstack[bisectptr - 20]) 
      bisectstack[bisectptr - 17] = bisectstack[bisectptr - 20];
      bisectstack[bisectptr - 16] = bisectstack[bisectptr - 20]+ 
      bisectstack[bisectptr - 19];
      if (bisectstack[bisectptr - 16]< 0) 
      bisectstack[bisectptr - 16] = 0;
    } 
  } 
  else if (bisectstack[bisectptr - 18]<= 0) 
  {
    if (bisectstack[bisectptr - 19] > 0) 
    bisectstack[bisectptr - 16] = bisectstack[bisectptr - 20]+ 
    bisectstack[bisectptr - 19];
    else bisectstack[bisectptr - 16] = bisectstack[bisectptr - 20];
    bisectstack[bisectptr - 17] = bisectstack[bisectptr - 20]+ 
    bisectstack[bisectptr - 19]+ bisectstack[bisectptr - 18];
    if (bisectstack[bisectptr - 17] > 0) 
    bisectstack[bisectptr - 17] = 0;
  } 
  else {
      
    bisectstack[bisectptr - 16] = bisectstack[bisectptr - 20]+ 
    bisectstack[bisectptr - 19]+ bisectstack[bisectptr - 18];
    if (bisectstack[bisectptr - 16]< bisectstack[bisectptr - 20]) 
    bisectstack[bisectptr - 16] = bisectstack[bisectptr - 20];
    bisectstack[bisectptr - 17] = bisectstack[bisectptr - 20]+ 
    bisectstack[bisectptr - 19];
    if (bisectstack[bisectptr - 17] > 0) 
    bisectstack[bisectptr - 17] = 0;
  } 
  delx = mem[p + 1].cint - mem[pp + 1].cint;
  dely = mem[p + 2].cint - mem[pp + 2].cint;
  tol = 0;
  uv = bisectptr;
  xy = bisectptr;
  threel = 0;
  curt = 1;
  curtt = 1;
  while (true) {
      
    lab22: if (delx - tol <= bisectstack[xy - 11] - bisectstack[uv - 2]
  ) {
	
      if (delx + tol >= bisectstack[xy - 12] - bisectstack[uv - 1]) {
	  
	if (dely - tol <= bisectstack[xy - 16] - bisectstack[uv - 7]) 
	{
	  if (dely + tol >= bisectstack[xy - 17] - bisectstack[uv - 6]
	) 
	  {
	    if (curt >= maxt) 
	    {
	      if (maxt == 131072L) 
	      {
		curt = halfp (curt + 1);
		curtt = halfp (curtt + 1);
		goto lab10;
	      } 
	      maxt = maxt + maxt;
	      apprt = curt;
	      apprtt = curtt;
	    } 
	    bisectstack[bisectptr] = delx;
	    bisectstack[bisectptr + 1] = dely;
	    bisectstack[bisectptr + 2] = tol;
	    bisectstack[bisectptr + 3] = uv;
	    bisectstack[bisectptr + 4] = xy;
	    bisectptr = bisectptr + 45;
	    curt = curt + curt;
	    curtt = curtt + curtt;
	    bisectstack[bisectptr - 25] = bisectstack[uv - 5];
	    bisectstack[bisectptr - 3] = bisectstack[uv - 3];
	    bisectstack[bisectptr - 24] = half (bisectstack[bisectptr - 
	    25]+ bisectstack[uv - 4]);
	    bisectstack[bisectptr - 4] = half (bisectstack[bisectptr - 3 
	  ]+ bisectstack[uv - 4]);
	    bisectstack[bisectptr - 23] = half (bisectstack[bisectptr - 
	    24]+ bisectstack[bisectptr - 4]);
	    bisectstack[bisectptr - 5] = bisectstack[bisectptr - 23];
	    if (bisectstack[bisectptr - 25]< 0) {
		
	      if (bisectstack[bisectptr - 23] >= 0) 
	      {
		if (bisectstack[bisectptr - 24]< 0) 
		bisectstack[bisectptr - 22] = bisectstack[bisectptr - 25 
		]+ bisectstack[bisectptr - 24];
		else bisectstack[bisectptr - 22] = bisectstack[bisectptr 
		- 25];
		bisectstack[bisectptr - 21] = bisectstack[bisectptr - 25 
		]+ bisectstack[bisectptr - 24]+ bisectstack[bisectptr - 
		23];
		if (bisectstack[bisectptr - 21]< 0) 
		bisectstack[bisectptr - 21] = 0;
	      } 
	      else {
		  
		bisectstack[bisectptr - 22] = bisectstack[bisectptr - 25 
		]+ bisectstack[bisectptr - 24]+ bisectstack[bisectptr - 
		23];
		if (bisectstack[bisectptr - 22] > bisectstack[bisectptr 
		- 25]) 
		bisectstack[bisectptr - 22] = bisectstack[bisectptr - 25 
		];
		bisectstack[bisectptr - 21] = bisectstack[bisectptr - 25 
		]+ bisectstack[bisectptr - 24];
		if (bisectstack[bisectptr - 21]< 0) 
		bisectstack[bisectptr - 21] = 0;
	      } 
	    } 
	    else if (bisectstack[bisectptr - 23]<= 0) 
	    {
	      if (bisectstack[bisectptr - 24] > 0) 
	      bisectstack[bisectptr - 21] = bisectstack[bisectptr - 25]
	      + bisectstack[bisectptr - 24];
	      else bisectstack[bisectptr - 21] = bisectstack[bisectptr - 
	      25];
	      bisectstack[bisectptr - 22] = bisectstack[bisectptr - 25]
	      + bisectstack[bisectptr - 24]+ bisectstack[bisectptr - 23 
	    ];
	      if (bisectstack[bisectptr - 22] > 0) 
	      bisectstack[bisectptr - 22] = 0;
	    } 
	    else {
		
	      bisectstack[bisectptr - 21] = bisectstack[bisectptr - 25]
	      + bisectstack[bisectptr - 24]+ bisectstack[bisectptr - 23 
	    ];
	      if (bisectstack[bisectptr - 21]< bisectstack[bisectptr - 
	      25]) 
	      bisectstack[bisectptr - 21] = bisectstack[bisectptr - 25]
	  ;
	      bisectstack[bisectptr - 22] = bisectstack[bisectptr - 25]
	      + bisectstack[bisectptr - 24];
	      if (bisectstack[bisectptr - 22] > 0) 
	      bisectstack[bisectptr - 22] = 0;
	    } 
	    if (bisectstack[bisectptr - 5]< 0) {
		
	      if (bisectstack[bisectptr - 3] >= 0) 
	      {
		if (bisectstack[bisectptr - 4]< 0) 
		bisectstack[bisectptr - 2] = bisectstack[bisectptr - 5]
		+ bisectstack[bisectptr - 4];
		else bisectstack[bisectptr - 2] = bisectstack[bisectptr - 
		5];
		bisectstack[bisectptr - 1] = bisectstack[bisectptr - 5]
		+ bisectstack[bisectptr - 4]+ bisectstack[bisectptr - 3 
		];
		if (bisectstack[bisectptr - 1]< 0) 
		bisectstack[bisectptr - 1] = 0;
	      } 
	      else {
		  
		bisectstack[bisectptr - 2] = bisectstack[bisectptr - 5]
		+ bisectstack[bisectptr - 4]+ bisectstack[bisectptr - 3 
		];
		if (bisectstack[bisectptr - 2] > bisectstack[bisectptr - 
		5]) 
		bisectstack[bisectptr - 2] = bisectstack[bisectptr - 5]
		;
		bisectstack[bisectptr - 1] = bisectstack[bisectptr - 5]
		+ bisectstack[bisectptr - 4];
		if (bisectstack[bisectptr - 1]< 0) 
		bisectstack[bisectptr - 1] = 0;
	      } 
	    } 
	    else if (bisectstack[bisectptr - 3]<= 0) 
	    {
	      if (bisectstack[bisectptr - 4] > 0) 
	      bisectstack[bisectptr - 1] = bisectstack[bisectptr - 5]+ 
	      bisectstack[bisectptr - 4];
	      else bisectstack[bisectptr - 1] = bisectstack[bisectptr - 5 
	    ];
	      bisectstack[bisectptr - 2] = bisectstack[bisectptr - 5]+ 
	      bisectstack[bisectptr - 4]+ bisectstack[bisectptr - 3];
	      if (bisectstack[bisectptr - 2] > 0) 
	      bisectstack[bisectptr - 2] = 0;
	    } 
	    else {
		
	      bisectstack[bisectptr - 1] = bisectstack[bisectptr - 5]+ 
	      bisectstack[bisectptr - 4]+ bisectstack[bisectptr - 3];
	      if (bisectstack[bisectptr - 1]< bisectstack[bisectptr - 5 
	    ]) 
	      bisectstack[bisectptr - 1] = bisectstack[bisectptr - 5];
	      bisectstack[bisectptr - 2] = bisectstack[bisectptr - 5]+ 
	      bisectstack[bisectptr - 4];
	      if (bisectstack[bisectptr - 2] > 0) 
	      bisectstack[bisectptr - 2] = 0;
	    } 
	    bisectstack[bisectptr - 30] = bisectstack[uv - 10];
	    bisectstack[bisectptr - 8] = bisectstack[uv - 8];
	    bisectstack[bisectptr - 29] = half (bisectstack[bisectptr - 
	    30]+ bisectstack[uv - 9]);
	    bisectstack[bisectptr - 9] = half (bisectstack[bisectptr - 8 
	  ]+ bisectstack[uv - 9]);
	    bisectstack[bisectptr - 28] = half (bisectstack[bisectptr - 
	    29]+ bisectstack[bisectptr - 9]);
	    bisectstack[bisectptr - 10] = bisectstack[bisectptr - 28];
	    if (bisectstack[bisectptr - 30]< 0) {
		
	      if (bisectstack[bisectptr - 28] >= 0) 
	      {
		if (bisectstack[bisectptr - 29]< 0) 
		bisectstack[bisectptr - 27] = bisectstack[bisectptr - 30 
		]+ bisectstack[bisectptr - 29];
		else bisectstack[bisectptr - 27] = bisectstack[bisectptr 
		- 30];
		bisectstack[bisectptr - 26] = bisectstack[bisectptr - 30 
		]+ bisectstack[bisectptr - 29]+ bisectstack[bisectptr - 
		28];
		if (bisectstack[bisectptr - 26]< 0) 
		bisectstack[bisectptr - 26] = 0;
	      } 
	      else {
		  
		bisectstack[bisectptr - 27] = bisectstack[bisectptr - 30 
		]+ bisectstack[bisectptr - 29]+ bisectstack[bisectptr - 
		28];
		if (bisectstack[bisectptr - 27] > bisectstack[bisectptr 
		- 30]) 
		bisectstack[bisectptr - 27] = bisectstack[bisectptr - 30 
		];
		bisectstack[bisectptr - 26] = bisectstack[bisectptr - 30 
		]+ bisectstack[bisectptr - 29];
		if (bisectstack[bisectptr - 26]< 0) 
		bisectstack[bisectptr - 26] = 0;
	      } 
	    } 
	    else if (bisectstack[bisectptr - 28]<= 0) 
	    {
	      if (bisectstack[bisectptr - 29] > 0) 
	      bisectstack[bisectptr - 26] = bisectstack[bisectptr - 30]
	      + bisectstack[bisectptr - 29];
	      else bisectstack[bisectptr - 26] = bisectstack[bisectptr - 
	      30];
	      bisectstack[bisectptr - 27] = bisectstack[bisectptr - 30]
	      + bisectstack[bisectptr - 29]+ bisectstack[bisectptr - 28 
	    ];
	      if (bisectstack[bisectptr - 27] > 0) 
	      bisectstack[bisectptr - 27] = 0;
	    } 
	    else {
		
	      bisectstack[bisectptr - 26] = bisectstack[bisectptr - 30]
	      + bisectstack[bisectptr - 29]+ bisectstack[bisectptr - 28 
	    ];
	      if (bisectstack[bisectptr - 26]< bisectstack[bisectptr - 
	      30]) 
	      bisectstack[bisectptr - 26] = bisectstack[bisectptr - 30]
	  ;
	      bisectstack[bisectptr - 27] = bisectstack[bisectptr - 30]
	      + bisectstack[bisectptr - 29];
	      if (bisectstack[bisectptr - 27] > 0) 
	      bisectstack[bisectptr - 27] = 0;
	    } 
	    if (bisectstack[bisectptr - 10]< 0) {
		
	      if (bisectstack[bisectptr - 8] >= 0) 
	      {
		if (bisectstack[bisectptr - 9]< 0) 
		bisectstack[bisectptr - 7] = bisectstack[bisectptr - 10]
		+ bisectstack[bisectptr - 9];
		else bisectstack[bisectptr - 7] = bisectstack[bisectptr - 
		10];
		bisectstack[bisectptr - 6] = bisectstack[bisectptr - 10]
		+ bisectstack[bisectptr - 9]+ bisectstack[bisectptr - 8 
		];
		if (bisectstack[bisectptr - 6]< 0) 
		bisectstack[bisectptr - 6] = 0;
	      } 
	      else {
		  
		bisectstack[bisectptr - 7] = bisectstack[bisectptr - 10]
		+ bisectstack[bisectptr - 9]+ bisectstack[bisectptr - 8 
		];
		if (bisectstack[bisectptr - 7] > bisectstack[bisectptr - 
		10]) 
		bisectstack[bisectptr - 7] = bisectstack[bisectptr - 10]
		;
		bisectstack[bisectptr - 6] = bisectstack[bisectptr - 10]
		+ bisectstack[bisectptr - 9];
		if (bisectstack[bisectptr - 6]< 0) 
		bisectstack[bisectptr - 6] = 0;
	      } 
	    } 
	    else if (bisectstack[bisectptr - 8]<= 0) 
	    {
	      if (bisectstack[bisectptr - 9] > 0) 
	      bisectstack[bisectptr - 6] = bisectstack[bisectptr - 10]+ 
	      bisectstack[bisectptr - 9];
	      else bisectstack[bisectptr - 6] = bisectstack[bisectptr - 
	      10];
	      bisectstack[bisectptr - 7] = bisectstack[bisectptr - 10]+ 
	      bisectstack[bisectptr - 9]+ bisectstack[bisectptr - 8];
	      if (bisectstack[bisectptr - 7] > 0) 
	      bisectstack[bisectptr - 7] = 0;
	    } 
	    else {
		
	      bisectstack[bisectptr - 6] = bisectstack[bisectptr - 10]+ 
	      bisectstack[bisectptr - 9]+ bisectstack[bisectptr - 8];
	      if (bisectstack[bisectptr - 6]< bisectstack[bisectptr - 
	      10]) 
	      bisectstack[bisectptr - 6] = bisectstack[bisectptr - 10];
	      bisectstack[bisectptr - 7] = bisectstack[bisectptr - 10]+ 
	      bisectstack[bisectptr - 9];
	      if (bisectstack[bisectptr - 7] > 0) 
	      bisectstack[bisectptr - 7] = 0;
	    } 
	    bisectstack[bisectptr - 35] = bisectstack[xy - 15];
	    bisectstack[bisectptr - 13] = bisectstack[xy - 13];
	    bisectstack[bisectptr - 34] = half (bisectstack[bisectptr - 
	    35]+ bisectstack[xy - 14]);
	    bisectstack[bisectptr - 14] = half (bisectstack[bisectptr - 
	    13]+ bisectstack[xy - 14]);
	    bisectstack[bisectptr - 33] = half (bisectstack[bisectptr - 
	    34]+ bisectstack[bisectptr - 14]);
	    bisectstack[bisectptr - 15] = bisectstack[bisectptr - 33];
	    if (bisectstack[bisectptr - 35]< 0) {
		
	      if (bisectstack[bisectptr - 33] >= 0) 
	      {
		if (bisectstack[bisectptr - 34]< 0) 
		bisectstack[bisectptr - 32] = bisectstack[bisectptr - 35 
		]+ bisectstack[bisectptr - 34];
		else bisectstack[bisectptr - 32] = bisectstack[bisectptr 
		- 35];
		bisectstack[bisectptr - 31] = bisectstack[bisectptr - 35 
		]+ bisectstack[bisectptr - 34]+ bisectstack[bisectptr - 
		33];
		if (bisectstack[bisectptr - 31]< 0) 
		bisectstack[bisectptr - 31] = 0;
	      } 
	      else {
		  
		bisectstack[bisectptr - 32] = bisectstack[bisectptr - 35 
		]+ bisectstack[bisectptr - 34]+ bisectstack[bisectptr - 
		33];
		if (bisectstack[bisectptr - 32] > bisectstack[bisectptr 
		- 35]) 
		bisectstack[bisectptr - 32] = bisectstack[bisectptr - 35 
		];
		bisectstack[bisectptr - 31] = bisectstack[bisectptr - 35 
		]+ bisectstack[bisectptr - 34];
		if (bisectstack[bisectptr - 31]< 0) 
		bisectstack[bisectptr - 31] = 0;
	      } 
	    } 
	    else if (bisectstack[bisectptr - 33]<= 0) 
	    {
	      if (bisectstack[bisectptr - 34] > 0) 
	      bisectstack[bisectptr - 31] = bisectstack[bisectptr - 35]
	      + bisectstack[bisectptr - 34];
	      else bisectstack[bisectptr - 31] = bisectstack[bisectptr - 
	      35];
	      bisectstack[bisectptr - 32] = bisectstack[bisectptr - 35]
	      + bisectstack[bisectptr - 34]+ bisectstack[bisectptr - 33 
	    ];
	      if (bisectstack[bisectptr - 32] > 0) 
	      bisectstack[bisectptr - 32] = 0;
	    } 
	    else {
		
	      bisectstack[bisectptr - 31] = bisectstack[bisectptr - 35]
	      + bisectstack[bisectptr - 34]+ bisectstack[bisectptr - 33 
	    ];
	      if (bisectstack[bisectptr - 31]< bisectstack[bisectptr - 
	      35]) 
	      bisectstack[bisectptr - 31] = bisectstack[bisectptr - 35]
	  ;
	      bisectstack[bisectptr - 32] = bisectstack[bisectptr - 35]
	      + bisectstack[bisectptr - 34];
	      if (bisectstack[bisectptr - 32] > 0) 
	      bisectstack[bisectptr - 32] = 0;
	    } 
	    if (bisectstack[bisectptr - 15]< 0) {
		
	      if (bisectstack[bisectptr - 13] >= 0) 
	      {
		if (bisectstack[bisectptr - 14]< 0) 
		bisectstack[bisectptr - 12] = bisectstack[bisectptr - 15 
		]+ bisectstack[bisectptr - 14];
		else bisectstack[bisectptr - 12] = bisectstack[bisectptr 
		- 15];
		bisectstack[bisectptr - 11] = bisectstack[bisectptr - 15 
		]+ bisectstack[bisectptr - 14]+ bisectstack[bisectptr - 
		13];
		if (bisectstack[bisectptr - 11]< 0) 
		bisectstack[bisectptr - 11] = 0;
	      } 
	      else {
		  
		bisectstack[bisectptr - 12] = bisectstack[bisectptr - 15 
		]+ bisectstack[bisectptr - 14]+ bisectstack[bisectptr - 
		13];
		if (bisectstack[bisectptr - 12] > bisectstack[bisectptr 
		- 15]) 
		bisectstack[bisectptr - 12] = bisectstack[bisectptr - 15 
		];
		bisectstack[bisectptr - 11] = bisectstack[bisectptr - 15 
		]+ bisectstack[bisectptr - 14];
		if (bisectstack[bisectptr - 11]< 0) 
		bisectstack[bisectptr - 11] = 0;
	      } 
	    } 
	    else if (bisectstack[bisectptr - 13]<= 0) 
	    {
	      if (bisectstack[bisectptr - 14] > 0) 
	      bisectstack[bisectptr - 11] = bisectstack[bisectptr - 15]
	      + bisectstack[bisectptr - 14];
	      else bisectstack[bisectptr - 11] = bisectstack[bisectptr - 
	      15];
	      bisectstack[bisectptr - 12] = bisectstack[bisectptr - 15]
	      + bisectstack[bisectptr - 14]+ bisectstack[bisectptr - 13 
	    ];
	      if (bisectstack[bisectptr - 12] > 0) 
	      bisectstack[bisectptr - 12] = 0;
	    } 
	    else {
		
	      bisectstack[bisectptr - 11] = bisectstack[bisectptr - 15]
	      + bisectstack[bisectptr - 14]+ bisectstack[bisectptr - 13 
	    ];
	      if (bisectstack[bisectptr - 11]< bisectstack[bisectptr - 
	      15]) 
	      bisectstack[bisectptr - 11] = bisectstack[bisectptr - 15]
	  ;
	      bisectstack[bisectptr - 12] = bisectstack[bisectptr - 15]
	      + bisectstack[bisectptr - 14];
	      if (bisectstack[bisectptr - 12] > 0) 
	      bisectstack[bisectptr - 12] = 0;
	    } 
	    bisectstack[bisectptr - 40] = bisectstack[xy - 20];
	    bisectstack[bisectptr - 18] = bisectstack[xy - 18];
	    bisectstack[bisectptr - 39] = half (bisectstack[bisectptr - 
	    40]+ bisectstack[xy - 19]);
	    bisectstack[bisectptr - 19] = half (bisectstack[bisectptr - 
	    18]+ bisectstack[xy - 19]);
	    bisectstack[bisectptr - 38] = half (bisectstack[bisectptr - 
	    39]+ bisectstack[bisectptr - 19]);
	    bisectstack[bisectptr - 20] = bisectstack[bisectptr - 38];
	    if (bisectstack[bisectptr - 40]< 0) {
		
	      if (bisectstack[bisectptr - 38] >= 0) 
	      {
		if (bisectstack[bisectptr - 39]< 0) 
		bisectstack[bisectptr - 37] = bisectstack[bisectptr - 40 
		]+ bisectstack[bisectptr - 39];
		else bisectstack[bisectptr - 37] = bisectstack[bisectptr 
		- 40];
		bisectstack[bisectptr - 36] = bisectstack[bisectptr - 40 
		]+ bisectstack[bisectptr - 39]+ bisectstack[bisectptr - 
		38];
		if (bisectstack[bisectptr - 36]< 0) 
		bisectstack[bisectptr - 36] = 0;
	      } 
	      else {
		  
		bisectstack[bisectptr - 37] = bisectstack[bisectptr - 40 
		]+ bisectstack[bisectptr - 39]+ bisectstack[bisectptr - 
		38];
		if (bisectstack[bisectptr - 37] > bisectstack[bisectptr 
		- 40]) 
		bisectstack[bisectptr - 37] = bisectstack[bisectptr - 40 
		];
		bisectstack[bisectptr - 36] = bisectstack[bisectptr - 40 
		]+ bisectstack[bisectptr - 39];
		if (bisectstack[bisectptr - 36]< 0) 
		bisectstack[bisectptr - 36] = 0;
	      } 
	    } 
	    else if (bisectstack[bisectptr - 38]<= 0) 
	    {
	      if (bisectstack[bisectptr - 39] > 0) 
	      bisectstack[bisectptr - 36] = bisectstack[bisectptr - 40]
	      + bisectstack[bisectptr - 39];
	      else bisectstack[bisectptr - 36] = bisectstack[bisectptr - 
	      40];
	      bisectstack[bisectptr - 37] = bisectstack[bisectptr - 40]
	      + bisectstack[bisectptr - 39]+ bisectstack[bisectptr - 38 
	    ];
	      if (bisectstack[bisectptr - 37] > 0) 
	      bisectstack[bisectptr - 37] = 0;
	    } 
	    else {
		
	      bisectstack[bisectptr - 36] = bisectstack[bisectptr - 40]
	      + bisectstack[bisectptr - 39]+ bisectstack[bisectptr - 38 
	    ];
	      if (bisectstack[bisectptr - 36]< bisectstack[bisectptr - 
	      40]) 
	      bisectstack[bisectptr - 36] = bisectstack[bisectptr - 40]
	  ;
	      bisectstack[bisectptr - 37] = bisectstack[bisectptr - 40]
	      + bisectstack[bisectptr - 39];
	      if (bisectstack[bisectptr - 37] > 0) 
	      bisectstack[bisectptr - 37] = 0;
	    } 
	    if (bisectstack[bisectptr - 20]< 0) {
		
	      if (bisectstack[bisectptr - 18] >= 0) 
	      {
		if (bisectstack[bisectptr - 19]< 0) 
		bisectstack[bisectptr - 17] = bisectstack[bisectptr - 20 
		]+ bisectstack[bisectptr - 19];
		else bisectstack[bisectptr - 17] = bisectstack[bisectptr 
		- 20];
		bisectstack[bisectptr - 16] = bisectstack[bisectptr - 20 
		]+ bisectstack[bisectptr - 19]+ bisectstack[bisectptr - 
		18];
		if (bisectstack[bisectptr - 16]< 0) 
		bisectstack[bisectptr - 16] = 0;
	      } 
	      else {
		  
		bisectstack[bisectptr - 17] = bisectstack[bisectptr - 20 
		]+ bisectstack[bisectptr - 19]+ bisectstack[bisectptr - 
		18];
		if (bisectstack[bisectptr - 17] > bisectstack[bisectptr 
		- 20]) 
		bisectstack[bisectptr - 17] = bisectstack[bisectptr - 20 
		];
		bisectstack[bisectptr - 16] = bisectstack[bisectptr - 20 
		]+ bisectstack[bisectptr - 19];
		if (bisectstack[bisectptr - 16]< 0) 
		bisectstack[bisectptr - 16] = 0;
	      } 
	    } 
	    else if (bisectstack[bisectptr - 18]<= 0) 
	    {
	      if (bisectstack[bisectptr - 19] > 0) 
	      bisectstack[bisectptr - 16] = bisectstack[bisectptr - 20]
	      + bisectstack[bisectptr - 19];
	      else bisectstack[bisectptr - 16] = bisectstack[bisectptr - 
	      20];
	      bisectstack[bisectptr - 17] = bisectstack[bisectptr - 20]
	      + bisectstack[bisectptr - 19]+ bisectstack[bisectptr - 18 
	    ];
	      if (bisectstack[bisectptr - 17] > 0) 
	      bisectstack[bisectptr - 17] = 0;
	    } 
	    else {
		
	      bisectstack[bisectptr - 16] = bisectstack[bisectptr - 20]
	      + bisectstack[bisectptr - 19]+ bisectstack[bisectptr - 18 
	    ];
	      if (bisectstack[bisectptr - 16]< bisectstack[bisectptr - 
	      20]) 
	      bisectstack[bisectptr - 16] = bisectstack[bisectptr - 20]
	  ;
	      bisectstack[bisectptr - 17] = bisectstack[bisectptr - 20]
	      + bisectstack[bisectptr - 19];
	      if (bisectstack[bisectptr - 17] > 0) 
	      bisectstack[bisectptr - 17] = 0;
	    } 
	    uv = bisectptr - 20;
	    xy = bisectptr - 20;
	    delx = delx + delx;
	    dely = dely + dely;
	    tol = tol - threel + tolstep;
	    tol = tol + tol;
	    threel = threel + tolstep;
	    goto lab22;
	  } 
	} 
      } 
    } 
    if (timetogo > 0) 
    decr (timetogo);
    else {
	
      while (apprt < 65536L) {
	  
	apprt = apprt + apprt;
	apprtt = apprtt + apprtt;
      } 
      curt = apprt;
      curtt = apprtt;
      goto lab10;
    } 
    not_found: if (odd (curtt)) {
	
      if (odd (curt)) 
      {
	curt = halfp (curt);
	curtt = halfp (curtt);
	if (curt == 0) 
	goto lab10;
	bisectptr = bisectptr - 45;
	threel = threel - tolstep;
	delx = bisectstack[bisectptr];
	dely = bisectstack[bisectptr + 1];
	tol = bisectstack[bisectptr + 2];
	uv = bisectstack[bisectptr + 3];
	xy = bisectstack[bisectptr + 4];
	goto not_found;
      } 
      else {
	  
	incr (curt);
	delx = delx + bisectstack[uv - 5]+ bisectstack[uv - 4]+ 
	bisectstack[uv - 3];
	dely = dely + bisectstack[uv - 10]+ bisectstack[uv - 9]+ 
	bisectstack[uv - 8];
	uv = uv + 20;
	decr (curtt);
	xy = xy - 20;
	delx = delx + bisectstack[xy - 15]+ bisectstack[xy - 14]+ 
	bisectstack[xy - 13];
	dely = dely + bisectstack[xy - 20]+ bisectstack[xy - 19]+ 
	bisectstack[xy - 18];
      } 
    } 
    else {
	
      incr (curtt);
      tol = tol + threel;
      delx = delx - bisectstack[xy - 15] - bisectstack[xy - 14] - 
      bisectstack[xy - 13];
      dely = dely - bisectstack[xy - 20] - bisectstack[xy - 19] - 
      bisectstack[xy - 18];
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
  tolstep = 0;
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
	    if (curt > 0) 
	    {
	      curt = curt + n;
	      curtt = curtt + nn;
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
    tolstep = tolstep + 3;
  } while (!(tolstep > 3));
  curt = -65536L;
  curtt = -65536L;
  lab10:;
} 
void 
zopenawindow (windownumber k , scaled r0 , scaled c0 , scaled r1 , scaled c1 
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
  windowopen[k] = true;
  incr (windowtime[k]);
  leftcol[k] = c0;
  rightcol[k] = c1;
  toprow[k] = r0;
  botrow[k] = r1;
  m = roundunscaled (x);
  n = roundunscaled (y) - 1;
  mwindow[k] = c0 - m;
  nwindow[k] = r0 + n;
  {
    if (!screenstarted) 
    {
      screenOK = initscreen ();
      screenstarted = true;
    } 
  } 
  if (screenOK) 
  {
    blankrectangle (c0 , c1 , r0 , r1);
    updatescreen ();
  } 
} 
void 
zdispedges (windownumber k) 
{
  /* 30 40 */ halfword p, q;
  boolean alreadythere;
  integer r;
  screencol n;
  integer w, ww;
  pixelcolor b;
  integer m, mm;
  integer d;
  integer madjustment;
  integer rightedge;
  screencol mincol;
  if (screenOK) {
      
    if (leftcol[k]< rightcol[k]) {
	
      if (toprow[k]< botrow[k]) 
      {
	alreadythere = false;
	if (mem[curedges + 3].hhfield.v.RH == k) {
	    
	  if (mem[curedges + 4].cint == windowtime[k]) 
	  alreadythere = true;
	} 
	if (!alreadythere) 
	blankrectangle (leftcol[k], rightcol[k], toprow[k], 
	botrow[k]);
	madjustment = mwindow[k] - mem[curedges + 3].hhfield.lhfield;
	rightedge = 8 * (rightcol[k] - madjustment);
	mincol = leftcol[k];
	p = mem[curedges].hhfield.v.RH;
	r = nwindow[k] - (mem[curedges + 1].hhfield.lhfield - 4096) 
	;
	while ((p != curedges) && (r >= toprow[k])) {
	    
	  if (r < botrow[k]) 
	  {
	    if (mem[p + 1].hhfield.lhfield > 1) 
	    sortedges (p);
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
	    rowtransition[0] = mincol;
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
		      rowtransition[n] = m;
		    } 
		  } 
		} 
		else if (ww <= 0) {
		    
		  if (m > mincol) 
		  {
		    if (n == 0) 
		    b = 1;
		    incr (n);
		    rowtransition[n] = m;
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
	      rowtransition[n] = rightcol[k];
	    } 
	    else if (n == 0) 
	    goto done;
	    paintrow (r , b , rowtransition , n);
	    done:;
	  } 
	  p = mem[p].hhfield.v.RH;
	  decr (r);
	} 
	updatescreen ();
	incr (windowtime[k]);
	mem[curedges + 3].hhfield.v.RH = k;
	mem[curedges + 4].cint = windowtime[k];
      } 
    } 
  } 
} 
fraction 
zmaxcoef (halfword p) 
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
	    
	  if (watchcoefs) 
	  {
	    mem[qq].hhfield.b0 = 0;
	    fixneeded = true;
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
  depfinal = p;
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
	fixneeded = true;
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
  mem[depfinal].hhfield.v.RH = r;
  mem[r + 1].hhfield.lhfield = depfinal;
  mem[13].hhfield.v.RH = q;
} 
halfword 
zconstdependency (scaled v) 
{
  register halfword Result; depfinal = get_node (2);
  mem[depfinal + 1].cint = v;
  mem[depfinal].hhfield.lhfield = 0;
  Result = depfinal;
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
    mem[q + 1].cint = twotothe[28 - m];
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
  depfinal = q;
  while (true) {
      
    mem[depfinal].hhfield.lhfield = mem[p].hhfield.lhfield;
    mem[depfinal + 1].cint = mem[p + 1].cint;
    if (mem[depfinal].hhfield.lhfield == 0) 
    goto done;
    mem[depfinal].hhfield.v.RH = get_node (2);
    depfinal = mem[depfinal].hhfield.v.RH;
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
      else w = mem[r + 1].cint / twotothe[n];
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
    depfinal = finalnode;
    newdep (x , p);
    if (cur_exp == x) {
	
      if (cur_type == 19) 
      cur_type = 17;
    } 
  } 
  if (fixneeded) 
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
	  if (strref[v]< 127) 
	  incr (strref[v]);
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
      mem[q + 1].cint = copyedges (v);
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
	  if ((filelineerrorstylep && !(curinput .namefield == 0))) 
	  {
	    print_nl (261);
	    print (fullsourcefilenamestack[inopen]);
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
zshowcmdmod (integer c , integer m) 
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
  /* 30 */ unsigned char oldsetting;
  integer i;
  integer l;
  integer m;
  integer n;
  integer p;
  integer q;
  fileptr = inputptr;
  inputstack[fileptr] = curinput;
  while (true) {
      
    curinput = inputstack[fileptr];
    if ((fileptr == inputptr) || (curinput.indexfield <= 15) || (
    curinput.indexfield != 19) || (curinput.locfield != 0)) 
    {
      tally = 0;
      oldsetting = selector;
      if ((curinput.indexfield <= 15)) 
      {
	if (curinput .namefield <= 1) {
	    
	  if ((curinput .namefield == 0) && (fileptr == 0)) 
	  print_nl (604);
	  else print_nl (605);
	} 
	else if (curinput .namefield == 2) 
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
	  trickcount = 1000000L;
	} 
	if (curinput .limitfield > 0) 
	{register integer for_end; i = curinput .startfield;for_end = 
	curinput .limitfield - 1; if (i <= for_end) do 
	  {
	    if (i == curinput.locfield) 
	    {
	      firstcount = tally;
	      trickcount = tally + 1 + errorline - halferrorline;
	      if (trickcount < errorline) 
	      trickcount = errorline;
	    } 
	    print (buffer[i]);
	  } 
	while (i++ < for_end);} 
      } 
      else {
	  
	switch (curinput.indexfield) 
	{case 16 : 
	  print_nl (608);
	  break;
	case 17 : 
	  {
	    print_nl (613);
	    p = paramstack[curinput .limitfield];
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
	  if (curinput.locfield == 0) 
	  print_nl (610);
	  else print_nl (611);
	  break;
	case 20 : 
	  print_nl (612);
	  break;
	case 21 : 
	  {
	    print_ln ();
	    if (curinput .namefield != 0) 
	    slow_print (hash[curinput .namefield].v.RH);
	    else {
		
	      p = paramstack[curinput .limitfield];
	      if (p == 0) 
	      show_token_list (paramstack[curinput .limitfield + 1], 0 , 20 
	      , tally);
	      else {
		  
		q = p;
		while (mem[q].hhfield.v.RH != 0) q = mem[q].hhfield 
		.v.RH;
		mem[q].hhfield.v.RH = paramstack[curinput .limitfield + 
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
	  trickcount = 1000000L;
	} 
	if (curinput.indexfield != 21) 
	show_token_list (curinput .startfield , curinput.locfield , 100000L , 
	0);
	else show_macro (curinput .startfield , curinput.locfield , 100000L) 
	;
      } 
      selector = oldsetting;
      if (trickcount == 1000000L) 
      {
	firstcount = tally;
	trickcount = tally + 1 + errorline - halferrorline;
	if (trickcount < errorline) 
	trickcount = errorline;
      } 
      if (tally < trickcount) 
      m = tally - firstcount;
      else m = trickcount - firstcount;
      if (l + firstcount <= halferrorline) 
      {
	p = 0;
	n = l + firstcount;
      } 
      else {
	  
	print (276);
	p = l + firstcount - halferrorline + 3;
	n = halferrorline;
      } 
      {register integer for_end; q = p;for_end = firstcount - 1; if (q <= 
      for_end) do 
	print_char (trickbuf[q % errorline]);
      while (q++ < for_end);} 
      print_ln ();
      {register integer for_end; q = 1;for_end = n; if (q <= for_end) do 
	print_char (32);
      while (q++ < for_end);} 
      if (m + n <= errorline) 
      p = firstcount + m;
      else p = firstcount + (errorline - n - 3);
      {register integer for_end; q = firstcount;for_end = p - 1; if (q <= 
      for_end) do 
	print_char (trickbuf[q % errorline]);
      while (q++ < for_end);} 
      if (m + n > errorline) 
      print (276);
    } 
    if ((curinput.indexfield <= 15)) {
	
      if ((curinput .namefield > 2) || (fileptr == 0)) 
      goto done;
    } 
    decr (fileptr);
  } 
  done: curinput = inputstack[inputptr];
} 
void 
zbegintokenlist (halfword p , quarterword t) 
{
  {
    if (inputptr > maxinstack) 
    {
      maxinstack = inputptr;
      if (inputptr == stacksize) 
      overflow (615 , stacksize);
    } 
    inputstack[inputptr] = curinput;
    incr (inputptr);
  } 
  curinput .startfield = p;
  curinput.indexfield = t;
  curinput .limitfield = paramptr;
  curinput.locfield = p;
} 
void 
endtokenlist (void) 
{
  /* 30 */ halfword p;
  if (curinput.indexfield >= 19) {
      
    if (curinput.indexfield <= 20) 
    {
      flush_token_list (curinput .startfield);
      goto done;
    } 
    else delete_mac_ref (curinput .startfield);
  } 
  while (paramptr > curinput .limitfield) {
      
    decr (paramptr);
    p = paramstack[paramptr];
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
      
    decr (inputptr);
    curinput = inputstack[inputptr];
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
    if (p == depfinal) 
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
	if (strref[cur_exp]< 127) 
	incr (strref[cur_exp]);
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
    cur_exp = copyedges (mem[p + 1].cint);
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
      q = mem[p + 1].cint + bignodesize[cur_type];
      r = mem[t + 1].cint + bignodesize[cur_type];
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
	if (serialno > 2147483583L) 
	overflow (588 , serialno / 64);
	mem[p].hhfield.b0 = 19;
	serialno = serialno + 64;
	mem[p + 1].cint = serialno;
      } 
      goto lab20;
    } 
    break;
  case 19 : 
    {
      q = singledependency (p);
      if (q == depfinal) 
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
curtok (void) 
{
  register halfword Result; halfword p;
  small_number savetype;
  integer saveexp;
  if (cursym == 0) {
      
    if (curcmd == 38) 
    {
      savetype = cur_type;
      saveexp = cur_exp;
      makeexpcopy (curmod);
      p = stash_cur_exp ();
      mem[p].hhfield.v.RH = 0;
      cur_type = savetype;
      cur_exp = saveexp;
    } 
    else {
	
      p = get_node (2);
      mem[p + 1].cint = curmod;
      mem[p].hhfield.b1 = 12;
      if (curcmd == 42) 
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
	incr (dynused);
#endif /* STAT */
      } 
    } 
    mem[p].hhfield.lhfield = cursym;
  } 
  Result = p;
  return Result;
} 
void 
backinput (void) 
{
  halfword p;
  p = curtok ();
  while ((curinput.indexfield > 15) && (curinput.locfield == 0)) 
  endtokenlist ();
  begintokenlist (p , 19);
} 
void 
backerror (void) 
{
  OKtointerrupt = false;
  backinput ();
  OKtointerrupt = true;
  error ();
} 
void 
inserror (void) 
{
  OKtointerrupt = false;
  backinput ();
  curinput.indexfield = 20;
  OKtointerrupt = true;
  error ();
} 
void 
beginfilereading (void) 
{
  if (inopen == 15) 
  overflow (616 , 15);
  if (first == bufsize) 
  overflow (256 , bufsize);
  incr (inopen);
  {
    if (inputptr > maxinstack) 
    {
      maxinstack = inputptr;
      if (inputptr == stacksize) 
      overflow (615 , stacksize);
    } 
    inputstack[inputptr] = curinput;
    incr (inputptr);
  } 
  curinput.indexfield = inopen;
  linestack[curinput.indexfield] = line;
  curinput .startfield = first;
  curinput .namefield = 0;
} 
void 
endfilereading (void) 
{
  first = curinput .startfield;
  line = linestack[curinput.indexfield];
  if (curinput.indexfield != inopen) 
  confusion (617);
  if (curinput .namefield > 2) 
  aclose (inputfile[curinput.indexfield]);
  {
    decr (inputptr);
    curinput = inputstack[inputptr];
  } 
  decr (inopen);
} 
void 
clearforerrorprompt (void) 
{
  while ((curinput.indexfield <= 15) && (curinput .namefield == 0) && 
  (inputptr > 0) && (curinput.locfield == curinput .limitfield)) 
  endfilereading ();
  print_ln ();
} 
boolean 
checkoutervalidity (void) 
{
  register boolean Result; halfword p;
  if (scannerstatus == 0) 
  Result = true;
  else {
      
    deletionsallowed = false;
    if (cursym != 0) 
    {
      p = get_avail ();
      mem[p].hhfield.lhfield = cursym;
      begintokenlist (p , 19);
    } 
    if (scannerstatus > 1) 
    {
      runaway ();
      if (cursym == 0) 
      {
	if (interaction == 3) 
	;
	if ((filelineerrorstylep && !(curinput .namefield == 0))) 
	{
	  print_nl (261);
	  print (fullsourcefilenamestack[inopen]);
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
	  if ((filelineerrorstylep && !(curinput .namefield == 0))) 
	  {
	    print_nl (261);
	    print (fullsourcefilenamestack[inopen]);
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
      switch (scannerstatus) 
      {case 2 : 
	{
	  print (630);
	  help_line[3] = 631;
	  cursym = 9763;
	} 
	break;
      case 3 : 
	{
	  print (632);
	  help_line[3] = 633;
	  if (warninginfo == 0) 
	  cursym = 9767;
	  else {
	      
	    cursym = 9759;
	    eqtb[9759].v.RH = warninginfo;
	  } 
	} 
	break;
      case 4 : 
      case 5 : 
	{
	  print (634);
	  if (scannerstatus == 5) 
	  slow_print (hash[warninginfo].v.RH);
	  else print_variable_name (warninginfo);
	  cursym = 9765;
	} 
	break;
      case 6 : 
	{
	  print (635);
	  slow_print (hash[warninginfo].v.RH);
	  print (636);
	  help_line[3] = 637;
	  cursym = 9764;
	} 
	break;
      } 
      inserror ();
    } 
    else {
	
      {
	if (interaction == 3) 
	;
	if ((filelineerrorstylep && !(curinput .namefield == 0))) 
	{
	  print_nl (261);
	  print (fullsourcefilenamestack[inopen]);
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
      print_int (warninginfo);
      {
	help_ptr = 3;
	help_line[2] = 619;
	help_line[1] = 620;
	help_line[0] = 621;
      } 
      if (cursym == 0) 
      help_line[2] = 622;
      cursym = 9766;
      inserror ();
    } 
    deletionsallowed = true;
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
  lab20: cursym = 0;
  if ((curinput.indexfield <= 15)) 
  {
    lab25: c = buffer[curinput.locfield];
    incr (curinput.locfield);
    cclass = char_class[c];
    switch (cclass) 
    {case 0 : 
      goto lab85;
      break;
    case 1 : 
      {
	cclass = char_class[buffer[curinput.locfield]];
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
	if (curinput .namefield > 2) 
	{
	  incr (line);
	  first = curinput .startfield;
	  if (!forceeof) 
	  {
	    if (inputln (inputfile[curinput.indexfield], true)) 
	    firmuptheline ();
	    else forceeof = true;
	  } 
	  if (forceeof) 
	  {
	    print_char (41);
	    decr (openparens);
	    fflush (stdout);
	    forceeof = false;
	    endfilereading ();
	    if (checkoutervalidity ()) 
	    goto lab20;
	    else goto lab20;
	  } 
	  buffer[curinput .limitfield] = 37;
	  first = curinput .limitfield + 1;
	  curinput.locfield = curinput .startfield;
	} 
	else {
	    
	  if (inputptr > 0) 
	  {
	    endfilereading ();
	    goto lab20;
	  } 
	  if (selector < 2) 
	  open_log_file ();
	  if (interaction > 1) 
	  {
	    if (curinput .limitfield == curinput .startfield) 
	    print_nl (652);
	    print_ln ();
	    first = curinput .startfield;
	    {
	  ;
	      print (42);
	      term_input ();
	    } 
	    curinput .limitfield = last;
	    buffer[curinput .limitfield] = 37;
	    first = curinput .limitfield + 1;
	    curinput.locfield = curinput .startfield;
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
	if (buffer[curinput.locfield] == 34) 
	curmod = 261;
	else {
	    
	  k = curinput.locfield;
	  buffer[curinput .limitfield + 1] = 34;
	  do {
	      incr (curinput.locfield);
	  } while (!(buffer[curinput.locfield] == 34));
	  if (curinput.locfield > curinput .limitfield) 
	  {
	    curinput.locfield = curinput .limitfield;
	    {
	      if (interaction == 3) 
	  ;
	      if ((filelineerrorstylep && !(curinput .namefield == 0))) 
	      {
		print_nl (261);
		print (fullsourcefilenamestack[inopen]);
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
	    deletionsallowed = false;
	    error ();
	    deletionsallowed = true;
	    goto lab20;
	  } 
	  if ((curinput.locfield == k + 1) && ((str_start[buffer[k]
	  + 1] - str_start[buffer[k]]) == 1)) 
	  curmod = buffer[k];
	  else {
	      
	    {
	      if (pool_ptr + curinput.locfield - k > max_pool_ptr) 
	      {
		if (pool_ptr + curinput.locfield - k > pool_size) 
		overflow (257 , pool_size - init_pool_ptr);
		max_pool_ptr = pool_ptr + curinput.locfield - k;
	      } 
	    } 
	    do {
		{ 
		str_pool[pool_ptr] = buffer[k];
		incr (pool_ptr);
	      } 
	      incr (k);
	    } while (!(k == curinput.locfield));
	    curmod = make_string ();
	  } 
	} 
	incr (curinput.locfield);
	curcmd = 39;
	goto lab10;
      } 
      break;
    case 5 : 
    case 6 : 
    case 7 : 
    case 8 : 
      {
	k = curinput.locfield - 1;
	goto found;
      } 
      break;
    case 20 : 
      {
	{
	  if (interaction == 3) 
	;
	  if ((filelineerrorstylep && !(curinput .namefield == 0))) 
	  {
	    print_nl (261);
	    print (fullsourcefilenamestack[inopen]);
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
	deletionsallowed = false;
	error ();
	deletionsallowed = true;
	goto lab20;
      } 
      break;
      default: 
  ;
      break;
    } 
    k = curinput.locfield - 1;
    while (char_class[buffer[curinput.locfield]] == cclass) incr (
    curinput.locfield);
    goto found;
    lab85: n = c - 48;
    while (char_class[buffer[curinput.locfield]] == 0) {
	
      if (n < 4096) 
      n = 10 * n + buffer[curinput.locfield] - 48;
      incr (curinput.locfield);
    } 
    if (buffer[curinput.locfield] == 46) {
	
      if (char_class[buffer[curinput.locfield + 1]] == 0) 
      goto done;
    } 
    f = 0;
    goto lab87;
    done: incr (curinput.locfield);
    lab86: k = 0;
    do {
	if (k < 17) 
      {
	dig[k] = buffer[curinput.locfield] - 48;
	incr (k);
      } 
      incr (curinput.locfield);
    } while (!(char_class[buffer[curinput.locfield]]!= 0));
    f = round_decimals (k);
    if (f == 65536L) 
    {
      incr (n);
      f = 0;
    } 
    lab87: if (n < 4096) 
    curmod = n * 65536L + f;
    else {
	
      {
	if (interaction == 3) 
	;
	if ((filelineerrorstylep && !(curinput .namefield == 0))) 
	{
	  print_nl (261);
	  print (fullsourcefilenamestack[inopen]);
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
      deletionsallowed = false;
      error ();
      deletionsallowed = true;
      curmod = 268435455L;
    } 
    curcmd = 42;
    goto lab10;
    found: cursym = id_lookup (k , curinput.locfield - k);
  } 
  else if (curinput.locfield >= himemmin) 
  {
    cursym = mem[curinput.locfield].hhfield.lhfield;
    curinput.locfield = mem[curinput.locfield].hhfield.v.RH;
    if (cursym >= 9770) {
	
      if (cursym >= 9920) 
      {
	if (cursym >= 10070) 
	cursym = cursym - 150;
	begintokenlist (paramstack[curinput .limitfield + cursym - (9920) 
	], 18);
	goto lab20;
      } 
      else {
	  
	curcmd = 38;
	curmod = paramstack[curinput .limitfield + cursym - (9770)];
	cursym = 0;
	goto lab10;
      } 
    } 
  } 
  else if (curinput.locfield > 0) 
  {
    if (mem[curinput.locfield].hhfield.b1 == 12) 
    {
      curmod = mem[curinput.locfield + 1].cint;
      if (mem[curinput.locfield].hhfield.b0 == 16) 
      curcmd = 42;
      else {
	  
	curcmd = 39;
	{
	  if (strref[curmod]< 127) 
	  incr (strref[curmod]);
	} 
      } 
    } 
    else {
	
      curmod = curinput.locfield;
      curcmd = 38;
    } 
    curinput.locfield = mem[curinput.locfield].hhfield.v.RH;
    goto lab10;
  } 
  else {
      
    endtokenlist ();
    goto lab20;
  } 
  curcmd = eqtb[cursym].lhfield;
  curmod = eqtb[cursym].v.RH;
  if (curcmd >= 86) {
      
    if (checkoutervalidity ()) 
    curcmd = curcmd - 86;
    else goto lab20;
  } 
  lab10:;
} 
void 
firmuptheline (void) 
{
  integer k;
  curinput .limitfield = last;
  if (internal[31] > 0) {
      
    if (interaction > 1) 
    {
  ;
      print_ln ();
      if (curinput .startfield < curinput .limitfield) 
      {register integer for_end; k = curinput .startfield;for_end = 
      curinput .limitfield - 1; if (k <= for_end) do 
	print (buffer[k]);
      while (k++ < for_end);} 
      first = curinput .limitfield;
      {
	;
	print (654);
	term_input ();
      } 
      if (last > first) 
      {
	{register integer for_end; k = first;for_end = last - 1; if (k <= 
	for_end) do 
	  buffer[k + curinput .startfield - first] = buffer[k];
	while (k++ < for_end);} 
	curinput .limitfield = curinput .startfield + last - first;
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
    if (cursym > 0) 
    {
      {
	q = substlist;
	while (q != 0) {
	    
	  if (mem[q].hhfield.lhfield == cursym) 
	  {
	    cursym = mem[q + 1].cint;
	    curcmd = 7;
	    goto found;
	  } 
	  q = mem[q].hhfield.v.RH;
	} 
	found:;
      } 
      if (curcmd == terminator) {
	  
	if (curmod > 0) 
	incr (balance);
	else {
	    
	  decr (balance);
	  if (balance == 0) 
	  goto done;
	} 
      } 
      else if (curcmd == 61) 
      {
	if (curmod == 0) 
	getnext ();
	else if (curmod <= suffixcount) 
	cursym = 9919 + curmod;
      } 
    } 
    mem[p].hhfield.v.RH = curtok ();
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
  if ((cursym == 0) || (cursym > 9757)) 
  {
    {
      if (interaction == 3) 
  ;
      if ((filelineerrorstylep && !(curinput .namefield == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[inopen]);
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
    if (cursym > 0) 
    help_line[2] = 670;
    else if (curcmd == 39) 
    {
      if (strref[curmod]< 127) {
	  
	if (strref[curmod] > 1) 
	decr (strref[curmod]);
	else flush_string (curmod);
      } 
    } 
    cursym = 9757;
    inserror ();
    goto lab20;
  } 
} 
void 
getclearsymbol (void) 
{
  getsymbol ();
  clearsymbol (cursym , false);
} 
void 
checkequals (void) 
{
  if (curcmd != 51) {
      
    if (curcmd != 77) 
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
  m = curmod;
  getsymbol ();
  q = get_node (2);
  mem[q].hhfield.lhfield = cursym;
  mem[q + 1].cint = 9770;
  getclearsymbol ();
  warninginfo = cursym;
  getsymbol ();
  p = get_node (2);
  mem[p].hhfield.lhfield = cursym;
  mem[p + 1].cint = 9771;
  mem[p].hhfield.v.RH = q;
  getnext ();
  checkequals ();
  scannerstatus = 5;
  q = get_avail ();
  mem[q].hhfield.lhfield = 0;
  r = get_avail ();
  mem[q].hhfield.v.RH = r;
  mem[r].hhfield.lhfield = 0;
  mem[r].hhfield.v.RH = scantoks (16 , p , 0 , 0);
  scannerstatus = 0;
  eqtb[warninginfo].lhfield = m;
  eqtb[warninginfo].v.RH = q;
  getxnext ();
} 
void 
zcheckdelimiter (halfword ldelim , halfword rdelim) 
{
  /* 10 */ if (curcmd == 62) {
      
    if (curmod == ldelim) 
    goto lab10;
  } 
  if (cursym != rdelim) 
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
      if ((filelineerrorstylep && !(curinput .namefield == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[inopen]);
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
  x = cursym;
  if (curcmd != 41) 
  clearsymbol (x , false);
  h = get_avail ();
  mem[h].hhfield.lhfield = x;
  t = h;
  while (true) {
      
    getxnext ();
    if (cursym == 0) 
    goto done;
    if (curcmd != 41) {
	
      if (curcmd != 40) {
	  
	if (curcmd == 63) 
	{
	  l = cursym;
	  getxnext ();
	  if (curcmd != 64) 
	  {
	    backinput ();
	    cursym = l;
	    curcmd = 63;
	    goto done;
	  } 
	  else cursym = 0;
	} 
	else goto done;
      } 
    } 
    mem[t].hhfield.v.RH = get_avail ();
    t = mem[t].hhfield.v.RH;
    mem[t].hhfield.lhfield = cursym;
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
  m = curmod;
  c = 0;
  mem[memtop - 2].hhfield.v.RH = 0;
  q = get_avail ();
  mem[q].hhfield.lhfield = 0;
  r = 0;
  if (m == 1) 
  {
    getclearsymbol ();
    warninginfo = cursym;
    getnext ();
    scannerstatus = 5;
    n = 0;
    eqtb[warninginfo].lhfield = 10;
    eqtb[warninginfo].v.RH = q;
  } 
  else {
      
    p = scandeclaredvariable ();
    flushvariable (eqtb[mem[p].hhfield.lhfield].v.RH , mem[p]
    .hhfield.v.RH , true);
    warninginfo = find_variable (p);
    flush_list (p);
    if (warninginfo == 0) 
    {
      {
	if (interaction == 3) 
	;
	if ((filelineerrorstylep && !(curinput .namefield == 0))) 
	{
	  print_nl (261);
	  print (fullsourcefilenamestack[inopen]);
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
      warninginfo = 21;
    } 
    scannerstatus = 4;
    n = 2;
    if (curcmd == 61) {
	
      if (curmod == 3) 
      {
	n = 3;
	getnext ();
      } 
    } 
    mem[warninginfo].hhfield.b0 = 20 + n;
    mem[warninginfo + 1].cint = q;
  } 
  k = n;
  if (curcmd == 31) 
  do {
      ldelim = cursym;
    rdelim = curmod;
    getnext ();
    if ((curcmd == 56) && (curmod >= 9770)) 
    base = curmod;
    else {
	
      {
	if (interaction == 3) 
	;
	if ((filelineerrorstylep && !(curinput .namefield == 0))) 
	{
	  print_nl (261);
	  print (fullsourcefilenamestack[inopen]);
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
      mem[p].hhfield.lhfield = cursym;
      if (k == 150) 
      overflow (687 , 150);
      incr (k);
      mem[p].hhfield.v.RH = r;
      r = p;
      getnext ();
    } while (!(curcmd != 82));
    checkdelimiter (ldelim , rdelim);
    getnext ();
  } while (!(curcmd != 31));
  if (curcmd == 56) 
  {
    p = get_node (2);
    if (curmod < 9770) 
    {
      c = curmod;
      mem[p + 1].cint = 9770 + k;
    } 
    else {
	
      mem[p + 1].cint = curmod + k;
      if (curmod == 9770) 
      c = 4;
      else if (curmod == 9920) 
      c = 6;
      else c = 7;
    } 
    if (k == 150) 
    overflow (687 , 150);
    incr (k);
    getsymbol ();
    mem[p].hhfield.lhfield = cursym;
    mem[p].hhfield.v.RH = r;
    r = p;
    getnext ();
    if (c == 4) {
	
      if (curcmd == 69) 
      {
	c = 5;
	p = get_node (2);
	if (k == 150) 
	overflow (687 , 150);
	mem[p + 1].cint = 9770 + k;
	getsymbol ();
	mem[p].hhfield.lhfield = cursym;
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
    mem[q].hhfield.lhfield = bgloc;
    mem[p].hhfield.v.RH = q;
    p = get_avail ();
    mem[p].hhfield.lhfield = egloc;
    mem[q].hhfield.v.RH = scantoks (16 , r , p , n);
  } 
  if (warninginfo == 21) 
  flush_token_list (mem[22].cint);
  scannerstatus = 0;
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
  warninginfo = ldelim;
  scannerstatus = 3;
  p = memtop - 2;
  balance = 1;
  mem[memtop - 2].hhfield.v.RH = 0;
  while (true) {
      
    getnext ();
    if (ldelim == 0) 
    {
      if (curcmd > 82) 
      {
	if (balance == 1) 
	goto done;
	else if (curcmd == 84) 
	decr (balance);
      } 
      else if (curcmd == 32) 
      incr (balance);
    } 
    else {
	
      if (curcmd == 62) 
      {
	if (curmod == ldelim) 
	{
	  decr (balance);
	  if (balance == 0) 
	  goto done;
	} 
      } 
      else if (curcmd == 31) {
	  
	if (curmod == rdelim) 
	incr (balance);
      } 
    } 
    mem[p].hhfield.v.RH = curtok ();
    p = mem[p].hhfield.v.RH;
  } 
  done: cur_exp = mem[memtop - 2].hhfield.v.RH;
  cur_type = 20;
  scannerstatus = 0;
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
  curcmd = 83;
  while (mem[r].hhfield.lhfield >= 9770) {
      
    if (curcmd != 82) 
    {
      getxnext ();
      if (curcmd != 31) 
      {
	{
	  if (interaction == 3) 
	;
	  if ((filelineerrorstylep && !(curinput .namefield == 0))) 
	  {
	    print_nl (261);
	    print (fullsourcefilenamestack[inopen]);
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
	curcmd = 62;
	goto found;
      } 
      ldelim = cursym;
      rdelim = curmod;
    } 
    if (mem[r].hhfield.lhfield >= 10070) 
    scantextarg (ldelim , rdelim);
    else {
	
      getxnext ();
      if (mem[r].hhfield.lhfield >= 9920) 
      scansuffix ();
      else scan_expression ();
    } 
    if (curcmd != 82) {
	
      if ((curcmd != 62) || (curmod != ldelim)) {
	  
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
	  curcmd = 82;
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
  if (curcmd == 82) 
  {
    {
      if (interaction == 3) 
  ;
      if ((filelineerrorstylep && !(curinput .namefield == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[inopen]);
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
	  
	if ((curcmd == 51) || (curcmd == 77)) 
	getxnext ();
      } 
    } 
    switch (mem[r].hhfield.lhfield) 
    {case 1 : 
      scanprimary ();
      break;
    case 2 : 
      scansecondary ();
      break;
    case 3 : 
      scantertiary ();
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
	if (curcmd != 69) 
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
	scanprimary ();
      } 
      break;
    case 6 : 
      {
	if (curcmd != 31) 
	ldelim = 0;
	else {
	    
	  ldelim = cursym;
	  rdelim = curmod;
	  getxnext ();
	} 
	scansuffix ();
	if (ldelim != 0) 
	{
	  if ((curcmd != 62) || (curmod != ldelim)) 
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
  while ((curinput.indexfield > 15) && (curinput.locfield == 0)) 
  endtokenlist ();
  if (paramptr + n > maxparamstack) 
  {
    maxparamstack = paramptr + n;
    if (maxparamstack > 150) 
    overflow (687 , 150);
  } 
  begintokenlist (defref , 21);
  curinput .namefield = macroname;
  curinput.locfield = r;
  if (n > 0) 
  {
    p = arglist;
    do {
	paramstack[paramptr] = mem[p].hhfield.lhfield;
      incr (paramptr);
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
      
    if (curcmd != 10) 
    showcmdmod (curcmd , curmod);
  } 
  switch (curcmd) 
  {case 1 : 
    conditional ();
    break;
  case 2 : 
    if (curmod > iflimit) {
	
      if (iflimit == 1) 
      {
	missing_err (58);
	backinput ();
	cursym = 9762;
	inserror ();
      } 
      else {
	  
	{
	  if (interaction == 3) 
	;
	  if ((filelineerrorstylep && !(curinput .namefield == 0))) 
	  {
	    print_nl (261);
	    print (fullsourcefilenamestack[inopen]);
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
	print_cmd_mod (2 , curmod);
	{
	  help_ptr = 1;
	  help_line[0] = 725;
	} 
	error ();
      } 
    } 
    else {
	
      while (curmod != 2) passtext ();
      {
	p = condptr;
	ifline = mem[p + 1].cint;
	curif = mem[p].hhfield.b1;
	iflimit = mem[p].hhfield.b0;
	condptr = mem[p].hhfield.v.RH;
	free_node (p , 2);
      } 
    } 
    break;
  case 3 : 
    if (curmod > 0) 
    forceeof = true;
    else start_input ();
    break;
  case 4 : 
    if (curmod == 0) 
    {
      {
	if (interaction == 3) 
	;
	if ((filelineerrorstylep && !(curinput .namefield == 0))) 
	{
	  print_nl (261);
	  print (fullsourcefilenamestack[inopen]);
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
      while ((curinput.indexfield > 15) && (curinput.locfield == 0)) 
      endtokenlist ();
      if (loopptr == 0) 
      {
	{
	  if (interaction == 3) 
	;
	  if ((filelineerrorstylep && !(curinput .namefield == 0))) 
	  {
	    print_nl (261);
	    print (fullsourcefilenamestack[inopen]);
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
      getboolean ();
      if (internal[7] > 65536L) 
      showcmdmod (33 , cur_exp);
      if (cur_exp == 30) {
	  
	if (loopptr == 0) 
	{
	  {
	    if (interaction == 3) 
	;
	    if ((filelineerrorstylep && !(curinput .namefield == 0))) 
	    {
	      print_nl (261);
	      print (fullsourcefilenamestack[inopen]);
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
	  if (curcmd == 83) 
	  error ();
	  else backerror ();
	} 
	else {
	    
	  p = 0;
	  do {
	      if ((curinput.indexfield <= 15)) 
	    endfilereading ();
	    else {
		
	      if (curinput.indexfield <= 17) 
	      p = curinput .startfield;
	      endtokenlist ();
	    } 
	  } while (!(p != 0));
	  if (p != mem[loopptr].hhfield.lhfield) 
	  fatal_error (699);
	  stop_iteration ();
	} 
      } 
      else if (curcmd != 83) 
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
      p = curtok ();
      getnext ();
      if (curcmd < 11) 
      expand ();
      else backinput ();
      begintokenlist (p , 19);
    } 
    break;
  case 8 : 
    {
      getxnext ();
      scanprimary ();
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
	  curinput .namefield = 2;
	  k = first + (str_start[cur_exp + 1] - str_start[cur_exp]);
	  if (k >= maxbufstack) 
	  {
	    if (k >= bufsize) 
	    {
	      maxbufstack = bufsize;
	      overflow (256 , bufsize);
	    } 
	    maxbufstack = k + 1;
	  } 
	  j = str_start[cur_exp];
	  curinput .limitfield = k;
	  while (first < curinput .limitfield) {
	      
	    buffer[first] = str_pool[j];
	    incr (j);
	    incr (first);
	  } 
	  buffer[curinput .limitfield] = 37;
	  first = curinput .limitfield + 1;
	  curinput.locfield = curinput .startfield;
	  flush_cur_exp (0);
	} 
      } 
    } 
    break;
  case 10 : 
    macrocall (curmod , 0 , cursym);
    break;
  } 
} 
void 
getxnext (void) 
{
  halfword saveexp;
  getnext ();
  if (curcmd < 11) 
  {
    saveexp = stash_cur_exp ();
    do {
	if (curcmd == 10) 
      macrocall (curmod , 0 , cursym);
      else expand ();
      getnext ();
    } while (!(curcmd >= 11));
    unstash_cur_exp (saveexp);
  } 
} 
void 
zstackargument (halfword p) 
{
  if (paramptr == maxparamstack) 
  {
    incr (maxparamstack);
    if (maxparamstack > 150) 
    overflow (687 , 150);
  } 
  paramstack[paramptr] = p;
  incr (paramptr);
} 
void 
passtext (void) 
{
  /* 30 */ integer l;
  scannerstatus = 1;
  l = 0;
  warninginfo = line;
  while (true) {
      
    getnext ();
    if (curcmd <= 2) {
	
      if (curcmd < 2) 
      incr (l);
      else {
	  
	if (l == 0) 
	goto done;
	if (curmod == 2) 
	decr (l);
      } 
    } 
    else if (curcmd == 39) 
    {
      if (strref[curmod]< 127) {
	  
	if (strref[curmod] > 1) 
	decr (strref[curmod]);
	else flush_string (curmod);
      } 
    } 
  } 
  done: scannerstatus = 0;
} 
void 
zchangeiflimit (small_number l , halfword p) 
{
  /* 10 */ halfword q;
  if (p == condptr) 
  iflimit = l;
  else {
      
    q = condptr;
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
  if (curcmd != 81) 
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
  /* 10 30 21 40 */ halfword savecondptr;
  unsigned char newiflimit;
  halfword p;
  {
    p = get_node (2);
    mem[p].hhfield.v.RH = condptr;
    mem[p].hhfield.b0 = iflimit;
    mem[p].hhfield.b1 = curif;
    mem[p + 1].cint = ifline;
    condptr = p;
    iflimit = 1;
    ifline = line;
    curif = 1;
  } 
  savecondptr = condptr;
  lab21: getboolean ();
  newiflimit = 4;
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
    changeiflimit (newiflimit , savecondptr);
    goto lab10;
  } 
  while (true) {
      
    passtext ();
    if (condptr == savecondptr) 
    goto done;
    else if (curmod == 2) 
    {
      p = condptr;
      ifline = mem[p + 1].cint;
      curif = mem[p].hhfield.b1;
      iflimit = mem[p].hhfield.b0;
      condptr = mem[p].hhfield.v.RH;
      free_node (p , 2);
    } 
  } 
  done: curif = curmod;
  ifline = line;
  if (curmod == 2) 
  {
    p = condptr;
    ifline = mem[p + 1].cint;
    curif = mem[p].hhfield.b1;
    iflimit = mem[p].hhfield.b0;
    condptr = mem[p].hhfield.v.RH;
    free_node (p , 2);
  } 
  else if (curmod == 4) 
  goto lab21;
  else {
      
    cur_exp = 30;
    newiflimit = 2;
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
  m = curmod;
  n = cursym;
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
  mem[p].hhfield.lhfield = cursym;
  mem[p + 1].cint = m;
  getxnext ();
  if ((curcmd != 51) && (curcmd != 77)) 
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
    scansuffix ();
    else {
	
      if (curcmd >= 81) {
	  
	if (curcmd <= 82) 
	goto lab22;
      } 
      scan_expression ();
      if (curcmd == 74) {
	  
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
	  if (curcmd != 75) 
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
  } while (!(curcmd != 82));
  done:;
  found: if (curcmd != 81) 
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
  scannerstatus = 6;
  warninginfo = n;
  mem[s].hhfield.lhfield = scantoks (4 , p , q , 0);
  scannerstatus = 0;
  mem[s].hhfield.v.RH = loopptr;
  loopptr = s;
  resumeiteration ();
} 
void 
resumeiteration (void) 
{
  /* 45 10 */ halfword p, q;
  p = mem[loopptr + 1].hhfield.lhfield;
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
    p = mem[loopptr + 1].hhfield.v.RH;
    if (p == 0) 
    goto not_found;
    mem[loopptr + 1].hhfield.v.RH = mem[p].hhfield.v.RH;
    q = mem[p].hhfield.lhfield;
    {
      mem[p].hhfield.v.RH = avail;
      avail = p;
	;
#ifdef STAT
      decr (dynused);
#endif /* STAT */
    } 
  } 
  else {
      
    begintokenlist (mem[loopptr].hhfield.lhfield , 16);
    goto lab10;
  } 
  begintokenlist (mem[loopptr].hhfield.lhfield , 17);
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
  p = mem[loopptr + 1].hhfield.lhfield;
  if (p > 1) 
  free_node (p , 4);
  else if (p < 1) 
  {
    q = mem[loopptr + 1].hhfield.v.RH;
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
	decr (dynused);
#endif /* STAT */
      } 
    } 
  } 
  p = loopptr;
  loopptr = mem[p].hhfield.v.RH;
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
  if (str_ptr + 3 > maxstr_ptr) 
  {
    if (str_ptr + 3 > maxstrings) 
    overflow (258 , maxstrings - initstr_ptr);
    maxstr_ptr = str_ptr + 3;
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
  curext = 261;
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
    curname = str_ptr;
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
  curname = make_string ();
  else curext = make_string ();
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
  namelength = k;
  else namelength = maxint;
  name_of_file[namelength + 1] = 0;
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
      c = xord[ucharcast (MFbasedefault[j])];
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
      c = xord[ucharcast (MFbasedefault[j])];
      if (!(c == 34)) 
      {
	incr (k);
	if (k <= maxint) 
	name_of_file[k] = xchr[c];
      } 
    } 
  while (j++ < for_end);} 
  if (k <= maxint) 
  namelength = k;
  else namelength = maxint;
  name_of_file[namelength + 1] = 0;
} 
str_number 
makenamestring (void) 
{
  register str_number Result; integer k;
  if ((pool_ptr + namelength > pool_size) || (str_ptr == maxstrings)) 
  Result = 63;
  else {
      
    {register integer for_end; k = 1;for_end = namelength; if (k <= 
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
  while ((k <= namelength) && (more_name (name_of_file[k]))) incr (k 
);
  stopatspace = true;
  end_name ();
  return Result;
} 
str_number 
zamakenamestring (alphafile f) 
{
  register str_number Result; Result = makenamestring ();
  return Result;
} 
str_number 
zbmakenamestring (bytefile f) 
{
  register str_number Result; Result = makenamestring ();
  return Result;
} 
str_number 
zwmakenamestring (wordfile f) 
{
  register str_number Result; Result = makenamestring ();
  return Result;
} 
void 
scan_file_name (void) 
{
  /* 30 */ begin_name ();
  while ((buffer[curinput.locfield] == 32) || (buffer[curinput 
 .locfield] == 9)) incr (curinput.locfield);
  while (true) {
      
    if ((buffer[curinput.locfield] == 59) || (buffer[curinput 
   .locfield] == 37)) 
    goto done;
    if (!more_name (buffer[curinput.locfield])) 
    goto done;
    incr (curinput.locfield);
  } 
  done: end_name ();
} 
void 
zpackjobname (str_number s) 
{
  cur_area = 261;
  curext = s;
  curname = jobname;
  packfilename (curname , cur_area , curext);
} 
void 
zpromptfilename (str_number s , str_number e) 
{
  /* 30 */ integer k;
  str_number savedcurname;
  if (interaction == 2) 
;
  if (s == 743) 
  {
    if (interaction == 3) 
;
    if ((filelineerrorstylep && !(curinput .namefield == 0))) 
    {
      print_nl (261);
      print (fullsourcefilenamestack[inopen]);
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
    if ((filelineerrorstylep && !(curinput .namefield == 0))) 
    {
      print_nl (261);
      print (fullsourcefilenamestack[inopen]);
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
  print_file_name (curname , cur_area , curext);
  print (746);
  if (e == 747) 
  showcontext ();
  print_nl (748);
  print (s);
  if (interaction < 2) 
  fatal_error (749);
  savedcurname = curname;
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
  if (curext == 261) 
  curext = e;
  if ((str_start[curname + 1] - str_start[curname]) == 0) 
  curname = savedcurname;
  packfilename (curname , cur_area , curext);
} 
void 
open_log_file (void) 
{
  unsigned char oldsetting;
  integer k;
  integer l;
  integer m;
  constcstring months;
  oldsetting = selector;
  if (jobname == 0) 
  jobname = getjobname (750);
  packjobname (751);
  recorderchangefilename (stringcast (name_of_file + 1));
  packjobname (752);
  while (!aopenout (logfile)) {
      
    selector = 1;
    promptfilename (754 , 752);
  } 
  texmflogname = amakenamestring (logfile);
  selector = 2;
  logopened = true;
  {
    Fputs (logfile ,  "This is METAFONT, Version 2.7182818");
    Fputs (logfile ,  versionstring);
    slow_print (baseident);
    print (755);
    print_int (roundunscaled (internal[16]));
    print_char (32);
    months = " JANFEBMARAPRMAYJUNJULAUGSEPOCTNOVDEC";
    m = roundunscaled (internal[15]);
    {register integer for_end; k = 3 * m - 2;for_end = 3 * m; if (k <= 
    for_end) do 
      putc (months[k],  logfile);
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
      putc ('\n',  logfile);
      putc ('(' ,  logfile);
      fputs (translatefilename , logfile);
      putc (')' ,  logfile);
    } 
  } 
  inputstack[inputptr] = curinput;
  print_nl (753);
  l = inputstack[0].limitfield - 1;
  {register integer for_end; k = 1;for_end = l; if (k <= for_end) do 
    print (buffer[k]);
  while (k++ < for_end);} 
  print_ln ();
  selector = oldsetting + 2;
} 
void 
start_input (void) 
{
  /* 30 */ while ((curinput.indexfield > 15) && (curinput.locfield == 
  0)) endtokenlist ();
  if ((curinput.indexfield > 15)) 
  {
    {
      if (interaction == 3) 
  ;
      if ((filelineerrorstylep && !(curinput .namefield == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[inopen]);
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
  if ((curinput.indexfield <= 15)) 
  scan_file_name ();
  else {
      
    curname = 261;
    curext = 261;
    cur_area = 261;
  } 
  packfilename (curname , cur_area , curext);
  while (true) {
      
    beginfilereading ();
    if (curext == 747) 
    {
      curext = 261;
      packfilename (curname , cur_area , curext);
    } 
    if (kpseinnameok (stringcast (name_of_file + 1)) && aopenin (inputfile 
  [curinput.indexfield], kpsemfformat)) 
    goto done;
    endfilereading ();
    promptfilename (743 , 747);
  } 
  done: curinput .namefield = amakenamestring (inputfile[curinput 
 .indexfield]);
  strref[curname] = 127;
  if (jobname == 0) 
  {
    jobname = getjobname (curname);
    open_log_file ();
  } 
  if (term_offset + (str_start[curinput .namefield + 1] - str_start[
  curinput .namefield]) > maxprintline - 2) 
  print_ln ();
  else if ((term_offset > 0) || (file_offset > 0)) 
  print_char (32);
  print_char (40);
  incr (openparens);
  slow_print (curinput .namefield);
  fflush (stdout);
  {
    line = 1;
    if (inputln (inputfile[curinput.indexfield], false)) 
;
    firmuptheline ();
    buffer[curinput .limitfield] = 37;
    first = curinput .limitfield + 1;
    curinput.locfield = curinput .startfield;
  } 
} 
void 
zbadexp (str_number s) 
{
  unsigned char saveflag;
  {
    if (interaction == 3) 
;
    if ((filelineerrorstylep && !(curinput .namefield == 0))) 
    {
      print_nl (261);
      print (fullsourcefilenamestack[inopen]);
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
  print_cmd_mod (curcmd , curmod);
  print_char (39);
  {
    help_ptr = 4;
    help_line[3] = 771;
    help_line[2] = 772;
    help_line[1] = 773;
    help_line[0] = 774;
  } 
  backinput ();
  cursym = 0;
  curcmd = 42;
  curmod = 0;
  inserror ();
  saveflag = varflag;
  varflag = 0;
  getxnext ();
  varflag = saveflag;
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
      if (q == depfinal) 
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
    if ((filelineerrorstylep && !(curinput .namefield == 0))) 
    {
      print_nl (261);
      print (fullsourcefilenamestack[inopen]);
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
      if ((filelineerrorstylep && !(curinput .namefield == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[inopen]);
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
  if (curcmd == 60) 
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
      if (curcmd != 82) 
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
  if (curcmd != 65) 
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
    if (aritherror) 
    clear_arith ();
  } 
  if (internal[7] > 131072L) 
  showcmdmod (33 , c);
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
      initedges (cur_exp);
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
      if (jobname == 0) 
      open_log_file ();
      cur_type = 4;
      cur_exp = jobname;
    } 
    break;
  case 35 : 
    {
      if (interaction <= 1) 
      fatal_error (835);
      beginfilereading ();
      curinput .namefield = 1;
      {
	;
	print (261);
	term_input ();
      } 
      {
	if (pool_ptr + last - curinput .startfield > max_pool_ptr) 
	{
	  if (pool_ptr + last - curinput .startfield > pool_size) 
	  overflow (257 , pool_size - init_pool_ptr);
	  max_pool_ptr = pool_ptr + last - curinput .startfield;
	} 
      } 
      {register integer for_end; k = curinput .startfield;for_end = last - 
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
    if (aritherror) 
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
	if ((filelineerrorstylep && !(curinput .namefield == 0))) 
	{
	  print_nl (261);
	  print (fullsourcefilenamestack[inopen]);
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
      q = p + bignodesize[cur_type];
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
    if (aritherror) 
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
      negateedges (cur_exp);
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
	cur_exp = roundfraction (nsin);
	else cur_exp = roundfraction (ncos);
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
	if (charexists[cur_exp]) 
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
	
      oldsetting = selector;
      selector = 5;
      print_scaled (cur_exp);
      cur_exp = make_string ();
      selector = oldsetting;
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
	
      curpen = 3;
      curpathtype = 1;
      cur_exp = makespec (cur_exp , -1879080960L , 0);
      flush_cur_exp (turningnumber * 65536L);
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
    else flush_cur_exp (totalweight (cur_exp));
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
    if (aritherror) 
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
  r = q + bignodesize[mem[p].hhfield.b0];
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
  if (fixneeded) 
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
	    
	  if (maxcoef (r) + maxcoef (v) < 626349397L) 
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
	
      if (ab_vs_cd (maxcoef (q) , abs (v) , 626349396L , 65536L) >= 0) 
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
      
    if (ab_vs_cd (maxcoef (q) , 65536L , 626349396L , abs (v)) >= 0) 
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
	mem[q + 5].cint = roundfraction (ncos);
	mem[q + 9].cint = roundfraction (nsin);
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
  curedges = cur_exp;
  if (mem[curedges].hhfield.v.RH == curedges) 
  goto lab10;
  if (txx == 0) {
      
    if (tyy == 0) {
	
      if (txy % 65536L == 0) {
	  
	if (tyx % 65536L == 0) 
	{
	  xyswapedges ();
	  txx = txy;
	  tyy = tyx;
	  txy = 0;
	  tyx = 0;
	  if (mem[curedges].hhfield.v.RH == curedges) 
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
	    toss_edges (curedges);
	    cur_exp = get_node (6);
	    initedges (cur_exp);
	  } 
	  else {
	      
	    if (txx < 0) 
	    {
	      xreflectedges ();
	      txx = - (integer) txx;
	    } 
	    if (tyy < 0) 
	    {
	      yreflectedges ();
	      tyy = - (integer) tyy;
	    } 
	    if (txx != 65536L) 
	    xscaleedges (txx / 65536L);
	    if (tyy != 65536L) 
	    yscaleedges (tyy / 65536L);
	    tx = roundunscaled (tx);
	    ty = roundunscaled (ty);
	    if ((mem[curedges + 2].hhfield.lhfield + tx <= 0) || (mem 
	  [curedges + 2].hhfield.v.RH + tx >= 8192) || (mem[curedges 
	    + 1].hhfield.lhfield + ty <= 0) || (mem[curedges + 1]
	    .hhfield.v.RH + ty >= 8191) || (abs (tx) >= 4096) || (abs (
	    ty) >= 4096)) 
	    {
	      {
		if (interaction == 3) 
		;
		if ((filelineerrorstylep && !(curinput .namefield == 0)) 
		) 
		{
		  print_nl (261);
		  print (fullsourcefilenamestack[inopen]);
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
		if (!(abs (mem[curedges + 3].hhfield.lhfield - tx - 
		4096) < 4096)) 
		fixoffset ();
		mem[curedges + 2].hhfield.lhfield = mem[curedges + 2]
		.hhfield.lhfield + tx;
		mem[curedges + 2].hhfield.v.RH = mem[curedges + 2]
		.hhfield.v.RH + tx;
		mem[curedges + 3].hhfield.lhfield = mem[curedges + 3]
		.hhfield.lhfield - tx;
		mem[curedges + 4].cint = 0;
	      } 
	      if (ty != 0) 
	      {
		mem[curedges + 1].hhfield.lhfield = mem[curedges + 1]
		.hhfield.lhfield + ty;
		mem[curedges + 1].hhfield.v.RH = mem[curedges + 1]
		.hhfield.v.RH + ty;
		mem[curedges + 5].hhfield.lhfield = mem[curedges + 5]
		.hhfield.lhfield + ty;
		mem[curedges + 4].cint = 0;
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
    if ((filelineerrorstylep && !(curinput .namefield == 0))) 
    {
      print_nl (261);
      print (fullsourcefilenamestack[inopen]);
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
  if (fixneeded) 
  fix_dependencies ();
} 
void 
zaddmultdep (halfword p , scaled v , halfword r) 
{
  if (mem[r].hhfield.b0 == 16) 
  mem[depfinal + 1].cint = mem[depfinal + 1].cint + takescaled (mem[
  r + 1].cint , v);
  else {
      
    mem[p + 1].hhfield.v.RH = p_plus_fq (mem[p + 1].hhfield.v.RH , v 
    , mem[r + 1].hhfield.v.RH , 18 , mem[r].hhfield.b0);
    if (fixneeded) 
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
  if (mem[p + 1].hhfield.v.RH == depfinal) 
  {
    vv = mem[depfinal + 1].cint;
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
  s = bignodesize[mem[p].hhfield.b0];
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
    if (strref[b]< 127) {
	
      if (strref[b] > 1) 
      decr (strref[b]);
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
    if (strref[s]< 127) {
	
      if (strref[s] > 1) 
      decr (strref[s]);
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
    if (aritherror) 
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
	negateedges (cur_exp);
	curedges = cur_exp;
	mergeedges (mem[p + 1].cint);
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
	rr = r + bignodesize[cur_type] - 2;
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
	pairvalue (curt , curtt);
      } 
      else badbinary (p , 92);
    } 
    break;
  } 
  recycle_value (p);
  free_node (p , 2);
  lab10: {
      
    if (aritherror) 
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
    gfprevptr = 0;
    fatal_error (1053);
  } 
  if (gf_limit == gf_buf_size) 
  {
    write_gf (0 , halfbuf - 1);
    gf_limit = halfbuf;
    gf_offset = gf_offset + gf_buf_size;
    gf_ptr = 0;
  } 
  else {
      
    write_gf (halfbuf , gf_buf_size - 1);
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
  /* 10 */ if (minm < gfminm) 
  gfminm = minm;
  if (maxn > gfmaxn) 
  gfmaxn = maxn;
  if (bocp == -1) {
      
    if (bocc >= 0) {
	
      if (bocc < 256) {
	  
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
			  gf_buf[gf_ptr] = bocc;
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
  gffour (bocc);
  gffour (bocp);
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
  gfminm = 4096;
  gfmaxm = -4096;
  gfminn = 4096;
  gfmaxn = -4096;
  {register integer for_end; k = 0;for_end = 255; if (k <= for_end) do 
    charptr[k] = -1;
  while (k++ < for_end);} 
  if (internal[27]<= 0) 
  gfext = 1055;
  else {
      
    oldsetting = selector;
    selector = 5;
    print_char (46);
    print_int (makescaled (internal[27], 59429463L));
    print (1056);
    gfext = make_string ();
    selector = oldsetting;
  } 
  {
    if (jobname == 0) 
    open_log_file ();
    packjobname (gfext);
    while (!bopenout (gffile)) promptfilename (756 , gfext);
    outputfilename = bmakenamestring (gffile);
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
  oldsetting = selector;
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
  selector = oldsetting;
  {
    gf_buf[gf_ptr] = (pool_ptr - str_start[str_ptr]);
    incr (gf_ptr);
    if (gf_ptr == gf_limit) 
    gf_swap ();
  } 
  gfstring (0 , make_string ());
  decr (str_ptr);
  pool_ptr = str_start[str_ptr];
  gfprevptr = gf_offset + gf_ptr;
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
  if (outputfilename == 0) 
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
  bocc = 256 * f + c;
  bocp = charptr[c];
  charptr[c] = gfprevptr;
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
  p = mem[curedges].hhfield.lhfield;
  n = mem[curedges + 1].hhfield.v.RH - 4096;
  while (p != curedges) {
      
    if (mem[p + 1].hhfield.lhfield > 1) 
    sortedges (p);
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
		gfboc (mem[curedges + 2].hhfield.lhfield + xoff - 4096 , 
		mem[curedges + 2].hhfield.v.RH + xoff - 4096 , mem[
		curedges + 1].hhfield.lhfield + yoff - 4096 , n + yoff);
		curminm = mem[curedges + 2].hhfield.lhfield - 4096 + mem 
		[curedges + 3].hhfield.lhfield;
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
    if (prevm - mem[curedges + 3].hhfield.lhfield + xoff > gfmaxm) 
    gfmaxm = prevm - mem[curedges + 3].hhfield.lhfield + xoff;
    p = mem[p].hhfield.lhfield;
    decr (n);
  } 
  if (prevn == 4096) 
  {
    gfboc (0 , 0 , 0 , 0);
    if (gfmaxm < 0) 
    gfmaxm = 0;
    if (gfminn > 0) 
    gfminn = 0;
  } 
  else if (prevn + yoff < gfminn) 
  gfminn = prevn + yoff;
  {
    gf_buf[gf_ptr] = 69;
    incr (gf_ptr);
    if (gf_ptr == gf_limit) 
    gf_swap ();
  } 
  gfprevptr = gf_offset + gf_ptr;
  incr (totalchars);
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
    q = depfinal;
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
  watchcoefs = false;
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
  watchcoefs = true;
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
	if ((filelineerrorstylep && !(curinput .namefield == 0))) 
	{
	  print_nl (261);
	  print (fullsourcefilenamestack[inopen]);
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
	if ((filelineerrorstylep && !(curinput .namefield == 0))) 
	{
	  print_nl (261);
	  print (fullsourcefilenamestack[inopen]);
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
	    if ((filelineerrorstylep && !(curinput .namefield == 0))) 
	    {
	      print_nl (261);
	      print (fullsourcefilenamestack[inopen]);
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
	if ((filelineerrorstylep && !(curinput .namefield == 0))) 
	{
	  print_nl (261);
	  print (fullsourcefilenamestack[inopen]);
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
	if ((filelineerrorstylep && !(curinput .namefield == 0))) 
	{
	  print_nl (261);
	  print (fullsourcefilenamestack[inopen]);
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
      p = v + bignodesize[t];
      q = mem[cur_exp + 1].cint + bignodesize[t];
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
      
    if (aritherror) 
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
  varflag = 77;
  scan_expression ();
  if (curcmd == 51) 
  doequation ();
  else if (curcmd == 77) 
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
    varflag = 77;
    scan_expression ();
    if (curcmd == 51) 
    doequation ();
    else if (curcmd == 77) 
    doassignment ();
    if (internal[7] > 131072L) 
    {
      begin_diagnostic ();
      print_nl (123);
      if (mem[lhs].hhfield.lhfield > 9769) 
      slow_print (intname[mem[lhs].hhfield.lhfield - (9769)]);
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
	slow_print (intname[mem[lhs].hhfield.lhfield - (9769)]);
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
  if (curmod >= 13) 
  t = curmod;
  else t = curmod + 1;
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
	if ((filelineerrorstylep && !(curinput .namefield == 0))) 
	{
	  print_nl (261);
	  print (fullsourcefilenamestack[inopen]);
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
    if (curcmd < 82) 
    {
      {
	if (interaction == 3) 
	;
	if ((filelineerrorstylep && !(curinput .namefield == 0))) 
	{
	  print_nl (261);
	  print (fullsourcefilenamestack[inopen]);
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
      if (curcmd == 42) 
      help_line[2] = 909;
      put_get_error ();
      scannerstatus = 2;
      do {
	  getnext ();
	if (curcmd == 39) 
	{
	  if (strref[curmod]< 127) {
	      
	    if (strref[curmod] > 1) 
	    decr (strref[curmod]);
	    else flush_string (curmod);
	  } 
	} 
      } while (!(curcmd >= 82));
      scannerstatus = 0;
    } 
  } while (!(curcmd > 82));
} 
void 
dorandomseed (void) 
{
  getxnext ();
  if (curcmd != 77) 
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
      oldsetting = selector;
      selector = 2;
      print_nl (918);
      print_scaled (cur_exp);
      print_char (125);
      print_nl (261);
      selector = oldsetting;
    } 
  } 
} 
void 
doprotection (void) 
{
  unsigned char m;
  halfword t;
  m = curmod;
  do {
      getsymbol ();
    t = eqtb[cursym].lhfield;
    if (m == 0) 
    {
      if (t >= 86) 
      eqtb[cursym].lhfield = t - 86;
    } 
    else if (t < 86) 
    eqtb[cursym].lhfield = t + 86;
    getxnext ();
  } while (!(curcmd != 82));
} 
void 
defdelims (void) 
{
  halfword ldelim, rdelim;
  getclearsymbol ();
  ldelim = cursym;
  getclearsymbol ();
  rdelim = cursym;
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
  if (curcmd != 40) 
  {
    {
      if (interaction == 3) 
  ;
      if ((filelineerrorstylep && !(curinput .namefield == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[inopen]);
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
    if (cursym == 0) 
    print (929);
    else slow_print (hash[cursym].v.RH);
    print (930);
    {
      help_ptr = 1;
      help_line[0] = 931;
    } 
    backerror ();
  } 
  else {
      
    saveinternal (curmod);
    backinput ();
  } 
  dostatement ();
} 
void 
dolet (void) 
{
  halfword l;
  getsymbol ();
  l = cursym;
  getxnext ();
  if (curcmd != 51) {
      
    if (curcmd != 77) 
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
  switch (curcmd) 
  {case 10 : 
  case 53 : 
  case 44 : 
  case 49 : 
    incr (mem[curmod].hhfield.lhfield);
    break;
    default: 
;
    break;
  } 
  clearsymbol (l , false);
  eqtb[l].lhfield = curcmd;
  if (curcmd == 41) 
  eqtb[l].v.RH = 0;
  else eqtb[l].v.RH = curmod;
  getxnext ();
} 
void 
donewinternal (void) 
{
  do {
      if (intptr == maxinternal) 
    overflow (934 , maxinternal);
    getclearsymbol ();
    incr (intptr);
    eqtb[cursym].lhfield = 40;
    eqtb[cursym].v.RH = intptr;
    intname[intptr] = hash[cursym].v.RH;
    internal[intptr] = 0;
    getxnext ();
  } while (!(curcmd != 82));
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
  } while (!(curcmd != 82));
} 
void 
disptoken (void) 
{
  print_nl (940);
  if (cursym == 0) 
  {
    if (curcmd == 42) 
    print_scaled (curmod);
    else if (curcmd == 38) 
    {
      gpointer = curmod;
      printcapsule ();
    } 
    else {
	
      print_char (34);
      slow_print (curmod);
      print_char (34);
      {
	if (strref[curmod]< 127) {
	    
	  if (strref[curmod] > 1) 
	  decr (strref[curmod]);
	  else flush_string (curmod);
	} 
      } 
    } 
  } 
  else {
      
    slow_print (hash[cursym].v.RH);
    print_char (61);
    if (eqtb[cursym].lhfield >= 86) 
    print (941);
    print_cmd_mod (curcmd , curmod);
    if (curcmd == 10) 
    {
      print_ln ();
      show_macro (curmod , 0 , 100000L);
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
  } while (!(curcmd != 82));
} 
void 
doshowstats (void) 
{
  print_nl (950);
	;
#ifdef STAT
  print_int (varused);
  print_char (38);
  print_int (dynused);
  if (false) 
#endif /* STAT */
  print (357);
  print (558);
  print_int (himemmin - lomemmax - 1);
  print (951);
  print_ln ();
  print_nl (952);
  print_int (str_ptr - initstr_ptr);
  print_char (38);
  print_int (pool_ptr - init_pool_ptr);
  print (558);
  print_int (maxstrings - maxstr_ptr);
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
    if (cursym > 0) {
	
      if (cursym <= 9769) {
	  
	if (curcmd == 41) {
	    
	  if (curmod != 0) 
	  {
	    dispvar (curmod);
	    goto done;
	  } 
	} 
      } 
    } 
    disptoken ();
    done: getxnext ();
  } while (!(curcmd != 82));
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
  switch (curmod) 
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
      if ((filelineerrorstylep && !(curinput .namefield == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[inopen]);
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
      decr (errorcount);
    } 
    else {
	
      help_ptr = 1;
      help_line[0] = 955;
    } 
    if (curcmd == 83) 
    error ();
    else put_get_error ();
  } 
} 
boolean 
scanwith (void) 
{
  register boolean Result; small_number t;
  boolean result;
  t = curmod;
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
	if ((filelineerrorstylep && !(curinput .namefield == 0))) 
	{
	  print_nl (261);
	  print (fullsourcefilenamestack[inopen]);
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
  curedges = 0;
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
      if ((filelineerrorstylep && !(curinput .namefield == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[inopen]);
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
  else curedges = mem[p + 1].cint;
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
  varflag = 68;
  scanprimary ();
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
    addtotype = curmod;
    cur_type = 1;
    getxnext ();
    scan_expression ();
    if (addtotype == 2) 
    {
      findedgesvar (lhs);
      if (curedges == 0) 
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
	  
	mergeedges (cur_exp);
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
	curpen = 3;
	while (curcmd == 66) if (scanwith ()) {
	    
	  if (cur_type == 16) 
	  w = cur_exp;
	  else {
	      
	    if (mem[curpen].hhfield.lhfield == 0) 
	    toss_pen (curpen);
	    else decr (mem[curpen].hhfield.lhfield);
	    curpen = cur_exp;
	  } 
	} 
	findedgesvar (lhs);
	if (curedges == 0) 
	toss_knot_list (rhs);
	else {
	    
	  lhs = 0;
	  curpathtype = addtotype;
	  if (mem[rhs].hhfield.b0 == 0) {
	      
	    if (curpathtype == 0) {
		
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
		mem[pathtail + 5].cint = mem[q + 5].cint;
		mem[pathtail + 6].cint = mem[q + 6].cint;
		mem[pathtail].hhfield.b1 = mem[q].hhfield.b1;
		mem[pathtail].hhfield.v.RH = mem[q].hhfield.v.RH;
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
		if ((filelineerrorstylep && !(curinput .namefield == 0)) 
		) 
		{
		  print_nl (261);
		  print (fullsourcefilenamestack[inopen]);
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
	  else if (curpathtype == 0) 
	  lhs = htapypoc (rhs);
	  curwt = w;
	  rhs = makespec (rhs , mem[curpen + 9].cint , internal[5]);
	  if (turningnumber <= 0) {
	      
	    if (curpathtype != 0) {
		
	      if (internal[39] > 0) {
		  
		if ((turningnumber < 0) && (mem[curpen].hhfield.v.RH 
		== 0)) 
		curwt = - (integer) curwt;
		else {
		    
		  if (turningnumber == 0) {
		      
		    if ((internal[39]<= 65536L) && (mem[curpen]
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
	  if (mem[curpen + 9].cint == 0) 
	  fillspec (rhs);
	  else fillenvelope (rhs);
	  if (lhs != 0) 
	  {
	    revturns = true;
	    lhs = makespec (lhs , mem[curpen + 9].cint , internal[5]) 
	;
	    revturns = false;
	    if (mem[curpen + 9].cint == 0) 
	    fillspec (lhs);
	    else fillenvelope (lhs);
	  } 
	  not_found:;
	} 
	if (mem[curpen].hhfield.lhfield == 0) 
	toss_pen (curpen);
	else decr (mem[curpen].hhfield.lhfield);
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
      if ((filelineerrorstylep && !(curinput .namefield == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[inopen]);
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
    print (intname[m]);
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
  varflag = 83;
  scan_expression ();
  if (cur_type != 20) {
      
    if (cur_type == 11) 
    curedges = cur_exp;
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
  if (curedges != 0) 
  {
    c = roundunscaled (internal[18]) % 256;
    if (c < 0) 
    c = c + 256;
    if (c < bc) 
    bc = c;
    if (c > ec) 
    ec = c;
    charexists[c] = true;
    gfdx[c] = internal[24];
    gfdy[c] = internal[25];
    tfmwidth[c] = tfmcheck (20);
    tfmheight[c] = tfmcheck (21);
    tfmdepth[c] = tfmcheck (22);
    tfmitalcorr[c] = tfmcheck (23);
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
  varflag = 73;
  scanprimary ();
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
    if (!windowopen[cur_exp]) 
    goto not_found;
    findedgesvar (e);
    if (curedges != 0) 
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
  if (curcmd != c) 
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
doopenwindow (void) 
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
    if ((filelineerrorstylep && !(curinput .namefield == 0))) 
    {
      print_nl (261);
      print (fullsourcefilenamestack[inopen]);
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
  varflag = 67;
  scanprimary ();
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
    keeping = curmod;
    if (!getpair (67)) 
    goto not_found;
    while ((curcmd == 66) && (curmod == 16)) if (scanwith ()) 
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
    if (curedges != 0) 
    culledges (floorunscaled (cur_x + 65535L) , floorunscaled (cur_y) , 
    wout , win);
    goto lab10;
    not_found: {
	
      if (interaction == 3) 
  ;
      if ((filelineerrorstylep && !(curinput .namefield == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[inopen]);
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
  m = curmod;
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
	if ((filelineerrorstylep && !(curinput .namefield == 0))) 
	{
	  print_nl (261);
	  print (fullsourcefilenamestack[inopen]);
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
      if (errhelp != 0) 
      useerrhelp = true;
      else if (longhelpseen) 
      {
	help_ptr = 1;
	help_line[0] = 996;
      } 
      else {
	  
	if (interaction < 3) 
	longhelpseen = true;
	{
	  help_ptr = 4;
	  help_line[3] = 997;
	  help_line[2] = 998;
	  help_line[1] = 999;
	  help_line[0] = 1000;
	} 
      } 
      put_get_error ();
      useerrhelp = false;
    } 
    break;
  case 2 : 
    {
      if (errhelp != 0) 
      {
	if (strref[errhelp]< 127) {
	    
	  if (strref[errhelp] > 1) 
	  decr (strref[errhelp]);
	  else flush_string (errhelp);
	} 
      } 
      if ((str_start[cur_exp + 1] - str_start[cur_exp]) == 0) 
      errhelp = 0;
      else {
	  
	errhelp = cur_exp;
	{
	  if (strref[errhelp]< 127) 
	  incr (strref[errhelp]);
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
  if (chartag[c] == 0) 
  {
    chartag[c] = t;
    charremainder[c] = r;
    if (t == 1) 
    {
      incr (labelptr);
      labelloc[labelptr] = r;
      labelchar[labelptr] = c;
    } 
  } 
  else {
      
    {
      if (interaction == 3) 
  ;
      if ((filelineerrorstylep && !(curinput .namefield == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[inopen]);
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
    switch (chartag[c]) 
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
  switch (curmod) 
  {case 0 : 
    {
      c = getcode ();
      while (curcmd == 81) {
	  
	cc = getcode ();
	settag (c , 2 , cc);
	c = cc;
      } 
    } 
    break;
  case 1 : 
    {
      lkstarted = false;
      lab22: getxnext ();
      if ((curcmd == 78) && lkstarted) 
      {
	c = getcode ();
	if (nl - skiptable[c] > 128) 
	{
	  {
	    {
	      if (interaction == 3) 
	  ;
	      if ((filelineerrorstylep && !(curinput .namefield == 0))) 
	      {
		print_nl (261);
		print (fullsourcefilenamestack[inopen]);
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
	    ll = skiptable[c];
	    do {
		lll = ligkern[ll].b0;
	      ligkern[ll].b0 = 128;
	      ll = ll - lll;
	    } while (!(lll == 0));
	  } 
	  skiptable[c] = ligtablesize;
	} 
	if (skiptable[c] == ligtablesize) 
	ligkern[nl - 1].b0 = 0;
	else ligkern[nl - 1].b0 = nl - skiptable[c] - 1;
	skiptable[c] = nl - 1;
	goto done;
      } 
      if (curcmd == 79) 
      {
	c = 256;
	curcmd = 81;
      } 
      else {
	  
	backinput ();
	c = getcode ();
      } 
      if ((curcmd == 81) || (curcmd == 80)) 
      {
	if (curcmd == 81) {
	    
	  if (c == 256) 
	  bchlabel = nl;
	  else settag (c , 1 , nl);
	} 
	else if (skiptable[c]< ligtablesize) 
	{
	  ll = skiptable[c];
	  skiptable[c] = ligtablesize;
	  do {
	      lll = ligkern[ll].b0;
	    if (nl - ll > 128) 
	    {
	      {
		{
		  if (interaction == 3) 
		;
		  if ((filelineerrorstylep && !(curinput .namefield == 0) 
		)) 
		  {
		    print_nl (261);
		    print (fullsourcefilenamestack[inopen]);
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
		    lll = ligkern[ll].b0;
		  ligkern[ll].b0 = 128;
		  ll = ll - lll;
		} while (!(lll == 0));
	      } 
	      goto lab22;
	    } 
	    ligkern[ll].b0 = nl - ll - 1;
	    ll = ll - lll;
	  } while (!(lll == 0));
	} 
	goto lab22;
      } 
      if (curcmd == 76) 
      {
	ligkern[nl].b1 = c;
	ligkern[nl].b0 = 0;
	if (curmod < 128) 
	{
	  ligkern[nl].b2 = curmod;
	  ligkern[nl].b3 = getcode ();
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
	    if (nk == maxkerns) 
	    overflow (1034 , maxkerns);
	    incr (nk);
	  } 
	  ligkern[nl].b2 = 128 + (k / 256);
	  ligkern[nl].b3 = (k % 256);
	} 
	lkstarted = true;
      } 
      else {
	  
	{
	  if (interaction == 3) 
	;
	  if ((filelineerrorstylep && !(curinput .namefield == 0))) 
	  {
	    print_nl (261);
	    print (fullsourcefilenamestack[inopen]);
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
	ligkern[nl].b1 = 0;
	ligkern[nl].b2 = 0;
	ligkern[nl].b3 = 0;
	ligkern[nl].b0 = 129;
      } 
      if (nl == ligtablesize) 
      overflow (1025 , ligtablesize);
      incr (nl);
      if (curcmd == 82) 
      goto lab22;
      if (ligkern[nl - 1].b0 < 128) 
      ligkern[nl - 1].b0 = 128;
      done:;
    } 
    break;
  case 2 : 
    {
      if (ne == 256) 
      overflow (1006 , 256);
      c = getcode ();
      settag (c , 3 , ne);
      if (curcmd != 81) 
      {
	missing_err (58);
	{
	  help_ptr = 1;
	  help_line[0] = 1039;
	} 
	backerror ();
      } 
      exten[ne].b0 = getcode ();
      if (curcmd != 82) 
      {
	missing_err (44);
	{
	  help_ptr = 1;
	  help_line[0] = 1039;
	} 
	backerror ();
      } 
      exten[ne].b1 = getcode ();
      if (curcmd != 82) 
      {
	missing_err (44);
	{
	  help_ptr = 1;
	  help_line[0] = 1039;
	} 
	backerror ();
      } 
      exten[ne].b2 = getcode ();
      if (curcmd != 82) 
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
      c = curmod;
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
	if (curcmd != 81) 
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
	    if (j > headersize) 
	  overflow (1007 , headersize);
	  headerbyte[j] = getcode ();
	  incr (j);
	} while (!(curcmd != 82));
	else do {
	    if (j > maxfontdimen) 
	  overflow (1008 , maxfontdimen);
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
	} while (!(curcmd != 82));
      } 
    } 
    break;
  } 
} 
void 
dospecial (void) 
{
  small_number m;
  m = curmod;
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
	
      if (outputfilename == 0) 
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
  if (curcmd > 43) 
  {
    if (curcmd < 83) 
    {
      {
	if (interaction == 3) 
	;
	if ((filelineerrorstylep && !(curinput .namefield == 0))) 
	{
	  print_nl (261);
	  print (fullsourcefilenamestack[inopen]);
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
      print_cmd_mod (curcmd , curmod);
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
  else if (curcmd > 30) 
  {
    varflag = 77;
    scan_expression ();
    if (curcmd < 84) 
    {
      if (curcmd == 51) 
      doequation ();
      else if (curcmd == 77) 
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
	  if (outputfilename == 0) 
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
    showcmdmod (curcmd , curmod);
    switch (curcmd) 
    {case 30 : 
      dotypedeclaration ();
      break;
    case 16 : 
      if (curmod > 2) 
      makeopdef ();
      else if (curmod > 0) 
      scandef ();
      break;
    case 24 : 
      dorandomseed ();
      break;
    case 23 : 
      {
	print_ln ();
	interaction = curmod;
	if (interaction == 0) 
	kpsemaketexdiscarderrors = 1;
	else kpsemaketexdiscarderrors = 0;
	if (interaction == 0) 
	selector = 0;
	else selector = 1;
	if (logopened) 
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
	savevariable (cursym);
	getxnext ();
      } while (!(curcmd != 82));
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
      doopenwindow ();
      break;
    case 19 : 
      docull ();
      break;
    case 26 : 
      {
	getsymbol ();
	startsym = cursym;
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
  if (curcmd < 83) 
  {
    {
      if (interaction == 3) 
  ;
      if ((filelineerrorstylep && !(curinput .namefield == 0))) 
      {
	print_nl (261);
	print (fullsourcefilenamestack[inopen]);
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
    scannerstatus = 2;
    do {
	getnext ();
      if (curcmd == 39) 
      {
	if (strref[curmod]< 127) {
	    
	  if (strref[curmod] > 1) 
	  decr (strref[curmod]);
	  else flush_string (curmod);
	} 
      } 
    } while (!(curcmd > 82));
    scannerstatus = 0;
  } 
  errorcount = 0;
} 
void 
maincontrol (void) 
{
  do {
      dostatement ();
    if (curcmd == 84) 
    {
      {
	if (interaction == 3) 
	;
	if ((filelineerrorstylep && !(curinput .namefield == 0))) 
	{
	  print_nl (261);
	  print (fullsourcefilenamestack[inopen]);
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
  } while (!(curcmd == 85));
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
  print (intname[m]);
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
  if (headerbyte[5]< 0) {
      
    if (headerbyte[6]< 0) {
	
      if (headerbyte[7]< 0) {
	  
	if (headerbyte[8]< 0) 
	{
	  headerbyte[5] = d / 1048576L;
	  headerbyte[6] = (d / 4096) % 256;
	  headerbyte[7] = (d / 16) % 256;
	  headerbyte[8] = (d % 16) * 16;
	} 
      } 
    } 
  } 
  maxtfmdimen = 16 * internal[26] - 1 - internal[26]/ 2097152L;
  if (maxtfmdimen >= 134217728L) 
  maxtfmdimen = 134217727L;
} 
integer 
zdimenout (scaled x) 
{
  register integer Result; if (abs (x) > maxtfmdimen) 
  {
    incr (tfmchanged);
    if (x > 0) 
    x = maxtfmdimen;
    else x = - (integer) maxtfmdimen;
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
  if (headerbyte[1]< 0) {
      
    if (headerbyte[2]< 0) {
	
      if (headerbyte[3]< 0) {
	  
	if (headerbyte[4]< 0) 
	{
	  lb1 = bc;
	  lb2 = ec;
	  lb3 = bc;
	  b4 = ec;
	  tfmchanged = 0;
	  {register integer for_end; k = bc;for_end = ec; if (k <= 
	  for_end) do 
	    if (charexists[k]) 
	    {
	      x = dimenout (mem[tfmwidth[k]+ 1].cint) + (k + 4) * 
	      4194304L;
	      lb1 = (lb1 + lb1 + x) % 255;
	      lb2 = (lb2 + lb2 + x) % 253;
	      lb3 = (lb3 + lb3 + x) % 251;
	      b4 = (b4 + b4 + x) % 247;
	    } 
	  while (k++ < for_end);} 
	  headerbyte[1] = lb1;
	  headerbyte[2] = lb2;
	  headerbyte[3] = lb3;
	  headerbyte[4] = b4;
	  goto lab10;
	} 
      } 
    } 
  } 
  {register integer for_end; k = 1;for_end = 4; if (k <= for_end) do 
    if (headerbyte[k]< 0) 
    headerbyte[k] = 0;
  while (k++ < for_end);} 
  lab10:;
} 
void 
ztfmqqqq (fourquarters x) 
{
  putbyte (x.b0 , tfmfile);
  putbyte (x.b1 , tfmfile);
  putbyte (x .b2 , tfmfile);
  putbyte (x .b3 , tfmfile);
} 
boolean 
openbasefile (void) 
{
  /* 40 10 */ register boolean Result; integer j;
  j = curinput.locfield;
  if (buffer[curinput.locfield] == 38) 
  {
    incr (curinput.locfield);
    j = curinput.locfield;
    buffer[last] = 32;
    while (buffer[j]!= 32) incr (j);
    packbufferedname (0 , curinput.locfield , j - 1);
    if (wopenin (basefile)) 
    goto found;
    Fputs (stdout ,  "Sorry, I can't find the base `");
    fputs (stringcast (name_of_file + 1) , stdout);
    Fputs (stdout ,  "'; will try `");
    fputs (MFbasedefault + 1 , stdout);
    fprintf (stdout , "%s\n",  "'.");
    fflush (stdout);
  } 
  packbufferedname (basedefaultlength - 5 , 1 , 0);
  if (!wopenin (basefile)) 
  {
;
    Fputs (stdout ,  "I can't find the base file `");
    fputs (MFbasedefault + 1 , stdout);
    fprintf (stdout , "%s\n",  "'!");
    Result = false;
    goto lab10;
  } 
  found: curinput.locfield = j;
  Result = true;
  lab10:;
  return Result;
} 
void 
scanprimary (void) 
{
  /* 20 30 31 32 */ halfword p, q, r;
  quarterword c;
  unsigned char myvarflag;
  halfword ldelim, rdelim;
  integer groupline;
  scaled num, denom;
  halfword prehead, posthead, tail;
  small_number tt;
  halfword t;
  halfword macroref;
  myvarflag = varflag;
  varflag = 0;
  lab20: {
      
    if (aritherror) 
    clear_arith ();
  } 
	;
#ifdef TEXMF_DEBUG
  if (panicking) 
  checkmem (false);
#endif /* TEXMF_DEBUG */
  if (interrupt != 0) {
      
    if (OKtointerrupt) 
    {
      backinput ();
      {
	if (interrupt != 0) 
	pause_for_instructions ();
      } 
      getxnext ();
    } 
  } 
  switch (curcmd) 
  {case 31 : 
    {
      ldelim = cursym;
      rdelim = curmod;
      getxnext ();
      scan_expression ();
      if ((curcmd == 82) && (cur_type >= 16)) 
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
      showcmdmod (curcmd , curmod);
      {
	p = get_avail ();
	mem[p].hhfield.lhfield = 0;
	mem[p].hhfield.v.RH = saveptr;
	saveptr = p;
      } 
      do {
	  dostatement ();
      } while (!(curcmd != 83));
      if (curcmd != 84) 
      {
	{
	  if (interaction == 3) 
	;
	  if ((filelineerrorstylep && !(curinput .namefield == 0))) 
	  {
	    print_nl (261);
	    print (fullsourcefilenamestack[inopen]);
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
	curcmd = 84;
      } 
      unsave ();
      if (internal[7] > 0) 
      showcmdmod (curcmd , curmod);
    } 
    break;
  case 39 : 
    {
      cur_type = 4;
      cur_exp = curmod;
    } 
    break;
  case 42 : 
    {
      cur_exp = curmod;
      cur_type = 16;
      getxnext ();
      if (curcmd != 54) 
      {
	num = 0;
	denom = 0;
      } 
      else {
	  
	getxnext ();
	if (curcmd != 42) 
	{
	  backinput ();
	  curcmd = 54;
	  curmod = 72;
	  cursym = 9761;
	  goto done;
	} 
	num = cur_exp;
	denom = curmod;
	if (denom == 0) 
	{
	  {
	    if (interaction == 3) 
	;
	    if ((filelineerrorstylep && !(curinput .namefield == 0))) 
	    {
	      print_nl (261);
	      print (fullsourcefilenamestack[inopen]);
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
	  if (aritherror) 
	  clear_arith ();
	} 
	getxnext ();
      } 
      if (curcmd >= 30) {
	  
	if (curcmd < 42) 
	{
	  p = stash_cur_exp ();
	  scanprimary ();
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
    donullary (curmod);
    break;
  case 34 : 
  case 30 : 
  case 36 : 
  case 43 : 
    {
      c = curmod;
      getxnext ();
      scanprimary ();
      dounary (c);
      goto done;
    } 
    break;
  case 37 : 
    {
      c = curmod;
      getxnext ();
      scan_expression ();
      if (curcmd != 69) 
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
      scanprimary ();
      dobinary (p , c);
      goto done;
    } 
    break;
  case 35 : 
    {
      getxnext ();
      scansuffix ();
      oldsetting = selector;
      selector = 5;
      show_token_list (cur_exp , 0 , 100000L , 0);
      flush_token_list (cur_exp);
      cur_exp = make_string ();
      selector = oldsetting;
      cur_type = 4;
      goto done;
    } 
    break;
  case 40 : 
    {
      q = curmod;
      if (myvarflag == 77) 
      {
	getxnext ();
	if (curcmd == 77) 
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
    makeexpcopy (curmod);
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
	  incr (dynused);
#endif /* STAT */
	} 
      } 
      tail = prehead;
      posthead = 0;
      tt = 1;
      while (true) {
	  
	t = curtok ();
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
		if (p >= himemmin) 
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
	if (curcmd == 63) 
	{
	  getxnext ();
	  scan_expression ();
	  if (curcmd != 64) 
	  {
	    backinput ();
	    backexpr ();
	    curcmd = 63;
	    curmod = 0;
	    cursym = 9760;
	  } 
	  else {
	      
	    if (cur_type != 16) 
	    badsubscript ();
	    curcmd = 42;
	    curmod = cur_exp;
	    cursym = 0;
	  } 
	} 
	if (curcmd > 42) 
	goto done1;
	if (curcmd < 40) 
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
	decr (dynused);
#endif /* STAT */
      } 
      if (curcmd == myvarflag) 
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
  done: if (curcmd == 63) {
      
    if (cur_type >= 16) 
    {
      p = stash_cur_exp ();
      getxnext ();
      scan_expression ();
      if (curcmd != 82) 
      {
	{
	  backinput ();
	  backexpr ();
	  curcmd = 63;
	  curmod = 0;
	  cursym = 9760;
	} 
	unstash_cur_exp (p);
      } 
      else {
	  
	q = stash_cur_exp ();
	getxnext ();
	scan_expression ();
	if (curcmd != 64) 
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
scansuffix (void) 
{
  /* 30 */ halfword h, t;
  halfword p;
  h = get_avail ();
  t = h;
  while (true) {
      
    if (curcmd == 63) 
    {
      getxnext ();
      scan_expression ();
      if (cur_type != 16) 
      badsubscript ();
      if (curcmd != 64) 
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
      curcmd = 42;
      curmod = cur_exp;
    } 
    if (curcmd == 42) 
    p = new_num_tok (curmod);
    else if ((curcmd == 41) || (curcmd == 40)) 
    {
      p = get_avail ();
      mem[p].hhfield.lhfield = cursym;
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
    decr (dynused);
#endif /* STAT */
  } 
  cur_type = 20;
} 
void 
scansecondary (void) 
{
  /* 20 22 */ halfword p;
  halfword c, d;
  halfword macname;
  lab20: if ((curcmd < 30) || (curcmd > 43)) 
  badexp (804);
  scanprimary ();
  lab22: if (curcmd <= 55) {
      
    if (curcmd >= 52) 
    {
      p = stash_cur_exp ();
      c = curmod;
      d = curcmd;
      if (d == 53) 
      {
	macname = cursym;
	incr (mem[c].hhfield.lhfield);
      } 
      getxnext ();
      scanprimary ();
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
scantertiary (void) 
{
  /* 20 22 */ halfword p;
  halfword c, d;
  halfword macname;
  lab20: if ((curcmd < 30) || (curcmd > 43)) 
  badexp (805);
  scansecondary ();
  if (cur_type == 8) 
  materializepen ();
  lab22: if (curcmd <= 45) {
      
    if (curcmd >= 43) 
    {
      p = stash_cur_exp ();
      c = curmod;
      d = curcmd;
      if (d == 44) 
      {
	macname = cursym;
	incr (mem[c].hhfield.lhfield);
      } 
      getxnext ();
      scansecondary ();
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
  unsigned char myvarflag;
  halfword macname;
  boolean cyclehit;
  scaled x, y;
  unsigned char t;
  myvarflag = varflag;
  lab20: if ((curcmd < 30) || (curcmd > 43)) 
  badexp (808);
  scantertiary ();
  lab22: if (curcmd <= 51) {
      
    if (curcmd >= 46) {
	
      if ((curcmd != 51) || (myvarflag != 77)) 
      {
	p = stash_cur_exp ();
	c = curmod;
	d = curcmd;
	if (d == 49) 
	{
	  macname = cursym;
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
	  lab25: if (curcmd == 46) 
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
	  d = curcmd;
	  if (d == 47) 
	  {
	    getxnext ();
	    if (curcmd == 58) 
	    {
	      getxnext ();
	      y = curcmd;
	      if (curcmd == 59) 
	      getxnext ();
	      scanprimary ();
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
	      if (curcmd == 52) 
	      {
		getxnext ();
		y = curcmd;
		if (curcmd == 59) 
		getxnext ();
		scanprimary ();
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
	    else if (curcmd == 57) 
	    {
	      mem[q].hhfield.b1 = 1;
	      t = 1;
	      getxnext ();
	      scanprimary ();
	      knownpair ();
	      mem[q + 5].cint = cur_x;
	      mem[q + 6].cint = cur_y;
	      if (curcmd != 52) 
	      {
		x = mem[q + 5].cint;
		y = mem[q + 6].cint;
	      } 
	      else {
		  
		getxnext ();
		scanprimary ();
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
	    if (curcmd != 47) 
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
	  if (curcmd == 46) 
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
	  if (curcmd == 36) 
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
	      
	    scantertiary ();
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
		  if ((filelineerrorstylep && !(curinput .namefield == 0) 
		)) 
		  {
		    print_nl (261);
		    print (fullsourcefilenamestack[inopen]);
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
	  if (curcmd >= 46) {
	      
	    if (curcmd <= 48) {
		
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
	  makechoices (p);
	  cur_type = 9;
	  cur_exp = p;
	} 
	else {
	    
	  getxnext ();
	  scantertiary ();
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
getboolean (void) 
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
printcapsule (void) 
{
  print_char (40);
  print_exp (gpointer , 0);
  print_char (41);
} 
void 
tokenrecycle (void) 
{
  recycle_value (gpointer);
} 
void 
closefilesandterminate (void) 
{
  integer k;
  integer lh;
  short lkoffset;
  halfword p;
  scaled x;
	;
#ifdef STAT
  if (internal[12] > 0) {
      
    if (logopened) 
    {
      { putc (' ' ,  logfile);  putc ('\n',  logfile); }
      fprintf (logfile , "%s%s\n",  "Here is how much of METAFONT's memory" ,       " you used:");
      fprintf (logfile , "%c%ld%s",  ' ' , (long)maxstr_ptr - initstr_ptr , " string");
      if (maxstr_ptr != initstr_ptr + 1) 
      putc ('s' ,  logfile);
      fprintf (logfile , "%s%ld\n",  " out of " , (long)maxstrings - initstr_ptr);
      fprintf (logfile , "%c%ld%s%ld\n",  ' ' , (long)max_pool_ptr - init_pool_ptr ,       " string characters out of " , (long)pool_size - init_pool_ptr);
      fprintf (logfile , "%c%ld%s%ld\n",  ' ' , (long)lomemmax + 0 + memend - himemmin + 2 ,       " words of memory out of " , (long)memend + 1);
      fprintf (logfile , "%c%ld%s%ld\n",  ' ' , (long)stcount , " symbolic tokens out of " , (long)9500) 
  ;
      fprintf (logfile , "%c%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%c\n",  ' ' , (long)maxinstack , "i," , (long)intptr , "n," ,       (long)maxroundingptr , "r," , (long)maxparamstack , "p," , (long)maxbufstack + 1 ,       "b stack positions out of " , (long)stacksize , "i," , (long)maxinternal , "n," ,       (long)maxwiggle , "r," , (long)150 , "p," , (long)bufsize , 'b');
    } 
  } 
#endif /* STAT */
  if ((gfprevptr > 0) || (internal[33] > 0)) 
  {
    rover = 23;
    mem[rover].hhfield.v.RH = 268435455L;
    lomemmax = himemmin - 1;
    if (lomemmax - rover > 268435455L) 
    lomemmax = 268435455L + rover;
    mem[rover].hhfield.lhfield = lomemmax - rover;
    mem[rover + 1].hhfield.lhfield = rover;
    mem[rover + 1].hhfield.v.RH = rover;
    mem[lomemmax].hhfield.v.RH = 0;
    mem[lomemmax].hhfield.lhfield = 0;
    mem[memtop - 1].hhfield.v.RH = 19;
    {register integer for_end; k = bc;for_end = ec; if (k <= for_end) do 
      if (charexists[k]) 
      tfmwidth[k] = sortin (tfmwidth[k]);
    while (k++ < for_end);} 
    nw = skimp (255) + 1;
    dimenhead[1] = mem[memtop - 1].hhfield.v.RH;
    if (perturbation >= 4096) 
    tfmwarning (20);
    fixdesignsize ();
    fixchecksum ();
    if (internal[33] > 0) 
    {
      mem[memtop - 1].hhfield.v.RH = 19;
      {register integer for_end; k = bc;for_end = ec; if (k <= for_end) 
      do 
	if (charexists[k]) {
	    
	  if (tfmheight[k] == 0) 
	  tfmheight[k] = 15;
	  else tfmheight[k] = sortin (tfmheight[k]);
	} 
      while (k++ < for_end);} 
      nh = skimp (15) + 1;
      dimenhead[2] = mem[memtop - 1].hhfield.v.RH;
      if (perturbation >= 4096) 
      tfmwarning (21);
      mem[memtop - 1].hhfield.v.RH = 19;
      {register integer for_end; k = bc;for_end = ec; if (k <= for_end) 
      do 
	if (charexists[k]) {
	    
	  if (tfmdepth[k] == 0) 
	  tfmdepth[k] = 15;
	  else tfmdepth[k] = sortin (tfmdepth[k]);
	} 
      while (k++ < for_end);} 
      nd = skimp (15) + 1;
      dimenhead[3] = mem[memtop - 1].hhfield.v.RH;
      if (perturbation >= 4096) 
      tfmwarning (22);
      mem[memtop - 1].hhfield.v.RH = 19;
      {register integer for_end; k = bc;for_end = ec; if (k <= for_end) 
      do 
	if (charexists[k]) {
	    
	  if (tfmitalcorr[k] == 0) 
	  tfmitalcorr[k] = 15;
	  else tfmitalcorr[k] = sortin (tfmitalcorr[k]);
	} 
      while (k++ < for_end);} 
      ni = skimp (63) + 1;
      dimenhead[4] = mem[memtop - 1].hhfield.v.RH;
      if (perturbation >= 4096) 
      tfmwarning (23);
      internal[33] = 0;
      if (jobname == 0) 
      open_log_file ();
      packjobname (1045);
      while (!bopenout (tfmfile)) promptfilename (1046 , 1045);
      metricfilename = bmakenamestring (tfmfile);
      k = headersize;
      while (headerbyte[k]< 0) decr (k);
      lh = (k + 3) / 4;
      if (bc > ec) 
      bc = 1;
      bchar = roundunscaled (internal[41]);
      if ((bchar < 0) || (bchar > 255)) 
      {
	bchar = -1;
	lkstarted = false;
	lkoffset = 0;
      } 
      else {
	  
	lkstarted = true;
	lkoffset = 1;
      } 
      k = labelptr;
      if (labelloc[k]+ lkoffset > 255) 
      {
	lkoffset = 0;
	lkstarted = false;
	do {
	    charremainder[labelchar[k]] = lkoffset;
	  while (labelloc[k - 1] == labelloc[k]) {
	      
	    decr (k);
	    charremainder[labelchar[k]] = lkoffset;
	  } 
	  incr (lkoffset);
	  decr (k);
	} while (!(lkoffset + labelloc[k]< 256));
      } 
      if (lkoffset > 0) 
      while (k > 0) {
	  
	charremainder[labelchar[k]] = charremainder[labelchar[k]]
	+ lkoffset;
	decr (k);
      } 
      if (bchlabel < ligtablesize) 
      {
	ligkern[nl].b0 = 255;
	ligkern[nl].b1 = 0;
	ligkern[nl].b2 = ((bchlabel + lkoffset) / 256);
	ligkern[nl].b3 = ((bchlabel + lkoffset) % 256);
	incr (nl);
      } 
      put2bytes (tfmfile , 6 + lh + (ec - bc + 1) + nw + nh + nd + ni + nl 
      + lkoffset + nk + ne + np);
      put2bytes (tfmfile , lh);
      put2bytes (tfmfile , bc);
      put2bytes (tfmfile , ec);
      put2bytes (tfmfile , nw);
      put2bytes (tfmfile , nh);
      put2bytes (tfmfile , nd);
      put2bytes (tfmfile , ni);
      put2bytes (tfmfile , nl + lkoffset);
      put2bytes (tfmfile , nk);
      put2bytes (tfmfile , ne);
      put2bytes (tfmfile , np);
      {register integer for_end; k = 1;for_end = 4 * lh; if (k <= 
      for_end) do 
	{
	  if (headerbyte[k]< 0) 
	  headerbyte[k] = 0;
	  putbyte (headerbyte[k], tfmfile);
	} 
      while (k++ < for_end);} 
      {register integer for_end; k = bc;for_end = ec; if (k <= for_end) 
      do 
	if (!charexists[k]) 
	put4bytes (tfmfile , 0);
	else {
	    
	  putbyte (mem[tfmwidth[k]].hhfield.lhfield , tfmfile);
	  putbyte ((mem[tfmheight[k]].hhfield.lhfield) * 16 + mem[
	  tfmdepth[k]].hhfield.lhfield , tfmfile);
	  putbyte ((mem[tfmitalcorr[k]].hhfield.lhfield) * 4 + 
	  chartag[k], tfmfile);
	  putbyte (charremainder[k], tfmfile);
	} 
      while (k++ < for_end);} 
      tfmchanged = 0;
      {register integer for_end; k = 1;for_end = 4; if (k <= for_end) do 
	{
	  put4bytes (tfmfile , 0);
	  p = dimenhead[k];
	  while (p != 19) {
	      
	    put4bytes (tfmfile , dimenout (mem[p + 1].cint));
	    p = mem[p].hhfield.v.RH;
	  } 
	} 
      while (k++ < for_end);} 
      {register integer for_end; k = 0;for_end = 255; if (k <= for_end) 
      do 
	if (skiptable[k]< ligtablesize) 
	{
	  print_nl (1048);
	  print_int (k);
	  print (1049);
	  ll = skiptable[k];
	  do {
	      lll = ligkern[ll].b0;
	    ligkern[ll].b0 = 128;
	    ll = ll - lll;
	  } while (!(lll == 0));
	} 
      while (k++ < for_end);} 
      if (lkstarted) 
      {
	putbyte (255 , tfmfile);
	putbyte (bchar , tfmfile);
	put2bytes (tfmfile , 0);
      } 
      else {
	  register integer for_end; k = 1;for_end = lkoffset; if (k <= 
      for_end) do 
	{
	  ll = labelloc[labelptr];
	  if (bchar < 0) 
	  {
	    putbyte (254 , tfmfile);
	    putbyte (0 , tfmfile);
	  } 
	  else {
	      
	    putbyte (255 , tfmfile);
	    putbyte (bchar , tfmfile);
	  } 
	  put2bytes (tfmfile , ll + lkoffset);
	  do {
	      decr (labelptr);
	  } while (!(labelloc[labelptr]< ll));
	} 
      while (k++ < for_end);} 
      {register integer for_end; k = 0;for_end = nl - 1; if (k <= 
      for_end) do 
	tfmqqqq (ligkern[k]);
      while (k++ < for_end);} 
      {register integer for_end; k = 0;for_end = nk - 1; if (k <= 
      for_end) do 
	put4bytes (tfmfile , dimenout (kern[k]));
      while (k++ < for_end);} 
      {register integer for_end; k = 0;for_end = ne - 1; if (k <= 
      for_end) do 
	tfmqqqq (exten[k]);
      while (k++ < for_end);} 
      {register integer for_end; k = 1;for_end = np; if (k <= for_end) do 
	if (k == 1) {
	    
	  if (abs (param[1]) < 134217728L) 
	  put4bytes (tfmfile , param[1]* 16);
	  else {
	      
	    incr (tfmchanged);
	    if (param[1] > 0) 
	    put4bytes (tfmfile , 2147483647L);
	    else put4bytes (tfmfile , -2147483647L);
	  } 
	} 
	else put4bytes (tfmfile , dimenout (param[k]));
      while (k++ < for_end);} 
      if (tfmchanged > 0) 
      {
	if (tfmchanged == 1) 
	print_nl (1050);
	else {
	    
	  print_nl (40);
	  print_int (tfmchanged);
	  print (1051);
	} 
	print (1052);
      } 
	;
#ifdef STAT
      if (internal[12] > 0) 
      {
	{ putc (' ' ,  logfile);  putc ('\n',  logfile); }
	if (bchlabel < ligtablesize) 
	decr (nl);
	fprintf (logfile , "%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s\n",  "(You used " , (long)nw , "w," , (long)nh , "h," , (long)nd , "d," ,         (long)ni , "i," , (long)nl , "l," , (long)nk , "k," , (long)ne , "e," , (long)np ,         "p metric file positions");
	fprintf (logfile , "%s%s%ld%s%ld%s%ld%s\n",  "  out of " , "256w,16h,16d,64i," , (long)ligtablesize ,         "l," , (long)maxkerns , "k,256e," , (long)maxfontdimen , "p)");
      } 
#endif /* STAT */
      print_nl (1047);
      print_file_name (0 , metricfilename , 0);
      print_char (46);
      bclose (tfmfile);
    } 
    if (gfprevptr > 0) 
    {
      {
	gf_buf[gf_ptr] = 248;
	incr (gf_ptr);
	if (gf_ptr == gf_limit) 
	gf_swap ();
      } 
      gffour (gfprevptr);
      gfprevptr = gf_offset + gf_ptr - 5;
      gffour (internal[26]* 16);
      {register integer for_end; k = 1;for_end = 4; if (k <= for_end) do 
	{
	  gf_buf[gf_ptr] = headerbyte[k];
	  incr (gf_ptr);
	  if (gf_ptr == gf_limit) 
	  gf_swap ();
	} 
      while (k++ < for_end);} 
      gffour (internal[27]);
      gffour (internal[28]);
      gffour (gfminm);
      gffour (gfmaxm);
      gffour (gfminn);
      gffour (gfmaxn);
      {register integer for_end; k = 0;for_end = 255; if (k <= for_end) 
      do 
	if (charexists[k]) 
	{
	  x = gfdx[k]/ 65536L;
	  if ((gfdy[k] == 0) && (x >= 0) && (x < 256) && (gfdx[k 
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
	    gffour (gfdx[k]);
	    gffour (gfdy[k]);
	  } 
	  x = mem[tfmwidth[k]+ 1].cint;
	  if (abs (x) > maxtfmdimen) {
	      
	    if (x > 0) 
	    x = 16777215L;
	    else x = -16777215L;
	  } 
	  else x = makescaled (x * 16 , internal[26]);
	  gffour (x);
	  gffour (charptr[k]);
	} 
      while (k++ < for_end);} 
      {
	gf_buf[gf_ptr] = 249;
	incr (gf_ptr);
	if (gf_ptr == gf_limit) 
	gf_swap ();
      } 
      gffour (gfprevptr);
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
      if (gf_limit == halfbuf) 
      write_gf (halfbuf , gf_buf_size - 1);
      if (gf_ptr > (2147483647L - gf_offset)) 
      {
	gfprevptr = 0;
	fatal_error (1053);
      } 
      if (gf_ptr > 0) 
      write_gf (0 , gf_ptr - 1);
      print_nl (1064);
      print_file_name (0 , outputfilename , 0);
      print (558);
      print_int (totalchars);
      if (totalchars != 1) 
      print (1065);
      else print (1066);
      print (1067);
      print_int (gf_offset + gf_ptr);
      print (1068);
      bclose (gffile);
    } 
  } 
  if (logopened) 
  {
    putc ('\n',  logfile);
    aclose (logfile);
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
  calledit (str_pool , editnamestart , editnamelength , editline);
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
