package vscode;

/**
 * A link on a terminal line.
 */
@:jsRequire("vscode", "TerminalLink")
extern class TerminalLink {
	/**
	 * The start index of the link on {@link TerminalLinkContext.line}.
	 */
	var startIndex:Int;

	/**
	 * The length of the link on {@link TerminalLinkContext.line}.
	 */
	var length:Int;

	/**
	 * The tooltip text when you hover over this link.
	 *
	 * If a tooltip is provided, is will be displayed in a string that includes instructions on
	 * how to trigger the link, such as `{0} (ctrl + click)`. The specific instructions vary
	 * depending on OS, user settings, and localization.
	 */
	var tooltip:Null<String>;

	/**
	 * Creates a new terminal link.
	 * @param startIndex The start index of the link on {@link TerminalLinkContext.line}.
	 * @param length The length of the link on {@link TerminalLinkContext.line}.
	 * @param tooltip The tooltip text when you hover over this link.
	 *
	 * If a tooltip is provided, is will be displayed in a string that includes instructions on
	 * how to trigger the link, such as `{0} (ctrl + click)`. The specific instructions vary
	 * depending on OS, user settings, and localization.
	 */
	function new(startIndex:Int, length:Int, ?tooltip:String);
}
