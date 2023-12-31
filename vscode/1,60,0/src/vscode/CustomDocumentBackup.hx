package vscode;

/**
 * A backup for an {@linkcode CustomDocument}.
 */
typedef CustomDocumentBackup = {
	/**
	 * Unique identifier for the backup.
	 *
	 * This id is passed back to your extension in `openCustomDocument` when opening a custom editor from a backup.
	 */
	var id(default, null):String;

	/**
	 * Delete the current backup.
	 *
	 * This is called by the editor when it is clear the current backup is no longer needed, such as when a new backup
	 * is made or when the file is saved.
	 */
	function delete():Void;
}
