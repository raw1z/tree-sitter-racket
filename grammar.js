module.exports = grammar({
  name: "racket",

  rules: {
    source_file: ($) => seq($.language, repeat($.datum)),

    language: ($) => seq("#lang", $.symbol),

    symbol: (_) => /[^()\[\]{}",'`;#|\s\\]+/,

    datum: ($) => choice($.number, $.boolean, $.string),

    number: (_) => {
      const sign = choice("-", "+");
      const digit_2 = /0|1/;
      const digit_8 = choice(digit_2, /[2-7]/);
      const digit_10 = choice(digit_8, /8|9/);
      const digit_16 = choice(digit_10, /[a-f]/);
      const digit = choice(digit_2, digit_8, digit_10, digit_16);
      const digit_hash = seq(digit, optional("#"));
      const exp_mark_16 = /s|l/;
      const exp_mark_10 = choice(exp_mark_16, /[d-f]/);
      const exp_mark_8 = exp_mark_10;
      const exp_mark_2 = exp_mark_10;
      const exactness = choice("#e", "#i");

      const unsigned_integer = repeat(digit);
      const exact_integer = seq(optional(sign), unsigned_integer);
      const unsigned_rational = choice(
        unsigned_integer,
        seq(unsigned_integer, "/", unsigned_integer)
      );
      const exact_rational = seq(optional(sign), unsigned_rational);
      const exact_complex = seq(exact_rational, sign, unsigned_rational, "i");
      const exact = choice(exact_integer, exact_rational);

      const integer = seq(optional(sign), /\d+/);

      const rational = seq(integer, "/", integer);

      const complex = seq(
        choice(integer, rational),
        choice("-", "+"),
        choice(integer, rational),
        "i"
      );

      const inexact = choice(
        seq(integer, ".", integer),
        seq(rational, "e", choice("+", "-"), integer),
        "+inf.0",
        "-inf.0",
        "+nan.0",
        "-nan.0"
      );

      return token(choice(/\d+([\./]\d+(e\+\d+)?)?/, /\d+\+\d+i/));
    },

    boolean: (_) => choice("#t", "#f"),

    string: ($) =>
      seq(
        '"',
        repeat(choice(token.immediate(prec(1, /[^"\\]+/)), $.escape_sequence)),
        '"'
      ),

    escape_sequence: (_) =>
      token.immediate(seq("\\", choice('"', /u[\da-fA-F]+/))),

    // $.symbol,
    // $.string,
    // $.boolean
    // $.list_or_pair,
    // $.quoted_datum
  },
});
