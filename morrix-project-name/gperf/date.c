/* C code produced by gperf version 3.0.4 */
/* Command-line: gperf -t date.gperf  */
/* Computed positions: -k'1-2' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gnu-gperf@gnu.org>."
#endif

#line 1 "date.gperf"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef (*FUNCPTR)();
void show_msg()
{
	printf ("Hello World\n");
}
#line 12 "date.gperf"
struct oam {
	char *name;
	int date;
	FUNCPTR ptr;
};

#define TOTAL_KEYWORDS 10
#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 5
#define MIN_HASH_VALUE 3
#define MAX_HASH_VALUE 28
/* maximum key range = 26, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
hash (str, len)
     register const char *str;
     register unsigned int len;
{
  static unsigned char asso_values[] =
    {
      29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
      29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
      29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
      29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
      29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
      29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
      29, 29, 29, 29, 29, 15, 29, 29, 29, 29,
       4, 29, 29, 29,  0, 29, 29,  5, 29, 15,
      29, 29, 29, 10, 29, 29, 29, 29, 29, 29,
      29, 29, 29, 29, 29, 29, 29,  5, 29, 10,
      29, 10, 29, 29, 29, 29, 29, 29, 29, 29,
      29, 29,  0, 29, 29, 29, 29,  0, 29, 29,
      29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
      29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
      29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
      29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
      29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
      29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
      29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
      29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
      29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
      29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
      29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
      29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
      29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
      29, 29, 29, 29, 29, 29
    };
  return len + asso_values[(unsigned char)str[1]] + asso_values[(unsigned char)str[0]];
}

#ifdef __GNUC__
__inline
#if defined __GNUC_STDC_INLINE__ || defined __GNUC_GNU_INLINE__
__attribute__ ((__gnu_inline__))
#endif
#endif
struct oam *
in_word_set (str, len)
     register const char *str;
     register unsigned int len;
{
  static struct oam wordlist[] =
    {
      {""}, {""}, {""},
#line 23 "date.gperf"
      {"Jun", 		31, (void *)0},
#line 24 "date.gperf"
      {"July", 	31, (void *)0},
      {""}, {""}, {""},
#line 18 "date.gperf"
      {"Jan", 		31, (void *)0},
      {""}, {""}, {""}, {""},
#line 22 "date.gperf"
      {"May", 		31, (void *)0},
      {""},
#line 20 "date.gperf"
      {"March", 	31, (void *)0},
      {""},
#line 19 "date.gperf"
      {"Feb", 		31, (void *)0},
#line 25 "date.gperf"
      {"Aug", 		31, (void *)0},
      {""},
#line 21 "date.gperf"
      {"April", 	31, show_msg},
      {""}, {""},
#line 26 "date.gperf"
      {"Sep", 		31, (void *)0},
      {""}, {""}, {""}, {""},
#line 27 "date.gperf"
      {"Oct", 		31, (void *)0}
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register int key = hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= 0)
        {
          register const char *s = wordlist[key].name;

          if (*str == *s && !strcmp (str + 1, s + 1))
            return &wordlist[key];
        }
    }
  return 0;
}
#line 28 "date.gperf"

int main()
{
	struct oam * mm = (void *)0;
	char * mon = "April";
	mm = in_word_set(mon, strlen(mon));
	printf ("name(%s),day(%d)\n", mm->name, mm->date);
	mm->ptr();

	return 0;
}
