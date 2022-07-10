#include "dis.h"

#include <stdlib.h>


/* ------------------------------- STRUCTURES ------------------------------- */
struct _dis_context_impl {
	dis_log_callback log_callback;
};



/* ------------------------------- FUNCTIONS -------------------------------- */
_DIS_API enum dis_result dis_create_context(struct dis_context** context) {
	if (context == NULL)
		return DIS_RESULT_FAILURE_NULL_POINTER;

	*context = calloc(1, sizeof(struct _dis_context_impl));

	if (*context == NULL)
		return DIS_RESULT_FAILURE_OUT_OF_MEMORY;
	else
		return DIS_RESULT_SUCCESS;
}


_DIS_API enum dis_result dis_delete_context(struct dis_context* context) {
	if (context == NULL)
		return DIS_RESULT_FAILURE_NULL_POINTER;

	free((struct _dis_context_impl*) context);

	return DIS_RESULT_SUCCESS;
}


_DIS_API enum dis_result dis_set_log_callback(struct dis_context* context, dis_log_callback callback) {
	if (context == NULL)
		return DIS_RESULT_FAILURE_NULL_POINTER;

	((struct _dis_context_impl*) context)->log_callback = callback;

	return DIS_RESULT_SUCCESS;
}


enum dis_result dis_log(const struct dis_context* context, enum dis_log_level log_level, const char* message) {
	if (context == NULL || message == NULL)
		return DIS_RESULT_FAILURE_NULL_POINTER;

	((const struct _dis_context_impl*) context)->log_callback(context, log_level, message);

	return DIS_RESULT_SUCCESS;
}


enum dis_result dis_log_debug(const struct dis_context* context, const char* message) {
	if (context == NULL || message == NULL)
		return DIS_RESULT_FAILURE_NULL_POINTER;

	((const struct _dis_context_impl*) context)->log_callback(context, DIS_LOG_LEVEL_DEBUG, message);

	return DIS_RESULT_SUCCESS;
}


enum dis_result dis_log_information(const struct dis_context* context, const char* message) {
	if (context == NULL || message == NULL)
		return DIS_RESULT_FAILURE_NULL_POINTER;

	((const struct _dis_context_impl*) context)->log_callback(context, DIS_LOG_LEVEL_INFORMATION, message);

	return DIS_RESULT_SUCCESS;
}


enum dis_result dis_log_warning(const struct dis_context* context, const char* message) {
	if (context == NULL || message == NULL)
		return DIS_RESULT_FAILURE_NULL_POINTER;

	((const struct _dis_context_impl*) context)->log_callback(context, DIS_LOG_LEVEL_WARNING, message);

	return DIS_RESULT_SUCCESS;
}


enum dis_result dis_log_error(const struct dis_context* context, const char* message) {
	if (context == NULL || message == NULL)
		return DIS_RESULT_FAILURE_NULL_POINTER;

	((const struct _dis_context_impl*) context)->log_callback(context, DIS_LOG_LEVEL_ERROR, message);

	return DIS_RESULT_SUCCESS;
}


enum dis_result dis_log_critical(const struct dis_context* context, const char* message) {
	if (context == NULL || message == NULL)
		return DIS_RESULT_FAILURE_NULL_POINTER;

	((const struct _dis_context_impl*) context)->log_callback(context, DIS_LOG_LEVEL_CRITICAL, message);

	return DIS_RESULT_SUCCESS;
}
