package vscode;

/**
 * A code action represents a change that can be performed in code, e.g. to fix a problem or
 * to refactor code.
 *
 * A CodeAction must set either {@linkcode CodeAction.edit edit} and/or a {@linkcode CodeAction.command command}. If both are supplied, the `edit` is applied first, then the command is executed.
 */
@:jsRequire("vscode", "CodeAction")
extern class CodeAction {
	/**
	 * A short, human-readable, title for this code action.
	 */
	var title:String;

	/**
	 * A {@link WorkspaceEdit workspace edit} this code action performs.
	 */
	var edit:Null<WorkspaceEdit>;

	/**
	 * {@link Diagnostic Diagnostics} that this code action resolves.
	 */
	var diagnostics:Null<Array<Diagnostic>>;

	/**
	 * A {@link Command} this code action executes.
	 *
	 * If this command throws an exception, the editor displays the exception message to users in the editor at the
	 * current cursor position.
	 */
	var command:Null<Command>;

	/**
	 * {@link CodeActionKind Kind} of the code action.
	 *
	 * Used to filter code actions.
	 */
	var kind:Null<CodeActionKind>;

	/**
	 * Marks this as a preferred action. Preferred actions are used by the `auto fix` command and can be targeted
	 * by keybindings.
	 *
	 * A quick fix should be marked preferred if it properly addresses the underlying error.
	 * A refactoring should be marked preferred if it is the most reasonable choice of actions to take.
	 */
	var isPreferred:Null<Bool>;

	/**
	 * Marks that the code action cannot currently be applied.
	 *
	 * - Disabled code actions are not shown in automatic [lightbulb](https://code.visualstudio.com/docs/editor/editingevolved#_code-action)
	 * code action menu.
	 *
	 * - Disabled actions are shown as faded out in the code action menu when the user request a more specific type
	 * of code action, such as refactorings.
	 *
	 * - If the user has a [keybinding](https://code.visualstudio.com/docs/editor/refactoring#_keybindings-for-code-actions)
	 * that auto applies a code action and only a disabled code actions are returned, the editor will show the user an
	 * error message with `reason` in the editor.
	 */
	var disabled:Null<{
		/**
		 * Human readable description of why the code action is currently disabled.
		 *
		 * This is displayed in the code actions UI.
		 */
		var reason(default, null):String;
	}>;

	/**
	 * Creates a new code action.
	 *
	 * A code action must have at least a {@link CodeAction.title title} and {@link CodeAction.edit edits}
	 * and/or a {@link CodeAction.command command}.
	 *
	 * @param title The title of the code action.
	 * @param kind The kind of the code action.
	 */
	function new(title:String, ?kind:CodeActionKind);
}
