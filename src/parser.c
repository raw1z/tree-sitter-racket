#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 15
#define LARGE_STATE_COUNT 5
#define SYMBOL_COUNT 16
#define ALIAS_COUNT 0
#define TOKEN_COUNT 9
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 1

enum {
  anon_sym_POUNDlang = 1,
  sym_symbol = 2,
  sym_number = 3,
  anon_sym_POUNDt = 4,
  anon_sym_POUNDf = 5,
  anon_sym_DQUOTE = 6,
  aux_sym_string_token1 = 7,
  sym_escape_sequence = 8,
  sym_source_file = 9,
  sym_language = 10,
  sym_datum = 11,
  sym_boolean = 12,
  sym_string = 13,
  aux_sym_source_file_repeat1 = 14,
  aux_sym_string_repeat1 = 15,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_POUNDlang] = "#lang",
  [sym_symbol] = "symbol",
  [sym_number] = "number",
  [anon_sym_POUNDt] = "#t",
  [anon_sym_POUNDf] = "#f",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_string_token1] = "string_token1",
  [sym_escape_sequence] = "escape_sequence",
  [sym_source_file] = "source_file",
  [sym_language] = "language",
  [sym_datum] = "datum",
  [sym_boolean] = "boolean",
  [sym_string] = "string",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_string_repeat1] = "string_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_POUNDlang] = anon_sym_POUNDlang,
  [sym_symbol] = sym_symbol,
  [sym_number] = sym_number,
  [anon_sym_POUNDt] = anon_sym_POUNDt,
  [anon_sym_POUNDf] = anon_sym_POUNDf,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_string_token1] = aux_sym_string_token1,
  [sym_escape_sequence] = sym_escape_sequence,
  [sym_source_file] = sym_source_file,
  [sym_language] = sym_language,
  [sym_datum] = sym_datum,
  [sym_boolean] = sym_boolean,
  [sym_string] = sym_string,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_string_repeat1] = aux_sym_string_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_POUNDlang] = {
    .visible = true,
    .named = false,
  },
  [sym_symbol] = {
    .visible = true,
    .named = true,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_POUNDt] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_POUNDf] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_escape_sequence] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_language] = {
    .visible = true,
    .named = true,
  },
  [sym_datum] = {
    .visible = true,
    .named = true,
  },
  [sym_boolean] = {
    .visible = true,
    .named = true,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
};

