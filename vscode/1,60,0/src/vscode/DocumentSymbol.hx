package vscode;

/**
 * Represents programming constructs like variables, classes, interfaces etc. that appear in a document. Document
 * symbols can be hierarchical and they have two ranges: one that encloses its definition and one that points to
 * its most interesting range, e.g. the range of an identifier.
 */
@:jsRequire("vscode", "DocumentSymbol")
extern class DocumentSymbol {
	/**
	 * The name of this symbol.
	 */
	var name:String;

	/**
	 * More detail for this symbol, e.g. the signature of a function.
	 */
	var detail:String;

	/**
	 * The kind of this symbol.
	 */
	var kind:SymbolKind;

	/**
	 * Tags for this symbol.
	 */
	var tags:Null<ReadOnlyArray<SymbolTag>>;

	/**
	 * The range enclosing this symbol not including leading/trailing whitespace but everything else, e.g. comments and code.
	 */
	var range:Range;

	/**
	 * The range that should be selected and reveal when this symbol is being picked, e.g. the name of a function.
	 * Must be contained by the {@linkcode DocumentSymbol.range range}.
	 */
	var selectionRange:Range;

	/**
	 * Children of this symbol, e.g. properties of a class.
	 */
	var children:Array<DocumentSymbol>;

	/**
	 * Creates a new document symbol.
	 *
	 * @param name The name of the symbol.
	 * @param detail Details for the symbol.
	 * @param kind The kind of the symbol.
	 * @param range The full range of the symbol.
	 * @param selectionRange The range that should be reveal.
	 */
	function new(name:String, detail:String, kind:SymbolKind, range:Range, selectionRange:Range);
}
