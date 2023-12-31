package vscode;

/**
 * A code lens represents a {@link Command} that should be shown along with
 * source text, like the number of references, a way to run tests, etc.
 *
 * A code lens is _unresolved_ when no command is associated to it. For performance
 * reasons the creation of a code lens and resolving should be done to two stages.
 *
 * @see {@link CodeLensProvider.provideCodeLenses}
 * @see {@link CodeLensProvider.resolveCodeLens}
 */
@:jsRequire("vscode", "CodeLens")
extern class CodeLens {
	/**
	 * The range in which this code lens is valid. Should only span a single line.
	 */
	var range:Range;

	/**
	 * The command this code lens represents.
	 */
	var command:Null<Command>;

	/**
	 * `true` when there is a command associated.
	 */
	var isResolved(default, null):Bool;

	/**
	 * Creates a new code lens object.
	 *
	 * @param range The range to which this code lens applies.
	 * @param command The command associated to this code lens.
	 */
	function new(range:Range, ?command:Command);
}