static inline bool sym_symbol_character_set_1(int32_t c) {
  return (c < '\''
    ? (c < '\r'
      ? (c < '\t'
        ? c == 0
        : c <= '\n')
      : (c <= '\r' || (c < '"'
        ? c == ' '
        : c <= '#')))
    : (c <= ')' || (c < '['
      ? (c < ';'
        ? c == ','
        : c <= ';')
      : (c <= ']' || (c < '{'
        ? c == '`'
        : c <= '}')))));
}

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(17);
      if (lookahead == '"') ADVANCE(33);
      if (lookahead == '#') ADVANCE(5);
      if (lookahead == '\\') ADVANCE(2);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(15)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(19);
      if (lookahead != 0 &&
          (lookahead < '\'' || ')' < lookahead) &&
          lookahead != ',' &&
          lookahead != ';' &&
          (lookahead < '[' || ']' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(26);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(33);
      if (lookahead == '\\') ADVANCE(2);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(34);
      if (lookahead != 0) ADVANCE(35);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(36);
      if (lookahead == 'u') ADVANCE(14);
      END_STATE();
    case 3:
      if (lookahead == '+') ADVANCE(13);
      END_STATE();
    case 4:
      if (lookahead == 'a') ADVANCE(9);
      END_STATE();
    case 5:
      if (lookahead == 'f') ADVANCE(32);
      if (lookahead == 'l') ADVANCE(4);
      if (lookahead == 't') ADVANCE(31);
      END_STATE();
    case 6:
      if (lookahead == 'f') ADVANCE(32);
      if (lookahead == 't') ADVANCE(31);
      END_STATE();
    case 7:
      if (lookahead == 'g') ADVANCE(18);
      END_STATE();
    case 8:
      if (lookahead == 'i') ADVANCE(27);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(8);
      END_STATE();
    case 9:
      if (lookahead == 'n') ADVANCE(7);
      END_STATE();
    case 10:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(10)
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '#' &&
          (lookahead < '\'' || ')' < lookahead) &&
          lookahead != ',' &&
          lookahead != ';' &&
          (lookahead < '[' || ']' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(26);
      END_STATE();
    case 11:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(8);
      END_STATE();
    case 12:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(29);
      END_STATE();
    case 13:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(30);
      END_STATE();
    case 14:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(37);
      END_STATE();
    case 15:
      if (eof) ADVANCE(17);
      if (lookahead == '"') ADVANCE(33);
      if (lookahead == '#') ADVANCE(5);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(15)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(19);
      if (lookahead != 0 &&
          (lookahead < '\'' || ')' < lookahead) &&
          lookahead != ',' &&
          lookahead != ';' &&
          (lookahead < '[' || ']' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(26);
      END_STATE();
    case 16:
      if (eof) ADVANCE(17);
      if (lookahead == '"') ADVANCE(33);
      if (lookahead == '#') ADVANCE(6);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(16)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(28);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_POUNDlang);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '+') ADVANCE(23);
      if (lookahead == '.' ||
          lookahead == '/') ADVANCE(24);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(19);
      if (!sym_symbol_character_set_1(lookahead)) ADVANCE(26);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '+') ADVANCE(25);
      if (!sym_symbol_character_set_1(lookahead)) ADVANCE(26);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == 'e') ADVANCE(20);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(21);
      if (!sym_symbol_character_set_1(lookahead)) ADVANCE(26);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == 'i') ADVANCE(26);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(22);
      if (!sym_symbol_character_set_1(lookahead)) ADVANCE(26);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(sym_symbol);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(22);
      if (!sym_symbol_character_set_1(lookahead)) ADVANCE(26);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(sym_symbol);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(21);
      if (!sym_symbol_character_set_1(lookahead)) ADVANCE(26);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(sym_symbol);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(25);
      if (!sym_symbol_character_set_1(lookahead)) ADVANCE(26);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(sym_symbol);
      if (!sym_symbol_character_set_1(lookahead)) ADVANCE(26);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(sym_number);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '+') ADVANCE(11);
      if (lookahead == '.' ||
          lookahead == '/') ADVANCE(12);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(28);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == 'e') ADVANCE(3);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(29);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(30);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_POUNDt);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_POUNDf);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(34);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(35);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(35);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(37);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 16},
  [3] = {.lex_state = 16},
  [4] = {.lex_state = 16},
  [5] = {.lex_state = 16},
  [6] = {.lex_state = 16},
  [7] = {.lex_state = 16},
  [8] = {.lex_state = 16},
  [9] = {.lex_state = 16},
  [10] = {.lex_state = 1},
  [11] = {.lex_state = 1},
  [12] = {.lex_state = 1},
  [13] = {.lex_state = 10},
  [14] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_POUNDlang] = ACTIONS(1),
    [sym_symbol] = ACTIONS(1),
    [sym_number] = ACTIONS(1),
    [anon_sym_POUNDt] = ACTIONS(1),
    [anon_sym_POUNDf] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [sym_escape_sequence] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(14),
    [sym_language] = STATE(2),
    [anon_sym_POUNDlang] = ACTIONS(3),
  },
  [2] = {
    [sym_datum] = STATE(3),
    [sym_boolean] = STATE(6),
    [sym_string] = STATE(6),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_number] = ACTIONS(7),
    [anon_sym_POUNDt] = ACTIONS(9),
    [anon_sym_POUNDf] = ACTIONS(9),
    [anon_sym_DQUOTE] = ACTIONS(11),
  },
  [3] = {
    [sym_datum] = STATE(4),
    [sym_boolean] = STATE(6),
    [sym_string] = STATE(6),
    [aux_sym_source_file_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(13),
    [sym_number] = ACTIONS(7),
    [anon_sym_POUNDt] = ACTIONS(9),
    [anon_sym_POUNDf] = ACTIONS(9),
    [anon_sym_DQUOTE] = ACTIONS(11),
  },
  [4] = {
    [sym_datum] = STATE(4),
    [sym_boolean] = STATE(6),
    [sym_string] = STATE(6),
    [aux_sym_source_file_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(15),
    [sym_number] = ACTIONS(17),
    [anon_sym_POUNDt] = ACTIONS(20),
    [anon_sym_POUNDf] = ACTIONS(20),
    [anon_sym_DQUOTE] = ACTIONS(23),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 1,
    ACTIONS(26), 5,
      ts_builtin_sym_end,
      sym_number,
      anon_sym_POUNDt,
      anon_sym_POUNDf,
      anon_sym_DQUOTE,
  [8] = 1,
    ACTIONS(28), 5,
      ts_builtin_sym_end,
      sym_number,
      anon_sym_POUNDt,
      anon_sym_POUNDf,
      anon_sym_DQUOTE,
  [16] = 1,
    ACTIONS(30), 5,
      ts_builtin_sym_end,
      sym_number,
      anon_sym_POUNDt,
      anon_sym_POUNDf,
      anon_sym_DQUOTE,
  [24] = 1,
    ACTIONS(32), 5,
      ts_builtin_sym_end,
      sym_number,
      anon_sym_POUNDt,
      anon_sym_POUNDf,
      anon_sym_DQUOTE,
  [32] = 1,
    ACTIONS(34), 5,
      ts_builtin_sym_end,
      sym_number,
      anon_sym_POUNDt,
      anon_sym_POUNDf,
      anon_sym_DQUOTE,
  [40] = 3,
    ACTIONS(36), 1,
      anon_sym_DQUOTE,
    STATE(11), 1,
      aux_sym_string_repeat1,
    ACTIONS(38), 2,
      aux_sym_string_token1,
      sym_escape_sequence,
  [51] = 3,
    ACTIONS(40), 1,
      anon_sym_DQUOTE,
    STATE(12), 1,
      aux_sym_string_repeat1,
    ACTIONS(42), 2,
      aux_sym_string_token1,
      sym_escape_sequence,
  [62] = 3,
    ACTIONS(44), 1,
      anon_sym_DQUOTE,
    STATE(12), 1,
      aux_sym_string_repeat1,
    ACTIONS(46), 2,
      aux_sym_string_token1,
      sym_escape_sequence,
  [73] = 1,
    ACTIONS(49), 1,
      sym_symbol,
  [77] = 1,
    ACTIONS(51), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(5)] = 0,
  [SMALL_STATE(6)] = 8,
  [SMALL_STATE(7)] = 16,
  [SMALL_STATE(8)] = 24,
  [SMALL_STATE(9)] = 32,
  [SMALL_STATE(10)] = 40,
  [SMALL_STATE(11)] = 51,
  [SMALL_STATE(12)] = 62,
  [SMALL_STATE(13)] = 73,
  [SMALL_STATE(14)] = 77,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 2),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [17] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(6),
  [20] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(7),
  [23] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(10),
  [26] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_language, 2),
  [28] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_datum, 1),
  [30] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean, 1),
  [32] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 2),
  [34] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 3),
  [36] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [38] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [40] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [42] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [44] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 2),
  [46] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_repeat1, 2), SHIFT_REPEAT(12),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [51] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_racket(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
