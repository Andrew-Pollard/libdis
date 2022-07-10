#ifndef _DIS_H_
#define _DIS_H_

#include <stdint.h>


/* --------------------------------- MACROS --------------------------------- */
 // Combine the various ways of defining Windows into one macro.
#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(__MINGW32__)
#define _DIS_WINDOWS
#endif

#if defined(DIS_BUILD_SHARED) && defined(DIS_USE_SHARED)
#error "DIS_BUILD_SHARED cannot be defined at the same time as DIS_USE_SHARED."
#endif

#if defined(__cplusplus)
#define _DIS_LINKAGE extern "C"
#else
#define _DIS_LINKAGE extern
#endif

#if defined(_DIS_WINDOWS) && defined(DIS_BUILD_SHARED)
 // Build as a Windows shared library (.dll)
#define _DIS_API _DIS_LINKAGE __declspec(dllexport)
#elif defined(_DIS_WINDOWS) && defined(DIS_USE_SHARED)
 // Use as a Windows shared library (.dll)
#define _DIS_API _DIS_LINKAGE __declspec(dllimport)
#elif defined(__GNUC__) && defined(DIS_BUILD_SHARED)
// Build as a Unix shared library (.so)
#define _DIS_API _DIS_LINKAGE __attribute__((visibility("default")))
#else
// Use as a Unix shared library (.so), or build/use it as a Windows/Unix static libary (.lib/.a)
#define _DIS_API _DIS_LINKAGE
#endif


/* ------------------------------- CONSTANTS -------------------------------- */


/* ------------------------------- STRUCTURES ------------------------------- */
struct dis_context;


/* ------------------------------ ENUMERATIONS ------------------------------ */
enum dis_result {
	DIS_RESULT_SUCCESS = 1,
	DIS_RESULT_FAILURE_NOT_IMPLEMENTED = 2,
	DIS_RESULT_FAILURE_NULL_POINTER = 3,
	DIS_RESULT_FAILURE_OUT_OF_MEMORY = 4
};

enum dis_log_level {
	DIS_LOG_LEVEL_DEBUG = 1,
	DIS_LOG_LEVEL_INFORMATION = 2,
	DIS_LOG_LEVEL_WARNING = 3,
	DIS_LOG_LEVEL_ERROR = 4,
	DIS_LOG_LEVEL_CRITICAL = 5
};


/* --------------------------- FUNCTION POINTERS ---------------------------- */
typedef void (*dis_log_callback)(const struct dis_context* context, enum dis_log_level log_level, const char* message);


/* ------------------------------- FUNCTIONS -------------------------------- */
// Context
_DIS_API enum dis_result dis_create_context(struct dis_context** context);
_DIS_API enum dis_result dis_delete_context(struct dis_context* context);

// Logging
_DIS_API enum dis_result dis_set_log_callback(struct dis_context* context, dis_log_callback callback);
enum dis_result dis_log(const struct dis_context* context, enum dis_log_level log_level, const char* message);
enum dis_result dis_log_debug(const struct dis_context* context, const char* message);
enum dis_result dis_log_information(const struct dis_context* context, const char* message);
enum dis_result dis_log_warning(const struct dis_context* context, const char* message);
enum dis_result dis_log_error(const struct dis_context* context, const char* message);
enum dis_result dis_log_critical(const struct dis_context* context, const char* message);


#endif /* _DIS_H_ */
