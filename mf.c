#include "mf.h"

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
  g = loadpoolstrings((pool_size - string_vacancies));
  if (g == 0)
  {
    ;
    fprintf(stdout, "%s\n", "! You have to increase pool_size.");
    Result = false;
    goto lab_exit;
  }
  Result = true;
lab_exit:;
  return Result;
}
/* 173 */
void sort_avail (void)
{
  halfword p, q, r;
  halfword old_rover;

  p = get_node(1073741824);
  p = mem[rover + 1].hh.rh;
  mem[rover + 1].hh.rh = 268435455;
  old_rover = rover;
  while (p != old_rover)
    if (p < rover)
    {
      q = p;
      p = mem[q + 1].hh.rh;
      mem[q + 1].hh.rh = rover;
      rover = q;
    }
    else
    {
      q = rover;
      while (mem[q + 1].hh.rh < p)
        q = mem[q + 1].hh.rh;
      r = mem[p + 1].hh.rh;
      mem[p + 1].hh.rh = mem[q + 1].hh.rh;
      mem[q + 1].hh.rh = p;
      p = r;
    }
  p = rover;
  while (mem[p + 1].hh.rh != 268435455L)
  {
    mem[mem[p + 1].hh.rh + 1].hh.lh = p;
    p = mem[p + 1].hh.rh;
  }
  mem[p + 1].hh.rh = rover;
  mem[rover + 1].hh.lh = p;
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
    hash[cur_sym].v.RH = s;
  }
  eqtb[cur_sym].lh = c;
  eqtb[cur_sym].v.RH = o;
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
  print_char(32);
  print_int(round_unscaled(internal[14]));
  print_char(46);
  print_int(round_unscaled(internal[15]));
  print_char(46);
  print_int(round_unscaled(internal[16]));
  print_char(41);
  if (interaction == 0)
    selector = 2;
  else
    selector = 3;
  {
    if (pool_ptr + 1 > max_pool_ptr)
    {
      if (pool_ptr + 1 > pool_size)
        overflow(257, pool_size - init_pool_ptr);
      max_pool_ptr = pool_ptr + 1;
    }
  }
  base_ident = make_string();
  str_ref[base_ident] = 127;
  pack_job_name(742);
  while (!w_open_out(base_file))
    prompt_file_name(1074, 742);
  print_nl(1075);
  slow_print(w_make_name_string(base_file));
  flush_string(str_ptr - 1);
  print_nl(261);
  slow_print(base_ident);
  dump_int(1462914374L);
  x = strlen(enginename);
  baseengine = xmallocarray(ASCII_code, x + 4);
  strcpy(stringcast(baseengine), enginename);
  {
    integer for_end; k = x; for_end = x + 3; if (k <= for_end) do
    baseengine[k] = 0;
    while (k++ < for_end);
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
  {
    integer for_end; k = 0; for_end = str_ptr; if (k <= for_end) do
    dump_int(str_start[k]);
    while (k++ < for_end);
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
    {
      integer for_end; k = p; for_end = q + 1; if (k <= for_end) do
      dumpwd(mem[k]);
      while (k++ < for_end);
    }
    x = x + q + 2 - p;
    var_used = var_used + q - p;
    p = q + mem[q].hh.lh;
    q = mem[q + 1].hh.rh;
  } while (!(q == rover));
  var_used = var_used + lo_mem_max - p;
  dyn_used = mem_end + 1 - hi_mem_min;
  {
    integer for_end; k = p; for_end = lo_mem_max; if (k <= for_end)
    do
      dumpwd(mem[k]);
    while (k++ < for_end);
  }
  x = x + lo_mem_max + 1 - p;
  dump_int(hi_mem_min);
  dump_int(avail);
  {
    integer for_end; k = hi_mem_min; for_end = mem_end; if (k <= for_end) do
    dumpwd(mem[k]);
    while (k++ < for_end);
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
  print_char(38);
  print_int(dyn_used);
  dump_int(hash_used);
  st_count = 9756 - hash_used;
  {
    integer for_end; p = 1; for_end = hash_used; if (p <= for_end)
    do
      if (hash[p].v.RH != 0)
      {
        dump_int(p);
        dumphh(hash[p]);
        dumphh(eqtb[p]);
        incr(st_count);
      }
    while (p++ < for_end);
  }
  {
    integer for_end; p = hash_used + 1; for_end = 9769; if (p <= for_end) do
    {
      dumphh(hash[p]);
      dumphh(eqtb[p]);
    } while (p++ < for_end);
  }
  dump_int(st_count);
  print_ln();
  print_int(st_count);
  print(1072);
  dump_int(int_ptr);
  {
    integer for_end; k = 1; for_end = int_ptr; if (k <= for_end) do
    {
      dump_int(internal[k]);
      dump_int(int_name[k]);
    } while (k++ < for_end);
  }
  dump_int(start_sym);
  dump_int(interaction);
  dump_int(base_ident);
  dump_int(bg_loc);
  dump_int(eg_loc);
  dump_int(serial_no);
  dump_int(69069L);
  internal[12] = 0;
  wclose(base_file);
}
/* 1187 */
boolean load_base_file (void)
{
  boolean Result; integer k;
  halfword p, q;
  integer x;
  four_quarters w;
  ASCII_code * baseengine;
  ASCII_code dummyxord;
  ASCII_code dummyxchr;
  ASCII_code dummyxprn;

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
    ;
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
  {integer for_end; k = 0; for_end = str_ptr; if (k <= for_end) do
  {
    {
      undump_int(x);
      if ((x < 0) || (x > pool_ptr))
        goto lab6666;
      else str_start[k] = x;
    }
    str_ref[k] = 127;
  } while (k++ < for_end);}
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
    { integer for_end; k = p; for_end = q + 1; if (k <=
      for_end) do
      undumpwd(mem[k]);
      while (k++ < for_end);
    }
    p = q + mem[q].hh.lh;
    if ((p > lo_mem_max) || ((q >= mem[q + 1].hh.rh) && (mem[q + 1].hh.rh != rover)))
      goto lab6666;
    q = mem[q + 1].hh.rh;
  } while (!(q == rover));
  {
    integer for_end; k = p; for_end = lo_mem_max; if (k <= for_end)
    do
      undumpwd(mem[k]);
    while (k++ < for_end);
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
  {
    integer for_end; k = hi_mem_min; for_end = mem_end; if (k <= for_end) do
    undumpwd(mem[k]);
    while (k++ < for_end);
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
  {
    integer for_end; p = hash_used + 1; for_end = 9769; if (p <= for_end) do
    {
      undumphh(hash[p]);
      undumphh(eqtb[p]);
    } while (p++ < for_end);
  }
  undump_int(st_count);
  {
    undump_int(x);
    if ((x < 41) || (x > max_internal))
      goto lab6666;
    else
      int_ptr = x;
  }
  {
    integer for_end; k = 1; for_end = int_ptr; if (k <= for_end) do
    {
      undump_int(internal[k]);
      {
        undump_int(x);
        if ((x < 0) || (x > str_ptr))
          goto lab6666;
        else
          int_name[k] = x;
      }
    } while (k++ < for_end);
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
  if (interactionoption != 4)
    interaction = interactionoption;
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
/* 1209 */
void final_cleanup (void)
{
  small_number c;

  c = cur_mod;
  if (job_name == 0)
    open_log_file();
  while (input_ptr > 0)
    if ((cur_input.index_field > 15))
      end_token_list();
    else
      end_file_reading();
  while (loop_ptr != 0)
    stop_iteration();
  while (open_parens > 0)
  {
    print(1077);
    decr(open_parens);
  }
  while (cond_ptr != 0)
  {
    print_nl(1078);
    print_cmd_mod(2, cur_if);
    if (if_line != 0)
    {
      print(1079);
      print_int(if_line);
    }
    print(1080);
    if_line = mem[cond_ptr + 1].cint;
    cur_if = mem[cond_ptr].hh.b1;
    loop_ptr = cond_ptr;
    cond_ptr = mem[cond_ptr].hh.rh;
    freenode(loop_ptr, 2);
  }
  if (history != 0)
  {
    if (((history == 1) || (interaction < 3)))
    {
      if (selector == 3)
      {
        selector = 1;
        print_nl(1081);
        selector = 3;
      }
    }
  }
  if (c == 1)
  {
    ;
#ifdef INIMF
    if (iniversion)
    {
      store_base_file();
      goto lab_exit;
    }
#endif /* INIMF */
    print_nl(1082);
    goto lab_exit;
  }
lab_exit:;
}
/* 1210 */
void init_prim (void)
{
  primitive(409, 40, 1);
  primitive(410, 40, 2);
  primitive(411, 40, 3);
  primitive(412, 40, 4);
  primitive(413, 40, 5);
  primitive(414, 40, 6);
  primitive(415, 40, 7);
  primitive(416, 40, 8);
  primitive(417, 40, 9);
  primitive(418, 40, 10);
  primitive(419, 40, 11);
  primitive(420, 40, 12);
  primitive(421, 40, 13);
  primitive(422, 40, 14);
  primitive(423, 40, 15);
  primitive(424, 40, 16);
  primitive(425, 40, 17);
  primitive(426, 40, 18);
  primitive(427, 40, 19);
  primitive(428, 40, 20);
  primitive(429, 40, 21);
  primitive(430, 40, 22);
  primitive(431, 40, 23);
  primitive(432, 40, 24);
  primitive(433, 40, 25);
  primitive(434, 40, 26);
  primitive(435, 40, 27);
  primitive(436, 40, 28);
  primitive(437, 40, 29);
  primitive(438, 40, 30);
  primitive(439, 40, 31);
  primitive(440, 40, 32);
  primitive(441, 40, 33);
  primitive(442, 40, 34);
  primitive(443, 40, 35);
  primitive(444, 40, 36);
  primitive(445, 40, 37);
  primitive(446, 40, 38);
  primitive(447, 40, 39);
  primitive(448, 40, 40);
  primitive(449, 40, 41);
  primitive(408, 47, 0);
  primitive(91, 63, 0);
  eqtb[9760] = eqtb[cur_sym];
  primitive(93, 64, 0);
  primitive(125, 65, 0);
  primitive(123, 46, 0);
  primitive(58, 81, 0);
  eqtb[9762] = eqtb[cur_sym];
  primitive(459, 80, 0);
  primitive(460, 79, 0);
  primitive(461, 77, 0);
  primitive(44, 82, 0);
  primitive(59, 83, 0);
  eqtb[9763] = eqtb[cur_sym];
  primitive(92, 7, 0);
  primitive(462, 18, 0);
  primitive(463, 72, 0);
  primitive(464, 59, 0);
  primitive(465, 32, 0);
  bg_loc = cur_sym;
  primitive(466, 57, 0);
  primitive(467, 19, 0);
  primitive(468, 60, 0);
  primitive(469, 27, 0);
  primitive(470, 11, 0);
  primitive(453, 84, 0);
  eqtb[9767] = eqtb[cur_sym];
  eg_loc = cur_sym;
  primitive(471, 26, 0);
  primitive(472, 6, 0);
  primitive(473, 9, 0);
  primitive(474, 70, 0);
  primitive(475, 73, 0);
  primitive(476, 13, 0);
  primitive(477, 14, 0);
  primitive(478, 15, 0);
  primitive(479, 69, 0);
  primitive(480, 28, 0);
  primitive(481, 24, 0);
  primitive(482, 12, 0);
  primitive(483, 8, 0);
  primitive(484, 17, 0);
  primitive(485, 78, 0);
  primitive(486, 74, 0);
  primitive(487, 35, 0);
  primitive(488, 58, 0);
  primitive(489, 71, 0);
  primitive(490, 75, 0);
  primitive(655, 16, 1);
  primitive(656, 16, 2);
  primitive(657, 16, 53);
  primitive(658, 16, 44);
  primitive(659, 16, 49);
  primitive(454, 16, 0);
  eqtb[9765] = eqtb[cur_sym];
  primitive(660, 4, 9770);
  primitive(661, 4, 9920);
  primitive(662, 4, 1);
  primitive(455, 4, 0);
  eqtb[9764] = eqtb[cur_sym];
  primitive(663, 61, 0);
  primitive(664, 61, 1);
  primitive(64, 61, 2);
  primitive(665, 61, 3);
  primitive(676, 56, 9770);
  primitive(677, 56, 9920);
  primitive(678, 56, 10070);
  primitive(679, 56, 1);
  primitive(680, 56, 2);
  primitive(681, 56, 3);
  primitive(691, 3, 0);
  primitive(617, 3, 1);
  primitive(718, 1, 1);
  primitive(452, 2, 2);
  eqtb[9766] = eqtb[cur_sym];
  primitive(719, 2, 3);
  primitive(720, 2, 4);
  primitive(347, 33, 30);
  primitive(348, 33, 31);
  primitive(349, 33, 32);
  primitive(350, 33, 33);
  primitive(351, 33, 34);
  primitive(352, 33, 35);
  primitive(353, 33, 36);
  primitive(354, 33, 37);
  primitive(355, 34, 38);
  primitive(356, 34, 39);
  primitive(357, 34, 40);
  primitive(358, 34, 41);
  primitive(359, 34, 42);
  primitive(360, 34, 43);
  primitive(361, 34, 44);
  primitive(362, 34, 45);
  primitive(363, 34, 46);
  primitive(364, 34, 47);
  primitive(365, 34, 48);
  primitive(366, 34, 49);
  primitive(367, 34, 50);
  primitive(368, 34, 51);
  primitive(369, 34, 52);
  primitive(370, 34, 53);
  primitive(371, 34, 54);
  primitive(372, 34, 55);
  primitive(373, 34, 56);
  primitive(374, 34, 57);
  primitive(375, 34, 58);
  primitive(376, 34, 59);
  primitive(377, 34, 60);
  primitive(378, 34, 61);
  primitive(379, 34, 62);
  primitive(380, 34, 63);
  primitive(381, 34, 64);
  primitive(382, 34, 65);
  primitive(383, 34, 66);
  primitive(384, 34, 67);
  primitive(385, 36, 68);
  primitive(43, 43, 69);
  primitive(45, 43, 70);
  primitive(42, 55, 71);
  primitive(47, 54, 72);
  eqtb[9761] = eqtb[cur_sym];
  primitive(386, 45, 73);
  primitive(310, 45, 74);
  primitive(388, 52, 76);
  primitive(387, 45, 75);
  primitive(60, 50, 77);
  primitive(389, 50, 78);
  primitive(62, 50, 79);
  primitive(390, 50, 80);
  primitive(61, 51, 81);
  primitive(391, 50, 82);
  primitive(401, 37, 94);
  primitive(402, 37, 95);
  primitive(403, 37, 96);
  primitive(404, 37, 97);
  primitive(405, 37, 98);
  primitive(406, 37, 99);
  primitive(407, 37, 100);
  primitive(38, 48, 83);
  primitive(392, 55, 84);
  primitive(393, 55, 85);
  primitive(394, 55, 86);
  primitive(395, 55, 87);
  primitive(396, 55, 88);
  primitive(397, 55, 89);
  primitive(398, 55, 90);
  primitive(399, 55, 91);
  primitive(400, 45, 92);
  primitive(340, 30, 15);
  primitive(326, 30, 4);
  primitive(324, 30, 2);
  primitive(331, 30, 9);
  primitive(328, 30, 6);
  primitive(333, 30, 11);
  primitive(335, 30, 13);
  primitive(336, 30, 14);
  primitive(912, 85, 0);
  primitive(913, 85, 1);
  primitive(273, 23, 0);
  primitive(274, 23, 1);
  primitive(275, 23, 2);
  primitive(919, 23, 3);
  primitive(920, 21, 0);
  primitive(921, 21, 1);
  primitive(935, 22, 0);
  primitive(936, 22, 1);
  primitive(937, 22, 2);
  primitive(938, 22, 3);
  primitive(939, 22, 4);
  primitive(956, 68, 1);
  primitive(957, 68, 0);
  primitive(958, 68, 2);
  primitive(959, 66, 6);
  primitive(960, 66, 16);
  primitive(961, 67, 0);
  primitive(962, 67, 1);
  primitive(992, 25, 0);
  primitive(993, 25, 1);
  primitive(994, 25, 2);
  primitive(1004, 20, 0);
  primitive(1005, 20, 1);
  primitive(1006, 20, 2);
  primitive(1007, 20, 3);
  primitive(1008, 20, 4);
  primitive(1026, 76, 0);
  primitive(1027, 76, 1);
  primitive(1028, 76, 5);
  primitive(1029, 76, 2);
  primitive(1030, 76, 6);
  primitive(1031, 76, 3);
  primitive(1032, 76, 7);
  primitive(1033, 76, 11);
  primitive(1034, 76, 128);
  primitive(1059, 29, 4);
  primitive(1060, 29, 16);
}
/* 1210 */
void init_tab (void)
{
  integer k;

  rover = 23;
  mem[rover].hh.rh = 268435455;
  mem[rover].hh.lh = 1000;
  mem[rover + 1].hh.lh = rover;
  mem[rover + 1].hh.rh = rover;
  lo_mem_max = rover + 1000;
  mem[lo_mem_max].hh.rh = 0;
  mem[lo_mem_max].hh.lh = 0;
  {
    integer for_end; k = mem_top - 2; for_end = mem_top; if (k <= for_end) do
    mem[k] = mem[lo_mem_max];
    while (k++ < for_end);
  }
  avail = 0;
  mem_end = mem_top;
  hi_mem_min = mem_top - 2;
  var_used = 23;
  dyn_used = mem_top + 1 - hi_mem_min;
  int_name[1] = 409;
  int_name[2] = 410;
  int_name[3] = 411;
  int_name[4] = 412;
  int_name[5] = 413;
  int_name[6] = 414;
  int_name[7] = 415;
  int_name[8] = 416;
  int_name[9] = 417;
  int_name[10] = 418;
  int_name[11] = 419;
  int_name[12] = 420;
  int_name[13] = 421;
  int_name[14] = 422;
  int_name[15] = 423;
  int_name[16] = 424;
  int_name[17] = 425;
  int_name[18] = 426;
  int_name[19] = 427;
  int_name[20] = 428;
  int_name[21] = 429;
  int_name[22] = 430;
  int_name[23] = 431;
  int_name[24] = 432;
  int_name[25] = 433;
  int_name[26] = 434;
  int_name[27] = 435;
  int_name[28] = 436;
  int_name[29] = 437;
  int_name[30] = 438;
  int_name[31] = 439;
  int_name[32] = 440;
  int_name[33] = 441;
  int_name[34] = 442;
  int_name[35] = 443;
  int_name[36] = 444;
  int_name[37] = 445;
  int_name[38] = 446;
  int_name[39] = 447;
  int_name[40] = 448;
  int_name[41] = 449;
  hash_used = 9757;
  st_count = 0;
  hash[9768].v.RH = 451;
  hash[9766].v.RH = 452;
  hash[9767].v.RH = 453;
  hash[9765].v.RH = 454;
  hash[9764].v.RH = 455;
  hash[9763].v.RH = 59;
  hash[9762].v.RH = 58;
  hash[9761].v.RH = 47;
  hash[9760].v.RH = 91;
  hash[9759].v.RH = 41;
  hash[9757].v.RH = 456;
  eqtb[9759].lh = 62;
  mem[19].hh.lh = 9770;
  mem[19].hh.rh = 0;
  mem[mem_top].hh.lh = 268435455;
  mem[3].hh.lh = 0;
  mem[3].hh.rh = 0;
  mem[4].hh.lh = 1;
  mem[4].hh.rh = 0;
  {
    integer for_end; k = 5; for_end = 11;
    if (k <= for_end) do
      mem[k] = mem[4];
    while (k++ < for_end);
  }
  mem[12].cint = 0;
  mem[0].hh.rh = 0;
  mem[0].hh.lh = 0;
  mem[1].cint = 0;
  mem[2].cint = 0;
  serial_no = 0;
  mem[13].hh.rh = 13;
  mem[14].hh.lh = 13;
  mem[13].hh.lh = 0;
  mem[14].hh.rh = 0;
  mem[21].hh.b1 = 0;
  mem[21].hh.rh = 9768;
  eqtb[9768].v.RH = 21;
  eqtb[9768].lh = 41;
  eqtb[9758].lh = 91;
  hash[9758].v.RH = 735;
  mem[17].hh.b1 = 11;
  mem[20].cint = 1073741824;
  mem[16].cint = 0;
  mem[15].hh.lh = 0;
  if (iniversion)
    base_ident = 1069;
}
/* main */
void mainbody (void)
{
  history = 3;
  if (ready_already == 314159)
    goto lab_start_of_MF;
  bad = 0;
  if ((half_error_line < 30) || (half_error_line > error_line - 15))
    bad = 1;
  if (max_print_line < 60)
    bad = 2;
  if (gf_buf_size % 8 != 0)
    bad = 3;
  if (1100 > mem_top)
    bad = 4;
  if (7919 > 9500)
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
  if ((0 > 0) || (255 < 127))
    bad = 11;
  if ((0 > 0) || (268435455L < 32767))
    bad = 12;
  if ((0 < 0) || (255 > 268435455L))
    bad = 13;
  if ((0 < 0) || (mem_max >= 268435455L))
    bad = 14;
  if (max_strings > 268435455L)
    bad = 15;
  if (buf_size > 268435455L)
    bad = 16;
  if ((255 < 255) || (268435455L < 65535L))
    bad = 17;
  if (9769 + max_internal > 268435455L)
    bad = 21;
  if (10220 > 268435455L)
    bad = 22;
  if (15 * 11 > bistack_size)
    bad = 31;
  if (20 + 17 * 45 > bistack_size)
    bad = 32;
  if (base_default_length > maxint)
    bad = 41;
  if (bad > 0)
  {
    fprintf(stdout, "%s%s%ld\n", "Ouch---my internal constants have been clobbered!", "---case ", (long)bad);
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
  selector = 1;
  tally = 0;
  term_offset = 0;
  file_offset = 0;
  Fputs(stdout, "This is METAFONT, Version 2.7182818");
  if (base_ident == 0)
    fprintf(stdout, "%s%s%c\n", " (preloaded base=", dumpname, ')');
  else
  {
    slow_print(base_ident);
    print_ln();
  }
  fflush(stdout);
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
      cur_input.start_field = 1;
      cur_input.index_field = 0;
      line = 0;
      cur_input.name_field = 0;
      force_eof = false;
      if (!initterminal())
        goto lab_final_end;
      cur_input.limit_field = last;
      first = last + 1;
    }
    scanner_status = 0;
    if ((base_ident == 0) || (buffer[cur_input.loc_field] == 38))
    {
      if (base_ident != 0)
        initialize();
      if (!open_base_file())
        goto lab_final_end;
      if (!load_base_file())
      {
        wclose(base_file);
        goto lab_final_end;
      }
      wclose(base_file);
      while ((cur_input.loc_field < cur_input.limit_field) && (buffer[cur_input.loc_field] == 32))
        incr(cur_input.loc_field);
    }
    buffer[cur_input.limit_field] = 37;
    fix_date_and_time();
    ini_trandoms((internal[17] / 65536) + internal[16]);
    if (interaction == 0)
      selector = 0;
    else
      selector = 1;
    if (cur_input.loc_field < cur_input.limit_field)
    {
      if (buffer[cur_input.loc_field] != 92)
        start_input();
    }
  }
  history = 0;
  if (start_sym > 0)
  {
    cur_sym = start_sym;
    back_input();
  }
  main_control();
  final_cleanup();
  close_files_and_terminate();
lab_final_end:
  {
    fflush(stdout);
    ready_already = 0;
    if ((history != 0) && (history != 1))
      uexit(1);
    else
      uexit(0);
  }
}
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
  {integer for_end; i = 0;for_end = 31; if (i <= for_end) do
    xchr[i] = i;
    while (i++ < for_end);
  }
  {integer for_end; i = 127;for_end = 255; if (i <= for_end) do
    xchr[i] = i;
    while (i++ < for_end);
  }
  {integer for_end; i = 0;for_end = 255; if (i <= for_end) do
    xord[chr (i)] = 127;
    while (i++ < for_end);
  }
  {integer for_end; i = 128;for_end = 255; if (i <= for_end) do
    xord[xchr[i]] = i;
    while (i++ < for_end);
  }
  {integer for_end; i = 0;for_end = 126; if (i <= for_end) do
    xord[xchr[i]] = i;
    while (i++ < for_end);
  }
  interaction = 3;
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
  ;
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
  hash[1].lh = 0;
  hash[1].v.RH = 0;
  eqtb[1].lh = 41;
  eqtb[1].v.RH = 0;
  {
    integer for_end; k = 2;for_end = 9769; if (k <= for_end) do
    {
      hash[k] = hash[1];
      eqtb[k] = eqtb[1];
    }
    while (k++ < for_end);
  }
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
  {
    integer for_end; k = 1;for_end = 8; if (k <= for_end) do
    octant_number[octant_code[k]] = k;
    while (k++ < for_end);
  }
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
  {
    integer for_end; k = 1;for_end = 8; if (k <= for_end) do
    z_corr[k] = xy_corr[k] - x_corr[k];
    while (k++ < for_end);
  }
  screen_started = false;
  screen_OK = false;
  {
    integer for_end; k = 0;for_end = 15; if (k <= for_end) do
    {
      window_open[k] = false;
      window_time[k] = 0;
    }
    while (k++ < for_end);
  }
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
  {
    integer for_end; k = 0;for_end = 255; if (k <= for_end) do
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
    while (k++ < for_end);
  }
  {
    integer for_end; k = 1;for_end = header_size; if (k <= for_end) do
    header_byte[k] = -1;
    while (k++ < for_end);
  }
  bc = 255;
  ec = 0;
  nl = 0;
  nk = 0;
  ne = 0;
  np = 0;
  internal[41] = -65536;
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
/* 57 */
void print_ln (void)
{
  switch (selector)
  {
    case term_and_log:
      {
        putc ('\n', stdout);
        putc ('\n', log_file);
        term_offset = 0;
        file_offset = 0;
      }
      break;
    case log_only:
      {
        putc ('\n', log_file);
        file_offset = 0;
      }
      break;
    case term_only:
      {
        putc ('\n', stdout);
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
        putc (xchr[s], stdout);
        putc (xchr[s], log_file);
        incr (term_offset);
        incr (file_offset);
        if (term_offset == max_print_line)
        {
          putc ('\n', stdout);
          term_offset = 0;
        }
        if (file_offset == max_print_line)
        {
          putc ('\n', log_file);
          file_offset = 0;
        }
      }
      break;
    case log_only:
      {
        putc (xchr[s], log_file);
        incr (file_offset);
        if (file_offset == max_print_line)
          print_ln ();
      }
      break;
    case term_only:
      {
        putc (xchr[s], stdout);
        incr (term_offset);
        if (term_offset == max_print_line)
          print_ln ();
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
  incr (tally);
}
/* 59 */
void print (integer s)
{
  pool_pointer j;

  if ((s < 0) || (s >= str_ptr))
    s = 259;
  if ((s < 256) && (selector > pseud))
    print_char(s);
  else
  {
    j = str_start[s];
    while (j < str_start[s + 1])
    {
      print_char(so(str_pool[j]));
      incr (j);
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
      incr (j);
    }
  }
}
/* 62 */
void print_nl (str_number s)
{
  if (((term_offset > 0) && (odd (selector))) || ((file_offset > 0) && (selector >= log_only)))
    print_ln ();
  print(s);
}
/* 63 */
void print_the_digs (eight_bits k)
{
  while (k > 0)
  {
    decr (k);
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
/* 103 */
void print_scaled (scaled s)
{
  scaled delta;

  if (s < 0)
  {
    print_char('-');
    negate(s);
  }
  print_int (s / unity);
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
  if ((internal[13] <= 0) && (selector == term_and_log))
  {
    decr (selector);
    if (history == spotless)
      history = warning_issued;
  }
}
/* 195 */
void end_diagnostic (boolean blank_line)
{
  print_nl(261);
  if (blank_line)
    print_ln ();
  selector = old_setting;
}
/* 197 */
void print_diagnostic (str_number s, str_number t, boolean nuline)
{
  begin_diagnostic ();
  if (nuline)
    print_nl(s);
  else
    print(s);
  print(450);
  print_int (line);
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
/* 43 */
void flush_string (str_number s)
{
  if (s < str_ptr - 1)
    str_ref[s] = 0;
  else
    do {
      decr (str_ptr);
    } while (!(str_ref[str_ptr - 1] != 0));
  pool_ptr = str_start[str_ptr];
}
/* 76 */
void jump_out (void)
{
  close_files_and_terminate ();
}
/* 77 */
void error (void)
{
  ASCII_code c;
  integer s1, s2, s3;
  pool_pointer j;

  if (history < 2)
    history = 2;
  print_char(46);
  show_context ();
  if ((haltonerrorp))
  {
    history = 3;
    jump_out ();
  }
  if (interaction == 3)
    while (true)
    {
    lab_continue:
      clear_for_error_prompt ();
      {
        do_nothing();
        print(265);
        term_input ();
      }
      if (last == first)
        goto lab_exit;
      c = buffer[first];
      if (c >= 97)
        c = c - 32;
      switch (c)
      {
        case 48:
        case 49:
        case 50:
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
        case 56:
        case 57:
          if (deletions_allowed)
          {
            s1 = cur_cmd;
            s2 = cur_mod;
            s3 = cur_sym;
            OK_to_interrupt = false;
            if ((last > first + 1) && (buffer[first + 1] >= 48) && (buffer[first + 1] <= 57))
              c = c * 10 + buffer[first + 1] - 48 * 11;
            else
              c = c - 48;
            while (c > 0)
            {
              get_next ();
              if (cur_cmd == 39)
              {
                if (str_ref[cur_mod] < 127)
                {
                  if (str_ref[cur_mod] > 1)
                    decr (str_ref[cur_mod]);
                  else
                    flush_string (cur_mod);
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
            show_context ();
            goto lab_continue;
          }
          break;
;
#ifdef TEXMF_DEBUG
        case 68:
        {
          debug_help ();
          goto lab_continue;
        }
        break;
#endif /* TEXMF_DEBUG */
        case 69:
          if (file_ptr > 0)
          {
            editnamestart = str_start[input_stack[file_ptr].name_field];
            editname_length = str_start[input_stack[file_ptr].name_field + 1] -
            str_start[input_stack[file_ptr].name_field];
            editline = line;
            jump_out ();
          }
          break;
        case 72:
        {
          if (use_err_help)
          {
            j = str_start[err_help];
            while (j < str_start[err_help + 1])
            {
              if (str_pool[j]!= 37)
                print(str_pool[j]);
              else if (j + 1 == str_start[err_help + 1])
                print_ln ();
              else if (str_pool[j + 1] != 37)
                print_ln ();
              else
              {
                incr (j);
                print_char(37);
              }
              incr (j);
            }
            use_err_help = false;
          }
          else
          {
            if (help_ptr == 0)
            {
              help_ptr = 2;
              help_line[1] = 280;
              help_line[0] = 281;
            }
            do {
              decr (help_ptr);
              print(help_line[help_ptr]);
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
          goto lab_continue;
        }
        break;
      case 73:
        {
          begin_file_reading ();
          if (last > first + 1)
          {
            cur_input.loc_field = first + 1;
            buffer[first] = 32;
          }
          else
          {
            {
              ;
              print(277);
              term_input ();
            }
            cur_input.loc_field = first;
          }
          first = last + 1;
          cur_input.limit_field = last;
          goto lab_exit;
        }
        break;
      case 81:
      case 82:
      case 83:
        {
          error_count = 0;
          interaction = 0 + c - 81;
          print(272);
          switch (c)
          {
            case 81:
              {
                print(273);
                decr (selector);
              }
              break;
            case 82:
              print(274);
              break;
            case 83:
              print(275);
              break;
          }
          print(276);
          print_ln ();
          fflush (stdout);
          goto lab_exit;
        }
        break;
      case 88:
        {
          interaction = 2;
          jump_out ();
        }
        break;
      default:
        do_nothing();
        break;
    }
      {
        print(266);
        print_nl(267);
        print_nl(268);
        if (file_ptr > 0)
          print(269);
        if (deletions_allowed)
          print_nl(270);
        print_nl(271);
      }
    }
  incr (error_count);
  if (error_count == 100)
  {
    print_nl(264);
    history = 3;
    jump_out ();
  }
  if (interaction > 0)
    decr (selector);
  if (use_err_help)
  {
    print_nl(261);
    j = str_start[err_help];
    while (j < str_start[err_help + 1])
    {
      if (str_pool[j]!= 37)
        print(str_pool[j]);
      else if (j + 1 == str_start[err_help + 1])
        print_ln ();
      else if (str_pool[j + 1]!= 37)
        print_ln ();
      else
      {
        incr (j);
        print_char(37);
      }
      incr (j);
    }
  }
  else
    while (help_ptr > 0)
    {
      decr (help_ptr);
      print_nl(help_line[help_ptr]);
    }
  print_ln ();
  if (interaction > 0)
    incr (selector);
  print_ln ();
  lab_exit:;
}
/* 88 */
void fatal_error (str_number s)
{
  normalize_selector ();
  print_err("Emergency stop");
  help1(s);
  succumb();
}
/* 89 */
void overflow (str_number s, integer n)
{
  normalize_selector ();
  print_err("METAFONT capacity exceeded, sorry [");
  print(s);
  print_char('=');
  print_int (n);
  print_char(']');
  {
    help_ptr = 2;
    help_line[1] = 287;
    help_line[0] = 288;
  }
  succumb ();
}
/* 90 */
void confusion (str_number s)
{
  normalize_selector ();
  if (history < error_message_issued)
  {
    print_err("This can't happen (");
    print(s);
    print_char(')');
    {
      help_ptr = 1;
      help_line[0] = 290;
    }
  }
  else
  {
    print_err("I can't go on meeting you like this");
    {
      help_ptr = 2;
      help_line[1] = 292;
      help_line[0] = 293;
    }
  }
  succumb ();
}
/* 36 */
boolean init_terminal (void)
{
  boolean Result;

  topenin ();
  if (last > first)
  {
    cur_input.loc_field = first;
    while ((cur_input.loc_field < last) && (buffer[cur_input.loc_field] == ' '))
      incr (cur_input.loc_field);
    if (cur_input.loc_field < last)
    {
      Result = true;
      goto lab_exit;
    }
  }
  while (true)
  {
    ;
    Fputs (stdout,  "**");
    fflush (stdout);
    if (!inputln (stdin, true))
    {
      putc ('\n',  stdout);
      fprintf (stdout, "%s\n",  "!End of file on the terminal... why?");
      Result = false;
      goto lab_exit;
    }
    cur_input.loc_field = first;
    while ((cur_input.loc_field < last) && (buffer[cur_input.loc_field] == 32))
      incr (cur_input.loc_field);
    if (cur_input.loc_field < last)
    {
      Result = true;
      goto lab_exit;
    }
    fprintf (stdout, "%s\n",  "Please type the name of your input file.");
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
      overflow (258, max_strings - init_str_ptr);
    incr (max_str_ptr);
  }
  str_ref[str_ptr] = 1;
  incr (str_ptr);
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
    incr (j);
    incr (k);
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

  ls = (str_start[s + 1] - str_start[s]);
  lt = (str_start[t + 1] - str_start[t]);
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
    incr (j);
    incr (k);
    decr (l);
  }
  Result = ls - lt;
lab_exit:;
  return Result;
}
/* 65 */
void print_dd (integer n)
{
  n = abs (n) % 100;
  print_char('0' + (n / 10));
  print_char('0' + (n % 10));
}
/* 66 */
void term_input (void)
{
  integer k;

  fflush (stdout);
  if (!inputln (stdin, true))
    fatal_error (260);
  term_offset = 0;
  decr (selector);
  if (last != first)
    for (k = first; k <= last - 1; k++)
      print(buffer[k]);
  print_ln ();
  buffer[last] = '%';
  incr (selector);
}
/* 87 */
void normalize_selector (void)
{
  if (log_opened)
    selector = term_and_log;
  else
    selector = term_only;
  if (job_name == 0)
    open_log_file ();
  if (interaction == 0)
    decr (selector);
}
/* 93 */
void pause_for_instructions (void)
{
  if (OK_to_interrupt)
  {
    interaction = error_stop_mode;
    if ((selector == log_only) || (selector == no_print))
      incr (selector);
    print_err("Interruption");
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
    decr (k);
    a = (a + dig[k] * two) / 10;
  }
  Result = half (a + 1);
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
    ;
#ifdef TEXMF_DEBUG
    if (q == 0)
      confusion(47);
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
      incr (f);
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
    f = -f;
    negative = true;
  }
  if (q < 0)
  {
    q = -q;
    negative = !negative;
  }
  if (f < 268435456L)
    n = 0;
  else
  {
    n = f / 268435456;
    f = f % 268435456;
    if (q <= 2147483647 / n)
      n = n * q;
    else
    {
      arith_error = true;
      n = 2147483647;
    }
  }
  f = f + 268435456;
  p = 134217728;
  if (q < 1073741824L)
    do {
      if (odd (f))
        p = half (p + q);
      else
        p = half (p);
      f = half (f);
    } while (!(f == 1));
  else
    do {
      if (odd (f))
        p = p + half (q - p);
      else
        p = half (p);
      f = half (f);
  } while (!(f == 1));
  be_careful = n - 2147483647;
  if (be_careful + p > 0)
  {
    arith_error = true;
    n = 2147483647L - p;
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
    f = -f;
    negative = true;
  }
  if (q < 0)
  {
    q = -q;
    negative = !negative;
  }
  if (f < 65536L)
    n = 0;
  else
  {
    n = f / 65536;
    f = f % 65536;
    if (q <= 2147483647 / n)
      n = n * q;
    else
    {
      arith_error = true;
      n = 2147483647;
    }
  }
  f = f + 65536;
  p = 32768;
  if (q < 1073741824L)
    do {
      if (odd (f))
        p = half (p + q);
      else
        p = half (p);
      f = half (f);
    } while (!(f == 1));
  else
    do {
      if (odd (f))
        p = p + half (q - p);
      else
        p = half (p);
      f = half (f);
    } while (!(f == 1));
  be_careful = n - 2147483647;
  if (be_careful + p > 0)
  {
    arith_error = true;
    n = 2147483647 - p;
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
    p = -p;
    negative = true;
  }
  if (q <= 0)
  {
    ;
#ifdef TEXMF_DEBUG
    if (q == 0)
      confusion(47);
#endif /* TEXMF_DEBUG */
    q = -q;
    negative = !negative;
  }
  n = p / q;
  p = p % q;
  if (n >= 32768L)
  {
    arith_error = true;
    if (negative)
      Result = -2147483647;
    else
      Result = 2147483647;
  }
  else
  {
    n = (n - 1) * 65536;
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
    } while (!(f >= 65536L));
    be_careful = p - q;
    if (be_careful + p >= 0)
      incr (f);
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

  acc = take_fraction (st - (sf / 16), sf - (st / 16));
  acc = take_fraction (acc, ct - cf);
  num = 536870912L + take_fraction (acc, 379625062L);
  denom = 805306368L + take_fraction (ct, 497706707L) + take_fraction (cf ,
  307599661L);
  if (t != 65536L)
    num = make_scaled (num, t);
  if (num / 4 >= denom)
    Result = 1073741824;
  else
    Result = make_fraction (num, denom);
  return Result;
}
/* 117 */
integer ab_vs_cd (integer a, integer b, integer c, integer d)
{
  integer Result;
  integer q, r;
  
  if (a < 0)
  {
    a = -a;
    b = -b;
  }
  if (c < 0)
  {
    c = -c;
    d = -d;
  }
  if (d <= 0)
  {
    if (b >= 0)
    {
      if (((a == 0) || (b == 0)) && ((c == 0) || (d == 0)))
      {
        Result = 0;
        goto lab_exit;
      }
      else
      {
        Result = 1;
        goto lab_exit;
      }
    }
    if (d == 0)
    {
      if (a == 0)
      {
        Result = 0;
        goto lab_exit;
      }
      else
      {
        Result = -1;
        goto lab_exit;
      }
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
      {
        Result = -1;
        goto lab_exit;
      }
    }
    if (c == 0)
    {
      Result = 0;
      goto lab_exit;
    }
    else
    {
      Result = -1;
      goto lab_exit;
    }
  }
  while (true)
  {
    q = a / d;
    r = c / b;
    if (q != r)
    {
      if (q > r)
      {
        Result = 1;
        goto lab_exit;
      }
      else
      {
        Result = -1;
        goto lab_exit;
      }
    }
    q = a % d;
    r = c % b;
    if (r == 0)
    {
      if (q == 0)
      {
        Result = 0;
        goto lab_exit;
      }
      else
      {
        Result = 1;
        goto lab_exit;
      }
    }
    if (q == 0)
    {
      Result = -1;
      goto lab_exit;
    }
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
      {
        help_ptr = 2;
        help_line[1] = 307;
        help_line[0] = 308;
      }
      error ();
    }
    Result = 0;
  }
  else
  {
    k = 23;
    q = 2;
    while (x < 536870912L)
    {
      decr (k);
      x = x + x + x + x;
    }
    if (x < 1073741824L)
      y = 0;
    else
    {
      x = x - 1073741824;
      y = 1;
    }
    do {
      x = x + x;
      y = y + y;
      if (x >= 1073741824L)
      {
        x = x - 1073741824;
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
    Result = half (q);
  }
  return Result;
}
/* 124 */
integer pyth_add (integer a, integer b)
{
  integer Result;
  fraction r;
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
    if (a < 536870912)
      big = false;
    else
    {
      a = a / 4;
      b = b / 4;
      big = true;
    }
    while (true)
    {
      r = make_fraction (b, a);
      r = take_fraction (r, r);
      if (r == 0)
        goto done;
      r = make_fraction (r, 1073741824L + r);
      a = a + take_fraction (a + a, r);
      b = take_fraction (b, r);
    }
    done:;
    if (big)
    {
      if (a < 536870912L)
        a = a + a + a + a;
      else
      {
        arith_error = true;
        a = 2147483647L;
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
  
  a = abs (a);
  b = abs (b);
  if (a <= b)
  {
    if (a < b)
    {
      print_err("Pythagorean subtraction ");
      print_scaled(a);
      print(310);
      print_scaled(b);
      print(306);
      {
        help_ptr = 2;
        help_line[1] = 307;
        help_line[0] = 308;
      }
      error ();
    }
    a = 0;
  }
  else
  {
    if (a < 1073741824L)
      big = false;
    else
    {
      a = half (a);
      b = half (b);
      big = true;
    }
    while (true)
    {
      r = make_fraction (b, a);
      r = take_fraction (r, r);
      if (r == 0)
        goto done;
      r = make_fraction (r, 1073741824L - r);
      a = a - take_fraction (a + a, r);
      b = take_fraction (b, r);
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
    {
      help_ptr = 2;
      help_line[1] = 312;
      help_line[0] = 308;
    }
    error ();
    Result = 0;
  }
  else
  {
    y = 1302456860L;
    z = 6581195L;
    while (x < 1073741824L)
    {
      x = x + x;
      y = y - 93032639L;
      z = z - 48782L;
    }
    y = y + (z / 65536L);
    k = 2;
    while (x > 1073741828L)
    {
      z = ((x - 1) / two_to_the[k]) + 1;
      while (x < 1073741824L + z)
      {
        z = half (z + 1);
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
  
  if (x > 174436200L)
  {
    arith_error = true;
    Result = 2147483647L;
  }
  else if (x < -197694359L)
    Result = 0;
  else
  {
    if (x <= 0)
    {
      z = -8 * x;
      y = 1048576L;
    }
    else
    {
      if (x <= 127919879L)
        z = 1023359037L - 8 * x;
      else
        z = 8 * (174436200L - x);
      y = 2147483647L;
    }
    k = 1;
    while (z > 0)
    {
      while (z >= spec_log[k])
      {
        z = z - spec_log[k];
        y = y - 1 - ((y - two_to_the[k - 1]) / two_to_the[k]);
      }
      incr (k);
    }
    if (x <= 127919879L)
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
    octant = 1;
  else
  {
    x = -x;
    octant = 2;
  }
  if (y < 0)
  {
    y = -y;
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
    print_err("angle(0,0) is taken as zero");
    {
      help_ptr = 2;
      help_line[1] = 314;
      help_line[0] = 308;
    }
    error ();
    Result = 0;
  }
  else
  {
    while (x >= 536870912L)
    {
      x = half (x);
      y = half (y);
    }
    z = 0;
    if (y > 0)
    {
      while (x < 268435456L)
      {
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
    {
      case 1:
        Result = z;
        break;
      case 5:
        Result = 94371840L - z;
        break;
      case 6:
        Result = 94371840L + z;
        break;
      case 2:
        Result = 188743680L - z;
        break;
      case 4:
        Result = z - 188743680L;
        break;
      case 8:
        Result = -z - 94371840L;
        break;
      case 7:
        Result = z - 94371840L;
        break;
      case 3:
        Result = -z;
        break;
    }
  }
  return Result;
}
/* 145 */
void n_sin_cos(angle z)
{
  small_number k;
  unsigned char q;
  fraction r;
  integer x, y, t;
  
  while (z < 0)
    z = z + 377487360L;
  z = z % 377487360L;
  q = z / 47185920L;
  z = z % 47185920L;
  x = 268435456L;
  y = x;
  if (!odd (q))
    z = 47185920L - z;
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
    incr (k);
  }
  if (y < 0)
    y = 0;
  switch (q)
  {
    case 0:
      ;
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
      x = -x;
      break;
    case 4:
      {
        x = -x;
        y = -y;
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
      y = -y;
      break;
  }
  r = pyth_add (x, y);
  n_cos = make_fraction (x, r);
  n_sin = make_fraction (y, r);
}
/* 149 */
void new_randoms (void)
{
  unsigned char k;
  fraction x;
  
  {integer for_end; k = 0;for_end = 23; if (k <= for_end) do
    {
      x = randoms[k] - randoms[k + 31];
      if (x < 0)
        x = x + 268435456L;
      randoms[k] = x;
    }
  while (k++ < for_end);}
  {integer for_end; k = 24;for_end = 54; if (k <= for_end) do
    {
      x = randoms[k] - randoms[k - 24];
      if (x < 0)
        x = x + 268435456L;
      randoms[k] = x;
    }
  while (k++ < for_end);}
  j_random = 54;
}
/* 150 */
void init_randoms (scaled seed)
{
  fraction j, jj, k;
  unsigned char i;

  j = abs (seed);
  while (j >= 268435456L)
    j = half (j);
  k = 1;
  {integer for_end; i = 0;for_end = 54; if (i <= for_end) do
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
/* 151 */
scaled unif_rand (scaled x)
{
  scaled Result;
  scaled y;
  
  if (j_random == 0)
    new_randoms ();
  else
    decr (j_random);
  y = take_fraction (abs (x), randoms[j_random]);
  if (y == abs (x))
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
      if (j_random == 0)
        new_randoms ();
      else
        decr (j_random);
      x = take_fraction (112429L, randoms[j_random] - 134217728L);
      if (j_random == 0)
        new_randoms ();
      else
        decr (j_random);
      u = randoms[j_random];
    } while (!(abs (x) < u));
    x = make_fraction (x, u);
    l = 139548960L - m_log (u);
  } while (!(ab_vs_cd (1024, l, x, x) >= 0));
  Result = x;
  return Result;
}
/* 157 */
#ifdef TEXMF_DEBUG
void print_word (memory_word w)
{
  print_int (w .cint);
  print_char(32);
  print_scaled(w .cint);
  print_char(32);
  print_scaled(w .cint / 4096);
  print_ln ();
  print_int (w .hh.lh);
  print_char(61);
  print_int (w .hh.b0);
  print_char(58);
  print_int (w .hh.b1);
  print_char(59);
  print_int (w .hh.rh);
  print_char(32);
  print_int (w .qqqq.b0);
  print_char(58);
  print_int (w .qqqq.b1);
  print_char(58);
  print_int (w .qqqq .b2);
  print_char(58);
  print_int (w .qqqq .b3);
}
#endif /* TEXMF_DEBUG */
/* 217 */
void show_token_list (integer p, integer q, integer l, integer nulltally)
{
  small_number cclass, c;
  integer r, v;
  cclass = 3;
  tally = nulltally;
  
  while ((p != 0) && (tally < l))
  {
    if (p == q)
    {
      first_count = tally;
      trick_count = tally + 1 + error_line - half_error_line;
      if (trick_count < error_line)
        trick_count = error_line;
    }
    c = 9;
    if ((p < 0) || (p > mem_end))
    {
      print(493);
      goto lab_exit;
    }
    if (p < hi_mem_min)
    {
      if (mem[p].hh.b1 == 12)
      {
        if (mem[p].hh.b0 == 16)
        {
          if (cclass == 0)
            print_char(32);
          v = mem[p + 1].cint;
          if (v < 0)
          {
            if (cclass == 17)
              print_char(32);
            print_char(91);
            print_scaled(v);
            print_char(93);
            c = 18;
          }
          else
          {
            print_scaled(v);
            c = 0;
          }
        }
        else if (mem[p].hh.b0 != 4)
          print(496);
        else
        {
          print_char(34);
          slow_print(mem[p + 1].cint);
          print_char(34);
          c = 4;
        }
      }
      else if ((mem[p].hh.b1 != 11) || (mem[p].hh.b0 < 1) || (mem[p].hh.b0 > 19))
        print(496);
      else
      {
        g_pointer = p;
        print_capsule ();
        c = 8;
      }
    }
    else
    {
      r = mem[p].hh.lh;
      if (r >= 9770)
      {
        if (r < 9920)
        {
          print(498);
          r = r - (9770);
        }
        else if (r < 10070)
        {
          print(499);
          r = r - (9920);
        }
        else
        {
          print(500);
          r = r - (10070);
        }
        print_int (r);
        print_char(41);
        c = 8;
      }
      else if (r < 1)
      {
        if (r == 0)
        {
          if (cclass == 17)
            print_char(32);
          print(497);
          c = 18;
        }
        else
          print(494);
      }
      else
      {
        r = hash[r].v.RH;
        if ((r < 0) || (r >= str_ptr))
          print(495);
        else
        {
          c = char_class[str_pool[str_start[r]]];
          if (c == cclass)
            switch (c)
            {
              case 9:
                print_char(46);
                break;
              case 5:
              case 6:
              case 7:
              case 8:
                ;
                break;
              default:
                print_char(32);
                break;
            }
          slow_print(r);
        }
      }
    }
    cclass = c;
    p = mem[p].hh.rh;
  }
  if (p != 0)
    print(492);
  lab_exit:;
}
/* 665 */
void runaway (void)
{
  if (scanner_status > 2)
  {
    print_nl(638);
    switch (scanner_status)
    {
      case 3:
        print(639);
        break;
      case 4:
      case 5:
        print(640);
        break;
      case 6:
        print(641);
        break;
    }
    print_ln ();
    show_token_list (mem[mem_top - 2].hh.rh, 0, error_line - 10, 0);
  }
}
/* 163 */
halfword get_avail (void)
{
  halfword Result;
  halfword p;
  
  p = avail;
  if (p != 0)
    avail = mem[avail].hh.rh;
  else if (mem_end < mem_max)
  {
    incr (mem_end);
    p = mem_end;
  }
  else
  {
    decr (hi_mem_min);
    p = hi_mem_min;
    if (hi_mem_min <= lo_mem_max)
    {
      runaway ();
      overflow (315, mem_max + 1);
    }
  }
  mem[p].hh.rh = 0;
  ;
#ifdef STAT
  incr (dyn_used);
#endif /* STAT */
  Result = p;
  return Result;
}
/* 167 */
halfword get_node (integer s)
{
  halfword Result;
  halfword p;
  halfword q;
  integer r;
  integer t, tt;
  
lab_restart:
  p = rover;
  do {
    q = p + mem[p].hh.lh;
    while ((mem[q].hh.rh == 268435455L))
    {
      t = mem[q + 1].hh.rh;
      tt = mem[q + 1].hh.lh;
      if (q == rover)
        rover = t;
      mem[t + 1].hh.lh = tt;
      mem[tt + 1].hh.rh = t;
      q = q + mem[q].hh.lh;
    }
    r = q - s;
    if (r > p + 1)
    {
      mem[p].hh.lh = r - p;
      rover = p;
      goto found;
    }
    if (r == p)
    {
      if (mem[p + 1].hh.rh != p)
      {
        rover = mem[p + 1].hh.rh;
        t = mem[p + 1].hh.lh;
        mem[rover + 1].hh.lh = t;
        mem[t + 1].hh.rh = rover;
        goto found;
      }
    }
    mem[p].hh.lh = q - p;
    p = mem[p + 1].hh.rh;
  } while (!(p == rover));
  if (s == 1073741824L)
  {
    Result = 268435455L;
    goto lab_exit;
  }
  if (lo_mem_max + 2 < hi_mem_min)
  {
    if (lo_mem_max + 2 <= 268435455L)
    {
      if (hi_mem_min - lo_mem_max >= 1998)
        t = lo_mem_max + 1000;
      else
        t = lo_mem_max + 1 + (hi_mem_min - lo_mem_max) / 2;
      if (t > 268435455L)
        t = 268435455L;
      p = mem[rover + 1].hh.lh;
      q = lo_mem_max;
      mem[p + 1].hh.rh = q;
      mem[rover + 1].hh.lh = q;
      mem[q + 1].hh.rh = rover;
      mem[q + 1].hh.lh = p;
      mem[q].hh.rh = 268435455L;
      mem[q].hh.lh = t - lo_mem_max;
      lo_mem_max = t;
      mem[lo_mem_max].hh.rh = 0;
      mem[lo_mem_max].hh.lh = 0;
      rover = q;
      goto lab_restart;
    }
  }
  overflow (315, mem_max + 1);
  found: mem[r].hh.rh = 0;
  ;
#ifdef STAT
  var_used = var_used + s;
#endif /* STAT */
  Result = r;
  lab_exit:;
  return Result;
}
/* 172 */
void free_node (halfword p, halfword s)
{
  halfword q;

  mem[p].hh.lh = s;
  mem[p].hh.rh = 268435455L;
  q = mem[rover + 1].hh.lh;
  mem[p + 1].hh.lh = q;
  mem[p + 1].hh.rh = rover;
  mem[rover + 1].hh.lh = p;
  mem[q + 1].hh.rh = p;
  ;
#ifdef STAT
  var_used = var_used - s;
#endif /* STAT */
}
/* 177 */
void flush_list (halfword p)
{
  halfword q, r;

  if (p >= hi_mem_min)
  {
    if (p != mem_top)
    {
      r = p;
      do {
        q = r;
        r = mem[r].hh.rh;
        ;
#ifdef STAT
        decr (dyn_used);
#endif /* STAT */
        if (r < hi_mem_min)
          goto done;
      } while (!(r == mem_top));
      done: mem[q].hh.rh = avail;
      avail = p;
    }
  }
}
/* 177 */
void flush_node_list (halfword p)
{
  halfword q;

  while (p != 0)
  {
    q = p;
    p = mem[p].hh.rh;
    if (q < hi_mem_min)
      free_node (q, 2);
    else
    {
      mem[q].hh.rh = avail;
      avail = q;
      ;
#ifdef STAT
      decr (dyn_used);
#endif /* STAT */
    }
  }
}
/* 180 */
#ifdef TEXMF_DEBUG
void check_mem (boolean print_locs)
{
  halfword p, q, r;
  boolean clobbered;
  
  {integer for_end; p = 0;for_end = lo_mem_max; if (p <= for_end)
    do
      freearr[p] = false;
    while (p++ < for_end);}
  {integer for_end; p = hi_mem_min;for_end = mem_end; if (p <= for_end)
    do
      freearr[p] = false;
    while (p++ < for_end);}
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
      print_int (q);
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
    else if (!((mem[p].hh.rh == 268435455L)) || (mem[p].hh.lh < 2) ||
      (p + mem[p].hh.lh > lo_mem_max) || (mem[mem[p + 1].hh.rh + 1].hh.lh != p))
      clobbered = true;
    if (clobbered)
    {
      print_nl(317);
      print_int (q);
      goto done2;
    }
    {integer for_end; q = p;for_end = p + mem[p].hh.lh - 1;
      if (q <= for_end)
        do {
          if (freearr[q])
          {
            print_nl(318);
            print_int (q);
            goto done2;
          }
          freearr[q] = true;
        }
    while (q++ < for_end);}
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
      print_int (p);
    }
    while ((p <= lo_mem_max) && !freearr[p])
      incr (p);
    while ((p <= lo_mem_max) && freearr[p])
      incr (p);
  }
  q = 13;
  p = mem[q].hh.rh;
  while (p != 13)
  {
    if (mem[p + 1].hh.lh != q)
    {
      print_nl(598);
      print_int (p);
    }
    p = mem[p + 1].hh.rh;
    r = 19;
    do {
      if (mem[mem[p].hh.lh + 1].cint >= mem[r + 1].cint)
      {
        print_nl(599);
        print_int (p);
      }
      r = mem[p].hh.lh;
      q = p;
      p = mem[q].hh.rh;
    } while (!(r == 0));
  }
  if (print_locs)
  {
    print_nl(320);
    {integer for_end; p = 0;for_end = lo_mem_max; if (p <= for_end) do
      if (!freearr[p] && ((p > was_lo_max) || was_free[p]))
      {
        print_char(32);
        print_int (p);
      }
    while (p++ < for_end);}
    {integer for_end; p = hi_mem_min;for_end = mem_end; if (p <=
    for_end) do
      if (!freearr[p]&& ((p < was_hi_min) || (p > was_mem_end) || was_free[p]))
      {
        print_char(32);
        print_int (p);
      }
    while (p++ < for_end);}
  }
  {integer for_end; p = 0;for_end = lo_mem_max; if (p <= for_end)
    do
      was_free[p] = freearr[p];
  while (p++ < for_end);}
  {integer for_end; p = hi_mem_min;for_end = mem_end; if (p <=
  for_end) do
    was_free[p] = freearr[p];
  while (p++ < for_end);}
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

  {integer for_end; q = 0;for_end = lo_mem_max; if (q <= for_end)
    do {
      if (mem[q].hh.rh == p)
      {
        print_nl(321);
        print_int (q);
        print_char(41);
      }
      if (mem[q].hh.lh == p)
      {
        print_nl(322);
        print_int (q);
        print_char(41);
      }
    }
  while (q++ < for_end);}
  {integer for_end; q = hi_mem_min;for_end = mem_end; if (q <=
  for_end) do
    {
      if (mem[q].hh.rh == p)
      {
        print_nl(321);
        print_int (q);
        print_char(41);
      }
      if (mem[q].hh.lh == p)
      {
        print_nl(322);
        print_int (q);
        print_char(41);
      }
    }
  while (q++ < for_end);}
  {integer for_end; q = 1;for_end = 9769; if (q <= for_end) do
    {
      if (eqtb[q].v.RH == p)
      {
        print_nl(458);
        print_int (q);
        print_char(41);
      }
    }
  while (q++ < for_end);}
}
#endif /* TEXMF_DEBUG */
/* 189 */
void print_op (quarterword c)
{
  if (c <= 15)
    print_type (c);
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
  dateandtime (internal[17], internal[16], internal[15],
  internal[14]);
  internal[17] = internal[17] * 65536L;
  internal[16] = internal[16] * 65536L;
  internal[15] = internal[15] * 65536L;
  internal[14] = internal[14] * 65536L;
}
/* 205 */
halfword id_lookup (integer j, integer l)
{
  halfword Result;
  integer h;
  halfword p;
  halfword k;
  
  if (l == 1)
  {
    p = buffer[j]+ 1;
    hash[p].v.RH = p - 1;
    goto found;
  }
  h = buffer[j];
  {integer for_end; k = j + 1;for_end = j + l - 1; if (k <= for_end) do
    {
      h = h + h + buffer[k];
      while (h >= 7919)
        h = h - 7919;
    }
  while (k++ < for_end);}
  p = h + 257;
  while (true)
  {
    if (hash[p].v.RH > 0)
    {
      if ((str_start[hash[p].v.RH + 1] - str_start[hash[p].v.RH]) == l)
      {
        if (str_eq_buf (hash[p].v.RH, j))
          goto found;
      }
    }
    if (hash[p].lh == 0)
    {
      if (hash[p].v.RH > 0)
      {
        do {
          if ((hash_used == 257))
            overflow (457, 9500);
          decr (hash_used);
        } while (!(hash[hash_used].v.RH == 0));
        hash[p].lh = hash_used;
        p = hash_used;
      }
      {
        if (pool_ptr + l > max_pool_ptr)
        {
          if (pool_ptr + l > pool_size)
          overflow (257, pool_size - init_pool_ptr);
          max_pool_ptr = pool_ptr + l;
        }
      }
      {integer for_end; k = j;for_end = j + l - 1; if (k <= for_end) do
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
    p = hash[p].lh;
  }
  found: Result = p;
  return Result;
}
/* 215 */
halfword new_num_tok (scaled v)
{
  halfword Result;
  halfword p;

  p = get_node (2);
  mem[p + 1].cint = v;
  mem[p].hh.b0 = 16;
  mem[p].hh.b1 = 12;
  Result = p;
  return Result;
}
/* 216 */
void flush_token_list (halfword p)
{
  halfword q;

  while (p != 0)
  {
    q = p;
    p = mem[p].hh.rh;
    if (q >= hi_mem_min)
    {
      mem[q].hh.rh = avail;
      avail = q;
      ;
#ifdef STAT
      decr (dyn_used);
#endif /* STAT */
    }
    else
    {
      switch (mem[q].hh.b0)
      {
        case 1:
        case 2:
        case 16:
          ;
          break;
        case 4:
          {
            if (str_ref[mem[q + 1].cint]< 127)
            {
              if (str_ref[mem[q + 1].cint] > 1)
                decr (str_ref[mem[q + 1].cint]);
              else
                flush_string (mem[q + 1].cint);
            }
          }
          break;
        case 3:
        case 5:
        case 7:
        case 12:
        case 10:
        case 6:
        case 9:
        case 8:
        case 11:
        case 14:
        case 13:
        case 17:
        case 18:
        case 19:
          {
            g_pointer = q;
            token_recycle ();
          }
          break;
        default:
          confusion(491);
          break;
      }
      free_node (q, 2);
    }
  }
}
/* 226 */
void delete_mac_ref (halfword p)
{
  if (mem[p].hh.lh == 0)
    flush_token_list (p);
  else
    decr (mem[p].hh.lh);
}
/* 625 */
void print_cmd_mod (integer c, integer m)
{
  switch (c)
  {
    case 18:
      print(462);
      break;
    case 77:
      print(461);
      break;
    case 59:
      print(464);
      break;
    case 72:
      print(463);
      break;
    case 79:
      print(460);
      break;
    case 32:
      print(465);
      break;
    case 81:
      print(58);
      break;
    case 82:
      print(44);
      break;
    case 57:
      print(466);
      break;
    case 19:
      print(467);
      break;
    case 60:
      print(468);
      break;
    case 27:
      print(469);
      break;
    case 11:
      print(470);
      break;
    case 80:
      print(459);
      break;
    case 84:
      print(453);
      break;
    case 26:
      print(471);
      break;
    case 6:
      print(472);
      break;
    case 9:
      print(473);
      break;
    case 70:
      print(474);
      break;
    case 73:
      print(475);
      break;
    case 13:
      print(476);
      break;
    case 46:
      print(123);
      break;
    case 63:
      print(91);
      break;
    case 14:
      print(477);
      break;
    case 15:
      print(478);
      break;
    case 69:
      print(479);
      break;
    case 28:
      print(480);
      break;
    case 47:
      print(408);
      break;
    case 24:
      print(481);
      break;
    case 7:
      print_char(92);
      break;
    case 65:
      print(125);
      break;
    case 64:
      print(93);
      break;
    case 12:
      print(482);
      break;
    case 8:
      print(483);
      break;
    case 83:
      print(59);
      break;
    case 17:
      print(484);
      break;
    case 78:
      print(485);
      break;
    case 74:
      print(486);
      break;
    case 35:
      print(487);
      break;
    case 58:
      print(488);
      break;
    case 71:
      print(489);
      break;
    case 75:
      print(490);
      break;
    case 16:
      if (m <= 2)
      {
        if (m == 1)
          print(655);
        else if (m < 1)
          print(454);
        else
          print(656);
      }
      else if (m == 53)
        print(657);
      else if (m == 44)
        print(658);
      else
        print(659);
      break;
    case 4:
      if (m <= 1)
      {
        if (m == 1)
          print(662);
        else
          print(455);
      }
      else if (m == 9770)
        print(660);
      else
        print(661);
      break;
    case 61:
      switch (m)
      {
        case 1:
          print(664);
          break;
        case 2:
          print_char(64);
          break;
        case 3:
          print(665);
          break;
        default:
          print(663);
          break;
      }
      break;
    case 56:
      if (m >= 9770)
      {
        if (m == 9770)
          print(676);
        else if (m == 9920)
          print(677);
        else
          print(678);
      }
      else if (m < 2)
        print(679);
      else if (m == 2)
        print(680);
      else
        print(681);
      break;
    case 3:
      if (m == 0)
        print(691);
      else
        print(617);
      break;
    case 1:
    case 2:
      switch (m)
      {
        case 1:
          print(718);
          break;
        case 2:
          print(452);
          break;
        case 3:
          print(719);
          break;
        default:
          print(720);
          break;
      }
      break;
    case 33:
    case 34:
    case 37:
    case 55:
    case 45:
    case 50:
    case 36:
    case 43:
    case 54:
    case 48:
    case 51:
    case 52:
      print_op (m);
      break;
    case 30:
      print_type (m);
      break;
    case 85:
      if (m == 0)
        print(912);
      else
        print(913);
      break;
    case 23:
      switch (m)
      {
        case 0:
          print(273);
          break;
        case 1:
          print(274);
          break;
        case 2:
          print(275);
          break;
        default:
          print(919);
          break;
      }
      break;
    case 21:
      if (m == 0)
        print(920);
      else
        print(921);
      break;
    case 22:
      switch (m)
      {
        case 0:
          print(935);
          break;
        case 1:
          print(936);
          break;
        case 2:
          print(937);
          break;
        case 3:
          print(938);
          break;
        default:
          print(939);
          break;
      }
      break;
    case 31:
    case 62:
      {
        if (c == 31)
          print(942);
        else
          print(943);
        print(944);
        slow_print(hash[m].v.RH);
      }
      break;
    case 41:
      if (m == 0)
        print(945);
      else
        print(946);
      break;
    case 10:
      print(947);
      break;
    case 53:
    case 44:
    case 49:
      {
        print_cmd_mod (16, c);
        print(948);
        print_ln ();
        show_token_list (mem[mem[m].hh.rh].hh.rh, 0, 1000, 0);
      }
      break;
    case 5:
      print(949);
      break;
    case 40:
      slow_print(int_name[m]);
      break;
    case 68:
      if (m == 1)
        print(956);
      else if (m == 0)
        print(957);
      else
        print(958);
      break;
    case 66:
      if (m == 6)
        print(959);
      else
        print(960);
      break;
    case 67:
      if (m == 0)
        print(961);
      else
        print(962);
      break;
    case 25:
      if (m < 1)
        print(992);
      else if (m == 1)
        print(993);
      else
        print(994);
      break;
    case 20:
      switch (m)
      {
        case 0:
          print(1004);
          break;
        case 1:
          print(1005);
          break;
        case 2:
          print(1006);
          break;
        case 3:
          print(1007);
          break;
        default:
          print(1008);
          break;
      }
      break;
    case 76:
      switch (m)
      {
        case 0:
          print(1026);
          break;
        case 1:
          print(1027);
          break;
        case 2:
          print(1029);
          break;
        case 3:
          print(1031);
          break;
        case 5:
          print(1028);
          break;
        case 6:
          print(1030);
          break;
        case 7:
          print(1032);
          break;
        case 11:
          print(1033);
          break;
        default:
          print(1034);
          break;
      }
      break;
    case 29:
      if (m == 16)
        print(1060);
      else
        print(1059);
      break;
    default:
      print(603);
      break;
  }
}
/* 227 */
void show_macro (halfword p, integer q, integer l)
{
  halfword r;

  p = mem[p].hh.rh;
  while (mem[p].hh.lh > 7)
  {
    r = mem[p].hh.rh;
    mem[p].hh.rh = 0;
    show_token_list (p, 0, l, 0);
    mem[p].hh.rh = r;
    p = r;
    if (l > 0)
      l = l - tally;
    else
      goto lab_exit;
  }
  tally = 0;
  switch (mem[p].hh.lh)
  {
    case 0:
      print(501);
      break;
    case 1:
    case 2:
    case 3:
      {
        print_char(60);
        print_cmd_mod (56, mem[p].hh.lh);
        print(502);
      }
      break;
    case 4:
      print(503);
      break;
    case 5:
      print(504);
      break;
    case 6:
      print(505);
      break;
    case 7:
      print(506);
      break;
  }
  show_token_list (mem[p].hh.rh, q, l - tally, 0);
lab_exit:;
}
/* 232 */
void init_big_node (halfword p)
{
  halfword q;
  small_number s;

  s = big_node_size[mem[p].hh.b0];
  q = get_node (s);
  do {
    s = s - 2;
    {
      if (serial_no > 2147483583L)
        overflow (588, serial_no / 64);
      mem[q + s].hh.b0 = 19;
      serial_no = serial_no + 64;
      mem[q + s + 1].cint = serial_no;
    }
    mem[q + s].hh.b1 = half (s) + 5;
    mem[q + s].hh.rh = 0;
  } while (!(s == 0));
  mem[q].hh.rh = p;
  mem[p + 1].cint = q;
}
/* 233 */
halfword id_transform (void)
{
  halfword Result;
  halfword p, q, r;
  
  p = get_node (2);
  mem[p].hh.b0 = 13;
  mem[p].hh.b1 = 11;
  mem[p + 1].cint = 0;
  init_big_node (p);
  q = mem[p + 1].cint;
  r = q + 12;
  do {
    r = r - 2;
    mem[r].hh.b0 = 16;
    mem[r + 1].cint = 0;
  } while (!(r == q));
  mem[q + 5].cint = 65536L;
  mem[q + 11].cint = 65536L;
  Result = p;
  return Result;
}
/* 234 */
void new_root (halfword x)
{
  halfword p;

  p = get_node (2);
  mem[p].hh.b0 = 0;
  mem[p].hh.b1 = 0;
  mem[p].hh.rh = x;
  eqtb[x].v.RH = p;
}
/* 235 */
void print_variable_name (halfword p)
{
  halfword q;
  halfword r;

  while (mem[p].hh.b1 >= 5)
  {
    switch (mem[p].hh.b1)
    {
      case 5:
        print_char(120);
        break;
      case 6:
        print_char(121);
        break;
      case 7:
        print(509);
        break;
      case 8:
        print(510);
        break;
      case 9:
        print(511);
        break;
      case 10:
        print(512);
        break;
      case 11:
        {
          print(513);
          print_int (p - 0);
          goto lab_exit;
        }
        break;
    }
    print(514);
    p = mem[p - 2 * (mem[p].hh.b1 - 5)].hh.rh;
  }
  q = 0;
  while (mem[p].hh.b1 > 1)
  {
    if (mem[p].hh.b1 == 3)
    {
      r = new_num_tok (mem[p + 2].cint);
      do {
        p = mem[p].hh.rh;
      } while (!(mem[p].hh.b1 == 4));
    }
    else if (mem[p].hh.b1 == 2)
    {
      p = mem[p].hh.rh;
      goto found;
    }
    else
    {
      if (mem[p].hh.b1 != 4)
        confusion(508);
      r = get_avail ();
      mem[r].hh.lh = mem[p + 2].hh.lh;
    }
    mem[r].hh.rh = q;
    q = r;
    found: p = mem[p + 2].hh.rh;
  }
  r = get_avail ();
  mem[r].hh.lh = mem[p].hh.rh;
  mem[r].hh.rh = q;
  if (mem[p].hh.b1 == 1)
    print(507);
  show_token_list (r, 0, 2147483647L, tally);
  flush_token_list (r);
  lab_exit:;
}
/* 238 */
boolean interesting (halfword p)
{
  boolean Result;
  small_number t;

  if (internal[3] > 0)
    Result = true;
  else
  {
    t = mem[p].hh.b1;
    if (t >= 5)
    {
      if (t != 11)
        t = mem[mem[p - 2 * (t - 5)].hh.rh].hh.b1;
    }
    Result = (t != 11);
  }
  return Result;
}
/* 239 */
halfword new_structure (halfword p)
{
  halfword Result;
  halfword q, r;
  
  switch (mem[p].hh.b1)
  {
    case 0:
      {
        q = mem[p].hh.rh;
        r = get_node (2);
        eqtb[q].v.RH = r;
      }
      break;
    case 3:
      {
        q = p;
        do {
          q = mem[q].hh.rh;
        } while (!(mem[q].hh.b1 == 4));
        q = mem[q + 2].hh.rh;
        r = q + 1;
        do {
          q = r;
          r = mem[r].hh.rh;
        } while (!(r == p));
        r = get_node (3);
        mem[q].hh.rh = r;
        mem[r + 2].cint = mem[p + 2].cint;
      }
      break;
    case 4:
      {
        q = mem[p + 2].hh.rh;
        r = mem[q + 1].hh.lh;
        do {
          q = r;
          r = mem[r].hh.rh;
        } while (!(r == p));
        r = get_node (3);
        mem[q].hh.rh = r;
        mem[r + 2] = mem[p + 2];
        if (mem[p + 2].hh.lh == 0)
        {
          q = mem[p + 2].hh.rh + 1;
          while (mem[q].hh.rh != p)
            q = mem[q].hh.rh;
          mem[q].hh.rh = r;
        }
      }
      break;
    default:
      confusion(515);
      break;
  }
  mem[r].hh.rh = mem[p].hh.rh;
  mem[r].hh.b0 = 21;
  mem[r].hh.b1 = mem[p].hh.b1;
  mem[r + 1].hh.lh = p;
  mem[p].hh.b1 = 2;
  q = get_node (3);
  mem[p].hh.rh = q;
  mem[r + 1].hh.rh = q;
  mem[q + 2].hh.rh = r;
  mem[q].hh.b0 = 0;
  mem[q].hh.b1 = 4;
  mem[q].hh.rh = 17;
  mem[q + 2].hh.lh = 0;
  Result = r;
  return Result;
}
/* 242 */
halfword find_variable (halfword t)
{
  halfword Result;
  halfword p, q, r, s;
  halfword pp, qq, rr, ss;
  integer n;
  memory_word saveword;
  
  p = mem[t].hh.lh;
  t = mem[t].hh.rh;
  if (eqtb[p].lh % 86 != 41)
  {
    Result = 0;
    goto lab_exit;
  }
  if (eqtb[p].v.RH == 0)
    new_root (p);
  p = eqtb[p].v.RH;
  pp = p;
  while (t != 0)
  {
    if (mem[pp].hh.b0 != 21)
    {
      if (mem[pp].hh.b0 > 21)
      {
        Result = 0;
        goto lab_exit;
      }
      ss = new_structure (pp);
      if (p == pp)
        p = ss;
      pp = ss;
    }
    if (mem[p].hh.b0 != 21)
      p = new_structure (p);
    if (t < hi_mem_min)
    {
      n = mem[t + 1].cint;
      pp = mem[mem[pp + 1].hh.lh].hh.rh;
      q = mem[mem[p + 1].hh.lh].hh.rh;
      saveword = mem[q + 2];
      mem[q + 2].cint = 2147483647L;
      s = p + 1;
      do {
        r = s;
        s = mem[s].hh.rh;
      } while (!(n <= mem[s + 2].cint));
      if (n == mem[s + 2].cint)
        p = s;
      else
      {
        p = get_node (3);
        mem[r].hh.rh = p;
        mem[p].hh.rh = s;
        mem[p + 2].cint = n;
        mem[p].hh.b1 = 3;
        mem[p].hh.b0 = 0;
      }
      mem[q + 2] = saveword;
    }
    else
    {
      n = mem[t].hh.lh;
      ss = mem[pp + 1].hh.lh;
      do {
        rr = ss;
        ss = mem[ss].hh.rh;
      } while (!(n <= mem[ss + 2].hh.lh));
      if (n < mem[ss + 2].hh.lh)
      {
        qq = get_node (3);
        mem[rr].hh.rh = qq;
        mem[qq].hh.rh = ss;
        mem[qq + 2].hh.lh = n;
        mem[qq].hh.b1 = 4;
        mem[qq].hh.b0 = 0;
        mem[qq + 2].hh.rh = pp;
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
        s = mem[p + 1].hh.lh;
        do {
          r = s;
          s = mem[s].hh.rh;
        } while (!(n <= mem[s + 2].hh.lh));
        if (n == mem[s + 2].hh.lh)
          p = s;
        else
        {
          q = get_node (3);
          mem[r].hh.rh = q;
          mem[q].hh.rh = s;
          mem[q + 2].hh.lh = n;
          mem[q].hh.b1 = 4;
          mem[q].hh.b0 = 0;
          mem[q + 2].hh.rh = p;
          p = q;
        }
      }
    }
    t = mem[t].hh.rh;
  }
  if (mem[pp].hh.b0 >= 21)
  {
    if (mem[pp].hh.b0 == 21)
      pp = mem[pp + 1].hh.lh;
    else
    {
      Result = 0;
      goto lab_exit;
    }
  }
  if (mem[p].hh.b0 == 21)
    p = mem[p + 1].hh.lh;
  if (mem[p].hh.b0 == 0)
  {
    if (mem[pp].hh.b0 == 0)
    {
      mem[pp].hh.b0 = 15;
      mem[pp + 1].cint = 0;
    }
    mem[p].hh.b0 = mem[pp].hh.b0;
    mem[p + 1].cint = 0;
  }
  Result = p;
  lab_exit:;
  return Result;
}
/* 257 */
void print_path (halfword h, str_number s, boolean nuline)
{
  halfword p, q;

  print_diagnostic(517, s, nuline);
  print_ln ();
  p = h;
  do {
    q = mem[p].hh.rh;
    if ((p == 0) || (q == 0))
    {
      print_nl(259);
      goto done;
    }
    print_two (mem[p + 1].cint, mem[p + 2].cint);
    switch (mem[p].hh.b1)
    {
      case 0:
        {
          if (mem[p].hh.b0 == 4)
            print(518);
          if ((mem[q].hh.b0 != 0) || (q != h))
            q = 0;
          goto done1;
        }
        break;
      case 1:
        {
          print(524);
          print_two (mem[p + 5].cint, mem[p + 6].cint);
          print(523);
          if (mem[q].hh.b0 != 1)
            print(525);
          else
            print_two (mem[q + 3].cint, mem[q + 4].cint);
          goto done1;
        }
        break;
      case 4:
        if ((mem[p].hh.b0 != 1) && (mem[p].hh.b0 != 4))
          print(518);
        break;
      case 3:
      case 2:
        {
          if (mem[p].hh.b0 == 4)
            print(525);
          if (mem[p].hh.b1 == 3)
          {
            print(521);
            print_scaled(mem[p + 5].cint);
          }
          else
          {
            n_sin_cos(mem[p + 5].cint);
            print_char(123);
            print_scaled(n_cos);
            print_char(44);
            print_scaled(n_sin);
          }
          print_char(125);
        }
        break;
      default:
        print(259);
        break;
    }
    if (mem[q].hh.b0 <= 1)
      print(519);
    else if ((mem[p + 6].cint != 65536L) || (mem[q + 4].cint != 65536L))
    {
      print(522);
      if (mem[p + 6].cint < 0)
        print(464);
      print_scaled(abs (mem[p + 6].cint));
      if (mem[p + 6].cint != mem[q + 4].cint)
      {
        print(523);
        if (mem[q + 4].cint < 0)
          print(464);
        print_scaled(abs (mem[q + 4].cint));
      }
    }
    done1:;
    p = q;
    if ((p != h) || (mem[h].hh.b0 != 0))
    {
      print_nl(520);
      if (mem[p].hh.b0 == 2)
      {
        n_sin_cos(mem[p + 3].cint);
        print_char(123);
        print_scaled(n_cos);
        print_char(44);
        print_scaled(n_sin);
        print_char(125);
      }
      else if (mem[p].hh.b0 == 3)
      {
        print(521);
        print_scaled(mem[p + 3].cint);
        print_char(125);
      }
    }
  } while (!(p == h));
  if (mem[h].hh.b0 != 0)
    print(385);
  done: end_diagnostic (true);
}
/* 333 */
void print_weight (halfword q, integer xoff)
{
  integer w, m;
  integer d;

  d = mem[q].hh.lh;
  w = d % 8;
  m = (d / 8) - mem[cur_edges + 3].hh.lh;
  if (file_offset > max_print_line - 9)
    print_nl(32);
  else
    print_char(32);
  print_int (m + xoff);
  while (w > 4)
  {
    print_char(43);
    decr (w);
  }
  while (w < 4)
  {
    print_char(45);
    incr (w);
  }
}
/* 332 */
void print_edges (str_number s, boolean nuline, integer xoff, integer yoff)
{
  halfword p, q, r;
  integer n;

  print_diagnostic(532, s, nuline);
  p = mem[cur_edges].hh.lh;
  n = mem[cur_edges + 1].hh.rh - 4096;
  while (p != cur_edges)
  {
    q = mem[p + 1].hh.lh;
    r = mem[p + 1].hh.rh;
    if ((q > 1) || (r != mem_top))
    {
      print_nl(533);
      print_int (n + yoff);
      print_char(58);
      while (q > 1)
      {
        print_weight (q, xoff);
        q = mem[q].hh.rh;
      }
      print(534);
      while (r != mem_top)
      {
        print_weight (r, xoff);
        r = mem[r].hh.rh;
      }
    }
    p = mem[p].hh.lh;
    decr (n);
  }
  end_diagnostic (true);
}
/* 388 */
void unskew (scaled x, scaled y, small_number octant)
{
  switch (octant)
  {
    case 1:
      {
        cur_x = x + y;
        cur_y = y;
      }
      break;
    case 5:
      {
        cur_x = y;
        cur_y = x + y;
      }
      break;
    case 6:
      {
        cur_x = -y;
        cur_y = x + y;
      }
      break;
    case 2:
      {
        cur_x = -x - y;
        cur_y = y;
      }
      break;
    case 4:
      {
        cur_x = -x - y;
        cur_y = -y;
      }
      break;
    case 8:
      {
        cur_x = -y;
        cur_y = -x - y;
      }
      break;
    case 7:
      {
        cur_x = y;
        cur_y = -x - y;
      }
      break;
    case 3:
      {
        cur_x = x + y;
        cur_y = -y;
      }
      break;
  }
}
/* 473 */
void print_pen (halfword p, str_number s, boolean nuline)
{
  boolean nothingprinted;
  unsigned char k;
  halfword h;
  integer m, n;
  halfword w, ww;

  print_diagnostic(569, s, nuline);
  nothingprinted = true;
  print_ln ();
  {integer for_end; k = 1;for_end = 8; if (k <= for_end) do
    {
      octant = octant_code[k];
      h = p + octant;
      n = mem[h].hh.lh;
      w = mem[h].hh.rh;
      if (!odd (k))
        w = mem[w].hh.lh;
      {integer for_end; m = 1;for_end = n + 1; if (m <= for_end)
      do
        {
          if (odd (k))
            ww = mem[w].hh.rh;
          else
            ww = mem[w].hh.lh;
          if ((mem[ww + 1].cint != mem[w + 1].cint) || (mem[ww + 2].cint != mem[w + 2].cint))
          {
            if (nothingprinted)
              nothingprinted = false;
            else
              print_nl(571);
            unskew (mem[ww + 1].cint, mem[ww + 2].cint, octant);
            print_two (cur_x, cur_y);
          }
          w = ww;
        }
      while (m++ < for_end);}
    }
  while (k++ < for_end);}
  if (nothingprinted)
  {
    w = mem[p + 1].hh.rh;
    print_two (mem[w + 1].cint + mem[w + 2].cint, mem[w + 2].cint);
  }
  print_nl(570);
  end_diagnostic (true);
}
/* 589 */
void print_dependency (halfword p, small_number t)
{
  integer v;
  halfword pp, q;

  pp = p;
  while (true)
  {
    v = abs (mem[p + 1].cint);
    q = mem[p].hh.lh;
    if (q == 0)
    {
      if ((v != 0) || (p == pp))
      {
        if (mem[p + 1].cint > 0)
        {
          if (p != pp)
            print_char(43);
        }
        print_scaled(mem[p + 1].cint);
      }
      goto lab_exit;
    }
    if (mem[p + 1].cint < 0)
      print_char(45);
    else if (p != pp)
      print_char(43);
    if (t == 17)
      v = round_fraction (v);
    if (v != 65536L)
      print_scaled(v);
    if (mem[q].hh.b0 != 19)
      confusion(589);
    print_variable_name(q);
    v = mem[q + 1].cint % 64;
    while (v > 0)
    {
      print(590);
      v = v - 2;
    }
    p = mem[p].hh.rh;
  }
  lab_exit:;
}
/* 805 */
void print_dp (small_number t, halfword p, small_number verbosity)
{
  halfword q;

  q = mem[p].hh.rh;
  if ((mem[q].hh.lh == 0) || (verbosity > 0))
    print_dependency(p, t);
  else
    print(764);
}
/* 799 */
halfword stash_cur_exp (void)
{
  halfword Result;
  halfword p;

  switch (cur_type)
  {
    case 3:
    case 5:
    case 7:
    case 12:
    case 10:
    case 13:
    case 14:
    case 17:
    case 18:
    case 19:
      p = cur_exp;
      break;
    default:
      {
        p = get_node (2);
        mem[p].hh.b1 = 11;
        mem[p].hh.b0 = cur_type;
        mem[p + 1].cint = cur_exp;
      }
      break;
  }
  cur_type = 1;
  mem[p].hh.rh = 1;
  Result = p;
  return Result;
}
/* 800 */
void unstash_cur_exp (halfword p)
{
  cur_type = mem[p].hh.b0;
  switch (cur_type)
  {
    case 3:
    case 5:
    case 7:
    case 12:
    case 10:
    case 13:
    case 14:
    case 17:
    case 18:
    case 19:
      cur_exp = p;
      break;
    default:
      {
        cur_exp = mem[p + 1].cint;
        free_node (p, 2);
      }
      break;
  }
}
/* 801 */
void print_exp (halfword p, small_number verbosity)
{
  boolean restorecur_exp;
  small_number t;
  integer v;
  halfword q;
  
  if (p != 0)
    restorecur_exp = false;
  else
  {
    p = stash_cur_exp ();
    restorecur_exp = true;
  }
  t = mem[p].hh.b0;
  if (t < 17)
    v = mem[p + 1].cint;
  else if (t < 19)
    v = mem[p + 1].hh.rh;
  switch (t)
  {
    case 1:
      print(323);
      break;
    case 2:
      if (v == 30)
        print(347);
      else
        print(348);
      break;
    case 3:
    case 5:
    case 7:
    case 12:
    case 10:
    case 15:
      {
        print_type (t);
        if (v != 0)
        {
          print_char(32);
          while ((mem[v].hh.b1 == 11) && (v != p))
            v = mem[v + 1].cint;
          print_variable_name(v);
        }
      }
      break;
    case 4:
      {
        print_char(34);
        slow_print(v);
        print_char(34);
      }
      break;
    case 6:
    case 8:
    case 9:
    case 11:
      if (verbosity <= 1)
        print_type (t);
      else
      {
        if (selector == 3)
        {
          if (internal[13]<= 0)
          {
            selector = 1;
            print_type (t);
            print(762);
            selector = 3;
          }
        }
        switch (t)
        {
          case 6:
            print_pen (v, 261, false);
            break;
          case 8:
            print_path (v, 763, false);
            break;
          case 9:
            print_path (v, 261, false);
            break;
          case 11:
            {
              cur_edges = v;
              print_edges (261, false, 0, 0);
            }
            break;
        }
      }
      break;
    case 13:
    case 14:
      if (v == 0)
        print_type (t);
      else
      {
        print_char(40);
        q = v + big_node_size[t];
        do {
          if (mem[v].hh.b0 == 16)
            print_scaled(mem[v + 1].cint);
          else if (mem[v].hh.b0 == 19)
            print_variable_name(v);
          else
            print_dp (mem[v].hh.b0, mem[v + 1].hh.rh, verbosity);
          v = v + 2;
          if (v != q)
            print_char(44);
        } while (!(v == q));
        print_char(41);
      }
      break;
    case 16:
      print_scaled(v);
      break;
    case 17:
    case 18:
      print_dp (t, v, verbosity);
      break;
    case 19:
      print_variable_name(p);
      break;
      default:
      confusion(761);
      break;
  }
  if (restorecur_exp)
    unstash_cur_exp (p);
}
/* 807 */
void disp_err (halfword p, str_number s)
{
  if (interaction == 3)
    ;
  print_nl(765);
  print_exp (p, 1);
  if (s != 261)
  {
    print_nl(263);
    print(s);
  }
}
/* 594 */
halfword p_plus_fq (halfword p, integer f, halfword q, small_number t, small_number tt)
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
  while (true)
    if (pp == qq)
    {
      if (pp == 0)
        goto done;
      else
      {
        if (tt == 17)
          v = mem[p + 1].cint + take_fraction (f, mem[q + 1].cint);
        else
          v = mem[p + 1].cint + take_scaled (f, mem[q + 1].cint);
        mem[p + 1].cint = v;
        s = p;
        p = mem[p].hh.rh;
        if (abs (v) < threshold)
          free_node (s, 2);
        else
        {
          if (abs (v) >= 626349397L)
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
        pp = mem[p].hh.lh;
        q = mem[q].hh.rh;
        qq = mem[q].hh.lh;
      }
    }
    else if (mem[pp + 1].cint < mem[qq + 1].cint)
    {
      if (tt == 17)
        v = take_fraction (f, mem[q + 1].cint);
      else
        v = take_scaled (f, mem[q + 1].cint);
      if (abs (v) > half (threshold))
      {
        s = get_node (2);
        mem[s].hh.lh = qq;
        mem[s + 1].cint = v;
        if (abs (v) >= 626349397L)
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
    else
    {
      mem[r].hh.rh = p;
      r = p;
      p = mem[p].hh.rh;
      pp = mem[p].hh.lh;
    }
done:
  if (t == 17)
    mem[p + 1].cint = slow_add (mem[p + 1].cint, take_fraction (mem[q + 1].cint, f));
  else
    mem[p + 1].cint = slow_add (mem[p + 1].cint, take_scaled (mem[q + 1].cint, f));
  mem[r].hh.rh = p;
  dep_final = p;
  Result = mem[mem_top - 1].hh.rh;
  return Result;
}
/* 600 */
halfword p_over_v (halfword p, scaled v, small_number t0, small_number t1)
{
  halfword Result;
  halfword r, s;
  integer w;
  integer threshold;
  boolean scalingdown;
  
  if (t0 != t1)
    scalingdown = true;
  else
    scalingdown = false;
  if (t1 == 17)
    threshold = 1342;
  else
    threshold = 4;
  r = mem_top - 1;
  while (mem[p].hh.lh != 0)
  {
    if (scalingdown)
    {
      if (abs (v) < 524288L)
        w = make_scaled (mem[p + 1].cint, v * 4096);
      else
        w = make_scaled (round_fraction (mem[p + 1].cint), v);
    }
    else
      w = make_scaled (mem[p + 1].cint, v);
    if (abs (w) <= threshold)
    {
      s = mem[p].hh.rh;
      free_node (p, 2);
      p = s;
    }
    else
    {
      if (abs (w) >= 626349397L)
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
  mem[p + 1].cint = make_scaled (mem[p + 1].cint, v);
  Result = mem[mem_top - 1].hh.rh;
  return Result;
}
/* 602 */
void val_too_big (scaled x)
{
  if (internal[40] > 0)
  {
    print_err("Value is too large (");
    print_scaled(x);
    print_char(41);
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
/* 603 */
void make_known (halfword p, halfword q)
{
  unsigned char t;

  mem[mem[q].hh.rh + 1].hh.lh = mem[p + 1].hh.lh;
  mem[mem[p + 1].hh.lh].hh.rh = mem[q].hh.rh;
  t = mem[p].hh.b0;
  mem[p].hh.b0 = 16;
  mem[p + 1].cint = mem[q + 1].cint;
  free_node (q, 2);
  if (abs (mem[p + 1].cint) >= 268435456L)
    val_too_big (mem[p + 1].cint);
  if (internal[2] > 0)
  {
    if (interesting (p))
    {
      begin_diagnostic ();
      print_nl(596);
      print_variable_name(p);
      print_char(61);
      print_scaled(mem[p + 1].cint);
      end_diagnostic (false);
    }
  }
  if (cur_exp == p)
  {
    if (cur_type == t)
    {
      cur_type = 16;
      cur_exp = mem[p + 1].cint;
      free_node (p, 2);
    }
  }
}
/* 604 */
void fix_dependencies (void)
{
  halfword p, q, r, s, t;
  halfword x;

  r = mem[13].hh.rh;
  s = 0;
  while (r != 13)
  {
    t = r;
    r = t + 1;
    while (true)
    {
      q = mem[r].hh.rh;
      x = mem[q].hh.lh;
      if (x == 0)
        goto done;
      if (mem[x].hh.b0 <= 1)
      {
        if (mem[x].hh.b0 < 1)
        {
          p = get_avail ();
          mem[p].hh.rh = s;
          s = p;
          mem[s].hh.lh = x;
          mem[x].hh.b0 = 1;
        }
        mem[q + 1].cint = mem[q + 1].cint / 4;
        if (mem[q + 1].cint == 0)
        {
          mem[r].hh.rh = mem[q].hh.rh;
          free_node (q, 2);
          q = r;
        }
      }
      r = q;
    }
done:;
    r = mem[q].hh.rh;
    if (q == mem[t + 1].hh.rh)
      make_known (t, q);
  }
  while (s != 0)
  {
    p = mem[s].hh.rh;
    x = mem[s].hh.lh;
    {
      mem[s].hh.rh = avail;
      avail = s;
      ;
#ifdef STAT
      decr (dyn_used);
#endif /* STAT */
    }
    s = p;
    mem[x].hh.b0 = 19;
    mem[x + 1].cint = mem[x + 1].cint + 2;
  }
  fix_needed = false;
}
/* 268 */
void toss_knot_list (halfword p)
{
  halfword q;
  halfword r;

  q = p;
  do {
    r = mem[q].hh.rh;
    free_node (q, 7);
    q = r;
  } while (!(q == p));
}
/* 385 */
void toss_edges (halfword h)
{
  halfword p, q;

  q = mem[h].hh.rh;
  while (q != h)
  {
    flush_list (mem[q + 1].hh.rh);
    if (mem[q + 1].hh.lh > 1)
      flush_list (mem[q + 1].hh.lh);
    p = q;
    q = mem[q].hh.rh;
    free_node (p, 2);
  }
  free_node (h, 6);
}
/* 487 */
void toss_pen (halfword p)
{
  unsigned char k;
  halfword w, ww;

  if (p != 3)
  {
    {integer for_end; k = 1;for_end = 8; if (k <= for_end) do
      {
        w = mem[p + k].hh.rh;
        do {
            ww = mem[w].hh.rh;
          free_node (w, 3);
          w = ww;
        } while (!(w == mem[p + k].hh.rh));
      }
    while (k++ < for_end);}
    free_node (p, 10);
  }
}
/* 620 */
void ring_delete (halfword p)
{
  halfword q;

  q = mem[p + 1].cint;
  if (q != 0)
  {
    if (q != p)
    {
      while (mem[q + 1].cint != p)
        q = mem[q + 1].cint;
      mem[q + 1].cint = mem[p + 1].cint;
    }
  }
}
/* 809 */
void recycle_value (halfword p)
{
  small_number t;
  integer v;
  integer vv;
  halfword q, r, s, pp;

  t = mem[p].hh.b0;
  if (t < 17)
    v = mem[p + 1].cint;
  switch (t)
  {
    case 0:
    case 1:
    case 2:
    case 16:
    case 15:
      ;
      break;
    case 3:
    case 5:
    case 7:
    case 12:
    case 10:
      ring_delete (p);
      break;
    case 4:
      {
        if (str_ref[v]< 127)
        {
          if (str_ref[v] > 1)
            decr (str_ref[v]);
          else
            flush_string (v);
        }
      }
      break;
    case 6:
      if (mem[v].hh.lh == 0)
        toss_pen (v);
      else
        decr (mem[v].hh.lh);
      break;
    case 9:
    case 8:
      toss_knot_list (v);
      break;
    case 11:
      toss_edges (v);
      break;
    case 14:
    case 13:
      if (v != 0)
      {
        q = v + big_node_size[t];
        do {
          q = q - 2;
          recycle_value (q);
        } while (!(q == v));
        free_node (v, big_node_size[t]);
      }
      break;
    case 17:
    case 18:
      {
        q = mem[p + 1].hh.rh;
        while (mem[q].hh.lh != 0)
          q = mem[q].hh.rh;
        mem[mem[p + 1].hh.lh].hh.rh = mem[q].hh.rh;
        mem[mem[q].hh.rh + 1].hh.lh = mem[p + 1].hh.lh;
        mem[q].hh.rh = 0;
        flush_node_list (mem[p + 1].hh.rh);
      }
      break;
    case 19:
      {
        max_c[17] = 0;
        max_c[18] = 0;
        max_link[17] = 0;
        max_link[18] = 0;
        q = mem[13].hh.rh;
        while (q != 13)
        {
          s = q + 1;
          while (true)
          {
            r = mem[s].hh.rh;
            if (mem[r].hh.lh == 0)
              goto done;
            if (mem[r].hh.lh != p)
              s = r;
            else
            {
              t = mem[q].hh.b0;
              mem[s].hh.rh = mem[r].hh.rh;
              mem[r].hh.lh = q;
              if (abs (mem[r + 1].cint) > max_c[t])
              {
                if (max_c[t] > 0)
                {
                  mem[max_ptr[t]].hh.rh = max_link[t];
                  max_link[t] = max_ptr[t];
                }
                max_c[t] = abs (mem[r + 1].cint);
                max_ptr[t] = r;
              }
              else
              {
                mem[r].hh.rh = max_link[t];
                max_link[t] = r;
              }
            }
          }
          done: q = mem[r].hh.rh;
        }
        if ((max_c[17] > 0) || (max_c[18] > 0))
        {
          if ((max_c[17]/ 4096 >= max_c[18]))
            t = 17;
          else
            t = 18;
          s = max_ptr[t];
          pp = mem[s].hh.lh;
          v = mem[s + 1].cint;
          if (t == 17)
            mem[s + 1].cint = -268435456L;
          else
            mem[s + 1].cint = -65536L;
          r = mem[pp + 1].hh.rh;
          mem[s].hh.rh = r;
          while (mem[r].hh.lh != 0) r = mem[r].hh.rh;
          q = mem[r].hh.rh;
          mem[r].hh.rh = 0;
          mem[q + 1].hh.lh = mem[pp + 1].hh.lh;
          mem[mem[pp + 1].hh.lh].hh.rh = q;
          {
            if (serial_no > 2147483583L)
              overflow (588, serial_no / 64);
            mem[pp].hh.b0 = 19;
            serial_no = serial_no + 64;
            mem[pp + 1].cint = serial_no;
          }
          if (cur_exp == pp)
          {
            if (cur_type == t)
              cur_type = 19;
          }
          if (internal[2] > 0)
          {
            if (interesting (p))
            {
              begin_diagnostic ();
              print_nl(767);
              if (v > 0)
                print_char(45);
              if (t == 17)
                vv = round_fraction (max_c[17]);
              else
                vv = max_c[18];
              if (vv != 65536L)
                print_scaled(vv);
              print_variable_name(p);
              while (mem[p + 1].cint % 64 > 0)
              {
                print(590);
                mem[p + 1].cint = mem[p + 1].cint - 2;
              }
              if (t == 17)
                print_char(61);
              else
                print(768);
              print_dependency(s, t);
              end_diagnostic (false);
            }
          }
          t = 35 - t;
          if (max_c[t] > 0)
          {
            mem[max_ptr[t]].hh.rh = max_link[t];
            max_link[t] = max_ptr[t];
          }
          if (t != 17)
          {
            integer for_end; t = 17;for_end = 18; if (t <= for_end)
            do {
              r = max_link[t];
              while (r != 0)
              {
                q = mem[r].hh.lh;
                mem[q + 1].hh.rh = p_plus_fq (mem[q + 1].hh.rh, make_fraction (mem[r + 1].cint, -v), s, t, 17);
                if (mem[q + 1].hh.rh == dep_final)
                  make_known (q, dep_final);
                q = r;
                r = mem[r].hh.rh;
                free_node (q, 2);
              }
            } while (t++ < for_end);
          }
          else
          {
            integer for_end; t = 17;for_end = 18; if (t <= for_end)
              do {
                r = max_link[t];
                while (r != 0)
                {
                  q = mem[r].hh.lh;
                  if (t == 17)
                  {
                    if (cur_exp == q)
                    {
                      if (cur_type == 17)
                        cur_type = 18;
                    }
                    mem[q + 1].hh.rh = p_over_v (mem[q + 1].hh.rh, 65536L, 17, 18);
                    mem[q].hh.b0 = 18;
                    mem[r + 1].cint = round_fraction (mem[r + 1].cint);
                  }
                  mem[q + 1].hh.rh = p_plus_fq (mem[q + 1].hh.rh, make_scaled (mem[r + 1].cint, -v), s , 18, 18);
                  if (mem[q + 1].hh.rh == dep_final)
                    make_known (q, dep_final);
                  q = r;
                  r = mem[r].hh.rh;
                  free_node (q, 2);
                }
            } while (t++ < for_end);
          }
          flush_node_list (s);
          if (fix_needed)
            fix_dependencies ();
          check_arith ();
        }
      }
      break;
    case 20:
    case 21:
      confusion(766);
      break;
    case 22:
    case 23:
      delete_mac_ref (mem[p + 1].cint);
      break;
  }
  mem[p].hh.b0 = 0;
}
/* 808 */
void flush_cur_exp (scaled v)
{
  switch (cur_type)
  {
    case 3:
    case 5:
    case 7:
    case 12:
    case 10:
    case 13:
    case 14:
    case 17:
    case 18:
    case 19:
      {
        recycle_value (cur_exp);
        free_node (cur_exp, 2);
      }
      break;
    case 6:
      if (mem[cur_exp].hh.lh == 0)
        toss_pen (cur_exp);
      else
        decr (mem[cur_exp].hh.lh);
      break;
    case 4:
      {
        if (str_ref[cur_exp]< 127)
        {
          if (str_ref[cur_exp] > 1)
            decr (str_ref[cur_exp]);
          else
            flush_string (cur_exp);
        }
      }
      break;
    case 8:
    case 9:
      toss_knot_list (cur_exp);
      break;
    case 11:
      toss_edges (cur_exp);
      break;
    default:
      ;
      break;
  }
  cur_type = 16;
  cur_exp = v;
}
/* 820 */
void flush_error (scaled v)
{
  error ();
  flush_cur_exp (v);
}
/* 820 */
void put_get_error (void)
{
  back_error ();
  get_x_next ();
}
/* 820 */
void put_get_flush_error (scaled v)
{
  put_get_error ();
  flush_cur_exp (v);
}
/* 247 */
void flush_below_variable (halfword p)
{
  halfword q, r;

  if (mem[p].hh.b0 != 21)
    recycle_value (p);
  else
  {
    q = mem[p + 1].hh.rh;
    while (mem[q].hh.b1 == 3)
    {
      flush_below_variable (q);
      r = q;
      q = mem[q].hh.rh;
      free_node (r, 3);
    }
    r = mem[p + 1].hh.lh;
    q = mem[r].hh.rh;
    recycle_value (r);
    if (mem[p].hh.b1 <= 1)
      free_node (r, 2);
    else
      free_node (r, 3);
    do {
      flush_below_variable (q);
      r = q;
      q = mem[q].hh.rh;
      free_node (r, 3);
    } while (!(q == 17));
    mem[p].hh.b0 = 0;
  }
}
/* 246 */
void flush_variable (halfword p, halfword t, boolean discardsuffixes)
{
  halfword q, r;
  halfword n;

  while (t != 0)
  {
    if (mem[p].hh.b0 != 21)
      goto lab_exit;
    n = mem[t].hh.lh;
    t = mem[t].hh.rh;
    if (n == 0)
    {
      r = p + 1;
      q = mem[r].hh.rh;
      while (mem[q].hh.b1 == 3)
      {
        flush_variable (q, t, discardsuffixes);
        if (t == 0)
        {
          if (mem[q].hh.b0 == 21)
            r = q;
          else
          {
            mem[r].hh.rh = mem[q].hh.rh;
            free_node (q, 3);
          }
        }
        else
          r = q;
        q = mem[r].hh.rh;
      }
    }
    p = mem[p + 1].hh.lh;
    do {
      r = p;
      p = mem[p].hh.rh;
    } while (!(mem[p + 2].hh.lh >= n));
    if (mem[p + 2].hh.lh != n)
      goto lab_exit;
  }
  if (discardsuffixes)
    flush_below_variable (p);
  else
  {
    if (mem[p].hh.b0 == 21)
      p = mem[p + 1].hh.lh;
    recycle_value (p);
  }
  lab_exit:;
}
/* 248 */
small_number und_type (halfword p)
{
  small_number Result;
  switch (mem[p].hh.b0)
  {
    case 0:
    case 1:
      Result = 0;
      break;
    case 2:
    case 3:
      Result = 3;
      break;
    case 4:
    case 5:
      Result = 5;
      break;
    case 6:
    case 7:
    case 8:
      Result = 7;
      break;
    case 9:
    case 10:
      Result = 10;
      break;
    case 11:
    case 12:
      Result = 12;
      break;
    case 13:
    case 14:
    case 15:
      Result = mem[p].hh.b0;
      break;
    case 16:
    case 17:
    case 18:
    case 19:
      Result = 15;
      break;
  }
  return Result;
}
/* 249 */
void clear_symbol (halfword p, boolean saving)
{
  halfword q;

  q = eqtb[p].v.RH;
  switch (eqtb[p].lh % 86)
  {
    case 10:
    case 53:
    case 44:
    case 49:
      if (!saving)
        delete_mac_ref (q);
      break;
    case 41:
      if (q != 0)
      {
        if (saving)
          mem[q].hh.b1 = 1;
        else
        {
          flush_below_variable (q);
          free_node (q, 2);
        }
      }
      break;
    default:
      ;
      break;
  }
  eqtb[p] = eqtb[9769];
}
/* 252 */
void save_variable (halfword q)
{
  halfword p;

  if (save_ptr != 0)
  {
    p = get_node (2);
    mem[p].hh.lh = q;
    mem[p].hh.rh = save_ptr;
    mem[p + 1].hh = eqtb[q];
    save_ptr = p;
  }
  clear_symbol (q, (save_ptr != 0));
}
/* 253 */
void save_internal (halfword q)
{
  halfword p;

  if (save_ptr != 0)
  {
    p = get_node (2);
    mem[p].hh.lh = 9769 + q;
    mem[p].hh.rh = save_ptr;
    mem[p + 1].cint = internal[q];
    save_ptr = p;
  }
}
/* 254 */
void unsave (void)
{
  halfword q;
  halfword p;

  while (mem[save_ptr].hh.lh != 0)
  {
    q = mem[save_ptr].hh.lh;
    if (q > 9769)
    {
      if (internal[8] > 0)
      {
        begin_diagnostic ();
        print_nl(516);
        slow_print(int_name[q - (9769)]);
        print_char(61);
        print_scaled(mem[save_ptr + 1].cint);
        print_char(125);
        end_diagnostic (false);
      }
      internal[q - (9769)] = mem[save_ptr + 1].cint;
    }
    else
    {
      if (internal[8] > 0)
      {
        begin_diagnostic ();
        print_nl(516);
        slow_print(hash[q].v.RH);
        print_char(125);
        end_diagnostic (false);
      }
      clear_symbol (q, false);
      eqtb[q] = mem[save_ptr + 1].hh;
      if (eqtb[q].lh % 86 == 41)
      {
        p = eqtb[q].v.RH;
        if (p != 0)
        mem[p].hh.b1 = 0;
      }
    }
    p = mem[save_ptr].hh.rh;
    free_node (save_ptr, 2);
    save_ptr = p;
  }
  p = mem[save_ptr].hh.rh;
  {
    mem[save_ptr].hh.rh = avail;
    avail = save_ptr;
    ;
#ifdef STAT
    decr (dyn_used);
#endif /* STAT */
  }
  save_ptr = p;
}
/* 264 */
halfword copy_knot (halfword p)
{
  halfword Result;
  halfword q;
  unsigned char k;

  q = get_node (7);
  {integer for_end; k = 0;for_end = 6; if (k <= for_end)
    do
      mem[q + k] = mem[p + k];
    while (k++ < for_end);
  }
  Result = q;
  return Result;
}
/* 265 */
halfword copy_path (halfword p)
{
  halfword Result;
  halfword q, pp, qq;

  q = get_node (7);
  qq = q;
  pp = p;
  while (true)
  {
    mem[qq].hh.b0 = mem[pp].hh.b0;
    mem[qq].hh.b1 = mem[pp].hh.b1;
    mem[qq + 1].cint = mem[pp + 1].cint;
    mem[qq + 2].cint = mem[pp + 2].cint;
    mem[qq + 3].cint = mem[pp + 3].cint;
    mem[qq + 4].cint = mem[pp + 4].cint;
    mem[qq + 5].cint = mem[pp + 5].cint;
    mem[qq + 6].cint = mem[pp + 6].cint;
    if (mem[pp].hh.rh == p)
    {
      mem[qq].hh.rh = q;
      Result = q;
      goto lab_exit;
    }
    mem[qq].hh.rh = get_node (7);
    qq = mem[qq].hh.rh;
    pp = mem[pp].hh.rh;
  }
  lab_exit:;
  return Result;
}
/* 266 */
halfword htap_ypoc (halfword p)
{
  halfword Result;
  halfword q, pp, qq, rr;

  q = get_node (7);
  qq = q;
  pp = p;
  while (true)
  {
    mem[qq].hh.b1 = mem[pp].hh.b0;
    mem[qq].hh.b0 = mem[pp].hh.b1;
    mem[qq + 1].cint = mem[pp + 1].cint;
    mem[qq + 2].cint = mem[pp + 2].cint;
    mem[qq + 5].cint = mem[pp + 3].cint;
    mem[qq + 6].cint = mem[pp + 4].cint;
    mem[qq + 3].cint = mem[pp + 5].cint;
    mem[qq + 4].cint = mem[pp + 6].cint;
    if (mem[pp].hh.rh == p)
    {
      mem[q].hh.rh = qq;
      path_tail = pp;
      Result = q;
      goto lab_exit;
    }
    rr = get_node (7);
    mem[rr].hh.rh = qq;
    qq = rr;
    pp = mem[pp].hh.rh;
  }
  lab_exit:;
  return Result;
}
/* 296 */
fraction curl_ratio (scaled gamma, scaled atension, scaled btension)
{
  fraction Result;
  fraction alpha, beta, num, denom, ff;

  alpha = make_fraction (65536L, atension);
  beta = make_fraction (65536L, btension);
  if (alpha <= beta)
  {
    ff = make_fraction (alpha, beta);
    ff = take_fraction (ff, ff);
    gamma = take_fraction (gamma, ff);
    beta = beta / 4096;
    denom = take_fraction (gamma, alpha) + 196608L - beta;
    num = take_fraction (gamma, 805306368L - alpha) + beta;
  }
  else
  {
    ff = make_fraction (beta, alpha);
    ff = take_fraction (ff, ff);
    beta = take_fraction (beta, ff) / 4096;
    denom = take_fraction (gamma, alpha) + (ff / 1365) - beta;
    num = take_fraction (gamma, 805306368L - alpha) + beta;
  }
  if (num >= denom + denom + denom + denom)
    Result = 1073741824L;
  else
    Result = make_fraction (num, denom);
  return Result;
}
/* 299 */
void set_controls (halfword p, halfword q, integer k)
{
  fraction rr, ss;
  scaled lt, rt;
  fraction sine;

  lt = abs (mem[q + 4].cint);
  rt = abs (mem[p + 6].cint);
  rr = velocity (st, ct, sf, cf, rt);
  ss = velocity (sf, cf, st, ct, lt);
  if ((mem[p + 6].cint < 0) || (mem[q + 4].cint < 0))
  {
    if (((st >= 0) && (sf >= 0)) || ((st <= 0) && (sf <= 0)))
    {
      sine = take_fraction (abs (st), cf) + take_fraction (abs (sf), ct);
      if (sine > 0)
      {
        sine = take_fraction (sine, 268500992L);
        if (mem[p + 6].cint < 0)
        {
          if (ab_vs_cd (abs (sf), 268435456L, rr, sine) < 0)
            rr = make_fraction (abs (sf), sine);
        }
        if (mem[q + 4].cint < 0)
        {
          if (ab_vs_cd (abs (st), 268435456L, ss, sine) < 0)
            ss = make_fraction (abs (st), sine);
        }
      }
    }
  }
  mem[p + 5].cint = mem[p + 1].cint + take_fraction (take_fraction (delta_x[k], ct) - take_fraction (delta_y[k], st), rr);
  mem[p + 6].cint = mem[p + 2].cint + take_fraction (take_fraction (delta_y[k], ct) + take_fraction (delta_x[k], st), rr);
  mem[q + 3].cint = mem[q + 1].cint - take_fraction (take_fraction (delta_x[k], cf) + take_fraction (delta_y[k], sf), ss);
  mem[q + 4].cint = mem[q + 2].cint - take_fraction (take_fraction (delta_y[k], cf) - take_fraction (delta_x[k], sf), ss);
  mem[p].hh.b1 = 1;
  mem[q].hh.b0 = 1;
}
/* 284 */
void solve_choices (halfword p, halfword q, halfword n)
{
  integer k;
  halfword r, s, t;
  fraction aa, bb, cc, ff, acc;
  scaled dd, ee;
  scaled lt, rt;

  k = 0;
  s = p;
  while (true)
  {
    t = mem[s].hh.rh;
    if (k == 0)
      switch (mem[s].hh.b1)
      {
        case 2:
          if (mem[t].hh.b0 == 2)
          {
            aa = n_arg (delta_x[0], delta_y[0]);
            n_sin_cos(mem[p + 5].cint - aa);
            ct = n_cos;
            st = n_sin;
            n_sin_cos(mem[q + 3].cint - aa);
            cf = n_cos;
            sf = -n_sin;
            set_controls (p, q, 0);
            goto lab_exit;
          }
          else
          {
            vv[0] = mem[s + 5].cint - n_arg (delta_x[0], delta_y[0]);
            if (abs (vv[0]) > 188743680L)
            {
              if (vv[0] > 0)
                vv[0] = vv[0] - 377487360L;
              else
                vv[0] = vv[0]+ 377487360L;
            }
            uu[0] = 0;
            ww[0] = 0;
          }
          break;
        case 3:
          if (mem[t].hh.b0 == 3)
          {
            mem[p].hh.b1 = 1;
            mem[q].hh.b0 = 1;
            lt = abs (mem[q + 4].cint);
            rt = abs (mem[p + 6].cint);
            if (rt == 65536L)
            {
              if (delta_x[0] >= 0)
                mem[p + 5].cint = mem[p + 1].cint + ((delta_x[0]+ 1) / 3);
              else
                mem[p + 5].cint = mem[p + 1].cint + ((delta_x[0] - 1) / 3);
              if (delta_y[0] >= 0)
                mem[p + 6].cint = mem[p + 2].cint + ((delta_y[0]+ 1) / 3);
              else
                mem[p + 6].cint = mem[p + 2].cint + ((delta_y[0] - 1) / 3);
            }
            else
            {
              ff = make_fraction (65536L, 3 * rt);
              mem[p + 5].cint = mem[p + 1].cint + take_fraction (delta_x[0], ff);
              mem[p + 6].cint = mem[p + 2].cint + take_fraction (delta_y[0], ff);
            }
            if (lt == 65536L)
            {
              if (delta_x[0] >= 0)
                mem[q + 3].cint = mem[q + 1].cint - ((delta_x[0]+ 1) / 3);
              else
                mem[q + 3].cint = mem[q + 1].cint - ((delta_x[0] - 1) / 3);
              if (delta_y[0] >= 0)
                mem[q + 4].cint = mem[q + 2].cint - ((delta_y[0]+ 1) / 3);
              else
                mem[q + 4].cint = mem[q + 2].cint - ((delta_y[0] - 1) / 3);
            }
            else
            {
              ff = make_fraction (65536L, 3 * lt);
              mem[q + 3].cint = mem[q + 1].cint - take_fraction (delta_x[0], ff);
              mem[q + 4].cint = mem[q + 2].cint - take_fraction (delta_y[0], ff);
            }
            goto lab_exit;
          }
          else
          {
            cc = mem[s + 5].cint;
            lt = abs (mem[t + 4].cint);
            rt = abs (mem[s + 6].cint);
            if ((rt == 65536L) && (lt == 65536L))
              uu[0] = make_fraction (cc + cc + 65536L, cc + 131072L);
            else
              uu[0] = curl_ratio (cc, rt, lt);
            vv[0] = -take_fraction (psi[1], uu[0]);
            ww[0] = 0;
          }
          break;
        case 4:
          {
            uu[0] = 0;
            vv[0] = 0;
            ww[0] = 268435456L;
          }
          break;
    }
    else
      switch (mem[s].hh.b0)
      {
        case 5:
        case 4:
          {
            if (abs (mem[r + 6].cint) == 65536L)
            {
              aa = 134217728L;
              dd = 2 * delta[k];
            }
            else
            {
              aa = make_fraction (65536L, 3 * abs (mem[r + 6].cint) - 65536L);
              dd = take_fraction (delta[k], 805306368L - make_fraction (65536L, abs (mem[r + 6].cint)));
            }
            if (abs (mem[t + 4].cint) == 65536L)
            {
              bb = 134217728L;
              ee = 2 * delta[k - 1];
            }
            else
            {
              bb = make_fraction (65536L, 3 * abs (mem[t + 4].cint) - 65536L);
              ee = take_fraction (delta[k - 1], 805306368L - make_fraction (65536L, abs (mem[t + 4].cint)));
            }
            cc = 268435456L - take_fraction (uu[k - 1], aa);
            dd = take_fraction (dd, cc);
            lt = abs (mem[s + 4].cint);
            rt = abs (mem[s + 6].cint);
            if (lt != rt)
            {
              if (lt < rt)
              {
                ff = make_fraction (lt, rt);
                ff = take_fraction (ff, ff);
                dd = take_fraction (dd, ff);
              }
              else
              {
                ff = make_fraction (rt, lt);
                ff = take_fraction (ff, ff);
                ee = take_fraction (ee, ff);
              }
            }
            ff = make_fraction (ee, ee + dd);
            uu[k] = take_fraction (ff, bb);
            acc = -take_fraction (psi[k + 1], uu[k]);
            if (mem[r].hh.b1 == 3)
            {
              ww[k] = 0;
              vv[k] = acc - take_fraction (psi[1], 268435456L - ff);
            }
            else
            {
              ff = make_fraction (268435456L - ff, cc);
              acc = acc - take_fraction (psi[k], ff);
              ff = take_fraction (ff, aa);
              vv[k] = acc - take_fraction (vv[k - 1], ff);
              if (ww[k - 1] == 0)
                ww[k] = 0;
              else
                ww[k] = -take_fraction (ww[k - 1], ff);
            }
            if (mem[s].hh.b0 == 5)
            {
              aa = 0;
              bb = 268435456L;
              do {
                decr (k);
                if (k == 0)
                  k = n;
                aa = vv[k] - take_fraction (aa, uu[k]);
                bb = ww[k] - take_fraction (bb, uu[k]);
              } while (!(k == n));
              aa = make_fraction (aa, 268435456L - bb);
              theta[n] = aa;
              vv[0] = aa;
              {integer for_end; k = 1;for_end = n - 1; if (k <= for_end)
                do
                  vv[k] = vv[k]+ take_fraction (aa, ww[k]);
                while (k++ < for_end);
              }
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
              ff = make_fraction (cc + cc + 65536L, cc + 131072L);
            else
              ff = curl_ratio (cc, lt, rt);
            theta[n] = -make_fraction (take_fraction (vv[n - 1], ff), 268435456L - take_fraction (ff, uu[n - 1]));
            goto found;
          }
          break;
        case 2:
          {
            theta[n] = mem[s + 3].cint - n_arg (delta_x[n - 1], delta_y[n - 1]);
            if (abs (theta[n]) > 188743680L)
            {
              if (theta[n] > 0)
                theta[n] = theta[n] - 377487360L;
              else
                theta[n] = theta[n]+ 377487360L;
            }
            goto found;
          }
          break;
      }
    r = s;
    s = t;
    incr (k);
  }
found: 
  {
    integer for_end; k = n - 1;for_end = 0; if (k >= for_end)
      do
        theta[k] = vv[k] - take_fraction (theta[k + 1], uu[k]);
      while (k-- > for_end);
  }
  s = p;
  k = 0;
  do {
    t = mem[s].hh.rh;
    n_sin_cos(theta[k]);
    st = n_sin;
    ct = n_cos;
    n_sin_cos(-psi[k + 1] - theta[k + 1]);
    sf = n_sin;
    cf = n_cos;
    set_controls (s, t, k);
    incr (k);
    s = t;
  } while (!(k == n));
  lab_exit:;
}
/* 269 */
void make_choices (halfword knots)
{
  halfword h;
  halfword p, q;
  integer k, n;
  halfword s, t;
  scaled delx, dely;
  fraction sine, cosine;

  check_arith ();
  if (internal[4] > 0)
    print_path (knots, 526, true);
  p = knots;
  do {
    q = mem[p].hh.rh;
    if (mem[p + 1].cint == mem[q + 1].cint)
    {
      if (mem[p + 2].cint == mem[q + 2].cint)
      {
        if (mem[p].hh.b1 > 1)
        {
          mem[p].hh.b1 = 1;
          if (mem[p].hh.b0 == 4)
          {
            mem[p].hh.b0 = 3;
            mem[p + 3].cint = 65536L;
          }
          mem[q].hh.b0 = 1;
          if (mem[q].hh.b1 == 4)
          {
            mem[q].hh.b1 = 3;
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
  while (true)
  {
    if (mem[h].hh.b0 != 4)
      goto done;
    if (mem[h].hh.b1 != 4)
      goto done;
    h = mem[h].hh.rh;
    if (h == knots)
    {
      mem[h].hh.b0 = 5;
      goto done;
    }
  }
  done:;
  p = h;
  do {
    q = mem[p].hh.rh;
    if (mem[p].hh.b1 >= 2)
    {
      while ((mem[q].hh.b0 == 4) && (mem[q].hh.b1 == 4))
        q = mem[q].hh.rh;
      k = 0;
      s = p;
      n = path_size;
      do {
        t = mem[s].hh.rh;
        delta_x[k] = mem[t + 1].cint - mem[s + 1].cint;
        delta_y[k] = mem[t + 2].cint - mem[s + 2].cint;
        delta[k] = pyth_add (delta_x[k], delta_y[k]);
        if (k > 0)
        {
          sine = make_fraction (delta_y[k - 1], delta[k - 1]);
          cosine = make_fraction (delta_x[k - 1], delta[k - 1]);
          psi[k] = n_arg (take_fraction (delta_x[k], cosine) +
          take_fraction (delta_y[k], sine), take_fraction (delta_y[k],
          cosine) - take_fraction (delta_x[k], sine));
        }
        incr (k);
        s = t;
        if (k == path_size)
          overflow (531, path_size);
        if (s == q)
          n = k;
      } while (!((k >= n) && (mem[s].hh.b0 != 5)));
      if (k == n)
        psi[n] = 0;
      else
        psi[k] = psi[1];
      if (mem[q].hh.b0 == 4)
      {
        delx = mem[q + 5].cint - mem[q + 1].cint;
        dely = mem[q + 6].cint - mem[q + 2].cint;
        if ((delx == 0) && (dely == 0))
        {
          mem[q].hh.b0 = 3;
          mem[q + 3].cint = 65536L;
        }
        else
        {
          mem[q].hh.b0 = 2;
          mem[q + 3].cint = n_arg (delx, dely);
        }
      }
      if ((mem[p].hh.b1 == 4) && (mem[p].hh.b0 == 1))
      {
        delx = mem[p + 1].cint - mem[p + 3].cint;
        dely = mem[p + 2].cint - mem[p + 4].cint;
        if ((delx == 0) && (dely == 0))
        {
          mem[p].hh.b1 = 3;
          mem[p + 5].cint = 65536L;
        }
        else
        {
          mem[p].hh.b1 = 2;
          mem[p + 5].cint = n_arg (delx, dely);
        }
      }
      solve_choices (p, q, n);
    }
    p = q;
  } while (!(p == h));
  if (internal[4] > 0)
    print_path (knots, 527, true);
  if (arith_error)
  {
    print_err("Some number got too big");
    {
      help_ptr = 2;
      help_line[1] = 529;
      help_line[0] = 530;
    }
    put_get_error ();
    arith_error = false;
  }
}
/* 311 */
void make_moves (scaled xx0, scaled xx1, scaled xx2, scaled xx3, scaled yy0, scaled yy1, scaled yy2, scaled yy3, small_number xicorr, small_number etacorr)
{
  integer x1, x2, x3, m, r, y1, y2, y3, n, s, l;
  integer q, t, u, x2a, x3a, y2a, y3a;

  if ((xx3 < xx0) || (yy3 < yy0))
    confusion(109);
  l = 16;
  bisect_ptr = 0;
  x1 = xx1 - xx0;
  x2 = xx2 - xx1;
  x3 = xx3 - xx2;
  if (xx0 >= xicorr)
    r = (xx0 - xicorr) % 65536L;
  else
    r = 65535L - ((-xx0 + xicorr - 1) % 65536L);
  m = (xx3 - xx0 + r) / 65536L;
  y1 = yy1 - yy0;
  y2 = yy2 - yy1;
  y3 = yy3 - yy2;
  if (yy0 >= etacorr)
    s = (yy0 - etacorr) % 65536L;
  else
    s = 65535L - ((-yy0 + etacorr - 1) % 65536L);
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
  while (true)
  {
    lab_continue: if (m == 0)
    while (n > 0)
    {
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
      while (l < 30)
      {
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
      if (ab_vs_cd (x1 + x2 + x3, s, y1 + y2 + y3, r) - xicorr >= 0)
      {
        incr (move[move_ptr]);
        incr (move_ptr);
        move[move_ptr] = 1;
      }
      else
      {
        incr (move_ptr);
        move[move_ptr] = 2;
      }
      done:;
    }
    else
    {
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
      goto lab_continue;
    }
    if (bisect_ptr == 0)
      goto lab_exit;
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
  lab_exit:;
}
/* 511 */
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
      if (abs (a - aa) > 1)
      {
        if (a > aa)
        {
          if (aaa >= aa)
          {
            if (a >= move[k + 1])
            {
              incr (move[k - 1]);
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
/* 326 */
void init_edges (halfword h)
{
  mem[h].hh.lh = h;
  mem[h].hh.rh = h;
  mem[h + 1].hh.lh = 8191;
  mem[h + 1].hh.rh = 1;
  mem[h + 2].hh.lh = 8191;
  mem[h + 2].hh.rh = 1;
  mem[h + 3].hh.lh = 4096;
  mem[h + 3].hh.rh = 0;
  mem[h + 4].cint = 0;
  mem[h + 5].hh.rh = h;
  mem[h + 5].hh.lh = 0;
}
/* 328 */
void fix_offset (void)
{
  halfword p, q;
  integer delta;

  delta = 8 * (mem[cur_edges + 3].hh.lh - 4096);
  mem[cur_edges + 3].hh.lh = 4096;
  q = mem[cur_edges].hh.rh;
  while (q != cur_edges)
  {
    p = mem[q + 1].hh.rh;
    while (p != mem_top)
    {
      mem[p].hh.lh = mem[p].hh.lh - delta;
      p = mem[p].hh.rh;
    }
    p = mem[q + 1].hh.lh;
    while (p > 1)
    {
      mem[p].hh.lh = mem[p].hh.lh - delta;
      p = mem[p].hh.rh;
    }
    q = mem[q].hh.rh;
  }
}
/* 329 */
void edge_prep (integer ml, integer mr, integer nl, integer nr)
{
  halfword delta;
  integer temp;
  halfword p, q;

  ml = ml + 4096;
  mr = mr + 4096;
  nl = nl + 4096;
  nr = nr + 4095;
  if (ml < mem[cur_edges + 2].hh.lh)
    mem[cur_edges + 2].hh.lh = ml;
  if (mr > mem[cur_edges + 2].hh.rh)
    mem[cur_edges + 2].hh.rh = mr;
  temp = mem[cur_edges + 3].hh.lh - 4096;
  if (!(abs (mem[cur_edges + 2].hh.lh + temp - 4096) < 4096) || !(abs (mem[cur_edges + 2].hh.rh + temp - 4096) < 4096))
    fix_offset ();
  if (mem[cur_edges].hh.rh == cur_edges)
  {
    mem[cur_edges + 1].hh.lh = nr + 1;
    mem[cur_edges + 1].hh.rh = nr;
  }
  if (nl < mem[cur_edges + 1].hh.lh)
  {
    delta = mem[cur_edges + 1].hh.lh - nl;
    mem[cur_edges + 1].hh.lh = nl;
    p = mem[cur_edges].hh.rh;
    do {
      q = get_node (2);
      mem[q + 1].hh.rh = mem_top;
      mem[q + 1].hh.lh = 1;
      mem[p].hh.lh = q;
      mem[q].hh.rh = p;
      p = q;
      decr (delta);
    } while (!(delta == 0));
    mem[p].hh.lh = cur_edges;
    mem[cur_edges].hh.rh = p;
    if (mem[cur_edges + 5].hh.rh == cur_edges)
      mem[cur_edges + 5].hh.lh = nl - 1;
  }
  if (nr > mem[cur_edges + 1].hh.rh)
  {
    delta = nr - mem[cur_edges + 1].hh.rh;
    mem[cur_edges + 1].hh.rh = nr;
    p = mem[cur_edges].hh.lh;
    do {
      q = get_node (2);
      mem[q + 1].hh.rh = mem_top;
      mem[q + 1].hh.lh = 1;
      mem[p].hh.rh = q;
      mem[q].hh.lh = p;
      p = q;
      decr (delta);
    } while (!(delta == 0));
    mem[p].hh.rh = cur_edges;
    mem[cur_edges].hh.lh = p;
    if (mem[cur_edges + 5].hh.rh == cur_edges)
      mem[cur_edges + 5].hh.lh = nr + 1;
  }
}
/* 334 */
halfword copy_edges (halfword h)
{
  halfword Result;
  halfword p, r;
  halfword hh, pp, qq, rr, ss;

  hh = get_node (6);
  mem[hh + 1] = mem[h + 1];
  mem[hh + 2] = mem[h + 2];
  mem[hh + 3] = mem[h + 3];
  mem[hh + 4] = mem[h + 4];
  mem[hh + 5].hh.lh = mem[hh + 1].hh.rh + 1;
  mem[hh + 5].hh.rh = hh;
  p = mem[h].hh.rh;
  qq = hh;

  while (p != h)
  {
    pp = get_node (2);
    mem[qq].hh.rh = pp;
    mem[pp].hh.lh = qq;
    r = mem[p + 1].hh.rh;
    rr = pp + 1;
    while (r != mem_top)
    {
      ss = get_avail ();
      mem[rr].hh.rh = ss;
      rr = ss;
      mem[rr].hh.lh = mem[r].hh.lh;
      r = mem[r].hh.rh;
    }
    mem[rr].hh.rh = mem_top;
    r = mem[p + 1].hh.lh;
    rr = mem_top - 1;
    while (r > 1)
    {
      ss = get_avail ();
      mem[rr].hh.rh = ss;
      rr = ss;
      mem[rr].hh.lh = mem[r].hh.lh;
      r = mem[r].hh.rh;
    }
    mem[rr].hh.rh = r;
    mem[pp + 1].hh.lh = mem[mem_top - 1].hh.rh;
    p = mem[p].hh.rh;
    qq = pp;
  }
  mem[qq].hh.rh = hh;
  mem[hh].hh.lh = qq;
  Result = hh;
  return Result;
}
/* 336 */
void y_reflect_edges (void)
{
  halfword p, q, r;

  p = mem[cur_edges + 1].hh.lh;
  mem[cur_edges + 1].hh.lh = 8191 - mem[cur_edges + 1].hh.rh;
  mem[cur_edges + 1].hh.rh = 8191 - p;
  mem[cur_edges + 5].hh.lh = 8191 - mem[cur_edges + 5].hh.lh;
  p = mem[cur_edges].hh.rh;
  q = cur_edges;
  do {
    r = mem[p].hh.rh;
    mem[p].hh.rh = q;
    mem[q].hh.lh = p;
    q = p;
    p = r;
  } while (!(q == cur_edges));
  mem[cur_edges + 4].cint = 0;
}
/* 337 */
void x_reflect_edges (void)
{
  halfword p, q, r, s;
  integer m;

  p = mem[cur_edges + 2].hh.lh;
  mem[cur_edges + 2].hh.lh = 8192 - mem[cur_edges + 2].hh.rh;
  mem[cur_edges + 2].hh.rh = 8192 - p;
  m = (4096 + mem[cur_edges + 3].hh.lh) * 8 + 8;
  mem[cur_edges + 3].hh.lh = 4096;
  p = mem[cur_edges].hh.rh;
  do {
    q = mem[p + 1].hh.rh;
    r = mem_top;
    while (q != mem_top)
    {
      s = mem[q].hh.rh;
      mem[q].hh.rh = r;
      r = q;
      mem[r].hh.lh = m - mem[q].hh.lh;
      q = s;
    }
    mem[p + 1].hh.rh = r;
    q = mem[p + 1].hh.lh;
    while (q > 1)
    {
      mem[q].hh.lh = m - mem[q].hh.lh;
      q = mem[q].hh.rh;
    }
    p = mem[p].hh.rh;
  } while (!(p == cur_edges));
  mem[cur_edges + 4].cint = 0;
}
/* 340 */
void y_scale_edges (integer s)
{
  halfword p, q, pp, r, rr, ss;
  integer t;

  if ((s * (mem[cur_edges + 1].hh.rh - 4095) >= 4096) || (s * (mem[cur_edges + 1].hh.lh - 4096) <= -4096))
  {
    print_err("Scaled picture would be too big");
    {
      help_ptr = 3;
      help_line[2] = 536;
      help_line[1] = 537;
      help_line[0] = 538;
    }
    put_get_error ();
  }
  else
  {
    mem[cur_edges + 1].hh.rh = s * (mem[cur_edges + 1].hh.rh - 4095) + 4095;
    mem[cur_edges + 1].hh.lh = s * (mem[cur_edges + 1].hh.lh - 4096) + 4096;
    p = cur_edges;
    do {
      q = p;
      p = mem[p].hh.rh;
      {integer for_end; t = 2;for_end = s; if (t <= for_end) do
        {
          pp = get_node (2);
          mem[q].hh.rh = pp;
          mem[p].hh.lh = pp;
          mem[pp].hh.rh = p;
          mem[pp].hh.lh = q;
          q = pp;
          r = mem[p + 1].hh.rh;
          rr = pp + 1;
          while (r != mem_top)
          {
            ss = get_avail ();
            mem[rr].hh.rh = ss;
            rr = ss;
            mem[rr].hh.lh = mem[r].hh.lh;
            r = mem[r].hh.rh;
          }
          mem[rr].hh.rh = mem_top;
          r = mem[p + 1].hh.lh;
          rr = mem_top - 1;
          while (r > 1)
          {
            ss = get_avail ();
            mem[rr].hh.rh = ss;
            rr = ss;
            mem[rr].hh.lh = mem[r].hh.lh;
            r = mem[r].hh.rh;
          }
          mem[rr].hh.rh = r;
          mem[pp + 1].hh.lh = mem[mem_top - 1].hh.rh;
        } while (t++ < for_end);
      }
    } while (!(mem[p].hh.rh == cur_edges));
    mem[cur_edges + 4].cint = 0;
  }
}
/* 342 */
void x_scale_edges (integer s)
{
  halfword p, q;
  unsigned short t;
  unsigned char w;
  integer delta;

  if ((s * (mem[cur_edges + 2].hh.rh - 4096) >= 4096) || (s * (mem[cur_edges + 2].hh.lh - 4096) <= -4096))
  {
    print_err("Scaled picture would be too big");
    {
      help_ptr = 3;
      help_line[2] = 539;
      help_line[1] = 537;
      help_line[0] = 538;
    }
    put_get_error ();
  }
  else if ((mem[cur_edges + 2].hh.rh != 4096) || (mem[cur_edges + 2].hh.lh != 4096))
  {
    mem[cur_edges + 2].hh.rh = s * (mem[cur_edges + 2].hh.rh - 4096) + 4096;
    mem[cur_edges + 2].hh.lh = s * (mem[cur_edges + 2].hh.lh - 4096) + 4096;
    delta = 8 * (4096 - s * mem[cur_edges + 3].hh.lh) + 0;
    mem[cur_edges + 3].hh.lh = 4096;
    q = mem[cur_edges].hh.rh;
    do {
      p = mem[q + 1].hh.rh;
      while (p != mem_top)
      {
        t = mem[p].hh.lh;
        w = t % 8;
        mem[p].hh.lh = (t - w) * s + w + delta;
        p = mem[p].hh.rh;
      }
      p = mem[q + 1].hh.lh;
      while (p > 1)
      {
        t = mem[p].hh.lh;
        w = t % 8;
        mem[p].hh.lh = (t - w) * s + w + delta;
        p = mem[p].hh.rh;
      }
      q = mem[q].hh.rh;
    } while (!(q == cur_edges));
    mem[cur_edges + 4].cint = 0;
  }
}
/* 344 */
void negate_edges (halfword h)
{
  halfword p, q, r, s, t, u;

  p = mem[h].hh.rh;
  while (p != h)
  {
    q = mem[p + 1].hh.lh;
    while (q > 1)
    {
      mem[q].hh.lh = 8 - 2 * ((mem[q].hh.lh) % 8) + mem[q].hh.lh;
      q = mem[q].hh.rh;
    }
    q = mem[p + 1].hh.rh;
    if (q != mem_top)
    {
      do {
        mem[q].hh.lh = 8 - 2 * ((mem[q].hh.lh) % 8) + mem[q].hh.lh;
        q = mem[q].hh.rh;
      } while (!(q == mem_top));
      u = p + 1;
      q = mem[u].hh.rh;
      r = q;
      s = mem[r].hh.rh;
      while (true)
        if (mem[s].hh.lh > mem[r].hh.lh)
        {
          mem[u].hh.rh = q;
          if (s == mem_top)
            goto done;
          u = r;
          q = s;
          r = q;
          s = mem[r].hh.rh;
        }
        else
        {
          t = s;
          s = mem[t].hh.rh;
          mem[t].hh.rh = q;
          q = t;
        }
        done: mem[r].hh.rh = mem_top;
    }
    p = mem[p].hh.rh;
  }
  mem[h + 4].cint = 0;
}
/* 346 */
void sort_edges (halfword h)
{
  halfword k;
  halfword p, q, r, s;

  r = mem[h + 1].hh.lh;
  mem[h + 1].hh.lh = 0;
  p = mem[r].hh.rh;
  mem[r].hh.rh = mem_top;
  mem[mem_top - 1].hh.rh = r;
  while (p > 1)
  {
    k = mem[p].hh.lh;
    q = mem_top - 1;
    do {
      r = q;
      q = mem[r].hh.rh;
    } while (!(k <= mem[q].hh.lh));
    mem[r].hh.rh = p;
    r = mem[p].hh.rh;
    mem[p].hh.rh = q;
    p = r;
  }
  {
    r = h + 1;
    q = mem[r].hh.rh;
    p = mem[mem_top - 1].hh.rh;
    while (true)
    {
      k = mem[p].hh.lh;
      while (k > mem[q].hh.lh)
      {
        r = q;
        q = mem[r].hh.rh;
      }
      mem[r].hh.rh = p;
      s = mem[p].hh.rh;
      mem[p].hh.rh = q;
      if (s == mem_top)
        goto done;
      r = p;
      p = s;
    }
    done:;
  }
}
/* 348 */
void cull_edges (integer wlo, integer whi, integer wout, integer win)
{
  halfword p, q, r, s;
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
  p = mem[cur_edges].hh.rh;
  n = mem[cur_edges + 1].hh.lh;
  while (p != cur_edges)
  {
    if (mem[p + 1].hh.lh > 1)
      sort_edges (p);
    if (mem[p + 1].hh.rh != mem_top)
    {
      r = mem_top - 1;
      q = mem[p + 1].hh.rh;
      ww = 0;
      m = 1000000L;
      prevw = 0;
      while (true)
      {
        if (q == mem_top)
          mm = 1000000L;
        else
        {
          d = mem[q].hh.lh;
          mm = d / 8;
          ww = ww + (d % 8) - 4;
        }
        if (mm > m)
        {
          if (w != prevw)
          {
            s = get_avail ();
            mem[r].hh.rh = s;
            mem[s].hh.lh = 8 * m + 4 + w - prevw;
            r = s;
            prevw = w;
          }
          if (q == mem_top)
            goto done;
        }
        m = mm;
        if (ww >= wlo)
        {
          if (ww <= whi)
            w = win;
          else
            w = wout;
        }
        else
          w = wout;
        s = mem[q].hh.rh;
        {
          mem[q].hh.rh = avail;
          avail = q;
          ;
#ifdef STAT
          decr (dyn_used);
#endif /* STAT */
        }
        q = s;
      }
      done: mem[r].hh.rh = mem_top;
      mem[p + 1].hh.rh = mem[mem_top - 1].hh.rh;
      if (r != mem_top - 1)
      {
        if (minn == 268435455L)
          minn = n;
        maxn = n;
        if (mind > mem[mem[mem_top - 1].hh.rh].hh.lh)
          mind = mem[mem[mem_top - 1].hh.rh].hh.lh;
        if (maxd < mem[r].hh.lh)
          maxd = mem[r].hh.lh;
      }
    }
    p = mem[p].hh.rh;
    incr (n);
  }
  if (minn > maxn)
  {
    p = mem[cur_edges].hh.rh;
    while (p != cur_edges)
    {
      q = mem[p].hh.rh;
      free_node (p, 2);
      p = q;
    }
    init_edges (cur_edges);
  }
  else
  {
    n = mem[cur_edges + 1].hh.lh;
    mem[cur_edges + 1].hh.lh = minn;
    while (minn > n)
    {
      p = mem[cur_edges].hh.rh;
      mem[cur_edges].hh.rh = mem[p].hh.rh;
      mem[mem[p].hh.rh].hh.lh = cur_edges;
      free_node (p, 2);
      incr (n);
    }
    n = mem[cur_edges + 1].hh.rh;
    mem[cur_edges + 1].hh.rh = maxn;
    mem[cur_edges + 5].hh.lh = maxn + 1;
    mem[cur_edges + 5].hh.rh = cur_edges;
    while (maxn < n)
    {
      p = mem[cur_edges].hh.lh;
      mem[cur_edges].hh.lh = mem[p].hh.lh;
      mem[mem[p].hh.lh].hh.rh = cur_edges;
      free_node (p, 2);
      decr (n);
    }
    mem[cur_edges + 2].hh.lh = ((mind) / 8) - mem[cur_edges + 3].hh.lh + 4096;
    mem[cur_edges + 2].hh.rh = ((maxd) / 8) - mem[cur_edges + 3].hh.lh + 4096;
  }
  mem[cur_edges + 4].cint = 0;
}
/* 354 */
void xy_swap_edges (void)
{
  integer mmagic, nmagic;
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

  mspread = mem[cur_edges + 2].hh.rh - mem[cur_edges + 2].hh.lh;
  if (mspread > move_size)
    overflow (540, move_size);
  {
    integer for_end; j = 0;for_end = mspread;
    if (j <= for_end)
      do
        move[j] = mem_top;
      while (j++ < for_end);
  }
  p = get_node (2);
  mem[p + 1].hh.rh = mem_top;
  mem[p + 1].hh.lh = 0;
  mem[p].hh.lh = cur_edges;
  mem[mem[cur_edges].hh.rh].hh.lh = p;
  p = get_node (2);
  mem[p + 1].hh.rh = mem_top;
  mem[p].hh.lh = mem[cur_edges].hh.lh;
  mmagic = mem[cur_edges + 2].hh.lh + mem[cur_edges + 3].hh.lh - 4096;
  nmagic = 8 * mem[cur_edges + 1].hh.rh + 12;
  do {
    q = mem[p].hh.lh;
    if (mem[q + 1].hh.lh > 1)
     sort_edges (q);
    r = mem[p + 1].hh.rh;
    free_node (p, 2);
    p = r;
    pd = mem[p].hh.lh;
    pm = pd / 8;
    r = mem[q + 1].hh.rh;
    rd = mem[r].hh.lh;
    rm = rd / 8;
    w = 0;
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
          if (mm - mmagic >= move_size)
            confusion(510);
          extras = (abs (w) - 1) / 3;
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
            j = m - mmagic;
            {
              integer for_end; k = 1;for_end = extras;
              if (k <= for_end)
                do {
                  s = get_avail ();
                  mem[s].hh.lh = nmagic + xw;
                  mem[s].hh.rh = move[j];
                  move[j] = s;
                } while (k++ < for_end);
            }
            s = get_avail ();
            mem[s].hh.lh = nmagic + ww;
            mem[s].hh.rh = move[j];
            move[j] = s;
            incr (m);
          } while (!(m == mm));
        }
      }
      if (pd < rd)
      {
        dw = (pd % 8) - 4;
        s = mem[p].hh.rh;
        {
          mem[p].hh.rh = avail;
          avail = p;
          ;
#ifdef STAT
          decr (dyn_used);
#endif /* STAT */
        }
        p = s;
        pd = mem[p].hh.lh;
        pm = pd / 8;
      }
      else
      {
        if (r == mem_top)
          goto done;
        dw = -((rd % 8) - 4);
        r = mem[r].hh.rh;
        rd = mem[r].hh.lh;
        rm = rd / 8;
      }
      m = mm;
      w = w + dw;
    }
    done:;
    p = q;
    nmagic = nmagic - 8;
  } while (!(mem[p].hh.lh == cur_edges));
  free_node (p, 2);
  move[mspread] = 0;
  j = 0;
  while (move[j] == mem_top)
    incr (j);
  if (j == mspread)
    init_edges (cur_edges);
  else
  {
    mm = mem[cur_edges + 2].hh.lh;
    mem[cur_edges + 2].hh.lh = mem[cur_edges + 1].hh.lh;
    mem[cur_edges + 2].hh.rh = mem[cur_edges + 1].hh.rh + 1;
    mem[cur_edges + 3].hh.lh = 4096;
    jj = mspread - 1;
    while (move[jj] == mem_top)
      decr (jj);
    mem[cur_edges + 1].hh.lh = j + mm;
    mem[cur_edges + 1].hh.rh = jj + mm;
    q = cur_edges;
    do {
      p = get_node (2);
      mem[q].hh.rh = p;
      mem[p].hh.lh = q;
      mem[p + 1].hh.rh = move[j];
      mem[p + 1].hh.lh = 0;
      incr (j);
      q = p;
    } while (!(j > jj));
    mem[q].hh.rh = cur_edges;
    mem[cur_edges].hh.lh = q;
    mem[cur_edges + 5].hh.lh = mem[cur_edges + 1].hh.rh + 1;
    mem[cur_edges + 5].hh.rh = cur_edges;
    mem[cur_edges + 4].cint = 0;
  }
}
/* 366 */
void merge_edges (halfword h)
{
  halfword p, q, r, pp, qq, rr;
  integer n;
  halfword k;
  integer delta;

  if (mem[h].hh.rh != h)
  {
    if ((mem[h + 2].hh.lh < mem[cur_edges + 2].hh.lh) ||
      (mem[h + 2].hh.rh > mem[cur_edges + 2].hh.rh) ||
      (mem[h + 1].hh.lh < mem[cur_edges + 1].hh.lh) ||
      (mem[h + 1].hh.rh > mem[cur_edges + 1].hh.rh))
      edge_prep (mem[h + 2].hh.lh - 4096, mem[h + 2].hh.rh - 4096, mem[h + 1].hh.lh - 4096, mem[h + 1].hh.rh - 4095);
    if (mem[h + 3].hh.lh != mem[cur_edges + 3].hh.lh)
    {
      pp = mem[h].hh.rh;
      delta = 8 * (mem[cur_edges + 3].hh.lh - mem[h + 3].hh.lh);
      do {
        qq = mem[pp + 1].hh.rh;
        while (qq != mem_top)
        {
          mem[qq].hh.lh = mem[qq].hh.lh + delta;
          qq = mem[qq].hh.rh;
        }
        qq = mem[pp + 1].hh.lh;
        while (qq > 1)
        {
          mem[qq].hh.lh = mem[qq].hh.lh + delta;
          qq = mem[qq].hh.rh;
        }
        pp = mem[pp].hh.rh;
      } while (!(pp == h));
    }
    n = mem[cur_edges + 1].hh.lh;
    p = mem[cur_edges].hh.rh;
    pp = mem[h].hh.rh;
    while (n < mem[h + 1].hh.lh)
    {
      incr (n);
      p = mem[p].hh.rh;
    }
    do {
      qq = mem[pp + 1].hh.lh;
      if (qq > 1)
      {
        if (mem[p + 1].hh.lh <= 1)
          mem[p + 1].hh.lh = qq;
        else
        {
          while (mem[qq].hh.rh > 1)
            qq = mem[qq].hh.rh;
          mem[qq].hh.rh = mem[p + 1].hh.lh;
          mem[p + 1].hh.lh = mem[pp + 1].hh.lh;
        }
      }
      mem[pp + 1].hh.lh = 0;
      qq = mem[pp + 1].hh.rh;
      if (qq != mem_top)
      {
        if (mem[p + 1].hh.lh == 1)
          mem[p + 1].hh.lh = 0;
        mem[pp + 1].hh.rh = mem_top;
        r = p + 1;
        q = mem[r].hh.rh;
        if (q == mem_top)
          mem[p + 1].hh.rh = qq;
        else
          while (true)
          {
            k = mem[qq].hh.lh;
            while (k > mem[q].hh.lh)
            {
              r = q;
              q = mem[r].hh.rh;
            }
            mem[r].hh.rh = qq;
            rr = mem[qq].hh.rh;
            mem[qq].hh.rh = q;
            if (rr == mem_top)
              goto done;
            r = qq;
            qq = rr;
          }
      }
      done:;
      pp = mem[pp].hh.rh;
      p = mem[p].hh.rh;
    } while (!(pp == h));
  }
}
/* 369 */
integer total_weight (halfword h)
{
  integer Result;
  halfword p, q;
  integer n;
  unsigned short m;

  n = 0;
  p = mem[h].hh.rh;
  while (p != h)
  {
    q = mem[p + 1].hh.rh;
    while (q != mem_top)
    {
      m = mem[q].hh.lh;
      n = n - ((m % 8) - 4) * (m / 8);
      q = mem[q].hh.rh;
    }
    q = mem[p + 1].hh.lh;
    while (q > 1)
    {
      m = mem[q].hh.lh;
      n = n - ((m % 8) - 4) * (m / 8);
      q = mem[q].hh.rh;
    }
    p = mem[p].hh.rh;
  }
  Result = n;
  return Result;
}
/* 654 */
void begin_edge_tracing (void)
{
  print_diagnostic(541, 261, true);
  print(542);
  print_int (cur_wt);
  print_char(41);
  trace_x = -4096;
}
/* 372 */
void trace_a_corner (void)
{
  if (file_offset > max_print_line - 13)
    print_nl(261);
  print_char(40);
  print_int (trace_x);
  print_char(44);
  print_int (trace_yy);
  print_char(41);
  trace_y = trace_yy;
}
/* 372 */
void end_edge_tracing (void)
{
  if (trace_x == -4096)
    print_nl(543);
  else
  {
    trace_a_corner ();
    print_char(46);
  }
  end_diagnostic (true);
}
/* 273 */
void trace_new_edge (halfword r, integer n)
{
  integer d;
  schar w;
  integer m, n0, n1;

  d = mem[r].hh.lh;
  w = (d % 8) - 4;
  m = (d / 8) - mem[cur_edges + 3].hh.lh;
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
      print_nl(261);
      trace_yy = n0;
    }
    else if (trace_yy != n0)
      print_char(63);
    else
      trace_a_corner ();
    trace_x = m;
    trace_a_corner ();
  }
  else
  {
    if (n0 != trace_yy)
      print_char(33);
    if (((n0 < n1) && (trace_y > trace_yy)) || ((n0 > n1) && (trace_y < trace_yy)))
      trace_a_corner ();
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
  halfword p, r;
  integer base;
  integer n;

  n0 = round_unscaled (y0);
  n1 = round_unscaled (y1);
  if (n0 != n1)
  {
    m0 = round_unscaled (x0);
    m1 = round_unscaled (x1);
    delx = x1 - x0;
    dely = y1 - y0;
    yt = n0 * 65536L - 32768L;
    y0 = y0 - yt;
    y1 = y1 - yt;
    if (n0 < n1)
    {
      base = 8 * mem[cur_edges + 3].hh.lh + 4 - cur_wt;
      if (m0 <= m1)
        edge_prep (m0, m1, n0, n1);
      else
        edge_prep (m1, m0, n0, n1);
      n = mem[cur_edges + 5].hh.lh - 4096;
      p = mem[cur_edges + 5].hh.rh;
      if (n != n0)
      {
        if (n < n0)
          do {
            incr (n);
            p = mem[p].hh.rh;
          } while (!(n == n0));
        else
          do {
            decr (n);
            p = mem[p].hh.lh;
          } while (!(n == n0));
      }
      y0 = 65536L - y0;
      while (true)
      {
        r = get_avail ();
        mem[r].hh.rh = mem[p + 1].hh.lh;
        mem[p + 1].hh.lh = r;
        tx = take_fraction (delx, make_fraction (y0, dely));
        if (ab_vs_cd (delx, y0, dely, tx) < 0)
          decr (tx);
        mem[r].hh.lh = 8 * round_unscaled (x0 + tx) + base;
        y1 = y1 - 65536L;
        if (internal[10] > 0)
          trace_new_edge (r, n);
        if (y1 < 65536L)
          goto done;
        p = mem[p].hh.rh;
        y0 = y0 + 65536L;
        incr (n);
      }
      done:;
    }
    else
    {
      base = 8 * mem[cur_edges + 3].hh.lh + 4 + cur_wt;
      if (m0 <= m1)
        edge_prep (m0, m1, n1, n0);
      else
        edge_prep (m1, m0, n1, n0);
      decr (n0);
      n = mem[cur_edges + 5].hh.lh - 4096;
      p = mem[cur_edges + 5].hh.rh;
      if (n != n0)
      {
        if (n < n0)
          do {
            incr (n);
            p = mem[p].hh.rh;
          } while (!(n == n0));
        else
          do {
            decr (n);
            p = mem[p].hh.lh;
          } while (!(n == n0));
      }
      while (true)
      {
        r = get_avail ();
        mem[r].hh.rh = mem[p + 1].hh.lh;
        mem[p + 1].hh.lh = r;
        tx = take_fraction (delx, make_fraction (y0, dely));
        if (ab_vs_cd (delx, y0, dely, tx) < 0)
          incr (tx);
        mem[r].hh.lh = 8 * round_unscaled (x0 - tx) + base;
        y1 = y1 + 65536L;
        if (internal[10] > 0)
          trace_new_edge (r, n);
        if (y1 >= 0)
          goto done1;
        p = mem[p].hh.lh;
        y0 = y0 + 65536L;
        decr (n);
      }
      done1:;
    }
    mem[cur_edges + 5].hh.rh = p;
    mem[cur_edges + 5].hh.lh = n + 4096;
  }
}
/* 378 */
void move_to_edges (integer m0, integer n0, integer m1, integer n1)
{
  integer delta;
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
  {
    integer for_end;
    k = 1; for_end = delta;
    if (k <= for_end)
      do
        sum = sum + abs (move[k]);
      while (k++ < for_end);
  }
  if (sum != m1 - m0)
    confusion(48);
#endif /* TEXMF_DEBUG */
  switch (octant)
  {
    case 1:
      {
        dx = 8;
        edge_prep (m0, m1, n0, n1);
        goto lab60;
      }
      break;
    case 5:
      {
        dx = 8;
        edge_prep (n0, n1, m0, m1);
        goto lab62;
      }
      break;
    case 6:
      {
        dx = -8;
        edge_prep (-n1, -n0, m0, m1);
        n0 = -n0;
        goto lab62;
      }
      break;
    case 2:
      {
        dx = -8;
        edge_prep (-m1, -m0, n0, n1);
        m0 = -m0;
        goto lab60;
      }
      break;
    case 4:
      {
        dx = -8;
        edge_prep (-m1, -m0, -n1, -n0);
        m0 = -m0;
        goto lab61;
      }
      break;
    case 8:
      {
        dx = -8;
        edge_prep (-n1, -n0, -m1, -m0);
        n0 = -n0;
        goto lab63;
      }
      break;
    case 7:
      {
        dx = 8;
        edge_prep (n0, n1, -m1, -m0);
        goto lab63;
      }
      break;
    case 3:
      {
        dx = 8;
        edge_prep (m0, m1, -n1, -n0);
        goto lab61;
      }
      break;
  }
  lab60: n = mem[cur_edges + 5].hh.lh - 4096;
  p = mem[cur_edges + 5].hh.rh;
  if (n != n0)
  {
    if (n < n0)
      do {
        incr (n);
        p = mem[p].hh.rh;
      } while (!(n == n0));
    else
      do {
        decr (n);
        p = mem[p].hh.lh;
      } while (!(n == n0));
  }
  if (delta > 0)
  {
    k = 0;
    edgeandweight = 8 * (m0 + mem[cur_edges + 3].hh.lh) + 4 - cur_wt;
    do {
      edgeandweight = edgeandweight + dx * move[k];
      {
        r = avail;
        if (r == 0)
          r = get_avail ();
        else
        {
          avail = mem[r].hh.rh;
          mem[r].hh.rh = 0;
          ;
#ifdef STAT
          incr (dyn_used);
#endif /* STAT */
        }
      }
      mem[r].hh.rh = mem[p + 1].hh.lh;
      mem[r].hh.lh = edgeandweight;
      if (internal[10] > 0)
        trace_new_edge (r, n);
      mem[p + 1].hh.lh = r;
      p = mem[p].hh.rh;
      incr (k);
      incr (n);
    } while (!(k == delta));
  }
  goto done;
  lab61: n0 = -n0 - 1;
  n = mem[cur_edges + 5].hh.lh - 4096;
  p = mem[cur_edges + 5].hh.rh;
  if (n != n0)
  {
    if (n < n0)
      do {
        incr (n);
        p = mem[p].hh.rh;
      } while (!(n == n0));
    else
      do {
        decr (n);
        p = mem[p].hh.lh;
      } while (!(n == n0));
  }
  if (delta > 0)
  {
    k = 0;
    edgeandweight = 8 * (m0 + mem[cur_edges + 3].hh.lh) + 4 + cur_wt;
    do {
      edgeandweight = edgeandweight + dx * move[k];
      {
        r = avail;
        if (r == 0)
          r = get_avail ();
        else
        {
          avail = mem[r].hh.rh;
          mem[r].hh.rh = 0;
          ;
#ifdef STAT
          incr (dyn_used);
#endif /* STAT */
        }
      }
      mem[r].hh.rh = mem[p + 1].hh.lh;
      mem[r].hh.lh = edgeandweight;
      if (internal[10] > 0)
        trace_new_edge (r, n);
      mem[p + 1].hh.lh = r;
      p = mem[p].hh.lh;
      incr (k);
      decr (n);
    } while (!(k == delta));
  }
  goto done;
  lab62: edgeandweight = 8 * (n0 + mem[cur_edges + 3].hh.lh) +
  4 - cur_wt;
  n0 = m0;
  k = 0;
  n = mem[cur_edges + 5].hh.lh - 4096;
  p = mem[cur_edges + 5].hh.rh;
  if (n != n0)
  {
    if (n < n0)
      do {
        incr (n);
        p = mem[p].hh.rh;
      } while (!(n == n0));
    else
      do {
        decr (n);
        p = mem[p].hh.lh;
      } while (!(n == n0));
  }
  do {
    j = move[k];
    while (j > 0)
    {
      {
        r = avail;
        if (r == 0)
          r = get_avail ();
        else
        {
          avail = mem[r].hh.rh;
          mem[r].hh.rh = 0;
          ;
#ifdef STAT
          incr (dyn_used);
#endif /* STAT */
        }
      }
      mem[r].hh.rh = mem[p + 1].hh.lh;
      mem[r].hh.lh = edgeandweight;
      if (internal[10] > 0)
        trace_new_edge (r, n);
      mem[p + 1].hh.lh = r;
      p = mem[p].hh.rh;
      decr (j);
      incr (n);
    }
    edgeandweight = edgeandweight + dx;
    incr (k);
  } while (!(k > delta));
  goto done;
  lab63: edgeandweight = 8 * (n0 + mem[cur_edges + 3].hh.lh) + 4 + cur_wt;
  n0 = -m0 - 1;
  k = 0;
  n = mem[cur_edges + 5].hh.lh - 4096;
  p = mem[cur_edges + 5].hh.rh;
  if (n != n0)
  {
    if (n < n0)
      do {
        incr (n);
        p = mem[p].hh.rh;
      } while (!(n == n0));
    else
      do {
        decr (n);
        p = mem[p].hh.lh;
      } while (!(n == n0));
  }
  do {
    j = move[k];
    while (j > 0)
    {
      {
        r = avail;
        if (r == 0)
          r = get_avail ();
        else
        {
          avail = mem[r].hh.rh;
          mem[r].hh.rh = 0;
          ;
#ifdef STAT
          incr (dyn_used);
#endif /* STAT */
        }
      }
      mem[r].hh.rh = mem[p + 1].hh.lh;
      mem[r].hh.lh = edgeandweight;
      if (internal[10] > 0)
        trace_new_edge (r, n);
      mem[p + 1].hh.lh = r;
      p = mem[p].hh.lh;
      decr (j);
      decr (n);
    }
    edgeandweight = edgeandweight + dx;
    incr (k);
  } while (!(k > delta));
  goto done;
  done: mem[cur_edges + 5].hh.lh = n + 4096;
  mem[cur_edges + 5].hh.rh = p;
}
/* 387 */
void skew (scaled x, scaled y, small_number octant)
{
  switch (octant)
  {
    case 1:
      {
        cur_x = x - y;
        cur_y = y;
      }
      break;
    case 5:
      {
        cur_x = y - x;
        cur_y = x;
      }
      break;
    case 6:
      {
        cur_x = y + x;
        cur_y = -x;
      }
      break;
    case 2:
      {
        cur_x = -x - y;
        cur_y = y;
      }
      break;
    case 4:
      {
        cur_x = -x + y;
        cur_y = -y;
      }
      break;
    case 8:
      {
        cur_x = -y + x;
        cur_y = -x;
      }
      break;
    case 7:
      {
        cur_x = -y - x;
        cur_y = x;
      }
      break;
    case 3:
      {
        cur_x = x + y;
        cur_y = -y;
      }
      break;
  }
}
/* 390 */
void abnegate (scaled x, scaled y, small_number octantbefore, small_number octantafter)
{
  if (odd (octantbefore) == odd (octantafter))
    cur_x = x;
  else
    cur_x = -x;
  if ((octantbefore > 2) == (octantafter > 2))
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
  {
    Result = 0;
    goto lab_exit;
  }
  if (c >= 0)
  {
    if (b >= 0)
    {
      if (c > 0)
      {
        Result = 268435457L;
        goto lab_exit;
      }
      else if ((a == 0) && (b == 0))
      {
        Result = 268435457L;
        goto lab_exit;
      }
      else
      {
        Result = 268435456L;
        goto lab_exit;
      }
    }
    if (a == 0)
    {
      Result = 0;
      goto lab_exit;
    }
  }
  else if (a == 0)
  {
    if (b <= 0)
    {
      Result = 0;
      goto lab_exit;
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
    else
    {
      xx = x1 + x - x0;
      if (xx > x0)
      {
        x2 = x;
        x0 = x0 + x0;
        d = d + d;
      }
      else
      {
        x0 = x0 - xx;
        if (x <= x0)
        {
          if (x + x2 <= x0)
          {
            Result = 268435457L;
            goto lab_exit;
          }
        }
        x1 = x;
        d = d + d + 1;
      }
    }
  } while (!(d >= 268435456L));
  Result = d - 268435456L;
  lab_exit:;
  return Result;
}
/* 394 */
void print_spec (str_number s)
{
  halfword p, q;
  small_number octant;

  print_diagnostic(544, s, true);
  p = cur_spec;
  octant = mem[p + 3].cint;
  print_ln ();
  unskew (mem[cur_spec + 1].cint, mem[cur_spec + 2].cint, octant);
  print_two (cur_x, cur_y);
  print(545);
  while (true)
  {
    print(octant_dir[octant]);
    print_char(39);
    while (true)
    {
      q = mem[p].hh.rh;
      if (mem[p].hh.b1 == 0)
        goto not_found;
      {
        print_nl(556);
        unskew (mem[p + 5].cint, mem[p + 6].cint, octant);
        print_two (cur_x, cur_y);
        print(523);
        unskew (mem[q + 3].cint, mem[q + 4].cint, octant);
        print_two (cur_x, cur_y);
        print_nl(520);
        unskew (mem[q + 1].cint, mem[q + 2].cint, octant);
        print_two (cur_x, cur_y);
        print(557);
        print_int (mem[q].hh.b0 - 1);
      }
      p = q;
    }
  not_found:
    if (q == cur_spec)
      goto done;
    p = q;
    octant = mem[p + 3].cint;
    print_nl(546);
  }
done:
  print_nl(547);
  end_diagnostic (true);
}
/* 398 */
void print_strange (str_number s)
{
  halfword p;
  halfword f;
  halfword q;
  integer t;

  if (interaction == 3)
    ;
  print_nl(62);
  p = cur_spec;
  t = 256;
  do {
    p = mem[p].hh.rh;
    if (mem[p].hh.b0 != 0)
    {
      if (mem[p].hh.b0 < t)
        f = p;
      t = mem[p].hh.b0;
    }
  } while (!(p == cur_spec));
  p = cur_spec;
  q = p;
  do {
    p = mem[p].hh.rh;
    if (mem[p].hh.b0 == 0)
      q = p;
  } while (!(p == f));
  t = 0;
  do {
    if (mem[p].hh.b0 != 0)
    {
      if (mem[p].hh.b0 != t)
      {
        t = mem[p].hh.b0;
        print_char(32);
        print_int (t - 1);
      }
      if (q != 0)
      {
        if (mem[mem[q].hh.rh].hh.b0 == 0)
        {
          print(558);
          print(octant_dir[mem[q + 3].cint]);
          q = mem[q].hh.rh;
          while (mem[mem[q].hh.rh].hh.b0 == 0)
          {
            print_char(32);
            print(octant_dir[mem[q + 3].cint]);
            q = mem[q].hh.rh;
          }
          print_char(41);
        }
        print_char(32);
        print(octant_dir[mem[q + 3].cint]);
        q = 0;
      }
    }
    else if (q == 0)
    q = p;
    p = mem[p].hh.rh;
  } while (!(p == f));
  print_char(32);
  print_int (mem[p].hh.b0 - 1);
  if (q != 0)
  {
    if (mem[mem[q].hh.rh].hh.b0 == 0)
    {
      print(558);
      print(octant_dir[mem[q + 3].cint]);
      q = mem[q].hh.rh;
      while (mem[mem[q].hh.rh].hh.b0 == 0)
      {
        print_char(32);
        print(octant_dir[mem[q + 3].cint]);
        q = mem[q].hh.rh;
      }
      print_char(41);
    }
  }
  print_err(s);
}
/* 405 */
void remove_cubic (halfword p)
{
  halfword q;

  q = mem[p].hh.rh;
  mem[p].hh.b1 = mem[q].hh.b1;
  mem[p].hh.rh = mem[q].hh.rh;
  mem[p + 1].cint = mem[q + 1].cint;
  mem[p + 2].cint = mem[q + 2].cint;
  mem[p + 5].cint = mem[q + 5].cint;
  mem[p + 6].cint = mem[q + 6].cint;
  free_node (q, 7);
}
/* 410 */
void split_cubic (halfword p, fraction t, scaled xq, scaled yq)
{
  scaled v;
  halfword q, r;

  q = mem[p].hh.rh;
  r = get_node (7);
  mem[p].hh.rh = r;
  mem[r].hh.rh = q;
  mem[r].hh.b0 = mem[q].hh.b0;
  mem[r].hh.b1 = mem[p].hh.b1;
  v = mem[p + 5].cint - take_fraction (mem[p + 5].cint - mem[q + 3].cint, t);
  mem[p + 5].cint = mem[p + 1].cint - take_fraction (mem[p + 1].cint - mem[p + 5].cint, t);
  mem[q + 3].cint = mem[q + 3].cint - take_fraction (mem[q + 3].cint - xq, t);
  mem[r + 3].cint = mem[p + 5].cint - take_fraction (mem[p + 5].cint - v, t);
  mem[r + 5].cint = v - take_fraction (v - mem[q + 3].cint, t);
  mem[r + 1].cint = mem[r + 3].cint - take_fraction (mem[r + 3].cint - mem[r + 5].cint, t);
  v = mem[p + 6].cint - take_fraction (mem[p + 6].cint - mem[q + 4].cint, t);
  mem[p + 6].cint = mem[p + 2].cint - take_fraction (mem[p + 2].cint - mem[p + 6].cint, t);
  mem[q + 4].cint = mem[q + 4].cint - take_fraction (mem[q + 4].cint - yq, t);
  mem[r + 4].cint = mem[p + 6].cint - take_fraction (mem[p + 6].cint - v, t);
  mem[r + 6].cint = v - take_fraction (v - mem[q + 4].cint, t);
  mem[r + 2].cint = mem[r + 4].cint - take_fraction (mem[r + 4].cint - mem[r + 6].cint, t);
}
/* 406 */
void quadrant_subdivide (void)
{
  halfword p, q, r, s, pp, qq;
  scaled firstx, firsty;
  scaled del1, del2, del3, del, dmax;
  fraction t;
  scaled destx, desty;
  boolean constantx;

  p = cur_spec;
  firstx = mem[cur_spec + 1].cint;
  firsty = mem[cur_spec + 2].cint;
  do {
lab_continue:
    q = mem[p].hh.rh;
    if (q == cur_spec)
    {
      destx = firstx;
      desty = firsty;
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
      dmax = abs (del1);
      if (abs (del2) > dmax)
        dmax = abs (del2);
      if (abs (del3) > dmax)
        dmax = abs (del3);
      while (dmax < 134217728L)
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
      if (t < 268435456L)
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
        if (t < 268435456L)
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
        dmax = abs (del1);
        if (abs (del2) > dmax)
          dmax = abs (del2);
        if (abs (del3) > dmax)
          dmax = abs (del3);
        while (dmax < 134217728L)
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
        if (t < 268435456L)
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
          if (t < 268435456L)
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
      else if (!odd (mem[pp].hh.b1))
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
      dmax = abs (del1);
      if (abs (del2) > dmax)
        dmax = abs (del2);
      if (abs (del3) > dmax)
        dmax = abs (del3);
      while (dmax < 134217728L)
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
      if (t < 268435456L)
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
        if (t < 268435456L)
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
  boolean allsafe;
  scaled nexta;
  scaled deltaa, deltab;

  before[cur_rounding_ptr] = before[0];
  node_to_round[cur_rounding_ptr] = node_to_round[0];
  do {
    after[cur_rounding_ptr] = after[0];
    allsafe = true;
    nexta = after[0];
    {integer for_end; k = 0;for_end = cur_rounding_ptr - 1; if (k <= for_end) do
      {
        deltab = before[k + 1] - before[k];
        if (deltab >= 0)
          deltaa = after[k + 1] - nexta;
        else
          deltaa = nexta - after[k + 1];
        nexta = after[k + 1];
        if ((deltaa < 0) || (deltaa > abs (deltab + deltab)))
        {
          allsafe = false;
          after[k] = before[k];
          if (k == cur_rounding_ptr - 1)
            after[0] = before[0];
          else
            after[k + 1] = before[k + 1];
        }
      } while (k++ < for_end);
    }
  } while (!(allsafe));
}
/* 429 */
void before_and_after (scaled b, scaled a, halfword p)
{
  if (cur_rounding_ptr == max_rounding_ptr)
  {
    if (max_rounding_ptr < max_wiggle)
      incr (max_rounding_ptr);
    else
      overflow (568, max_wiggle);
  }
  after[cur_rounding_ptr] = a;
  before[cur_rounding_ptr] = b;
  node_to_round[cur_rounding_ptr] = p;
  incr (cur_rounding_ptr);
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
  
  Result = half (good_val (u + u, -u - v));
  return Result;
}
/* 433 */
void xy_round (void)
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
    q = mem[p].hh.rh;
    if (odd (mem[p].hh.b1) != odd (mem[q].hh.b1))
    {
      if (odd (mem[q].hh.b1))
        b = mem[q + 1].cint;
      else
        b = -mem[q + 1].cint;
      if ((abs (mem[q + 1].cint - mem[q + 5].cint) < 655) || (abs (mem[q + 1].cint + mem[q + 3].cint) < 655))
      {
        if (cur_pen == 3)
          penedge = 0;
        else if (cur_path_type == 0)
         penedge = compromise (mem[mem[cur_pen + 5].hh.rh + 2].cint, mem[mem[cur_pen + 7].hh.rh + 2].cint);
        else if (odd (mem[q].hh.b1))
          penedge = mem[mem[cur_pen + 7].hh.rh + 2].cint;
        else
          penedge = mem[mem[cur_pen + 5].hh.rh + 2].cint;
        a = good_val (b, penedge);
      }
      else
        a = b;
      if (abs (a) > max_allowed)
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
    make_safe ();
    do {
      decr (cur_rounding_ptr);
      if ((after[cur_rounding_ptr]!= before[cur_rounding_ptr]) || (after[cur_rounding_ptr + 1]!= before[cur_rounding_ptr + 1]))
      {
        p = node_to_round[cur_rounding_ptr];
        if (odd (mem[p].hh.b1))
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
          alpha = 268435456L;
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
      if ((abs (mem[q + 2].cint - mem[q + 6].cint) < 655) || (abs (mem[q + 2].cint + mem[q + 4].cint) < 655))
      {
        if (cur_pen == 3)
          penedge = 0;
        else if (cur_path_type == 0)
          penedge = compromise (mem[mem[cur_pen + 2].hh.rh + 2].cint, mem[mem[cur_pen + 1].hh.rh + 2].cint);
        else if (mem[q].hh.b1 <= 2)
          penedge = mem[mem[cur_pen + 1].hh.rh + 2].cint;
        else
          penedge = mem[mem[cur_pen + 2].hh.rh + 2].cint;
        a = good_val (b, penedge);
      }
      else
        a = b;
      if (abs (a) > max_allowed)
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
    make_safe ();
    do {
      decr (cur_rounding_ptr);
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
          alpha = 268435456L;
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
  scaled firstx, firsty;

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
      if (abs (mem[q].hh.b1 - mem[p].hh.b1) == 4)
      {
        if ((abs (mem[q + 1].cint - mem[q + 5].cint) < 655) || (abs (mem[q + 1].cint + mem[q + 3].cint) < 655))
        {
          if (cur_pen == 3)
            penedge = 0;
          else if (cur_path_type == 0)
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
            if (odd (mem[q].hh.b1))
              a = good_val (b, penedge + half (cur_gran));
            else
              a = good_val (b - 1, penedge + half (cur_gran));
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
    firstx = mem[p + 1].cint;
    firsty = mem[p + 2].cint;
    before[cur_rounding_ptr] = before[0];
    node_to_round[cur_rounding_ptr] = node_to_round[0];
    do {
      after[cur_rounding_ptr] = after[0];
      allsafe = true;
      nexta = after[0];
      {integer for_end; k = 0;for_end = cur_rounding_ptr - 1; if (k <= for_end) do
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
                unskew (firstx, firsty, mem[pp].hh.b1);
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
                dd = firsty - bb;
              else
                dd = mem[pp + 2].cint - bb;
              if (odd (aa - bb))
              {
                if (mem[p].hh.b1 > 4)
                  cc = dd - half (aa - bb + 1);
                else
                  cc = dd - half (aa - bb - 1);
              }
              else
                cc = dd - half (aa - bb);
            }
            d = mem[p + 2].cint;
            if (odd (a - b))
            {
              if (mem[p].hh.b1 > 4)
                c = d - half (a - b - 1);
              else
                c = d - half (a - b + 1);
            }
            else
              c = d - half (a - b);
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
      while (k++ < for_end);}
    } while (!(allsafe));
    {integer for_end; k = 0;for_end = cur_rounding_ptr - 1; if (k <= for_end) do
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
              unskew (firstx, firsty, mem[pp].hh.b1);
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
              dd = firsty - bb;
            else
              dd = mem[pp + 2].cint - bb;
            if (odd (aa - bb))
            {
              if (mem[p].hh.b1 > 4)
                cc = dd - half (aa - bb + 1);
              else
                cc = dd - half (aa - bb - 1);
            }
            else
              cc = dd - half (aa - bb);
          }
          d = mem[p + 2].cint;
          if (odd (a - b))
          {
            if (mem[p].hh.b1 > 4)
              c = d - half (a - b - 1);
            else
              c = d - half (a - b + 1);
          }
          else
            c = d - half (a - b);
          if (b == bb)
            alpha = 268435456L;
          else
            alpha = make_fraction (aa - a, bb - b);
          if (d == dd)
            beta = 268435456L;
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
    while (k++ < for_end);}
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
  dmax = half (max_allowed);
  do {
    if (abs (mem[p + 3].cint) >= dmax)
    {
      if (abs (mem[p + 3].cint) > max_allowed)
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
    if (abs (mem[p + 4].cint) >= dmax)
    {
      if (abs (mem[p + 4].cint) > max_allowed)
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
    if (abs (mem[p + 1].cint) >= dmax)
    {
      if (abs (mem[p + 1].cint) > max_allowed)
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
    if (abs (mem[p + 2].cint) >= dmax)
    {
      if (abs (mem[p + 2].cint) > max_allowed)
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
    if (abs (mem[p + 5].cint) >= dmax)
    {
      if (abs (mem[p + 5].cint) > max_allowed)
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
    if (abs (mem[p + 6].cint) >= dmax)
    {
      if (abs (mem[p + 6].cint) > max_allowed)
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
      incr (k);
    else
      k = 1;
  } while (!(p == cur_spec));
  if (chopped > 0)
  {
    print_err("Curve out of range");
    {
      help_ptr = 4;
      help_line[3] = 564;
      help_line[2] = 565;
      help_line[1] = 566;
      help_line[0] = 567;
    }
    put_get_error ();
  }
  quadrant_subdivide ();
  if ((internal[36] > 0) && (chopped == 0))
    xy_round ();
  octant_subdivide ();
  if ((internal[36] > 65536L) && (chopped == 0))
    diag_round ();
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
            dmax = abs (dx1);
            if (abs (dy1) > dmax)
              dmax = abs (dy1);
            while (dmax < 268435456L)
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
            dmax = abs (dx2);
            if (abs (dy2) > dmax)
              dmax = abs (dy2);
            while (dmax < 268435456L)
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
            decr (o1);
        }
        else if (o1 == 8)
          o1 = 1;
        else
          incr (o1);
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
        if (abs (o1 - o2) == 1)
        {
          if (o2 < o1)
            o2 = o1;
          if (odd (o2))
            mem[p + 6].cint = 0;
          else
            mem[p + 6].cint = 1;
        }
        else
        {
          if (o1 == 8)
            incr (turning_number);
          else
            decr (turning_number);
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
    if ((internal[36]<= 0) || (chopped != 0))
      print_spec (560);
    else if (internal[36] > 65536L)
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
  y = y + 32768L - y_corr[octant];
  x = x + y - x_corr[octant];
  m1 = floorunscaled (x);
  n1 = floorunscaled (y);
  if (x - 65536L * m1 >= y - 65536L * n1 + z_corr[octant])
    d1 = 1;
  else
    d1 = 0;
}
/* 465 */
void fill_spec (halfword h)
{
  halfword p, q, r, s;

  if (internal[10] > 0)
    begin_edge_tracing ();
  p = h;
  do {
    octant = mem[p + 3].cint;
    q = p;
    while (mem[q].hh.b1 != 0)
      q = mem[q].hh.rh;
    if (q != p)
    {
      end_round (mem[p + 1].cint, mem[p + 2].cint);
      m0 = m1;
      n0 = n1;
      d0 = d1;
      end_round (mem[q + 1].cint, mem[q + 2].cint);
      if (n1 - n0 >= move_size)
        overflow (540, move_size);
      move[0] = d0;
      move_ptr = 0;
      r = p;
      do {
        s = mem[r].hh.rh;
        make_moves (mem[r + 1].cint, mem[r + 5].cint, mem[s + 3].cint, mem[s + 1].cint, mem[r + 2].cint + 32768L, mem[r + 6].cint + 32768L, mem[s + 4].cint + 32768L, mem[s + 2].cint + 32768L, xy_corr[octant], y_corr[octant]);
        r = s;
      } while (!(r == q));
      move[move_ptr] = move[move_ptr] - d1;
      if (internal[35] > 0)
        smooth_moves (0, move_ptr);
      move_to_edges (m0, n0, m1, n1);
    }
    p = mem[q].hh.rh;
  } while (!(p == h));
  toss_knot_list (h);
  if (internal[10] > 0)
    end_edge_tracing ();
}
/* 476 */
void dup_offset (halfword w)
{
  halfword r;

  r = get_node (3);
  mem[r + 1].cint = mem[w + 1].cint;
  mem[r + 2].cint = mem[w + 2].cint;
  mem[r].hh.rh = mem[w].hh.rh;
  mem[mem[w].hh.rh].hh.lh = r;
  mem[r].hh.lh = w;
  mem[w].hh.rh = r;
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
  mc = abs (mem[h + 1].cint);
  if (q == r)
  {
    hh = h;
    mem[h].hh.b1 = 0;
    if (mc < abs (mem[h + 2].cint))
      mc = abs (mem[h + 2].cint);
  }
  else
  {
    o = 0;
    hh = 0;
    while (true)
    {
      s = mem[r].hh.rh;
      if (mc < abs (mem[r + 1].cint))
        mc = abs (mem[r + 1].cint);
      if (mc < abs (mem[r + 2].cint))
        mc = abs (mem[r + 2].cint);
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
  {integer for_end; k = 1;for_end = 8; if (k <= for_end) do
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
        else if (odd (k))
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
        incr (n);
      }
      done1: r = mem[h].hh.rh;
      if (odd (k))
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
        incr (n);
      }
      r = mem[r].hh.lh;
      if (mem[r + 1].cint != mem[mem[r].hh.lh + 1].cint)
        dup_offset (r);
      else
        decr (n);
      if (n >= 255)
        overflow (579, 255);
      mem[h].hh.lh = n;
    }
  while (k++ < for_end);}
  goto found;
  not_found: p = 3;
  if (mc >= 268402688L)
  {
    print_err("Pen too large");
    {
      help_ptr = 2;
      help_line[1] = 574;
      help_line[0] = 575;
    }
  }
  else
  {
    print_err("Pen cycle must be convex");
    {
      help_ptr = 3;
      help_line[2] = 577;
      help_line[1] = 578;
      help_line[0] = 575;
    }
  }
  put_get_error ();
found:
  if (internal[6] > 0)
    print_pen (p, 572, true);
  Result = p;
  return Result;
}
/* 486 */
halfword trivial_knot (scaled x, scaled y)
{
  halfword Result;
  halfword p;

  p = get_node (7);
  mem[p].hh.b0 = 1;
  mem[p].hh.b1 = 1;
  mem[p + 1].cint = x;
  mem[p + 3].cint = x;
  mem[p + 5].cint = x;
  mem[p + 2].cint = y;
  mem[p + 4].cint = y;
  mem[p + 6].cint = y;
  Result = p;
  return Result;
}
/* 484 */
halfword make_path (halfword penhead)
{
  halfword Result;
  halfword p;
  unsigned char k;
  halfword h;
  integer m, n;
  halfword w, ww;

  p = mem_top - 1;
  {integer for_end; k = 1;for_end = 8; if (k <= for_end) do
    {
      octant = octant_code[k];
      h = penhead + octant;
      n = mem[h].hh.lh;
      w = mem[h].hh.rh;
      if (!odd (k))
        w = mem[w].hh.lh;
      {integer for_end; m = 1;for_end = n + 1; if (m <= for_end)
        do {
          if (odd (k))
            ww = mem[w].hh.rh;
          else
            ww = mem[w].hh.lh;
          if ((mem[ww + 1].cint != mem[w + 1].cint) || (mem[ww + 2].cint != mem[w + 2].cint))
          {
            unskew (mem[ww + 1].cint, mem[ww + 2].cint, octant);
            mem[p].hh.rh = trivial_knot (cur_x, cur_y);
            p = mem[p].hh.rh;
          }
          w = ww;
        }
      while (m++ < for_end);}
    }
  while (k++ < for_end);}
  if (p == mem_top - 1)
  {
    w = mem[penhead + 1].hh.rh;
    p = trivial_knot (mem[w + 1].cint + mem[w + 2].cint, mem[w + 2].cint);
    mem[mem_top - 1].hh.rh = p;
  }
  mem[p].hh.rh = mem[mem_top - 1].hh.rh;
  Result = mem[mem_top - 1].hh.rh;
  return Result;
}
/* 488 */
void find_offset (scaled x, scaled y, halfword p)
{
  unsigned char octant;
  schar s;
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
  if (odd (octant_number[octant]))
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
    decr (n);
  }
  done: unskew (mem[w + 1].cint, mem[w + 2].cint, octant);
  lab_exit:;
}
/* 493 */
void split_for_offset (halfword p, fraction t)
{
  halfword q;
  halfword r;

  q = mem[p].hh.rh;
  split_cubic (p, t, mem[q + 1].cint, mem[q + 2].cint);
  r = mem[p].hh.rh;
  if (mem[r + 2].cint < mem[p + 2].cint)
    mem[r + 2].cint = mem[p + 2].cint;
  else if (mem[r + 2].cint > mem[q + 2].cint)
    mem[r + 2].cint = mem[q + 2].cint;
  if (mem[r + 1].cint < mem[p + 1].cint)
    mem[r + 1].cint = mem[p + 1].cint;
  else if (mem[r + 1].cint > mem[q + 1].cint)
    mem[r + 1].cint = mem[q + 1].cint;
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
    if (abs (du) >= abs (dv))
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
    if (t >= 268435456L)
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
      if (t < 268435456L)
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
      incr (k);
    else
      decr (k);
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
      while (lmax_coef < 134217728L)
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
          if (ab_vs_cd (dy, abs (mem[ww + 1].cint - mem[w + 1].cint), dx, abs (mem[ww + 2].cint - mem[w + 2].cint)) >= 0)
          {
            incr (k);
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
          if (abs (du) >= abs (dv))
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
        if (t >= 268435456L)
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
          if (t < 268435456L)
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
void skew_line_edges (halfword p, halfword w, halfword ww)
{
  scaled x0, y0, x1, y1;

  if ((mem[w + 1].cint != mem[ww + 1].cint) || (mem[w + 2].cint != mem[ww + 2].cint))
  {
    x0 = mem[p + 1].cint + mem[w + 1].cint;
    y0 = mem[p + 2].cint + mem[w + 2].cint;
    x1 = mem[p + 1].cint + mem[ww + 1].cint;
    y1 = mem[p + 2].cint + mem[ww + 2].cint;
    unskew (x0, y0, octant);
    x0 = cur_x;
    y0 = cur_y;
    unskew (x1, y1, octant);
    ;
#ifdef STAT
    if (internal[10] > 65536L)
    {
      print_nl(585);
      print_two (x0, y0);
      print(584);
      print_two (cur_x, cur_y);
      print_nl(261);
    }
#endif /* STAT */
    line_edges (x0, y0, cur_x, cur_y);
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
  {
    integer for_end; n = 1;for_end = n1 - n0 + 1; if (n <= for_end)
      do
        env_move[n] = mm1;
      while (n++ < for_end);
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
      yy = mem[r + 2].cint + mem[w + 2].cint + 32768L;
      ;
#ifdef STAT
      if (internal[10] > 65536L)
      {
        print_nl(586);
        print_int (k);
        print(587);
        unskew (xx, yy - 32768L, octant);
        print_two (cur_x, cur_y);
      }
#endif /* STAT */
      if (mem[r].hh.b1 < k)
      {
        decr (k);
        w = mem[w].hh.lh;
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
            while (true)
            {
              if (m < env_move[move_ptr])
                env_move[move_ptr] = m;
              tx = take_fraction (delx, make_fraction (yy, dely));
              if (ab_vs_cd (tx, dely, delx, yy) + xy_corr[octant] > 0)
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
      else
      {
        incr (k);
        w = mem[w].hh.rh;
        xp = mem[r + 1].cint + mem[w + 1].cint;
        yp = mem[r + 2].cint + mem[w + 2].cint + 32768L;
      }
      ;
#ifdef STAT
      if (internal[10] > 65536L)
      {
        print(584);
        unskew (xp, yp - 32768L, octant);
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
    mem[s + 1].cint + mem[w + 1].cint, mem[r + 2].cint + mem[w + 2].cint + 32768L, mem[r + 6].cint + mem[w + 2].cint + 32768L, mem[s + 4].cint + mem[w + 2].cint + 32768L, mem[s + 2].cint + mem[w + 2].cint + 32768L, xy_corr[octant], y_corr[octant]);
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
    confusion(50);
#endif /* TEXMF_DEBUG */
  move[0] = d0 + env_move[1] - mm0;
  {integer for_end; n = 1;for_end = move_ptr; if (n <= for_end)
    do
      move[n] = env_move[n + 1] - env_move[n]+ 1;
    while (n++ < for_end);
  }
  move[move_ptr] = move[move_ptr] - d1;
  if (internal[35] > 0)
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

  if (internal[10] > 0)
    begin_edge_tracing ();
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
    ;
#ifdef STAT
    if (internal[10] > 65536L)
    {
      print_nl(580);
      print(octant_dir[octant]);
      print(558);
      print_int (mem[h].hh.lh);
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
    if (odd (octant_number[octant]))
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
      overflow (540, move_size);
    offset_prep (p, h);
    q = p;
    while (mem[q].hh.b1 != 0)
      q = mem[q].hh.rh;
    if (odd (octant_number[octant]))
    {
      k = 0;
      w = mem[h].hh.rh;
      ww = mem[w].hh.lh;
      mm0 = floorunscaled (mem[p + 1].cint + mem[w + 1].cint - xy_corr[octant]);
      mm1 = floorunscaled (mem[q + 1].cint + mem[ww + 1].cint - xy_corr[octant]);
      {
        integer for_end; n = 0;for_end = n1 - n0;
        if (n <= for_end)
          do
            env_move[n] = mm0;
          while (n++ < for_end);
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
          yy = mem[r + 2].cint + mem[w + 2].cint + 32768L;
          ;
#ifdef STAT
          if (internal[10] > 65536L)
          {
            print_nl(586);
            print_int (k);
            print(587);
            unskew (xx, yy - 32768L, octant);
            print_two (cur_x, cur_y);
          }
#endif /* STAT */
          if (mem[r].hh.b1 > k)
          {
            incr (k);
            w = mem[w].hh.rh;
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
                while (true)
                {
                  tx = take_fraction (delx, make_fraction (yy, dely));
                  if (ab_vs_cd (tx, dely, delx, yy) + xy_corr[octant] > 0)
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
          else
          {
            decr (k);
            w = mem[w].hh.lh;
            xp = mem[r + 1].cint + mem[w + 1].cint;
            yp = mem[r + 2].cint + mem[w + 2].cint + 32768L;
          }
          ;
#ifdef STAT
          if (internal[10] > 65536L)
          {
            print(584);
            unskew (xp, yp - 32768L, octant);
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
        make_moves (mem[r + 1].cint + mem[w + 1].cint, mem[r + 5].cint + mem[w + 1].cint, mem[s + 3].cint + mem[w + 1].cint, mem[s + 1].cint + mem[w + 1].cint, mem[r + 2].cint + mem[w + 2].cint + 32768L, mem[r + 6].cint + mem[w + 2].cint + 32768L, mem[s + 4].cint + mem[w + 2].cint + 32768L, mem[s + 2].cint + mem[w + 2].cint + 32768L, xy_corr[octant], y_corr[octant]);
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
        confusion(49);
#endif /* TEXMF_DEBUG */
      move[0] = d0 + env_move[0] - mm0;
      {
        integer for_end; n = 1;for_end = move_ptr;
        if (n <= for_end)
          do
            move[n] = env_move[n] - env_move[n - 1]+ 1;
          while (n++ < for_end);
      }
      move[move_ptr] = move[move_ptr] - d1;
      if (internal[35] > 0)
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
  if (internal[10] > 0)
    end_edge_tracing ();
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

  if ((major_axis == minor_axis) || (theta % 94371840L == 0))
  {
    symmetric = true;
    alpha = 0;
    if (odd (theta / 94371840L))
    {
      beta = major_axis;
      gamma = minor_axis;
      n_sin = 268435456L;
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
    alpha = (alpha + 32768L) / 65536L;
    gamma = take_fraction (minor_axis, n_sin);
    gamma = pyth_add (take_fraction (major_axis, n_cos), gamma);
  }
  beta = (beta + 32768L) / 65536L;
  gamma = (gamma + 32768L) / 65536L;
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
  if (gamma <= abs (alpha))
  {
    if (alpha > 0)
      alpha = gamma - 1;
    else
      alpha = 1 - gamma;
  }
  mem[p + 1].cint = -alpha * 32768L;
  mem[p + 2].cint = -beta * 32768L;
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
  else
  {
    mem[r + 2].cint = -mem[p + 2].cint;
    mem[r + 4].cint = beta + beta;
    mem[s + 1].cint = -mem[p + 1].cint;
    mem[s + 2].cint = mem[r + 2].cint;
    mem[s + 3].cint = 32768L;
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
    alpha = abs (u);
    beta = abs (v);
    if (alpha < beta)
    {
      alpha = abs (v);
      beta = abs (u);
    }
    if (internal[38] != 0)
      d = d - take_fraction (internal[38], make_fraction (beta + beta, delta));
    d = take_fraction ((d + 4) / 8, delta);
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

  if (abs (x) < abs (y))
  {
    x = make_fraction (x, abs (y));
    if (y > 0)
      y = 268435456L;
    else
      y = -268435456L;
  }
  else if (x == 0)
  {
    Result = 0;
    goto lab_exit;
  }
  else
  {
    y = make_fraction (y, abs (x));
    if (x > 0)
      x = 268435456L;
    else
      x = -268435456L;
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
    while (max < 134217728L)
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
          if (phi >= theta - 188743680L)
          goto found;
        }
      }
      if (theta <= 0)
      {
        if (phi >= 0)
        {
          if (phi <= theta + 188743680L)
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
          if (t <= 268435456L)
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
          tt = 65536L;
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
    if (t > 268435456L)
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
    if (t > 268435456L)
      goto done;
    x1 = x1 - take_fraction (x1 - x2, t);
    x2 = x2 - take_fraction (x2 - x3, t);
    if (x1 - take_fraction (x1 - x2, t) >= 0)
    {
      t = tt - take_fraction (tt - 268435456L, t);
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
              if (max_t == 131072L)
              {
                cur_t = half (cur_t + 1);
                cur_tt = half (cur_tt + 1);
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
            bisect_stack[bisect_ptr - 24] = half (bisect_stack[bisect_ptr - 25]+ bisect_stack[uv - 4]);
            bisect_stack[bisect_ptr - 4] = half (bisect_stack[bisect_ptr - 3]+ bisect_stack[uv - 4]);
            bisect_stack[bisect_ptr - 23] = half (bisect_stack[bisect_ptr - 24]+ bisect_stack[bisect_ptr - 4]);
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
            bisect_stack[bisect_ptr - 29] = half (bisect_stack[bisect_ptr - 30]+ bisect_stack[uv - 9]);
            bisect_stack[bisect_ptr - 9] = half (bisect_stack[bisect_ptr - 8] + bisect_stack[uv - 9]);
            bisect_stack[bisect_ptr - 28] = half (bisect_stack[bisect_ptr - 29]+ bisect_stack[bisect_ptr - 9]);
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
            bisect_stack[bisect_ptr - 34] = half (bisect_stack[bisect_ptr - 35]+ bisect_stack[xy - 14]);
            bisect_stack[bisect_ptr - 14] = half (bisect_stack[bisect_ptr - 13]+ bisect_stack[xy - 14]);
            bisect_stack[bisect_ptr - 33] = half (bisect_stack[bisect_ptr - 34]+ bisect_stack[bisect_ptr - 14]);
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
            bisect_stack[bisect_ptr - 39] = half (bisect_stack[bisect_ptr - 40] + bisect_stack[xy - 19]);
            bisect_stack[bisect_ptr - 19] = half (bisect_stack[bisect_ptr - 18] + bisect_stack[xy - 19]);
            bisect_stack[bisect_ptr - 38] = half (bisect_stack[bisect_ptr - 39] + bisect_stack[bisect_ptr - 19]);
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
      decr (time_to_go);
    else
    {
      while (appr_t < 65536L)
      {
        appr_t = appr_t + appr_t;
        appr_tt = appr_tt + appr_tt;
      }
      cur_t = appr_t;
      cur_tt = appr_tt;
      goto lab_exit;
    }
  not_found:
    if (odd (cur_tt))
    {
      if (odd (cur_t))
      {
        cur_t = half (cur_t);
        cur_tt = half (cur_tt);
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
    else
    {
      incr (cur_tt);
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
void path_intersection (halfword h, halfword hh)
{
  halfword p, pp;
  integer n, nn;

  if (mem[h].hh.b1 == 0)
  {
    mem[h + 5].cint = mem[h + 1].cint;
    mem[h + 3].cint = mem[h + 1].cint;
    mem[h + 6].cint = mem[h + 2].cint;
    mem[h + 4].cint = mem[h + 2].cint;
    mem[h].hh.b1 = 1;
  }
  if (mem[hh].hh.b1 == 0)
  {
    mem[hh + 5].cint = mem[hh + 1].cint;
    mem[hh + 3].cint = mem[hh + 1].cint;
    mem[hh + 6].cint = mem[hh + 2].cint;
    mem[hh + 4].cint = mem[hh + 2].cint;
    mem[hh].hh.b1 = 1;
  }
  tol_step = 0;
  do {
    n = -65536L;
    p = h;
    do {
      if (mem[p].hh.b1 != 0)
      {
        nn = -65536L;
        pp = hh;
        do {
          if (mem[pp].hh.b1 != 0)
          {
            cubic_intersection (p, pp);
            if (cur_t > 0)
            {
              cur_t = cur_t + n;
              cur_tt = cur_tt + nn;
              goto lab_exit;
            }
          }
          nn = nn + 65536L;
          pp = mem[pp].hh.rh;
        } while (!(pp == hh));
      }
      n = n + 65536L;
      p = mem[p].hh.rh;
    } while (!(p == h));
    tol_step = tol_step + 3;
  } while (!(tol_step > 3));
  cur_t = -65536L;
  cur_tt = -65536L;
  lab_exit:;
}
/* 574 */
void open_a_window (window_number k, scaled r0, scaled c0, scaled r1, scaled c1, scaled x, scaled y)
{
  integer m, n;

  if (r0 < 0)
    r0 = 0;
  else
    r0 = round_unscaled (r0);
  r1 = round_unscaled (r1);
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
    c0 = round_unscaled (c0);
  c1 = round_unscaled (c1);
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
  incr (window_time[k]);
  left_col[k] = c0;
  right_col[k] = c1;
  top_row[k] = r0;
  bot_row[k] = r1;
  m = round_unscaled (x);
  n = round_unscaled (y) - 1;
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
    blankrectangle (c0, c1, r0, r1);
    updatescreen ();
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
                          incr (n);
                        }
                        else
                          b = 1;
                      }
                      else
                        incr (n);
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
              incr (n);
              row_transition[n] = right_col[k];
            }
            else if (n == 0)
              goto done;
            paintrow (r, b, row_transition, n);
            done:;
          }
          p = mem[p].hh.rh;
          decr (r);
        }
        updatescreen ();
        incr (window_time[k]);
        mem[cur_edges + 3].hh.rh = k;
        mem[cur_edges + 4].cint = window_time[k];
      }
    }
  }
}
/* 495 */
fraction max_coef (halfword p)
{
  fraction Result;
  fraction x;

  x = 0;
  while (mem[p].hh.lh != 0)
  {
    if (abs (mem[p + 1].cint) > x)
      x = abs (mem[p + 1].cint);
    p = mem[p].hh.rh;
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
      if (abs (v) < threshold)
        free_node (s, 2);
      else
      {
        if (abs (v) >= 626349397L)
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
    if (abs (w) <= threshold)
    {
      s = mem[p].hh.rh;
      free_node (p, 2);
      p = s;
    }
    else
    {
      if (abs (w) >= 626349397L)
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
void new_dep (halfword q, halfword p)
{
  halfword r;

  mem[q + 1].hh.rh = p;
  mem[q + 1].hh.lh = 13;
  r = mem[13].hh.rh;
  mem[dep_final].hh.rh = r;
  mem[r + 1].hh.lh = dep_final;
  mem[13].hh.rh = q;
}
/* 607 */
halfword const_dependency (scaled v)
{
  halfword Result;

  dep_final = get_node (2);
  mem[dep_final + 1].cint = v;
  mem[dep_final].hh.lh = 0;
  Result = dep_final;
  return Result;
}
/* 608 */
halfword single_dependency (halfword p)
{
  halfword Result;
  halfword q;
  integer m;

  m = mem[p + 1].cint % 64;
  if (m > 28)
    Result = const_dependency (0);
  else
  {
    q = get_node (2);
    mem[q + 1].cint = two_to_the[28 - m];
    mem[q].hh.lh = p;
    mem[q].hh.rh = const_dependency (0);
    Result = q;
  }
  return Result;
}
/* 609 */
halfword copy_dep_list (halfword p)
{
  halfword Result;
  halfword q;

  q = get_node (2);
  dep_final = q;
  while (true)
  {
    mem[dep_final].hh.lh = mem[p].hh.lh;
    mem[dep_final + 1].cint = mem[p + 1].cint;
    if (mem[dep_final].hh.lh == 0)
      goto done;
    mem[dep_final].hh.rh = get_node (2);
    dep_final = mem[dep_final].hh.rh;
    p = mem[p].hh.rh;
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
    if (abs (mem[r + 1].cint) > abs (v))
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
      if (abs (w) <= 1342)
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
  else if (v != -268435456L)
    mem[r + 1].cint = -make_fraction (mem[r + 1].cint, v);
  finalnode = r;
  p = mem[mem_top - 1].hh.rh;
  if (internal[2] > 0)
  {
    if (interesting (x))
    {
      begin_diagnostic ();
      print_nl(597);
      print_variable_name(x);
      w = n;
      while (w > 0)
      {
        print(590);
        w = w - 2;
      }
      print_char(61);
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
      if ((abs (w) <= 1342) && (mem[r].hh.lh != 0))
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
    if (abs (mem[x + 1].cint) >= 268435456L)
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
    fix_dependencies ();
}
/* 619 */
halfword new_ring_entry (halfword p)
{
  halfword Result;
  halfword q;

  q = get_node (2);
  mem[q].hh.b1 = 11;
  mem[q].hh.b0 = mem[p].hh.b0;
  if (mem[p + 1].cint == 0)
    mem[q + 1].cint = p;
  else
    mem[q + 1].cint = mem[p + 1].cint;
  mem[p + 1].cint = q;
  Result = q;
  return Result;
}
/* 621 */
void non_linear_eq (integer v, halfword p, boolean flushp)
{
  small_number t;
  halfword q, r;

  t = mem[p].hh.b0 - 1;
  q = mem[p + 1].cint;
  if (flushp)
    mem[p].hh.b0 = 1;
  else
    p = q;
  do {
    r = mem[q + 1].cint;
    mem[q].hh.b0 = t;
    switch (t)
    {
      case 2:
        mem[q + 1].cint = v;
        break;
      case 4:
        {
          mem[q + 1].cint = v;
          {
            if (str_ref[v]< 127)
            incr (str_ref[v]);
          }
        }
        break;
      case 6:
        {
          mem[q + 1].cint = v;
          incr (mem[v].hh.lh);
        }
        break;
      case 9:
        mem[q + 1].cint = copy_path (v);
        break;
      case 11:
        mem[q + 1].cint = copy_edges (v);
        break;
    }
    q = r;
  } while (!(q == p));
}
/* 622 */
void ring_merge (halfword p, halfword q)
{
  halfword r;

  r = mem[p + 1].cint;
  while (r != p)
  {
    if (r == q)
    {
      {
        print_err("Redundant equation");
        {
          help_ptr = 2;
          help_line[1] = 601;
          help_line[0] = 602;
        }
        put_get_error ();
      }
      goto lab_exit;
    }
    r = mem[r + 1].cint;
  }
  r = mem[p + 1].cint;
  mem[p + 1].cint = mem[q + 1].cint;
  mem[q + 1].cint = r;
  lab_exit:;
}
/* 626 */
void show_cmd_mod (integer c, integer m)
{
  begin_diagnostic ();
  print_nl(123);
  print_cmd_mod (c, m);
  print_char(125);
  end_diagnostic (false);
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
    if ((file_ptr == input_ptr) || (cur_input.index_field <= 15) || (cur_input.index_field != 19) || (cur_input.loc_field != 0))
    {
      tally = 0;
      old_setting = selector;
      if ((cur_input.index_field <= 15))
      {
        if (cur_input.name_field <= 1)
        {
          if ((cur_input.name_field == 0) && (file_ptr == 0))
            print_nl(604);
          else
            print_nl(605);
        }
        else if (cur_input.name_field == 2)
          print_nl(606);
        else
        {
          print_nl(607);
          print_int (line);
        }
        print_char(32);
        {
          l = tally;
          tally = 0;
          selector = 4;
          trick_count = 1000000L;
        }
        if (cur_input.limit_field > 0)
        {
          integer for_end; i = cur_input.start_field;for_end = cur_input.limit_field - 1;
          if (i <= for_end)
            do {
              if (i == cur_input.loc_field)
              {
                first_count = tally;
                trick_count = tally + 1 + error_line - half_error_line;
                if (trick_count < error_line)
                  trick_count = error_line;
              }
              print(buffer[i]);
          } while (i++ < for_end);
        }
      }
      else
      {
        switch (cur_input.index_field)
        {
          case 16:
            print_nl(608);
            break;
          case 17:
            {
              print_nl(613);
              p = param_stack[cur_input.limit_field];
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
            if (cur_input.loc_field == 0)
              print_nl(610);
            else
              print_nl(611);
            break;
          case 20:
            print_nl(612);
            break;
          case 21:
            {
              print_ln ();
              if (cur_input.name_field != 0)
                slow_print(hash[cur_input.name_field].v.RH);
              else
              {
                p = param_stack[cur_input.limit_field];
                if (p == 0)
                  show_token_list (param_stack[cur_input.limit_field + 1], 0, 20, tally);
                else
                {
                  q = p;
                  while (mem[q].hh.rh != 0)
                    q = mem[q].hh.rh;
                  mem[q].hh.rh = param_stack[cur_input.limit_field + 1];
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
          selector = 4;
          trick_count = 1000000L;
        }
        if (cur_input.index_field != 21)
          show_token_list (cur_input.start_field, cur_input.loc_field, 100000L, 0);
        else
          show_macro (cur_input.start_field, cur_input.loc_field, 100000L);
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
      {
        integer for_end; q = p;for_end = first_count - 1;
        if (q <= for_end) do
          print_char(trick_buf[q % error_line]);
          while (q++ < for_end);
      }
      print_ln ();
      {
        integer for_end; q = 1;for_end = n;
        if (q <= for_end) do
          print_char(32);
          while (q++ < for_end);
      }
      if (m + n <= error_line)
        p = first_count + m;
      else
        p = first_count + (error_line - n - 3);
      {
        integer for_end; q = first_count;for_end = p - 1;
        if (q <= for_end) do
          print_char(trick_buf[q % error_line]);
          while (q++ < for_end);
      }
      if (m + n > error_line)
        print(276);
    }
    if ((cur_input.index_field <= 15))
    {
      if ((cur_input.name_field > 2) || (file_ptr == 0))
        goto done;
    }
    decr (file_ptr);
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
        overflow (615, stack_size);
    }
    input_stack[input_ptr] = cur_input;
    incr (input_ptr);
  }
  cur_input.start_field = p;
  cur_input.index_field = t;
  cur_input.limit_field = param_ptr;
  cur_input.loc_field = p;
}
/* 650 */
void end_token_list (void)
{
  halfword p;

  if (cur_input.index_field >= 19)
  {
    if (cur_input.index_field <= 20)
    {
      flush_token_list (cur_input.start_field);
      goto done;
    }
    else
      delete_mac_ref (cur_input.start_field);
  }
  while (param_ptr > cur_input.limit_field)
  {
    decr (param_ptr);
    p = param_stack[param_ptr];
    if (p != 0)
    {
      if (mem[p].hh.rh == 1)
      {
        recycle_value (p);
        free_node (p, 2);
      }
      else
        flush_token_list (p);
    }
  }
done:
  {
    decr (input_ptr);
    cur_input = input_stack[input_ptr];
  }
  {
    if (interrupt != 0)
      pause_for_instructions ();
  }
}
/* 856 */
void encapsulate (halfword p)
{
  cur_exp = get_node (2);
  mem[cur_exp].hh.b0 = cur_type;
  mem[cur_exp].hh.b1 = 11;
  new_dep (cur_exp, p);
}
/* 858 */
void install (halfword r, halfword q)
{
  halfword p;

  if (mem[q].hh.b0 == 16)
  {
    mem[r + 1].cint = mem[q + 1].cint;
    mem[r].hh.b0 = 16;
  }
  else if (mem[q].hh.b0 == 19)
  {
    p = single_dependency (q);
    if (p == dep_final)
    {
      mem[r].hh.b0 = 16;
      mem[r + 1].cint = 0;
      free_node (p, 2);
    }
    else
    {
      mem[r].hh.b0 = 17;
      new_dep (r, p);
    }
  }
  else
  {
    mem[r].hh.b0 = mem[q].hh.b0;
    new_dep (r, copy_dep_list (mem[q + 1].hh.rh));
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
            incr (str_ref[cur_exp]);
        }
      }
      break;
    case 6:
      {
        cur_exp = mem[p + 1].cint;
        incr (mem[cur_exp].hh.lh);
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
            overflow (588, serial_no / 64);
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
      confusion(800);
      break;
  }
}
/* 651 */
halfword cur_tok (void)
{
  halfword Result;
  halfword p;
  small_number save_type;
  integer save_exp;

  if (cur_sym == 0)
  {
    if (cur_cmd == 38)
    {
      save_type = cur_type;
      save_exp = cur_exp;
      make_exp_copy (cur_mod);
      p = stash_cur_exp ();
      mem[p].hh.rh = 0;
      cur_type = save_type;
      cur_exp = save_exp;
    }
    else
    {
      p = get_node (2);
      mem[p + 1].cint = cur_mod;
      mem[p].hh.b1 = 12;
      if (cur_cmd == 42)
        mem[p].hh.b0 = 16;
      else
        mem[p].hh.b0 = 4;
    }
  }
  else
  {
    {
      p = avail;
      if (p == 0)
        p = get_avail ();
      else
      {
        avail = mem[p].hh.rh;
        mem[p].hh.rh = 0;
        ;
#ifdef STAT
        incr (dyn_used);
#endif /* STAT */
      }
    }
    mem[p].hh.lh = cur_sym;
  }
  Result = p;
  return Result;
}
/* 652 */
void back_input (void)
{
  halfword p;

  p = cur_tok ();
  while ((cur_input.index_field > 15) && (cur_input.loc_field == 0))
    end_token_list ();
  begin_token_list (p, 19);
}
/* 653 */
void back_error (void)
{
  OK_to_interrupt = false;
  back_input ();
  OK_to_interrupt = true;
  error ();
}
/* 653 */
void ins_error (void)
{
  OK_to_interrupt = false;
  back_input ();
  cur_input.index_field = 20;
  OK_to_interrupt = true;
  error ();
}
/* 654 */
void begin_file_reading (void)
{
  if (in_open == 15)
    overflow (616, 15);
  if (first == buf_size)
    overflow (256, buf_size);
  incr (in_open);
  {
    if (input_ptr > max_in_stack)
    {
      max_in_stack = input_ptr;
      if (input_ptr == stack_size)
        overflow (615, stack_size);
    }
    input_stack[input_ptr] = cur_input;
    incr (input_ptr);
  }
  cur_input.index_field = in_open;
  line_stack[cur_input.index_field] = line;
  cur_input.start_field = first;
  cur_input.name_field = 0;
}
/* 655 */
void end_file_reading (void)
{
  first = cur_input.start_field;
  line = line_stack[cur_input.index_field];
  if (cur_input.index_field != in_open)
    confusion(617);
  if (cur_input.name_field > 2)
    aclose (input_file[cur_input.index_field]);
  {
    decr (input_ptr);
    cur_input = input_stack[input_ptr];
  }
  decr (in_open);
}
/* 656 */
void clear_for_error_prompt (void)
{
  while ((cur_input.index_field <= 15) && (cur_input.name_field == 0) && (input_ptr > 0) && (cur_input.loc_field == cur_input.limit_field))
    end_file_reading ();
  print_ln ();
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
      p = get_avail ();
      mem[p].hh.lh = cur_sym;
      begin_token_list (p, 19);
    }
    if (scanner_status > 1)
    {
      runaway ();
      if (cur_sym == 0)
        print_err("File ended");
      else
      {
        print_err("Forbidden token found");
      }
      print(625);
      {
        help_ptr = 4;
        help_line[3] = 626;
        help_line[2] = 627;
        help_line[1] = 628;
        help_line[0] = 629;
      }
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
              eqtb[9759].v.RH = warning_info;
            }
          }
          break;
        case 4:
        case 5:
          {
            print(634);
            if (scanner_status == 5)
              slow_print(hash[warning_info].v.RH);
            else
              print_variable_name(warning_info);
            cur_sym = 9765;
          }
          break;
        case 6:
          {
            print(635);
            slow_print(hash[warning_info].v.RH);
            print(636);
            help_line[3] = 637;
            cur_sym = 9764;
          }
          break;
      }
      ins_error ();
    }
    else
    {
      print_err("Incomplete if; all text was ignored after line ");
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
      ins_error ();
    }
    deletions_allowed = true;
    Result = false;
  }
  return Result;
}
/* 667 */
void get_next (void)
{
  integer k;
  ASCII_code c;
  ASCII_code cclass;
  integer n, f;

lab_restart:
  cur_sym = 0;
  if ((cur_input.index_field <= 15))
  {
lab25:
    c = buffer[cur_input.loc_field];
    incr (cur_input.loc_field);
    cclass = char_class[c];
    switch (cclass)
    {
      case 0:
        goto lab85;
        break;
      case 1:
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
      case 2:
        goto lab25;
        break;
      case 3:
        {
          if (cur_input.name_field > 2)
          {
            incr (line);
            first = cur_input.start_field;
            if (!force_eof)
            {
              if (inputln (input_file[cur_input.index_field], true))
                firm_up_the_line ();
              else
                force_eof = true;
            }
            if (force_eof)
            {
              print_char(41);
              decr (open_parens);
              fflush (stdout);
              force_eof = false;
              end_file_reading ();
              if (check_outer_validity ())
                goto lab_restart;
              else
                goto lab_restart;
            }
            buffer[cur_input.limit_field] = 37;
            first = cur_input.limit_field + 1;
            cur_input.loc_field = cur_input.start_field;
          }
          else
          {
            if (input_ptr > 0)
            {
              end_file_reading ();
              goto lab_restart;
            }
            if (selector < 2)
              open_log_file ();
            if (interaction > 1)
            {
              if (cur_input.limit_field == cur_input.start_field)
                print_nl(652);
              print_ln ();
              first = cur_input.start_field;
              {
                ;
                print(42);
                term_input ();
              }
              cur_input.limit_field = last;
              buffer[cur_input.limit_field] = 37;
              first = cur_input.limit_field + 1;
              cur_input.loc_field = cur_input.start_field;
            }
            else
              fatal_error (653);
          }
          {
            if (interrupt != 0)
              pause_for_instructions ();
          }
          goto lab25;
        }
        break;
      case 4:
        {
          if (buffer[cur_input.loc_field] == 34)
            cur_mod = 261;
          else
          {
            k = cur_input.loc_field;
            buffer[cur_input.limit_field + 1] = 34;
            do {
              incr (cur_input.loc_field);
            } while (!(buffer[cur_input.loc_field] == 34));
            if (cur_input.loc_field > cur_input.limit_field)
            {
              cur_input.loc_field = cur_input.limit_field;
              print_err("Incomplete string token has been flushed");
              {
                help_ptr = 3;
                help_line[2] = 646;
                help_line[1] = 647;
                help_line[0] = 648;
              }
              deletions_allowed = false;
              error ();
              deletions_allowed = true;
              goto lab_restart;
            }
            if ((cur_input.loc_field == k + 1) && ((str_start[buffer[k] + 1] - str_start[buffer[k]]) == 1))
              cur_mod = buffer[k];
            else
            {
              {
                if (pool_ptr + cur_input.loc_field - k > max_pool_ptr)
                {
                  if (pool_ptr + cur_input.loc_field - k > pool_size)
                    overflow (257, pool_size - init_pool_ptr);
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
          goto lab_exit;
        }
        break;
      case 5:
      case 6:
      case 7:
      case 8:
        {
          k = cur_input.loc_field - 1;
          goto found;
        }
        break;
      case 20:
        {
          print_err("Text line contains an invalid character");
          {
            help_ptr = 2;
            help_line[1] = 643;
            help_line[0] = 644;
          }
          deletions_allowed = false;
          error ();
          deletions_allowed = true;
          goto lab_restart;
        }
        break;
      default:
        ;
        break;
    }
    k = cur_input.loc_field - 1;
    while (char_class[buffer[cur_input.loc_field]] == cclass)
      incr (cur_input.loc_field);
    goto found;
  lab85:
    n = c - 48;
    while (char_class[buffer[cur_input.loc_field]] == 0)
    {
      if (n < 4096)
        n = 10 * n + buffer[cur_input.loc_field] - 48;
      incr (cur_input.loc_field);
    }
    if (buffer[cur_input.loc_field] == 46)
    {
      if (char_class[buffer[cur_input.loc_field + 1]] == 0)
        goto done;
    }
    f = 0;
    goto lab87;
  done:
    incr (cur_input.loc_field);
  lab86:
    k = 0;
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
  lab87:
    if (n < 4096)
      cur_mod = n * 65536L + f;
    else
    {
      print_err("Enormous number has been reduced");
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
    goto lab_exit;
  found:
    cur_sym = id_lookup (k, cur_input.loc_field - k);
  }
  else if (cur_input.loc_field >= hi_mem_min)
  {
    cur_sym = mem[cur_input.loc_field].hh.lh;
    cur_input.loc_field = mem[cur_input.loc_field].hh.rh;
    if (cur_sym >= 9770)
    {
      if (cur_sym >= 9920)
      {
        if (cur_sym >= 10070)
        cur_sym = cur_sym - 150;
        begin_token_list (param_stack[cur_input.limit_field + cur_sym - (9920)], 18);
        goto lab_restart;
      }
      else
      {
        cur_cmd = 38;
        cur_mod = param_stack[cur_input.limit_field + cur_sym - (9770)];
        cur_sym = 0;
        goto lab_exit;
      }
    }
  }
  else if (cur_input.loc_field > 0)
  {
    if (mem[cur_input.loc_field].hh.b1 == 12)
    {
      cur_mod = mem[cur_input.loc_field + 1].cint;
      if (mem[cur_input.loc_field].hh.b0 == 16)
        cur_cmd = 42;
      else
      {
        cur_cmd = 39;
        {
          if (str_ref[cur_mod]< 127)
            incr (str_ref[cur_mod]);
        }
      }
    }
    else
    {
      cur_mod = cur_input.loc_field;
      cur_cmd = 38;
    }
    cur_input.loc_field = mem[cur_input.loc_field].hh.rh;
    goto lab_exit;
  }
  else
  {
    end_token_list ();
    goto lab_restart;
  }
  cur_cmd = eqtb[cur_sym].lh;
  cur_mod = eqtb[cur_sym].v.RH;
  if (cur_cmd >= 86)
  {
    if (check_outer_validity ())
      cur_cmd = cur_cmd - 86;
    else
      goto lab_restart;
  }
  lab_exit:;
}
/* 682 */
void firm_up_the_line (void)
{
  integer k;

  cur_input.limit_field = last;
  if (internal[31] > 0)
  {
    if (interaction > 1)
    {
      ;
      print_ln ();
      if (cur_input.start_field < cur_input.limit_field)
      {
        integer for_end; k = cur_input.start_field; for_end = cur_input.limit_field - 1;
        if (k <= for_end) do
          print(buffer[k]);
          while (k++ < for_end);
      }
      first = cur_input.limit_field;
      {
        ;
        print(654);
        term_input ();
      }
      if (last > first)
      {
        {
          integer for_end; k = first;for_end = last - 1;
          if (k <= for_end) do
            buffer[k + cur_input.start_field - first] = buffer[k];
            while (k++ < for_end);
        }
        cur_input.limit_field = cur_input.start_field + last - first;
      }
    }
  }
}
/* 685 */
halfword scan_toks (command_code terminator, halfword substlist, halfword tailend, small_number suffixcount)
{
  halfword Result;
  halfword p;
  halfword q;
  integer balance;

  p = mem_top - 2;
  balance = 1;
  mem[mem_top - 2].hh.rh = 0;
  while (true)
  {
    get_next ();
    if (cur_sym > 0)
    {
      {
        q = substlist;
        while (q != 0)
        {
          if (mem[q].hh.lh == cur_sym)
          {
            cur_sym = mem[q + 1].cint;
            cur_cmd = 7;
            goto found;
          }
          q = mem[q].hh.rh;
        }
        found:;
      }
      if (cur_cmd == terminator)
      {
        if (cur_mod > 0)
          incr (balance);
        else
        {
          decr (balance);
          if (balance == 0)
            goto done;
        }
      }
      else if (cur_cmd == 61)
      {
        if (cur_mod == 0)
          get_next ();
        else if (cur_mod <= suffixcount)
          cur_sym = 9919 + cur_mod;
      }
    }
    mem[p].hh.rh = cur_tok ();
    p = mem[p].hh.rh;
  }
done:
  mem[p].hh.rh = tailend;
  flush_node_list (substlist);
  Result = mem[mem_top - 2].hh.rh;
  return Result;
}
/* 691 */
void get_symbol (void)
{
lab_restart:
  get_next ();
  if ((cur_sym == 0) || (cur_sym > 9757))
  {
    print_err("Missing symbolic token inserted");
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
      if (str_ref[cur_mod] < 127)
      {
        if (str_ref[cur_mod] > 1)
          decr (str_ref[cur_mod]);
        else
          flush_string (cur_mod);
      }
    }
    cur_sym = 9757;
    ins_error ();
    goto lab_restart;
  }
}
/* 692 */
void get_clear_symbol (void)
{
  get_symbol ();
  clear_symbol (cur_sym, false);
}
/* 693 */
void check_equals (void)
{
  if (cur_cmd != 51)
  {
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
      back_error ();
    }
  }
}
/* 694 */
void make_op_def (void)
{
  command_code m;
  halfword p, q, r;

  m = cur_mod;
  get_symbol ();
  q = get_node (2);
  mem[q].hh.lh = cur_sym;
  mem[q + 1].cint = 9770;
  get_clear_symbol ();
  warning_info = cur_sym;
  get_symbol ();
  p = get_node (2);
  mem[p].hh.lh = cur_sym;
  mem[p + 1].cint = 9771;
  mem[p].hh.rh = q;
  get_next ();
  check_equals ();
  scanner_status = 5;
  q = get_avail ();
  mem[q].hh.lh = 0;
  r = get_avail ();
  mem[q].hh.rh = r;
  mem[r].hh.lh = 0;
  mem[r].hh.rh = scan_toks (16, p, 0, 0);
  scanner_status = 0;
  eqtb[warning_info].lh = m;
  eqtb[warning_info].v.RH = q;
  get_x_next ();
}
/* 1032 */
void check_delimiter (halfword ldelim, halfword rdelim)
{
  if (cur_cmd == 62)
  {
    if (cur_mod == ldelim)
      goto lab_exit;
  }
  if (cur_sym != rdelim)
  {
    missing_err (hash[rdelim].v.RH);
    {
      help_ptr = 2;
      help_line[1] = 922;
      help_line[0] = 923;
    }
    back_error ();
  }
  else
  {
    print_err("The token `");
    slow_print(hash[rdelim].v.RH);
    print(925);
    {
      help_ptr = 3;
      help_line[2] = 926;
      help_line[1] = 927;
      help_line[0] = 928;
    }
    error ();
  }
  lab_exit:;
}
/* 1011 */
halfword scan_declared_variable (void)
{
  halfword Result;
  halfword x;
  halfword h, t;
  halfword l;

  get_symbol ();
  x = cur_sym;
  if (cur_cmd != 41)
    clear_symbol (x, false);
  h = get_avail ();
  mem[h].hh.lh = x;
  t = h;
  while (true)
  {
    get_x_next ();
    if (cur_sym == 0)
      goto done;
    if (cur_cmd != 41)
    {
      if (cur_cmd != 40)
      {
        if (cur_cmd == 63)
        {
          l = cur_sym;
          get_x_next ();
          if (cur_cmd != 64)
          {
            back_input ();
            cur_sym = l;
            cur_cmd = 63;
            goto done;
          }
          else
            cur_sym = 0;
        }
        else
          goto done;
      }
    }
    mem[t].hh.rh = get_avail ();
    t = mem[t].hh.rh;
    mem[t].hh.lh = cur_sym;
  }
done:
  if (eqtb[x].lh % 86 != 41)
    clear_symbol (x, false);
  if (eqtb[x].v.RH == 0)
    new_root (x);
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
  q = get_avail ();
  mem[q].hh.lh = 0;
  r = 0;
  if (m == 1)
  {
    get_clear_symbol ();
    warning_info = cur_sym;
    get_next ();
    scanner_status = 5;
    n = 0;
    eqtb[warning_info].lh = 10;
    eqtb[warning_info].v.RH = q;
  }
  else
  {
    p = scan_declared_variable ();
    flush_variable (eqtb[mem[p].hh.lh].v.RH, mem[p].hh.rh, true);
    warning_info = find_variable (p);
    flush_list (p);
    if (warning_info == 0)
    {
      print_err("This variable already starts with a macro");
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
    if (cur_cmd == 61)
    {
      if (cur_mod == 3)
      {
        n = 3;
        get_next ();
      }
    }
    mem[warning_info].hh.b0 = 20 + n;
    mem[warning_info + 1].cint = q;
  }
  k = n;
  if (cur_cmd == 31)
    do {
      ldelim = cur_sym;
      rdelim = cur_mod;
      get_next ();
      if ((cur_cmd == 56) && (cur_mod >= 9770))
        base = cur_mod;
      else
      {
        print_err("Missing parameter type; `expr' will be assumed");
        {
          help_ptr = 1;
          help_line[0] = 686;
        }
        back_error ();
        base = 9770;
      }
      do {
        mem[q].hh.rh = get_avail ();
        q = mem[q].hh.rh;
        mem[q].hh.lh = base + k;
        get_symbol ();
        p = get_node (2);
        mem[p + 1].cint = base + k;
        mem[p].hh.lh = cur_sym;
        if (k == 150)
          overflow (687, 150);
        incr (k);
        mem[p].hh.rh = r;
        r = p;
        get_next ();
      } while (!(cur_cmd != 82));
      check_delimiter (ldelim, rdelim);
      get_next ();
    } while (!(cur_cmd != 31));
  if (cur_cmd == 56)
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
      overflow (687, 150);
    incr (k);
    get_symbol ();
    mem[p].hh.lh = cur_sym;
    mem[p].hh.rh = r;
    r = p;
    get_next ();
    if (c == 4)
    {
      if (cur_cmd == 69)
      {
        c = 5;
        p = get_node (2);
        if (k == 150)
          overflow (687, 150);
        mem[p + 1].cint = 9770 + k;
        get_symbol ();
        mem[p].hh.lh = cur_sym;
        mem[p].hh.rh = r;
        r = p;
        get_next ();
      }
    }
  }
  check_equals ();
  p = get_avail ();
  mem[p].hh.lh = c;
  mem[q].hh.rh = p;
  if (m == 1)
    mem[p].hh.rh = scan_toks (16, r, 0, n);
  else
  {
    q = get_avail ();
    mem[q].hh.lh = bg_loc;
    mem[p].hh.rh = q;
    p = get_avail ();
    mem[p].hh.lh = eg_loc;
    mem[q].hh.rh = scan_toks (16, r, p, n);
  }
  if (warning_info == 21)
    flush_token_list (mem[22].cint);
  scanner_status = 0;
  get_x_next ();
}
/* 722 */
void print_macro_name (halfword a, halfword n)
{
  halfword p, q;

  if (n != 0)
    slow_print(hash[n].v.RH);
  else
  {
    p = mem[a].hh.lh;
    if (p == 0)
      slow_print(hash[mem[mem[mem[a].hh.rh].hh.lh].hh.lh].v.RH);
    else
    {
      q = p;
      while (mem[q].hh.rh != 0)
        q = mem[q].hh.rh;
      mem[q].hh.rh = mem[mem[a].hh.rh].hh.lh;
      show_token_list (p, 0, 1000, 0);
      mem[q].hh.rh = 0;
    }
  }
}
/* 723 */
void print_arg (halfword q, integer n, halfword b)
{
  if (mem[q].hh.rh == 1)
    print_nl(498);
  else if ((b < 10070) && (b != 7))
    print_nl(499);
  else
    print_nl(500);
  print_int (n);
  print(703);
  if (mem[q].hh.rh == 1)
    print_exp (q, 1);
  else
    show_token_list (q, 0, 1000, 0);
}
/* 730 */
void scan_text_arg (halfword ldelim, halfword rdelim)
{
  integer balance;
  halfword p;

  warning_info = ldelim;
  scanner_status = 3;
  p = mem_top - 2;
  balance = 1;
  mem[mem_top - 2].hh.rh = 0;
  while (true)
  {
    get_next ();
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
    else
    {
      if (cur_cmd == 62)
      {
        if (cur_mod == ldelim)
        {
          decr (balance);
          if (balance == 0)
            goto done;
        }
      }
      else if (cur_cmd == 31)
      {
        if (cur_mod == rdelim)
          incr (balance);
      }
    }
    mem[p].hh.rh = cur_tok ();
    p = mem[p].hh.rh;
  }
done:
  cur_exp = mem[mem_top - 2].hh.rh;
  cur_type = 20;
  scanner_status = 0;
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
  incr (mem[defref].hh.lh);
  if (arg_list == 0)
    n = 0;
  else
  {
    n = 1;
    tail = arg_list;
    while (mem[tail].hh.rh != 0)
    {
      incr (n);
      tail = mem[tail].hh.rh;
    }
  }
  if (internal[9] > 0)
  {
    begin_diagnostic ();
    print_ln ();
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
        incr (n);
        p = mem[p].hh.rh;
      } while (!(p == 0));
    }
    end_diagnostic (false);
  }
  cur_cmd = 83;
  while (mem[r].hh.lh >= 9770)
  {
    if (cur_cmd != 82)
    {
      get_x_next ();
      if (cur_cmd != 31)
      {
        print_err("Missing argument to ");
        print_macro_name (arg_list, macro_name);
        {
          help_ptr = 3;
          help_line[2] = 710;
          help_line[1] = 711;
          help_line[0] = 712;
        }
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
        back_error ();
        cur_cmd = 62;
        goto found;
      }
      ldelim = cur_sym;
      rdelim = cur_mod;
    }
    if (mem[r].hh.lh >= 10070)
      scan_text_arg (ldelim, rdelim);
    else
    {
      get_x_next ();
      if (mem[r].hh.lh >= 9920)
        scan_suffix ();
      else
        scan_expression ();
    }
    if (cur_cmd != 82)
    {
      if ((cur_cmd != 62) || (cur_mod != ldelim))
      {
        if (mem[mem[r].hh.rh].hh.lh >= 9770)
        {
          missing_err (44);
          {
            help_ptr = 3;
            help_line[2] = 713;
            help_line[1] = 714;
            help_line[0] = 708;
          }
          back_error ();
          cur_cmd = 82;
        }
        else
        {
          missing_err (hash[rdelim].v.RH);
          {
            help_ptr = 2;
            help_line[1] = 715;
            help_line[0] = 708;
          }
          back_error ();
        }
      }
    }
  found:
    {
      p = get_avail ();
      if (cur_type == 20)
        mem[p].hh.lh = cur_exp;
      else
        mem[p].hh.lh = stash_cur_exp ();
      if (internal[9] > 0)
      {
        begin_diagnostic ();
        print_arg (mem[p].hh.lh, n, mem[r].hh.lh);
        end_diagnostic (false);
      }
      if (arg_list == 0)
        arg_list = p;
      else
        mem[tail].hh.rh = p;
      tail = p;
      incr (n);
    }
    r = mem[r].hh.rh;
  }
  if (cur_cmd == 82)
  {
    print_err("Too many arguments to ");
    print_macro_name (arg_list, macro_name);
    print_char(59);
    print_nl(705);
    slow_print(hash[rdelim].v.RH);
    print(299);
    {
      help_ptr = 3;
      help_line[2] = 706;
      help_line[1] = 707;
      help_line[0] = 708;
    }
    error ();
  }
  if (mem[r].hh.lh != 0)
  {
    if (mem[r].hh.lh < 7)
    {
      get_x_next ();
      if (mem[r].hh.lh != 6)
      {
        if ((cur_cmd == 51) || (cur_cmd == 77))
          get_x_next ();
      }
    }
    switch (mem[r].hh.lh)
    {
      case 1:
        scan_primary ();
        break;
      case 2:
        scan_secondary ();
        break;
      case 3:
        scan_tertiary ();
        break;
      case 4:
        scan_expression ();
        break;
      case 5:
        {
          scan_expression ();
          p = get_avail ();
          mem[p].hh.lh = stash_cur_exp ();
          if (internal[9] > 0)
          {
            begin_diagnostic ();
            print_arg (mem[p].hh.lh, n, 0);
            end_diagnostic (false);
          }
          if (arg_list == 0)
            arg_list = p;
          else
            mem[tail].hh.rh = p;
          tail = p;
          incr (n);
          if (cur_cmd != 69)
          {
            missing_err (479);
            print(716);
            print_macro_name (arg_list, macro_name);
            {
              help_ptr = 1;
              help_line[0] = 717;
            }
            back_error ();
          }
          get_x_next ();
          scan_primary ();
        }
        break;
      case 6:
        {
          if (cur_cmd != 31)
            ldelim = 0;
          else
          {
            ldelim = cur_sym;
            rdelim = cur_mod;
            get_x_next ();
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
              back_error ();
            }
            get_x_next ();
          }
        }
        break;
      case 7:
        scan_text_arg (0, 0);
        break;
    }
    back_input ();
    {
      p = get_avail ();
      if (cur_type == 20)
        mem[p].hh.lh = cur_exp;
      else
        mem[p].hh.lh = stash_cur_exp ();
      if (internal[9] > 0)
      {
        begin_diagnostic ();
        print_arg (mem[p].hh.lh, n, mem[r].hh.lh);
        end_diagnostic (false);
      }
      if (arg_list == 0)
        arg_list = p;
      else
        mem[tail].hh.rh = p;
      tail = p;
      incr (n);
    }
  }
  r = mem[r].hh.rh;
  while ((cur_input.index_field > 15) && (cur_input.loc_field == 0))
    end_token_list ();
  if (param_ptr + n > max_param_stack)
  {
    max_param_stack = param_ptr + n;
    if (max_param_stack > 150)
      overflow (687, 150);
  }
  begin_token_list (defref, 21);
  cur_input.name_field = macro_name;
  cur_input.loc_field = r;
  if (n > 0)
  {
    p = arg_list;
    do {
      param_stack[param_ptr] = mem[p].hh.lh;
      incr (param_ptr);
      p = mem[p].hh.rh;
    } while (!(p == 0));
    flush_list (arg_list);
  }
}
/* 707 */
void expand (void)
{
  halfword p;
  integer k;
  pool_pointer j;

  if (internal[7] > 65536L)
  {
    if (cur_cmd != 10)
      show_cmd_mod (cur_cmd, cur_mod);
  }
  switch (cur_cmd)
  {
    case 1:
      conditional ();
      break;
    case 2:
      if (cur_mod > if_limit)
      {
        if (if_limit == 1)
        {
          missing_err (58);
          back_input ();
          cur_sym = 9762;
          ins_error ();
        }
        else
        {
          print_err("Extra ");
          print_cmd_mod (2, cur_mod);
          {
            help_ptr = 1;
            help_line[0] = 725;
          }
          error ();
        }
      }
      else
      {
        while (cur_mod != 2) pass_text ();
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
    case 3:
      if (cur_mod > 0)
        force_eof = true;
      else
        start_input ();
      break;
    case 4:
      if (cur_mod == 0)
      {
        print_err("Extra `endfor'");
        {
          help_ptr = 2;
          help_line[1] = 689;
          help_line[0] = 690;
        }
        error ();
      }
      else
        begin_iteration ();
      break;
    case 5:
      {
        while ((cur_input.index_field > 15) && (cur_input.loc_field == 0))
          end_token_list ();
        if (loop_ptr == 0)
        {
          print_err("Lost loop");
          {
            help_ptr = 2;
            help_line[1] = 693;
            help_line[0] = 694;
          }
          error ();
        }
        else
          resume_iteration ();
      }
      break;
    case 6:
      {
        get_boolean ();
        if (internal[7] > 65536L)
          show_cmd_mod (33, cur_exp);
        if (cur_exp == 30)
        {
          if (loop_ptr == 0)
          {
            print_err("No loop is in progress");
            {
              help_ptr = 1;
              help_line[0] = 696;
            }
            if (cur_cmd == 83)
              error ();
            else
              back_error ();
          }
          else
          {
            p = 0;
            do {
              if ((cur_input.index_field <= 15))
                end_file_reading ();
              else
              {
                if (cur_input.index_field <= 17)
                  p = cur_input.start_field;
                end_token_list ();
              }
            } while (!(p != 0));
            if (p != mem[loop_ptr].hh.lh)
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
          back_error ();
        }
      }
      break;
    case 7:
      ;
      break;
    case 9:
      {
        get_next ();
        p = cur_tok ();
        get_next ();
        if (cur_cmd < 11)
          expand ();
        else
          back_input ();
        begin_token_list (p, 19);
      }
      break;
    case 8:
      {
        get_x_next ();
        scan_primary ();
        if (cur_type != 4)
        {
          disp_err (0, 700);
          {
            help_ptr = 2;
            help_line[1] = 701;
            help_line[0] = 702;
          }
          put_get_flush_error (0);
        }
        else
        {
          back_input ();
          if ((str_start[cur_exp + 1] - str_start[cur_exp]) > 0)
          {
            begin_file_reading ();
            cur_input.name_field = 2;
            k = first + (str_start[cur_exp + 1] - str_start[cur_exp]);
            if (k >= max_buf_stack)
            {
              if (k >= buf_size)
              {
                max_buf_stack = buf_size;
                overflow (256, buf_size);
              }
              max_buf_stack = k + 1;
            }
            j = str_start[cur_exp];
            cur_input.limit_field = k;
            while (first < cur_input.limit_field)
            {
              buffer[first] = str_pool[j];
              incr (j);
              incr (first);
            }
            buffer[cur_input.limit_field] = 37;
            first = cur_input.limit_field + 1;
            cur_input.loc_field = cur_input.start_field;
            flush_cur_exp (0);
          }
        }
      }
      break;
    case 10:
      macro_call (cur_mod, 0, cur_sym);
      break;
  }
}
/* 718 */
void get_x_next (void)
{
  halfword save_exp;

  get_next ();
  if (cur_cmd < 11)
  {
    save_exp = stash_cur_exp ();
    do {
      if (cur_cmd == 10)
        macro_call (cur_mod, 0, cur_sym);
      else
        expand ();
      get_next ();
    } while (!(cur_cmd >= 11));
    unstash_cur_exp (save_exp);
  }
}
/* 737 */
void stack_argument (halfword p)
{
  if (param_ptr == max_param_stack)
  {
    incr (max_param_stack);
    if (max_param_stack > 150)
      overflow (687, 150);
  }
  param_stack[param_ptr] = p;
  incr (param_ptr);
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
    get_next ();
    if (cur_cmd <= 2)
    {
      if (cur_cmd < 2)
        incr (l);
      else
      {
        if (l == 0)
          goto done;
        if (cur_mod == 2)
          decr (l);
      }
    }
    else if (cur_cmd == 39)
    {
      if (str_ref[cur_mod] < 127)
      {
        if (str_ref[cur_mod] > 1)
          decr (str_ref[cur_mod]);
        else
          flush_string (cur_mod);
      }
    }
  }
done:
  scanner_status = 0;
}
/* 746 */
void change_if_limit (small_number l, halfword p)
{
  halfword q;

  if (p == cond_ptr)
    if_limit = l;
  else
  {
    q = cond_ptr;
    while (true)
    {
      if (q == 0)
        confusion(718);
      if (mem[q].hh.rh == p)
      {
        mem[q].hh.b0 = l;
        goto lab_exit;
      }
      q = mem[q].hh.rh;
    }
  }
  lab_exit:;
}
/* 747 */
void check_colon (void)
{
  if (cur_cmd != 81)
  {
    missing_err (58);
    {
      help_ptr = 2;
      help_line[1] = 721;
      help_line[0] = 698;
    }
    back_error ();
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
  lab_reswitch: get_boolean ();
  new_if_limit = 4;
  if (internal[7] > 65536L)
  {
    begin_diagnostic ();
    if (cur_exp == 30)
      print(722);
    else
      print(723);
    end_diagnostic (false);
  }
found:
  check_colon ();
  if (cur_exp == 30)
  {
    change_if_limit (new_if_limit, savecond_ptr);
    goto lab_exit;
  }
  while (true)
  {
    pass_text ();
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
    get_x_next ();
    goto found;
  }
  lab_exit:;
}
/* 754 */
void bad_for (str_number s)
{
  disp_err (0, 726);
  print(s);
  print(306);
  {
    help_ptr = 4;
    help_line[3] = 727;
    help_line[2] = 728;
    help_line[1] = 729;
    help_line[0] = 308;
  }
  put_get_flush_error (0);
}
/* 755 */
void begin_iteration (void)
{
  halfword m;
  halfword n;
  halfword p, q, s, pp;

  m = cur_mod;
  n = cur_sym;
  s = get_node (2);
  if (m == 1)
  {
    mem[s + 1].hh.lh = 1;
    p = 0;
    get_x_next ();
    goto found;
  }
  get_symbol ();
  p = get_node (2);
  mem[p].hh.lh = cur_sym;
  mem[p + 1].cint = m;
  get_x_next ();
  if ((cur_cmd != 51) && (cur_cmd != 77))
  {
    missing_err (61);
    {
      help_ptr = 3;
      help_line[2] = 730;
      help_line[1] = 673;
      help_line[0] = 731;
    }
    back_error ();
  }
  mem[s + 1].hh.lh = 0;
  q = s + 1;
  mem[q].hh.rh = 0;
  do {
    get_x_next ();
    if (m != 9770)
      scan_suffix ();
    else
    {
      if (cur_cmd >= 81)
      {
        if (cur_cmd <= 82)
          goto lab_continue;
      }
      scan_expression ();
      if (cur_cmd == 74)
      {
        if (q == s + 1)
        {
          if (cur_type != 16)
            bad_for (737);
          pp = get_node (4);
          mem[pp + 1].cint = cur_exp;
          get_x_next ();
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
            back_error ();
          }
          get_x_next ();
          scan_expression ();
          if (cur_type != 16)
            bad_for (741);
          mem[pp + 3].cint = cur_exp;
          mem[s + 1].hh.lh = pp;
          goto done;
        }
      }
      cur_exp = stash_cur_exp ();
    }
    mem[q].hh.rh = get_avail ();
    q = mem[q].hh.rh;
    mem[q].hh.lh = cur_exp;
    cur_type = 1;
    lab_continue:;
  } while (!(cur_cmd != 82));
done:;
found:
  if (cur_cmd != 81)
  {
    missing_err (58);
    {
      help_ptr = 3;
      help_line[2] = 732;
      help_line[1] = 733;
      help_line[0] = 734;
    }
    back_error ();
  }
  q = get_avail ();
  mem[q].hh.lh = 9758;
  scanner_status = 6;
  warning_info = n;
  mem[s].hh.lh = scan_toks (4, p, q, 0);
  scanner_status = 0;
  mem[s].hh.rh = loop_ptr;
  loop_ptr = s;
  resume_iteration ();
}
/* 760 */
void resume_iteration (void)
{
  halfword p, q;

  p = mem[loop_ptr + 1].hh.lh;
  if (p > 1)
  {
    cur_exp = mem[p + 1].cint;
    if (((mem[p + 2].cint > 0) && (cur_exp > mem[p + 3].cint)) || ((mem[p + 2].cint < 0) && (cur_exp < mem[p + 3].cint)))
      goto not_found;
    cur_type = 16;
    q = stash_cur_exp ();
    mem[p + 1].cint = cur_exp + mem[p + 2].cint;
  }
  else if (p < 1)
  {
    p = mem[loop_ptr + 1].hh.rh;
    if (p == 0)
      goto not_found;
    mem[loop_ptr + 1].hh.rh = mem[p].hh.rh;
    q = mem[p].hh.lh;
    {
      mem[p].hh.rh = avail;
      avail = p;
      ;
#ifdef STAT
      decr (dyn_used);
#endif /* STAT */
    }
  }
  else
  {
    begin_token_list (mem[loop_ptr].hh.lh, 16);
    goto lab_exit;
  }
  begin_token_list (mem[loop_ptr].hh.lh, 17);
  stack_argument (q);
  if (internal[7] > 65536L)
  {
    begin_diagnostic ();
    print_nl(736);
    if ((q != 0) && (mem[q].hh.rh == 1))
      print_exp (q, 1);
    else
      show_token_list (q, 0, 50, 0);
    print_char(125);
    end_diagnostic (false);
  }
  goto lab_exit;
not_found:
  stop_iteration ();
lab_exit:;
}
/* 763 */
void stop_iteration (void)
{
  halfword p, q;

  p = mem[loop_ptr + 1].hh.lh;
  if (p > 1)
    free_node (p, 4);
  else if (p < 1)
  {
    q = mem[loop_ptr + 1].hh.rh;
    while (q != 0)
    {
      p = mem[q].hh.lh;
      if (p != 0)
      {
        if (mem[p].hh.rh == 1)
        {
          recycle_value (p);
          free_node (p, 2);
        }
        else
          flush_token_list (p);
      }
      p = q;
      q = mem[q].hh.rh;
      {
        mem[p].hh.rh = avail;
        avail = p;
        ;
#ifdef STAT
        decr (dyn_used);
#endif /* STAT */
      }
    }
  }
  p = loop_ptr;
  loop_ptr = mem[p].hh.rh;
  flush_token_list (mem[p].hh.lh);
  free_node (p, 2);
}
/* 770 */
void begin_name (void)
{
  area_delimiter = 0;
  ext_delimiter = 0;
  quotedfilename = false;
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
          overflow (257, pool_size - init_pool_ptr);
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
/* 772 */
void end_name (void)
{
  boolean mustquote;
  pool_pointer j, s, t;

  if (str_ptr + 3 > max_str_ptr)
  {
    if (str_ptr + 3 > max_strings)
      overflow (258, max_strings - init_str_ptr);
    max_str_ptr = str_ptr + 3;
  }
  {
    if (pool_ptr + 6 > max_pool_ptr)
    {
      if (pool_ptr + 6 > pool_size)
        overflow (257, pool_size - init_pool_ptr);
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
      incr (j);
    }
    if (mustquote)
    {
      {
        integer for_end; j = pool_ptr - 1;for_end = t;
        if (j >= for_end) do
          str_pool[j + 2] = str_pool[j];
          while (j-- > for_end);
      }
      str_pool[t + 1] = 34;
      {
        integer for_end; j = t - 1;for_end = s;
        if (j >= for_end) do
          str_pool[j + 1] = str_pool[j];
          while (j-- > for_end);
      }
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
  else
  {
    mustquote = false;
    s = str_start[str_ptr];
    t = ext_delimiter;
    j = s;
    while ((!mustquote) && (j < t))
    {
      mustquote = str_pool[j] == 32;
      incr (j);
    }
    if (mustquote)
    {
      {
        integer for_end; j = pool_ptr - 1;for_end = t;
        if (j >= for_end) do
          str_pool[j + 2] = str_pool[j];
          while (j-- > for_end);
      }
      str_pool[t + 1] = 34;
      {
        integer for_end; j = t - 1;for_end = s;
        if (j >= for_end) do
          str_pool[j + 1] = str_pool[j];
          while (j-- > for_end);
      }
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
  while ((!mustquote) && (j < t))
  {
    mustquote = str_pool[j] == 32;
    incr (j);
  }
  if (mustquote)
  {
    str_pool[t + 1] = 34;
    {
      integer for_end; j = t - 1;for_end = s;
      if (j >= for_end) do
        str_pool[j + 1] = str_pool[j];
        while (j-- > for_end);
    }
    str_pool[s] = 34;
    pool_ptr = pool_ptr + 2;
  }
  if (ext_delimiter == 0)
    cur_name = make_string ();
  else
    cur_ext = make_string ();
}
/* 774 */
void pack_file_name (str_number n, str_number a, str_number e)
{
  integer k;
  ASCII_code c;
  pool_pointer j;

  k = 0;
  if (name_of_file)
    libcfree (name_of_file);
  name_of_file = xmallocarray (ASCII_code, (str_start[a + 1] - str_start[a]) + (str_start[n + 1] - str_start[n]) + (str_start[e + 1] - str_start[e]) + 1);
  {
    integer for_end; j = str_start[a];for_end = str_start[a + 1] - 1;
    if (j <= for_end) do
    {
      c = str_pool[j];
      if (!(c == 34))
      {
        incr (k);
        if (k <= maxint)
          name_of_file[k] = xchr[c];
      }
    } while (j++ < for_end);
  }
  {
    integer for_end; j = str_start[n];for_end = str_start[n + 1] - 1;
    if (j <= for_end) do
    {
      c = str_pool[j];
      if (!(c == 34))
      {
        incr (k);
        if (k <= maxint)
          name_of_file[k] = xchr[c];
      }
    } while (j++ < for_end);
  }
  {
    integer for_end; j = str_start[e];for_end = str_start[e + 1] - 1;
    if (j <= for_end) do
    {
      c = str_pool[j];
      if (!(c == 34))
      {
        incr (k);
        if (k <= maxint)
          name_of_file[k] = xchr[c];
      }
    } while (j++ < for_end);
  }
  if (k <= maxint)
    name_length = k;
  else
    name_length = maxint;
  name_of_file[name_length + 1] = 0;
}
/* 778 */
void pack_buffered_name (small_number n, integer a, integer b)
{
  integer k;
  ASCII_code c;
  integer j;

  if (n + b - a + 6 > maxint)
    b = a + maxint - n - 6;
  k = 0;
  if (name_of_file)
    libcfree (name_of_file);
  name_of_file = xmallocarray (ASCII_code, n + (b - a + 1) + 6);
  {
    integer for_end; j = 1;for_end = n; 
    if (j <= for_end) do
    {
      c = xord[ucharcast (MF_base_default[j])];
      if (!(c == 34))
      {
        incr (k);
        if (k <= maxint)
          name_of_file[k] = xchr[c];
      }
    } while (j++ < for_end);
  }
  {
    integer for_end; j = a;for_end = b;
    if (j <= for_end) do
    {
      c = buffer[j];
      if (!(c == 34))
      {
        incr (k);
        if (k <= maxint)
          name_of_file[k] = xchr[c];
      }
    } while (j++ < for_end);
  }
  {
    integer for_end; j = base_default_length - 4;for_end = base_default_length;
    if (j <= for_end) do
    {
      c = xord[ucharcast (MF_base_default[j])];
      if (!(c == 34))
      {
        incr (k);
        if (k <= maxint)
          name_of_file[k] = xchr[c];
      }
    } while (j++ < for_end);
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
    {
      integer for_end; k = 1;for_end = name_length;
      if (k <= for_end) do
      {
        str_pool[pool_ptr] = xord[name_of_file[k]];
        incr (pool_ptr);
      } while (k++ < for_end);
    }
    Result = make_string ();
  }
  k = 1;
  begin_name ();
  stopatspace = false;
  while ((k <= name_length) && (more_name (name_of_file[k])))
    incr (k);
  stopatspace = true;
  end_name ();
  return Result;
}
/* 780 */
str_number a_make_name_string (alpha_file f)
{
  str_number Result;
  
  Result = make_name_string ();
  return Result;
}
/* 780 */
str_number b_make_name_string (byte_file f)
{
  str_number Result;
  
  Result = make_name_string ();
  return Result;
}
/* 780 */
str_number w_make_name_string (word_file f)
{
  str_number Result;
  
  Result = make_name_string ();
  return Result;
}
/* 781 */
void scan_file_name (void)
{
  begin_name ();
  while ((buffer[cur_input.loc_field] == 32) || (buffer[cur_input.loc_field] == 9))
    incr (cur_input.loc_field);
  while (true)
  {
    if ((buffer[cur_input.loc_field] == 59) || (buffer[cur_input.loc_field] == 37))
      goto done;
    if (!more_name (buffer[cur_input.loc_field]))
      goto done;
    incr (cur_input.loc_field);
  }
done:
  end_name ();
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

  if (interaction == 2)
    ;
  if (s == 743)
    print_err("I can't find file `");
  else
    print_err("I can't write on file `");
  print_file_name (cur_name, cur_area, cur_ext);
  print(746);
  if (e == 747)
    show_context ();
  print_nl(748);
  print(s);
  if (interaction < 2)
    fatal_error (749);
  saved_cur_name = cur_name;
  {
    ;
    print(262);
    term_input ();
  }
  {
    begin_name ();
    k = first;
    while (((buffer[k] == 32) || (buffer[k] == 9)) && (k < last))
      incr (k);
    while (true)
    {
      if (k == last)
        goto done;
      if (!more_name (buffer[k]))
        goto done;
      incr (k);
    }
  done:
    end_name ();
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
  constcstring months;

  old_setting = selector;
  if (job_name == 0)
    job_name = getjob_name (750);
  pack_job_name (751);
  recorderchangefilename (stringcast (name_of_file + 1));
  pack_job_name (752);
  while (!aopenout (log_file))
  {
    selector = 1;
    prompt_file_name (754, 752);
  }
  texmflogname = a_make_name_string (log_file);
  selector = 2;
  log_opened = true;
  {
    Fputs (log_file,  "This is METAFONT, Version 2.7182818");
    Fputs (log_file,  versionstring);
    slow_print(base_ident);
    print(755);
    print_int (round_unscaled (internal[16]));
    print_char(32);
    months = " JANFEBMARAPRMAYJUNJULAUGSEPOCTNOVDEC";
    m = round_unscaled (internal[15]);
    {
      integer for_end; k = 3 * m - 2;for_end = 3 * m;
      if (k <= for_end) do
        putc (months[k],  log_file);
        while (k++ < for_end);
    }
    print_char(32);
    print_int (round_unscaled (internal[14]));
    print_char(32);
    m = round_unscaled (internal[17]);
    print_dd (m / 60);
    print_char(58);
    print_dd (m % 60);
    if (translatefilename)
    {
      putc ('\n', log_file);
      putc ('(', log_file);
      fputs (translatefilename, log_file);
      putc (')', log_file);
    }
  }
  input_stack[input_ptr] = cur_input;
  print_nl(753);
  l = input_stack[0].limit_field - 1;
  {
    integer for_end; k = 1;for_end = l;
    if (k <= for_end) do
      print(buffer[k]);
      while (k++ < for_end);
  }
  print_ln ();
  selector = old_setting + 2;
}
/* 793 */
void start_input (void)
{
  while ((cur_input.index_field > 15) && (cur_input.loc_field == 0))
    end_token_list ();
  if ((cur_input.index_field > 15))
  {
    print_err("File names can't appear within macros");
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
  else
  {
    cur_name = 261;
    cur_ext = 261;
    cur_area = 261;
  }
  pack_file_name (cur_name, cur_area, cur_ext);
  while (true)
  {
    begin_file_reading ();
    if (cur_ext == 747)
    {
      cur_ext = 261;
      pack_file_name (cur_name, cur_area, cur_ext);
    }
    if (kpseinnameok (stringcast (name_of_file + 1)) && aopenin (input_file[cur_input.index_field], kpsemfformat))
      goto done;
    end_file_reading ();
    prompt_file_name (743, 747);
  }
done:
  cur_input.name_field = a_make_name_string (input_file[cur_input.index_field]);
  str_ref[cur_name] = 127;
  if (job_name == 0)
  {
    job_name = getjob_name (cur_name);
    open_log_file ();
  }
  if (term_offset + (str_start[cur_input.name_field + 1] - str_start[cur_input.name_field]) > max_print_line - 2)
    print_ln ();
  else if ((term_offset > 0) || (file_offset > 0))
    print_char(32);
  print_char(40);
  incr (open_parens);
  slow_print(cur_input.name_field);
  fflush (stdout);
  {
    line = 1;
    if (inputln (input_file[cur_input.index_field], false))
      ;
    firm_up_the_line ();
    buffer[cur_input.limit_field] = 37;
    first = cur_input.limit_field + 1;
    cur_input.loc_field = cur_input.start_field;
  }
}
/* 824 */
void bad_exp (str_number s)
{
  unsigned char saveflag;

  print_err(s);
  print(770);
  print_cmd_mod (cur_cmd, cur_mod);
  print_char(39);
  {
    help_ptr = 4;
    help_line[3] = 771;
    help_line[2] = 772;
    help_line[1] = 773;
    help_line[0] = 774;
  }
  back_input ();
  cur_sym = 0;
  cur_cmd = 42;
  cur_mod = 0;
  ins_error ();
  saveflag = var_flag;
  var_flag = 0;
  get_x_next ();
  var_flag = saveflag;
}
/* 827 */
void stash_in (halfword p)
{
  halfword q;

  mem[p].hh.b0 = cur_type;
  if (cur_type == 16)
    mem[p + 1].cint = cur_exp;
  else
  {
    if (cur_type == 19)
    {
      q = single_dependency (cur_exp);
      if (q == dep_final)
      {
        mem[p].hh.b0 = 16;
        mem[p + 1].cint = 0;
        free_node (q, 2);
      }
      else
      {
        mem[p].hh.b0 = 17;
        new_dep (p, q);
      }
      recycle_value (cur_exp);
    }
    else
    {
      mem[p + 1] = mem[cur_exp + 1];
      mem[mem[p + 1].hh.lh].hh.rh = p;
    }
    free_node (cur_exp, 2);
  }
  cur_type = 1;
}
/* 848 */
void back_expr (void)
{
  halfword p;

  p = stash_cur_exp ();
  mem[p].hh.rh = 0;
  begin_token_list (p, 19);
}
/* 849 */
void bad_sub_script (void)
{
  disp_err (0, 786);
  {
    help_ptr = 3;
    help_line[2] = 787;
    help_line[1] = 788;
    help_line[0] = 789;
  }
  flush_error (0);
}
/* 851 */
void obliterated (halfword q)
{
  print_err("Variable ");
  show_token_list (q, 0, 1000, 0);
  print(791);
  {
    help_ptr = 5;
    help_line[4] = 792;
    help_line[3] = 793;
    help_line[2] = 794;
    help_line[1] = 795;
    help_line[0] = 796;
  }
}
/* 863 */
void binary_mac (halfword p, halfword c, halfword n)
{
  halfword q, r;

  q = get_avail ();
  r = get_avail ();
  mem[q].hh.rh = r;
  mem[q].hh.lh = p;
  mem[r].hh.lh = stash_cur_exp ();
  macro_call (c, q, n);
}
/* 865 */
void materialize_pen (void)
{
  scaled aminusb, aplusb, major_axis, minor_axis;
  angle theta;
  halfword p;
  halfword q;

  q = cur_exp;
  if (mem[q].hh.b0 == 0)
  {
    print_err("Pen path must be a cycle");
    {
      help_ptr = 2;
      help_line[1] = 807;
      help_line[0] = 575;
    }
    put_get_error ();
    cur_exp = 3;
    goto common_ending;
  }
  else if (mem[q].hh.b0 == 4)
  {
    tx = mem[q + 1].cint;
    ty = mem[q + 2].cint;
    txx = mem[q + 3].cint - tx;
    tyx = mem[q + 4].cint - ty;
    txy = mem[q + 5].cint - tx;
    tyy = mem[q + 6].cint - ty;
    aminusb = pyth_add (txx - tyy, tyx + txy);
    aplusb = pyth_add (txx + tyy, tyx - txy);
    major_axis = half (aminusb + aplusb);
    minor_axis = half (abs (aplusb - aminusb));
    if (major_axis == minor_axis)
      theta = 0;
    else
      theta = half (n_arg (txx - tyy, tyx + txy) + n_arg (txx + tyy, tyx - txy));
    free_node (q, 7);
    q = make_ellipse (major_axis, minor_axis, theta);
    if ((tx != 0) || (ty != 0))
    {
      p = q;
      do {
        mem[p + 1].cint = mem[p + 1].cint + tx;
        mem[p + 2].cint = mem[p + 2].cint + ty;
        p = mem[p].hh.rh;
      } while (!(p == q));
    }
  }
  cur_exp = make_pen (q);
  common_ending: toss_knot_list (q);
  cur_type = 6;
}
/* 872 */
void known_pair (void)
{
  halfword p;

  if (cur_type != 14)
  {
    disp_err (0, 809);
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
  else
  {
    p = mem[cur_exp + 1].cint;
    if (mem[p].hh.b0 == 16)
      cur_x = mem[p + 1].cint;
    else
    {
      disp_err (p, 815);
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
    if (mem[p + 2].hh.b0 == 16)
      cur_y = mem[p + 3].cint;
    else
    {
      disp_err (p + 2, 817);
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
/* 871 */
halfword new_knot (void)
{
  halfword Result;
  halfword q;

  q = get_node (7);
  mem[q].hh.b0 = 0;
  mem[q].hh.b1 = 0;
  mem[q].hh.rh = q;
  known_pair ();
  mem[q + 1].cint = cur_x;
  mem[q + 2].cint = cur_y;
  Result = q;
  return Result;
}
/* 875 */
small_number scan_direction (void)
{
  small_number Result;
  unsigned char t;
  scaled x;

  get_x_next ();
  if (cur_cmd == 60)
  {
    get_x_next ();
    scan_expression ();
    if ((cur_type != 16) || (cur_exp < 0))
    {
      disp_err (0, 821);
      {
        help_ptr = 1;
        help_line[0] = 822;
      }
      put_get_flush_error (65536L);
    }
    t = 3;
  }
  else
  {
    scan_expression ();
    if (cur_type > 14)
    {
      if (cur_type != 16)
      {
        disp_err (0, 815);
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
        back_error ();
      }
      get_x_next ();
      scan_expression ();
      if (cur_type != 16)
      {
        disp_err (0, 817);
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
    else
      known_pair ();
    if ((cur_x == 0) && (cur_y == 0))
      t = 4;
    else
    {
      t = 2;
      cur_exp = n_arg (cur_x, cur_y);
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
    back_error ();
  }
  get_x_next ();
  Result = t;
  return Result;
}
/* 895 */
void do_nullary (quarterword c)
{
  integer k;

  check_arith ();
  if (internal[7] > 131072L)
    show_cmd_mod (33, c);
  switch (c)
  {
    case 30:
    case 31:
      {
        cur_type = 2;
        cur_exp = c;
      }
      break;
    case 32:
      {
        cur_type = 11;
        cur_exp = get_node (6);
        init_edges (cur_exp);
      }
      break;
    case 33:
      {
        cur_type = 6;
        cur_exp = 3;
      }
      break;
    case 37:
      {
        cur_type = 16;
        cur_exp = norm_rand ();
      }
      break;
    case 36:
      {
        cur_type = 8;
        cur_exp = get_node (7);
        mem[cur_exp].hh.b0 = 4;
        mem[cur_exp].hh.b1 = 4;
        mem[cur_exp].hh.rh = cur_exp;
        mem[cur_exp + 1].cint = 0;
        mem[cur_exp + 2].cint = 0;
        mem[cur_exp + 3].cint = 65536L;
        mem[cur_exp + 4].cint = 0;
        mem[cur_exp + 5].cint = 0;
        mem[cur_exp + 6].cint = 65536L;
      }
      break;
    case 34:
      {
        if (job_name == 0)
          open_log_file ();
        cur_type = 4;
        cur_exp = job_name;
      }
      break;
    case 35:
      {
        if (interaction <= 1)
          fatal_error (835);
        begin_file_reading ();
        cur_input.name_field = 1;
        {
          ;
          print(261);
          term_input ();
        }
        {
          if (pool_ptr + last - cur_input.start_field > max_pool_ptr)
          {
            if (pool_ptr + last - cur_input.start_field > pool_size)
              overflow (257, pool_size - init_pool_ptr);
            max_pool_ptr = pool_ptr + last - cur_input.start_field;
          }
        }
        {
          integer for_end; k = cur_input.start_field;for_end = last - 1;
          if (k <= for_end) do
          {
            str_pool[pool_ptr] = buffer[k];
            incr (pool_ptr);
          } while (k++ < for_end);
        }
        end_file_reading ();
        cur_type = 4;
        cur_exp = make_string ();
      }
      break;
  }
  check_arith ();
}
/* 899 */
boolean nice_pair (integer p, quarterword t)
{
  boolean Result;

  if (t == 14)
  {
    p = mem[p + 1].cint;
    if (mem[p].hh.b0 == 16)
    {
      if (mem[p + 2].hh.b0 == 16)
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
  print_char(40);
  if (t < 17)
  {
    if (t != 14)
      print_type (t);
    else if (nice_pair (v, 14))
      print(336);
    else
      print(836);
  }
  else
    print(837);
  print_char(41);
}
/* 901 */
void bad_unary (quarterword c)
{
  disp_err (0, 838);
  print_op (c);
  print_known_or_unknown_type (cur_type, cur_exp);
  {
    help_ptr = 3;
    help_line[2] = 839;
    help_line[1] = 840;
    help_line[0] = 841;
  }
  put_get_error ();
}
/* 904 */
void negate_dep_list (halfword p)
{
  while (true)
  {
    mem[p + 1].cint = -mem[p + 1].cint;
    if (mem[p].hh.lh == 0)
      goto lab_exit;
    p = mem[p].hh.rh;
  }
  lab_exit:;
}
/* 908 */
void pair_to_path (void)
{
  cur_exp = new_knot ();
  cur_type = 9;
}
/* 910 */
void take_part (quarterword c)
{
  halfword p;

  p = mem[cur_exp + 1].cint;
  mem[18].cint = p;
  mem[17].hh.b0 = cur_type;
  mem[p].hh.rh = 17;
  free_node (cur_exp, 2);
  make_exp_copy (p + 2 * (c - 53));
  recycle_value (17);
}
/* 913 */
void str_to_num (quarterword c)
{
  integer n;
  ASCII_code m;
  pool_pointer k;
  unsigned char b;
  boolean badchar;

  if (c == 49)
  {
    if ((str_start[cur_exp + 1] - str_start[cur_exp]) == 0)
      n = -1;
    else
      n = str_pool[str_start[cur_exp]];
  }
  else
  {
    if (c == 47)
      b = 8;
    else
      b = 16;
    n = 0;
    badchar = false;
    {
      integer for_end; k = str_start[cur_exp];for_end = str_start[cur_exp + 1] - 1;
      if (k <= for_end) do
      {
        m = str_pool[k];
        if ((m >= 48) && (m <= 57))
          m = m - 48;
        else if ((m >= 65) && (m <= 70))
          m = m - 55;
        else if ((m >= 97) && (m <= 102))
          m = m - 87;
        else
        {
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
        else
          n = 32767;
      } while (k++ < for_end);
    }
    if (badchar)
    {
      disp_err (0, 843);
      if (c == 47)
      {
        help_ptr = 1;
        help_line[0] = 844;
      }
      else
      {
        help_ptr = 1;
        help_line[0] = 845;
      }
      put_get_error ();
    }
    if (n > 4095)
    {
      print_err("Number too large (");
      print_int (n);
      print_char(41);
      {
        help_ptr = 1;
        help_line[0] = 847;
      }
      put_get_error ();
    }
  }
  flush_cur_exp (n * 65536L);
}
/* 916 */
scaled path_length (void)
{
  scaled Result;
  scaled n;
  halfword p;

  p = cur_exp;
  if (mem[p].hh.b0 == 0)
    n = -65536L;
  else
    n = 0;
  do {
    p = mem[p].hh.rh;
    n = n + 65536L;
  } while (!(p == cur_exp));
  Result = n;
  return Result;
}
/* 919 */
void test_known (quarterword c)
{
  unsigned char b;
  halfword p, q;

  b = 31;
  switch (cur_type)
  {
    case 1:
    case 2:
    case 4:
    case 6:
    case 8:
    case 9:
    case 11:
    case 16:
      b = 30;
      break;
    case 13:
    case 14:
      {
        p = mem[cur_exp + 1].cint;
        q = p + big_node_size[cur_type];
        do {
          q = q - 2;
          if (mem[q].hh.b0 != 16)
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
  else
    flush_cur_exp (61 - b);
  cur_type = 2;
}
/* 895 */
void do_unary (quarterword c)
{
  halfword p, q;
  integer x;

  check_arith ();
  if (internal[7] > 131072L)
  {
    begin_diagnostic ();
    print_nl(123);
    print_op (c);
    print_char(40);
    print_exp (0, 0);
    print(842);
    end_diagnostic (false);
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
            if (odd (round_unscaled (cur_exp)))
              cur_exp = 30;
            else
              cur_exp = 31;
            cur_type = 2;
          }
          break;
        case 66:
          {
            cur_exp = round_unscaled (cur_exp) % 256;
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
        cur_exp = round_unscaled (cur_exp) % 256;
        cur_type = 4;
        if (cur_exp < 0)
          cur_exp = cur_exp + 256;
        if ((str_start[cur_exp + 1] - str_start[cur_exp]) != 1)
        {
          {
            if (pool_ptr + 1 > max_pool_ptr)
            {
              if (pool_ptr + 1 > pool_size)
                overflow (257, pool_size - init_pool_ptr);
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
    case 42:
      if (cur_type != 16)
        bad_unary (42);
      else
      {
        old_setting = selector;
        selector = 5;
        print_scaled(cur_exp);
        cur_exp = make_string ();
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
        flush_cur_exp ((str_start[cur_exp + 1] - str_start[cur_exp]) * 65536L);
      else if (cur_type == 9)
        flush_cur_exp (path_length ());
      else if (cur_type == 16)
        cur_exp = abs (cur_exp);
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
        cur_path_type = 1;
        cur_exp = make_spec (cur_exp, -1879080960L, 0);
        flush_cur_exp (turning_number * 65536L);
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
          pair_to_path ();
        if (cur_type == 9)
          cur_type = 8;
        else
          bad_unary (45);
      }
      break;
    case 44 :
      {
        if (cur_type == 8)
          materialize_pen ();
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
        pair_to_path ();
      else
        bad_unary (43);
      break;
  }
  check_arith ();
}
/* 923 */
void bad_binary (halfword p, quarterword c)
{
  disp_err (p, 261);
  disp_err (0, 838);
  if (c >= 94)
    print_op (c);
  print_known_or_unknown_type (mem[p].hh.b0, p);
  if (c >= 94)
    print(479);
  else
    print_op (c);
  print_known_or_unknown_type (cur_type, cur_exp);
  {
    help_ptr = 3;
    help_line[2] = 839;
    help_line[1] = 848;
    help_line[0] = 849;
  }
  put_get_error ();
}
/* 928 */
halfword tarnished (halfword p)
{
  halfword Result;
  halfword q;
  halfword r;

  q = mem[p + 1].cint;
  r = q + big_node_size[mem[p].hh.b0];
  do {
    r = r - 2;
    if (mem[r].hh.b0 == 19)
    {
      Result = 1;
      goto lab_exit;
    }
  } while (!(r == q));
  Result = 0;
  lab_exit:;
  return Result;
}
/* 935 */
void dep_finish (halfword v, halfword q, small_number t)
{
  halfword p;
  scaled vv;

  if (q == 0)
    p = cur_exp;
  else
    p = q;
  mem[p + 1].hh.rh = v;
  mem[p].hh.b0 = t;
  if (mem[v].hh.lh == 0)
  {
    vv = mem[v + 1].cint;
    if (q == 0)
      flush_cur_exp (vv);
    else
    {
      recycle_value (p);
      mem[q].hh.b0 = 16;
      mem[q + 1].cint = vv;
    }
  }
  else if (q == 0)
    cur_type = t;
  if (fix_needed)
    fix_dependencies ();
}
/* 930 */
void add_or_subtract (halfword p, halfword q, quarterword c)
{
  small_number s, t;
  halfword r;
  integer v;

  if (q == 0)
  {
    t = cur_type;
    if (t < 17)
      v = cur_exp;
    else
      v = mem[cur_exp + 1].hh.rh;
  }
  else
  {
    t = mem[q].hh.b0;
    if (t < 17)
      v = mem[q + 1].cint;
    else
      v = mem[q + 1].hh.rh;
  }
  if (t == 16)
  {
    if (c == 70)
      v = -v;
    if (mem[p].hh.b0 == 16)
    {
      v = slow_add (mem[p + 1].cint, v);
      if (q == 0)
        cur_exp = v;
      else
        mem[q + 1].cint = v;
      goto lab_exit;
    }
    r = mem[p + 1].hh.rh;
    while (mem[r].hh.lh != 0)
      r = mem[r].hh.rh;
    mem[r + 1].cint = slow_add (mem[r + 1].cint, v);
    if (q == 0)
    {
      q = get_node (2);
      cur_exp = q;
      cur_type = mem[p].hh.b0;
      mem[q].hh.b1 = 11;
    }
    mem[q + 1].hh.rh = mem[p + 1].hh.rh;
    mem[q].hh.b0 = mem[p].hh.b0;
    mem[q + 1].hh.lh = mem[p + 1].hh.lh;
    mem[mem[p + 1].hh.lh].hh.rh = q;
    mem[p].hh.b0 = 16;
  }
  else
  {
    if (c == 70)
      negate_dep_list (v);
    if (mem[p].hh.b0 == 16)
    {
      while (mem[v].hh.lh != 0)
        v = mem[v].hh.rh;
      mem[v + 1].cint = slow_add (mem[p + 1].cint, mem[v + 1].cint);
    }
    else
    {
      s = mem[p].hh.b0;
      r = mem[p + 1].hh.rh;
      if (t == 17)
      {
        if (s == 17)
        {
          if (max_coef (r) + max_coef (v) < 626349397L)
          {
            v = p_plus_q (v, r, 17);
            goto done;
          }
        }
        t = 18;
        v = p_over_v (v, 65536L, 17, 18);
      }
      if (s == 18)
        v = p_plus_q (v, r, 18);
      else
        v = p_plus_fq (v, 65536L, r, 18, 17);
    done:
      if (q != 0)
        dep_finish (v, q, t);
      else
      {
        cur_type = t;
        dep_finish (v, 0, t);
      }
    }
  }
  lab_exit:;
}
/* 943 */
void dep_mult (halfword p, integer v, boolean v_is_scaled)
{
  halfword q;
  small_number s, t;

  if (p == 0)
    q = cur_exp;
  else if (mem[p].hh.b0 != 16)
    q = p;
  else
  {
    if (v_is_scaled)
      mem[p + 1].cint = take_scaled (mem[p + 1].cint, v);
    else
      mem[p + 1].cint = take_fraction (mem[p + 1].cint, v);
    goto lab_exit;
  }
  t = mem[q].hh.b0;
  q = mem[q + 1].hh.rh;
  s = t;
  if (t == 17)
  {
    if (v_is_scaled)
    {
      if (ab_vs_cd (max_coef (q), abs (v), 626349396L, 65536L) >= 0)
        t = 18;
    }
  }
  q = p_times_v (q, v, s, t, v_is_scaled);
  dep_finish (q, p, t);
  lab_exit:;
}
/* 946 */
void hard_times (halfword p)
{
  halfword q;
  halfword r;
  scaled u, v;

  if (mem[p].hh.b0 == 14)
  {
    q = stash_cur_exp ();
    unstash_cur_exp (p);
    p = q;
  }
  r = mem[cur_exp + 1].cint;
  u = mem[r + 1].cint;
  v = mem[r + 3].cint;
  mem[r + 2].hh.b0 = mem[p].hh.b0;
  new_dep (r + 2, copy_dep_list (mem[p + 1].hh.rh));
  mem[r].hh.b0 = mem[p].hh.b0;
  mem[r + 1] = mem[p + 1];
  mem[mem[p + 1].hh.lh].hh.rh = r;
  free_node (p, 2);
  dep_mult (r, u, true);
  dep_mult (r + 2, v, true);
}
/* 949 */
void dep_div (halfword p, scaled v)
{
  halfword q;
  small_number s, t;

  if (p == 0)
    q = cur_exp;
  else if (mem[p].hh.b0 != 16)
    q = p;
  else
  {
    mem[p + 1].cint = make_scaled (mem[p + 1].cint, v);
    goto lab_exit;
  }
  t = mem[q].hh.b0;
  q = mem[q + 1].hh.rh;
  s = t;
  if (t == 17)
  {
    if (ab_vs_cd (max_coef (q), 65536L, 626349396L, abs (v)) >= 0)
      t = 18;
  }
  q = p_over_v (q, v, s, t);
  dep_finish (q, p, t);
  lab_exit:;
}
/* 953 */
void set_up_trans (quarterword c)
{
  halfword p, q, r;

  if ((c != 88) || (cur_type != 13))
  {
    p = stash_cur_exp ();
    cur_exp = id_transform ();
    cur_type = 13;
    q = mem[cur_exp + 1].cint;
    switch (c)
    {
      case 84:
        if (mem[p].hh.b0 == 16)
        {
          n_sin_cos((mem[p + 1].cint % 23592960L) * 16);
          mem[q + 5].cint = round_fraction (n_cos);
          mem[q + 9].cint = round_fraction (n_sin);
          mem[q + 7].cint = -mem[q + 9].cint;
          mem[q + 11].cint = mem[q + 5].cint;
          goto done;
        }
        break;
      case 85:
        if (mem[p].hh.b0 > 14)
        {
          install (q + 6, p);
          goto done;
        }
        break;
      case 86 :
        if (mem[p].hh.b0 > 14)
        {
          install (q + 4, p);
          install (q + 10, p);
          goto done;
        }
        break;
      case 87:
        if (mem[p].hh.b0 == 14)
        {
          r = mem[p + 1].cint;
          install (q, r);
          install (q + 2, r + 2);
          goto done;
        }
        break;
      case 89:
        if (mem[p].hh.b0 > 14)
        {
          install (q + 4, p);
          goto done;
        }
        break;
      case 90:
        if (mem[p].hh.b0 > 14)
        {
          install (q + 10, p);
          goto done;
        }
        break;
      case 91:
        if (mem[p].hh.b0 == 14)
        {
          r = mem[p + 1].cint;
          install (q + 4, r);
          install (q + 10, r);
          install (q + 8, r + 2);
          if (mem[r + 2].hh.b0 == 16)
            mem[r + 3].cint = -mem[r + 3].cint;
          else
            negate_dep_list (mem[r + 3].hh.rh);
          install (q + 6, r + 2);
          goto done;
        }
        break;
      case 88:
        ;
        break;
    }
    disp_err (p, 858);
    {
      help_ptr = 3;
      help_line[2] = 859;
      help_line[1] = 860;
      help_line[0] = 538;
    }
    put_get_error ();
  done:
    recycle_value (p);
    free_node (p, 2);
  }
  q = mem[cur_exp + 1].cint;
  r = q + 12;
  do {
    r = r - 2;
    if (mem[r].hh.b0 != 16)
      goto lab_exit;
  } while (!(r == q));
  txx = mem[q + 5].cint;
  txy = mem[q + 7].cint;
  tyx = mem[q + 9].cint;
  tyy = mem[q + 11].cint;
  tx = mem[q + 1].cint;
  ty = mem[q + 3].cint;
  flush_cur_exp (0);
  lab_exit:;
}
/* 960 */
void set_up_known_trans (quarterword c)
{
  set_up_trans (c);
  if (cur_type != 16)
  {
    disp_err (0, 861);
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
/* 961 */
void trans (halfword p, halfword q)
{
  scaled v;

  v = take_scaled (mem[p].cint, txx) + take_scaled (mem[q].cint, txy) + tx;
  mem[q].cint = take_scaled (mem[p].cint, tyx) + take_scaled (mem[q].cint, tyy) + ty;
  mem[p].cint = v;
}
/* 962 */
void path_trans (halfword p, quarterword c)
{
  halfword q;

  set_up_known_trans (c);
  unstash_cur_exp (p);
  if (cur_type == 6)
  {
    if (mem[cur_exp + 9].cint == 0)
    {
      if (tx == 0)
      {
        if (ty == 0)
          goto lab_exit;
      }
    }
    flush_cur_exp (make_path (cur_exp));
    cur_type = 8;
  }
  q = cur_exp;
  do {
    if (mem[q].hh.b0 != 0)
      trans (q + 3, q + 4);
    trans (q + 1, q + 2);
    if (mem[q].hh.b1 != 0)
      trans (q + 5, q + 6);
    q = mem[q].hh.rh;
  } while (!(q == cur_exp));
  lab_exit:;
}
/* 963 */
void edges_trans (halfword p, quarterword c)
{
  set_up_known_trans (c);
  unstash_cur_exp (p);
  cur_edges = cur_exp;
  if (mem[cur_edges].hh.rh == cur_edges)
    goto lab_exit;
  if (txx == 0)
  {
    if (tyy == 0)
    {
      if (txy % 65536L == 0)
      {
        if (tyx % 65536L == 0)
        {
          xy_swap_edges ();
          txx = txy;
          tyy = tyx;
          txy = 0;
          tyx = 0;
          if (mem[cur_edges].hh.rh == cur_edges)
            goto lab_exit;
        }
      }
    }
  }
  if (txy == 0)
  {
    if (tyx == 0)
    {
      if (txx % 65536L == 0)
      {
        if (tyy % 65536L == 0)
        {
          if ((txx == 0) || (tyy == 0))
          {
            toss_edges (cur_edges);
            cur_exp = get_node (6);
            init_edges (cur_exp);
          }
          else
          {
            if (txx < 0)
            {
              x_reflect_edges ();
              txx = -txx;
            }
            if (tyy < 0)
            {
              yreflect_edges ();
              tyy = -tyy;
            }
            if (txx != 65536L)
              x_scale_edges (txx / 65536L);
            if (tyy != 65536L)
              y_scale_edges (tyy / 65536L);
            tx = round_unscaled (tx);
            ty = round_unscaled (ty);
            if ((mem[cur_edges + 2].hh.lh + tx <= 0) || (mem[cur_edges + 2].hh.rh + tx >= 8192) || (mem[cur_edges + 1].hh.lh + ty <= 0) || (mem[cur_edges + 1].hh.rh + ty >= 8191) || (abs (tx) >= 4096) || (abs (ty) >= 4096))
            {
              print_err("Too far to shift");
              {
                help_ptr = 3;
                help_line[2] = 868;
                help_line[1] = 537;
                help_line[0] = 538;
              }
              put_get_error ();
            }
            else
            {
              if (tx != 0)
              {
                if (!(abs (mem[cur_edges + 3].hh.lh - tx - 4096) < 4096))
                  fix_offset ();
                mem[cur_edges + 2].hh.lh = mem[cur_edges + 2].hh.lh + tx;
                mem[cur_edges + 2].hh.rh = mem[cur_edges + 2].hh.rh + tx;
                mem[cur_edges + 3].hh.lh = mem[cur_edges + 3].hh.lh - tx;
                mem[cur_edges + 4].cint = 0;
              }
              if (ty != 0)
              {
                mem[cur_edges + 1].hh.lh = mem[cur_edges + 1].hh.lh + ty;
                mem[cur_edges + 1].hh.rh = mem[cur_edges + 1].hh.rh + ty;
                mem[cur_edges + 5].hh.lh = mem[cur_edges + 5].hh.lh + ty;
                mem[cur_edges + 4].cint = 0;
              }
            }
          }
          goto lab_exit;
        }
      }
    }
  }
  print_err("That transformation is too hard");
  {
    help_ptr = 3;
    help_line[2] = 865;
    help_line[1] = 866;
    help_line[0] = 538;
  }
  put_get_error ();
  lab_exit:;
}
/* 968 */
void bilin1 (halfword p, scaled t, halfword q, scaled u, scaled delta)
{
  halfword r;

  if (t != 65536L)
    dep_mult (p, t, true);
  if (u != 0)
  {
    if (mem[q].hh.b0 == 16)
      delta = delta + take_scaled (mem[q + 1].cint, u);
    else
    {
      if (mem[p].hh.b0 != 18)
      {
        if (mem[p].hh.b0 == 16)
          new_dep (p, const_dependency (mem[p + 1].cint));
        else
          mem[p + 1].hh.rh = p_times_v (mem[p + 1].hh.rh, 65536L, 17, 18, true);
        mem[p].hh.b0 = 18;
      }
      mem[p + 1].hh.rh = p_plus_fq (mem[p + 1].hh.rh, u, mem[q + 1].hh.rh, 18, mem[q].hh.b0);
    }
  }
  if (mem[p].hh.b0 == 16)
    mem[p + 1].cint = mem[p + 1].cint + delta;
  else
  {
    r = mem[p + 1].hh.rh;
    while (mem[r].hh.lh != 0)
      r = mem[r].hh.rh;
    delta = mem[r + 1].cint + delta;
    if (r != mem[p + 1].hh.rh)
      mem[r + 1].cint = delta;
    else
    {
      recycle_value (p);
      mem[p].hh.b0 = 16;
      mem[p + 1].cint = delta;
    }
  }
  if (fix_needed)
    fix_dependencies ();
}
/* 971 */
void add_mult_dep (halfword p, scaled v, halfword r)
{
  if (mem[r].hh.b0 == 16)
    mem[dep_final + 1].cint = mem[dep_final + 1].cint + take_scaled (mem[r + 1].cint, v);
  else
  {
    mem[p + 1].hh.rh = p_plus_fq (mem[p + 1].hh.rh, v, mem[r + 1].hh.rh, 18, mem[r].hh.b0);
    if (fix_needed)
      fix_dependencies ();
  }
}
/* 972 */
void bilin2 (halfword p, halfword t, scaled v, halfword u, halfword q)
{
  scaled vv;

  vv = mem[p + 1].cint;
  mem[p].hh.b0 = 18;
  new_dep (p, const_dependency (0));
  if (vv != 0)
    add_mult_dep (p, vv, t);
  if (v != 0)
    add_mult_dep (p, v, u);
  if (q != 0)
    add_mult_dep (p, 65536L, q);
  if (mem[p + 1].hh.rh == dep_final)
  {
    vv = mem[dep_final + 1].cint;
    recycle_value (p);
    mem[p].hh.b0 = 16;
    mem[p + 1].cint = vv;
  }
}
/* 974 */
void bilin3 (halfword p, scaled t, scaled v, scaled u, scaled delta)
{
  if (t != 65536L)
    delta = delta + take_scaled (mem[p + 1].cint, t);
  else
    delta = delta + mem[p + 1].cint;
  if (u != 0)
    mem[p + 1].cint = delta + take_scaled (v, u);
  else
    mem[p + 1].cint = delta;
}
/* 966 */
void big_trans (halfword p, quarterword c)
{
  halfword q, r, pp, qq;
  small_number s;

  s = big_node_size[mem[p].hh.b0];
  q = mem[p + 1].cint;
  r = q + s;
  do {
    r = r - 2;
    if (mem[r].hh.b0 != 16)
    {
      set_up_known_trans (c);
      make_exp_copy (p);
      r = mem[cur_exp + 1].cint;
      if (cur_type == 13)
      {
        bilin1 (r + 10, tyy, q + 6, tyx, 0);
        bilin1 (r + 8, tyy, q + 4, tyx, 0);
        bilin1 (r + 6, txx, q + 10, txy, 0);
        bilin1 (r + 4, txx, q + 8, txy, 0);
      }
      bilin1 (r + 2, tyy, q, tyx, ty);
      bilin1 (r, txx, q + 2, txy, tx);
      goto lab_exit;
    }
  } while (!(r == q));
  set_up_trans (c);
  if (cur_type == 16)
  {
    make_exp_copy (p);
    r = mem[cur_exp + 1].cint;
    if (cur_type == 13)
    {
      bilin3 (r + 10, tyy, mem[q + 7].cint, tyx, 0);
      bilin3 (r + 8, tyy, mem[q + 5].cint, tyx, 0);
      bilin3 (r + 6, txx, mem[q + 11].cint, txy, 0);
      bilin3 (r + 4, txx, mem[q + 9].cint, txy, 0);
    }
    bilin3 (r + 2, tyy, mem[q + 1].cint, tyx, ty);
    bilin3 (r, txx, mem[q + 3].cint, txy, tx);
  }
  else
  {
    pp = stash_cur_exp ();
    qq = mem[pp + 1].cint;
    make_exp_copy (p);
    r = mem[cur_exp + 1].cint;
    if (cur_type == 13)
    {
      bilin2 (r + 10, qq + 10, mem[q + 7].cint, qq + 8, 0);
      bilin2 (r + 8, qq + 10, mem[q + 5].cint, qq + 8, 0);
      bilin2 (r + 6, qq + 4, mem[q + 11].cint, qq + 6, 0);
      bilin2 (r + 4, qq + 4, mem[q + 9].cint, qq + 6, 0);
    }
    bilin2 (r + 2, qq + 10, mem[q + 1].cint, qq + 8, qq + 2);
    bilin2 (r, qq + 4, mem[q + 3].cint, qq + 6, qq);
    recycle_value (pp);
    free_node (pp, 2);
  }
  lab_exit:;
}
/* 976 */
void cat (halfword p)
{
  str_number a, b;
  pool_pointer k;

  a = mem[p + 1].cint;
  b = cur_exp;
  {
    if (pool_ptr + (str_start[a + 1] - str_start[a]) + (str_start[b + 1] - str_start[b]) > max_pool_ptr)
    {
      if (pool_ptr + (str_start[a + 1] - str_start[a]) + (str_start[b + 1] - str_start[b]) > pool_size)
        overflow (257, pool_size - init_pool_ptr);
      max_pool_ptr = pool_ptr + (str_start[a + 1] - str_start[a]) + (str_start[b + 1] - str_start[b]);
    }
  }
  {
    integer for_end; k = str_start[a];for_end = str_start[a + 1] - 1;
    if (k <= for_end) do
    {
      str_pool[pool_ptr] = str_pool[k];
      incr (pool_ptr);
    } while (k++ < for_end);
  }
  {
    integer for_end; k = str_start[b];for_end = str_start[b + 1] - 1;
    if (k <= for_end) do
    {
      str_pool[pool_ptr] = str_pool[k];
      incr (pool_ptr);
    } while (k++ < for_end);
  }
  cur_exp = make_string ();
  {
    if (str_ref[b]< 127)
    {
      if (str_ref[b] > 1)
        decr (str_ref[b]);
      else
        flush_string (b);
    }
  }
}
/* 977 */
void chop_string (halfword p)
{
  integer a, b;
  integer l;
  integer k;
  str_number s;
  boolean reversed;

  a = round_unscaled (mem[p + 1].cint);
  b = round_unscaled (mem[p + 3].cint);
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
        overflow (257, pool_size - init_pool_ptr);
      max_pool_ptr = pool_ptr + b - a;
    }
  }
  if (reversed)
  {
    integer for_end; k = str_start[s]+ b - 1;for_end = str_start[s]+ a;
    if (k >= for_end) do
    {
      str_pool[pool_ptr] = str_pool[k];
      incr (pool_ptr);
    } while (k-- > for_end);
  }
  else
  {
    integer for_end; k = str_start[s]+ a;for_end = str_start[s]+ b - 1;
    if (k <= for_end) do
    {
      str_pool[pool_ptr] = str_pool[k];
      incr (pool_ptr);
    } while (k++ < for_end);
  }
  cur_exp = make_string ();
  {
    if (str_ref[s]< 127)
    {
      if (str_ref[s] > 1)
        decr (str_ref[s]);
      else
        flush_string (s);
    }
  }
}
/* 978 */
void chop_path (halfword p)
{
  halfword q;
  halfword pp, qq, rr, ss;
  scaled a, b, k, l;
  boolean reversed;

  l = path_length ();
  a = mem[p + 1].cint;
  b = mem[p + 3].cint;
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
    if (mem[cur_exp].hh.b0 == 0)
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
    if (mem[cur_exp].hh.b0 == 0)
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
  while (a >= 65536L)
  {
    q = mem[q].hh.rh;
    a = a - 65536L;
    b = b - 65536L;
  }
  if (b == a)
  {
    if (a > 0)
    {
      qq = mem[q].hh.rh;
      split_cubic (q, a * 4096, mem[qq + 1].cint, mem[qq + 2].cint);
      q = mem[q].hh.rh;
    }
    pp = copy_knot (q);
    qq = pp;
  }
  else
  {
    pp = copy_knot (q);
    qq = pp;
    do {
      q = mem[q].hh.rh;
      rr = qq;
      qq = copy_knot (q);
      mem[rr].hh.rh = qq;
      b = b - 65536L;
    } while (!(b <= 0));
    if (a > 0)
    {
      ss = pp;
      pp = mem[pp].hh.rh;
      split_cubic (ss, a * 4096, mem[pp + 1].cint, mem[pp + 2].cint);
      pp = mem[ss].hh.rh;
      free_node (ss, 7);
      if (rr == ss)
      {
        b = make_scaled (b, 65536L - a);
        rr = pp;
      }
    }
    if (b < 0)
    {
      split_cubic (rr, (b + 65536L) * 4096, mem[qq + 1].cint, mem[qq + 2].cint);
      free_node (qq, 7);
      qq = mem[rr].hh.rh;
    }
  }
  mem[pp].hh.b0 = 0;
  mem[qq].hh.b1 = 0;
  mem[qq].hh.rh = pp;
  toss_knot_list (cur_exp);
  if (reversed)
  {
    cur_exp = mem[htap_ypoc (pp)].hh.rh;
    toss_knot_list (pp);
  }
  else
    cur_exp = pp;
}
/* 982 */
void pair_value (scaled x, scaled y)
{
  halfword p;

  p = get_node (2);
  flush_cur_exp (p);
  cur_type = 14;
  mem[p].hh.b0 = 14;
  mem[p].hh.b1 = 11;
  init_big_node (p);
  p = mem[p + 1].cint;
  mem[p].hh.b0 = 16;
  mem[p + 1].cint = x;
  mem[p + 2].hh.b0 = 16;
  mem[p + 3].cint = y;
}
/* 984 */
void set_up_offset (halfword p)
{
  find_offset (mem[p + 1].cint, mem[p + 3].cint, cur_exp);
  pair_value (cur_x, cur_y);
}
/* 984 */
void set_up_direction_time (halfword p)
{
  flush_cur_exp (find_direction_time (mem[p + 1].cint, mem[p + 3].cint, cur_exp));
}
/* 985 */
void find_point (scaled v, quarterword c)
{
  halfword p;
  scaled n;
  halfword q;

  p = cur_exp;
  if (mem[p].hh.b0 == 0)
    n = -65536L;
  else
    n = 0;
  do {
    p = mem[p].hh.rh;
    n = n + 65536L;
  } while (!(p == cur_exp));
  if (n == 0)
    v = 0;
  else if (v < 0)
  {
    if (mem[p].hh.b0 == 0)
      v = 0;
    else
      v = n - 1 - ((-v - 1) % n);
  }
  else if (v > n)
  {
    if (mem[p].hh.b0 == 0)
      v = n;
    else
      v = v % n;
  }
  p = cur_exp;
  while (v >= 65536L)
  {
    p = mem[p].hh.rh;
    v = v - 65536L;
  }
  if (v != 0)
  {
    q = mem[p].hh.rh;
    split_cubic (p, v * 4096, mem[q + 1].cint, mem[q + 2].cint);
    p = mem[p].hh.rh;
  }
  switch (c)
  {
    case 97:
      pair_value (mem[p + 1].cint, mem[p + 2].cint);
      break;
    case 98:
      if (mem[p].hh.b0 == 0)
        pair_value (mem[p + 1].cint, mem[p + 2].cint);
      else
        pair_value (mem[p + 3].cint, mem[p + 4].cint);
      break;
    case 99:
      if (mem[p].hh.b1 == 0)
        pair_value (mem[p + 1].cint, mem[p + 2].cint);
      else
        pair_value (mem[p + 5].cint, mem[p + 6].cint);
      break;
  }
}
/* 922 */
void do_binary (halfword p, quarterword c)
{
  halfword q, r, rr;
  halfword oldp, oldexp;
  integer v;
 
  check_arith ();
  if (internal[7] > 131072L)
  {
    begin_diagnostic ();
    print_nl(850);
    print_exp (p, 0);
    print_char(41);
    print_op (c);
    print_char(40);
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
    q = stash_cur_exp ();
    oldp = p;
    make_exp_copy (oldp);
    p = stash_cur_exp ();
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
          done1: take_part (53 + half (r - mem[cur_exp + 1].cint));
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
            disp_err (p, 261);
            {
              help_ptr = 1;
              help_line[0] = 851;
            }
          }
          else
          {
            help_ptr = 2;
            help_line[1] = 852;
            help_line[0] = 853;
          }
          disp_err (0, 854);
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
          disp_err (0, 784);
          {
            help_ptr = 2;
            help_line[1] = 856;
            help_line[0] = 857;
          }
          put_get_error ();
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
          pair_to_path ();
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
          pair_to_path ();
        if ((cur_type == 9) && (mem[p].hh.b0 == 16))
          find_point (mem[p + 1].cint, c);
        else
          bad_binary (p, c);
      }
      break;
    case 100:
      {
        if (cur_type == 8)
          materialize_pen ();
        if ((cur_type == 6) && nice_pair (p, mem[p].hh.b0))
          set_up_offset (mem[p + 1].cint);
        else
          bad_binary (p, 100);
      }
      break;
    case 96:
      {
        if (cur_type == 14)
          pair_to_path ();
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
          q = stash_cur_exp ();
          unstash_cur_exp (p);
          pair_to_path ();
          p = stash_cur_exp ();
          unstash_cur_exp (q);
        }
        if (cur_type == 14)
          pair_to_path ();
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
  check_arith ();
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
  halfword p;
  halfword oldexp;
  fraction v;

  if (internal[7] > 131072L)
  {
    begin_diagnostic ();
    print_nl(850);
    print_scaled(n);
    print_char(47);
    print_scaled(d);
    print(855);
    print_exp (0, 0);
    print(842);
    end_diagnostic (false);
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
  v = make_fraction (n, d);
  if (cur_type == 16)
    cur_exp = take_fraction (cur_exp, v);
  else if (cur_type == 14)
  {
    p = mem[cur_exp + 1].cint;
    dep_mult (p, v, false);
    dep_mult (p + 2, v, false);
  }
  else
    dep_mult (0, v, false);
  if (oldexp != 0)
  {
    recycle_value (oldexp);
    free_node (oldexp, 2);
  }
}
/* 1155 */
void gf_swap (void)
{
  if (gf_ptr > (2147483647L - gf_offset))
  {
    gf_prev_ptr = 0;
    fatal_error (1053);
  }
  if (gf_limit == gf_buf_size)
  {
    write_gf (0, half_buf - 1);
    gf_limit = half_buf;
    gf_offset = gf_offset + gf_buf_size;
    gf_ptr = 0;
  }
  else
  {
    write_gf (half_buf, gf_buf_size - 1);
    gf_limit = gf_buf_size;
  }
}
/* 1157 */
void gf_four (integer x)
{
  if (x >= 0)
  {
    gf_buf[gf_ptr] = x / 16777216L;
    incr (gf_ptr);
    if (gf_ptr == gf_limit)
      gf_swap ();
  }
  else
  {
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
/* 1158 */
void gf_two (integer x)
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
/* 1158 */
void gf_three (integer x)
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
/* 1159 */
void gf_paint (integer d)
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
  else
  {
    {
      gf_buf[gf_ptr] = 65;
      incr (gf_ptr);
      if (gf_ptr == gf_limit)
        gf_swap ();
    }
    gf_two (d);
  }
}
/* 1160 */
void gf_string (str_number s, str_number t)
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
    else
    {
      {
        gf_buf[gf_ptr] = 241;
        incr (gf_ptr);
        if (gf_ptr == gf_limit)
          gf_swap ();
      }
      gf_three (l);
    }
    {
      integer for_end; k = str_start[s];for_end = str_start[s + 1] - 1;
      if (k <= for_end) do
      {
        gf_buf[gf_ptr] = str_pool[k];
        incr (gf_ptr);
        if (gf_ptr == gf_limit)
          gf_swap ();
      } while (k++ < for_end);
    }
  }
  if (t != 0)
  {
    integer for_end; k = str_start[t];for_end = str_start[t + 1] - 1;
    if (k <= for_end) do
    {
      gf_buf[gf_ptr] = str_pool[k];
      incr (gf_ptr);
      if (gf_ptr == gf_limit)
        gf_swap ();
    } while (k++ < for_end);
  }
}
/* 1161 */
void gf_boc (integer minm, integer maxm, integer minn, integer maxn)
{
  if (minm < gf_min_m)
    gf_min_m = minm;
  if (maxn > gf_max_n)
    gf_max_n = maxn;
  if (boc_p == -1)
  {
    if (boc_c >= 0)
    {
      if (boc_c < 256)
      {
        if (maxm - minm >= 0)
        {
          if (maxm - minm < 256)
          {
            if (maxm >= 0)
            {
              if (maxm < 256)
              {
                if (maxn - minn >= 0)
                {
                  if (maxn - minn < 256)
                  {
                    if (maxn >= 0)
                    {
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
                        goto lab_exit;
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
  gf_four (boc_c);
  gf_four (boc_p);
  gf_four (minm);
  gf_four (maxm);
  gf_four (minn);
  gf_four (maxn);
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
  {
    integer for_end; k = 0;for_end = 255;
    if (k <= for_end) do
      char_ptr[k] = -1;
      while (k++ < for_end);
  }
  if (internal[27]<= 0)
    gf_ext = 1055;
  else
  {
    old_setting = selector;
    selector = 5;
    print_char(46);
    print_int (make_scaled (internal[27], 59429463L));
    print(1056);
    gf_ext = make_string ();
    selector = old_setting;
  }
  {
    if (job_name == 0)
      open_log_file ();
    pack_job_name (gf_ext);
    while (!bopenout (gf_file))
      prompt_file_name (756, gf_ext);
    output_file_name = b_make_name_string (gf_file);
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
  print(1054);
  print_int (round_unscaled (internal[14]));
  print_char(46);
  print_dd (round_unscaled (internal[15]));
  print_char(46);
  print_dd (round_unscaled (internal[16]));
  print_char(58);
  t = round_unscaled (internal[17]);
  print_dd (t / 60);
  print_dd (t % 60);
  selector = old_setting;
  {
    gf_buf[gf_ptr] = (pool_ptr - str_start[str_ptr]);
    incr (gf_ptr);
    if (gf_ptr == gf_limit)
      gf_swap ();
  }
  gf_string (0, make_string ());
  decr (str_ptr);
  pool_ptr = str_start[str_ptr];
  gf_prev_ptr = gf_offset + gf_ptr;
}
/* 1165 */
void ship_out (eight_bits c)
{
  integer f;
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
  f = round_unscaled (internal[19]);
  xoff = round_unscaled (internal[29]);
  yoff = round_unscaled (internal[30]);
  if (term_offset > max_print_line - 9)
    print_ln ();
  else if ((term_offset > 0) || (file_offset > 0))
    print_char(32);
  print_char(91);
  print_int (c);
  if (f != 0)
  {
    print_char(46);
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
      gf_string (437, 0);
      {
        gf_buf[gf_ptr] = 243;
        incr (gf_ptr);
        if (gf_ptr == gf_limit)
          gf_swap ();
      }
      gf_four (xoff * 65536L);
    }
    if (yoff != 0)
    {
      gf_string (438, 0);
      {
        gf_buf[gf_ptr] = 243;
        incr (gf_ptr);
        if (gf_ptr == gf_limit)
          gf_swap ();
      }
      gf_four (yoff * 65536L);
    }
  }
  prevn = 4096;
  p = mem[cur_edges].hh.lh;
  n = mem[cur_edges + 1].hh.rh - 4096;
  while (p != cur_edges)
  {
    if (mem[p + 1].hh.lh > 1)
      sort_edges (p);
    q = mem[p + 1].hh.rh;
    w = 0;
    prevm = -268435456L;
    ww = 0;
    prevw = 0;
    m = prevm;
    do {
      if (q == mem_top)
        mm = 268435456L;
      else
      {
        d = mem[q].hh.lh;
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
                gf_boc (mem[cur_edges + 2].hh.lh + xoff - 4096, mem[cur_edges + 2].hh.rh + xoff - 4096, mem[cur_edges + 1].hh.lh + yoff - 4096, n + yoff);
                curminm = mem[cur_edges + 2].hh.lh - 4096 + mem[cur_edges + 3].hh.lh;
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
                else
                {
                  {
                    gf_buf[gf_ptr] = 72;
                    incr (gf_ptr);
                    if (gf_ptr == gf_limit)
                      gf_swap ();
                  }
                  gf_two (delta);
                }
              }
              else
              {
                delta = m - curminm;
                if (delta > 164)
                {
                  gf_buf[gf_ptr] = 70;
                  incr (gf_ptr);
                  if (gf_ptr == gf_limit)
                    gf_swap ();
                }
                else
                {
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
            else
              gf_paint (m - prevm);
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
      q = mem[q].hh.rh;
    } while (!(mm == 268435456L));
    if (w != 0)
      print_nl(1058);
    if (prevm - mem[cur_edges + 3].hh.lh + xoff > gf_max_m)
      gf_max_m = prevm - mem[cur_edges + 3].hh.lh + xoff;
    p = mem[p].hh.lh;
    decr (n);
  }
  if (prevn == 4096)
  {
    gf_boc (0, 0, 0, 0);
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
  print_char(93);
  fflush (stdout);
  if (internal[11] > 0)
    print_edges (1057, true, xoff, yoff);
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
    p = p_plus_fq (p, 65536L, pp, 18, 17);
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
    if (abs (mem[p + 1].cint) > 64)
    {
      print_err("Inconsistent equation");
      print(899);
      print_scaled(mem[p + 1].cint);
      print_char(41);
      {
        help_ptr = 2;
        help_line[1] = 898;
        help_line[0] = 896;
      }
      put_get_error ();
    }
    else if (r == 0)
    {
      print_err("Redundant equation");
      {
        help_ptr = 2;
        help_line[1] = 601;
        help_line[0] = 602;
      }
      put_get_error ();
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
void make_eq (halfword lhs)
{
  small_number t;
  integer v;
  halfword p, q;

lab_restart:
  t = mem[lhs].hh.b0;
  if (t <= 14)
    v = mem[lhs + 1].cint;
  switch (t)
  {
    case 2:
    case 4:
    case 6:
    case 9:
    case 11:
      if (cur_type == t + 1)
      {
        non_linear_eq (v, cur_exp, false);
        unstash_cur_exp (cur_exp);
        goto done;
      }
      else if (cur_type == t)
      {
        if (cur_type <= 4)
        {
          if (cur_type == 4)
          {
            if (str_vs_str (v, cur_exp) != 0)
              goto not_found;
          }
          else if (v != cur_exp)
            goto not_found;
          {
            print_err("Redundant equation");
            {
              help_ptr = 2;
              help_line[1] = 601;
              help_line[0] = 602;
            }
            put_get_error ();
          }
          goto done;
        }
        print_err("Redundant or inconsistent equation");
        {
          help_ptr = 2;
          help_line[1] = 895;
          help_line[0] = 896;
        }
        put_get_error ();
        goto done;
      not_found:
        print_err("Inconsistent equation");
        {
          help_ptr = 2;
          help_line[1] = 898;
          help_line[0] = 896;
        }
        put_get_error ();
        goto done;
      }
      break;
    case 3:
    case 5:
    case 7:
    case 12:
    case 10:
      if (cur_type == t - 1)
      {
        non_linear_eq (cur_exp, lhs, true);
        goto done;
      }
      else if (cur_type == t)
      {
        ring_merge (lhs, cur_exp);
        goto done;
      }
      else if (cur_type == 14)
      {
        if (t == 10)
        {
          pair_to_path ();
          goto lab_restart;
        }
      }
      break;
    case 13:
    case 14:
      if (cur_type == t)
      {
        p = v + big_node_size[t];
        q = mem[cur_exp + 1].cint + big_node_size[t];
        do {
          p = p - 2;
          q = q - 2;
          try_eq (p, q);
        } while (!(p == v));
        goto done;
      }
      break;
    case 16:
    case 17:
    case 18:
    case 19:
      if (cur_type >= 16)
      {
        try_eq (lhs, 0);
        goto done;
      }
      break;
    case 1:
      ;
      break;
  }
  disp_err (lhs, 261);
  disp_err (0, 891);
  if (mem[lhs].hh.b0 <= 14)
    print_type (mem[lhs].hh.b0);
  else
    print(340);
  print_char(61);
  if (cur_type <= 14)
    print_type (cur_type);
  else
    print(340);
  print_char(41);
  {
    help_ptr = 2;
    help_line[1] = 892;
    help_line[0] = 893;
  }
  put_get_error ();
done:
  check_arith ();
  recycle_value (lhs);
  free_node (lhs, 2);
}
/* 995 */
void do_equation (void)
{
  halfword lhs;
  halfword p;

  lhs = stash_cur_exp ();
  get_x_next ();
  var_flag = 77;
  scan_expression ();
  if (cur_cmd == 51)
    do_equation ();
  else if (cur_cmd == 77)
    do_assignment ();
  if (internal[7] > 131072L)
  {
    begin_diagnostic ();
    print_nl(850);
    print_exp (lhs, 0);
    print(886);
    print_exp (0, 0);
    print(842);
    end_diagnostic (false);
  }
  if (cur_type == 10)
  {
    if (mem[lhs].hh.b0 == 14)
    {
      p = stash_cur_exp ();
      unstash_cur_exp (lhs);
      lhs = p;
    }
  }
  make_eq (lhs);
}
/* 996 */
void do_assignment (void)
{
  halfword lhs;
  halfword p;
  halfword q;

  if (cur_type != 20)
  {
    disp_err (0, 883);
    {
      help_ptr = 2;
      help_line[1] = 884;
      help_line[0] = 885;
    }
    error ();
    do_equation ();
  }
  else
  {
    lhs = cur_exp;
    cur_type = 1;
    get_x_next ();
    var_flag = 77;
    scan_expression ();
    if (cur_cmd == 51)
      do_equation ();
    else if (cur_cmd == 77)
      do_assignment ();
    if (internal[7] > 131072L)
    {
      begin_diagnostic ();
      print_nl(123);
      if (mem[lhs].hh.lh > 9769)
        slow_print(int_name[mem[lhs].hh.lh - (9769)]);
      else
        show_token_list (lhs, 0, 1000, 0);
      print(461);
      print_exp (0, 0);
      print_char(125);
      end_diagnostic (false);
    }
    if (mem[lhs].hh.lh > 9769)
    {
      if (cur_type == 16)
        internal[mem[lhs].hh.lh - (9769)] = cur_exp;
      else
      {
        disp_err (0, 887);
        slow_print(int_name[mem[lhs].hh.lh - (9769)]);
        print(888);
        {
          help_ptr = 2;
          help_line[1] = 889;
          help_line[0] = 890;
        }
        put_get_error ();
      }
    }
    else
    {
      p = find_variable (lhs);
      if (p != 0)
      {
        q = stash_cur_exp ();
        cur_type = und_type (p);
        recycle_value (p);
        mem[p].hh.b0 = cur_type;
        mem[p + 1].cint = 0;
        make_exp_copy (p);
        p = stash_cur_exp ();
        unstash_cur_exp (q);
        make_eq (p);
      }
      else
      {
        obliterated (lhs);
        put_get_error ();
      }
    }
    flush_node_list (lhs);
  }
}
/* 1015 */
void do_type_declaration (void)
{
  small_number t;
  halfword p;
  halfword q;

  if (cur_mod >= 13)
    t = cur_mod;
  else
    t = cur_mod + 1;
  do {
    p = scan_declared_variable ();
    flush_variable (eqtb[mem[p].hh.lh].v.RH, mem[p].hh.rh, false);
    q = find_variable (p);
    if (q != 0)
    {
      mem[q].hh.b0 = t;
      mem[q + 1].cint = 0;
    }
    else
    {
      print_err("Declared variable conflicts with previous vardef");
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
      print_err("Illegal suffix of declared variable will be flushed");
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
        get_next ();
        if (cur_cmd == 39)
        {
          if (str_ref[cur_mod]< 127)
          {
            if (str_ref[cur_mod] > 1)
              decr (str_ref[cur_mod]);
            else
              flush_string (cur_mod);
          }
        }
      } while (!(cur_cmd >= 82));
      scanner_status = 0;
    }
  } while (!(cur_cmd > 82));
}
/* 1021 */
void do_random_seed (void)
{
  get_x_next ();
  if (cur_cmd != 77)
  {
    missing_err (461);
    {
      help_ptr = 1;
      help_line[0] = 914;
    }
    back_error ();
  }
  get_x_next ();
  scan_expression ();
  if (cur_type != 16)
  {
    disp_err (0, 915);
    {
      help_ptr = 2;
      help_line[1] = 916;
      help_line[0] = 917;
    }
    put_get_flush_error (0);
  }
  else
  {
    init_randoms (cur_exp);
    if (selector >= 2)
    {
      old_setting = selector;
      selector = 2;
      print_nl(918);
      print_scaled(cur_exp);
      print_char(125);
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
    get_symbol ();
    t = eqtb[cur_sym].lh;
    if (m == 0)
    {
      if (t >= 86)
        eqtb[cur_sym].lh = t - 86;
    }
    else if (t < 86)
      eqtb[cur_sym].lh = t + 86;
    get_x_next ();
  } while (!(cur_cmd != 82));
}
/* 1031 */
void def_delims (void)
{
  halfword ldelim, rdelim;

  get_clear_symbol ();
  ldelim = cur_sym;
  get_clear_symbol ();
  rdelim = cur_sym;
  eqtb[ldelim].lh = 31;
  eqtb[ldelim].v.RH = rdelim;
  eqtb[rdelim].lh = 62;
  eqtb[rdelim].v.RH = ldelim;
  get_x_next ();
}
/* 1034 */
void do_interim (void)
{
  get_x_next ();
  if (cur_cmd != 40)
  {
    print_err("The token `");
    if (cur_sym == 0)
      print(929);
    else
      slow_print(hash[cur_sym].v.RH);
    print(930);
    {
      help_ptr = 1;
      help_line[0] = 931;
    }
    back_error ();
  }
  else
  {
    save_internal (cur_mod);
    back_input ();
  }
  do_statement ();
}
/* 1035 */
void do_let (void)
{
  halfword l;

  get_symbol ();
  l = cur_sym;
  get_x_next ();
  if (cur_cmd != 51)
  {
    if (cur_cmd != 77)
    {
      missing_err (61);
      {
        help_ptr = 3;
        help_line[2] = 932;
        help_line[1] = 673;
        help_line[0] = 933;
      }
      back_error ();
    }
  }
  get_symbol ();
  switch (cur_cmd)
  {
    case 10:
    case 53:
    case 44:
    case 49:
      incr (mem[cur_mod].hh.lh);
      break;
    default:
      ;
      break;
  }
  clear_symbol (l, false);
  eqtb[l].lh = cur_cmd;
  if (cur_cmd == 41)
    eqtb[l].v.RH = 0;
  else
    eqtb[l].v.RH = cur_mod;
  get_x_next ();
}
/* 1036 */
void do_new_internal (void)
{
  do {
    if (int_ptr == max_internal)
      overflow (934, max_internal);
    get_clear_symbol ();
    incr (int_ptr);
    eqtb[cur_sym].lh = 40;
    eqtb[cur_sym].v.RH = int_ptr;
    int_name[int_ptr] = hash[cur_sym].v.RH;
    internal[int_ptr] = 0;
    get_x_next ();
  } while (!(cur_cmd != 82));
}
/* 1040 */
void do_show (void)
{
  do {
    get_x_next ();
    scan_expression ();
    print_nl(765);
    print_exp (0, 2);
    flush_cur_exp (0);
  } while (!(cur_cmd != 82));
}
/* 1041 */
void disp_token (void)
{
  print_nl(940);
  if (cur_sym == 0)
  {
    if (cur_cmd == 42)
      print_scaled(cur_mod);
    else if (cur_cmd == 38)
    {
      g_pointer = cur_mod;
      print_capsule ();
    }
    else
    {
      print_char(34);
      slow_print(cur_mod);
      print_char(34);
      {
        if (str_ref[cur_mod] < 127)
        {
          if (str_ref[cur_mod] > 1)
            decr (str_ref[cur_mod]);
          else
            flush_string (cur_mod);
        }
      }
    }
  }
  else
  {
    slow_print(hash[cur_sym].v.RH);
    print_char(61);
    if (eqtb[cur_sym].lh >= 86)
      print(941);
    print_cmd_mod (cur_cmd, cur_mod);
    if (cur_cmd == 10)
    {
      print_ln ();
      show_macro (cur_mod, 0, 100000L);
    }
  }
}
/* 1044 */
void do_show_token (void)
{
  do {
    get_next ();
    disp_token ();
    get_x_next ();
  } while (!(cur_cmd != 82));
}
/* 1045 */
void do_show_stats (void)
{
  print_nl(950);
  ;
#ifdef STAT
  print_int (var_used);
  print_char(38);
  print_int (dyn_used);
  if (false)
#endif /* STAT */
  print(357);
  print(558);
  print_int (hi_mem_min - lo_mem_max - 1);
  print(951);
  print_ln ();
  print_nl(952);
  print_int (str_ptr - init_str_ptr);
  print_char(38);
  print_int (pool_ptr - init_pool_ptr);
  print(558);
  print_int (max_strings - max_str_ptr);
  print_char(38);
  print_int (pool_size - max_pool_ptr);
  print(951);
  print_ln ();
  get_x_next ();
}
/* 1046 */
void disp_var (halfword p)
{
  halfword q;
  integer n;

  if (mem[p].hh.b0 == 21)
  {
    q = mem[p + 1].hh.lh;
    do {
      disp_var (q);
      q = mem[q].hh.rh;
    } while (!(q == 17));
    q = mem[p + 1].hh.rh;
    while (mem[q].hh.b1 == 3)
    {
      disp_var (q);
      q = mem[q].hh.rh;
    }
  }
  else if (mem[p].hh.b0 >= 22)
  {
    print_nl(261);
    print_variable_name(p);
    if (mem[p].hh.b0 > 22)
      print(665);
    print(953);
    if (file_offset >= max_print_line - 20)
      n = 5;
    else
      n = max_print_line - file_offset - 15;
    show_macro (mem[p + 1].cint, 0, n);
  }
  else if (mem[p].hh.b0 != 0)
  {
    print_nl(261);
    print_variable_name(p);
    print_char(61);
    print_exp (p, 0);
  }
}
/* 1049 */
void do_show_var (void)
{
  do {
    get_next ();
    if (cur_sym > 0)
    {
      if (cur_sym <= 9769)
      {
        if (cur_cmd == 41)
        {
          if (cur_mod != 0)
          {
            disp_var (cur_mod);
            goto done;
          }
        }
      }
    }
    disp_token ();
  done:
    get_x_next ();
  } while (!(cur_cmd != 82));
}
/* 1050 */
void do_show_dependencies (void)
{
  halfword p;

  p = mem[13].hh.rh;
  while (p != 13)
  {
    if (interesting (p))
    {
      print_nl(261);
      print_variable_name(p);
      if (mem[p].hh.b0 == 17)
        print_char(61);
      else
        print(768);
      print_dependency(mem[p + 1].hh.rh, mem[p].hh.b0);
    }
    p = mem[p + 1].hh.rh;
    while (mem[p].hh.lh != 0)
      p = mem[p].hh.rh;
    p = mem[p].hh.rh;
  }
  get_x_next ();
}
/* 1051 */
void do_show_whatever (void)
{
  if (interaction == 3)
    ;
  switch (cur_mod)
  {
    case 0:
      do_show_token ();
      break;
    case 1:
      do_show_stats ();
      break;
    case 2:
      do_show ();
      break;
    case 3:
      do_show_var ();
      break;
    case 4:
      do_show_dependencies ();
      break;
  }
  if (internal[32] > 0)
  {
    print_err("OK");
    if (interaction < 3)
    {
      help_ptr = 0;
      decr (error_count);
    }
    else
    {
      help_ptr = 1;
      help_line[0] = 955;
    }
    if (cur_cmd == 83)
      error ();
    else
      put_get_error ();
  }
}
/* 1054 */
boolean scan_with (void)
{
  boolean Result;
  small_number t;
  boolean result;

  t = cur_mod;
  cur_type = 1;
  get_x_next ();
  scan_expression ();
  result = false;
  if (cur_type != t)
  {
    disp_err (0, 963);
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
  else
  {
    cur_exp = round_unscaled (cur_exp);
    if ((abs (cur_exp) < 4) && (cur_exp != 0))
      result = true;
    else
    {
      print_err("Weight must be -3, -2, -1, +1, +2, or +3");
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
/* 1057 */
void find_edges_var (halfword t)
{
  halfword p;

  p = find_variable (t);
  cur_edges = 0;
  if (p == 0)
  {
    obliterated (t);
    put_get_error ();
  }
  else if (mem[p].hh.b0 != 11)
  {
    print_err("Variable ");
    show_token_list (t, 0, 1000, 0);
    print(968);
    print_type (mem[p].hh.b0);
    print_char(41);
    {
      help_ptr = 2;
      help_line[1] = 969;
      help_line[0] = 970;
    }
    put_get_error ();
  }
  else
    cur_edges = mem[p + 1].cint;
  flush_node_list (t);
}
/* 1059 */
void do_add_to (void)
{
  halfword lhs, rhs;
  integer w;
  halfword p;
  halfword q;
  unsigned char addtotype;

  get_x_next ();
  var_flag = 68;
  scan_primary ();
  if (cur_type != 20)
  {
    disp_err (0, 971);
    {
      help_ptr = 4;
      help_line[3] = 972;
      help_line[2] = 973;
      help_line[1] = 974;
      help_line[0] = 970;
    }
    put_get_flush_error (0);
  }
  else
  {
    lhs = cur_exp;
    addtotype = cur_mod;
    cur_type = 1;
    get_x_next ();
    scan_expression ();
    if (addtotype == 2)
    {
      find_edges_var (lhs);
      if (cur_edges == 0)
        flush_cur_exp (0);
      else if (cur_type != 11)
      {
        disp_err (0, 975);
        {
          help_ptr = 2;
          help_line[1] = 976;
          help_line[0] = 970;
        }
        put_get_flush_error (0);
      }
      else
      {
        merge_edges (cur_exp);
        flush_cur_exp (0);
      }
    }
    else
    {
      if (cur_type == 14)
        pair_to_path ();
      if (cur_type != 9)
      {
        disp_err (0, 975);
        {
          help_ptr = 2;
          help_line[1] = 977;
          help_line[0] = 970;
        }
        put_get_flush_error (0);
        flush_token_list (lhs);
      }
      else
      {
        rhs = cur_exp;
        w = 1;
        cur_pen = 3;
        while (cur_cmd == 66)
          if (scan_with ())
          {
            if (cur_type == 16)
              w = cur_exp;
            else
            {
              if (mem[cur_pen].hh.lh == 0)
                toss_pen (cur_pen);
              else
                decr (mem[cur_pen].hh.lh);
              cur_pen = cur_exp;
            }
          }
        find_edges_var (lhs);
        if (cur_edges == 0)
          toss_knot_list (rhs);
        else
        {
          lhs = 0;
          cur_path_type = addtotype;
          if (mem[rhs].hh.b0 == 0)
          {
            if (cur_path_type == 0)
            {
              if (mem[rhs].hh.rh == rhs)
              {
                mem[rhs + 5].cint = mem[rhs + 1].cint;
                mem[rhs + 6].cint = mem[rhs + 2].cint;
                mem[rhs + 3].cint = mem[rhs + 1].cint;
                mem[rhs + 4].cint = mem[rhs + 2].cint;
                mem[rhs].hh.b0 = 1;
                mem[rhs].hh.b1 = 1;
              }
              else
              {
                p = htap_ypoc (rhs);
                q = mem[p].hh.rh;
                mem[path_tail + 5].cint = mem[q + 5].cint;
                mem[path_tail + 6].cint = mem[q + 6].cint;
                mem[path_tail].hh.b1 = mem[q].hh.b1;
                mem[path_tail].hh.rh = mem[q].hh.rh;
                free_node (q, 7);
                mem[p + 5].cint = mem[rhs + 5].cint;
                mem[p + 6].cint = mem[rhs + 6].cint;
                mem[p].hh.b1 = mem[rhs].hh.b1;
                mem[p].hh.rh = mem[rhs].hh.rh;
                free_node (rhs, 7);
                rhs = p;
              }
            }
            else
            {
              print_err("Not a cycle");
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
            lhs = htap_ypoc (rhs);
          cur_wt = w;
          rhs = make_spec (rhs, mem[cur_pen + 9].cint, internal[5]);
          if (turning_number <= 0)
          {
            if (cur_path_type != 0)
            {
              if (internal[39] > 0)
              {
                if ((turning_number < 0) && (mem[cur_pen].hh.rh == 0))
                  cur_wt = -cur_wt;
                else
                {
                  if (turning_number == 0)
                  {
                    if ((internal[39]<= 65536L) && (mem[cur_pen].hh.rh == 0))
                      goto done;
                    else
                      print_strange (980);
                  }
                  else
                    print_strange (981);
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
            fill_spec (rhs);
          else
            fill_envelope (rhs);
          if (lhs != 0)
          {
            rev_turns = true;
            lhs = make_spec (lhs, mem[cur_pen + 9].cint, internal[5]);
            rev_turns = false;
            if (mem[cur_pen + 9].cint == 0)
              fill_spec (lhs);
            else
              fill_envelope (lhs);
          }
          not_found:;
        }
        if (mem[cur_pen].hh.lh == 0)
          toss_pen (cur_pen);
        else
          decr (mem[cur_pen].hh.lh);
      }
    }
  }
}
/* 1098 */
scaled tfm_check (small_number m)
{
  scaled Result;
  if (abs (internal[m]) >= 134217728L)
  {
    print_err("Enormous ");
    print(int_name[m]);
    print(1002);
    {
      help_ptr = 1;
      help_line[0] = 1003;
    }
    put_get_error ();
    if (internal[m] > 0)
      Result = 134217727L;
    else
      Result = -134217727L;
  }
  else
    Result = internal[m];
  return Result;
}
/* 1070 */
void do_ship_out (void)
{
  integer c;

  get_x_next ();
  var_flag = 83;
  scan_expression ();
  if (cur_type != 20)
  {
    if (cur_type == 11)
      cur_edges = cur_exp;
    else
    {
      {
        disp_err (0, 971);
        {
          help_ptr = 4;
          help_line[3] = 972;
          help_line[2] = 973;
          help_line[1] = 974;
          help_line[0] = 970;
        }
        put_get_flush_error (0);
      }
      goto lab_exit;
    }
  }
  else
  {
    find_edges_var (cur_exp);
    cur_type = 1;
  }
  if (cur_edges != 0)
  {
    c = round_unscaled (internal[18]) % 256;
    if (c < 0)
      c = c + 256;
    if (c < bc)
      bc = c;
    if (c > ec)
      ec = c;
    char_exists[c] = true;
    gf_dx[c] = internal[24];
    gf_dy[c] = internal[25];
    tfm_width[c] = tfm_check (20);
    tfm_height[c] = tfm_check (21);
    tfm_depth[c] = tfm_check (22);
    tfm_ital_corr[c] = tfm_check (23);
    if (internal[34] >= 0)
      ship_out (c);
  }
  flush_cur_exp (0);
  lab_exit:;
}
/* 1071 */
void do_display (void)
{
  halfword e;

  get_x_next ();
  var_flag = 73;
  scan_primary ();
  if (cur_type != 20)
  {
    disp_err (0, 971);
    {
      help_ptr = 4;
      help_line[3] = 972;
      help_line[2] = 973;
      help_line[1] = 974;
      help_line[0] = 970;
    }
    put_get_flush_error (0);
  }
  else
  {
    e = cur_exp;
    cur_type = 1;
    get_x_next ();
    scan_expression ();
    if (cur_type != 16)
      goto common_ending;
    cur_exp = round_unscaled (cur_exp);
    if (cur_exp < 0)
      goto not_found;
    if (cur_exp > 15)
      goto not_found;
    if (!window_open[cur_exp])
      goto not_found;
    find_edges_var (e);
    if (cur_edges != 0)
      disp_edges (cur_exp);
    goto lab_exit;
  not_found:
    cur_exp = cur_exp * 65536L;
  common_ending:
    disp_err (0, 985);
    {
      help_ptr = 1;
      help_line[0] = 986;
    }
    put_get_flush_error (0);
    flush_token_list (e);
  }
  lab_exit:;
}
/* 1072 */
boolean get_pair (command_code c)
{
  boolean Result;
  halfword p;
  boolean b;

  if (cur_cmd != c)
    Result = false;
  else
  {
    get_x_next ();
    scan_expression ();
    if (nice_pair (cur_exp, cur_type))
    {
      p = mem[cur_exp + 1].cint;
      cur_x = mem[p + 1].cint;
      cur_y = mem[p + 3].cint;
      b = true;
    }
    else
      b = false;
    flush_cur_exp (0);
    Result = b;
  }
  return Result;
}
/* 1073 */
void do_open_window (void)
{
  integer k;
  scaled r0, c0, r1, c1;

  get_x_next ();
  scan_expression ();
  if (cur_type != 16)
    goto not_found;
  k = round_unscaled (cur_exp);
  if (k < 0)
    goto not_found;
  if (k > 15)
    goto not_found;
  if (!get_pair (70))
    goto not_found;
  r0 = cur_x;
  c0 = cur_y;
  if (!get_pair (71))
    goto not_found;
  r1 = cur_x;
  c1 = cur_y;
  if (!get_pair (72))
    goto not_found;
  open_a_window (k, r0, c0, r1, c1, cur_x, cur_y);
  goto lab_exit;
not_found:
  print_err("Improper `openwindow'");
  {
    help_ptr = 2;
    help_line[1] = 988;
    help_line[0] = 989;
  }
  put_get_error ();
  lab_exit:;
}
/* 1047 */
void do_cull (void)
{
  halfword e;
  unsigned char keeping;
  integer w, win, wout;

  w = 1;
  get_x_next ();
  var_flag = 67;
  scan_primary ();
  if (cur_type != 20)
  {
    disp_err (0, 971);
    {
      help_ptr = 4;
      help_line[3] = 972;
      help_line[2] = 973;
      help_line[1] = 974;
      help_line[0] = 970;
    }
    put_get_flush_error (0);
  }
  else
  {
    e = cur_exp;
    cur_type = 1;
    keeping = cur_mod;
    if (!get_pair (67))
      goto not_found;
    while ((cur_cmd == 66) && (cur_mod == 16)) if (scan_with ())
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
    else
    {
      if ((cur_x <= 0) && (cur_y >= 0))
        goto not_found;
      wout = 0;
      win = w;
    }
    find_edges_var (e);
    if (cur_edges != 0)
      cull_edges (floorunscaled (cur_x + 65535L), floorunscaled (cur_y), wout, win);
    goto lab_exit;
  not_found:
    print_err("Bad culling amounts");
    {
      help_ptr = 1;
      help_line[0] = 991;
    }
    put_get_error ();
    flush_token_list (e);
  }
  lab_exit:;
}
/* 1082 */
void do_message (void)
{
  unsigned char m;

  m = cur_mod;
  get_x_next ();
  scan_expression ();
  if (cur_type != 4)
  {
    disp_err (0, 700);
    {
      help_ptr = 1;
      help_line[0] = 995;
    }
    put_get_error ();
  }
  else
    switch (m)
    {
      case 0:
        {
          print_nl(261);
          slow_print(cur_exp);
        }
        break;
      case 1:
        {
          print_err("");
          slow_print(cur_exp);
          if (err_help != 0)
            use_err_help = true;
          else if (long_help_seen)
          {
            help_ptr = 1;
            help_line[0] = 996;
          }
          else
          {
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
      case 2:
        {
          if (err_help != 0)
          {
            if (str_ref[err_help]< 127)
            {
              if (str_ref[err_help] > 1)
                decr (str_ref[err_help]);
              else
                flush_string (err_help);
            }
          }
          if ((str_start[cur_exp + 1] - str_start[cur_exp]) == 0)
            err_help = 0;
          else
          {
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
/* 1103 */
eight_bits get_code (void)
{
  eight_bits Result;
  integer c;

  get_x_next ();
  scan_expression ();
  if (cur_type == 16)
  {
    c = round_unscaled (cur_exp);
    if (c >= 0)
    {
      if (c < 256)
        goto found;
    }
  }
  else if (cur_type == 4)
  {
    if ((str_start[cur_exp + 1] - str_start[cur_exp]) == 1)
    {
      c = str_pool[str_start[cur_exp]];
      goto found;
    }
  }
  disp_err (0, 1009);
  {
    help_ptr = 2;
    help_line[1] = 1010;
    help_line[0] = 1011;
  }
  put_get_flush_error (0);
  c = 0;
found:
  Result = c;
  return Result;
}
/* 1104 */
void set_tag (halfword c, small_number t, halfword r)
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
      print_int (c);
    }
    print(1015);
    switch (char_tag[c])
    {
      case 1:
        print(1016);
        break;
      case 2:
        print(1017);
        break;
      case 3:
        print(1006);
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
/* 1106 */
void do_tfm_command (void)
{
  short c, cc;
  integer k;
  integer j;

  switch (cur_mod)
  {
    case 0:
      {
        c = get_code ();
        while (cur_cmd == 81)
        {
          cc = get_code ();
          set_tag (c, 2, cc);
          c = cc;
        }
      }
      break;
    case 1:
      {
        lk_started = false;
      lab_continue:
        get_x_next ();
        if ((cur_cmd == 78) && lk_started)
        {
          c = get_code ();
          if (nl - skip_table[c] > 128)
          {
            {
              print_err("Too far to skip");
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
          else
            lig_kern[nl - 1].b0 = nl - skip_table[c] - 1;
          skip_table[c] = nl - 1;
          goto done;
        }
        if (cur_cmd == 79)
        {
          c = 256;
          cur_cmd = 81;
        }
        else
        {
          back_input ();
          c = get_code ();
        }
        if ((cur_cmd == 81) || (cur_cmd == 80))
        {
          if (cur_cmd == 81)
          {
            if (c == 256)
              bch_label = nl;
            else
              set_tag (c, 1, nl);
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
                  print_err("Too far to skip");
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
                goto lab_continue;
              }
              lig_kern[ll].b0 = nl - ll - 1;
              ll = ll - lll;
            } while (!(lll == 0));
          }
          goto lab_continue;
        }
        if (cur_cmd == 76)
        {
          lig_kern[nl].b1 = c;
          lig_kern[nl].b0 = 0;
          if (cur_mod < 128)
          {
            lig_kern[nl].b2 = cur_mod;
            lig_kern[nl].b3 = get_code ();
          }
          else
          {
            get_x_next ();
            scan_expression ();
            if (cur_type != 16)
            {
              disp_err (0, 1037);
              {
                help_ptr = 2;
                help_line[1] = 1038;
                help_line[0] = 308;
              }
              put_get_flush_error (0);
            }
            kern[nk] = cur_exp;
            k = 0;
            while (kern[k]!= cur_exp)
              incr (k);
            if (k == nk)
            {
              if (nk == max_kerns)
                overflow (1034, max_kerns);
              incr (nk);
            }
            lig_kern[nl].b2 = 128 + (k / 256);
            lig_kern[nl].b3 = (k % 256);
          }
          lk_started = true;
        }
        else
        {
          print_err("Illegal ligtable step");
          {
            help_ptr = 1;
            help_line[0] = 1024;
          }
          back_error ();
          lig_kern[nl].b1 = 0;
          lig_kern[nl].b2 = 0;
          lig_kern[nl].b3 = 0;
          lig_kern[nl].b0 = 129;
        }
        if (nl == lig_table_size)
          overflow (1025, lig_table_size);
        incr (nl);
        if (cur_cmd == 82)
          goto lab_continue;
        if (lig_kern[nl - 1].b0 < 128)
          lig_kern[nl - 1].b0 = 128;
        done:;
      }
      break;
    case 2:
      {
        if (ne == 256)
          overflow (1006, 256);
        c = get_code ();
        set_tag (c, 3, ne);
        if (cur_cmd != 81)
        {
          missing_err (58);
          {
            help_ptr = 1;
            help_line[0] = 1039;
          }
          back_error ();
        }
        exten[ne].b0 = get_code ();
        if (cur_cmd != 82)
        {
          missing_err (44);
          {
            help_ptr = 1;
            help_line[0] = 1039;
          }
          back_error ();
        }
        exten[ne].b1 = get_code ();
        if (cur_cmd != 82)
        {
          missing_err (44);
          {
            help_ptr = 1;
            help_line[0] = 1039;
          }
          back_error ();
        }
        exten[ne].b2 = get_code ();
        if (cur_cmd != 82)
        {
          missing_err (44);
          {
            help_ptr = 1;
            help_line[0] = 1039;
          }
          back_error ();
        }
        exten[ne].b3 = get_code ();
        incr (ne);
      }
      break;
    case 3:
    case 4:
      {
        c = cur_mod;
        get_x_next ();
        scan_expression ();
        if ((cur_type != 16) || (cur_exp < 32768L))
        {
          disp_err (0, 1019);
          {
            help_ptr = 2;
            help_line[1] = 1020;
            help_line[0] = 1021;
          }
          put_get_error ();
        }
        else
        {
          j = round_unscaled (cur_exp);
          if (cur_cmd != 81)
          {
            missing_err (58);
            {
              help_ptr = 1;
              help_line[0] = 1022;
            }
            back_error ();
          }
          if (c == 3)
            do {
              if (j > header_size)
                overflow (1007, header_size);
              header_byte[j] = get_code ();
              incr (j);
            } while (!(cur_cmd != 82));
          else
            do {
              if (j > max_font_dimen)
                overflow (1008, max_font_dimen);
              while (j > np)
              {
                incr (np);
                param[np] = 0;
              }
              get_x_next ();
              scan_expression ();
              if (cur_type != 16)
              {
                disp_err (0, 1040);
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
/* 1177 */
void do_special (void)
{
  small_number m;

  m = cur_mod;
  get_x_next ();
  scan_expression ();
  if (internal[34] >= 0)
  {
    if (cur_type != m)
    {
      disp_err (0, 1061);
      {
        help_ptr = 1;
        help_line[0] = 1062;
      }
      put_get_error ();
    }
    else
    {
      if (output_file_name == 0)
        init_gf ();
      if (m == 4)
        gf_string (cur_exp, 0);
      else
      {
        {
          gf_buf[gf_ptr] = 243;
          incr (gf_ptr);
          if (gf_ptr == gf_limit)
            gf_swap ();
        }
        gf_four (cur_exp);
      }
    }
  }
  flush_cur_exp (0);
}
/* 989 */
void do_statement (void)
{
  cur_type = 1;
  get_x_next ();
  if (cur_cmd > 43)
  {
    if (cur_cmd < 83)
    {
      print_err("A statement can't begin with `");
      print_cmd_mod (cur_cmd, cur_mod);
      print_char(39);
      {
        help_ptr = 5;
        help_line[4] = 870;
        help_line[3] = 871;
        help_line[2] = 872;
        help_line[1] = 873;
        help_line[0] = 874;
      }
      back_error ();
      get_x_next ();
    }
  }
  else if (cur_cmd > 30)
  {
    var_flag = 77;
    scan_expression ();
    if (cur_cmd < 84)
    {
      if (cur_cmd == 51)
        do_equation ();
      else if (cur_cmd == 77)
        do_assignment ();
      else if (cur_type == 4)
      {
        if (internal[1] > 0)
        {
          print_nl(261);
          slow_print(cur_exp);
          fflush (stdout);
        }
        if (internal[34] > 0)
        {
          if (output_file_name == 0)
            init_gf ();
          gf_string (1063, cur_exp);
        }
      }
      else if (cur_type != 1)
      {
        disp_err (0, 879);
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
  else
  {
    if (internal[7] > 0)
      show_cmd_mod (cur_cmd, cur_mod);
    switch (cur_cmd)
    {
      case 30:
        do_type_declaration ();
        break;
      case 16:
        if (cur_mod > 2)
          make_op_def ();
        else if (cur_mod > 0)
          scan_def ();
        break;
      case 24 :
        do_random_seed ();
        break;
      case 23 :
        {
          print_ln ();
          interaction = cur_mod;
          if (interaction == 0)
            kpsemaketexdiscarderrors = 1;
          else
            kpsemaketexdiscarderrors = 0;
          if (interaction == 0)
            selector = 0;
          else
            selector = 1;
          if (log_opened)
            selector = selector + 2;
          get_x_next ();
        }
        break;
      case 21:
        do_protection ();
        break;
      case 27:
        def_delims ();
        break;
      case 12:
        do {
          get_symbol ();
          save_variable (cur_sym);
          get_x_next ();
        } while (!(cur_cmd != 82));
        break;
      case 13:
        do_interim ();
        break;
      case 14:
        do_let ();
        break;
      case 15:
        do_new_internal ();
        break;
      case 22:
        do_show_whatever ();
        break;
      case 18:
        do_add_to ();
        break;
      case 17:
        do_ship_out ();
        break;
      case 11:
        do_display ();
        break;
      case 28:
        doopen_window ();
        break;
      case 19:
        do_cull ();
        break;
      case 26:
        {
          get_symbol ();
          start_sym = cur_sym;
          get_x_next ();
        }
        break;
      case 25:
        do_message ();
        break;
      case 20:
        do_tfm_command ();
        break;
      case 29:
        do_special ();
        break;
    }
    cur_type = 1;
  }
  if (cur_cmd < 83)
  {
    print_err("Extra tokens will be flushed");
    {
      help_ptr = 6;
      help_line[5] = 876;
      help_line[4] = 877;
      help_line[3] = 878;
      help_line[2] = 872;
      help_line[1] = 873;
      help_line[0] = 874;
    }
    back_error ();
    scanner_status = 2;
    do {
      get_next ();
      if (cur_cmd == 39)
      {
        if (str_ref[cur_mod]< 127)
        {
          if (str_ref[cur_mod] > 1)
            decr (str_ref[cur_mod]);
          else
            flush_string (cur_mod);
        }
      }
    } while (!(cur_cmd > 82));
    scanner_status = 0;
  }
  error_count = 0;
}
/* 1017 */
void main_control (void)
{
  do {
    do_statement ();
    if (cur_cmd == 84)
    {
      print_err("Extra `endgroup'");
      {
        help_ptr = 2;
        help_line[1] = 911;
        help_line[0] = 690;
      }
      flush_error (0);
    }
  } while (!(cur_cmd == 85));
}
/* 1117 */
halfword sort_in (scaled v)
{
  halfword Result;
  halfword p, q, r;

  p = mem_top - 1;
  while (true)
  {
    q = mem[p].hh.rh;
    if (v <= mem[q + 1].cint)
      goto found;
    p = q;
  }
found:
  if (v < mem[q + 1].cint)
  {
    r = get_node (2);
    mem[r + 1].cint = v;
    mem[r].hh.rh = q;
    mem[p].hh.rh = r;
  }
  Result = mem[p].hh.rh;
  return Result;
}
/* 1118 */
integer min_cover (scaled d)
{
  integer Result;
  halfword p;
  scaled l;
  integer m;

  m = 0;
  p = mem[mem_top - 1].hh.rh;
  perturbation = 2147483647L;
  while (p != 19)
  {
    incr (m);
    l = mem[p + 1].cint;
    do {
      p = mem[p].hh.rh;
    } while (!(mem[p + 1].cint > l + d));
    if (mem[p + 1].cint - l < perturbation)
      perturbation = mem[p + 1].cint - l;
  }
  Result = m;
  return Result;
}
/* 1120 */
scaled threshold (integer m)
{
  scaled Result;
  scaled d;

  excess = min_cover (0) - m;
  if (excess <= 0)
    Result = 0;
  else
  {
    do {
      d = perturbation;
    } while (!(min_cover (d + d) <= m));
    while (min_cover (d) > m)
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
  halfword p, q, r;
  scaled l;
  scaled v;

  d = threshold_fn (m);
  perturbation = 0;
  q = mem_top - 1;
  m = 0;
  p = mem[mem_top - 1].hh.rh;
  while (p != 19)
  {
    incr (m);
    l = mem[p + 1].cint;
    mem[p].hh.lh = m;
    if (mem[mem[p].hh.rh + 1].cint <= l + d)
    {
      do {
        p = mem[p].hh.rh;
        mem[p].hh.lh = m;
        decr (excess);
        if (excess == 0)
          d = 0;
      } while (!(mem[mem[p].hh.rh + 1].cint > l + d));
      v = l + half (mem[p + 1].cint - l);
      if (mem[p + 1].cint - v > perturbation)
        perturbation = mem[p + 1].cint - v;
      r = q;
      do {
        r = mem[r].hh.rh;
        mem[r + 1].cint = v;
      } while (!(r == p));
      mem[q].hh.rh = p;
    }
    q = p;
    p = mem[p].hh.rh;
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

  d = internal[26];
  if ((d < 65536L) || (d >= 134217728L))
  {
    if (d != 0)
      print_nl(1044);
    d = 8388608L;
    internal[26] = d;
  }
  if (header_byte[5] < 0)
  {
    if (header_byte[6] < 0)
    {
      if (header_byte[7] < 0)
      {
        if (header_byte[8] < 0)
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
/* 1129 */
integer dimen_out (scaled x)
{
  integer Result;

  if (abs (x) > max_tfm_dimen)
  {
    incr (tfm_changed);
    if (x > 0)
      x = max_tfm_dimen;
    else
      x = -max_tfm_dimen;
  }
  x = make_scaled (x * 16, internal[26]);
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
          {
            integer for_end; k = bc;for_end = ec;
            if (k <= for_end) do
              if (char_exists[k])
              {
                x = dimen_out (mem[tfm_width[k]+ 1].cint) + (k + 4) * 4194304L;
                lb1 = (lb1 + lb1 + x) % 255;
                lb2 = (lb2 + lb2 + x) % 253;
                lb3 = (lb3 + lb3 + x) % 251;
                b4 = (b4 + b4 + x) % 247;
              }
            while (k++ < for_end);
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
  {
    integer for_end; k = 1;for_end = 4;
    if (k <= for_end) do
      if (header_byte[k]< 0)
        header_byte[k] = 0;
    while (k++ < for_end);
  }
  lab_exit:;
}
/* 1133 */
void tfm_qqqq (four_quarters x)
{
  putbyte (x.b0, tfm_file);
  putbyte (x.b1, tfm_file);
  putbyte (x.b2, tfm_file);
  putbyte (x.b3, tfm_file);
}
/* 779 */
boolean open_base_file (void)
{
  boolean Result;
  integer j;

  j = cur_input.loc_field;
  if (buffer[cur_input.loc_field] == 38)
  {
    incr (cur_input.loc_field);
    j = cur_input.loc_field;
    buffer[last] = 32;
    while (buffer[j]!= 32)
      incr (j);
    pack_buffered_name (0, cur_input.loc_field, j - 1);
    if (w_open_in (base_file))
      goto found;
    Fputs (stdout,  "Sorry, I can't find the base `");
    fputs (stringcast (name_of_file + 1), stdout);
    Fputs (stdout,  "'; will try `");
    fputs (MF_base_default + 1, stdout);
    fprintf (stdout, "%s\n",  "'.");
    fflush (stdout);
  }
  pack_buffered_name (base_default_length - 5, 1, 0);
  if (!w_open_in (base_file))
  {
    ;
    Fputs (stdout, "I can't find the base file `");
    fputs (MF_base_default + 1, stdout);
    fprintf (stdout, "%s\n",  "'!");
    Result = false;
    goto lab_exit;
  }
found:
  cur_input.loc_field = j;
  Result = true;
  lab_exit:;
  return Result;
}
/* 823 */
void scan_primary (void)
{
  halfword p, q, r;
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
lab_restart:
  check_arith ();
  ;
#ifdef TEXMF_DEBUG
  if (panicking)
    check_mem (false);
#endif /* TEXMF_DEBUG */
  if (interrupt != 0)
  {
    if (OK_to_interrupt)
    {
      back_input ();
      {
        if (interrupt != 0)
          pause_for_instructions ();
      }
      get_x_next ();
    }
  }
  switch (cur_cmd)
  {
    case 31:
      {
        ldelim = cur_sym;
        rdelim = cur_mod;
        get_x_next ();
        scan_expression ();
        if ((cur_cmd == 82) && (cur_type >= 16))
        {
          p = get_node (2);
          mem[p].hh.b0 = 14;
          mem[p].hh.b1 = 11;
          init_big_node (p);
          q = mem[p + 1].cint;
          stash_in (q);
          get_x_next ();
          scan_expression ();
          if (cur_type < 16)
          {
            disp_err (0, 775);
            {
              help_ptr = 4;
              help_line[3] = 776;
              help_line[2] = 777;
              help_line[1] = 778;
              help_line[0] = 779;
            }
            put_get_flush_error (0);
          }
          stash_in (q + 2);
          check_delimiter (ldelim, rdelim);
          cur_type = 14;
          cur_exp = p;
        }
        else
          check_delimiter (ldelim, rdelim);
      }
      break;
    case 32:
      {
        groupline = line;
        if (internal[7] > 0)
          show_cmd_mod (cur_cmd, cur_mod);
        {
          p = get_avail ();
          mem[p].hh.lh = 0;
          mem[p].hh.rh = save_ptr;
          save_ptr = p;
        }
        do {
          do_statement ();
        } while (!(cur_cmd != 83));
        if (cur_cmd != 84)
        {
          print_err("A group begun on line ");
          print_int (groupline);
          print(781);
          {
            help_ptr = 2;
            help_line[1] = 782;
            help_line[0] = 783;
          }
          back_error ();
          cur_cmd = 84;
        }
        unsave ();
        if (internal[7] > 0)
          show_cmd_mod (cur_cmd, cur_mod);
      }
      break;
    case 39:
      {
        cur_type = 4;
        cur_exp = cur_mod;
      }
      break;
    case 42:
      {
        cur_exp = cur_mod;
        cur_type = 16;
        get_x_next ();
        if (cur_cmd != 54)
        {
          num = 0;
          denom = 0;
        }
        else
        {
          get_x_next ();
          if (cur_cmd != 42)
          {
            back_input ();
            cur_cmd = 54;
            cur_mod = 72;
            cur_sym = 9761;
            goto done;
          }
          num = cur_exp;
          denom = cur_mod;
          if (denom == 0)
          {
            print_err("Division by zero");
            {
              help_ptr = 1;
              help_line[0] = 785;
            }
            error ();
          }
          else cur_exp = make_scaled (num, denom);
          {
            check_arith ();
          }
          get_x_next ();
        }
        if (cur_cmd >= 30)
        {
          if (cur_cmd < 42)
          {
            p = stash_cur_exp ();
            scan_primary ();
            if ((abs (num) >= abs (denom)) || (cur_type < 14))
              do_binary (p, 71);
            else
            {
              frac_mult (num, denom);
              free_node (p, 2);
            }
          }
        }
        goto done;
      }
      break;
    case 33:
      do_nullary (cur_mod);
      break;
    case 34:
    case 30:
    case 36:
    case 43:
      {
        c = cur_mod;
        get_x_next ();
        scan_primary ();
        do_unary (c);
        goto done;
      }
      break;
    case 37:
      {
        c = cur_mod;
        get_x_next ();
        scan_expression ();
        if (cur_cmd != 69)
        {
          missing_err (479);
          print(716);
          print_cmd_mod (37, c);
          {
            help_ptr = 1;
            help_line[0] = 717;
          }
          back_error ();
        }
        p = stash_cur_exp ();
        get_x_next ();
        scan_primary ();
        do_binary (p, c);
        goto done;
      }
      break;
    case 35:
      {
        get_x_next ();
        scan_suffix ();
        old_setting = selector;
        selector = 5;
        show_token_list (cur_exp, 0, 100000L, 0);
        flush_token_list (cur_exp);
        cur_exp = make_string ();
        selector = old_setting;
        cur_type = 4;
        goto done;
      }
      break;
    case 40:
      {
        q = cur_mod;
        if (myvar_flag == 77)
        {
          get_x_next ();
          if (cur_cmd == 77)
          {
            cur_exp = get_avail ();
            mem[cur_exp].hh.lh = q + 9769;
            cur_type = 20;
            goto done;
          }
          back_input ();
        }
        cur_type = 16;
        cur_exp = internal[q];
      }
      break;
    case 38:
      make_exp_copy (cur_mod);
      break;
    case 41:
      {
        {
          prehead = avail;
          if (prehead == 0)
            prehead = get_avail ();
          else
          {
            avail = mem[prehead].hh.rh;
            mem[prehead].hh.rh = 0;
            ;
#ifdef STAT
            incr (dyn_used);
#endif /* STAT */
          }
        }
        tail = prehead;
        posthead = 0;
        tt = 1;
        while (true)
        {
          t = cur_tok ();
          mem[tail].hh.rh = t;
          if (tt != 0)
          {
            {
              p = mem[prehead].hh.rh;
              q = mem[p].hh.lh;
              tt = 0;
              if (eqtb[q].lh % 86 == 41)
              {
                q = eqtb[q].v.RH;
                if (q == 0)
                  goto done2;
                while (true)
                {
                  p = mem[p].hh.rh;
                  if (p == 0)
                  {
                    tt = mem[q].hh.b0;
                    goto done2;
                  }
                  if (mem[q].hh.b0 != 21)
                    goto done2;
                  q = mem[mem[q + 1].hh.lh].hh.rh;
                  if (p >= hi_mem_min)
                  {
                    do {
                      q = mem[q].hh.rh;
                    } while (!(mem[q + 2].hh.lh >= mem[p].hh.lh));
                    if (mem[q + 2].hh.lh > mem[p].hh.lh)
                      goto done2;
                  }
                }
              }
              done2:;
            }
            if (tt >= 22)
            {
              mem[tail].hh.rh = 0;
              if (tt > 22)
              {
                posthead = get_avail ();
                tail = posthead;
                mem[tail].hh.rh = t;
                tt = 0;
                macroref = mem[q + 1].cint;
                incr (mem[macroref].hh.lh);
              }
              else
              {
                p = get_avail ();
                mem[prehead].hh.lh = mem[prehead].hh.rh;
                mem[prehead].hh.rh = p;
                mem[p].hh.lh = t;
                macro_call (mem[q + 1].cint, prehead, 0);
                get_x_next ();
                goto lab_restart;
              }
            }
          }
          get_x_next ();
          tail = t;
          if (cur_cmd == 63)
          {
            get_x_next ();
            scan_expression ();
            if (cur_cmd != 64)
            {
              back_input ();
              back_expr ();
              cur_cmd = 63;
              cur_mod = 0;
              cur_sym = 9760;
            }
            else
            {
              if (cur_type != 16)
                bad_sub_script ();
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
      done1:
        if (posthead != 0)
        {
          back_input ();
          p = get_avail ();
          q = mem[posthead].hh.rh;
          mem[prehead].hh.lh = mem[prehead].hh.rh;
          mem[prehead].hh.rh = posthead;
          mem[posthead].hh.lh = q;
          mem[posthead].hh.rh = p;
          mem[p].hh.lh = mem[q].hh.rh;
          mem[q].hh.rh = 0;
          macro_call (macroref, prehead, 0);
          decr (mem[macroref].hh.lh);
          get_x_next ();
          goto lab_restart;
        }
        q = mem[prehead].hh.rh;
        {
          mem[prehead].hh.rh = avail;
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
          make_exp_copy (p);
        else
        {
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
        bad_exp (769);
        goto lab_restart;
      }
      break;
  }
  get_x_next ();
done:
  if (cur_cmd == 63)
  {
    if (cur_type >= 16)
    {
      p = stash_cur_exp ();
      get_x_next ();
      scan_expression ();
      if (cur_cmd != 82)
      {
        {
          back_input ();
          back_expr ();
          cur_cmd = 63;
          cur_mod = 0;
          cur_sym = 9760;
        }
        unstash_cur_exp (p);
      }
      else
      {
        q = stash_cur_exp ();
        get_x_next ();
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
          back_error ();
        }
        r = stash_cur_exp ();
        make_exp_copy (q);
        do_binary (r, 70);
        do_binary (p, 71);
        do_binary (q, 69);
        get_x_next ();
      }
    }
  }
}
/* 860 */
void scan_suffix (void)
{
  halfword h, t;
  halfword p;

  h = get_avail ();
  t = h;
  while (true)
  {
    if (cur_cmd == 63)
    {
      get_x_next ();
      scan_expression ();
      if (cur_type != 16)
        bad_sub_script ();
      if (cur_cmd != 64)
      {
        missing_err (93);
        {
          help_ptr = 3;
          help_line[2] = 803;
          help_line[1] = 802;
          help_line[0] = 698;
        }
        back_error ();
      }
      cur_cmd = 42;
      cur_mod = cur_exp;
    }
    if (cur_cmd == 42)
      p = new_num_tok (cur_mod);
    else if ((cur_cmd == 41) || (cur_cmd == 40))
    {
      p = get_avail ();
      mem[p].hh.lh = cur_sym;
    }
    else
      goto done;
    mem[t].hh.rh = p;
    t = p;
    get_x_next ();
  }
done:
  cur_exp = mem[h].hh.rh;
  {
    mem[h].hh.rh = avail;
    avail = h;
    ;
#ifdef STAT
    decr (dyn_used);
#endif /* STAT */
  }
  cur_type = 20;
}
/* 862 */
void scan_secondary (void)
{
  halfword p;
  halfword c, d;
  halfword macname;

lab_restart:
  if ((cur_cmd < 30) || (cur_cmd > 43))
    bad_exp (804);
  scan_primary ();
lab_continue:
  if (cur_cmd <= 55)
  {
    if (cur_cmd >= 52)
    {
      p = stash_cur_exp ();
      c = cur_mod;
      d = cur_cmd;
      if (d == 53)
      {
        macname = cur_sym;
        incr (mem[c].hh.lh);
      }
      get_x_next ();
      scan_primary ();
      if (d != 53)
       do_binary (p, c);
      else
      {
        back_input ();
        binary_mac (p, c, macname);
        decr (mem[c].hh.lh);
        get_x_next ();
        goto lab_restart;
      }
      goto lab_continue;
    }
  }
}
/* 864 */
void scan_tertiary (void)
{
  halfword p;
  halfword c, d;
  halfword macname;

lab_restart:
  if ((cur_cmd < 30) || (cur_cmd > 43))
    bad_exp (805);
  scan_secondary ();
  if (cur_type == 8)
    materialize_pen ();
lab_continue:
  if (cur_cmd <= 45)
  {
    if (cur_cmd >= 43)
    {
      p = stash_cur_exp ();
      c = cur_mod;
      d = cur_cmd;
      if (d == 44)
      {
        macname = cur_sym;
        incr (mem[c].hh.lh);
      }
      get_x_next ();
      scan_secondary ();
      if (d != 44)
        do_binary (p, c);
      else
      {
        back_input ();
        binary_mac (p, c, macname);
        decr (mem[c].hh.lh);
        get_x_next ();
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
  if ((cur_cmd < 30) || (cur_cmd > 43))
    bad_exp (808);
  scan_tertiary ();
lab_continue:
  if (cur_cmd <= 51)
  {
    if (cur_cmd >= 46)
    {
      if ((cur_cmd != 51) || (myvar_flag != 77))
      {
        p = stash_cur_exp ();
        c = cur_mod;
        d = cur_cmd;
        if (d == 49)
        {
          macname = cur_sym;
          incr (mem[c].hh.lh);
        }
        if ((d < 48) || ((d == 48) && ((mem[p].hh.b0 == 14) || (mem[p].hh.b0 == 9))))
        {
          cyclehit = false;
          {
            unstash_cur_exp (p);
            if (cur_type == 14)
              p = new_knot ();
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
          if (cur_cmd == 46)
          {
            t = scan_direction ();
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
            get_x_next ();
            if (cur_cmd == 58)
            {
              get_x_next ();
              y = cur_cmd;
              if (cur_cmd == 59)
                get_x_next ();
              scan_primary ();
              if ((cur_type != 16) || (cur_exp < 49152L))
              {
                disp_err (0, 826);
                {
                  help_ptr = 1;
                  help_line[0] = 827;
                }
                put_get_flush_error (65536L);
              }
              if (y == 59)
                cur_exp = -cur_exp;
              mem[q + 6].cint = cur_exp;
              if (cur_cmd == 52)
              {
                get_x_next ();
                y = cur_cmd;
                if (cur_cmd == 59)
                  get_x_next ();
                scan_primary ();
                if ((cur_type != 16) || (cur_exp < 49152L))
                {
                  disp_err (0, 826);
                  {
                    help_ptr = 1;
                    help_line[0] = 827;
                  }
                  put_get_flush_error (65536L);
                }
                if (y == 59)
                  cur_exp = -cur_exp;
              }
              y = cur_exp;
            }
            else if (cur_cmd == 57)
            {
              mem[q].hh.b1 = 1;
              t = 1;
              get_x_next ();
              scan_primary ();
              known_pair ();
              mem[q + 5].cint = cur_x;
              mem[q + 6].cint = cur_y;
              if (cur_cmd != 52)
              {
                x = mem[q + 5].cint;
                y = mem[q + 6].cint;
              }
              else
              {
                get_x_next ();
                scan_primary ();
                known_pair ();
                x = cur_x;
                y = cur_y;
              }
            }
            else
            {
              mem[q + 6].cint = 65536L;
              y = 65536L;
              back_input ();
              goto done;
            }
            if (cur_cmd != 47)
            {
              missing_err (408);
              {
                help_ptr = 1;
                help_line[0] = 825;
              }
              back_error ();
            }
            done:;
          }
          else if (d != 48)
            goto lab26;
          get_x_next ();
          if (cur_cmd == 46)
          {
            t = scan_direction ();
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
          if (cur_cmd == 36)
          {
            cyclehit = true;
            get_x_next ();
            pp = p;
            qq = p;
            if (d == 48)
            {
              if (p == q)
              {
                d = 47;
                mem[q + 6].cint = 65536L;
                y = 65536L;
              }
            }
          }
          else
          {
            scan_tertiary ();
            {
              if (cur_type != 9)
                pp = new_knot ();
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
                  mem[q + 3].cint = 65536L;
                }
              }
              if (mem[pp].hh.b1 == 4)
              {
                if (t == 4)
                {
                  mem[pp].hh.b1 = 3;
                  mem[pp + 5].cint = 65536L;
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
          if (cur_cmd >= 46)
          {
            if (cur_cmd <= 48)
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
              mem[p + 5].cint = 65536L;
            }
            mem[q].hh.b1 = 0;
            if (mem[q].hh.b0 == 4)
            {
              mem[q].hh.b0 = 3;
              mem[q + 3].cint = 65536L;
            }
            mem[q].hh.rh = p;
          }
          make_choices (p);
          cur_type = 9;
          cur_exp = p;
        }
        else
        {
          get_x_next ();
          scan_tertiary ();
          if (d != 49)
            do_binary (p, c);
          else
          {
            back_input ();
            binary_mac (p, c, macname);
            decr (mem[c].hh.lh);
            get_x_next ();
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
  get_x_next ();
  scan_expression ();
  if (cur_type != 2)
  {
    disp_err (0, 832);
    {
      help_ptr = 2;
      help_line[1] = 833;
      help_line[0] = 834;
    }
    put_get_flush_error (31);
    cur_type = 2;
  }
}
/* 224 */
void print_capsule (void)
{
  print_char(40);
  print_exp (g_pointer, 0);
  print_char(41);
}
/* 224 */
void token_recycle (void)
{
  recycle_value (g_pointer);
}
/* 1205 */
void close_files_and_terminate (void)
{
  integer k;
  integer lh;
  short lkoffset;
  halfword p;
  scaled x;

  ;
#ifdef STAT
  if (internal[12] > 0)
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
  if ((gf_prev_ptr > 0) || (internal[33] > 0))
  {
    rover = 23;
    mem[rover].hh.rh = 268435455L;
    lo_mem_max = hi_mem_min - 1;
    if (lo_mem_max - rover > 268435455L)
      lo_mem_max = 268435455L + rover;
    mem[rover].hh.lh = lo_mem_max - rover;
    mem[rover + 1].hh.lh = rover;
    mem[rover + 1].hh.rh = rover;
    mem[lo_mem_max].hh.rh = 0;
    mem[lo_mem_max].hh.lh = 0;
    mem[mem_top - 1].hh.rh = 19;
    {
      integer for_end; k = bc;for_end = ec;
      if (k <= for_end) do
        if (char_exists[k])
          tfm_width[k] = sort_in (tfm_width[k]);
        while (k++ < for_end);
    }
    nw = skimp (255) + 1;
    dimen_head[1] = mem[mem_top - 1].hh.rh;
    if (perturbation >= 4096)
      tfm_warning (20);
    fix_design_size ();
    fix_check_sum ();
    if (internal[33] > 0)
    {
      mem[mem_top - 1].hh.rh = 19;
      {
        integer for_end; k = bc;for_end = ec;
        if (k <= for_end) do
          if (char_exists[k])
          {
            if (tfm_height[k] == 0)
              tfm_height[k] = 15;
            else
              tfm_height[k] = sort_in (tfm_height[k]);
          }
          while (k++ < for_end);
      }
      nh = skimp (15) + 1;
      dimen_head[2] = mem[mem_top - 1].hh.rh;
      if (perturbation >= 4096)
        tfm_warning (21);
      mem[mem_top - 1].hh.rh = 19;
      {
        integer for_end; k = bc;for_end = ec;
        if (k <= for_end) do
          if (char_exists[k])
          {
            if (tfm_depth[k] == 0)
              tfm_depth[k] = 15;
            else
              tfm_depth[k] = sort_in (tfm_depth[k]);
          }
        while (k++ < for_end);
      }
      nd = skimp (15) + 1;
      dimen_head[3] = mem[mem_top - 1].hh.rh;
      if (perturbation >= 4096)
        tfm_warning (22);
      mem[mem_top - 1].hh.rh = 19;
      {
        integer for_end; k = bc;for_end = ec;
        if (k <= for_end) do
          if (char_exists[k])
          {
            if (tfm_ital_corr[k] == 0)
              tfm_ital_corr[k] = 15;
            else
              tfm_ital_corr[k] = sort_in (tfm_ital_corr[k]);
          }
        while (k++ < for_end);
      }
      ni = skimp (63) + 1;
      dimen_head[4] = mem[mem_top - 1].hh.rh;
      if (perturbation >= 4096)
        tfm_warning (23);
      internal[33] = 0;
      if (job_name == 0)
        open_log_file ();
      pack_job_name (1045);
      while (!bopenout (tfm_file))
        prompt_file_name (1046, 1045);
      metric_file_name = b_make_name_string (tfm_file);
      k = header_size;
      while (header_byte[k] < 0)
        decr (k);
      lh = (k + 3) / 4;
      if (bc > ec)
        bc = 1;
      bchar = round_unscaled (internal[41]);
      if ((bchar < 0) || (bchar > 255))
      {
        bchar = -1;
        lk_started = false;
        lkoffset = 0;
      }
      else
      {
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
          while (label_loc[k - 1] == label_loc[k])
          {
            decr (k);
            char_remainder[label_char[k]] = lkoffset;
          }
          incr (lkoffset);
          decr (k);
        } while (!(lkoffset + label_loc[k]< 256));
      }
      if (lkoffset > 0)
        while (k > 0)
        {
          char_remainder[label_char[k]] = char_remainder[label_char[k]] + lkoffset;
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
      put2bytes (tfm_file, 6 + lh + (ec - bc + 1) + nw + nh + nd + ni + nl + lkoffset + nk + ne + np);
      put2bytes (tfm_file, lh);
      put2bytes (tfm_file, bc);
      put2bytes (tfm_file, ec);
      put2bytes (tfm_file, nw);
      put2bytes (tfm_file, nh);
      put2bytes (tfm_file, nd);
      put2bytes (tfm_file, ni);
      put2bytes (tfm_file, nl + lkoffset);
      put2bytes (tfm_file, nk);
      put2bytes (tfm_file, ne);
      put2bytes (tfm_file, np);
      {
        integer for_end; k = 1;for_end = 4 * lh;
        if (k <= for_end) do
        {
          if (header_byte[k]< 0)
            header_byte[k] = 0;
          putbyte (header_byte[k], tfm_file);
        }
        while (k++ < for_end);
      }
      {
        integer for_end; k = bc;for_end = ec;
        if (k <= for_end) do
          if (!char_exists[k])
            put4bytes (tfm_file, 0);
          else
          {
            putbyte (mem[tfm_width[k]].hh.lh, tfm_file);
            putbyte ((mem[tfm_height[k]].hh.lh) * 16 + mem[
            tfm_depth[k]].hh.lh, tfm_file);
            putbyte ((mem[tfm_ital_corr[k]].hh.lh) * 4 +
            char_tag[k], tfm_file);
            putbyte (char_remainder[k], tfm_file);
          }
        while (k++ < for_end);
      }
      tfm_changed = 0;
      {
        integer for_end; k = 1;for_end = 4;
        if (k <= for_end) do
        {
          put4bytes (tfm_file, 0);
          p = dimen_head[k];
          while (p != 19)
          {
            put4bytes (tfm_file, dimen_out (mem[p + 1].cint));
            p = mem[p].hh.rh;
          }
        }
        while (k++ < for_end);
      }
      {
        integer for_end; k = 0;for_end = 255;
        if (k <= for_end) do
          if (skip_table[k]< lig_table_size)
          {
            print_nl(1048);
            print_int (k);
            print(1049);
            ll = skip_table[k];
            do {
              lll = lig_kern[ll].b0;
              lig_kern[ll].b0 = 128;
              ll = ll - lll;
            } while (!(lll == 0));
          }
        while (k++ < for_end);
      }
      if (lk_started)
      {
        putbyte (255, tfm_file);
        putbyte (bchar, tfm_file);
        put2bytes (tfm_file, 0);
      }
      else
      {
        integer for_end; k = 1;for_end = lkoffset;
        if (k <= for_end) do
        {
          ll = label_loc[label_ptr];
          if (bchar < 0)
          {
            putbyte (254, tfm_file);
            putbyte (0, tfm_file);
          }
          else
          {
            putbyte (255, tfm_file);
            putbyte (bchar, tfm_file);
          }
          put2bytes (tfm_file, ll + lkoffset);
          do {
            decr (label_ptr);
          } while (!(label_loc[label_ptr]< ll));
        }
        while (k++ < for_end);
      }
      {
        integer for_end; k = 0;for_end = nl - 1;
        if (k <= for_end) do
          tfm_qqqq (lig_kern[k]);
          while (k++ < for_end);
      }
      {
        integer for_end; k = 0;for_end = nk - 1;
        if (k <= for_end) do
          put4bytes (tfm_file, dimen_out (kern[k]));
          while (k++ < for_end);
      }
      {
        integer for_end; k = 0;for_end = ne - 1;
        if (k <= for_end) do
          tfm_qqqq (exten[k]);
          while (k++ < for_end);
      }
      {
        integer for_end; k = 1;for_end = np;
        if (k <= for_end) do
          if (k == 1)
          {
            if (abs (param[1]) < 134217728L)
              put4bytes (tfm_file, param[1]* 16);
            else
            {
              incr (tfm_changed);
              if (param[1] > 0)
                put4bytes (tfm_file, 2147483647L);
              else
                put4bytes (tfm_file, -2147483647L);
            }
          }
          else
            put4bytes (tfm_file, dimen_out (param[k]));
          while (k++ < for_end);
      }
      if (tfm_changed > 0)
      {
        if (tfm_changed == 1)
          print_nl(1050);
        else
        {
          print_nl(40);
          print_int (tfm_changed);
          print(1051);
        }
        print(1052);
      }
      ;
#ifdef STAT
      if (internal[12] > 0)
      {
        { putc (' ', log_file);  putc ('\n', log_file); }
        if (bch_label < lig_table_size)
          decr (nl);
        fprintf (log_file, "%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s\n", "(You used ", (long)nw, "w,", (long)nh, "h,", (long)nd, "d,", (long)ni, "i,", (long)nl, "l,", (long)nk, "k,", (long)ne, "e,", (long)np, "p metric file positions");
        fprintf (log_file, "%s%s%ld%s%ld%s%ld%s\n", "  out of ", "256w,16h,16d,64i,", (long)lig_table_size, "l,", (long)max_kerns, "k,256e,", (long)max_font_dimen, "p)");
      }
#endif /* STAT */
      print_nl(1047);
      print_file_name (0, metric_file_name, 0);
      print_char(46);
      b_close (tfm_file);
    }
    if (gf_prev_ptr > 0)
    {
      {
        gf_buf[gf_ptr] = 248;
        incr (gf_ptr);
        if (gf_ptr == gf_limit)
          gf_swap ();
      }
      gf_four (gf_prev_ptr);
      gf_prev_ptr = gf_offset + gf_ptr - 5;
      gf_four (internal[26]* 16);
      {
        integer for_end; k = 1;for_end = 4;
        if (k <= for_end) do
        {
          gf_buf[gf_ptr] = header_byte[k];
          incr (gf_ptr);
          if (gf_ptr == gf_limit)
            gf_swap ();
        }
        while (k++ < for_end);
      }
      gf_four (internal[27]);
      gf_four (internal[28]);
      gf_four (gf_min_m);
      gf_four (gf_max_m);
      gf_four (gf_min_n);
      gf_four (gf_max_n);
      {
        integer for_end; k = 0;for_end = 255;
        if (k <= for_end) do
          if (char_exists[k])
          {
            x = gf_dx[k]/ 65536L;
            if ((gf_dy[k] == 0) && (x >= 0) && (x < 256) && (gf_dx[k] == x * 65536L))
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
            else
            {
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
              gf_four (gf_dx[k]);
              gf_four (gf_dy[k]);
            }
            x = mem[tfm_width[k]+ 1].cint;
            if (abs (x) > max_tfm_dimen)
            {
              if (x > 0)
                x = 16777215L;
              else
                x = -16777215L;
            }
            else
              x = make_scaled (x * 16, internal[26]);
            gf_four (x);
            gf_four (char_ptr[k]);
          }
        while (k++ < for_end);
      }
      {
        gf_buf[gf_ptr] = 249;
        incr (gf_ptr);
        if (gf_ptr == gf_limit)
          gf_swap ();
      }
      gf_four (gf_prev_ptr);
      {
        gf_buf[gf_ptr] = 131;
        incr (gf_ptr);
        if (gf_ptr == gf_limit)
          gf_swap ();
      }
      k = 4 + ((gf_buf_size - gf_ptr) % 4);
      while (k > 0)
      {
        {
          gf_buf[gf_ptr] = 223;
          incr (gf_ptr);
          if (gf_ptr == gf_limit)
            gf_swap ();
        }
        decr (k);
      }
      if (gf_limit == half_buf)
        write_gf (half_buf, gf_buf_size - 1);
      if (gf_ptr > (2147483647L - gf_offset))
      {
        gf_prev_ptr = 0;
        fatal_error (1053);
      }
      if (gf_ptr > 0)
        write_gf (0, gf_ptr - 1);
      print_nl(1064);
      print_file_name (0, output_file_name, 0);
      print(558);
      print_int (total_chars);
      if (total_chars != 1)
        print(1065);
      else
        print(1066);
      print(1067);
      print_int (gf_offset + gf_ptr);
      print(1068);
      b_close (gf_file);
    }
  }
  if (log_opened)
  {
    putc ('\n', log_file);
    aclose (log_file);
    selector = selector - 2;
    if (selector == 1)
    {
      print_nl(1076);
      print_file_name (0, texmflogname, 0);
      print_char(46);
    }
  }
  print_ln ();
  if ((editnamestart != 0) && (interaction > 0))
    calledit (str_pool, editnamestart, editname_length, editline);
}
/* 1212 */
#ifdef TEXMF_DEBUG
void debug_help (void)
{
  integer k, l, m, n;
  while (true)
  {
    ;
    print_nl(1083);
    fflush (stdout);
    read (stdin, m);
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
          print_word (mem[n]);
          break;
        case 2:
          print_int (mem[n].hh.lh);
          break;
        case 3:
          print_int (mem[n].hh.rh);
          break;
        case 4:
          {
            print_int (eqtb[n].lh);
            print_char(58);
            print_int (eqtb[n].v.RH);
          }
          break;
        case 5:
          print_variable_name(n);
          break;
        case 6:
          print_int (internal[n]);
          break;
        case 7:
          do_show_dependencies ();
          break;
        case 9:
          show_token_list (n, 0, 100000L, 0);
          break;
        case 10:
          slow_print(n);
          break;
        case 11:
          check_mem (n > 0);
          break;
        case 12:
          search_mem (n);
          break;
        case 13:
          {
            read (stdin, l);
            print_cmd_mod (n, l);
          }
          break;
        case 14:
          {
            integer for_end; k = 0;for_end = n;
            if (k <= for_end) do
              print(buffer[k]);
            while (k++ < for_end);
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
