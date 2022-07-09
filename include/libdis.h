#ifndef _LIB_DIS_H_
#define _LIB_DIS_H_

#include <stdint.h>


/* --------------------------------- MACROS --------------------------------- */
 // Combine the various ways of defining Windows into one macro.
#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(__MINGW32__)
#define _DIS_WINDOWS
#endif

#if defined(DIS_BUILD_DYNAMIC) && defined(DIS_USE_DYNAMIC)
#error "DIS_BUILD_DYNAMIC cannot be defined at the same time as DIS_USE_DYNAMIC."
#endif

#if defined(__cplusplus)
#define _DIS_LINKAGE extern "C"
#else
#define _DIS_LINKAGE extern
#endif

#if defined(_DIS_WINDOWS) && defined(DIS_BUILD_DYNAMIC)
 // Build Windows dynamic link library (.dll)
#define DIS_API _DIS_LINKAGE __declspec(dllexport)
#elif defined(_DIS_WINDOWS) && defined(DIS_USE_DYNAMIC)
 // Use Windows dynamic link library (.dll)
#define DIS_API _DIS_LINKAGE __declspec(dllimport)
#else
 // Build/use static library or Unix shared object (.so)
#define DIS_API _DIS_LINKAGE
#endif


/* ------------------------------- FUNCTIONS -------------------------------- */
DIS_API int32_t do_thing();


#endif /* _LIB_DIS_H_ */
