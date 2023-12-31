package vscode;

/**
 * Author information of a {@link Comment}
 */
typedef CommentAuthorInformation = {
	/**
	 * The display name of the author of the comment
	 */
	var name:String;

	/**
	 * The optional icon path for the author
	 */
	var ?iconPath:Uri;
}
