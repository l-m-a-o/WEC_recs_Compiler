# Instructions
Ok, so to compile the compiler, use commands in README.txt and then just execute and enter any input. Endline character terminates input.

You should get Symbol table, lexical errors, and syntactical errors, if any. Else, it will show phase passed. Code also shows accepted token enum values in order.

# Lexical Phase
Done exactly as asked, including quotations and symbol table. 

If token less than 3 letters in a word, token is declared invalid.

If token more than 26 letters is split.
# Semantic Phase
Code accepts multiple sentences ending with full stops.

Each sentence can only start with title case word(starting word)

It ignores all whitespaces.

Commas and hyphens accept only non starting words on right side, but any word on left side.

Unresolved quotations throw syntax error.

Empty string within quotations throw error.

Quotations can't start with punctuation.

