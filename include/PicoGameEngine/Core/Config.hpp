#ifndef PGE_CORE_CONFIG_HPP
#define PGE_CORE_CONFIG_HPP

#ifdef _WIN32
#  define PGE_WINDOWS
#else
#  define PGE_LINUX
#endif

#ifdef _MSC_VER
#  pragma warning(disable: 4201) // nonstandard extension used: nameless struct/union
#  pragma warning(disable: 4251) // class 'X' needs to have dll-interface to be used by clients of class 'Y'
#  define PGE_DLLEXPORT __declspec(dllexport)
#  define PGE_DLLIMPORT __declspec(dllimport)
#else
#  define PGE_DLLEXPORT __attribute__ ((visibility ("default")))
#  define PGE_DLLIMPORT
#endif

#ifdef PGE_BUILD_DLL
#  define PGE_API PGE_DLLEXPORT
#elif defined(PS_DLL)
#  define PGE_API PGE_DLLIMPORT
#else
#  define PGE_API
#endif

#endif
