package vscode;

/**
 * A type that filesystem providers should use to signal errors.
 *
 * This class has factory methods for common error-cases, like `FileNotFound` when
 * a file or folder doesn't exist, use them like so: `throw vscode.FileSystemError.FileNotFound(someUri);`
 */
@:jsRequire("vscode", "FileSystemError")
extern class FileSystemError extends Error {
	/**
	 * Create an error to signal that a file or folder wasn't found.
	 * @param messageOrUri Message or uri.
	 */
	static function FileNotFound(?messageOrUri:EitherType<String, Uri>):FileSystemError;

	/**
	 * Create an error to signal that a file or folder already exists, e.g. when
	 * creating but not overwriting a file.
	 * @param messageOrUri Message or uri.
	 */
	static function FileExists(?messageOrUri:EitherType<String, Uri>):FileSystemError;

	/**
	 * Create an error to signal that a file is not a folder.
	 * @param messageOrUri Message or uri.
	 */
	static function FileNotADirectory(?messageOrUri:EitherType<String, Uri>):FileSystemError;

	/**
	 * Create an error to signal that a file is a folder.
	 * @param messageOrUri Message or uri.
	 */
	static function FileIsADirectory(?messageOrUri:EitherType<String, Uri>):FileSystemError;

	/**
	 * Create an error to signal that an operation lacks required permissions.
	 * @param messageOrUri Message or uri.
	 */
	static function NoPermissions(?messageOrUri:EitherType<String, Uri>):FileSystemError;

	/**
	 * Create an error to signal that the file system is unavailable or too busy to
	 * complete a request.
	 * @param messageOrUri Message or uri.
	 */
	static function Unavailable(?messageOrUri:EitherType<String, Uri>):FileSystemError;

	/**
	 * Creates a new filesystem error.
	 *
	 * @param messageOrUri Message or uri.
	 */
	function new(?messageOrUri:EitherType<String, Uri>);

	/**
	 * A code that identifies this error.
	 *
	 * Possible values are names of errors, like {@linkcode FileSystemError.FileNotFound FileNotFound},
	 * or `Unknown` for unspecified errors.
	 */
	var code(default, null):String;
}
