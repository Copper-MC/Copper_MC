package vscode;

/**
 * An event signaling the start of a process execution
 * triggered through a task
 */
typedef TaskProcessStartEvent = {
	/**
	 * The task execution for which the process got started.
	 */
	var execution(default, null):TaskExecution;

	/**
	 * The underlying process id.
	 */
	var processId(default, null):Int;
}
