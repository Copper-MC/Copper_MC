package vscode;

/**
 * Represents a line of text, such as a line of source code.
 *
 * TextLine objects are __immutable__. When a {@link TextDocument document} changes,
 * previously retrieved lines will not represent the latest state.
 */
typedef TextLine = {
	/**
	 * The zero-based line number.
	 */
	var lineNumber(default, null):Int;

	/**
	 * The text of this line without the line separator characters.
	 */
	var text(default, null):String;

	/**
	 * The range this line covers without the line separator characters.
	 */
	var range(default, null):Range;

	/**
	 * The range this line covers with the line separator characters.
	 */
	var rangeIncludingLineBreak(default, null):Range;

	/**
	 * The offset of the first character which is not a whitespace character as defined
	 * by `/\s/`. **Note** that if a line is all whitespace the length of the line is returned.
	 */
	var firstNonWhitespaceCharacterIndex(default, null):Int;

	/**
	 * Whether this line is whitespace only, shorthand
	 * for {@link TextLine.firstNonWhitespaceCharacterIndex} === {@link TextLine.text TextLine.text.length}.
	 */
	var isEmptyOrWhitespace(default, null):Bool;
}
